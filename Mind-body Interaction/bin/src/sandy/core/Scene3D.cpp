#include <hxcpp.h>

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
#ifndef INCLUDED_nme_display_IBitmapDrawable
#include <nme/display/IBitmapDrawable.h>
#endif
#ifndef INCLUDED_sandy_core_Renderer
#include <sandy/core/Renderer.h>
#endif
#ifndef INCLUDED_sandy_core_Scene3D
#include <sandy/core/Scene3D.h>
#endif
#ifndef INCLUDED_sandy_core_SceneLocator
#include <sandy/core/SceneLocator.h>
#endif
#ifndef INCLUDED_sandy_core_data_Matrix4
#include <sandy/core/data/Matrix4.h>
#endif
#ifndef INCLUDED_sandy_core_data_Point3D
#include <sandy/core/data/Point3D.h>
#endif
#ifndef INCLUDED_sandy_core_data_Pool
#include <sandy/core/data/Pool.h>
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
#ifndef INCLUDED_sandy_core_scenegraph_Group
#include <sandy/core/scenegraph/Group.h>
#endif
#ifndef INCLUDED_sandy_core_scenegraph_Node
#include <sandy/core/scenegraph/Node.h>
#endif
#ifndef INCLUDED_sandy_events_SandyEvent
#include <sandy/events/SandyEvent.h>
#endif
#ifndef INCLUDED_sandy_view_Frustum
#include <sandy/view/Frustum.h>
#endif
#ifndef INCLUDED_sandy_view_ViewPort
#include <sandy/view/ViewPort.h>
#endif
namespace sandy{
namespace core{

Void Scene3D_obj::__construct(::String p_sName,::neash::display::Sprite p_oContainer,::sandy::core::scenegraph::Camera3D p_oCamera,::sandy::core::scenegraph::Group p_oRootNode)
{
{
	this->renderer = ::sandy::core::Renderer_obj::__new();
	this->m_bRectClipped = false;
	super::__construct(null());
	if ((p_sName != null())){
		if (::sandy::core::SceneLocator_obj::getInstance()->registerScene(p_sName,this)){
			this->container = p_oContainer;
			this->camera = p_oCamera;
			this->__setRoot(p_oRootNode);
			if ((bool((this->__getRoot() != null())) && bool((this->camera != null())))){
				if (!this->camera->hasParent())
					this->__getRoot()->addChild(this->camera);
			}
		}
		this->m_sName = p_sName;
	}
	this->__setLight(::sandy::core::light::Light3D_obj::__new(::sandy::core::data::Point3D_obj::__new(0,0,1),100));
	this->frameCount = 0;
}
;
	return null();
}

Scene3D_obj::~Scene3D_obj() { }

Dynamic Scene3D_obj::__CreateEmpty() { return  new Scene3D_obj; }
hx::ObjectPtr< Scene3D_obj > Scene3D_obj::__new(::String p_sName,::neash::display::Sprite p_oContainer,::sandy::core::scenegraph::Camera3D p_oCamera,::sandy::core::scenegraph::Group p_oRootNode)
{  hx::ObjectPtr< Scene3D_obj > result = new Scene3D_obj();
	result->__construct(p_sName,p_oContainer,p_oCamera,p_oRootNode);
	return result;}

Dynamic Scene3D_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Scene3D_obj > result = new Scene3D_obj();
	result->__construct(inArgs[0],inArgs[1],inArgs[2],inArgs[3]);
	return result;}

Void Scene3D_obj::render( Dynamic __o_p_bUseCache){
bool p_bUseCache = __o_p_bUseCache.Default(true);
{
		__SAFE_POINT
		if ((bool((this->__getRoot() != null())) && bool((bool((this->camera != null())) && bool((this->container != null())))))){
			::sandy::core::data::Pool_obj::getInstance()->init();
			this->renderer->init();
			this->dispatchEvent(::sandy::events::SandyEvent_obj::__new(HX_STRING(L"scene_update",12),null(),null()));
			this->__getRoot()->update(null(),false);
			this->dispatchEvent(::sandy::events::SandyEvent_obj::__new(HX_STRING(L"scene_cull",10),null(),null()));
			this->__getRoot()->cull(this->camera->frustrum,this->camera->invModelMatrix,this->camera->__getChanged());
			this->dispatchEvent(::sandy::events::SandyEvent_obj::__new(HX_STRING(L"scene_render",12),null(),null()));
			bool l_bNeedDraw = this->renderer->render(this,p_bUseCache);
			this->frameCount++;
			this->dispatchEvent(::sandy::events::SandyEvent_obj::__new(HX_STRING(L"scene_render_display_list",25),null(),null()));
			if (l_bNeedDraw){
				this->renderer->renderDisplayList(this);
				this->_light->changed = false;
			}
			this->dispatchEvent(::sandy::events::SandyEvent_obj::__new(HX_STRING(L"scene_render_finish",19),null(),null()));
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Scene3D_obj,render,(void))

::sandy::core::scenegraph::Group Scene3D_obj::__setRoot( ::sandy::core::scenegraph::Group p_oGroup){
	__SAFE_POINT
	if ((this->m_oRoot != null())){
		this->m_oRoot->__setScene(null());
		this->m_oRoot = null();
	}
	if ((p_oGroup != null())){
		this->m_oRoot = p_oGroup;
		this->m_oRoot->__setScene(this);
		if (!this->camera->hasParent())
			this->__getRoot()->addChild(this->camera);
	}
	return p_oGroup;
}


HX_DEFINE_DYNAMIC_FUNC1(Scene3D_obj,__setRoot,return )

::sandy::core::scenegraph::Group Scene3D_obj::__getRoot( ){
	return this->m_oRoot;
}


HX_DEFINE_DYNAMIC_FUNC0(Scene3D_obj,__getRoot,return )

bool Scene3D_obj::dispose( ){
	__SAFE_POINT
	::sandy::core::SceneLocator_obj::getInstance()->unregisterScene(this->m_sName);
	this->__getRoot()->destroy();
	if ((this->__getRoot() != null())){
		this->__getRoot()->destroy();
		this->__setRoot(null());
	}
	if ((this->camera != null())){
		this->camera = null();
	}
	if ((this->_light != null())){
		this->_light = null();
	}
	return true;
}


HX_DEFINE_DYNAMIC_FUNC0(Scene3D_obj,dispose,return )

::sandy::core::light::Light3D Scene3D_obj::__getLight( ){
	return this->_light;
}


HX_DEFINE_DYNAMIC_FUNC0(Scene3D_obj,__getLight,return )

::sandy::core::light::Light3D Scene3D_obj::__setLight( ::sandy::core::light::Light3D l){
	__SAFE_POINT
	if ((this->_light != null())){
		this->_light->destroy();
	}
	this->_light = l;
	this->dispatchEvent(::sandy::events::SandyEvent_obj::__new(HX_STRING(L"lightAdded",10),null(),null()));
	return l;
}


HX_DEFINE_DYNAMIC_FUNC1(Scene3D_obj,__setLight,return )

Void Scene3D_obj::_onLightUpdate( ::sandy::events::SandyEvent pEvt){
{
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Scene3D_obj,_onLightUpdate,(void))

bool Scene3D_obj::__getRectClipping( ){
	return this->m_bRectClipped;
}


HX_DEFINE_DYNAMIC_FUNC0(Scene3D_obj,__getRectClipping,return )

bool Scene3D_obj::__setRectClipping( bool p_bEnableClipping){
	this->m_bRectClipped = p_bEnableClipping;
	if ((this->camera != null())){
		this->camera->viewport->hasChanged = true;
	}
	return p_bEnableClipping;
}


HX_DEFINE_DYNAMIC_FUNC1(Scene3D_obj,__setRectClipping,return )

::String Scene3D_obj::__getName( ){
	return this->m_sName;
}


HX_DEFINE_DYNAMIC_FUNC0(Scene3D_obj,__getName,return )

::String Scene3D_obj::getVersion( ){
	return ::sandy::core::Scene3D_obj::_version;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(Scene3D_obj,getVersion,return )

::String Scene3D_obj::_version;


Scene3D_obj::Scene3D_obj()
{
}

void Scene3D_obj::__Mark()
{
	hx::MarkMember(camera);
	hx::MarkMember(container);
	hx::MarkMember(renderer);
	hx::MarkMember(frameCount);
	hx::MarkMember(root);
	hx::MarkMember(m_oRoot);
	hx::MarkMember(light);
	hx::MarkMember(rectClipping);
	hx::MarkMember(name);
	hx::MarkMember(m_sName);
	hx::MarkMember(m_bRectClipped);
	hx::MarkMember(_light);
	super::__Mark();
}

Dynamic Scene3D_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 4:
		if (!memcmp(inName.__s,L"root",sizeof(wchar_t)*4) ) { return __getRoot(); }
		if (!memcmp(inName.__s,L"name",sizeof(wchar_t)*4) ) { return __getName(); }
		break;
	case 5:
		if (!memcmp(inName.__s,L"light",sizeof(wchar_t)*5) ) { return __getLight(); }
		break;
	case 6:
		if (!memcmp(inName.__s,L"camera",sizeof(wchar_t)*6) ) { return camera; }
		if (!memcmp(inName.__s,L"render",sizeof(wchar_t)*6) ) { return render_dyn(); }
		if (!memcmp(inName.__s,L"_light",sizeof(wchar_t)*6) ) { return _light; }
		break;
	case 7:
		if (!memcmp(inName.__s,L"m_oRoot",sizeof(wchar_t)*7) ) { return m_oRoot; }
		if (!memcmp(inName.__s,L"dispose",sizeof(wchar_t)*7) ) { return dispose_dyn(); }
		if (!memcmp(inName.__s,L"m_sName",sizeof(wchar_t)*7) ) { return m_sName; }
		break;
	case 8:
		if (!memcmp(inName.__s,L"_version",sizeof(wchar_t)*8) ) { return _version; }
		if (!memcmp(inName.__s,L"renderer",sizeof(wchar_t)*8) ) { return renderer; }
		break;
	case 9:
		if (!memcmp(inName.__s,L"container",sizeof(wchar_t)*9) ) { return container; }
		if (!memcmp(inName.__s,L"__setRoot",sizeof(wchar_t)*9) ) { return __setRoot_dyn(); }
		if (!memcmp(inName.__s,L"__getRoot",sizeof(wchar_t)*9) ) { return __getRoot_dyn(); }
		if (!memcmp(inName.__s,L"__getName",sizeof(wchar_t)*9) ) { return __getName_dyn(); }
		break;
	case 10:
		if (!memcmp(inName.__s,L"getVersion",sizeof(wchar_t)*10) ) { return getVersion_dyn(); }
		if (!memcmp(inName.__s,L"frameCount",sizeof(wchar_t)*10) ) { return frameCount; }
		if (!memcmp(inName.__s,L"__getLight",sizeof(wchar_t)*10) ) { return __getLight_dyn(); }
		if (!memcmp(inName.__s,L"__setLight",sizeof(wchar_t)*10) ) { return __setLight_dyn(); }
		break;
	case 12:
		if (!memcmp(inName.__s,L"rectClipping",sizeof(wchar_t)*12) ) { return __getRectClipping(); }
		break;
	case 14:
		if (!memcmp(inName.__s,L"_onLightUpdate",sizeof(wchar_t)*14) ) { return _onLightUpdate_dyn(); }
		if (!memcmp(inName.__s,L"m_bRectClipped",sizeof(wchar_t)*14) ) { return m_bRectClipped; }
		break;
	case 17:
		if (!memcmp(inName.__s,L"__getRectClipping",sizeof(wchar_t)*17) ) { return __getRectClipping_dyn(); }
		if (!memcmp(inName.__s,L"__setRectClipping",sizeof(wchar_t)*17) ) { return __setRectClipping_dyn(); }
	}
	return super::__Field(inName);
}

Dynamic Scene3D_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	switch(inName.length) {
	case 4:
		if (!memcmp(inName.__s,L"root",sizeof(wchar_t)*4) ) { return __setRoot(inValue); }
		if (!memcmp(inName.__s,L"name",sizeof(wchar_t)*4) ) { name=inValue.Cast< ::String >(); return inValue; }
		break;
	case 5:
		if (!memcmp(inName.__s,L"light",sizeof(wchar_t)*5) ) { return __setLight(inValue); }
		break;
	case 6:
		if (!memcmp(inName.__s,L"camera",sizeof(wchar_t)*6) ) { camera=inValue.Cast< ::sandy::core::scenegraph::Camera3D >(); return inValue; }
		if (!memcmp(inName.__s,L"_light",sizeof(wchar_t)*6) ) { _light=inValue.Cast< ::sandy::core::light::Light3D >(); return inValue; }
		break;
	case 7:
		if (!memcmp(inName.__s,L"m_oRoot",sizeof(wchar_t)*7) ) { m_oRoot=inValue.Cast< ::sandy::core::scenegraph::Group >(); return inValue; }
		if (!memcmp(inName.__s,L"m_sName",sizeof(wchar_t)*7) ) { m_sName=inValue.Cast< ::String >(); return inValue; }
		break;
	case 8:
		if (!memcmp(inName.__s,L"_version",sizeof(wchar_t)*8) ) { _version=inValue.Cast< ::String >(); return inValue; }
		if (!memcmp(inName.__s,L"renderer",sizeof(wchar_t)*8) ) { renderer=inValue.Cast< ::sandy::core::Renderer >(); return inValue; }
		break;
	case 9:
		if (!memcmp(inName.__s,L"container",sizeof(wchar_t)*9) ) { container=inValue.Cast< ::neash::display::Sprite >(); return inValue; }
		break;
	case 10:
		if (!memcmp(inName.__s,L"frameCount",sizeof(wchar_t)*10) ) { frameCount=inValue.Cast< int >(); return inValue; }
		break;
	case 12:
		if (!memcmp(inName.__s,L"rectClipping",sizeof(wchar_t)*12) ) { return __setRectClipping(inValue); }
		break;
	case 14:
		if (!memcmp(inName.__s,L"m_bRectClipped",sizeof(wchar_t)*14) ) { m_bRectClipped=inValue.Cast< bool >(); return inValue; }
	}
	return super::__SetField(inName,inValue);
}

void Scene3D_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_STRING(L"camera",6));
	outFields->push(HX_STRING(L"container",9));
	outFields->push(HX_STRING(L"renderer",8));
	outFields->push(HX_STRING(L"frameCount",10));
	outFields->push(HX_STRING(L"root",4));
	outFields->push(HX_STRING(L"m_oRoot",7));
	outFields->push(HX_STRING(L"light",5));
	outFields->push(HX_STRING(L"rectClipping",12));
	outFields->push(HX_STRING(L"name",4));
	outFields->push(HX_STRING(L"m_sName",7));
	outFields->push(HX_STRING(L"m_bRectClipped",14));
	outFields->push(HX_STRING(L"_light",6));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_STRING(L"getVersion",10),
	HX_STRING(L"_version",8),
	String(null()) };

