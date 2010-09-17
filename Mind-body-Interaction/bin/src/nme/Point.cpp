#include <hxcpp.h>

#ifndef INCLUDED_nme_Point
#include <nme/Point.h>
#endif
namespace nme{

Void Point_obj::__construct(int vX,int vY)
{
{
	this->x = vX;
	this->y = vY;
}
;
	return null();
}

Point_obj::~Point_obj() { }

Dynamic Point_obj::__CreateEmpty() { return  new Point_obj; }
hx::ObjectPtr< Point_obj > Point_obj::__new(int vX,int vY)
{  hx::ObjectPtr< Point_obj > result = new Point_obj();
	result->__construct(vX,vY);
	return result;}

Dynamic Point_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Point_obj > result = new Point_obj();
	result->__construct(inArgs[0],inArgs[1]);
	return result;}


Point_obj::Point_obj()
{
}

void Point_obj::__Mark()
{
	hx::MarkMember(x);
	hx::MarkMember(y);
}

Dynamic Point_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 1:
		if (!memcmp(inName.__s,L"x",sizeof(wchar_t)*1) ) { return x; }
		if (!memcmp(inName.__s,L"y",sizeof(wchar_t)*1) ) { return y; }
	}
	return super::__Field(inName);
}

Dynamic Point_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	switch(inName.length) {
	case 1:
		if (!memcmp(inName.__s,L"x",sizeof(wchar_t)*1) ) { x=inValue.Cast< int >(); return inValue; }
		if (!memcmp(inName.__s,L"y",sizeof(wchar_t)*1) ) { y=inValue.Cast< int >(); return inValue; }
	}
	return super::__SetField(inName,inValue);
}

void Point_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_STRING(L"x",1));
	outFields->push(HX_STRING(L"y",1));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_STRING(L"x",1),
	HX_STRING(L"y",1),
	String(null()) };

static void sMarkStatics() {
};

Class Point_obj::__mClass;

void Point_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_STRING(L"nme.Point",9), hx::TCanCast< Point_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void Point_obj::__boot()
{
}

} // end namespace nme
