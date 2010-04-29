#include <hxcpp.h>

#ifndef INCLUDED_Lambda
#include <Lambda.h>
#endif
#ifndef INCLUDED_List
#include <List.h>
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
#ifndef INCLUDED_neash_events_EventDispatcher
#include <neash/events/EventDispatcher.h>
#endif
#ifndef INCLUDED_neash_events_IEventDispatcher
#include <neash/events/IEventDispatcher.h>
#endif
#ifndef INCLUDED_nme_display_IBitmapDrawable
#include <nme/display/IBitmapDrawable.h>
#endif
#ifndef INCLUDED_sandy_core_Renderer
#include <sandy/core/Renderer.h>
#endif
#ifndef INCLUDED_sandy_core_SandyFlags
#include <sandy/core/SandyFlags.h>
#endif
#ifndef INCLUDED_sandy_core_Scene3D
#include <sandy/core/Scene3D.h>
#endif
#ifndef INCLUDED_sandy_core_data_Matrix4
#include <sandy/core/data/Matrix4.h>
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
#ifndef INCLUDED_sandy_core_data_Vertex
#include <sandy/core/data/Vertex.h>
#endif
#ifndef INCLUDED_sandy_core_light_Light3D
#include <sandy/core/light/Light3D.h>
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
#ifndef INCLUDED_sandy_core_scenegraph_Renderable
#include <sandy/core/scenegraph/Renderable.h>
#endif
#ifndef INCLUDED_sandy_core_scenegraph_Shape3D
#include <sandy/core/scenegraph/Shape3D.h>
#endif
#ifndef INCLUDED_sandy_core_scenegraph_Sprite2D
#include <sandy/core/scenegraph/Sprite2D.h>
#endif
#ifndef INCLUDED_sandy_materials_Appearance
#include <sandy/materials/Appearance.h>
#endif
#ifndef INCLUDED_sandy_materials_Material
#include <sandy/materials/Material.h>
#endif
#ifndef INCLUDED_sandy_util_ArrayUtil
#include <sandy/util/ArrayUtil.h>
#endif
#ifndef INCLUDED_sandy_view_Frustum
#include <sandy/view/Frustum.h>
#endif
namespace sandy{
namespace core{

Void Renderer_obj::__construct()
{
{
	this->m_aDisplayList = Array_obj< ::sandy::core::scenegraph::IDisplayable >::__new();
	this->m_aRenderingList = Array_obj< ::sandy::core::scenegraph::IDisplayable >::__new();
	this->pool = ::sandy::core::data::Pool_obj::getInstance();
	this->m_nRenderingListCount = 0;
	this->m_nDisplayListCount = 0;
}
;
	return null();
}

Renderer_obj::~Renderer_obj() { }

Dynamic Renderer_obj::__CreateEmpty() { return  new Renderer_obj; }
hx::ObjectPtr< Renderer_obj > Renderer_obj::__new()
{  hx::ObjectPtr< Renderer_obj > result = new Renderer_obj();
	result->__construct();
	return result;}

Dynamic Renderer_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Renderer_obj > result = new Renderer_obj();
	result->__construct();
	return result;}

Void Renderer_obj::init( ){
{
		this->m_nDisplayListCount = 0;
		this->m_bGlobalRedraw = false;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Renderer_obj,init,(void))

Void Renderer_obj::renderDisplayList( ::sandy::core::Scene3D p_oScene){
{
		__SAFE_POINT
		::neash::display::Sprite l_mcContainer = p_oScene->container;
		{
			Array< ::sandy::core::scenegraph::IDisplayable > inArray = this->m_aRenderingList;
			Array< ::String > fieldNames = Array_obj< ::String >::__new().Add(HX_STRING(L"m_nDepth",8));
			int options = 18;
			Array< ::sandy::core::scenegraph::IDisplayable > result = Array_obj< ::sandy::core::scenegraph::IDisplayable >::__new();
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
									struct _Function_8_1{
										inline static Dynamic Block( Array< ::sandy::core::scenegraph::IDisplayable > &inArray,int &i,::String &f)/* DEF (ret block)(not intern) */{
											Dynamic o = inArray->__get(i);
											return ((o == null())) ? Dynamic( null() ) : Dynamic( o->__Field(f) );
										}
									};
									Dynamic fi = _Function_8_1::Block(inArray,i,f);
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
					struct _Function_4_1{
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
					Array< Array< Dynamic > > removedDup = _Function_4_1::Block(testCase);
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
		::sandy::core::scenegraph::IDisplayable l_oFace;
		{
			int _g1 = 0;
			int _g = this->m_nRenderingListCount;
			while((_g1 < _g)){
				__SAFE_POINT
				int i = _g1++;
				l_oFace = this->m_aRenderingList->__get(i);
				if ((bool(l_oFace->__getChanged()) || bool((bool((((l_oFace->__getMaterial() != null())) ? bool( l_oFace->__getMaterial()->__getModified() ) : bool( false ))) || bool(p_oScene->camera->__getChanged()))))){
					l_oFace->display(null());
				}
				if ((i < l_mcContainer->GetNumChildren())){
					if ((l_mcContainer->getChildAt(i) != l_oFace->__getContainer())){
						l_mcContainer->addChildAt(l_oFace->__getContainer(),i);
					}
				}
				else{
					l_mcContainer->addChildAt(l_oFace->__getContainer(),i);
				}
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Renderer_obj,renderDisplayList,(void))

Void Renderer_obj::addToDisplayList( ::sandy::core::scenegraph::IDisplayable p_oObject){
{
		__SAFE_POINT
		this->m_aDisplayList[this->m_nDisplayListCount++] = p_oObject;
		this->m_bGlobalRedraw = (bool(this->m_bGlobalRedraw) || bool((bool(p_oObject->__getChanged()) || bool((((p_oObject->__getMaterial() != null())) ? bool( p_oObject->__getMaterial()->__getModified() ) : bool( false ))))));
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Renderer_obj,addToDisplayList,(void))

Void Renderer_obj::removeFromDisplayList( ::sandy::core::scenegraph::IDisplayable $t1){
{
		__SAFE_POINT
		Array< ::sandy::core::scenegraph::IDisplayable > p_oObject = Array_obj< ::sandy::core::scenegraph::IDisplayable >::__new().Add($t1);
		p_oObject[0]->clear();
		Array< int > l_nKey = Array_obj< int >::__new().Add(-1);

		HX_BEGIN_LOCAL_FUNC2(_Function_1_1,Array< int >,l_nKey,Array< ::sandy::core::scenegraph::IDisplayable >,p_oObject)
		Dynamic run(int i,::sandy::core::scenegraph::IDisplayable v){
{
				l_nKey[0] = ((p_oObject->__get(0) == v)) ? int( i ) : int( l_nKey->__get(0) );
				return null();
			}
			return null();
		}
		HX_END_LOCAL_FUNC2(return)

		::Lambda_obj::mapi(this->m_aDisplayList, Dynamic(new _Function_1_1(l_nKey,p_oObject)));
		if ((l_nKey->__get(0) > -1))
			this->m_aDisplayList->splice(l_nKey->__get(0),1);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Renderer_obj,removeFromDisplayList,(void))

bool Renderer_obj::render( ::sandy::core::Scene3D p_oScene,Dynamic __o_p_bUseCache){
bool p_bUseCache = __o_p_bUseCache.Default(true);
{
		__SAFE_POINT
		double m11;
		double m21;
		double m31;
		double m12;
		double m22;
		double m32;
		double m13;
		double m23;
		double m33;
		double m14;
		double m24;
		double m34;
		double x;
		double y;
		double z;
		::sandy::core::scenegraph::Camera3D l_oCamera = p_oScene->camera;
		double l_nZNear = l_oCamera->__getNear();
		::sandy::core::data::Point3D l_oCamPos = this->pool->__getNextPoint3D();
		int l_nPolyFlags = 0;
		::sandy::core::data::Matrix4 l_oMatrix;
		::sandy::view::Frustum l_oFrustum = l_oCamera->frustrum;
		::sandy::core::data::Vertex l_oVertex;
		Array< ::sandy::core::data::Vertex > l_aVertices;
		::sandy::core::data::Polygon l_oFace;
		double l_nMinZ;
		int l_nFlags;
		int l_nVisiblePolyCount = 0;
		bool l_bForceRedraw = (bool(p_oScene->camera->__getChanged()) || bool((bool(!p_bUseCache) || bool(p_oScene->__getLight()->changed))));
		this->m_bGlobalRedraw = (bool(this->m_bGlobalRedraw) || bool(((this->m_aRenderingList->length == this->m_aDisplayList->length))));
		if ((bool((this->m_bGlobalRedraw == false)) && bool((l_bForceRedraw == false))))
			return false;
		{
			int _g = 0;
			Array< ::sandy::core::scenegraph::IDisplayable > _g1 = this->m_aRenderingList;
			while((_g < _g1->length)){
				__SAFE_POINT
				::sandy::core::scenegraph::IDisplayable l_oObj = _g1->__get(_g);
				++_g;
				if ((l_oObj != null())){
					if ((bool((l_bForceRedraw == true)) || bool((bool((((l_oObj->__getMaterial() != null())) ? bool( l_oObj->__getMaterial()->__getModified() ) : bool( false ))) || bool((l_oObj->__getChanged() == true)))))){
						l_oObj->clear();
					}
				}
			}
		}
		this->m_nRenderingListCount = 0;
		{
			Dynamic array = this->m_aRenderingList;
			array->__Field(HX_STRING(L"splice",6))(0,array->__Field(HX_STRING(L"length",6)));
		}
		{
			int _g1 = 0;
			int _g = this->m_nDisplayListCount;
			while((_g1 < _g)){
				__SAFE_POINT
				int i = _g1++;
				if (::Std_obj::is(this->m_aDisplayList->__get(i),hx::ClassOf< ::sandy::core::scenegraph::Shape3D >())){
					::sandy::core::scenegraph::Shape3D l_oShape = this->m_aDisplayList->__get(i);
					bool l_oShapeSingleContainer = l_oShape->__getUseSingleContainer();
					if ((bool((l_oShape->__getChanged() == false)) && bool((l_bForceRedraw == false)))){
						if (l_oShapeSingleContainer){
							this->m_aRenderingList[this->m_nRenderingListCount++] = l_oShape;
						}
						else{
							{
								int _g2 = 0;
								Array< ::sandy::core::data::Polygon > _g3 = l_oShape->aVisiblePolygons;
								while((_g2 < _g3->length)){
									__SAFE_POINT
									::sandy::core::data::Polygon l_oFace1 = _g3->__get(_g2);
									++_g2;
									this->m_aRenderingList[this->m_nRenderingListCount++] = l_oFace1;
								}
							}
						}
						continue;
					}
					l_nFlags = l_oShape->__getAppearance()->__getFlags();
					l_oShape->__setDepth(0);
					{
						Dynamic array = l_oShape->aVisiblePolygons;
						array->__Field(HX_STRING(L"splice",6))(0,array->__Field(HX_STRING(L"length",6)));
					}
					l_oCamPos->reset(l_oCamera->modelMatrix->n14,l_oCamera->modelMatrix->n24,l_oCamera->modelMatrix->n34);
					l_oShape->invModelMatrix->transform(l_oCamPos);
					l_oMatrix = l_oShape->viewMatrix;
					m11 = l_oMatrix->n11;
					m21 = l_oMatrix->n21;
					m31 = l_oMatrix->n31;
					m12 = l_oMatrix->n12;
					m22 = l_oMatrix->n22;
					m32 = l_oMatrix->n32;
					m13 = l_oMatrix->n13;
					m23 = l_oMatrix->n23;
					m33 = l_oMatrix->n33;
					m14 = l_oMatrix->n14;
					m24 = l_oMatrix->n24;
					m34 = l_oMatrix->n34;
					bool l_bClipped = ((bool(((l_oShape->culled == 0))) && bool(((bool(l_oShape->__getEnableClipping()) || bool(l_oShape->enableNearClipping))))));
					{
						int _g2 = 0;
						Array< ::sandy::core::data::Vertex > _g3 = l_oShape->__getGeometry()->aVertex;
						while((_g2 < _g3->length)){
							__SAFE_POINT
							::sandy::core::data::Vertex l_oVertex1 = _g3->__get(_g2);
							++_g2;
							l_oVertex1->projected = l_oVertex1->transformed = false;
						}
					}
					{
						int _g2 = 0;
						Array< ::sandy::core::data::Polygon > _g3 = l_oShape->aPolygons;
						while((_g2 < _g3->length)){
							__SAFE_POINT
							::sandy::core::data::Polygon l_oFace1 = _g3->__get(_g2);
							++_g2;
							if (l_oShape->animated)
								l_oFace1->updateNormal();
							l_oVertex = l_oFace1->__getNormal();
							x = l_oFace1->a->x;
							y = l_oFace1->a->y;
							z = l_oFace1->a->z;
							l_oFace1->visible = ((((((l_oVertex->x * ((l_oCamPos->x - x))) + (l_oVertex->y * ((l_oCamPos->y - y))))) + (l_oVertex->z * ((l_oCamPos->z - z))))) > 0);
							if (l_oShape->__getEnableBackFaceCulling()){
								if ((l_oFace1->visible == false))
									continue;
							}
							l_oVertex = l_oFace1->a;
							if ((l_oVertex->transformed == false)){
								l_oVertex->wx = (((((((x) * m11) + ((y) * m12))) + ((z) * m13))) + m14);
								l_oVertex->wy = ((((((x * m21) + (y * m22))) + (z * m23))) + m24);
								l_oVertex->wz = ((((((x * m31) + (y * m32))) + (z * m33))) + m34);
								l_oVertex->transformed = true;
							}
							l_oVertex = l_oFace1->b;
							if ((l_oVertex->transformed == false)){
								l_oVertex->wx = (((((((x = l_oVertex->x) * m11) + ((y = l_oVertex->y) * m12))) + ((z = l_oVertex->z) * m13))) + m14);
								l_oVertex->wy = ((((((x * m21) + (y * m22))) + (z * m23))) + m24);
								l_oVertex->wz = ((((((x * m31) + (y * m32))) + (z * m33))) + m34);
								l_oVertex->transformed = true;
							}
							l_oVertex = l_oFace1->c;
							if ((l_oVertex != null())){
								if ((l_oVertex->transformed == false)){
									l_oVertex->wx = (((((((x = l_oVertex->x) * m11) + ((y = l_oVertex->y) * m12))) + ((z = l_oVertex->z) * m13))) + m14);
									l_oVertex->wy = ((((((x * m21) + (y * m22))) + (z * m23))) + m24);
									l_oVertex->wz = ((((((x * m31) + (y * m32))) + (z * m33))) + m34);
									l_oVertex->transformed = true;
								}
							}
							l_oVertex = l_oFace1->d;
							if ((l_oVertex != null())){
								if ((l_oVertex->transformed == false)){
									l_oVertex->wx = (((((((x = l_oVertex->x) * m11) + ((y = l_oVertex->y) * m12))) + ((z = l_oVertex->z) * m13))) + m14);
									l_oVertex->wy = ((((((x * m21) + (y * m22))) + (z * m23))) + m24);
									l_oVertex->wz = ((((((x * m31) + (y * m32))) + (z * m33))) + m34);
									l_oVertex->transformed = true;
								}
							}
							l_oFace1->precompute();
							l_nMinZ = l_oFace1->minZ;
							if (l_bClipped){
								if (l_oShape->__getEnableClipping()){
									l_oFace1->clip(l_oFrustum);
								}
								else{
									if ((bool(l_oShape->enableNearClipping) && bool((l_nMinZ < l_nZNear)))){
										l_oFace1->clipFrontPlane(l_oFrustum);
									}
									else{
										if ((l_nMinZ < l_nZNear)){
											continue;
										}
									}
								}
							}
							else{
								if ((l_nMinZ < l_nZNear)){
									continue;
								}
							}
							bool l_bIsClipped = l_oFace1->isClipped;
							l_aVertices = l_bIsClipped ? Array< ::sandy::core::data::Vertex >( l_oFace1->cvertices ) : Array< ::sandy::core::data::Vertex >( l_oFace1->vertices );
							if ((l_aVertices->length > 1)){
								l_oCamera->projectArray(l_aVertices);
								if ((bool(l_bIsClipped) && bool(l_oFace1->__getEnableEvents())))
									l_oCamera->projectArray(l_oFace1->vertices);
								if (l_oShape->enableForcedDepth){
									if ((l_oShapeSingleContainer == false))
										l_oFace1->__setDepth(l_oShape->forcedDepth);
								}
								else{
									::sandy::core::scenegraph::Shape3D _g4 = l_oShape;
									_g4->__setDepth((_g4->__getDepth() + l_oFace1->__getDepth()));
								}
								l_nVisiblePolyCount++;
								l_oShape->aVisiblePolygons[l_oShape->aVisiblePolygons->length] = l_oFace1;
								hx::OrEq(l_nPolyFlags,l_nFlags);
								if ((l_oShapeSingleContainer == false)){
									this->m_aRenderingList[this->m_nRenderingListCount++] = l_oFace1;
								}
							}
						}
					}
					if ((l_oShape->aVisiblePolygons->length > 0)){
						if ((l_oShape->__getUseSingleContainer() == true)){
							if (l_oShape->enableForcedDepth){
								l_oShape->__setDepth(l_oShape->forcedDepth);
							}
							else{
								::sandy::core::scenegraph::Shape3D _g2 = l_oShape;
								_g2->__setDepth((double(_g2->__getDepth()) / double(l_oShape->aVisiblePolygons->length)));
							}
							this->m_aRenderingList[this->m_nRenderingListCount++] = l_oShape;
						}
						else{
							if ((l_oShape->enableForcedDepth == false)){
								::sandy::core::scenegraph::Shape3D _g2 = l_oShape;
								_g2->__setDepth((double(_g2->__getDepth()) / double(l_oShape->aVisiblePolygons->length)));
							}
						}
						if ((bool((l_nFlags != 0)) || bool((l_nPolyFlags != 0)))){
							if ((((int(((int(l_nFlags) | int(l_nPolyFlags)))) & int(::sandy::core::SandyFlags_obj::POLYGON_NORMAL_WORLD))) != 0)){
								l_oMatrix = l_oShape->modelMatrix;
								m11 = l_oMatrix->n11;
								m21 = l_oMatrix->n21;
								m31 = l_oMatrix->n31;
								m12 = l_oMatrix->n12;
								m22 = l_oMatrix->n22;
								m32 = l_oMatrix->n32;
								m13 = l_oMatrix->n13;
								m23 = l_oMatrix->n23;
								m33 = l_oMatrix->n33;
								{
									int _g2 = 0;
									Array< ::sandy::core::data::Polygon > _g3 = l_oShape->aVisiblePolygons;
									while((_g2 < _g3->length)){
										__SAFE_POINT
										::sandy::core::data::Polygon l_oFace1 = _g3->__get(_g2);
										++_g2;
										l_oVertex = l_oFace1->__getNormal();
										l_oVertex->wx = (((((x = l_oVertex->x) * m11) + ((y = l_oVertex->y) * m12))) + ((z = l_oVertex->z) * m13));
										l_oVertex->wy = ((((x * m21) + (y * m22))) + (z * m23));
										l_oVertex->wz = ((((x * m31) + (y * m32))) + (z * m33));
									}
								}
							}
							if ((((int(((int(l_nFlags) | int(l_nPolyFlags)))) & int(::sandy::core::SandyFlags_obj::VERTEX_NORMAL_WORLD))) != 0)){
								l_oMatrix = l_oShape->modelMatrix;
								m11 = l_oMatrix->n11;
								m21 = l_oMatrix->n21;
								m31 = l_oMatrix->n31;
								m12 = l_oMatrix->n12;
								m22 = l_oMatrix->n22;
								m32 = l_oMatrix->n32;
								m13 = l_oMatrix->n13;
								m23 = l_oMatrix->n23;
								m33 = l_oMatrix->n33;
								{
									int _g2 = 0;
									Array< ::sandy::core::data::Vertex > _g3 = l_oShape->__getGeometry()->aVertexNormals;
									while((_g2 < _g3->length)){
										__SAFE_POINT
										::sandy::core::data::Vertex l_oVertex1 = _g3->__get(_g2);
										++_g2;
										l_oVertex1->wx = (((((x = l_oVertex1->x) * m11) + ((y = l_oVertex1->y) * m12))) + ((z = l_oVertex1->z) * m13));
										l_oVertex1->wy = ((((x * m21) + (y * m22))) + (z * m23));
										l_oVertex1->wz = ((((x * m31) + (y * m32))) + (z * m33));
									}
								}
							}
						}
					}
				}
				else{
					if (::Std_obj::is(this->m_aDisplayList->__get(i),hx::ClassOf< ::sandy::core::scenegraph::Sprite2D >())){
						::sandy::core::scenegraph::Sprite2D l_oSprite2D = this->m_aDisplayList->__get(i);
						l_oSprite2D->v->projected = false;
						l_oSprite2D->vx->projected = false;
						l_oSprite2D->vy->projected = false;
						l_oVertex = l_oSprite2D->v;
						l_oMatrix = l_oSprite2D->viewMatrix;
						l_oVertex->wx = ((((((l_oVertex->x * l_oMatrix->n11) + (l_oVertex->y * l_oMatrix->n12))) + (l_oVertex->z * l_oMatrix->n13))) + l_oMatrix->n14);
						l_oVertex->wy = ((((((l_oVertex->x * l_oMatrix->n21) + (l_oVertex->y * l_oMatrix->n22))) + (l_oVertex->z * l_oMatrix->n23))) + l_oMatrix->n24);
						l_oVertex->wz = ((((((l_oVertex->x * l_oMatrix->n31) + (l_oVertex->y * l_oMatrix->n32))) + (l_oVertex->z * l_oMatrix->n33))) + l_oMatrix->n34);
						l_oSprite2D->__setDepth(l_oSprite2D->enableForcedDepth ? double( l_oSprite2D->forcedDepth ) : double( l_oVertex->wz ));
						l_oCamera->projectVertex(l_oVertex);
						this->m_aRenderingList[this->m_nRenderingListCount++] = l_oSprite2D;
						l_oSprite2D->vx->copy(l_oVertex);
						l_oSprite2D->vx->wx++;
						l_oCamera->projectVertex(l_oSprite2D->vx);
						l_oSprite2D->vy->copy(l_oVertex);
						l_oSprite2D->vy->wy++;
						l_oCamera->projectVertex(l_oSprite2D->vy);
					}
					else{
						if (::Std_obj::is(this->m_aDisplayList->__get(i),hx::ClassOf< ::sandy::core::scenegraph::Renderable >())){
							::sandy::core::scenegraph::Renderable r = this->m_aDisplayList->__get(i);
							r->render(l_oCamera);
							this->m_aRenderingList[this->m_nRenderingListCount++] = this->m_aDisplayList->__get(i);
						}
					}
				}
			}
		}
		return true;
	}
}


HX_DEFINE_DYNAMIC_FUNC2(Renderer_obj,render,return )


Renderer_obj::Renderer_obj()
{
}

void Renderer_obj::__Mark()
{
	hx::MarkMember(m_aDisplayList);
	hx::MarkMember(m_nDisplayListCount);
	hx::MarkMember(m_aCamera);
	hx::MarkMember(m_aRenderingList);
	hx::MarkMember(m_nRenderingListCount);
	hx::MarkMember(pool);
	hx::MarkMember(m_bGlobalRedraw);
}

Dynamic Renderer_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 4:
		if (!memcmp(inName.__s,L"pool",sizeof(wchar_t)*4) ) { return pool; }
		if (!memcmp(inName.__s,L"init",sizeof(wchar_t)*4) ) { return init_dyn(); }
		break;
	case 6:
		if (!memcmp(inName.__s,L"render",sizeof(wchar_t)*6) ) { return render_dyn(); }
		break;
	case 9:
		if (!memcmp(inName.__s,L"m_aCamera",sizeof(wchar_t)*9) ) { return m_aCamera; }
		break;
	case 14:
		if (!memcmp(inName.__s,L"m_aDisplayList",sizeof(wchar_t)*14) ) { return m_aDisplayList; }
		break;
	case 15:
		if (!memcmp(inName.__s,L"m_bGlobalRedraw",sizeof(wchar_t)*15) ) { return m_bGlobalRedraw; }
		break;
	case 16:
		if (!memcmp(inName.__s,L"m_aRenderingList",sizeof(wchar_t)*16) ) { return m_aRenderingList; }
		if (!memcmp(inName.__s,L"addToDisplayList",sizeof(wchar_t)*16) ) { return addToDisplayList_dyn(); }
		break;
	case 17:
		if (!memcmp(inName.__s,L"renderDisplayList",sizeof(wchar_t)*17) ) { return renderDisplayList_dyn(); }
		break;
	case 19:
		if (!memcmp(inName.__s,L"m_nDisplayListCount",sizeof(wchar_t)*19) ) { return m_nDisplayListCount; }
		break;
	case 21:
		if (!memcmp(inName.__s,L"m_nRenderingListCount",sizeof(wchar_t)*21) ) { return m_nRenderingListCount; }
		if (!memcmp(inName.__s,L"removeFromDisplayList",sizeof(wchar_t)*21) ) { return removeFromDisplayList_dyn(); }
	}
	return super::__Field(inName);
}

Dynamic Renderer_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	switch(inName.length) {
	case 4:
		if (!memcmp(inName.__s,L"pool",sizeof(wchar_t)*4) ) { pool=inValue.Cast< ::sandy::core::data::Pool >(); return inValue; }
		break;
	case 9:
		if (!memcmp(inName.__s,L"m_aCamera",sizeof(wchar_t)*9) ) { m_aCamera=inValue.Cast< ::sandy::core::scenegraph::Camera3D >(); return inValue; }
		break;
	case 14:
		if (!memcmp(inName.__s,L"m_aDisplayList",sizeof(wchar_t)*14) ) { m_aDisplayList=inValue.Cast< Array< ::sandy::core::scenegraph::IDisplayable > >(); return inValue; }
		break;
	case 15:
		if (!memcmp(inName.__s,L"m_bGlobalRedraw",sizeof(wchar_t)*15) ) { m_bGlobalRedraw=inValue.Cast< bool >(); return inValue; }
		break;
	case 16:
		if (!memcmp(inName.__s,L"m_aRenderingList",sizeof(wchar_t)*16) ) { m_aRenderingList=inValue.Cast< Array< ::sandy::core::scenegraph::IDisplayable > >(); return inValue; }
		break;
	case 19:
		if (!memcmp(inName.__s,L"m_nDisplayListCount",sizeof(wchar_t)*19) ) { m_nDisplayListCount=inValue.Cast< int >(); return inValue; }
		break;
	case 21:
		if (!memcmp(inName.__s,L"m_nRenderingListCount",sizeof(wchar_t)*21) ) { m_nRenderingListCount=inValue.Cast< int >(); return inValue; }
	}
	return super::__SetField(inName,inValue);
}

void Renderer_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_STRING(L"m_aDisplayList",14));
	outFields->push(HX_STRING(L"m_nDisplayListCount",19));
	outFields->push(HX_STRING(L"m_aCamera",9));
	outFields->push(HX_STRING(L"m_aRenderingList",16));
	outFields->push(HX_STRING(L"m_nRenderingListCount",21));
	outFields->push(HX_STRING(L"pool",4));
	outFields->push(HX_STRING(L"m_bGlobalRedraw",15));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_STRING(L"m_aDisplayList",14),
	HX_STRING(L"m_nDisplayListCount",19),
	HX_STRING(L"m_aCamera",9),
	HX_STRING(L"m_aRenderingList",16),
	HX_STRING(L"m_nRenderingListCount",21),
	HX_STRING(L"pool",4),
	HX_STRING(L"m_bGlobalRedraw",15),
	HX_STRING(L"init",4),
	HX_STRING(L"renderDisplayList",17),
	HX_STRING(L"addToDisplayList",16),
	HX_STRING(L"removeFromDisplayList",21),
	HX_STRING(L"render",6),
	String(null()) };

static void sMarkStatics() {
};

Class Renderer_obj::__mClass;

void Renderer_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_STRING(L"sandy.core.Renderer",19), hx::TCanCast< Renderer_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void Renderer_obj::__boot()
{
}

} // end namespace sandy
} // end namespace core
