#ifndef INCLUDED_cpp_vm_Mutex
#define INCLUDED_cpp_vm_Mutex

#include <hxcpp.h>

HX_DECLARE_CLASS2(cpp,vm,Mutex)
namespace cpp{
namespace vm{


class Mutex_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef Mutex_obj OBJ_;
		Mutex_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< Mutex_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~Mutex_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark();
		::String __ToString() const { return HX_STRING(L"Mutex",5); }

		Dynamic m; /* REM */ 
		virtual Void acquire( );
		Dynamic acquire_dyn();

		virtual bool tryAcquire( );
		Dynamic tryAcquire_dyn();

		virtual Void release( );
		Dynamic release_dyn();

};

} // end namespace cpp
} // end namespace vm

#endif /* INCLUDED_cpp_vm_Mutex */ 
