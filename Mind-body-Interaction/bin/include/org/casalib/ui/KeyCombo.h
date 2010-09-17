#ifndef INCLUDED_org_casalib_ui_KeyCombo
#define INCLUDED_org_casalib_ui_KeyCombo

#include <hxcpp.h>

HX_DECLARE_CLASS3(org,casalib,ui,KeyCombo)
namespace org{
namespace casalib{
namespace ui{


class KeyCombo_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef KeyCombo_obj OBJ_;
		KeyCombo_obj();
		Void __construct(Array< int > keyCodes);

	public:
		static hx::ObjectPtr< KeyCombo_obj > __new(Array< int > keyCodes);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~KeyCombo_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark();
		::String __ToString() const { return HX_STRING(L"KeyCombo",8); }

		Array< int > keyCodes; /* REM */ 
		Array< int > _keyCodes; /* REM */ 
		virtual Array< int > getKeyCodes( );
		Dynamic getKeyCodes_dyn();

		virtual bool equals( ::org::casalib::ui::KeyCombo keyCombo);
		Dynamic equals_dyn();

};

} // end namespace org
} // end namespace casalib
} // end namespace ui

#endif /* INCLUDED_org_casalib_ui_KeyCombo */ 
