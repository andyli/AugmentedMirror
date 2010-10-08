package hxcv.ds;

interface IARGB2DImage<T> implements IRGB2DImage<T> {
	public function getA(x:Int, y:Int):T;
	public function setA(x:Int, y:Int, val:T):Void;
}