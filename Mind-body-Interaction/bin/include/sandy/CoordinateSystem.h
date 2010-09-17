#ifndef INCLUDED_sandy_CoordinateSystem
#define INCLUDED_sandy_CoordinateSystem

#include <hxcpp.h>

HX_DECLARE_CLASS1(sandy,CoordinateSystem)
namespace sandy{


class CoordinateSystem_obj : public hx::EnumBase_obj
{
	typedef hx::EnumBase_obj super;
		typedef CoordinateSystem_obj OBJ_;

	public:
		CoordinateSystem_obj() {};
		HX_DO_ENUM_RTTI;
		static void __boot();
		static void __register();
		::String GetEnumName( ) const { return HX_STRING(L"sandy.CoordinateSystem",22); }
		::String __ToString() const { return HX_STRING(L"CoordinateSystem.",17) + tag; }

		static CoordinateSystem ABSOLUTE;
		static CoordinateSystem CAMERA;
		static CoordinateSystem LOCAL;
};

} // end namespace sandy

#endif /* INCLUDED_sandy_CoordinateSystem */ 
