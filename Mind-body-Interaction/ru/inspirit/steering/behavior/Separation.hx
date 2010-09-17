package ru.inspirit.steering.behavior; 

	import haxe.FastList;
	
	import ru.inspirit.steering.Vehicle;
	using ru.inspirit.steering.SteerVector3D;

	/**
	 * @author Eugene Zatepyakin
	 */
	class Separation extends AbstractBehavior {
		
		public var separateDist:Float;
		public var separateAngleCos:Float;
		public var separateStrength:Float;
		
		public var separateList:FastList<Vehicle>;
		
		public function new(?separateList:FastList<Vehicle> = null, ?separateDist:Int = 9, ?separateAngle:Int = 135, ?separateStrength:Float = 0.95)
		{
			super();
			this.separateList = separateList;
			this.separateDist = separateDist;
			this.separateAngleCos = Math.cos(((separateAngle / 360) * 2.0) * Math.PI);
			this.separateStrength = separateStrength;
		}

		public override function apply(veh:Vehicle):Void
		{
			var ax = 0.0, ay = 0.0, az = 0.0;
			
			var approximateDistance:Float;
			
			var px:Float = veh.position.x;
			var py:Float = veh.position.y;
			var pz:Float = veh.position.z;
			var dx:Float, dy:Float, dz:Float;
			var f:Float;


			for (other in separateList)
			{
				if(other == veh)
				{
					continue;
				}

				approximateDistance = nearby(veh, other, separateDist, separateAngleCos);
				if( approximateDistance != 0 )
				{
					dx = px - other.position.x;
					dy = py - other.position.y;
					dz = pz - other.position.z;
					
					f = 1 / (approximateDistance * approximateDistance);
					
					ax += dx * f;
					ay += dy * f;
					az += dz * f;
				}
			}
			
			accumulator.x = ax;
			accumulator.y = ay;
			accumulator.z = az;
			accumulator.setApproximateNormalize();
			
			accumulator.x *= separateStrength;
			accumulator.y *= separateStrength;
			accumulator.z *= separateStrength;
			
			veh.applyGlobalForce(accumulator);
		}
	}
