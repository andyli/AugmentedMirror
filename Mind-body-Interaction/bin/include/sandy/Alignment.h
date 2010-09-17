#ifndef INCLUDED_sandy_Alignment
#define INCLUDED_sandy_Alignment

#include <hxcpp.h>

HX_DECLARE_CLASS1(sandy,Alignment)
namespace sandy{


class Alignment_obj : public hx::EnumBase_obj
{
	typedef hx::EnumBase_obj super;
		typedef Alignment_obj OBJ_;

	public:
		Alignment_obj() {};
		HX_DO_ENUM_RTTI;
		static void __boot();
		static void __register();
		::String GetEnumName( ) const { return HX_STRING(L"sandy.Alignment",15); }
		::String __ToString() const { return HX_STRING(L"Alignment.",10) + tag; }

		static Alignment XY;
		static Alignment YZ;
		static Alignment ZX;
};

} // end namespace sandy

#endif /* INCLUDED_sandy_Alignment */ 
