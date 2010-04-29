#include <hxcpp.h>

#ifndef INCLUDED_cpp_Lib
#include <cpp/Lib.h>
#endif
#ifndef INCLUDED_cpp_net_SocketOutput
#include <cpp/net/SocketOutput.h>
#endif
#ifndef INCLUDED_haxe_io_Bytes
#include <haxe/io/Bytes.h>
#endif
#ifndef INCLUDED_haxe_io_Error
#include <haxe/io/Error.h>
#endif
#ifndef INCLUDED_haxe_io_Output
#include <haxe/io/Output.h>
#endif
namespace cpp{
namespace net{

Void SocketOutput_obj::__construct(Dynamic s)
{
{
	this->__s = s;
}
;
	return null();
}

SocketOutput_obj::~SocketOutput_obj() { }

Dynamic SocketOutput_obj::__CreateEmpty() { return  new SocketOutput_obj; }
hx::ObjectPtr< SocketOutput_obj > SocketOutput_obj::__new(Dynamic s)
{  hx::ObjectPtr< SocketOutput_obj > result = new SocketOutput_obj();
	result->__construct(s);
	return result;}

Dynamic SocketOutput_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< SocketOutput_obj > result = new SocketOutput_obj();
	result->__construct(inArgs[0]);
	return result;}

Void SocketOutput_obj::writeByte( int c){
{
		__SAFE_POINT
		try{
			::cpp::net::SocketOutput_obj::socket_send_char(this->__s,c);
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
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(SocketOutput_obj,writeByte,(void))

int SocketOutput_obj::writeBytes( ::haxe::io::Bytes buf,int pos,int len){
	__SAFE_POINT
	struct _Function_1_1{
		inline static int Block( ::cpp::net::SocketOutput_obj *__this,::haxe::io::Bytes &buf,int &pos,int &len)/* DEF (not block)(ret intern) */{
			try{
				return ::cpp::net::SocketOutput_obj::socket_send(__this->__s,buf->b,pos,len);
			}
			catch(Dynamic __e){
				{
					Dynamic e = __e;{
						return (e == HX_STRING(L"Blocking",8)) ? int( hx::Throw (::haxe::io::Error_obj::Blocked) ) : int( hx::Throw (::haxe::io::Error_obj::Custom(e)) );
					}
				}
			}
		}
	};
	return _Function_1_1::Block(this,buf,pos,len);
}


HX_DEFINE_DYNAMIC_FUNC3(SocketOutput_obj,writeBytes,return )

Void SocketOutput_obj::close( ){
{
		__SAFE_POINT
		this->super::close();
		if ((this->__s != null()))
			::cpp::net::SocketOutput_obj::socket_close(this->__s);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(SocketOutput_obj,close,(void))

Dynamic SocketOutput_obj::socket_close;

Dynamic SocketOutput_obj::socket_send_char;

Dynamic SocketOutput_obj::socket_send;


SocketOutput_obj::SocketOutput_obj()
{
}

void SocketOutput_obj::__Mark()
{
	hx::MarkMember(__s);
	super::__Mark();
}

Dynamic SocketOutput_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 3:
		if (!memcmp(inName.__s,L"__s",sizeof(wchar_t)*3) ) { return __s; }
		break;
	case 5:
		if (!memcmp(inName.__s,L"close",sizeof(wchar_t)*5) ) { return close_dyn(); }
		break;
	case 9:
		if (!memcmp(inName.__s,L"writeByte",sizeof(wchar_t)*9) ) { return writeByte_dyn(); }
		break;
	case 10:
		if (!memcmp(inName.__s,L"writeBytes",sizeof(wchar_t)*10) ) { return writeBytes_dyn(); }
		break;
	case 11:
		if (!memcmp(inName.__s,L"socket_send",sizeof(wchar_t)*11) ) { return socket_send; }
		break;
	case 12:
		if (!memcmp(inName.__s,L"socket_close",sizeof(wchar_t)*12) ) { return socket_close; }
		break;
	case 16:
		if (!memcmp(inName.__s,L"socket_send_char",sizeof(wchar_t)*16) ) { return socket_send_char; }
	}
	return super::__Field(inName);
}

Dynamic SocketOutput_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	switch(inName.length) {
	case 3:
		if (!memcmp(inName.__s,L"__s",sizeof(wchar_t)*3) ) { __s=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 11:
		if (!memcmp(inName.__s,L"socket_send",sizeof(wchar_t)*11) ) { socket_send=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 12:
		if (!memcmp(inName.__s,L"socket_close",sizeof(wchar_t)*12) ) { socket_close=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 16:
		if (!memcmp(inName.__s,L"socket_send_char",sizeof(wchar_t)*16) ) { socket_send_char=inValue.Cast< Dynamic >(); return inValue; }
	}
	return super::__SetField(inName,inValue);
}

void SocketOutput_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_STRING(L"__s",3));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_STRING(L"socket_close",12),
	HX_STRING(L"socket_send_char",16),
	HX_STRING(L"socket_send",11),
	String(null()) };

static ::String sMemberFields[] = {
	HX_STRING(L"__s",3),
	HX_STRING(L"writeByte",9),
	HX_STRING(L"writeBytes",10),
	HX_STRING(L"close",5),
	String(null()) };

static void sMarkStatics() {
	hx::MarkMember(SocketOutput_obj::socket_close);
	hx::MarkMember(SocketOutput_obj::socket_send_char);
	hx::MarkMember(SocketOutput_obj::socket_send);
};

Class SocketOutput_obj::__mClass;

void SocketOutput_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_STRING(L"cpp.net.SocketOutput",20), hx::TCanCast< SocketOutput_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void SocketOutput_obj::__boot()
{
	hx::Static(socket_close) = ::cpp::Lib_obj::load(HX_STRING(L"std",3),HX_STRING(L"socket_close",12),1);
	hx::Static(socket_send_char) = ::cpp::Lib_obj::load(HX_STRING(L"std",3),HX_STRING(L"socket_send_char",16),2);
	hx::Static(socket_send) = ::cpp::Lib_obj::load(HX_STRING(L"std",3),HX_STRING(L"socket_send",11),4);
}

} // end namespace cpp
} // end namespace net
