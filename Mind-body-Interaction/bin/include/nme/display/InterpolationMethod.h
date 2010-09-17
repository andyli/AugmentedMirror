#ifndef INCLUDED_nme_display_InterpolationMethod
#define INCLUDED_nme_display_InterpolationMethod

#include <hxcpp.h>

HX_DECLARE_CLASS2(nme,display,InterpolationMethod)
namespace nme{
namespace display{


class InterpolationMethod_obj : public hx::EnumBase_obj
{
	typedef hx::EnumBase_obj super;
		typedef InterpolationMethod_obj OBJ_;

	public:
		InterpolationMethod_obj() {};
		HX_DO_ENUM_RTTI;
		static void __boot();
		static void __register();
		::String GetEnumName( ) const { return HX_STRING(L"nme.display.InterpolationMethod",31); }
		::String __ToString() const { return HX_STRING(L"InterpolationMethod.",20) + tag; }

		static InterpolationMethod LINEAR_RGB;
		static InterpolationMethod RGB;
};

} // end namespace nme
} // end namespace display

#endif /* INCLUDED_nme_display_InterpolationMethod */ 
