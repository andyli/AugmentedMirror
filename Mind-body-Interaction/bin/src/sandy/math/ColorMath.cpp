#include <hxcpp.h>

#ifndef INCLUDED_hxMath
#include <hxMath.h>
#endif
#ifndef INCLUDED_Std
#include <Std.h>
#endif
#ifndef INCLUDED_sandy_math_ColorMath
#include <sandy/math/ColorMath.h>
#endif
namespace sandy{
namespace math{

Void ColorMath_obj::__construct()
{
	return null();
}

ColorMath_obj::~ColorMath_obj() { }

Dynamic ColorMath_obj::__CreateEmpty() { return  new ColorMath_obj; }
hx::ObjectPtr< ColorMath_obj > ColorMath_obj::__new()
{  hx::ObjectPtr< ColorMath_obj > result = new ColorMath_obj();
	result->__construct();
	return result;}

Dynamic ColorMath_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< ColorMath_obj > result = new ColorMath_obj();
	result->__construct();
	return result;}

int ColorMath_obj::applyAlpha( int c,double a){
	__SAFE_POINT
	int a0 = ::Std_obj::toInt((double(c) / double(16777216)));
	return (((int(c) & int(16777215))) + (::Math_obj::floor((a * a0)) * 16777216));
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(ColorMath_obj,applyAlpha,return )

int ColorMath_obj::rgb2hex( int r,int g,int b){
	return ((int(((int(((int(r) << int(16)))) | int(((int(g) << int(8))))))) | int(b)));
}


STATIC_HX_DEFINE_DYNAMIC_FUNC3(ColorMath_obj,rgb2hex,return )

Dynamic ColorMath_obj::hex2rgb( int hex){
	double r;
	double g;
	double b;
	r = (int(((int(16711680) & int(hex)))) >> int(16));
	g = (int(((int(65280) & int(hex)))) >> int(8));
	b = ((int(255) & int(hex)));
	struct _Function_1_1{
		inline static Dynamic Block( double &b,double &g,double &r){
			hx::Anon __result = hx::Anon_obj::Create();
			__result->Add(HX_STRING(L"r",1) , r);
			__result->Add(HX_STRING(L"g",1) , g);
			__result->Add(HX_STRING(L"b",1) , b);
			return __result;
		}
	};
	return _Function_1_1::Block(b,g,r);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(ColorMath_obj,hex2rgb,return )

Dynamic ColorMath_obj::hex2rgbn( int hex){
	double r;
	double g;
	double b;
	r = (int(((int(16711680) & int(hex)))) >> int(16));
	g = (int(((int(65280) & int(hex)))) >> int(8));
	b = ((int(255) & int(hex)));
	struct _Function_1_1{
		inline static Dynamic Block( double &b,double &g,double &r){
			hx::Anon __result = hx::Anon_obj::Create();
			__result->Add(HX_STRING(L"r",1) , (double(r) / double(255)));
			__result->Add(HX_STRING(L"g",1) , (double(g) / double(255)));
			__result->Add(HX_STRING(L"b",1) , (double(b) / double(255)));
			return __result;
		}
	};
	return _Function_1_1::Block(b,g,r);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(ColorMath_obj,hex2rgbn,return )

double ColorMath_obj::calculateLitColour( int col,double lightStrength){
	__SAFE_POINT
	double r = (int(((int(col) >> int(16)))) & int(255));
	double g = (int(((int(col) >> int(8)))) & int(255));
	double b = (int((col)) & int(255));
	hx::MultEq(r,0.00390625);
	hx::MultEq(g,0.00390625);
	hx::MultEq(b,0.00390625);
	double min = 0.0;
	double mid = 0.0;
	double max = 0.0;
	double delta = 0.0;
	double l = 0.0;
	double s = 0.0;
	double h = 0.0;
	double F = 0.0;
	int n = 0;
	Array< double > a = Array_obj< double >::__new().Add(r).Add(g).Add(b);

	HX_BEGIN_LOCAL_FUNC0(_Function_1_1)
	int run(double a1,double b1){
{
			return (((a1 > b1)) ? int( 1 ) : int( ((a1 < b1)) ? int( -1 ) : int( 0 ) ));
		}
		return null();
	}
	HX_END_LOCAL_FUNC2(return)

	a->sort( Dynamic(new _Function_1_1()));
	min = a->__get(0);
	mid = a->__get(1);
	max = a->__get(2);
	double range = (max - min);
	l = (((min + max)) * 0.5);
	if ((l == 0)){
		s = 1;
	}
	else{
		delta = (range * 0.5);
		if ((l < 0.5)){
			s = (double(delta) / double(l));
		}
		else{
			s = (double(delta) / double(((1 - l))));
		}
		if ((range != 0)){
			while(true){
				__SAFE_POINT
				if ((r == max)){
					if ((b == min)){
						n = 0;
					}
					else{
						n = 5;
					}
					break;
				}
				if ((g == max)){
					if ((b == min)){
						n = 1;
					}
					else{
						n = 2;
					}
					break;
				}
				if ((r == min)){
					n = 3;
				}
				else{
					n = 4;
				}
				break;
			}
			if (((hx::Mod(n,2)) == 0)){
				F = (mid - min);
			}
			else{
				F = (max - mid);
			}
			F = (double(F) / double(range));
			h = (60 * ((n + F)));
		}
	}
	if ((lightStrength < 0.5)){
		delta = (s * lightStrength);
	}
	else{
		delta = (s * ((1 - lightStrength)));
	}
	min = (lightStrength - delta);
	max = (lightStrength + delta);
	n = ::Math_obj::floor((double(h) / double(60)));
	F = (double(((((h - (n * 60))) * delta))) / double(30));
	hx::ModEq(n,6);
	double mu = (min + F);
	double md = (max - F);
	switch( (int)(n)){
		case 0: {
			r = max;
			g = mu;
			b = min;
		}
		;break;
		case 1: {
			r = md;
			g = max;
			b = min;
		}
		;break;
		case 2: {
			r = min;
			g = max;
			b = mu;
		}
		;break;
		case 3: {
			r = min;
			g = md;
			b = max;
		}
		;break;
		case 4: {
			r = mu;
			g = min;
			b = max;
		}
		;break;
		case 5: {
			r = max;
			g = min;
			b = md;
		}
		;break;
	}
	return ((int(((int((int(::Std_obj::toInt((r * 256))) << int(16))) | int((int(::Std_obj::toInt((g * 256))) << int(8)))))) | int(::Std_obj::toInt((b * 256)))));
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(ColorMath_obj,calculateLitColour,return )


ColorMath_obj::ColorMath_obj()
{
}

void ColorMath_obj::__Mark()
{
}

Dynamic ColorMath_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 7:
		if (!memcmp(inName.__s,L"rgb2hex",sizeof(wchar_t)*7) ) { return rgb2hex_dyn(); }
		if (!memcmp(inName.__s,L"hex2rgb",sizeof(wchar_t)*7) ) { return hex2rgb_dyn(); }
		break;
	case 8:
		if (!memcmp(inName.__s,L"hex2rgbn",sizeof(wchar_t)*8) ) { return hex2rgbn_dyn(); }
		break;
	case 10:
		if (!memcmp(inName.__s,L"applyAlpha",sizeof(wchar_t)*10) ) { return applyAlpha_dyn(); }
		break;
	case 18:
		if (!memcmp(inName.__s,L"calculateLitColour",sizeof(wchar_t)*18) ) { return calculateLitColour_dyn(); }
	}
	return super::__Field(inName);
}

Dynamic ColorMath_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	return super::__SetField(inName,inValue);
}

void ColorMath_obj::__GetFields(Array< ::String> &outFields)
{
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_STRING(L"applyAlpha",10),
	HX_STRING(L"rgb2hex",7),
	HX_STRING(L"hex2rgb",7),
	HX_STRING(L"hex2rgbn",8),
	HX_STRING(L"calculateLitColour",18),
	String(null()) };

static ::String sMemberFields[] = {
	String(null()) };

static void sMarkStatics() {
};

Class ColorMath_obj::__mClass;

void ColorMath_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_STRING(L"sandy.math.ColorMath",20), hx::TCanCast< ColorMath_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void ColorMath_obj::__boot()
{
}

} // end namespace sandy
} // end namespace math
