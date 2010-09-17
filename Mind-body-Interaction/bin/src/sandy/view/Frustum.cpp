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
#ifndef INCLUDED_sandy_core_data_Plane
#include <sandy/core/data/Plane.h>
#endif
#ifndef INCLUDED_sandy_core_data_Point3D
#include <sandy/core/data/Point3D.h>
#endif
#ifndef INCLUDED_sandy_core_data_Polygon
#include <sandy/core/data/Polygon.h>
#endif
#ifndef INCLUDED_sandy_core_data_Pool
#include <sandy/core/data/Pool.h>
#endif
#ifndef INCLUDED_sandy_core_data_UVCoord
#include <sandy/core/data/UVCoord.h>
#endif
#ifndef INCLUDED_sandy_core_data_Vertex
#include <sandy/core/data/Vertex.h>
#endif
#ifndef INCLUDED_sandy_core_scenegraph_IDisplayable
#include <sandy/core/scenegraph/IDisplayable.h>
#endif
#ifndef INCLUDED_sandy_math_PlaneMath
#include <sandy/math/PlaneMath.h>
#endif
#ifndef INCLUDED_sandy_view_Frustum
#include <sandy/view/Frustum.h>
#endif
namespace sandy{
namespace view{

Void Frustum_obj::__construct()
{
{
	this->aPlanes = Array_obj< ::sandy::core::data::Plane >::__new();
	this->aPoints = Array_obj< ::sandy::core::data::Point3D >::__new();
	this->aNormals = Array_obj< ::sandy::core::data::Vertex >::__new();
	this->aConstants = Array_obj< double >::__new();
	this->m_aBoxEdges = Array_obj< ::sandy::core::data::Point3D >::__new();
	this->pool = ::sandy::core::data::Pool_obj::getInstance();
	this->aDist = Array_obj< double >::__new();
	{
		int _g = 0;
		while((_g < 8)){
			__SAFE_POINT
			int i = _g++;
			this->m_aBoxEdges[i] = ::sandy::core::data::Point3D_obj::__new(null(),null(),null());
		}
	}
}
;
	return null();
}

Frustum_obj::~Frustum_obj() { }

Dynamic Frustum_obj::__CreateEmpty() { return  new Frustum_obj; }
hx::ObjectPtr< Frustum_obj > Frustum_obj::__new()
{  hx::ObjectPtr< Frustum_obj > result = new Frustum_obj();
	result->__construct();
	return result;}

Dynamic Frustum_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Frustum_obj > result = new Frustum_obj();
	result->__construct();
	return result;}

Void Frustum_obj::computePlanes( double p_nAspect,double p_nNear,double p_nFar,double p_nFov){
{
		__SAFE_POINT
		double lRadAngle = (p_nFov * 0.01745329251994329577);
		double tang = ::Math_obj::tan((lRadAngle * 0.5));
		double yNear = (-tang * p_nNear);
		double xNear = (yNear * p_nAspect);
		double yFar = ((p_nNear != 0)) ? double( (double(((yNear * p_nFar))) / double(p_nNear)) ) : double( (-tang * p_nFar) );
		double xFar = ((p_nNear != 0)) ? double( (double(((xNear * p_nFar))) / double(p_nNear)) ) : double( (((-tang * p_nAspect)) * p_nFar) );
		p_nNear = -p_nNear;
		p_nFar = -p_nFar;
		Array< ::sandy::core::data::Point3D > p = this->aPoints;
		p[0] = ::sandy::core::data::Point3D_obj::__new(xNear,yNear,p_nNear);
		p[1] = ::sandy::core::data::Point3D_obj::__new(xNear,-yNear,p_nNear);
		p[2] = ::sandy::core::data::Point3D_obj::__new(-xNear,-yNear,p_nNear);
		p[3] = ::sandy::core::data::Point3D_obj::__new(-xNear,yNear,p_nNear);
		p[4] = ::sandy::core::data::Point3D_obj::__new(xFar,yFar,p_nFar);
		p[5] = ::sandy::core::data::Point3D_obj::__new(xFar,-yFar,p_nFar);
		p[6] = ::sandy::core::data::Point3D_obj::__new(-xFar,-yFar,p_nFar);
		p[7] = ::sandy::core::data::Point3D_obj::__new(-xFar,yFar,p_nFar);
		this->aPlanes[3] = ::sandy::math::PlaneMath_obj::computePlaneFromPoints(p->__get(7),p->__get(6),p->__get(2));
		this->aPlanes[2] = ::sandy::math::PlaneMath_obj::computePlaneFromPoints(p->__get(4),p->__get(0),p->__get(5));
		this->aPlanes[4] = ::sandy::math::PlaneMath_obj::computePlaneFromPoints(p->__get(7),p->__get(0),p->__get(4));
		this->aPlanes[5] = ::sandy::math::PlaneMath_obj::computePlaneFromPoints(p->__get(5),p->__get(1),p->__get(6));
		this->aPlanes[0] = ::sandy::math::PlaneMath_obj::computePlaneFromPoints(p->__get(0),p->__get(2),p->__get(1));
		this->aPlanes[1] = ::sandy::math::PlaneMath_obj::computePlaneFromPoints(p->__get(4),p->__get(5),p->__get(6));
		{
			int _g = 0;
			while((_g < 6)){
				__SAFE_POINT
				int i = _g++;
				::sandy::math::PlaneMath_obj::normalizePlane(this->aPlanes->__get(i));
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC4(Frustum_obj,computePlanes,(void))

int Frustum_obj::pointInFrustum( ::sandy::core::data::Point3D p_oPoint){
	__SAFE_POINT
	{
		int _g = 0;
		Array< ::sandy::core::data::Plane > _g1 = this->aPlanes;
		while((_g < _g1->length)){
			__SAFE_POINT
			::sandy::core::data::Plane plane = _g1->__get(_g);
			++_g;
			if ((::sandy::math::PlaneMath_obj::classifyPoint(plane,p_oPoint) == ::sandy::math::PlaneMath_obj::NEGATIVE)){
				return 2;
			}
		}
	}
	return 1;
}


HX_DEFINE_DYNAMIC_FUNC1(Frustum_obj,pointInFrustum,return )

int Frustum_obj::polygonInFrustum( ::sandy::core::data::Polygon p_oPoly){
	int l_nIn = 0;
	int l_nOut = 0;
	double l_nDist;
	Array< ::sandy::core::data::Vertex > l_aVertices = p_oPoly->vertices;
	{
		int _g = 0;
		Array< ::sandy::core::data::Plane > _g1 = this->aPlanes;
		while((_g < _g1->length)){
			__SAFE_POINT
			::sandy::core::data::Plane plane = _g1->__get(_g);
			++_g;
			{
				int _g2 = 0;
				while((_g2 < l_aVertices->length)){
					__SAFE_POINT
					::sandy::core::data::Vertex l_oVertex = l_aVertices->__get(_g2);
					++_g2;
					l_nDist = ((((((plane->a * l_oVertex->wx) + (plane->b * l_oVertex->wy))) + (plane->c * l_oVertex->wz))) + plane->d);
					if ((l_nDist < 0)){
						if ((l_nIn > 0))
							return 0;
						l_nOut++;
					}
					else{
						if ((l_nOut > 0))
							return 0;
						l_nIn++;
					}
				}
			}
		}
	}
	if ((l_nIn == 0)){
		return 2;
	}
	else{
		return 1;
	}
}


HX_DEFINE_DYNAMIC_FUNC1(Frustum_obj,polygonInFrustum,return )

int Frustum_obj::sphereInFrustum( ::sandy::bounds::BSphere p_oS){
	double d = 0;
	int c = 0;
	double x = p_oS->position->x;
	double y = p_oS->position->y;
	double z = p_oS->position->z;
	double radius = p_oS->radius;
	{
		int _g = 0;
		Array< ::sandy::core::data::Plane > _g1 = this->aPlanes;
		while((_g < _g1->length)){
			__SAFE_POINT
			::sandy::core::data::Plane plane = _g1->__get(_g);
			++_g;
			d = ((((((plane->a * x) + (plane->b * y))) + (plane->c * z))) + plane->d);
			if ((d <= -radius)){
				return 2;
			}
			if ((d > radius)){
				c++;
			}
		}
	}
	return ((c == 6)) ? int( 1 ) : int( 0 );
}


HX_DEFINE_DYNAMIC_FUNC1(Frustum_obj,sphereInFrustum,return )

int Frustum_obj::boxInFrustum( ::sandy::bounds::BBox p_oBox){
	__SAFE_POINT
	int result = 1;
	double out;
	double iin;
	double lDist;
	p_oBox->getEdges(this->m_aBoxEdges);
	{
		int _g = 0;
		Array< ::sandy::core::data::Plane > _g1 = this->aPlanes;
		while((_g < _g1->length)){
			__SAFE_POINT
			::sandy::core::data::Plane plane = _g1->__get(_g);
			++_g;
			out = 0;
			iin = 0;
			{
				int _g2 = 0;
				Array< ::sandy::core::data::Point3D > _g3 = this->m_aBoxEdges;
				while((_g2 < _g3->length)){
					__SAFE_POINT
					::sandy::core::data::Point3D v = _g3->__get(_g2);
					++_g2;
					lDist = ((((((plane->a * v->x) + (plane->b * v->y))) + (plane->c * v->z))) + plane->d);
					if ((lDist < 0)){
						out++;
					}
					else{
						iin++;
					}
					if ((bool((iin > 0)) && bool((out > 0)))){
						break;
					}
				}
			}
			if ((iin == 0)){
				return 2;
			}
			else{
				if ((out > 0)){
					return 0;
				}
			}
		}
	}
	return result;
}


HX_DEFINE_DYNAMIC_FUNC1(Frustum_obj,boxInFrustum,return )

bool Frustum_obj::clipFrustum( Array< ::sandy::core::data::Vertex > p_aCvert,Array< ::sandy::core::data::UVCoord > p_aUVCoords){
	__SAFE_POINT
	if ((p_aCvert->length <= 2)){
		return true;
	}
	bool l_bResult;
	bool l_bClipped;
	l_bResult = this->clipPolygon(this->aPlanes->__get(0),p_aCvert,p_aUVCoords);
	if ((p_aCvert->length <= 2))
		return true;
	l_bClipped = this->clipPolygon(this->aPlanes->__get(3),p_aCvert,p_aUVCoords);
	if ((p_aCvert->length <= 2))
		return true;
	l_bResult = (bool(l_bResult) || bool(l_bClipped));
	l_bClipped = this->clipPolygon(this->aPlanes->__get(2),p_aCvert,p_aUVCoords);
	if ((p_aCvert->length <= 2))
		return true;
	l_bResult = (bool(l_bResult) || bool(l_bClipped));
	l_bClipped = this->clipPolygon(this->aPlanes->__get(5),p_aCvert,p_aUVCoords);
	if ((p_aCvert->length <= 2))
		return true;
	l_bResult = (bool(l_bResult) || bool(l_bClipped));
	l_bClipped = this->clipPolygon(this->aPlanes->__get(4),p_aCvert,p_aUVCoords);
	if ((p_aCvert->length <= 2))
		return true;
	l_bResult = (bool(l_bResult) || bool(l_bClipped));
	return l_bResult;
}


HX_DEFINE_DYNAMIC_FUNC2(Frustum_obj,clipFrustum,return )

bool Frustum_obj::clipFrontPlane( Array< ::sandy::core::data::Vertex > p_aCvert,Array< ::sandy::core::data::UVCoord > p_aUVCoords){
	__SAFE_POINT
	if ((p_aCvert->length <= 2))
		return true;
	return this->clipPolygon(this->aPlanes->__get(0),p_aCvert,p_aUVCoords);
}


HX_DEFINE_DYNAMIC_FUNC2(Frustum_obj,clipFrontPlane,return )

bool Frustum_obj::clipLineFrontPlane( Array< ::sandy::core::data::Vertex > p_aCvert){
	__SAFE_POINT
	::sandy::core::data::Plane l_oPlane = this->aPlanes->__get(0);
	Array< ::sandy::core::data::Vertex > tmp = p_aCvert->splice(0,p_aCvert->length);
	::sandy::core::data::Vertex v0 = tmp->__get(0);
	::sandy::core::data::Vertex v1 = tmp->__get(1);
	double l_nDist0 = ((((((l_oPlane->a * v0->wx) + (l_oPlane->b * v0->wy))) + (l_oPlane->c * v0->wz))) + l_oPlane->d);
	double l_nDist1 = ((((((l_oPlane->a * v1->wx) + (l_oPlane->b * v1->wy))) + (l_oPlane->c * v1->wz))) + l_oPlane->d);
	double d = 0;
	::sandy::core::data::Vertex t = ::sandy::core::data::Vertex_obj::__new(null(),null(),null(),null(),null(),null());
	if ((bool((l_nDist0 < 0)) && bool((l_nDist1 >= 0)))){
		d = (double(l_nDist0) / double(((l_nDist0 - l_nDist1))));
		t->wx = ((v0->wx + (((v1->wx - v0->wx)) * d)));
		t->wy = ((v0->wy + (((v1->wy - v0->wy)) * d)));
		t->wz = ((v0->wz + (((v1->wz - v0->wz)) * d)));
		p_aCvert->push(t);
		p_aCvert->push(v1);
		return true;
	}
	else{
		if ((bool((l_nDist1 < 0)) && bool((l_nDist0 >= 0)))){
			d = (double(l_nDist0) / double(((l_nDist0 - l_nDist1))));
			t->wx = ((v0->wx + (((v1->wx - v0->wx)) * d)));
			t->wy = ((v0->wy + (((v1->wy - v0->wy)) * d)));
			t->wz = ((v0->wz + (((v1->wz - v0->wz)) * d)));
			p_aCvert->push(v0);
			p_aCvert->push(t);
			return true;
		}
		else{
			if ((bool((l_nDist1 < 0)) && bool((l_nDist0 < 0)))){
				p_aCvert = null();
				return true;
			}
			else{
				if ((bool((l_nDist1 > 0)) && bool((l_nDist0 > 0)))){
					p_aCvert->push(v0);
					p_aCvert->push(v1);
					return false;
				}
			}
		}
	}
	return true;
}


HX_DEFINE_DYNAMIC_FUNC1(Frustum_obj,clipLineFrontPlane,return )

bool Frustum_obj::clipPolygon( ::sandy::core::data::Plane p_oPlane,Array< ::sandy::core::data::Vertex > p_aCvert,Array< ::sandy::core::data::UVCoord > p_aUVCoords){
	__SAFE_POINT
	bool allin = true;
	bool allout = true;
	::sandy::core::data::Vertex v;
	int i;
	int l = p_aCvert->length;
	double lDist;
	double a = p_oPlane->a;
	double b = p_oPlane->b;
	double c = p_oPlane->c;
	double d = p_oPlane->d;
	{
		Dynamic array = this->aDist;
		array->__Field(HX_STRING(L"splice",6))(0,array->__Field(HX_STRING(L"length",6)));
	}
	{
		int _g = 0;
		while((_g < p_aCvert->length)){
			__SAFE_POINT
			::sandy::core::data::Vertex v1 = p_aCvert->__get(_g);
			++_g;
			lDist = ((((((a * v1->wx) + (b * v1->wy))) + (c * v1->wz))) + d);
			if ((lDist < 0))
				allin = false;
			if ((lDist >= 0))
				allout = false;
			this->aDist->push(lDist);
		}
	}
	if (allin){
		return false;
	}
	else{
		if (allout){
			p_aCvert->splice(0,p_aCvert->length);
			p_aUVCoords->splice(0,p_aUVCoords->length);
			return true;
		}
	}
	Array< ::sandy::core::data::Vertex > tmp = p_aCvert->splice(0,p_aCvert->length);
	Array< ::sandy::core::data::UVCoord > l_aTmpUv = p_aUVCoords->splice(0,p_aUVCoords->length);
	::sandy::core::data::UVCoord l_oUV1 = l_aTmpUv->__get(0);
	::sandy::core::data::UVCoord l_oUV2 = null();
	::sandy::core::data::UVCoord l_oUVTmp = null();
	::sandy::core::data::Vertex v1 = tmp->__get(0);
	::sandy::core::data::Vertex v2 = null();
	::sandy::core::data::Vertex t = null();
	double dist2;
	double dist1 = this->aDist->__get(0);
	bool clipped = false;
	bool inside = ((dist1 >= 0));
	double curv = 0;
	{
		int _g1 = 1;
		int _g = ((l + 1));
		while((_g1 < _g)){
			__SAFE_POINT
			int i1 = _g1++;
			v2 = tmp->__get(hx::Mod(i1,l));
			l_oUV2 = l_aTmpUv->__get(hx::Mod(i1,l));
			dist2 = this->aDist->__get(hx::Mod(i1,l));
			if ((bool(inside) && bool(((dist2 >= 0))))){
				p_aCvert->push(v2);
				p_aUVCoords->push(l_oUV2);
			}
			else{
				if ((bool((!inside)) && bool(((dist2 >= 0))))){
					clipped = inside = true;
					t = this->pool->__getNextVertex();
					d = (double(dist1) / double(((dist1 - dist2))));
					t->wx = ((v1->wx + (((v2->wx - v1->wx)) * d)));
					t->wy = ((v1->wy + (((v2->wy - v1->wy)) * d)));
					t->wz = ((v1->wz + (((v2->wz - v1->wz)) * d)));
					p_aCvert[p_aCvert->length] = (t);
					p_aCvert[p_aCvert->length] = (v2);
					l_oUVTmp = ::sandy::core::data::UVCoord_obj::__new(null(),null());
					l_oUVTmp->u = ((l_oUV1->u + (((l_oUV2->u - l_oUV1->u)) * d)));
					l_oUVTmp->v = ((l_oUV1->v + (((l_oUV2->v - l_oUV1->v)) * d)));
					p_aUVCoords->push(l_oUVTmp);
					p_aUVCoords->push(l_oUV2);
				}
				else{
					if ((bool(inside) && bool(((dist2 < 0))))){
						clipped = true;
						inside = false;
						t = this->pool->__getNextVertex();
						d = (double(dist1) / double(((dist1 - dist2))));
						t->wx = ((v1->wx + (((v2->wx - v1->wx)) * d)));
						t->wy = ((v1->wy + (((v2->wy - v1->wy)) * d)));
						t->wz = ((v1->wz + (((v2->wz - v1->wz)) * d)));
						l_oUVTmp = this->pool->__getNextUV();
						l_oUVTmp->u = ((l_oUV1->u + (((l_oUV2->u - l_oUV1->u)) * d)));
						l_oUVTmp->v = ((l_oUV1->v + (((l_oUV2->v - l_oUV1->v)) * d)));
						p_aUVCoords->push(l_oUVTmp);
						p_aCvert->push(t);
					}
					else{
						clipped = true;
					}
				}
			}
			v1 = v2;
			dist1 = dist2;
			l_oUV1 = l_oUV2;
		}
	}
	return true;
}


HX_DEFINE_DYNAMIC_FUNC3(Frustum_obj,clipPolygon,return )

int Frustum_obj::NEAR;

int Frustum_obj::FAR;

int Frustum_obj::RIGHT;

int Frustum_obj::LEFT;

int Frustum_obj::TOP;

int Frustum_obj::BOTTOM;

int Frustum_obj::INSIDE;

int Frustum_obj::OUTSIDE;

int Frustum_obj::INTERSECT;

double Frustum_obj::EPSILON;


Frustum_obj::Frustum_obj()
{
}

void Frustum_obj::__Mark()
{
	hx::MarkMember(aPlanes);
	hx::MarkMember(aPoints);
	hx::MarkMember(aNormals);
	hx::MarkMember(aConstants);
	hx::MarkMember(m_aBoxEdges);
	hx::MarkMember(pool);
	hx::MarkMember(aDist);
}

Dynamic Frustum_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 3:
		if (!memcmp(inName.__s,L"FAR",sizeof(wchar_t)*3) ) { return FAR; }
		if (!memcmp(inName.__s,L"TOP",sizeof(wchar_t)*3) ) { return TOP; }
		break;
	case 4:
		if (!memcmp(inName.__s,L"NEAR",sizeof(wchar_t)*4) ) { return NEAR; }
		if (!memcmp(inName.__s,L"LEFT",sizeof(wchar_t)*4) ) { return LEFT; }
		if (!memcmp(inName.__s,L"pool",sizeof(wchar_t)*4) ) { return pool; }
		break;
	case 5:
		if (!memcmp(inName.__s,L"RIGHT",sizeof(wchar_t)*5) ) { return RIGHT; }
		if (!memcmp(inName.__s,L"aDist",sizeof(wchar_t)*5) ) { return aDist; }
		break;
	case 6:
		if (!memcmp(inName.__s,L"BOTTOM",sizeof(wchar_t)*6) ) { return BOTTOM; }
		if (!memcmp(inName.__s,L"INSIDE",sizeof(wchar_t)*6) ) { return INSIDE; }
		break;
	case 7:
		if (!memcmp(inName.__s,L"OUTSIDE",sizeof(wchar_t)*7) ) { return OUTSIDE; }
		if (!memcmp(inName.__s,L"EPSILON",sizeof(wchar_t)*7) ) { return EPSILON; }
		if (!memcmp(inName.__s,L"aPlanes",sizeof(wchar_t)*7) ) { return aPlanes; }
		if (!memcmp(inName.__s,L"aPoints",sizeof(wchar_t)*7) ) { return aPoints; }
		break;
	case 8:
		if (!memcmp(inName.__s,L"aNormals",sizeof(wchar_t)*8) ) { return aNormals; }
		break;
	case 9:
		if (!memcmp(inName.__s,L"INTERSECT",sizeof(wchar_t)*9) ) { return INTERSECT; }
		break;
	case 10:
		if (!memcmp(inName.__s,L"aConstants",sizeof(wchar_t)*10) ) { return aConstants; }
		break;
	case 11:
		if (!memcmp(inName.__s,L"m_aBoxEdges",sizeof(wchar_t)*11) ) { return m_aBoxEdges; }
		if (!memcmp(inName.__s,L"clipFrustum",sizeof(wchar_t)*11) ) { return clipFrustum_dyn(); }
		if (!memcmp(inName.__s,L"clipPolygon",sizeof(wchar_t)*11) ) { return clipPolygon_dyn(); }
		break;
	case 12:
		if (!memcmp(inName.__s,L"boxInFrustum",sizeof(wchar_t)*12) ) { return boxInFrustum_dyn(); }
		break;
	case 13:
		if (!memcmp(inName.__s,L"computePlanes",sizeof(wchar_t)*13) ) { return computePlanes_dyn(); }
		break;
	case 14:
		if (!memcmp(inName.__s,L"pointInFrustum",sizeof(wchar_t)*14) ) { return pointInFrustum_dyn(); }
		if (!memcmp(inName.__s,L"clipFrontPlane",sizeof(wchar_t)*14) ) { return clipFrontPlane_dyn(); }
		break;
	case 15:
		if (!memcmp(inName.__s,L"sphereInFrustum",sizeof(wchar_t)*15) ) { return sphereInFrustum_dyn(); }
		break;
	case 16:
		if (!memcmp(inName.__s,L"polygonInFrustum",sizeof(wchar_t)*16) ) { return polygonInFrustum_dyn(); }
		break;
	case 18:
		if (!memcmp(inName.__s,L"clipLineFrontPlane",sizeof(wchar_t)*18) ) { return clipLineFrontPlane_dyn(); }
	}
	return super::__Field(inName);
}

Dynamic Frustum_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	switch(inName.length) {
	case 3:
		if (!memcmp(inName.__s,L"FAR",sizeof(wchar_t)*3) ) { FAR=inValue.Cast< int >(); return inValue; }
		if (!memcmp(inName.__s,L"TOP",sizeof(wchar_t)*3) ) { TOP=inValue.Cast< int >(); return inValue; }
		break;
	case 4:
		if (!memcmp(inName.__s,L"NEAR",sizeof(wchar_t)*4) ) { NEAR=inValue.Cast< int >(); return inValue; }
		if (!memcmp(inName.__s,L"LEFT",sizeof(wchar_t)*4) ) { LEFT=inValue.Cast< int >(); return inValue; }
		if (!memcmp(inName.__s,L"pool",sizeof(wchar_t)*4) ) { pool=inValue.Cast< ::sandy::core::data::Pool >(); return inValue; }
		break;
	case 5:
		if (!memcmp(inName.__s,L"RIGHT",sizeof(wchar_t)*5) ) { RIGHT=inValue.Cast< int >(); return inValue; }
		if (!memcmp(inName.__s,L"aDist",sizeof(wchar_t)*5) ) { aDist=inValue.Cast< Array< double > >(); return inValue; }
		break;
	case 6:
		if (!memcmp(inName.__s,L"BOTTOM",sizeof(wchar_t)*6) ) { BOTTOM=inValue.Cast< int >(); return inValue; }
		if (!memcmp(inName.__s,L"INSIDE",sizeof(wchar_t)*6) ) { INSIDE=inValue.Cast< int >(); return inValue; }
		break;
	case 7:
		if (!memcmp(inName.__s,L"OUTSIDE",sizeof(wchar_t)*7) ) { OUTSIDE=inValue.Cast< int >(); return inValue; }
		if (!memcmp(inName.__s,L"EPSILON",sizeof(wchar_t)*7) ) { EPSILON=inValue.Cast< double >(); return inValue; }
		if (!memcmp(inName.__s,L"aPlanes",sizeof(wchar_t)*7) ) { aPlanes=inValue.Cast< Array< ::sandy::core::data::Plane > >(); return inValue; }
		if (!memcmp(inName.__s,L"aPoints",sizeof(wchar_t)*7) ) { aPoints=inValue.Cast< Array< ::sandy::core::data::Point3D > >(); return inValue; }
		break;
	case 8:
		if (!memcmp(inName.__s,L"aNormals",sizeof(wchar_t)*8) ) { aNormals=inValue.Cast< Array< ::sandy::core::data::Vertex > >(); return inValue; }
		break;
	case 9:
		if (!memcmp(inName.__s,L"INTERSECT",sizeof(wchar_t)*9) ) { INTERSECT=inValue.Cast< int >(); return inValue; }
		break;
	case 10:
		if (!memcmp(inName.__s,L"aConstants",sizeof(wchar_t)*10) ) { aConstants=inValue.Cast< Array< double > >(); return inValue; }
		break;
	case 11:
		if (!memcmp(inName.__s,L"m_aBoxEdges",sizeof(wchar_t)*11) ) { m_aBoxEdges=inValue.Cast< Array< ::sandy::core::data::Point3D > >(); return inValue; }
	}
	return super::__SetField(inName,inValue);
}

void Frustum_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_STRING(L"aPlanes",7));
	outFields->push(HX_STRING(L"aPoints",7));
	outFields->push(HX_STRING(L"aNormals",8));
	outFields->push(HX_STRING(L"aConstants",10));
	outFields->push(HX_STRING(L"m_aBoxEdges",11));
	outFields->push(HX_STRING(L"pool",4));
	outFields->push(HX_STRING(L"aDist",5));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_STRING(L"NEAR",4),
	HX_STRING(L"FAR",3),
	HX_STRING(L"RIGHT",5),
	HX_STRING(L"LEFT",4),
	HX_STRING(L"TOP",3),
	HX_STRING(L"BOTTOM",6),
	HX_STRING(L"INSIDE",6),
	HX_STRING(L"OUTSIDE",7),
	HX_STRING(L"INTERSECT",9),
	HX_STRING(L"EPSILON",7),
	String(null()) };

