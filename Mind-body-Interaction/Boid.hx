import hxSteeringBehaviors.Vehicle;
using hxSteeringBehaviors.Float3DTools;

import sandy.core.scenegraph.ATransformable;

class Boid extends Vehicle {
	public var shape3D:ATransformable;

	public function new(shape3D:ATransformable){
		super();
		
		this.shape3D = shape3D;
		position.setToVector(shape3D.getPosition());
	}
	
	override public function update():Void {
		super.update();
		
		shape3D.setPosition(position.x,position.y,position.z);
		var pt = position.add(forward);
		shape3D.lookAt(pt.x,pt.y,pt.z);
	}
}
