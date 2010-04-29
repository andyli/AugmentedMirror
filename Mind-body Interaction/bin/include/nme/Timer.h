#ifndef INCLUDED_nme_Timer
#define INCLUDED_nme_Timer

#include <hxcpp.h>

#include <nme/Time.h>
HX_DECLARE_CLASS1(nme,Time)
HX_DECLARE_CLASS1(nme,Timer)
namespace nme{


class Timer_obj : public ::nme::Time_obj{
	public:
		typedef ::nme::Time_obj super;
		typedef Timer_obj OBJ_;
		Timer_obj();
		Void __construct(double time);

	public:
		static hx::ObjectPtr< Timer_obj > __new(double time);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~Timer_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark();
		::String __ToString() const { return HX_STRING(L"Timer",5); }

		virtual Void stop( );
		Dynamic stop_dyn();

		Dynamic run;
		inline Dynamic &run_dyn() {return run; }

		virtual bool isTime( );
		Dynamic isTime_dyn();

		static Array< ::nme::Timer > arr; /* REM */ 
		static Void check( );
		static Dynamic check_dyn();

		static Dynamic delayed( Dynamic $t1,int $t2);
		static Dynamic delayed_dyn();

		static Array< Dynamic > fqueue; /* REM */ 
		static Void queue( Dynamic f,Dynamic time);
		static Dynamic queue_dyn();

		static double stamp( );
		static Dynamic stamp_dyn();

		static double getCurrent( );
		static Dynamic getCurrent_dyn();

};

} // end namespace nme

#endif /* INCLUDED_nme_Timer */ 
