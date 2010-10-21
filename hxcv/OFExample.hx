package ;

import cpp.Lib;
import hxcv.ds.of.OFGray2DImage;
import hxcv.ds.of.OFRGB2DImage;
import hxcv.ds.of.OFARGB2DImage;

import of.Context;
using of.Context.Functions;

class OFExample extends BaseApp {
	var img:OFARGB2DImage;
	var ofImg:Image;
	
	override function setup():Void {
		ofImg = new Image();
		ofImg.allocate(200, 100, Constants.OF_IMAGE_COLOR_ALPHA);
		
		img = new OFARGB2DImage(ofImg);
		
		enableAlphaBlending();
		img.lock();
		for (i in 0...img.width) {
			for (j in 0...img.height) {
				//img.setHex(i, j, 0x11FF0000);
				img.set(i, j, 0, 0xFF);
				img.setA(i, j, 0x11);
			}
		}
		img.unlock();
	}
	
	override function draw():Void {
		img.ofImage.draw(100, 100);
	}
	
	static function main():Void {
		setupOpenGL(new of.app.AppGlutWindow(), 1024, 768, Constants.OF_WINDOW);
		runApp(new OFExample());
	}
}