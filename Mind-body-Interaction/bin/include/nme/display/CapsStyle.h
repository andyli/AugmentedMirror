#ifndef INCLUDED_nme_display_CapsStyle
#define INCLUDED_nme_display_CapsStyle

#include <hxcpp.h>

HX_DECLARE_CLASS2(nme,display,CapsStyle)
namespace nme{
namespace display{


class CapsStyle_obj : public hx::EnumBase_obj
{
	typedef hx::EnumBase_obj super;
		typedef CapsStyle_obj OBJ_;

	public:
		CapsStyle_obj() {};
		HX_DO_ENUM_RTTI;
		static void __boot();
		static void __register();
		::String GetEnumName( ) const { return HX_STRING(L"nme.display.CapsStyle",21); }
		::String __ToString() const { return HX_STRING(L"CapsStyle.",10) + tag; }

		static CapsStyle NONE;
		static CapsStyle ROUND;
		static CapsStyle SQUARE;
};

} // end namespace nme
} // end namespace display

#endif /* INCLUDED_nme_display_CapsStyle */ 
