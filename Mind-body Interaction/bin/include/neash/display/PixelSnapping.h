#ifndef INCLUDED_neash_display_PixelSnapping
#define INCLUDED_neash_display_PixelSnapping

#include <hxcpp.h>

HX_DECLARE_CLASS2(neash,display,PixelSnapping)
namespace neash{
namespace display{


class PixelSnapping_obj : public hx::EnumBase_obj
{
	typedef hx::EnumBase_obj super;
		typedef PixelSnapping_obj OBJ_;

	public:
		PixelSnapping_obj() {};
		HX_DO_ENUM_RTTI;
		static void __boot();
		static void __register();
		::String GetEnumName( ) const { return HX_STRING(L"neash.display.PixelSnapping",27); }
		::String __ToString() const { return HX_STRING(L"PixelSnapping.",14) + tag; }

		static PixelSnapping ALWAYS;
		static PixelSnapping AUTO;
		static PixelSnapping NEVER;
};

} // end namespace neash
} // end namespace display

#endif /* INCLUDED_neash_display_PixelSnapping */ 
