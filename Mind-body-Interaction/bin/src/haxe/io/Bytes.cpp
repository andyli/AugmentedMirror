#include <hxcpp.h>

#ifndef INCLUDED_haxe_io_Bytes
#include <haxe/io/Bytes.h>
#endif
#ifndef INCLUDED_haxe_io_Error
#include <haxe/io/Error.h>
#endif
namespace haxe{
namespace io{

Void Bytes_obj::__construct(int length,Array< unsigned char > b)
{
{
	this->length = length;
	this->b = b;
}
;
	return null();
}

Bytes_obj::~Bytes_obj() { }

Dynamic Bytes_obj::__CreateEmpty() { return  new Bytes_obj; }
hx::ObjectPtr< Bytes_obj > Bytes_obj::__new(int length,Array< unsigned char > b)
{  hx::ObjectPtr< Bytes_obj > result = new Bytes_obj();
	result->__construct(length,b);
	return result;}

Dynamic Bytes_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Bytes_obj > result = new Bytes_obj();
	result->__construct(inArgs[0],inArgs[1]);
	return result;}

int Bytes_obj::get( int pos){
	return this->b->__get(pos);
}


HX_DEFINE_DYNAMIC_FUNC1(Bytes_obj,get,return )

Void Bytes_obj::set( int pos,int v){
{
		this->b[pos] = v;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(Bytes_obj,set,(void))

Void Bytes_obj::blit( int pos,::haxe::io::Bytes src,int srcpos,int len){
{
		if ((bool((pos < 0)) || bool((bool((srcpos < 0)) || bool((bool((len < 0)) || bool((bool(((pos + len) > this->length)) || bool(((srcpos + len) > src->length))))))))))
			hx::Throw (::haxe::io::Error_obj::OutsideBounds);
		Array< unsigned char > b1 = this->b;
		Array< unsigned char > b2 = src->b;
		if ((bool((b1 == b2)) && bool((pos > srcpos)))){
			int i = len;
			while((i > 0)){
				__SAFE_POINT
				i--;
				b1[(i + pos)] = b2->__get((i + srcpos));
			}
			return null();
		}
		{
			int _g = 0;
			while((_g < len)){
				__SAFE_POINT
				int i = _g++;
				b1[(i + pos)] = b2->__get((i + srcpos));
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC4(Bytes_obj,blit,(void))

::haxe::io::Bytes Bytes_obj::sub( int pos,int len){
	__SAFE_POINT
	if ((bool((pos < 0)) || bool((bool((len < 0)) || bool(((pos + len) > this->length))))))
		hx::Throw (::haxe::io::Error_obj::OutsideBounds);
	return ::haxe::io::Bytes_obj::__new(len,this->b->slice(pos,(pos + len)));
}


HX_DEFINE_DYNAMIC_FUNC2(Bytes_obj,sub,return )

int Bytes_obj::compare( ::haxe::io::Bytes other){
	Array< unsigned char > b1 = this->b;
	Array< unsigned char > b2 = other->b;
	int len = ((this->length < other->length)) ? int( this->length ) : int( other->length );
	{
		int _g = 0;
		while((_g < len)){
			__SAFE_POINT
			int i = _g++;
			if ((b1->__get(i) != b2->__get(i)))
				return (b1->__get(i) - b2->__get(i));
		}
	}
	return (this->length - other->length);
}


HX_DEFINE_DYNAMIC_FUNC1(Bytes_obj,compare,return )

::String Bytes_obj::readString( int pos,int len){
	__SAFE_POINT
	if ((bool((pos < 0)) || bool((bool((len < 0)) || bool(((pos + len) > this->length))))))
		hx::Throw (::haxe::io::Error_obj::OutsideBounds);
	::String result = HX_STRING(L"",0);
	::__hxcpp_string_of_bytes(this->b,result,pos,len);
	return result;
}


HX_DEFINE_DYNAMIC_FUNC2(Bytes_obj,readString,return )

::String Bytes_obj::toString( ){
	__SAFE_POINT
	return this->readString(0,this->length);
}


HX_DEFINE_DYNAMIC_FUNC0(Bytes_obj,toString,return )

Array< unsigned char > Bytes_obj::getData( ){
	return this->b;
}


HX_DEFINE_DYNAMIC_FUNC0(Bytes_obj,getData,return )

::haxe::io::Bytes Bytes_obj::alloc( int length){
	Array< unsigned char > a = Array_obj< unsigned char >::__new();
	if ((length > 0))
		a[(length - 1)] = 0;
	return ::haxe::io::Bytes_obj::__new(length,a);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Bytes_obj,alloc,return )

::haxe::io::Bytes Bytes_obj::ofString( ::String s){
	__SAFE_POINT
	Array< unsigned char > a = Array_obj< unsigned char >::__new();
	::__hxcpp_bytes_of_string(a,s);
	return ::haxe::io::Bytes_obj::__new(a->length,a);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Bytes_obj,ofString,return )

::haxe::io::Bytes Bytes_obj::ofData( Array< unsigned char > b){
	return ::haxe::io::Bytes_obj::__new(b->length,b);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Bytes_obj,ofData,return )


Bytes_obj::Bytes_obj()
{
}

void Bytes_obj::__Mark()
{
	hx::MarkMember(length);
	hx::MarkMember(b);
}

Dynamic Bytes_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 1:
		if (!memcmp(inName.__s,L"b",sizeof(wchar_t)*1) ) { return b; }
		break;
	case 3:
		if (!memcmp(inName.__s,L"get",sizeof(wchar_t)*3) ) { return get_dyn(); }
		if (!memcmp(inName.__s,L"set",sizeof(wchar_t)*3) ) { return set_dyn(); }
		if (!memcmp(inName.__s,L"sub",sizeof(wchar_t)*3) ) { return sub_dyn(); }
		break;
	case 4:
		if (!memcmp(inName.__s,L"blit",sizeof(wchar_t)*4) ) { return blit_dyn(); }
		break;
	case 5:
		if (!memcmp(inName.__s,L"alloc",sizeof(wchar_t)*5) ) { return alloc_dyn(); }
		break;
	case 6:
		if (!memcmp(inName.__s,L"ofData",sizeof(wchar_t)*6) ) { return ofData_dyn(); }
		if (!memcmp(inName.__s,L"length",sizeof(wchar_t)*6) ) { return length; }
		break;
	case 7:
		if (!memcmp(inName.__s,L"compare",sizeof(wchar_t)*7) ) { return compare_dyn(); }
		if (!memcmp(inName.__s,L"getData",sizeof(wchar_t)*7) ) { return getData_dyn(); }
		break;
	case 8:
		if (!memcmp(inName.__s,L"ofString",sizeof(wchar_t)*8) ) { return ofString_dyn(); }
		if (!memcmp(inName.__s,L"toString",sizeof(wchar_t)*8) ) { return toString_dyn(); }
		break;
	case 10:
		if (!memcmp(inName.__s,L"readString",sizeof(wchar_t)*10) ) { return readString_dyn(); }
	}
	return super::__Field(inName);
}

Dynamic Bytes_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	switch(inName.length) {
	case 1:
		if (!memcmp(inName.__s,L"b",sizeof(wchar_t)*1) ) { b=inValue.Cast< Array< unsigned char > >(); return inValue; }
		break;
	case 6:
		if (!memcmp(inName.__s,L"length",sizeof(wchar_t)*6) ) { length=inValue.Cast< int >(); return inValue; }
	}
	return super::__SetField(inName,inValue);
}

void Bytes_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_STRING(L"length",6));
	outFields->push(HX_STRING(L"b",1));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_STRING(L"alloc",5),
	HX_STRING(L"ofString",8),
	HX_STRING(L"ofData",6),
	String(null()) };

static ::String sMemberFields[] = {
	HX_STRING(L"length",6),
	HX_STRING(L"b",1),
	HX_STRING(L"get",3),
	HX_STRING(L"set",3),
	HX_STRING(L"blit",4),
	HX_STRING(L"sub",3),
	HX_STRING(L"compare",7),
	HX_STRING(L"readString",10),
	HX_STRING(L"toString",8),
	HX_STRING(L"getData",7),
	String(null()) };

static void sMarkStatics() {
};

Class Bytes_obj::__mClass;

void Bytes_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_STRING(L"haxe.io.Bytes",13), hx::TCanCast< Bytes_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void Bytes_obj::__boot()
{
}

} // end namespace haxe
} // end namespace io
