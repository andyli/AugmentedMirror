#include <hxcpp.h>

#ifndef INCLUDED_neash_events_Event
#include <neash/events/Event.h>
#endif
#ifndef INCLUDED_sandy_events_BubbleEvent
#include <sandy/events/BubbleEvent.h>
#endif
namespace sandy{
namespace events{

Void BubbleEvent_obj::__construct(::String e,Dynamic oT,Dynamic p_Info)
{
{
	super::__construct(e,true,true);
	this->m_oTarget = oT;
	this->info = p_Info;
}
;
	return null();
}

BubbleEvent_obj::~BubbleEvent_obj() { }

Dynamic BubbleEvent_obj::__CreateEmpty() { return  new BubbleEvent_obj; }
hx::ObjectPtr< BubbleEvent_obj > BubbleEvent_obj::__new(::String e,Dynamic oT,Dynamic p_Info)
{  hx::ObjectPtr< BubbleEvent_obj > result = new BubbleEvent_obj();
	result->__construct(e,oT,p_Info);
	return result;}

Dynamic BubbleEvent_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< BubbleEvent_obj > result = new BubbleEvent_obj();
	result->__construct(inArgs[0],inArgs[1],inArgs[2]);
	return result;}

Dynamic BubbleEvent_obj::__getObject( ){
	return this->m_oTarget;
}


HX_DEFINE_DYNAMIC_FUNC0(BubbleEvent_obj,__getObject,return )

::String BubbleEvent_obj::toString( ){
	return HX_STRING(L"BubbleEvent",11);
}


HX_DEFINE_DYNAMIC_FUNC0(BubbleEvent_obj,toString,return )


BubbleEvent_obj::BubbleEvent_obj()
{
}

void BubbleEvent_obj::__Mark()
{
	hx::MarkMember(info);
	hx::MarkMember(object);
	hx::MarkMember(m_oTarget);
	super::__Mark();
}

Dynamic BubbleEvent_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 4:
		if (!memcmp(inName.__s,L"info",sizeof(wchar_t)*4) ) { return info; }
		break;
	case 6:
		if (!memcmp(inName.__s,L"object",sizeof(wchar_t)*6) ) { return __getObject(); }
		break;
	case 8:
		if (!memcmp(inName.__s,L"toString",sizeof(wchar_t)*8) ) { return toString_dyn(); }
		break;
	case 9:
		if (!memcmp(inName.__s,L"m_oTarget",sizeof(wchar_t)*9) ) { return m_oTarget; }
		break;
	case 11:
		if (!memcmp(inName.__s,L"__getObject",sizeof(wchar_t)*11) ) { return __getObject_dyn(); }
	}
	return super::__Field(inName);
}

Dynamic BubbleEvent_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	switch(inName.length) {
	case 4:
		if (!memcmp(inName.__s,L"info",sizeof(wchar_t)*4) ) { info=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 6:
		if (!memcmp(inName.__s,L"object",sizeof(wchar_t)*6) ) { object=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 9:
		if (!memcmp(inName.__s,L"m_oTarget",sizeof(wchar_t)*9) ) { m_oTarget=inValue.Cast< Dynamic >(); return inValue; }
	}
	return super::__SetField(inName,inValue);
}

void BubbleEvent_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_STRING(L"info",4));
	outFields->push(HX_STRING(L"object",6));
	outFields->push(HX_STRING(L"m_oTarget",9));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_STRING(L"info",4),
	HX_STRING(L"object",6),
	HX_STRING(L"m_oTarget",9),
	HX_STRING(L"__getObject",11),
	HX_STRING(L"toString",8),
	String(null()) };

static void sMarkStatics() {
};

Class BubbleEvent_obj::__mClass;

void BubbleEvent_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_STRING(L"sandy.events.BubbleEvent",24), hx::TCanCast< BubbleEvent_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void BubbleEvent_obj::__boot()
{
}

} // end namespace sandy
} // end namespace events
