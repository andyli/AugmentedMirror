#ifndef INCLUDED_neash_RGB
#define INCLUDED_neash_RGB

#include <hxcpp.h>

HX_DECLARE_CLASS1(neash,RGB)
namespace neash{


class RGB_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef RGB_obj OBJ_;
		RGB_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< RGB_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~RGB_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark();
		::String __ToString() const { return HX_STRING(L"RGB",3); }

		static int ZERO; /* REM */ 
		static int ONE; /* REM */ 
		static int CLEAR; /* REM */ 
		static int BLACK; /* REM */ 
		static int WHITE; /* REM */ 
		static int RED; /* REM */ 
		static int GREEN; /* REM */ 
		static int BLUE; /* REM */ 
		static int RGB( int inR,int inG,int inB);
		static Dynamic RGB_dyn();

		static int IRGB( int inRGBA);
		static Dynamic IRGB_dyn();

		static int RGBA( int inR,int inG,int inB,Dynamic inA);
		static Dynamic RGBA_dyn();

		static int Red( int inRGBA);
		static Dynamic Red_dyn();

		static int Green( int inRGBA);
		static Dynamic Green_dyn();

		static int Blue( int inRGBA);
		static Dynamic Blue_dyn();

		static int Alpha( int inRGBA);
		static Dynamic Alpha_dyn();

};

} // end namespace neash

#endif /* INCLUDED_neash_RGB */ 
