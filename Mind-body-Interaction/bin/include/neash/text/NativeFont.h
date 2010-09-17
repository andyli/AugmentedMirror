#ifndef INCLUDED_neash_text_NativeFont
#define INCLUDED_neash_text_NativeFont

#include <hxcpp.h>

#include <neash/text/Font.h>
HX_DECLARE_CLASS2(neash,text,Font)
HX_DECLARE_CLASS2(neash,text,NativeFont)
HX_DECLARE_CLASS1(nme,FontHandle)
namespace neash{
namespace text{


class NativeFont_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef NativeFont_obj OBJ_;
		NativeFont_obj();
		Void __construct(::String inFace,int inHeight);

	public:
		static hx::ObjectPtr< NativeFont_obj > __new(::String inFace,int inHeight);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~NativeFont_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark();
		inline operator ::neash::text::Font_obj *()
			{ return new ::neash::text::Font_delegate_< NativeFont_obj >(this); }
		hx::Object *__ToInterface(const type_info &inType);
		::String __ToString() const { return HX_STRING(L"NativeFont",10); }

		::String mName; /* REM */ 
		::nme::FontHandle mFont; /* REM */ 
		int mHeight; /* REM */ 
		double mToEm; /* REM */ 
		Dynamic mFontMetrics; /* REM */ 
		Array< Dynamic > mMetrics; /* REM */ 
		virtual ::String toString( );
		Dynamic toString_dyn();

		virtual ::String GetName( );
		Dynamic GetName_dyn();

		virtual bool Ok( );
		Dynamic Ok_dyn();

		virtual bool CanRenderSolid( );
		Dynamic CanRenderSolid_dyn();

		virtual bool CanRenderOutline( );
		Dynamic CanRenderOutline_dyn();

		virtual int GetHeight( );
		Dynamic GetHeight_dyn();

		virtual int Render( Dynamic inGraphics,int inChar,int inX,int inY,bool inFreeType);
		Dynamic Render_dyn();

		virtual int GetAdvance( int inGlyph);
		Dynamic GetAdvance_dyn();

		virtual int GetAscent( );
		Dynamic GetAscent_dyn();

		virtual int GetDescent( );
		Dynamic GetDescent_dyn();

		virtual int GetLeading( );
		Dynamic GetLeading_dyn();

};

} // end namespace neash
} // end namespace text

#endif /* INCLUDED_neash_text_NativeFont */ 
