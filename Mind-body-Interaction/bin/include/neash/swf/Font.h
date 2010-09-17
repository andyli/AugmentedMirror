#ifndef INCLUDED_neash_swf_Font
#define INCLUDED_neash_swf_Font

#include <hxcpp.h>

HX_DECLARE_CLASS2(neash,swf,Font)
HX_DECLARE_CLASS2(neash,swf,SWFStream)
HX_DECLARE_CLASS2(nme,geom,Matrix)
namespace neash{
namespace swf{


class Font_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef Font_obj OBJ_;
		Font_obj();
		Void __construct(::neash::swf::SWFStream inStream,int inVersion);

	public:
		static hx::ObjectPtr< Font_obj > __new(::neash::swf::SWFStream inStream,int inVersion);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~Font_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark();
		::String __ToString() const { return HX_STRING(L"Font",4); }

		Array< Dynamic > mGlyphs; /* REM */ 
		Array< Dynamic > mCodeToGlyph; /* REM */ 
		::String mName; /* REM */ 
		double mAscent; /* REM */ 
		double mDescent; /* REM */ 
		double mLeading; /* REM */ 
		Array< double > mAdvance; /* REM */ 
		virtual Void RestoreLineStyle( Dynamic g);
		Dynamic RestoreLineStyle_dyn();

		virtual bool Ok( );
		Dynamic Ok_dyn();

		virtual ::String GetName( );
		Dynamic GetName_dyn();

		virtual double RenderChar( Dynamic inGraphics,int inChar,::nme::geom::Matrix m);
		Dynamic RenderChar_dyn();

		virtual Void RenderGlyph( Dynamic inGraphics,int inGlyph,::nme::geom::Matrix m);
		Dynamic RenderGlyph_dyn();

		virtual double GetAdvance( int inChar,Dynamic inNext);
		Dynamic GetAdvance_dyn();

		virtual double GetAscent( );
		Dynamic GetAscent_dyn();

		virtual double GetDescent( );
		Dynamic GetDescent_dyn();

		virtual double GetLeading( );
		Dynamic GetLeading_dyn();

};

} // end namespace neash
} // end namespace swf

#endif /* INCLUDED_neash_swf_Font */ 
