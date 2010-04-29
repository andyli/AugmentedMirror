#include <hxcpp.h>

#ifndef INCLUDED_hxMath
#include <hxMath.h>
#endif
#ifndef INCLUDED_sandy_util_NumberUtil
#include <sandy/util/NumberUtil.h>
#endif
namespace sandy{
namespace util{

Void NumberUtil_obj::__construct()
{
	return null();
}

NumberUtil_obj::~NumberUtil_obj() { }

Dynamic NumberUtil_obj::__CreateEmpty() { return  new NumberUtil_obj; }
hx::ObjectPtr< NumberUtil_obj > NumberUtil_obj::__new()
{  hx::ObjectPtr< NumberUtil_obj > result = new NumberUtil_obj();
	result->__construct();
	return result;}

Dynamic NumberUtil_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< NumberUtil_obj > result = new NumberUtil_obj();
	result->__construct();
	return result;}

double NumberUtil_obj::TWO_PI;

double NumberUtil_obj::PI;

double NumberUtil_obj::HALF_PI;

double NumberUtil_obj::TO_DEGREE;

double NumberUtil_obj::TO_RADIAN;

double NumberUtil_obj::TOL;

bool NumberUtil_obj::isZero( double p_nN){
	__SAFE_POINT
	return (::Math_obj::abs(p_nN) < 0.00001);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(NumberUtil_obj,isZero,return )

bool NumberUtil_obj::areEqual( double p_nN,double p_nM){
	__SAFE_POINT
	return (::Math_obj::abs((p_nN - p_nM)) < 0.00001);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(NumberUtil_obj,areEqual,return )

double NumberUtil_obj::toDegree( double p_nRad){
	return (p_nRad * 57.29577951308232088);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(NumberUtil_obj,toDegree,return )

double NumberUtil_obj::toRadian( double p_nDeg){
	return (p_nDeg * 0.01745329251994329577);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(NumberUtil_obj,toRadian,return )

double NumberUtil_obj::constrain( double p_nN,double p_nMin,double p_nMax){
	__SAFE_POINT
	return ::Math_obj::max(::Math_obj::min(p_nN,p_nMax),p_nMin);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC3(NumberUtil_obj,constrain,return )

double NumberUtil_obj::roundTo( double p_nN,Dynamic p_nRoundToInterval){
	__SAFE_POINT
	if ((p_nRoundToInterval == 0.)){
		p_nRoundToInterval = 1.;
	}
	return (::Math_obj::round((double(p_nN) / double(p_nRoundToInterval))) * p_nRoundToInterval);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(NumberUtil_obj,roundTo,return )

double NumberUtil_obj::roundToPlaces( double p_nN,Dynamic __o_p_nPlaces){
int p_nPlaces = __o_p_nPlaces.Default(2);
{
		__SAFE_POINT
		double mul = ::Math_obj::pow(10,p_nPlaces);
		double j = (double(::Math_obj::round((p_nN * mul))) / double(mul));
		return j;
	}
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(NumberUtil_obj,roundToPlaces,return )


NumberUtil_obj::NumberUtil_obj()
{
}

void NumberUtil_obj::__Mark()
{
}

Dynamic NumberUtil_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 2:
		if (!memcmp(inName.__s,L"PI",sizeof(wchar_t)*2) ) { return PI; }
		break;
	case 3:
		if (!memcmp(inName.__s,L"TOL",sizeof(wchar_t)*3) ) { return TOL; }
		break;
	case 6:
		if (!memcmp(inName.__s,L"TWO_PI",sizeof(wchar_t)*6) ) { return TWO_PI; }
		if (!memcmp(inName.__s,L"isZero",sizeof(wchar_t)*6) ) { return isZero_dyn(); }
		break;
	case 7:
		if (!memcmp(inName.__s,L"HALF_PI",sizeof(wchar_t)*7) ) { return HALF_PI; }
		if (!memcmp(inName.__s,L"roundTo",sizeof(wchar_t)*7) ) { return roundTo_dyn(); }
		break;
	case 8:
		if (!memcmp(inName.__s,L"areEqual",sizeof(wchar_t)*8) ) { return areEqual_dyn(); }
		if (!memcmp(inName.__s,L"toDegree",sizeof(wchar_t)*8) ) { return toDegree_dyn(); }
		if (!memcmp(inName.__s,L"toRadian",sizeof(wchar_t)*8) ) { return toRadian_dyn(); }
		break;
	case 9:
		if (!memcmp(inName.__s,L"TO_DEGREE",sizeof(wchar_t)*9) ) { return TO_DEGREE; }
		if (!memcmp(inName.__s,L"TO_RADIAN",sizeof(wchar_t)*9) ) { return TO_RADIAN; }
		if (!memcmp(inName.__s,L"constrain",sizeof(wchar_t)*9) ) { return constrain_dyn(); }
		break;
	case 13:
		if (!memcmp(inName.__s,L"roundToPlaces",sizeof(wchar_t)*13) ) { return roundToPlaces_dyn(); }
	}
	return super::__Field(inName);
}

Dynamic NumberUtil_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	switch(inName.length) {
	case 2:
		if (!memcmp(inName.__s,L"PI",sizeof(wchar_t)*2) ) { PI=inValue.Cast< double >(); return inValue; }
		break;
	case 3:
		if (!memcmp(inName.__s,L"TOL",sizeof(wchar_t)*3) ) { TOL=inValue.Cast< double >(); return inValue; }
		break;
	case 6:
		if (!memcmp(inName.__s,L"TWO_PI",sizeof(wchar_t)*6) ) { TWO_PI=inValue.Cast< double >(); return inValue; }
		break;
	case 7:
		if (!memcmp(inName.__s,L"HALF_PI",sizeof(wchar_t)*7) ) { HALF_PI=inValue.Cast< double >(); return inValue; }
		break;
	case 9:
		if (!memcmp(inName.__s,L"TO_DEGREE",sizeof(wchar_t)*9) ) { TO_DEGREE=inValue.Cast< double >(); return inValue; }
		if (!memcmp(inName.__s,L"TO_RADIAN",sizeof(wchar_t)*9) ) { TO_RADIAN=inValue.Cast< double >(); return inValue; }
	}
	return super::__SetField(inName,inValue);
}

void NumberUtil_obj::__GetFields(Array< ::String> &outFields)
{
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_STRING(L"TWO_PI",6),
	HX_STRING(L"PI",2),
	HX_STRING(L"HALF_PI",7),
	HX_STRING(L"TO_DEGREE",9),
	HX_STRING(L"TO_RADIAN",9),
	HX_STRING(L"TOL",3),
	HX_STRING(L"isZero",6),
	HX_STRING(L"areEqual",8),
	HX_STRING(L"toDegree",8),
	HX_STRING(L"toRadian",8),
	HX_STRING(L"constrain",9),
	HX_STRING(L"roundTo",7),
	HX_STRING(L"roundToPlaces",13),
	String(null()) };

static ::String sMemberFields[] = {
	String(null()) };

static void sMarkStatics() {
	hx::MarkMember(NumberUtil_obj::TWO_PI);
	hx::MarkMember(NumberUtil_obj::PI);
	hx::MarkMember(NumberUtil_obj::HALF_PI);
	hx::MarkMember(NumberUtil_obj::TO_DEGREE);
	hx::MarkMember(NumberUtil_obj::TO_RADIAN);
	hx::MarkMember(NumberUtil_obj::TOL);
};

Class NumberUtil_obj::__mClass;

void NumberUtil_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_STRING(L"sandy.util.NumberUtil",21), hx::TCanCast< NumberUtil_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void NumberUtil_obj::__boot()
{
	hx::Static(TWO_PI) = 6.283185307179586477;
	hx::Static(PI) = 3.141592653589793238;
	hx::Static(HALF_PI) = 1.570796326794896619;
	hx::Static(TO_DEGREE) = 57.29577951308232088;
	hx::Static(TO_RADIAN) = 0.01745329251994329577;
	hx::Static(TOL) = 0.00001;
}

} // end namespace sandy
} // end namespace util
