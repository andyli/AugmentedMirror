#ifndef INCLUDED_neash_swf_ScaledFont
#define INCLUDED_neash_swf_ScaledFont

#include <hxcpp.h>

#include <neash/text/Font.h>
HX_DECLARE_CLASS2(neash,swf,Font)
HX_DECLARE_CLASS2(neash,swf,ScaledFont)
HX_DECLARE_CLASS2(neash,text,Font)
HX_DECLARE_CLASS2(nme,geom,Matrix)
namespace neash{
namespace swf{


class ScaledFont_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef ScaledFont_obj OBJ_;
		ScaledFont_obj();
		Void __construct(::neash::swf::Font inFont,int inHeight);

	public:
		static hx::ObjectPtr< ScaledFont_obj > __new(::neash::swf::Font inFont,int inHeight);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~ScaledFont_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark();
		inline operator ::neash::text::Font_obj *()
			{ return new ::neash::text::Font_delegate_< ScaledFont_obj >(this); }
		hx::Object *__ToInterface(const type_info &inType);
		::String __ToString() const { return HX_STRING(L"ScaledFont",10); }

		::neash::swf::Font mFont; /* REM */ 
		::nme::geom::Matrix mMatrix; /* REM */ 
		int mHeight; /* REM */ 
		double mScale; /* REM */ 
		double mAscent; /* REM */ 
		virtual ::String GetName( );
		Dynamic GetName_dyn();

		virtual int GetHeight( );
		Dynamic GetHeight_dyn();

		virtual bool CanRenderSolid( );
		Dynamic CanRenderSolid_dyn();

		virtual bool CanRenderOutline( );
		Dynamic CanRenderOutline_dyn();

		virtual int Render( Dynamic inGfx,int inChar,int inX,int inY,bool inOutline);
		Dynamic Render_dyn();

		virtual int GetAdvance( int inChar);
		Dynamic GetAdvance_dyn();

		virtual int GetAscent( );
		Dynamic GetAscent_dyn();

		virtual int GetDescent( );
		Dynamic GetDescent_dyn();

		virtual int GetLeading( );
		Dynamic GetLeading_dyn();

};

} // end namespace neash
} // end namespace swf

#endif /* INCLUDED_neash_swf_ScaledFont */ 