static ::String sMemberFields[] = {
	HX_STRING(L"camera",6),
	HX_STRING(L"container",9),
	HX_STRING(L"renderer",8),
	HX_STRING(L"frameCount",10),
	HX_STRING(L"render",6),
	HX_STRING(L"root",4),
	HX_STRING(L"m_oRoot",7),
	HX_STRING(L"__setRoot",9),
	HX_STRING(L"__getRoot",9),
	HX_STRING(L"dispose",7),
	HX_STRING(L"light",5),
	HX_STRING(L"__getLight",10),
	HX_STRING(L"__setLight",10),
	HX_STRING(L"_onLightUpdate",14),
	HX_STRING(L"rectClipping",12),
	HX_STRING(L"__getRectClipping",17),
	HX_STRING(L"__setRectClipping",17),
	HX_STRING(L"name",4),
	HX_STRING(L"__getName",9),
	HX_STRING(L"m_sName",7),
	HX_STRING(L"m_bRectClipped",14),
	HX_STRING(L"_light",6),
	String(null()) };

static void sMarkStatics() {
	hx::MarkMember(Scene3D_obj::_version);
};

Class Scene3D_obj::__mClass;

void Scene3D_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_STRING(L"sandy.core.Scene3D",18), hx::TCanCast< Scene3D_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void Scene3D_obj::__boot()
{
	hx::Static(_version) = HX_STRING(L"3.2",3);
}

} // end namespace sandy
} // end namespace core
