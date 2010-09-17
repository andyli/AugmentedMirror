#ifndef INCLUDED_nme_display_Graphics
#define INCLUDED_nme_display_Graphics

#include <hxcpp.h>

HX_DECLARE_CLASS1(nme,FontHandle)
HX_DECLARE_CLASS2(nme,display,BitmapData)
HX_DECLARE_CLASS2(nme,display,CapsStyle)
HX_DECLARE_CLASS2(nme,display,GfxPoint)
HX_DECLARE_CLASS2(nme,display,GradientType)
HX_DECLARE_CLASS2(nme,display,Graphics)
HX_DECLARE_CLASS2(nme,display,IBitmapDrawable)
HX_DECLARE_CLASS2(nme,display,InterpolationMethod)
HX_DECLARE_CLASS2(nme,display,JointStyle)
HX_DECLARE_CLASS2(nme,display,LineJob)
HX_DECLARE_CLASS2(nme,display,LineScaleMode)
HX_DECLARE_CLASS2(nme,display,SpreadMethod)
HX_DECLARE_CLASS2(nme,display,TriangleCulling)
HX_DECLARE_CLASS2(nme,geom,Matrix)
HX_DECLARE_CLASS2(nme,geom,Rectangle)
namespace nme{
namespace display{


class Graphics_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef Graphics_obj OBJ_;
		Graphics_obj();
		Void __construct(Dynamic inSurface);

	public:
		static hx::ObjectPtr< Graphics_obj > __new(Dynamic inSurface);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~Graphics_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark();
		::String __ToString() const { return HX_STRING(L"Graphics",8); }

		Dynamic mSurface; /* REM */ 
		bool mChanged; /* REM */ 
		Array< ::nme::display::GfxPoint > mPoints; /* REM */ 
		bool mSolid; /* REM */ 
		bool mFilling; /* REM */ 
		int mFillColour; /* REM */ 
		double mFillAlpha; /* REM */ 
		Dynamic mSolidGradient; /* REM */ 
		Dynamic mBitmap; /* REM */ 
		::nme::display::LineJob mCurrentLine; /* REM */ 
		Array< ::nme::display::LineJob > mLineJobs; /* REM */ 
		Array< Dynamic > mDrawList; /* REM */ 
		Array< Dynamic > mLineDraws; /* REM */ 
		double mPenX; /* REM */ 
		double mPenY; /* REM */ 
		int mLastMoveID; /* REM */ 
		virtual Void SetSurface( Dynamic inSurface);
		Dynamic SetSurface_dyn();

		virtual ::nme::geom::Rectangle GetSurfaceRect( );
		Dynamic GetSurfaceRect_dyn();

		virtual Void render( ::nme::geom::Matrix inMatrix,Dynamic inSurface,Dynamic inMaskHandle,::nme::geom::Rectangle inScrollRect);
		Dynamic render_dyn();

		virtual bool hitTest( int inX,int inY);
		Dynamic hitTest_dyn();

		virtual Void blit( ::nme::display::BitmapData inTexture);
		Dynamic blit_dyn();

		virtual Void lineStyle( Dynamic thickness,Dynamic color,Dynamic alpha,Dynamic pixelHinting,::nme::display::LineScaleMode scaleMode,::nme::display::CapsStyle caps,::nme::display::JointStyle joints,Dynamic miterLimit);
		Dynamic lineStyle_dyn();

		virtual Void lineGradientStyle( ::nme::display::GradientType type,Array< Dynamic > colors,Array< Dynamic > alphas,Array< Dynamic > ratios,::nme::geom::Matrix matrix,::nme::display::SpreadMethod spreadMethod,::nme::display::InterpolationMethod interpolationMethod,Dynamic focalPointRatio);
		Dynamic lineGradientStyle_dyn();

		virtual Void beginFill( int color,Dynamic alpha);
		Dynamic beginFill_dyn();

		virtual Void endFill( );
		Dynamic endFill_dyn();

		virtual Void drawEllipse( double x,double y,double rx,double ry);
		Dynamic drawEllipse_dyn();

		virtual Void drawCircle( double x,double y,double rad);
		Dynamic drawCircle_dyn();

