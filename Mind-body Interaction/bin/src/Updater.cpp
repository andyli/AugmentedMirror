#include <hxcpp.h>

#ifndef INCLUDED_Std
#include <Std.h>
#endif
#ifndef INCLUDED_Updater
#include <Updater.h>
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
#ifndef INCLUDED_cpp_vm_Thread
#include <cpp/vm/Thread.h>
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
#ifndef INCLUDED_neash_events_Event
#include <neash/events/Event.h>
#endif

Void Updater_obj::__construct(::String socketUrlAndPort,Dynamic __o_readyByte)
{
int readyByte = __o_readyByte.Default(8);
{
	this->readyByte = readyByte;
	Array< ::String > parts = socketUrlAndPort.split(HX_STRING(L":",1));
	if ((parts->length >= 2)){
		this->host = parts->__get(0);
		this->port = ::Std_obj::parseInt(parts->__get(1));
	}
	this->inputSize = 0;
	this->socket = ::cpp::net::Socket_obj::__new(null());
}
;
	return null();
}

Updater_obj::~Updater_obj() { }

Dynamic Updater_obj::__CreateEmpty() { return  new Updater_obj; }
hx::ObjectPtr< Updater_obj > Updater_obj::__new(::String socketUrlAndPort,Dynamic __o_readyByte)
{  hx::ObjectPtr< Updater_obj > result = new Updater_obj();
	result->__construct(socketUrlAndPort,__o_readyByte);
	return result;}

Dynamic Updater_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Updater_obj > result = new Updater_obj();
	result->__construct(inArgs[0],inArgs[1]);
	return result;}

Void Updater_obj::start( ){
{
		__SAFE_POINT
		this->temp = ::haxe::io::Bytes_obj::alloc(this->inputSize);
		this->socket->connect(::cpp::net::Host_obj::__new(this->host),this->port);
		this->socket->setBlocking(true);
		::cpp::vm::Thread_obj::create(this->threadFunction_dyn());
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Updater_obj,start,(void))

Void Updater_obj::updateTarget( ::haxe::io::Bytes bytes){
{
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Updater_obj,updateTarget,(void))

Void Updater_obj::threadFunction( ){
{
		__SAFE_POINT
		while(true){
			__SAFE_POINT
			this->onEnterframe(null());
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Updater_obj,threadFunction,(void))

Void Updater_obj::onEnterframe( ::neash::events::Event e){
{
		__SAFE_POINT
		try{
			this->socket->output->writeByte(this->readyByte);
			this->socket->input->readFullBytes(this->temp,0,this->inputSize);
			this->updateTarget(this->temp);
		}
		catch(Dynamic __e){
			{
				Dynamic s = __e;{
				}
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Updater_obj,onEnterframe,(void))


Updater_obj::Updater_obj()
{
}

void Updater_obj::__Mark()
{
	hx::MarkMember(host);
	hx::MarkMember(port);
	hx::MarkMember(socket);
	hx::MarkMember(readyByte);
	hx::MarkMember(inputSize);
	hx::MarkMember(temp);
}

Dynamic Updater_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 4:
		if (!memcmp(inName.__s,L"host",sizeof(wchar_t)*4) ) { return host; }
		if (!memcmp(inName.__s,L"port",sizeof(wchar_t)*4) ) { return port; }
		if (!memcmp(inName.__s,L"temp",sizeof(wchar_t)*4) ) { return temp; }
		break;
	case 5:
		if (!memcmp(inName.__s,L"start",sizeof(wchar_t)*5) ) { return start_dyn(); }
		break;
	case 6:
		if (!memcmp(inName.__s,L"socket",sizeof(wchar_t)*6) ) { return socket; }
		break;
	case 9:
		if (!memcmp(inName.__s,L"readyByte",sizeof(wchar_t)*9) ) { return readyByte; }
		if (!memcmp(inName.__s,L"inputSize",sizeof(wchar_t)*9) ) { return inputSize; }
		break;
	case 12:
		if (!memcmp(inName.__s,L"updateTarget",sizeof(wchar_t)*12) ) { return updateTarget_dyn(); }
		if (!memcmp(inName.__s,L"onEnterframe",sizeof(wchar_t)*12) ) { return onEnterframe_dyn(); }
		break;
	case 14:
		if (!memcmp(inName.__s,L"threadFunction",sizeof(wchar_t)*14) ) { return threadFunction_dyn(); }
	}
	return super::__Field(inName);
}

Dynamic Updater_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	switch(inName.length) {
	case 4:
		if (!memcmp(inName.__s,L"host",sizeof(wchar_t)*4) ) { host=inValue.Cast< ::String >(); return inValue; }
		if (!memcmp(inName.__s,L"port",sizeof(wchar_t)*4) ) { port=inValue.Cast< int >(); return inValue; }
		if (!memcmp(inName.__s,L"temp",sizeof(wchar_t)*4) ) { temp=inValue.Cast< ::haxe::io::Bytes >(); return inValue; }
		break;
	case 6:
		if (!memcmp(inName.__s,L"socket",sizeof(wchar_t)*6) ) { socket=inValue.Cast< ::cpp::net::Socket >(); return inValue; }
		break;
	case 9:
		if (!memcmp(inName.__s,L"readyByte",sizeof(wchar_t)*9) ) { readyByte=inValue.Cast< int >(); return inValue; }
		if (!memcmp(inName.__s,L"inputSize",sizeof(wchar_t)*9) ) { inputSize=inValue.Cast< int >(); return inValue; }
	}
	return super::__SetField(inName,inValue);
}

void Updater_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_STRING(L"host",4));
	outFields->push(HX_STRING(L"port",4));
	outFields->push(HX_STRING(L"socket",6));
	outFields->push(HX_STRING(L"readyByte",9));
	outFields->push(HX_STRING(L"inputSize",9));
	outFields->push(HX_STRING(L"temp",4));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_STRING(L"host",4),
	HX_STRING(L"port",4),
	HX_STRING(L"socket",6),
	HX_STRING(L"readyByte",9),
	HX_STRING(L"inputSize",9),
	HX_STRING(L"temp",4),
	HX_STRING(L"start",5),
	HX_STRING(L"updateTarget",12),
	HX_STRING(L"threadFunction",14),
	HX_STRING(L"onEnterframe",12),
	String(null()) };

static void sMarkStatics() {
};

Class Updater_obj::__mClass;

void Updater_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_STRING(L"Updater",7), hx::TCanCast< Updater_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void Updater_obj::__boot()
{
}

