#ifndef INCLUDED_neash_display_StageQuality
#define INCLUDED_neash_display_StageQuality

#include <hxcpp.h>

HX_DECLARE_CLASS2(neash,display,StageQuality)
namespace neash{
namespace display{


class StageQuality_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef StageQuality_obj OBJ_;
		StageQuality_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< StageQuality_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~StageQuality_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark();
		::String __ToString() const { return HX_STRING(L"StageQuality",12); }

		static ::String BEST; /* REM */ 
		static ::String HIGH; /* REM */ 
		static ::String MEDIUM; /* REM */ 
		static ::String LOW; /* REM */ 
};

} // end namespace neash
} // end namespace display

#endif /* INCLUDED_neash_display_StageQuality */ 
