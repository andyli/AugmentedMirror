package;

import haxe.io.Bytes;
import haxe.io.BytesInput;

import sandy.core.scenegraph.ATransformable;

import org.casalib.math.geom.Point3d;

using org.casalib.util.ArrayUtil;

class CameraUpdater extends Updater {
	public var camera0(default,null):ATransformable;
	public var camera1(default,null):ATransformable;
	
	public var detectionIsActive:Bool;
	
	public function new(camera0:ATransformable,camera1:ATransformable, socketUrlAndPort:String, readyByte:Int = 8){
		super(socketUrlAndPort, readyByte);
		
		this.camera0 = camera0;
		this.camera1 = camera1;
		
		detectionIsActive = false;
		
		inputSize = 6*4;
	}
	
	override private function updateTarget(bytes:Bytes):Void {
		var input = new BytesInput(bytes);
		var values = [input.readFloat(),input.readFloat(),input.readFloat(),input.readFloat(),input.readFloat(),input.readFloat()];
		if ([-1.0].containsAll(values)){
			detectionIsActive = false;
		} else {
			#if cpp
			values.reverse();
			#end
			
			camera0.x = values[0];
			camera0.y = values[1];
			camera0.z = values[2];
			camera1.x = values[3];
			camera1.y = values[4];
			camera1.z = values[5];
			//trace(Lambda.map(values,function(i){return Math.round(i);}));
			//var pt0 = new Point3d(camera0.x,camera0.y,camera0.z);
			//var pt1 = new Point3d(camera1.x,camera1.y,camera1.z);
			//trace(Point3d.distance(pt0,pt1));
			
			detectionIsActive = true;
		}
	}
}
