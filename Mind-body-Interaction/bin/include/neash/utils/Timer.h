#ifndef INCLUDED_neash_utils_Timer
#define INCLUDED_neash_utils_Timer

#include <hxcpp.h>

#include <neash/events/EventDispatcher.h>
HX_DECLARE_CLASS1(neash,Timer)
HX_DECLARE_CLASS2(neash,events,EventDispatcher)
HX_DECLARE_CLASS2(neash,events,IEventDispatcher)
HX_DECLARE_CLASS2(neash,utils,Timer)
namespace neash{
namespace utils{


class Timer_obj : public ::neash::events::EventDispatcher_obj{
	public:
		typedef ::neash::events::EventDispatcher_obj super;
		typedef Timer_obj OBJ_;
		Timer_obj();
		Void __construct(double delay,Dynamic __o_repeatCount);

	public:
		static hx::ObjectPtr< Timer_obj > __new(double delay,Dynamic __o_repeatCount);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~Timer_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark();
		::String __ToString() const { return HX_STRING(L"Timer",5); }

		int currentCount; /* REM */ 
		double delay; /* REM */ 
		int repeatCount; /* REM */ 
		bool running; /* REM */ 
		::neash::Timer proxy; /* REM */ 
		virtual Void reset( );
		Dynamic reset_dyn();

		virtual Void start( );
		Dynamic start_dyn();

		virtual Void stop( );
		Dynamic stop_dyn();

		virtual Void __onInterval( );
		Dynamic __onInterval_dyn();

		virtual double __setDelay( double v);
		Dynamic __setDelay_dyn();

		virtual int __setRepeatCount( int v);
		Dynamic __setRepeatCount_dyn();

};

} // end namespace neash
} // end namespace utils

#endif /* INCLUDED_neash_utils_Timer */ 
