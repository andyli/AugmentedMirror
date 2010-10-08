package hxcv.ds;

interface I2DImage<T>{
	public function get(x:Int, y:Int, channel:Int):T;
	public function getHex(x:Int, y:Int, ?alpha:Null<Int>):Int;
	public function set(x:Int, y:Int, channel:Int, val:T):Void;
	public function setHex(x:Int, y:Int, val:T):Void;
	public function getPixels():Array<T>;
	public function setPixels(src:Array<T>):Void;
	public function lock():Void;
	public function unlock():Void;
	public function clone():I2DImage<T>;
	public var width(default, null):Int;
	public var height(default, null):Int;
	public var numOfChannels(default, null):Int;
	public function iterator():Iterator<T>;
}