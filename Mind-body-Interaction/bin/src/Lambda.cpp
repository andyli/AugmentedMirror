#include <hxcpp.h>

#ifndef INCLUDED_Lambda
#include <Lambda.h>
#endif
#ifndef INCLUDED_List
#include <List.h>
#endif

Void Lambda_obj::__construct()
{
	return null();
}

Lambda_obj::~Lambda_obj() { }

Dynamic Lambda_obj::__CreateEmpty() { return  new Lambda_obj; }
hx::ObjectPtr< Lambda_obj > Lambda_obj::__new()
{  hx::ObjectPtr< Lambda_obj > result = new Lambda_obj();
	result->__construct();
	return result;}

Dynamic Lambda_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Lambda_obj > result = new Lambda_obj();
	result->__construct();
	return result;}

Array< Dynamic > Lambda_obj::array( Dynamic it){
	__SAFE_POINT
	Array< Dynamic > a = Array_obj< Dynamic >::__new();
	for(Dynamic __it = it->__Field(HX_STRING(L"iterator",8))();  __it->__Field(HX_STRING(L"hasNext",7))(); ){
Dynamic i = __it->__Field(HX_STRING(L"next",4))();
		a->push(i);
		__SAFE_POINT
	}
	return a;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Lambda_obj,array,return )

::List Lambda_obj::list( Dynamic it){
	__SAFE_POINT
	::List l = ::List_obj::__new();
	for(Dynamic __it = it->__Field(HX_STRING(L"iterator",8))();  __it->__Field(HX_STRING(L"hasNext",7))(); ){
Dynamic i = __it->__Field(HX_STRING(L"next",4))();
		l->add(i);
		__SAFE_POINT
	}
	return l;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Lambda_obj,list,return )

