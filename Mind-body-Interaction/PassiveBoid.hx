import hxSteeringBehaviors.Vehicle;
using hxSteeringBehaviors.Float3DTools;
import hxSteeringBehaviors.Float3D;

import sandy.core.data.Point3D;
import sandy.core.data.Matrix4;

class PassiveBoid extends Vehicle {
	public var position3D:Float3D;
	public var mat:Matrix4;

	public function new(position3D:Float3D, ?mat:Matrix4){
		super();
		
		this.position3D = position3D;
		if (mat != null) this.mat = mat;
		updatePosition();
	}
	
	override public function update():Void {
		updatePosition();
	}
	
	inline private function updatePosition():Void {
		var pt:Float3D;
		if (mat == null){
			pt = position3D;
		} else {
			var p = new Point3D();
			p.setToVector(position3D);
			mat.transform(p);
			pt = p;
		}
		position.setToVector(pt);
	}
}
