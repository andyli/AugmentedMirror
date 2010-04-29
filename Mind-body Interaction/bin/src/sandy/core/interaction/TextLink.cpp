#include <hxcpp.h>

#ifndef INCLUDED_neash_display_DisplayObject
#include <neash/display/DisplayObject.h>
#endif
#ifndef INCLUDED_neash_display_InteractiveObject
#include <neash/display/InteractiveObject.h>
#endif
#ifndef INCLUDED_neash_events_EventDispatcher
#include <neash/events/EventDispatcher.h>
#endif
#ifndef INCLUDED_neash_events_IEventDispatcher
#include <neash/events/IEventDispatcher.h>
#endif
#ifndef INCLUDED_neash_text_NeashText
#include <neash/text/NeashText.h>
#endif
#ifndef INCLUDED_nme_display_IBitmapDrawable
#include <nme/display/IBitmapDrawable.h>
#endif
#ifndef INCLUDED_nme_geom_Rectangle
#include <nme/geom/Rectangle.h>
#endif
#ifndef INCLUDED_sandy_core_interaction_TextLink
#include <sandy/core/interaction/TextLink.h>
#endif
namespace sandy{
namespace core{
namespace interaction{

Void TextLink_obj::__construct()
{
{
	this->x = 0;
	this->y = 0;
	this->height = 0;
	this->width = 0;
}
;
	return null();
}

TextLink_obj::~TextLink_obj() { }

Dynamic TextLink_obj::__CreateEmpty() { return  new TextLink_obj; }
hx::ObjectPtr< TextLink_obj > TextLink_obj::__new()
{  hx::ObjectPtr< TextLink_obj > result = new TextLink_obj();
	result->__construct();
	return result;}

Dynamic TextLink_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< TextLink_obj > result = new TextLink_obj();
	result->__construct();
	return result;}

::nme::geom::Rectangle TextLink_obj::getBounds( ){
	return this->__rBounds;
}


HX_DEFINE_DYNAMIC_FUNC0(TextLink_obj,getBounds,return )

::neash::text::NeashText TextLink_obj::__getOwner( ){
	return this->__tfOwner;
}


HX_DEFINE_DYNAMIC_FUNC0(TextLink_obj,__getOwner,return )

::neash::text::NeashText TextLink_obj::__setOwner( ::neash::text::NeashText tf){
	this->__tfOwner = tf;
	return tf;
}


HX_DEFINE_DYNAMIC_FUNC1(TextLink_obj,__setOwner,return )

::String TextLink_obj::__getTarget( ){
	return this->__sTarget;
}


HX_DEFINE_DYNAMIC_FUNC0(TextLink_obj,__getTarget,return )

::String TextLink_obj::__setTarget( ::String s){
	this->__sTarget = s;
	return s;
}


HX_DEFINE_DYNAMIC_FUNC1(TextLink_obj,__setTarget,return )

::String TextLink_obj::__getHref( ){
	return this->__sHRef;
}


HX_DEFINE_DYNAMIC_FUNC0(TextLink_obj,__getHref,return )

::String TextLink_obj::__setHref( ::String s){
	this->__sHRef = s;
	return s;
}


HX_DEFINE_DYNAMIC_FUNC1(TextLink_obj,__setHref,return )

int TextLink_obj::__getOpenIndex( ){
	return this->__iOpenIndex;
}


HX_DEFINE_DYNAMIC_FUNC0(TextLink_obj,__getOpenIndex,return )

int TextLink_obj::__setOpenIndex( int i){
	this->__iOpenIndex = i;
	return i;
}


HX_DEFINE_DYNAMIC_FUNC1(TextLink_obj,__setOpenIndex,return )

int TextLink_obj::__getCloseIndex( ){
	return this->__iCloseIndex;
}


HX_DEFINE_DYNAMIC_FUNC0(TextLink_obj,__getCloseIndex,return )

int TextLink_obj::__setCloseIndex( int i){
	this->__iCloseIndex = i;
	return i;
}


HX_DEFINE_DYNAMIC_FUNC1(TextLink_obj,__setCloseIndex,return )

Void TextLink_obj::_init( ){
{
		__SAFE_POINT
		{
			int _g1 = 0;
			int _g = ((this->__iCloseIndex - this->__iOpenIndex));
			while((_g1 < _g)){
				__SAFE_POINT
				int j = _g1++;
				::nme::geom::Rectangle rectB = this->__tfOwner->getCharBoundaries((this->__getOpenIndex() + j));
				if ((j == 0)){
					this->x = rectB->x;
					this->y = rectB->y;
				}
				hx::AddEq(this->width,rectB->width);
				this->height = (this->height < rectB->height) ? double( rectB->height ) : double( this->height );
			}
		}
		this->__rBounds = ::nme::geom::Rectangle_obj::__new(null(),null(),null(),null());
		this->__rBounds->x = this->x;
		this->__rBounds->y = this->y;
		this->__rBounds->height = this->height;
		this->__rBounds->width = this->width;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(TextLink_obj,_init,(void))

Array< ::sandy::core::interaction::TextLink > TextLink_obj::getTextLinks( ::neash::text::NeashText t,Dynamic __o_force){
bool force = __o_force.Default(false);
{
		return Array_obj< ::sandy::core::interaction::TextLink >::__new();
	}
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(TextLink_obj,getTextLinks,return )


TextLink_obj::TextLink_obj()
{
}

void TextLink_obj::__Mark()
{
	hx::MarkMember(x);
	hx::MarkMember(y);
	hx::MarkMember(height);
	hx::MarkMember(width);
	hx::MarkMember(__sHRef);
	hx::MarkMember(__sTarget);
	hx::MarkMember(__iOpenIndex);
	hx::MarkMember(__iCloseIndex);
	hx::MarkMember(__tfOwner);
	hx::MarkMember(__rBounds);
	hx::MarkMember(owner);
	hx::MarkMember(target);
	hx::MarkMember(href);
	hx::MarkMember(openIndex);
	hx::MarkMember(closeIndex);
}

Dynamic TextLink_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 1:
		if (!memcmp(inName.__s,L"x",sizeof(wchar_t)*1) ) { return x; }
		if (!memcmp(inName.__s,L"y",sizeof(wchar_t)*1) ) { return y; }
		break;
	case 4:
		if (!memcmp(inName.__s,L"href",sizeof(wchar_t)*4) ) { return __getHref(); }
		break;
	case 5:
		if (!memcmp(inName.__s,L"width",sizeof(wchar_t)*5) ) { return width; }
		if (!memcmp(inName.__s,L"owner",sizeof(wchar_t)*5) ) { return __getOwner(); }
		if (!memcmp(inName.__s,L"_init",sizeof(wchar_t)*5) ) { return _init_dyn(); }
		break;
	case 6:
		if (!memcmp(inName.__s,L"height",sizeof(wchar_t)*6) ) { return height; }
		if (!memcmp(inName.__s,L"target",sizeof(wchar_t)*6) ) { return __getTarget(); }
		break;
	case 7:
		if (!memcmp(inName.__s,L"__sHRef",sizeof(wchar_t)*7) ) { return __sHRef; }
		break;
	case 9:
		if (!memcmp(inName.__s,L"__sTarget",sizeof(wchar_t)*9) ) { return __sTarget; }
		if (!memcmp(inName.__s,L"__tfOwner",sizeof(wchar_t)*9) ) { return __tfOwner; }
		if (!memcmp(inName.__s,L"__rBounds",sizeof(wchar_t)*9) ) { return __rBounds; }
		if (!memcmp(inName.__s,L"getBounds",sizeof(wchar_t)*9) ) { return getBounds_dyn(); }
		if (!memcmp(inName.__s,L"__getHref",sizeof(wchar_t)*9) ) { return __getHref_dyn(); }
		if (!memcmp(inName.__s,L"__setHref",sizeof(wchar_t)*9) ) { return __setHref_dyn(); }
		if (!memcmp(inName.__s,L"openIndex",sizeof(wchar_t)*9) ) { return __getOpenIndex(); }
		break;
	case 10:
		if (!memcmp(inName.__s,L"__getOwner",sizeof(wchar_t)*10) ) { return __getOwner_dyn(); }
		if (!memcmp(inName.__s,L"__setOwner",sizeof(wchar_t)*10) ) { return __setOwner_dyn(); }
		if (!memcmp(inName.__s,L"closeIndex",sizeof(wchar_t)*10) ) { return __getCloseIndex(); }
		break;
	case 11:
		if (!memcmp(inName.__s,L"__getTarget",sizeof(wchar_t)*11) ) { return __getTarget_dyn(); }
		if (!memcmp(inName.__s,L"__setTarget",sizeof(wchar_t)*11) ) { return __setTarget_dyn(); }
		break;
	case 12:
		if (!memcmp(inName.__s,L"getTextLinks",sizeof(wchar_t)*12) ) { return getTextLinks_dyn(); }
		if (!memcmp(inName.__s,L"__iOpenIndex",sizeof(wchar_t)*12) ) { return __iOpenIndex; }
		break;
	case 13:
		if (!memcmp(inName.__s,L"__iCloseIndex",sizeof(wchar_t)*13) ) { return __iCloseIndex; }
		break;
	case 14:
		if (!memcmp(inName.__s,L"__getOpenIndex",sizeof(wchar_t)*14) ) { return __getOpenIndex_dyn(); }
		if (!memcmp(inName.__s,L"__setOpenIndex",sizeof(wchar_t)*14) ) { return __setOpenIndex_dyn(); }
		break;
	case 15:
		if (!memcmp(inName.__s,L"__getCloseIndex",sizeof(wchar_t)*15) ) { return __getCloseIndex_dyn(); }
		if (!memcmp(inName.__s,L"__setCloseIndex",sizeof(wchar_t)*15) ) { return __setCloseIndex_dyn(); }
	}
	return super::__Field(inName);
}

Dynamic TextLink_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	switch(inName.length) {
	case 1:
		if (!memcmp(inName.__s,L"x",sizeof(wchar_t)*1) ) { x=inValue.Cast< double >(); return inValue; }
		if (!memcmp(inName.__s,L"y",sizeof(wchar_t)*1) ) { y=inValue.Cast< double >(); return inValue; }
		break;
	case 4:
		if (!memcmp(inName.__s,L"href",sizeof(wchar_t)*4) ) { return __setHref(inValue); }
		break;
	case 5:
		if (!memcmp(inName.__s,L"width",sizeof(wchar_t)*5) ) { width=inValue.Cast< double >(); return inValue; }
		if (!memcmp(inName.__s,L"owner",sizeof(wchar_t)*5) ) { return __setOwner(inValue); }
		break;
	case 6:
		if (!memcmp(inName.__s,L"height",sizeof(wchar_t)*6) ) { height=inValue.Cast< double >(); return inValue; }
		if (!memcmp(inName.__s,L"target",sizeof(wchar_t)*6) ) { return __setTarget(inValue); }
		break;
	case 7:
		if (!memcmp(inName.__s,L"__sHRef",sizeof(wchar_t)*7) ) { __sHRef=inValue.Cast< ::String >(); return inValue; }
		break;
	case 9:
		if (!memcmp(inName.__s,L"__sTarget",sizeof(wchar_t)*9) ) { __sTarget=inValue.Cast< ::String >(); return inValue; }
		if (!memcmp(inName.__s,L"__tfOwner",sizeof(wchar_t)*9) ) { __tfOwner=inValue.Cast< ::neash::text::NeashText >(); return inValue; }
		if (!memcmp(inName.__s,L"__rBounds",sizeof(wchar_t)*9) ) { __rBounds=inValue.Cast< ::nme::geom::Rectangle >(); return inValue; }
		if (!memcmp(inName.__s,L"openIndex",sizeof(wchar_t)*9) ) { return __setOpenIndex(inValue); }
		break;
	case 10:
		if (!memcmp(inName.__s,L"closeIndex",sizeof(wchar_t)*10) ) { return __setCloseIndex(inValue); }
		break;
	case 12:
		if (!memcmp(inName.__s,L"__iOpenIndex",sizeof(wchar_t)*12) ) { __iOpenIndex=inValue.Cast< int >(); return inValue; }
		break;
	case 13:
		if (!memcmp(inName.__s,L"__iCloseIndex",sizeof(wchar_t)*13) ) { __iCloseIndex=inValue.Cast< int >(); return inValue; }
	}
	return super::__SetField(inName,inValue);
}

void TextLink_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_STRING(L"x",1));
	outFields->push(HX_STRING(L"y",1));
	outFields->push(HX_STRING(L"height",6));
	outFields->push(HX_STRING(L"width",5));
	outFields->push(HX_STRING(L"__sHRef",7));
	outFields->push(HX_STRING(L"__sTarget",9));
	outFields->push(HX_STRING(L"__iOpenIndex",12));
	outFields->push(HX_STRING(L"__iCloseIndex",13));
	outFields->push(HX_STRING(L"__tfOwner",9));
	outFields->push(HX_STRING(L"__rBounds",9));
	outFields->push(HX_STRING(L"owner",5));
	outFields->push(HX_STRING(L"target",6));
	outFields->push(HX_STRING(L"href",4));
	outFields->push(HX_STRING(L"openIndex",9));
	outFields->push(HX_STRING(L"closeIndex",10));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_STRING(L"getTextLinks",12),
	String(null()) };

