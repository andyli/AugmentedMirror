#ifndef INCLUDED_nme_Time
#define INCLUDED_nme_Time

#include <hxcpp.h>

HX_DECLARE_CLASS1(nme,Time)
namespace nme{


class Time_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef Time_obj OBJ_;
		Time_obj();
		Void __construct(double p);

	public:
		static hx::ObjectPtr< Time_obj > __new(double p);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~Time_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark();
		::String __ToString() const { return HX_STRING(L"Time",4); }

		double period; /* REM */ 
		double previous; /* REM */ 
		virtual double getPrevious( );
		Dynamic getPrevious_dyn();

		virtual bool isTime( );
		Dynamic isTime_dyn();

		static double getSeconds( );
		static Dynamic getSeconds_dyn();

		static Dynamic nme_gettime; /* REM */ 
	Dynamic &nme_gettime_dyn() { return nme_gettime;}
};

} // end namespace nme

#endif /* INCLUDED_nme_Time */ 
