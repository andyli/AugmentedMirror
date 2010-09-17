#include <hxcpp.h>

#ifndef INCLUDED_cpp_Lib
#include <cpp/Lib.h>
#endif
#ifndef INCLUDED_cpp_net_SocketInput
#include <cpp/net/SocketInput.h>
#endif
#ifndef INCLUDED_haxe_io_Bytes
#include <haxe/io/Bytes.h>
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
namespace cpp{
namespace net{

Void SocketInput_obj::__construct(Dynamic s)
{
{
	this->__s = s;
}
;
	return null();
}

SocketInput_obj::~SocketInput_obj() { }

Dynamic SocketInput_obj::__CreateEmpty() { return  new SocketInput_obj; }
hx::ObjectPtr< SocketInput_obj > SocketInput_obj::__new(Dynamic s)
{  hx::ObjectPtr< SocketInput_obj > result = new SocketInput_obj();
	result->__construct(s);
	return result;}

Dynamic SocketInput_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< SocketInput_obj > result = new SocketInput_obj();
	result->__construct(inArgs[0]);
	return result;}

int SocketInput_obj::readByte( ){
	__SAFE_POINT
	struct _Function_1_1{
		inline static int Block( ::cpp::net::SocketInput_obj *__this)/* DEF (not block)(ret intern) */{
			try{
				return ::cpp::net::SocketInput_obj::socket_recv_char(__this->__s);
			}
			catch(Dynamic __e){
				{
					Dynamic e = __e;{
						return (e == HX_STRING(L"Blocking",8)) ? int( hx::Throw (::haxe::io::Error_obj::Blocked) ) : int( (__this->__s == null()) ? int( hx::Throw (::haxe::io::Error_obj::Custom(e)) ) : int( hx::Throw (::haxe::io::Eof_obj::__new()) ) );
					}
				}
			}
		}
	};
	return _Function_1_1::Block(this);
}


HX_DEFINE_DYNAMIC_FUNC0(SocketInput_obj,readByte,return )

int SocketInput_obj::readBytes( ::haxe::io::Bytes buf,int pos,int len){
	__SAFE_POINT
	int r;
	try{
		r = ::cpp::net::SocketInput_obj::socket_recv(this->__s,buf->b,pos,len);
	}
	catch(Dynamic __e){
		{
			Dynamic e = __e;{
				if ((e == HX_STRING(L"Blocking",8))){
					hx::Throw (::haxe::io::Error_obj::Blocked);
				}
				else{
					hx::Throw (::haxe::io::Error_obj::Custom(e));
				}
			}
		}
	}
	if ((r == 0))
		hx::Throw (::haxe::io::Eof_obj::__new());
	return r;
}


HX_DEFINE_DYNAMIC_FUNC3(SocketInput_obj,readBytes,return )

Void SocketInput_obj::close( ){
{
		__SAFE_POINT
		this->super::close();
		if ((this->__s != null()))
			::cpp::net::SocketInput_obj::socket_close(this->__s);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(SocketInput_obj,close,(void))

Dynamic SocketInput_obj::socket_recv;

Dynamic SocketInput_obj::socket_recv_char;

Dynamic SocketInput_obj::socket_close;


SocketInput_obj::SocketInput_obj()
{
}

void SocketInput_obj::__Mark()
{
	hx::MarkMember(__s);
	super::__Mark();
}

Dynamic SocketInput_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 3:
		if (!memcmp(inName.__s,L"__s",sizeof(wchar_t)*3) ) { return __s; }
		break;
	case 5:
		if (!memcmp(inName.__s,L"close",sizeof(wchar_t)*5) ) { return close_dyn(); }
		break;
	case 8:
		if (!memcmp(inName.__s,L"readByte",sizeof(wchar_t)*8) ) { return readByte_dyn(); }
		break;
	case 9:
		if (!memcmp(inName.__s,L"readBytes",sizeof(wchar_t)*9) ) { return readBytes_dyn(); }
		break;
	case 11:
		if (!memcmp(inName.__s,L"socket_recv",sizeof(wchar_t)*11) ) { return socket_recv; }
		break;
	case 12:
		if (!memcmp(inName.__s,L"socket_close",sizeof(wchar_t)*12) ) { return socket_close; }
		break;
	case 16:
		if (!memcmp(inName.__s,L"socket_recv_char",sizeof(wchar_t)*16) ) { return socket_recv_char; }
	}
	return super::__Field(inName);
}

Dynamic SocketInput_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	switch(inName.length) {
	case 3:
		if (!memcmp(inName.__s,L"__s",sizeof(wchar_t)*3) ) { __s=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 11:
		if (!memcmp(inName.__s,L"socket_recv",sizeof(wchar_t)*11) ) { socket_recv=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 12:
		if (!memcmp(inName.__s,L"socket_close",sizeof(wchar_t)*12) ) { socket_close=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 16:
		if (!memcmp(inName.__s,L"socket_recv_char",sizeof(wchar_t)*16) ) { socket_recv_char=inValue.Cast< Dynamic >(); return inValue; }
	}
	return super::__SetField(inName,inValue);
}

void SocketInput_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_STRING(L"__s",3));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_STRING(L"socket_recv",11),
	HX_STRING(L"socket_recv_char",16),
	HX_STRING(L"socket_close",12),
	String(null()) };

static ::String sMemberFields[] = {
	HX_STRING(L"__s",3),
	HX_STRING(L"readByte",8),
	HX_STRING(L"readBytes",9),
	HX_STRING(L"close",5),
	String(null()) };

static void sMarkStatics() {
	hx::MarkMember(SocketInput_obj::socket_recv);
	hx::MarkMember(SocketInput_obj::socket_recv_char);
	hx::MarkMember(SocketInput_obj::socket_close);
};

Class SocketInput_obj::__mClass;

void SocketInput_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_STRING(L"cpp.net.SocketInput",19), hx::TCanCast< SocketInput_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void SocketInput_obj::__boot()
{
	hx::Static(socket_recv) = ::cpp::Lib_obj::load(HX_STRING(L"std",3),HX_STRING(L"socket_recv",11),4);
	hx::Static(socket_recv_char) = ::cpp::Lib_obj::load(HX_STRING(L"std",3),HX_STRING(L"socket_recv_char",16),1);
	hx::Static(socket_close) = ::cpp::Lib_obj::load(HX_STRING(L"std",3),HX_STRING(L"socket_close",12),1);
}

} // end namespace cpp
} // end namespace net
