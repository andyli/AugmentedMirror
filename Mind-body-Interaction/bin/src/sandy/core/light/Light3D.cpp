#include <hxcpp.h>

#ifndef INCLUDED_hxMath
#include <hxMath.h>
#endif
#ifndef INCLUDED_neash_events_Event
#include <neash/events/Event.h>
#endif
#ifndef INCLUDED_neash_events_EventDispatcher
#include <neash/events/EventDispatcher.h>
#endif
#ifndef INCLUDED_neash_events_IEventDispatcher
#include <neash/events/IEventDispatcher.h>
#endif
#ifndef INCLUDED_sandy_core_data_Point3D
#include <sandy/core/data/Point3D.h>
#endif
#ifndef INCLUDED_sandy_core_light_Light3D
#include <sandy/core/light/Light3D.h>
#endif
#ifndef INCLUDED_sandy_events_SandyEvent
#include <sandy/events/SandyEvent.h>
#endif
namespace sandy{
namespace core{
namespace light{

Void Light3D_obj::__construct(::sandy::core::data::Point3D p_oD,double p_nPow)
{
{
	super::__construct(null());
	this->_dir = p_oD;
	this->_dir->normalize();
	this->setPower(p_nPow);
}
;
	return null();
}

Light3D_obj::~Light3D_obj() { }

Dynamic Light3D_obj::__CreateEmpty() { return  new Light3D_obj; }
hx::ObjectPtr< Light3D_obj > Light3D_obj::__new(::sandy::core::data::Point3D p_oD,double p_nPow)
{  hx::ObjectPtr< Light3D_obj > result = new Light3D_obj();
	result->__construct(p_oD,p_nPow);
	return result;}

Dynamic Light3D_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Light3D_obj > result = new Light3D_obj();
	result->__construct(inArgs[0],inArgs[1]);
	return result;}

Void Light3D_obj::setPower( double p_nPow){
{
		__SAFE_POINT
		this->_power = ::Math_obj::max(::Math_obj::min(p_nPow,150),0);
		this->_nPower = (double(this->_power) / double(150));
		this->changed = true;
		this->dispatchEvent(::sandy::events::SandyEvent_obj::__new(HX_STRING(L"lightUpdated",12),null(),null()));
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Light3D_obj,setPower,(void))

double Light3D_obj::getPower( ){
	return this->_power;
}


HX_DEFINE_DYNAMIC_FUNC0(Light3D_obj,getPower,return )

double Light3D_obj::getNormalizedPower( ){
	return this->_nPower;
}


HX_DEFINE_DYNAMIC_FUNC0(Light3D_obj,getNormalizedPower,return )

::sandy::core::data::Point3D Light3D_obj::getDirectionPoint3D( ){
	return this->_dir;
}


HX_DEFINE_DYNAMIC_FUNC0(Light3D_obj,getDirectionPoint3D,return )

Void Light3D_obj::setDirection( double x,double y,double z){
{
		__SAFE_POINT
		this->_dir->x = x;
		this->_dir->y = y;
		this->_dir->z = z;
		this->_dir->normalize();
		this->changed = true;
		this->dispatchEvent(::sandy::events::SandyEvent_obj::__new(HX_STRING(L"lightUpdated",12),null(),null()));
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC3(Light3D_obj,setDirection,(void))

Void Light3D_obj::setDirectionPoint3D( ::sandy::core::data::Point3D pDir){
{
		__SAFE_POINT
		this->_dir = pDir;
		this->_dir->normalize();
		this->changed = true;
		this->dispatchEvent(::sandy::events::SandyEvent_obj::__new(HX_STRING(L"lightUpdated",12),null(),null()));
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Light3D_obj,setDirectionPoint3D,(void))

double Light3D_obj::calculate( ::sandy::core::data::Point3D normal){
	__SAFE_POINT
	double DP = this->_dir->dot(normal);
	DP = -DP;
	if ((DP < 0)){
		DP = 0;
	}
	return (this->_nPower * DP);
}


HX_DEFINE_DYNAMIC_FUNC1(Light3D_obj,calculate,return )

Void Light3D_obj::destroy( ){
{
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Light3D_obj,destroy,(void))

int Light3D_obj::__getColor( ){
	return this->_color;
}


HX_DEFINE_DYNAMIC_FUNC0(Light3D_obj,__getColor,return )

int Light3D_obj::__setColor( int p_nColor){
	__SAFE_POINT
	this->_color = p_nColor;
	this->changed = true;
	this->dispatchEvent(::sandy::events::SandyEvent_obj::__new(HX_STRING(L"lightColorChanged",17),null(),null()));
	return p_nColor;
}


HX_DEFINE_DYNAMIC_FUNC1(Light3D_obj,__setColor,return )

double Light3D_obj::MAX_POWER;


Light3D_obj::Light3D_obj()
{
}

void Light3D_obj::__Mark()
{
	hx::MarkMember(changed);
	hx::MarkMember(color);
	hx::MarkMember(_dir);
	hx::MarkMember(_power);
	hx::MarkMember(_nPower);
	hx::MarkMember(_color);
	super::__Mark();
}

Dynamic Light3D_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 4:
		if (!memcmp(inName.__s,L"_dir",sizeof(wchar_t)*4) ) { return _dir; }
		break;
	case 5:
		if (!memcmp(inName.__s,L"color",sizeof(wchar_t)*5) ) { return __getColor(); }
		break;
	case 6:
		if (!memcmp(inName.__s,L"_power",sizeof(wchar_t)*6) ) { return _power; }
		if (!memcmp(inName.__s,L"_color",sizeof(wchar_t)*6) ) { return _color; }
		break;
	case 7:
		if (!memcmp(inName.__s,L"changed",sizeof(wchar_t)*7) ) { return changed; }
		if (!memcmp(inName.__s,L"destroy",sizeof(wchar_t)*7) ) { return destroy_dyn(); }
		if (!memcmp(inName.__s,L"_nPower",sizeof(wchar_t)*7) ) { return _nPower; }
		break;
	case 8:
		if (!memcmp(inName.__s,L"setPower",sizeof(wchar_t)*8) ) { return setPower_dyn(); }
		if (!memcmp(inName.__s,L"getPower",sizeof(wchar_t)*8) ) { return getPower_dyn(); }
		break;
	case 9:
		if (!memcmp(inName.__s,L"MAX_POWER",sizeof(wchar_t)*9) ) { return MAX_POWER; }
		if (!memcmp(inName.__s,L"calculate",sizeof(wchar_t)*9) ) { return calculate_dyn(); }
		break;
	case 10:
		if (!memcmp(inName.__s,L"__getColor",sizeof(wchar_t)*10) ) { return __getColor_dyn(); }
		if (!memcmp(inName.__s,L"__setColor",sizeof(wchar_t)*10) ) { return __setColor_dyn(); }
		break;
	case 12:
		if (!memcmp(inName.__s,L"setDirection",sizeof(wchar_t)*12) ) { return setDirection_dyn(); }
		break;
	case 18:
		if (!memcmp(inName.__s,L"getNormalizedPower",sizeof(wchar_t)*18) ) { return getNormalizedPower_dyn(); }
		break;
	case 19:
		if (!memcmp(inName.__s,L"getDirectionPoint3D",sizeof(wchar_t)*19) ) { return getDirectionPoint3D_dyn(); }
		if (!memcmp(inName.__s,L"setDirectionPoint3D",sizeof(wchar_t)*19) ) { return setDirectionPoint3D_dyn(); }
	}
	return super::__Field(inName);
}

Dynamic Light3D_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	switch(inName.length) {
	case 4:
		if (!memcmp(inName.__s,L"_dir",sizeof(wchar_t)*4) ) { _dir=inValue.Cast< ::sandy::core::data::Point3D >(); return inValue; }
		break;
	case 5:
		if (!memcmp(inName.__s,L"color",sizeof(wchar_t)*5) ) { return __setColor(inValue); }
		break;
	case 6:
		if (!memcmp(inName.__s,L"_power",sizeof(wchar_t)*6) ) { _power=inValue.Cast< double >(); return inValue; }
		if (!memcmp(inName.__s,L"_color",sizeof(wchar_t)*6) ) { _color=inValue.Cast< int >(); return inValue; }
		break;
	case 7:
		if (!memcmp(inName.__s,L"changed",sizeof(wchar_t)*7) ) { changed=inValue.Cast< bool >(); return inValue; }
		if (!memcmp(inName.__s,L"_nPower",sizeof(wchar_t)*7) ) { _nPower=inValue.Cast< double >(); return inValue; }
		break;
	case 9:
		if (!memcmp(inName.__s,L"MAX_POWER",sizeof(wchar_t)*9) ) { MAX_POWER=inValue.Cast< double >(); return inValue; }
	}
	return super::__SetField(inName,inValue);
}

void Light3D_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_STRING(L"changed",7));
	outFields->push(HX_STRING(L"color",5));
	outFields->push(HX_STRING(L"_dir",4));
	outFields->push(HX_STRING(L"_power",6));
	outFields->push(HX_STRING(L"_nPower",7));
	outFields->push(HX_STRING(L"_color",6));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_STRING(L"MAX_POWER",9),
	String(null()) };

static ::String sMemberFields[] = {
	HX_STRING(L"changed",7),
	HX_STRING(L"setPower",8),
	HX_STRING(L"getPower",8),
	HX_STRING(L"getNormalizedPower",18),
	HX_STRING(L"getDirectionPoint3D",19),
	HX_STRING(L"setDirection",12),
	HX_STRING(L"setDirectionPoint3D",19),
	HX_STRING(L"calculate",9),
	HX_STRING(L"destroy",7),
	HX_STRING(L"color",5),
	HX_STRING(L"__getColor",10),
	HX_STRING(L"__setColor",10),
	HX_STRING(L"_dir",4),
	HX_STRING(L"_power",6),
	HX_STRING(L"_nPower",7),
	HX_STRING(L"_color",6),
	String(null()) };

static void sMarkStatics() {
	hx::MarkMember(Light3D_obj::MAX_POWER);
};

Class Light3D_obj::__mClass;

void Light3D_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_STRING(L"sandy.core.light.Light3D",24), hx::TCanCast< Light3D_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void Light3D_obj::__boot()
{
	hx::Static(MAX_POWER) = 150;
}

} // end namespace sandy
} // end namespace core
} // end namespace light
