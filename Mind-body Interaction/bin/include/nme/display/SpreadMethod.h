#ifndef INCLUDED_nme_display_SpreadMethod
#define INCLUDED_nme_display_SpreadMethod

#include <hxcpp.h>

HX_DECLARE_CLASS2(nme,display,SpreadMethod)
namespace nme{
namespace display{


class SpreadMethod_obj : public hx::EnumBase_obj
{
	typedef hx::EnumBase_obj super;
		typedef SpreadMethod_obj OBJ_;

	public:
		SpreadMethod_obj() {};
		HX_DO_ENUM_RTTI;
		static void __boot();
		static void __register();
		::String GetEnumName( ) const { return HX_STRING(L"nme.display.SpreadMethod",24); }
		::String __ToString() const { return HX_STRING(L"SpreadMethod.",13) + tag; }

		static SpreadMethod PAD;
		static SpreadMethod REFLECT;
		static SpreadMethod REPEAT;
};

} // end namespace nme
} // end namespace display

#endif /* INCLUDED_nme_display_SpreadMethod */ 
