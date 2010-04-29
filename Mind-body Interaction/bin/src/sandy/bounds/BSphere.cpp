#include <hxcpp.h>

#ifndef INCLUDED_hxMath
#include <hxMath.h>
#endif
#ifndef INCLUDED_sandy_bounds_BBox
#include <sandy/bounds/BBox.h>
#endif
#ifndef INCLUDED_sandy_bounds_BSphere
#include <sandy/bounds/BSphere.h>
#endif
#ifndef INCLUDED_sandy_core_data_Matrix4
#include <sandy/core/data/Matrix4.h>
#endif
#ifndef INCLUDED_sandy_core_data_Point3D
#include <sandy/core/data/Point3D.h>
#endif
#ifndef INCLUDED_sandy_core_data_Vertex
#include <sandy/core/data/Vertex.h>
#endif
namespace sandy{
namespace bounds{

Void BSphere_obj::__construct()
{
{
	this->uptodate = false;
	this->center = ::sandy::core::data::Point3D_obj::__new(null(),null(),null());
	this->radius = 1;
	this->position = ::sandy::core::data::Point3D_obj::__new(null(),null(),null());
}
;
	return null();
}

BSphere_obj::~BSphere_obj() { }

Dynamic BSphere_obj::__CreateEmpty() { return  new BSphere_obj; }
hx::ObjectPtr< BSphere_obj > BSphere_obj::__new()
{  hx::ObjectPtr< BSphere_obj > result = new BSphere_obj();
	result->__construct();
	return result;}

Dynamic BSphere_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< BSphere_obj > result = new BSphere_obj();
	result->__construct();
	return result;}

::sandy::bounds::BSphere BSphere_obj::clone( ){
	__SAFE_POINT
	::sandy::bounds::BSphere s = ::sandy::bounds::BSphere_obj::__new();
	s->uptodate = this->uptodate;
	s->center = this->center->clone();
	s->radius = this->radius;
	s->position = this->position->clone();
	return s;
}


HX_DEFINE_DYNAMIC_FUNC0(BSphere_obj,clone,return )

Void BSphere_obj::compute( Array< ::sandy::core::data::Vertex > p_aVertices){
{
		__SAFE_POINT
		if ((p_aVertices->length == 0))
			return null();
		double x;
		double y;
		double z;
		double d;
		int i = 0;
		int j = 0;
		int l = p_aVertices->length;
		::sandy::core::data::Vertex p1 = p_aVertices[0]->clone();
		::sandy::core::data::Vertex p2 = p_aVertices[0]->clone();
		double dmax = 0.0;
		::sandy::core::data::Vertex pA;
		::sandy::core::data::Vertex pB;
		while((i < l)){
			__SAFE_POINT
			j = (i + 1);
			while((j < l)){
				__SAFE_POINT
				pA = p_aVertices->__get(i);
				pB = p_aVertices->__get(j);
				x = (pB->x - pA->x);
				y = (pB->y - pA->y);
				z = (pB->z - pA->z);
				d = ((((x * x) + (y * y))) + (z * z));
				if ((d > dmax)){
					dmax = d;
					p1->copy(pA);
					p2->copy(pB);
				}
				hx::AddEq(j,1);
			}
			hx::AddEq(i,1);
		}
		this->center = ::sandy::core::data::Point3D_obj::__new((double(((p1->x + p2->x))) / double(2)),(double(((p1->y + p2->y))) / double(2)),(double(((p1->z + p2->z))) / double(2)));
		this->radius = (double(::Math_obj::sqrt(dmax)) / double(2));
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(BSphere_obj,compute,(void))

double BSphere_obj::computeRadius( Array< ::sandy::core::data::Vertex > p_aPoints){
	__SAFE_POINT
	double x;
	double y;
	double z;
	double d;
	double dmax = 0;
	int i = 0;
	int l = p_aPoints->length;
	while((i < l)){
		__SAFE_POINT
		x = (p_aPoints[(i)]->x - this->center->x);
		y = (p_aPoints[(i)]->x - this->center->x);
		z = (p_aPoints[(i)]->x - this->center->x);
		d = ((((x * x) + (y * y))) + (z * z));
		if ((d > dmax))
			dmax = d;
		i++;
	}
	return ::Math_obj::sqrt(dmax);
}


HX_DEFINE_DYNAMIC_FUNC1(BSphere_obj,computeRadius,return )

Void BSphere_obj::copy( ::sandy::bounds::BSphere p_oBSphere){
{
		__SAFE_POINT
		this->uptodate = p_oBSphere->uptodate;
		this->center->copy(p_oBSphere->center);
		this->radius = p_oBSphere->radius;
		this->position->copy(p_oBSphere->position);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(BSphere_obj,copy,(void))

double BSphere_obj::distance( ::sandy::core::data::Point3D p_oPoint){
	__SAFE_POINT
	double x = (p_oPoint->x - this->center->x);
	double y = (p_oPoint->y - this->center->y);
	double z = (p_oPoint->z - this->center->z);
	return (::Math_obj::sqrt(((((x * x) + (y * y))) + (z * z))) - this->radius);
}


HX_DEFINE_DYNAMIC_FUNC1(BSphere_obj,distance,return )

Array< ::sandy::core::data::Point3D > BSphere_obj::pointsOutofSphere( Array< ::sandy::core::data::Point3D > p_aPoints){
	__SAFE_POINT
	Array< ::sandy::core::data::Point3D > r = Array_obj< ::sandy::core::data::Point3D >::__new();
	int i = 0;
	int l = p_aPoints->length;
	while((i < l)){
		__SAFE_POINT
		if ((this->distance(p_aPoints->__get((i))) > 0)){
			r->push(p_aPoints->__get((i)));
		}
		i++;
	}
	return r;
}


HX_DEFINE_DYNAMIC_FUNC1(BSphere_obj,pointsOutofSphere,return )

Void BSphere_obj::reset( ){
{
		__SAFE_POINT
		this->center->reset(null(),null(),null());
		this->radius = 0;
		this->position->reset(null(),null(),null());
		this->uptodate = false;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(BSphere_obj,reset,(void))

Void BSphere_obj::resetFromBox( ::sandy::bounds::BBox box){
{
		__SAFE_POINT
		this->center->copy(box->getCenter());
		this->radius = ::Math_obj::sqrt((((((((box->maxEdge->x - this->center->x)) * ((box->maxEdge->x - this->center->x)))) + ((((box->maxEdge->y - this->center->y)) * ((box->maxEdge->y - this->center->y)))))) + ((((box->maxEdge->z - this->center->z)) * ((box->maxEdge->z - this->center->z))))));
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(BSphere_obj,resetFromBox,(void))

::String BSphere_obj::toString( ){
	return (((((((HX_STRING(L"sandy.bounds.BSphere (center : ",31) + this->center)) + HX_STRING(L", radius : ",11))) + this->radius)) + HX_STRING(L")",1));
}


HX_DEFINE_DYNAMIC_FUNC0(BSphere_obj,toString,return )

Void BSphere_obj::transform( ::sandy::core::data::Matrix4 p_oMatrix){
{
		__SAFE_POINT
		this->position->copy(this->center);
		p_oMatrix->transform(this->position);
		this->uptodate = true;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(BSphere_obj,transform,(void))

::sandy::bounds::BSphere BSphere_obj::create( Array< ::sandy::core::data::Vertex > p_aVertices){
	__SAFE_POINT
	::sandy::bounds::BSphere l_sphere = ::sandy::bounds::BSphere_obj::__new();
	l_sphere->compute(p_aVertices);
	return l_sphere;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(BSphere_obj,create,return )


BSphere_obj::BSphere_obj()
{
}

void BSphere_obj::__Mark()
{
	hx::MarkMember(uptodate);
	hx::MarkMember(center);
	hx::MarkMember(radius);
	hx::MarkMember(position);
}

Dynamic BSphere_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 4:
		if (!memcmp(inName.__s,L"copy",sizeof(wchar_t)*4) ) { return copy_dyn(); }
		break;
	case 5:
		if (!memcmp(inName.__s,L"clone",sizeof(wchar_t)*5) ) { return clone_dyn(); }
		if (!memcmp(inName.__s,L"reset",sizeof(wchar_t)*5) ) { return reset_dyn(); }
		break;
	case 6:
		if (!memcmp(inName.__s,L"create",sizeof(wchar_t)*6) ) { return create_dyn(); }
		if (!memcmp(inName.__s,L"center",sizeof(wchar_t)*6) ) { return center; }
		if (!memcmp(inName.__s,L"radius",sizeof(wchar_t)*6) ) { return radius; }
		break;
	case 7:
		if (!memcmp(inName.__s,L"compute",sizeof(wchar_t)*7) ) { return compute_dyn(); }
		break;
	case 8:
		if (!memcmp(inName.__s,L"uptodate",sizeof(wchar_t)*8) ) { return uptodate; }
		if (!memcmp(inName.__s,L"position",sizeof(wchar_t)*8) ) { return position; }
		if (!memcmp(inName.__s,L"distance",sizeof(wchar_t)*8) ) { return distance_dyn(); }
		if (!memcmp(inName.__s,L"toString",sizeof(wchar_t)*8) ) { return toString_dyn(); }
		break;
	case 9:
		if (!memcmp(inName.__s,L"transform",sizeof(wchar_t)*9) ) { return transform_dyn(); }
		break;
	case 12:
		if (!memcmp(inName.__s,L"resetFromBox",sizeof(wchar_t)*12) ) { return resetFromBox_dyn(); }
		break;
	case 13:
		if (!memcmp(inName.__s,L"computeRadius",sizeof(wchar_t)*13) ) { return computeRadius_dyn(); }
		break;
	case 17:
		if (!memcmp(inName.__s,L"pointsOutofSphere",sizeof(wchar_t)*17) ) { return pointsOutofSphere_dyn(); }
	}
	return super::__Field(inName);
}

Dynamic BSphere_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	switch(inName.length) {
	case 6:
		if (!memcmp(inName.__s,L"center",sizeof(wchar_t)*6) ) { center=inValue.Cast< ::sandy::core::data::Point3D >(); return inValue; }
		if (!memcmp(inName.__s,L"radius",sizeof(wchar_t)*6) ) { radius=inValue.Cast< double >(); return inValue; }
		break;
	case 8:
		if (!memcmp(inName.__s,L"uptodate",sizeof(wchar_t)*8) ) { uptodate=inValue.Cast< bool >(); return inValue; }
		if (!memcmp(inName.__s,L"position",sizeof(wchar_t)*8) ) { position=inValue.Cast< ::sandy::core::data::Point3D >(); return inValue; }
	}
	return super::__SetField(inName,inValue);
}

void BSphere_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_STRING(L"uptodate",8));
	outFields->push(HX_STRING(L"center",6));
	outFields->push(HX_STRING(L"radius",6));
	outFields->push(HX_STRING(L"position",8));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_STRING(L"create",6),
	String(null()) };

static ::String sMemberFields[] = {
	HX_STRING(L"uptodate",8),
	HX_STRING(L"center",6),
	HX_STRING(L"radius",6),
	HX_STRING(L"position",8),
	HX_STRING(L"clone",5),
	HX_STRING(L"compute",7),
	HX_STRING(L"computeRadius",13),
	HX_STRING(L"copy",4),
	HX_STRING(L"distance",8),
	HX_STRING(L"pointsOutofSphere",17),
	HX_STRING(L"reset",5),
	HX_STRING(L"resetFromBox",12),
	HX_STRING(L"toString",8),
	HX_STRING(L"transform",9),
	String(null()) };

static void sMarkStatics() {
};

Class BSphere_obj::__mClass;

void BSphere_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_STRING(L"sandy.bounds.BSphere",20), hx::TCanCast< BSphere_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void BSphere_obj::__boot()
{
}

} // end namespace sandy
} // end namespace bounds
