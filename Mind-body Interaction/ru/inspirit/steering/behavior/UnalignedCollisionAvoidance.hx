package ru.inspirit.steering.behavior; 

	import haxe.FastList;

	import ru.inspirit.steering.Vehicle;
	import ru.inspirit.steering.behavior.AbstractBehavior;
	using ru.inspirit.steering.SteerVector3D;

	/**
	 * @author Eugene Zatepyakin
	 */
	class UnalignedCollisionAvoidance extends AbstractBehavior {
		
		public var collisionDangerThreshold:Int ; // should be around 3 * Vehicle Radius
		public var predict:Int ;
		
		public var avoidList:FastList<Vehicle>;
		
		public function new(?avoidList:FastList<Vehicle> = null, ?collisionDangerThreshold:Int = 9, ?predict:Int = 25)
		{
			super();
			this.avoidList = avoidList;
			this.collisionDangerThreshold = collisionDangerThreshold;
			this.predict = predict;
		}
		
		public override function apply(veh:Vehicle):Void
		{			
			var a:Float, b:Float, c:Float, t:Float;
			var dx:Float, dy:Float, dz:Float;
			var pdx:Float, pdy:Float, pdz:Float;
			var vx:Float = veh.velocity.x;
			var vy:Float = veh.velocity.y;
			var vz:Float = veh.velocity.z;
			var px:Float = veh.position.x;
			var py:Float = veh.position.y;
			var pz:Float = veh.position.z;
			var mag:Float;
			var d:Float;
			
			var threat:Vehicle = null;
			var time:Float;
			var minTime:Int = 20;
			var relSpeed:Float;
			for(other in avoidList){
				if(other == veh)
				{
					continue;
				}
				// predict Nearest Approach Time
				dx = other.velocity.x - vx;
				dy = other.velocity.y - vy;
				dz = other.velocity.z - vz;
				
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
				
				relSpeed = a * 0.9375 + (b + c) * 0.375;
				
				mag = Math.sqrt( dx * dx + dy * dy + dz * dz );
				if(mag != 0) 
				{
					mag = 1 / mag;
					dx *= mag;
					dy *= mag;
					dz *= mag;
				}
				
				pdx = px - other.position.x;
				pdy = py - other.position.y;
				pdz = pz - other.position.z;
				
				time = (dx * pdx + dy * pdy + dz * pdz) / relSpeed;
				
				if(time >= 0 && time < minTime)
				{
					// compute Nearest Approach Positions
					dx = (vx * time + px) - (other.velocity.x * time + other.position.x);
					dy = (vy * time + py) - (other.velocity.y * time + other.position.y);
					dz = (vz * time + pz) - (other.velocity.z * time + other.position.z);
					
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
					
					d = a * 0.9375 + (b + c) * 0.375;
					
					if(d < collisionDangerThreshold)
					{
						minTime = cast time;
						threat = other;
					}
				}
			}
			
			if(threat != null)
			{
				pdx = (threat.velocity.x * minTime + threat.position.x);
				pdy = (threat.velocity.y * minTime + threat.position.y);
				pdz = (threat.velocity.z * minTime + threat.position.z);
				dx = px - pdx;
				dy = py - pdy;
				dz = pz - pdz;
				d = (dx * veh.up.x + dy * veh.up.y + dz * veh.up.z);
				dx = d * veh.up.x;
				dy = d * veh.up.y;
				dz = d * veh.up.z;
				
				if(veh.velocity.approximateLength() < 0.2 * veh.maxSpeed)
				{
					accumulator.x = dx + veh.forward.x;
					accumulator.y = dy + veh.forward.y;
					accumulator.z = dz + veh.forward.z;
				} else {
					pdx = (vx * minTime + px) - pdx;
					pdy = (vy * minTime + py) - pdy;
					pdz = (vz * minTime + pz) - pdz;
					d = (pdx * veh.forward.x + pdy * veh.forward.y + pdz * veh.forward.z);
					
					accumulator.x = dx + veh.forward.x * d;
					accumulator.y = dy + veh.forward.y * d;
					accumulator.z = dz + veh.forward.z * d;
				}
				veh.applyGlobalForce(accumulator);
			}
		}
	}
