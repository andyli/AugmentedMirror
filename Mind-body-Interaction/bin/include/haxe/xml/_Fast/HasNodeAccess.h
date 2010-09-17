#ifndef INCLUDED_haxe_xml__Fast_HasNodeAccess
#define INCLUDED_haxe_xml__Fast_HasNodeAccess

#include <hxcpp.h>

HX_DECLARE_CLASS1(cpp,CppXml__)
HX_DECLARE_CLASS3(haxe,xml,_Fast,HasNodeAccess)
namespace haxe{
namespace xml{
namespace _Fast{


class HasNodeAccess_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef HasNodeAccess_obj OBJ_;
		HasNodeAccess_obj();
		Void __construct(::cpp::CppXml__ x);

	public:
		static hx::ObjectPtr< HasNodeAccess_obj > __new(::cpp::CppXml__ x);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~HasNodeAccess_obj();

		HX_DO_RTTI;
		HX_DECLARE_IMPLEMENT_DYNAMIC;
		static void __boot();
		static void __register();
		void __Mark();
		::String __ToString() const { return HX_STRING(L"HasNodeAccess",13); }

		::cpp::CppXml__ __x; /* REM */ 
		virtual bool resolve( ::String name);
		Dynamic resolve_dyn();

};

} // end namespace haxe
} // end namespace xml
} // end namespace _Fast

#endif /* INCLUDED_haxe_xml__Fast_HasNodeAccess */ 
