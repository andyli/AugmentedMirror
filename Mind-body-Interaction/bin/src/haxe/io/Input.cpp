#include <hxcpp.h>

#ifndef INCLUDED_StringBuf
#include <StringBuf.h>
#endif
#ifndef INCLUDED_cpp_CppInt32__
#include <cpp/CppInt32__.h>
#endif
#ifndef INCLUDED_cpp_Lib
#include <cpp/Lib.h>
#endif
#ifndef INCLUDED_haxe_io_Bytes
#include <haxe/io/Bytes.h>
#endif
#ifndef INCLUDED_haxe_io_BytesBuffer
#include <haxe/io/BytesBuffer.h>
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

Void Input_obj::__construct()
{
	return null();
}

Input_obj::~Input_obj() { }

Dynamic Input_obj::__CreateEmpty() { return  new Input_obj; }
hx::ObjectPtr< Input_obj > Input_obj::__new()
{  hx::ObjectPtr< Input_obj > result = new Input_obj();
	result->__construct();
	return result;}

Dynamic Input_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Input_obj > result = new Input_obj();
	result->__construct();
	return result;}

int Input_obj::readByte( ){
	hx::Throw (HX_STRING(L"Not implemented",15));
	return 0;
}


HX_DEFINE_DYNAMIC_FUNC0(Input_obj,readByte,return )

int Input_obj::readBytes( ::haxe::io::Bytes s,int pos,int len){
	__SAFE_POINT
	int k = len;
	Array< unsigned char > b = s->b;
	if ((bool((pos < 0)) || bool((bool((len < 0)) || bool(((pos + len) > s->length))))))
		hx::Throw (::haxe::io::Error_obj::OutsideBounds);
	while((k > 0)){
		__SAFE_POINT
		b[pos] = this->readByte();
		pos++;
		k--;
	}
	return len;
}


HX_DEFINE_DYNAMIC_FUNC3(Input_obj,readBytes,return )

