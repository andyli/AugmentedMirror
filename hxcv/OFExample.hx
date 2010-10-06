package ;

import cpp.Lib;
import hxcv.ds.of.OF2DImage;
import of.app.BaseApp;
import of.graphics.Image;
import of.utils.Constants;

using of.helpers.OpenFrameworksContext;

class OFExample extends BaseApp {
	var img:OF2DImage;
	var ofImg:Image;
	
	override function setup():Void {
		ofImg = new Image();
		ofImg.allocate(200, 100, Constants.OF_IMAGE_COLOR);
		
		img = new OF2DImage(ofImg);
		
		trace(img.width);
		trace(img.height);
		img.lock();
		for (i in 0...img.width) {
			for (j in 0...img.height) {
				img.setHex(i, j, 0xFF0000);
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