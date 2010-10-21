package hxcv.ds;

interface IGray2DImage<T> implements I2DImage<T> {
	public function getGray(x:Int, y:Int):T;
	public function setGray(x:Int, y:Int, val:T):Void;
}