#ifndef INCLUDED_nme_display_BitmapData
#define INCLUDED_nme_display_BitmapData

#include <hxcpp.h>

#include <nme/display/IBitmapDrawable.h>
HX_DECLARE_CLASS2(haxe,io,Input)
HX_DECLARE_CLASS2(nme,display,BitmapData)
HX_DECLARE_CLASS2(nme,display,Graphics)
HX_DECLARE_CLASS2(nme,display,IBitmapDrawable)
HX_DECLARE_CLASS2(nme,geom,ColorTransform)
HX_DECLARE_CLASS2(nme,geom,Matrix)
HX_DECLARE_CLASS2(nme,geom,Point)
HX_DECLARE_CLASS2(nme,geom,Rectangle)
HX_DECLARE_CLASS2(nme,utils,ByteArray)
namespace nme{
namespace display{


class BitmapData_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef BitmapData_obj OBJ_;
		BitmapData_obj();
		Void __construct(int inWidth,int inHeight,Dynamic __o_inTransparent,Dynamic inFillRGBA);

	public:
		static hx::ObjectPtr< BitmapData_obj > __new(int inWidth,int inHeight,Dynamic __o_inTransparent,Dynamic inFillRGBA);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~BitmapData_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark();
		inline operator ::nme::display::IBitmapDrawable_obj *()
			{ return new ::nme::display::IBitmapDrawable_delegate_< BitmapData_obj >(this); }
		hx::Object *__ToInterface(const type_info &inType);
		::String __ToString() const { return HX_STRING(L"BitmapData",10); }

		Dynamic mTextureBuffer; /* REM */ 
		int width; /* REM */ 
		int height; /* REM */ 
		::nme::display::Graphics graphics; /* REM */ 
		::nme::geom::Rectangle rect; /* REM */ 
		bool transparent; /* REM */ 
		virtual ::nme::display::Graphics GetBitmapDrawable( );
		Dynamic GetBitmapDrawable_dyn();

		virtual ::nme::geom::Rectangle GetRect( );
		Dynamic GetRect_dyn();

		virtual Void LoadFromFile( ::String inFilename);
		Dynamic LoadFromFile_dyn();

		virtual Void LoadFromBytes( Array< unsigned char > inBytes,::String inType,::String inAlpha);
		Dynamic LoadFromBytes_dyn();

		virtual Void SetPixelData( ::String inBuffer,int inFormat,int inTableSize);
		Dynamic SetPixelData_dyn();

		virtual Void clear( int color);
		Dynamic clear_dyn();

		virtual ::nme::display::BitmapData clone( );
		Dynamic clone_dyn();

		virtual Void copyPixels( ::nme::display::BitmapData sourceBitmapData,::nme::geom::Rectangle sourceRect,::nme::geom::Point destPoint,::nme::display::BitmapData alphaBitmapData,::nme::geom::Point alphaPoint,Dynamic mergeAlpha);
		Dynamic copyPixels_dyn();

		virtual Void dispose( );
		Dynamic dispose_dyn();

		virtual Void draw( ::nme::display::IBitmapDrawable source,::nme::geom::Matrix matrix,::nme::geom::ColorTransform colorTransform,::String blendMode,::nme::geom::Rectangle clipRect,Dynamic smoothing);
		Dynamic draw_dyn();

		virtual Void drawToSurface( Dynamic inSurface,::nme::geom::Matrix matrix,::nme::geom::ColorTransform colorTransform,::String blendMode,::nme::geom::Rectangle clipRect,bool smoothing);
		Dynamic drawToSurface_dyn();

		virtual Void fillRect( ::nme::geom::Rectangle rect,int inColour);
		Dynamic fillRect_dyn();

		virtual Void fillRectEx( ::nme::geom::Rectangle rect,int inColour,Dynamic inAlpha);
		Dynamic fillRectEx_dyn();

		virtual Void flushGraphics( );
		Dynamic flushGraphics_dyn();

		virtual ::nme::geom::Rectangle getColorBoundsRect( int mask,int color,Dynamic findColor);
		Dynamic getColorBoundsRect_dyn();

		virtual ::nme::display::Graphics getGraphics( );
		Dynamic getGraphics_dyn();

		virtual int getHeight( );
		Dynamic getHeight_dyn();

		virtual int getWidth( );
		Dynamic getWidth_dyn();

		virtual Dynamic handle( );
		Dynamic handle_dyn();

		virtual ::nme::utils::ByteArray getPixels( ::nme::geom::Rectangle rect);
		Dynamic getPixels_dyn();

		virtual int getPixel( int x,int y);
		Dynamic getPixel_dyn();

		virtual int getPixel32( int x,int y);
		Dynamic getPixel32_dyn();

