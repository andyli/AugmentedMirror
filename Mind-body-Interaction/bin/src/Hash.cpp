#include <hxcpp.h>

#ifndef INCLUDED_Hash
#include <Hash.h>
#endif
#ifndef INCLUDED_Std
#include <Std.h>
#endif
#ifndef INCLUDED_StringBuf
#include <StringBuf.h>
#endif

Void Hash_obj::__construct()
{
{
	struct _Function_1_1{
		inline static Dynamic Block( ){
			hx::Anon __result = hx::Anon_obj::Create();
			return __result;
		}
	};
	this->h = _Function_1_1::Block();
}
;
	return null();
}

Hash_obj::~Hash_obj() { }

Dynamic Hash_obj::__CreateEmpty() { return  new Hash_obj; }
hx::ObjectPtr< Hash_obj > Hash_obj::__new()
{  hx::ObjectPtr< Hash_obj > result = new Hash_obj();
	result->__construct();
	return result;}

Dynamic Hash_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Hash_obj > result = new Hash_obj();
	result->__construct();
	return result;}

Void Hash_obj::set( ::String key,Dynamic value){
{
		__SAFE_POINT
		this->h->__SetField(key,value);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(Hash_obj,set,(void))

Dynamic Hash_obj::get( ::String key){
	__SAFE_POINT
	return this->h->__Field(key);
}


HX_DEFINE_DYNAMIC_FUNC1(Hash_obj,get,return )

bool Hash_obj::exists( ::String key){
	__SAFE_POINT
	return (this->h->__Field(key) != null());
}


HX_DEFINE_DYNAMIC_FUNC1(Hash_obj,exists,return )

bool Hash_obj::remove( ::String key){
	__SAFE_POINT
	return ::__hxcpp_anon_remove(this->h,key);
}


HX_DEFINE_DYNAMIC_FUNC1(Hash_obj,remove,return )

Dynamic Hash_obj::keys( ){
	__SAFE_POINT
	Array< ::String > a = Array_obj< ::String >::__new();
	this->h->__GetFields(a);
	return a->iterator();
}


HX_DEFINE_DYNAMIC_FUNC0(Hash_obj,keys,return )

Dynamic Hash_obj::iterator( ){
	__SAFE_POINT
	Array< ::String > a = Array_obj< ::String >::__new();
	this->h->__GetFields(a);
	Array< Dynamic > it = Array_obj< Dynamic >::__new().Add(a->iterator());
	struct _Function_1_1{
		inline static Dynamic Block( Array< Dynamic > &it,Dynamic &h){
			hx::Anon __result = hx::Anon_obj::Create();

			HX_BEGIN_LOCAL_FUNC1(_Function_2_1,Array< Dynamic >,it)
			bool run(){
{
					__SAFE_POINT
					return it[0]->__Field(HX_STRING(L"hasNext",7))();
				}
				return null();
			}
			HX_END_LOCAL_FUNC0(return)

			__result->Add(HX_STRING(L"hasNext",7) ,  Dynamic(new _Function_2_1(it)));

			HX_BEGIN_LOCAL_FUNC2(_Function_2_2,Dynamic,h,Array< Dynamic >,it)
			Dynamic run(){
{
					__SAFE_POINT
					return h->__Field(it[0]->__Field(HX_STRING(L"next",4))());
				}
				return null();
			}
			HX_END_LOCAL_FUNC0(return)

			__result->Add(HX_STRING(L"next",4) ,  Dynamic(new _Function_2_2(h,it)));
			return __result;
		}
	};
	return _Function_1_1::Block(it,h);
}


HX_DEFINE_DYNAMIC_FUNC0(Hash_obj,iterator,return )

::String Hash_obj::toString( ){
	__SAFE_POINT
	::StringBuf s = ::StringBuf_obj::__new();
	s->b[s->b->length] = HX_STRING(L"{",1);
	Dynamic it = this->keys();
	for(Dynamic __it = it;  __it->__Field(HX_STRING(L"hasNext",7))(); ){
::String i = __it->__Field(HX_STRING(L"next",4))();
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


HX_DEFINE_DYNAMIC_FUNC0(Hash_obj,toString,return )


Hash_obj::Hash_obj()
{
}

void Hash_obj::__Mark()
{
	hx::MarkMember(h);
}

Dynamic Hash_obj::__Field(const ::String &inName)
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

Dynamic Hash_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	switch(inName.length) {
	case 1:
		if (!memcmp(inName.__s,L"h",sizeof(wchar_t)*1) ) { h=inValue.Cast< Dynamic >(); return inValue; }
	}
	return super::__SetField(inName,inValue);
}

void Hash_obj::__GetFields(Array< ::String> &outFields)
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

Class Hash_obj::__mClass;

void Hash_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_STRING(L"Hash",4), hx::TCanCast< Hash_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void Hash_obj::__boot()
{
}

