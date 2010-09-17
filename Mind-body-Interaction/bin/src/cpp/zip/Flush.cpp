#include <hxcpp.h>

#ifndef INCLUDED_cpp_zip_Flush
#include <cpp/zip/Flush.h>
#endif
namespace cpp{
namespace zip{

Flush Flush_obj::BLOCK;

Flush Flush_obj::FINISH;

Flush Flush_obj::FULL;

Flush Flush_obj::NO;

Flush Flush_obj::SYNC;

HX_DEFINE_CREATE_ENUM(Flush_obj)

int Flush_obj::__FindIndex(::String inName)
{
	if (inName==HX_STRING(L"BLOCK",5)) return 4;
	if (inName==HX_STRING(L"FINISH",6)) return 3;
	if (inName==HX_STRING(L"FULL",4)) return 2;
	if (inName==HX_STRING(L"NO",2)) return 0;
	if (inName==HX_STRING(L"SYNC",4)) return 1;
	return super::__FindIndex(inName);
}

int Flush_obj::__FindArgCount(::String inName)
{
	if (inName==HX_STRING(L"BLOCK",5)) return 0;
	if (inName==HX_STRING(L"FINISH",6)) return 0;
	if (inName==HX_STRING(L"FULL",4)) return 0;
	if (inName==HX_STRING(L"NO",2)) return 0;
	if (inName==HX_STRING(L"SYNC",4)) return 0;
	return super::__FindArgCount(inName);
}

Dynamic Flush_obj::__Field(const ::String &inName)
{
	if (inName==HX_STRING(L"BLOCK",5)) return BLOCK;
	if (inName==HX_STRING(L"FINISH",6)) return FINISH;
	if (inName==HX_STRING(L"FULL",4)) return FULL;
	if (inName==HX_STRING(L"NO",2)) return NO;
	if (inName==HX_STRING(L"SYNC",4)) return SYNC;
	return super::__Field(inName);
}

static ::String sStaticFields[] = {
	HX_STRING(L"BLOCK",5),
	HX_STRING(L"FINISH",6),
	HX_STRING(L"FULL",4),
	HX_STRING(L"NO",2),
	HX_STRING(L"SYNC",4),
	::String(null()) };

static void sMarkStatics() {
	hx::MarkMember(Flush_obj::BLOCK);
	hx::MarkMember(Flush_obj::FINISH);
	hx::MarkMember(Flush_obj::FULL);
	hx::MarkMember(Flush_obj::NO);
	hx::MarkMember(Flush_obj::SYNC);
};

static ::String sMemberFields[] = { ::String(null()) };
Class Flush_obj::__mClass;

Dynamic __Create_Flush_obj() { return new Flush_obj; }

void Flush_obj::__register()
{

Static(__mClass) = hx::RegisterClass(HX_STRING(L"cpp.zip.Flush",13), hx::TCanCast< Flush_obj >,sStaticFields,sMemberFields,
	&__Create_Flush_obj, &__Create,
	&super::__SGetClass(), &CreateFlush_obj, sMarkStatics);
}

void Flush_obj::__boot()
{
Static(BLOCK) = hx::CreateEnum< Flush_obj >(HX_STRING(L"BLOCK",5),4);
Static(FINISH) = hx::CreateEnum< Flush_obj >(HX_STRING(L"FINISH",6),3);
Static(FULL) = hx::CreateEnum< Flush_obj >(HX_STRING(L"FULL",4),2);
Static(NO) = hx::CreateEnum< Flush_obj >(HX_STRING(L"NO",2),0);
Static(SYNC) = hx::CreateEnum< Flush_obj >(HX_STRING(L"SYNC",4),1);
}


} // end namespace cpp
} // end namespace zip
