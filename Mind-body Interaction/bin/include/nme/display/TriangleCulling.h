#ifndef INCLUDED_nme_display_TriangleCulling
#define INCLUDED_nme_display_TriangleCulling

#include <hxcpp.h>

HX_DECLARE_CLASS2(nme,display,TriangleCulling)
namespace nme{
namespace display{


class TriangleCulling_obj : public hx::EnumBase_obj
{
	typedef hx::EnumBase_obj super;
		typedef TriangleCulling_obj OBJ_;

	public:
		TriangleCulling_obj() {};
		HX_DO_ENUM_RTTI;
		static void __boot();
		static void __register();
		::String GetEnumName( ) const { return HX_STRING(L"nme.display.TriangleCulling",27); }
		::String __ToString() const { return HX_STRING(L"TriangleCulling.",16) + tag; }

		static TriangleCulling NEGATIVE;
		static TriangleCulling NONE;
		static TriangleCulling POSITIVE;
};

} // end namespace nme
} // end namespace display

#endif /* INCLUDED_nme_display_TriangleCulling */ 
