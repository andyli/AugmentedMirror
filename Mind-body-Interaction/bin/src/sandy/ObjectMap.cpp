#include <hxcpp.h>

#ifndef INCLUDED_Reflect
#include <Reflect.h>
#endif
#ifndef INCLUDED_Type
#include <Type.h>
#endif
#ifndef INCLUDED_ValueType
#include <ValueType.h>
#endif
#ifndef INCLUDED_sandy_ObjectMap
#include <sandy/ObjectMap.h>
#endif
namespace sandy{

Void ObjectMap_obj::__construct(Dynamic __o_useWeak)
{
bool useWeak = __o_useWeak.Default(false);
{
	this->m_values = Array_obj< Dynamic >::__new();
}
;
	return null();
}

ObjectMap_obj::~ObjectMap_obj() { }

Dynamic ObjectMap_obj::__CreateEmpty() { return  new ObjectMap_obj; }
hx::ObjectPtr< ObjectMap_obj > ObjectMap_obj::__new(Dynamic __o_useWeak)
{  hx::ObjectPtr< ObjectMap_obj > result = new ObjectMap_obj();
	result->__construct(__o_useWeak);
	return result;}

Dynamic ObjectMap_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< ObjectMap_obj > result = new ObjectMap_obj();
	result->__construct(inArgs[0]);
	return result;}

Dynamic ObjectMap_obj::get( Dynamic key){
	__SAFE_POINT
	int idx = this->getTagIndex(key);
	return ((idx < 0)) ? Dynamic( null() ) : Dynamic( this->m_values->__get(idx) );
}


HX_DEFINE_DYNAMIC_FUNC1(ObjectMap_obj,get,return )

Void ObjectMap_obj::set( Dynamic key,Dynamic value){
{
		__SAFE_POINT
		int idx = this->getTagIndex(key);
		if ((idx < 0)){
			this->m_values[idx] = value;
		}
		else{
			this->m_keys->push(key);
			if ((key != null())){
				key->__SetField(HX_STRING(L"__{ObjectMapTag}",16),(this->m_values->push(value) - 1));
			}
			else{
				{};
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(ObjectMap_obj,set,(void))

bool ObjectMap_obj::exists( Dynamic key){
	__SAFE_POINT
	return (this->getTagIndex(key) >= 0);
}


HX_DEFINE_DYNAMIC_FUNC1(ObjectMap_obj,exists,return )

Void ObjectMap_obj::_delete( Dynamic key){
{
		__SAFE_POINT
		int idx = this->getTagIndex(key);
		if ((idx >= 0)){
			this->m_keys[idx] = null();
			this->m_values[idx] = null();
		}
		::Reflect_obj::deleteField(key,HX_STRING(L"__{ObjectMapTag}",16));
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(ObjectMap_obj,_delete,(void))

Array< Dynamic > ObjectMap_obj::keys( ){
	return this->m_keys;
}


HX_DEFINE_DYNAMIC_FUNC0(ObjectMap_obj,keys,return )

Dynamic ObjectMap_obj::iterator( ){
	__SAFE_POINT
	return this->m_keys->iterator();
}


HX_DEFINE_DYNAMIC_FUNC0(ObjectMap_obj,iterator,return )

int ObjectMap_obj::getTagIndex( Dynamic key){
	__SAFE_POINT
	Dynamic idyn = ((key == null())) ? Dynamic( null() ) : Dynamic( key->__Field(HX_STRING(L"__{ObjectMapTag}",16)) );
	if ((idyn == null()))
		return -1;
	::ValueType _switch_1 = (::Type_obj::_typeof(idyn));
	switch((_switch_1)->GetIndex()){
		case 1: {
			return idyn;
		}
		;break;
		default: {
			return -1;
		}
	}
}


HX_DEFINE_DYNAMIC_FUNC1(ObjectMap_obj,getTagIndex,return )

::String ObjectMap_obj::TAG;


ObjectMap_obj::ObjectMap_obj()
{
}

void ObjectMap_obj::__Mark()
{
	hx::MarkMember(m_keys);
	hx::MarkMember(m_values);
}

Dynamic ObjectMap_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 3:
		if (!memcmp(inName.__s,L"TAG",sizeof(wchar_t)*3) ) { return TAG; }
		if (!memcmp(inName.__s,L"get",sizeof(wchar_t)*3) ) { return get_dyn(); }
		if (!memcmp(inName.__s,L"set",sizeof(wchar_t)*3) ) { return set_dyn(); }
		break;
	case 4:
		if (!memcmp(inName.__s,L"keys",sizeof(wchar_t)*4) ) { return keys_dyn(); }
		break;
	case 6:
		if (!memcmp(inName.__s,L"m_keys",sizeof(wchar_t)*6) ) { return m_keys; }
		if (!memcmp(inName.__s,L"exists",sizeof(wchar_t)*6) ) { return exists_dyn(); }
		if (!memcmp(inName.__s,L"delete",sizeof(wchar_t)*6) ) { return _delete_dyn(); }
		break;
	case 8:
		if (!memcmp(inName.__s,L"m_values",sizeof(wchar_t)*8) ) { return m_values; }
		if (!memcmp(inName.__s,L"iterator",sizeof(wchar_t)*8) ) { return iterator_dyn(); }
		break;
	case 11:
		if (!memcmp(inName.__s,L"getTagIndex",sizeof(wchar_t)*11) ) { return getTagIndex_dyn(); }
	}
	return super::__Field(inName);
}

Dynamic ObjectMap_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	switch(inName.length) {
	case 3:
		if (!memcmp(inName.__s,L"TAG",sizeof(wchar_t)*3) ) { TAG=inValue.Cast< ::String >(); return inValue; }
		break;
	case 6:
		if (!memcmp(inName.__s,L"m_keys",sizeof(wchar_t)*6) ) { m_keys=inValue.Cast< Array< Dynamic > >(); return inValue; }
		break;
	case 8:
		if (!memcmp(inName.__s,L"m_values",sizeof(wchar_t)*8) ) { m_values=inValue.Cast< Array< Dynamic > >(); return inValue; }
	}
	return super::__SetField(inName,inValue);
}

void ObjectMap_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_STRING(L"m_keys",6));
	outFields->push(HX_STRING(L"m_values",8));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_STRING(L"TAG",3),
	String(null()) };

static ::String sMemberFields[] = {
	HX_STRING(L"m_keys",6),
	HX_STRING(L"m_values",8),
	HX_STRING(L"get",3),
	HX_STRING(L"set",3),
	HX_STRING(L"exists",6),
	HX_STRING(L"delete",6),
	HX_STRING(L"keys",4),
	HX_STRING(L"iterator",8),
	HX_STRING(L"getTagIndex",11),
	String(null()) };

static void sMarkStatics() {
	hx::MarkMember(ObjectMap_obj::TAG);
};

Class ObjectMap_obj::__mClass;

void ObjectMap_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_STRING(L"sandy.ObjectMap",15), hx::TCanCast< ObjectMap_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void ObjectMap_obj::__boot()
{
	hx::Static(TAG) = HX_STRING(L"__{ObjectMapTag}",16);
}

} // end namespace sandy
