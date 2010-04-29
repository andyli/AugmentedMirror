package ru.inspirit.steering; 

	import ru.inspirit.steering.behavior.BehaviorList;
	using ru.inspirit.steering.SteerVector3D;

	import flash.geom.Vector3D;

	/**
	 * Base class for any moving entity
	 * 
	 * @author Eugene Zatepyakin
	 */
	class Vehicle 
	 {		
				
		public static var globalUp:Vector3D = new Vector3D(0, 0.1, 0);
		
		// BOUNDS OPTIONS
		inline public static var EDGE_NONE:UInt = 0;
		inline public static var EDGE_WRAP:UInt = 1;
		inline public static var EDGE_BOUNCE:UInt = 2;
		
		public var boundsCentre:Vector3D ;
		public var boundsRadius:Int ;
		public var edgeBehavior:UInt ;
		
		public var mass:Float;
		public var maxSpeed:Float;
		public var maxForce:Float;
		public var accelDamping:Float;
		
		public var velocity:Vector3D;
		public var allForces:Vector3D;
		public var acceleration:Vector3D;
		
		public var position:Vector3D;
		public var forward:Vector3D;
		public var side:Vector3D;
		public var up:Vector3D;
		
		public var vehicleRadius:Float;
		
		//public var next:Vehicle;
		public var behaviorList:BehaviorList;
		
		public function new(?position:Vector3D, ?behaviorList:BehaviorList) 
		{
			
			boundsCentre = new Vector3D();
			boundsRadius = 25;
			edgeBehavior = EDGE_WRAP;
			identity();
			if (position != null) {
				this.position = position;
			}
			
			this.behaviorList = behaviorList;
		}

		public function identity():Void
		{
			mass = 1;
			maxSpeed = 1;
			maxForce = 0.04;
			accelDamping = 0.7;
			vehicleRadius = 3;
			
			acceleration = new Vector3D();
			velocity = new Vector3D();
			allForces = new Vector3D();
			
			position = new Vector3D();
			forward = new Vector3D(0, 0, 1);
			side = new Vector3D(1, 0, 0);
			up = new Vector3D(0, 1, 0);
		}
		
		inline public function applyGlobalForce(force:Vector3D):Void
		{
			allForces.x += force.x;
			allForces.y += force.y;
			allForces.z += force.z;
		}

		public function update():Void
		{
			allForces.setApproximateTruncate(maxForce);
			
			var nax:Float, nay:Float, naz:Float;
			var m:Float;
			
			if(mass == 1) 
			{
				nax = allForces.x;
				nay = allForces.y;
				naz = allForces.z;
			} else {
				m = 1 / mass;
				nax = allForces.x * m;
				nay = allForces.y * m;
				naz = allForces.z * m;
			}
			
			allForces.x = allForces.y = allForces.z = 0;
			
			acceleration.x = nax + accelDamping * (acceleration.x - nax);
			acceleration.y = nay + accelDamping * (acceleration.y - nay);
			acceleration.z = naz + accelDamping * (acceleration.z - naz);
			
			velocity.x += acceleration.x;
			velocity.y += acceleration.y;
			velocity.z += acceleration.z;
			
			velocity.setApproximateTruncate(maxSpeed);
			
			position.x += velocity.x;
			position.y += velocity.y;
			position.z += velocity.z;
			
			boundsCheck();
			
			var aux:Float = acceleration.x * 0.5 + up.x + globalUp.x;
			var auy:Float = acceleration.y * 0.5 + up.y + globalUp.y;
			var auz:Float = acceleration.z * 0.5 + up.z + globalUp.z;
			
			m = Math.sqrt( aux * aux + auy * auy + auz * auz );
			if(m != 0) 
			{
				m = 1 / m;
				aux *= m;
				auy *= m;
				auz *= m;
			}
			
			var speed:Float = velocity.magnitude();
			if(speed != 0) 
			{
				speed = 1 / speed;
				forward.x = velocity.x * speed;
				forward.y = velocity.y * speed;
				forward.z = velocity.z * speed;
				
				side.x = forward.y * auz - forward.z * auy;
				side.y = forward.z * aux - forward.x * auz;
				side.z = forward.x * auy - forward.y * aux;
				
				up.setCross(side, forward);
			}
		}
		
		public function boundsCheck():Void
		{
			if(edgeBehavior == EDGE_NONE) return;
			
			var distance:Float = Vector3D.distance(position, boundsCentre);
				
			if( distance > boundsRadius + vehicleRadius ) 
			{
				switch( edgeBehavior )
				{
					case EDGE_BOUNCE :
						
						position.decrementBy(boundsCentre);
						position.normalize();
						position.scaleBy(boundsRadius + vehicleRadius);
						
						velocity.scaleBy(-1);
						position.incrementBy(velocity);
						position.incrementBy(boundsCentre);
					
					case EDGE_WRAP :

						//position.decrementBy(boundsCentre);
						//position.negate();
						//position.incrementBy(boundsCentre);
						var wrap = position.scale(1 / distance);
						wrap.setScale(-2 * boundsRadius,wrap);
						position.setSum(wrap,position);
				}
			}
		}

		inline public function globalizePosition(local:Vector3D, globalized:Vector3D):Void
		{
			globalized.x = (side.x * local.x) + (up.x * local.y) + (forward.x * local.z) + position.x;
			globalized.y = (side.y * local.x) + (up.y * local.y) + (forward.y * local.z) + position.y;
			globalized.z = (side.z * local.x) + (up.z * local.y) + (forward.z * local.z) + position.z;
		}
		
		inline public function globalizeDirection(local:Vector3D, globalized:Vector3D):Void
		{	
			globalized.x = (side.x * local.x) + (up.x * local.y) + (forward.x * local.z);
			globalized.y = (side.y * local.x) + (up.y * local.y) + (forward.y * local.z);
			globalized.z = (side.z * local.x) + (up.z * local.y) + (forward.z * local.z);
		}
		
		inline public function localizePosition(global:Vector3D, localized:Vector3D):Void
		{
			//component.setDiff(global, position);
			var xd:Float = global.x - position.x;
			var yd:Float = global.y - position.y;
			var zd:Float = global.z - position.z;
			//localized.setTo(component.dot(side), component.dot(up), component.dot(forward));
			localized.x = xd * side.x + yd * side.y + zd * side.z;
			localized.y = xd * up.x + yd * up.y + zd * up.z;
			localized.z = xd * forward.x + yd * forward.y + zd * forward.z;
		}
	}
