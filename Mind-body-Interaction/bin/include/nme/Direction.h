#ifndef INCLUDED_nme_Direction
#define INCLUDED_nme_Direction

#include <hxcpp.h>

HX_DECLARE_CLASS1(nme,Direction)
namespace nme{


class Direction_obj : public hx::EnumBase_obj
{
	typedef hx::EnumBase_obj super;
		typedef Direction_obj OBJ_;

	public:
		Direction_obj() {};
		HX_DO_ENUM_RTTI;
		static void __boot();
		static void __register();
		::String GetEnumName( ) const { return HX_STRING(L"nme.Direction",13); }
		::String __ToString() const { return HX_STRING(L"Direction.",10) + tag; }

		static Direction d_backward;
		static Direction d_forward;
};

} // end namespace nme

#endif /* INCLUDED_nme_Direction */ 
