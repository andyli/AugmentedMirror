#ifndef INCLUDED_haxe_xml__Fast_AttribAccess
#define INCLUDED_haxe_xml__Fast_AttribAccess

#include <hxcpp.h>

HX_DECLARE_CLASS1(cpp,CppXml__)
HX_DECLARE_CLASS3(haxe,xml,_Fast,AttribAccess)
namespace haxe{
namespace xml{
namespace _Fast{


class AttribAccess_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef AttribAccess_obj OBJ_;
		AttribAccess_obj();
		Void __construct(::cpp::CppXml__ x);

	public:
		static hx::ObjectPtr< AttribAccess_obj > __new(::cpp::CppXml__ x);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~AttribAccess_obj();

		HX_DO_RTTI;
		HX_DECLARE_IMPLEMENT_DYNAMIC;
		static void __boot();
		static void __register();
		void __Mark();
		::String __ToString() const { return HX_STRING(L"AttribAccess",12); }

		::cpp::CppXml__ __x; /* REM */ 
		virtual ::String resolve( ::String name);
		Dynamic resolve_dyn();

};

} // end namespace haxe
} // end namespace xml
} // end namespace _Fast

#endif /* INCLUDED_haxe_xml__Fast_AttribAccess */ 
