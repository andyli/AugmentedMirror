package ru.inspirit.steering; 

	import haxe.FastList;
	
	import ru.inspirit.steering.behavior.AbstractBehavior;
	import ru.inspirit.steering.behavior.BehaviorList;

	/**
	 * Vehicle Group
	 * simple way to control large number of vehicles
	 * 
	 * @author Eugene Zatepyakin
	 */
	class VehicleGroup 
	 {
		inline public function iterator():Iterator<Vehicle> {
			return fastList.iterator();
		}

		public function toFastList():FastList<Vehicle> {
			var fl = new FastList<Vehicle>();
			for (i in this) {
				fl.add(i);
			}
			return fl;
		}

		private var fastList:FastList<Vehicle>;
		
		public var vehicleFirst(getVehicleFirst,null):Vehicle;

		private function getVehicleFirst():Vehicle {
			return fastList.first();
		}
		
		public var defaultBehavior:BehaviorList;
		
		/**
		 * @param defaultBehavior	is used if Vehicle doesn't have any
		 */
		public function new(defaultBehavior:BehaviorList)
		{
			this.defaultBehavior = defaultBehavior;
			fastList = new FastList<Vehicle>();
		}
		
		/**
		 * Update all vehicles in group
		 */
		public function update():Void
		{	
			for (veh in fastList) 
			{
				for (behave in veh.behaviorList != null ? veh.behaviorList : defaultBehavior)
				{
					behave.apply(veh);
				}
				
				veh.update();
			}
		}
		
		/**
		 * Add vehicle to group
		 * 
		 * @param veh	Vehicle object to add
		 */
		public function addVehicle(veh:Vehicle):Void
		{
			fastList.add(veh);
		}
		
		/**
		 * Remove vehicle from group
		 * 
		 * @param veh	Vehicle to remove
		 */
		public function removeVehicle(veh:Vehicle):Void
		{
			fastList.remove(veh);
		}
		
		/**
		 * Remove all Vehicles
		 */
		public function clear():Void
        {
			for (i in fastList){
				fastList.remove(i);
			}
        }
	}
