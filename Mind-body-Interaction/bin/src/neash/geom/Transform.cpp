#include <hxcpp.h>

#ifndef INCLUDED_neash_display_DisplayObject
#include <neash/display/DisplayObject.h>
#endif
#ifndef INCLUDED_neash_events_EventDispatcher
#include <neash/events/EventDispatcher.h>
#endif
#ifndef INCLUDED_neash_events_IEventDispatcher
#include <neash/events/IEventDispatcher.h>
#endif
#ifndef INCLUDED_neash_geom_Transform
#include <neash/geom/Transform.h>
#endif
#ifndef INCLUDED_nme_display_IBitmapDrawable
#include <nme/display/IBitmapDrawable.h>
#endif
#ifndef INCLUDED_nme_geom_ColorTransform
#include <nme/geom/ColorTransform.h>
#endif
#ifndef INCLUDED_nme_geom_Matrix
#include <nme/geom/Matrix.h>
#endif
namespace neash{
namespace geom{

Void Transform_obj::__construct(::neash::display::DisplayObject inParent)
{
{
	this->mObj = inParent;
}
;
	return null();
}

Transform_obj::~Transform_obj() { }

Dynamic Transform_obj::__CreateEmpty() { return  new Transform_obj; }
hx::ObjectPtr< Transform_obj > Transform_obj::__new(::neash::display::DisplayObject inParent)
{  hx::ObjectPtr< Transform_obj > result = new Transform_obj();
	result->__construct(inParent);
	return result;}

Dynamic Transform_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Transform_obj > result = new Transform_obj();
	result->__construct(inArgs[0]);
	return result;}

::nme::geom::Matrix Transform_obj::GetMatrix( ){
	__SAFE_POINT
	return this->mObj->GetMatrix();
}


HX_DEFINE_DYNAMIC_FUNC0(Transform_obj,GetMatrix,return )

::nme::geom::Matrix Transform_obj::SetMatrix( ::nme::geom::Matrix inMatrix){
	__SAFE_POINT
	return this->mObj->SetMatrix(inMatrix);
}


HX_DEFINE_DYNAMIC_FUNC1(Transform_obj,SetMatrix,return )

::nme::geom::ColorTransform Transform_obj::GetColorTransform( ){
	return ::nme::geom::ColorTransform_obj::__new(null(),null(),null(),null(),null(),null(),null(),null());
}


HX_DEFINE_DYNAMIC_FUNC0(Transform_obj,GetColorTransform,return )

::nme::geom::ColorTransform Transform_obj::SetColorTransform( ::nme::geom::ColorTransform inColorTransform){
	return inColorTransform;
}


HX_DEFINE_DYNAMIC_FUNC1(Transform_obj,SetColorTransform,return )


Transform_obj::Transform_obj()
{
}

void Transform_obj::__Mark()
{
	hx::MarkMember(colorTransform);
	hx::MarkMember(matrix);
	hx::MarkMember(mObj);
}

Dynamic Transform_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 4:
		if (!memcmp(inName.__s,L"mObj",sizeof(wchar_t)*4) ) { return mObj; }
		break;
	case 6:
		if (!memcmp(inName.__s,L"matrix",sizeof(wchar_t)*6) ) { return GetMatrix(); }
		break;
	case 9:
		if (!memcmp(inName.__s,L"GetMatrix",sizeof(wchar_t)*9) ) { return GetMatrix_dyn(); }
		if (!memcmp(inName.__s,L"SetMatrix",sizeof(wchar_t)*9) ) { return SetMatrix_dyn(); }
		break;
	case 14:
		if (!memcmp(inName.__s,L"colorTransform",sizeof(wchar_t)*14) ) { return GetColorTransform(); }
		break;
	case 17:
		if (!memcmp(inName.__s,L"GetColorTransform",sizeof(wchar_t)*17) ) { return GetColorTransform_dyn(); }
		if (!memcmp(inName.__s,L"SetColorTransform",sizeof(wchar_t)*17) ) { return SetColorTransform_dyn(); }
	}
	return super::__Field(inName);
}

Dynamic Transform_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	switch(inName.length) {
	case 4:
		if (!memcmp(inName.__s,L"mObj",sizeof(wchar_t)*4) ) { mObj=inValue.Cast< ::neash::display::DisplayObject >(); return inValue; }
		break;
	case 6:
		if (!memcmp(inName.__s,L"matrix",sizeof(wchar_t)*6) ) { return SetMatrix(inValue); }
		break;
	case 14:
		if (!memcmp(inName.__s,L"colorTransform",sizeof(wchar_t)*14) ) { return SetColorTransform(inValue); }
	}
	return super::__SetField(inName,inValue);
}

void Transform_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_STRING(L"colorTransform",14));
	outFields->push(HX_STRING(L"matrix",6));
	outFields->push(HX_STRING(L"mObj",4));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_STRING(L"colorTransform",14),
	HX_STRING(L"matrix",6),
	HX_STRING(L"mObj",4),
	HX_STRING(L"GetMatrix",9),
	HX_STRING(L"SetMatrix",9),
	HX_STRING(L"GetColorTransform",17),
	HX_STRING(L"SetColorTransform",17),
	String(null()) };

static void sMarkStatics() {
};

Class Transform_obj::__mClass;

void Transform_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_STRING(L"neash.geom.Transform",20), hx::TCanCast< Transform_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void Transform_obj::__boot()
{
}

} // end namespace neash
} // end namespace geom
