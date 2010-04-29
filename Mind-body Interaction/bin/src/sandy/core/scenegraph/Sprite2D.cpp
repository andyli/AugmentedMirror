#include <hxcpp.h>

#ifndef INCLUDED_hxMath
#include <hxMath.h>
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
#ifndef INCLUDED_neash_geom_Transform
#include <neash/geom/Transform.h>
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
#ifndef INCLUDED_sandy_bounds_BSphere
#include <sandy/bounds/BSphere.h>
#endif
#ifndef INCLUDED_sandy_core_Renderer
#include <sandy/core/Renderer.h>
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
#ifndef INCLUDED_sandy_core_data_Vertex
#include <sandy/core/data/Vertex.h>
#endif
#ifndef INCLUDED_sandy_core_scenegraph_ATransformable
#include <sandy/core/scenegraph/ATransformable.h>
#endif
#ifndef INCLUDED_sandy_core_scenegraph_Camera3D
#include <sandy/core/scenegraph/Camera3D.h>
#endif
#ifndef INCLUDED_sandy_core_scenegraph_IDisplayable
#include <sandy/core/scenegraph/IDisplayable.h>
#endif
#ifndef INCLUDED_sandy_core_scenegraph_Node
#include <sandy/core/scenegraph/Node.h>
#endif
#ifndef INCLUDED_sandy_core_scenegraph_Sprite2D
#include <sandy/core/scenegraph/Sprite2D.h>
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
#ifndef INCLUDED_sandy_materials_Material
#include <sandy/materials/Material.h>
#endif
#ifndef INCLUDED_sandy_view_Frustum
#include <sandy/view/Frustum.h>
#endif
namespace sandy{
namespace core{
namespace scenegraph{

Void Sprite2D_obj::__construct(Dynamic __o_p_sName,::neash::display::DisplayObject p_oContent,Dynamic __o_p_nScale)
{
::String p_sName = __o_p_sName.Default(HX_STRING(L"",0));
double p_nScale = __o_p_nScale.Default(1.0);
{
	this->fixedAngle = false;
	this->autoCenter = true;
	this->floorCenter = false;
	this->enableForcedDepth = false;
	this->forcedDepth = 0;
	this->m_bEv = false;
	this->m_nW2 = 0;
	this->m_nH2 = 0;
	this->m_nPerspScaleX = 0;
	this->m_nPerspScaleY = 0;
	this->m_nRotation = 0;
	super::__construct(p_sName);
	this->m_oContainer = ::neash::display::Sprite_obj::__new();
	this->v = ::sandy::core::data::Vertex_obj::__new(null(),null(),null(),null(),null(),null());
	this->vx = ::sandy::core::data::Vertex_obj::__new(null(),null(),null(),null(),null(),null());
	this->vy = ::sandy::core::data::Vertex_obj::__new(null(),null(),null(),null(),null(),null());
	this->_nScale = p_nScale;
	if ((p_oContent != null())){
		this->__setContent(p_oContent);
		this->setBoundingSphereRadius(::Math_obj::max(30,(::Math_obj::abs(this->_nScale) * ::Math_obj::max(this->__getContent()->GetWidth(),this->__getContent()->GetHeight()))));
	}
}
;
	return null();
}

Sprite2D_obj::~Sprite2D_obj() { }

Dynamic Sprite2D_obj::__CreateEmpty() { return  new Sprite2D_obj; }
hx::ObjectPtr< Sprite2D_obj > Sprite2D_obj::__new(Dynamic __o_p_sName,::neash::display::DisplayObject p_oContent,Dynamic __o_p_nScale)
{  hx::ObjectPtr< Sprite2D_obj > result = new Sprite2D_obj();
	result->__construct(__o_p_sName,p_oContent,__o_p_nScale);
	return result;}

Dynamic Sprite2D_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Sprite2D_obj > result = new Sprite2D_obj();
	result->__construct(inArgs[0],inArgs[1],inArgs[2]);
	return result;}

hx::Object *Sprite2D_obj::__ToInterface(const type_info &inType) {
	if (inType==typeid( ::sandy::core::scenegraph::IDisplayable_obj)) return operator ::sandy::core::scenegraph::IDisplayable_obj *();
	return super::__ToInterface(inType);
}

::neash::display::DisplayObject Sprite2D_obj::__getContent( ){
	return this->m_oContent;
}


HX_DEFINE_DYNAMIC_FUNC0(Sprite2D_obj,__getContent,return )

::neash::display::DisplayObject Sprite2D_obj::__setContent( ::neash::display::DisplayObject p_content){
	__SAFE_POINT
	p_content->GetTransform()->GetMatrix()->identity();
	if ((this->m_oContent != null()))
		this->m_oContainer->removeChild(this->m_oContent);
	this->m_oContent = p_content;
	this->m_oContainer->addChildAt(this->m_oContent,0);
	this->m_oContent->SetX(0);
	this->m_oContent->SetY(0);
	this->m_nW2 = (double(this->m_oContainer->GetWidth()) / double(2));
	this->m_nH2 = (double(this->m_oContainer->GetHeight()) / double(2));
	return p_content;
}


HX_DEFINE_DYNAMIC_FUNC1(Sprite2D_obj,__setContent,return )

::sandy::core::Scene3D Sprite2D_obj::__setScene( ::sandy::core::Scene3D p_oScene){
	__SAFE_POINT
	if ((p_oScene == null()))
		return null();
	if ((this->__getScene() != null())){
		this->__getScene()->removeEventListener(HX_STRING(L"scene_render_finish",19),this->_finishMaterial_dyn(),null());
		this->__getScene()->removeEventListener(HX_STRING(L"scene_render_display_list",25),this->_beginMaterial_dyn(),null());
	}
	this->super::__setScene(p_oScene);
	this->__getScene()->addEventListener(HX_STRING(L"scene_render_finish",19),this->_finishMaterial_dyn(),null(),null(),null());
	this->__getScene()->addEventListener(HX_STRING(L"scene_render_display_list",25),this->_beginMaterial_dyn(),null(),null(),null());
	return p_oScene;
}


HX_DEFINE_DYNAMIC_FUNC1(Sprite2D_obj,__setScene,return )

Void Sprite2D_obj::_finishMaterial( ::sandy::events::SandyEvent pEvt){
{
		__SAFE_POINT
		if ((this->m_oMaterial == null()))
			return null();
		if (!this->__getVisible())
			return null();
		this->m_oMaterial->finish(this->__getScene());
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Sprite2D_obj,_finishMaterial,(void))

Void Sprite2D_obj::_beginMaterial( ::sandy::events::SandyEvent pEvt){
{
		__SAFE_POINT
		if ((this->m_oMaterial == null()))
			return null();
		if (!this->__getVisible())
			return null();
		this->m_oMaterial->begin(this->__getScene());
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Sprite2D_obj,_beginMaterial,(void))

::neash::display::Sprite Sprite2D_obj::__getContainer( ){
	return this->m_oContainer;
}


HX_DEFINE_DYNAMIC_FUNC0(Sprite2D_obj,__getContainer,return )

Void Sprite2D_obj::setBoundingSphereRadius( double p_nRadius){
{
		this->boundingSphere->radius = p_nRadius;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Sprite2D_obj,setBoundingSphereRadius,(void))

double Sprite2D_obj::__getScale( ){
	return this->_nScale;
}


HX_DEFINE_DYNAMIC_FUNC0(Sprite2D_obj,__getScale,return )

double Sprite2D_obj::__setScale( double n){
	__SAFE_POINT
	if (!::Math_obj::isNaN(n))
		this->_nScale = n;
	this->__setChanged(true);
	return n;
}


HX_DEFINE_DYNAMIC_FUNC1(Sprite2D_obj,__setScale,return )

double Sprite2D_obj::__getDepth( ){
	return this->m_nDepth;
}


HX_DEFINE_DYNAMIC_FUNC0(Sprite2D_obj,__getDepth,return )

double Sprite2D_obj::__setDepth( double p_nDepth){
	__SAFE_POINT
	this->m_nDepth = p_nDepth;
	this->__setChanged(true);
	return p_nDepth;
}


HX_DEFINE_DYNAMIC_FUNC1(Sprite2D_obj,__setDepth,return )

Void Sprite2D_obj::cull( ::sandy::view::Frustum p_oFrustum,::sandy::core::data::Matrix4 p_oViewMatrix,bool p_bChanged){
{
		__SAFE_POINT
		this->super::cull(p_oFrustum,p_oViewMatrix,p_bChanged);
		if ((this->__getVisible() == false)){
			this->__getContainer()->visible = this->__getVisible();
			return null();
		}
		if ((this->viewMatrix != null())){
			this->boundingSphere->transform(this->viewMatrix);
			this->culled = p_oFrustum->sphereInFrustum(this->boundingSphere);
		}
		if ((this->culled == 2)){
			this->__getContainer()->visible = false;
		}
		else{
			if ((this->culled == 0)){
				if ((this->boundingSphere->position->z <= this->__getScene()->camera->__getNear())){
					this->__getContainer()->visible = false;
				}
				else{
					this->__getContainer()->visible = true;
					this->__getScene()->renderer->addToDisplayList(this);
				}
			}
			else{
				this->__getContainer()->visible = true;
				this->__getScene()->renderer->addToDisplayList(this);
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC3(Sprite2D_obj,cull,(void))

Void Sprite2D_obj::clear( ){
{
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Sprite2D_obj,clear,(void))

Void Sprite2D_obj::remove( ){
{
		__SAFE_POINT
		if ((this->m_oContainer->GetParent() != null()))
			this->m_oContainer->GetParent()->removeChild(this->m_oContainer);
		this->m_oContainer->GetGraphics()->clear();
		this->__setEnableEvents(false);
		if ((this->__getScene() != null())){
			this->__getScene()->removeEventListener(HX_STRING(L"scene_render_finish",19),this->_finishMaterial_dyn(),null());
			this->__getScene()->removeEventListener(HX_STRING(L"scene_render_display_list",25),this->_beginMaterial_dyn(),null());
		}
		this->super::remove();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Sprite2D_obj,remove,(void))

Void Sprite2D_obj::destroy( ){
{
		__SAFE_POINT
		this->remove();
		this->super::destroy();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Sprite2D_obj,destroy,(void))

Void Sprite2D_obj::display( ::neash::display::Sprite p_oContainer){
{
		__SAFE_POINT
		this->m_nPerspScaleX = ((this->_nScale == 0)) ? double( 1 ) : double( (this->_nScale * ((this->vx->sx - this->v->sx))) );
		this->m_nPerspScaleY = ((this->_nScale == 0)) ? double( 1 ) : double( (this->_nScale * ((this->v->sy - this->vy->sy))) );
		this->m_nRotation = ::Math_obj::atan2(this->viewMatrix->n12,this->viewMatrix->n22);
		this->m_oContainer->SetScaleX(this->m_nPerspScaleX);
		this->m_oContainer->SetScaleY(this->m_nPerspScaleY);
		this->m_oContainer->SetX((this->v->sx - (this->autoCenter ? double( (double(this->m_oContainer->GetWidth()) / double(2)) ) : double( 0 ))));
		this->m_oContainer->SetY((this->v->sy - (this->autoCenter ? double( (double(this->m_oContainer->GetHeight()) / double(2)) ) : double( (this->floorCenter ? double( this->m_oContainer->GetHeight() ) : double( 0 )) ))));
		if (this->fixedAngle)
			this->m_oContainer->SetRotation((double(((this->m_nRotation * 180))) / double(::Math_obj::PI)));
		if ((this->m_oMaterial != null()))
			this->m_oMaterial->renderSprite(this,this->m_oMaterial,this->__getScene());
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Sprite2D_obj,display,(void))

::sandy::materials::Material Sprite2D_obj::__getMaterial( ){
	return this->m_oMaterial;
}


HX_DEFINE_DYNAMIC_FUNC0(Sprite2D_obj,__getMaterial,return )

::sandy::materials::Material Sprite2D_obj::__setMaterial( ::sandy::materials::Material p_oMaterial){
	__SAFE_POINT
	this->m_oMaterial = p_oMaterial;
	this->__setChanged(true);
	return p_oMaterial;
}


HX_DEFINE_DYNAMIC_FUNC1(Sprite2D_obj,__setMaterial,return )

bool Sprite2D_obj::__getEnableEvents( ){
	return this->m_bEv;
}


HX_DEFINE_DYNAMIC_FUNC0(Sprite2D_obj,__getEnableEvents,return )

bool Sprite2D_obj::__setEnableEvents( bool b){
	__SAFE_POINT
	if ((bool(b) && bool(!this->m_bEv))){
		this->m_oContainer->addEventListener(::neash::events::MouseEvent_obj::CLICK,this->_onInteraction_dyn(),null(),null(),null());
		this->m_oContainer->addEventListener(::neash::events::MouseEvent_obj::MOUSE_UP,this->_onInteraction_dyn(),null(),null(),null());
		this->m_oContainer->addEventListener(::neash::events::MouseEvent_obj::MOUSE_DOWN,this->_onInteraction_dyn(),null(),null(),null());
		this->m_oContainer->addEventListener(::neash::events::MouseEvent_obj::ROLL_OVER,this->_onInteraction_dyn(),null(),null(),null());
		this->m_oContainer->addEventListener(::neash::events::MouseEvent_obj::ROLL_OUT,this->_onInteraction_dyn(),null(),null(),null());
		this->m_oContainer->addEventListener(::neash::events::MouseEvent_obj::DOUBLE_CLICK,this->_onInteraction_dyn(),null(),null(),null());
		this->m_oContainer->addEventListener(::neash::events::MouseEvent_obj::MOUSE_MOVE,this->_onInteraction_dyn(),null(),null(),null());
		this->m_oContainer->addEventListener(::neash::events::MouseEvent_obj::MOUSE_OVER,this->_onInteraction_dyn(),null(),null(),null());
		this->m_oContainer->addEventListener(::neash::events::MouseEvent_obj::MOUSE_OUT,this->_onInteraction_dyn(),null(),null(),null());
		this->m_oContainer->addEventListener(::neash::events::MouseEvent_obj::MOUSE_WHEEL,this->_onInteraction_dyn(),null(),null(),null());
	}
	else{
		if ((bool(!b) && bool(this->m_bEv))){
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
	}
	return b;
}


HX_DEFINE_DYNAMIC_FUNC1(Sprite2D_obj,__setEnableEvents,return )

Void Sprite2D_obj::_onInteraction( ::neash::events::Event p_oEvt){
{
		__SAFE_POINT
		this->m_oEB->dispatchEvent(::sandy::events::BubbleEvent_obj::__new(p_oEvt->type,this,null()));
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Sprite2D_obj,_onInteraction,(void))

::String Sprite2D_obj::toString( ){
	return (HX_STRING(L"sandy.core.scenegraph.Sprite2D, container:",42) + this->m_oContainer);
}


HX_DEFINE_DYNAMIC_FUNC0(Sprite2D_obj,toString,return )


Sprite2D_obj::Sprite2D_obj()
{
}

void Sprite2D_obj::__Mark()
{
	hx::MarkMember(fixedAngle);
	hx::MarkMember(autoCenter);
	hx::MarkMember(floorCenter);
	hx::MarkMember(v);
	hx::MarkMember(vx);
	hx::MarkMember(vy);
	hx::MarkMember(content);
	hx::MarkMember(container);
	hx::MarkMember(scale);
	hx::MarkMember(depth);
	hx::MarkMember(material);
	hx::MarkMember(enableForcedDepth);
	hx::MarkMember(forcedDepth);
	hx::MarkMember(enableEvents);
	hx::MarkMember(m_bEv);
	hx::MarkMember(m_nW2);
	hx::MarkMember(m_nH2);
	hx::MarkMember(m_oContainer);
	hx::MarkMember(m_nPerspScaleX);
	hx::MarkMember(m_nPerspScaleY);
	hx::MarkMember(m_nRotation);
	hx::MarkMember(m_nDepth);
	hx::MarkMember(_nScale);
	hx::MarkMember(m_oContent);
	hx::MarkMember(m_oMaterial);
	super::__Mark();
}

Dynamic Sprite2D_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 1:
		if (!memcmp(inName.__s,L"v",sizeof(wchar_t)*1) ) { return v; }
		break;
	case 2:
		if (!memcmp(inName.__s,L"vx",sizeof(wchar_t)*2) ) { return vx; }
		if (!memcmp(inName.__s,L"vy",sizeof(wchar_t)*2) ) { return vy; }
		break;
	case 4:
		if (!memcmp(inName.__s,L"cull",sizeof(wchar_t)*4) ) { return cull_dyn(); }
		break;
	case 5:
		if (!memcmp(inName.__s,L"scale",sizeof(wchar_t)*5) ) { return __getScale(); }
		if (!memcmp(inName.__s,L"depth",sizeof(wchar_t)*5) ) { return __getDepth(); }
		if (!memcmp(inName.__s,L"clear",sizeof(wchar_t)*5) ) { return clear_dyn(); }
		if (!memcmp(inName.__s,L"m_bEv",sizeof(wchar_t)*5) ) { return m_bEv; }
		if (!memcmp(inName.__s,L"m_nW2",sizeof(wchar_t)*5) ) { return m_nW2; }
		if (!memcmp(inName.__s,L"m_nH2",sizeof(wchar_t)*5) ) { return m_nH2; }
		break;
	case 6:
		if (!memcmp(inName.__s,L"remove",sizeof(wchar_t)*6) ) { return remove_dyn(); }
		break;
	case 7:
		if (!memcmp(inName.__s,L"content",sizeof(wchar_t)*7) ) { return __getContent(); }
		if (!memcmp(inName.__s,L"destroy",sizeof(wchar_t)*7) ) { return destroy_dyn(); }
		if (!memcmp(inName.__s,L"display",sizeof(wchar_t)*7) ) { return display_dyn(); }
		if (!memcmp(inName.__s,L"_nScale",sizeof(wchar_t)*7) ) { return _nScale; }
		break;
	case 8:
		if (!memcmp(inName.__s,L"material",sizeof(wchar_t)*8) ) { return __getMaterial(); }
		if (!memcmp(inName.__s,L"toString",sizeof(wchar_t)*8) ) { return toString_dyn(); }
		if (!memcmp(inName.__s,L"m_nDepth",sizeof(wchar_t)*8) ) { return m_nDepth; }
		break;
	case 9:
		if (!memcmp(inName.__s,L"container",sizeof(wchar_t)*9) ) { return __getContainer(); }
		break;
	case 10:
		if (!memcmp(inName.__s,L"fixedAngle",sizeof(wchar_t)*10) ) { return fixedAngle; }
		if (!memcmp(inName.__s,L"autoCenter",sizeof(wchar_t)*10) ) { return autoCenter; }
		if (!memcmp(inName.__s,L"__setScene",sizeof(wchar_t)*10) ) { return __setScene_dyn(); }
		if (!memcmp(inName.__s,L"__getScale",sizeof(wchar_t)*10) ) { return __getScale_dyn(); }
		if (!memcmp(inName.__s,L"__setScale",sizeof(wchar_t)*10) ) { return __setScale_dyn(); }
		if (!memcmp(inName.__s,L"__getDepth",sizeof(wchar_t)*10) ) { return __getDepth_dyn(); }
		if (!memcmp(inName.__s,L"__setDepth",sizeof(wchar_t)*10) ) { return __setDepth_dyn(); }
		if (!memcmp(inName.__s,L"m_oContent",sizeof(wchar_t)*10) ) { return m_oContent; }
		break;
	case 11:
		if (!memcmp(inName.__s,L"floorCenter",sizeof(wchar_t)*11) ) { return floorCenter; }
		if (!memcmp(inName.__s,L"forcedDepth",sizeof(wchar_t)*11) ) { return forcedDepth; }
		if (!memcmp(inName.__s,L"m_nRotation",sizeof(wchar_t)*11) ) { return m_nRotation; }
		if (!memcmp(inName.__s,L"m_oMaterial",sizeof(wchar_t)*11) ) { return m_oMaterial; }
		break;
	case 12:
		if (!memcmp(inName.__s,L"__getContent",sizeof(wchar_t)*12) ) { return __getContent_dyn(); }
		if (!memcmp(inName.__s,L"__setContent",sizeof(wchar_t)*12) ) { return __setContent_dyn(); }
		if (!memcmp(inName.__s,L"enableEvents",sizeof(wchar_t)*12) ) { return __getEnableEvents(); }
		if (!memcmp(inName.__s,L"m_oContainer",sizeof(wchar_t)*12) ) { return m_oContainer; }
		break;
	case 13:
		if (!memcmp(inName.__s,L"__getMaterial",sizeof(wchar_t)*13) ) { return __getMaterial_dyn(); }
		if (!memcmp(inName.__s,L"__setMaterial",sizeof(wchar_t)*13) ) { return __setMaterial_dyn(); }
		break;
	case 14:
		if (!memcmp(inName.__s,L"_beginMaterial",sizeof(wchar_t)*14) ) { return _beginMaterial_dyn(); }
		if (!memcmp(inName.__s,L"__getContainer",sizeof(wchar_t)*14) ) { return __getContainer_dyn(); }
		if (!memcmp(inName.__s,L"_onInteraction",sizeof(wchar_t)*14) ) { return _onInteraction_dyn(); }
		if (!memcmp(inName.__s,L"m_nPerspScaleX",sizeof(wchar_t)*14) ) { return m_nPerspScaleX; }
		if (!memcmp(inName.__s,L"m_nPerspScaleY",sizeof(wchar_t)*14) ) { return m_nPerspScaleY; }
		break;
	case 15:
		if (!memcmp(inName.__s,L"_finishMaterial",sizeof(wchar_t)*15) ) { return _finishMaterial_dyn(); }
		break;
	case 17:
		if (!memcmp(inName.__s,L"enableForcedDepth",sizeof(wchar_t)*17) ) { return enableForcedDepth; }
		if (!memcmp(inName.__s,L"__getEnableEvents",sizeof(wchar_t)*17) ) { return __getEnableEvents_dyn(); }
		if (!memcmp(inName.__s,L"__setEnableEvents",sizeof(wchar_t)*17) ) { return __setEnableEvents_dyn(); }
		break;
	case 23:
		if (!memcmp(inName.__s,L"setBoundingSphereRadius",sizeof(wchar_t)*23) ) { return setBoundingSphereRadius_dyn(); }
	}
	return super::__Field(inName);
}

Dynamic Sprite2D_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	switch(inName.length) {
	case 1:
		if (!memcmp(inName.__s,L"v",sizeof(wchar_t)*1) ) { v=inValue.Cast< ::sandy::core::data::Vertex >(); return inValue; }
		break;
	case 2:
		if (!memcmp(inName.__s,L"vx",sizeof(wchar_t)*2) ) { vx=inValue.Cast< ::sandy::core::data::Vertex >(); return inValue; }
		if (!memcmp(inName.__s,L"vy",sizeof(wchar_t)*2) ) { vy=inValue.Cast< ::sandy::core::data::Vertex >(); return inValue; }
		break;
	case 5:
		if (!memcmp(inName.__s,L"scale",sizeof(wchar_t)*5) ) { return __setScale(inValue); }
		if (!memcmp(inName.__s,L"depth",sizeof(wchar_t)*5) ) { return __setDepth(inValue); }
		if (!memcmp(inName.__s,L"m_bEv",sizeof(wchar_t)*5) ) { m_bEv=inValue.Cast< bool >(); return inValue; }
		if (!memcmp(inName.__s,L"m_nW2",sizeof(wchar_t)*5) ) { m_nW2=inValue.Cast< double >(); return inValue; }
		if (!memcmp(inName.__s,L"m_nH2",sizeof(wchar_t)*5) ) { m_nH2=inValue.Cast< double >(); return inValue; }
		break;
	case 7:
		if (!memcmp(inName.__s,L"content",sizeof(wchar_t)*7) ) { return __setContent(inValue); }
		if (!memcmp(inName.__s,L"_nScale",sizeof(wchar_t)*7) ) { _nScale=inValue.Cast< double >(); return inValue; }
		break;
	case 8:
		if (!memcmp(inName.__s,L"material",sizeof(wchar_t)*8) ) { return __setMaterial(inValue); }
		if (!memcmp(inName.__s,L"m_nDepth",sizeof(wchar_t)*8) ) { m_nDepth=inValue.Cast< double >(); return inValue; }
		break;
	case 9:
		if (!memcmp(inName.__s,L"container",sizeof(wchar_t)*9) ) { container=inValue.Cast< ::neash::display::Sprite >(); return inValue; }
		break;
	case 10:
		if (!memcmp(inName.__s,L"fixedAngle",sizeof(wchar_t)*10) ) { fixedAngle=inValue.Cast< bool >(); return inValue; }
		if (!memcmp(inName.__s,L"autoCenter",sizeof(wchar_t)*10) ) { autoCenter=inValue.Cast< bool >(); return inValue; }
		if (!memcmp(inName.__s,L"m_oContent",sizeof(wchar_t)*10) ) { m_oContent=inValue.Cast< ::neash::display::DisplayObject >(); return inValue; }
		break;
	case 11:
		if (!memcmp(inName.__s,L"floorCenter",sizeof(wchar_t)*11) ) { floorCenter=inValue.Cast< bool >(); return inValue; }
		if (!memcmp(inName.__s,L"forcedDepth",sizeof(wchar_t)*11) ) { forcedDepth=inValue.Cast< double >(); return inValue; }
		if (!memcmp(inName.__s,L"m_nRotation",sizeof(wchar_t)*11) ) { m_nRotation=inValue.Cast< double >(); return inValue; }
		if (!memcmp(inName.__s,L"m_oMaterial",sizeof(wchar_t)*11) ) { m_oMaterial=inValue.Cast< ::sandy::materials::Material >(); return inValue; }
		break;
	case 12:
		if (!memcmp(inName.__s,L"enableEvents",sizeof(wchar_t)*12) ) { return __setEnableEvents(inValue); }
		if (!memcmp(inName.__s,L"m_oContainer",sizeof(wchar_t)*12) ) { m_oContainer=inValue.Cast< ::neash::display::Sprite >(); return inValue; }
		break;
	case 14:
		if (!memcmp(inName.__s,L"m_nPerspScaleX",sizeof(wchar_t)*14) ) { m_nPerspScaleX=inValue.Cast< double >(); return inValue; }
		if (!memcmp(inName.__s,L"m_nPerspScaleY",sizeof(wchar_t)*14) ) { m_nPerspScaleY=inValue.Cast< double >(); return inValue; }
		break;
	case 17:
		if (!memcmp(inName.__s,L"enableForcedDepth",sizeof(wchar_t)*17) ) { enableForcedDepth=inValue.Cast< bool >(); return inValue; }
	}
	return super::__SetField(inName,inValue);
}

void Sprite2D_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_STRING(L"fixedAngle",10));
	outFields->push(HX_STRING(L"autoCenter",10));
	outFields->push(HX_STRING(L"floorCenter",11));
	outFields->push(HX_STRING(L"v",1));
	outFields->push(HX_STRING(L"vx",2));
	outFields->push(HX_STRING(L"vy",2));
	outFields->push(HX_STRING(L"content",7));
	outFields->push(HX_STRING(L"container",9));
	outFields->push(HX_STRING(L"scale",5));
	outFields->push(HX_STRING(L"depth",5));
	outFields->push(HX_STRING(L"material",8));
	outFields->push(HX_STRING(L"enableForcedDepth",17));
	outFields->push(HX_STRING(L"forcedDepth",11));
	outFields->push(HX_STRING(L"enableEvents",12));
	outFields->push(HX_STRING(L"m_bEv",5));
	outFields->push(HX_STRING(L"m_nW2",5));
	outFields->push(HX_STRING(L"m_nH2",5));
	outFields->push(HX_STRING(L"m_oContainer",12));
	outFields->push(HX_STRING(L"m_nPerspScaleX",14));
	outFields->push(HX_STRING(L"m_nPerspScaleY",14));
	outFields->push(HX_STRING(L"m_nRotation",11));
	outFields->push(HX_STRING(L"m_nDepth",8));
	outFields->push(HX_STRING(L"_nScale",7));
	outFields->push(HX_STRING(L"m_oContent",10));
	outFields->push(HX_STRING(L"m_oMaterial",11));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_STRING(L"fixedAngle",10),
	HX_STRING(L"autoCenter",10),
	HX_STRING(L"floorCenter",11),
	HX_STRING(L"v",1),
	HX_STRING(L"vx",2),
	HX_STRING(L"vy",2),
	HX_STRING(L"content",7),
	HX_STRING(L"__getContent",12),
	HX_STRING(L"__setContent",12),
	HX_STRING(L"__setScene",10),
	HX_STRING(L"_finishMaterial",15),
	HX_STRING(L"_beginMaterial",14),
	HX_STRING(L"container",9),
	HX_STRING(L"__getContainer",14),
	HX_STRING(L"setBoundingSphereRadius",23),
	HX_STRING(L"scale",5),
	HX_STRING(L"__getScale",10),
	HX_STRING(L"__setScale",10),
	HX_STRING(L"depth",5),
	HX_STRING(L"__getDepth",10),
	HX_STRING(L"__setDepth",10),
	HX_STRING(L"cull",4),
	HX_STRING(L"clear",5),
	HX_STRING(L"remove",6),
	HX_STRING(L"destroy",7),
	HX_STRING(L"display",7),
	HX_STRING(L"material",8),
	HX_STRING(L"__getMaterial",13),
	HX_STRING(L"__setMaterial",13),
	HX_STRING(L"enableForcedDepth",17),
	HX_STRING(L"forcedDepth",11),
	HX_STRING(L"enableEvents",12),
	HX_STRING(L"__getEnableEvents",17),
	HX_STRING(L"__setEnableEvents",17),
	HX_STRING(L"_onInteraction",14),
	HX_STRING(L"toString",8),
	HX_STRING(L"m_bEv",5),
	HX_STRING(L"m_nW2",5),
	HX_STRING(L"m_nH2",5),
	HX_STRING(L"m_oContainer",12),
	HX_STRING(L"m_nPerspScaleX",14),
	HX_STRING(L"m_nPerspScaleY",14),
	HX_STRING(L"m_nRotation",11),
	HX_STRING(L"m_nDepth",8),
	HX_STRING(L"_nScale",7),
	HX_STRING(L"m_oContent",10),
	HX_STRING(L"m_oMaterial",11),
	String(null()) };

static void sMarkStatics() {
};

Class Sprite2D_obj::__mClass;

void Sprite2D_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_STRING(L"sandy.core.scenegraph.Sprite2D",30), hx::TCanCast< Sprite2D_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void Sprite2D_obj::__boot()
{
}

} // end namespace sandy
} // end namespace core
} // end namespace scenegraph
