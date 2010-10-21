package hxcv.ds.of;

import haxe.io.Bytes;
import haxe.io.BytesInput;
import hxcv.ds.I2DImage;
import hxcv.ds.IGray2DImage;
import of.graphics.Image;
import of.utils.Constants;

class OFGray2DImage implements IGray2DImage<Int>
{
	public function new(img:Image):Void {
		if (img.type != Constants.OF_IMAGE_GRAYSCALE) throw "Input is not a grayscale image.";
		
		ofImage = img;
		width = img.width;
		height = img.height;
		pixels = Bytes.ofData(img.getPixels());
		numOfChannels = 1;
	}
	
	inline public function get(x:Int, y:Int, channel:Int):Int {
		#if debug
		if (channel != 0)
			throw "image does not have channel " + channel;
		#end
		return pixels.get(y * width + x + channel);
	}
	
	inline public function getHex(x:Int, y:Int, ?alpha:Null<Int>):Int {
		var g = pixels.get(y * width + x);
		return g << 16 ^ g << 8 ^ g;
	}
	
	inline public function set(x:Int, y:Int, channel:Int, val:Int):Void {
		#if debug
		if (channel != 0)
			throw "image does not have channel " + channel;
		#end
		pixels.set(y * width + x + channel, val);
	}
	
	inline public function setHex(x:Int, y:Int, val:Int):Void {
		pixels.set(y * width + x, Std.int(0.3*(val >> 16 & 0xFF) + 0.59*(val >> 8 & 0xFF) + 0.11*(val & 0xFF)));
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
		return new OFGray2DImage(img);
	}
	
	public var width(default, null):Int;
	public var height(default, null):Int;
	public var numOfChannels(default, null):Int;
	
	inline public function iterator():Iterator<Int> {
		return cast pixels.getData().iterator();
	}
	
	public var ofImage(default, null):Image;
	var pixels:Bytes;
	
	inline public function getGray(x:Int, y:Int):Int {
		return get(x, y, 0);
	}
	
	inline public function setGray(x:Int, y:Int, val:Int):Void {
		set(x, y, 0, val);
	}
}