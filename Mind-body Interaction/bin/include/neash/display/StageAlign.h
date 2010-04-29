#ifndef INCLUDED_neash_display_StageAlign
#define INCLUDED_neash_display_StageAlign

#include <hxcpp.h>

HX_DECLARE_CLASS2(neash,display,StageAlign)
namespace neash{
namespace display{


class StageAlign_obj : public hx::EnumBase_obj
{
	typedef hx::EnumBase_obj super;
		typedef StageAlign_obj OBJ_;

	public:
		StageAlign_obj() {};
		HX_DO_ENUM_RTTI;
		static void __boot();
		static void __register();
		::String GetEnumName( ) const { return HX_STRING(L"neash.display.StageAlign",24); }
		::String __ToString() const { return HX_STRING(L"StageAlign.",11) + tag; }

		static StageAlign BOTTOM;
		static StageAlign BOTTOM_LEFT;
		static StageAlign BOTTOM_RIGHT;
		static StageAlign LEFT;
		static StageAlign RIGHT;
		static StageAlign TOP;
		static StageAlign TOP_LEFT;
		static StageAlign TOP_RIGHT;
};

} // end namespace neash
} // end namespace display

#endif /* INCLUDED_neash_display_StageAlign */ 
