#include <hxcpp.h>

#ifndef INCLUDED_Hash
#include <Hash.h>
#endif
#ifndef INCLUDED_hxMath
#include <hxMath.h>
#endif
#ifndef INCLUDED_neash_Lib
#include <neash/Lib.h>
#endif
#ifndef INCLUDED_neash_RGB
#include <neash/RGB.h>
#endif
#ifndef INCLUDED_neash_display_DisplayObject
#include <neash/display/DisplayObject.h>
#endif
#ifndef INCLUDED_neash_display_Shape
#include <neash/display/Shape.h>
#endif
#ifndef INCLUDED_neash_events_EventDispatcher
#include <neash/events/EventDispatcher.h>
#endif
#ifndef INCLUDED_neash_events_IEventDispatcher
#include <neash/events/IEventDispatcher.h>
#endif
#ifndef INCLUDED_neash_text_Font
#include <neash/text/Font.h>
#endif
#ifndef INCLUDED_neash_text_FontInstance
#include <neash/text/FontInstance.h>
#endif
#ifndef INCLUDED_neash_text_FontInstanceMode
#include <neash/text/FontInstanceMode.h>
#endif
#ifndef INCLUDED_neash_text_FontManager
#include <neash/text/FontManager.h>
#endif
#ifndef INCLUDED_nme_display_BitmapData
#include <nme/display/BitmapData.h>
#endif
#ifndef INCLUDED_nme_display_CapsStyle
#include <nme/display/CapsStyle.h>
#endif
#ifndef INCLUDED_nme_display_Graphics
#include <nme/display/Graphics.h>
#endif
#ifndef INCLUDED_nme_display_IBitmapDrawable
#include <nme/display/IBitmapDrawable.h>
#endif
#ifndef INCLUDED_nme_display_JointStyle
#include <nme/display/JointStyle.h>
#endif
#ifndef INCLUDED_nme_display_LineScaleMode
#include <nme/display/LineScaleMode.h>
#endif
#ifndef INCLUDED_nme_geom_Matrix
#include <nme/geom/Matrix.h>
#endif
namespace neash{
namespace text{

Void FontInstance_obj::__construct(::neash::text::Font inFont,int inHeight)
{
{
	this->mFont = inFont;
	this->mHeight = inHeight;
	this->mTryFreeType = true;
	this->mGlyphs = Array_obj< ::nme::display::BitmapData >::__new();
	this->mCacheAsBitmap = ::neash::Lib_obj::IsOpenGL();
}
;
	return null();
}

FontInstance_obj::~FontInstance_obj() { }

Dynamic FontInstance_obj::__CreateEmpty() { return  new FontInstance_obj; }
hx::ObjectPtr< FontInstance_obj > FontInstance_obj::__new(::neash::text::Font inFont,int inHeight)
{  hx::ObjectPtr< FontInstance_obj > result = new FontInstance_obj();
	result->__construct(inFont,inHeight);
	return result;}

Dynamic FontInstance_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< FontInstance_obj > result = new FontInstance_obj();
	result->__construct(inArgs[0],inArgs[1]);
	return result;}

::String FontInstance_obj::toString( ){
	return (((((((((((HX_STRING(L"FontInstance:",13) + this->mFont)) + HX_STRING(L":",1))) + this->mColour)) + HX_STRING(L"(",1))) + this->mGlyphs->length)) + HX_STRING(L")",1));
}


HX_DEFINE_DYNAMIC_FUNC0(FontInstance_obj,toString,return )

::String FontInstance_obj::GetFace( ){
	__SAFE_POINT
	return this->mFont->GetName();
}


HX_DEFINE_DYNAMIC_FUNC0(FontInstance_obj,GetFace,return )

int FontInstance_obj::GetHeight( ){
	return this->mHeight;
}


HX_DEFINE_DYNAMIC_FUNC0(FontInstance_obj,GetHeight,return )

Void FontInstance_obj::SetSolid( int inCol,double inAlpha){
{
		this->mColour = inCol;
		this->mAlpha = inAlpha;
		this->mMode = ::neash::text::FontInstanceMode_obj::fimSolid;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(FontInstance_obj,SetSolid,(void))

int FontInstance_obj::RenderChar( ::nme::display::Graphics inGraphics,int inGlyph,int inX,int inY){
	__SAFE_POINT
	inGraphics->lineStyle(null(),null(),null(),null(),null(),null(),null(),null());
	if (this->mCacheAsBitmap){
		::nme::display::BitmapData glyph = this->mGlyphs->__get(inGlyph);
		if ((glyph == null())){
			::neash::display::Shape shape = ::neash::display::Shape_obj::__new();
			::nme::display::Graphics gfx = shape->GetGraphics();
			gfx->lineStyle(1,1,null(),null(),null(),null(),null(),null());
			gfx->moveTo(1,1);
			gfx->lineTo(0,0);
			this->mFont->Render(gfx,inGlyph,0,0,this->mTryFreeType);
			int w = ::Math_obj::ceil((shape->GetWidth() + 10));
			int h = ::Math_obj::ceil((shape->GetHeight() + 10));
			::nme::display::BitmapData bmp = ::nme::display::BitmapData_obj::__new(w,h,true,::neash::RGB_obj::CLEAR);
			::nme::display::Graphics gfx1 = bmp->getGraphics();
			gfx1->beginFill(this->mColour,this->mAlpha);
			this->mFont->Render(gfx1,inGlyph,0,0,false);
			this->mGlyphs[inGlyph] = glyph = bmp;
		}
		::nme::geom::Matrix m = ::nme::geom::Matrix_obj::__new(null(),null(),null(),null(),null(),null());
		m->tx = inX;
		m->ty = inY;
		inGraphics->beginBitmapFill(glyph,m,false,true);
		inGraphics->drawRect(inX,inY,glyph->getWidth(),glyph->getHeight());
		return this->mFont->GetAdvance(inGlyph);
	}
	else{
		inGraphics->beginFill(this->mColour,this->mAlpha);
		return this->mFont->Render(inGraphics,inGlyph,inX,inY,this->mTryFreeType);
	}
}


HX_DEFINE_DYNAMIC_FUNC4(FontInstance_obj,RenderChar,return )

int FontInstance_obj::GetAdvance( int inChar){
	__SAFE_POINT
	if ((this->mFont == null()))
		return 0;
	return this->mFont->GetAdvance(inChar);
}


HX_DEFINE_DYNAMIC_FUNC1(FontInstance_obj,GetAdvance,return )

::Hash FontInstance_obj::mSolidFonts;

::neash::text::FontInstance FontInstance_obj::CreateSolid( ::String inFace,int inHeight,int inColour,double inAlpha){
	__SAFE_POINT
	::String id = (((((((((((((HX_STRING(L"SOLID:",6) + inFace)) + HX_STRING(L":",1))) + inHeight)) + HX_STRING(L":",1))) + inColour)) + HX_STRING(L":",1))) + inAlpha);
	::neash::text::FontInstance f = ::neash::text::FontInstance_obj::mSolidFonts->get(id).Cast< ::neash::text::FontInstance >();
	if ((f != null()))
		return f;
	::neash::text::Font font = ::neash::text::FontManager_obj::GetFont(inFace,inHeight);
	if ((font == null()))
		return null();
	f = ::neash::text::FontInstance_obj::__new(font,inHeight);
	f->SetSolid(inColour,inAlpha);
	::neash::text::FontInstance_obj::mSolidFonts->set(id,f);
	return f;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC4(FontInstance_obj,CreateSolid,return )


FontInstance_obj::FontInstance_obj()
{
}

void FontInstance_obj::__Mark()
{
	hx::MarkMember(mMode);
	hx::MarkMember(mColour);
	hx::MarkMember(mAlpha);
	hx::MarkMember(mFont);
	hx::MarkMember(mHeight);
	hx::MarkMember(mGlyphs);
	hx::MarkMember(mCacheAsBitmap);
	hx::MarkMember(mTryFreeType);
	hx::MarkMember(height);
}

Dynamic FontInstance_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 5:
		if (!memcmp(inName.__s,L"mMode",sizeof(wchar_t)*5) ) { return mMode; }
		if (!memcmp(inName.__s,L"mFont",sizeof(wchar_t)*5) ) { return mFont; }
		break;
	case 6:
		if (!memcmp(inName.__s,L"mAlpha",sizeof(wchar_t)*6) ) { return mAlpha; }
		if (!memcmp(inName.__s,L"height",sizeof(wchar_t)*6) ) { return GetHeight(); }
		break;
	case 7:
		if (!memcmp(inName.__s,L"mColour",sizeof(wchar_t)*7) ) { return mColour; }
		if (!memcmp(inName.__s,L"mHeight",sizeof(wchar_t)*7) ) { return mHeight; }
		if (!memcmp(inName.__s,L"mGlyphs",sizeof(wchar_t)*7) ) { return mGlyphs; }
		if (!memcmp(inName.__s,L"GetFace",sizeof(wchar_t)*7) ) { return GetFace_dyn(); }
		break;
	case 8:
		if (!memcmp(inName.__s,L"toString",sizeof(wchar_t)*8) ) { return toString_dyn(); }
		if (!memcmp(inName.__s,L"SetSolid",sizeof(wchar_t)*8) ) { return SetSolid_dyn(); }
		break;
	case 9:
		if (!memcmp(inName.__s,L"GetHeight",sizeof(wchar_t)*9) ) { return GetHeight_dyn(); }
		break;
	case 10:
		if (!memcmp(inName.__s,L"RenderChar",sizeof(wchar_t)*10) ) { return RenderChar_dyn(); }
		if (!memcmp(inName.__s,L"GetAdvance",sizeof(wchar_t)*10) ) { return GetAdvance_dyn(); }
		break;
	case 11:
		if (!memcmp(inName.__s,L"mSolidFonts",sizeof(wchar_t)*11) ) { return mSolidFonts; }
		if (!memcmp(inName.__s,L"CreateSolid",sizeof(wchar_t)*11) ) { return CreateSolid_dyn(); }
		break;
	case 12:
		if (!memcmp(inName.__s,L"mTryFreeType",sizeof(wchar_t)*12) ) { return mTryFreeType; }
		break;
	case 14:
		if (!memcmp(inName.__s,L"mCacheAsBitmap",sizeof(wchar_t)*14) ) { return mCacheAsBitmap; }
	}
	return super::__Field(inName);
}

Dynamic FontInstance_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	switch(inName.length) {
	case 5:
		if (!memcmp(inName.__s,L"mMode",sizeof(wchar_t)*5) ) { mMode=inValue.Cast< ::neash::text::FontInstanceMode >(); return inValue; }
		if (!memcmp(inName.__s,L"mFont",sizeof(wchar_t)*5) ) { mFont=inValue.Cast< ::neash::text::Font >(); return inValue; }
		break;
	case 6:
		if (!memcmp(inName.__s,L"mAlpha",sizeof(wchar_t)*6) ) { mAlpha=inValue.Cast< double >(); return inValue; }
		if (!memcmp(inName.__s,L"height",sizeof(wchar_t)*6) ) { height=inValue.Cast< int >(); return inValue; }
		break;
	case 7:
		if (!memcmp(inName.__s,L"mColour",sizeof(wchar_t)*7) ) { mColour=inValue.Cast< int >(); return inValue; }
		if (!memcmp(inName.__s,L"mHeight",sizeof(wchar_t)*7) ) { mHeight=inValue.Cast< int >(); return inValue; }
		if (!memcmp(inName.__s,L"mGlyphs",sizeof(wchar_t)*7) ) { mGlyphs=inValue.Cast< Array< ::nme::display::BitmapData > >(); return inValue; }
		break;
	case 11:
		if (!memcmp(inName.__s,L"mSolidFonts",sizeof(wchar_t)*11) ) { mSolidFonts=inValue.Cast< ::Hash >(); return inValue; }
		break;
	case 12:
		if (!memcmp(inName.__s,L"mTryFreeType",sizeof(wchar_t)*12) ) { mTryFreeType=inValue.Cast< bool >(); return inValue; }
		break;
	case 14:
		if (!memcmp(inName.__s,L"mCacheAsBitmap",sizeof(wchar_t)*14) ) { mCacheAsBitmap=inValue.Cast< bool >(); return inValue; }
	}
	return super::__SetField(inName,inValue);
}

void FontInstance_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_STRING(L"mMode",5));
	outFields->push(HX_STRING(L"mColour",7));
	outFields->push(HX_STRING(L"mAlpha",6));
	outFields->push(HX_STRING(L"mFont",5));
	outFields->push(HX_STRING(L"mHeight",7));
	outFields->push(HX_STRING(L"mGlyphs",7));
	outFields->push(HX_STRING(L"mCacheAsBitmap",14));
	outFields->push(HX_STRING(L"mTryFreeType",12));
	outFields->push(HX_STRING(L"height",6));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_STRING(L"mSolidFonts",11),
	HX_STRING(L"CreateSolid",11),
	String(null()) };

static ::String sMemberFields[] = {
	HX_STRING(L"mMode",5),
	HX_STRING(L"mColour",7),
	HX_STRING(L"mAlpha",6),
	HX_STRING(L"mFont",5),
	HX_STRING(L"mHeight",7),
	HX_STRING(L"mGlyphs",7),
	HX_STRING(L"mCacheAsBitmap",14),
	HX_STRING(L"mTryFreeType",12),
	HX_STRING(L"height",6),
	HX_STRING(L"toString",8),
	HX_STRING(L"GetFace",7),
	HX_STRING(L"GetHeight",9),
	HX_STRING(L"SetSolid",8),
	HX_STRING(L"RenderChar",10),
	HX_STRING(L"GetAdvance",10),
	String(null()) };

static void sMarkStatics() {
	hx::MarkMember(FontInstance_obj::mSolidFonts);
};

Class FontInstance_obj::__mClass;

void FontInstance_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_STRING(L"neash.text.FontInstance",23), hx::TCanCast< FontInstance_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void FontInstance_obj::__boot()
{
	hx::Static(mSolidFonts) = ::Hash_obj::__new();
}

} // end namespace neash
} // end namespace text
