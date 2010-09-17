#ifndef INCLUDED_ThreadedCmd
#define INCLUDED_ThreadedCmd

#include <hxcpp.h>

HX_DECLARE_CLASS0(List)
HX_DECLARE_CLASS0(ThreadedCmd)


class ThreadedCmd_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef ThreadedCmd_obj OBJ_;
		ThreadedCmd_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< ThreadedCmd_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~ThreadedCmd_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark();
		::String __ToString() const { return HX_STRING(L"ThreadedCmd",11); }

		static ::List cmds; /* REM */ 
		static Void run( ::String cmd);
		static Dynamic run_dyn();

};


#endif /* INCLUDED_ThreadedCmd */ 
