#include <hxcpp.h>

#ifndef INCLUDED_sandy_Haxe
#include <sandy/Haxe.h>
#endif
namespace sandy{

Void Haxe_obj::__construct()
{
	return null();
}

Haxe_obj::~Haxe_obj() { }

Dynamic Haxe_obj::__CreateEmpty() { return  new Haxe_obj; }
hx::ObjectPtr< Haxe_obj > Haxe_obj::__new()
{  hx::ObjectPtr< Haxe_obj > result = new Haxe_obj();
	result->__construct();
	return result;}

Dynamic Haxe_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Haxe_obj > result = new Haxe_obj();
	result->__construct();
	return result;}

void Haxe_obj::__init__(){
}


Array< Dynamic > Haxe_obj::toArray( Array< Dynamic > v){
	Array< Dynamic > a = Array_obj< Dynamic >::__new();
	{
		int _g1 = 0;
		int _g = v->length;
		while((_g1 < _g)){
			__SAFE_POINT
			int i = _g1++;
			a[i] = v->__get(i);
		}
	}
	return a;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Haxe_obj,toArray,return )

Array< Dynamic > Haxe_obj::toTypedArray( Array< Dynamic > v){
	return v;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Haxe_obj,toTypedArray,return )


Haxe_obj::Haxe_obj()
{
}

void Haxe_obj::__Mark()
{
}

Dynamic Haxe_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 7:
		if (!memcmp(inName.__s,L"toArray",sizeof(wchar_t)*7) ) { return toArray_dyn(); }
		break;
	case 12:
		if (!memcmp(inName.__s,L"toTypedArray",sizeof(wchar_t)*12) ) { return toTypedArray_dyn(); }
	}
	return super::__Field(inName);
}

Dynamic Haxe_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	return super::__SetField(inName,inValue);
}

void Haxe_obj::__GetFields(Array< ::String> &outFields)
{
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_STRING(L"toArray",7),
	HX_STRING(L"toTypedArray",12),
	String(null()) };

static ::String sMemberFields[] = {
	String(null()) };

static void sMarkStatics() {
};

Class Haxe_obj::__mClass;

void Haxe_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_STRING(L"sandy.Haxe",10), hx::TCanCast< Haxe_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void Haxe_obj::__boot()
{
}

} // end namespace sandy
