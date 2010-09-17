#include <hxcpp.h>

#ifndef INCLUDED_hxMath
#include <hxMath.h>
#endif
#ifndef INCLUDED_nme_FontHandle
#include <nme/FontHandle.h>
#endif
#ifndef INCLUDED_nme_Loader
#include <nme/Loader.h>
#endif
#ifndef INCLUDED_nme_Manager
#include <nme/Manager.h>
#endif
#ifndef INCLUDED_nme_Surface
#include <nme/Surface.h>
#endif
#ifndef INCLUDED_nme_display_BitmapData
#include <nme/display/BitmapData.h>
#endif
#ifndef INCLUDED_nme_display_CapsStyle
#include <nme/display/CapsStyle.h>
#endif
#ifndef INCLUDED_nme_display_GfxPoint
#include <nme/display/GfxPoint.h>
#endif
#ifndef INCLUDED_nme_display_GradientType
#include <nme/display/GradientType.h>
#endif
#ifndef INCLUDED_nme_display_Graphics
#include <nme/display/Graphics.h>
#endif
#ifndef INCLUDED_nme_display_IBitmapDrawable
#include <nme/display/IBitmapDrawable.h>
#endif
#ifndef INCLUDED_nme_display_InterpolationMethod
#include <nme/display/InterpolationMethod.h>
#endif
#ifndef INCLUDED_nme_display_JointStyle
#include <nme/display/JointStyle.h>
#endif
#ifndef INCLUDED_nme_display_LineJob
#include <nme/display/LineJob.h>
#endif
#ifndef INCLUDED_nme_display_LineScaleMode
#include <nme/display/LineScaleMode.h>
#endif
#ifndef INCLUDED_nme_display_SpreadMethod
#include <nme/display/SpreadMethod.h>
#endif
#ifndef INCLUDED_nme_display_TriangleCulling
#include <nme/display/TriangleCulling.h>
#endif
#ifndef INCLUDED_nme_geom_Matrix
#include <nme/geom/Matrix.h>
#endif
#ifndef INCLUDED_nme_geom_Rectangle
#include <nme/geom/Rectangle.h>
#endif
namespace nme{
namespace display{

Void Graphics_obj::__construct(Dynamic inSurface)
{
{
	this->mChanged = false;
	this->mSurface = inSurface;
	this->mLastMoveID = 0;
	this->clear();
}
;
	return null();
}

Graphics_obj::~Graphics_obj() { }

Dynamic Graphics_obj::__CreateEmpty() { return  new Graphics_obj; }
hx::ObjectPtr< Graphics_obj > Graphics_obj::__new(Dynamic inSurface)
{  hx::ObjectPtr< Graphics_obj > result = new Graphics_obj();
	result->__construct(inSurface);
	return result;}

Dynamic Graphics_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Graphics_obj > result = new Graphics_obj();
	result->__construct(inArgs[0]);
	return result;}

Void Graphics_obj::SetSurface( Dynamic inSurface){
{
		this->mSurface = inSurface;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Graphics_obj,SetSurface,(void))

::nme::geom::Rectangle Graphics_obj::GetSurfaceRect( ){
	__SAFE_POINT
	Dynamic s = (this->mSurface == null()) ? Dynamic( ::nme::Manager_obj::getScreen() ) : Dynamic( this->mSurface );
	return ::nme::Surface_obj::GetSurfaceRect(s);
}


HX_DEFINE_DYNAMIC_FUNC0(Graphics_obj,GetSurfaceRect,return )

Void Graphics_obj::render( ::nme::geom::Matrix inMatrix,Dynamic inSurface,Dynamic inMaskHandle,::nme::geom::Rectangle inScrollRect){
{
		__SAFE_POINT
		this->ClosePolygon(true);
		Dynamic dest = (inSurface == null()) ? Dynamic( ::nme::Manager_obj::getScreen() ) : Dynamic( inSurface );
		if ((this->mDrawList->length > 0))
			::nme::display::Graphics_obj::nme_draw_objects_to(this->mDrawList,dest,inMatrix,inMaskHandle,inScrollRect);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC4(Graphics_obj,render,(void))

bool Graphics_obj::hitTest( int inX,int inY){
	__SAFE_POINT
	{
		int _g = 0;
		Array< Dynamic > _g1 = this->mDrawList;
		while((_g < _g1->length)){
			__SAFE_POINT
			Dynamic obj = _g1->__get(_g);
			++_g;
			if (::nme::display::Graphics_obj::nme_hit_object(obj,inX,inY))
				return true;
		}
	}
	return false;
}


HX_DEFINE_DYNAMIC_FUNC2(Graphics_obj,hitTest,return )

Void Graphics_obj::blit( ::nme::display::BitmapData inTexture){
{
		__SAFE_POINT
		this->ClosePolygon(true);
		this->AddDrawable(::nme::display::Graphics_obj::nme_create_blit_drawable(inTexture->handle(),this->mPenX,this->mPenY));
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Graphics_obj,blit,(void))

Void Graphics_obj::lineStyle( Dynamic thickness,Dynamic color,Dynamic alpha,Dynamic pixelHinting,::nme::display::LineScaleMode scaleMode,::nme::display::CapsStyle caps,::nme::display::JointStyle joints,Dynamic miterLimit){
{
		__SAFE_POINT
		this->AddLineSegment();
		if ((thickness == null())){
			this->ClearLine();
			return null();
		}
		else{
			this->mCurrentLine->grad = null();
			this->mCurrentLine->thickness = ::Math_obj::round(thickness);
			this->mCurrentLine->colour = (color == null()) ? Dynamic( 0 ) : Dynamic( color );
			this->mCurrentLine->alpha = (alpha == null()) ? Dynamic( 1.0 ) : Dynamic( alpha );
			this->mCurrentLine->miter_limit = (miterLimit == null()) ? Dynamic( 3.0 ) : Dynamic( miterLimit );
			this->mCurrentLine->pixel_hinting = ((bool((pixelHinting == null())) || bool(!pixelHinting))) ? int( 0 ) : int( ::nme::display::Graphics_obj::PIXEL_HINTING );
		}
		this->mCurrentLine->caps = ::nme::display::Graphics_obj::END_ROUND;
		if ((caps != null())){
			::nme::display::CapsStyle _switch_1 = (caps);
			if (  ( _switch_1==::nme::display::CapsStyle_obj::ROUND)){
				this->mCurrentLine->caps = ::nme::display::Graphics_obj::END_ROUND;
			}
			else if (  ( _switch_1==::nme::display::CapsStyle_obj::SQUARE)){
				this->mCurrentLine->caps = ::nme::display::Graphics_obj::END_SQUARE;
			}
			else if (  ( _switch_1==::nme::display::CapsStyle_obj::NONE)){
				this->mCurrentLine->caps = ::nme::display::Graphics_obj::END_NONE;
			}
		}
		this->mCurrentLine->scale_mode = ::nme::display::Graphics_obj::SCALE_NORMAL;
		if ((scaleMode != null())){
			::nme::display::LineScaleMode _switch_2 = (scaleMode);
			if (  ( _switch_2==::nme::display::LineScaleMode_obj::NORMAL)){
				this->mCurrentLine->scale_mode = ::nme::display::Graphics_obj::SCALE_NORMAL;
			}
			else if (  ( _switch_2==::nme::display::LineScaleMode_obj::VERTICAL)){
				this->mCurrentLine->scale_mode = ::nme::display::Graphics_obj::SCALE_VERTICAL;
			}
			else if (  ( _switch_2==::nme::display::LineScaleMode_obj::HORIZONTAL)){
				this->mCurrentLine->scale_mode = ::nme::display::Graphics_obj::SCALE_HORIZONTAL;
			}
			else if (  ( _switch_2==::nme::display::LineScaleMode_obj::NONE)){
				this->mCurrentLine->scale_mode = ::nme::display::Graphics_obj::SCALE_NONE;
			}
		}
		this->mCurrentLine->joints = ::nme::display::Graphics_obj::CORNER_ROUND;
		if ((joints != null())){
			::nme::display::JointStyle _switch_3 = (joints);
			if (  ( _switch_3==::nme::display::JointStyle_obj::ROUND)){
				this->mCurrentLine->joints = ::nme::display::Graphics_obj::CORNER_ROUND;
			}
			else if (  ( _switch_3==::nme::display::JointStyle_obj::MITER)){
				this->mCurrentLine->joints = ::nme::display::Graphics_obj::CORNER_MITER;
			}
			else if (  ( _switch_3==::nme::display::JointStyle_obj::BEVEL)){
				this->mCurrentLine->joints = ::nme::display::Graphics_obj::CORNER_BEVEL;
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC8(Graphics_obj,lineStyle,(void))

Void Graphics_obj::lineGradientStyle( ::nme::display::GradientType type,Array< Dynamic > colors,Array< Dynamic > alphas,Array< Dynamic > ratios,::nme::geom::Matrix matrix,::nme::display::SpreadMethod spreadMethod,::nme::display::InterpolationMethod interpolationMethod,Dynamic focalPointRatio){
{
		__SAFE_POINT
		this->mCurrentLine->grad = this->CreateGradient(type,colors,alphas,ratios,matrix,spreadMethod,interpolationMethod,focalPointRatio);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC8(Graphics_obj,lineGradientStyle,(void))

Void Graphics_obj::beginFill( int color,Dynamic alpha){
{
		__SAFE_POINT
		this->ClosePolygon(true);
		this->mFillColour = color;
		this->mFillAlpha = (alpha == null()) ? Dynamic( 1.0 ) : Dynamic( alpha );
		this->mFilling = true;
		this->mSolidGradient = null();
		this->mBitmap = null();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(Graphics_obj,beginFill,(void))

Void Graphics_obj::endFill( ){
{
		__SAFE_POINT
		this->ClosePolygon(true);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Graphics_obj,endFill,(void))

Void Graphics_obj::drawEllipse( double x,double y,double rx,double ry){
{
		__SAFE_POINT
		this->ClosePolygon(false);
		this->moveTo((x + rx),y);
		this->curveTo((rx + x),((-0.4142 * ry) + y),((0.7071 * rx) + x),((-0.7071 * ry) + y));
		this->curveTo(((0.4142 * rx) + x),(-ry + y),x,(-ry + y));
		this->curveTo(((-0.4142 * rx) + x),(-ry + y),((-0.7071 * rx) + x),((-0.7071 * ry) + y));
		this->curveTo((-rx + x),((-0.4142 * ry) + y),(-rx + x),y);
		this->curveTo((-rx + x),((0.4142 * ry) + y),((-0.7071 * rx) + x),((0.7071 * ry) + y));
		this->curveTo(((-0.4142 * rx) + x),(ry + y),x,(ry + y));
		this->curveTo(((0.4142 * rx) + x),(ry + y),((0.7071 * rx) + x),((0.7071 * ry) + y));
		this->curveTo((rx + x),((0.4142 * ry) + y),(rx + x),y);
		this->ClosePolygon(false);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC4(Graphics_obj,drawEllipse,(void))

Void Graphics_obj::drawCircle( double x,double y,double rad){
{
		__SAFE_POINT
		this->drawEllipse(x,y,rad,rad);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC3(Graphics_obj,drawCircle,(void))

Void Graphics_obj::drawRect( double x,double y,double width,double height){
{
		__SAFE_POINT
		this->ClosePolygon(false);
		this->moveTo(x,y);
		this->lineTo((x + width),y);
		this->lineTo((x + width),(y + height));
		this->lineTo(x,(y + height));
		this->lineTo(x,y);
		this->ClosePolygon(false);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC4(Graphics_obj,drawRect,(void))

Void Graphics_obj::drawRoundRect( double x,double y,double width,double height,double ellipseWidth,double ellipseHeight){
{
		__SAFE_POINT
		if ((bool((ellipseHeight < 1)) || bool((ellipseHeight < 1)))){
			this->drawRect(x,y,width,height);
			return null();
		}
		this->ClosePolygon(false);
		double w = (ellipseWidth * 0.5);
		double h = (ellipseHeight * 0.5);
		this->moveTo(x,(y + h));
		this->curveTo(x,y,(x + w),y);
		this->lineTo((((x + width)) - w),y);
		this->curveTo((x + width),y,(x + width),(y + w));
		this->lineTo((x + width),(((y + height)) - h));
		this->curveTo((x + width),(y + height),(((x + width)) - w),(y + height));
		this->lineTo((x + w),(y + height));
		this->curveTo(x,(y + height),x,(((y + height)) - h));
		this->lineTo(x,(y + h));
		this->ClosePolygon(false);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC6(Graphics_obj,drawRoundRect,(void))

Dynamic Graphics_obj::CreateGradient( ::nme::display::GradientType type,Array< Dynamic > colors,Array< Dynamic > alphas,Array< Dynamic > ratios,::nme::geom::Matrix matrix,::nme::display::SpreadMethod spreadMethod,::nme::display::InterpolationMethod interpolationMethod,Dynamic focalPointRatio){
	__SAFE_POINT
	Array< Dynamic > points = Array_obj< Dynamic >::__new();
	{
		int _g1 = 0;
		int _g = colors->length;
		while((_g1 < _g)){
			__SAFE_POINT
			int i = _g1++;
			struct _Function_3_1{
				inline static Dynamic Block( Array< Dynamic > &colors,Array< Dynamic > &ratios,int &i,Array< Dynamic > &alphas){
					hx::Anon __result = hx::Anon_obj::Create();
					__result->Add(HX_STRING(L"col",3) , colors->__get(i));
					__result->Add(HX_STRING(L"alpha",5) , alphas->__get(i));
					__result->Add(HX_STRING(L"ratio",5) , ratios->__get(i));
					return __result;
				}
			};
			points->push(_Function_3_1::Block(colors,ratios,i,alphas));
		}
	}
	int flags = 0;
	if ((type == ::nme::display::GradientType_obj::RADIAL))
		hx::OrEq(flags,::nme::display::Graphics_obj::RADIAL);
	if ((spreadMethod == ::nme::display::SpreadMethod_obj::REPEAT)){
		hx::OrEq(flags,::nme::display::Graphics_obj::REPEAT);
	}
	else{
		if ((spreadMethod == ::nme::display::SpreadMethod_obj::REFLECT))
			hx::OrEq(flags,::nme::display::Graphics_obj::REFLECT);
	}
	if ((matrix == null())){
		matrix = ::nme::geom::Matrix_obj::__new(null(),null(),null(),null(),null(),null());
		matrix->createGradientBox(25,25,null(),null(),null());
	}
	else{
		matrix = matrix->clone();
	}
	double focal = (focalPointRatio == null()) ? Dynamic( 0 ) : Dynamic( focalPointRatio );
	struct _Function_1_1{
		inline static Dynamic Block( ::nme::geom::Matrix &matrix,double &focal,Array< Dynamic > &points,int &flags){
			hx::Anon __result = hx::Anon_obj::Create();
			__result->Add(HX_STRING(L"points",6) , points);
			__result->Add(HX_STRING(L"matrix",6) , matrix);
			__result->Add(HX_STRING(L"flags",5) , flags);
			__result->Add(HX_STRING(L"focal",5) , focal);
			return __result;
		}
	};
	return _Function_1_1::Block(matrix,focal,points,flags);
}


HX_DEFINE_DYNAMIC_FUNC8(Graphics_obj,CreateGradient,return )

Void Graphics_obj::beginGradientFill( ::nme::display::GradientType type,Array< Dynamic > colors,Array< Dynamic > alphas,Array< Dynamic > ratios,::nme::geom::Matrix matrix,::nme::display::SpreadMethod spreadMethod,::nme::display::InterpolationMethod interpolationMethod,Dynamic focalPointRatio){
{
		__SAFE_POINT
		this->ClosePolygon(true);
		this->mFilling = true;
		this->mBitmap = null();
		this->mSolidGradient = this->CreateGradient(type,colors,alphas,ratios,matrix,spreadMethod,interpolationMethod,focalPointRatio);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC8(Graphics_obj,beginGradientFill,(void))

Void Graphics_obj::beginBitmapFill( ::nme::display::BitmapData bitmap,::nme::geom::Matrix matrix,Dynamic in_repeat,Dynamic in_smooth){
{
		__SAFE_POINT
		this->ClosePolygon(true);
		bool repeat = (in_repeat == null()) ? Dynamic( true ) : Dynamic( in_repeat );
		bool smooth = (in_smooth == null()) ? Dynamic( false ) : Dynamic( in_smooth );
		this->mFilling = true;
		this->mSolidGradient = null();
		struct _Function_1_1{
			inline static Dynamic Block( bool &repeat,::nme::display::BitmapData &bitmap,::nme::geom::Matrix &matrix,bool &smooth){
				hx::Anon __result = hx::Anon_obj::Create();
				__result->Add(HX_STRING(L"texture_buffer",14) , bitmap->handle());
				__result->Add(HX_STRING(L"matrix",6) , (matrix == null()) ? ::nme::geom::Matrix( matrix ) : ::nme::geom::Matrix( matrix->clone() ));
				__result->Add(HX_STRING(L"flags",5) , (int((repeat ? int( ::nme::display::Graphics_obj::BMP_REPEAT ) : int( 0 ))) | int((smooth ? int( ::nme::display::Graphics_obj::BMP_SMOOTH ) : int( 0 )))));
				return __result;
			}
		};
		this->mBitmap = _Function_1_1::Block(repeat,bitmap,matrix,smooth);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC4(Graphics_obj,beginBitmapFill,(void))

Void Graphics_obj::RenderGlyph( ::nme::FontHandle inFont,int inChar,double inX,double inY,Dynamic inUseFreeType){
{
		__SAFE_POINT
		this->ClosePolygon(false);
		Dynamic free_type = (inUseFreeType == null()) ? Dynamic( ((bool((this->mSolidGradient == null())) && bool((bool((this->mBitmap == null())) && bool((this->mCurrentLine->thickness == 0)))))) ) : Dynamic( inUseFreeType );
		this->AddDrawable(::nme::display::Graphics_obj::nme_create_glyph_draw_obj(inX,inY,inFont->get_handle(),inChar,this->mFillColour,this->mFillAlpha,(this->mSolidGradient == null()) ? Dynamic( this->mBitmap ) : Dynamic( this->mSolidGradient ),this->mCurrentLine,free_type));
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC5(Graphics_obj,RenderGlyph,(void))

Void Graphics_obj::drawTriangles( Array< double > vertices,Array< int > indices,Array< double > uvtData,::nme::display::TriangleCulling culling){
{
		__SAFE_POINT
		struct _Function_1_1{
			inline static int Block( ::nme::display::TriangleCulling &culling)/* DEF (not block)(ret intern) */{
				::nme::display::TriangleCulling _switch_4 = (culling);
				switch((_switch_4)->GetIndex()){
					case 1: {
						return 0;
					}
					;break;
					case 0: {
						return -1;
					}
					;break;
					case 2: {
						return 1;
					}
					;break;
					default: {
						return null();
					}
				}
			}
		};
		int cull = (culling == null()) ? int( 0 ) : int( _Function_1_1::Block(culling) );
		this->ClosePolygon(false);
		this->AddDrawable(::nme::display::Graphics_obj::nme_create_draw_triangles(vertices,indices,uvtData,cull,this->mFillColour,this->mFillAlpha,this->mBitmap,this->mCurrentLine));
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC4(Graphics_obj,drawTriangles,(void))

Void Graphics_obj::ClearLine( ){
{
		this->mCurrentLine = ::nme::display::LineJob_obj::__new(null(),-1,-1,0.0,0.0,0,1,::nme::display::Graphics_obj::CORNER_ROUND,::nme::display::Graphics_obj::END_ROUND,::nme::display::Graphics_obj::SCALE_NORMAL,3.0);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Graphics_obj,ClearLine,(void))

Void Graphics_obj::clear( ){
{
		__SAFE_POINT
		this->mChanged = true;
		this->mPenX = 0.0;
		this->mPenY = 0.0;
		this->mDrawList = Array_obj< Dynamic >::__new();
		this->mPoints = Array_obj< ::nme::display::GfxPoint >::__new();
		this->mSolidGradient = null();
		this->mBitmap = null();
		this->mFilling = false;
		this->mFillColour = 0;
		this->mFillAlpha = 0.0;
		this->mLastMoveID = 0;
		this->ClearLine();
		this->mLineJobs = Array_obj< ::nme::display::LineJob >::__new();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Graphics_obj,clear,(void))

::nme::geom::Rectangle Graphics_obj::GetExtent( ::nme::geom::Matrix inMatrix){
	__SAFE_POINT
	this->flush();
	::nme::geom::Rectangle result = ::nme::geom::Rectangle_obj::__new(null(),null(),null(),null());
	::nme::display::Graphics_obj::nme_get_extent(this->mDrawList,result,inMatrix,true);
	return result;
}


HX_DEFINE_DYNAMIC_FUNC1(Graphics_obj,GetExtent,return )

Void Graphics_obj::moveTo( double inX,double inY){
{
		__SAFE_POINT
		this->mPenX = inX;
		this->mPenY = inY;
		if (!this->mFilling){
			this->ClosePolygon(false);
		}
		else{
			this->AddLineSegment();
			this->mLastMoveID = this->mPoints->length;
			this->mPoints->push(::nme::display::GfxPoint_obj::__new(this->mPenX,this->mPenY,0.0,0.0,::nme::display::Graphics_obj::MOVE));
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(Graphics_obj,moveTo,(void))

Void Graphics_obj::lineTo( double inX,double inY){
{
		__SAFE_POINT
		int pid = this->mPoints->length;
		if ((pid == 0)){
			this->mPoints->push(::nme::display::GfxPoint_obj::__new(this->mPenX,this->mPenY,0.0,0.0,::nme::display::Graphics_obj::MOVE));
			pid++;
		}
		this->mPenX = inX;
		this->mPenY = inY;
		this->mPoints->push(::nme::display::GfxPoint_obj::__new(this->mPenX,this->mPenY,0.0,0.0,::nme::display::Graphics_obj::LINE));
		if ((bool((this->mCurrentLine->grad != null())) || bool((this->mCurrentLine->alpha > 0)))){
			if ((this->mCurrentLine->point_idx0 < 0))
				this->mCurrentLine->point_idx0 = (pid - 1);
			this->mCurrentLine->point_idx1 = pid;
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(Graphics_obj,lineTo,(void))

Void Graphics_obj::curveTo( double inCX,double inCY,double inX,double inY){
{
		__SAFE_POINT
		int pid = this->mPoints->length;
		if ((pid == 0)){
			this->mPoints->push(::nme::display::GfxPoint_obj::__new(this->mPenX,this->mPenY,0.0,0.0,::nme::display::Graphics_obj::MOVE));
			pid++;
		}
		this->mPenX = inX;
		this->mPenY = inY;
		this->mPoints->push(::nme::display::GfxPoint_obj::__new(inX,inY,inCX,inCY,::nme::display::Graphics_obj::CURVE));
		if ((bool((this->mCurrentLine->grad != null())) || bool((this->mCurrentLine->alpha > 0)))){
			if ((this->mCurrentLine->point_idx0 < 0))
				this->mCurrentLine->point_idx0 = (pid - 1);
			this->mCurrentLine->point_idx1 = pid;
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC4(Graphics_obj,curveTo,(void))

Void Graphics_obj::text( ::String text,Dynamic fontSize,::String fontName,Dynamic bgColor,Dynamic alignX,Dynamic alignY){
{
		__SAFE_POINT
		this->ClosePolygon(true);
		int size = (fontSize == null()) ? Dynamic( ::nme::display::Graphics_obj::defaultFontSize ) : Dynamic( fontSize );
		::String font = (fontName == null()) ? ::String( ::nme::display::Graphics_obj::defaultFontName ) : ::String( fontName );
		this->AddDrawable(::nme::display::Graphics_obj::nme_create_text_drawable(text,font,size,this->mPenX,this->mPenY,this->mCurrentLine->colour,this->mCurrentLine->alpha,bgColor,alignX,alignY));
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC6(Graphics_obj,text,(void))

Void Graphics_obj::flush( ){
{
		__SAFE_POINT
		this->ClosePolygon(true);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Graphics_obj,flush,(void))

bool Graphics_obj::CheckChanged( ){
	__SAFE_POINT
	this->ClosePolygon(true);
	bool result = this->mChanged;
	this->mChanged = false;
	return result;
}


HX_DEFINE_DYNAMIC_FUNC0(Graphics_obj,CheckChanged,return )

Void Graphics_obj::AddDrawable( Dynamic inDrawable){
{
		__SAFE_POINT
		if ((inDrawable == null()))
			return null();
		this->mChanged = true;
		if ((this->mSurface == null())){
			this->mDrawList->push(inDrawable);
		}
		else{
			::nme::display::Graphics_obj::nme_draw_object_to(inDrawable,this->mSurface,::nme::display::Graphics_obj::immediateMatrix,::nme::display::Graphics_obj::immediateMask,null());
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Graphics_obj,AddDrawable,(void))

Void Graphics_obj::AddLineSegment( ){
{
		__SAFE_POINT
		if ((this->mCurrentLine->point_idx1 > 0)){
			this->mLineJobs->push(::nme::display::LineJob_obj::__new(this->mCurrentLine->grad,this->mCurrentLine->point_idx0,this->mCurrentLine->point_idx1,this->mCurrentLine->thickness,this->mCurrentLine->alpha,this->mCurrentLine->colour,this->mCurrentLine->pixel_hinting,this->mCurrentLine->joints,this->mCurrentLine->caps,this->mCurrentLine->scale_mode,this->mCurrentLine->miter_limit));
		}
		this->mCurrentLine->point_idx0 = this->mCurrentLine->point_idx1 = -1;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Graphics_obj,AddLineSegment,(void))

Void Graphics_obj::ClosePolygon( bool inCancelFill){
{
		__SAFE_POINT
		int l = this->mPoints->length;
		if ((l > 0)){
			if ((l > 1)){
				if ((bool(this->mFilling) && bool((l > 2)))){
					if ((bool((this->mPoints[this->mLastMoveID]->x != this->mPoints[(l - 1)]->x)) || bool((this->mPoints[this->mLastMoveID]->y != this->mPoints[(l - 1)]->y)))){
						this->lineTo(this->mPoints[this->mLastMoveID]->x,this->mPoints[this->mLastMoveID]->y);
					}
				}
				this->AddLineSegment();
				this->AddDrawable(::nme::display::Graphics_obj::nme_create_draw_obj(this->mPoints,this->mFillColour,this->mFillAlpha,(this->mSolidGradient == null()) ? Dynamic( this->mBitmap ) : Dynamic( this->mSolidGradient ),this->mLineJobs));
			}
			this->mLineJobs = Array_obj< ::nme::display::LineJob >::__new();
			this->mPoints = Array_obj< ::nme::display::GfxPoint >::__new();
		}
		if (inCancelFill){
			this->mFillAlpha = 0;
			this->mSolidGradient = null();
			this->mBitmap = null();
			this->mFilling = false;
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Graphics_obj,ClosePolygon,(void))

Void Graphics_obj::AddToMask( Dynamic ioMask,::nme::geom::Matrix inMatrix,Dynamic inSurface){
{
		__SAFE_POINT
		if ((this->mDrawList->length > 0)){
			Dynamic dest = (inSurface == null()) ? Dynamic( ::nme::Manager_obj::getScreen() ) : Dynamic( inSurface );
			::nme::display::Graphics_obj::nme_add_to_mask(this->mDrawList,dest,ioMask,inMatrix);
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC3(Graphics_obj,AddToMask,(void))

Dynamic Graphics_obj::CreateMask( ::nme::geom::Matrix inMatrix){
	__SAFE_POINT
	Dynamic mask = ::nme::display::Graphics_obj::nme_create_mask();
	this->AddToMask(mask,inMatrix,null());
	return mask;
}


HX_DEFINE_DYNAMIC_FUNC1(Graphics_obj,CreateMask,return )

Void Graphics_obj::SetScale9Grid( ::nme::geom::Rectangle inRect,double inSX,double inSY,::nme::geom::Rectangle inExtent){
{
		__SAFE_POINT
		::nme::display::Graphics_obj::nme_set_scale9_grid(inRect,inSX,inSY,inExtent);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC4(Graphics_obj,SetScale9Grid,(void))

::String Graphics_obj::defaultFontName;

int Graphics_obj::defaultFontSize;

::nme::geom::Matrix Graphics_obj::immediateMatrix;

Dynamic Graphics_obj::immediateMask;

int Graphics_obj::TOP;

int Graphics_obj::CENTER;

int Graphics_obj::BOTTOM;

int Graphics_obj::LEFT;

int Graphics_obj::RIGHT;

int Graphics_obj::RADIAL;

int Graphics_obj::REPEAT;

int Graphics_obj::REFLECT;

int Graphics_obj::EDGE_MASK;

int Graphics_obj::EDGE_CLAMP;

int Graphics_obj::EDGE_REPEAT;

int Graphics_obj::EDGE_UNCHECKED;

int Graphics_obj::EDGE_REPEAT_POW2;

int Graphics_obj::END_NONE;

int Graphics_obj::END_ROUND;

int Graphics_obj::END_SQUARE;

int Graphics_obj::END_MASK;

int Graphics_obj::END_SHIFT;

int Graphics_obj::CORNER_ROUND;

int Graphics_obj::CORNER_MITER;

int Graphics_obj::CORNER_BEVEL;

int Graphics_obj::CORNER_MASK;

int Graphics_obj::CORNER_SHIFT;

int Graphics_obj::PIXEL_HINTING;

int Graphics_obj::BMP_REPEAT;

int Graphics_obj::BMP_SMOOTH;

int Graphics_obj::SCALE_NONE;

int Graphics_obj::SCALE_VERTICAL;

int Graphics_obj::SCALE_HORIZONTAL;

int Graphics_obj::SCALE_NORMAL;

int Graphics_obj::MOVE;

int Graphics_obj::LINE;

int Graphics_obj::CURVE;

int Graphics_obj::BLEND_ADD;

int Graphics_obj::BLEND_ALPHA;

int Graphics_obj::BLEND_DARKEN;

int Graphics_obj::BLEND_DIFFERENCE;

int Graphics_obj::BLEND_ERASE;

int Graphics_obj::BLEND_HARDLIGHT;

int Graphics_obj::BLEND_INVERT;

int Graphics_obj::BLEND_LAYER;

int Graphics_obj::BLEND_LIGHTEN;

int Graphics_obj::BLEND_MULTIPLY;

int Graphics_obj::BLEND_NORMAL;

int Graphics_obj::BLEND_OVERLAY;

int Graphics_obj::BLEND_SCREEN;

int Graphics_obj::BLEND_SUBTRACT;

int Graphics_obj::BLEND_SHADER;

Void Graphics_obj::setBlendMode( int inBlendMode){
{
		__SAFE_POINT
		::nme::display::Graphics_obj::nme_set_blend_mode(inBlendMode);
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Graphics_obj,setBlendMode,(void))

Dynamic Graphics_obj::nme_draw_object_to;

Dynamic Graphics_obj::nme_draw_objects_to;

Dynamic Graphics_obj::nme_hit_object;

Dynamic Graphics_obj::nme_create_blit_drawable;

Dynamic Graphics_obj::nme_create_draw_obj;

Dynamic Graphics_obj::nme_create_text_drawable;

Dynamic Graphics_obj::nme_create_draw_triangles;

Dynamic Graphics_obj::nme_get_clip_rect;

Dynamic Graphics_obj::nme_set_clip_rect;

Dynamic Graphics_obj::nme_get_extent;

Dynamic Graphics_obj::nme_create_glyph_draw_obj;

Dynamic Graphics_obj::nme_create_mask;

Dynamic Graphics_obj::nme_add_to_mask;

Dynamic Graphics_obj::nme_set_scale9_grid;

Dynamic Graphics_obj::nme_set_blend_mode;


Graphics_obj::Graphics_obj()
{
}

void Graphics_obj::__Mark()
{
	hx::MarkMember(mSurface);
	hx::MarkMember(mChanged);
	hx::MarkMember(mPoints);
	hx::MarkMember(mSolid);
	hx::MarkMember(mFilling);
	hx::MarkMember(mFillColour);
	hx::MarkMember(mFillAlpha);
	hx::MarkMember(mSolidGradient);
	hx::MarkMember(mBitmap);
	hx::MarkMember(mCurrentLine);
	hx::MarkMember(mLineJobs);
	hx::MarkMember(mDrawList);
	hx::MarkMember(mLineDraws);
	hx::MarkMember(mPenX);
	hx::MarkMember(mPenY);
	hx::MarkMember(mLastMoveID);
}

Dynamic Graphics_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 3:
		if (!memcmp(inName.__s,L"TOP",sizeof(wchar_t)*3) ) { return TOP; }
		break;
	case 4:
		if (!memcmp(inName.__s,L"LEFT",sizeof(wchar_t)*4) ) { return LEFT; }
		if (!memcmp(inName.__s,L"MOVE",sizeof(wchar_t)*4) ) { return MOVE; }
		if (!memcmp(inName.__s,L"LINE",sizeof(wchar_t)*4) ) { return LINE; }
		if (!memcmp(inName.__s,L"blit",sizeof(wchar_t)*4) ) { return blit_dyn(); }
		if (!memcmp(inName.__s,L"text",sizeof(wchar_t)*4) ) { return text_dyn(); }
		break;
	case 5:
		if (!memcmp(inName.__s,L"RIGHT",sizeof(wchar_t)*5) ) { return RIGHT; }
		if (!memcmp(inName.__s,L"CURVE",sizeof(wchar_t)*5) ) { return CURVE; }
		if (!memcmp(inName.__s,L"mPenX",sizeof(wchar_t)*5) ) { return mPenX; }
		if (!memcmp(inName.__s,L"mPenY",sizeof(wchar_t)*5) ) { return mPenY; }
		if (!memcmp(inName.__s,L"clear",sizeof(wchar_t)*5) ) { return clear_dyn(); }
		if (!memcmp(inName.__s,L"flush",sizeof(wchar_t)*5) ) { return flush_dyn(); }
		break;
	case 6:
		if (!memcmp(inName.__s,L"CENTER",sizeof(wchar_t)*6) ) { return CENTER; }
		if (!memcmp(inName.__s,L"BOTTOM",sizeof(wchar_t)*6) ) { return BOTTOM; }
		if (!memcmp(inName.__s,L"RADIAL",sizeof(wchar_t)*6) ) { return RADIAL; }
		if (!memcmp(inName.__s,L"REPEAT",sizeof(wchar_t)*6) ) { return REPEAT; }
		if (!memcmp(inName.__s,L"mSolid",sizeof(wchar_t)*6) ) { return mSolid; }
		if (!memcmp(inName.__s,L"render",sizeof(wchar_t)*6) ) { return render_dyn(); }
		if (!memcmp(inName.__s,L"moveTo",sizeof(wchar_t)*6) ) { return moveTo_dyn(); }
		if (!memcmp(inName.__s,L"lineTo",sizeof(wchar_t)*6) ) { return lineTo_dyn(); }
		break;
	case 7:
		if (!memcmp(inName.__s,L"REFLECT",sizeof(wchar_t)*7) ) { return REFLECT; }
		if (!memcmp(inName.__s,L"mPoints",sizeof(wchar_t)*7) ) { return mPoints; }
		if (!memcmp(inName.__s,L"mBitmap",sizeof(wchar_t)*7) ) { return mBitmap; }
		if (!memcmp(inName.__s,L"hitTest",sizeof(wchar_t)*7) ) { return hitTest_dyn(); }
		if (!memcmp(inName.__s,L"endFill",sizeof(wchar_t)*7) ) { return endFill_dyn(); }
		if (!memcmp(inName.__s,L"curveTo",sizeof(wchar_t)*7) ) { return curveTo_dyn(); }
		break;
	case 8:
		if (!memcmp(inName.__s,L"END_NONE",sizeof(wchar_t)*8) ) { return END_NONE; }
		if (!memcmp(inName.__s,L"END_MASK",sizeof(wchar_t)*8) ) { return END_MASK; }
		if (!memcmp(inName.__s,L"mSurface",sizeof(wchar_t)*8) ) { return mSurface; }
		if (!memcmp(inName.__s,L"mChanged",sizeof(wchar_t)*8) ) { return mChanged; }
		if (!memcmp(inName.__s,L"mFilling",sizeof(wchar_t)*8) ) { return mFilling; }
		if (!memcmp(inName.__s,L"drawRect",sizeof(wchar_t)*8) ) { return drawRect_dyn(); }
		break;
	case 9:
		if (!memcmp(inName.__s,L"EDGE_MASK",sizeof(wchar_t)*9) ) { return EDGE_MASK; }
		if (!memcmp(inName.__s,L"END_ROUND",sizeof(wchar_t)*9) ) { return END_ROUND; }
		if (!memcmp(inName.__s,L"END_SHIFT",sizeof(wchar_t)*9) ) { return END_SHIFT; }
		if (!memcmp(inName.__s,L"BLEND_ADD",sizeof(wchar_t)*9) ) { return BLEND_ADD; }
		if (!memcmp(inName.__s,L"mLineJobs",sizeof(wchar_t)*9) ) { return mLineJobs; }
		if (!memcmp(inName.__s,L"mDrawList",sizeof(wchar_t)*9) ) { return mDrawList; }
		if (!memcmp(inName.__s,L"lineStyle",sizeof(wchar_t)*9) ) { return lineStyle_dyn(); }
		if (!memcmp(inName.__s,L"beginFill",sizeof(wchar_t)*9) ) { return beginFill_dyn(); }
		if (!memcmp(inName.__s,L"ClearLine",sizeof(wchar_t)*9) ) { return ClearLine_dyn(); }
		if (!memcmp(inName.__s,L"GetExtent",sizeof(wchar_t)*9) ) { return GetExtent_dyn(); }
		if (!memcmp(inName.__s,L"AddToMask",sizeof(wchar_t)*9) ) { return AddToMask_dyn(); }
		break;
	case 10:
		if (!memcmp(inName.__s,L"EDGE_CLAMP",sizeof(wchar_t)*10) ) { return EDGE_CLAMP; }
		if (!memcmp(inName.__s,L"END_SQUARE",sizeof(wchar_t)*10) ) { return END_SQUARE; }
		if (!memcmp(inName.__s,L"BMP_REPEAT",sizeof(wchar_t)*10) ) { return BMP_REPEAT; }
		if (!memcmp(inName.__s,L"BMP_SMOOTH",sizeof(wchar_t)*10) ) { return BMP_SMOOTH; }
		if (!memcmp(inName.__s,L"SCALE_NONE",sizeof(wchar_t)*10) ) { return SCALE_NONE; }
		if (!memcmp(inName.__s,L"mFillAlpha",sizeof(wchar_t)*10) ) { return mFillAlpha; }
		if (!memcmp(inName.__s,L"mLineDraws",sizeof(wchar_t)*10) ) { return mLineDraws; }
		if (!memcmp(inName.__s,L"SetSurface",sizeof(wchar_t)*10) ) { return SetSurface_dyn(); }
		if (!memcmp(inName.__s,L"drawCircle",sizeof(wchar_t)*10) ) { return drawCircle_dyn(); }
		if (!memcmp(inName.__s,L"CreateMask",sizeof(wchar_t)*10) ) { return CreateMask_dyn(); }
		break;
	case 11:
		if (!memcmp(inName.__s,L"EDGE_REPEAT",sizeof(wchar_t)*11) ) { return EDGE_REPEAT; }
		if (!memcmp(inName.__s,L"CORNER_MASK",sizeof(wchar_t)*11) ) { return CORNER_MASK; }
		if (!memcmp(inName.__s,L"BLEND_ALPHA",sizeof(wchar_t)*11) ) { return BLEND_ALPHA; }
		if (!memcmp(inName.__s,L"BLEND_ERASE",sizeof(wchar_t)*11) ) { return BLEND_ERASE; }
		if (!memcmp(inName.__s,L"BLEND_LAYER",sizeof(wchar_t)*11) ) { return BLEND_LAYER; }
		if (!memcmp(inName.__s,L"mFillColour",sizeof(wchar_t)*11) ) { return mFillColour; }
		if (!memcmp(inName.__s,L"mLastMoveID",sizeof(wchar_t)*11) ) { return mLastMoveID; }
		if (!memcmp(inName.__s,L"drawEllipse",sizeof(wchar_t)*11) ) { return drawEllipse_dyn(); }
		if (!memcmp(inName.__s,L"RenderGlyph",sizeof(wchar_t)*11) ) { return RenderGlyph_dyn(); }
		if (!memcmp(inName.__s,L"AddDrawable",sizeof(wchar_t)*11) ) { return AddDrawable_dyn(); }
		break;
	case 12:
		if (!memcmp(inName.__s,L"CORNER_ROUND",sizeof(wchar_t)*12) ) { return CORNER_ROUND; }
		if (!memcmp(inName.__s,L"CORNER_MITER",sizeof(wchar_t)*12) ) { return CORNER_MITER; }
		if (!memcmp(inName.__s,L"CORNER_BEVEL",sizeof(wchar_t)*12) ) { return CORNER_BEVEL; }
		if (!memcmp(inName.__s,L"CORNER_SHIFT",sizeof(wchar_t)*12) ) { return CORNER_SHIFT; }
		if (!memcmp(inName.__s,L"SCALE_NORMAL",sizeof(wchar_t)*12) ) { return SCALE_NORMAL; }
		if (!memcmp(inName.__s,L"BLEND_DARKEN",sizeof(wchar_t)*12) ) { return BLEND_DARKEN; }
		if (!memcmp(inName.__s,L"BLEND_INVERT",sizeof(wchar_t)*12) ) { return BLEND_INVERT; }
		if (!memcmp(inName.__s,L"BLEND_NORMAL",sizeof(wchar_t)*12) ) { return BLEND_NORMAL; }
		if (!memcmp(inName.__s,L"BLEND_SCREEN",sizeof(wchar_t)*12) ) { return BLEND_SCREEN; }
		if (!memcmp(inName.__s,L"BLEND_SHADER",sizeof(wchar_t)*12) ) { return BLEND_SHADER; }
		if (!memcmp(inName.__s,L"setBlendMode",sizeof(wchar_t)*12) ) { return setBlendMode_dyn(); }
		if (!memcmp(inName.__s,L"mCurrentLine",sizeof(wchar_t)*12) ) { return mCurrentLine; }
		if (!memcmp(inName.__s,L"CheckChanged",sizeof(wchar_t)*12) ) { return CheckChanged_dyn(); }
		if (!memcmp(inName.__s,L"ClosePolygon",sizeof(wchar_t)*12) ) { return ClosePolygon_dyn(); }
		break;
	case 13:
		if (!memcmp(inName.__s,L"immediateMask",sizeof(wchar_t)*13) ) { return immediateMask; }
		if (!memcmp(inName.__s,L"PIXEL_HINTING",sizeof(wchar_t)*13) ) { return PIXEL_HINTING; }
		if (!memcmp(inName.__s,L"BLEND_LIGHTEN",sizeof(wchar_t)*13) ) { return BLEND_LIGHTEN; }
		if (!memcmp(inName.__s,L"BLEND_OVERLAY",sizeof(wchar_t)*13) ) { return BLEND_OVERLAY; }
		if (!memcmp(inName.__s,L"drawRoundRect",sizeof(wchar_t)*13) ) { return drawRoundRect_dyn(); }
		if (!memcmp(inName.__s,L"drawTriangles",sizeof(wchar_t)*13) ) { return drawTriangles_dyn(); }
		if (!memcmp(inName.__s,L"SetScale9Grid",sizeof(wchar_t)*13) ) { return SetScale9Grid_dyn(); }
		break;
	case 14:
		if (!memcmp(inName.__s,L"EDGE_UNCHECKED",sizeof(wchar_t)*14) ) { return EDGE_UNCHECKED; }
		if (!memcmp(inName.__s,L"SCALE_VERTICAL",sizeof(wchar_t)*14) ) { return SCALE_VERTICAL; }
		if (!memcmp(inName.__s,L"BLEND_MULTIPLY",sizeof(wchar_t)*14) ) { return BLEND_MULTIPLY; }
		if (!memcmp(inName.__s,L"BLEND_SUBTRACT",sizeof(wchar_t)*14) ) { return BLEND_SUBTRACT; }
		if (!memcmp(inName.__s,L"nme_hit_object",sizeof(wchar_t)*14) ) { return nme_hit_object; }
		if (!memcmp(inName.__s,L"nme_get_extent",sizeof(wchar_t)*14) ) { return nme_get_extent; }
		if (!memcmp(inName.__s,L"mSolidGradient",sizeof(wchar_t)*14) ) { return mSolidGradient; }
		if (!memcmp(inName.__s,L"GetSurfaceRect",sizeof(wchar_t)*14) ) { return GetSurfaceRect_dyn(); }
		if (!memcmp(inName.__s,L"CreateGradient",sizeof(wchar_t)*14) ) { return CreateGradient_dyn(); }
		if (!memcmp(inName.__s,L"AddLineSegment",sizeof(wchar_t)*14) ) { return AddLineSegment_dyn(); }
		break;
	case 15:
		if (!memcmp(inName.__s,L"defaultFontName",sizeof(wchar_t)*15) ) { return defaultFontName; }
		if (!memcmp(inName.__s,L"defaultFontSize",sizeof(wchar_t)*15) ) { return defaultFontSize; }
		if (!memcmp(inName.__s,L"immediateMatrix",sizeof(wchar_t)*15) ) { return immediateMatrix; }
		if (!memcmp(inName.__s,L"BLEND_HARDLIGHT",sizeof(wchar_t)*15) ) { return BLEND_HARDLIGHT; }
		if (!memcmp(inName.__s,L"nme_create_mask",sizeof(wchar_t)*15) ) { return nme_create_mask; }
		if (!memcmp(inName.__s,L"nme_add_to_mask",sizeof(wchar_t)*15) ) { return nme_add_to_mask; }
		if (!memcmp(inName.__s,L"beginBitmapFill",sizeof(wchar_t)*15) ) { return beginBitmapFill_dyn(); }
		break;
	case 16:
		if (!memcmp(inName.__s,L"EDGE_REPEAT_POW2",sizeof(wchar_t)*16) ) { return EDGE_REPEAT_POW2; }
		if (!memcmp(inName.__s,L"SCALE_HORIZONTAL",sizeof(wchar_t)*16) ) { return SCALE_HORIZONTAL; }
		if (!memcmp(inName.__s,L"BLEND_DIFFERENCE",sizeof(wchar_t)*16) ) { return BLEND_DIFFERENCE; }
		break;
	case 17:
		if (!memcmp(inName.__s,L"nme_get_clip_rect",sizeof(wchar_t)*17) ) { return nme_get_clip_rect; }
		if (!memcmp(inName.__s,L"nme_set_clip_rect",sizeof(wchar_t)*17) ) { return nme_set_clip_rect; }
		if (!memcmp(inName.__s,L"lineGradientStyle",sizeof(wchar_t)*17) ) { return lineGradientStyle_dyn(); }
		if (!memcmp(inName.__s,L"beginGradientFill",sizeof(wchar_t)*17) ) { return beginGradientFill_dyn(); }
		break;
	case 18:
		if (!memcmp(inName.__s,L"nme_draw_object_to",sizeof(wchar_t)*18) ) { return nme_draw_object_to; }
		if (!memcmp(inName.__s,L"nme_set_blend_mode",sizeof(wchar_t)*18) ) { return nme_set_blend_mode; }
		break;
	case 19:
		if (!memcmp(inName.__s,L"nme_draw_objects_to",sizeof(wchar_t)*19) ) { return nme_draw_objects_to; }
		if (!memcmp(inName.__s,L"nme_create_draw_obj",sizeof(wchar_t)*19) ) { return nme_create_draw_obj; }
		if (!memcmp(inName.__s,L"nme_set_scale9_grid",sizeof(wchar_t)*19) ) { return nme_set_scale9_grid; }
		break;
	case 24:
		if (!memcmp(inName.__s,L"nme_create_blit_drawable",sizeof(wchar_t)*24) ) { return nme_create_blit_drawable; }
		if (!memcmp(inName.__s,L"nme_create_text_drawable",sizeof(wchar_t)*24) ) { return nme_create_text_drawable; }
		break;
	case 25:
		if (!memcmp(inName.__s,L"nme_create_draw_triangles",sizeof(wchar_t)*25) ) { return nme_create_draw_triangles; }
		if (!memcmp(inName.__s,L"nme_create_glyph_draw_obj",sizeof(wchar_t)*25) ) { return nme_create_glyph_draw_obj; }
	}
	return super::__Field(inName);
}

Dynamic Graphics_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	switch(inName.length) {
	case 3:
		if (!memcmp(inName.__s,L"TOP",sizeof(wchar_t)*3) ) { TOP=inValue.Cast< int >(); return inValue; }
		break;
	case 4:
		if (!memcmp(inName.__s,L"LEFT",sizeof(wchar_t)*4) ) { LEFT=inValue.Cast< int >(); return inValue; }
		if (!memcmp(inName.__s,L"MOVE",sizeof(wchar_t)*4) ) { MOVE=inValue.Cast< int >(); return inValue; }
		if (!memcmp(inName.__s,L"LINE",sizeof(wchar_t)*4) ) { LINE=inValue.Cast< int >(); return inValue; }
		break;
	case 5:
		if (!memcmp(inName.__s,L"RIGHT",sizeof(wchar_t)*5) ) { RIGHT=inValue.Cast< int >(); return inValue; }
		if (!memcmp(inName.__s,L"CURVE",sizeof(wchar_t)*5) ) { CURVE=inValue.Cast< int >(); return inValue; }
		if (!memcmp(inName.__s,L"mPenX",sizeof(wchar_t)*5) ) { mPenX=inValue.Cast< double >(); return inValue; }
		if (!memcmp(inName.__s,L"mPenY",sizeof(wchar_t)*5) ) { mPenY=inValue.Cast< double >(); return inValue; }
		break;
	case 6:
		if (!memcmp(inName.__s,L"CENTER",sizeof(wchar_t)*6) ) { CENTER=inValue.Cast< int >(); return inValue; }
		if (!memcmp(inName.__s,L"BOTTOM",sizeof(wchar_t)*6) ) { BOTTOM=inValue.Cast< int >(); return inValue; }
		if (!memcmp(inName.__s,L"RADIAL",sizeof(wchar_t)*6) ) { RADIAL=inValue.Cast< int >(); return inValue; }
		if (!memcmp(inName.__s,L"REPEAT",sizeof(wchar_t)*6) ) { REPEAT=inValue.Cast< int >(); return inValue; }
		if (!memcmp(inName.__s,L"mSolid",sizeof(wchar_t)*6) ) { mSolid=inValue.Cast< bool >(); return inValue; }
		break;
	case 7:
		if (!memcmp(inName.__s,L"REFLECT",sizeof(wchar_t)*7) ) { REFLECT=inValue.Cast< int >(); return inValue; }
		if (!memcmp(inName.__s,L"mPoints",sizeof(wchar_t)*7) ) { mPoints=inValue.Cast< Array< ::nme::display::GfxPoint > >(); return inValue; }
		if (!memcmp(inName.__s,L"mBitmap",sizeof(wchar_t)*7) ) { mBitmap=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 8:
		if (!memcmp(inName.__s,L"END_NONE",sizeof(wchar_t)*8) ) { END_NONE=inValue.Cast< int >(); return inValue; }
		if (!memcmp(inName.__s,L"END_MASK",sizeof(wchar_t)*8) ) { END_MASK=inValue.Cast< int >(); return inValue; }
		if (!memcmp(inName.__s,L"mSurface",sizeof(wchar_t)*8) ) { mSurface=inValue.Cast< Dynamic >(); return inValue; }
		if (!memcmp(inName.__s,L"mChanged",sizeof(wchar_t)*8) ) { mChanged=inValue.Cast< bool >(); return inValue; }
		if (!memcmp(inName.__s,L"mFilling",sizeof(wchar_t)*8) ) { mFilling=inValue.Cast< bool >(); return inValue; }
		break;
	case 9:
		if (!memcmp(inName.__s,L"EDGE_MASK",sizeof(wchar_t)*9) ) { EDGE_MASK=inValue.Cast< int >(); return inValue; }
		if (!memcmp(inName.__s,L"END_ROUND",sizeof(wchar_t)*9) ) { END_ROUND=inValue.Cast< int >(); return inValue; }
		if (!memcmp(inName.__s,L"END_SHIFT",sizeof(wchar_t)*9) ) { END_SHIFT=inValue.Cast< int >(); return inValue; }
		if (!memcmp(inName.__s,L"BLEND_ADD",sizeof(wchar_t)*9) ) { BLEND_ADD=inValue.Cast< int >(); return inValue; }
		if (!memcmp(inName.__s,L"mLineJobs",sizeof(wchar_t)*9) ) { mLineJobs=inValue.Cast< Array< ::nme::display::LineJob > >(); return inValue; }
		if (!memcmp(inName.__s,L"mDrawList",sizeof(wchar_t)*9) ) { mDrawList=inValue.Cast< Array< Dynamic > >(); return inValue; }
		break;
	case 10:
		if (!memcmp(inName.__s,L"EDGE_CLAMP",sizeof(wchar_t)*10) ) { EDGE_CLAMP=inValue.Cast< int >(); return inValue; }
		if (!memcmp(inName.__s,L"END_SQUARE",sizeof(wchar_t)*10) ) { END_SQUARE=inValue.Cast< int >(); return inValue; }
		if (!memcmp(inName.__s,L"BMP_REPEAT",sizeof(wchar_t)*10) ) { BMP_REPEAT=inValue.Cast< int >(); return inValue; }
		if (!memcmp(inName.__s,L"BMP_SMOOTH",sizeof(wchar_t)*10) ) { BMP_SMOOTH=inValue.Cast< int >(); return inValue; }
		if (!memcmp(inName.__s,L"SCALE_NONE",sizeof(wchar_t)*10) ) { SCALE_NONE=inValue.Cast< int >(); return inValue; }
		if (!memcmp(inName.__s,L"mFillAlpha",sizeof(wchar_t)*10) ) { mFillAlpha=inValue.Cast< double >(); return inValue; }
		if (!memcmp(inName.__s,L"mLineDraws",sizeof(wchar_t)*10) ) { mLineDraws=inValue.Cast< Array< Dynamic > >(); return inValue; }
		break;
	case 11:
		if (!memcmp(inName.__s,L"EDGE_REPEAT",sizeof(wchar_t)*11) ) { EDGE_REPEAT=inValue.Cast< int >(); return inValue; }
		if (!memcmp(inName.__s,L"CORNER_MASK",sizeof(wchar_t)*11) ) { CORNER_MASK=inValue.Cast< int >(); return inValue; }
		if (!memcmp(inName.__s,L"BLEND_ALPHA",sizeof(wchar_t)*11) ) { BLEND_ALPHA=inValue.Cast< int >(); return inValue; }
		if (!memcmp(inName.__s,L"BLEND_ERASE",sizeof(wchar_t)*11) ) { BLEND_ERASE=inValue.Cast< int >(); return inValue; }
		if (!memcmp(inName.__s,L"BLEND_LAYER",sizeof(wchar_t)*11) ) { BLEND_LAYER=inValue.Cast< int >(); return inValue; }
		if (!memcmp(inName.__s,L"mFillColour",sizeof(wchar_t)*11) ) { mFillColour=inValue.Cast< int >(); return inValue; }
		if (!memcmp(inName.__s,L"mLastMoveID",sizeof(wchar_t)*11) ) { mLastMoveID=inValue.Cast< int >(); return inValue; }
		break;
	case 12:
		if (!memcmp(inName.__s,L"CORNER_ROUND",sizeof(wchar_t)*12) ) { CORNER_ROUND=inValue.Cast< int >(); return inValue; }
		if (!memcmp(inName.__s,L"CORNER_MITER",sizeof(wchar_t)*12) ) { CORNER_MITER=inValue.Cast< int >(); return inValue; }
		if (!memcmp(inName.__s,L"CORNER_BEVEL",sizeof(wchar_t)*12) ) { CORNER_BEVEL=inValue.Cast< int >(); return inValue; }
		if (!memcmp(inName.__s,L"CORNER_SHIFT",sizeof(wchar_t)*12) ) { CORNER_SHIFT=inValue.Cast< int >(); return inValue; }
		if (!memcmp(inName.__s,L"SCALE_NORMAL",sizeof(wchar_t)*12) ) { SCALE_NORMAL=inValue.Cast< int >(); return inValue; }
		if (!memcmp(inName.__s,L"BLEND_DARKEN",sizeof(wchar_t)*12) ) { BLEND_DARKEN=inValue.Cast< int >(); return inValue; }
		if (!memcmp(inName.__s,L"BLEND_INVERT",sizeof(wchar_t)*12) ) { BLEND_INVERT=inValue.Cast< int >(); return inValue; }
		if (!memcmp(inName.__s,L"BLEND_NORMAL",sizeof(wchar_t)*12) ) { BLEND_NORMAL=inValue.Cast< int >(); return inValue; }
		if (!memcmp(inName.__s,L"BLEND_SCREEN",sizeof(wchar_t)*12) ) { BLEND_SCREEN=inValue.Cast< int >(); return inValue; }
		if (!memcmp(inName.__s,L"BLEND_SHADER",sizeof(wchar_t)*12) ) { BLEND_SHADER=inValue.Cast< int >(); return inValue; }
		if (!memcmp(inName.__s,L"mCurrentLine",sizeof(wchar_t)*12) ) { mCurrentLine=inValue.Cast< ::nme::display::LineJob >(); return inValue; }
		break;
	case 13:
		if (!memcmp(inName.__s,L"immediateMask",sizeof(wchar_t)*13) ) { immediateMask=inValue.Cast< Dynamic >(); return inValue; }
		if (!memcmp(inName.__s,L"PIXEL_HINTING",sizeof(wchar_t)*13) ) { PIXEL_HINTING=inValue.Cast< int >(); return inValue; }
		if (!memcmp(inName.__s,L"BLEND_LIGHTEN",sizeof(wchar_t)*13) ) { BLEND_LIGHTEN=inValue.Cast< int >(); return inValue; }
		if (!memcmp(inName.__s,L"BLEND_OVERLAY",sizeof(wchar_t)*13) ) { BLEND_OVERLAY=inValue.Cast< int >(); return inValue; }
		break;
	case 14:
		if (!memcmp(inName.__s,L"EDGE_UNCHECKED",sizeof(wchar_t)*14) ) { EDGE_UNCHECKED=inValue.Cast< int >(); return inValue; }
		if (!memcmp(inName.__s,L"SCALE_VERTICAL",sizeof(wchar_t)*14) ) { SCALE_VERTICAL=inValue.Cast< int >(); return inValue; }
		if (!memcmp(inName.__s,L"BLEND_MULTIPLY",sizeof(wchar_t)*14) ) { BLEND_MULTIPLY=inValue.Cast< int >(); return inValue; }
		if (!memcmp(inName.__s,L"BLEND_SUBTRACT",sizeof(wchar_t)*14) ) { BLEND_SUBTRACT=inValue.Cast< int >(); return inValue; }
		if (!memcmp(inName.__s,L"nme_hit_object",sizeof(wchar_t)*14) ) { nme_hit_object=inValue.Cast< Dynamic >(); return inValue; }
		if (!memcmp(inName.__s,L"nme_get_extent",sizeof(wchar_t)*14) ) { nme_get_extent=inValue.Cast< Dynamic >(); return inValue; }
		if (!memcmp(inName.__s,L"mSolidGradient",sizeof(wchar_t)*14) ) { mSolidGradient=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 15:
		if (!memcmp(inName.__s,L"defaultFontName",sizeof(wchar_t)*15) ) { defaultFontName=inValue.Cast< ::String >(); return inValue; }
		if (!memcmp(inName.__s,L"defaultFontSize",sizeof(wchar_t)*15) ) { defaultFontSize=inValue.Cast< int >(); return inValue; }
		if (!memcmp(inName.__s,L"immediateMatrix",sizeof(wchar_t)*15) ) { immediateMatrix=inValue.Cast< ::nme::geom::Matrix >(); return inValue; }
		if (!memcmp(inName.__s,L"BLEND_HARDLIGHT",sizeof(wchar_t)*15) ) { BLEND_HARDLIGHT=inValue.Cast< int >(); return inValue; }
		if (!memcmp(inName.__s,L"nme_create_mask",sizeof(wchar_t)*15) ) { nme_create_mask=inValue.Cast< Dynamic >(); return inValue; }
		if (!memcmp(inName.__s,L"nme_add_to_mask",sizeof(wchar_t)*15) ) { nme_add_to_mask=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 16:
		if (!memcmp(inName.__s,L"EDGE_REPEAT_POW2",sizeof(wchar_t)*16) ) { EDGE_REPEAT_POW2=inValue.Cast< int >(); return inValue; }
		if (!memcmp(inName.__s,L"SCALE_HORIZONTAL",sizeof(wchar_t)*16) ) { SCALE_HORIZONTAL=inValue.Cast< int >(); return inValue; }
		if (!memcmp(inName.__s,L"BLEND_DIFFERENCE",sizeof(wchar_t)*16) ) { BLEND_DIFFERENCE=inValue.Cast< int >(); return inValue; }
		break;
	case 17:
		if (!memcmp(inName.__s,L"nme_get_clip_rect",sizeof(wchar_t)*17) ) { nme_get_clip_rect=inValue.Cast< Dynamic >(); return inValue; }
		if (!memcmp(inName.__s,L"nme_set_clip_rect",sizeof(wchar_t)*17) ) { nme_set_clip_rect=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 18:
		if (!memcmp(inName.__s,L"nme_draw_object_to",sizeof(wchar_t)*18) ) { nme_draw_object_to=inValue.Cast< Dynamic >(); return inValue; }
		if (!memcmp(inName.__s,L"nme_set_blend_mode",sizeof(wchar_t)*18) ) { nme_set_blend_mode=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 19:
		if (!memcmp(inName.__s,L"nme_draw_objects_to",sizeof(wchar_t)*19) ) { nme_draw_objects_to=inValue.Cast< Dynamic >(); return inValue; }
		if (!memcmp(inName.__s,L"nme_create_draw_obj",sizeof(wchar_t)*19) ) { nme_create_draw_obj=inValue.Cast< Dynamic >(); return inValue; }
		if (!memcmp(inName.__s,L"nme_set_scale9_grid",sizeof(wchar_t)*19) ) { nme_set_scale9_grid=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 24:
		if (!memcmp(inName.__s,L"nme_create_blit_drawable",sizeof(wchar_t)*24) ) { nme_create_blit_drawable=inValue.Cast< Dynamic >(); return inValue; }
		if (!memcmp(inName.__s,L"nme_create_text_drawable",sizeof(wchar_t)*24) ) { nme_create_text_drawable=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 25:
		if (!memcmp(inName.__s,L"nme_create_draw_triangles",sizeof(wchar_t)*25) ) { nme_create_draw_triangles=inValue.Cast< Dynamic >(); return inValue; }
		if (!memcmp(inName.__s,L"nme_create_glyph_draw_obj",sizeof(wchar_t)*25) ) { nme_create_glyph_draw_obj=inValue.Cast< Dynamic >(); return inValue; }
	}
	return super::__SetField(inName,inValue);
}

void Graphics_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_STRING(L"mSurface",8));
	outFields->push(HX_STRING(L"mChanged",8));
	outFields->push(HX_STRING(L"mPoints",7));
	outFields->push(HX_STRING(L"mSolid",6));
	outFields->push(HX_STRING(L"mFilling",8));
	outFields->push(HX_STRING(L"mFillColour",11));
	outFields->push(HX_STRING(L"mFillAlpha",10));
	outFields->push(HX_STRING(L"mSolidGradient",14));
	outFields->push(HX_STRING(L"mBitmap",7));
	outFields->push(HX_STRING(L"mCurrentLine",12));
	outFields->push(HX_STRING(L"mLineJobs",9));
	outFields->push(HX_STRING(L"mDrawList",9));
	outFields->push(HX_STRING(L"mLineDraws",10));
	outFields->push(HX_STRING(L"mPenX",5));
	outFields->push(HX_STRING(L"mPenY",5));
	outFields->push(HX_STRING(L"mLastMoveID",11));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_STRING(L"defaultFontName",15),
	HX_STRING(L"defaultFontSize",15),
	HX_STRING(L"immediateMatrix",15),
	HX_STRING(L"immediateMask",13),
	HX_STRING(L"TOP",3),
	HX_STRING(L"CENTER",6),
	HX_STRING(L"BOTTOM",6),
	HX_STRING(L"LEFT",4),
	HX_STRING(L"RIGHT",5),
	HX_STRING(L"RADIAL",6),
	HX_STRING(L"REPEAT",6),
	HX_STRING(L"REFLECT",7),
	HX_STRING(L"EDGE_MASK",9),
	HX_STRING(L"EDGE_CLAMP",10),
	HX_STRING(L"EDGE_REPEAT",11),
	HX_STRING(L"EDGE_UNCHECKED",14),
	HX_STRING(L"EDGE_REPEAT_POW2",16),
	HX_STRING(L"END_NONE",8),
	HX_STRING(L"END_ROUND",9),
	HX_STRING(L"END_SQUARE",10),
	HX_STRING(L"END_MASK",8),
	HX_STRING(L"END_SHIFT",9),
	HX_STRING(L"CORNER_ROUND",12),
	HX_STRING(L"CORNER_MITER",12),
	HX_STRING(L"CORNER_BEVEL",12),
	HX_STRING(L"CORNER_MASK",11),
	HX_STRING(L"CORNER_SHIFT",12),
	HX_STRING(L"PIXEL_HINTING",13),
	HX_STRING(L"BMP_REPEAT",10),
	HX_STRING(L"BMP_SMOOTH",10),
	HX_STRING(L"SCALE_NONE",10),
	HX_STRING(L"SCALE_VERTICAL",14),
	HX_STRING(L"SCALE_HORIZONTAL",16),
	HX_STRING(L"SCALE_NORMAL",12),
	HX_STRING(L"MOVE",4),
	HX_STRING(L"LINE",4),
	HX_STRING(L"CURVE",5),
	HX_STRING(L"BLEND_ADD",9),
	HX_STRING(L"BLEND_ALPHA",11),
	HX_STRING(L"BLEND_DARKEN",12),
	HX_STRING(L"BLEND_DIFFERENCE",16),
	HX_STRING(L"BLEND_ERASE",11),
	HX_STRING(L"BLEND_HARDLIGHT",15),
	HX_STRING(L"BLEND_INVERT",12),
	HX_STRING(L"BLEND_LAYER",11),
	HX_STRING(L"BLEND_LIGHTEN",13),
	HX_STRING(L"BLEND_MULTIPLY",14),
	HX_STRING(L"BLEND_NORMAL",12),
	HX_STRING(L"BLEND_OVERLAY",13),
	HX_STRING(L"BLEND_SCREEN",12),
	HX_STRING(L"BLEND_SUBTRACT",14),
	HX_STRING(L"BLEND_SHADER",12),
	HX_STRING(L"setBlendMode",12),
	HX_STRING(L"nme_draw_object_to",18),
	HX_STRING(L"nme_draw_objects_to",19),
	HX_STRING(L"nme_hit_object",14),
	HX_STRING(L"nme_create_blit_drawable",24),
	HX_STRING(L"nme_create_draw_obj",19),
	HX_STRING(L"nme_create_text_drawable",24),
	HX_STRING(L"nme_create_draw_triangles",25),
	HX_STRING(L"nme_get_clip_rect",17),
	HX_STRING(L"nme_set_clip_rect",17),
	HX_STRING(L"nme_get_extent",14),
	HX_STRING(L"nme_create_glyph_draw_obj",25),
	HX_STRING(L"nme_create_mask",15),
	HX_STRING(L"nme_add_to_mask",15),
	HX_STRING(L"nme_set_scale9_grid",19),
	HX_STRING(L"nme_set_blend_mode",18),
	String(null()) };

static ::String sMemberFields[] = {
	HX_STRING(L"mSurface",8),
	HX_STRING(L"mChanged",8),
	HX_STRING(L"mPoints",7),
	HX_STRING(L"mSolid",6),
	HX_STRING(L"mFilling",8),
	HX_STRING(L"mFillColour",11),
	HX_STRING(L"mFillAlpha",10),
	HX_STRING(L"mSolidGradient",14),
	HX_STRING(L"mBitmap",7),
	HX_STRING(L"mCurrentLine",12),
	HX_STRING(L"mLineJobs",9),
	HX_STRING(L"mDrawList",9),
	HX_STRING(L"mLineDraws",10),
	HX_STRING(L"mPenX",5),
	HX_STRING(L"mPenY",5),
	HX_STRING(L"mLastMoveID",11),
	HX_STRING(L"SetSurface",10),
	HX_STRING(L"GetSurfaceRect",14),
	HX_STRING(L"render",6),
	HX_STRING(L"hitTest",7),
	HX_STRING(L"blit",4),
	HX_STRING(L"lineStyle",9),
	HX_STRING(L"lineGradientStyle",17),
	HX_STRING(L"beginFill",9),
	HX_STRING(L"endFill",7),
	HX_STRING(L"drawEllipse",11),
	HX_STRING(L"drawCircle",10),
	HX_STRING(L"drawRect",8),
	HX_STRING(L"drawRoundRect",13),
	HX_STRING(L"CreateGradient",14),
	HX_STRING(L"beginGradientFill",17),
	HX_STRING(L"beginBitmapFill",15),
	HX_STRING(L"RenderGlyph",11),
	HX_STRING(L"drawTriangles",13),
	HX_STRING(L"ClearLine",9),
	HX_STRING(L"clear",5),
	HX_STRING(L"GetExtent",9),
	HX_STRING(L"moveTo",6),
	HX_STRING(L"lineTo",6),
	HX_STRING(L"curveTo",7),
	HX_STRING(L"text",4),
	HX_STRING(L"flush",5),
	HX_STRING(L"CheckChanged",12),
	HX_STRING(L"AddDrawable",11),
	HX_STRING(L"AddLineSegment",14),
	HX_STRING(L"ClosePolygon",12),
	HX_STRING(L"AddToMask",9),
	HX_STRING(L"CreateMask",10),
	HX_STRING(L"SetScale9Grid",13),
	String(null()) };

static void sMarkStatics() {
	hx::MarkMember(Graphics_obj::defaultFontName);
	hx::MarkMember(Graphics_obj::defaultFontSize);
	hx::MarkMember(Graphics_obj::immediateMatrix);
	hx::MarkMember(Graphics_obj::immediateMask);
	hx::MarkMember(Graphics_obj::TOP);
	hx::MarkMember(Graphics_obj::CENTER);
	hx::MarkMember(Graphics_obj::BOTTOM);
	hx::MarkMember(Graphics_obj::LEFT);
	hx::MarkMember(Graphics_obj::RIGHT);
	hx::MarkMember(Graphics_obj::RADIAL);
	hx::MarkMember(Graphics_obj::REPEAT);
	hx::MarkMember(Graphics_obj::REFLECT);
	hx::MarkMember(Graphics_obj::EDGE_MASK);
	hx::MarkMember(Graphics_obj::EDGE_CLAMP);
	hx::MarkMember(Graphics_obj::EDGE_REPEAT);
	hx::MarkMember(Graphics_obj::EDGE_UNCHECKED);
	hx::MarkMember(Graphics_obj::EDGE_REPEAT_POW2);
	hx::MarkMember(Graphics_obj::END_NONE);
	hx::MarkMember(Graphics_obj::END_ROUND);
	hx::MarkMember(Graphics_obj::END_SQUARE);
	hx::MarkMember(Graphics_obj::END_MASK);
	hx::MarkMember(Graphics_obj::END_SHIFT);
	hx::MarkMember(Graphics_obj::CORNER_ROUND);
	hx::MarkMember(Graphics_obj::CORNER_MITER);
	hx::MarkMember(Graphics_obj::CORNER_BEVEL);
	hx::MarkMember(Graphics_obj::CORNER_MASK);
	hx::MarkMember(Graphics_obj::CORNER_SHIFT);
	hx::MarkMember(Graphics_obj::PIXEL_HINTING);
	hx::MarkMember(Graphics_obj::BMP_REPEAT);
	hx::MarkMember(Graphics_obj::BMP_SMOOTH);
	hx::MarkMember(Graphics_obj::SCALE_NONE);
	hx::MarkMember(Graphics_obj::SCALE_VERTICAL);
	hx::MarkMember(Graphics_obj::SCALE_HORIZONTAL);
	hx::MarkMember(Graphics_obj::SCALE_NORMAL);
	hx::MarkMember(Graphics_obj::MOVE);
	hx::MarkMember(Graphics_obj::LINE);
	hx::MarkMember(Graphics_obj::CURVE);
	hx::MarkMember(Graphics_obj::BLEND_ADD);
	hx::MarkMember(Graphics_obj::BLEND_ALPHA);
	hx::MarkMember(Graphics_obj::BLEND_DARKEN);
	hx::MarkMember(Graphics_obj::BLEND_DIFFERENCE);
	hx::MarkMember(Graphics_obj::BLEND_ERASE);
	hx::MarkMember(Graphics_obj::BLEND_HARDLIGHT);
	hx::MarkMember(Graphics_obj::BLEND_INVERT);
	hx::MarkMember(Graphics_obj::BLEND_LAYER);
	hx::MarkMember(Graphics_obj::BLEND_LIGHTEN);
	hx::MarkMember(Graphics_obj::BLEND_MULTIPLY);
	hx::MarkMember(Graphics_obj::BLEND_NORMAL);
	hx::MarkMember(Graphics_obj::BLEND_OVERLAY);
	hx::MarkMember(Graphics_obj::BLEND_SCREEN);
	hx::MarkMember(Graphics_obj::BLEND_SUBTRACT);
	hx::MarkMember(Graphics_obj::BLEND_SHADER);
	hx::MarkMember(Graphics_obj::nme_draw_object_to);
	hx::MarkMember(Graphics_obj::nme_draw_objects_to);
	hx::MarkMember(Graphics_obj::nme_hit_object);
	hx::MarkMember(Graphics_obj::nme_create_blit_drawable);
	hx::MarkMember(Graphics_obj::nme_create_draw_obj);
	hx::MarkMember(Graphics_obj::nme_create_text_drawable);
	hx::MarkMember(Graphics_obj::nme_create_draw_triangles);
	hx::MarkMember(Graphics_obj::nme_get_clip_rect);
	hx::MarkMember(Graphics_obj::nme_set_clip_rect);
	hx::MarkMember(Graphics_obj::nme_get_extent);
	hx::MarkMember(Graphics_obj::nme_create_glyph_draw_obj);
	hx::MarkMember(Graphics_obj::nme_create_mask);
	hx::MarkMember(Graphics_obj::nme_add_to_mask);
	hx::MarkMember(Graphics_obj::nme_set_scale9_grid);
	hx::MarkMember(Graphics_obj::nme_set_blend_mode);
};

Class Graphics_obj::__mClass;

void Graphics_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_STRING(L"nme.display.Graphics",20), hx::TCanCast< Graphics_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void Graphics_obj::__boot()
{
	hx::Static(defaultFontName) = HX_STRING(L"ARIAL.TTF",9);
	hx::Static(defaultFontSize) = 12;
	hx::Static(immediateMatrix) = null();
	hx::Static(immediateMask) = null();
	hx::Static(TOP) = 0;
	hx::Static(CENTER) = 1;
	hx::Static(BOTTOM) = 2;
	hx::Static(LEFT) = 0;
	hx::Static(RIGHT) = 2;
	hx::Static(RADIAL) = 1;
	hx::Static(REPEAT) = 2;
	hx::Static(REFLECT) = 4;
	hx::Static(EDGE_MASK) = 240;
	hx::Static(EDGE_CLAMP) = 0;
	hx::Static(EDGE_REPEAT) = 16;
	hx::Static(EDGE_UNCHECKED) = 32;
	hx::Static(EDGE_REPEAT_POW2) = 48;
	hx::Static(END_NONE) = 0;
	hx::Static(END_ROUND) = 256;
	hx::Static(END_SQUARE) = 512;
	hx::Static(END_MASK) = 768;
	hx::Static(END_SHIFT) = 8;
	hx::Static(CORNER_ROUND) = 0;
	hx::Static(CORNER_MITER) = 4096;
	hx::Static(CORNER_BEVEL) = 8192;
	hx::Static(CORNER_MASK) = 12288;
	hx::Static(CORNER_SHIFT) = 12;
	hx::Static(PIXEL_HINTING) = 16384;
	hx::Static(BMP_REPEAT) = 16;
	hx::Static(BMP_SMOOTH) = 65536;
	hx::Static(SCALE_NONE) = 0;
	hx::Static(SCALE_VERTICAL) = 1;
	hx::Static(SCALE_HORIZONTAL) = 2;
	hx::Static(SCALE_NORMAL) = 3;
	hx::Static(MOVE) = 0;
	hx::Static(LINE) = 1;
	hx::Static(CURVE) = 2;
	hx::Static(BLEND_ADD) = 0;
	hx::Static(BLEND_ALPHA) = 1;
	hx::Static(BLEND_DARKEN) = 2;
	hx::Static(BLEND_DIFFERENCE) = 3;
	hx::Static(BLEND_ERASE) = 4;
	hx::Static(BLEND_HARDLIGHT) = 5;
	hx::Static(BLEND_INVERT) = 6;
	hx::Static(BLEND_LAYER) = 7;
	hx::Static(BLEND_LIGHTEN) = 8;
	hx::Static(BLEND_MULTIPLY) = 9;
	hx::Static(BLEND_NORMAL) = 10;
	hx::Static(BLEND_OVERLAY) = 11;
	hx::Static(BLEND_SCREEN) = 12;
	hx::Static(BLEND_SUBTRACT) = 13;
	hx::Static(BLEND_SHADER) = 14;
	hx::Static(nme_draw_object_to) = ::nme::Loader_obj::load(HX_STRING(L"nme_draw_object_to",18),5);
	hx::Static(nme_draw_objects_to) = ::nme::Loader_obj::load(HX_STRING(L"nme_draw_objects_to",19),5);
	hx::Static(nme_hit_object) = ::nme::Loader_obj::load(HX_STRING(L"nme_hit_object",14),3);
	hx::Static(nme_create_blit_drawable) = ::nme::Loader_obj::load(HX_STRING(L"nme_create_blit_drawable",24),3);
	hx::Static(nme_create_draw_obj) = ::nme::Loader_obj::load(HX_STRING(L"nme_create_draw_obj",19),5);
	hx::Static(nme_create_text_drawable) = ::nme::Loader_obj::load(HX_STRING(L"nme_create_text_drawable",24),-1);
	hx::Static(nme_create_draw_triangles) = ::nme::Loader_obj::load(HX_STRING(L"nme_create_draw_triangles",25),-1);
	hx::Static(nme_get_clip_rect) = ::nme::Loader_obj::load(HX_STRING(L"nme_get_clip_rect",17),1);
	hx::Static(nme_set_clip_rect) = ::nme::Loader_obj::load(HX_STRING(L"nme_set_clip_rect",17),2);
	hx::Static(nme_get_extent) = ::nme::Loader_obj::load(HX_STRING(L"nme_get_extent",14),4);
	hx::Static(nme_create_glyph_draw_obj) = ::nme::Loader_obj::load(HX_STRING(L"nme_create_glyph_draw_obj",25),-1);
	hx::Static(nme_create_mask) = ::nme::Loader_obj::load(HX_STRING(L"nme_create_mask",15),0);
	hx::Static(nme_add_to_mask) = ::nme::Loader_obj::load(HX_STRING(L"nme_add_to_mask",15),4);
	hx::Static(nme_set_scale9_grid) = ::nme::Loader_obj::load(HX_STRING(L"nme_set_scale9_grid",19),4);
	hx::Static(nme_set_blend_mode) = ::nme::Loader_obj::load(HX_STRING(L"nme_set_blend_mode",18),1);
}

} // end namespace nme
} // end namespace display
