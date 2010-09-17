#include <hxcpp.h>

#ifndef INCLUDED_cpp_CppInt32__
#include <cpp/CppInt32__.h>
#endif
#ifndef INCLUDED_haxe_io_Bytes
#include <haxe/io/Bytes.h>
#endif
#ifndef INCLUDED_haxe_io_Input
#include <haxe/io/Input.h>
#endif
#ifndef INCLUDED_neash_utils_IDataInput
#include <neash/utils/IDataInput.h>
#endif
namespace neash{
namespace utils{

Void IDataInput_obj::__construct(::haxe::io::Input inInput)
{
{
	this->mInput = inInput;
}
;
	return null();
}

IDataInput_obj::~IDataInput_obj() { }

Dynamic IDataInput_obj::__CreateEmpty() { return  new IDataInput_obj; }
hx::ObjectPtr< IDataInput_obj > IDataInput_obj::__new(::haxe::io::Input inInput)
{  hx::ObjectPtr< IDataInput_obj > result = new IDataInput_obj();
	result->__construct(inInput);
	return result;}

Dynamic IDataInput_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< IDataInput_obj > result = new IDataInput_obj();
	result->__construct(inArgs[0]);
	return result;}

Void IDataInput_obj::close( ){
{
		__SAFE_POINT
		this->mInput->close();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(IDataInput_obj,close,(void))

::haxe::io::Bytes IDataInput_obj::readAll( Dynamic bufsize){
	__SAFE_POINT
	return this->mInput->readAll(bufsize);
}


HX_DEFINE_DYNAMIC_FUNC1(IDataInput_obj,readAll,return )

bool IDataInput_obj::readBoolean( ){
	__SAFE_POINT
	return (this->mInput->readInt8() != 0);
}


HX_DEFINE_DYNAMIC_FUNC0(IDataInput_obj,readBoolean,return )

int IDataInput_obj::readByte( ){
	__SAFE_POINT
	return this->mInput->readByte();
}


HX_DEFINE_DYNAMIC_FUNC0(IDataInput_obj,readByte,return )

::haxe::io::Bytes IDataInput_obj::readBytes( int inLen){
	__SAFE_POINT
	return this->mInput->read(inLen);
}


HX_DEFINE_DYNAMIC_FUNC1(IDataInput_obj,readBytes,return )

double IDataInput_obj::readDouble( ){
	__SAFE_POINT
	return this->mInput->readDouble();
}


HX_DEFINE_DYNAMIC_FUNC0(IDataInput_obj,readDouble,return )

double IDataInput_obj::readFloat( ){
	__SAFE_POINT
	return this->mInput->readFloat();
}


HX_DEFINE_DYNAMIC_FUNC0(IDataInput_obj,readFloat,return )

int IDataInput_obj::readInt( ){
	__SAFE_POINT
	return ::cpp::CppInt32___obj::toInt(this->mInput->readInt32());
}


HX_DEFINE_DYNAMIC_FUNC0(IDataInput_obj,readInt,return )

int IDataInput_obj::readUnsignedInt( ){
	__SAFE_POINT
	return ::cpp::CppInt32___obj::toInt(this->mInput->readInt32());
}


HX_DEFINE_DYNAMIC_FUNC0(IDataInput_obj,readUnsignedInt,return )

int IDataInput_obj::readShort( ){
	__SAFE_POINT
	return this->mInput->readInt16();
}


HX_DEFINE_DYNAMIC_FUNC0(IDataInput_obj,readShort,return )

::haxe::io::Bytes IDataInput_obj::readUTFBytes( int length){
	__SAFE_POINT
	return this->mInput->read(length);
}


HX_DEFINE_DYNAMIC_FUNC1(IDataInput_obj,readUTFBytes,return )

int IDataInput_obj::readUnsignedByte( ){
	__SAFE_POINT
	return this->mInput->readByte();
}


HX_DEFINE_DYNAMIC_FUNC0(IDataInput_obj,readUnsignedByte,return )

int IDataInput_obj::readUnsignedShort( ){
	__SAFE_POINT
	return this->mInput->readUInt16();
}


HX_DEFINE_DYNAMIC_FUNC0(IDataInput_obj,readUnsignedShort,return )


IDataInput_obj::IDataInput_obj()
{
}

void IDataInput_obj::__Mark()
{
	hx::MarkMember(mInput);
}

Dynamic IDataInput_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 5:
		if (!memcmp(inName.__s,L"close",sizeof(wchar_t)*5) ) { return close_dyn(); }
		break;
	case 6:
		if (!memcmp(inName.__s,L"mInput",sizeof(wchar_t)*6) ) { return mInput; }
		break;
	case 7:
		if (!memcmp(inName.__s,L"readAll",sizeof(wchar_t)*7) ) { return readAll_dyn(); }
		if (!memcmp(inName.__s,L"readInt",sizeof(wchar_t)*7) ) { return readInt_dyn(); }
		break;
	case 8:
		if (!memcmp(inName.__s,L"readByte",sizeof(wchar_t)*8) ) { return readByte_dyn(); }
		break;
	case 9:
		if (!memcmp(inName.__s,L"readBytes",sizeof(wchar_t)*9) ) { return readBytes_dyn(); }
		if (!memcmp(inName.__s,L"readFloat",sizeof(wchar_t)*9) ) { return readFloat_dyn(); }
		if (!memcmp(inName.__s,L"readShort",sizeof(wchar_t)*9) ) { return readShort_dyn(); }
		break;
	case 10:
		if (!memcmp(inName.__s,L"readDouble",sizeof(wchar_t)*10) ) { return readDouble_dyn(); }
		break;
	case 11:
		if (!memcmp(inName.__s,L"readBoolean",sizeof(wchar_t)*11) ) { return readBoolean_dyn(); }
		break;
	case 12:
		if (!memcmp(inName.__s,L"readUTFBytes",sizeof(wchar_t)*12) ) { return readUTFBytes_dyn(); }
		break;
	case 15:
		if (!memcmp(inName.__s,L"readUnsignedInt",sizeof(wchar_t)*15) ) { return readUnsignedInt_dyn(); }
		break;
	case 16:
		if (!memcmp(inName.__s,L"readUnsignedByte",sizeof(wchar_t)*16) ) { return readUnsignedByte_dyn(); }
		break;
	case 17:
		if (!memcmp(inName.__s,L"readUnsignedShort",sizeof(wchar_t)*17) ) { return readUnsignedShort_dyn(); }
	}
	return super::__Field(inName);
}

Dynamic IDataInput_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	switch(inName.length) {
	case 6:
		if (!memcmp(inName.__s,L"mInput",sizeof(wchar_t)*6) ) { mInput=inValue.Cast< ::haxe::io::Input >(); return inValue; }
	}
	return super::__SetField(inName,inValue);
}

void IDataInput_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_STRING(L"mInput",6));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_STRING(L"mInput",6),
	HX_STRING(L"close",5),
	HX_STRING(L"readAll",7),
	HX_STRING(L"readBoolean",11),
	HX_STRING(L"readByte",8),
	HX_STRING(L"readBytes",9),
	HX_STRING(L"readDouble",10),
	HX_STRING(L"readFloat",9),
	HX_STRING(L"readInt",7),
	HX_STRING(L"readUnsignedInt",15),
	HX_STRING(L"readShort",9),
	HX_STRING(L"readUTFBytes",12),
	HX_STRING(L"readUnsignedByte",16),
	HX_STRING(L"readUnsignedShort",17),
	String(null()) };

static void sMarkStatics() {
};

Class IDataInput_obj::__mClass;

void IDataInput_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_STRING(L"neash.utils.IDataInput",22), hx::TCanCast< IDataInput_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void IDataInput_obj::__boot()
{
}

} // end namespace neash
} // end namespace utils
