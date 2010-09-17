package ru.inspirit.steering; 

	import flash.geom.Vector3D;
	
	/**
	 * Steer Vector is based on Vector3D
	 * with some additional methods
	 * 
	 * @author Eugene Zatepyakin
	 */
	class SteerVector3D {
		
		inline public static var ZERO:Float3D = new Vector3D();
		
		public static var seed:UInt = 1;//int(Math.random() * 0x7FFFFFFE) + 1;
		
		inline static public function setTo(that:Float3D, ?x:Float = 0, ?y:Float = 0, ?z:Float = 0):Void
		{
			that.x = x;
			that.y = y;
			that.z = z;
		}
		
		inline static public function setToVector(that:Float3D, v:Float3D):Void
		{
			that.x = v.x;
			that.y = v.y;
			that.z = v.z;
		}
		
		inline static public function setZero(that:Float3D):Void
		{
			that.x = that.y = that.z = 0;
		}
		
		inline static public function equalsZero(that:Float3D):Bool
		{	
			return (that.x == 0) && (that.y == 0) && (that.z == 0);
		}
		
		inline static public function setSum(that:Float3D, a:Float3D, b:Float3D):Void
		{
			that.x = a.x + b.x;
			that.y = a.y + b.y;
			that.z = a.z + b.z;
		}

		inline static public function scale(that:Float3D, factor:Float):Vector3D
		{
			return new Vector3D(that.x * factor, that.y * factor, that.z * factor);
		}
		
		inline static public function setScale(that:Float3D, factor:Float, other:Float3D):Void
		{
			that.x = other.x * factor;
			that.y = other.y * factor;
			that.z = other.z * factor;
		}

		inline static public function magnitudeSquared(that:Float3D):Float
		{
			return that.x * that.x + that.y * that.y + that.z * that.z;
		}

		inline static public function magnitude(that:Float3D):Float
		{
			return Math.sqrt( that.x * that.x + that.y * that.y + that.z * that.z );
		}

		public static function truncate(that:Float3D, threshold:Float):Float3D
		{
			var lengthSquared:Float = that.x * that.x + that.y * that.y + that.z * that.z;
			
			if(lengthSquared > threshold * threshold)
			{
				var factor:Float = threshold / Math.sqrt(lengthSquared);
				return new Vector3D(that.x * factor, that.y * factor, that.z * factor);
			} 
			else
			{
				return that;
			}
		}
		
		inline static public function setApproximateTruncate(that:Float3D, threshold:Float):Void
		{
			var length:Float = approximateLength(that);
			if (length > threshold) {
				length = threshold / length;
				that.x *= length;
				that.y *= length;
				that.z *= length;
			}
		}
		
		public static function approximateTruncate(that:Float3D, threshold:Float):Float3D
		{
			var length:Float = approximateLength(that);
			if(length > threshold)
			{
				var factor:Float = threshold / length;
				return new Vector3D(that.x * factor, that.y * factor, that.z * factor);
			}
			else
			{
				return that;
			}
		}

		inline static public function dot(that:Float3D, target:Float3D):Float
		{
			return target.x * that.x + target.y * that.y + target.z * that.z;
		}

		inline static public function cross(that:Float3D, target:Float3D):Vector3D
		{
			return new Vector3D(that.y * target.z - that.z * target.y, that.z * target.x - that.x * target.z, that.x * target.y - that.y * target.x);
		}
		
		inline static public function setDiff(that:Float3D, a:Float3D, b:Float3D):Void
		{
			that.x = a.x - b.x;
			that.y = a.y - b.y;
			that.z = a.z - b.z;
		}
		
		inline static public function setCross(that:Float3D, a:Float3D, b:Float3D):Void
		{
			that.x = a.y * b.z - a.z * b.y;
			that.y = a.z * b.x - a.x * b.z;
			that.z = a.x * b.y - a.y * b.x;
		}
		
		public static function setUnitRandom(that:Float3D):Void
		{
			do
			{
				that.x = random() * 2 - 1;
				that.y = random() * 2 - 1;
				that.z = random() * 2 - 1;
			} while((that.x * that.x + that.y * that.y + that.z * that.z) > 1);
		}

		public static function unitRandom():Vector3D
		{
			var x:Int = 0, y:Int = 0, z:Int = 0;
			do
			{
				x = cast random() * 2 - 1;
				y = cast random() * 2 - 1;
				z = cast random() * 2 - 1;
			} while((x * x + y * y + z * z) > 1);
			
			return new Vector3D(x, y, z);
		}

		inline static public function approximateLength(that:Float3D):Float
		{
			var a:Float = that.x;
			if (a < 0) a = -a;
			
			var b:Float = that.y;
			if (b < 0) b = -b;
			
			var c:Float = that.z;
			if (c < 0) c = -c;
			
			var t:Float;
			if(a < b) {
				t = a;
				a = b;
				b = t;
			}
			if(a < c) {
				t = a;
				a = c;
				c = t;
			}
			return a * 0.9375 + (b + c) * 0.375;
		}
		
		inline static public function distance(that:Float3D, v:Float3D):Float
		{
			var xd:Float = that.x - v.x;
			var yd:Float = that.y - v.y;
			var zd:Float = that.z - v.z;
			
			return Math.sqrt( xd * xd + yd * yd + zd * zd );
		}
		
		inline static public function approximateDistance(that:Float3D, v:Float3D):Float
		{
			var xd:Float = that.x - v.x;
			var yd:Float = that.y - v.y;
			var zd:Float = that.z - v.z;
			
			var a:Float = xd;
			if (a < 0) a = -a;
			
			var b:Float = yd;
			if (b < 0) b = -b;
			
			var c:Float = zd;
			if (c < 0) c = -c;
			
			var t:Float;
			if(a < b) {
				t = a;
				a = b;
				b = t;
			}
			if(a < c) {
				t = a;
				a = c;
				c = t;
			}
			return a * 0.9375 + (b + c) * 0.375;
		}
		
		inline static public function setApproximateNormalize(that:Float3D):Void
		{
			var m:Float = approximateLength(that);
			if(m != 0) 
			{
				m = 1 / m;
				that.x *= m;
				that.y *= m;
				that.z *= m;
			}
		}

		public static function approximateNormalize(that:Float3D):Float3D
		{
			var m:Float = approximateLength(that);
			if(m == 0)
			{
				return that;
			}
			else
			{		
				m = 1 / m;
				return new Vector3D(that.x * m, that.y * m, that.z * m);
			}
		}
		
		inline static public function setInterp(that:Float3D, blend:Float, v0:Float3D, v1:Float3D):Void
		{
			that.x = v0.x + blend * (v1.x - v0.x);
			that.y = v0.y + blend * (v1.y - v0.y);
			that.z = v0.z + blend * (v1.z - v0.z);
		}
		
		public static function setNormalize(that:Float3D):Void
		{
			var m:Float = Math.sqrt( that.x * that.x + that.y * that.y + that.z * that.z );
			if(m != 0) 
			{
				m = 1 / m;
				that.x *= m;
				that.y *= m;
				that.z *= m;
			}
		}
		
		inline static public function parallelComponent (that:Float3D, unitBasis:Float3D):Vector3D
        {
            var projection:Float = dot(that,unitBasis);
            return scale(unitBasis,projection);
        }

        // return component of vector perpendicular to a unit basis vector
        // (IMPORTANT NOTE: assumes "basis" has unit magnitude (length==1))

        /*public function perpendicularComponent (unitBasis:Float3D):Float3D
        {
            return subtract(parallelComponent(unitBasis));
        }*/
        
        inline public static function random():Float
        {
        		return (seed = (seed * 16807) % 2147483647) / 2147483647;
        }
	}
