#ifndef INCLUDED_nme_display_JointStyle
#define INCLUDED_nme_display_JointStyle

#include <hxcpp.h>

HX_DECLARE_CLASS2(nme,display,JointStyle)
namespace nme{
namespace display{


class JointStyle_obj : public hx::EnumBase_obj
{
	typedef hx::EnumBase_obj super;
		typedef JointStyle_obj OBJ_;

	public:
		JointStyle_obj() {};
		HX_DO_ENUM_RTTI;
		static void __boot();
		static void __register();
		::String GetEnumName( ) const { return HX_STRING(L"nme.display.JointStyle",22); }
		::String __ToString() const { return HX_STRING(L"JointStyle.",11) + tag; }

		static JointStyle BEVEL;
		static JointStyle MITER;
		static JointStyle ROUND;
};

} // end namespace nme
} // end namespace display

#endif /* INCLUDED_nme_display_JointStyle */ 
