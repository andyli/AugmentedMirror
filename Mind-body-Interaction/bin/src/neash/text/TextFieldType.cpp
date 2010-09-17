#include <hxcpp.h>

#ifndef INCLUDED_neash_text_TextFieldType
#include <neash/text/TextFieldType.h>
#endif
namespace neash{
namespace text{

Void TextFieldType_obj::__construct()
{
{
}
;
	return null();
}

TextFieldType_obj::~TextFieldType_obj() { }

Dynamic TextFieldType_obj::__CreateEmpty() { return  new TextFieldType_obj; }
hx::ObjectPtr< TextFieldType_obj > TextFieldType_obj::__new()
{  hx::ObjectPtr< TextFieldType_obj > result = new TextFieldType_obj();
	result->__construct();
	return result;}

Dynamic TextFieldType_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< TextFieldType_obj > result = new TextFieldType_obj();
	result->__construct();
	return result;}

::String TextFieldType_obj::DYNAMIC;

::String TextFieldType_obj::INPUT;


TextFieldType_obj::TextFieldType_obj()
{
}

void TextFieldType_obj::__Mark()
{
}

Dynamic TextFieldType_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 5:
		if (!memcmp(inName.__s,L"INPUT",sizeof(wchar_t)*5) ) { return INPUT; }
		break;
	case 7:
		if (!memcmp(inName.__s,L"DYNAMIC",sizeof(wchar_t)*7) ) { return DYNAMIC; }
	}
	return super::__Field(inName);
}

Dynamic TextFieldType_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	switch(inName.length) {
	case 5:
		if (!memcmp(inName.__s,L"INPUT",sizeof(wchar_t)*5) ) { INPUT=inValue.Cast< ::String >(); return inValue; }
		break;
	case 7:
		if (!memcmp(inName.__s,L"DYNAMIC",sizeof(wchar_t)*7) ) { DYNAMIC=inValue.Cast< ::String >(); return inValue; }
	}
	return super::__SetField(inName,inValue);
}

void TextFieldType_obj::__GetFields(Array< ::String> &outFields)
{
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_STRING(L"DYNAMIC",7),
	HX_STRING(L"INPUT",5),
	String(null()) };

static ::String sMemberFields[] = {
	String(null()) };

static void sMarkStatics() {
	hx::MarkMember(TextFieldType_obj::DYNAMIC);
	hx::MarkMember(TextFieldType_obj::INPUT);
};

Class TextFieldType_obj::__mClass;

void TextFieldType_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_STRING(L"neash.text.TextFieldType",24), hx::TCanCast< TextFieldType_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void TextFieldType_obj::__boot()
{
	hx::Static(DYNAMIC) = HX_STRING(L"DYNAMIC",7);
	hx::Static(INPUT) = HX_STRING(L"INPUT",5);
}

} // end namespace neash
} // end namespace text
