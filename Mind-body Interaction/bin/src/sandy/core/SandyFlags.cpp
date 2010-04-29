#include <hxcpp.h>

#ifndef INCLUDED_sandy_core_SandyFlags
#include <sandy/core/SandyFlags.h>
#endif
namespace sandy{
namespace core{

Void SandyFlags_obj::__construct()
{
	return null();
}

SandyFlags_obj::~SandyFlags_obj() { }

Dynamic SandyFlags_obj::__CreateEmpty() { return  new SandyFlags_obj; }
hx::ObjectPtr< SandyFlags_obj > SandyFlags_obj::__new()
{  hx::ObjectPtr< SandyFlags_obj > result = new SandyFlags_obj();
	result->__construct();
	return result;}

Dynamic SandyFlags_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< SandyFlags_obj > result = new SandyFlags_obj();
	result->__construct();
	return result;}

int SandyFlags_obj::POLYGON_NORMAL_WORLD;

int SandyFlags_obj::VERTEX_NORMAL_WORLD;


SandyFlags_obj::SandyFlags_obj()
{
}

void SandyFlags_obj::__Mark()
{
}

Dynamic SandyFlags_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 19:
		if (!memcmp(inName.__s,L"VERTEX_NORMAL_WORLD",sizeof(wchar_t)*19) ) { return VERTEX_NORMAL_WORLD; }
		break;
	case 20:
		if (!memcmp(inName.__s,L"POLYGON_NORMAL_WORLD",sizeof(wchar_t)*20) ) { return POLYGON_NORMAL_WORLD; }
	}
	return super::__Field(inName);
}

Dynamic SandyFlags_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	switch(inName.length) {
	case 19:
		if (!memcmp(inName.__s,L"VERTEX_NORMAL_WORLD",sizeof(wchar_t)*19) ) { VERTEX_NORMAL_WORLD=inValue.Cast< int >(); return inValue; }
		break;
	case 20:
		if (!memcmp(inName.__s,L"POLYGON_NORMAL_WORLD",sizeof(wchar_t)*20) ) { POLYGON_NORMAL_WORLD=inValue.Cast< int >(); return inValue; }
	}
	return super::__SetField(inName,inValue);
}

void SandyFlags_obj::__GetFields(Array< ::String> &outFields)
{
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_STRING(L"POLYGON_NORMAL_WORLD",20),
	HX_STRING(L"VERTEX_NORMAL_WORLD",19),
	String(null()) };

static ::String sMemberFields[] = {
	String(null()) };

static void sMarkStatics() {
	hx::MarkMember(SandyFlags_obj::POLYGON_NORMAL_WORLD);
	hx::MarkMember(SandyFlags_obj::VERTEX_NORMAL_WORLD);
};

Class SandyFlags_obj::__mClass;

void SandyFlags_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_STRING(L"sandy.core.SandyFlags",21), hx::TCanCast< SandyFlags_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void SandyFlags_obj::__boot()
{
	hx::Static(POLYGON_NORMAL_WORLD) = 1;
	hx::Static(VERTEX_NORMAL_WORLD) = 2;
}

} // end namespace sandy
} // end namespace core
