#ifndef INCLUDED_neash_display_StageScaleMode
#define INCLUDED_neash_display_StageScaleMode

#include <hxcpp.h>

HX_DECLARE_CLASS2(neash,display,StageScaleMode)
namespace neash{
namespace display{


class StageScaleMode_obj : public hx::EnumBase_obj
{
	typedef hx::EnumBase_obj super;
		typedef StageScaleMode_obj OBJ_;

	public:
		StageScaleMode_obj() {};
		HX_DO_ENUM_RTTI;
		static void __boot();
		static void __register();
		::String GetEnumName( ) const { return HX_STRING(L"neash.display.StageScaleMode",28); }
		::String __ToString() const { return HX_STRING(L"StageScaleMode.",15) + tag; }

		static StageScaleMode EXACT_FIT;
		static StageScaleMode NO_BORDER;
		static StageScaleMode NO_SCALE;
		static StageScaleMode SHOW_ALL;
};

} // end namespace neash
} // end namespace display

#endif /* INCLUDED_neash_display_StageScaleMode */ 
