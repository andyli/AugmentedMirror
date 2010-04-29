package ru.inspirit.steering.behavior; 

	using ru.inspirit.steering.SteerVector3D;
	import ru.inspirit.steering.Vehicle;

	import flash.geom.Vector3D;

	/**
	 * @author Eugene Zatepyakin
	 */
	class AbstractBehavior 
	 {		
		public function new() { 
			accumulator = new Vector3D();
		}
				
		public var accumulator:Vector3D;
		
		//public var next:AbstractBehavior;
		
		public function apply(veh:Vehicle):Void {}
		
		public function nearby(veh:Vehicle, other:Vehicle, distance:Float, angleCosine:Float):Float
		{			
			var dx:Float = other.position.x - veh.position.x;
			var dy:Float = other.position.y - veh.position.y;
			var dz:Float = other.position.z - veh.position.z;
			
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
			
			var approximateDistance:Float = a * 0.9375 + (b + c) * 0.375;
			
			if(approximateDistance > distance)
			{
				return 0;
			}
			
			var dot:Float = dx * veh.forward.x + dy * veh.forward.y + dz * veh.forward.z;
			
			return dot >= angleCosine ? approximateDistance : 0;
		}
	}
