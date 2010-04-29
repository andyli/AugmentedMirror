#include <hxcpp.h>

#ifndef INCLUDED_haxe_FastCell_sandy_core_data_Polygon
#include <haxe/FastCell_sandy_core_data_Polygon.h>
#endif
#ifndef INCLUDED_sandy_core_data_Polygon
#include <sandy/core/data/Polygon.h>
#endif
#ifndef INCLUDED_sandy_core_scenegraph_IDisplayable
#include <sandy/core/scenegraph/IDisplayable.h>
#endif
namespace haxe{

Void FastCell_sandy_core_data_Polygon_obj::__construct(::sandy::core::data::Polygon elt,::haxe::FastCell_sandy_core_data_Polygon next)
{
{
	this->elt = elt;
	this->next = next;
}
;
	return null();
}

FastCell_sandy_core_data_Polygon_obj::~FastCell_sandy_core_data_Polygon_obj() { }

Dynamic FastCell_sandy_core_data_Polygon_obj::__CreateEmpty() { return  new FastCell_sandy_core_data_Polygon_obj; }
hx::ObjectPtr< FastCell_sandy_core_data_Polygon_obj > FastCell_sandy_core_data_Polygon_obj::__new(::sandy::core::data::Polygon elt,::haxe::FastCell_sandy_core_data_Polygon next)
{  hx::ObjectPtr< FastCell_sandy_core_data_Polygon_obj > result = new FastCell_sandy_core_data_Polygon_obj();
	result->__construct(elt,next);
	return result;}

Dynamic FastCell_sandy_core_data_Polygon_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< FastCell_sandy_core_data_Polygon_obj > result = new FastCell_sandy_core_data_Polygon_obj();
	result->__construct(inArgs[0],inArgs[1]);
	return result;}


FastCell_sandy_core_data_Polygon_obj::FastCell_sandy_core_data_Polygon_obj()
{
}

void FastCell_sandy_core_data_Polygon_obj::__Mark()
{
	hx::MarkMember(elt);
	hx::MarkMember(next);
}

Dynamic FastCell_sandy_core_data_Polygon_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 3:
		if (!memcmp(inName.__s,L"elt",sizeof(wchar_t)*3) ) { return elt; }
		break;
	case 4:
		if (!memcmp(inName.__s,L"next",sizeof(wchar_t)*4) ) { return next; }
	}
	return super::__Field(inName);
}

Dynamic FastCell_sandy_core_data_Polygon_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	switch(inName.length) {
	case 3:
		if (!memcmp(inName.__s,L"elt",sizeof(wchar_t)*3) ) { elt=inValue.Cast< ::sandy::core::data::Polygon >(); return inValue; }
		break;
	case 4:
		if (!memcmp(inName.__s,L"next",sizeof(wchar_t)*4) ) { next=inValue.Cast< ::haxe::FastCell_sandy_core_data_Polygon >(); return inValue; }
	}
	return super::__SetField(inName,inValue);
}

void FastCell_sandy_core_data_Polygon_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_STRING(L"elt",3));
	outFields->push(HX_STRING(L"next",4));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_STRING(L"elt",3),
	HX_STRING(L"next",4),
	String(null()) };

static void sMarkStatics() {
};

Class FastCell_sandy_core_data_Polygon_obj::__mClass;

void FastCell_sandy_core_data_Polygon_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_STRING(L"haxe.FastCell_sandy_core_data_Polygon",37), hx::TCanCast< FastCell_sandy_core_data_Polygon_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void FastCell_sandy_core_data_Polygon_obj::__boot()
{
}

} // end namespace haxe