		virtual Void lock( );
		Dynamic lock_dyn();

		virtual Void scroll( int inDX,int inDY);
		Dynamic scroll_dyn();

		virtual Void setPixel( int inX,int inY,int inColour);
		Dynamic setPixel_dyn();

		virtual Void setPixel32( int inX,int inY,int inColour);
		Dynamic setPixel32_dyn();

		virtual Void setPixel32Ex( int inX,int inY,int inAlpha,int inColour);
		Dynamic setPixel32Ex_dyn();

		virtual Void setPixels( ::nme::geom::Rectangle rect,::nme::utils::ByteArray pixels);
		Dynamic setPixels_dyn();

		virtual Void unlock( ::nme::geom::Rectangle changeRect);
		Dynamic unlock_dyn();

		virtual bool __getTransparent( );
		Dynamic __getTransparent_dyn();

		static int CLEAR; /* REM */ 
		static int BLACK; /* REM */ 
		static int WHITE; /* REM */ 
		static int RED; /* REM */ 
		static int GREEN; /* REM */ 
		static int BLUE; /* REM */ 
		static int TRANSPARENT; /* REM */ 
		static int HARDWARE; /* REM */ 
		static ::nme::display::BitmapData CreateFromHandle( Dynamic inHandle);
		static Dynamic CreateFromHandle_dyn();

		static ::nme::display::BitmapData Load( ::String inFilename);
		static Dynamic Load_dyn();

		static int extractAlpha( int v);
		static Dynamic extractAlpha_dyn();

		static int extractColor( int v);
		static Dynamic extractColor_dyn();

		static Dynamic nme_clone_texture_buffer; /* REM */ 
	Dynamic &nme_clone_texture_buffer_dyn() { return nme_clone_texture_buffer;}
		static Dynamic nme_copy_pixels; /* REM */ 
	Dynamic &nme_copy_pixels_dyn() { return nme_copy_pixels;}
		static Dynamic nme_create_texture_buffer; /* REM */ 
	Dynamic &nme_create_texture_buffer_dyn() { return nme_create_texture_buffer;}
		static Dynamic nme_draw_object_to; /* REM */ 
		static Dynamic nme_get_pixel; /* REM */ 
	Dynamic &nme_get_pixel_dyn() { return nme_get_pixel;}
		static Dynamic nme_get_pixel32; /* REM */ 
	Dynamic &nme_get_pixel32_dyn() { return nme_get_pixel32;}
		static Dynamic nme_get_transparent; /* REM */ 
	Dynamic &nme_get_transparent_dyn() { return nme_get_transparent;}
		static Dynamic nme_load_texture; /* REM */ 
	Dynamic &nme_load_texture_dyn() { return nme_load_texture;}
		static Dynamic nme_load_texture_from_bytes; /* REM */ 
	Dynamic &nme_load_texture_from_bytes_dyn() { return nme_load_texture_from_bytes;}
		static Dynamic nme_scroll_texture; /* REM */ 
	Dynamic &nme_scroll_texture_dyn() { return nme_scroll_texture;}
		static Dynamic nme_set_pixel; /* REM */ 
	Dynamic &nme_set_pixel_dyn() { return nme_set_pixel;}
		static Dynamic nme_set_pixel32; /* REM */ 
	Dynamic &nme_set_pixel32_dyn() { return nme_set_pixel32;}
		static Dynamic nme_set_pixel32_ex; /* REM */ 
	Dynamic &nme_set_pixel32_ex_dyn() { return nme_set_pixel32_ex;}
		static Dynamic nme_set_pixel_data; /* REM */ 
	Dynamic &nme_set_pixel_data_dyn() { return nme_set_pixel_data;}
		static Dynamic nme_surface_clear; /* REM */ 
	Dynamic &nme_surface_clear_dyn() { return nme_surface_clear;}
		static Dynamic nme_tex_fill_rect; /* REM */ 
	Dynamic &nme_tex_fill_rect_dyn() { return nme_tex_fill_rect;}
		static Dynamic nme_texture_get_bytes; /* REM */ 
	Dynamic &nme_texture_get_bytes_dyn() { return nme_texture_get_bytes;}
		static Dynamic nme_texture_height; /* REM */ 
	Dynamic &nme_texture_height_dyn() { return nme_texture_height;}
		static Dynamic nme_texture_set_bytes; /* REM */ 
	Dynamic &nme_texture_set_bytes_dyn() { return nme_texture_set_bytes;}
		static Dynamic nme_texture_width; /* REM */ 
	Dynamic &nme_texture_width_dyn() { return nme_texture_width;}
};

} // end namespace nme
} // end namespace display

#endif /* INCLUDED_nme_display_BitmapData */ 
