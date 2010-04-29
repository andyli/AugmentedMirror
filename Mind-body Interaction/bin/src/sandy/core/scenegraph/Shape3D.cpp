#include <hxcpp.h>

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
#ifndef INCLUDED_neash_events_MouseEvent
#include <neash/events/MouseEvent.h>
#endif
#ifndef INCLUDED_nme_display_Graphics
#include <nme/display/Graphics.h>
#endif
#ifndef INCLUDED_nme_display_IBitmapDrawable
#include <nme/display/IBitmapDrawable.h>
#endif
#ifndef INCLUDED_nme_geom_Point
#include <nme/geom/Point.h>
#endif
#ifndef INCLUDED_sandy_bounds_BBox
#include <sandy/bounds/BBox.h>
#endif
#ifndef INCLUDED_sandy_bounds_BSphere
#include <sandy/bounds/BSphere.h>
#endif
#ifndef INCLUDED_sandy_core_Renderer
#include <sandy/core/Renderer.h>
#endif
#ifndef INCLUDED_sandy_core_Scene3D
#include <sandy/core/Scene3D.h>
#endif
#ifndef INCLUDED_sandy_core_data_BSPNode
#include <sandy/core/data/BSPNode.h>
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
#ifndef INCLUDED_sandy_core_scenegraph_ATransformable
#include <sandy/core/scenegraph/ATransformable.h>
#endif
#ifndef INCLUDED_sandy_core_scenegraph_Camera3D
#include <sandy/core/scenegraph/Camera3D.h>
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
#ifndef INCLUDED_sandy_events_Shape3DEvent
#include <sandy/events/Shape3DEvent.h>
#endif
#ifndef INCLUDED_sandy_materials_Appearance
#include <sandy/materials/Appearance.h>
#endif
#ifndef INCLUDED_sandy_materials_Material
#include <sandy/materials/Material.h>
#endif
#ifndef INCLUDED_sandy_materials_WireFrameMaterial
#include <sandy/materials/WireFrameMaterial.h>
#endif
#ifndef INCLUDED_sandy_materials_attributes_MaterialAttributes
#include <sandy/materials/attributes/MaterialAttributes.h>
#endif
#ifndef INCLUDED_sandy_math_IntersectionMath
#include <sandy/math/IntersectionMath.h>
#endif
#ifndef INCLUDED_sandy_util_ArrayUtil
#include <sandy/util/ArrayUtil.h>
#endif
#ifndef INCLUDED_sandy_view_Frustum
#include <sandy/view/Frustum.h>
#endif
namespace sandy{
namespace core{
namespace scenegraph{

Void Shape3D_obj::__construct(Dynamic __o_p_sName,::sandy::core::scenegraph::Geometry3D p_oGeometry,::sandy::materials::Appearance p_oAppearance,Dynamic __o_p_bUseSingleContainer)
{
::String p_sName = __o_p_sName.Default(HX_STRING(L"",0));
bool p_bUseSingleContainer = __o_p_bUseSingleContainer.Default(true);
{
	this->aPolygons = Array_obj< ::sandy::core::data::Polygon >::__new();
	this->enableNearClipping = false;
	this->__setEnableClipping(false);
	this->enableForcedDepth = false;
	this->forcedDepth = 0;
	this->animated = false;
	this->aVisiblePolygons = Array_obj< ::sandy::core::data::Polygon >::__new();
	this->m_bEv = false;
	this->m_oGeomCenter = ::sandy::core::data::Point3D_obj::__new(null(),null(),null());
	this->m_bBackFaceCulling = true;
	this->m_bWasOver = false;
	this->m_bUseSingleContainer = true;
	this->m_nDepth = 0;
	this->m_bMouseInteractivity = false;
	this->m_bForcedSingleContainer = false;
	this->m_nSortingMode = 1;
	super::__construct(p_sName);
	this->m_oContainer = ::neash::display::Sprite_obj::__new();
	this->m_oContainer->name = this->name;
	this->__setGeometry(p_oGeometry);
	this->m_bUseSingleContainer = !p_bUseSingleContainer;
	this->__setUseSingleContainer(p_bUseSingleContainer);
	this->__setAppearance(((p_oAppearance != null())) ? ::sandy::materials::Appearance( p_oAppearance ) : ::sandy::materials::Appearance( ::sandy::materials::Appearance_obj::__new(::sandy::materials::WireFrameMaterial_obj::__new(null(),null(),null(),null()),null()) ));
	this->updateBoundingVolumes();
}
;
	return null();
}

Shape3D_obj::~Shape3D_obj() { }

Dynamic Shape3D_obj::__CreateEmpty() { return  new Shape3D_obj; }
hx::ObjectPtr< Shape3D_obj > Shape3D_obj::__new(Dynamic __o_p_sName,::sandy::core::scenegraph::Geometry3D p_oGeometry,::sandy::materials::Appearance p_oAppearance,Dynamic __o_p_bUseSingleContainer)
{  hx::ObjectPtr< Shape3D_obj > result = new Shape3D_obj();
	result->__construct(__o_p_sName,p_oGeometry,p_oAppearance,__o_p_bUseSingleContainer);
	return result;}

Dynamic Shape3D_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Shape3D_obj > result = new Shape3D_obj();
	result->__construct(inArgs[0],inArgs[1],inArgs[2],inArgs[3]);
	return result;}

hx::Object *Shape3D_obj::__ToInterface(const type_info &inType) {
	if (inType==typeid( ::sandy::core::scenegraph::IDisplayable_obj)) return operator ::sandy::core::scenegraph::IDisplayable_obj *();
	return super::__ToInterface(inType);
}

Void Shape3D_obj::clear( ){
{
		__SAFE_POINT
		if ((this->m_oContainer != null()))
			this->m_oContainer->GetGraphics()->clear();
		this->__setChanged(true);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Shape3D_obj,clear,(void))

::sandy::core::scenegraph::Shape3D Shape3D_obj::clone( Dynamic __o_p_sName,Dynamic __o_p_bKeepTransform){
::String p_sName = __o_p_sName.Default(HX_STRING(L"",0));
bool p_bKeepTransform = __o_p_bKeepTransform.Default(false);
{
		__SAFE_POINT
		::sandy::core::scenegraph::Shape3D o = ::sandy::core::scenegraph::Shape3D_obj::__new(p_sName,null(),this->__getAppearance(),this->m_bUseSingleContainer);
		o->copy(this,p_bKeepTransform,null());
		return o;
	}
}


HX_DEFINE_DYNAMIC_FUNC2(Shape3D_obj,clone,return )

Void Shape3D_obj::cull( ::sandy::view::Frustum p_oFrustum,::sandy::core::data::Matrix4 p_oViewMatrix,bool p_bChanged){
{
		__SAFE_POINT
		this->super::cull(p_oFrustum,p_oViewMatrix,p_bChanged);
		if ((this->culled == 2))
			return null();
		this->boundingSphere->transform(this->viewMatrix);
		this->culled = p_oFrustum->sphereInFrustum(this->boundingSphere);
		if ((this->culled == 0)){
			this->culled = p_oFrustum->boxInFrustum(this->boundingBox->transform(this->viewMatrix));
		}
		if ((bool((this->culled != 2)) && bool((this->m_oAppearance != null())))){
			this->__getScene()->renderer->addToDisplayList(this);
		}
		if ((bool(this->m_bEv) || bool(this->m_bMouseInteractivity))){
			if ((bool((this->m_bWasOver == true)) && bool((this->m_oLastContainer->hitTestPoint(this->m_oLastContainer->GetMouseX(),this->m_oLastContainer->GetMouseY(),null()) == false)))){
				this->m_oEB->dispatchEvent(::sandy::events::Shape3DEvent_obj::__new(::neash::events::MouseEvent_obj::MOUSE_OUT,this,this->m_oLastEvent->polygon,this->m_oLastEvent->uv,this->m_oLastEvent->point,this->m_oLastEvent->event));
				this->m_bWasOver = false;
				if ((this->m_oLastContainer != this->m_oContainer)){
					this->m_oLastEvent->polygon->_onTextureInteraction(this->m_oLastEvent->event);
					this->m_oLastEvent->polygon->_stopMouseInteraction(null());
				}
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC3(Shape3D_obj,cull,(void))

Void Shape3D_obj::display( ::neash::display::Sprite p_oContainer){
{
		__SAFE_POINT
		if ((this->m_nSortingMode < 2)){
			if ((bool(((this->m_nSortingMode == 1))) || bool(((this->m_bBackFaceCulling == false))))){
				{
					Array< ::sandy::core::data::Polygon > inArray = this->aVisiblePolygons;
					Array< ::String > fieldNames = Array_obj< ::String >::__new().Add(HX_STRING(L"m_nDepth",8));
					int options = 18;
					Array< ::sandy::core::data::Polygon > result = Array_obj< ::sandy::core::data::Polygon >::__new();
					if ((inArray->length != 0)){
						bool oNumeric = ((int((int(options) >> int(4))) & int(1)) == 1);
						bool oUniquesort = ((int((int(options) >> int(2))) & int(1)) == 1);
						bool oDescending = ((int((int(options) >> int(1))) & int(1)) == 1);
						bool oCaseinsensitive = ((int(options) & int(1)) == 1);
						bool hasDup = false;
						if (oUniquesort){
							Array< Array< Dynamic > > testCase = Array_obj< Array< Dynamic > >::__new();
							{
								int _g1 = 0;
								int _g2 = inArray->length;
								while((_g1 < _g2)){
									__SAFE_POINT
									int i = _g1++;
									testCase[i] = Array_obj< Dynamic >::__new();
									{
										int _g21 = 0;
										while((_g21 < fieldNames->length)){
											__SAFE_POINT
											::String f = fieldNames->__get(_g21);
											++_g21;
											struct _Function_10_1{
												inline static Dynamic Block( Array< ::sandy::core::data::Polygon > &inArray,int &i,::String &f)/* DEF (ret block)(not intern) */{
													Dynamic o = inArray->__get(i);
													return ((o == null())) ? Dynamic( null() ) : Dynamic( o->__Field(f) );
												}
											};
											Dynamic fi = _Function_10_1::Block(inArray,i,f);
											bool isString = !((bool(::Std_obj::is(fi,hx::ClassOf< ::Float >())) || bool(::Std_obj::is(fi,hx::ClassOf< ::Int >()))));
											Dynamic ele;
											if ((bool(oCaseinsensitive) && bool(isString))){
												ele = ::Std_obj::string(fi).toLowerCase();
											}
											else{
												ele = inArray->__get(i);
											}
											testCase[i]->push(ele);
										}
									}
								}
							}
							struct _Function_6_1{
								inline static Array< Array< Dynamic > > Block( Array< Array< Dynamic > > &testCase)/* DEF (ret block)(not intern) */{
									Dynamic _g1 = hx::ClassOf< ::sandy::util::ArrayUtil >();
									int i = 0;
									Array< Array< Dynamic > > cp = testCase->copy();
									Array< Array< Dynamic > > outArray = testCase->copy();
									{
										int _g11 = 0;
										while((_g11 < cp->length)){
											__SAFE_POINT
											Array< Dynamic > i1 = cp->__get(_g11);
											++_g11;
											{
												int _g2 = 1;
												int _g111 = ::sandy::util::ArrayUtil_obj::contains2(outArray,i1);
												while((_g2 < _g111)){
													__SAFE_POINT
													int j = _g2++;
													outArray->remove(i1);
												}
											}
										}
									}
									return outArray;
								}
							};
							Array< Array< Dynamic > > removedDup = _Function_6_1::Block(testCase);
							if ((removedDup->length != testCase->length))
								hasDup = true;
						}
						if (!hasDup){
							inArray->sort(::sandy::util::ArrayUtil_obj::getSortingFunction(oNumeric,false,oUniquesort,oDescending,oCaseinsensitive,fieldNames));
							result = inArray;
						}
					}
					result;
				}
			}
			{
				int _g = 0;
				Array< ::sandy::core::data::Polygon > _g1 = this->aVisiblePolygons;
				while((_g < _g1->length)){
					__SAFE_POINT
					::sandy::core::data::Polygon l_oFace = _g1->__get(_g);
					++_g;
					l_oFace->display(this->m_oContainer);
				}
			}
		}
		else{
			::sandy::core::data::Point3D camPt = ::sandy::core::data::Point3D_obj::__new(this->__getScene()->camera->modelMatrix->n14,this->__getScene()->camera->modelMatrix->n24,this->__getScene()->camera->modelMatrix->n34);
			this->invModelMatrix->transform(camPt);
			this->displayBSPTree(this->bsp,camPt);
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Shape3D_obj,display,(void))

Void Shape3D_obj::displayBSPTree( ::sandy::core::data::BSPNode tree,::sandy::core::data::Point3D camPt){
{
		__SAFE_POINT
		::sandy::core::data::Polygon face;
		double dist = ((((((tree->plane->a * camPt->x) + (tree->plane->b * camPt->y))) + (tree->plane->c * camPt->z))) + tree->plane->d);
		if ((dist > 0)){
			if ((tree->negative != null()))
				this->displayBSPTree(tree->negative,camPt);
			{
				int _g = 0;
				Array< ::sandy::core::data::Polygon > _g1 = tree->faces;
				while((_g < _g1->length)){
					__SAFE_POINT
					::sandy::core::data::Polygon face1 = _g1->__get(_g);
					++_g;
					if (face1->visible)
						face1->display(this->m_oContainer);
				}
			}
			if ((tree->positive != null()))
				this->displayBSPTree(tree->positive,camPt);
		}
		else{
			if ((tree->positive != null()))
				this->displayBSPTree(tree->positive,camPt);
			{
				int _g = 0;
				Array< ::sandy::core::data::Polygon > _g1 = tree->faces;
				while((_g < _g1->length)){
					__SAFE_POINT
					::sandy::core::data::Polygon face1 = _g1->__get(_g);
					++_g;
					if (face1->visible)
						face1->display(this->m_oContainer);
				}
			}
			if ((tree->negative != null()))
				this->displayBSPTree(tree->negative,camPt);
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(Shape3D_obj,displayBSPTree,(void))

Void Shape3D_obj::destroy( ){
{
		__SAFE_POINT
		if ((this->m_oGeometry != null()))
			this->m_oGeometry->dispose();
		if ((this->m_oAppearance != null()))
			this->m_oAppearance->dispose();
		this->clear();
		if ((this->m_oContainer != null())){
			if ((this->m_oContainer->GetParent() != null()))
				this->m_oContainer->GetParent()->removeChild(this->m_oContainer);
			this->m_oContainer = null();
		}
		this->__destroyPolygons();
		this->m_oGeometry = null();
		this->aVisiblePolygons = null();
		this->aPolygons = null();
		this->boundingBox = null();
		this->boundingSphere = null();
		this->super::destroy();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Shape3D_obj,destroy,(void))

Void Shape3D_obj::setConvexFlag( bool convex){
{
		__SAFE_POINT
		{
			int mode = convex ? int( 0 ) : int( 1 );
			if (this->m_bUseSingleContainer){
				if ((mode == 2)){
					this->bsp = ::sandy::core::data::BSPNode_obj::makeLazyBSP(this->aPolygons,(0.01 * this->boundingSphere->radius));
				}
				this->m_nSortingMode = mode;
				this->__setChanged(true);
			}
			mode;
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Shape3D_obj,setConvexFlag,(void))

Void Shape3D_obj::swapCulling( ){
{
		__SAFE_POINT
		{
			int _g = 0;
			Array< ::sandy::core::data::Polygon > _g1 = this->aPolygons;
			while((_g < _g1->length)){
				__SAFE_POINT
				::sandy::core::data::Polygon v = _g1->__get(_g);
				++_g;
				v->swapCulling();
			}
		}
		this->__setChanged(true);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Shape3D_obj,swapCulling,(void))

::String Shape3D_obj::toString( ){
	__SAFE_POINT
	return (((HX_STRING(L"sandy.core.scenegraph.Shape3D",29) + HX_STRING(L" ",1))) + this->m_oGeometry->toString());
}


HX_DEFINE_DYNAMIC_FUNC0(Shape3D_obj,toString,return )

Void Shape3D_obj::updateBoundingVolumes( ){
{
		__SAFE_POINT
		if ((this->m_oGeometry != null())){
			this->boundingBox = ::sandy::bounds::BBox_obj::create(this->m_oGeometry->aVertex);
			this->boundingSphere->resetFromBox(this->boundingBox);
			if ((this->__getParent() != null()))
				this->__getParent()->onChildBoundsChanged(this);
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Shape3D_obj,updateBoundingVolumes,(void))

::sandy::materials::Appearance Shape3D_obj::__getAppearance( ){
	return this->m_oAppearance;
}


HX_DEFINE_DYNAMIC_FUNC0(Shape3D_obj,__getAppearance,return )

::sandy::materials::Appearance Shape3D_obj::__setAppearance( ::sandy::materials::Appearance p_oApp){
	__SAFE_POINT
	this->m_oAppearance = p_oApp;
	if ((this->m_oGeometry != null())){
		{
			int _g = 0;
			Array< ::sandy::core::data::Polygon > _g1 = this->aPolygons;
			while((_g < _g1->length)){
				__SAFE_POINT
				::sandy::core::data::Polygon v = _g1->__get(_g);
				++_g;
				v->__setAppearance(this->m_oAppearance);
			}
		}
	}
	this->__setChanged(true);
	return p_oApp;
}


HX_DEFINE_DYNAMIC_FUNC1(Shape3D_obj,__setAppearance,return )

::neash::display::Sprite Shape3D_obj::__getContainer( ){
	return this->m_oContainer;
}


HX_DEFINE_DYNAMIC_FUNC0(Shape3D_obj,__getContainer,return )

double Shape3D_obj::__getDepth( ){
	return this->m_nDepth;
}


HX_DEFINE_DYNAMIC_FUNC0(Shape3D_obj,__getDepth,return )

double Shape3D_obj::__setDepth( double p_nDepth){
	__SAFE_POINT
	this->m_nDepth = p_nDepth;
	this->__setChanged(true);
	return p_nDepth;
}


HX_DEFINE_DYNAMIC_FUNC1(Shape3D_obj,__setDepth,return )

bool Shape3D_obj::__getEnableBackFaceCulling( ){
	return this->m_bBackFaceCulling;
}


HX_DEFINE_DYNAMIC_FUNC0(Shape3D_obj,__getEnableBackFaceCulling,return )

bool Shape3D_obj::__setEnableBackFaceCulling( bool b){
	__SAFE_POINT
	if ((b != this->m_bBackFaceCulling)){
		this->m_bBackFaceCulling = b;
		this->__setChanged(true);
	}
	return b;
}


HX_DEFINE_DYNAMIC_FUNC1(Shape3D_obj,__setEnableBackFaceCulling,return )

bool Shape3D_obj::__getEnableClipping( ){
	return this->m_bClipping;
}


HX_DEFINE_DYNAMIC_FUNC0(Shape3D_obj,__getEnableClipping,return )

bool Shape3D_obj::__setEnableClipping( bool p_bClippingValue){
	this->m_bClipping = p_bClippingValue;
	return p_bClippingValue;
}


HX_DEFINE_DYNAMIC_FUNC1(Shape3D_obj,__setEnableClipping,return )

bool Shape3D_obj::__getEnableEvents( ){
	return this->m_bEv;
}


HX_DEFINE_DYNAMIC_FUNC0(Shape3D_obj,__getEnableEvents,return )

bool Shape3D_obj::__setEnableEvents( bool b){
	__SAFE_POINT
	if ((b == this->m_bEv))
		return b;
	if (b){
		this->subscribeEvents();
	}
	else{
		this->unsubscribeEvents();
	}
	this->m_bEv = b;
	return b;
}


HX_DEFINE_DYNAMIC_FUNC1(Shape3D_obj,__setEnableEvents,return )

bool Shape3D_obj::__getEnableInteractivity( ){
	return this->m_bMouseInteractivity;
}


HX_DEFINE_DYNAMIC_FUNC0(Shape3D_obj,__getEnableInteractivity,return )

bool Shape3D_obj::__setEnableInteractivity( bool p_bState){
	__SAFE_POINT
	if ((p_bState != this->m_bMouseInteractivity)){
		this->__setChanged(true);
		if (p_bState){
			if ((this->m_bUseSingleContainer == true)){
				this->__setUseSingleContainer(false);
				this->m_bForcedSingleContainer = true;
			}
		}
		else{
			if ((this->m_bForcedSingleContainer == true)){
				this->__setUseSingleContainer(true);
				this->m_bForcedSingleContainer = false;
			}
		}
		{
			int _g = 0;
			Array< ::sandy::core::data::Polygon > _g1 = this->aPolygons;
			while((_g < _g1->length)){
				__SAFE_POINT
				::sandy::core::data::Polygon l_oPolygon = _g1->__get(_g);
				++_g;
				l_oPolygon->__setEnableInteractivity(p_bState);
			}
		}
		this->m_bMouseInteractivity = p_bState;
	}
	return p_bState;
}


HX_DEFINE_DYNAMIC_FUNC1(Shape3D_obj,__setEnableInteractivity,return )

::sandy::core::scenegraph::Geometry3D Shape3D_obj::__getGeometry( ){
	return this->m_oGeometry;
}


HX_DEFINE_DYNAMIC_FUNC0(Shape3D_obj,__getGeometry,return )

::sandy::core::scenegraph::Geometry3D Shape3D_obj::__setGeometry( ::sandy::core::scenegraph::Geometry3D p_geometry){
	__SAFE_POINT
	if ((p_geometry == null()))
		return null();
	this->m_oGeometry = p_geometry;
	this->updateBoundingVolumes();
	this->m_oGeometry->generateFaceNormals();
	this->m_oGeometry->generateVertexNormals();
	this->__destroyPolygons();
	this->__generatePolygons(this->m_oGeometry);
	this->__setChanged(true);
	return p_geometry;
}


HX_DEFINE_DYNAMIC_FUNC1(Shape3D_obj,__setGeometry,return )

::sandy::core::data::Point3D Shape3D_obj::__getGeometryCenter( ){
	return this->m_oGeomCenter;
}


HX_DEFINE_DYNAMIC_FUNC0(Shape3D_obj,__getGeometryCenter,return )

::sandy::core::data::Point3D Shape3D_obj::__setGeometryCenter( ::sandy::core::data::Point3D p_oGeomCenter){
	__SAFE_POINT
	::sandy::core::data::Point3D l_oDiff = p_oGeomCenter->clone();
	l_oDiff->sub(this->m_oGeomCenter);
	if ((this->m_oGeometry != null())){
		{
			int _g = 0;
			Array< ::sandy::core::data::Vertex > _g1 = this->m_oGeometry->aVertex;
			while((_g < _g1->length)){
				__SAFE_POINT
				::sandy::core::data::Vertex l_oVertex = _g1->__get(_g);
				++_g;
				hx::AddEq(l_oVertex->x,l_oDiff->x);
				hx::AddEq(l_oVertex->y,l_oDiff->y);
				hx::AddEq(l_oVertex->z,l_oDiff->z);
			}
		}
	}
	this->m_oGeomCenter->copy(p_oGeomCenter);
	this->updateBoundingVolumes();
	this->__setChanged(true);
	return p_oGeomCenter;
}


HX_DEFINE_DYNAMIC_FUNC1(Shape3D_obj,__setGeometryCenter,return )

::sandy::materials::Material Shape3D_obj::__getMaterial( ){
	__SAFE_POINT
	return (this->aPolygons[0]->visible) ? ::sandy::materials::Material( this->m_oAppearance->__getFrontMaterial() ) : ::sandy::materials::Material( this->m_oAppearance->__getBackMaterial() );
}


HX_DEFINE_DYNAMIC_FUNC0(Shape3D_obj,__getMaterial,return )

::sandy::materials::Material Shape3D_obj::__setMaterial( ::sandy::materials::Material v){
	return hx::Throw (HX_STRING(L"not implemented",15));
}


HX_DEFINE_DYNAMIC_FUNC1(Shape3D_obj,__setMaterial,return )

::sandy::core::Scene3D Shape3D_obj::__setScene( ::sandy::core::Scene3D p_oScene){
	__SAFE_POINT
	this->super::__setScene(p_oScene);
	if ((this->aPolygons != null())){
		{
			int _g = 0;
			Array< ::sandy::core::data::Polygon > _g1 = this->aPolygons;
			while((_g < _g1->length)){
				__SAFE_POINT
				::sandy::core::data::Polygon l_oPoly = _g1->__get(_g);
				++_g;
				l_oPoly->__setScene(null());
				l_oPoly->__setScene(p_oScene);
			}
		}
	}
	return p_oScene;
}


HX_DEFINE_DYNAMIC_FUNC1(Shape3D_obj,__setScene,return )

bool Shape3D_obj::__getUseSingleContainer( ){
	return this->m_bUseSingleContainer;
}


HX_DEFINE_DYNAMIC_FUNC0(Shape3D_obj,__getUseSingleContainer,return )

bool Shape3D_obj::__setUseSingleContainer( bool p_bUseSingleContainer){
	__SAFE_POINT
	::sandy::core::data::Polygon l_oFace;
	if ((p_bUseSingleContainer == this->m_bUseSingleContainer))
		return p_bUseSingleContainer;
	bool useEvents = this->__getEnableEvents();
	this->unsubscribeEvents();
	if (p_bUseSingleContainer){
		{
			int _g = 0;
			Array< ::sandy::core::data::Polygon > _g1 = this->aPolygons;
			while((_g < _g1->length)){
				__SAFE_POINT
				::sandy::core::data::Polygon l_oFace1 = _g1->__get(_g);
				++_g;
				if ((l_oFace1->__getContainer()->GetParent() != null())){
					l_oFace1->__getContainer()->GetGraphics()->clear();
					l_oFace1->__getContainer()->GetParent()->removeChild(l_oFace1->__getContainer());
					this->__getBroadcaster()->removeChild(l_oFace1->__getBroadcaster());
				}
			}
		}
	}
	else{
		if ((this->m_oContainer->GetParent() != null())){
			this->m_oContainer->GetGraphics()->clear();
			this->m_oContainer->GetParent()->removeChild(this->m_oContainer);
		}
		{
			int _g = 0;
			Array< ::sandy::core::data::Polygon > _g1 = this->aPolygons;
			while((_g < _g1->length)){
				__SAFE_POINT
				::sandy::core::data::Polygon l_oFace1 = _g1->__get(_g);
				++_g;
				this->__getBroadcaster()->addChild(l_oFace1->__getBroadcaster());
				l_oFace1->__getContainer()->GetGraphics()->clear();
			}
		}
	}
	this->m_bUseSingleContainer = p_bUseSingleContainer;
	if (useEvents)
		this->subscribeEvents();
	this->__setChanged(true);
	return p_bUseSingleContainer;
}


HX_DEFINE_DYNAMIC_FUNC1(Shape3D_obj,__setUseSingleContainer,return )

int Shape3D_obj::__getSortingMode( ){
	return this->m_bUseSingleContainer ? int( this->m_nSortingMode ) : int( 1 );
}


HX_DEFINE_DYNAMIC_FUNC0(Shape3D_obj,__getSortingMode,return )

int Shape3D_obj::__setSortingMode( int mode){
	__SAFE_POINT
	if (this->m_bUseSingleContainer){
		if ((mode == 2)){
			this->bsp = ::sandy::core::data::BSPNode_obj::makeLazyBSP(this->aPolygons,(0.01 * this->boundingSphere->radius));
		}
		this->m_nSortingMode = mode;
		this->__setChanged(true);
	}
	return mode;
}


HX_DEFINE_DYNAMIC_FUNC1(Shape3D_obj,__setSortingMode,return )

Void Shape3D_obj::copy( ::sandy::core::scenegraph::Node src,Dynamic __o_includeTransforms,Dynamic __o_includeGeometry){
bool includeTransforms = __o_includeTransforms.Default(false);
bool includeGeometry = __o_includeGeometry.Default(true);
{
		__SAFE_POINT
		if (!::Std_obj::is(src,hx::ClassOf< ::sandy::core::scenegraph::Shape3D >()))
			hx::Throw (HX_STRING(L"Invalid src",11));
		::sandy::core::scenegraph::Shape3D o = src;
		bool finalEvents = o->__getEnableEvents();
		this->super::copy(src,includeTransforms,null());
		if (includeGeometry)
			this->__setGeometry(o->__getGeometry()->clone());
		this->animated = o->animated;
		this->enableForcedDepth = o->enableForcedDepth;
		this->enableNearClipping = o->enableNearClipping;
		this->forcedDepth = o->forcedDepth;
		this->__setAppearance(o->m_oAppearance);
		this->__setGeometryCenter(o->m_oGeomCenter->clone());
		this->m_bWasOver = false;
		this->m_oLastEvent = null();
		this->m_oLastContainer = null();
		this->m_nDepth = o->m_nDepth;
		this->unsubscribeEvents();
		if (finalEvents)
			this->subscribeEvents();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC3(Shape3D_obj,copy,(void))

Void Shape3D_obj::__destroyPolygons( ){
{
		__SAFE_POINT
		if ((bool((this->aPolygons != null())) && bool((this->aPolygons->length > 0)))){
			int i = 0;
			int l = this->aPolygons->length;
			while((i < l)){
				__SAFE_POINT
				if ((this->__getBroadcaster() != null()))
					this->__getBroadcaster()->removeChild(this->aPolygons[i]->__getBroadcaster());
				if ((this->aPolygons->__get(i) != null()))
					this->aPolygons[i]->destroy();
				this->aPolygons[i] = null();
				i++;
			}
		}
		this->aPolygons->splice(0,this->aPolygons->length);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Shape3D_obj,__destroyPolygons,(void))

Void Shape3D_obj::__generatePolygons( ::sandy::core::scenegraph::Geometry3D p_oGeometry){
{
		__SAFE_POINT
		int i = 0;
		int j = 0;
		int l = p_oGeometry->aFacesVertexID->length;
		this->aPolygons = Array_obj< ::sandy::core::data::Polygon >::__new();
		{
			int _g = 0;
			while((_g < l)){
				__SAFE_POINT
				int i1 = _g++;
				this->aPolygons[i1] = ::sandy::core::data::Polygon_obj::__new(this,p_oGeometry,p_oGeometry->aFacesVertexID->__get(i1),p_oGeometry->aFacesUVCoordsID->__get(i1),i1,i1);
				if ((this->m_oAppearance != null()))
					this->aPolygons[i1]->__setAppearance(this->m_oAppearance);
				this->__getBroadcaster()->addChild(this->aPolygons[i1]->__getBroadcaster());
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Shape3D_obj,__generatePolygons,(void))

Void Shape3D_obj::_onInteraction( ::neash::events::Event p_oEvt){
{
		__SAFE_POINT
		::nme::geom::Point l_oClick = ::nme::geom::Point_obj::__new(this->m_oContainer->GetMouseX(),this->m_oContainer->GetMouseY());
		::nme::geom::Point l_oA = ::nme::geom::Point_obj::__new(null(),null());
		::nme::geom::Point l_oB = ::nme::geom::Point_obj::__new(null(),null());
		::nme::geom::Point l_oC = ::nme::geom::Point_obj::__new(null(),null());
		::sandy::core::data::Polygon l_oPoly;
		struct _Function_1_1{
			inline static Array< int > Block( ::sandy::core::scenegraph::Shape3D_obj *__this)/* DEF (ret block)(not intern) */{
				Dynamic _g = hx::ClassOf< ::sandy::util::ArrayUtil >();
				Array< Dynamic > inArray = __this->aPolygons;
				Array< ::String > fieldNames = Array_obj< ::String >::__new().Add(HX_STRING(L"m_nDepth",8));
				Array< int > result = Array_obj< int >::__new();
				struct _Function_2_1{
					inline static Array< Dynamic > Block( Array< Dynamic > &inArray,Array< ::String > &fieldNames)/* DEF (ret block)(not intern) */{
						Array< Dynamic > inArray1 = inArray->copy();
						Array< Dynamic > result1 = Array_obj< Dynamic >::__new();
						if ((inArray1->length != 0)){
							bool oNumeric = true;
							bool oUniquesort = false;
							bool oDescending = false;
							bool oCaseinsensitive = false;
							bool hasDup = false;
							if (oUniquesort){
								Array< Array< Dynamic > > testCase = Array_obj< Array< Dynamic > >::__new();
								{
									int _g1 = 0;
									int _g2 = inArray1->length;
									while((_g1 < _g2)){
										__SAFE_POINT
										int i = _g1++;
										testCase[i] = Array_obj< Dynamic >::__new();
										{
											int _g21 = 0;
											while((_g21 < fieldNames->length)){
												__SAFE_POINT
												::String f = fieldNames->__get(_g21);
												++_g21;
												struct _Function_9_1{
													inline static Dynamic Block( Array< Dynamic > &inArray1,int &i,::String &f)/* DEF (ret block)(not intern) */{
														Dynamic o = inArray1->__get(i);
														return ((o == null())) ? Dynamic( null() ) : Dynamic( o->__Field(f) );
													}
												};
												Dynamic fi = _Function_9_1::Block(inArray1,i,f);
												bool isString = !((bool(::Std_obj::is(fi,hx::ClassOf< ::Float >())) || bool(::Std_obj::is(fi,hx::ClassOf< ::Int >()))));
												Dynamic ele;
												if ((bool(oCaseinsensitive) && bool(isString))){
													ele = ::Std_obj::string(fi).toLowerCase();
												}
												else{
													ele = inArray1->__get(i);
												}
												testCase[i]->push(ele);
											}
										}
									}
								}
								struct _Function_5_1{
									inline static Array< Array< Dynamic > > Block( Array< Array< Dynamic > > &testCase)/* DEF (ret block)(not intern) */{
										Dynamic _g1 = hx::ClassOf< ::sandy::util::ArrayUtil >();
										int i = 0;
										Array< Array< Dynamic > > cp = testCase->copy();
										Array< Array< Dynamic > > outArray = testCase->copy();
										{
											int _g11 = 0;
											while((_g11 < cp->length)){
												__SAFE_POINT
												Array< Dynamic > i1 = cp->__get(_g11);
												++_g11;
												{
													int _g2 = 1;
													int _g111 = ::sandy::util::ArrayUtil_obj::contains2(outArray,i1);
													while((_g2 < _g111)){
														__SAFE_POINT
														int j = _g2++;
														outArray->remove(i1);
													}
												}
											}
										}
										return outArray;
									}
								};
								Array< Array< Dynamic > > removedDup = _Function_5_1::Block(testCase);
								if ((removedDup->length != testCase->length))
									hasDup = true;
							}
							if (!hasDup){
								inArray1->sort(::sandy::util::ArrayUtil_obj::getSortingFunction(oNumeric,false,oUniquesort,oDescending,oCaseinsensitive,fieldNames));
								result1 = inArray1;
							}
						}
						return result1;
					}
				};
				Array< Dynamic > sortArray = _Function_2_1::Block(inArray,fieldNames);
				if ((sortArray->length != 0)){
					Array< bool > usedArray = Array_obj< bool >::__new();
					{
						int _g1 = 0;
						while((_g1 < inArray->length)){
							__SAFE_POINT
							Dynamic e = inArray->__get(_g1);
							++_g1;
							usedArray->push(false);
						}
					}
					{
						int _g1 = 0;
						while((_g1 < inArray->length)){
							__SAFE_POINT
							Dynamic e = inArray->__get(_g1);
							++_g1;
							int index = 0;
							do{
								struct _Function_6_1{
									inline static int Block( int &index,Array< Dynamic > &sortArray,Dynamic &e)/* DEF (ret block)(not intern) */{
										Dynamic _g11 = hx::ClassOf< ::sandy::util::ArrayUtil >();
										int idx = -1;
										{
											int _g111 = index;
											int _g2 = sortArray->length;
											while((_g111 < _g2)){
												__SAFE_POINT
												int i = _g111++;
												if ((sortArray->__get(i) == e)){
													idx = i;
													break;
												}
											}
										}
										return idx;
									}
								};
								index = _Function_6_1::Block(index,sortArray,e);
							}
while((bool(((index < usedArray->length))) && bool(((usedArray->__get(index) == true)))));
							usedArray[index] = true;
							result->push(index);
						}
					}
				}
				return result;
			}
		};
		Array< int > l_aSId = _Function_1_1::Block(this);
		int l = this->aPolygons->length;
		int j;
		{
			int _g = 0;
			while((_g < l)){
				__SAFE_POINT
				int j1 = _g++;
				l_oPoly = this->aPolygons->__get(l_aSId->__get(j1));
				if ((bool(!l_oPoly->visible) && bool(this->m_bBackFaceCulling)))
					continue;
				int l_nSize = l_oPoly->vertices->length;
				int l_nTriangles = (l_nSize - 2);
				{
					int _g1 = 0;
					while((_g1 < l_nTriangles)){
						__SAFE_POINT
						int i = _g1++;
						l_oA->x = l_oPoly->vertices[i]->sx;
						l_oA->y = l_oPoly->vertices[i]->sy;
						l_oB->x = l_oPoly->vertices[(i + 1)]->sx;
						l_oB->y = l_oPoly->vertices[(i + 1)]->sy;
						l_oC->x = l_oPoly->vertices[hx::Mod(((i + 2)),l_nSize)]->sx;
						l_oC->y = l_oPoly->vertices[hx::Mod(((i + 2)),l_nSize)]->sy;
						if (::sandy::math::IntersectionMath_obj::isPointInTriangle2D(l_oClick,l_oA,l_oB,l_oC)){
							::sandy::core::data::UVCoord l_oUV = l_oPoly->getUVFrom2D(l_oClick);
							::sandy::core::data::Point3D l_oPt3d = l_oPoly->get3DFrom2D(l_oClick);
							this->m_oLastContainer = this->m_oContainer;
							this->m_oLastEvent = ::sandy::events::Shape3DEvent_obj::__new(p_oEvt->type,this,l_oPoly,l_oUV,l_oPt3d,p_oEvt);
							this->m_oEB->dispatchEvent(this->m_oLastEvent);
							if ((p_oEvt->type == ::neash::events::MouseEvent_obj::MOUSE_OVER))
								this->m_bWasOver = true;
							return null();
						}
					}
				}
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Shape3D_obj,_onInteraction,(void))

Void Shape3D_obj::subscribeEvents( ){
{
		__SAFE_POINT
		if ((this->m_bUseSingleContainer == false)){
			{
				int _g = 0;
				Array< ::sandy::core::data::Polygon > _g1 = this->aPolygons;
				while((_g < _g1->length)){
					__SAFE_POINT
					::sandy::core::data::Polygon v = _g1->__get(_g);
					++_g;
					v->__setEnableEvents(true);
				}
			}
		}
		else{
			this->m_oContainer->addEventListener(::neash::events::MouseEvent_obj::CLICK,this->_onInteraction_dyn(),false,0,true);
			this->m_oContainer->addEventListener(::neash::events::MouseEvent_obj::MOUSE_UP,this->_onInteraction_dyn(),false,0,true);
			this->m_oContainer->addEventListener(::neash::events::MouseEvent_obj::MOUSE_DOWN,this->_onInteraction_dyn(),false,0,true);
			this->m_oContainer->addEventListener(::neash::events::MouseEvent_obj::ROLL_OVER,this->_onInteraction_dyn(),false,0,true);
			this->m_oContainer->addEventListener(::neash::events::MouseEvent_obj::ROLL_OUT,this->_onInteraction_dyn(),false,0,true);
			this->m_oContainer->addEventListener(::neash::events::MouseEvent_obj::DOUBLE_CLICK,this->_onInteraction_dyn(),false,0,true);
			this->m_oContainer->addEventListener(::neash::events::MouseEvent_obj::MOUSE_MOVE,this->_onInteraction_dyn(),false,0,true);
			this->m_oContainer->addEventListener(::neash::events::MouseEvent_obj::MOUSE_OVER,this->_onInteraction_dyn(),false,0,true);
			this->m_oContainer->addEventListener(::neash::events::MouseEvent_obj::MOUSE_OUT,this->_onInteraction_dyn(),false,0,true);
			this->m_oContainer->addEventListener(::neash::events::MouseEvent_obj::MOUSE_WHEEL,this->_onInteraction_dyn(),false,0,true);
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Shape3D_obj,subscribeEvents,(void))

Void Shape3D_obj::unsubscribeEvents( ){
{
		__SAFE_POINT
		{
			int _g = 0;
			Array< ::sandy::core::data::Polygon > _g1 = this->aPolygons;
			while((_g < _g1->length)){
				__SAFE_POINT
				::sandy::core::data::Polygon v = _g1->__get(_g);
				++_g;
				v->__setEnableEvents(false);
			}
		}
		this->m_oContainer->removeEventListener(::neash::events::MouseEvent_obj::CLICK,this->_onInteraction_dyn(),null());
		this->m_oContainer->removeEventListener(::neash::events::MouseEvent_obj::MOUSE_UP,this->_onInteraction_dyn(),null());
		this->m_oContainer->removeEventListener(::neash::events::MouseEvent_obj::MOUSE_DOWN,this->_onInteraction_dyn(),null());
		this->m_oContainer->removeEventListener(::neash::events::MouseEvent_obj::ROLL_OVER,this->_onInteraction_dyn(),null());
		this->m_oContainer->removeEventListener(::neash::events::MouseEvent_obj::ROLL_OUT,this->_onInteraction_dyn(),null());
		this->m_oContainer->removeEventListener(::neash::events::MouseEvent_obj::DOUBLE_CLICK,this->_onInteraction_dyn(),null());
		this->m_oContainer->removeEventListener(::neash::events::MouseEvent_obj::MOUSE_MOVE,this->_onInteraction_dyn(),null());
		this->m_oContainer->removeEventListener(::neash::events::MouseEvent_obj::MOUSE_OVER,this->_onInteraction_dyn(),null());
		this->m_oContainer->removeEventListener(::neash::events::MouseEvent_obj::MOUSE_OUT,this->_onInteraction_dyn(),null());
		this->m_oContainer->removeEventListener(::neash::events::MouseEvent_obj::MOUSE_WHEEL,this->_onInteraction_dyn(),null());
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Shape3D_obj,unsubscribeEvents,(void))

Void Shape3D_obj::updateForGeometryChange( ::sandy::core::scenegraph::Geometry3D p_oGeometry,Dynamic __o_updateNormals,Dynamic __o_updateBounds){
bool updateNormals = __o_updateNormals.Default(true);
bool updateBounds = __o_updateBounds.Default(true);
{
		__SAFE_POINT
		if ((bool((this->m_oGeometry == null())) || bool((this->m_oGeometry->aFacesVertexID->length != p_oGeometry->aFacesVertexID->length)))){
			this->__setGeometry(p_oGeometry);
			return null();
		}
		this->m_oGeometry = p_oGeometry;
		if (updateBounds)
			this->updateBoundingVolumes();
		if (updateNormals)
			this->m_oGeometry->updateFaceNormals();
		int l = this->m_oGeometry->aFacesVertexID->length;
		{
			int _g = 0;
			while((_g < l)){
				__SAFE_POINT
				int i = _g++;
				this->aPolygons[i]->update(this->m_oGeometry->aFacesVertexID->__get(i));
			}
		}
		this->__setChanged(true);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC3(Shape3D_obj,updateForGeometryChange,(void))

int Shape3D_obj::SORT_NONE;

int Shape3D_obj::SORT_AVGZ;

int Shape3D_obj::SORT_LAZY_BSP;

int Shape3D_obj::SORT_CUSTOM_BSP;


Shape3D_obj::Shape3D_obj()
{
}

void Shape3D_obj::__Mark()
{
	hx::MarkMember(animated);
	hx::MarkMember(aPolygons);
	hx::MarkMember(aVisiblePolygons);
	hx::MarkMember(container);
	hx::MarkMember(depth);
	hx::MarkMember(enableClipping);
	hx::MarkMember(enableForcedDepth);
	hx::MarkMember(enableNearClipping);
	hx::MarkMember(forcedDepth);
	hx::MarkMember(geometry);
	hx::MarkMember(geometryCenter);
	hx::MarkMember(material);
	hx::MarkMember(bsp);
	hx::MarkMember(sortingMode);
	hx::MarkMember(m_oAppearance);
	hx::MarkMember(m_bEv);
	hx::MarkMember(m_oGeomCenter);
	hx::MarkMember(m_bBackFaceCulling);
	hx::MarkMember(m_bClipping);
	hx::MarkMember(m_bWasOver);
	hx::MarkMember(m_oLastEvent);
	hx::MarkMember(m_oLastContainer);
	hx::MarkMember(m_oGeometry);
	hx::MarkMember(m_bUseSingleContainer);
	hx::MarkMember(m_nDepth);
	hx::MarkMember(m_oContainer);
	hx::MarkMember(m_bMouseInteractivity);
	hx::MarkMember(m_bForcedSingleContainer);
	hx::MarkMember(m_nSortingMode);
	super::__Mark();
}

Dynamic Shape3D_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 3:
		if (!memcmp(inName.__s,L"bsp",sizeof(wchar_t)*3) ) { return bsp; }
		break;
	case 4:
		if (!memcmp(inName.__s,L"cull",sizeof(wchar_t)*4) ) { return cull_dyn(); }
		if (!memcmp(inName.__s,L"copy",sizeof(wchar_t)*4) ) { return copy_dyn(); }
		break;
	case 5:
		if (!memcmp(inName.__s,L"depth",sizeof(wchar_t)*5) ) { return __getDepth(); }
		if (!memcmp(inName.__s,L"clear",sizeof(wchar_t)*5) ) { return clear_dyn(); }
		if (!memcmp(inName.__s,L"clone",sizeof(wchar_t)*5) ) { return clone_dyn(); }
		if (!memcmp(inName.__s,L"m_bEv",sizeof(wchar_t)*5) ) { return m_bEv; }
		break;
	case 7:
		if (!memcmp(inName.__s,L"display",sizeof(wchar_t)*7) ) { return display_dyn(); }
		if (!memcmp(inName.__s,L"destroy",sizeof(wchar_t)*7) ) { return destroy_dyn(); }
		break;
	case 8:
		if (!memcmp(inName.__s,L"animated",sizeof(wchar_t)*8) ) { return animated; }
		if (!memcmp(inName.__s,L"geometry",sizeof(wchar_t)*8) ) { return __getGeometry(); }
		if (!memcmp(inName.__s,L"material",sizeof(wchar_t)*8) ) { return __getMaterial(); }
		if (!memcmp(inName.__s,L"toString",sizeof(wchar_t)*8) ) { return toString_dyn(); }
		if (!memcmp(inName.__s,L"m_nDepth",sizeof(wchar_t)*8) ) { return m_nDepth; }
		break;
	case 9:
		if (!memcmp(inName.__s,L"SORT_NONE",sizeof(wchar_t)*9) ) { return SORT_NONE; }
		if (!memcmp(inName.__s,L"SORT_AVGZ",sizeof(wchar_t)*9) ) { return SORT_AVGZ; }
		if (!memcmp(inName.__s,L"aPolygons",sizeof(wchar_t)*9) ) { return aPolygons; }
		if (!memcmp(inName.__s,L"container",sizeof(wchar_t)*9) ) { return __getContainer(); }
		break;
	case 10:
		if (!memcmp(inName.__s,L"__getDepth",sizeof(wchar_t)*10) ) { return __getDepth_dyn(); }
		if (!memcmp(inName.__s,L"__setDepth",sizeof(wchar_t)*10) ) { return __setDepth_dyn(); }
		if (!memcmp(inName.__s,L"__setScene",sizeof(wchar_t)*10) ) { return __setScene_dyn(); }
		if (!memcmp(inName.__s,L"m_bWasOver",sizeof(wchar_t)*10) ) { return m_bWasOver; }
		break;
	case 11:
		if (!memcmp(inName.__s,L"forcedDepth",sizeof(wchar_t)*11) ) { return forcedDepth; }
		if (!memcmp(inName.__s,L"swapCulling",sizeof(wchar_t)*11) ) { return swapCulling_dyn(); }
		if (!memcmp(inName.__s,L"sortingMode",sizeof(wchar_t)*11) ) { return __getSortingMode(); }
		if (!memcmp(inName.__s,L"m_bClipping",sizeof(wchar_t)*11) ) { return m_bClipping; }
		if (!memcmp(inName.__s,L"m_oGeometry",sizeof(wchar_t)*11) ) { return m_oGeometry; }
		break;
	case 12:
		if (!memcmp(inName.__s,L"m_oLastEvent",sizeof(wchar_t)*12) ) { return m_oLastEvent; }
		if (!memcmp(inName.__s,L"m_oContainer",sizeof(wchar_t)*12) ) { return m_oContainer; }
		break;
	case 13:
		if (!memcmp(inName.__s,L"SORT_LAZY_BSP",sizeof(wchar_t)*13) ) { return SORT_LAZY_BSP; }
		if (!memcmp(inName.__s,L"setConvexFlag",sizeof(wchar_t)*13) ) { return setConvexFlag_dyn(); }
		if (!memcmp(inName.__s,L"__getGeometry",sizeof(wchar_t)*13) ) { return __getGeometry_dyn(); }
		if (!memcmp(inName.__s,L"__setGeometry",sizeof(wchar_t)*13) ) { return __setGeometry_dyn(); }
		if (!memcmp(inName.__s,L"__getMaterial",sizeof(wchar_t)*13) ) { return __getMaterial_dyn(); }
		if (!memcmp(inName.__s,L"__setMaterial",sizeof(wchar_t)*13) ) { return __setMaterial_dyn(); }
		if (!memcmp(inName.__s,L"m_oAppearance",sizeof(wchar_t)*13) ) { return m_oAppearance; }
		if (!memcmp(inName.__s,L"m_oGeomCenter",sizeof(wchar_t)*13) ) { return m_oGeomCenter; }
		break;
	case 14:
		if (!memcmp(inName.__s,L"enableClipping",sizeof(wchar_t)*14) ) { return __getEnableClipping(); }
		if (!memcmp(inName.__s,L"geometryCenter",sizeof(wchar_t)*14) ) { return __getGeometryCenter(); }
		if (!memcmp(inName.__s,L"displayBSPTree",sizeof(wchar_t)*14) ) { return displayBSPTree_dyn(); }
		if (!memcmp(inName.__s,L"__getContainer",sizeof(wchar_t)*14) ) { return __getContainer_dyn(); }
		if (!memcmp(inName.__s,L"_onInteraction",sizeof(wchar_t)*14) ) { return _onInteraction_dyn(); }
		if (!memcmp(inName.__s,L"m_nSortingMode",sizeof(wchar_t)*14) ) { return m_nSortingMode; }
		break;
	case 15:
		if (!memcmp(inName.__s,L"SORT_CUSTOM_BSP",sizeof(wchar_t)*15) ) { return SORT_CUSTOM_BSP; }
		if (!memcmp(inName.__s,L"__getAppearance",sizeof(wchar_t)*15) ) { return __getAppearance_dyn(); }
		if (!memcmp(inName.__s,L"__setAppearance",sizeof(wchar_t)*15) ) { return __setAppearance_dyn(); }
		if (!memcmp(inName.__s,L"subscribeEvents",sizeof(wchar_t)*15) ) { return subscribeEvents_dyn(); }
		break;
	case 16:
		if (!memcmp(inName.__s,L"aVisiblePolygons",sizeof(wchar_t)*16) ) { return aVisiblePolygons; }
		if (!memcmp(inName.__s,L"__getSortingMode",sizeof(wchar_t)*16) ) { return __getSortingMode_dyn(); }
		if (!memcmp(inName.__s,L"__setSortingMode",sizeof(wchar_t)*16) ) { return __setSortingMode_dyn(); }
		if (!memcmp(inName.__s,L"m_oLastContainer",sizeof(wchar_t)*16) ) { return m_oLastContainer; }
		break;
	case 17:
		if (!memcmp(inName.__s,L"enableForcedDepth",sizeof(wchar_t)*17) ) { return enableForcedDepth; }
		if (!memcmp(inName.__s,L"__getEnableEvents",sizeof(wchar_t)*17) ) { return __getEnableEvents_dyn(); }
		if (!memcmp(inName.__s,L"__setEnableEvents",sizeof(wchar_t)*17) ) { return __setEnableEvents_dyn(); }
		if (!memcmp(inName.__s,L"__destroyPolygons",sizeof(wchar_t)*17) ) { return __destroyPolygons_dyn(); }
		if (!memcmp(inName.__s,L"unsubscribeEvents",sizeof(wchar_t)*17) ) { return unsubscribeEvents_dyn(); }
		break;
	case 18:
		if (!memcmp(inName.__s,L"enableNearClipping",sizeof(wchar_t)*18) ) { return enableNearClipping; }
		if (!memcmp(inName.__s,L"__generatePolygons",sizeof(wchar_t)*18) ) { return __generatePolygons_dyn(); }
		if (!memcmp(inName.__s,L"m_bBackFaceCulling",sizeof(wchar_t)*18) ) { return m_bBackFaceCulling; }
		break;
	case 19:
		if (!memcmp(inName.__s,L"__getEnableClipping",sizeof(wchar_t)*19) ) { return __getEnableClipping_dyn(); }
		if (!memcmp(inName.__s,L"__setEnableClipping",sizeof(wchar_t)*19) ) { return __setEnableClipping_dyn(); }
		if (!memcmp(inName.__s,L"__getGeometryCenter",sizeof(wchar_t)*19) ) { return __getGeometryCenter_dyn(); }
		if (!memcmp(inName.__s,L"__setGeometryCenter",sizeof(wchar_t)*19) ) { return __setGeometryCenter_dyn(); }
		break;
	case 21:
		if (!memcmp(inName.__s,L"updateBoundingVolumes",sizeof(wchar_t)*21) ) { return updateBoundingVolumes_dyn(); }
		if (!memcmp(inName.__s,L"m_bUseSingleContainer",sizeof(wchar_t)*21) ) { return m_bUseSingleContainer; }
		if (!memcmp(inName.__s,L"m_bMouseInteractivity",sizeof(wchar_t)*21) ) { return m_bMouseInteractivity; }
		break;
	case 23:
		if (!memcmp(inName.__s,L"__getUseSingleContainer",sizeof(wchar_t)*23) ) { return __getUseSingleContainer_dyn(); }
		if (!memcmp(inName.__s,L"__setUseSingleContainer",sizeof(wchar_t)*23) ) { return __setUseSingleContainer_dyn(); }
		if (!memcmp(inName.__s,L"updateForGeometryChange",sizeof(wchar_t)*23) ) { return updateForGeometryChange_dyn(); }
		break;
	case 24:
		if (!memcmp(inName.__s,L"__getEnableInteractivity",sizeof(wchar_t)*24) ) { return __getEnableInteractivity_dyn(); }
		if (!memcmp(inName.__s,L"__setEnableInteractivity",sizeof(wchar_t)*24) ) { return __setEnableInteractivity_dyn(); }
		if (!memcmp(inName.__s,L"m_bForcedSingleContainer",sizeof(wchar_t)*24) ) { return m_bForcedSingleContainer; }
		break;
	case 26:
		if (!memcmp(inName.__s,L"__getEnableBackFaceCulling",sizeof(wchar_t)*26) ) { return __getEnableBackFaceCulling_dyn(); }
		if (!memcmp(inName.__s,L"__setEnableBackFaceCulling",sizeof(wchar_t)*26) ) { return __setEnableBackFaceCulling_dyn(); }
	}
	return super::__Field(inName);
}

Dynamic Shape3D_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	switch(inName.length) {
	case 3:
		if (!memcmp(inName.__s,L"bsp",sizeof(wchar_t)*3) ) { bsp=inValue.Cast< ::sandy::core::data::BSPNode >(); return inValue; }
		break;
	case 5:
		if (!memcmp(inName.__s,L"depth",sizeof(wchar_t)*5) ) { return __setDepth(inValue); }
		if (!memcmp(inName.__s,L"m_bEv",sizeof(wchar_t)*5) ) { m_bEv=inValue.Cast< bool >(); return inValue; }
		break;
	case 8:
		if (!memcmp(inName.__s,L"animated",sizeof(wchar_t)*8) ) { animated=inValue.Cast< bool >(); return inValue; }
		if (!memcmp(inName.__s,L"geometry",sizeof(wchar_t)*8) ) { return __setGeometry(inValue); }
		if (!memcmp(inName.__s,L"material",sizeof(wchar_t)*8) ) { return __setMaterial(inValue); }
		if (!memcmp(inName.__s,L"m_nDepth",sizeof(wchar_t)*8) ) { m_nDepth=inValue.Cast< double >(); return inValue; }
		break;
	case 9:
		if (!memcmp(inName.__s,L"SORT_NONE",sizeof(wchar_t)*9) ) { SORT_NONE=inValue.Cast< int >(); return inValue; }
		if (!memcmp(inName.__s,L"SORT_AVGZ",sizeof(wchar_t)*9) ) { SORT_AVGZ=inValue.Cast< int >(); return inValue; }
		if (!memcmp(inName.__s,L"aPolygons",sizeof(wchar_t)*9) ) { aPolygons=inValue.Cast< Array< ::sandy::core::data::Polygon > >(); return inValue; }
		if (!memcmp(inName.__s,L"container",sizeof(wchar_t)*9) ) { container=inValue.Cast< ::neash::display::Sprite >(); return inValue; }
		break;
	case 10:
		if (!memcmp(inName.__s,L"m_bWasOver",sizeof(wchar_t)*10) ) { m_bWasOver=inValue.Cast< bool >(); return inValue; }
		break;
	case 11:
		if (!memcmp(inName.__s,L"forcedDepth",sizeof(wchar_t)*11) ) { forcedDepth=inValue.Cast< double >(); return inValue; }
		if (!memcmp(inName.__s,L"sortingMode",sizeof(wchar_t)*11) ) { return __setSortingMode(inValue); }
		if (!memcmp(inName.__s,L"m_bClipping",sizeof(wchar_t)*11) ) { m_bClipping=inValue.Cast< bool >(); return inValue; }
		if (!memcmp(inName.__s,L"m_oGeometry",sizeof(wchar_t)*11) ) { m_oGeometry=inValue.Cast< ::sandy::core::scenegraph::Geometry3D >(); return inValue; }
		break;
	case 12:
		if (!memcmp(inName.__s,L"m_oLastEvent",sizeof(wchar_t)*12) ) { m_oLastEvent=inValue.Cast< ::sandy::events::Shape3DEvent >(); return inValue; }
		if (!memcmp(inName.__s,L"m_oContainer",sizeof(wchar_t)*12) ) { m_oContainer=inValue.Cast< ::neash::display::Sprite >(); return inValue; }
		break;
	case 13:
		if (!memcmp(inName.__s,L"SORT_LAZY_BSP",sizeof(wchar_t)*13) ) { SORT_LAZY_BSP=inValue.Cast< int >(); return inValue; }
		if (!memcmp(inName.__s,L"m_oAppearance",sizeof(wchar_t)*13) ) { m_oAppearance=inValue.Cast< ::sandy::materials::Appearance >(); return inValue; }
		if (!memcmp(inName.__s,L"m_oGeomCenter",sizeof(wchar_t)*13) ) { m_oGeomCenter=inValue.Cast< ::sandy::core::data::Point3D >(); return inValue; }
		break;
	case 14:
		if (!memcmp(inName.__s,L"enableClipping",sizeof(wchar_t)*14) ) { return __setEnableClipping(inValue); }
		if (!memcmp(inName.__s,L"geometryCenter",sizeof(wchar_t)*14) ) { return __setGeometryCenter(inValue); }
		if (!memcmp(inName.__s,L"m_nSortingMode",sizeof(wchar_t)*14) ) { m_nSortingMode=inValue.Cast< int >(); return inValue; }
		break;
	case 15:
		if (!memcmp(inName.__s,L"SORT_CUSTOM_BSP",sizeof(wchar_t)*15) ) { SORT_CUSTOM_BSP=inValue.Cast< int >(); return inValue; }
		break;
	case 16:
		if (!memcmp(inName.__s,L"aVisiblePolygons",sizeof(wchar_t)*16) ) { aVisiblePolygons=inValue.Cast< Array< ::sandy::core::data::Polygon > >(); return inValue; }
		if (!memcmp(inName.__s,L"m_oLastContainer",sizeof(wchar_t)*16) ) { m_oLastContainer=inValue.Cast< ::neash::display::Sprite >(); return inValue; }
		break;
	case 17:
		if (!memcmp(inName.__s,L"enableForcedDepth",sizeof(wchar_t)*17) ) { enableForcedDepth=inValue.Cast< bool >(); return inValue; }
		break;
	case 18:
		if (!memcmp(inName.__s,L"enableNearClipping",sizeof(wchar_t)*18) ) { enableNearClipping=inValue.Cast< bool >(); return inValue; }
		if (!memcmp(inName.__s,L"m_bBackFaceCulling",sizeof(wchar_t)*18) ) { m_bBackFaceCulling=inValue.Cast< bool >(); return inValue; }
		break;
	case 21:
		if (!memcmp(inName.__s,L"m_bUseSingleContainer",sizeof(wchar_t)*21) ) { m_bUseSingleContainer=inValue.Cast< bool >(); return inValue; }
		if (!memcmp(inName.__s,L"m_bMouseInteractivity",sizeof(wchar_t)*21) ) { m_bMouseInteractivity=inValue.Cast< bool >(); return inValue; }
		break;
	case 24:
		if (!memcmp(inName.__s,L"m_bForcedSingleContainer",sizeof(wchar_t)*24) ) { m_bForcedSingleContainer=inValue.Cast< bool >(); return inValue; }
	}
	return super::__SetField(inName,inValue);
}

void Shape3D_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_STRING(L"animated",8));
	outFields->push(HX_STRING(L"aPolygons",9));
	outFields->push(HX_STRING(L"aVisiblePolygons",16));
	outFields->push(HX_STRING(L"container",9));
	outFields->push(HX_STRING(L"depth",5));
	outFields->push(HX_STRING(L"enableClipping",14));
	outFields->push(HX_STRING(L"enableForcedDepth",17));
	outFields->push(HX_STRING(L"enableNearClipping",18));
	outFields->push(HX_STRING(L"forcedDepth",11));
	outFields->push(HX_STRING(L"geometry",8));
	outFields->push(HX_STRING(L"geometryCenter",14));
	outFields->push(HX_STRING(L"material",8));
	outFields->push(HX_STRING(L"bsp",3));
	outFields->push(HX_STRING(L"sortingMode",11));
	outFields->push(HX_STRING(L"m_oAppearance",13));
	outFields->push(HX_STRING(L"m_bEv",5));
	outFields->push(HX_STRING(L"m_oGeomCenter",13));
	outFields->push(HX_STRING(L"m_bBackFaceCulling",18));
	outFields->push(HX_STRING(L"m_bClipping",11));
	outFields->push(HX_STRING(L"m_bWasOver",10));
	outFields->push(HX_STRING(L"m_oLastEvent",12));
	outFields->push(HX_STRING(L"m_oLastContainer",16));
	outFields->push(HX_STRING(L"m_oGeometry",11));
	outFields->push(HX_STRING(L"m_bUseSingleContainer",21));
	outFields->push(HX_STRING(L"m_nDepth",8));
	outFields->push(HX_STRING(L"m_oContainer",12));
	outFields->push(HX_STRING(L"m_bMouseInteractivity",21));
	outFields->push(HX_STRING(L"m_bForcedSingleContainer",24));
	outFields->push(HX_STRING(L"m_nSortingMode",14));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_STRING(L"SORT_NONE",9),
	HX_STRING(L"SORT_AVGZ",9),
	HX_STRING(L"SORT_LAZY_BSP",13),
	HX_STRING(L"SORT_CUSTOM_BSP",15),
	String(null()) };

static ::String sMemberFields[] = {
	HX_STRING(L"animated",8),
	HX_STRING(L"aPolygons",9),
	HX_STRING(L"aVisiblePolygons",16),
	HX_STRING(L"container",9),
	HX_STRING(L"depth",5),
	HX_STRING(L"enableClipping",14),
	HX_STRING(L"enableForcedDepth",17),
	HX_STRING(L"enableNearClipping",18),
	HX_STRING(L"forcedDepth",11),
	HX_STRING(L"geometry",8),
	HX_STRING(L"geometryCenter",14),
	HX_STRING(L"material",8),
	HX_STRING(L"bsp",3),
	HX_STRING(L"clear",5),
	HX_STRING(L"clone",5),
	HX_STRING(L"cull",4),
	HX_STRING(L"display",7),
	HX_STRING(L"displayBSPTree",14),
	HX_STRING(L"destroy",7),
	HX_STRING(L"setConvexFlag",13),
	HX_STRING(L"swapCulling",11),
	HX_STRING(L"toString",8),
	HX_STRING(L"updateBoundingVolumes",21),
	HX_STRING(L"__getAppearance",15),
	HX_STRING(L"__setAppearance",15),
	HX_STRING(L"__getContainer",14),
	HX_STRING(L"__getDepth",10),
	HX_STRING(L"__setDepth",10),
	HX_STRING(L"__getEnableBackFaceCulling",26),
	HX_STRING(L"__setEnableBackFaceCulling",26),
	HX_STRING(L"__getEnableClipping",19),
	HX_STRING(L"__setEnableClipping",19),
	HX_STRING(L"__getEnableEvents",17),
	HX_STRING(L"__setEnableEvents",17),
	HX_STRING(L"__getEnableInteractivity",24),
	HX_STRING(L"__setEnableInteractivity",24),
	HX_STRING(L"__getGeometry",13),
	HX_STRING(L"__setGeometry",13),
	HX_STRING(L"__getGeometryCenter",19),
	HX_STRING(L"__setGeometryCenter",19),
	HX_STRING(L"__getMaterial",13),
	HX_STRING(L"__setMaterial",13),
	HX_STRING(L"__setScene",10),
	HX_STRING(L"__getUseSingleContainer",23),
	HX_STRING(L"__setUseSingleContainer",23),
	HX_STRING(L"sortingMode",11),
	HX_STRING(L"__getSortingMode",16),
	HX_STRING(L"__setSortingMode",16),
	HX_STRING(L"copy",4),
	HX_STRING(L"__destroyPolygons",17),
	HX_STRING(L"__generatePolygons",18),
	HX_STRING(L"_onInteraction",14),
	HX_STRING(L"subscribeEvents",15),
	HX_STRING(L"unsubscribeEvents",17),
	HX_STRING(L"updateForGeometryChange",23),
	HX_STRING(L"m_oAppearance",13),
	HX_STRING(L"m_bEv",5),
	HX_STRING(L"m_oGeomCenter",13),
	HX_STRING(L"m_bBackFaceCulling",18),
	HX_STRING(L"m_bClipping",11),
	HX_STRING(L"m_bWasOver",10),
	HX_STRING(L"m_oLastEvent",12),
	HX_STRING(L"m_oLastContainer",16),
	HX_STRING(L"m_oGeometry",11),
	HX_STRING(L"m_bUseSingleContainer",21),
	HX_STRING(L"m_nDepth",8),
	HX_STRING(L"m_oContainer",12),
	HX_STRING(L"m_bMouseInteractivity",21),
	HX_STRING(L"m_bForcedSingleContainer",24),
	HX_STRING(L"m_nSortingMode",14),
	String(null()) };

static void sMarkStatics() {
	hx::MarkMember(Shape3D_obj::SORT_NONE);
	hx::MarkMember(Shape3D_obj::SORT_AVGZ);
	hx::MarkMember(Shape3D_obj::SORT_LAZY_BSP);
	hx::MarkMember(Shape3D_obj::SORT_CUSTOM_BSP);
};

Class Shape3D_obj::__mClass;

void Shape3D_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_STRING(L"sandy.core.scenegraph.Shape3D",29), hx::TCanCast< Shape3D_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void Shape3D_obj::__boot()
{
	hx::Static(SORT_NONE) = 0;
	hx::Static(SORT_AVGZ) = 1;
	hx::Static(SORT_LAZY_BSP) = 2;
	hx::Static(SORT_CUSTOM_BSP) = 3;
}

} // end namespace sandy
} // end namespace core
} // end namespace scenegraph