		virtual Void drawRect( double x,double y,double width,double height);
		Dynamic drawRect_dyn();

		virtual Void drawRoundRect( double x,double y,double width,double height,double ellipseWidth,double ellipseHeight);
		Dynamic drawRoundRect_dyn();

		virtual Dynamic CreateGradient( ::nme::display::GradientType type,Array< Dynamic > colors,Array< Dynamic > alphas,Array< Dynamic > ratios,::nme::geom::Matrix matrix,::nme::display::SpreadMethod spreadMethod,::nme::display::InterpolationMethod interpolationMethod,Dynamic focalPointRatio);
		Dynamic CreateGradient_dyn();

		virtual Void beginGradientFill( ::nme::display::GradientType type,Array< Dynamic > colors,Array< Dynamic > alphas,Array< Dynamic > ratios,::nme::geom::Matrix matrix,::nme::display::SpreadMethod spreadMethod,::nme::display::InterpolationMethod interpolationMethod,Dynamic focalPointRatio);
		Dynamic beginGradientFill_dyn();

		virtual Void beginBitmapFill( ::nme::display::BitmapData bitmap,::nme::geom::Matrix matrix,Dynamic in_repeat,Dynamic in_smooth);
		Dynamic beginBitmapFill_dyn();

		virtual Void RenderGlyph( ::nme::FontHandle inFont,int inChar,double inX,double inY,Dynamic inUseFreeType);
		Dynamic RenderGlyph_dyn();

		virtual Void drawTriangles( Array< double > vertices,Array< int > indices,Array< double > uvtData,::nme::display::TriangleCulling culling);
		Dynamic drawTriangles_dyn();

		virtual Void ClearLine( );
		Dynamic ClearLine_dyn();

		virtual Void clear( );
		Dynamic clear_dyn();

		virtual ::nme::geom::Rectangle GetExtent( ::nme::geom::Matrix inMatrix);
		Dynamic GetExtent_dyn();

		virtual Void moveTo( double inX,double inY);
		Dynamic moveTo_dyn();

		virtual Void lineTo( double inX,double inY);
		Dynamic lineTo_dyn();

		virtual Void curveTo( double inCX,double inCY,double inX,double inY);
		Dynamic curveTo_dyn();

		virtual Void text( ::String text,Dynamic fontSize,::String fontName,Dynamic bgColor,Dynamic alignX,Dynamic alignY);
		Dynamic text_dyn();

		virtual Void flush( );
		Dynamic flush_dyn();

		virtual bool CheckChanged( );
		Dynamic CheckChanged_dyn();

		virtual Void AddDrawable( Dynamic inDrawable);
		Dynamic AddDrawable_dyn();

		virtual Void AddLineSegment( );
		Dynamic AddLineSegment_dyn();

		virtual Void ClosePolygon( bool inCancelFill);
		Dynamic ClosePolygon_dyn();

		virtual Void AddToMask( Dynamic ioMask,::nme::geom::Matrix inMatrix,Dynamic inSurface);
		Dynamic AddToMask_dyn();

		virtual Dynamic CreateMask( ::nme::geom::Matrix inMatrix);
		Dynamic CreateMask_dyn();

		virtual Void SetScale9Grid( ::nme::geom::Rectangle inRect,double inSX,double inSY,::nme::geom::Rectangle inExtent);
		Dynamic SetScale9Grid_dyn();

