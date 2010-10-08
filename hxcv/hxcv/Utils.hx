package hxcv;

class Utils {
	/**
	 * Return the number of bits of the data.
	 */
	static public function sizeOf<T>(c:Class<T>):Int {
		return switch (c) {
			case Int:
				#if !neko 
					32;
				#else;
					31;
				#end
			#if flash9
			case UInt: 32;
			#end
			case Float: 64;
			default: throw "Only number types' sizes are known.";
		}
	}
}