package ru.inspirit.steering.behavior; 

	import ru.inspirit.steering.Float3D;
	using ru.inspirit.steering.SteerVector3D;
	import ru.inspirit.steering.Vehicle;
	import ru.inspirit.steering.behavior.AbstractBehavior;

	import flash.geom.Vector3D;

	/**
	 * @author Eugene Zatepyakin
	 */
	class Arrival extends AbstractBehavior {
		
		public var target:Float3D;
		public var slowingDistance:Int ;
		
		public function new(target:Float3D, ?slowingDistance:Int = 7)
		{
			super();
			this.target = target;
			this.slowingDistance = slowingDistance;
		}
		
		public override function apply(veh:Vehicle):Void
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
			
			accumulator.x = dx * clippedSpeed - veh.velocity.x;
			accumulator.y = dy * clippedSpeed - veh.velocity.y;
			accumulator.z = dz * clippedSpeed - veh.velocity.z;
			
			veh.applyGlobalForce(accumulator);
		}
	}
