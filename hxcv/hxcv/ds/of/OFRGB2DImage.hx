package hxcv.ds.of;

import haxe.io.Bytes;
import haxe.io.BytesInput;
import hxcv.ds.I2DImage;
import hxcv.ds.IRGB2DImage;
import of.graphics.Image;
import of.utils.Constants;

class OFRGB2DImage implements IRGB2DImage<Int>
{
	public function new(img:Image):Void {
		if (img.type != Constants.OF_IMAGE_COLOR) throw "Input is not a OF_IMAGE_COLOR image.";
		ofImage = img;
		width = img.width;
		height = img.height;
		pixels = Bytes.ofData(img.getPixels());
		numOfChannels = 3;
	}
	
	inline public function get(x:Int, y:Int, channel:Int):Int {
		#if debug
		if (channel < 0 || channel >= 3)
			throw "image does not have channel " + channel;
		#end
		return pixels.get((y * width + x) * 3 + channel);
	}
	
	inline public function getHex(x:Int, y:Int, ?alpha:Null<Int>):Int {
		return (alpha == null ? 0xFF : alpha) | (new BytesInput(pixels, (y * width + x) * 3).readInt24());
	}
	
	inline public function set(x:Int, y:Int, channel:Int, val:Int):Void {
		#if debug
		if (channel < 0 || channel >= 3)
			throw "image does not have channel " + channel;
		#end
		pixels.set((y * width + x) * 3 + channel, val);
	}
	
	inline public function setHex(x:Int, y:Int, val:Int):Void {
		var pos = (y * width + x) * 3;

		pixels.set(pos, val >> 16 & 0xFF);
		pixels.set(++pos, val >> 8 & 0xFF);
		pixels.set(++pos, val & 0xFF);
	}
	
	inline public function getPixels():Array<Int> {
		return cast pixels.getData();
	}
	
	inline public function setPixels(src:Array<Int>):Void {
		ofImage.setFromPixels(cast src, width, height, ofImage.type);
	}
	
	
	inline public function lock():Void {}
	inline public function unlock():Void {
		ofImage.update();
	}
	
	inline public function clone():I2DImage<Int> {
		var img = new Image();
		img.clone(ofImage);
		return new OF2DImage(img);
	}
	
	public var width(default, null):Int;
	public var height(default, null):Int;
	public var numOfChannels(default, null):Int;
	
	inline public function iterator():Iterator<Int> {
		return cast pixels.getData().iterator();
	}
	
	public var ofImage(default, null):Image;
	var pixels:Bytes;
	
	
	inline public function getR(x:Int, y:Int):Int {
		return get(x, y, 0);
	}
	
	inline public function setR(x:Int, y:Int, val:Int):Void {
		set(x, y, 0, val);
	}
	
	inline public function getG(x:Int, y:Int):Int {
		return get(x, y, 1);
	}
	
	inline public function setG(x:Int, y:Int, val:Int):Void {
		set(x, y, 1, val);
	}
	
	inline public function getB(x:Int, y:Int):Int {
		return get(x, y, 2);
	}
	
	inline public function setB(x:Int, y:Int, val:Int):Void {
		set(x, y, 2, val);
	}
}