static ::String sMemberFields[] = {
	HX_STRING(L"aPlanes",7),
	HX_STRING(L"aPoints",7),
	HX_STRING(L"aNormals",8),
	HX_STRING(L"aConstants",10),
	HX_STRING(L"m_aBoxEdges",11),
	HX_STRING(L"pool",4),
	HX_STRING(L"aDist",5),
	HX_STRING(L"computePlanes",13),
	HX_STRING(L"pointInFrustum",14),
	HX_STRING(L"polygonInFrustum",16),
	HX_STRING(L"sphereInFrustum",15),
	HX_STRING(L"boxInFrustum",12),
	HX_STRING(L"clipFrustum",11),
	HX_STRING(L"clipFrontPlane",14),
	HX_STRING(L"clipLineFrontPlane",18),
	HX_STRING(L"clipPolygon",11),
	String(null()) };

static void sMarkStatics() {
	hx::MarkMember(Frustum_obj::NEAR);
	hx::MarkMember(Frustum_obj::FAR);
	hx::MarkMember(Frustum_obj::RIGHT);
	hx::MarkMember(Frustum_obj::LEFT);
	hx::MarkMember(Frustum_obj::TOP);
	hx::MarkMember(Frustum_obj::BOTTOM);
	hx::MarkMember(Frustum_obj::INSIDE);
	hx::MarkMember(Frustum_obj::OUTSIDE);
	hx::MarkMember(Frustum_obj::INTERSECT);
	hx::MarkMember(Frustum_obj::EPSILON);
};

Class Frustum_obj::__mClass;

void Frustum_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_STRING(L"sandy.view.Frustum",18), hx::TCanCast< Frustum_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void Frustum_obj::__boot()
{
	hx::Static(NEAR) = 0;
	hx::Static(FAR) = 1;
	hx::Static(RIGHT) = 2;
	hx::Static(LEFT) = 3;
	hx::Static(TOP) = 4;
	hx::Static(BOTTOM) = 5;
	hx::Static(INSIDE) = 1;
	hx::Static(OUTSIDE) = 2;
	hx::Static(INTERSECT) = 0;
	hx::Static(EPSILON) = 0.005;
}

} // end namespace sandy
} // end namespace view