static ::String sMemberFields[] = {
	HX_STRING(L"x",1),
	HX_STRING(L"y",1),
	HX_STRING(L"height",6),
	HX_STRING(L"width",5),
	HX_STRING(L"__sHRef",7),
	HX_STRING(L"__sTarget",9),
	HX_STRING(L"__iOpenIndex",12),
	HX_STRING(L"__iCloseIndex",13),
	HX_STRING(L"__tfOwner",9),
	HX_STRING(L"__rBounds",9),
	HX_STRING(L"getBounds",9),
	HX_STRING(L"owner",5),
	HX_STRING(L"__getOwner",10),
	HX_STRING(L"__setOwner",10),
	HX_STRING(L"target",6),
	HX_STRING(L"__getTarget",11),
	HX_STRING(L"__setTarget",11),
	HX_STRING(L"href",4),
	HX_STRING(L"__getHref",9),
	HX_STRING(L"__setHref",9),
	HX_STRING(L"openIndex",9),
	HX_STRING(L"__getOpenIndex",14),
	HX_STRING(L"__setOpenIndex",14),
	HX_STRING(L"closeIndex",10),
	HX_STRING(L"__getCloseIndex",15),
	HX_STRING(L"__setCloseIndex",15),
	HX_STRING(L"_init",5),
	String(null()) };

static void sMarkStatics() {
};

Class TextLink_obj::__mClass;

void TextLink_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_STRING(L"sandy.core.interaction.TextLink",31), hx::TCanCast< TextLink_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void TextLink_obj::__boot()
{
}

} // end namespace sandy
} // end namespace core
} // end namespace interaction
