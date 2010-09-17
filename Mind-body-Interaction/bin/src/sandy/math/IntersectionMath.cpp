#include <hxcpp.h>

#ifndef INCLUDED_hxMath
#include <hxMath.h>
#endif
#ifndef INCLUDED_nme_geom_Point
#include <nme/geom/Point.h>
#endif
#ifndef INCLUDED_sandy_bounds_BSphere
#include <sandy/bounds/BSphere.h>
#endif
#ifndef INCLUDED_sandy_core_data_Point3D
#include <sandy/core/data/Point3D.h>
#endif
#ifndef INCLUDED_sandy_math_IntersectionMath
#include <sandy/math/IntersectionMath.h>
#endif
namespace sandy{
namespace math{

Void IntersectionMath_obj::__construct()
{
	return null();
}

IntersectionMath_obj::~IntersectionMath_obj() { }

Dynamic IntersectionMath_obj::__CreateEmpty() { return  new IntersectionMath_obj; }
hx::ObjectPtr< IntersectionMath_obj > IntersectionMath_obj::__new()
{  hx::ObjectPtr< IntersectionMath_obj > result = new IntersectionMath_obj();
	result->__construct();
	return result;}

Dynamic IntersectionMath_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< IntersectionMath_obj > result = new IntersectionMath_obj();
	result->__construct();
	return result;}

bool IntersectionMath_obj::intersectionBSphere( ::sandy::bounds::BSphere p_oBSphereA,::sandy::bounds::BSphere p_oBSphereB){
	__SAFE_POINT
	::sandy::core::data::Point3D l_oVec = p_oBSphereA->position->clone();
	l_oVec->sub(p_oBSphereB->position);
	double l_nDist = (p_oBSphereA->radius + p_oBSphereB->radius);
	double l_nNorm = l_oVec->getNorm();
	return ((l_nNorm <= l_nDist));
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(IntersectionMath_obj,intersectionBSphere,return )

Array< ::sandy::core::data::Point3D > IntersectionMath_obj::intersectionLine3D( ::sandy::core::data::Point3D p_oPointA,::sandy::core::data::Point3D p_oPointB,::sandy::core::data::Point3D p_oPointC,::sandy::core::data::Point3D p_oPointD){
	__SAFE_POINT
	Array< ::sandy::core::data::Point3D > res = Array_obj< ::sandy::core::data::Point3D >::__new().Add(::sandy::core::data::Point3D_obj::__new((0.5 * ((p_oPointA->x + p_oPointB->x))),(0.5 * ((p_oPointA->y + p_oPointB->y))),(0.5 * ((p_oPointA->z + p_oPointB->z))))).Add(::sandy::core::data::Point3D_obj::__new((0.5 * ((p_oPointC->x + p_oPointD->x))),(0.5 * ((p_oPointC->y + p_oPointD->y))),(0.5 * ((p_oPointC->z + p_oPointD->z)))));
	double p13_x = (p_oPointA->x - p_oPointC->x);
	double p13_y = (p_oPointA->y - p_oPointC->y);
	double p13_z = (p_oPointA->z - p_oPointC->z);
	double p43_x = (p_oPointD->x - p_oPointC->x);
	double p43_y = (p_oPointD->y - p_oPointC->y);
	double p43_z = (p_oPointD->z - p_oPointC->z);
	if ((bool((::Math_obj::abs(p43_x) < 0.00001)) && bool((bool((::Math_obj::abs(p43_y) < 0.00001)) && bool((::Math_obj::abs(p43_z) < 0.00001))))))
		return res;
	double p21_x = (p_oPointB->x - p_oPointA->x);
	double p21_y = (p_oPointB->y - p_oPointA->y);
	double p21_z = (p_oPointB->z - p_oPointA->z);
	if ((bool((::Math_obj::abs(p21_x) < 0.00001)) && bool((bool((::Math_obj::abs(p21_y) < 0.00001)) && bool((::Math_obj::abs(p21_z) < 0.00001))))))
		return res;
	double d1343 = ((((p13_x * p43_x) + (p13_y * p43_y))) + (p13_z * p43_z));
	double d4321 = ((((p43_x * p21_x) + (p43_y * p21_y))) + (p43_z * p21_z));
	double d1321 = ((((p13_x * p21_x) + (p13_y * p21_y))) + (p13_z * p21_z));
	double d4343 = ((((p43_x * p43_x) + (p43_y * p43_y))) + (p43_z * p43_z));
	double d2121 = ((((p21_x * p21_x) + (p21_y * p21_y))) + (p21_z * p21_z));
	double denom = ((d2121 * d4343) - (d4321 * d4321));
	if ((::Math_obj::abs(denom) < 0.00001))
		return res;
	double mua = (double((((d1343 * d4321) - (d1321 * d4343)))) / double(denom));
	double mub = (double(((d1343 + (d4321 * mua)))) / double(d4343));
	return Array_obj< ::sandy::core::data::Point3D >::__new().Add(::sandy::core::data::Point3D_obj::__new((p_oPointA->x + (mua * p21_x)),(p_oPointA->y + (mua * p21_y)),(p_oPointA->z + (mua * p21_z)))).Add(::sandy::core::data::Point3D_obj::__new((p_oPointC->x + (mub * p43_x)),(p_oPointC->y + (mub * p43_y)),(p_oPointC->z + (mub * p43_z))));
}


STATIC_HX_DEFINE_DYNAMIC_FUNC4(IntersectionMath_obj,intersectionLine3D,return )

::nme::geom::Point IntersectionMath_obj::intersectionLine2D( ::nme::geom::Point p_oPointA,::nme::geom::Point p_oPointB,::nme::geom::Point p_oPointC,::nme::geom::Point p_oPointD){
	double xA = p_oPointA->x;
	double yA = p_oPointA->y;
	double xB = p_oPointB->x;
	double yB = p_oPointB->y;
	double xC = p_oPointC->x;
	double yC = p_oPointC->y;
	double xD = p_oPointD->x;
	double yD = p_oPointD->y;
	double denom = (((((yD - yC)) * ((xB - xA))) - (((xD - xC)) * ((yB - yA)))));
	if ((denom == 0))
		return null();
	double uA = (((((xD - xC)) * ((yA - yC))) - (((yD - yC)) * ((xA - xC)))));
	hx::DivEq(uA,denom);
	return ::nme::geom::Point_obj::__new((xA + (uA * ((xB - xA)))),(yA + (uA * ((yB - yA)))));
}


STATIC_HX_DEFINE_DYNAMIC_FUNC4(IntersectionMath_obj,intersectionLine2D,return )

bool IntersectionMath_obj::isPointInTriangle2D( ::nme::geom::Point p_oPoint,::nme::geom::Point p_oA,::nme::geom::Point p_oB,::nme::geom::Point p_oC){
	double oneOverDenom = ((double(1) / double(((((((p_oA->y - p_oC->y)) * ((p_oB->x - p_oC->x)))) + ((((p_oB->y - p_oC->y)) * ((p_oC->x - p_oA->x)))))))));
	double b1 = ((oneOverDenom * ((((((p_oPoint->y - p_oC->y)) * ((p_oB->x - p_oC->x)))) + ((((p_oB->y - p_oC->y)) * ((p_oC->x - p_oPoint->x))))))));
	double b2 = ((oneOverDenom * ((((((p_oPoint->y - p_oA->y)) * ((p_oC->x - p_oA->x)))) + ((((p_oC->y - p_oA->y)) * ((p_oA->x - p_oPoint->x))))))));
	double b3 = ((oneOverDenom * ((((((p_oPoint->y - p_oB->y)) * ((p_oA->x - p_oB->x)))) + ((((p_oA->y - p_oB->y)) * ((p_oB->x - p_oPoint->x))))))));
	return ((bool(((b1 > 0))) && bool((bool(((b2 > 0))) && bool(((b3 > 0)))))));
}


STATIC_HX_DEFINE_DYNAMIC_FUNC4(IntersectionMath_obj,isPointInTriangle2D,return )


IntersectionMath_obj::IntersectionMath_obj()
{
}

void IntersectionMath_obj::__Mark()
{
}

Dynamic IntersectionMath_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 18:
		if (!memcmp(inName.__s,L"intersectionLine3D",sizeof(wchar_t)*18) ) { return intersectionLine3D_dyn(); }
		if (!memcmp(inName.__s,L"intersectionLine2D",sizeof(wchar_t)*18) ) { return intersectionLine2D_dyn(); }
		break;
	case 19:
		if (!memcmp(inName.__s,L"intersectionBSphere",sizeof(wchar_t)*19) ) { return intersectionBSphere_dyn(); }
		if (!memcmp(inName.__s,L"isPointInTriangle2D",sizeof(wchar_t)*19) ) { return isPointInTriangle2D_dyn(); }
	}
	return super::__Field(inName);
}

Dynamic IntersectionMath_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	return super::__SetField(inName,inValue);
}

void IntersectionMath_obj::__GetFields(Array< ::String> &outFields)
{
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_STRING(L"intersectionBSphere",19),
	HX_STRING(L"intersectionLine3D",18),
	HX_STRING(L"intersectionLine2D",18),
	HX_STRING(L"isPointInTriangle2D",19),
	String(null()) };

static ::String sMemberFields[] = {
	String(null()) };

static void sMarkStatics() {
};

Class IntersectionMath_obj::__mClass;

void IntersectionMath_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_STRING(L"sandy.math.IntersectionMath",27), hx::TCanCast< IntersectionMath_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void IntersectionMath_obj::__boot()
{
}

} // end namespace sandy
} // end namespace math
