#include <hxcpp.h>

#ifndef INCLUDED_IntHash
#include <IntHash.h>
#endif
#ifndef INCLUDED_hxMath
#include <hxMath.h>
#endif
#ifndef INCLUDED_Reflect
#include <Reflect.h>
#endif
#ifndef INCLUDED_Std
#include <Std.h>
#endif
#ifndef INCLUDED_neash_display_DisplayObject
#include <neash/display/DisplayObject.h>
#endif
#ifndef INCLUDED_neash_display_DisplayObjectContainer
#include <neash/display/DisplayObjectContainer.h>
#endif
#ifndef INCLUDED_neash_display_InteractiveObject
#include <neash/display/InteractiveObject.h>
#endif
#ifndef INCLUDED_neash_display_Sprite
#include <neash/display/Sprite.h>
#endif
#ifndef INCLUDED_neash_events_Event
#include <neash/events/Event.h>
#endif
#ifndef INCLUDED_neash_events_EventDispatcher
#include <neash/events/EventDispatcher.h>
#endif
#ifndef INCLUDED_neash_events_IEventDispatcher
#include <neash/events/IEventDispatcher.h>
#endif
#ifndef INCLUDED_neash_events_KeyboardEvent
#include <neash/events/KeyboardEvent.h>
#endif
#ifndef INCLUDED_neash_events_MouseEvent
#include <neash/events/MouseEvent.h>
#endif
#ifndef INCLUDED_nme_display_Graphics
#include <nme/display/Graphics.h>
#endif
#ifndef INCLUDED_nme_display_IBitmapDrawable
#include <nme/display/IBitmapDrawable.h>
#endif
#ifndef INCLUDED_nme_geom_Matrix
#include <nme/geom/Matrix.h>
#endif
#ifndef INCLUDED_nme_geom_Point
#include <nme/geom/Point.h>
#endif
#ifndef INCLUDED_nme_geom_Rectangle
#include <nme/geom/Rectangle.h>
#endif
#ifndef INCLUDED_sandy_core_Scene3D
#include <sandy/core/Scene3D.h>
#endif
#ifndef INCLUDED_sandy_core_data_Edge3D
#include <sandy/core/data/Edge3D.h>
#endif
#ifndef INCLUDED_sandy_core_data_Matrix4
#include <sandy/core/data/Matrix4.h>
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
#ifndef INCLUDED_sandy_core_data_UVCoord
#include <sandy/core/data/UVCoord.h>
#endif
#ifndef INCLUDED_sandy_core_data_Vertex
#include <sandy/core/data/Vertex.h>
#endif
#ifndef INCLUDED_sandy_core_interaction_VirtualMouse
#include <sandy/core/interaction/VirtualMouse.h>
#endif
#ifndef INCLUDED_sandy_core_scenegraph_ATransformable
#include <sandy/core/scenegraph/ATransformable.h>
#endif
#ifndef INCLUDED_sandy_core_scenegraph_Geometry3D
#include <sandy/core/scenegraph/Geometry3D.h>
#endif
#ifndef INCLUDED_sandy_core_scenegraph_IDisplayable
#include <sandy/core/scenegraph/IDisplayable.h>
#endif
#ifndef INCLUDED_sandy_core_scenegraph_Node
#include <sandy/core/scenegraph/Node.h>
#endif
#ifndef INCLUDED_sandy_core_scenegraph_Shape3D
#include <sandy/core/scenegraph/Shape3D.h>
#endif
#ifndef INCLUDED_sandy_events_BubbleEvent
#include <sandy/events/BubbleEvent.h>
#endif
#ifndef INCLUDED_sandy_events_BubbleEventBroadcaster
#include <sandy/events/BubbleEventBroadcaster.h>
#endif
#ifndef INCLUDED_sandy_events_EventBroadcaster
#include <sandy/events/EventBroadcaster.h>
#endif
#ifndef INCLUDED_sandy_events_SandyEvent
#include <sandy/events/SandyEvent.h>
#endif
#ifndef INCLUDED_sandy_events_Shape3DEvent
#include <sandy/events/Shape3DEvent.h>
#endif
#ifndef INCLUDED_sandy_materials_Appearance
#include <sandy/materials/Appearance.h>
#endif
#ifndef INCLUDED_sandy_materials_Material
#include <sandy/materials/Material.h>
#endif
#ifndef INCLUDED_sandy_math_IntersectionMath
#include <sandy/math/IntersectionMath.h>
#endif
#ifndef INCLUDED_sandy_math_PlaneMath
#include <sandy/math/PlaneMath.h>
#endif
#ifndef INCLUDED_sandy_math_Point3DMath
#include <sandy/math/Point3DMath.h>
#endif
#ifndef INCLUDED_sandy_view_Frustum
#include <sandy/view/Frustum.h>
#endif
namespace sandy{
namespace core{
namespace data{

Void Polygon_obj::__construct(::sandy::core::scenegraph::Shape3D p_oOwner,::sandy::core::scenegraph::Geometry3D p_geometry,Array< int > p_aVertexID,Array< int > p_aUVCoordsID,Dynamic __o_p_nFaceNormalID,Dynamic __o_p_nEdgesID)
{
int p_nFaceNormalID = __o_p_nFaceNormalID.Default(0);
int p_nEdgesID = __o_p_nEdgesID.Default(0);
{
	this->id = ::sandy::core::data::Polygon_obj::_ID_++;
	this->isClipped = false;
	this->aNeighboors = Array_obj< ::sandy::core::data::Polygon >::__new();
	this->mouseEvents = false;
	this->mouseInteractivity = false;
	this->shape = p_oOwner;
	this->m_oGeometry = p_geometry;
	this->__create(p_aVertexID,p_aUVCoordsID,p_nFaceNormalID,p_nEdgesID);
	this->m_oContainer = ::neash::display::Sprite_obj::__new();
	::sandy::core::data::Polygon_obj::POLYGON_MAP->set(this->id,this);
	this->m_oEB = ::sandy::events::BubbleEventBroadcaster_obj::__new(this);
}
;
	return null();
}

Polygon_obj::~Polygon_obj() { }

Dynamic Polygon_obj::__CreateEmpty() { return  new Polygon_obj; }
hx::ObjectPtr< Polygon_obj > Polygon_obj::__new(::sandy::core::scenegraph::Shape3D p_oOwner,::sandy::core::scenegraph::Geometry3D p_geometry,Array< int > p_aVertexID,Array< int > p_aUVCoordsID,Dynamic __o_p_nFaceNormalID,Dynamic __o_p_nEdgesID)
{  hx::ObjectPtr< Polygon_obj > result = new Polygon_obj();
	result->__construct(p_oOwner,p_geometry,p_aVertexID,p_aUVCoordsID,__o_p_nFaceNormalID,__o_p_nEdgesID);
	return result;}

Dynamic Polygon_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Polygon_obj > result = new Polygon_obj();
	result->__construct(inArgs[0],inArgs[1],inArgs[2],inArgs[3],inArgs[4],inArgs[5]);
	return result;}

hx::Object *Polygon_obj::__ToInterface(const type_info &inType) {
	if (inType==typeid( ::sandy::core::scenegraph::IDisplayable_obj)) return operator ::sandy::core::scenegraph::IDisplayable_obj *();
	return super::__ToInterface(inType);
}

double Polygon_obj::__getArea( ){
	__SAFE_POINT
	if (::Math_obj::isNaN(this->_area)){
		::sandy::core::data::Vertex ab = this->b->clone();
		ab->sub(this->a);
		::sandy::core::data::Vertex ac = this->c->clone();
		ac->sub(this->a);
		this->_area = (0.5 * ab->cross(ac)->getNorm());
		if ((this->d != null())){
			::sandy::core::data::Vertex ad = this->d->clone();
			ad->sub(this->a);
			hx::AddEq(this->_area,(0.5 * ac->cross(ad)->getNorm()));
		}
	}
	return this->_area;
}


HX_DEFINE_DYNAMIC_FUNC0(Polygon_obj,__getArea,return )

Void Polygon_obj::update( Array< int > p_aVertexID){
{
		int i = 0;
		{
			int _g = 0;
			while((_g < p_aVertexID->length)){
				__SAFE_POINT
				int id = p_aVertexID->__get(_g);
				++_g;
				this->vertices[i] = this->m_oGeometry->aVertex->__get(id);
				this->vertexNormals[i] = this->m_oGeometry->aVertexNormals->__get(id);
				i++;
			}
		}
		this->a = this->vertices->__get(0);
		this->b = this->vertices->__get(1);
		this->c = this->vertices->__get(2);
		this->d = this->vertices->__get(3);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Polygon_obj,update,(void))

bool Polygon_obj::__getChanged( ){
	__SAFE_POINT
	return this->shape->__getChanged();
}


HX_DEFINE_DYNAMIC_FUNC0(Polygon_obj,__getChanged,return )

bool Polygon_obj::__setChanged( bool v){
	__SAFE_POINT
	this->shape->__setChanged(v);
	return v;
}


HX_DEFINE_DYNAMIC_FUNC1(Polygon_obj,__setChanged,return )

::sandy::core::Scene3D Polygon_obj::__setScene( ::sandy::core::Scene3D p_oScene){
	__SAFE_POINT
	if ((p_oScene == null()))
		return null();
	if ((this->m_oScene != null())){
		this->m_oScene->removeEventListener(HX_STRING(L"scene_render_finish",19),this->_finishMaterial_dyn(),null());
		this->m_oScene->removeEventListener(HX_STRING(L"scene_render_display_list",25),this->_beginMaterial_dyn(),null());
	}
	this->m_oScene = p_oScene;
	this->m_oScene->addEventListener(HX_STRING(L"scene_render_finish",19),this->_finishMaterial_dyn(),null(),null(),null());
	this->m_oScene->addEventListener(HX_STRING(L"scene_render_display_list",25),this->_beginMaterial_dyn(),null(),null(),null());
	return p_oScene;
}


HX_DEFINE_DYNAMIC_FUNC1(Polygon_obj,__setScene,return )

::sandy::core::Scene3D Polygon_obj::__getScene( ){
	return this->m_oScene;
}


HX_DEFINE_DYNAMIC_FUNC0(Polygon_obj,__getScene,return )

Void Polygon_obj::__create( Array< int > p_aVertexID,Array< int > p_aUVCoordsID,int p_nFaceNormalID,int p_nEdgeListID){
{
		__SAFE_POINT
		int i = 0;
		int l;
		this->vertexNormals = Array_obj< ::sandy::core::data::Vertex >::__new();
		this->vertices = Array_obj< ::sandy::core::data::Vertex >::__new();
		{
			int _g = 0;
			while((_g < p_aVertexID->length)){
				__SAFE_POINT
				int o = p_aVertexID->__get(_g);
				++_g;
				this->vertices[i] = this->m_oGeometry->aVertex->__get(p_aVertexID->__get(i));
				this->vertexNormals[i] = this->m_oGeometry->aVertexNormals->__get(p_aVertexID->__get(i));
				i++;
			}
		}
		this->a = this->vertices->__get(0);
		this->b = this->vertices->__get(1);
		this->c = this->vertices->__get(2);
		this->d = this->vertices->__get(3);
		if ((p_aUVCoordsID != null())){
			double l_nMinU = ::Math_obj::POSITIVE_INFINITY;
			double l_nMinV = ::Math_obj::POSITIVE_INFINITY;
			double l_nMaxU = ::Math_obj::NEGATIVE_INFINITY;
			double l_nMaxV = ::Math_obj::NEGATIVE_INFINITY;
			this->aUVCoord = Array_obj< ::sandy::core::data::UVCoord >::__new();
			i = 0;
			if ((p_aUVCoordsID != null())){
				{
					int _g = 0;
					while((_g < p_aUVCoordsID->length)){
						__SAFE_POINT
						int p = p_aUVCoordsID->__get(_g);
						++_g;
						::sandy::core::data::UVCoord l_oUV = this->m_oGeometry->aUVCoords->__get(p_aUVCoordsID->__get(i));
						this->aUVCoord[i] = l_oUV;
						if ((l_oUV->u < l_nMinU)){
							l_nMinU = l_oUV->u;
						}
						else{
							if ((l_oUV->u > l_nMaxU))
								l_nMaxU = l_oUV->u;
						}
						if ((l_oUV->v < l_nMinV)){
							l_nMinV = l_oUV->v;
						}
						else{
							if ((l_oUV->v > l_nMaxV))
								l_nMaxV = l_oUV->v;
						}
						i++;
					}
				}
				this->uvBounds = ::nme::geom::Rectangle_obj::__new(l_nMinU,l_nMinV,(l_nMaxU - l_nMinU),(l_nMaxV - l_nMinV));
			}
			else{
				this->aUVCoord = Array_obj< ::sandy::core::data::UVCoord >::__new().Add(::sandy::core::data::UVCoord_obj::__new(null(),null())).Add(::sandy::core::data::UVCoord_obj::__new(null(),null())).Add(::sandy::core::data::UVCoord_obj::__new(null(),null()));
				this->uvBounds = ::nme::geom::Rectangle_obj::__new(0,0,0,0);
			}
		}
		this->m_nNormalId = p_nFaceNormalID;
		this->__setNormal(this->m_oGeometry->aFacesNormals->__get(p_nFaceNormalID));
		if ((this->__getNormal() == null())){
			::sandy::core::data::Point3D l_oNormal = this->createNormal();
			this->m_nNormalId = this->m_oGeometry->setFaceNormal(this->m_oGeometry->getNextFaceNormalID(),l_oNormal->x,l_oNormal->y,l_oNormal->z);
		}
		this->aEdges = Array_obj< ::sandy::core::data::Edge3D >::__new();
		{
			int _g = 0;
			Array< int > _g1 = this->m_oGeometry->aFaceEdges->__get(p_nEdgeListID);
			while((_g < _g1->length)){
				__SAFE_POINT
				int l_nEdgeId = _g1->__get(_g);
				++_g;
				::sandy::core::data::Edge3D l_oEdge = this->m_oGeometry->aEdges->__get(l_nEdgeId);
				l_oEdge->vertex1 = this->m_oGeometry->aVertex->__get(l_oEdge->vertexId1);
				l_oEdge->vertex2 = this->m_oGeometry->aVertex->__get(l_oEdge->vertexId2);
				this->aEdges->push(l_oEdge);
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC4(Polygon_obj,__create,(void))

::sandy::core::data::Vertex Polygon_obj::__getNormal( ){
	return this->m_oGeometry->aFacesNormals->__get(this->m_nNormalId);
}


HX_DEFINE_DYNAMIC_FUNC0(Polygon_obj,__getNormal,return )

::sandy::core::data::Vertex Polygon_obj::__setNormal( ::sandy::core::data::Vertex p_oVertex){
	__SAFE_POINT
	if ((p_oVertex != null()))
		this->m_oGeometry->aFacesNormals[this->m_nNormalId]->copy(p_oVertex);
	return p_oVertex;
}


HX_DEFINE_DYNAMIC_FUNC1(Polygon_obj,__setNormal,return )

Void Polygon_obj::updateNormal( ){
{
		__SAFE_POINT
		double x = (((((this->a->y - this->b->y)) * ((this->c->z - this->b->z)))) - ((((this->a->z - this->b->z)) * ((this->c->y - this->b->y)))));
		double y = (((((this->a->z - this->b->z)) * ((this->c->x - this->b->x)))) - ((((this->a->x - this->b->x)) * ((this->c->z - this->b->z)))));
		double z = (((((this->a->x - this->b->x)) * ((this->c->y - this->b->y)))) - ((((this->a->y - this->b->y)) * ((this->c->x - this->b->x)))));
		this->__getNormal()->reset(x,y,z);
		if ((this->__getNormal()->getNorm() > 0)){
			this->__getNormal()->normalize();
		}
		else{
			this->__getNormal()->y = 1;
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Polygon_obj,updateNormal,(void))

double Polygon_obj::__getDepth( ){
	return this->m_nDepth;
}


HX_DEFINE_DYNAMIC_FUNC0(Polygon_obj,__getDepth,return )

double Polygon_obj::__setDepth( double p_nDepth){
	this->m_nDepth = p_nDepth;
	return p_nDepth;
}


HX_DEFINE_DYNAMIC_FUNC1(Polygon_obj,__setDepth,return )

::sandy::events::BubbleEventBroadcaster Polygon_obj::__getBroadcaster( ){
	return this->m_oEB;
}


HX_DEFINE_DYNAMIC_FUNC0(Polygon_obj,__getBroadcaster,return )

Void Polygon_obj::addEventListener( ::String p_sEvent,Dynamic oL,Array< Dynamic > arguments){
{
		__SAFE_POINT
		::Reflect_obj::callMethod(this->m_oEB->addEventListener_dyn(),this->m_oEB,arguments);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC3(Polygon_obj,addEventListener,(void))

Void Polygon_obj::removeEventListener( ::String p_sEvent,Dynamic oL){
{
		__SAFE_POINT
		this->m_oEB->removeEventListener(p_sEvent,oL,null());
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(Polygon_obj,removeEventListener,(void))

Void Polygon_obj::precompute( ){
{
		this->isClipped = false;
		this->minZ = this->a->wz;
		if ((this->b->wz < this->minZ))
			this->minZ = this->b->wz;
		this->m_nDepth = (this->a->wz + this->b->wz);
		if ((this->c != null())){
			if ((this->c->wz < this->minZ))
				this->minZ = this->c->wz;
			hx::AddEq(this->m_nDepth,this->c->wz);
		}
		if ((this->d != null())){
			if ((this->d->wz < this->minZ))
				this->minZ = this->d->wz;
			hx::AddEq(this->m_nDepth,this->d->wz);
		}
		hx::DivEq(this->m_nDepth,this->vertices->length);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Polygon_obj,precompute,(void))

::sandy::core::data::Point3D Polygon_obj::get3DFrom2D( ::nme::geom::Point p_oScreenPoint){
	__SAFE_POINT
	::nme::geom::Matrix m1 = ::nme::geom::Matrix_obj::__new((this->vertices[1]->sx - this->vertices[0]->sx),(this->vertices[2]->sx - this->vertices[0]->sx),(this->vertices[1]->sy - this->vertices[0]->sy),(this->vertices[2]->sy - this->vertices[0]->sy),0,0);
	m1->invert();
	double capA = ((m1->a * ((p_oScreenPoint->x - this->vertices[0]->sx))) + (m1->b * ((p_oScreenPoint->y - this->vertices[0]->sy))));
	double capB = ((m1->c * ((p_oScreenPoint->x - this->vertices[0]->sx))) + (m1->d * ((p_oScreenPoint->y - this->vertices[0]->sy))));
	::sandy::core::data::Point3D l_oPoint = ::sandy::core::data::Point3D_obj::__new((((this->vertices[0]->x + (capA * ((this->vertices[1]->x - this->vertices[0]->x))))) + (capB * ((this->vertices[2]->x - this->vertices[0]->x)))),(((this->vertices[0]->y + (capA * ((this->vertices[1]->y - this->vertices[0]->y))))) + (capB * ((this->vertices[2]->y - this->vertices[0]->y)))),(((this->vertices[0]->z + (capA * ((this->vertices[1]->z - this->vertices[0]->z))))) + (capB * ((this->vertices[2]->z - this->vertices[0]->z)))));
	this->shape->__getMatrix()->transform(l_oPoint);
	return l_oPoint;
}


HX_DEFINE_DYNAMIC_FUNC1(Polygon_obj,get3DFrom2D,return )

::sandy::core::data::UVCoord Polygon_obj::getUVFrom2D( ::nme::geom::Point p_oScreenPoint){
	__SAFE_POINT
	::nme::geom::Point p0 = ::nme::geom::Point_obj::__new(this->vertices[0]->sx,this->vertices[0]->sy);
	::nme::geom::Point p1 = ::nme::geom::Point_obj::__new(this->vertices[1]->sx,this->vertices[1]->sy);
	::nme::geom::Point p2 = ::nme::geom::Point_obj::__new(this->vertices[2]->sx,this->vertices[2]->sy);
	::sandy::core::data::UVCoord u0 = this->aUVCoord->__get(0);
	::sandy::core::data::UVCoord u1 = this->aUVCoord->__get(1);
	::sandy::core::data::UVCoord u2 = this->aUVCoord->__get(2);
	::nme::geom::Point v01 = ::nme::geom::Point_obj::__new((p1->x - p0->x),(p1->y - p0->y));
	::nme::geom::Point vn01 = v01->clone();
	vn01->normalize(1);
	::nme::geom::Point v02 = ::nme::geom::Point_obj::__new((p2->x - p0->x),(p2->y - p0->y));
	::nme::geom::Point vn02 = v02->clone();
	vn02->normalize(1);
	::nme::geom::Point v4 = ::nme::geom::Point_obj::__new((p_oScreenPoint->x - v01->x),(p_oScreenPoint->y - v01->y));
	::nme::geom::Point l_oInter = ::sandy::math::IntersectionMath_obj::intersectionLine2D(p0,p2,p_oScreenPoint,v4);
	::nme::geom::Point vi02 = ::nme::geom::Point_obj::__new((l_oInter->x - p0->x),(l_oInter->y - p0->y));
	::nme::geom::Point vi01 = ::nme::geom::Point_obj::__new((p_oScreenPoint->x - l_oInter->x),(p_oScreenPoint->y - l_oInter->y));
	double d1 = (double(vi01->get_length()) / double(v01->get_length()));
	double d2 = (double(vi02->get_length()) / double(v02->get_length()));
	return ::sandy::core::data::UVCoord_obj::__new((((u0->u + (d1 * ((u1->u - u0->u))))) + (d2 * ((u2->u - u0->u)))),(((u0->v + (d1 * ((u1->v - u0->v))))) + (d2 * ((u2->v - u0->v)))));
}


HX_DEFINE_DYNAMIC_FUNC1(Polygon_obj,getUVFrom2D,return )

Array< ::sandy::core::data::Vertex > Polygon_obj::clip( ::sandy::view::Frustum p_oFrustum){
	__SAFE_POINT
	this->cvertices = null();
	this->caUVCoord = null();
	int l_oCull = p_oFrustum->polygonInFrustum(this);
	if ((l_oCull == 1)){
		return this->vertices;
	}
	else{
		if ((l_oCull == 2))
			return null();
	}
	if ((this->vertices->length < 3)){
		this->clipFrontPlane(p_oFrustum);
	}
	else{
		this->cvertices = this->vertices->copy();
		this->caUVCoord = this->aUVCoord->copy();
		this->isClipped = p_oFrustum->clipFrustum(this->cvertices,this->caUVCoord);
	}
	return this->cvertices;
}


HX_DEFINE_DYNAMIC_FUNC1(Polygon_obj,clip,return )

Array< ::sandy::core::data::Vertex > Polygon_obj::clipFrontPlane( ::sandy::view::Frustum p_oFrustum){
	__SAFE_POINT
	this->cvertices = this->vertices->copy();
	if ((this->vertices->length < 3)){
		this->isClipped = p_oFrustum->clipLineFrontPlane(this->cvertices);
	}
	else{
		this->caUVCoord = this->aUVCoord->copy();
		this->isClipped = p_oFrustum->clipFrontPlane(this->cvertices,this->caUVCoord);
	}
	return this->cvertices;
}


HX_DEFINE_DYNAMIC_FUNC1(Polygon_obj,clipFrontPlane,return )

Void Polygon_obj::clear( ){
{
		__SAFE_POINT
		if ((this->m_oContainer != null()))
			this->m_oContainer->GetGraphics()->clear();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Polygon_obj,clear,(void))

Void Polygon_obj::display( ::neash::display::Sprite p_oContainer){
{
		__SAFE_POINT
		::neash::display::Sprite lCont = ((p_oContainer != null())) ? ::neash::display::Sprite( p_oContainer ) : ::neash::display::Sprite( this->m_oContainer );
		if ((this->__getMaterial() != null()))
			this->__getMaterial()->renderPolygon(this->__getScene(),this,lCont);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Polygon_obj,display,(void))

::sandy::materials::Material Polygon_obj::__getMaterial( ){
	__SAFE_POINT
	if ((this->m_oAppearance == null()))
		return null();
	return (this->visible) ? ::sandy::materials::Material( this->m_oAppearance->__getFrontMaterial() ) : ::sandy::materials::Material( this->m_oAppearance->__getBackMaterial() );
}


HX_DEFINE_DYNAMIC_FUNC0(Polygon_obj,__getMaterial,return )

::sandy::materials::Material Polygon_obj::__setMaterial( ::sandy::materials::Material v){
	return hx::Throw (HX_STRING(L"unimplemented",13));
}


HX_DEFINE_DYNAMIC_FUNC1(Polygon_obj,__setMaterial,return )

::neash::display::Sprite Polygon_obj::__getContainer( ){
	return this->m_oContainer;
}


HX_DEFINE_DYNAMIC_FUNC0(Polygon_obj,__getContainer,return )

::String Polygon_obj::toString( ){
	return (((((((HX_STRING(L"sandy.core.data.Polygon::id=",28) + this->id)) + HX_STRING(L" [Points: ",10))) + this->vertices->length)) + HX_STRING(L"]",1));
}


HX_DEFINE_DYNAMIC_FUNC0(Polygon_obj,toString,return )

bool Polygon_obj::__getEnableEvents( ){
	return this->mouseEvents;
}


HX_DEFINE_DYNAMIC_FUNC0(Polygon_obj,__getEnableEvents,return )

bool Polygon_obj::__setEnableEvents( bool b){
	__SAFE_POINT
	if ((bool(b) && bool(!this->mouseEvents))){
		this->__getContainer()->addEventListener(::neash::events::MouseEvent_obj::CLICK,this->_onInteraction_dyn(),null(),null(),null());
		this->__getContainer()->addEventListener(::neash::events::MouseEvent_obj::MOUSE_UP,this->_onInteraction_dyn(),null(),null(),null());
		this->__getContainer()->addEventListener(::neash::events::MouseEvent_obj::MOUSE_DOWN,this->_onInteraction_dyn(),null(),null(),null());
		this->__getContainer()->addEventListener(::neash::events::MouseEvent_obj::ROLL_OVER,this->_onInteraction_dyn(),null(),null(),null());
		this->__getContainer()->addEventListener(::neash::events::MouseEvent_obj::ROLL_OUT,this->_onInteraction_dyn(),null(),null(),null());
		this->__getContainer()->addEventListener(::neash::events::MouseEvent_obj::DOUBLE_CLICK,this->_onInteraction_dyn(),null(),null(),null());
		this->__getContainer()->addEventListener(::neash::events::MouseEvent_obj::MOUSE_MOVE,this->_onInteraction_dyn(),null(),null(),null());
		this->__getContainer()->addEventListener(::neash::events::MouseEvent_obj::MOUSE_OVER,this->_onInteraction_dyn(),null(),null(),null());
		this->__getContainer()->addEventListener(::neash::events::MouseEvent_obj::MOUSE_OUT,this->_onInteraction_dyn(),null(),null(),null());
		this->__getContainer()->addEventListener(::neash::events::MouseEvent_obj::MOUSE_WHEEL,this->_onInteraction_dyn(),null(),null(),null());
	}
	else{
		if ((bool(!b) && bool(this->mouseEvents))){
			this->__getContainer()->removeEventListener(::neash::events::MouseEvent_obj::CLICK,this->_onInteraction_dyn(),null());
			this->__getContainer()->removeEventListener(::neash::events::MouseEvent_obj::MOUSE_UP,this->_onInteraction_dyn(),null());
			this->__getContainer()->removeEventListener(::neash::events::MouseEvent_obj::MOUSE_DOWN,this->_onInteraction_dyn(),null());
			this->__getContainer()->removeEventListener(::neash::events::MouseEvent_obj::ROLL_OVER,this->_onInteraction_dyn(),null());
			this->__getContainer()->removeEventListener(::neash::events::MouseEvent_obj::ROLL_OUT,this->_onInteraction_dyn(),null());
			this->__getContainer()->removeEventListener(::neash::events::MouseEvent_obj::DOUBLE_CLICK,this->_onInteraction_dyn(),null());
			this->__getContainer()->removeEventListener(::neash::events::MouseEvent_obj::MOUSE_MOVE,this->_onInteraction_dyn(),null());
			this->__getContainer()->removeEventListener(::neash::events::MouseEvent_obj::MOUSE_OVER,this->_onInteraction_dyn(),null());
			this->__getContainer()->removeEventListener(::neash::events::MouseEvent_obj::MOUSE_OUT,this->_onInteraction_dyn(),null());
			this->__getContainer()->removeEventListener(::neash::events::MouseEvent_obj::MOUSE_WHEEL,this->_onInteraction_dyn(),null());
		}
	}
	this->mouseEvents = b;
	return b;
}


HX_DEFINE_DYNAMIC_FUNC1(Polygon_obj,__setEnableEvents,return )

Void Polygon_obj::_onInteraction( ::neash::events::Event p_oEvt){
{
		__SAFE_POINT
		::nme::geom::Point l_oClick = ::nme::geom::Point_obj::__new(this->m_oContainer->GetMouseX(),this->m_oContainer->GetMouseY());
		::sandy::core::data::UVCoord l_oUV = this->getUVFrom2D(l_oClick);
		::sandy::core::data::Point3D l_oPt3d = this->get3DFrom2D(l_oClick);
		this->shape->m_oLastContainer = this->m_oContainer;
		this->shape->m_oLastEvent = ::sandy::events::Shape3DEvent_obj::__new(p_oEvt->type,this->shape,this,l_oUV,l_oPt3d,p_oEvt);
		this->m_oEB->dispatchEvent(this->shape->m_oLastEvent);
		if ((p_oEvt->type == ::neash::events::MouseEvent_obj::MOUSE_OVER))
			this->shape->m_bWasOver = true;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Polygon_obj,_onInteraction,(void))

Void Polygon_obj::_startMouseInteraction( ::neash::events::MouseEvent e){
{
		__SAFE_POINT
		this->__getContainer()->addEventListener(::neash::events::MouseEvent_obj::CLICK,this->_onTextureInteraction_dyn(),null(),null(),null());
		this->__getContainer()->addEventListener(::neash::events::MouseEvent_obj::MOUSE_UP,this->_onTextureInteraction_dyn(),null(),null(),null());
		this->__getContainer()->addEventListener(::neash::events::MouseEvent_obj::MOUSE_DOWN,this->_onTextureInteraction_dyn(),null(),null(),null());
		this->__getContainer()->addEventListener(::neash::events::MouseEvent_obj::DOUBLE_CLICK,this->_onTextureInteraction_dyn(),null(),null(),null());
		this->__getContainer()->addEventListener(::neash::events::MouseEvent_obj::MOUSE_MOVE,this->_onTextureInteraction_dyn(),null(),null(),null());
		this->__getContainer()->addEventListener(::neash::events::MouseEvent_obj::MOUSE_OVER,this->_onTextureInteraction_dyn(),null(),null(),null());
		this->__getContainer()->addEventListener(::neash::events::MouseEvent_obj::MOUSE_OUT,this->_onTextureInteraction_dyn(),null(),null(),null());
		this->__getContainer()->addEventListener(::neash::events::MouseEvent_obj::MOUSE_WHEEL,this->_onTextureInteraction_dyn(),null(),null(),null());
		this->__getContainer()->addEventListener(::neash::events::KeyboardEvent_obj::KEY_DOWN,this->_onTextureInteraction_dyn(),null(),null(),null());
		this->__getContainer()->addEventListener(::neash::events::KeyboardEvent_obj::KEY_UP,this->_onTextureInteraction_dyn(),null(),null(),null());
		this->m_oContainer->addEventListener(::neash::events::Event_obj::ENTER_FRAME,this->_onTextureInteraction_dyn(),null(),null(),null());
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Polygon_obj,_startMouseInteraction,(void))

Void Polygon_obj::_stopMouseInteraction( ::neash::events::MouseEvent e){
{
		__SAFE_POINT
		this->__getContainer()->addEventListener(::neash::events::MouseEvent_obj::CLICK,this->_onTextureInteraction_dyn(),null(),null(),null());
		this->__getContainer()->addEventListener(::neash::events::MouseEvent_obj::MOUSE_UP,this->_onTextureInteraction_dyn(),null(),null(),null());
		this->__getContainer()->addEventListener(::neash::events::MouseEvent_obj::MOUSE_DOWN,this->_onTextureInteraction_dyn(),null(),null(),null());
		this->__getContainer()->addEventListener(::neash::events::MouseEvent_obj::DOUBLE_CLICK,this->_onTextureInteraction_dyn(),null(),null(),null());
		this->__getContainer()->addEventListener(::neash::events::MouseEvent_obj::MOUSE_MOVE,this->_onTextureInteraction_dyn(),null(),null(),null());
		this->__getContainer()->addEventListener(::neash::events::MouseEvent_obj::MOUSE_OVER,this->_onTextureInteraction_dyn(),null(),null(),null());
		this->__getContainer()->addEventListener(::neash::events::MouseEvent_obj::MOUSE_OUT,this->_onTextureInteraction_dyn(),null(),null(),null());
		this->__getContainer()->addEventListener(::neash::events::MouseEvent_obj::MOUSE_WHEEL,this->_onTextureInteraction_dyn(),null(),null(),null());
		this->__getContainer()->addEventListener(::neash::events::KeyboardEvent_obj::KEY_DOWN,this->_onTextureInteraction_dyn(),null(),null(),null());
		this->__getContainer()->addEventListener(::neash::events::KeyboardEvent_obj::KEY_UP,this->_onTextureInteraction_dyn(),null(),null(),null());
		this->m_oContainer->addEventListener(::neash::events::Event_obj::ENTER_FRAME,this->_onTextureInteraction_dyn(),null(),null(),null());
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Polygon_obj,_stopMouseInteraction,(void))

bool Polygon_obj::__getEnableInteractivity( ){
	return this->mouseInteractivity;
}


HX_DEFINE_DYNAMIC_FUNC0(Polygon_obj,__getEnableInteractivity,return )

bool Polygon_obj::__setEnableInteractivity( bool p_bState){
	__SAFE_POINT
	if ((p_bState != this->mouseInteractivity)){
		if (p_bState){
			this->__getContainer()->addEventListener(::neash::events::MouseEvent_obj::ROLL_OVER,this->_startMouseInteraction_dyn(),false,null(),null());
			this->__getContainer()->addEventListener(::neash::events::MouseEvent_obj::ROLL_OUT,this->_stopMouseInteraction_dyn(),false,null(),null());
		}
		else{
			this->_stopMouseInteraction(null());
		}
		this->mouseInteractivity = p_bState;
	}
	return p_bState;
}


HX_DEFINE_DYNAMIC_FUNC1(Polygon_obj,__setEnableInteractivity,return )

Void Polygon_obj::_onTextureInteraction( ::neash::events::Event p_oEvt){
{
		__SAFE_POINT
		::neash::events::MouseEvent l_oEvt = null();
		if ((bool((p_oEvt == null())) || bool(!::Std_obj::is(p_oEvt,hx::ClassOf< ::neash::events::MouseEvent >())))){
			l_oEvt = ::neash::events::MouseEvent_obj::__new(::neash::events::MouseEvent_obj::MOUSE_MOVE,true,false,0,0,null(),false,false,false,false,0);
		}
		else{
			l_oEvt = p_oEvt;
		}
		::nme::geom::Point pt2D = ::nme::geom::Point_obj::__new(this->__getScene()->container->GetMouseX(),this->__getScene()->container->GetMouseY());
		::sandy::core::data::UVCoord uv = this->getUVFrom2D(pt2D);
		::sandy::core::interaction::VirtualMouse_obj::getInstance()->interactWithTexture(this,uv,l_oEvt);
		this->_onInteraction(p_oEvt);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Polygon_obj,_onTextureInteraction,(void))

::sandy::core::data::Point3D Polygon_obj::createTransformedNormal( ){
	__SAFE_POINT
	if ((this->vertices->length > 2)){
		::sandy::core::data::Point3D v;
		::sandy::core::data::Point3D w;
		::sandy::core::data::Vertex a = this->vertices->__get(0);
		::sandy::core::data::Vertex b = this->vertices->__get(1);
		::sandy::core::data::Vertex c = this->vertices->__get(2);
		v = ::sandy::core::data::Point3D_obj::__new((b->wx - a->wx),(b->wy - a->wy),(b->wz - a->wz));
		w = ::sandy::core::data::Point3D_obj::__new((b->wx - c->wx),(b->wy - c->wy),(b->wz - c->wz));
		::sandy::core::data::Point3D l_normal = ::sandy::math::Point3DMath_obj::cross(v,w);
		{
			double norm = ::Math_obj::sqrt(((((l_normal->x * l_normal->x) + (l_normal->y * l_normal->y))) + (l_normal->z * l_normal->z)));
			if ((bool((norm == 0)) || bool((norm == 1)))){
				false;
			}
			else{
				hx::DivEq(l_normal->x,norm);
				hx::DivEq(l_normal->y,norm);
				hx::DivEq(l_normal->z,norm);
				true;
			}
		}
		return l_normal;
	}
	else{
		return ::sandy::core::data::Point3D_obj::__new(null(),null(),null());
	}
}


HX_DEFINE_DYNAMIC_FUNC0(Polygon_obj,createTransformedNormal,return )

::sandy::core::data::Point3D Polygon_obj::createNormal( ){
	__SAFE_POINT
	if ((this->vertices->length > 2)){
		::sandy::core::data::Point3D v;
		::sandy::core::data::Point3D w;
		::sandy::core::data::Vertex a = this->vertices->__get(0);
		::sandy::core::data::Vertex b = this->vertices->__get(1);
		::sandy::core::data::Vertex c = this->vertices->__get(2);
		v = ::sandy::core::data::Point3D_obj::__new((b->wx - a->wx),(b->wy - a->wy),(b->wz - a->wz));
		w = ::sandy::core::data::Point3D_obj::__new((b->wx - c->wx),(b->wy - c->wy),(b->wz - c->wz));
		::sandy::core::data::Point3D l_normal = ::sandy::math::Point3DMath_obj::cross(v,w);
		{
			double norm = ::Math_obj::sqrt(((((l_normal->x * l_normal->x) + (l_normal->y * l_normal->y))) + (l_normal->z * l_normal->z)));
			if ((bool((norm == 0)) || bool((norm == 1)))){
				false;
			}
			else{
				hx::DivEq(l_normal->x,norm);
				hx::DivEq(l_normal->y,norm);
				hx::DivEq(l_normal->z,norm);
				true;
			}
		}
		return l_normal;
	}
	else{
		return ::sandy::core::data::Point3D_obj::__new(null(),null(),null());
	}
}


HX_DEFINE_DYNAMIC_FUNC0(Polygon_obj,createNormal,return )

::sandy::materials::Appearance Polygon_obj::__getAppearance( ){
	return this->m_oAppearance;
}


HX_DEFINE_DYNAMIC_FUNC0(Polygon_obj,__getAppearance,return )

::sandy::materials::Appearance Polygon_obj::__setAppearance( ::sandy::materials::Appearance p_oApp){
	__SAFE_POINT
	if ((p_oApp == this->m_oAppearance))
		return null();
	if ((bool((this->m_oAppearance != null())) && bool((p_oApp != null())))){
		if ((p_oApp->__getFrontMaterial() != this->m_oAppearance->__getFrontMaterial())){
			if ((this->m_oAppearance->__getFrontMaterial() != null()))
				this->m_oAppearance->__getFrontMaterial()->unlink(this);
			p_oApp->__getFrontMaterial()->init(this);
		}
		if ((bool((this->m_oAppearance->__getFrontMaterial() != this->m_oAppearance->__getBackMaterial())) && bool((p_oApp->__getBackMaterial() != this->m_oAppearance->__getBackMaterial())))){
			this->m_oAppearance->__getBackMaterial()->unlink(this);
		}
		if ((bool((p_oApp->__getFrontMaterial() != p_oApp->__getBackMaterial())) && bool((p_oApp->__getBackMaterial() != this->m_oAppearance->__getBackMaterial())))){
			p_oApp->__getBackMaterial()->init(this);
		}
		this->m_oAppearance = p_oApp;
	}
	else{
		if ((p_oApp != null())){
			this->m_oAppearance = p_oApp;
			this->m_oAppearance->__getFrontMaterial()->init(this);
			if ((this->m_oAppearance->__getBackMaterial() != this->m_oAppearance->__getFrontMaterial()))
				this->m_oAppearance->__getBackMaterial()->init(this);
		}
		else{
			if ((this->m_oAppearance != null())){
				if ((this->m_oAppearance->__getFrontMaterial() != null()))
					this->m_oAppearance->__getFrontMaterial()->unlink(this);
				if ((this->m_oAppearance->__getBackMaterial() != this->m_oAppearance->__getFrontMaterial()))
					this->m_oAppearance->__getBackMaterial()->unlink(this);
				this->m_oAppearance = null();
			}
		}
	}
	return p_oApp;
}


HX_DEFINE_DYNAMIC_FUNC1(Polygon_obj,__setAppearance,return )

Void Polygon_obj::_finishMaterial( ::sandy::events::SandyEvent pEvt){
{
		__SAFE_POINT
		if ((this->m_oAppearance == null()))
			return null();
		if ((this->m_oAppearance->__getFrontMaterial() != null())){
			this->m_oAppearance->__getFrontMaterial()->finish(this->m_oScene);
		}
		if ((bool((this->m_oAppearance->__getBackMaterial() != null())) && bool((this->m_oAppearance->__getBackMaterial() != this->m_oAppearance->__getFrontMaterial())))){
			this->m_oAppearance->__getBackMaterial()->finish(this->m_oScene);
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Polygon_obj,_finishMaterial,(void))

Void Polygon_obj::_beginMaterial( ::sandy::events::SandyEvent pEvt){
{
		__SAFE_POINT
		if ((this->m_oAppearance == null()))
			return null();
		if ((this->m_oAppearance->__getFrontMaterial() != null())){
			this->m_oAppearance->__getFrontMaterial()->begin(this->m_oScene);
		}
		if ((bool((this->m_oAppearance->__getBackMaterial() != null())) && bool((this->m_oAppearance->__getBackMaterial() != this->m_oAppearance->__getFrontMaterial())))){
			this->m_oAppearance->__getBackMaterial()->begin(this->m_oScene);
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Polygon_obj,_beginMaterial,(void))

Void Polygon_obj::swapCulling( ){
{
		__SAFE_POINT
		this->__getNormal()->negate();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Polygon_obj,swapCulling,(void))

Void Polygon_obj::destroy( ){
{
		__SAFE_POINT
		this->clear();
		if ((this->__getScene() != null())){
			this->__getScene()->removeEventListener(HX_STRING(L"scene_render_finish",19),this->_finishMaterial_dyn(),null());
			this->__getScene()->removeEventListener(HX_STRING(L"scene_render_display_list",25),this->_beginMaterial_dyn(),null());
		}
		this->__setEnableEvents(false);
		this->__setEnableInteractivity(false);
		if ((this->__getAppearance() != null())){
			if ((this->__getAppearance()->__getFrontMaterial() != null()))
				this->__getAppearance()->__getFrontMaterial()->unlink(this);
			if ((this->__getAppearance()->__getBackMaterial() != null()))
				this->__getAppearance()->__getBackMaterial()->unlink(this);
			this->__setAppearance(null());
		}
		if ((this->m_oContainer != null())){
			if ((this->m_oContainer->GetParent() != null()))
				this->m_oContainer->GetParent()->removeChild(this->m_oContainer);
			this->m_oContainer = null();
		}
		this->cvertices = null();
		this->vertices = null();
		this->m_oEB = null();
		this->m_oGeometry = null();
		this->shape = null();
		this->__setScene(null());
		::sandy::core::data::Polygon_obj::POLYGON_MAP->remove(this->id);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Polygon_obj,destroy,(void))

::sandy::core::data::Plane Polygon_obj::getPlane( Dynamic __o_centered){
bool centered = __o_centered.Default(true);
{
		__SAFE_POINT
		::sandy::core::data::Point3D center = this->a->getPoint3D();
		if (centered){
			hx::AddEq(center->x,this->b->x);
			hx::AddEq(center->y,this->b->y);
			hx::AddEq(center->z,this->b->z);
			hx::AddEq(center->x,this->c->x);
			hx::AddEq(center->y,this->c->y);
			hx::AddEq(center->z,this->c->z);
			if ((this->d != null())){
				hx::AddEq(center->x,this->d->x);
				hx::AddEq(center->y,this->d->y);
				hx::AddEq(center->z,this->d->z);
				center->scale(0.25);
			}
			else{
				center->scale((double(1) / double(3)));
			}
		}
		return ::sandy::math::PlaneMath_obj::createFromNormalAndPoint(this->__getNormal()->getPoint3D(),center);
	}
}


HX_DEFINE_DYNAMIC_FUNC1(Polygon_obj,getPlane,return )

int Polygon_obj::_ID_;

::IntHash Polygon_obj::POLYGON_MAP;


Polygon_obj::Polygon_obj()
{
}

void Polygon_obj::__Mark()
{
	hx::MarkMember(id);
	hx::MarkMember(shape);
	hx::MarkMember(isClipped);
	hx::MarkMember(cvertices);
	hx::MarkMember(vertices);
	hx::MarkMember(vertexNormals);
	hx::MarkMember(aUVCoord);
	hx::MarkMember(aEdges);
	hx::MarkMember(caUVCoord);
	hx::MarkMember(uvBounds);
	hx::MarkMember(aNeighboors);
	hx::MarkMember(visible);
	hx::MarkMember(minZ);
	hx::MarkMember(a);
	hx::MarkMember(b);
	hx::MarkMember(c);
	hx::MarkMember(d);
	hx::MarkMember(_area);
	hx::MarkMember(area);
	hx::MarkMember(changed);
	hx::MarkMember(scene);
	hx::MarkMember(m_oScene);
	hx::MarkMember(normal);
	hx::MarkMember(depth);
	hx::MarkMember(broadcaster);
	hx::MarkMember(material);
	hx::MarkMember(container);
	hx::MarkMember(enableEvents);
	hx::MarkMember(m_bWasOver);
	hx::MarkMember(enableInteractivity);
	hx::MarkMember(appearance);
	hx::MarkMember(m_oGeometry);
	hx::MarkMember(m_oAppearance);
	hx::MarkMember(m_nNormalId);
	hx::MarkMember(m_nDepth);
	hx::MarkMember(m_oContainer);
	hx::MarkMember(m_oEB);
	hx::MarkMember(mouseEvents);
	hx::MarkMember(mouseInteractivity);
}

Dynamic Polygon_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 1:
		if (!memcmp(inName.__s,L"a",sizeof(wchar_t)*1) ) { return a; }
		if (!memcmp(inName.__s,L"b",sizeof(wchar_t)*1) ) { return b; }
		if (!memcmp(inName.__s,L"c",sizeof(wchar_t)*1) ) { return c; }
		if (!memcmp(inName.__s,L"d",sizeof(wchar_t)*1) ) { return d; }
		break;
	case 2:
		if (!memcmp(inName.__s,L"id",sizeof(wchar_t)*2) ) { return id; }
		break;
	case 4:
		if (!memcmp(inName.__s,L"_ID_",sizeof(wchar_t)*4) ) { return _ID_; }
		if (!memcmp(inName.__s,L"minZ",sizeof(wchar_t)*4) ) { return minZ; }
		if (!memcmp(inName.__s,L"area",sizeof(wchar_t)*4) ) { return __getArea(); }
		if (!memcmp(inName.__s,L"clip",sizeof(wchar_t)*4) ) { return clip_dyn(); }
		break;
	case 5:
		if (!memcmp(inName.__s,L"shape",sizeof(wchar_t)*5) ) { return shape; }
		if (!memcmp(inName.__s,L"_area",sizeof(wchar_t)*5) ) { return _area; }
		if (!memcmp(inName.__s,L"scene",sizeof(wchar_t)*5) ) { return __getScene(); }
		if (!memcmp(inName.__s,L"depth",sizeof(wchar_t)*5) ) { return __getDepth(); }
		if (!memcmp(inName.__s,L"clear",sizeof(wchar_t)*5) ) { return clear_dyn(); }
		if (!memcmp(inName.__s,L"m_oEB",sizeof(wchar_t)*5) ) { return m_oEB; }
		break;
	case 6:
		if (!memcmp(inName.__s,L"aEdges",sizeof(wchar_t)*6) ) { return aEdges; }
		if (!memcmp(inName.__s,L"update",sizeof(wchar_t)*6) ) { return update_dyn(); }
		if (!memcmp(inName.__s,L"normal",sizeof(wchar_t)*6) ) { return __getNormal(); }
		break;
	case 7:
		if (!memcmp(inName.__s,L"visible",sizeof(wchar_t)*7) ) { return visible; }
		if (!memcmp(inName.__s,L"changed",sizeof(wchar_t)*7) ) { return __getChanged(); }
		if (!memcmp(inName.__s,L"display",sizeof(wchar_t)*7) ) { return display_dyn(); }
		if (!memcmp(inName.__s,L"destroy",sizeof(wchar_t)*7) ) { return destroy_dyn(); }
		break;
	case 8:
		if (!memcmp(inName.__s,L"vertices",sizeof(wchar_t)*8) ) { return vertices; }
		if (!memcmp(inName.__s,L"aUVCoord",sizeof(wchar_t)*8) ) { return aUVCoord; }
		if (!memcmp(inName.__s,L"uvBounds",sizeof(wchar_t)*8) ) { return uvBounds; }
		if (!memcmp(inName.__s,L"m_oScene",sizeof(wchar_t)*8) ) { return m_oScene; }
		if (!memcmp(inName.__s,L"__create",sizeof(wchar_t)*8) ) { return __create_dyn(); }
		if (!memcmp(inName.__s,L"material",sizeof(wchar_t)*8) ) { return __getMaterial(); }
		if (!memcmp(inName.__s,L"toString",sizeof(wchar_t)*8) ) { return toString_dyn(); }
		if (!memcmp(inName.__s,L"getPlane",sizeof(wchar_t)*8) ) { return getPlane_dyn(); }
		if (!memcmp(inName.__s,L"m_nDepth",sizeof(wchar_t)*8) ) { return m_nDepth; }
		break;
	case 9:
		if (!memcmp(inName.__s,L"isClipped",sizeof(wchar_t)*9) ) { return isClipped; }
		if (!memcmp(inName.__s,L"cvertices",sizeof(wchar_t)*9) ) { return cvertices; }
		if (!memcmp(inName.__s,L"caUVCoord",sizeof(wchar_t)*9) ) { return caUVCoord; }
		if (!memcmp(inName.__s,L"__getArea",sizeof(wchar_t)*9) ) { return __getArea_dyn(); }
		if (!memcmp(inName.__s,L"container",sizeof(wchar_t)*9) ) { return __getContainer(); }
		break;
	case 10:
		if (!memcmp(inName.__s,L"__setScene",sizeof(wchar_t)*10) ) { return __setScene_dyn(); }
		if (!memcmp(inName.__s,L"__getScene",sizeof(wchar_t)*10) ) { return __getScene_dyn(); }
		if (!memcmp(inName.__s,L"__getDepth",sizeof(wchar_t)*10) ) { return __getDepth_dyn(); }
		if (!memcmp(inName.__s,L"__setDepth",sizeof(wchar_t)*10) ) { return __setDepth_dyn(); }
		if (!memcmp(inName.__s,L"precompute",sizeof(wchar_t)*10) ) { return precompute_dyn(); }
		if (!memcmp(inName.__s,L"m_bWasOver",sizeof(wchar_t)*10) ) { return m_bWasOver; }
		if (!memcmp(inName.__s,L"appearance",sizeof(wchar_t)*10) ) { return __getAppearance(); }
		break;
	case 11:
		if (!memcmp(inName.__s,L"POLYGON_MAP",sizeof(wchar_t)*11) ) { return POLYGON_MAP; }
		if (!memcmp(inName.__s,L"aNeighboors",sizeof(wchar_t)*11) ) { return aNeighboors; }
		if (!memcmp(inName.__s,L"__getNormal",sizeof(wchar_t)*11) ) { return __getNormal_dyn(); }
		if (!memcmp(inName.__s,L"__setNormal",sizeof(wchar_t)*11) ) { return __setNormal_dyn(); }
		if (!memcmp(inName.__s,L"broadcaster",sizeof(wchar_t)*11) ) { return __getBroadcaster(); }
		if (!memcmp(inName.__s,L"get3DFrom2D",sizeof(wchar_t)*11) ) { return get3DFrom2D_dyn(); }
		if (!memcmp(inName.__s,L"getUVFrom2D",sizeof(wchar_t)*11) ) { return getUVFrom2D_dyn(); }
		if (!memcmp(inName.__s,L"swapCulling",sizeof(wchar_t)*11) ) { return swapCulling_dyn(); }
		if (!memcmp(inName.__s,L"m_oGeometry",sizeof(wchar_t)*11) ) { return m_oGeometry; }
		if (!memcmp(inName.__s,L"m_nNormalId",sizeof(wchar_t)*11) ) { return m_nNormalId; }
		if (!memcmp(inName.__s,L"mouseEvents",sizeof(wchar_t)*11) ) { return mouseEvents; }
		break;
	case 12:
		if (!memcmp(inName.__s,L"__getChanged",sizeof(wchar_t)*12) ) { return __getChanged_dyn(); }
		if (!memcmp(inName.__s,L"__setChanged",sizeof(wchar_t)*12) ) { return __setChanged_dyn(); }
		if (!memcmp(inName.__s,L"updateNormal",sizeof(wchar_t)*12) ) { return updateNormal_dyn(); }
		if (!memcmp(inName.__s,L"enableEvents",sizeof(wchar_t)*12) ) { return __getEnableEvents(); }
		if (!memcmp(inName.__s,L"createNormal",sizeof(wchar_t)*12) ) { return createNormal_dyn(); }
		if (!memcmp(inName.__s,L"m_oContainer",sizeof(wchar_t)*12) ) { return m_oContainer; }
		break;
	case 13:
		if (!memcmp(inName.__s,L"vertexNormals",sizeof(wchar_t)*13) ) { return vertexNormals; }
		if (!memcmp(inName.__s,L"__getMaterial",sizeof(wchar_t)*13) ) { return __getMaterial_dyn(); }
		if (!memcmp(inName.__s,L"__setMaterial",sizeof(wchar_t)*13) ) { return __setMaterial_dyn(); }
		if (!memcmp(inName.__s,L"m_oAppearance",sizeof(wchar_t)*13) ) { return m_oAppearance; }
		break;
	case 14:
		if (!memcmp(inName.__s,L"clipFrontPlane",sizeof(wchar_t)*14) ) { return clipFrontPlane_dyn(); }
		if (!memcmp(inName.__s,L"__getContainer",sizeof(wchar_t)*14) ) { return __getContainer_dyn(); }
		if (!memcmp(inName.__s,L"_onInteraction",sizeof(wchar_t)*14) ) { return _onInteraction_dyn(); }
		if (!memcmp(inName.__s,L"_beginMaterial",sizeof(wchar_t)*14) ) { return _beginMaterial_dyn(); }
		break;
	case 15:
		if (!memcmp(inName.__s,L"__getAppearance",sizeof(wchar_t)*15) ) { return __getAppearance_dyn(); }
		if (!memcmp(inName.__s,L"__setAppearance",sizeof(wchar_t)*15) ) { return __setAppearance_dyn(); }
		if (!memcmp(inName.__s,L"_finishMaterial",sizeof(wchar_t)*15) ) { return _finishMaterial_dyn(); }
		break;
	case 16:
		if (!memcmp(inName.__s,L"__getBroadcaster",sizeof(wchar_t)*16) ) { return __getBroadcaster_dyn(); }
		if (!memcmp(inName.__s,L"addEventListener",sizeof(wchar_t)*16) ) { return addEventListener_dyn(); }
		break;
	case 17:
		if (!memcmp(inName.__s,L"__getEnableEvents",sizeof(wchar_t)*17) ) { return __getEnableEvents_dyn(); }
		if (!memcmp(inName.__s,L"__setEnableEvents",sizeof(wchar_t)*17) ) { return __setEnableEvents_dyn(); }
		break;
	case 18:
		if (!memcmp(inName.__s,L"mouseInteractivity",sizeof(wchar_t)*18) ) { return mouseInteractivity; }
		break;
	case 19:
		if (!memcmp(inName.__s,L"removeEventListener",sizeof(wchar_t)*19) ) { return removeEventListener_dyn(); }
		if (!memcmp(inName.__s,L"enableInteractivity",sizeof(wchar_t)*19) ) { return __getEnableInteractivity(); }
		break;
	case 21:
		if (!memcmp(inName.__s,L"_stopMouseInteraction",sizeof(wchar_t)*21) ) { return _stopMouseInteraction_dyn(); }
		if (!memcmp(inName.__s,L"_onTextureInteraction",sizeof(wchar_t)*21) ) { return _onTextureInteraction_dyn(); }
		break;
	case 22:
		if (!memcmp(inName.__s,L"_startMouseInteraction",sizeof(wchar_t)*22) ) { return _startMouseInteraction_dyn(); }
		break;
	case 23:
		if (!memcmp(inName.__s,L"createTransformedNormal",sizeof(wchar_t)*23) ) { return createTransformedNormal_dyn(); }
		break;
	case 24:
		if (!memcmp(inName.__s,L"__getEnableInteractivity",sizeof(wchar_t)*24) ) { return __getEnableInteractivity_dyn(); }
		if (!memcmp(inName.__s,L"__setEnableInteractivity",sizeof(wchar_t)*24) ) { return __setEnableInteractivity_dyn(); }
	}
	return super::__Field(inName);
}

Dynamic Polygon_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	switch(inName.length) {
	case 1:
		if (!memcmp(inName.__s,L"a",sizeof(wchar_t)*1) ) { a=inValue.Cast< ::sandy::core::data::Vertex >(); return inValue; }
		if (!memcmp(inName.__s,L"b",sizeof(wchar_t)*1) ) { b=inValue.Cast< ::sandy::core::data::Vertex >(); return inValue; }
		if (!memcmp(inName.__s,L"c",sizeof(wchar_t)*1) ) { c=inValue.Cast< ::sandy::core::data::Vertex >(); return inValue; }
		if (!memcmp(inName.__s,L"d",sizeof(wchar_t)*1) ) { d=inValue.Cast< ::sandy::core::data::Vertex >(); return inValue; }
		break;
	case 2:
		if (!memcmp(inName.__s,L"id",sizeof(wchar_t)*2) ) { id=inValue.Cast< int >(); return inValue; }
		break;
	case 4:
		if (!memcmp(inName.__s,L"_ID_",sizeof(wchar_t)*4) ) { _ID_=inValue.Cast< int >(); return inValue; }
		if (!memcmp(inName.__s,L"minZ",sizeof(wchar_t)*4) ) { minZ=inValue.Cast< double >(); return inValue; }
		if (!memcmp(inName.__s,L"area",sizeof(wchar_t)*4) ) { area=inValue.Cast< double >(); return inValue; }
		break;
	case 5:
		if (!memcmp(inName.__s,L"shape",sizeof(wchar_t)*5) ) { shape=inValue.Cast< ::sandy::core::scenegraph::Shape3D >(); return inValue; }
		if (!memcmp(inName.__s,L"_area",sizeof(wchar_t)*5) ) { _area=inValue.Cast< double >(); return inValue; }
		if (!memcmp(inName.__s,L"scene",sizeof(wchar_t)*5) ) { return __setScene(inValue); }
		if (!memcmp(inName.__s,L"depth",sizeof(wchar_t)*5) ) { return __setDepth(inValue); }
		if (!memcmp(inName.__s,L"m_oEB",sizeof(wchar_t)*5) ) { m_oEB=inValue.Cast< ::sandy::events::BubbleEventBroadcaster >(); return inValue; }
		break;
	case 6:
		if (!memcmp(inName.__s,L"aEdges",sizeof(wchar_t)*6) ) { aEdges=inValue.Cast< Array< ::sandy::core::data::Edge3D > >(); return inValue; }
		if (!memcmp(inName.__s,L"normal",sizeof(wchar_t)*6) ) { return __setNormal(inValue); }
		break;
	case 7:
		if (!memcmp(inName.__s,L"visible",sizeof(wchar_t)*7) ) { visible=inValue.Cast< bool >(); return inValue; }
		if (!memcmp(inName.__s,L"changed",sizeof(wchar_t)*7) ) { return __setChanged(inValue); }
		break;
	case 8:
		if (!memcmp(inName.__s,L"vertices",sizeof(wchar_t)*8) ) { vertices=inValue.Cast< Array< ::sandy::core::data::Vertex > >(); return inValue; }
		if (!memcmp(inName.__s,L"aUVCoord",sizeof(wchar_t)*8) ) { aUVCoord=inValue.Cast< Array< ::sandy::core::data::UVCoord > >(); return inValue; }
		if (!memcmp(inName.__s,L"uvBounds",sizeof(wchar_t)*8) ) { uvBounds=inValue.Cast< ::nme::geom::Rectangle >(); return inValue; }
		if (!memcmp(inName.__s,L"m_oScene",sizeof(wchar_t)*8) ) { m_oScene=inValue.Cast< ::sandy::core::Scene3D >(); return inValue; }
		if (!memcmp(inName.__s,L"material",sizeof(wchar_t)*8) ) { return __setMaterial(inValue); }
		if (!memcmp(inName.__s,L"m_nDepth",sizeof(wchar_t)*8) ) { m_nDepth=inValue.Cast< double >(); return inValue; }
		break;
	case 9:
		if (!memcmp(inName.__s,L"isClipped",sizeof(wchar_t)*9) ) { isClipped=inValue.Cast< bool >(); return inValue; }
		if (!memcmp(inName.__s,L"cvertices",sizeof(wchar_t)*9) ) { cvertices=inValue.Cast< Array< ::sandy::core::data::Vertex > >(); return inValue; }
		if (!memcmp(inName.__s,L"caUVCoord",sizeof(wchar_t)*9) ) { caUVCoord=inValue.Cast< Array< ::sandy::core::data::UVCoord > >(); return inValue; }
		if (!memcmp(inName.__s,L"container",sizeof(wchar_t)*9) ) { container=inValue.Cast< ::neash::display::Sprite >(); return inValue; }
		break;
	case 10:
		if (!memcmp(inName.__s,L"m_bWasOver",sizeof(wchar_t)*10) ) { m_bWasOver=inValue.Cast< bool >(); return inValue; }
		if (!memcmp(inName.__s,L"appearance",sizeof(wchar_t)*10) ) { return __setAppearance(inValue); }
		break;
	case 11:
		if (!memcmp(inName.__s,L"POLYGON_MAP",sizeof(wchar_t)*11) ) { POLYGON_MAP=inValue.Cast< ::IntHash >(); return inValue; }
		if (!memcmp(inName.__s,L"aNeighboors",sizeof(wchar_t)*11) ) { aNeighboors=inValue.Cast< Array< ::sandy::core::data::Polygon > >(); return inValue; }
		if (!memcmp(inName.__s,L"broadcaster",sizeof(wchar_t)*11) ) { broadcaster=inValue.Cast< ::sandy::events::BubbleEventBroadcaster >(); return inValue; }
		if (!memcmp(inName.__s,L"m_oGeometry",sizeof(wchar_t)*11) ) { m_oGeometry=inValue.Cast< ::sandy::core::scenegraph::Geometry3D >(); return inValue; }
		if (!memcmp(inName.__s,L"m_nNormalId",sizeof(wchar_t)*11) ) { m_nNormalId=inValue.Cast< int >(); return inValue; }
		if (!memcmp(inName.__s,L"mouseEvents",sizeof(wchar_t)*11) ) { mouseEvents=inValue.Cast< bool >(); return inValue; }
		break;
	case 12:
		if (!memcmp(inName.__s,L"enableEvents",sizeof(wchar_t)*12) ) { return __setEnableEvents(inValue); }
		if (!memcmp(inName.__s,L"m_oContainer",sizeof(wchar_t)*12) ) { m_oContainer=inValue.Cast< ::neash::display::Sprite >(); return inValue; }
		break;
	case 13:
		if (!memcmp(inName.__s,L"vertexNormals",sizeof(wchar_t)*13) ) { vertexNormals=inValue.Cast< Array< ::sandy::core::data::Vertex > >(); return inValue; }
		if (!memcmp(inName.__s,L"m_oAppearance",sizeof(wchar_t)*13) ) { m_oAppearance=inValue.Cast< ::sandy::materials::Appearance >(); return inValue; }
		break;
	case 18:
		if (!memcmp(inName.__s,L"mouseInteractivity",sizeof(wchar_t)*18) ) { mouseInteractivity=inValue.Cast< bool >(); return inValue; }
		break;
	case 19:
		if (!memcmp(inName.__s,L"enableInteractivity",sizeof(wchar_t)*19) ) { return __setEnableInteractivity(inValue); }
	}
	return super::__SetField(inName,inValue);
}

void Polygon_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_STRING(L"id",2));
	outFields->push(HX_STRING(L"shape",5));
	outFields->push(HX_STRING(L"isClipped",9));
	outFields->push(HX_STRING(L"cvertices",9));
	outFields->push(HX_STRING(L"vertices",8));
	outFields->push(HX_STRING(L"vertexNormals",13));
	outFields->push(HX_STRING(L"aUVCoord",8));
	outFields->push(HX_STRING(L"aEdges",6));
	outFields->push(HX_STRING(L"caUVCoord",9));
	outFields->push(HX_STRING(L"uvBounds",8));
	outFields->push(HX_STRING(L"aNeighboors",11));
	outFields->push(HX_STRING(L"visible",7));
	outFields->push(HX_STRING(L"minZ",4));
	outFields->push(HX_STRING(L"a",1));
	outFields->push(HX_STRING(L"b",1));
	outFields->push(HX_STRING(L"c",1));
	outFields->push(HX_STRING(L"d",1));
	outFields->push(HX_STRING(L"_area",5));
	outFields->push(HX_STRING(L"area",4));
	outFields->push(HX_STRING(L"changed",7));
	outFields->push(HX_STRING(L"scene",5));
	outFields->push(HX_STRING(L"m_oScene",8));
	outFields->push(HX_STRING(L"normal",6));
	outFields->push(HX_STRING(L"depth",5));
	outFields->push(HX_STRING(L"broadcaster",11));
	outFields->push(HX_STRING(L"material",8));
	outFields->push(HX_STRING(L"container",9));
	outFields->push(HX_STRING(L"enableEvents",12));
	outFields->push(HX_STRING(L"m_bWasOver",10));
	outFields->push(HX_STRING(L"enableInteractivity",19));
	outFields->push(HX_STRING(L"appearance",10));
	outFields->push(HX_STRING(L"m_oGeometry",11));
	outFields->push(HX_STRING(L"m_oAppearance",13));
	outFields->push(HX_STRING(L"m_nNormalId",11));
	outFields->push(HX_STRING(L"m_nDepth",8));
	outFields->push(HX_STRING(L"m_oContainer",12));
	outFields->push(HX_STRING(L"m_oEB",5));
	outFields->push(HX_STRING(L"mouseEvents",11));
	outFields->push(HX_STRING(L"mouseInteractivity",18));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_STRING(L"_ID_",4),
	HX_STRING(L"POLYGON_MAP",11),
	String(null()) };

static ::String sMemberFields[] = {
	HX_STRING(L"id",2),
	HX_STRING(L"shape",5),
	HX_STRING(L"isClipped",9),
	HX_STRING(L"cvertices",9),
	HX_STRING(L"vertices",8),
	HX_STRING(L"vertexNormals",13),
	HX_STRING(L"aUVCoord",8),
	HX_STRING(L"aEdges",6),
	HX_STRING(L"caUVCoord",9),
	HX_STRING(L"uvBounds",8),
	HX_STRING(L"aNeighboors",11),
	HX_STRING(L"visible",7),
	HX_STRING(L"minZ",4),
	HX_STRING(L"a",1),
	HX_STRING(L"b",1),
	HX_STRING(L"c",1),
	HX_STRING(L"d",1),
	HX_STRING(L"_area",5),
	HX_STRING(L"area",4),
	HX_STRING(L"__getArea",9),
	HX_STRING(L"update",6),
	HX_STRING(L"changed",7),
	HX_STRING(L"__getChanged",12),
	HX_STRING(L"__setChanged",12),
	HX_STRING(L"scene",5),
	HX_STRING(L"m_oScene",8),
	HX_STRING(L"__setScene",10),
	HX_STRING(L"__getScene",10),
	HX_STRING(L"__create",8),
	HX_STRING(L"normal",6),
	HX_STRING(L"__getNormal",11),
	HX_STRING(L"__setNormal",11),
	HX_STRING(L"updateNormal",12),
	HX_STRING(L"depth",5),
	HX_STRING(L"__getDepth",10),
	HX_STRING(L"__setDepth",10),
	HX_STRING(L"broadcaster",11),
	HX_STRING(L"__getBroadcaster",16),
	HX_STRING(L"addEventListener",16),
	HX_STRING(L"removeEventListener",19),
	HX_STRING(L"precompute",10),
	HX_STRING(L"get3DFrom2D",11),
	HX_STRING(L"getUVFrom2D",11),
	HX_STRING(L"clip",4),
	HX_STRING(L"clipFrontPlane",14),
	HX_STRING(L"clear",5),
	HX_STRING(L"display",7),
	HX_STRING(L"material",8),
	HX_STRING(L"__getMaterial",13),
	HX_STRING(L"__setMaterial",13),
	HX_STRING(L"container",9),
	HX_STRING(L"__getContainer",14),
	HX_STRING(L"toString",8),
	HX_STRING(L"enableEvents",12),
	HX_STRING(L"__getEnableEvents",17),
	HX_STRING(L"__setEnableEvents",17),
	HX_STRING(L"m_bWasOver",10),
	HX_STRING(L"_onInteraction",14),
	HX_STRING(L"_startMouseInteraction",22),
	HX_STRING(L"_stopMouseInteraction",21),
	HX_STRING(L"enableInteractivity",19),
	HX_STRING(L"__getEnableInteractivity",24),
	HX_STRING(L"__setEnableInteractivity",24),
	HX_STRING(L"_onTextureInteraction",21),
	HX_STRING(L"createTransformedNormal",23),
	HX_STRING(L"createNormal",12),
	HX_STRING(L"appearance",10),
	HX_STRING(L"__getAppearance",15),
	HX_STRING(L"__setAppearance",15),
	HX_STRING(L"_finishMaterial",15),
	HX_STRING(L"_beginMaterial",14),
	HX_STRING(L"swapCulling",11),
	HX_STRING(L"destroy",7),
	HX_STRING(L"getPlane",8),
	HX_STRING(L"m_oGeometry",11),
	HX_STRING(L"m_oAppearance",13),
	HX_STRING(L"m_nNormalId",11),
	HX_STRING(L"m_nDepth",8),
	HX_STRING(L"m_oContainer",12),
	HX_STRING(L"m_oEB",5),
	HX_STRING(L"mouseEvents",11),
	HX_STRING(L"mouseInteractivity",18),
	String(null()) };

static void sMarkStatics() {
	hx::MarkMember(Polygon_obj::_ID_);
	hx::MarkMember(Polygon_obj::POLYGON_MAP);
};

Class Polygon_obj::__mClass;

void Polygon_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_STRING(L"sandy.core.data.Polygon",23), hx::TCanCast< Polygon_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void Polygon_obj::__boot()
{
	hx::Static(_ID_) = 0;
	hx::Static(POLYGON_MAP) = ::IntHash_obj::__new();
}

} // end namespace sandy
} // end namespace core
} // end namespace data
