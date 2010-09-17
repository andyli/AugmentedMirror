#ifndef INCLUDED_sandy_core_interaction_VirtualMouse
#define INCLUDED_sandy_core_interaction_VirtualMouse

#include <hxcpp.h>

#include <neash/events/EventDispatcher.h>
HX_DECLARE_CLASS2(neash,display,DisplayObject)
HX_DECLARE_CLASS2(neash,display,DisplayObjectContainer)
HX_DECLARE_CLASS2(neash,display,InteractiveObject)
HX_DECLARE_CLASS2(neash,display,Sprite)
HX_DECLARE_CLASS2(neash,events,Event)
HX_DECLARE_CLASS2(neash,events,EventDispatcher)
HX_DECLARE_CLASS2(neash,events,IEventDispatcher)
HX_DECLARE_CLASS2(neash,events,MouseEvent)
HX_DECLARE_CLASS2(neash,text,NeashText)
HX_DECLARE_CLASS2(nme,display,IBitmapDrawable)
HX_DECLARE_CLASS2(nme,geom,Point)
HX_DECLARE_CLASS3(sandy,core,data,Polygon)
HX_DECLARE_CLASS3(sandy,core,data,UVCoord)
HX_DECLARE_CLASS3(sandy,core,interaction,PrivateConstructorAccess)
HX_DECLARE_CLASS3(sandy,core,interaction,VirtualMouse)
HX_DECLARE_CLASS3(sandy,core,scenegraph,IDisplayable)
namespace sandy{
namespace core{
namespace interaction{


class VirtualMouse_obj : public ::neash::events::EventDispatcher_obj{
	public:
		typedef ::neash::events::EventDispatcher_obj super;
		typedef VirtualMouse_obj OBJ_;
		VirtualMouse_obj();
		Void __construct(::sandy::core::interaction::PrivateConstructorAccess access);

	public:
		static hx::ObjectPtr< VirtualMouse_obj > __new(::sandy::core::interaction::PrivateConstructorAccess access);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~VirtualMouse_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark();
		::String __ToString() const { return HX_STRING(L"VirtualMouse",12); }

		::neash::display::Sprite m_ioTarget; /* REM */ 
		::neash::display::Sprite m_ioOldTarget; /* REM */ 
		::nme::geom::Point location; /* REM */ 
		::nme::geom::Point lastLocation; /* REM */ 
		bool lastWithinStage; /* REM */ 
		::neash::events::Event _lastEvent; /* REM */ 
		::neash::display::InteractiveObject lastDownTarget; /* REM */ 
		Array< ::neash::display::InteractiveObject > m_oPreviousTargets; /* REM */ 
		Array< ::neash::display::InteractiveObject > m_oCurrentTargets; /* REM */ 
		virtual Void interactWithTexture( ::sandy::core::data::Polygon p_oPoly,::sandy::core::data::UVCoord p_uvTexture,::neash::events::MouseEvent p_event);
		Dynamic interactWithTexture_dyn();

		virtual Void _checkLinks( ::neash::text::NeashText tf);
		Dynamic _checkLinks_dyn();

		static ::sandy::core::interaction::VirtualMouse _oI; /* REM */ 
		static ::sandy::core::interaction::VirtualMouse getInstance( );
		static Dynamic getInstance_dyn();

};

} // end namespace sandy
} // end namespace core
} // end namespace interaction

#endif /* INCLUDED_sandy_core_interaction_VirtualMouse */ 