Void Input_obj::close( ){
{
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Input_obj,close,(void))

bool Input_obj::setEndian( bool b){
	this->bigEndian = b;
	return b;
}


HX_DEFINE_DYNAMIC_FUNC1(Input_obj,setEndian,return )

::haxe::io::Bytes Input_obj::readAll( Dynamic bufsize){
	__SAFE_POINT
	if ((bufsize == null()))
		bufsize = 16384;
	::haxe::io::Bytes buf = ::haxe::io::Bytes_obj::alloc(bufsize);
	::haxe::io::BytesBuffer total = ::haxe::io::BytesBuffer_obj::__new();
	try{
		while(true){
			__SAFE_POINT
			int len = this->readBytes(buf,0,bufsize);
			if ((len == 0))
				hx::Throw (::haxe::io::Error_obj::Blocked);
			{
				if ((bool((len < 0)) || bool((len > buf->length))))
					hx::Throw (::haxe::io::Error_obj::OutsideBounds);
				Array< unsigned char > b1 = total->b;
				Array< unsigned char > b2 = buf->b;
				{
					int _g1 = 0;
					int _g2 = len;
					while((_g1 < _g2)){
						__SAFE_POINT
						int i = _g1++;
						total->b->push(b2->__get(i));
					}
				}
			}
		}
	}
	catch(Dynamic __e){
		if (__e.IsClass< ::haxe::io::Eof >() ){
			::haxe::io::Eof e = __e;{
			}
		}
		else throw(__e);
	}
	return total->getBytes();
}


HX_DEFINE_DYNAMIC_FUNC1(Input_obj,readAll,return )

Void Input_obj::readFullBytes( ::haxe::io::Bytes s,int pos,int len){
{
		__SAFE_POINT
		while((len > 0)){
			__SAFE_POINT
			int k = this->readBytes(s,pos,len);
			hx::AddEq(pos,k);
			hx::SubEq(len,k);
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC3(Input_obj,readFullBytes,(void))

::haxe::io::Bytes Input_obj::read( int nbytes){
	__SAFE_POINT
	::haxe::io::Bytes s = ::haxe::io::Bytes_obj::alloc(nbytes);
	int p = 0;
	while((nbytes > 0)){
		__SAFE_POINT
		int k = this->readBytes(s,p,nbytes);
		if ((k == 0))
			hx::Throw (::haxe::io::Error_obj::Blocked);
		hx::AddEq(p,k);
		hx::SubEq(nbytes,k);
	}
	return s;
}


HX_DEFINE_DYNAMIC_FUNC1(Input_obj,read,return )

::String Input_obj::readUntil( int end){
	__SAFE_POINT
	::StringBuf buf = ::StringBuf_obj::__new();
	int last;
	while(((last = this->readByte()) != end))buf->b[buf->b->length] = ::String::fromCharCode(last);
	return buf->b->join(HX_STRING(L"",0));
}


HX_DEFINE_DYNAMIC_FUNC1(Input_obj,readUntil,return )

::String Input_obj::readLine( ){
	__SAFE_POINT
	::StringBuf buf = ::StringBuf_obj::__new();
	int last;
	::String s;
	try{
		while(((last = this->readByte()) != 10))buf->b[buf->b->length] = ::String::fromCharCode(last);
		s = buf->b->join(HX_STRING(L"",0));
		if ((s.charCodeAt((s.length - 1)) == 13))
			s = s.substr(0,-1);
	}
	catch(Dynamic __e){
		if (__e.IsClass< ::haxe::io::Eof >() ){
			::haxe::io::Eof e = __e;{
				s = buf->b->join(HX_STRING(L"",0));
				if ((s.length == 0))
					hx::Throw ((e));
			}
		}
		else throw(__e);
	}
	return s;
}


HX_DEFINE_DYNAMIC_FUNC0(Input_obj,readLine,return )

double Input_obj::readFloat( ){
	__SAFE_POINT
	return ::haxe::io::Input_obj::_float_of_bytes(this->read(4)->b,this->bigEndian);
}


HX_DEFINE_DYNAMIC_FUNC0(Input_obj,readFloat,return )

double Input_obj::readDouble( ){
	__SAFE_POINT
	return ::haxe::io::Input_obj::_double_of_bytes(this->read(8)->b,this->bigEndian);
}


HX_DEFINE_DYNAMIC_FUNC0(Input_obj,readDouble,return )

int Input_obj::readInt8( ){
	__SAFE_POINT
	int n = this->readByte();
	if ((n >= 128))
		return (n - 256);
	return n;
}


HX_DEFINE_DYNAMIC_FUNC0(Input_obj,readInt8,return )

int Input_obj::readInt16( ){
	__SAFE_POINT
	int ch1 = this->readByte();
	int ch2 = this->readByte();
	int n = this->bigEndian ? int( (int(ch2) | int(((int(ch1) << int(8))))) ) : int( (int(ch1) | int(((int(ch2) << int(8))))) );
	if (((int(n) & int(32768)) != 0))
		return (n - 65536);
	return n;
}


HX_DEFINE_DYNAMIC_FUNC0(Input_obj,readInt16,return )

int Input_obj::readUInt16( ){
	__SAFE_POINT
	int ch1 = this->readByte();
	int ch2 = this->readByte();
	return this->bigEndian ? int( (int(ch2) | int(((int(ch1) << int(8))))) ) : int( (int(ch1) | int(((int(ch2) << int(8))))) );
}


HX_DEFINE_DYNAMIC_FUNC0(Input_obj,readUInt16,return )

int Input_obj::readInt24( ){
	__SAFE_POINT
	int ch1 = this->readByte();
	int ch2 = this->readByte();
	int ch3 = this->readByte();
	int n = this->bigEndian ? int( (int(((int(ch3) | int(((int(ch2) << int(8))))))) | int(((int(ch1) << int(16))))) ) : int( (int(((int(ch1) | int(((int(ch2) << int(8))))))) | int(((int(ch3) << int(16))))) );
	if (((int(n) & int(8388608)) != 0))
		return (n - 16777216);
	return n;
}


HX_DEFINE_DYNAMIC_FUNC0(Input_obj,readInt24,return )

int Input_obj::readUInt24( ){
	__SAFE_POINT
	int ch1 = this->readByte();
	int ch2 = this->readByte();
	int ch3 = this->readByte();
	return this->bigEndian ? int( (int(((int(ch3) | int(((int(ch2) << int(8))))))) | int(((int(ch1) << int(16))))) ) : int( (int(((int(ch1) | int(((int(ch2) << int(8))))))) | int(((int(ch3) << int(16))))) );
}


HX_DEFINE_DYNAMIC_FUNC0(Input_obj,readUInt24,return )

int Input_obj::readInt31( ){
	__SAFE_POINT
	int ch1;
	int ch2;
	int ch3;
	int ch4;
	if (this->bigEndian){
		ch4 = this->readByte();
		ch3 = this->readByte();
		ch2 = this->readByte();
		ch1 = this->readByte();
	}
	else{
		ch1 = this->readByte();
		ch2 = this->readByte();
		ch3 = this->readByte();
		ch4 = this->readByte();
	}
	if ((((((int(ch4) & int(128))) == 0)) != ((((int(ch4) & int(64))) == 0))))
		hx::Throw (::haxe::io::Error_obj::Overflow);
	return (int(((int(((int(ch1) | int(((int(ch2) << int(8))))))) | int(((int(ch3) << int(16))))))) | int(((int(ch4) << int(24)))));
}


HX_DEFINE_DYNAMIC_FUNC0(Input_obj,readInt31,return )

int Input_obj::readUInt30( ){
	__SAFE_POINT
	int ch1 = this->readByte();
	int ch2 = this->readByte();
	int ch3 = this->readByte();
	int ch4 = this->readByte();
	if (((this->bigEndian ? int( ch1 ) : int( ch4 )) >= 64))
		hx::Throw (::haxe::io::Error_obj::Overflow);
	return this->bigEndian ? int( (int(((int(((int(ch4) | int(((int(ch3) << int(8))))))) | int(((int(ch2) << int(16))))))) | int(((int(ch1) << int(24))))) ) : int( (int(((int(((int(ch1) | int(((int(ch2) << int(8))))))) | int(((int(ch3) << int(16))))))) | int(((int(ch4) << int(24))))) );
}


HX_DEFINE_DYNAMIC_FUNC0(Input_obj,readUInt30,return )

::cpp::CppInt32__ Input_obj::readInt32( ){
	__SAFE_POINT
	int ch1 = this->readByte();
	int ch2 = this->readByte();
	int ch3 = this->readByte();
	int ch4 = this->readByte();
	return this->bigEndian ? ::cpp::CppInt32__( ::cpp::CppInt32___obj::make((int(((int(ch1) << int(8)))) | int(ch2)),(int(((int(ch3) << int(8)))) | int(ch4))) ) : ::cpp::CppInt32__( ::cpp::CppInt32___obj::make((int(((int(ch4) << int(8)))) | int(ch3)),(int(((int(ch2) << int(8)))) | int(ch1))) );
}


HX_DEFINE_DYNAMIC_FUNC0(Input_obj,readInt32,return )

::String Input_obj::readString( int len){
	__SAFE_POINT
	::haxe::io::Bytes b = ::haxe::io::Bytes_obj::alloc(len);
	this->readFullBytes(b,0,len);
	return b->toString();
}


HX_DEFINE_DYNAMIC_FUNC1(Input_obj,readString,return )

Dynamic Input_obj::_float_of_bytes;

Dynamic Input_obj::_double_of_bytes;


Input_obj::Input_obj()
{
}

void Input_obj::__Mark()
{
	hx::MarkMember(bigEndian);
}

Dynamic Input_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 4:
		if (!memcmp(inName.__s,L"read",sizeof(wchar_t)*4) ) { return read_dyn(); }
		break;
	case 5:
		if (!memcmp(inName.__s,L"close",sizeof(wchar_t)*5) ) { return close_dyn(); }
		break;
	case 7:
		if (!memcmp(inName.__s,L"readAll",sizeof(wchar_t)*7) ) { return readAll_dyn(); }
		break;
	case 8:
		if (!memcmp(inName.__s,L"readByte",sizeof(wchar_t)*8) ) { return readByte_dyn(); }
		if (!memcmp(inName.__s,L"readLine",sizeof(wchar_t)*8) ) { return readLine_dyn(); }
		if (!memcmp(inName.__s,L"readInt8",sizeof(wchar_t)*8) ) { return readInt8_dyn(); }
		break;
	case 9:
		if (!memcmp(inName.__s,L"bigEndian",sizeof(wchar_t)*9) ) { return bigEndian; }
		if (!memcmp(inName.__s,L"readBytes",sizeof(wchar_t)*9) ) { return readBytes_dyn(); }
		if (!memcmp(inName.__s,L"setEndian",sizeof(wchar_t)*9) ) { return setEndian_dyn(); }
		if (!memcmp(inName.__s,L"readUntil",sizeof(wchar_t)*9) ) { return readUntil_dyn(); }
		if (!memcmp(inName.__s,L"readFloat",sizeof(wchar_t)*9) ) { return readFloat_dyn(); }
		if (!memcmp(inName.__s,L"readInt16",sizeof(wchar_t)*9) ) { return readInt16_dyn(); }
		if (!memcmp(inName.__s,L"readInt24",sizeof(wchar_t)*9) ) { return readInt24_dyn(); }
		if (!memcmp(inName.__s,L"readInt31",sizeof(wchar_t)*9) ) { return readInt31_dyn(); }
		if (!memcmp(inName.__s,L"readInt32",sizeof(wchar_t)*9) ) { return readInt32_dyn(); }
		break;
	case 10:
		if (!memcmp(inName.__s,L"readDouble",sizeof(wchar_t)*10) ) { return readDouble_dyn(); }
		if (!memcmp(inName.__s,L"readUInt16",sizeof(wchar_t)*10) ) { return readUInt16_dyn(); }
		if (!memcmp(inName.__s,L"readUInt24",sizeof(wchar_t)*10) ) { return readUInt24_dyn(); }
		if (!memcmp(inName.__s,L"readUInt30",sizeof(wchar_t)*10) ) { return readUInt30_dyn(); }
		if (!memcmp(inName.__s,L"readString",sizeof(wchar_t)*10) ) { return readString_dyn(); }
		break;
	case 13:
		if (!memcmp(inName.__s,L"readFullBytes",sizeof(wchar_t)*13) ) { return readFullBytes_dyn(); }
		break;
	case 15:
		if (!memcmp(inName.__s,L"_float_of_bytes",sizeof(wchar_t)*15) ) { return _float_of_bytes; }
		break;
	case 16:
		if (!memcmp(inName.__s,L"_double_of_bytes",sizeof(wchar_t)*16) ) { return _double_of_bytes; }
	}
	return super::__Field(inName);
}

Dynamic Input_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	switch(inName.length) {
	case 9:
		if (!memcmp(inName.__s,L"bigEndian",sizeof(wchar_t)*9) ) { return setEndian(inValue); }
		break;
	case 15:
		if (!memcmp(inName.__s,L"_float_of_bytes",sizeof(wchar_t)*15) ) { _float_of_bytes=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 16:
		if (!memcmp(inName.__s,L"_double_of_bytes",sizeof(wchar_t)*16) ) { _double_of_bytes=inValue.Cast< Dynamic >(); return inValue; }
	}
	return super::__SetField(inName,inValue);
}

void Input_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_STRING(L"bigEndian",9));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_STRING(L"_float_of_bytes",15),
	HX_STRING(L"_double_of_bytes",16),
	String(null()) };

