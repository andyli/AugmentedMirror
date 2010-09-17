#include <hxcpp.h>

#ifndef INCLUDED_Reflect
#include <Reflect.h>
#endif
#ifndef INCLUDED_neash_events_Event
#include <neash/events/Event.h>
#endif
#ifndef INCLUDED_neash_events_Listener
#include <neash/events/Listener.h>
#endif
namespace neash{
namespace events{

Void Listener_obj::__construct(Dynamic inListener,bool inUseCapture,int inPriority)
{
{
	this->mListner = inListener;
	this->mUseCapture = inUseCapture;
	this->mPriority = inPriority;
	this->mID = ::neash::events::Listener_obj::sIDs++;
}
;
	return null();
}

Listener_obj::~Listener_obj() { }

Dynamic Listener_obj::__CreateEmpty() { return  new Listener_obj; }
hx::ObjectPtr< Listener_obj > Listener_obj::__new(Dynamic inListener,bool inUseCapture,int inPriority)
{  hx::ObjectPtr< Listener_obj > result = new Listener_obj();
	result->__construct(inListener,inUseCapture,inPriority);
	return result;}

Dynamic Listener_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Listener_obj > result = new Listener_obj();
	result->__construct(inArgs[0],inArgs[1],inArgs[2]);
	return result;}

bool Listener_obj::Is( Dynamic inListener,bool inCapture){
	__SAFE_POINT
	return (bool(::Reflect_obj::compareMethods(this->mListner_dyn(),inListener)) && bool((this->mUseCapture == inCapture)));
}


HX_DEFINE_DYNAMIC_FUNC2(Listener_obj,Is,return )

Void Listener_obj::dispatchEvent( ::neash::events::Event event){
{
		__SAFE_POINT
		this->mListner(event);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Listener_obj,dispatchEvent,(void))

int Listener_obj::sIDs;


Listener_obj::Listener_obj()
{
}

void Listener_obj::__Mark()
{
	hx::MarkMember(mListner);
	hx::MarkMember(mUseCapture);
	hx::MarkMember(mPriority);
	hx::MarkMember(mID);
}

Dynamic Listener_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 2:
		if (!memcmp(inName.__s,L"Is",sizeof(wchar_t)*2) ) { return Is_dyn(); }
		break;
	case 3:
		if (!memcmp(inName.__s,L"mID",sizeof(wchar_t)*3) ) { return mID; }
		break;
	case 4:
		if (!memcmp(inName.__s,L"sIDs",sizeof(wchar_t)*4) ) { return sIDs; }
		break;
	case 8:
		if (!memcmp(inName.__s,L"mListner",sizeof(wchar_t)*8) ) { return mListner; }
		break;
	case 9:
		if (!memcmp(inName.__s,L"mPriority",sizeof(wchar_t)*9) ) { return mPriority; }
		break;
	case 11:
		if (!memcmp(inName.__s,L"mUseCapture",sizeof(wchar_t)*11) ) { return mUseCapture; }
		break;
	case 13:
		if (!memcmp(inName.__s,L"dispatchEvent",sizeof(wchar_t)*13) ) { return dispatchEvent_dyn(); }
	}
	return super::__Field(inName);
}

Dynamic Listener_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	switch(inName.length) {
	case 3:
		if (!memcmp(inName.__s,L"mID",sizeof(wchar_t)*3) ) { mID=inValue.Cast< int >(); return inValue; }
		break;
	case 4:
		if (!memcmp(inName.__s,L"sIDs",sizeof(wchar_t)*4) ) { sIDs=inValue.Cast< int >(); return inValue; }
		break;
	case 8:
		if (!memcmp(inName.__s,L"mListner",sizeof(wchar_t)*8) ) { mListner=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 9:
		if (!memcmp(inName.__s,L"mPriority",sizeof(wchar_t)*9) ) { mPriority=inValue.Cast< int >(); return inValue; }
		break;
	case 11:
		if (!memcmp(inName.__s,L"mUseCapture",sizeof(wchar_t)*11) ) { mUseCapture=inValue.Cast< bool >(); return inValue; }
	}
	return super::__SetField(inName,inValue);
}

void Listener_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_STRING(L"mUseCapture",11));
	outFields->push(HX_STRING(L"mPriority",9));
	outFields->push(HX_STRING(L"mID",3));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_STRING(L"sIDs",4),
	String(null()) };

static ::String sMemberFields[] = {
	HX_STRING(L"mListner",8),
	HX_STRING(L"mUseCapture",11),
	HX_STRING(L"mPriority",9),
	HX_STRING(L"mID",3),
	HX_STRING(L"Is",2),
	HX_STRING(L"dispatchEvent",13),
	String(null()) };

static void sMarkStatics() {
	hx::MarkMember(Listener_obj::sIDs);
};

Class Listener_obj::__mClass;

void Listener_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_STRING(L"neash.events.Listener",21), hx::TCanCast< Listener_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void Listener_obj::__boot()
{
	hx::Static(sIDs) = 1;
}

} // end namespace neash
} // end namespace events
