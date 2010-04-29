#include <hxcpp.h>

#ifndef INCLUDED_neash_text_TextFormat
#include <neash/text/TextFormat.h>
#endif
namespace neash{
namespace text{

Void TextFormat_obj::__construct(::String in_font,Dynamic in_size,Dynamic in_color,Dynamic in_bold,Dynamic in_italic,Dynamic in_underline,::String in_url,::String in_target,::String in_align,Dynamic in_leftMargin,Dynamic in_rightMargin,Dynamic in_indent,Dynamic in_leading)
{
{
	this->font = in_font;
	this->size = in_size;
	this->color = in_color;
	this->bold = in_bold;
	this->italic = in_italic;
	this->underline = in_underline;
	this->url = in_url;
	this->target = in_target;
	this->align = in_align;
	this->leftMargin = in_leftMargin;
	this->rightMargin = in_rightMargin;
	this->indent = in_indent;
	this->leading = in_leading;
}
;
	return null();
}

TextFormat_obj::~TextFormat_obj() { }

Dynamic TextFormat_obj::__CreateEmpty() { return  new TextFormat_obj; }
hx::ObjectPtr< TextFormat_obj > TextFormat_obj::__new(::String in_font,Dynamic in_size,Dynamic in_color,Dynamic in_bold,Dynamic in_italic,Dynamic in_underline,::String in_url,::String in_target,::String in_align,Dynamic in_leftMargin,Dynamic in_rightMargin,Dynamic in_indent,Dynamic in_leading)
{  hx::ObjectPtr< TextFormat_obj > result = new TextFormat_obj();
	result->__construct(in_font,in_size,in_color,in_bold,in_italic,in_underline,in_url,in_target,in_align,in_leftMargin,in_rightMargin,in_indent,in_leading);
	return result;}

Dynamic TextFormat_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< TextFormat_obj > result = new TextFormat_obj();
	result->__construct(inArgs[0],inArgs[1],inArgs[2],inArgs[3],inArgs[4],inArgs[5],inArgs[6],inArgs[7],inArgs[8],inArgs[9],inArgs[10],inArgs[11],inArgs[12]);
	return result;}


TextFormat_obj::TextFormat_obj()
{
}

void TextFormat_obj::__Mark()
{
	hx::MarkMember(align);
	hx::MarkMember(blockIndent);
	hx::MarkMember(bold);
	hx::MarkMember(bullet);
	hx::MarkMember(color);
	hx::MarkMember(display);
	hx::MarkMember(font);
	hx::MarkMember(indent);
	hx::MarkMember(italic);
	hx::MarkMember(kerning);
	hx::MarkMember(leading);
	hx::MarkMember(leftMargin);
	hx::MarkMember(letterSpacing);
	hx::MarkMember(rightMargin);
	hx::MarkMember(size);
	hx::MarkMember(tabStops);
	hx::MarkMember(target);
	hx::MarkMember(underline);
	hx::MarkMember(url);
}

Dynamic TextFormat_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 3:
		if (!memcmp(inName.__s,L"url",sizeof(wchar_t)*3) ) { return url; }
		break;
	case 4:
		if (!memcmp(inName.__s,L"bold",sizeof(wchar_t)*4) ) { return bold; }
		if (!memcmp(inName.__s,L"font",sizeof(wchar_t)*4) ) { return font; }
		if (!memcmp(inName.__s,L"size",sizeof(wchar_t)*4) ) { return size; }
		break;
	case 5:
		if (!memcmp(inName.__s,L"align",sizeof(wchar_t)*5) ) { return align; }
		if (!memcmp(inName.__s,L"color",sizeof(wchar_t)*5) ) { return color; }
		break;
	case 6:
		if (!memcmp(inName.__s,L"bullet",sizeof(wchar_t)*6) ) { return bullet; }
		if (!memcmp(inName.__s,L"indent",sizeof(wchar_t)*6) ) { return indent; }
		if (!memcmp(inName.__s,L"italic",sizeof(wchar_t)*6) ) { return italic; }
		if (!memcmp(inName.__s,L"target",sizeof(wchar_t)*6) ) { return target; }
		break;
	case 7:
		if (!memcmp(inName.__s,L"display",sizeof(wchar_t)*7) ) { return display; }
		if (!memcmp(inName.__s,L"kerning",sizeof(wchar_t)*7) ) { return kerning; }
		if (!memcmp(inName.__s,L"leading",sizeof(wchar_t)*7) ) { return leading; }
		break;
	case 8:
		if (!memcmp(inName.__s,L"tabStops",sizeof(wchar_t)*8) ) { return tabStops; }
		break;
	case 9:
		if (!memcmp(inName.__s,L"underline",sizeof(wchar_t)*9) ) { return underline; }
		break;
	case 10:
		if (!memcmp(inName.__s,L"leftMargin",sizeof(wchar_t)*10) ) { return leftMargin; }
		break;
	case 11:
		if (!memcmp(inName.__s,L"blockIndent",sizeof(wchar_t)*11) ) { return blockIndent; }
		if (!memcmp(inName.__s,L"rightMargin",sizeof(wchar_t)*11) ) { return rightMargin; }
		break;
	case 13:
		if (!memcmp(inName.__s,L"letterSpacing",sizeof(wchar_t)*13) ) { return letterSpacing; }
	}
	return super::__Field(inName);
}

