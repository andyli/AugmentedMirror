#ifndef INCLUDED_nme_display_GfxPoint
#define INCLUDED_nme_display_GfxPoint

#include <hxcpp.h>

HX_DECLARE_CLASS2(nme,display,GfxPoint)
namespace nme{
namespace display{


class GfxPoint_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef GfxPoint_obj OBJ_;
		GfxPoint_obj();
		Void __construct(double inX,double inY,double inCX,double inCY,int inType);

	public:
		static hx::ObjectPtr< GfxPoint_obj > __new(double inX,double inY,double inCX,double inCY,int inType);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~GfxPoint_obj();

		HX_DO_RTTI;
		double __INumField(int inFieldID);
		static void __boot();
		static void __register();
		void __Mark();
		::String __ToString() const { return HX_STRING(L"GfxPoint",8); }

		double x; /* REM */ 
		double y; /* REM */ 
		double cx; /* REM */ 
		double cy; /* REM */ 
		int type; /* REM */ 
};

} // end namespace nme
} // end namespace display

#endif /* INCLUDED_nme_display_GfxPoint */ 
