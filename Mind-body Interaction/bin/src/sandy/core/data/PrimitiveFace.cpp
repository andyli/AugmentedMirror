#include <hxcpp.h>

#ifndef INCLUDED_sandy_core_data_Polygon
#include <sandy/core/data/Polygon.h>
#endif
#ifndef INCLUDED_sandy_core_data_PrimitiveFace
#include <sandy/core/data/PrimitiveFace.h>
#endif
#ifndef INCLUDED_sandy_core_scenegraph_ATransformable
#include <sandy/core/scenegraph/ATransformable.h>
#endif
#ifndef INCLUDED_sandy_core_scenegraph_Geometry3D
#include <sandy/core/scenegraph/Geometry3D.h>
#endif
#ifndef INCLUDED_sandy_core_scenegraph_IDisplayable
#include <sandy/core/scenegraph/IDisplayable.h>
#endif
#ifndef INCLUDED_sandy_core_scenegraph_Node
#include <sandy/core/scenegraph/Node.h>
#endif
#ifndef INCLUDED_sandy_core_scenegraph_Shape3D
#include <sandy/core/scenegraph/Shape3D.h>
#endif
#ifndef INCLUDED_sandy_materials_Appearance
#include <sandy/materials/Appearance.h>
#endif
namespace sandy{
namespace core{
namespace data{

Void PrimitiveFace_obj::__construct(::sandy::core::scenegraph::Shape3D p_iPrimitive)
{
{
	this->aPolygons = Array_obj< ::sandy::core::data::Polygon >::__new();
	this->m_iPrimitive = p_iPrimitive;
}
;
	return null();
}

PrimitiveFace_obj::~PrimitiveFace_obj() { }

Dynamic PrimitiveFace_obj::__CreateEmpty() { return  new PrimitiveFace_obj; }
hx::ObjectPtr< PrimitiveFace_obj > PrimitiveFace_obj::__new(::sandy::core::scenegraph::Shape3D p_iPrimitive)
{  hx::ObjectPtr< PrimitiveFace_obj > result = new PrimitiveFace_obj();
	result->__construct(p_iPrimitive);
	return result;}

Dynamic PrimitiveFace_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< PrimitiveFace_obj > result = new PrimitiveFace_obj();
	result->__construct(inArgs[0]);
	return result;}

::sandy::core::scenegraph::Shape3D PrimitiveFace_obj::__getPrimitive( ){
	return this->m_iPrimitive;
}


HX_DEFINE_DYNAMIC_FUNC0(PrimitiveFace_obj,__getPrimitive,return )

Void PrimitiveFace_obj::addPolygon( int p_oPolyId){
{
		__SAFE_POINT
		this->aPolygons->push(this->m_iPrimitive->aPolygons->__get(p_oPolyId));
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(PrimitiveFace_obj,addPolygon,(void))

::sandy::materials::Appearance PrimitiveFace_obj::__setAppearance( ::sandy::materials::Appearance p_oApp){
	__SAFE_POINT
	this->m_oAppearance = p_oApp;
	if ((this->m_iPrimitive->__getGeometry() != null())){
		{
			int _g = 0;
			Array< ::sandy::core::data::Polygon > _g1 = this->aPolygons;
			while((_g < _g1->length)){
				__SAFE_POINT
				::sandy::core::data::Polygon v = _g1->__get(_g);
				++_g;
				v->__setAppearance(this->m_oAppearance);
			}
		}
	}
	return p_oApp;
}


HX_DEFINE_DYNAMIC_FUNC1(PrimitiveFace_obj,__setAppearance,return )

::sandy::materials::Appearance PrimitiveFace_obj::__getAppearance( ){
	return this->m_oAppearance;
}


HX_DEFINE_DYNAMIC_FUNC0(PrimitiveFace_obj,__getAppearance,return )


PrimitiveFace_obj::PrimitiveFace_obj()
{
}

void PrimitiveFace_obj::__Mark()
{
	hx::MarkMember(m_iPrimitive);
	hx::MarkMember(m_oAppearance);
	hx::MarkMember(aPolygons);
	hx::MarkMember(primitive);
	hx::MarkMember(appearance);
}

Dynamic PrimitiveFace_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 9:
		if (!memcmp(inName.__s,L"aPolygons",sizeof(wchar_t)*9) ) { return aPolygons; }
		if (!memcmp(inName.__s,L"primitive",sizeof(wchar_t)*9) ) { return __getPrimitive(); }
		break;
	case 10:
		if (!memcmp(inName.__s,L"addPolygon",sizeof(wchar_t)*10) ) { return addPolygon_dyn(); }
		if (!memcmp(inName.__s,L"appearance",sizeof(wchar_t)*10) ) { return __getAppearance(); }
		break;
	case 12:
		if (!memcmp(inName.__s,L"m_iPrimitive",sizeof(wchar_t)*12) ) { return m_iPrimitive; }
		break;
	case 13:
		if (!memcmp(inName.__s,L"m_oAppearance",sizeof(wchar_t)*13) ) { return m_oAppearance; }
		break;
	case 14:
		if (!memcmp(inName.__s,L"__getPrimitive",sizeof(wchar_t)*14) ) { return __getPrimitive_dyn(); }
		break;
	case 15:
		if (!memcmp(inName.__s,L"__setAppearance",sizeof(wchar_t)*15) ) { return __setAppearance_dyn(); }
		if (!memcmp(inName.__s,L"__getAppearance",sizeof(wchar_t)*15) ) { return __getAppearance_dyn(); }
	}
	return super::__Field(inName);
}

Dynamic PrimitiveFace_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	switch(inName.length) {
	case 9:
		if (!memcmp(inName.__s,L"aPolygons",sizeof(wchar_t)*9) ) { aPolygons=inValue.Cast< Array< ::sandy::core::data::Polygon > >(); return inValue; }
		if (!memcmp(inName.__s,L"primitive",sizeof(wchar_t)*9) ) { primitive=inValue.Cast< ::sandy::core::scenegraph::Shape3D >(); return inValue; }
		break;
	case 10:
		if (!memcmp(inName.__s,L"appearance",sizeof(wchar_t)*10) ) { return __setAppearance(inValue); }
		break;
	case 12:
		if (!memcmp(inName.__s,L"m_iPrimitive",sizeof(wchar_t)*12) ) { m_iPrimitive=inValue.Cast< ::sandy::core::scenegraph::Shape3D >(); return inValue; }
		break;
	case 13:
		if (!memcmp(inName.__s,L"m_oAppearance",sizeof(wchar_t)*13) ) { m_oAppearance=inValue.Cast< ::sandy::materials::Appearance >(); return inValue; }
	}
	return super::__SetField(inName,inValue);
}

void PrimitiveFace_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_STRING(L"m_iPrimitive",12));
	outFields->push(HX_STRING(L"m_oAppearance",13));
	outFields->push(HX_STRING(L"aPolygons",9));
	outFields->push(HX_STRING(L"primitive",9));
	outFields->push(HX_STRING(L"appearance",10));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_STRING(L"m_iPrimitive",12),
	HX_STRING(L"m_oAppearance",13),
	HX_STRING(L"aPolygons",9),
	HX_STRING(L"primitive",9),
	HX_STRING(L"__getPrimitive",14),
	HX_STRING(L"addPolygon",10),
	HX_STRING(L"appearance",10),
	HX_STRING(L"__setAppearance",15),
	HX_STRING(L"__getAppearance",15),
	String(null()) };

static void sMarkStatics() {
};

Class PrimitiveFace_obj::__mClass;

void PrimitiveFace_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_STRING(L"sandy.core.data.PrimitiveFace",29), hx::TCanCast< PrimitiveFace_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void PrimitiveFace_obj::__boot()
{
}

} // end namespace sandy
} // end namespace core
} // end namespace data
