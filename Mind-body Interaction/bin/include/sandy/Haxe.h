#ifndef INCLUDED_sandy_Haxe
#define INCLUDED_sandy_Haxe

#include <hxcpp.h>

HX_DECLARE_CLASS1(sandy,Haxe)
namespace sandy{


class Haxe_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef Haxe_obj OBJ_;
		Haxe_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< Haxe_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~Haxe_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark();
		static void __init__();

		::String __ToString() const { return HX_STRING(L"Haxe",4); }

		static Array< Dynamic > toArray( Array< Dynamic > v);
		static Dynamic toArray_dyn();

		static Array< Dynamic > toTypedArray( Array< Dynamic > v);
		static Dynamic toTypedArray_dyn();

};

} // end namespace sandy

#endif /* INCLUDED_sandy_Haxe */ 
