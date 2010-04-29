#include <hxcpp.h>

#ifndef INCLUDED_CameraUpdater
#include <CameraUpdater.h>
#endif
#ifndef INCLUDED_IntHash
#include <IntHash.h>
#endif
#ifndef INCLUDED_Main
#include <Main.h>
#endif
#ifndef INCLUDED_PlaneUpdater
#include <PlaneUpdater.h>
#endif
#ifndef INCLUDED_ThreadedCmd
#include <ThreadedCmd.h>
#endif
#ifndef INCLUDED_Updater
#include <Updater.h>
#endif
#ifndef INCLUDED_cpp_Sys
#include <cpp/Sys.h>
#endif
#ifndef INCLUDED_haxe_Log
#include <haxe/Log.h>
#endif
#ifndef INCLUDED_neash_Lib
#include <neash/Lib.h>
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
#ifndef INCLUDED_neash_display_MovieClip
#include <neash/display/MovieClip.h>
#endif
#ifndef INCLUDED_neash_display_Sprite
#include <neash/display/Sprite.h>
#endif
#ifndef INCLUDED_neash_display_Stage
#include <neash/display/Stage.h>
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
#ifndef INCLUDED_neash_text_KeyCode
#include <neash/text/KeyCode.h>
#endif
#ifndef INCLUDED_nme_display_Graphics
#include <nme/display/Graphics.h>
#endif
#ifndef INCLUDED_nme_display_IBitmapDrawable
#include <nme/display/IBitmapDrawable.h>
#endif
#ifndef INCLUDED_org_casalib_core_IDestroyable
#include <org/casalib/core/IDestroyable.h>
#endif
#ifndef INCLUDED_org_casalib_events_IRemovableEventDispatcher
#include <org/casalib/events/IRemovableEventDispatcher.h>
#endif
#ifndef INCLUDED_org_casalib_events_RemovableEventDispatcher
#include <org/casalib/events/RemovableEventDispatcher.h>
#endif
#ifndef INCLUDED_org_casalib_ui_Key
#include <org/casalib/ui/Key.h>
#endif
#ifndef INCLUDED_org_casalib_util_StageReference
#include <org/casalib/util/StageReference.h>
#endif
#ifndef INCLUDED_sandy_core_Scene3D
#include <sandy/core/Scene3D.h>
#endif
#ifndef INCLUDED_sandy_core_data_Point3D
#include <sandy/core/data/Point3D.h>
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
#ifndef INCLUDED_sandy_core_scenegraph_IDisplayable
#include <sandy/core/scenegraph/IDisplayable.h>
#endif
#ifndef INCLUDED_sandy_core_scenegraph_Node
#include <sandy/core/scenegraph/Node.h>
#endif
#ifndef INCLUDED_sandy_core_scenegraph_Shape3D
#include <sandy/core/scenegraph/Shape3D.h>
#endif
#ifndef INCLUDED_sandy_core_scenegraph_TransformGroup
#include <sandy/core/scenegraph/TransformGroup.h>
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
#ifndef INCLUDED_sandy_primitive_Cone
#include <sandy/primitive/Cone.h>
#endif
#ifndef INCLUDED_sandy_primitive_Cylinder
#include <sandy/primitive/Cylinder.h>
#endif
#ifndef INCLUDED_sandy_primitive_Line3D
#include <sandy/primitive/Line3D.h>
#endif
#ifndef INCLUDED_sandy_primitive_Plane3D
#include <sandy/primitive/Plane3D.h>
#endif
#ifndef INCLUDED_sandy_primitive_Primitive3D
#include <sandy/primitive/Primitive3D.h>
#endif

