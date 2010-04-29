#include <hxcpp.h>

#ifndef INCLUDED_cpp_zip_Uncompress
#include <cpp/zip/Uncompress.h>
#endif
#ifndef INCLUDED_haxe_io_Bytes
#include <haxe/io/Bytes.h>
#endif
#ifndef INCLUDED_haxe_io_BytesInput
#include <haxe/io/BytesInput.h>
#endif
#ifndef INCLUDED_haxe_io_Input
#include <haxe/io/Input.h>
#endif
#ifndef INCLUDED_neash_utils_IDataInput
#include <neash/utils/IDataInput.h>
#endif
#ifndef INCLUDED_neash_utils_Uncompress
#include <neash/utils/Uncompress.h>
#endif
namespace neash{
namespace utils{

Void Uncompress_obj::__construct()
{
	return null();
}

Uncompress_obj::~Uncompress_obj() { }

Dynamic Uncompress_obj::__CreateEmpty() { return  new Uncompress_obj; }
hx::ObjectPtr< Uncompress_obj > Uncompress_obj::__new()
{  hx::ObjectPtr< Uncompress_obj > result = new Uncompress_obj();
	result->__construct();
	return result;}

Dynamic Uncompress_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Uncompress_obj > result = new Uncompress_obj();
	result->__construct();
	return result;}

::neash::utils::IDataInput Uncompress_obj::ConvertStream( ::neash::utils::IDataInput inStream,Dynamic inSize){
	__SAFE_POINT
	::haxe::io::Bytes bytes = (inSize == null()) ? ::haxe::io::Bytes( inStream->readAll(null()) ) : ::haxe::io::Bytes( inStream->readBytes(inSize) );
	return ::neash::utils::IDataInput_obj::__new(::haxe::io::BytesInput_obj::__new(::cpp::zip::Uncompress_obj::run(bytes,null()),null(),null()));
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(Uncompress_obj,ConvertStream,return )

::haxe::io::Bytes Uncompress_obj::Run( ::haxe::io::Bytes inBytes){
	__SAFE_POINT
	return ::cpp::zip::Uncompress_obj::run(inBytes,null());
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Uncompress_obj,Run,return )


Uncompress_obj::Uncompress_obj()
{
}

void Uncompress_obj::__Mark()
{
}

Dynamic Uncompress_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 3:
		if (!memcmp(inName.__s,L"Run",sizeof(wchar_t)*3) ) { return Run_dyn(); }
		break;
	case 13:
		if (!memcmp(inName.__s,L"ConvertStream",sizeof(wchar_t)*13) ) { return ConvertStream_dyn(); }
	}
	return super::__Field(inName);
}

Dynamic Uncompress_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	return super::__SetField(inName,inValue);
}

void Uncompress_obj::__GetFields(Array< ::String> &outFields)
{
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_STRING(L"ConvertStream",13),
	HX_STRING(L"Run",3),
	String(null()) };

static ::String sMemberFields[] = {
	String(null()) };

static void sMarkStatics() {
};

Class Uncompress_obj::__mClass;

void Uncompress_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_STRING(L"neash.utils.Uncompress",22), hx::TCanCast< Uncompress_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void Uncompress_obj::__boot()
{
}

} // end namespace neash
} // end namespace utils
