#include <hxcpp.h>

#ifndef INCLUDED_haxe_io_Bytes
#include <haxe/io/Bytes.h>
#endif
#ifndef INCLUDED_haxe_io_BytesInput
#include <haxe/io/BytesInput.h>
#endif
#ifndef INCLUDED_haxe_io_Eof
#include <haxe/io/Eof.h>
#endif
#ifndef INCLUDED_haxe_io_Error
#include <haxe/io/Error.h>
#endif
#ifndef INCLUDED_haxe_io_Input
#include <haxe/io/Input.h>
#endif
namespace haxe{
namespace io{

Void BytesInput_obj::__construct(::haxe::io::Bytes b,Dynamic pos,Dynamic len)
{
{
	if ((pos == null()))
		pos = 0;
	if ((len == null()))
		len = (b->length - pos);
	if ((bool((pos < 0)) || bool((bool((len < 0)) || bool(((pos + len) > b->length))))))
		hx::Throw (::haxe::io::Error_obj::OutsideBounds);
	this->b = b->b;
	this->pos = pos;
	this->len = len;
}
;
	return null();
}

BytesInput_obj::~BytesInput_obj() { }

Dynamic BytesInput_obj::__CreateEmpty() { return  new BytesInput_obj; }
hx::ObjectPtr< BytesInput_obj > BytesInput_obj::__new(::haxe::io::Bytes b,Dynamic pos,Dynamic len)
{  hx::ObjectPtr< BytesInput_obj > result = new BytesInput_obj();
	result->__construct(b,pos,len);
	return result;}

Dynamic BytesInput_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< BytesInput_obj > result = new BytesInput_obj();
	result->__construct(inArgs[0],inArgs[1],inArgs[2]);
	return result;}

int BytesInput_obj::readByte( ){
	if ((this->len == 0))
		hx::Throw (::haxe::io::Eof_obj::__new());
	this->len--;
	return this->b->__get(this->pos++);
}


HX_DEFINE_DYNAMIC_FUNC0(BytesInput_obj,readByte,return )

int BytesInput_obj::readBytes( ::haxe::io::Bytes buf,int pos,int len){
	if ((bool((pos < 0)) || bool((bool((len < 0)) || bool(((pos + len) > buf->length))))))
		hx::Throw (::haxe::io::Error_obj::OutsideBounds);
	if ((bool((this->len == 0)) && bool((len > 0))))
		hx::Throw (::haxe::io::Eof_obj::__new());
	if ((this->len < len))
		len = this->len;
	Array< unsigned char > b1 = this->b;
	Array< unsigned char > b2 = buf->b;
	{
		int _g = 0;
		while((_g < len)){
			__SAFE_POINT
			int i = _g++;
			b2[(pos + i)] = b1->__get((this->pos + i));
		}
	}
	hx::AddEq(this->pos,len);
	hx::SubEq(this->len,len);
	return len;
}


HX_DEFINE_DYNAMIC_FUNC3(BytesInput_obj,readBytes,return )


BytesInput_obj::BytesInput_obj()
{
}

void BytesInput_obj::__Mark()
{
	hx::MarkMember(b);
	hx::MarkMember(pos);
	hx::MarkMember(len);
	super::__Mark();
}

Dynamic BytesInput_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 1:
		if (!memcmp(inName.__s,L"b",sizeof(wchar_t)*1) ) { return b; }
		break;
	case 3:
		if (!memcmp(inName.__s,L"pos",sizeof(wchar_t)*3) ) { return pos; }
		if (!memcmp(inName.__s,L"len",sizeof(wchar_t)*3) ) { return len; }
		break;
	case 8:
		if (!memcmp(inName.__s,L"readByte",sizeof(wchar_t)*8) ) { return readByte_dyn(); }
		break;
	case 9:
		if (!memcmp(inName.__s,L"readBytes",sizeof(wchar_t)*9) ) { return readBytes_dyn(); }
	}
	return super::__Field(inName);
}

Dynamic BytesInput_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	switch(inName.length) {
	case 1:
		if (!memcmp(inName.__s,L"b",sizeof(wchar_t)*1) ) { b=inValue.Cast< Array< unsigned char > >(); return inValue; }
		break;
	case 3:
		if (!memcmp(inName.__s,L"pos",sizeof(wchar_t)*3) ) { pos=inValue.Cast< int >(); return inValue; }
		if (!memcmp(inName.__s,L"len",sizeof(wchar_t)*3) ) { len=inValue.Cast< int >(); return inValue; }
	}
	return super::__SetField(inName,inValue);
}

void BytesInput_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_STRING(L"b",1));
	outFields->push(HX_STRING(L"pos",3));
	outFields->push(HX_STRING(L"len",3));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_STRING(L"b",1),
	HX_STRING(L"pos",3),
	HX_STRING(L"len",3),
	HX_STRING(L"readByte",8),
	HX_STRING(L"readBytes",9),
	String(null()) };

static void sMarkStatics() {
};

Class BytesInput_obj::__mClass;

void BytesInput_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_STRING(L"haxe.io.BytesInput",18), hx::TCanCast< BytesInput_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void BytesInput_obj::__boot()
{
}

} // end namespace haxe
} // end namespace io
