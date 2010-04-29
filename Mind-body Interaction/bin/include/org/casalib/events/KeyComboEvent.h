#ifndef INCLUDED_org_casalib_events_KeyComboEvent
#define INCLUDED_org_casalib_events_KeyComboEvent

#include <hxcpp.h>

#include <neash/events/Event.h>
HX_DECLARE_CLASS2(neash,events,Event)
HX_DECLARE_CLASS3(org,casalib,events,KeyComboEvent)
HX_DECLARE_CLASS3(org,casalib,ui,KeyCombo)
namespace org{
namespace casalib{
namespace events{


class KeyComboEvent_obj : public ::neash::events::Event_obj{
	public:
		typedef ::neash::events::Event_obj super;
		typedef KeyComboEvent_obj OBJ_;
		KeyComboEvent_obj();
		Void __construct(::String type,Dynamic __o_bubbles,Dynamic __o_cancelable);

	public:
		static hx::ObjectPtr< KeyComboEvent_obj > __new(::String type,Dynamic __o_bubbles,Dynamic __o_cancelable);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~KeyComboEvent_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark();
		::String __ToString() const { return HX_STRING(L"KeyComboEvent",13); }

		::org::casalib::ui::KeyCombo keyCombo; /* REM */ 
		::org::casalib::ui::KeyCombo _keyCombo; /* REM */ 
		virtual ::org::casalib::ui::KeyCombo getKeyCombo( );
		Dynamic getKeyCombo_dyn();

		virtual ::org::casalib::ui::KeyCombo setKeyCombo( ::org::casalib::ui::KeyCombo keyCombo);
		Dynamic setKeyCombo_dyn();

		virtual ::neash::events::Event clone( );
		Dynamic clone_dyn();

		static ::String DOWN; /* REM */ 
		static ::String RELEASE; /* REM */ 
		static ::String SEQUENCE; /* REM */ 
};

} // end namespace org
} // end namespace casalib
} // end namespace events

#endif /* INCLUDED_org_casalib_events_KeyComboEvent */ 
