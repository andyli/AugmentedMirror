#include <hxcpp.h>

#ifndef INCLUDED_sandy_view_CullingState
#include <sandy/view/CullingState.h>
#endif
namespace sandy{
namespace view{

Void CullingState_obj::__construct()
{
	return null();
}

CullingState_obj::~CullingState_obj() { }

Dynamic CullingState_obj::__CreateEmpty() { return  new CullingState_obj; }
hx::ObjectPtr< CullingState_obj > CullingState_obj::__new()
{  hx::ObjectPtr< CullingState_obj > result = new CullingState_obj();
	result->__construct();
	return result;}

Dynamic CullingState_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< CullingState_obj > result = new CullingState_obj();
	result->__construct();
	return result;}

int CullingState_obj::INTERSECT;

int CullingState_obj::INSIDE;

int CullingState_obj::OUTSIDE;


CullingState_obj::CullingState_obj()
{
}

void CullingState_obj::__Mark()
{
}

Dynamic CullingState_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 6:
		if (!memcmp(inName.__s,L"INSIDE",sizeof(wchar_t)*6) ) { return INSIDE; }
		break;
	case 7:
		if (!memcmp(inName.__s,L"OUTSIDE",sizeof(wchar_t)*7) ) { return OUTSIDE; }
		break;
	case 9:
		if (!memcmp(inName.__s,L"INTERSECT",sizeof(wchar_t)*9) ) { return INTERSECT; }
	}
	return super::__Field(inName);
}

Dynamic CullingState_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	switch(inName.length) {
	case 6:
		if (!memcmp(inName.__s,L"INSIDE",sizeof(wchar_t)*6) ) { INSIDE=inValue.Cast< int >(); return inValue; }
		break;
	case 7:
		if (!memcmp(inName.__s,L"OUTSIDE",sizeof(wchar_t)*7) ) { OUTSIDE=inValue.Cast< int >(); return inValue; }
		break;
	case 9:
		if (!memcmp(inName.__s,L"INTERSECT",sizeof(wchar_t)*9) ) { INTERSECT=inValue.Cast< int >(); return inValue; }
	}
	return super::__SetField(inName,inValue);
}

void CullingState_obj::__GetFields(Array< ::String> &outFields)
{
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_STRING(L"INTERSECT",9),
	HX_STRING(L"INSIDE",6),
	HX_STRING(L"OUTSIDE",7),
	String(null()) };

static ::String sMemberFields[] = {
	String(null()) };

static void sMarkStatics() {
	hx::MarkMember(CullingState_obj::INTERSECT);
	hx::MarkMember(CullingState_obj::INSIDE);
	hx::MarkMember(CullingState_obj::OUTSIDE);
};

Class CullingState_obj::__mClass;

void CullingState_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_STRING(L"sandy.view.CullingState",23), hx::TCanCast< CullingState_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void CullingState_obj::__boot()
{
	hx::Static(INTERSECT) = 0;
	hx::Static(INSIDE) = 1;
	hx::Static(OUTSIDE) = 2;
}

} // end namespace sandy
} // end namespace view