Void Main_obj::__construct()
{
{
	super::__construct();
	::org::casalib::util::StageReference_obj::setStage(::neash::Lib_obj::GetCurrent()->GetStage(),null());
	this->GetGraphics()->beginFill(16777215,1);
	this->GetGraphics()->drawRect(0,0,768,1024);
	this->GetGraphics()->endFill();
	this->camera = ::sandy::core::scenegraph::Camera3D_obj::__new(600,800,45,0,100000000);
	this->camera->__setX(10);
	this->camera->__setY(10);
	this->camera->__setZ(-300);
	this->camera->lookAt(0,0,0);
	this->initRoot();
	this->scene = ::sandy::core::Scene3D_obj::__new(HX_STRING(L"scene",5),this,this->camera,this->sandyRoot);
	this->addEventListener(::neash::events::Event_obj::ENTER_FRAME,this->enterFrameHandler_dyn(),null(),null(),null());
	this->addEventListener(::neash::events::MouseEvent_obj::MOUSE_MOVE,this->onMouseMove_dyn(),null(),null(),null());
	struct _Function_1_1{
		inline static ::org::casalib::ui::Key Block( )/* DEF (ret block)(not intern) */{
			if ((::org::casalib::ui::Key_obj::_instance == null()))
				::org::casalib::ui::Key_obj::_instance = ::org::casalib::ui::Key_obj::__new();
			return ::org::casalib::ui::Key_obj::_instance;
		}
	};
	this->key = _Function_1_1::Block();
	this->key->addEventListener(::neash::events::KeyboardEvent_obj::KEY_DOWN,this->onKeyDown_dyn(),null(),null(),null());
	::cpp::Sys_obj::setCwd(HX_STRING(L"helper",6));
	::ThreadedCmd_obj::run(HX_STRING(L"./openHelpers.sh",16));
	::cpp::Sys_obj::sleep(1);
	::cpp::Sys_obj::setCwd(HX_STRING(L"..",2));
	::PlaneUpdater_obj::__new(this->realWorld,HX_STRING(L"127.0.0.1:11999",15),null())->start();
	::CameraUpdater_obj::__new(this->camPos0,this->camPos1,HX_STRING(L"127.0.0.1:11998",15),null())->start();
}
;
	return null();
}

Main_obj::~Main_obj() { }

Dynamic Main_obj::__CreateEmpty() { return  new Main_obj; }
hx::ObjectPtr< Main_obj > Main_obj::__new()
{  hx::ObjectPtr< Main_obj > result = new Main_obj();
	result->__construct();
	return result;}

Dynamic Main_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Main_obj > result = new Main_obj();
	result->__construct();
	return result;}

