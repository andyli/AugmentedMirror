#ifndef INCLUDED_nme_display_LineScaleMode
#define INCLUDED_nme_display_LineScaleMode

#include <hxcpp.h>

HX_DECLARE_CLASS2(nme,display,LineScaleMode)
namespace nme{
namespace display{


class LineScaleMode_obj : public hx::EnumBase_obj
{
	typedef hx::EnumBase_obj super;
		typedef LineScaleMode_obj OBJ_;

	public:
		LineScaleMode_obj() {};
		HX_DO_ENUM_RTTI;
		static void __boot();
		static void __register();
		::String GetEnumName( ) const { return HX_STRING(L"nme.display.LineScaleMode",25); }
		::String __ToString() const { return HX_STRING(L"LineScaleMode.",14) + tag; }

		static LineScaleMode HORIZONTAL;
		static LineScaleMode NONE;
		static LineScaleMode NORMAL;
		static LineScaleMode VERTICAL;
};

} // end namespace nme
} // end namespace display

#endif /* INCLUDED_nme_display_LineScaleMode */ 
