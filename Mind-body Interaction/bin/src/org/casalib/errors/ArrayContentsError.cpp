#include <hxcpp.h>

#ifndef INCLUDED_org_casalib_errors_ArrayContentsError
#include <org/casalib/errors/ArrayContentsError.h>
#endif
namespace org{
namespace casalib{
namespace errors{

Void ArrayContentsError_obj::__construct()
{
{
}
;
	return null();
}

ArrayContentsError_obj::~ArrayContentsError_obj() { }

Dynamic ArrayContentsError_obj::__CreateEmpty() { return  new ArrayContentsError_obj; }
hx::ObjectPtr< ArrayContentsError_obj > ArrayContentsError_obj::__new()
{  hx::ObjectPtr< ArrayContentsError_obj > result = new ArrayContentsError_obj();
	result->__construct();
	return result;}

Dynamic ArrayContentsError_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< ArrayContentsError_obj > result = new ArrayContentsError_obj();
	result->__construct();
	return result;}

::String ArrayContentsError_obj::toString( ){
	return HX_STRING(L"The Array is composed of an incorrect number of values, or values of an incorrect type.",87);
}


HX_DEFINE_DYNAMIC_FUNC0(ArrayContentsError_obj,toString,return )


ArrayContentsError_obj::ArrayContentsError_obj()
{
}

void ArrayContentsError_obj::__Mark()
{
}

Dynamic ArrayContentsError_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 8:
		if (!memcmp(inName.__s,L"toString",sizeof(wchar_t)*8) ) { return toString_dyn(); }
	}
	return super::__Field(inName);
}

Dynamic ArrayContentsError_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	return super::__SetField(inName,inValue);
}

void ArrayContentsError_obj::__GetFields(Array< ::String> &outFields)
{
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_STRING(L"toString",8),
	String(null()) };

static void sMarkStatics() {
};

Class ArrayContentsError_obj::__mClass;

void ArrayContentsError_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_STRING(L"org.casalib.errors.ArrayContentsError",37), hx::TCanCast< ArrayContentsError_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void ArrayContentsError_obj::__boot()
{
}

} // end namespace org
} // end namespace casalib
} // end namespace errors
