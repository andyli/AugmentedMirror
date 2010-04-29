package ru.inspirit.steering.behavior.combined; 

	import haxe.FastList;

	import ru.inspirit.steering.SteerVector3D;
	using ru.inspirit.steering.SteerVector3D;
	import ru.inspirit.steering.Vehicle;
	import ru.inspirit.steering.behavior.AbstractBehavior;
	import ru.inspirit.steering.Float3D;

	import flash.geom.Vector3D;

	/**
	 * Leader following bahevior
	 * Should update to allow users control leader vehicle
	 * 
	 * @author Eugene Zatepyakin
	 */
	class LeaderFollowing extends AbstractBehavior {
		// WONDER OPTIONS
		inline static private var SQRT2:Float = Math.sqrt(2);
		
		var wanderJiggle:Vector3D ;
		var wanderGlobal:Vector3D ;
		
		public var wanderStrength:Float ;
		public var wanderRate:Float ;
		public var wanderDirection:Vector3D ;
		
		public var slowingDistance:Int ;
		
		//
		var s1:Vector3D ;
		var s2:Vector3D ;
		var local:Vector3D ;
		var followTarget:Vector3D ;
		
		public var leaderAvoidWidth:Int ;
		public var leaderAvoidLength:Int ;
		public var fastslow:Bool;
		
		public var leaderTarget:Vector3D ;
		public var leaderTargetCenter:Vector3D ;
		public var newTargetOffset:Vector3D ;
		
		public var leaderTargetRange:Int ;
		public var leaderTargetCount:Int ;
		
		public var vehicleList:FastList<Vehicle>;
		public var vehicleLeader:Vehicle;
		
		public function new(?vehicleList:FastList<Vehicle>, ?vehicleLeader:Vehicle)
		{
			super();
			
			wanderJiggle = new Vector3D();
			wanderGlobal = new Vector3D();
			wanderStrength = .1;
			wanderRate = 0.8;
			wanderDirection = new Vector3D();
			slowingDistance = 7;
			s1 = new Vector3D();
			s2 = new Vector3D();
			local = new Vector3D();
			followTarget = new Vector3D();
			leaderAvoidWidth = cast 4 * 0.5;
			leaderAvoidLength = cast 30 * 0.5;
			leaderTarget = new Vector3D();
			leaderTargetCenter = new Vector3D();
			newTargetOffset = new Vector3D();
			leaderTargetRange = 8;
			leaderTargetCount = 0;
			this.vehicleList = vehicleList;
			this.vehicleLeader = vehicleLeader;
			
			fastslow = true;
		}

		public override function apply(veh:Vehicle):Void
		{
			if(veh == vehicleLeader)
			{
				steeringForLeader(veh, accumulator);
			} else
			{
				steeringForFollower(veh, vehicleLeader, accumulator);
			}
			
			veh.applyGlobalForce(accumulator);
		}
		
		public function steeringForFollower(veh:Vehicle, target:Vehicle, v:Float3D):Void
		{
			steeringToFollowLeaderOrGetOutOfItsWay(veh, target, s1);
			steeringForSeparation(veh, 8 * veh.vehicleRadius, s2);
			
			v.x = s2.x * 0.2 + s1.x;
			v.y = s2.y * 0.2 + s1.y;
			v.z = s2.z * 0.2 + s1.z;
		}
		
		public function steeringToFollowLeaderOrGetOutOfItsWay(veh:Vehicle, target:Vehicle, v:Float3D):Void
		{
			target.localizePosition(veh.position, local);
			var adjust:Float = target.velocity.approximateLength() / target.maxSpeed;
			var margin:Int = Std.int(3 * veh.vehicleRadius);
			
			if(local.z > 0.0 && local.z < leaderAvoidLength * adjust + margin * 2.0 && local.x < leaderAvoidWidth * adjust + margin && local.x > -leaderAvoidWidth * adjust - margin && local.y < leaderAvoidWidth * adjust + margin && local.y > -leaderAvoidWidth * adjust - margin)
			{
				local.x += local.x <= 0 ? -1 : 1;
				local.y += local.y <= 0 ? -1 : 1;
				local.x *= 3;
				local.y *= 3;
				local.z *= 0.5;
				target.globalizePosition(local, followTarget);
				steeringForSeek(veh, followTarget, v);
			} else
			{
				var followDistance:Int = cast veh.vehicleRadius * -5;
				followTarget.x = target.forward.x * followDistance + target.position.x;
				followTarget.y = target.forward.y * followDistance + target.position.y;
				followTarget.z = target.forward.z * followDistance + target.position.z;
				
				steeringForArrival(veh, followTarget, v);
			}
		}
		
		public function steeringForLeader(veh:Vehicle, v:Float3D):Void
		{
			maybeSteerTowardRandomLeaderTarget(veh, v);
			if(v.equalsZero())
			{
				if(SteerVector3D.random() < 0.8)
				{
					var r:Float = SteerVector3D.random();
					if(r > 0.97) fastslow = true;
					if(r < 0.03) fastslow = false;
					var speed:Int = Std.int((fastslow ? 0.3 : 1) * veh.maxSpeed);
					accelToTargetSpeed(veh, speed, v);
				} 
				else {
					steeringForWander(veh, v);
				}
			}
		}
		
		public function maybeSteerTowardRandomLeaderTarget(veh:Vehicle, v:Float3D):Void
		{
			if(leaderTargetCount == 0 || leaderTarget.approximateDistance(veh.position) < veh.vehicleRadius * 3)
			{
				var loop:Int = -1;
				var fwd:Float3D = veh.forward;
				var px:Float = veh.position.x, py:Float = veh.position.y, pz:Float = veh.position.z;
				do
				{
					leaderTarget.x = leaderTargetRange * (SteerVector3D.random() * 0.8 + 0.1);
					leaderTarget.y = leaderTargetRange * (SteerVector3D.random() * 0.8 + 0.1);
					leaderTarget.z = leaderTargetRange * (SteerVector3D.random() * 0.8 + 0.1);
					
					newTargetOffset.x = leaderTarget.x - px;
					newTargetOffset.y = leaderTarget.y - py;
					newTargetOffset.z = leaderTarget.z - pz;
					
					newTargetOffset.setApproximateNormalize();
				} 
				while(newTargetOffset.dot(fwd) < -0.8 && ++loop < 50);
				
				leaderTargetCount = 50;
			} else
			{
				leaderTargetCount--;
			}
			
			if(SteerVector3D.random() < 0.43)
			{
				steeringForSeek(veh, leaderTarget, v);
			} else
			{
				v.setZero();
			}
		}
		
		public function accelToTargetSpeed(veh:Vehicle, targetSpeed:Float, v:Float3D):Void
		{
			var speed:Float = veh.velocity.approximateLength();
			if(speed < targetSpeed) 
			{
				v.setScale(veh.maxForce, veh.forward);
			} else {
				v.setScale(-veh.maxForce, veh.forward);
			}
		}

		public function steeringForSeek(veh:Vehicle, target:Float3D, v:Float3D):Void
		{
			v.setDiff(target, veh.position);
			v.setApproximateTruncate(veh.maxSpeed);
			v.setDiff(v, veh.velocity);
		}
		
		public function steeringForWander(veh:Vehicle, v:Float3D):Void
		{
			wanderJiggle.setUnitRandom();
			
			wanderJiggle.x *= wanderRate;
			wanderJiggle.y *= wanderRate;
			wanderJiggle.z *= wanderRate;
			
			//wanderDirection.x += wanderJiggle.x;
			wanderDirection.y += wanderJiggle.y;
			wanderDirection.z += wanderJiggle.z;
			
			wanderDirection.setApproximateNormalize();
			
			veh.globalizeDirection(wanderDirection, wanderGlobal);
			
			wanderGlobal.x *= wanderStrength;
			wanderGlobal.y *= wanderStrength;
			wanderGlobal.z *= wanderStrength;
			
			v.x = veh.forward.x * SQRT2 + wanderGlobal.x;
			v.y = veh.forward.y * SQRT2 + wanderGlobal.y;
			v.z = veh.forward.z * SQRT2 + wanderGlobal.z;
		}
		
		public function steeringForSeparation(veh:Vehicle, separationDistance:Float, v:Float3D):Void
		{
			var approximateDistance:Float;
			
			var px:Float = veh.position.x;
			var py:Float = veh.position.y;
			var pz:Float = veh.position.z;
			var dx:Float, dy:Float, dz:Float;
			var vx = 0.0, vy = 0.0, vz = 0.0;
			var a:Float, b:Float, c:Float, t:Float;
			var f:Float;
			
			for (other in vehicleList)
			{
				if(other == veh)
				{
					continue;
				}
				dx = px - other.position.x;
				dy = py - other.position.y;
				dz = pz - other.position.z;
				
				a = dx;
				if (a < 0) a = -a;
				
				b = dy;
				if (b < 0) b = -b;
				
				c = dz;
				if (c < 0) c = -c;
				
				if(a < b) {
					t = a;
					a = b;
					b = t;
				}
				if(a < c) {
					t = a;
					a = c;
					c = t;
				}
				
				approximateDistance = a * 0.9375 + (b + c) * 0.375;
				
				if( approximateDistance < separationDistance && approximateDistance > 0) 
				{					
					
					f = 1 / (approximateDistance * approximateDistance);
					
					vx += dx * f;
					vy += dy * f;
					vz += dz * f;
				}
			}
			
			v.x = vx;
			v.y = vy;
			v.z = vz;
		}
		
		public function steeringForArrival(veh:Vehicle, target:Float3D, v:Float3D):Void
		{
			var dx:Float = target.x - veh.position.x;
			var dy:Float = target.y - veh.position.y;
			var dz:Float = target.z - veh.position.z;
			
			var a:Float = dx;
			if (a < 0) a = -a;
			
			var b:Float = dy;
			if (b < 0) b = -b;
			
			var c:Float = dz;
			if (c < 0) c = -c;
			
			var t:Float;
			if(a < b) {
				t = a;
				a = b;
				b = t;
			}
			if(a < c) {
				t = a;
				a = c;
				c = t;
			}
			
			var distance:Float =  a * 0.9375 + (b + c) * 0.375;
			
			var rampedSpeed:Float = veh.maxSpeed * (distance / slowingDistance);
			var clippedSpeed:Float = (rampedSpeed > veh.maxSpeed ? veh.maxSpeed : rampedSpeed) / distance;
			
			v.x = dx * clippedSpeed - veh.velocity.x;
			v.y = dy * clippedSpeed - veh.velocity.y;
			v.z = dz * clippedSpeed - veh.velocity.z;
		}
	}
