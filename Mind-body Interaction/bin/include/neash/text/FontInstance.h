#ifndef INCLUDED_neash_text_FontInstance
#define INCLUDED_neash_text_FontInstance

#include <hxcpp.h>

HX_DECLARE_CLASS0(Hash)
HX_DECLARE_CLASS2(neash,text,Font)
HX_DECLARE_CLASS2(neash,text,FontInstance)
HX_DECLARE_CLASS2(neash,text,FontInstanceMode)
HX_DECLARE_CLASS2(nme,display,BitmapData)
HX_DECLARE_CLASS2(nme,display,Graphics)
HX_DECLARE_CLASS2(nme,display,IBitmapDrawable)
namespace neash{
namespace text{


class FontInstance_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef FontInstance_obj OBJ_;
		FontInstance_obj();
		Void __construct(::neash::text::Font inFont,int inHeight);

	public:
		static hx::ObjectPtr< FontInstance_obj > __new(::neash::text::Font inFont,int inHeight);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~FontInstance_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark();
		::String __ToString() const { return HX_STRING(L"FontInstance",12); }

		::neash::text::FontInstanceMode mMode; /* REM */ 
		int mColour; /* REM */ 
		double mAlpha; /* REM */ 
		::neash::text::Font mFont; /* REM */ 
		int mHeight; /* REM */ 
		Array< ::nme::display::BitmapData > mGlyphs; /* REM */ 
		bool mCacheAsBitmap; /* REM */ 
		bool mTryFreeType; /* REM */ 
		int height; /* REM */ 
		virtual ::String toString( );
		Dynamic toString_dyn();

		virtual ::String GetFace( );
		Dynamic GetFace_dyn();

		virtual int GetHeight( );
		Dynamic GetHeight_dyn();

		virtual Void SetSolid( int inCol,double inAlpha);
		Dynamic SetSolid_dyn();

		virtual int RenderChar( ::nme::display::Graphics inGraphics,int inGlyph,int inX,int inY);
		Dynamic RenderChar_dyn();

		virtual int GetAdvance( int inChar);
		Dynamic GetAdvance_dyn();

		static ::Hash mSolidFonts; /* REM */ 
		static ::neash::text::FontInstance CreateSolid( ::String inFace,int inHeight,int inColour,double inAlpha);
		static Dynamic CreateSolid_dyn();

};

} // end namespace neash
} // end namespace text

#endif /* INCLUDED_neash_text_FontInstance */ 
