#ifndef INCLUDED_haxe_xml__Fast_NodeAccess
#define INCLUDED_haxe_xml__Fast_NodeAccess

#include <hxcpp.h>

HX_DECLARE_CLASS1(cpp,CppXml__)
HX_DECLARE_CLASS2(haxe,xml,Fast)
HX_DECLARE_CLASS3(haxe,xml,_Fast,NodeAccess)
namespace haxe{
namespace xml{
namespace _Fast{


class NodeAccess_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef NodeAccess_obj OBJ_;
		NodeAccess_obj();
		Void __construct(::cpp::CppXml__ x);

	public:
		static hx::ObjectPtr< NodeAccess_obj > __new(::cpp::CppXml__ x);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~NodeAccess_obj();

		HX_DO_RTTI;
		HX_DECLARE_IMPLEMENT_DYNAMIC;
		static void __boot();
		static void __register();
		void __Mark();
		::String __ToString() const { return HX_STRING(L"NodeAccess",10); }

		::cpp::CppXml__ __x; /* REM */ 
		virtual ::haxe::xml::Fast resolve( ::String name);
		Dynamic resolve_dyn();

};

} // end namespace haxe
} // end namespace xml
} // end namespace _Fast

#endif /* INCLUDED_haxe_xml__Fast_NodeAccess */ 
