package;

import flash.display.Bitmap;
import flash.display.BitmapData;
import flash.events.Event;

import haxe.io.Bytes;
import haxe.io.BytesInput;

import sandy.primitive.Plane3D;
import sandy.core.data.Vertex;
import sandy.materials.Appearance;
import sandy.materials.BitmapMaterial;

import org.casalib.util.ColorUtil;

class PlaneUpdater extends Updater {
	public var plane(default,null):Plane3D;
	
	public var bm:Bitmap;
	public var bd:BitmapData;
	
	public var positionSize(default,null):Int;
	public var colorSize(default,null):Int;

	public function new(plane:Plane3D, socketUrlAndPort:String, readyByte:Int = 8){
		super(socketUrlAndPort, readyByte);
		
		this.plane = plane;
		
		positionSize = plane.geometry.aVertex.length*3*4;
		colorSize = plane.geometry.aVertex.length*3;
		
		inputSize = positionSize + colorSize;
		
		bd = new BitmapData(32, 24, false);
		bm = new Bitmap(bd);
		
		var bitmapMat:BitmapMaterial = new BitmapMaterial(bd);
		plane.appearance = new Appearance(bitmapMat);
	}
	
	override private function updateTarget(bytes:Bytes):Void {
		updatePlane(bytes.sub(0, positionSize));
		updateBitmap(bytes.sub(positionSize, colorSize));
	}
	
	private function updateBitmap(bytes:Bytes):Void {
		var data = bytes.getData();
		var i = 0;
		var pixelNum = 0;
		bd.lock();
		while (i < data.length) {
			var r:Int = cast data[i++];
			var g:Int = cast data[i++];
			var b:Int = cast data[i++];
			bd.setPixel(pixelNum%32,23-Math.floor(pixelNum/32),ColorUtil.getColor(r,g,b));
			pixelNum++;
		}
		bd.unlock();
	}
	
	private function updatePlane(bytes:Bytes):Void {
		var inp = new BytesInput(bytes);
		inp.bigEndian = false;
	
		var t = plane.geometry.aVertex.length;
		var v:Vertex;
		for (i in 0...t) {
			v = plane.geometry.aVertex[i];
			v.x = inp.readFloat();
			v.y = inp.readFloat();
			v.z = inp.readFloat();
		}
	
		inp.close();
		
		plane.changed = true;
	}
}
