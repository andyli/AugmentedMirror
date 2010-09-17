#ifndef INCLUDED_nme_Rect
#define INCLUDED_nme_Rect

#include <hxcpp.h>

HX_DECLARE_CLASS1(nme,Rect)
namespace nme{


class Rect_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef Rect_obj OBJ_;
		Rect_obj();
		Void __construct(int vX,int vY,int vW,int vH);

	public:
		static hx::ObjectPtr< Rect_obj > __new(int vX,int vY,int vW,int vH);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~Rect_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark();
		::String __ToString() const { return HX_STRING(L"Rect",4); }

		int x; /* REM */ 
		int y; /* REM */ 
		int w; /* REM */ 
		int h; /* REM */ 
};

} // end namespace nme

#endif /* INCLUDED_nme_Rect */ 
