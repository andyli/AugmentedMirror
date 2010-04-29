package ru.inspirit.steering.behavior; 

	import haxe.FastList;
	
	import ru.inspirit.steering.Vehicle;
	import ru.inspirit.steering.behavior.AbstractBehavior;
	using ru.inspirit.steering.SteerVector3D;

	/**
	 * @author Eugene Zatepyakin
	 */
	class Alignment extends AbstractBehavior {
		
		public var alignDist:Float;
		public var alignAngleCos:Float;
		public var alignStrength:Float;
		
		public var alignList:FastList<Vehicle>;
		
		public var deltaHeading:Bool ;
		
		public function new(?alignList:FastList<Vehicle> = null, ?alignDist:Int = 9, ?alignAngle:Int = 90, ?alignStrength:Float = 0.13, ?deltaHeading:Bool = false)
		{
			super();
			deltaHeading = false;
			this.alignList = alignList;
			this.alignDist = alignDist;
			this.alignAngleCos = Math.cos(((alignAngle / 360) * 2.0) * Math.PI);
			this.alignStrength = alignStrength;
			this.deltaHeading = deltaHeading;
		}
		
		public override function apply(veh:Vehicle):Void
		{
			var ax = 0.0, ay = 0.0, az = 0.0;
			
			var count:Int = 0;
			
			for (other in alignList)
			{
				if(other == veh)
				{
					continue;
				}
				
				if( nearby(veh, other, alignDist, alignAngleCos)>0 )
				{
					count++;
					
					ax += other.forward.x;
					ay += other.forward.y;
					az += other.forward.z;
				}
			}
			
			if(count>0)
			{
				var f = 1 / count;
				ax *= f;
				ay *= f;
				az *= f;
				
				if (deltaHeading) 
				{
					accumulator.x = ax - veh.forward.x;
					accumulator.y = ay - veh.forward.y;
					accumulator.z = az - veh.forward.z;
				} else {
					accumulator.x = ax;
					accumulator.y = ay;
					accumulator.z = az;
				}
				
				accumulator.setApproximateNormalize();
			
				accumulator.x *= alignStrength;
				accumulator.y *= alignStrength;
				accumulator.z *= alignStrength;
				
				veh.applyGlobalForce(accumulator);
			}
		}
	}