static ::String sMemberFields[] = {
	HX_STRING(L"bigEndian",9),
	HX_STRING(L"readByte",8),
	HX_STRING(L"readBytes",9),
	HX_STRING(L"close",5),
	HX_STRING(L"setEndian",9),
	HX_STRING(L"readAll",7),
	HX_STRING(L"readFullBytes",13),
	HX_STRING(L"read",4),
	HX_STRING(L"readUntil",9),
	HX_STRING(L"readLine",8),
	HX_STRING(L"readFloat",9),
	HX_STRING(L"readDouble",10),
	HX_STRING(L"readInt8",8),
	HX_STRING(L"readInt16",9),
	HX_STRING(L"readUInt16",10),
	HX_STRING(L"readInt24",9),
	HX_STRING(L"readUInt24",10),
	HX_STRING(L"readInt31",9),
	HX_STRING(L"readUInt30",10),
	HX_STRING(L"readInt32",9),
	HX_STRING(L"readString",10),
	String(null()) };

static void sMarkStatics() {
	hx::MarkMember(Input_obj::_float_of_bytes);
	hx::MarkMember(Input_obj::_double_of_bytes);
};

Class Input_obj::__mClass;

void Input_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_STRING(L"haxe.io.Input",13), hx::TCanCast< Input_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void Input_obj::__boot()
{
	hx::Static(_float_of_bytes) = ::cpp::Lib_obj::load(HX_STRING(L"std",3),HX_STRING(L"float_of_bytes",14),2);
	hx::Static(_double_of_bytes) = ::cpp::Lib_obj::load(HX_STRING(L"std",3),HX_STRING(L"double_of_bytes",15),2);
}

} // end namespace haxe
} // end namespace io