Dynamic TextFormat_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	switch(inName.length) {
	case 3:
		if (!memcmp(inName.__s,L"url",sizeof(wchar_t)*3) ) { url=inValue.Cast< ::String >(); return inValue; }
		break;
	case 4:
		if (!memcmp(inName.__s,L"bold",sizeof(wchar_t)*4) ) { bold=inValue.Cast< Dynamic >(); return inValue; }
		if (!memcmp(inName.__s,L"font",sizeof(wchar_t)*4) ) { font=inValue.Cast< ::String >(); return inValue; }
		if (!memcmp(inName.__s,L"size",sizeof(wchar_t)*4) ) { size=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 5:
		if (!memcmp(inName.__s,L"align",sizeof(wchar_t)*5) ) { align=inValue.Cast< ::String >(); return inValue; }
		if (!memcmp(inName.__s,L"color",sizeof(wchar_t)*5) ) { color=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 6:
		if (!memcmp(inName.__s,L"bullet",sizeof(wchar_t)*6) ) { bullet=inValue.Cast< Dynamic >(); return inValue; }
		if (!memcmp(inName.__s,L"indent",sizeof(wchar_t)*6) ) { indent=inValue.Cast< Dynamic >(); return inValue; }
		if (!memcmp(inName.__s,L"italic",sizeof(wchar_t)*6) ) { italic=inValue.Cast< Dynamic >(); return inValue; }
		if (!memcmp(inName.__s,L"target",sizeof(wchar_t)*6) ) { target=inValue.Cast< ::String >(); return inValue; }
		break;
	case 7:
		if (!memcmp(inName.__s,L"display",sizeof(wchar_t)*7) ) { display=inValue.Cast< ::String >(); return inValue; }
		if (!memcmp(inName.__s,L"kerning",sizeof(wchar_t)*7) ) { kerning=inValue.Cast< Dynamic >(); return inValue; }
		if (!memcmp(inName.__s,L"leading",sizeof(wchar_t)*7) ) { leading=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 8:
		if (!memcmp(inName.__s,L"tabStops",sizeof(wchar_t)*8) ) { tabStops=inValue.Cast< Array< int > >(); return inValue; }
		break;
	case 9:
		if (!memcmp(inName.__s,L"underline",sizeof(wchar_t)*9) ) { underline=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 10:
		if (!memcmp(inName.__s,L"leftMargin",sizeof(wchar_t)*10) ) { leftMargin=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 11:
		if (!memcmp(inName.__s,L"blockIndent",sizeof(wchar_t)*11) ) { blockIndent=inValue.Cast< Dynamic >(); return inValue; }
		if (!memcmp(inName.__s,L"rightMargin",sizeof(wchar_t)*11) ) { rightMargin=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 13:
		if (!memcmp(inName.__s,L"letterSpacing",sizeof(wchar_t)*13) ) { letterSpacing=inValue.Cast< Dynamic >(); return inValue; }
	}
	return super::__SetField(inName,inValue);
}

void TextFormat_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_STRING(L"align",5));
	outFields->push(HX_STRING(L"blockIndent",11));
	outFields->push(HX_STRING(L"bold",4));
	outFields->push(HX_STRING(L"bullet",6));
	outFields->push(HX_STRING(L"color",5));
	outFields->push(HX_STRING(L"display",7));
	outFields->push(HX_STRING(L"font",4));
	outFields->push(HX_STRING(L"indent",6));
	outFields->push(HX_STRING(L"italic",6));
	outFields->push(HX_STRING(L"kerning",7));
	outFields->push(HX_STRING(L"leading",7));
	outFields->push(HX_STRING(L"leftMargin",10));
	outFields->push(HX_STRING(L"letterSpacing",13));
	outFields->push(HX_STRING(L"rightMargin",11));
	outFields->push(HX_STRING(L"size",4));
	outFields->push(HX_STRING(L"tabStops",8));
	outFields->push(HX_STRING(L"target",6));
	outFields->push(HX_STRING(L"underline",9));
	outFields->push(HX_STRING(L"url",3));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_STRING(L"align",5),
	HX_STRING(L"blockIndent",11),
	HX_STRING(L"bold",4),
	HX_STRING(L"bullet",6),
	HX_STRING(L"color",5),
	HX_STRING(L"display",7),
	HX_STRING(L"font",4),
	HX_STRING(L"indent",6),
	HX_STRING(L"italic",6),
	HX_STRING(L"kerning",7),
	HX_STRING(L"leading",7),
	HX_STRING(L"leftMargin",10),
	HX_STRING(L"letterSpacing",13),
	HX_STRING(L"rightMargin",11),
	HX_STRING(L"size",4),
	HX_STRING(L"tabStops",8),
	HX_STRING(L"target",6),
	HX_STRING(L"underline",9),
	HX_STRING(L"url",3),
	String(null()) };

static void sMarkStatics() {
};

Class TextFormat_obj::__mClass;

void TextFormat_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_STRING(L"neash.text.TextFormat",21), hx::TCanCast< TextFormat_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void TextFormat_obj::__boot()
{
}

} // end namespace neash
} // end namespace text
