#ifndef INCLUDED_sandy_ColorChannel
#define INCLUDED_sandy_ColorChannel

#include <hxcpp.h>

HX_DECLARE_CLASS1(sandy,ColorChannel)
namespace sandy{


class ColorChannel_obj : public hx::EnumBase_obj
{
	typedef hx::EnumBase_obj super;
		typedef ColorChannel_obj OBJ_;

	public:
		ColorChannel_obj() {};
		HX_DO_ENUM_RTTI;
		static void __boot();
		static void __register();
		::String GetEnumName( ) const { return HX_STRING(L"sandy.ColorChannel",18); }
		::String __ToString() const { return HX_STRING(L"ColorChannel.",13) + tag; }

		static ColorChannel ALPHA;
		static ColorChannel AV;
		static ColorChannel BLUE;
		static ColorChannel GREEN;
		static ColorChannel RED;
};

} // end namespace sandy

#endif /* INCLUDED_sandy_ColorChannel */ 
