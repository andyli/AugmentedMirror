#ifndef INCLUDED_Updater
#define INCLUDED_Updater

#include <hxcpp.h>

HX_DECLARE_CLASS0(Updater)
HX_DECLARE_CLASS2(cpp,net,Socket)
HX_DECLARE_CLASS2(haxe,io,Bytes)
HX_DECLARE_CLASS2(neash,events,Event)


class Updater_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef Updater_obj OBJ_;
		Updater_obj();
		Void __construct(::String socketUrlAndPort,Dynamic __o_readyByte);

	public:
		static hx::ObjectPtr< Updater_obj > __new(::String socketUrlAndPort,Dynamic __o_readyByte);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~Updater_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark();
		::String __ToString() const { return HX_STRING(L"Updater",7); }

		::String host; /* REM */ 
		int port; /* REM */ 
		::cpp::net::Socket socket; /* REM */ 
		int readyByte; /* REM */ 
		int inputSize; /* REM */ 
		::haxe::io::Bytes temp; /* REM */ 
		virtual Void start( );
		Dynamic start_dyn();

		virtual Void updateTarget( ::haxe::io::Bytes bytes);
		Dynamic updateTarget_dyn();

		virtual Void threadFunction( );
		Dynamic threadFunction_dyn();

		virtual Void onEnterframe( ::neash::events::Event e);
		Dynamic onEnterframe_dyn();

};


#endif /* INCLUDED_Updater */ 
