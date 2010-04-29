#ifndef INCLUDED_haxe_io_Eof
#define INCLUDED_haxe_io_Eof

#include <hxcpp.h>

HX_DECLARE_CLASS2(haxe,io,Eof)
namespace haxe{
namespace io{


class Eof_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef Eof_obj OBJ_;
		Eof_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< Eof_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~Eof_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark();
		::String __ToString() const { return HX_STRING(L"Eof",3); }

		virtual ::String toString( );
		Dynamic toString_dyn();

};

} // end namespace haxe
} // end namespace io

#endif /* INCLUDED_haxe_io_Eof */ 
