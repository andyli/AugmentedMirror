#ifndef INCLUDED_org_casalib_ui_Key
#define INCLUDED_org_casalib_ui_Key

#include <hxcpp.h>

#include <org/casalib/events/RemovableEventDispatcher.h>
HX_DECLARE_CLASS0(IntHash)
HX_DECLARE_CLASS2(neash,events,Event)
HX_DECLARE_CLASS2(neash,events,EventDispatcher)
HX_DECLARE_CLASS2(neash,events,IEventDispatcher)
HX_DECLARE_CLASS2(neash,events,KeyboardEvent)
HX_DECLARE_CLASS3(org,casalib,core,IDestroyable)
HX_DECLARE_CLASS3(org,casalib,events,IRemovableEventDispatcher)
HX_DECLARE_CLASS3(org,casalib,events,RemovableEventDispatcher)
HX_DECLARE_CLASS3(org,casalib,ui,Key)
HX_DECLARE_CLASS3(org,casalib,ui,KeyCombo)
namespace org{
namespace casalib{
namespace ui{


class Key_obj : public ::org::casalib::events::RemovableEventDispatcher_obj{
	public:
		typedef ::org::casalib::events::RemovableEventDispatcher_obj super;
		typedef Key_obj OBJ_;
		Key_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< Key_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~Key_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark();
		::String __ToString() const { return HX_STRING(L"Key",3); }

		::IntHash _keysDown; /* REM */ 
		Array< int > _keysTyped; /* REM */ 
		Array< ::org::casalib::ui::KeyCombo > _combosDown; /* REM */ 
		Array< ::org::casalib::ui::KeyCombo > _combinations; /* REM */ 
		int _longestCombo; /* REM */ 
		virtual bool isDown( int keyCode);
		Dynamic isDown_dyn();

		virtual Void addKeyCombo( ::org::casalib::ui::KeyCombo keyCombo);
		Dynamic addKeyCombo_dyn();

		virtual Void removeKeyCombo( ::org::casalib::ui::KeyCombo keyCombo);
		Dynamic removeKeyCombo_dyn();

		virtual Void destroy( );
		Dynamic destroy_dyn();

		virtual Void _onKeyDown( ::neash::events::KeyboardEvent e);
		Dynamic _onKeyDown_dyn();

		virtual Void _onKeyUp( ::neash::events::KeyboardEvent e);
		Dynamic _onKeyUp_dyn();

		virtual Void _onDeactivate( ::neash::events::Event e);
		Dynamic _onDeactivate_dyn();

		virtual Void _checkedTypedKeys( ::org::casalib::ui::KeyCombo keyCombo);
		Dynamic _checkedTypedKeys_dyn();

		virtual Void _checkDownKeys( ::org::casalib::ui::KeyCombo keyCombo);
		Dynamic _checkDownKeys_dyn();

		static ::org::casalib::ui::Key _instance; /* REM */ 
		static ::org::casalib::ui::Key getInstance( );
		static Dynamic getInstance_dyn();

};

} // end namespace org
} // end namespace casalib
} // end namespace ui

#endif /* INCLUDED_org_casalib_ui_Key */ 
