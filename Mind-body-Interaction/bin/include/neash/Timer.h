#ifndef INCLUDED_neash_Timer
#define INCLUDED_neash_Timer

#include <hxcpp.h>

HX_DECLARE_CLASS1(neash,Timer)
namespace neash{


class Timer_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef Timer_obj OBJ_;
		Timer_obj();
		Void __construct(int time);

	public:
		static hx::ObjectPtr< Timer_obj > __new(int time);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~Timer_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark();
		::String __ToString() const { return HX_STRING(L"Timer",5); }

		int mTime; /* REM */ 
		int mFireAt; /* REM */ 
		bool mRunning; /* REM */ 
		Dynamic run;
		inline Dynamic &run_dyn() {return run; }

		virtual Void stop( );
		Dynamic stop_dyn();

		virtual Void Check( int inTime);
		Dynamic Check_dyn();

		static Array< ::neash::Timer > sRunningTimers; /* REM */ 
		static double sInitTime; /* REM */ 
		static Void CheckTimers( );
		static Dynamic CheckTimers_dyn();

		static int GetMS( );
		static Dynamic GetMS_dyn();

		static Void delay( Dynamic $t1,int time);
		static Dynamic delay_dyn();

		static double stamp( );
		static Dynamic stamp_dyn();

};

} // end namespace neash

#endif /* INCLUDED_neash_Timer */ 
