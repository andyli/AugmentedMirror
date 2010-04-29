#ifndef INCLUDED_cpp_vm_Thread
#define INCLUDED_cpp_vm_Thread

#include <hxcpp.h>

HX_DECLARE_CLASS2(cpp,vm,Thread)
namespace cpp{
namespace vm{


class Thread_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef Thread_obj OBJ_;
		Thread_obj();
		Void __construct(Dynamic h);

	public:
		static hx::ObjectPtr< Thread_obj > __new(Dynamic h);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~Thread_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark();
		::String __ToString() const { return HX_STRING(L"Thread",6); }

		Dynamic handle; /* REM */ 
		virtual Void sendMessage( Dynamic msg);
		Dynamic sendMessage_dyn();

		virtual Dynamic __compare( Dynamic t);
		Dynamic __compare_dyn();

		static ::cpp::vm::Thread current( );
		static Dynamic current_dyn();

		static ::cpp::vm::Thread create( Dynamic callb);
		static Dynamic create_dyn();

		static Dynamic readMessage( bool block);
		static Dynamic readMessage_dyn();

};

} // end namespace cpp
} // end namespace vm

#endif /* INCLUDED_cpp_vm_Thread */ 
