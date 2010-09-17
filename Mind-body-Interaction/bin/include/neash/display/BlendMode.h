#ifndef INCLUDED_neash_display_BlendMode
#define INCLUDED_neash_display_BlendMode

#include <hxcpp.h>

HX_DECLARE_CLASS2(neash,display,BlendMode)
namespace neash{
namespace display{


class BlendMode_obj : public hx::EnumBase_obj
{
	typedef hx::EnumBase_obj super;
		typedef BlendMode_obj OBJ_;

	public:
		BlendMode_obj() {};
		HX_DO_ENUM_RTTI;
		static void __boot();
		static void __register();
		::String GetEnumName( ) const { return HX_STRING(L"neash.display.BlendMode",23); }
		::String __ToString() const { return HX_STRING(L"BlendMode.",10) + tag; }

		static BlendMode ADD;
		static BlendMode ALPHA;
		static BlendMode DARKEN;
		static BlendMode DIFFERENCE;
		static BlendMode ERASE;
		static BlendMode HARDLIGHT;
		static BlendMode INVERT;
		static BlendMode LAYER;
		static BlendMode LIGHTEN;
		static BlendMode MULTIPLY;
		static BlendMode NORMAL;
		static BlendMode OVERLAY;
		static BlendMode SCREEN;
		static BlendMode SUBTRACT;
};

} // end namespace neash
} // end namespace display

#endif /* INCLUDED_neash_display_BlendMode */ 
