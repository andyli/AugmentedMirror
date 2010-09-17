package ru.inspirit.steering.behavior; 

	import haxe.FastList;

	import ru.inspirit.steering.Vehicle;
	import ru.inspirit.steering.behavior.AbstractBehavior;
	using ru.inspirit.steering.SteerVector3D;

	/**
	 * @author Eugene Zatepyakin
	 */
	class Cohesion extends AbstractBehavior {
		
		public var cohereDist:Float;
		public var cohereAngleCos:Float;
		public var cohereStrength:Float;
		
		public var cohereList:FastList<Vehicle>;
		
		public function new(?cohereList:FastList<Vehicle> = null, ?cohereDist:Int = 15, ?cohereAngle:Int = 150, ?cohereStrength:Int = 1)
		{
			super();
			this.cohereList = cohereList;
			this.cohereDist = cohereDist;
			this.cohereAngleCos = Math.cos(((cohereAngle / 360) * 2.0) * Math.PI);
			this.cohereStrength = cohereStrength;
		}
		
		public override function apply(veh:Vehicle):Void
		{
			var ax = 0.0, ay = 0.0, az = 0.0;
			
			var count:Int = 0;
			
			for (other in cohereList)
			{
				if(other == veh)
				{
					continue;
				}
				
				if( nearby(veh, other, cohereDist, cohereAngleCos) > 0 )
				{
					count++;
					
					ax += other.position.x;
					ay += other.position.y;
					az += other.position.z;
				}
			}
			
			if(count > 0)
			{
				var f = 1 / count;
				ax *= f;
				ay *= f;
				az *= f;
				
				accumulator.x = ax - veh.position.x;
				accumulator.y = ay - veh.position.y;
				accumulator.z = az - veh.position.z;
				accumulator.setApproximateNormalize();
			
				accumulator.x *= cohereStrength;
				accumulator.y *= cohereStrength;
				accumulator.z *= cohereStrength;
				
				veh.applyGlobalForce(accumulator);
			}
		}
	}
