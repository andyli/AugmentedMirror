#include <hxcpp.h>

#ifndef INCLUDED_haxe_io_Input
#include <haxe/io/Input.h>
#endif
#ifndef INCLUDED_nme_Loader
#include <nme/Loader.h>
#endif
#ifndef INCLUDED_nme_display_BitmapData
#include <nme/display/BitmapData.h>
#endif
#ifndef INCLUDED_nme_display_Graphics
#include <nme/display/Graphics.h>
#endif
#ifndef INCLUDED_nme_display_IBitmapDrawable
#include <nme/display/IBitmapDrawable.h>
#endif
#ifndef INCLUDED_nme_geom_ColorTransform
#include <nme/geom/ColorTransform.h>
#endif
#ifndef INCLUDED_nme_geom_Matrix
#include <nme/geom/Matrix.h>
#endif
#ifndef INCLUDED_nme_geom_Point
#include <nme/geom/Point.h>
#endif
#ifndef INCLUDED_nme_geom_Rectangle
#include <nme/geom/Rectangle.h>
#endif
#ifndef INCLUDED_nme_utils_ByteArray
#include <nme/utils/ByteArray.h>
#endif
namespace nme{
namespace display{

Void BitmapData_obj::__construct(int inWidth,int inHeight,Dynamic __o_inTransparent,Dynamic inFillRGBA)
{
bool inTransparent = __o_inTransparent.Default(true);
{
	int fill_col = 16777215;
	int fill_alpha = 255;
	if ((inFillRGBA != null())){
		struct _Function_2_1{
			inline static int Block( Dynamic &inFillRGBA)/* DEF (ret block)(not intern) */{
				int v = inFillRGBA;
				return (int(v) & int(16777215));
			}
		};
		fill_col = _Function_2_1::Block(inFillRGBA);
		struct _Function_2_2{
			inline static int Block( Dynamic &inFillRGBA)/* DEF (ret block)(not intern) */{
				int v = inFillRGBA;
				return hx::UShr(v,24);
			}
		};
		fill_alpha = _Function_2_2::Block(inFillRGBA);
	}
	if ((bool((inWidth < 1)) || bool((inHeight < 1)))){
		this->mTextureBuffer = null();
	}
	else{
		int flags = ::nme::display::BitmapData_obj::HARDWARE;
		if (inTransparent)
			hx::OrEq(flags,::nme::display::BitmapData_obj::TRANSPARENT);
		this->mTextureBuffer = ::nme::display::BitmapData_obj::nme_create_texture_buffer(inWidth,inHeight,flags,fill_col,fill_alpha);
	}
}
;
	return null();
}

BitmapData_obj::~BitmapData_obj() { }

Dynamic BitmapData_obj::__CreateEmpty() { return  new BitmapData_obj; }
hx::ObjectPtr< BitmapData_obj > BitmapData_obj::__new(int inWidth,int inHeight,Dynamic __o_inTransparent,Dynamic inFillRGBA)
{  hx::ObjectPtr< BitmapData_obj > result = new BitmapData_obj();
	result->__construct(inWidth,inHeight,__o_inTransparent,inFillRGBA);
	return result;}

Dynamic BitmapData_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< BitmapData_obj > result = new BitmapData_obj();
	result->__construct(inArgs[0],inArgs[1],inArgs[2],inArgs[3]);
	return result;}

hx::Object *BitmapData_obj::__ToInterface(const type_info &inType) {
	if (inType==typeid( ::nme::display::IBitmapDrawable_obj)) return operator ::nme::display::IBitmapDrawable_obj *();
	return super::__ToInterface(inType);
}

::nme::display::Graphics BitmapData_obj::GetBitmapDrawable( ){
	return ::nme::display::Graphics_obj::__new(this->mTextureBuffer);
}


HX_DEFINE_DYNAMIC_FUNC0(BitmapData_obj,GetBitmapDrawable,return )

::nme::geom::Rectangle BitmapData_obj::GetRect( ){
	__SAFE_POINT
	return ::nme::geom::Rectangle_obj::__new(0,0,this->getWidth(),this->getHeight());
}


HX_DEFINE_DYNAMIC_FUNC0(BitmapData_obj,GetRect,return )

Void BitmapData_obj::LoadFromFile( ::String inFilename){
{
		__SAFE_POINT
		this->mTextureBuffer = ::nme::display::BitmapData_obj::nme_load_texture(inFilename);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(BitmapData_obj,LoadFromFile,(void))

Void BitmapData_obj::LoadFromBytes( Array< unsigned char > inBytes,::String inType,::String inAlpha){
{
		__SAFE_POINT
		::String a = (inAlpha == null()) ? ::String( HX_STRING(L"",0) ) : ::String( inAlpha );
		this->mTextureBuffer = ::nme::display::BitmapData_obj::nme_load_texture_from_bytes(inBytes,inBytes->length,inType,a,a.length);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC3(BitmapData_obj,LoadFromBytes,(void))

Void BitmapData_obj::SetPixelData( ::String inBuffer,int inFormat,int inTableSize){
{
		__SAFE_POINT
		::nme::display::BitmapData_obj::nme_set_pixel_data(this->mTextureBuffer,inBuffer,inBuffer.length,inFormat,inTableSize);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC3(BitmapData_obj,SetPixelData,(void))

Void BitmapData_obj::clear( int color){
{
		__SAFE_POINT
		::nme::display::BitmapData_obj::nme_surface_clear(this->mTextureBuffer,color);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(BitmapData_obj,clear,(void))

::nme::display::BitmapData BitmapData_obj::clone( ){
	__SAFE_POINT
	::nme::display::BitmapData bm = ::nme::display::BitmapData_obj::__new(0,0,null(),null());
	bm->mTextureBuffer = ::nme::display::BitmapData_obj::nme_clone_texture_buffer(this->mTextureBuffer);
	return bm;
}


HX_DEFINE_DYNAMIC_FUNC0(BitmapData_obj,clone,return )

Void BitmapData_obj::copyPixels( ::nme::display::BitmapData sourceBitmapData,::nme::geom::Rectangle sourceRect,::nme::geom::Point destPoint,::nme::display::BitmapData alphaBitmapData,::nme::geom::Point alphaPoint,Dynamic __o_mergeAlpha){
bool mergeAlpha = __o_mergeAlpha.Default(false);
{
		__SAFE_POINT
		::nme::display::BitmapData_obj::nme_copy_pixels(sourceBitmapData->handle(),sourceRect->x,sourceRect->y,sourceRect->width,sourceRect->height,this->handle(),destPoint->x,destPoint->y);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC6(BitmapData_obj,copyPixels,(void))

Void BitmapData_obj::dispose( ){
{
		this->mTextureBuffer = null();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(BitmapData_obj,dispose,(void))

Void BitmapData_obj::draw( ::nme::display::IBitmapDrawable source,::nme::geom::Matrix matrix,::nme::geom::ColorTransform colorTransform,::String blendMode,::nme::geom::Rectangle clipRect,Dynamic __o_smoothing){
bool smoothing = __o_smoothing.Default(false);
{
		__SAFE_POINT
		source->drawToSurface(this->mTextureBuffer,matrix,colorTransform,blendMode,clipRect,smoothing);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC6(BitmapData_obj,draw,(void))

Void BitmapData_obj::drawToSurface( Dynamic inSurface,::nme::geom::Matrix matrix,::nme::geom::ColorTransform colorTransform,::String blendMode,::nme::geom::Rectangle clipRect,bool smoothing){
{
		__SAFE_POINT
		if ((matrix == null()))
			matrix = ::nme::geom::Matrix_obj::__new(null(),null(),null(),null(),null(),null());
		::nme::display::BitmapData_obj::nme_copy_pixels(this->handle(),0.0,0.0,(this->getWidth() + 0.0),(this->getHeight() + 0.0),inSurface(),matrix->tx,matrix->ty);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC6(BitmapData_obj,drawToSurface,(void))

Void BitmapData_obj::fillRect( ::nme::geom::Rectangle rect,int inColour){
{
		__SAFE_POINT
		int a = hx::UShr(inColour,24);
		int c = (int(inColour) & int(16777215));
		::nme::display::BitmapData_obj::nme_tex_fill_rect(this->handle(),rect,c,a);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(BitmapData_obj,fillRect,(void))

Void BitmapData_obj::fillRectEx( ::nme::geom::Rectangle rect,int inColour,Dynamic __o_inAlpha){
int inAlpha = __o_inAlpha.Default(255);
{
		__SAFE_POINT
		::nme::display::BitmapData_obj::nme_tex_fill_rect(this->handle(),rect,inColour,inAlpha);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC3(BitmapData_obj,fillRectEx,(void))

Void BitmapData_obj::flushGraphics( ){
{
		__SAFE_POINT
		if ((this->getGraphics() != null()))
			this->getGraphics()->flush();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(BitmapData_obj,flushGraphics,(void))

::nme::geom::Rectangle BitmapData_obj::getColorBoundsRect( int mask,int color,Dynamic __o_findColor){
bool findColor = __o_findColor.Default(true);
{
		__SAFE_POINT
		return ::nme::geom::Rectangle_obj::__new(this->getWidth(),this->getHeight(),null(),null());
	}
}


HX_DEFINE_DYNAMIC_FUNC3(BitmapData_obj,getColorBoundsRect,return )

::nme::display::Graphics BitmapData_obj::getGraphics( ){
	if ((this->graphics == null()))
		this->graphics = ::nme::display::Graphics_obj::__new(this->mTextureBuffer);
	return this->graphics;
}


HX_DEFINE_DYNAMIC_FUNC0(BitmapData_obj,getGraphics,return )

int BitmapData_obj::getHeight( ){
	__SAFE_POINT
	return ::nme::display::BitmapData_obj::nme_texture_height(this->mTextureBuffer);
}


HX_DEFINE_DYNAMIC_FUNC0(BitmapData_obj,getHeight,return )

int BitmapData_obj::getWidth( ){
	__SAFE_POINT
	return ::nme::display::BitmapData_obj::nme_texture_width(this->mTextureBuffer);
}


HX_DEFINE_DYNAMIC_FUNC0(BitmapData_obj,getWidth,return )

Dynamic BitmapData_obj::handle( ){
	return this->mTextureBuffer;
}


HX_DEFINE_DYNAMIC_FUNC0(BitmapData_obj,handle,return )

::nme::utils::ByteArray BitmapData_obj::getPixels( ::nme::geom::Rectangle rect){
	__SAFE_POINT
	return ::nme::utils::ByteArray_obj::__new(::nme::display::BitmapData_obj::nme_texture_get_bytes(this->mTextureBuffer,rect));
}


HX_DEFINE_DYNAMIC_FUNC1(BitmapData_obj,getPixels,return )

int BitmapData_obj::getPixel( int x,int y){
	__SAFE_POINT
	return ::nme::display::BitmapData_obj::nme_get_pixel(this->mTextureBuffer,x,y);
}


HX_DEFINE_DYNAMIC_FUNC2(BitmapData_obj,getPixel,return )

int BitmapData_obj::getPixel32( int x,int y){
	__SAFE_POINT
	return ::nme::display::BitmapData_obj::nme_get_pixel32(this->mTextureBuffer,x,y);
}


HX_DEFINE_DYNAMIC_FUNC2(BitmapData_obj,getPixel32,return )

Void BitmapData_obj::lock( ){
{
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(BitmapData_obj,lock,(void))

Void BitmapData_obj::scroll( int inDX,int inDY){
{
		__SAFE_POINT
		::nme::display::BitmapData_obj::nme_scroll_texture(this->handle(),inDX,inDY);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(BitmapData_obj,scroll,(void))

Void BitmapData_obj::setPixel( int inX,int inY,int inColour){
{
		__SAFE_POINT
		::nme::display::BitmapData_obj::nme_set_pixel(this->mTextureBuffer,inX,inY,inColour);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC3(BitmapData_obj,setPixel,(void))

Void BitmapData_obj::setPixel32( int inX,int inY,int inColour){
{
		__SAFE_POINT
		::nme::display::BitmapData_obj::nme_set_pixel32(this->mTextureBuffer,inX,inY,inColour);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC3(BitmapData_obj,setPixel32,(void))

Void BitmapData_obj::setPixel32Ex( int inX,int inY,int inAlpha,int inColour){
{
		__SAFE_POINT
		::nme::display::BitmapData_obj::nme_set_pixel32_ex(this->mTextureBuffer,inX,inY,inAlpha,inColour);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC4(BitmapData_obj,setPixel32Ex,(void))

Void BitmapData_obj::setPixels( ::nme::geom::Rectangle rect,::nme::utils::ByteArray pixels){
{
		__SAFE_POINT
		::nme::display::BitmapData_obj::nme_texture_set_bytes(this->mTextureBuffer,rect,pixels->get_handle());
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(BitmapData_obj,setPixels,(void))

Void BitmapData_obj::unlock( ::nme::geom::Rectangle changeRect){
{
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(BitmapData_obj,unlock,(void))

bool BitmapData_obj::__getTransparent( ){
	__SAFE_POINT
	return ::nme::display::BitmapData_obj::nme_get_transparent(this->mTextureBuffer);
}


HX_DEFINE_DYNAMIC_FUNC0(BitmapData_obj,__getTransparent,return )

int BitmapData_obj::CLEAR;

int BitmapData_obj::BLACK;

int BitmapData_obj::WHITE;

int BitmapData_obj::RED;

int BitmapData_obj::GREEN;

int BitmapData_obj::BLUE;

int BitmapData_obj::TRANSPARENT;

int BitmapData_obj::HARDWARE;

::nme::display::BitmapData BitmapData_obj::CreateFromHandle( Dynamic inHandle){
	::nme::display::BitmapData result = ::nme::display::BitmapData_obj::__new(0,0,null(),null());
	result->mTextureBuffer = inHandle;
	return result;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(BitmapData_obj,CreateFromHandle,return )

::nme::display::BitmapData BitmapData_obj::Load( ::String inFilename){
	__SAFE_POINT
	::nme::display::BitmapData result = ::nme::display::BitmapData_obj::__new(0,0,null(),null());
	result->LoadFromFile(inFilename);
	return result;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(BitmapData_obj,Load,return )

int BitmapData_obj::extractAlpha( int v){
	return hx::UShr(v,24);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(BitmapData_obj,extractAlpha,return )

int BitmapData_obj::extractColor( int v){
	return (int(v) & int(16777215));
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(BitmapData_obj,extractColor,return )

Dynamic BitmapData_obj::nme_clone_texture_buffer;

Dynamic BitmapData_obj::nme_copy_pixels;

Dynamic BitmapData_obj::nme_create_texture_buffer;

Dynamic BitmapData_obj::nme_draw_object_to;

Dynamic BitmapData_obj::nme_get_pixel;

Dynamic BitmapData_obj::nme_get_pixel32;

Dynamic BitmapData_obj::nme_get_transparent;

Dynamic BitmapData_obj::nme_load_texture;

Dynamic BitmapData_obj::nme_load_texture_from_bytes;

Dynamic BitmapData_obj::nme_scroll_texture;

Dynamic BitmapData_obj::nme_set_pixel;

Dynamic BitmapData_obj::nme_set_pixel32;

Dynamic BitmapData_obj::nme_set_pixel32_ex;

Dynamic BitmapData_obj::nme_set_pixel_data;

Dynamic BitmapData_obj::nme_surface_clear;

Dynamic BitmapData_obj::nme_tex_fill_rect;

Dynamic BitmapData_obj::nme_texture_get_bytes;

Dynamic BitmapData_obj::nme_texture_height;

Dynamic BitmapData_obj::nme_texture_set_bytes;

Dynamic BitmapData_obj::nme_texture_width;


BitmapData_obj::BitmapData_obj()
{
}

void BitmapData_obj::__Mark()
{
	hx::MarkMember(mTextureBuffer);
	hx::MarkMember(width);
	hx::MarkMember(height);
	hx::MarkMember(graphics);
	hx::MarkMember(rect);
	hx::MarkMember(transparent);
}

Dynamic BitmapData_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 3:
		if (!memcmp(inName.__s,L"RED",sizeof(wchar_t)*3) ) { return RED; }
		break;
	case 4:
		if (!memcmp(inName.__s,L"BLUE",sizeof(wchar_t)*4) ) { return BLUE; }
		if (!memcmp(inName.__s,L"Load",sizeof(wchar_t)*4) ) { return Load_dyn(); }
		if (!memcmp(inName.__s,L"rect",sizeof(wchar_t)*4) ) { return GetRect(); }
		if (!memcmp(inName.__s,L"draw",sizeof(wchar_t)*4) ) { return draw_dyn(); }
		if (!memcmp(inName.__s,L"lock",sizeof(wchar_t)*4) ) { return lock_dyn(); }
		break;
	case 5:
		if (!memcmp(inName.__s,L"CLEAR",sizeof(wchar_t)*5) ) { return CLEAR; }
		if (!memcmp(inName.__s,L"BLACK",sizeof(wchar_t)*5) ) { return BLACK; }
		if (!memcmp(inName.__s,L"WHITE",sizeof(wchar_t)*5) ) { return WHITE; }
		if (!memcmp(inName.__s,L"GREEN",sizeof(wchar_t)*5) ) { return GREEN; }
		if (!memcmp(inName.__s,L"width",sizeof(wchar_t)*5) ) { return getWidth(); }
		if (!memcmp(inName.__s,L"clear",sizeof(wchar_t)*5) ) { return clear_dyn(); }
		if (!memcmp(inName.__s,L"clone",sizeof(wchar_t)*5) ) { return clone_dyn(); }
		break;
	case 6:
		if (!memcmp(inName.__s,L"height",sizeof(wchar_t)*6) ) { return getHeight(); }
		if (!memcmp(inName.__s,L"handle",sizeof(wchar_t)*6) ) { return handle_dyn(); }
		if (!memcmp(inName.__s,L"scroll",sizeof(wchar_t)*6) ) { return scroll_dyn(); }
		if (!memcmp(inName.__s,L"unlock",sizeof(wchar_t)*6) ) { return unlock_dyn(); }
		break;
	case 7:
		if (!memcmp(inName.__s,L"GetRect",sizeof(wchar_t)*7) ) { return GetRect_dyn(); }
		if (!memcmp(inName.__s,L"dispose",sizeof(wchar_t)*7) ) { return dispose_dyn(); }
		break;
	case 8:
		if (!memcmp(inName.__s,L"HARDWARE",sizeof(wchar_t)*8) ) { return HARDWARE; }
		if (!memcmp(inName.__s,L"graphics",sizeof(wchar_t)*8) ) { return getGraphics(); }
		if (!memcmp(inName.__s,L"fillRect",sizeof(wchar_t)*8) ) { return fillRect_dyn(); }
		if (!memcmp(inName.__s,L"getWidth",sizeof(wchar_t)*8) ) { return getWidth_dyn(); }
		if (!memcmp(inName.__s,L"getPixel",sizeof(wchar_t)*8) ) { return getPixel_dyn(); }
		if (!memcmp(inName.__s,L"setPixel",sizeof(wchar_t)*8) ) { return setPixel_dyn(); }
		break;
	case 9:
		if (!memcmp(inName.__s,L"getHeight",sizeof(wchar_t)*9) ) { return getHeight_dyn(); }
		if (!memcmp(inName.__s,L"getPixels",sizeof(wchar_t)*9) ) { return getPixels_dyn(); }
		if (!memcmp(inName.__s,L"setPixels",sizeof(wchar_t)*9) ) { return setPixels_dyn(); }
		break;
	case 10:
		if (!memcmp(inName.__s,L"copyPixels",sizeof(wchar_t)*10) ) { return copyPixels_dyn(); }
		if (!memcmp(inName.__s,L"fillRectEx",sizeof(wchar_t)*10) ) { return fillRectEx_dyn(); }
		if (!memcmp(inName.__s,L"getPixel32",sizeof(wchar_t)*10) ) { return getPixel32_dyn(); }
		if (!memcmp(inName.__s,L"setPixel32",sizeof(wchar_t)*10) ) { return setPixel32_dyn(); }
		break;
	case 11:
		if (!memcmp(inName.__s,L"TRANSPARENT",sizeof(wchar_t)*11) ) { return TRANSPARENT; }
		if (!memcmp(inName.__s,L"transparent",sizeof(wchar_t)*11) ) { return __getTransparent(); }
		if (!memcmp(inName.__s,L"getGraphics",sizeof(wchar_t)*11) ) { return getGraphics_dyn(); }
		break;
	case 12:
		if (!memcmp(inName.__s,L"extractAlpha",sizeof(wchar_t)*12) ) { return extractAlpha_dyn(); }
		if (!memcmp(inName.__s,L"extractColor",sizeof(wchar_t)*12) ) { return extractColor_dyn(); }
		if (!memcmp(inName.__s,L"LoadFromFile",sizeof(wchar_t)*12) ) { return LoadFromFile_dyn(); }
		if (!memcmp(inName.__s,L"SetPixelData",sizeof(wchar_t)*12) ) { return SetPixelData_dyn(); }
		if (!memcmp(inName.__s,L"setPixel32Ex",sizeof(wchar_t)*12) ) { return setPixel32Ex_dyn(); }
		break;
	case 13:
		if (!memcmp(inName.__s,L"nme_get_pixel",sizeof(wchar_t)*13) ) { return nme_get_pixel; }
		if (!memcmp(inName.__s,L"nme_set_pixel",sizeof(wchar_t)*13) ) { return nme_set_pixel; }
		if (!memcmp(inName.__s,L"LoadFromBytes",sizeof(wchar_t)*13) ) { return LoadFromBytes_dyn(); }
		if (!memcmp(inName.__s,L"drawToSurface",sizeof(wchar_t)*13) ) { return drawToSurface_dyn(); }
		if (!memcmp(inName.__s,L"flushGraphics",sizeof(wchar_t)*13) ) { return flushGraphics_dyn(); }
		break;
	case 14:
		if (!memcmp(inName.__s,L"mTextureBuffer",sizeof(wchar_t)*14) ) { return mTextureBuffer; }
		break;
	case 15:
		if (!memcmp(inName.__s,L"nme_copy_pixels",sizeof(wchar_t)*15) ) { return nme_copy_pixels; }
		if (!memcmp(inName.__s,L"nme_get_pixel32",sizeof(wchar_t)*15) ) { return nme_get_pixel32; }
		if (!memcmp(inName.__s,L"nme_set_pixel32",sizeof(wchar_t)*15) ) { return nme_set_pixel32; }
		break;
	case 16:
		if (!memcmp(inName.__s,L"CreateFromHandle",sizeof(wchar_t)*16) ) { return CreateFromHandle_dyn(); }
		if (!memcmp(inName.__s,L"nme_load_texture",sizeof(wchar_t)*16) ) { return nme_load_texture; }
		if (!memcmp(inName.__s,L"__getTransparent",sizeof(wchar_t)*16) ) { return __getTransparent_dyn(); }
		break;
	case 17:
		if (!memcmp(inName.__s,L"nme_surface_clear",sizeof(wchar_t)*17) ) { return nme_surface_clear; }
		if (!memcmp(inName.__s,L"nme_tex_fill_rect",sizeof(wchar_t)*17) ) { return nme_tex_fill_rect; }
		if (!memcmp(inName.__s,L"nme_texture_width",sizeof(wchar_t)*17) ) { return nme_texture_width; }
		if (!memcmp(inName.__s,L"GetBitmapDrawable",sizeof(wchar_t)*17) ) { return GetBitmapDrawable_dyn(); }
		break;
	case 18:
		if (!memcmp(inName.__s,L"nme_draw_object_to",sizeof(wchar_t)*18) ) { return nme_draw_object_to; }
		if (!memcmp(inName.__s,L"nme_scroll_texture",sizeof(wchar_t)*18) ) { return nme_scroll_texture; }
		if (!memcmp(inName.__s,L"nme_set_pixel32_ex",sizeof(wchar_t)*18) ) { return nme_set_pixel32_ex; }
		if (!memcmp(inName.__s,L"nme_set_pixel_data",sizeof(wchar_t)*18) ) { return nme_set_pixel_data; }
		if (!memcmp(inName.__s,L"nme_texture_height",sizeof(wchar_t)*18) ) { return nme_texture_height; }
		if (!memcmp(inName.__s,L"getColorBoundsRect",sizeof(wchar_t)*18) ) { return getColorBoundsRect_dyn(); }
		break;
	case 19:
		if (!memcmp(inName.__s,L"nme_get_transparent",sizeof(wchar_t)*19) ) { return nme_get_transparent; }
		break;
	case 21:
		if (!memcmp(inName.__s,L"nme_texture_get_bytes",sizeof(wchar_t)*21) ) { return nme_texture_get_bytes; }
		if (!memcmp(inName.__s,L"nme_texture_set_bytes",sizeof(wchar_t)*21) ) { return nme_texture_set_bytes; }
		break;
	case 24:
		if (!memcmp(inName.__s,L"nme_clone_texture_buffer",sizeof(wchar_t)*24) ) { return nme_clone_texture_buffer; }
		break;
	case 25:
		if (!memcmp(inName.__s,L"nme_create_texture_buffer",sizeof(wchar_t)*25) ) { return nme_create_texture_buffer; }
		break;
	case 27:
		if (!memcmp(inName.__s,L"nme_load_texture_from_bytes",sizeof(wchar_t)*27) ) { return nme_load_texture_from_bytes; }
	}
	return super::__Field(inName);
}

Dynamic BitmapData_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	switch(inName.length) {
	case 3:
		if (!memcmp(inName.__s,L"RED",sizeof(wchar_t)*3) ) { RED=inValue.Cast< int >(); return inValue; }
		break;
	case 4:
		if (!memcmp(inName.__s,L"BLUE",sizeof(wchar_t)*4) ) { BLUE=inValue.Cast< int >(); return inValue; }
		if (!memcmp(inName.__s,L"rect",sizeof(wchar_t)*4) ) { rect=inValue.Cast< ::nme::geom::Rectangle >(); return inValue; }
		break;
	case 5:
		if (!memcmp(inName.__s,L"CLEAR",sizeof(wchar_t)*5) ) { CLEAR=inValue.Cast< int >(); return inValue; }
		if (!memcmp(inName.__s,L"BLACK",sizeof(wchar_t)*5) ) { BLACK=inValue.Cast< int >(); return inValue; }
		if (!memcmp(inName.__s,L"WHITE",sizeof(wchar_t)*5) ) { WHITE=inValue.Cast< int >(); return inValue; }
		if (!memcmp(inName.__s,L"GREEN",sizeof(wchar_t)*5) ) { GREEN=inValue.Cast< int >(); return inValue; }
		if (!memcmp(inName.__s,L"width",sizeof(wchar_t)*5) ) { width=inValue.Cast< int >(); return inValue; }
		break;
	case 6:
		if (!memcmp(inName.__s,L"height",sizeof(wchar_t)*6) ) { height=inValue.Cast< int >(); return inValue; }
		break;
	case 8:
		if (!memcmp(inName.__s,L"HARDWARE",sizeof(wchar_t)*8) ) { HARDWARE=inValue.Cast< int >(); return inValue; }
		if (!memcmp(inName.__s,L"graphics",sizeof(wchar_t)*8) ) { graphics=inValue.Cast< ::nme::display::Graphics >(); return inValue; }
		break;
	case 11:
		if (!memcmp(inName.__s,L"TRANSPARENT",sizeof(wchar_t)*11) ) { TRANSPARENT=inValue.Cast< int >(); return inValue; }
		if (!memcmp(inName.__s,L"transparent",sizeof(wchar_t)*11) ) { transparent=inValue.Cast< bool >(); return inValue; }
		break;
	case 13:
		if (!memcmp(inName.__s,L"nme_get_pixel",sizeof(wchar_t)*13) ) { nme_get_pixel=inValue.Cast< Dynamic >(); return inValue; }
		if (!memcmp(inName.__s,L"nme_set_pixel",sizeof(wchar_t)*13) ) { nme_set_pixel=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 14:
		if (!memcmp(inName.__s,L"mTextureBuffer",sizeof(wchar_t)*14) ) { mTextureBuffer=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 15:
		if (!memcmp(inName.__s,L"nme_copy_pixels",sizeof(wchar_t)*15) ) { nme_copy_pixels=inValue.Cast< Dynamic >(); return inValue; }
		if (!memcmp(inName.__s,L"nme_get_pixel32",sizeof(wchar_t)*15) ) { nme_get_pixel32=inValue.Cast< Dynamic >(); return inValue; }
		if (!memcmp(inName.__s,L"nme_set_pixel32",sizeof(wchar_t)*15) ) { nme_set_pixel32=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 16:
		if (!memcmp(inName.__s,L"nme_load_texture",sizeof(wchar_t)*16) ) { nme_load_texture=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 17:
		if (!memcmp(inName.__s,L"nme_surface_clear",sizeof(wchar_t)*17) ) { nme_surface_clear=inValue.Cast< Dynamic >(); return inValue; }
		if (!memcmp(inName.__s,L"nme_tex_fill_rect",sizeof(wchar_t)*17) ) { nme_tex_fill_rect=inValue.Cast< Dynamic >(); return inValue; }
		if (!memcmp(inName.__s,L"nme_texture_width",sizeof(wchar_t)*17) ) { nme_texture_width=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 18:
		if (!memcmp(inName.__s,L"nme_draw_object_to",sizeof(wchar_t)*18) ) { nme_draw_object_to=inValue.Cast< Dynamic >(); return inValue; }
		if (!memcmp(inName.__s,L"nme_scroll_texture",sizeof(wchar_t)*18) ) { nme_scroll_texture=inValue.Cast< Dynamic >(); return inValue; }
		if (!memcmp(inName.__s,L"nme_set_pixel32_ex",sizeof(wchar_t)*18) ) { nme_set_pixel32_ex=inValue.Cast< Dynamic >(); return inValue; }
		if (!memcmp(inName.__s,L"nme_set_pixel_data",sizeof(wchar_t)*18) ) { nme_set_pixel_data=inValue.Cast< Dynamic >(); return inValue; }
		if (!memcmp(inName.__s,L"nme_texture_height",sizeof(wchar_t)*18) ) { nme_texture_height=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 19:
		if (!memcmp(inName.__s,L"nme_get_transparent",sizeof(wchar_t)*19) ) { nme_get_transparent=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 21:
		if (!memcmp(inName.__s,L"nme_texture_get_bytes",sizeof(wchar_t)*21) ) { nme_texture_get_bytes=inValue.Cast< Dynamic >(); return inValue; }
		if (!memcmp(inName.__s,L"nme_texture_set_bytes",sizeof(wchar_t)*21) ) { nme_texture_set_bytes=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 24:
		if (!memcmp(inName.__s,L"nme_clone_texture_buffer",sizeof(wchar_t)*24) ) { nme_clone_texture_buffer=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 25:
		if (!memcmp(inName.__s,L"nme_create_texture_buffer",sizeof(wchar_t)*25) ) { nme_create_texture_buffer=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 27:
		if (!memcmp(inName.__s,L"nme_load_texture_from_bytes",sizeof(wchar_t)*27) ) { nme_load_texture_from_bytes=inValue.Cast< Dynamic >(); return inValue; }
	}
	return super::__SetField(inName,inValue);
}

void BitmapData_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_STRING(L"mTextureBuffer",14));
	outFields->push(HX_STRING(L"width",5));
	outFields->push(HX_STRING(L"height",6));
	outFields->push(HX_STRING(L"graphics",8));
	outFields->push(HX_STRING(L"rect",4));
	outFields->push(HX_STRING(L"transparent",11));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_STRING(L"CLEAR",5),
	HX_STRING(L"BLACK",5),
	HX_STRING(L"WHITE",5),
	HX_STRING(L"RED",3),
	HX_STRING(L"GREEN",5),
	HX_STRING(L"BLUE",4),
	HX_STRING(L"TRANSPARENT",11),
	HX_STRING(L"HARDWARE",8),
	HX_STRING(L"CreateFromHandle",16),
	HX_STRING(L"Load",4),
	HX_STRING(L"extractAlpha",12),
	HX_STRING(L"extractColor",12),
	HX_STRING(L"nme_clone_texture_buffer",24),
	HX_STRING(L"nme_copy_pixels",15),
	HX_STRING(L"nme_create_texture_buffer",25),
	HX_STRING(L"nme_draw_object_to",18),
	HX_STRING(L"nme_get_pixel",13),
	HX_STRING(L"nme_get_pixel32",15),
	HX_STRING(L"nme_get_transparent",19),
	HX_STRING(L"nme_load_texture",16),
	HX_STRING(L"nme_load_texture_from_bytes",27),
	HX_STRING(L"nme_scroll_texture",18),
	HX_STRING(L"nme_set_pixel",13),
	HX_STRING(L"nme_set_pixel32",15),
	HX_STRING(L"nme_set_pixel32_ex",18),
	HX_STRING(L"nme_set_pixel_data",18),
	HX_STRING(L"nme_surface_clear",17),
	HX_STRING(L"nme_tex_fill_rect",17),
	HX_STRING(L"nme_texture_get_bytes",21),
	HX_STRING(L"nme_texture_height",18),
	HX_STRING(L"nme_texture_set_bytes",21),
	HX_STRING(L"nme_texture_width",17),
	String(null()) };

static ::String sMemberFields[] = {
	HX_STRING(L"mTextureBuffer",14),
	HX_STRING(L"width",5),
	HX_STRING(L"height",6),
	HX_STRING(L"graphics",8),
	HX_STRING(L"rect",4),
	HX_STRING(L"transparent",11),
	HX_STRING(L"GetBitmapDrawable",17),
	HX_STRING(L"GetRect",7),
	HX_STRING(L"LoadFromFile",12),
	HX_STRING(L"LoadFromBytes",13),
	HX_STRING(L"SetPixelData",12),
	HX_STRING(L"clear",5),
	HX_STRING(L"clone",5),
	HX_STRING(L"copyPixels",10),
	HX_STRING(L"dispose",7),
	HX_STRING(L"draw",4),
	HX_STRING(L"drawToSurface",13),
	HX_STRING(L"fillRect",8),
	HX_STRING(L"fillRectEx",10),
	HX_STRING(L"flushGraphics",13),
	HX_STRING(L"getColorBoundsRect",18),
	HX_STRING(L"getGraphics",11),
	HX_STRING(L"getHeight",9),
	HX_STRING(L"getWidth",8),
	HX_STRING(L"handle",6),
	HX_STRING(L"getPixels",9),
	HX_STRING(L"getPixel",8),
	HX_STRING(L"getPixel32",10),
	HX_STRING(L"lock",4),
	HX_STRING(L"scroll",6),
	HX_STRING(L"setPixel",8),
	HX_STRING(L"setPixel32",10),
	HX_STRING(L"setPixel32Ex",12),
	HX_STRING(L"setPixels",9),
	HX_STRING(L"unlock",6),
	HX_STRING(L"__getTransparent",16),
	String(null()) };

static void sMarkStatics() {
	hx::MarkMember(BitmapData_obj::CLEAR);
	hx::MarkMember(BitmapData_obj::BLACK);
	hx::MarkMember(BitmapData_obj::WHITE);
	hx::MarkMember(BitmapData_obj::RED);
	hx::MarkMember(BitmapData_obj::GREEN);
	hx::MarkMember(BitmapData_obj::BLUE);
	hx::MarkMember(BitmapData_obj::TRANSPARENT);
	hx::MarkMember(BitmapData_obj::HARDWARE);
	hx::MarkMember(BitmapData_obj::nme_clone_texture_buffer);
	hx::MarkMember(BitmapData_obj::nme_copy_pixels);
	hx::MarkMember(BitmapData_obj::nme_create_texture_buffer);
	hx::MarkMember(BitmapData_obj::nme_draw_object_to);
	hx::MarkMember(BitmapData_obj::nme_get_pixel);
	hx::MarkMember(BitmapData_obj::nme_get_pixel32);
	hx::MarkMember(BitmapData_obj::nme_get_transparent);
	hx::MarkMember(BitmapData_obj::nme_load_texture);
	hx::MarkMember(BitmapData_obj::nme_load_texture_from_bytes);
	hx::MarkMember(BitmapData_obj::nme_scroll_texture);
	hx::MarkMember(BitmapData_obj::nme_set_pixel);
	hx::MarkMember(BitmapData_obj::nme_set_pixel32);
	hx::MarkMember(BitmapData_obj::nme_set_pixel32_ex);
	hx::MarkMember(BitmapData_obj::nme_set_pixel_data);
	hx::MarkMember(BitmapData_obj::nme_surface_clear);
	hx::MarkMember(BitmapData_obj::nme_tex_fill_rect);
	hx::MarkMember(BitmapData_obj::nme_texture_get_bytes);
	hx::MarkMember(BitmapData_obj::nme_texture_height);
	hx::MarkMember(BitmapData_obj::nme_texture_set_bytes);
	hx::MarkMember(BitmapData_obj::nme_texture_width);
};

Class BitmapData_obj::__mClass;

void BitmapData_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_STRING(L"nme.display.BitmapData",22), hx::TCanCast< BitmapData_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void BitmapData_obj::__boot()
{
	hx::Static(CLEAR) = 0;
	hx::Static(BLACK) = -16777216;
	hx::Static(WHITE) = -1;
	hx::Static(RED) = -65536;
	hx::Static(GREEN) = -16711936;
	hx::Static(BLUE) = -16776961;
	hx::Static(TRANSPARENT) = 1;
	hx::Static(HARDWARE) = 2;
	hx::Static(nme_clone_texture_buffer) = ::nme::Loader_obj::load(HX_STRING(L"nme_clone_texture_buffer",24),1);
	hx::Static(nme_copy_pixels) = ::nme::Loader_obj::load(HX_STRING(L"nme_copy_pixels",15),-1);
	hx::Static(nme_create_texture_buffer) = ::nme::Loader_obj::load(HX_STRING(L"nme_create_texture_buffer",25),5);
	hx::Static(nme_draw_object_to) = ::nme::Loader_obj::load(HX_STRING(L"nme_draw_object_to",18),5);
	hx::Static(nme_get_pixel) = ::nme::Loader_obj::load(HX_STRING(L"nme_get_pixel",13),3);
	hx::Static(nme_get_pixel32) = ::nme::Loader_obj::load(HX_STRING(L"nme_get_pixel32",15),3);
	hx::Static(nme_get_transparent) = ::nme::Loader_obj::load(HX_STRING(L"nme_get_transparent",19),1);
	hx::Static(nme_load_texture) = ::nme::Loader_obj::load(HX_STRING(L"nme_load_texture",16),1);
	hx::Static(nme_load_texture_from_bytes) = ::nme::Loader_obj::load(HX_STRING(L"nme_load_texture_from_bytes",27),5);
	hx::Static(nme_scroll_texture) = ::nme::Loader_obj::load(HX_STRING(L"nme_scroll_texture",18),3);
	hx::Static(nme_set_pixel) = ::nme::Loader_obj::load(HX_STRING(L"nme_set_pixel",13),4);
	hx::Static(nme_set_pixel32) = ::nme::Loader_obj::load(HX_STRING(L"nme_set_pixel32",15),4);
	hx::Static(nme_set_pixel32_ex) = ::nme::Loader_obj::load(HX_STRING(L"nme_set_pixel32_ex",18),5);
	hx::Static(nme_set_pixel_data) = ::nme::Loader_obj::load(HX_STRING(L"nme_set_pixel_data",18),5);
	hx::Static(nme_surface_clear) = ::nme::Loader_obj::load(HX_STRING(L"nme_surface_clear",17),2);
	hx::Static(nme_tex_fill_rect) = ::nme::Loader_obj::load(HX_STRING(L"nme_tex_fill_rect",17),4);
	hx::Static(nme_texture_get_bytes) = ::nme::Loader_obj::load(HX_STRING(L"nme_texture_get_bytes",21),2);
	hx::Static(nme_texture_height) = ::nme::Loader_obj::load(HX_STRING(L"nme_texture_height",18),1);
	hx::Static(nme_texture_set_bytes) = ::nme::Loader_obj::load(HX_STRING(L"nme_texture_set_bytes",21),3);
	hx::Static(nme_texture_width) = ::nme::Loader_obj::load(HX_STRING(L"nme_texture_width",17),1);
}

} // end namespace nme
} // end namespace display
