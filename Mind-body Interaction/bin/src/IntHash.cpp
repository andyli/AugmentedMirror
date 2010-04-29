#include <hxcpp.h>

#ifndef INCLUDED_IntHash
#include <IntHash.h>
#endif
#ifndef INCLUDED_Std
#include <Std.h>
#endif
#ifndef INCLUDED_StringBuf
#include <StringBuf.h>
#endif

Void IntHash_obj::__construct()
{
{
	this->h = ::__int_hash_create();
}
;
	return null();
}

IntHash_obj::~IntHash_obj() { }

Dynamic IntHash_obj::__CreateEmpty() { return  new IntHash_obj; }
hx::ObjectPtr< IntHash_obj > IntHash_obj::__new()
{  hx::ObjectPtr< IntHash_obj > result = new IntHash_obj();
	result->__construct();
	return result;}

Dynamic IntHash_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< IntHash_obj > result = new IntHash_obj();
	result->__construct();
	return result;}

Void IntHash_obj::set( int key,Dynamic value){
{
		__SAFE_POINT
		::__int_hash_set(this->h,key,value);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(IntHash_obj,set,(void))

Dynamic IntHash_obj::get( int key){
	__SAFE_POINT
	return ::__int_hash_get(this->h,key);
}


HX_DEFINE_DYNAMIC_FUNC1(IntHash_obj,get,return )

bool IntHash_obj::exists( int key){
	__SAFE_POINT
	return ::__int_hash_exists(this->h,key);
}


HX_DEFINE_DYNAMIC_FUNC1(IntHash_obj,exists,return )

bool IntHash_obj::remove( int key){
	__SAFE_POINT
	return ::__int_hash_remove(this->h,key);
}


HX_DEFINE_DYNAMIC_FUNC1(IntHash_obj,remove,return )

Dynamic IntHash_obj::keys( ){
	__SAFE_POINT
	Array< int > a = ::__int_hash_keys(this->h);
	return a->iterator();
}


HX_DEFINE_DYNAMIC_FUNC0(IntHash_obj,keys,return )

Dynamic IntHash_obj::iterator( ){
	__SAFE_POINT
	Array< Dynamic > a = ::__int_hash_values(this->h);
	return a->iterator();
}


HX_DEFINE_DYNAMIC_FUNC0(IntHash_obj,iterator,return )

::String IntHash_obj::toString( ){
	__SAFE_POINT
	::StringBuf s = ::StringBuf_obj::__new();
	s->b[s->b->length] = HX_STRING(L"{",1);
	Dynamic it = this->keys();
	for(Dynamic __it = it;  __it->__Field(HX_STRING(L"hasNext",7))(); ){
int i = __it->__Field(HX_STRING(L"next",4))();
		{
			s->b[s->b->length] = i;
			s->b[s->b->length] = HX_STRING(L" => ",4);
			s->b[s->b->length] = ::Std_obj::string(this->get(i));
			if (it->__Field(HX_STRING(L"hasNext",7))())
				s->b[s->b->length] = HX_STRING(L", ",2);
		}
;
		__SAFE_POINT
	}
	s->b[s->b->length] = HX_STRING(L"}",1);
	return s->b->join(HX_STRING(L"",0));
}


HX_DEFINE_DYNAMIC_FUNC0(IntHash_obj,toString,return )


IntHash_obj::IntHash_obj()
{
}

void IntHash_obj::__Mark()
{
	hx::MarkMember(h);
}

Dynamic IntHash_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 1:
		if (!memcmp(inName.__s,L"h",sizeof(wchar_t)*1) ) { return h; }
		break;
	case 3:
		if (!memcmp(inName.__s,L"set",sizeof(wchar_t)*3) ) { return set_dyn(); }
		if (!memcmp(inName.__s,L"get",sizeof(wchar_t)*3) ) { return get_dyn(); }
		break;
	case 4:
		if (!memcmp(inName.__s,L"keys",sizeof(wchar_t)*4) ) { return keys_dyn(); }
		break;
	case 6:
		if (!memcmp(inName.__s,L"exists",sizeof(wchar_t)*6) ) { return exists_dyn(); }
		if (!memcmp(inName.__s,L"remove",sizeof(wchar_t)*6) ) { return remove_dyn(); }
		break;
	case 8:
		if (!memcmp(inName.__s,L"iterator",sizeof(wchar_t)*8) ) { return iterator_dyn(); }
		if (!memcmp(inName.__s,L"toString",sizeof(wchar_t)*8) ) { return toString_dyn(); }
	}
	return super::__Field(inName);
}

Dynamic IntHash_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	switch(inName.length) {
	case 1:
		if (!memcmp(inName.__s,L"h",sizeof(wchar_t)*1) ) { h=inValue.Cast< Dynamic >(); return inValue; }
	}
	return super::__SetField(inName,inValue);
}

void IntHash_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_STRING(L"h",1));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_STRING(L"h",1),
	HX_STRING(L"set",3),
	HX_STRING(L"get",3),
	HX_STRING(L"exists",6),
	HX_STRING(L"remove",6),
	HX_STRING(L"keys",4),
	HX_STRING(L"iterator",8),
	HX_STRING(L"toString",8),
	String(null()) };

static void sMarkStatics() {
};

Class IntHash_obj::__mClass;

void IntHash_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_STRING(L"IntHash",7), hx::TCanCast< IntHash_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void IntHash_obj::__boot()
{
}