Void Main_obj::initRoot( ){
{
		__SAFE_POINT
		this->sandyRoot = ::sandy::core::scenegraph::Group_obj::__new(null());
		::sandy::materials::Material material;
		::sandy::materials::attributes::MaterialAttributes materialAttr;
		::sandy::materials::Appearance appearance;
		::sandy::primitive::Line3D myXLine = ::sandy::primitive::Line3D_obj::__new(HX_STRING(L"x-coord",7),Array_obj< ::sandy::core::data::Point3D >::__new().Add(::sandy::core::data::Point3D_obj::__new(-50,0,0)).Add(::sandy::core::data::Point3D_obj::__new(50,0,0)));
		::sandy::primitive::Line3D myYLine = ::sandy::primitive::Line3D_obj::__new(HX_STRING(L"y-coord",7),Array_obj< ::sandy::core::data::Point3D >::__new().Add(::sandy::core::data::Point3D_obj::__new(0,-50,0)).Add(::sandy::core::data::Point3D_obj::__new(0,50,0)));
		::sandy::primitive::Line3D myZLine = ::sandy::primitive::Line3D_obj::__new(HX_STRING(L"z-coord",7),Array_obj< ::sandy::core::data::Point3D >::__new().Add(::sandy::core::data::Point3D_obj::__new(0,0,-50)).Add(::sandy::core::data::Point3D_obj::__new(0,0,50)));
		material = ::sandy::materials::WireFrameMaterial_obj::__new(1,16777215,null(),null());
		appearance = ::sandy::materials::Appearance_obj::__new(material,null());
		myXLine->__setAppearance(appearance);
		myYLine->__setAppearance(appearance);
		myZLine->__setAppearance(appearance);
		this->sandyRoot->addChild(myXLine);
		this->sandyRoot->addChild(myYLine);
		this->sandyRoot->addChild(myZLine);
		this->realWorld = ::sandy::primitive::Plane3D_obj::__new(HX_STRING(L"plane",5),240,320,31,23,null(),null());
		this->realWorld->__setEnableBackFaceCulling(false);
		this->camPos0 = ::sandy::primitive::Cone_obj::__new(HX_STRING(L"camPos0",7),2,4,null(),null());
		this->camPos1 = ::sandy::primitive::Cone_obj::__new(HX_STRING(L"camPos1",7),2,4,null(),null());
		this->rootT = ::sandy::core::scenegraph::TransformGroup_obj::__new(null());
		this->rootT->addChild(this->realWorld);
		this->camT = ::sandy::core::scenegraph::TransformGroup_obj::__new(null());
		this->camT->addChild(this->camPos0);
		this->camT->addChild(this->camPos1);
		this->rootT->addChild(this->camT);
		this->rootT->__setScaleZ(-2);
		this->rootT->__setX(0);
		this->rootT->__setY(70);
		this->rootT->__setX(0);
		this->rootT->__setRotateX(60);
		this->rootT->__setRotateY(0);
		this->rootT->__setRotateZ(0);
		this->sandyRoot->addChild(this->rootT);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Main_obj,initRoot,(void))

Void Main_obj::enterFrameHandler( ::neash::events::Event evt){
{
		__SAFE_POINT
		if (!this->key->_keysDown->get(::neash::text::KeyCode_obj::ENTER).Cast< bool >()){
			this->camera->__setX(0);
			this->camera->__setY(0);
			this->camera->lookAt(0,0,0);
		}
		this->scene->render(false);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Main_obj,enterFrameHandler,(void))

Void Main_obj::onMouseMove( ::neash::events::MouseEvent evt){
{
		__SAFE_POINT
		if (this->key->_keysDown->get(::neash::text::KeyCode_obj::ENTER).Cast< bool >()){
			this->camera->__setX((-1000 + (2000 * ((double((evt->stageX)) / double((::org::casalib::util::StageReference_obj::getStage(null())->GetStageWidth())))))));
			this->camera->__setY((1000 + (-2000 * ((double((evt->stageY)) / double((::org::casalib::util::StageReference_obj::getStage(null())->GetStageHeight())))))));
			this->camera->lookAt(0,0,0);
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Main_obj,onMouseMove,(void))

Void Main_obj::onKeyDown( ::neash::events::KeyboardEvent evt){
{
		__SAFE_POINT
		int _switch_1 = (evt->keyCode);
		if (  ( _switch_1==::neash::text::KeyCode_obj::UP)){
			{
				::sandy::core::scenegraph::Camera3D _g = this->camera;
				_g->__setZ((_g->__getZ() + 10));
			}
		}
		else if (  ( _switch_1==::neash::text::KeyCode_obj::DOWN)){
			{
				::sandy::core::scenegraph::Camera3D _g = this->camera;
				_g->__setZ((_g->__getZ() - 10));
			}
		}
		else if (  ( _switch_1==::neash::text::KeyCode_obj::SPACE)){
			struct _Function_2_1{
				inline static Dynamic Block( ){
					hx::Anon __result = hx::Anon_obj::Create();
					__result->Add(HX_STRING(L"fileName",8) , HX_STRING(L"Main.hx",7));
					__result->Add(HX_STRING(L"lineNumber",10) , 156);
					__result->Add(HX_STRING(L"className",9) , HX_STRING(L"Main",4));
					__result->Add(HX_STRING(L"methodName",10) , HX_STRING(L"onKeyDown",9));
					return __result;
				}
			};
			::haxe::Log_obj::trace((HX_STRING(L"x = ",4) + this->rootT->__getX()),_Function_2_1::Block());
			struct _Function_2_2{
				inline static Dynamic Block( ){
					hx::Anon __result = hx::Anon_obj::Create();
					__result->Add(HX_STRING(L"fileName",8) , HX_STRING(L"Main.hx",7));
					__result->Add(HX_STRING(L"lineNumber",10) , 157);
					__result->Add(HX_STRING(L"className",9) , HX_STRING(L"Main",4));
					__result->Add(HX_STRING(L"methodName",10) , HX_STRING(L"onKeyDown",9));
					return __result;
				}
			};
			::haxe::Log_obj::trace((HX_STRING(L"y = ",4) + this->rootT->__getY()),_Function_2_2::Block());
			struct _Function_2_3{
				inline static Dynamic Block( ){
					hx::Anon __result = hx::Anon_obj::Create();
					__result->Add(HX_STRING(L"fileName",8) , HX_STRING(L"Main.hx",7));
					__result->Add(HX_STRING(L"lineNumber",10) , 158);
					__result->Add(HX_STRING(L"className",9) , HX_STRING(L"Main",4));
					__result->Add(HX_STRING(L"methodName",10) , HX_STRING(L"onKeyDown",9));
					return __result;
				}
			};
			::haxe::Log_obj::trace((HX_STRING(L"z = ",4) + this->rootT->__getZ()),_Function_2_3::Block());
			struct _Function_2_4{
				inline static Dynamic Block( ){
					hx::Anon __result = hx::Anon_obj::Create();
					__result->Add(HX_STRING(L"fileName",8) , HX_STRING(L"Main.hx",7));
					__result->Add(HX_STRING(L"lineNumber",10) , 159);
					__result->Add(HX_STRING(L"className",9) , HX_STRING(L"Main",4));
					__result->Add(HX_STRING(L"methodName",10) , HX_STRING(L"onKeyDown",9));
					return __result;
				}
			};
			::haxe::Log_obj::trace((HX_STRING(L"rotateX = ",10) + this->rootT->__getRotateX()),_Function_2_4::Block());
			struct _Function_2_5{
				inline static Dynamic Block( ){
					hx::Anon __result = hx::Anon_obj::Create();
					__result->Add(HX_STRING(L"fileName",8) , HX_STRING(L"Main.hx",7));
					__result->Add(HX_STRING(L"lineNumber",10) , 160);
					__result->Add(HX_STRING(L"className",9) , HX_STRING(L"Main",4));
					__result->Add(HX_STRING(L"methodName",10) , HX_STRING(L"onKeyDown",9));
					return __result;
				}
			};
			::haxe::Log_obj::trace((HX_STRING(L"rotateY = ",10) + this->rootT->__getRotateY()),_Function_2_5::Block());
			struct _Function_2_6{
				inline static Dynamic Block( ){
					hx::Anon __result = hx::Anon_obj::Create();
					__result->Add(HX_STRING(L"fileName",8) , HX_STRING(L"Main.hx",7));
					__result->Add(HX_STRING(L"lineNumber",10) , 161);
					__result->Add(HX_STRING(L"className",9) , HX_STRING(L"Main",4));
					__result->Add(HX_STRING(L"methodName",10) , HX_STRING(L"onKeyDown",9));
					return __result;
				}
			};
			::haxe::Log_obj::trace((HX_STRING(L"rotateZ = ",10) + this->rootT->__getRotateZ()),_Function_2_6::Block());
		}
		else  {
		}
;
;
		::sandy::core::scenegraph::TransformGroup transformGroup = this->camT;
		int _switch_2 = (evt->charCode);
		if (  ( _switch_2==HX_STRING(L"a",1).charCodeAt(0))){
			{
				::sandy::core::scenegraph::TransformGroup _g = transformGroup;
				_g->__setZ((_g->__getZ() + 10));
			}
		}
		else if (  ( _switch_2==HX_STRING(L"q",1).charCodeAt(0))){
			{
				::sandy::core::scenegraph::TransformGroup _g = transformGroup;
				_g->__setZ((_g->__getZ() - 10));
			}
		}
		else if (  ( _switch_2==HX_STRING(L"w",1).charCodeAt(0))){
			{
				::sandy::core::scenegraph::TransformGroup _g = transformGroup;
				_g->__setRotateX((_g->__getRotateX() + 5));
			}
		}
		else if (  ( _switch_2==HX_STRING(L"s",1).charCodeAt(0))){
			{
				::sandy::core::scenegraph::TransformGroup _g = transformGroup;
				_g->__setRotateX((_g->__getRotateX() - 5));
			}
		}
		else if (  ( _switch_2==HX_STRING(L"e",1).charCodeAt(0))){
			{
				::sandy::core::scenegraph::TransformGroup _g = transformGroup;
				_g->__setY((_g->__getY() + 10));
			}
		}
		else if (  ( _switch_2==HX_STRING(L"d",1).charCodeAt(0))){
			{
				::sandy::core::scenegraph::TransformGroup _g = transformGroup;
				_g->__setY((_g->__getY() - 10));
			}
		}
		else  {
		}
;
;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Main_obj,onKeyDown,(void))

Void Main_obj::main( ){
{
		__SAFE_POINT
		::neash::Lib_obj::Init(HX_STRING(L"Mind-Body Interaction",21),600,800,null(),null(),null());
		::neash::Lib_obj::GetCurrent()->addChild(::Main_obj::__new());
		::neash::Lib_obj::Run();
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(Main_obj,main,(void))


Main_obj::Main_obj()
{
}

void Main_obj::__Mark()
{
	hx::MarkMember(scene);
	hx::MarkMember(camera);
	hx::MarkMember(camPos0);
	hx::MarkMember(camPos1);
	hx::MarkMember(camT);
	hx::MarkMember(sandyRoot);
	hx::MarkMember(rootT);
	hx::MarkMember(realWorld);
	hx::MarkMember(key);
	super::__Mark();
}

Dynamic Main_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 3:
		if (!memcmp(inName.__s,L"key",sizeof(wchar_t)*3) ) { return key; }
		break;
	case 4:
		if (!memcmp(inName.__s,L"main",sizeof(wchar_t)*4) ) { return main_dyn(); }
		if (!memcmp(inName.__s,L"camT",sizeof(wchar_t)*4) ) { return camT; }
		break;
	case 5:
		if (!memcmp(inName.__s,L"scene",sizeof(wchar_t)*5) ) { return scene; }
		if (!memcmp(inName.__s,L"rootT",sizeof(wchar_t)*5) ) { return rootT; }
		break;
	case 6:
		if (!memcmp(inName.__s,L"camera",sizeof(wchar_t)*6) ) { return camera; }
		break;
	case 7:
		if (!memcmp(inName.__s,L"camPos0",sizeof(wchar_t)*7) ) { return camPos0; }
		if (!memcmp(inName.__s,L"camPos1",sizeof(wchar_t)*7) ) { return camPos1; }
		break;
	case 8:
		if (!memcmp(inName.__s,L"initRoot",sizeof(wchar_t)*8) ) { return initRoot_dyn(); }
		break;
	case 9:
		if (!memcmp(inName.__s,L"sandyRoot",sizeof(wchar_t)*9) ) { return sandyRoot; }
		if (!memcmp(inName.__s,L"realWorld",sizeof(wchar_t)*9) ) { return realWorld; }
		if (!memcmp(inName.__s,L"onKeyDown",sizeof(wchar_t)*9) ) { return onKeyDown_dyn(); }
		break;
	case 11:
		if (!memcmp(inName.__s,L"onMouseMove",sizeof(wchar_t)*11) ) { return onMouseMove_dyn(); }
		break;
	case 17:
		if (!memcmp(inName.__s,L"enterFrameHandler",sizeof(wchar_t)*17) ) { return enterFrameHandler_dyn(); }
	}
	return super::__Field(inName);
}

Dynamic Main_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	switch(inName.length) {
	case 3:
		if (!memcmp(inName.__s,L"key",sizeof(wchar_t)*3) ) { key=inValue.Cast< ::org::casalib::ui::Key >(); return inValue; }
		break;
	case 4:
		if (!memcmp(inName.__s,L"camT",sizeof(wchar_t)*4) ) { camT=inValue.Cast< ::sandy::core::scenegraph::TransformGroup >(); return inValue; }
		break;
	case 5:
		if (!memcmp(inName.__s,L"scene",sizeof(wchar_t)*5) ) { scene=inValue.Cast< ::sandy::core::Scene3D >(); return inValue; }
		if (!memcmp(inName.__s,L"rootT",sizeof(wchar_t)*5) ) { rootT=inValue.Cast< ::sandy::core::scenegraph::TransformGroup >(); return inValue; }
		break;
	case 6:
		if (!memcmp(inName.__s,L"camera",sizeof(wchar_t)*6) ) { camera=inValue.Cast< ::sandy::core::scenegraph::Camera3D >(); return inValue; }
		break;
	case 7:
		if (!memcmp(inName.__s,L"camPos0",sizeof(wchar_t)*7) ) { camPos0=inValue.Cast< ::sandy::primitive::Cone >(); return inValue; }
		if (!memcmp(inName.__s,L"camPos1",sizeof(wchar_t)*7) ) { camPos1=inValue.Cast< ::sandy::primitive::Cone >(); return inValue; }
		break;
	case 9:
		if (!memcmp(inName.__s,L"sandyRoot",sizeof(wchar_t)*9) ) { sandyRoot=inValue.Cast< ::sandy::core::scenegraph::Group >(); return inValue; }
		if (!memcmp(inName.__s,L"realWorld",sizeof(wchar_t)*9) ) { realWorld=inValue.Cast< ::sandy::primitive::Plane3D >(); return inValue; }
	}
	return super::__SetField(inName,inValue);
}

void Main_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_STRING(L"scene",5));
	outFields->push(HX_STRING(L"camera",6));
	outFields->push(HX_STRING(L"camPos0",7));
	outFields->push(HX_STRING(L"camPos1",7));
	outFields->push(HX_STRING(L"camT",4));
	outFields->push(HX_STRING(L"sandyRoot",9));
	outFields->push(HX_STRING(L"rootT",5));
	outFields->push(HX_STRING(L"realWorld",9));
	outFields->push(HX_STRING(L"key",3));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_STRING(L"main",4),
	String(null()) };

static ::String sMemberFields[] = {
	HX_STRING(L"scene",5),
	HX_STRING(L"camera",6),
	HX_STRING(L"camPos0",7),
	HX_STRING(L"camPos1",7),
	HX_STRING(L"camT",4),
	HX_STRING(L"sandyRoot",9),
	HX_STRING(L"rootT",5),
	HX_STRING(L"realWorld",9),
	HX_STRING(L"key",3),
	HX_STRING(L"initRoot",8),
	HX_STRING(L"enterFrameHandler",17),
	HX_STRING(L"onMouseMove",11),
	HX_STRING(L"onKeyDown",9),
	String(null()) };

static void sMarkStatics() {
};

Class Main_obj::__mClass;

void Main_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_STRING(L"Main",4), hx::TCanCast< Main_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void Main_obj::__boot()
{
}

