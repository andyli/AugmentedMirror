#ifndef INCLUDED_Main
#define INCLUDED_Main

#include <hxcpp.h>

#include <neash/display/Sprite.h>
HX_DECLARE_CLASS0(Main)
HX_DECLARE_CLASS2(neash,display,DisplayObject)
HX_DECLARE_CLASS2(neash,display,DisplayObjectContainer)
HX_DECLARE_CLASS2(neash,display,InteractiveObject)
HX_DECLARE_CLASS2(neash,display,Sprite)
HX_DECLARE_CLASS2(neash,events,Event)
HX_DECLARE_CLASS2(neash,events,EventDispatcher)
HX_DECLARE_CLASS2(neash,events,IEventDispatcher)
HX_DECLARE_CLASS2(neash,events,KeyboardEvent)
HX_DECLARE_CLASS2(neash,events,MouseEvent)
HX_DECLARE_CLASS2(nme,display,IBitmapDrawable)
HX_DECLARE_CLASS3(org,casalib,core,IDestroyable)
HX_DECLARE_CLASS3(org,casalib,events,IRemovableEventDispatcher)
HX_DECLARE_CLASS3(org,casalib,events,RemovableEventDispatcher)
HX_DECLARE_CLASS3(org,casalib,ui,Key)
HX_DECLARE_CLASS2(sandy,core,Scene3D)
HX_DECLARE_CLASS3(sandy,core,scenegraph,ATransformable)
HX_DECLARE_CLASS3(sandy,core,scenegraph,Camera3D)
HX_DECLARE_CLASS3(sandy,core,scenegraph,Group)
HX_DECLARE_CLASS3(sandy,core,scenegraph,IDisplayable)
HX_DECLARE_CLASS3(sandy,core,scenegraph,Node)
HX_DECLARE_CLASS3(sandy,core,scenegraph,Shape3D)
HX_DECLARE_CLASS3(sandy,core,scenegraph,TransformGroup)
HX_DECLARE_CLASS2(sandy,primitive,Cone)
HX_DECLARE_CLASS2(sandy,primitive,Cylinder)
HX_DECLARE_CLASS2(sandy,primitive,Plane3D)
HX_DECLARE_CLASS2(sandy,primitive,Primitive3D)


class Main_obj : public ::neash::display::Sprite_obj{
	public:
		typedef ::neash::display::Sprite_obj super;
		typedef Main_obj OBJ_;
		Main_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< Main_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~Main_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark();
		::String __ToString() const { return HX_STRING(L"Main",4); }

		::sandy::core::Scene3D scene; /* REM */ 
		::sandy::core::scenegraph::Camera3D camera; /* REM */ 
		::sandy::primitive::Cone camPos0; /* REM */ 
		::sandy::primitive::Cone camPos1; /* REM */ 
		::sandy::core::scenegraph::TransformGroup camT; /* REM */ 
		::sandy::core::scenegraph::Group sandyRoot; /* REM */ 
		::sandy::core::scenegraph::TransformGroup rootT; /* REM */ 
		::sandy::primitive::Plane3D realWorld; /* REM */ 
		::org::casalib::ui::Key key; /* REM */ 
		virtual Void initRoot( );
		Dynamic initRoot_dyn();

		virtual Void enterFrameHandler( ::neash::events::Event evt);
		Dynamic enterFrameHandler_dyn();

		virtual Void onMouseMove( ::neash::events::MouseEvent evt);
		Dynamic onMouseMove_dyn();

		virtual Void onKeyDown( ::neash::events::KeyboardEvent evt);
		Dynamic onKeyDown_dyn();

		static Void main( );
		static Dynamic main_dyn();

};


#endif /* INCLUDED_Main */ 
