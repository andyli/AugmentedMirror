#include <hxcpp.h>

#ifndef INCLUDED_cpp_Lib
#include <cpp/Lib.h>
#endif
#ifndef INCLUDED_cpp_zip_Flush
#include <cpp/zip/Flush.h>
#endif
#ifndef INCLUDED_cpp_zip_Uncompress
#include <cpp/zip/Uncompress.h>
#endif
#ifndef INCLUDED_haxe_io_Bytes
#include <haxe/io/Bytes.h>
#endif
#ifndef INCLUDED_haxe_io_BytesBuffer
#include <haxe/io/BytesBuffer.h>
#endif
#ifndef INCLUDED_haxe_io_Error
#include <haxe/io/Error.h>
#endif
namespace cpp{
namespace zip{

Void Uncompress_obj::__construct(Dynamic windowBits)
{
{
	this->s = ::cpp::zip::Uncompress_obj::_inflate_init(windowBits);
}
;
	return null();
}

Uncompress_obj::~Uncompress_obj() { }

Dynamic Uncompress_obj::__CreateEmpty() { return  new Uncompress_obj; }
hx::ObjectPtr< Uncompress_obj > Uncompress_obj::__new(Dynamic windowBits)
{  hx::ObjectPtr< Uncompress_obj > result = new Uncompress_obj();
	result->__construct(windowBits);
	return result;}

Dynamic Uncompress_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Uncompress_obj > result = new Uncompress_obj();
	result->__construct(inArgs[0]);
	return result;}

Dynamic Uncompress_obj::this_run( ::haxe::io::Bytes src,int srcPos,::haxe::io::Bytes dst,int dstPos){
	__SAFE_POINT
	return ::cpp::zip::Uncompress_obj::_inflate_buffer(this->s,src->b,srcPos,dst->b,dstPos);
}


HX_DEFINE_DYNAMIC_FUNC4(Uncompress_obj,this_run,return )

Void Uncompress_obj::setFlushMode( ::cpp::zip::Flush f){
{
		__SAFE_POINT
		::cpp::zip::Uncompress_obj::_set_flush_mode(this->s,f->__Tag());
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Uncompress_obj,setFlushMode,(void))

Void Uncompress_obj::close( ){
{
		__SAFE_POINT
		::cpp::zip::Uncompress_obj::_inflate_end(this->s);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Uncompress_obj,close,(void))

::haxe::io::Bytes Uncompress_obj::run( ::haxe::io::Bytes src,Dynamic bufsize){
	__SAFE_POINT
	::cpp::zip::Uncompress u = ::cpp::zip::Uncompress_obj::__new(null());
	if ((bufsize == null()))
		bufsize = 65536;
	::haxe::io::Bytes tmp = ::haxe::io::Bytes_obj::alloc(bufsize);
	::haxe::io::BytesBuffer b = ::haxe::io::BytesBuffer_obj::__new();
	int pos = 0;
	u->setFlushMode(::cpp::zip::Flush_obj::SYNC);
	while(true){
		__SAFE_POINT
		Dynamic r = u->this_run(src,pos,tmp,0);
		{
			int len = r->__Field(HX_STRING(L"write",5)).Cast< int >();
			if ((bool((len < 0)) || bool((len > tmp->length))))
				hx::Throw (::haxe::io::Error_obj::OutsideBounds);
			Array< unsigned char > b1 = b->b;
			Array< unsigned char > b2 = tmp->b;
			{
				int _g1 = 0;
				int _g2 = len;
				while((_g1 < _g2)){
					__SAFE_POINT
					int i = _g1++;
					b->b->push(b2->__get(i));
				}
			}
		}
		hx::AddEq(pos,r->__Field(HX_STRING(L"read",4)).Cast< int >());
		if (r->__Field(HX_STRING(L"done",4)).Cast< bool >())
			break;
	}
	u->close();
	return b->getBytes();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(Uncompress_obj,run,return )

Dynamic Uncompress_obj::_inflate_init;

Dynamic Uncompress_obj::_inflate_buffer;

Dynamic Uncompress_obj::_inflate_end;

Dynamic Uncompress_obj::_set_flush_mode;


Uncompress_obj::Uncompress_obj()
{
}

void Uncompress_obj::__Mark()
{
	hx::MarkMember(s);
}

Dynamic Uncompress_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 1:
		if (!memcmp(inName.__s,L"s",sizeof(wchar_t)*1) ) { return s; }
		break;
	case 3:
		if (!memcmp(inName.__s,L"run",sizeof(wchar_t)*3) ) { return run_dyn(); }
		break;
	case 5:
		if (!memcmp(inName.__s,L"close",sizeof(wchar_t)*5) ) { return close_dyn(); }
		break;
	case 8:
		if (!memcmp(inName.__s,L"this_run",sizeof(wchar_t)*8) ) { return this_run_dyn(); }
		break;
	case 12:
		if (!memcmp(inName.__s,L"_inflate_end",sizeof(wchar_t)*12) ) { return _inflate_end; }
		if (!memcmp(inName.__s,L"setFlushMode",sizeof(wchar_t)*12) ) { return setFlushMode_dyn(); }
		break;
	case 13:
		if (!memcmp(inName.__s,L"_inflate_init",sizeof(wchar_t)*13) ) { return _inflate_init; }
		break;
	case 15:
		if (!memcmp(inName.__s,L"_inflate_buffer",sizeof(wchar_t)*15) ) { return _inflate_buffer; }
		if (!memcmp(inName.__s,L"_set_flush_mode",sizeof(wchar_t)*15) ) { return _set_flush_mode; }
	}
	return super::__Field(inName);
}

Dynamic Uncompress_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	switch(inName.length) {
	case 1:
		if (!memcmp(inName.__s,L"s",sizeof(wchar_t)*1) ) { s=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 12:
		if (!memcmp(inName.__s,L"_inflate_end",sizeof(wchar_t)*12) ) { _inflate_end=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 13:
		if (!memcmp(inName.__s,L"_inflate_init",sizeof(wchar_t)*13) ) { _inflate_init=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 15:
		if (!memcmp(inName.__s,L"_inflate_buffer",sizeof(wchar_t)*15) ) { _inflate_buffer=inValue.Cast< Dynamic >(); return inValue; }
		if (!memcmp(inName.__s,L"_set_flush_mode",sizeof(wchar_t)*15) ) { _set_flush_mode=inValue.Cast< Dynamic >(); return inValue; }
	}
	return super::__SetField(inName,inValue);
}

void Uncompress_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_STRING(L"s",1));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_STRING(L"run",3),
	HX_STRING(L"_inflate_init",13),
	HX_STRING(L"_inflate_buffer",15),
	HX_STRING(L"_inflate_end",12),
	HX_STRING(L"_set_flush_mode",15),
	String(null()) };

static ::String sMemberFields[] = {
	HX_STRING(L"s",1),
	HX_STRING(L"this_run",8),
	HX_STRING(L"setFlushMode",12),
	HX_STRING(L"close",5),
	String(null()) };

static void sMarkStatics() {
	hx::MarkMember(Uncompress_obj::_inflate_init);
	hx::MarkMember(Uncompress_obj::_inflate_buffer);
	hx::MarkMember(Uncompress_obj::_inflate_end);
	hx::MarkMember(Uncompress_obj::_set_flush_mode);
};

Class Uncompress_obj::__mClass;

void Uncompress_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_STRING(L"cpp.zip.Uncompress",18), hx::TCanCast< Uncompress_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void Uncompress_obj::__boot()
{
	hx::Static(_inflate_init) = ::cpp::Lib_obj::load(HX_STRING(L"zlib",4),HX_STRING(L"inflate_init",12),1);
	hx::Static(_inflate_buffer) = ::cpp::Lib_obj::load(HX_STRING(L"zlib",4),HX_STRING(L"inflate_buffer",14),5);
	hx::Static(_inflate_end) = ::cpp::Lib_obj::load(HX_STRING(L"zlib",4),HX_STRING(L"inflate_end",11),1);
	hx::Static(_set_flush_mode) = ::cpp::Lib_obj::load(HX_STRING(L"zlib",4),HX_STRING(L"set_flush_mode",14),2);
}

} // end namespace cpp
} // end namespace zip
