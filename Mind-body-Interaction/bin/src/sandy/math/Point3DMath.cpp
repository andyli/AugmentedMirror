#include <hxcpp.h>

#ifndef INCLUDED_hxMath
#include <hxMath.h>
#endif
#ifndef INCLUDED_haxe_Log
#include <haxe/Log.h>
#endif
#ifndef INCLUDED_sandy_core_data_Point3D
#include <sandy/core/data/Point3D.h>
#endif
#ifndef INCLUDED_sandy_math_Point3DMath
#include <sandy/math/Point3DMath.h>
#endif
namespace sandy{
namespace math{

Void Point3DMath_obj::__construct()
{
	return null();
}

Point3DMath_obj::~Point3DMath_obj() { }

Dynamic Point3DMath_obj::__CreateEmpty() { return  new Point3DMath_obj; }
hx::ObjectPtr< Point3DMath_obj > Point3DMath_obj::__new()
{  hx::ObjectPtr< Point3DMath_obj > result = new Point3DMath_obj();
	result->__construct();
	return result;}

Dynamic Point3DMath_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Point3DMath_obj > result = new Point3DMath_obj();
	result->__construct();
	return result;}

double Point3DMath_obj::getNorm( ::sandy::core::data::Point3D p_oV){
	__SAFE_POINT
	return ::Math_obj::sqrt(((((p_oV->x * p_oV->x) + (p_oV->y * p_oV->y))) + (p_oV->z * p_oV->z)));
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Point3DMath_obj,getNorm,return )

::sandy::core::data::Point3D Point3DMath_obj::negate( ::sandy::core::data::Point3D p_oV){
	return ::sandy::core::data::Point3D_obj::__new(-p_oV->x,-p_oV->y,-p_oV->z);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Point3DMath_obj,negate,return )

::sandy::core::data::Point3D Point3DMath_obj::addPoint3D( ::sandy::core::data::Point3D p_oV,::sandy::core::data::Point3D p_oW){
	return ::sandy::core::data::Point3D_obj::__new((p_oV->x + p_oW->x),(p_oV->y + p_oW->y),(p_oV->z + p_oW->z));
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(Point3DMath_obj,addPoint3D,return )

::sandy::core::data::Point3D Point3DMath_obj::sub( ::sandy::core::data::Point3D p_oV,::sandy::core::data::Point3D p_oW){
	return ::sandy::core::data::Point3D_obj::__new((p_oV->x - p_oW->x),(p_oV->y - p_oW->y),(p_oV->z - p_oW->z));
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(Point3DMath_obj,sub,return )

::sandy::core::data::Point3D Point3DMath_obj::pow( ::sandy::core::data::Point3D p_oV,double p_nExp){
	__SAFE_POINT
	return ::sandy::core::data::Point3D_obj::__new(::Math_obj::pow(p_oV->x,p_nExp),::Math_obj::pow(p_oV->y,p_nExp),::Math_obj::pow(p_oV->z,p_nExp));
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(Point3DMath_obj,pow,return )

::sandy::core::data::Point3D Point3DMath_obj::scale( ::sandy::core::data::Point3D p_oV,double n){
	return ::sandy::core::data::Point3D_obj::__new((p_oV->x * n),(p_oV->y * n),(p_oV->z * n));
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(Point3DMath_obj,scale,return )

double Point3DMath_obj::dot( ::sandy::core::data::Point3D p_oV,::sandy::core::data::Point3D p_oW){
	return (((((p_oV->x * p_oW->x) + (p_oV->y * p_oW->y))) + (p_oW->z * p_oV->z)));
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(Point3DMath_obj,dot,return )

::sandy::core::data::Point3D Point3DMath_obj::cross( ::sandy::core::data::Point3D p_oW,::sandy::core::data::Point3D p_oV){
	return ::sandy::core::data::Point3D_obj::__new((((p_oW->y * p_oV->z)) - ((p_oW->z * p_oV->y))),(((p_oW->z * p_oV->x)) - ((p_oW->x * p_oV->z))),(((p_oW->x * p_oV->y)) - ((p_oW->y * p_oV->x))));
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(Point3DMath_obj,cross,return )

bool Point3DMath_obj::normalize( ::sandy::core::data::Point3D p_oV){
	__SAFE_POINT
	double norm = ::Math_obj::sqrt(((((p_oV->x * p_oV->x) + (p_oV->y * p_oV->y))) + (p_oV->z * p_oV->z)));
	if ((bool((norm == 0)) || bool((norm == 1)))){
		return false;
	}
	else{
		hx::DivEq(p_oV->x,norm);
		hx::DivEq(p_oV->y,norm);
		hx::DivEq(p_oV->z,norm);
		return true;
	}
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Point3DMath_obj,normalize,return )

double Point3DMath_obj::getAngle( ::sandy::core::data::Point3D p_oV,::sandy::core::data::Point3D p_oW){
	__SAFE_POINT
	double ncos = (double(::sandy::math::Point3DMath_obj::dot(p_oV,p_oW)) / double(((::Math_obj::sqrt(((((p_oV->x * p_oV->x) + (p_oV->y * p_oV->y))) + (p_oV->z * p_oV->z))) * ::Math_obj::sqrt(((((p_oW->x * p_oW->x) + (p_oW->y * p_oW->y))) + (p_oW->z * p_oW->z)))))));
	double sin2 = (1 - (ncos * ncos));
	if ((sin2 < 0)){
		struct _Function_2_1{
			inline static Dynamic Block( ){
				hx::Anon __result = hx::Anon_obj::Create();
				__result->Add(HX_STRING(L"fileName",8) , HX_STRING(L"Point3DMath.hx",14));
				__result->Add(HX_STRING(L"lineNumber",10) , 169);
				__result->Add(HX_STRING(L"className",9) , HX_STRING(L"sandy.math.Point3DMath",22));
				__result->Add(HX_STRING(L"methodName",10) , HX_STRING(L"getAngle",8));
				return __result;
			}
		};
		::haxe::Log_obj::trace((HX_STRING(L" wrong ",7) + ncos),_Function_2_1::Block());
		sin2 = 0;
	}
	return ::Math_obj::atan2(::Math_obj::sqrt(sin2),ncos);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(Point3DMath_obj,getAngle,return )

::sandy::core::data::Point3D Point3DMath_obj::sphrand( double inner,double outer){
	__SAFE_POINT
	::sandy::core::data::Point3D v = ::sandy::core::data::Point3D_obj::__new((::Math_obj::random() - .5),(::Math_obj::random() - .5),(::Math_obj::random() - .5));
	v->normalize();
	double r = ::Math_obj::random();
	r = ((((outer - inner)) * r) + inner);
	v->scale(r);
	return v;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(Point3DMath_obj,sphrand,return )

double Point3DMath_obj::distance( ::sandy::core::data::Point3D pA,::sandy::core::data::Point3D pB){
	__SAFE_POINT
	double x = (pB->x - pA->x);
	double y = (pB->y - pA->y);
	double z = (pB->z - pA->z);
	return ::Math_obj::sqrt(((((x * x) + (y * y))) + (z * z)));
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(Point3DMath_obj,distance,return )

double Point3DMath_obj::distanceSquared( ::sandy::core::data::Point3D pA,::sandy::core::data::Point3D pB){
	double x = (pB->x - pA->x);
	double y = (pB->y - pA->y);
	double z = (pB->z - pA->z);
	return ((((x * x) + (y * y))) + (z * z));
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(Point3DMath_obj,distanceSquared,return )

::sandy::core::data::Point3D Point3DMath_obj::clone( ::sandy::core::data::Point3D p_oV){
	return ::sandy::core::data::Point3D_obj::__new(p_oV->x,p_oV->y,p_oV->z);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Point3DMath_obj,clone,return )


Point3DMath_obj::Point3DMath_obj()
{
}

void Point3DMath_obj::__Mark()
{
}

Dynamic Point3DMath_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 3:
		if (!memcmp(inName.__s,L"sub",sizeof(wchar_t)*3) ) { return sub_dyn(); }
		if (!memcmp(inName.__s,L"pow",sizeof(wchar_t)*3) ) { return pow_dyn(); }
		if (!memcmp(inName.__s,L"dot",sizeof(wchar_t)*3) ) { return dot_dyn(); }
		break;
	case 5:
		if (!memcmp(inName.__s,L"scale",sizeof(wchar_t)*5) ) { return scale_dyn(); }
		if (!memcmp(inName.__s,L"cross",sizeof(wchar_t)*5) ) { return cross_dyn(); }
		if (!memcmp(inName.__s,L"clone",sizeof(wchar_t)*5) ) { return clone_dyn(); }
		break;
	case 6:
		if (!memcmp(inName.__s,L"negate",sizeof(wchar_t)*6) ) { return negate_dyn(); }
		break;
	case 7:
		if (!memcmp(inName.__s,L"getNorm",sizeof(wchar_t)*7) ) { return getNorm_dyn(); }
		if (!memcmp(inName.__s,L"sphrand",sizeof(wchar_t)*7) ) { return sphrand_dyn(); }
		break;
	case 8:
		if (!memcmp(inName.__s,L"getAngle",sizeof(wchar_t)*8) ) { return getAngle_dyn(); }
		if (!memcmp(inName.__s,L"distance",sizeof(wchar_t)*8) ) { return distance_dyn(); }
		break;
	case 9:
		if (!memcmp(inName.__s,L"normalize",sizeof(wchar_t)*9) ) { return normalize_dyn(); }
		break;
	case 10:
		if (!memcmp(inName.__s,L"addPoint3D",sizeof(wchar_t)*10) ) { return addPoint3D_dyn(); }
		break;
	case 15:
		if (!memcmp(inName.__s,L"distanceSquared",sizeof(wchar_t)*15) ) { return distanceSquared_dyn(); }
	}
	return super::__Field(inName);
}

Dynamic Point3DMath_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	return super::__SetField(inName,inValue);
}

void Point3DMath_obj::__GetFields(Array< ::String> &outFields)
{
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_STRING(L"getNorm",7),
	HX_STRING(L"negate",6),
	HX_STRING(L"addPoint3D",10),
	HX_STRING(L"sub",3),
	HX_STRING(L"pow",3),
	HX_STRING(L"scale",5),
	HX_STRING(L"dot",3),
	HX_STRING(L"cross",5),
	HX_STRING(L"normalize",9),
	HX_STRING(L"getAngle",8),
	HX_STRING(L"sphrand",7),
	HX_STRING(L"distance",8),
	HX_STRING(L"distanceSquared",15),
	HX_STRING(L"clone",5),
	String(null()) };

static ::String sMemberFields[] = {
	String(null()) };

static void sMarkStatics() {
};

Class Point3DMath_obj::__mClass;

void Point3DMath_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_STRING(L"sandy.math.Point3DMath",22), hx::TCanCast< Point3DMath_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void Point3DMath_obj::__boot()
{
}

} // end namespace sandy
} // end namespace math
