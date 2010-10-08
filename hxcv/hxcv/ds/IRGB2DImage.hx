package hxcv.ds;

interface IRGB2DImage<T> implements I2DImage<T> {
	public function getR(x:Int, y:Int):T;
	public function setR(x:Int, y:Int, val:T):Void;
	public function getG(x:Int, y:Int):T;
	public function setG(x:Int, y:Int, val:T):Void;
	public function getB(x:Int, y:Int):T;
	public function setB(x:Int, y:Int, val:T):Void;
}