#include <hxcpp.h>

#ifndef INCLUDED_neash_events_Event
#include <neash/events/Event.h>
#endif
#ifndef INCLUDED_sandy_core_data_Point3D
#include <sandy/core/data/Point3D.h>
#endif
#ifndef INCLUDED_sandy_core_data_Polygon
#include <sandy/core/data/Polygon.h>
#endif
#ifndef INCLUDED_sandy_core_data_UVCoord
#include <sandy/core/data/UVCoord.h>
#endif
#ifndef INCLUDED_sandy_core_scenegraph_ATransformable
#include <sandy/core/scenegraph/ATransformable.h>
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
#ifndef INCLUDED_sandy_events_BubbleEvent
#include <sandy/events/BubbleEvent.h>
#endif
#ifndef INCLUDED_sandy_events_Shape3DEvent
#include <sandy/events/Shape3DEvent.h>
#endif
namespace sandy{
namespace events{

Void Shape3DEvent_obj::__construct(::String e,::sandy::core::scenegraph::Shape3D p_oShape,::sandy::core::data::Polygon p_oPolygon,::sandy::core::data::UVCoord p_oUV,::sandy::core::data::Point3D p_oPoint3d,::neash::events::Event p_oEvent)
{
{
	super::__construct(e,p_oShape,null());
	this->shape = p_oShape;
	this->polygon = p_oPolygon;
	this->uv = p_oUV;
	this->point = p_oPoint3d;
	this->event = p_oEvent;
}
;
	return null();
}

Shape3DEvent_obj::~Shape3DEvent_obj() { }

Dynamic Shape3DEvent_obj::__CreateEmpty() { return  new Shape3DEvent_obj; }
hx::ObjectPtr< Shape3DEvent_obj > Shape3DEvent_obj::__new(::String e,::sandy::core::scenegraph::Shape3D p_oShape,::sandy::core::data::Polygon p_oPolygon,::sandy::core::data::UVCoord p_oUV,::sandy::core::data::Point3D p_oPoint3d,::neash::events::Event p_oEvent)
{  hx::ObjectPtr< Shape3DEvent_obj > result = new Shape3DEvent_obj();
	result->__construct(e,p_oShape,p_oPolygon,p_oUV,p_oPoint3d,p_oEvent);
	return result;}

Dynamic Shape3DEvent_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Shape3DEvent_obj > result = new Shape3DEvent_obj();
	result->__construct(inArgs[0],inArgs[1],inArgs[2],inArgs[3],inArgs[4],inArgs[5]);
	return result;}


Shape3DEvent_obj::Shape3DEvent_obj()
{
}

void Shape3DEvent_obj::__Mark()
{
	hx::MarkMember(shape);
	hx::MarkMember(polygon);
	hx::MarkMember(uv);
	hx::MarkMember(point);
	hx::MarkMember(event);
	super::__Mark();
}

Dynamic Shape3DEvent_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 2:
		if (!memcmp(inName.__s,L"uv",sizeof(wchar_t)*2) ) { return uv; }
		break;
	case 5:
		if (!memcmp(inName.__s,L"shape",sizeof(wchar_t)*5) ) { return shape; }
		if (!memcmp(inName.__s,L"point",sizeof(wchar_t)*5) ) { return point; }
		if (!memcmp(inName.__s,L"event",sizeof(wchar_t)*5) ) { return event; }
		break;
	case 7:
		if (!memcmp(inName.__s,L"polygon",sizeof(wchar_t)*7) ) { return polygon; }
	}
	return super::__Field(inName);
}

Dynamic Shape3DEvent_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	switch(inName.length) {
	case 2:
		if (!memcmp(inName.__s,L"uv",sizeof(wchar_t)*2) ) { uv=inValue.Cast< ::sandy::core::data::UVCoord >(); return inValue; }
		break;
	case 5:
		if (!memcmp(inName.__s,L"shape",sizeof(wchar_t)*5) ) { shape=inValue.Cast< ::sandy::core::scenegraph::Shape3D >(); return inValue; }
		if (!memcmp(inName.__s,L"point",sizeof(wchar_t)*5) ) { point=inValue.Cast< ::sandy::core::data::Point3D >(); return inValue; }
		if (!memcmp(inName.__s,L"event",sizeof(wchar_t)*5) ) { event=inValue.Cast< ::neash::events::Event >(); return inValue; }
		break;
	case 7:
		if (!memcmp(inName.__s,L"polygon",sizeof(wchar_t)*7) ) { polygon=inValue.Cast< ::sandy::core::data::Polygon >(); return inValue; }
	}
	return super::__SetField(inName,inValue);
}

void Shape3DEvent_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_STRING(L"shape",5));
	outFields->push(HX_STRING(L"polygon",7));
	outFields->push(HX_STRING(L"uv",2));
	outFields->push(HX_STRING(L"point",5));
	outFields->push(HX_STRING(L"event",5));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_STRING(L"shape",5),
	HX_STRING(L"polygon",7),
	HX_STRING(L"uv",2),
	HX_STRING(L"point",5),
	HX_STRING(L"event",5),
	String(null()) };

static void sMarkStatics() {
};

Class Shape3DEvent_obj::__mClass;

void Shape3DEvent_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_STRING(L"sandy.events.Shape3DEvent",25), hx::TCanCast< Shape3DEvent_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void Shape3DEvent_obj::__boot()
{
}

} // end namespace sandy
} // end namespace events
