#include <hxcpp.h>

#ifndef INCLUDED_cpp_CppInt32__
#include <cpp/CppInt32__.h>
#endif
#ifndef INCLUDED_cpp_Lib
#include <cpp/Lib.h>
#endif
#ifndef INCLUDED_cpp_net_Host
#include <cpp/net/Host.h>
#endif
#ifndef INCLUDED_cpp_net_Socket
#include <cpp/net/Socket.h>
#endif
#ifndef INCLUDED_cpp_net_SocketInput
#include <cpp/net/SocketInput.h>
#endif
#ifndef INCLUDED_cpp_net_SocketOutput
#include <cpp/net/SocketOutput.h>
#endif
#ifndef INCLUDED_haxe_io_Bytes
#include <haxe/io/Bytes.h>
#endif
#ifndef INCLUDED_haxe_io_Input
#include <haxe/io/Input.h>
#endif
#ifndef INCLUDED_haxe_io_Output
#include <haxe/io/Output.h>
#endif
namespace cpp{
namespace net{

Void Socket_obj::__construct(Dynamic s)
{
{
	this->__s = (s == null()) ? Dynamic( ::cpp::net::Socket_obj::socket_new(false) ) : Dynamic( s );
	this->input = ::cpp::net::SocketInput_obj::__new(this->__s);
	this->output = ::cpp::net::SocketOutput_obj::__new(this->__s);
}
;
	return null();
}

Socket_obj::~Socket_obj() { }

Dynamic Socket_obj::__CreateEmpty() { return  new Socket_obj; }
hx::ObjectPtr< Socket_obj > Socket_obj::__new(Dynamic s)
{  hx::ObjectPtr< Socket_obj > result = new Socket_obj();
	result->__construct(s);
	return result;}

Dynamic Socket_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Socket_obj > result = new Socket_obj();
	result->__construct(inArgs[0]);
	return result;}

Void Socket_obj::close( ){
{
		__SAFE_POINT
		::cpp::net::Socket_obj::socket_close(this->__s);
		{
			this->input->__s = null();
			this->output->__s = null();
		}
		this->input->close();
		this->output->close();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Socket_obj,close,(void))

::String Socket_obj::read( ){
	__SAFE_POINT
	Array< unsigned char > bytes = ::cpp::net::Socket_obj::socket_read(this->__s);
	if ((bytes == null()))
		return HX_STRING(L"",0);
	return bytes->toString();
}


HX_DEFINE_DYNAMIC_FUNC0(Socket_obj,read,return )

Void Socket_obj::write( ::String content){
{
		__SAFE_POINT
		::cpp::net::Socket_obj::socket_write(this->__s,::haxe::io::Bytes_obj::ofString(content)->b);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Socket_obj,write,(void))

Void Socket_obj::connect( ::cpp::net::Host host,int port){
{
		__SAFE_POINT
		try{
			::cpp::net::Socket_obj::socket_connect(this->__s,host->ip,port);
		}
		catch(Dynamic __e){
			if (__e.IsClass< ::String >() ){
				::String s = __e;{
					struct _Function_2_1{
						inline static ::String Block( ::cpp::net::Host &host)/* DEF (not block)(ret intern) */{
							try{
								return host->reverse();
							}
							catch(Dynamic __e){
								{
									Dynamic e = __e;{
										return host->toString();
									}
								}
							}
						}
					};
					if ((s == HX_STRING(L"std@socket_connect",18))){
						struct _Function_3_1{
							inline static ::String Block( ::cpp::net::Host &host)/* DEF (not block)(ret intern) */{
								try{
									return host->reverse();
								}
								catch(Dynamic __e){
									{
										Dynamic e = __e;{
											return host->toString();
										}
									}
								}
							}
						};
						hx::Throw ((((((HX_STRING(L"Failed to connect on ",21) + (_Function_3_1::Block(host)))) + HX_STRING(L":",1))) + port));
					}
					else{
						::cpp::Lib_obj::rethrow(s);
					}
				}
			}
			else throw(__e);
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(Socket_obj,connect,(void))

Void Socket_obj::listen( int connections){
{
		__SAFE_POINT
		::cpp::net::Socket_obj::socket_listen(this->__s,connections);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Socket_obj,listen,(void))

Void Socket_obj::shutdown( bool read,bool write){
{
		__SAFE_POINT
		::cpp::net::Socket_obj::socket_shutdown(this->__s,read,write);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(Socket_obj,shutdown,(void))

Void Socket_obj::bind( ::cpp::net::Host host,int port){
{
		__SAFE_POINT
		::cpp::net::Socket_obj::socket_bind(this->__s,host->ip,port);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(Socket_obj,bind,(void))

::cpp::net::Socket Socket_obj::accept( ){
	__SAFE_POINT
	return ::cpp::net::Socket_obj::__new(::cpp::net::Socket_obj::socket_accept(this->__s));
}


HX_DEFINE_DYNAMIC_FUNC0(Socket_obj,accept,return )

Dynamic Socket_obj::peer( ){
	__SAFE_POINT
	Dynamic a = ::cpp::net::Socket_obj::socket_peer(this->__s);
	::cpp::net::Host h = ::cpp::net::Host_obj::__new(HX_STRING(L"127.0.0.1",9));
	h->ip = a[0];
	struct _Function_1_1{
		inline static Dynamic Block( ::cpp::net::Host &h,Dynamic &a){
			hx::Anon __result = hx::Anon_obj::Create();
			__result->Add(HX_STRING(L"host",4) , h);
			__result->Add(HX_STRING(L"port",4) , a[1]);
			return __result;
		}
	};
	return _Function_1_1::Block(h,a);
}


HX_DEFINE_DYNAMIC_FUNC0(Socket_obj,peer,return )

Dynamic Socket_obj::host( ){
	__SAFE_POINT
	Dynamic a = ::cpp::net::Socket_obj::socket_host(this->__s);
	::cpp::net::Host h = ::cpp::net::Host_obj::__new(HX_STRING(L"127.0.0.1",9));
	h->ip = a[0];
	struct _Function_1_1{
		inline static Dynamic Block( ::cpp::net::Host &h,Dynamic &a){
			hx::Anon __result = hx::Anon_obj::Create();
			__result->Add(HX_STRING(L"host",4) , h);
			__result->Add(HX_STRING(L"port",4) , a[1]);
			return __result;
		}
	};
	return _Function_1_1::Block(h,a);
}


HX_DEFINE_DYNAMIC_FUNC0(Socket_obj,host,return )

Void Socket_obj::setTimeout( double timeout){
{
		__SAFE_POINT
		::cpp::net::Socket_obj::socket_set_timeout(this->__s,timeout);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Socket_obj,setTimeout,(void))

Void Socket_obj::waitForRead( ){
{
		__SAFE_POINT
		::cpp::net::Socket_obj::select(Array_obj< ::cpp::net::Socket >::__new().Add(this),null(),null(),null());
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Socket_obj,waitForRead,(void))

Void Socket_obj::setBlocking( bool b){
{
		__SAFE_POINT
		::cpp::net::Socket_obj::socket_set_blocking(this->__s,b);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Socket_obj,setBlocking,(void))

::cpp::net::Socket Socket_obj::newUdpSocket( ){
	__SAFE_POINT
	return ::cpp::net::Socket_obj::__new(::cpp::net::Socket_obj::socket_new(true));
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(Socket_obj,newUdpSocket,return )

Dynamic Socket_obj::select( Array< ::cpp::net::Socket > read,Array< ::cpp::net::Socket > write,Array< ::cpp::net::Socket > others,double timeout){
	__SAFE_POINT
	Array< Array< ::cpp::net::Socket > > neko_array = ::cpp::net::Socket_obj::socket_select(read,write,others,timeout);
	struct _Function_1_1{
		inline static Dynamic Block( Array< Array< ::cpp::net::Socket > > &neko_array){
			hx::Anon __result = hx::Anon_obj::Create();
			__result->Add(HX_STRING(L"read",4) , neko_array->__get(0));
			__result->Add(HX_STRING(L"write",5) , neko_array->__get(1));
			__result->Add(HX_STRING(L"others",6) , neko_array->__get(2));
			return __result;
		}
	};
	return _Function_1_1::Block(neko_array);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC4(Socket_obj,select,return )

Dynamic Socket_obj::socket_new;

Dynamic Socket_obj::socket_close;

Dynamic Socket_obj::socket_write;

Dynamic Socket_obj::socket_read;

Dynamic Socket_obj::socket_connect;

Dynamic Socket_obj::socket_listen;

Dynamic Socket_obj::socket_select;

Dynamic Socket_obj::socket_bind;

Dynamic Socket_obj::socket_accept;

Dynamic Socket_obj::socket_peer;

Dynamic Socket_obj::socket_host;

Dynamic Socket_obj::socket_set_timeout;

Dynamic Socket_obj::socket_shutdown;

Dynamic Socket_obj::socket_set_blocking;


Socket_obj::Socket_obj()
{
}

void Socket_obj::__Mark()
{
	hx::MarkMember(__s);
	hx::MarkMember(input);
	hx::MarkMember(output);
	hx::MarkMember(custom);
}

Dynamic Socket_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 3:
		if (!memcmp(inName.__s,L"__s",sizeof(wchar_t)*3) ) { return __s; }
		break;
	case 4:
		if (!memcmp(inName.__s,L"read",sizeof(wchar_t)*4) ) { return read_dyn(); }
		if (!memcmp(inName.__s,L"bind",sizeof(wchar_t)*4) ) { return bind_dyn(); }
		if (!memcmp(inName.__s,L"peer",sizeof(wchar_t)*4) ) { return peer_dyn(); }
		if (!memcmp(inName.__s,L"host",sizeof(wchar_t)*4) ) { return host_dyn(); }
		break;
	case 5:
		if (!memcmp(inName.__s,L"input",sizeof(wchar_t)*5) ) { return input; }
		if (!memcmp(inName.__s,L"close",sizeof(wchar_t)*5) ) { return close_dyn(); }
		if (!memcmp(inName.__s,L"write",sizeof(wchar_t)*5) ) { return write_dyn(); }
		break;
	case 6:
		if (!memcmp(inName.__s,L"select",sizeof(wchar_t)*6) ) { return select_dyn(); }
		if (!memcmp(inName.__s,L"output",sizeof(wchar_t)*6) ) { return output; }
		if (!memcmp(inName.__s,L"custom",sizeof(wchar_t)*6) ) { return custom; }
		if (!memcmp(inName.__s,L"listen",sizeof(wchar_t)*6) ) { return listen_dyn(); }
		if (!memcmp(inName.__s,L"accept",sizeof(wchar_t)*6) ) { return accept_dyn(); }
		break;
	case 7:
		if (!memcmp(inName.__s,L"connect",sizeof(wchar_t)*7) ) { return connect_dyn(); }
		break;
	case 8:
		if (!memcmp(inName.__s,L"shutdown",sizeof(wchar_t)*8) ) { return shutdown_dyn(); }
		break;
	case 10:
		if (!memcmp(inName.__s,L"socket_new",sizeof(wchar_t)*10) ) { return socket_new; }
		if (!memcmp(inName.__s,L"setTimeout",sizeof(wchar_t)*10) ) { return setTimeout_dyn(); }
		break;
	case 11:
		if (!memcmp(inName.__s,L"socket_read",sizeof(wchar_t)*11) ) { return socket_read; }
		if (!memcmp(inName.__s,L"socket_bind",sizeof(wchar_t)*11) ) { return socket_bind; }
		if (!memcmp(inName.__s,L"socket_peer",sizeof(wchar_t)*11) ) { return socket_peer; }
		if (!memcmp(inName.__s,L"socket_host",sizeof(wchar_t)*11) ) { return socket_host; }
		if (!memcmp(inName.__s,L"waitForRead",sizeof(wchar_t)*11) ) { return waitForRead_dyn(); }
		if (!memcmp(inName.__s,L"setBlocking",sizeof(wchar_t)*11) ) { return setBlocking_dyn(); }
		break;
	case 12:
		if (!memcmp(inName.__s,L"newUdpSocket",sizeof(wchar_t)*12) ) { return newUdpSocket_dyn(); }
		if (!memcmp(inName.__s,L"socket_close",sizeof(wchar_t)*12) ) { return socket_close; }
		if (!memcmp(inName.__s,L"socket_write",sizeof(wchar_t)*12) ) { return socket_write; }
		break;
	case 13:
		if (!memcmp(inName.__s,L"socket_listen",sizeof(wchar_t)*13) ) { return socket_listen; }
		if (!memcmp(inName.__s,L"socket_select",sizeof(wchar_t)*13) ) { return socket_select; }
		if (!memcmp(inName.__s,L"socket_accept",sizeof(wchar_t)*13) ) { return socket_accept; }
		break;
	case 14:
		if (!memcmp(inName.__s,L"socket_connect",sizeof(wchar_t)*14) ) { return socket_connect; }
		break;
	case 15:
		if (!memcmp(inName.__s,L"socket_shutdown",sizeof(wchar_t)*15) ) { return socket_shutdown; }
		break;
	case 18:
		if (!memcmp(inName.__s,L"socket_set_timeout",sizeof(wchar_t)*18) ) { return socket_set_timeout; }
		break;
	case 19:
		if (!memcmp(inName.__s,L"socket_set_blocking",sizeof(wchar_t)*19) ) { return socket_set_blocking; }
	}
	return super::__Field(inName);
}

Dynamic Socket_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	switch(inName.length) {
	case 3:
		if (!memcmp(inName.__s,L"__s",sizeof(wchar_t)*3) ) { __s=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 5:
		if (!memcmp(inName.__s,L"input",sizeof(wchar_t)*5) ) { input=inValue.Cast< ::cpp::net::SocketInput >(); return inValue; }
		break;
	case 6:
		if (!memcmp(inName.__s,L"output",sizeof(wchar_t)*6) ) { output=inValue.Cast< ::cpp::net::SocketOutput >(); return inValue; }
		if (!memcmp(inName.__s,L"custom",sizeof(wchar_t)*6) ) { custom=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 10:
		if (!memcmp(inName.__s,L"socket_new",sizeof(wchar_t)*10) ) { socket_new=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 11:
		if (!memcmp(inName.__s,L"socket_read",sizeof(wchar_t)*11) ) { socket_read=inValue.Cast< Dynamic >(); return inValue; }
		if (!memcmp(inName.__s,L"socket_bind",sizeof(wchar_t)*11) ) { socket_bind=inValue.Cast< Dynamic >(); return inValue; }
		if (!memcmp(inName.__s,L"socket_peer",sizeof(wchar_t)*11) ) { socket_peer=inValue.Cast< Dynamic >(); return inValue; }
		if (!memcmp(inName.__s,L"socket_host",sizeof(wchar_t)*11) ) { socket_host=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 12:
		if (!memcmp(inName.__s,L"socket_close",sizeof(wchar_t)*12) ) { socket_close=inValue.Cast< Dynamic >(); return inValue; }
		if (!memcmp(inName.__s,L"socket_write",sizeof(wchar_t)*12) ) { socket_write=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 13:
		if (!memcmp(inName.__s,L"socket_listen",sizeof(wchar_t)*13) ) { socket_listen=inValue.Cast< Dynamic >(); return inValue; }
		if (!memcmp(inName.__s,L"socket_select",sizeof(wchar_t)*13) ) { socket_select=inValue.Cast< Dynamic >(); return inValue; }
		if (!memcmp(inName.__s,L"socket_accept",sizeof(wchar_t)*13) ) { socket_accept=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 14:
		if (!memcmp(inName.__s,L"socket_connect",sizeof(wchar_t)*14) ) { socket_connect=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 15:
		if (!memcmp(inName.__s,L"socket_shutdown",sizeof(wchar_t)*15) ) { socket_shutdown=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 18:
		if (!memcmp(inName.__s,L"socket_set_timeout",sizeof(wchar_t)*18) ) { socket_set_timeout=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 19:
		if (!memcmp(inName.__s,L"socket_set_blocking",sizeof(wchar_t)*19) ) { socket_set_blocking=inValue.Cast< Dynamic >(); return inValue; }
	}
	return super::__SetField(inName,inValue);
}

void Socket_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_STRING(L"__s",3));
	outFields->push(HX_STRING(L"input",5));
	outFields->push(HX_STRING(L"output",6));
	outFields->push(HX_STRING(L"custom",6));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_STRING(L"newUdpSocket",12),
	HX_STRING(L"select",6),
	HX_STRING(L"socket_new",10),
	HX_STRING(L"socket_close",12),
	HX_STRING(L"socket_write",12),
	HX_STRING(L"socket_read",11),
	HX_STRING(L"socket_connect",14),
	HX_STRING(L"socket_listen",13),
	HX_STRING(L"socket_select",13),
	HX_STRING(L"socket_bind",11),
	HX_STRING(L"socket_accept",13),
	HX_STRING(L"socket_peer",11),
	HX_STRING(L"socket_host",11),
	HX_STRING(L"socket_set_timeout",18),
	HX_STRING(L"socket_shutdown",15),
	HX_STRING(L"socket_set_blocking",19),
	String(null()) };

static ::String sMemberFields[] = {
	HX_STRING(L"__s",3),
	HX_STRING(L"input",5),
	HX_STRING(L"output",6),
	HX_STRING(L"custom",6),
	HX_STRING(L"close",5),
	HX_STRING(L"read",4),
	HX_STRING(L"write",5),
	HX_STRING(L"connect",7),
	HX_STRING(L"listen",6),
	HX_STRING(L"shutdown",8),
	HX_STRING(L"bind",4),
	HX_STRING(L"accept",6),
	HX_STRING(L"peer",4),
	HX_STRING(L"host",4),
	HX_STRING(L"setTimeout",10),
	HX_STRING(L"waitForRead",11),
	HX_STRING(L"setBlocking",11),
	String(null()) };

static void sMarkStatics() {
	hx::MarkMember(Socket_obj::socket_new);
	hx::MarkMember(Socket_obj::socket_close);
	hx::MarkMember(Socket_obj::socket_write);
	hx::MarkMember(Socket_obj::socket_read);
	hx::MarkMember(Socket_obj::socket_connect);
	hx::MarkMember(Socket_obj::socket_listen);
	hx::MarkMember(Socket_obj::socket_select);
	hx::MarkMember(Socket_obj::socket_bind);
	hx::MarkMember(Socket_obj::socket_accept);
	hx::MarkMember(Socket_obj::socket_peer);
	hx::MarkMember(Socket_obj::socket_host);
	hx::MarkMember(Socket_obj::socket_set_timeout);
	hx::MarkMember(Socket_obj::socket_shutdown);
	hx::MarkMember(Socket_obj::socket_set_blocking);
};

Class Socket_obj::__mClass;

void Socket_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_STRING(L"cpp.net.Socket",14), hx::TCanCast< Socket_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void Socket_obj::__boot()
{
	hx::Static(socket_new) = ::cpp::Lib_obj::load(HX_STRING(L"std",3),HX_STRING(L"socket_new",10),1);
	hx::Static(socket_close) = ::cpp::Lib_obj::load(HX_STRING(L"std",3),HX_STRING(L"socket_close",12),1);
	hx::Static(socket_write) = ::cpp::Lib_obj::load(HX_STRING(L"std",3),HX_STRING(L"socket_write",12),2);
	hx::Static(socket_read) = ::cpp::Lib_obj::load(HX_STRING(L"std",3),HX_STRING(L"socket_read",11),1);
	hx::Static(socket_connect) = ::cpp::Lib_obj::load(HX_STRING(L"std",3),HX_STRING(L"socket_connect",14),3);
	hx::Static(socket_listen) = ::cpp::Lib_obj::load(HX_STRING(L"std",3),HX_STRING(L"socket_listen",13),2);
	hx::Static(socket_select) = ::cpp::Lib_obj::load(HX_STRING(L"std",3),HX_STRING(L"socket_select",13),4);
	hx::Static(socket_bind) = ::cpp::Lib_obj::load(HX_STRING(L"std",3),HX_STRING(L"socket_bind",11),3);
	hx::Static(socket_accept) = ::cpp::Lib_obj::load(HX_STRING(L"std",3),HX_STRING(L"socket_accept",13),1);
	hx::Static(socket_peer) = ::cpp::Lib_obj::load(HX_STRING(L"std",3),HX_STRING(L"socket_peer",11),1);
	hx::Static(socket_host) = ::cpp::Lib_obj::load(HX_STRING(L"std",3),HX_STRING(L"socket_host",11),1);
	hx::Static(socket_set_timeout) = ::cpp::Lib_obj::load(HX_STRING(L"std",3),HX_STRING(L"socket_set_timeout",18),2);
	hx::Static(socket_shutdown) = ::cpp::Lib_obj::load(HX_STRING(L"std",3),HX_STRING(L"socket_shutdown",15),3);
	hx::Static(socket_set_blocking) = ::cpp::Lib_obj::load(HX_STRING(L"std",3),HX_STRING(L"socket_set_blocking",19),2);
}

} // end namespace cpp
} // end namespace net
