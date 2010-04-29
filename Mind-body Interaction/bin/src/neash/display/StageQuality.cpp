#include <hxcpp.h>

#ifndef INCLUDED_neash_display_StageQuality
#include <neash/display/StageQuality.h>
#endif
namespace neash{
namespace display{

Void StageQuality_obj::__construct()
{
	return null();
}

StageQuality_obj::~StageQuality_obj() { }

Dynamic StageQuality_obj::__CreateEmpty() { return  new StageQuality_obj; }
hx::ObjectPtr< StageQuality_obj > StageQuality_obj::__new()
{  hx::ObjectPtr< StageQuality_obj > result = new StageQuality_obj();
	result->__construct();
	return result;}

Dynamic StageQuality_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< StageQuality_obj > result = new StageQuality_obj();
	result->__construct();
	return result;}

::String StageQuality_obj::BEST;

::String StageQuality_obj::HIGH;

::String StageQuality_obj::MEDIUM;

::String StageQuality_obj::LOW;


StageQuality_obj::StageQuality_obj()
{
}

void StageQuality_obj::__Mark()
{
}

Dynamic StageQuality_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 3:
		if (!memcmp(inName.__s,L"LOW",sizeof(wchar_t)*3) ) { return LOW; }
		break;
	case 4:
		if (!memcmp(inName.__s,L"BEST",sizeof(wchar_t)*4) ) { return BEST; }
		if (!memcmp(inName.__s,L"HIGH",sizeof(wchar_t)*4) ) { return HIGH; }
		break;
	case 6:
		if (!memcmp(inName.__s,L"MEDIUM",sizeof(wchar_t)*6) ) { return MEDIUM; }
	}
	return super::__Field(inName);
}

Dynamic StageQuality_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	switch(inName.length) {
	case 3:
		if (!memcmp(inName.__s,L"LOW",sizeof(wchar_t)*3) ) { LOW=inValue.Cast< ::String >(); return inValue; }
		break;
	case 4:
		if (!memcmp(inName.__s,L"BEST",sizeof(wchar_t)*4) ) { BEST=inValue.Cast< ::String >(); return inValue; }
		if (!memcmp(inName.__s,L"HIGH",sizeof(wchar_t)*4) ) { HIGH=inValue.Cast< ::String >(); return inValue; }
		break;
	case 6:
		if (!memcmp(inName.__s,L"MEDIUM",sizeof(wchar_t)*6) ) { MEDIUM=inValue.Cast< ::String >(); return inValue; }
	}
	return super::__SetField(inName,inValue);
}

void StageQuality_obj::__GetFields(Array< ::String> &outFields)
{
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_STRING(L"BEST",4),
	HX_STRING(L"HIGH",4),
	HX_STRING(L"MEDIUM",6),
	HX_STRING(L"LOW",3),
	String(null()) };

static ::String sMemberFields[] = {
	String(null()) };

static void sMarkStatics() {
	hx::MarkMember(StageQuality_obj::BEST);
	hx::MarkMember(StageQuality_obj::HIGH);
	hx::MarkMember(StageQuality_obj::MEDIUM);
	hx::MarkMember(StageQuality_obj::LOW);
};

Class StageQuality_obj::__mClass;

void StageQuality_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_STRING(L"neash.display.StageQuality",26), hx::TCanCast< StageQuality_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void StageQuality_obj::__boot()
{
	hx::Static(BEST) = HX_STRING(L"best",4);
	hx::Static(HIGH) = HX_STRING(L"high",4);
	hx::Static(MEDIUM) = HX_STRING(L"medium",6);
	hx::Static(LOW) = HX_STRING(L"low",3);
}

} // end namespace neash
} // end namespace display
