#ifndef INCLUDED_nme_AnimType
#define INCLUDED_nme_AnimType

#include <hxcpp.h>

HX_DECLARE_CLASS1(nme,AnimType)
namespace nme{


class AnimType_obj : public hx::EnumBase_obj
{
	typedef hx::EnumBase_obj super;
		typedef AnimType_obj OBJ_;

	public:
		AnimType_obj() {};
		HX_DO_ENUM_RTTI;
		static void __boot();
		static void __register();
		::String GetEnumName( ) const { return HX_STRING(L"nme.AnimType",12); }
		::String __ToString() const { return HX_STRING(L"AnimType.",9) + tag; }

		static AnimType at_loop;
		static AnimType at_once;
		static AnimType at_pingpong;
};

} // end namespace nme

#endif /* INCLUDED_nme_AnimType */ 
