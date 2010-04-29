#ifndef INCLUDED_nme_display_GradientType
#define INCLUDED_nme_display_GradientType

#include <hxcpp.h>

HX_DECLARE_CLASS2(nme,display,GradientType)
namespace nme{
namespace display{


class GradientType_obj : public hx::EnumBase_obj
{
	typedef hx::EnumBase_obj super;
		typedef GradientType_obj OBJ_;

	public:
		GradientType_obj() {};
		HX_DO_ENUM_RTTI;
		static void __boot();
		static void __register();
		::String GetEnumName( ) const { return HX_STRING(L"nme.display.GradientType",24); }
		::String __ToString() const { return HX_STRING(L"GradientType.",13) + tag; }

		static GradientType LINEAR;
		static GradientType RADIAL;
};

} // end namespace nme
} // end namespace display

#endif /* INCLUDED_nme_display_GradientType */ 
