#include <hxcpp.h>

#ifndef INCLUDED_neash_text_TextFieldAutoSize
#include <neash/text/TextFieldAutoSize.h>
#endif
namespace neash{
namespace text{

Void TextFieldAutoSize_obj::__construct()
{
{
}
;
	return null();
}

TextFieldAutoSize_obj::~TextFieldAutoSize_obj() { }

Dynamic TextFieldAutoSize_obj::__CreateEmpty() { return  new TextFieldAutoSize_obj; }
hx::ObjectPtr< TextFieldAutoSize_obj > TextFieldAutoSize_obj::__new()
{  hx::ObjectPtr< TextFieldAutoSize_obj > result = new TextFieldAutoSize_obj();
	result->__construct();
	return result;}

Dynamic TextFieldAutoSize_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< TextFieldAutoSize_obj > result = new TextFieldAutoSize_obj();
	result->__construct();
	return result;}

::String TextFieldAutoSize_obj::CENTER;

::String TextFieldAutoSize_obj::LEFT;

::String TextFieldAutoSize_obj::NONE;

::String TextFieldAutoSize_obj::RIGHT;


TextFieldAutoSize_obj::TextFieldAutoSize_obj()
{
}

void TextFieldAutoSize_obj::__Mark()
{
}

Dynamic TextFieldAutoSize_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 4:
		if (!memcmp(inName.__s,L"LEFT",sizeof(wchar_t)*4) ) { return LEFT; }
		if (!memcmp(inName.__s,L"NONE",sizeof(wchar_t)*4) ) { return NONE; }
		break;
	case 5:
		if (!memcmp(inName.__s,L"RIGHT",sizeof(wchar_t)*5) ) { return RIGHT; }
		break;
	case 6:
		if (!memcmp(inName.__s,L"CENTER",sizeof(wchar_t)*6) ) { return CENTER; }
	}
	return super::__Field(inName);
}

Dynamic TextFieldAutoSize_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	switch(inName.length) {
	case 4:
		if (!memcmp(inName.__s,L"LEFT",sizeof(wchar_t)*4) ) { LEFT=inValue.Cast< ::String >(); return inValue; }
		if (!memcmp(inName.__s,L"NONE",sizeof(wchar_t)*4) ) { NONE=inValue.Cast< ::String >(); return inValue; }
		break;
	case 5:
		if (!memcmp(inName.__s,L"RIGHT",sizeof(wchar_t)*5) ) { RIGHT=inValue.Cast< ::String >(); return inValue; }
		break;
	case 6:
		if (!memcmp(inName.__s,L"CENTER",sizeof(wchar_t)*6) ) { CENTER=inValue.Cast< ::String >(); return inValue; }
	}
	return super::__SetField(inName,inValue);
}

void TextFieldAutoSize_obj::__GetFields(Array< ::String> &outFields)
{
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_STRING(L"CENTER",6),
	HX_STRING(L"LEFT",4),
	HX_STRING(L"NONE",4),
	HX_STRING(L"RIGHT",5),
	String(null()) };

static ::String sMemberFields[] = {
	String(null()) };

static void sMarkStatics() {
	hx::MarkMember(TextFieldAutoSize_obj::CENTER);
	hx::MarkMember(TextFieldAutoSize_obj::LEFT);
	hx::MarkMember(TextFieldAutoSize_obj::NONE);
	hx::MarkMember(TextFieldAutoSize_obj::RIGHT);
};

Class TextFieldAutoSize_obj::__mClass;

void TextFieldAutoSize_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_STRING(L"neash.text.TextFieldAutoSize",28), hx::TCanCast< TextFieldAutoSize_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void TextFieldAutoSize_obj::__boot()
{
	hx::Static(CENTER) = HX_STRING(L"CENTER",6);
	hx::Static(LEFT) = HX_STRING(L"LEFT",4);
	hx::Static(NONE) = HX_STRING(L"NONE",4);
	hx::Static(RIGHT) = HX_STRING(L"RIGHT",5);
}

} // end namespace neash
} // end namespace text
