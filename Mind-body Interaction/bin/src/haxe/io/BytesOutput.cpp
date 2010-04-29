#include <hxcpp.h>

#ifndef INCLUDED_haxe_io_Bytes
#include <haxe/io/Bytes.h>
#endif
#ifndef INCLUDED_haxe_io_BytesBuffer
#include <haxe/io/BytesBuffer.h>
#endif
#ifndef INCLUDED_haxe_io_BytesOutput
#include <haxe/io/BytesOutput.h>
#endif
#ifndef INCLUDED_haxe_io_Error
#include <haxe/io/Error.h>
#endif
#ifndef INCLUDED_haxe_io_Output
#include <haxe/io/Output.h>
#endif
namespace haxe{
namespace io{

Void BytesOutput_obj::__construct()
{
{
	this->b = ::haxe::io::BytesBuffer_obj::__new();
}
;
	return null();
}

BytesOutput_obj::~BytesOutput_obj() { }

Dynamic BytesOutput_obj::__CreateEmpty() { return  new BytesOutput_obj; }
hx::ObjectPtr< BytesOutput_obj > BytesOutput_obj::__new()
{  hx::ObjectPtr< BytesOutput_obj > result = new BytesOutput_obj();
	result->__construct();
	return result;}

Dynamic BytesOutput_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< BytesOutput_obj > result = new BytesOutput_obj();
	result->__construct();
	return result;}

Void BytesOutput_obj::writeByte( int c){
{
		__SAFE_POINT
		this->b->b->push(c);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(BytesOutput_obj,writeByte,(void))

int BytesOutput_obj::writeBytes( ::haxe::io::Bytes buf,int pos,int len){
	__SAFE_POINT
	{
		::haxe::io::BytesBuffer _g = this->b;
		if ((bool((pos < 0)) || bool((bool((len < 0)) || bool(((pos + len) > buf->length))))))
			hx::Throw (::haxe::io::Error_obj::OutsideBounds);
		Array< unsigned char > b1 = _g->b;
		Array< unsigned char > b2 = buf->b;
		{
			int _g1 = pos;
			int _g2 = (pos + len);
			while((_g1 < _g2)){
				__SAFE_POINT
				int i = _g1++;
				_g->b->push(b2->__get(i));
			}
		}
	}
	return len;
}


HX_DEFINE_DYNAMIC_FUNC3(BytesOutput_obj,writeBytes,return )

::haxe::io::Bytes BytesOutput_obj::getBytes( ){
	__SAFE_POINT
	return this->b->getBytes();
}


HX_DEFINE_DYNAMIC_FUNC0(BytesOutput_obj,getBytes,return )


BytesOutput_obj::BytesOutput_obj()
{
}

void BytesOutput_obj::__Mark()
{
	hx::MarkMember(b);
	super::__Mark();
}

Dynamic BytesOutput_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 1:
		if (!memcmp(inName.__s,L"b",sizeof(wchar_t)*1) ) { return b; }
		break;
	case 8:
		if (!memcmp(inName.__s,L"getBytes",sizeof(wchar_t)*8) ) { return getBytes_dyn(); }
		break;
	case 9:
		if (!memcmp(inName.__s,L"writeByte",sizeof(wchar_t)*9) ) { return writeByte_dyn(); }
		break;
	case 10:
		if (!memcmp(inName.__s,L"writeBytes",sizeof(wchar_t)*10) ) { return writeBytes_dyn(); }
	}
	return super::__Field(inName);
}

Dynamic BytesOutput_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	switch(inName.length) {
	case 1:
		if (!memcmp(inName.__s,L"b",sizeof(wchar_t)*1) ) { b=inValue.Cast< ::haxe::io::BytesBuffer >(); return inValue; }
	}
	return super::__SetField(inName,inValue);
}

void BytesOutput_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_STRING(L"b",1));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_STRING(L"b",1),
	HX_STRING(L"writeByte",9),
	HX_STRING(L"writeBytes",10),
	HX_STRING(L"getBytes",8),
	String(null()) };

static void sMarkStatics() {
};

Class BytesOutput_obj::__mClass;

void BytesOutput_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_STRING(L"haxe.io.BytesOutput",19), hx::TCanCast< BytesOutput_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void BytesOutput_obj::__boot()
{
}

} // end namespace haxe
} // end namespace io
