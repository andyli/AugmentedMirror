#include <hxcpp.h>

#ifndef INCLUDED_neash_text_TextFormatAlign
#include <neash/text/TextFormatAlign.h>
#endif
namespace neash{
namespace text{

Void TextFormatAlign_obj::__construct()
{
	return null();
}

TextFormatAlign_obj::~TextFormatAlign_obj() { }

Dynamic TextFormatAlign_obj::__CreateEmpty() { return  new TextFormatAlign_obj; }
hx::ObjectPtr< TextFormatAlign_obj > TextFormatAlign_obj::__new()
{  hx::ObjectPtr< TextFormatAlign_obj > result = new TextFormatAlign_obj();
	result->__construct();
	return result;}

Dynamic TextFormatAlign_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< TextFormatAlign_obj > result = new TextFormatAlign_obj();
	result->__construct();
	return result;}

::String TextFormatAlign_obj::LEFT;

::String TextFormatAlign_obj::RIGHT;

::String TextFormatAlign_obj::CENTER;

::String TextFormatAlign_obj::JUSTIFY;


TextFormatAlign_obj::TextFormatAlign_obj()
{
}

void TextFormatAlign_obj::__Mark()
{
}

Dynamic TextFormatAlign_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 4:
		if (!memcmp(inName.__s,L"LEFT",sizeof(wchar_t)*4) ) { return LEFT; }
		break;
	case 5:
		if (!memcmp(inName.__s,L"RIGHT",sizeof(wchar_t)*5) ) { return RIGHT; }
		break;
	case 6:
		if (!memcmp(inName.__s,L"CENTER",sizeof(wchar_t)*6) ) { return CENTER; }
		break;
	case 7:
		if (!memcmp(inName.__s,L"JUSTIFY",sizeof(wchar_t)*7) ) { return JUSTIFY; }
	}
	return super::__Field(inName);
}

Dynamic TextFormatAlign_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	switch(inName.length) {
	case 4:
		if (!memcmp(inName.__s,L"LEFT",sizeof(wchar_t)*4) ) { LEFT=inValue.Cast< ::String >(); return inValue; }
		break;
	case 5:
		if (!memcmp(inName.__s,L"RIGHT",sizeof(wchar_t)*5) ) { RIGHT=inValue.Cast< ::String >(); return inValue; }
		break;
	case 6:
		if (!memcmp(inName.__s,L"CENTER",sizeof(wchar_t)*6) ) { CENTER=inValue.Cast< ::String >(); return inValue; }
		break;
	case 7:
		if (!memcmp(inName.__s,L"JUSTIFY",sizeof(wchar_t)*7) ) { JUSTIFY=inValue.Cast< ::String >(); return inValue; }
	}
	return super::__SetField(inName,inValue);
}

void TextFormatAlign_obj::__GetFields(Array< ::String> &outFields)
{
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_STRING(L"LEFT",4),
	HX_STRING(L"RIGHT",5),
	HX_STRING(L"CENTER",6),
	HX_STRING(L"JUSTIFY",7),
	String(null()) };

static ::String sMemberFields[] = {
	String(null()) };

static void sMarkStatics() {
	hx::MarkMember(TextFormatAlign_obj::LEFT);
	hx::MarkMember(TextFormatAlign_obj::RIGHT);
	hx::MarkMember(TextFormatAlign_obj::CENTER);
	hx::MarkMember(TextFormatAlign_obj::JUSTIFY);
};

Class TextFormatAlign_obj::__mClass;

void TextFormatAlign_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_STRING(L"neash.text.TextFormatAlign",26), hx::TCanCast< TextFormatAlign_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void TextFormatAlign_obj::__boot()
{
	hx::Static(LEFT) = HX_STRING(L"left",4);
	hx::Static(RIGHT) = HX_STRING(L"right",5);
	hx::Static(CENTER) = HX_STRING(L"center",6);
	hx::Static(JUSTIFY) = HX_STRING(L"justify",7);
}

} // end namespace neash
} // end namespace text
