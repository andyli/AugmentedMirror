#ifndef INCLUDED_org_casalib_core_Destroyable
#define INCLUDED_org_casalib_core_Destroyable

#include <hxcpp.h>

#include <org/casalib/core/IDestroyable.h>
HX_DECLARE_CLASS3(org,casalib,core,Destroyable)
HX_DECLARE_CLASS3(org,casalib,core,IDestroyable)
namespace org{
namespace casalib{
namespace core{


class Destroyable_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef Destroyable_obj OBJ_;
		Destroyable_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< Destroyable_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~Destroyable_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark();
		inline operator ::org::casalib::core::IDestroyable_obj *()
			{ return new ::org::casalib::core::IDestroyable_delegate_< Destroyable_obj >(this); }
		hx::Object *__ToInterface(const type_info &inType);
		::String __ToString() const { return HX_STRING(L"Destroyable",11); }

		bool destroyed; /* REM */ 
		bool _isDestroyed; /* REM */ 
		virtual bool getDestroyed( );
		Dynamic getDestroyed_dyn();

		virtual Void destroy( );
		Dynamic destroy_dyn();

};

} // end namespace org
} // end namespace casalib
} // end namespace core

#endif /* INCLUDED_org_casalib_core_Destroyable */ 