		static ::String defaultFontName; /* REM */ 
		static int defaultFontSize; /* REM */ 
		static ::nme::geom::Matrix immediateMatrix; /* REM */ 
		static Dynamic immediateMask; /* REM */ 
		static int TOP; /* REM */ 
		static int CENTER; /* REM */ 
		static int BOTTOM; /* REM */ 
		static int LEFT; /* REM */ 
		static int RIGHT; /* REM */ 
		static int RADIAL; /* REM */ 
		static int REPEAT; /* REM */ 
		static int REFLECT; /* REM */ 
		static int EDGE_MASK; /* REM */ 
		static int EDGE_CLAMP; /* REM */ 
		static int EDGE_REPEAT; /* REM */ 
		static int EDGE_UNCHECKED; /* REM */ 
		static int EDGE_REPEAT_POW2; /* REM */ 
		static int END_NONE; /* REM */ 
		static int END_ROUND; /* REM */ 
		static int END_SQUARE; /* REM */ 
		static int END_MASK; /* REM */ 
		static int END_SHIFT; /* REM */ 
		static int CORNER_ROUND; /* REM */ 
		static int CORNER_MITER; /* REM */ 
		static int CORNER_BEVEL; /* REM */ 
		static int CORNER_MASK; /* REM */ 
		static int CORNER_SHIFT; /* REM */ 
		static int PIXEL_HINTING; /* REM */ 
		static int BMP_REPEAT; /* REM */ 
		static int BMP_SMOOTH; /* REM */ 
		static int SCALE_NONE; /* REM */ 
		static int SCALE_VERTICAL; /* REM */ 
		static int SCALE_HORIZONTAL; /* REM */ 
		static int SCALE_NORMAL; /* REM */ 
		static int MOVE; /* REM */ 
		static int LINE; /* REM */ 
		static int CURVE; /* REM */ 
		static int BLEND_ADD; /* REM */ 
		static int BLEND_ALPHA; /* REM */ 
		static int BLEND_DARKEN; /* REM */ 
		static int BLEND_DIFFERENCE; /* REM */ 
		static int BLEND_ERASE; /* REM */ 
		static int BLEND_HARDLIGHT; /* REM */ 
		static int BLEND_INVERT; /* REM */ 
		static int BLEND_LAYER; /* REM */ 
		static int BLEND_LIGHTEN; /* REM */ 
		static int BLEND_MULTIPLY; /* REM */ 
		static int BLEND_NORMAL; /* REM */ 
		static int BLEND_OVERLAY; /* REM */ 
		static int BLEND_SCREEN; /* REM */ 
		static int BLEND_SUBTRACT; /* REM */ 
		static int BLEND_SHADER; /* REM */ 
		static Void setBlendMode( int inBlendMode);
		static Dynamic setBlendMode_dyn();

		static Dynamic nme_draw_object_to; /* REM */ 
	Dynamic &nme_draw_object_to_dyn() { return nme_draw_object_to;}
		static Dynamic nme_draw_objects_to; /* REM */ 
	Dynamic &nme_draw_objects_to_dyn() { return nme_draw_objects_to;}
		static Dynamic nme_hit_object; /* REM */ 
	Dynamic &nme_hit_object_dyn() { return nme_hit_object;}
		static Dynamic nme_create_blit_drawable; /* REM */ 
	Dynamic &nme_create_blit_drawable_dyn() { return nme_create_blit_drawable;}
		static Dynamic nme_create_draw_obj; /* REM */ 
	Dynamic &nme_create_draw_obj_dyn() { return nme_create_draw_obj;}
		static Dynamic nme_create_text_drawable; /* REM */ 
	Dynamic &nme_create_text_drawable_dyn() { return nme_create_text_drawable;}
		static Dynamic nme_create_draw_triangles; /* REM */ 
	Dynamic &nme_create_draw_triangles_dyn() { return nme_create_draw_triangles;}
		static Dynamic nme_get_clip_rect; /* REM */ 
		static Dynamic nme_set_clip_rect; /* REM */ 
		static Dynamic nme_get_extent; /* REM */ 
	Dynamic &nme_get_extent_dyn() { return nme_get_extent;}
		static Dynamic nme_create_glyph_draw_obj; /* REM */ 
	Dynamic &nme_create_glyph_draw_obj_dyn() { return nme_create_glyph_draw_obj;}
		static Dynamic nme_create_mask; /* REM */ 
	Dynamic &nme_create_mask_dyn() { return nme_create_mask;}
		static Dynamic nme_add_to_mask; /* REM */ 
	Dynamic &nme_add_to_mask_dyn() { return nme_add_to_mask;}
		static Dynamic nme_set_scale9_grid; /* REM */ 
	Dynamic &nme_set_scale9_grid_dyn() { return nme_set_scale9_grid;}
		static Dynamic nme_set_blend_mode; /* REM */ 
	Dynamic &nme_set_blend_mode_dyn() { return nme_set_blend_mode;}
};

} // end namespace nme
} // end namespace display

#endif /* INCLUDED_nme_display_Graphics */ 
