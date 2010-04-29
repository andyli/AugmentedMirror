#include <hxcpp.h>

#ifndef INCLUDED_nme_display_GfxPoint
#include <nme/display/GfxPoint.h>
#endif
namespace nme{
namespace display{

Void GfxPoint_obj::__construct(double inX,double inY,double inCX,double inCY,int inType)
{
{
	this->x = inX;
	this->y = inY;
	this->cx = inCX;
	this->cy = inCY;
	this->type = inType;
}
;
	return null();
}

GfxPoint_obj::~GfxPoint_obj() { }

Dynamic GfxPoint_obj::__CreateEmpty() { return  new GfxPoint_obj; }
hx::ObjectPtr< GfxPoint_obj > GfxPoint_obj::__new(double inX,double inY,double inCX,double inCY,int inType)
{  hx::ObjectPtr< GfxPoint_obj > result = new GfxPoint_obj();
	result->__construct(inX,inY,inCX,inCY,inType);
	return result;}

Dynamic GfxPoint_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< GfxPoint_obj > result = new GfxPoint_obj();
	result->__construct(inArgs[0],inArgs[1],inArgs[2],inArgs[3],inArgs[4]);
	return result;}


GfxPoint_obj::GfxPoint_obj()
{
}

void GfxPoint_obj::__Mark()
{
	hx::MarkMember(x);
	hx::MarkMember(y);
	hx::MarkMember(cx);
	hx::MarkMember(cy);
	hx::MarkMember(type);
}

Dynamic GfxPoint_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 1:
		if (!memcmp(inName.__s,L"x",sizeof(wchar_t)*1) ) { return x; }
		if (!memcmp(inName.__s,L"y",sizeof(wchar_t)*1) ) { return y; }
		break;
	case 2:
		if (!memcmp(inName.__s,L"cx",sizeof(wchar_t)*2) ) { return cx; }
		if (!memcmp(inName.__s,L"cy",sizeof(wchar_t)*2) ) { return cy; }
		break;
	case 4:
		if (!memcmp(inName.__s,L"type",sizeof(wchar_t)*4) ) { return type; }
	}
	return super::__Field(inName);
}

static int __id_x = __hxcpp_field_to_id("x");
static int __id_y = __hxcpp_field_to_id("y");
static int __id_cx = __hxcpp_field_to_id("cx");
static int __id_cy = __hxcpp_field_to_id("cy");
static int __id_type = __hxcpp_field_to_id("type");


double GfxPoint_obj::__INumField(int inFieldID)
{
	if (inFieldID==__id_x) return hx::ToDouble( x ) ;
	if (inFieldID==__id_y) return hx::ToDouble( y ) ;
	if (inFieldID==__id_cx) return hx::ToDouble( cx ) ;
	if (inFieldID==__id_cy) return hx::ToDouble( cy ) ;
	if (inFieldID==__id_type) return hx::ToDouble( type ) ;
	return super::__INumField(inFieldID);
}

Dynamic GfxPoint_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	switch(inName.length) {
	case 1:
		if (!memcmp(inName.__s,L"x",sizeof(wchar_t)*1) ) { x=inValue.Cast< double >(); return inValue; }
		if (!memcmp(inName.__s,L"y",sizeof(wchar_t)*1) ) { y=inValue.Cast< double >(); return inValue; }
		break;
	case 2:
		if (!memcmp(inName.__s,L"cx",sizeof(wchar_t)*2) ) { cx=inValue.Cast< double >(); return inValue; }
		if (!memcmp(inName.__s,L"cy",sizeof(wchar_t)*2) ) { cy=inValue.Cast< double >(); return inValue; }
		break;
	case 4:
		if (!memcmp(inName.__s,L"type",sizeof(wchar_t)*4) ) { type=inValue.Cast< int >(); return inValue; }
	}
	return super::__SetField(inName,inValue);
}

void GfxPoint_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_STRING(L"x",1));
	outFields->push(HX_STRING(L"y",1));
	outFields->push(HX_STRING(L"cx",2));
	outFields->push(HX_STRING(L"cy",2));
	outFields->push(HX_STRING(L"type",4));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_STRING(L"x",1),
	HX_STRING(L"y",1),
	HX_STRING(L"cx",2),
	HX_STRING(L"cy",2),
	HX_STRING(L"type",4),
	String(null()) };

static void sMarkStatics() {
};

Class GfxPoint_obj::__mClass;

void GfxPoint_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_STRING(L"nme.display.GfxPoint",20), hx::TCanCast< GfxPoint_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void GfxPoint_obj::__boot()
{
}

} // end namespace nme
} // end namespace display
