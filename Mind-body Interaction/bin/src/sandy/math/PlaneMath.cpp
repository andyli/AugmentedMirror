#include <hxcpp.h>

#ifndef INCLUDED_hxMath
#include <hxMath.h>
#endif
#ifndef INCLUDED_sandy_core_data_Plane
#include <sandy/core/data/Plane.h>
#endif
#ifndef INCLUDED_sandy_core_data_Point3D
#include <sandy/core/data/Point3D.h>
#endif
#ifndef INCLUDED_sandy_math_PlaneMath
#include <sandy/math/PlaneMath.h>
#endif
#ifndef INCLUDED_sandy_math_Point3DMath
#include <sandy/math/Point3DMath.h>
#endif
namespace sandy{
namespace math{

Void PlaneMath_obj::__construct()
{
	return null();
}

PlaneMath_obj::~PlaneMath_obj() { }

Dynamic PlaneMath_obj::__CreateEmpty() { return  new PlaneMath_obj; }
hx::ObjectPtr< PlaneMath_obj > PlaneMath_obj::__new()
{  hx::ObjectPtr< PlaneMath_obj > result = new PlaneMath_obj();
	result->__construct();
	return result;}

Dynamic PlaneMath_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< PlaneMath_obj > result = new PlaneMath_obj();
	result->__construct();
	return result;}

int PlaneMath_obj::NEGATIVE;

int PlaneMath_obj::ON_PLANE;

int PlaneMath_obj::POSITIVE;

Void PlaneMath_obj::normalizePlane( ::sandy::core::data::Plane p_oPlane){
{
		__SAFE_POINT
		double mag;
		mag = ::Math_obj::sqrt(((((p_oPlane->a * p_oPlane->a) + (p_oPlane->b * p_oPlane->b))) + (p_oPlane->c * p_oPlane->c)));
		p_oPlane->a = (double(p_oPlane->a) / double(mag));
		p_oPlane->b = (double(p_oPlane->b) / double(mag));
		p_oPlane->c = (double(p_oPlane->c) / double(mag));
		p_oPlane->d = (double(p_oPlane->d) / double(mag));
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(PlaneMath_obj,normalizePlane,(void))

double PlaneMath_obj::distanceToPoint( ::sandy::core::data::Plane p_oPlane,::sandy::core::data::Point3D p_oPoint){
	return ((((((p_oPlane->a * p_oPoint->x) + (p_oPlane->b * p_oPoint->y))) + (p_oPlane->c * p_oPoint->z))) + p_oPlane->d);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(PlaneMath_obj,distanceToPoint,return )

int PlaneMath_obj::classifyPoint( ::sandy::core::data::Plane p_oPlane,::sandy::core::data::Point3D p_oPoint3D){
	__SAFE_POINT
	double d;
	d = ::sandy::math::PlaneMath_obj::distanceToPoint(p_oPlane,p_oPoint3D);
	if ((d < 0))
		return ::sandy::math::PlaneMath_obj::NEGATIVE;
	if ((d > 0))
		return ::sandy::math::PlaneMath_obj::POSITIVE;
	return ::sandy::math::PlaneMath_obj::ON_PLANE;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(PlaneMath_obj,classifyPoint,return )

::sandy::core::data::Plane PlaneMath_obj::computePlaneFromPoints( ::sandy::core::data::Point3D p_oPointA,::sandy::core::data::Point3D p_oPointB,::sandy::core::data::Point3D p_oPointC){
	__SAFE_POINT
	::sandy::core::data::Point3D n = ::sandy::math::Point3DMath_obj::cross(::sandy::math::Point3DMath_obj::sub(p_oPointA,p_oPointB),::sandy::math::Point3DMath_obj::sub(p_oPointA,p_oPointC));
	{
		double norm = ::Math_obj::sqrt(((((n->x * n->x) + (n->y * n->y))) + (n->z * n->z)));
		if ((bool((norm == 0)) || bool((norm == 1)))){
			false;
		}
		else{
			hx::DivEq(n->x,norm);
			hx::DivEq(n->y,norm);
			hx::DivEq(n->z,norm);
			true;
		}
	}
	double d = ::sandy::math::Point3DMath_obj::dot(p_oPointA,n);
	return ::sandy::core::data::Plane_obj::__new(n->x,n->y,n->z,d);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC3(PlaneMath_obj,computePlaneFromPoints,return )

::sandy::core::data::Plane PlaneMath_obj::createFromNormalAndPoint( ::sandy::core::data::Point3D p_oNormal,::sandy::core::data::Point3D p_oPoint){
	__SAFE_POINT
	::sandy::core::data::Plane p = ::sandy::core::data::Plane_obj::__new(null(),null(),null(),null());
	{
		double norm = ::Math_obj::sqrt(((((p_oNormal->x * p_oNormal->x) + (p_oNormal->y * p_oNormal->y))) + (p_oNormal->z * p_oNormal->z)));
		if ((bool((norm == 0)) || bool((norm == 1)))){
			false;
		}
		else{
			hx::DivEq(p_oNormal->x,norm);
			hx::DivEq(p_oNormal->y,norm);
			hx::DivEq(p_oNormal->z,norm);
			true;
		}
	}
	p->a = p_oNormal->x;
	p->b = p_oNormal->y;
	p->c = p_oNormal->z;
	p->d = (p_oNormal->dot(p_oPoint) * -1);
	::sandy::math::PlaneMath_obj::normalizePlane(p);
	return p;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(PlaneMath_obj,createFromNormalAndPoint,return )


PlaneMath_obj::PlaneMath_obj()
{
}

void PlaneMath_obj::__Mark()
{
}

Dynamic PlaneMath_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 8:
		if (!memcmp(inName.__s,L"NEGATIVE",sizeof(wchar_t)*8) ) { return NEGATIVE; }
		if (!memcmp(inName.__s,L"ON_PLANE",sizeof(wchar_t)*8) ) { return ON_PLANE; }
		if (!memcmp(inName.__s,L"POSITIVE",sizeof(wchar_t)*8) ) { return POSITIVE; }
		break;
	case 13:
		if (!memcmp(inName.__s,L"classifyPoint",sizeof(wchar_t)*13) ) { return classifyPoint_dyn(); }
		break;
	case 14:
		if (!memcmp(inName.__s,L"normalizePlane",sizeof(wchar_t)*14) ) { return normalizePlane_dyn(); }
		break;
	case 15:
		if (!memcmp(inName.__s,L"distanceToPoint",sizeof(wchar_t)*15) ) { return distanceToPoint_dyn(); }
		break;
	case 22:
		if (!memcmp(inName.__s,L"computePlaneFromPoints",sizeof(wchar_t)*22) ) { return computePlaneFromPoints_dyn(); }
		break;
	case 24:
		if (!memcmp(inName.__s,L"createFromNormalAndPoint",sizeof(wchar_t)*24) ) { return createFromNormalAndPoint_dyn(); }
	}
	return super::__Field(inName);
}

Dynamic PlaneMath_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	switch(inName.length) {
	case 8:
		if (!memcmp(inName.__s,L"NEGATIVE",sizeof(wchar_t)*8) ) { NEGATIVE=inValue.Cast< int >(); return inValue; }
		if (!memcmp(inName.__s,L"ON_PLANE",sizeof(wchar_t)*8) ) { ON_PLANE=inValue.Cast< int >(); return inValue; }
		if (!memcmp(inName.__s,L"POSITIVE",sizeof(wchar_t)*8) ) { POSITIVE=inValue.Cast< int >(); return inValue; }
	}
	return super::__SetField(inName,inValue);
}

void PlaneMath_obj::__GetFields(Array< ::String> &outFields)
{
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_STRING(L"NEGATIVE",8),
	HX_STRING(L"ON_PLANE",8),
	HX_STRING(L"POSITIVE",8),
	HX_STRING(L"normalizePlane",14),
	HX_STRING(L"distanceToPoint",15),
	HX_STRING(L"classifyPoint",13),
	HX_STRING(L"computePlaneFromPoints",22),
	HX_STRING(L"createFromNormalAndPoint",24),
	String(null()) };

static ::String sMemberFields[] = {
	String(null()) };

static void sMarkStatics() {
	hx::MarkMember(PlaneMath_obj::NEGATIVE);
	hx::MarkMember(PlaneMath_obj::ON_PLANE);
	hx::MarkMember(PlaneMath_obj::POSITIVE);
};

Class PlaneMath_obj::__mClass;

void PlaneMath_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_STRING(L"sandy.math.PlaneMath",20), hx::TCanCast< PlaneMath_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void PlaneMath_obj::__boot()
{
	hx::Static(NEGATIVE) = -1;
	hx::Static(ON_PLANE) = 0;
	hx::Static(POSITIVE) = 1;
}

} // end namespace sandy
} // end namespace math
