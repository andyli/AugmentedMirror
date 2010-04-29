#include <hxcpp.h>

#ifndef INCLUDED_sandy_primitive_PrimitiveMode
#include <sandy/primitive/PrimitiveMode.h>
#endif
namespace sandy{
namespace primitive{

Void PrimitiveMode_obj::__construct()
{
	return null();
}

PrimitiveMode_obj::~PrimitiveMode_obj() { }

Dynamic PrimitiveMode_obj::__CreateEmpty() { return  new PrimitiveMode_obj; }
hx::ObjectPtr< PrimitiveMode_obj > PrimitiveMode_obj::__new()
{  hx::ObjectPtr< PrimitiveMode_obj > result = new PrimitiveMode_obj();
	result->__construct();
	return result;}

Dynamic PrimitiveMode_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< PrimitiveMode_obj > result = new PrimitiveMode_obj();
	result->__construct();
	return result;}

::String PrimitiveMode_obj::QUAD;

::String PrimitiveMode_obj::TRI;


PrimitiveMode_obj::PrimitiveMode_obj()
{
}

void PrimitiveMode_obj::__Mark()
{
}

Dynamic PrimitiveMode_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 3:
		if (!memcmp(inName.__s,L"TRI",sizeof(wchar_t)*3) ) { return TRI; }
		break;
	case 4:
		if (!memcmp(inName.__s,L"QUAD",sizeof(wchar_t)*4) ) { return QUAD; }
	}
	return super::__Field(inName);
}

Dynamic PrimitiveMode_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	switch(inName.length) {
	case 3:
		if (!memcmp(inName.__s,L"TRI",sizeof(wchar_t)*3) ) { TRI=inValue.Cast< ::String >(); return inValue; }
		break;
	case 4:
		if (!memcmp(inName.__s,L"QUAD",sizeof(wchar_t)*4) ) { QUAD=inValue.Cast< ::String >(); return inValue; }
	}
	return super::__SetField(inName,inValue);
}

void PrimitiveMode_obj::__GetFields(Array< ::String> &outFields)
{
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_STRING(L"QUAD",4),
	HX_STRING(L"TRI",3),
	String(null()) };

static ::String sMemberFields[] = {
	String(null()) };

static void sMarkStatics() {
	hx::MarkMember(PrimitiveMode_obj::QUAD);
	hx::MarkMember(PrimitiveMode_obj::TRI);
};

Class PrimitiveMode_obj::__mClass;

void PrimitiveMode_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_STRING(L"sandy.primitive.PrimitiveMode",29), hx::TCanCast< PrimitiveMode_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void PrimitiveMode_obj::__boot()
{
	hx::Static(QUAD) = HX_STRING(L"quad",4);
	hx::Static(TRI) = HX_STRING(L"tri",3);
}

} // end namespace sandy
} // end namespace primitive
