#include <hxcpp.h>

#ifndef INCLUDED_cpp_CppInt32__
#include <cpp/CppInt32__.h>
#endif
#ifndef INCLUDED_haxe_io_Input
#include <haxe/io/Input.h>
#endif
#ifndef INCLUDED_nme_Loader
#include <nme/Loader.h>
#endif
#ifndef INCLUDED_nme_utils_ByteArray
#include <nme/utils/ByteArray.h>
#endif
namespace nme{
namespace utils{

Void ByteArray_obj::__construct(Dynamic inHandle)
{
{
	if ((inHandle == null())){
		this->mArray = ::nme::utils::ByteArray_obj::nme_create_byte_array();
	}
	else{
		this->mArray = inHandle;
	}
	this->position = 0;
}
;
	return null();
}

ByteArray_obj::~ByteArray_obj() { }

Dynamic ByteArray_obj::__CreateEmpty() { return  new ByteArray_obj; }
hx::ObjectPtr< ByteArray_obj > ByteArray_obj::__new(Dynamic inHandle)
{  hx::ObjectPtr< ByteArray_obj > result = new ByteArray_obj();
	result->__construct(inHandle);
	return result;}

Dynamic ByteArray_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< ByteArray_obj > result = new ByteArray_obj();
	result->__construct(inArgs[0]);
	return result;}

Dynamic ByteArray_obj::get_handle( ){
	return this->mArray;
}


HX_DEFINE_DYNAMIC_FUNC0(ByteArray_obj,get_handle,return )

int ByteArray_obj::get_length( ){
	__SAFE_POINT
	return ::nme::utils::ByteArray_obj::nme_byte_array_length(this->mArray);
}


HX_DEFINE_DYNAMIC_FUNC0(ByteArray_obj,get_length,return )

int ByteArray_obj::__get( int pos){
	__SAFE_POINT
	return ::nme::utils::ByteArray_obj::nme_byte_array_get(this->mArray,pos);
}


HX_DEFINE_DYNAMIC_FUNC1(ByteArray_obj,__get,return )

Void ByteArray_obj::__set( int pos,int v){
{
		__SAFE_POINT
		::nme::utils::ByteArray_obj::nme_byte_array_set(this->mArray,pos,v);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(ByteArray_obj,__set,(void))

int ByteArray_obj::readByte( ){
	__SAFE_POINT
	return ::nme::utils::ByteArray_obj::nme_byte_array_get(this->mArray,this->position++);
}


HX_DEFINE_DYNAMIC_FUNC0(ByteArray_obj,readByte,return )

int ByteArray_obj::readInt( ){
	__SAFE_POINT
	return this->readInt32();
}


HX_DEFINE_DYNAMIC_FUNC0(ByteArray_obj,readInt,return )

int ByteArray_obj::readShort( ){
	__SAFE_POINT
	return this->readInt16();
}


HX_DEFINE_DYNAMIC_FUNC0(ByteArray_obj,readShort,return )

int ByteArray_obj::readUnsignedByte( ){
	__SAFE_POINT
	return this->readByte();
}


HX_DEFINE_DYNAMIC_FUNC0(ByteArray_obj,readUnsignedByte,return )

::String ByteArray_obj::readUTFBytes( int inLen){
	__SAFE_POINT
	return this->readString(inLen);
}


HX_DEFINE_DYNAMIC_FUNC1(ByteArray_obj,readUTFBytes,return )

::String ByteArray_obj::__getEndian( ){
	return this->bigEndian ? ::String( HX_STRING(L"bigEndian",9) ) : ::String( HX_STRING(L"littleEndian",12) );
}


HX_DEFINE_DYNAMIC_FUNC0(ByteArray_obj,__getEndian,return )

::String ByteArray_obj::__setEndian( ::String s){
	__SAFE_POINT
	this->setEndian(((s == HX_STRING(L"bigEndian",9))) ? bool( true ) : bool( false ));
	return s;
}


HX_DEFINE_DYNAMIC_FUNC1(ByteArray_obj,__setEndian,return )

::nme::utils::ByteArray ByteArray_obj::readFile( ::String inString){
	__SAFE_POINT
	Dynamic handle = ::nme::utils::ByteArray_obj::nme_read_file(inString);
	return ::nme::utils::ByteArray_obj::__new(handle);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(ByteArray_obj,readFile,return )

Dynamic ByteArray_obj::nme_create_byte_array;

Dynamic ByteArray_obj::nme_byte_array_length;

Dynamic ByteArray_obj::nme_byte_array_get;

Dynamic ByteArray_obj::nme_byte_array_set;

Dynamic ByteArray_obj::nme_read_file;


ByteArray_obj::ByteArray_obj()
{
}

void ByteArray_obj::__Mark()
{
	hx::MarkMember(mArray);
	hx::MarkMember(position);
	hx::MarkMember(endian);
	hx::MarkMember(length);
	super::__Mark();
}

Dynamic ByteArray_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 5:
		if (!memcmp(inName.__s,L"__get",sizeof(wchar_t)*5) ) { return __get_dyn(); }
		if (!memcmp(inName.__s,L"__set",sizeof(wchar_t)*5) ) { return __set_dyn(); }
		break;
	case 6:
		if (!memcmp(inName.__s,L"mArray",sizeof(wchar_t)*6) ) { return mArray; }
		if (!memcmp(inName.__s,L"endian",sizeof(wchar_t)*6) ) { return __getEndian(); }
		if (!memcmp(inName.__s,L"length",sizeof(wchar_t)*6) ) { return get_length(); }
		break;
	case 7:
		if (!memcmp(inName.__s,L"readInt",sizeof(wchar_t)*7) ) { return readInt_dyn(); }
		break;
	case 8:
		if (!memcmp(inName.__s,L"readFile",sizeof(wchar_t)*8) ) { return readFile_dyn(); }
		if (!memcmp(inName.__s,L"position",sizeof(wchar_t)*8) ) { return position; }
		if (!memcmp(inName.__s,L"readByte",sizeof(wchar_t)*8) ) { return readByte_dyn(); }
		break;
	case 9:
		if (!memcmp(inName.__s,L"readShort",sizeof(wchar_t)*9) ) { return readShort_dyn(); }
		break;
	case 10:
		if (!memcmp(inName.__s,L"get_handle",sizeof(wchar_t)*10) ) { return get_handle_dyn(); }
		if (!memcmp(inName.__s,L"get_length",sizeof(wchar_t)*10) ) { return get_length_dyn(); }
		break;
	case 11:
		if (!memcmp(inName.__s,L"__getEndian",sizeof(wchar_t)*11) ) { return __getEndian_dyn(); }
		if (!memcmp(inName.__s,L"__setEndian",sizeof(wchar_t)*11) ) { return __setEndian_dyn(); }
		break;
	case 12:
		if (!memcmp(inName.__s,L"readUTFBytes",sizeof(wchar_t)*12) ) { return readUTFBytes_dyn(); }
		break;
	case 13:
		if (!memcmp(inName.__s,L"nme_read_file",sizeof(wchar_t)*13) ) { return nme_read_file; }
		break;
	case 16:
		if (!memcmp(inName.__s,L"readUnsignedByte",sizeof(wchar_t)*16) ) { return readUnsignedByte_dyn(); }
		break;
	case 18:
		if (!memcmp(inName.__s,L"nme_byte_array_get",sizeof(wchar_t)*18) ) { return nme_byte_array_get; }
		if (!memcmp(inName.__s,L"nme_byte_array_set",sizeof(wchar_t)*18) ) { return nme_byte_array_set; }
		break;
	case 21:
		if (!memcmp(inName.__s,L"nme_create_byte_array",sizeof(wchar_t)*21) ) { return nme_create_byte_array; }
		if (!memcmp(inName.__s,L"nme_byte_array_length",sizeof(wchar_t)*21) ) { return nme_byte_array_length; }
	}
	return super::__Field(inName);
}

Dynamic ByteArray_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	switch(inName.length) {
	case 6:
		if (!memcmp(inName.__s,L"mArray",sizeof(wchar_t)*6) ) { mArray=inValue.Cast< Dynamic >(); return inValue; }
		if (!memcmp(inName.__s,L"endian",sizeof(wchar_t)*6) ) { return __setEndian(inValue); }
		if (!memcmp(inName.__s,L"length",sizeof(wchar_t)*6) ) { length=inValue.Cast< int >(); return inValue; }
		break;
	case 8:
		if (!memcmp(inName.__s,L"position",sizeof(wchar_t)*8) ) { position=inValue.Cast< int >(); return inValue; }
		break;
	case 13:
		if (!memcmp(inName.__s,L"nme_read_file",sizeof(wchar_t)*13) ) { nme_read_file=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 18:
		if (!memcmp(inName.__s,L"nme_byte_array_get",sizeof(wchar_t)*18) ) { nme_byte_array_get=inValue.Cast< Dynamic >(); return inValue; }
		if (!memcmp(inName.__s,L"nme_byte_array_set",sizeof(wchar_t)*18) ) { nme_byte_array_set=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 21:
		if (!memcmp(inName.__s,L"nme_create_byte_array",sizeof(wchar_t)*21) ) { nme_create_byte_array=inValue.Cast< Dynamic >(); return inValue; }
		if (!memcmp(inName.__s,L"nme_byte_array_length",sizeof(wchar_t)*21) ) { nme_byte_array_length=inValue.Cast< Dynamic >(); return inValue; }
	}
	return super::__SetField(inName,inValue);
}

void ByteArray_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_STRING(L"mArray",6));
	outFields->push(HX_STRING(L"position",8));
	outFields->push(HX_STRING(L"endian",6));
	outFields->push(HX_STRING(L"length",6));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_STRING(L"readFile",8),
	HX_STRING(L"nme_create_byte_array",21),
	HX_STRING(L"nme_byte_array_length",21),
	HX_STRING(L"nme_byte_array_get",18),
	HX_STRING(L"nme_byte_array_set",18),
	HX_STRING(L"nme_read_file",13),
	String(null()) };

static ::String sMemberFields[] = {
	HX_STRING(L"mArray",6),
	HX_STRING(L"position",8),
	HX_STRING(L"endian",6),
	HX_STRING(L"length",6),
	HX_STRING(L"get_handle",10),
	HX_STRING(L"get_length",10),
	HX_STRING(L"__get",5),
	HX_STRING(L"__set",5),
	HX_STRING(L"readByte",8),
	HX_STRING(L"readInt",7),
	HX_STRING(L"readShort",9),
	HX_STRING(L"readUnsignedByte",16),
	HX_STRING(L"readUTFBytes",12),
	HX_STRING(L"__getEndian",11),
	HX_STRING(L"__setEndian",11),
	String(null()) };

static void sMarkStatics() {
	hx::MarkMember(ByteArray_obj::nme_create_byte_array);
	hx::MarkMember(ByteArray_obj::nme_byte_array_length);
	hx::MarkMember(ByteArray_obj::nme_byte_array_get);
	hx::MarkMember(ByteArray_obj::nme_byte_array_set);
	hx::MarkMember(ByteArray_obj::nme_read_file);
};

Class ByteArray_obj::__mClass;

void ByteArray_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_STRING(L"nme.utils.ByteArray",19), hx::TCanCast< ByteArray_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void ByteArray_obj::__boot()
{
	hx::Static(nme_create_byte_array) = ::nme::Loader_obj::load(HX_STRING(L"nme_create_byte_array",21),0);
	hx::Static(nme_byte_array_length) = ::nme::Loader_obj::load(HX_STRING(L"nme_byte_array_length",21),1);
	hx::Static(nme_byte_array_get) = ::nme::Loader_obj::load(HX_STRING(L"nme_byte_array_get",18),2);
	hx::Static(nme_byte_array_set) = ::nme::Loader_obj::load(HX_STRING(L"nme_byte_array_set",18),3);
	hx::Static(nme_read_file) = ::nme::Loader_obj::load(HX_STRING(L"nme_read_file",13),1);
}

} // end namespace nme
} // end namespace utils
