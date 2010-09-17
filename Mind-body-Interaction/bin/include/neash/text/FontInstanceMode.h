#ifndef INCLUDED_neash_text_FontInstanceMode
#define INCLUDED_neash_text_FontInstanceMode

#include <hxcpp.h>

HX_DECLARE_CLASS2(neash,text,FontInstanceMode)
namespace neash{
namespace text{


class FontInstanceMode_obj : public hx::EnumBase_obj
{
	typedef hx::EnumBase_obj super;
		typedef FontInstanceMode_obj OBJ_;

	public:
		FontInstanceMode_obj() {};
		HX_DO_ENUM_RTTI;
		static void __boot();
		static void __register();
		::String GetEnumName( ) const { return HX_STRING(L"neash.text.FontInstanceMode",27); }
		::String __ToString() const { return HX_STRING(L"FontInstanceMode.",17) + tag; }

		static FontInstanceMode fimSolid;
};

} // end namespace neash
} // end namespace text

#endif /* INCLUDED_neash_text_FontInstanceMode */ 
