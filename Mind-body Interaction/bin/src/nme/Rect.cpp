#include <hxcpp.h>

#ifndef INCLUDED_nme_Rect
#include <nme/Rect.h>
#endif
namespace nme{

Void Rect_obj::__construct(int vX,int vY,int vW,int vH)
{
{
	this->x = vX;
	this->y = vY;
	this->w = vW;
	this->h = vH;
}
;
	return null();
}

Rect_obj::~Rect_obj() { }

Dynamic Rect_obj::__CreateEmpty() { return  new Rect_obj; }
hx::ObjectPtr< Rect_obj > Rect_obj::__new(int vX,int vY,int vW,int vH)
{  hx::ObjectPtr< Rect_obj > result = new Rect_obj();
	result->__construct(vX,vY,vW,vH);
	return result;}

Dynamic Rect_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Rect_obj > result = new Rect_obj();
	result->__construct(inArgs[0],inArgs[1],inArgs[2],inArgs[3]);
	return result;}


Rect_obj::Rect_obj()
{
}

void Rect_obj::__Mark()
{
	hx::MarkMember(x);
	hx::MarkMember(y);
	hx::MarkMember(w);
	hx::MarkMember(h);
}

Dynamic Rect_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 1:
		if (!memcmp(inName.__s,L"x",sizeof(wchar_t)*1) ) { return x; }
		if (!memcmp(inName.__s,L"y",sizeof(wchar_t)*1) ) { return y; }
		if (!memcmp(inName.__s,L"w",sizeof(wchar_t)*1) ) { return w; }
		if (!memcmp(inName.__s,L"h",sizeof(wchar_t)*1) ) { return h; }
	}
	return super::__Field(inName);
}

Dynamic Rect_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	switch(inName.length) {
	case 1:
		if (!memcmp(inName.__s,L"x",sizeof(wchar_t)*1) ) { x=inValue.Cast< int >(); return inValue; }
		if (!memcmp(inName.__s,L"y",sizeof(wchar_t)*1) ) { y=inValue.Cast< int >(); return inValue; }
		if (!memcmp(inName.__s,L"w",sizeof(wchar_t)*1) ) { w=inValue.Cast< int >(); return inValue; }
		if (!memcmp(inName.__s,L"h",sizeof(wchar_t)*1) ) { h=inValue.Cast< int >(); return inValue; }
	}
	return super::__SetField(inName,inValue);
}

void Rect_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_STRING(L"x",1));
	outFields->push(HX_STRING(L"y",1));
	outFields->push(HX_STRING(L"w",1));
	outFields->push(HX_STRING(L"h",1));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_STRING(L"x",1),
	HX_STRING(L"y",1),
	HX_STRING(L"w",1),
	HX_STRING(L"h",1),
	String(null()) };

static void sMarkStatics() {
};

Class Rect_obj::__mClass;

void Rect_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_STRING(L"nme.Rect",8), hx::TCanCast< Rect_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void Rect_obj::__boot()
{
}

} // end namespace nme
