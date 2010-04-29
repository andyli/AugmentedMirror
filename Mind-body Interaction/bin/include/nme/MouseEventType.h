#ifndef INCLUDED_nme_MouseEventType
#define INCLUDED_nme_MouseEventType

#include <hxcpp.h>

HX_DECLARE_CLASS1(nme,MouseEventType)
namespace nme{


class MouseEventType_obj : public hx::EnumBase_obj
{
	typedef hx::EnumBase_obj super;
		typedef MouseEventType_obj OBJ_;

	public:
		MouseEventType_obj() {};
		HX_DO_ENUM_RTTI;
		static void __boot();
		static void __register();
		::String GetEnumName( ) const { return HX_STRING(L"nme.MouseEventType",18); }
		::String __ToString() const { return HX_STRING(L"MouseEventType.",15) + tag; }

		static MouseEventType met_LeftDown;
		static MouseEventType met_LeftUp;
		static MouseEventType met_MiddleDown;
		static MouseEventType met_MiddleUp;
		static MouseEventType met_MouseWheelDown;
		static MouseEventType met_MouseWheelUp;
		static MouseEventType met_Move;
		static MouseEventType met_RightDown;
		static MouseEventType met_RightUp;
};

} // end namespace nme

#endif /* INCLUDED_nme_MouseEventType */ 
