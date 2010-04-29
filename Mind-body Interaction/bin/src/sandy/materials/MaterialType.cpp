#include <hxcpp.h>

#ifndef INCLUDED_sandy_materials_MaterialType
#include <sandy/materials/MaterialType.h>
#endif
namespace sandy{
namespace materials{

MaterialType MaterialType_obj::BITMAP;

MaterialType MaterialType_obj::COLOR;

MaterialType MaterialType_obj::MOVIE;

MaterialType MaterialType_obj::NONE;

MaterialType MaterialType_obj::OUTLINE;

MaterialType MaterialType_obj::VIDEO;

MaterialType MaterialType_obj::WIREFRAME;

HX_DEFINE_CREATE_ENUM(MaterialType_obj)

int MaterialType_obj::__FindIndex(::String inName)
{
	if (inName==HX_STRING(L"BITMAP",6)) return 3;
	if (inName==HX_STRING(L"COLOR",5)) return 1;
	if (inName==HX_STRING(L"MOVIE",5)) return 4;
	if (inName==HX_STRING(L"NONE",4)) return 0;
	if (inName==HX_STRING(L"OUTLINE",7)) return 6;
	if (inName==HX_STRING(L"VIDEO",5)) return 5;
	if (inName==HX_STRING(L"WIREFRAME",9)) return 2;
	return super::__FindIndex(inName);
}

int MaterialType_obj::__FindArgCount(::String inName)
{
	if (inName==HX_STRING(L"BITMAP",6)) return 0;
	if (inName==HX_STRING(L"COLOR",5)) return 0;
	if (inName==HX_STRING(L"MOVIE",5)) return 0;
	if (inName==HX_STRING(L"NONE",4)) return 0;
	if (inName==HX_STRING(L"OUTLINE",7)) return 0;
	if (inName==HX_STRING(L"VIDEO",5)) return 0;
	if (inName==HX_STRING(L"WIREFRAME",9)) return 0;
	return super::__FindArgCount(inName);
}

Dynamic MaterialType_obj::__Field(const ::String &inName)
{
	if (inName==HX_STRING(L"BITMAP",6)) return BITMAP;
	if (inName==HX_STRING(L"COLOR",5)) return COLOR;
	if (inName==HX_STRING(L"MOVIE",5)) return MOVIE;
	if (inName==HX_STRING(L"NONE",4)) return NONE;
	if (inName==HX_STRING(L"OUTLINE",7)) return OUTLINE;
	if (inName==HX_STRING(L"VIDEO",5)) return VIDEO;
	if (inName==HX_STRING(L"WIREFRAME",9)) return WIREFRAME;
	return super::__Field(inName);
}

static ::String sStaticFields[] = {
	HX_STRING(L"BITMAP",6),
	HX_STRING(L"COLOR",5),
	HX_STRING(L"MOVIE",5),
	HX_STRING(L"NONE",4),
	HX_STRING(L"OUTLINE",7),
	HX_STRING(L"VIDEO",5),
	HX_STRING(L"WIREFRAME",9),
	::String(null()) };

static void sMarkStatics() {
	hx::MarkMember(MaterialType_obj::BITMAP);
	hx::MarkMember(MaterialType_obj::COLOR);
	hx::MarkMember(MaterialType_obj::MOVIE);
	hx::MarkMember(MaterialType_obj::NONE);
	hx::MarkMember(MaterialType_obj::OUTLINE);
	hx::MarkMember(MaterialType_obj::VIDEO);
	hx::MarkMember(MaterialType_obj::WIREFRAME);
};

static ::String sMemberFields[] = { ::String(null()) };
Class MaterialType_obj::__mClass;

Dynamic __Create_MaterialType_obj() { return new MaterialType_obj; }

void MaterialType_obj::__register()
{

Static(__mClass) = hx::RegisterClass(HX_STRING(L"sandy.materials.MaterialType",28), hx::TCanCast< MaterialType_obj >,sStaticFields,sMemberFields,
	&__Create_MaterialType_obj, &__Create,
	&super::__SGetClass(), &CreateMaterialType_obj, sMarkStatics);
}

void MaterialType_obj::__boot()
{
Static(BITMAP) = hx::CreateEnum< MaterialType_obj >(HX_STRING(L"BITMAP",6),3);
Static(COLOR) = hx::CreateEnum< MaterialType_obj >(HX_STRING(L"COLOR",5),1);
Static(MOVIE) = hx::CreateEnum< MaterialType_obj >(HX_STRING(L"MOVIE",5),4);
Static(NONE) = hx::CreateEnum< MaterialType_obj >(HX_STRING(L"NONE",4),0);
Static(OUTLINE) = hx::CreateEnum< MaterialType_obj >(HX_STRING(L"OUTLINE",7),6);
Static(VIDEO) = hx::CreateEnum< MaterialType_obj >(HX_STRING(L"VIDEO",5),5);
Static(WIREFRAME) = hx::CreateEnum< MaterialType_obj >(HX_STRING(L"WIREFRAME",9),2);
}


} // end namespace sandy
} // end namespace materials
