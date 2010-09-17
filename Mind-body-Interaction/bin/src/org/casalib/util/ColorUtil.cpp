#include <hxcpp.h>

#ifndef INCLUDED_StringTools
#include <StringTools.h>
#endif
#ifndef INCLUDED_nme_geom_ColorTransform
#include <nme/geom/ColorTransform.h>
#endif
#ifndef INCLUDED_org_casalib_math_Percent
#include <org/casalib/math/Percent.h>
#endif
#ifndef INCLUDED_org_casalib_util_ColorUtil
#include <org/casalib/util/ColorUtil.h>
#endif
namespace org{
namespace casalib{
namespace util{

Void ColorUtil_obj::__construct()
{
	return null();
}

ColorUtil_obj::~ColorUtil_obj() { }

Dynamic ColorUtil_obj::__CreateEmpty() { return  new ColorUtil_obj; }
hx::ObjectPtr< ColorUtil_obj > ColorUtil_obj::__new()
{  hx::ObjectPtr< ColorUtil_obj > result = new ColorUtil_obj();
	result->__construct();
	return result;}

Dynamic ColorUtil_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< ColorUtil_obj > result = new ColorUtil_obj();
	result->__construct();
	return result;}

::nme::geom::ColorTransform ColorUtil_obj::interpolateColor( ::nme::geom::ColorTransform begin,::nme::geom::ColorTransform end,::org::casalib::math::Percent amount){
	::nme::geom::ColorTransform interpolation = ::nme::geom::ColorTransform_obj::__new(null(),null(),null(),null(),null(),null(),null(),null());
	struct _Function_1_1{
		inline static double Block( ::nme::geom::ColorTransform &end,::nme::geom::ColorTransform &begin,::org::casalib::math::Percent &amount)/* DEF (ret block)(not intern) */{
			double begin1 = begin->redMultiplier;
			return (begin1 + (((end->redMultiplier - begin1)) * amount->_percent));
		}
	};
	interpolation->redMultiplier = _Function_1_1::Block(end,begin,amount);
	struct _Function_1_2{
		inline static double Block( ::nme::geom::ColorTransform &end,::nme::geom::ColorTransform &begin,::org::casalib::math::Percent &amount)/* DEF (ret block)(not intern) */{
			double begin1 = begin->greenMultiplier;
			return (begin1 + (((end->greenMultiplier - begin1)) * amount->_percent));
		}
	};
	interpolation->greenMultiplier = _Function_1_2::Block(end,begin,amount);
	struct _Function_1_3{
		inline static double Block( ::nme::geom::ColorTransform &end,::nme::geom::ColorTransform &begin,::org::casalib::math::Percent &amount)/* DEF (ret block)(not intern) */{
			double begin1 = begin->blueMultiplier;
			return (begin1 + (((end->blueMultiplier - begin1)) * amount->_percent));
		}
	};
	interpolation->blueMultiplier = _Function_1_3::Block(end,begin,amount);
	struct _Function_1_4{
		inline static double Block( ::nme::geom::ColorTransform &end,::nme::geom::ColorTransform &begin,::org::casalib::math::Percent &amount)/* DEF (ret block)(not intern) */{
			double begin1 = begin->alphaMultiplier;
			return (begin1 + (((end->alphaMultiplier - begin1)) * amount->_percent));
		}
	};
	interpolation->alphaMultiplier = _Function_1_4::Block(end,begin,amount);
	struct _Function_1_5{
		inline static double Block( ::nme::geom::ColorTransform &end,::nme::geom::ColorTransform &begin,::org::casalib::math::Percent &amount)/* DEF (ret block)(not intern) */{
			double begin1 = begin->redOffset;
			return (begin1 + (((end->redOffset - begin1)) * amount->_percent));
		}
	};
	interpolation->redOffset = _Function_1_5::Block(end,begin,amount);
	struct _Function_1_6{
		inline static double Block( ::nme::geom::ColorTransform &end,::nme::geom::ColorTransform &begin,::org::casalib::math::Percent &amount)/* DEF (ret block)(not intern) */{
			double begin1 = begin->greenOffset;
			return (begin1 + (((end->greenOffset - begin1)) * amount->_percent));
		}
	};
	interpolation->greenOffset = _Function_1_6::Block(end,begin,amount);
	struct _Function_1_7{
		inline static double Block( ::nme::geom::ColorTransform &end,::nme::geom::ColorTransform &begin,::org::casalib::math::Percent &amount)/* DEF (ret block)(not intern) */{
			double begin1 = begin->blueOffset;
			return (begin1 + (((end->blueOffset - begin1)) * amount->_percent));
		}
	};
	interpolation->blueOffset = _Function_1_7::Block(end,begin,amount);
	struct _Function_1_8{
		inline static double Block( ::nme::geom::ColorTransform &end,::nme::geom::ColorTransform &begin,::org::casalib::math::Percent &amount)/* DEF (ret block)(not intern) */{
			double begin1 = begin->alphaOffset;
			return (begin1 + (((end->alphaOffset - begin1)) * amount->_percent));
		}
	};
	interpolation->alphaOffset = _Function_1_8::Block(end,begin,amount);
	return interpolation;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC3(ColorUtil_obj,interpolateColor,return )

int ColorUtil_obj::getColor( int r,int g,int b,Dynamic __o_a){
int a = __o_a.Default(255);
{
		return (((((((int(a) << int(24))) + ((int(r) << int(16))))) + ((int(g) << int(8))))) + b);
	}
}


STATIC_HX_DEFINE_DYNAMIC_FUNC4(ColorUtil_obj,getColor,return )

Dynamic ColorUtil_obj::getARGB( int color){
	struct _Function_1_1{
		inline static Dynamic Block( int &color){
			hx::Anon __result = hx::Anon_obj::Create();
			__result->Add(HX_STRING(L"a",1) , (int((int(color) >> int(24))) & int(255)));
			__result->Add(HX_STRING(L"r",1) , (int((int(color) >> int(16))) & int(255)));
			__result->Add(HX_STRING(L"g",1) , (int((int(color) >> int(8))) & int(255)));
			__result->Add(HX_STRING(L"b",1) , (int(color) & int(255)));
			return __result;
		}
	};
	return _Function_1_1::Block(color);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(ColorUtil_obj,getARGB,return )

Dynamic ColorUtil_obj::getRGB( int color){
	struct _Function_1_1{
		inline static Dynamic Block( int &color){
			hx::Anon __result = hx::Anon_obj::Create();
			__result->Add(HX_STRING(L"r",1) , (int((int(color) >> int(16))) & int(255)));
			__result->Add(HX_STRING(L"g",1) , (int((int(color) >> int(8))) & int(255)));
			__result->Add(HX_STRING(L"b",1) , (int(color) & int(255)));
			return __result;
		}
	};
	return _Function_1_1::Block(color);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(ColorUtil_obj,getRGB,return )

::String ColorUtil_obj::getHexStringFromARGB( int a,int r,int g,int b){
	__SAFE_POINT
	::String aa = ::StringTools_obj::hex(a,2);
	::String rr = ::StringTools_obj::hex(r,2);
	::String gg = ::StringTools_obj::hex(g,2);
	::String bb = ::StringTools_obj::hex(b,2);
	return ((((((aa + rr)) + gg)) + bb)).toUpperCase();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC4(ColorUtil_obj,getHexStringFromARGB,return )

::String ColorUtil_obj::getHexStringFromRGB( int r,int g,int b){
	__SAFE_POINT
	::String rr = ::StringTools_obj::hex(r,2);
	::String gg = ::StringTools_obj::hex(g,2);
	::String bb = ::StringTools_obj::hex(b,2);
	return ((((rr + gg)) + bb)).toUpperCase();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC3(ColorUtil_obj,getHexStringFromRGB,return )


ColorUtil_obj::ColorUtil_obj()
{
}

void ColorUtil_obj::__Mark()
{
}

Dynamic ColorUtil_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 6:
		if (!memcmp(inName.__s,L"getRGB",sizeof(wchar_t)*6) ) { return getRGB_dyn(); }
		break;
	case 7:
		if (!memcmp(inName.__s,L"getARGB",sizeof(wchar_t)*7) ) { return getARGB_dyn(); }
		break;
	case 8:
		if (!memcmp(inName.__s,L"getColor",sizeof(wchar_t)*8) ) { return getColor_dyn(); }
		break;
	case 16:
		if (!memcmp(inName.__s,L"interpolateColor",sizeof(wchar_t)*16) ) { return interpolateColor_dyn(); }
		break;
	case 19:
		if (!memcmp(inName.__s,L"getHexStringFromRGB",sizeof(wchar_t)*19) ) { return getHexStringFromRGB_dyn(); }
		break;
	case 20:
		if (!memcmp(inName.__s,L"getHexStringFromARGB",sizeof(wchar_t)*20) ) { return getHexStringFromARGB_dyn(); }
	}
	return super::__Field(inName);
}

Dynamic ColorUtil_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	return super::__SetField(inName,inValue);
}

void ColorUtil_obj::__GetFields(Array< ::String> &outFields)
{
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_STRING(L"interpolateColor",16),
	HX_STRING(L"getColor",8),
	HX_STRING(L"getARGB",7),
	HX_STRING(L"getRGB",6),
	HX_STRING(L"getHexStringFromARGB",20),
	HX_STRING(L"getHexStringFromRGB",19),
	String(null()) };

static ::String sMemberFields[] = {
	String(null()) };

static void sMarkStatics() {
};

Class ColorUtil_obj::__mClass;

void ColorUtil_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_STRING(L"org.casalib.util.ColorUtil",26), hx::TCanCast< ColorUtil_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void ColorUtil_obj::__boot()
{
}

} // end namespace org
} // end namespace casalib
} // end namespace util
