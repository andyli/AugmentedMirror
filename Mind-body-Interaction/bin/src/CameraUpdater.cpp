#include <hxcpp.h>

#ifndef INCLUDED_CameraUpdater
#include <CameraUpdater.h>
#endif
#ifndef INCLUDED_Updater
#include <Updater.h>
#endif
#ifndef INCLUDED_haxe_io_Bytes
#include <haxe/io/Bytes.h>
#endif
#ifndef INCLUDED_haxe_io_BytesInput
#include <haxe/io/BytesInput.h>
#endif
#ifndef INCLUDED_haxe_io_Input
#include <haxe/io/Input.h>
#endif
#ifndef INCLUDED_org_casalib_util_ArrayUtil
#include <org/casalib/util/ArrayUtil.h>
#endif
#ifndef INCLUDED_sandy_core_scenegraph_ATransformable
#include <sandy/core/scenegraph/ATransformable.h>
#endif
#ifndef INCLUDED_sandy_core_scenegraph_Node
#include <sandy/core/scenegraph/Node.h>
#endif

Void CameraUpdater_obj::__construct(::sandy::core::scenegraph::ATransformable camera0,::sandy::core::scenegraph::ATransformable camera1,::String socketUrlAndPort,Dynamic __o_readyByte)
{
int readyByte = __o_readyByte.Default(8);
{
	super::__construct(socketUrlAndPort,readyByte);
	this->camera0 = camera0;
	this->camera1 = camera1;
	this->inputSize = 24;
}
;
	return null();
}

CameraUpdater_obj::~CameraUpdater_obj() { }

Dynamic CameraUpdater_obj::__CreateEmpty() { return  new CameraUpdater_obj; }
hx::ObjectPtr< CameraUpdater_obj > CameraUpdater_obj::__new(::sandy::core::scenegraph::ATransformable camera0,::sandy::core::scenegraph::ATransformable camera1,::String socketUrlAndPort,Dynamic __o_readyByte)
{  hx::ObjectPtr< CameraUpdater_obj > result = new CameraUpdater_obj();
	result->__construct(camera0,camera1,socketUrlAndPort,__o_readyByte);
	return result;}

Dynamic CameraUpdater_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< CameraUpdater_obj > result = new CameraUpdater_obj();
	result->__construct(inArgs[0],inArgs[1],inArgs[2],inArgs[3]);
	return result;}

Void CameraUpdater_obj::updateTarget( ::haxe::io::Bytes bytes){
{
		__SAFE_POINT
		::haxe::io::BytesInput input = ::haxe::io::BytesInput_obj::__new(bytes,null(),null());
		Array< double > values = Array_obj< double >::__new().Add(input->readFloat()).Add(input->readFloat()).Add(input->readFloat()).Add(input->readFloat()).Add(input->readFloat()).Add(input->readFloat());
		if (::org::casalib::util::ArrayUtil_obj::containsAll(Array_obj< double >::__new().Add(-1.),values)){
		}
		else{
			values->reverse();
			this->camera0->__setX(values->__get(0));
			this->camera0->__setY(values->__get(1));
			this->camera0->__setZ(values->__get(2));
			this->camera1->__setX(values->__get(3));
			this->camera1->__setY(values->__get(4));
			this->camera1->__setZ(values->__get(5));
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(CameraUpdater_obj,updateTarget,(void))


CameraUpdater_obj::CameraUpdater_obj()
{
}

void CameraUpdater_obj::__Mark()
{
	hx::MarkMember(camera0);
	hx::MarkMember(camera1);
	super::__Mark();
}

Dynamic CameraUpdater_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 7:
		if (!memcmp(inName.__s,L"camera0",sizeof(wchar_t)*7) ) { return camera0; }
		if (!memcmp(inName.__s,L"camera1",sizeof(wchar_t)*7) ) { return camera1; }
		break;
	case 12:
		if (!memcmp(inName.__s,L"updateTarget",sizeof(wchar_t)*12) ) { return updateTarget_dyn(); }
	}
	return super::__Field(inName);
}

Dynamic CameraUpdater_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	switch(inName.length) {
	case 7:
		if (!memcmp(inName.__s,L"camera0",sizeof(wchar_t)*7) ) { camera0=inValue.Cast< ::sandy::core::scenegraph::ATransformable >(); return inValue; }
		if (!memcmp(inName.__s,L"camera1",sizeof(wchar_t)*7) ) { camera1=inValue.Cast< ::sandy::core::scenegraph::ATransformable >(); return inValue; }
	}
	return super::__SetField(inName,inValue);
}

void CameraUpdater_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_STRING(L"camera0",7));
	outFields->push(HX_STRING(L"camera1",7));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_STRING(L"camera0",7),
	HX_STRING(L"camera1",7),
	HX_STRING(L"updateTarget",12),
	String(null()) };

static void sMarkStatics() {
};

Class CameraUpdater_obj::__mClass;

void CameraUpdater_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_STRING(L"CameraUpdater",13), hx::TCanCast< CameraUpdater_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void CameraUpdater_obj::__boot()
{
}

