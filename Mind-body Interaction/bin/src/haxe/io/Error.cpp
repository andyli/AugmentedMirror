#include <hxcpp.h>

#ifndef INCLUDED_haxe_io_Error
#include <haxe/io/Error.h>
#endif
namespace haxe{
namespace io{

Error Error_obj::Blocked;

Error  Error_obj::Custom(Dynamic e)
	{ return hx::CreateEnum< Error_obj >(HX_STRING(L"Custom",6),3,hx::DynamicArray(0,1).Add(e)); }

Error Error_obj::OutsideBounds;

Error Error_obj::Overflow;

HX_DEFINE_CREATE_ENUM(Error_obj)

int Error_obj::__FindIndex(::String inName)
{
	if (inName==HX_STRING(L"Blocked",7)) return 0;
	if (inName==HX_STRING(L"Custom",6)) return 3;
	if (inName==HX_STRING(L"OutsideBounds",13)) return 2;
	if (inName==HX_STRING(L"Overflow",8)) return 1;
	return super::__FindIndex(inName);
}

STATIC_HX_DEFINE_DYNAMIC_FUNC1(Error_obj,Custom,return)

int Error_obj::__FindArgCount(::String inName)
{
	if (inName==HX_STRING(L"Blocked",7)) return 0;
	if (inName==HX_STRING(L"Custom",6)) return 1;
	if (inName==HX_STRING(L"OutsideBounds",13)) return 0;
	if (inName==HX_STRING(L"Overflow",8)) return 0;
	return super::__FindArgCount(inName);
}

Dynamic Error_obj::__Field(const ::String &inName)
{
	if (inName==HX_STRING(L"Blocked",7)) return Blocked;
	if (inName==HX_STRING(L"Custom",6)) return Custom_dyn();
	if (inName==HX_STRING(L"OutsideBounds",13)) return OutsideBounds;
	if (inName==HX_STRING(L"Overflow",8)) return Overflow;
	return super::__Field(inName);
}

static ::String sStaticFields[] = {
	HX_STRING(L"Blocked",7),
	HX_STRING(L"Custom",6),
	HX_STRING(L"OutsideBounds",13),
	HX_STRING(L"Overflow",8),
	::String(null()) };

static void sMarkStatics() {
	hx::MarkMember(Error_obj::Blocked);
	hx::MarkMember(Error_obj::OutsideBounds);
	hx::MarkMember(Error_obj::Overflow);
};

static ::String sMemberFields[] = { ::String(null()) };
Class Error_obj::__mClass;

Dynamic __Create_Error_obj() { return new Error_obj; }

void Error_obj::__register()
{

Static(__mClass) = hx::RegisterClass(HX_STRING(L"haxe.io.Error",13), hx::TCanCast< Error_obj >,sStaticFields,sMemberFields,
	&__Create_Error_obj, &__Create,
	&super::__SGetClass(), &CreateError_obj, sMarkStatics);
}

void Error_obj::__boot()
{
Static(Blocked) = hx::CreateEnum< Error_obj >(HX_STRING(L"Blocked",7),0);
Static(OutsideBounds) = hx::CreateEnum< Error_obj >(HX_STRING(L"OutsideBounds",13),2);
Static(Overflow) = hx::CreateEnum< Error_obj >(HX_STRING(L"Overflow",8),1);
}


} // end namespace haxe
} // end namespace io
