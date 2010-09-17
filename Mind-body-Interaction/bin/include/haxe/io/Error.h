#ifndef INCLUDED_haxe_io_Error
#define INCLUDED_haxe_io_Error

#include <hxcpp.h>

HX_DECLARE_CLASS2(haxe,io,Error)
namespace haxe{
namespace io{


class Error_obj : public hx::EnumBase_obj
{
	typedef hx::EnumBase_obj super;
		typedef Error_obj OBJ_;

	public:
		Error_obj() {};
		HX_DO_ENUM_RTTI;
		static void __boot();
		static void __register();
		::String GetEnumName( ) const { return HX_STRING(L"haxe.io.Error",13); }
		::String __ToString() const { return HX_STRING(L"Error.",6) + tag; }

		static Error Blocked;
		static Error Custom(Dynamic e);
		static Dynamic Custom_dyn();
		static Error OutsideBounds;
		static Error Overflow;
};

} // end namespace haxe
} // end namespace io

#endif /* INCLUDED_haxe_io_Error */ 
