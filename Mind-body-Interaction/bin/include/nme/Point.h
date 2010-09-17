#ifndef INCLUDED_nme_Point
#define INCLUDED_nme_Point

#include <hxcpp.h>

HX_DECLARE_CLASS1(nme,Point)
namespace nme{


class Point_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef Point_obj OBJ_;
		Point_obj();
		Void __construct(int vX,int vY);

	public:
		static hx::ObjectPtr< Point_obj > __new(int vX,int vY);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~Point_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark();
		::String __ToString() const { return HX_STRING(L"Point",5); }

		int x; /* REM */ 
		int y; /* REM */ 
};

} // end namespace nme

#endif /* INCLUDED_nme_Point */ 
