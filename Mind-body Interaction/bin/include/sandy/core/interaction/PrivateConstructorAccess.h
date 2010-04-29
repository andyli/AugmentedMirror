#ifndef INCLUDED_sandy_core_interaction_PrivateConstructorAccess
#define INCLUDED_sandy_core_interaction_PrivateConstructorAccess

#include <hxcpp.h>

HX_DECLARE_CLASS3(sandy,core,interaction,PrivateConstructorAccess)
namespace sandy{
namespace core{
namespace interaction{


class PrivateConstructorAccess_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef PrivateConstructorAccess_obj OBJ_;
		PrivateConstructorAccess_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< PrivateConstructorAccess_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~PrivateConstructorAccess_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark();
		::String __ToString() const { return HX_STRING(L"PrivateConstructorAccess",24); }

};

} // end namespace sandy
} // end namespace core
} // end namespace interaction

#endif /* INCLUDED_sandy_core_interaction_PrivateConstructorAccess */ 
