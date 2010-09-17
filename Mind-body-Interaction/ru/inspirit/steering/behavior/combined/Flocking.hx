package ru.inspirit.steering.behavior.combined; 

	import haxe.FastList;
	
	import ru.inspirit.steering.Vehicle;
	import ru.inspirit.steering.behavior.AbstractBehavior;
	import ru.inspirit.steering.behavior.Alignment;
	import ru.inspirit.steering.behavior.Cohesion;
	import ru.inspirit.steering.behavior.Separation;

	/**
	 * Flocking Behavior
	 * as described by Craig Reynolds 
	 * 
	 * @author Eugene Zatepyakin
	 */
	class Flocking extends AbstractBehavior {
		
		public var separate:Separation;
		public var align:Alignment;
		public var cohere:Cohesion;
		
		public function new(?separateList:FastList<Vehicle>, ?alignList:FastList<Vehicle>, ?cohereList:FastList<Vehicle>)
		{
			super();
			separate = new Separation(separateList);
			align = new Alignment(alignList);
			cohere = new Cohesion(cohereList);
		}

		public override function apply(veh:Vehicle):Void
		{
			separate.apply(veh);
			align.apply(veh);
			cohere.apply(veh);
		}
	}
