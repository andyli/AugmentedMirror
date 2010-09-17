#include <hxcpp.h>

#ifndef INCLUDED_org_casalib_core_Destroyable
#include <org/casalib/core/Destroyable.h>
#endif
#ifndef INCLUDED_org_casalib_core_IDestroyable
#include <org/casalib/core/IDestroyable.h>
#endif
namespace org{
namespace casalib{
namespace core{

Void Destroyable_obj::__construct()
{
{
	this->_isDestroyed = false;
}
;
	return null();
}

Destroyable_obj::~Destroyable_obj() { }

Dynamic Destroyable_obj::__CreateEmpty() { return  new Destroyable_obj; }
hx::ObjectPtr< Destroyable_obj > Destroyable_obj::__new()
{  hx::ObjectPtr< Destroyable_obj > result = new Destroyable_obj();
	result->__construct();
	return result;}

Dynamic Destroyable_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Destroyable_obj > result = new Destroyable_obj();
	result->__construct();
	return result;}

hx::Object *Destroyable_obj::__ToInterface(const type_info &inType) {
	if (inType==typeid( ::org::casalib::core::IDestroyable_obj)) return operator ::org::casalib::core::IDestroyable_obj *();
	return super::__ToInterface(inType);
}

bool Destroyable_obj::getDestroyed( ){
	return this->_isDestroyed;
}


HX_DEFINE_DYNAMIC_FUNC0(Destroyable_obj,getDestroyed,return )

Void Destroyable_obj::destroy( ){
{
		this->_isDestroyed = true;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Destroyable_obj,destroy,(void))


Destroyable_obj::Destroyable_obj()
{
}

void Destroyable_obj::__Mark()
{
	hx::MarkMember(destroyed);
	hx::MarkMember(_isDestroyed);
}

Dynamic Destroyable_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 7:
		if (!memcmp(inName.__s,L"destroy",sizeof(wchar_t)*7) ) { return destroy_dyn(); }
		break;
	case 9:
		if (!memcmp(inName.__s,L"destroyed",sizeof(wchar_t)*9) ) { return getDestroyed(); }
		break;
	case 12:
		if (!memcmp(inName.__s,L"_isDestroyed",sizeof(wchar_t)*12) ) { return _isDestroyed; }
		if (!memcmp(inName.__s,L"getDestroyed",sizeof(wchar_t)*12) ) { return getDestroyed_dyn(); }
	}
	return super::__Field(inName);
}

Dynamic Destroyable_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	switch(inName.length) {
	case 9:
		if (!memcmp(inName.__s,L"destroyed",sizeof(wchar_t)*9) ) { destroyed=inValue.Cast< bool >(); return inValue; }
		break;
	case 12:
		if (!memcmp(inName.__s,L"_isDestroyed",sizeof(wchar_t)*12) ) { _isDestroyed=inValue.Cast< bool >(); return inValue; }
	}
	return super::__SetField(inName,inValue);
}

void Destroyable_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_STRING(L"destroyed",9));
	outFields->push(HX_STRING(L"_isDestroyed",12));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_STRING(L"destroyed",9),
	HX_STRING(L"_isDestroyed",12),
	HX_STRING(L"getDestroyed",12),
	HX_STRING(L"destroy",7),
	String(null()) };

static void sMarkStatics() {
};

Class Destroyable_obj::__mClass;

void Destroyable_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_STRING(L"org.casalib.core.Destroyable",28), hx::TCanCast< Destroyable_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void Destroyable_obj::__boot()
{
}

} // end namespace org
} // end namespace casalib
} // end namespace core
