#include <hxcpp.h>

#ifndef INCLUDED_cpp_CppInt32__
#include <cpp/CppInt32__.h>
#endif
#ifndef INCLUDED_cpp_Lib
#include <cpp/Lib.h>
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
#ifndef INCLUDED_haxe_io_Output
#include <haxe/io/Output.h>
#endif
namespace haxe{
namespace io{

Void Output_obj::__construct()
{
	return null();
}

Output_obj::~Output_obj() { }

Dynamic Output_obj::__CreateEmpty() { return  new Output_obj; }
hx::ObjectPtr< Output_obj > Output_obj::__new()
{  hx::ObjectPtr< Output_obj > result = new Output_obj();
	result->__construct();
	return result;}

Dynamic Output_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Output_obj > result = new Output_obj();
	result->__construct();
	return result;}

Void Output_obj::writeByte( int c){
{
		hx::Throw (HX_STRING(L"Not implemented",15));
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Output_obj,writeByte,(void))

int Output_obj::writeBytes( ::haxe::io::Bytes s,int pos,int len){
	__SAFE_POINT
	int k = len;
	Array< unsigned char > b = s->b;
	if ((bool((pos < 0)) || bool((bool((len < 0)) || bool(((pos + len) > s->length))))))
		hx::Throw (::haxe::io::Error_obj::OutsideBounds);
	while((k > 0)){
		__SAFE_POINT
		this->writeByte(b->__get(pos));
		pos++;
		k--;
	}
	return len;
}


HX_DEFINE_DYNAMIC_FUNC3(Output_obj,writeBytes,return )

Void Output_obj::flush( ){
{
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Output_obj,flush,(void))

Void Output_obj::close( ){
{
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Output_obj,close,(void))

bool Output_obj::setEndian( bool b){
	this->bigEndian = b;
	return b;
}


HX_DEFINE_DYNAMIC_FUNC1(Output_obj,setEndian,return )

Void Output_obj::write( ::haxe::io::Bytes s){
{
		__SAFE_POINT
		int l = s->length;
		int p = 0;
		while((l > 0)){
			__SAFE_POINT
			int k = this->writeBytes(s,p,l);
			if ((k == 0))
				hx::Throw (::haxe::io::Error_obj::Blocked);
			hx::AddEq(p,k);
			hx::SubEq(l,k);
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Output_obj,write,(void))

Void Output_obj::writeFullBytes( ::haxe::io::Bytes s,int pos,int len){
{
		__SAFE_POINT
		while((len > 0)){
			__SAFE_POINT
			int k = this->writeBytes(s,pos,len);
			hx::AddEq(pos,k);
			hx::SubEq(len,k);
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC3(Output_obj,writeFullBytes,(void))

Void Output_obj::writeFloat( double x){
{
		__SAFE_POINT
		this->write(::haxe::io::Bytes_obj::ofData(::haxe::io::Output_obj::_float_bytes(x,this->bigEndian)));
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Output_obj,writeFloat,(void))

Void Output_obj::writeDouble( double x){
{
		__SAFE_POINT
		this->write(::haxe::io::Bytes_obj::ofData(::haxe::io::Output_obj::_double_bytes(x,this->bigEndian)));
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Output_obj,writeDouble,(void))

Void Output_obj::writeInt8( int x){
{
		__SAFE_POINT
		if ((bool((x < -128)) || bool((x >= 128))))
			hx::Throw (::haxe::io::Error_obj::Overflow);
		this->writeByte((int(x) & int(255)));
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Output_obj,writeInt8,(void))

Void Output_obj::writeInt16( int x){
{
		__SAFE_POINT
		if ((bool((x < -32768)) || bool((x >= 32768))))
			hx::Throw (::haxe::io::Error_obj::Overflow);
		this->writeUInt16((int(x) & int(65535)));
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Output_obj,writeInt16,(void))

Void Output_obj::writeUInt16( int x){
{
		__SAFE_POINT
		if ((bool((x < 0)) || bool((x >= 65536))))
			hx::Throw (::haxe::io::Error_obj::Overflow);
		if (this->bigEndian){
			this->writeByte((int(x) >> int(8)));
			this->writeByte((int(x) & int(255)));
		}
		else{
			this->writeByte((int(x) & int(255)));
			this->writeByte((int(x) >> int(8)));
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Output_obj,writeUInt16,(void))

Void Output_obj::writeInt24( int x){
{
		__SAFE_POINT
		if ((bool((x < -8388608)) || bool((x >= 8388608))))
			hx::Throw (::haxe::io::Error_obj::Overflow);
		this->writeUInt24((int(x) & int(16777215)));
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Output_obj,writeInt24,(void))

Void Output_obj::writeUInt24( int x){
{
		__SAFE_POINT
		if ((bool((x < 0)) || bool((x >= 16777216))))
			hx::Throw (::haxe::io::Error_obj::Overflow);
		if (this->bigEndian){
			this->writeByte((int(x) >> int(16)));
			this->writeByte((int(((int(x) >> int(8)))) & int(255)));
			this->writeByte((int(x) & int(255)));
		}
		else{
			this->writeByte((int(x) & int(255)));
			this->writeByte((int(((int(x) >> int(8)))) & int(255)));
			this->writeByte((int(x) >> int(16)));
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Output_obj,writeUInt24,(void))

Void Output_obj::writeInt31( int x){
{
		__SAFE_POINT
		if ((bool((x < -1073741824)) || bool((x >= 1073741824))))
			hx::Throw (::haxe::io::Error_obj::Overflow);
		if (this->bigEndian){
			this->writeByte(hx::UShr(x,24));
			this->writeByte((int(((int(x) >> int(16)))) & int(255)));
			this->writeByte((int(((int(x) >> int(8)))) & int(255)));
			this->writeByte((int(x) & int(255)));
		}
		else{
			this->writeByte((int(x) & int(255)));
			this->writeByte((int(((int(x) >> int(8)))) & int(255)));
			this->writeByte((int(((int(x) >> int(16)))) & int(255)));
			this->writeByte(hx::UShr(x,24));
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Output_obj,writeInt31,(void))

Void Output_obj::writeUInt30( int x){
{
		__SAFE_POINT
		if ((bool((x < 0)) || bool((x >= 1073741824))))
			hx::Throw (::haxe::io::Error_obj::Overflow);
		if (this->bigEndian){
			this->writeByte(hx::UShr(x,24));
			this->writeByte((int(((int(x) >> int(16)))) & int(255)));
			this->writeByte((int(((int(x) >> int(8)))) & int(255)));
			this->writeByte((int(x) & int(255)));
		}
		else{
			this->writeByte((int(x) & int(255)));
			this->writeByte((int(((int(x) >> int(8)))) & int(255)));
			this->writeByte((int(((int(x) >> int(16)))) & int(255)));
			this->writeByte(hx::UShr(x,24));
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Output_obj,writeUInt30,(void))

Void Output_obj::writeInt32( ::cpp::CppInt32__ x){
{
		__SAFE_POINT
		if (this->bigEndian){
			this->writeByte(::cpp::CppInt32___obj::toInt(::cpp::CppInt32___obj::ushr(x,24)));
			this->writeByte((int(::cpp::CppInt32___obj::toInt(::cpp::CppInt32___obj::ushr(x,16))) & int(255)));
			this->writeByte((int(::cpp::CppInt32___obj::toInt(::cpp::CppInt32___obj::ushr(x,8))) & int(255)));
			this->writeByte(::cpp::CppInt32___obj::toInt(::cpp::CppInt32___obj::_and(x,::cpp::CppInt32___obj::ofInt(255))));
		}
		else{
			this->writeByte(::cpp::CppInt32___obj::toInt(::cpp::CppInt32___obj::_and(x,::cpp::CppInt32___obj::ofInt(255))));
			this->writeByte((int(::cpp::CppInt32___obj::toInt(::cpp::CppInt32___obj::ushr(x,8))) & int(255)));
			this->writeByte((int(::cpp::CppInt32___obj::toInt(::cpp::CppInt32___obj::ushr(x,16))) & int(255)));
			this->writeByte(::cpp::CppInt32___obj::toInt(::cpp::CppInt32___obj::ushr(x,24)));
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Output_obj,writeInt32,(void))

Void Output_obj::prepare( int nbytes){
{
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Output_obj,prepare,(void))

Void Output_obj::writeInput( ::haxe::io::Input i,Dynamic bufsize){
{
		__SAFE_POINT
		if ((bufsize == null()))
			bufsize = 4096;
		::haxe::io::Bytes buf = ::haxe::io::Bytes_obj::alloc(bufsize);
		try{
			while(true){
				__SAFE_POINT
				int len = i->readBytes(buf,0,bufsize);
				if ((len == 0))
					hx::Throw (::haxe::io::Error_obj::Blocked);
				int p = 0;
				while((len > 0)){
					__SAFE_POINT
					int k = this->writeBytes(buf,p,len);
					if ((k == 0))
						hx::Throw (::haxe::io::Error_obj::Blocked);
					hx::AddEq(p,k);
					hx::SubEq(len,k);
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
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(Output_obj,writeInput,(void))

Void Output_obj::writeString( ::String s){
{
		__SAFE_POINT
		::haxe::io::Bytes b = ::haxe::io::Bytes_obj::ofString(s);
		this->writeFullBytes(b,0,b->length);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Output_obj,writeString,(void))

Dynamic Output_obj::_float_bytes;

Dynamic Output_obj::_double_bytes;


Output_obj::Output_obj()
{
}

void Output_obj::__Mark()
{
	hx::MarkMember(bigEndian);
}

Dynamic Output_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 5:
		if (!memcmp(inName.__s,L"flush",sizeof(wchar_t)*5) ) { return flush_dyn(); }
		if (!memcmp(inName.__s,L"close",sizeof(wchar_t)*5) ) { return close_dyn(); }
		if (!memcmp(inName.__s,L"write",sizeof(wchar_t)*5) ) { return write_dyn(); }
		break;
	case 7:
		if (!memcmp(inName.__s,L"prepare",sizeof(wchar_t)*7) ) { return prepare_dyn(); }
		break;
	case 9:
		if (!memcmp(inName.__s,L"bigEndian",sizeof(wchar_t)*9) ) { return bigEndian; }
		if (!memcmp(inName.__s,L"writeByte",sizeof(wchar_t)*9) ) { return writeByte_dyn(); }
		if (!memcmp(inName.__s,L"setEndian",sizeof(wchar_t)*9) ) { return setEndian_dyn(); }
		if (!memcmp(inName.__s,L"writeInt8",sizeof(wchar_t)*9) ) { return writeInt8_dyn(); }
		break;
	case 10:
		if (!memcmp(inName.__s,L"writeBytes",sizeof(wchar_t)*10) ) { return writeBytes_dyn(); }
		if (!memcmp(inName.__s,L"writeFloat",sizeof(wchar_t)*10) ) { return writeFloat_dyn(); }
		if (!memcmp(inName.__s,L"writeInt16",sizeof(wchar_t)*10) ) { return writeInt16_dyn(); }
		if (!memcmp(inName.__s,L"writeInt24",sizeof(wchar_t)*10) ) { return writeInt24_dyn(); }
		if (!memcmp(inName.__s,L"writeInt31",sizeof(wchar_t)*10) ) { return writeInt31_dyn(); }
		if (!memcmp(inName.__s,L"writeInt32",sizeof(wchar_t)*10) ) { return writeInt32_dyn(); }
		if (!memcmp(inName.__s,L"writeInput",sizeof(wchar_t)*10) ) { return writeInput_dyn(); }
		break;
	case 11:
		if (!memcmp(inName.__s,L"writeDouble",sizeof(wchar_t)*11) ) { return writeDouble_dyn(); }
		if (!memcmp(inName.__s,L"writeUInt16",sizeof(wchar_t)*11) ) { return writeUInt16_dyn(); }
		if (!memcmp(inName.__s,L"writeUInt24",sizeof(wchar_t)*11) ) { return writeUInt24_dyn(); }
		if (!memcmp(inName.__s,L"writeUInt30",sizeof(wchar_t)*11) ) { return writeUInt30_dyn(); }
		if (!memcmp(inName.__s,L"writeString",sizeof(wchar_t)*11) ) { return writeString_dyn(); }
		break;
	case 12:
		if (!memcmp(inName.__s,L"_float_bytes",sizeof(wchar_t)*12) ) { return _float_bytes; }
		break;
	case 13:
		if (!memcmp(inName.__s,L"_double_bytes",sizeof(wchar_t)*13) ) { return _double_bytes; }
		break;
	case 14:
		if (!memcmp(inName.__s,L"writeFullBytes",sizeof(wchar_t)*14) ) { return writeFullBytes_dyn(); }
	}
	return super::__Field(inName);
}

Dynamic Output_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	switch(inName.length) {
	case 9:
		if (!memcmp(inName.__s,L"bigEndian",sizeof(wchar_t)*9) ) { return setEndian(inValue); }
		break;
	case 12:
		if (!memcmp(inName.__s,L"_float_bytes",sizeof(wchar_t)*12) ) { _float_bytes=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 13:
		if (!memcmp(inName.__s,L"_double_bytes",sizeof(wchar_t)*13) ) { _double_bytes=inValue.Cast< Dynamic >(); return inValue; }
	}
	return super::__SetField(inName,inValue);
}

void Output_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_STRING(L"bigEndian",9));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_STRING(L"_float_bytes",12),
	HX_STRING(L"_double_bytes",13),
	String(null()) };

static ::String sMemberFields[] = {
	HX_STRING(L"bigEndian",9),
	HX_STRING(L"writeByte",9),
	HX_STRING(L"writeBytes",10),
	HX_STRING(L"flush",5),
	HX_STRING(L"close",5),
	HX_STRING(L"setEndian",9),
	HX_STRING(L"write",5),
	HX_STRING(L"writeFullBytes",14),
	HX_STRING(L"writeFloat",10),
	HX_STRING(L"writeDouble",11),
	HX_STRING(L"writeInt8",9),
	HX_STRING(L"writeInt16",10),
	HX_STRING(L"writeUInt16",11),
	HX_STRING(L"writeInt24",10),
	HX_STRING(L"writeUInt24",11),
	HX_STRING(L"writeInt31",10),
	HX_STRING(L"writeUInt30",11),
	HX_STRING(L"writeInt32",10),
	HX_STRING(L"prepare",7),
	HX_STRING(L"writeInput",10),
	HX_STRING(L"writeString",11),
	String(null()) };

static void sMarkStatics() {
	hx::MarkMember(Output_obj::_float_bytes);
	hx::MarkMember(Output_obj::_double_bytes);
};

Class Output_obj::__mClass;

void Output_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_STRING(L"haxe.io.Output",14), hx::TCanCast< Output_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void Output_obj::__boot()
{
	hx::Static(_float_bytes) = ::cpp::Lib_obj::load(HX_STRING(L"std",3),HX_STRING(L"float_bytes",11),2);
	hx::Static(_double_bytes) = ::cpp::Lib_obj::load(HX_STRING(L"std",3),HX_STRING(L"double_bytes",12),2);
}

} // end namespace haxe
} // end namespace io
