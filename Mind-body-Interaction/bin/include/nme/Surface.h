#ifndef INCLUDED_nme_Surface
#define INCLUDED_nme_Surface

#include <hxcpp.h>

HX_DECLARE_CLASS1(nme,Point)
HX_DECLARE_CLASS1(nme,Rect)
HX_DECLARE_CLASS1(nme,Surface)
HX_DECLARE_CLASS2(nme,geom,Rectangle)
namespace nme{


class Surface_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef Surface_obj OBJ_;
		Surface_obj();
		Void __construct(::String file);

	public:
		static hx::ObjectPtr< Surface_obj > __new(::String file);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~Surface_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark();
		::String __ToString() const { return HX_STRING(L"Surface",7); }

		Dynamic __srf; /* REM */ 
		int width; /* REM */ 
		int height; /* REM */ 
		virtual Dynamic handle( );
		Dynamic handle_dyn();

		virtual Void draw( Dynamic screen,::nme::Rect rect,::nme::Point point);
		Dynamic draw_dyn();

		virtual Void clear( int color);
		Dynamic clear_dyn();

		virtual Void free( );
		Dynamic free_dyn();

		virtual int getWidth( );
		Dynamic getWidth_dyn();

		virtual int getHeight( );
		Dynamic getHeight_dyn();

		virtual Void setKey( int r,int g,int b);
		Dynamic setKey_dyn();

		virtual ::nme::Rect transform( Dynamic screen,double angle,::nme::Point scale,::nme::Point pivot,::nme::Point destination,int flags);
		Dynamic transform_dyn();

		virtual Void transformSurface( int bgColor,double angle,::nme::Point scale,int flags);
		Dynamic transformSurface_dyn();

		virtual Void setAlpha( int percentage);
		Dynamic setAlpha_dyn();

		virtual bool collisionPixel( ::nme::Surface srfb,::nme::Rect rect,::nme::Rect rectb,::nme::Point offsetPoint);
		Dynamic collisionPixel_dyn();

		virtual bool collisionBox( ::nme::Rect rect,::nme::Rect rectb,::nme::Point offsetPoint);
		Dynamic collisionBox_dyn();

		static int DEFAULT; /* REM */ 
		static int TAA; /* REM */ 
		static int TSAFE; /* REM */ 
		static int TTMAP; /* REM */ 
		static ::nme::geom::Rectangle GetSurfaceRect( Dynamic inS);
		static Dynamic GetSurfaceRect_dyn();

		static Dynamic nme_surface_clear; /* REM */ 
	Dynamic &nme_surface_clear_dyn() { return nme_surface_clear;}
		static Dynamic nme_surface_width; /* REM */ 
	Dynamic &nme_surface_width_dyn() { return nme_surface_width;}
		static Dynamic nme_surface_height; /* REM */ 
	Dynamic &nme_surface_height_dyn() { return nme_surface_height;}
		static Dynamic nme_surface_free; /* REM */ 
		static Dynamic nme_surface_colourkey; /* REM */ 
	Dynamic &nme_surface_colourkey_dyn() { return nme_surface_colourkey;}
		static Dynamic nme_sprite_alpha; /* REM */ 
	Dynamic &nme_sprite_alpha_dyn() { return nme_sprite_alpha;}
		static Dynamic nme_sprite_init; /* REM */ 
	Dynamic &nme_sprite_init_dyn() { return nme_sprite_init;}
		static Dynamic nme_sprite_draw; /* REM */ 
	Dynamic &nme_sprite_draw_dyn() { return nme_sprite_draw;}
		static Dynamic nme_sprite_transform; /* REM */ 
	Dynamic &nme_sprite_transform_dyn() { return nme_sprite_transform;}
		static Dynamic nme_sprite_transform_surface; /* REM */ 
	Dynamic &nme_sprite_transform_surface_dyn() { return nme_sprite_transform_surface;}
		static Dynamic nme_collision_pixel; /* REM */ 
	Dynamic &nme_collision_pixel_dyn() { return nme_collision_pixel;}
		static Dynamic nme_collision_boundingbox; /* REM */ 
	Dynamic &nme_collision_boundingbox_dyn() { return nme_collision_boundingbox;}
};

} // end namespace nme

#endif /* INCLUDED_nme_Surface */ 
