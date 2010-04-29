package ru.inspirit.steering.behavior; 

	import haxe.FastList;

	/**
	 * Behavior list is based on Linked List structure
	 * Every Vehicle have a list of behaviors to apply
	 * 
	 * @author Eugene Zatepyakin
	 */
	 class BehaviorList 
	 {
		inline public function iterator():Iterator<AbstractBehavior> {
			return fastList.iterator();
		}

		public function toFastList():FastList<AbstractBehavior> {
			var fl = new FastList<AbstractBehavior>();
			for (i in this) {
				fl.add(i);
			}
			return fl;
		}


		private var fastList:FastList<AbstractBehavior>;
		
		public var behaviorFirst(getBehaviorFirst,null):AbstractBehavior;

		private function getBehaviorFirst():AbstractBehavior {
			return fastList.first();
		}
		
		public function new(args:Iterable<AbstractBehavior>)
		{
			fastList = new FastList<AbstractBehavior>();
			addBehavior(args);
		}
		
		/**
		 * @param args	comma separated list of Behaviors to add
		 */
		public function addBehavior(args:Iterable<AbstractBehavior>):Void
		{
			for (i in args){
				fastList.add(i);
			}
		}
		
		public function removeBehavior(behave:AbstractBehavior):Void
		{
			fastList.remove(behave);
		}
		
		public function clear():Void
        {
			for (i in fastList) {
				fastList.remove(i);
			}
        }
	}
