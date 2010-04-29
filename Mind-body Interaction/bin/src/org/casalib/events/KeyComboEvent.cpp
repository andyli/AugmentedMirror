#include <hxcpp.h>

#ifndef INCLUDED_neash_events_Event
#include <neash/events/Event.h>
#endif
#ifndef INCLUDED_org_casalib_events_KeyComboEvent
#include <org/casalib/events/KeyComboEvent.h>
#endif
#ifndef INCLUDED_org_casalib_ui_KeyCombo
#include <org/casalib/ui/KeyCombo.h>
#endif
namespace org{
namespace casalib{
namespace events{

Void KeyComboEvent_obj::__construct(::String type,Dynamic __o_bubbles,Dynamic __o_cancelable)
{
bool bubbles = __o_bubbles.Default(false);
bool cancelable = __o_cancelable.Default(false);
{
	super::__construct(type,bubbles,cancelable);
}
;
	return null();
}

KeyComboEvent_obj::~KeyComboEvent_obj() { }

Dynamic KeyComboEvent_obj::__CreateEmpty() { return  new KeyComboEvent_obj; }
hx::ObjectPtr< KeyComboEvent_obj > KeyComboEvent_obj::__new(::String type,Dynamic __o_bubbles,Dynamic __o_cancelable)
{  hx::ObjectPtr< KeyComboEvent_obj > result = new KeyComboEvent_obj();
	result->__construct(type,__o_bubbles,__o_cancelable);
	return result;}

Dynamic KeyComboEvent_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< KeyComboEvent_obj > result = new KeyComboEvent_obj();
	result->__construct(inArgs[0],inArgs[1],inArgs[2]);
	return result;}

::org::casalib::ui::KeyCombo KeyComboEvent_obj::getKeyCombo( ){
	return this->_keyCombo;
}


HX_DEFINE_DYNAMIC_FUNC0(KeyComboEvent_obj,getKeyCombo,return )

::org::casalib::ui::KeyCombo KeyComboEvent_obj::setKeyCombo( ::org::casalib::ui::KeyCombo keyCombo){
	this->_keyCombo = keyCombo;
	return keyCombo;
}


HX_DEFINE_DYNAMIC_FUNC1(KeyComboEvent_obj,setKeyCombo,return )

::neash::events::Event KeyComboEvent_obj::clone( ){
	::org::casalib::events::KeyComboEvent e = ::org::casalib::events::KeyComboEvent_obj::__new(this->type,this->bubbles,this->cancelable);
	{
		::org::casalib::ui::KeyCombo keyCombo = this->_keyCombo;
		e->_keyCombo = keyCombo;
		keyCombo;
	}
	return e;
}


HX_DEFINE_DYNAMIC_FUNC0(KeyComboEvent_obj,clone,return )

::String KeyComboEvent_obj::DOWN;

::String KeyComboEvent_obj::RELEASE;

::String KeyComboEvent_obj::SEQUENCE;


KeyComboEvent_obj::KeyComboEvent_obj()
{
}

void KeyComboEvent_obj::__Mark()
{
	hx::MarkMember(keyCombo);
	hx::MarkMember(_keyCombo);
	super::__Mark();
}

Dynamic KeyComboEvent_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 4:
		if (!memcmp(inName.__s,L"DOWN",sizeof(wchar_t)*4) ) { return DOWN; }
		break;
	case 5:
		if (!memcmp(inName.__s,L"clone",sizeof(wchar_t)*5) ) { return clone_dyn(); }
		break;
	case 7:
		if (!memcmp(inName.__s,L"RELEASE",sizeof(wchar_t)*7) ) { return RELEASE; }
		break;
	case 8:
		if (!memcmp(inName.__s,L"SEQUENCE",sizeof(wchar_t)*8) ) { return SEQUENCE; }
		if (!memcmp(inName.__s,L"keyCombo",sizeof(wchar_t)*8) ) { return getKeyCombo(); }
		break;
	case 9:
		if (!memcmp(inName.__s,L"_keyCombo",sizeof(wchar_t)*9) ) { return _keyCombo; }
		break;
	case 11:
		if (!memcmp(inName.__s,L"getKeyCombo",sizeof(wchar_t)*11) ) { return getKeyCombo_dyn(); }
		if (!memcmp(inName.__s,L"setKeyCombo",sizeof(wchar_t)*11) ) { return setKeyCombo_dyn(); }
	}
	return super::__Field(inName);
}

Dynamic KeyComboEvent_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	switch(inName.length) {
	case 4:
		if (!memcmp(inName.__s,L"DOWN",sizeof(wchar_t)*4) ) { DOWN=inValue.Cast< ::String >(); return inValue; }
		break;
	case 7:
		if (!memcmp(inName.__s,L"RELEASE",sizeof(wchar_t)*7) ) { RELEASE=inValue.Cast< ::String >(); return inValue; }
		break;
	case 8:
		if (!memcmp(inName.__s,L"SEQUENCE",sizeof(wchar_t)*8) ) { SEQUENCE=inValue.Cast< ::String >(); return inValue; }
		if (!memcmp(inName.__s,L"keyCombo",sizeof(wchar_t)*8) ) { return setKeyCombo(inValue); }
		break;
	case 9:
		if (!memcmp(inName.__s,L"_keyCombo",sizeof(wchar_t)*9) ) { _keyCombo=inValue.Cast< ::org::casalib::ui::KeyCombo >(); return inValue; }
	}
	return super::__SetField(inName,inValue);
}

void KeyComboEvent_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_STRING(L"keyCombo",8));
	outFields->push(HX_STRING(L"_keyCombo",9));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_STRING(L"DOWN",4),
	HX_STRING(L"RELEASE",7),
	HX_STRING(L"SEQUENCE",8),
	String(null()) };

static ::String sMemberFields[] = {
	HX_STRING(L"keyCombo",8),
	HX_STRING(L"_keyCombo",9),
	HX_STRING(L"getKeyCombo",11),
	HX_STRING(L"setKeyCombo",11),
	HX_STRING(L"clone",5),
	String(null()) };

static void sMarkStatics() {
	hx::MarkMember(KeyComboEvent_obj::DOWN);
	hx::MarkMember(KeyComboEvent_obj::RELEASE);
	hx::MarkMember(KeyComboEvent_obj::SEQUENCE);
};

Class KeyComboEvent_obj::__mClass;

void KeyComboEvent_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_STRING(L"org.casalib.events.KeyComboEvent",32), hx::TCanCast< KeyComboEvent_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void KeyComboEvent_obj::__boot()
{
	hx::Static(DOWN) = HX_STRING(L"down",4);
	hx::Static(RELEASE) = HX_STRING(L"release",7);
	hx::Static(SEQUENCE) = HX_STRING(L"sequence",8);
}

} // end namespace org
} // end namespace casalib
} // end namespace events