::List Lambda_obj::map( Dynamic it,Dynamic f){
	__SAFE_POINT
	::List l = ::List_obj::__new();
	for(Dynamic __it = it->__Field(HX_STRING(L"iterator",8))();  __it->__Field(HX_STRING(L"hasNext",7))(); ){
Dynamic x = __it->__Field(HX_STRING(L"next",4))();
		l->add(f(x));
		__SAFE_POINT
	}
	return l;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(Lambda_obj,map,return )

::List Lambda_obj::mapi( Dynamic it,Dynamic f){
	__SAFE_POINT
	::List l = ::List_obj::__new();
	int i = 0;
	for(Dynamic __it = it->__Field(HX_STRING(L"iterator",8))();  __it->__Field(HX_STRING(L"hasNext",7))(); ){
Dynamic x = __it->__Field(HX_STRING(L"next",4))();
		l->add(f(i++,x));
		__SAFE_POINT
	}
	return l;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(Lambda_obj,mapi,return )

bool Lambda_obj::has( Dynamic it,Dynamic elt,Dynamic cmp){
	__SAFE_POINT
	if ((cmp == null())){
		for(Dynamic __it = it->__Field(HX_STRING(L"iterator",8))();  __it->__Field(HX_STRING(L"hasNext",7))(); ){
Dynamic x = __it->__Field(HX_STRING(L"next",4))();
			if ((x == elt))
				return true;
			__SAFE_POINT
		}
	}
	else{
		for(Dynamic __it = it->__Field(HX_STRING(L"iterator",8))();  __it->__Field(HX_STRING(L"hasNext",7))(); ){
Dynamic x = __it->__Field(HX_STRING(L"next",4))();
			if (cmp(x,elt))
				return true;
			__SAFE_POINT
		}
	}
	return false;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC3(Lambda_obj,has,return )

bool Lambda_obj::exists( Dynamic it,Dynamic f){
	__SAFE_POINT
	for(Dynamic __it = it->__Field(HX_STRING(L"iterator",8))();  __it->__Field(HX_STRING(L"hasNext",7))(); ){
Dynamic x = __it->__Field(HX_STRING(L"next",4))();
		if (f(x))
			return true;
		__SAFE_POINT
	}
	return false;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(Lambda_obj,exists,return )

bool Lambda_obj::foreach( Dynamic it,Dynamic f){
	__SAFE_POINT
	for(Dynamic __it = it->__Field(HX_STRING(L"iterator",8))();  __it->__Field(HX_STRING(L"hasNext",7))(); ){
Dynamic x = __it->__Field(HX_STRING(L"next",4))();
		if (!f(x))
			return false;
		__SAFE_POINT
	}
	return true;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(Lambda_obj,foreach,return )

Void Lambda_obj::iter( Dynamic it,Dynamic f){
{
		__SAFE_POINT
		for(Dynamic __it = it->__Field(HX_STRING(L"iterator",8))();  __it->__Field(HX_STRING(L"hasNext",7))(); ){
Dynamic x = __it->__Field(HX_STRING(L"next",4))();
			f(x);
			__SAFE_POINT
		}
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(Lambda_obj,iter,(void))

::List Lambda_obj::filter( Dynamic it,Dynamic f){
	__SAFE_POINT
	::List l = ::List_obj::__new();
	for(Dynamic __it = it->__Field(HX_STRING(L"iterator",8))();  __it->__Field(HX_STRING(L"hasNext",7))(); ){
Dynamic x = __it->__Field(HX_STRING(L"next",4))();
		if (f(x))
			l->add(x);
		__SAFE_POINT
	}
	return l;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(Lambda_obj,filter,return )

Dynamic Lambda_obj::fold( Dynamic it,Dynamic f,Dynamic first){
	__SAFE_POINT
	for(Dynamic __it = it->__Field(HX_STRING(L"iterator",8))();  __it->__Field(HX_STRING(L"hasNext",7))(); ){
Dynamic x = __it->__Field(HX_STRING(L"next",4))();
		first = f(x,first);
		__SAFE_POINT
	}
	return first;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC3(Lambda_obj,fold,return )

int Lambda_obj::count( Dynamic it){
	__SAFE_POINT
	int n = 0;
	for(Dynamic __it = it->__Field(HX_STRING(L"iterator",8))();  __it->__Field(HX_STRING(L"hasNext",7))(); ){
Dynamic _ = __it->__Field(HX_STRING(L"next",4))();
		++n;
		__SAFE_POINT
	}
	return n;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Lambda_obj,count,return )

bool Lambda_obj::empty( Dynamic it){
	__SAFE_POINT
	return !it->__Field(HX_STRING(L"iterator",8))()->__Field(HX_STRING(L"hasNext",7))();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Lambda_obj,empty,return )


Lambda_obj::Lambda_obj()
{
}

void Lambda_obj::__Mark()
{
}

Dynamic Lambda_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 3:
		if (!memcmp(inName.__s,L"map",sizeof(wchar_t)*3) ) { return map_dyn(); }
		if (!memcmp(inName.__s,L"has",sizeof(wchar_t)*3) ) { return has_dyn(); }
		break;
	case 4:
		if (!memcmp(inName.__s,L"list",sizeof(wchar_t)*4) ) { return list_dyn(); }
		if (!memcmp(inName.__s,L"mapi",sizeof(wchar_t)*4) ) { return mapi_dyn(); }
		if (!memcmp(inName.__s,L"iter",sizeof(wchar_t)*4) ) { return iter_dyn(); }
		if (!memcmp(inName.__s,L"fold",sizeof(wchar_t)*4) ) { return fold_dyn(); }
		break;
	case 5:
		if (!memcmp(inName.__s,L"array",sizeof(wchar_t)*5) ) { return array_dyn(); }
		if (!memcmp(inName.__s,L"count",sizeof(wchar_t)*5) ) { return count_dyn(); }
		if (!memcmp(inName.__s,L"empty",sizeof(wchar_t)*5) ) { return empty_dyn(); }
		break;
	case 6:
		if (!memcmp(inName.__s,L"exists",sizeof(wchar_t)*6) ) { return exists_dyn(); }
		if (!memcmp(inName.__s,L"filter",sizeof(wchar_t)*6) ) { return filter_dyn(); }
		break;
	case 7:
		if (!memcmp(inName.__s,L"foreach",sizeof(wchar_t)*7) ) { return foreach_dyn(); }
	}
	return super::__Field(inName);
}

Dynamic Lambda_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	return super::__SetField(inName,inValue);
}

void Lambda_obj::__GetFields(Array< ::String> &outFields)
{
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_STRING(L"array",5),
	HX_STRING(L"list",4),
	HX_STRING(L"map",3),
	HX_STRING(L"mapi",4),
	HX_STRING(L"has",3),
	HX_STRING(L"exists",6),
	HX_STRING(L"foreach",7),
	HX_STRING(L"iter",4),
	HX_STRING(L"filter",6),
	HX_STRING(L"fold",4),
	HX_STRING(L"count",5),
	HX_STRING(L"empty",5),
	String(null()) };

static ::String sMemberFields[] = {
	String(null()) };

static void sMarkStatics() {
};

Class Lambda_obj::__mClass;

void Lambda_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_STRING(L"Lambda",6), hx::TCanCast< Lambda_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void Lambda_obj::__boot()
{
}

