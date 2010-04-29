#ifndef INCLUDED_sandy_core_Scene3D
#define INCLUDED_sandy_core_Scene3D

#include <hxcpp.h>

#include <neash/events/EventDispatcher.h>
HX_DECLARE_CLASS2(neash,display,DisplayObject)
HX_DECLARE_CLASS2(neash,display,DisplayObjectContainer)
HX_DECLARE_CLASS2(neash,display,InteractiveObject)
HX_DECLARE_CLASS2(neash,display,Sprite)
HX_DECLARE_CLASS2(neash,events,Event)
HX_DECLARE_CLASS2(neash,events,EventDispatcher)
HX_DECLARE_CLASS2(neash,events,IEventDispatcher)
HX_DECLARE_CLASS2(nme,display,IBitmapDrawable)
HX_DECLARE_CLASS2(sandy,core,Renderer)
HX_DECLARE_CLASS2(sandy,core,Scene3D)
HX_DECLARE_CLASS3(sandy,core,light,Light3D)
HX_DECLARE_CLASS3(sandy,core,scenegraph,ATransformable)
HX_DECLARE_CLASS3(sandy,core,scenegraph,Camera3D)
HX_DECLARE_CLASS3(sandy,core,scenegraph,Group)
HX_DECLARE_CLASS3(sandy,core,scenegraph,Node)
HX_DECLARE_CLASS2(sandy,events,SandyEvent)
namespace sandy{
namespace core{


class Scene3D_obj : public ::neash::events::EventDispatcher_obj{
	public:
		typedef ::neash::events::EventDispatcher_obj super;
		typedef Scene3D_obj OBJ_;
		Scene3D_obj();
		Void __construct(::String p_sName,::neash::display::Sprite p_oContainer,::sandy::core::scenegraph::Camera3D p_oCamera,::sandy::core::scenegraph::Group p_oRootNode);

	public:
		static hx::ObjectPtr< Scene3D_obj > __new(::String p_sName,::neash::display::Sprite p_oContainer,::sandy::core::scenegraph::Camera3D p_oCamera,::sandy::core::scenegraph::Group p_oRootNode);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~Scene3D_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark();
		::String __ToString() const { return HX_STRING(L"Scene3D",7); }

		::sandy::core::scenegraph::Camera3D camera; /* REM */ 
		::neash::display::Sprite container; /* REM */ 
		::sandy::core::Renderer renderer; /* REM */ 
		int frameCount; /* REM */ 
		virtual Void render( Dynamic p_bUseCache);
		Dynamic render_dyn();

		::sandy::core::scenegraph::Group root; /* REM */ 
		::sandy::core::scenegraph::Group m_oRoot; /* REM */ 
		virtual ::sandy::core::scenegraph::Group __setRoot( ::sandy::core::scenegraph::Group p_oGroup);
		Dynamic __setRoot_dyn();

		virtual ::sandy::core::scenegraph::Group __getRoot( );
		Dynamic __getRoot_dyn();

		virtual bool dispose( );
		Dynamic dispose_dyn();

		::sandy::core::light::Light3D light; /* REM */ 
		virtual ::sandy::core::light::Light3D __getLight( );
		Dynamic __getLight_dyn();

		virtual ::sandy::core::light::Light3D __setLight( ::sandy::core::light::Light3D l);
		Dynamic __setLight_dyn();

		virtual Void _onLightUpdate( ::sandy::events::SandyEvent pEvt);
		Dynamic _onLightUpdate_dyn();

		bool rectClipping; /* REM */ 
		virtual bool __getRectClipping( );
		Dynamic __getRectClipping_dyn();

		virtual bool __setRectClipping( bool p_bEnableClipping);
		Dynamic __setRectClipping_dyn();

		::String name; /* REM */ 
		virtual ::String __getName( );
		Dynamic __getName_dyn();

		::String m_sName; /* REM */ 
		bool m_bRectClipped; /* REM */ 
		::sandy::core::light::Light3D _light; /* REM */ 
		static ::String getVersion( );
		static Dynamic getVersion_dyn();

		static ::String _version; /* REM */ 
};

} // end namespace sandy
} // end namespace core

#endif /* INCLUDED_sandy_core_Scene3D */ 
