#include <hxcpp.h>

#ifndef INCLUDED_Hash
#include <Hash.h>
#endif
#ifndef INCLUDED_neash_display_DisplayObject
#include <neash/display/DisplayObject.h>
#endif
#ifndef INCLUDED_neash_display_DisplayObjectContainer
#include <neash/display/DisplayObjectContainer.h>
#endif
#ifndef INCLUDED_neash_display_InteractiveObject
#include <neash/display/InteractiveObject.h>
#endif
#ifndef INCLUDED_neash_display_Stage
#include <neash/display/Stage.h>
#endif
#ifndef INCLUDED_neash_events_EventDispatcher
#include <neash/events/EventDispatcher.h>
#endif
#ifndef INCLUDED_neash_events_IEventDispatcher
#include <neash/events/IEventDispatcher.h>
#endif
#ifndef INCLUDED_nme_display_IBitmapDrawable
#include <nme/display/IBitmapDrawable.h>
#endif
#ifndef INCLUDED_org_casalib_util_StageReference
#include <org/casalib/util/StageReference.h>
#endif
namespace org{
namespace casalib{
namespace util{

Void StageReference_obj::__construct()
{
	return null();
}

StageReference_obj::~StageReference_obj() { }

Dynamic StageReference_obj::__CreateEmpty() { return  new StageReference_obj; }
hx::ObjectPtr< StageReference_obj > StageReference_obj::__new()
{  hx::ObjectPtr< StageReference_obj > result = new StageReference_obj();
	result->__construct();
	return result;}

Dynamic StageReference_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< StageReference_obj > result = new StageReference_obj();
	result->__construct();
	return result;}

::String StageReference_obj::STAGE_DEFAULT;

::String StageReference_obj::_STAGE_DEFAULT( ){
	return HX_STRING(L"stageDefault",12);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(StageReference_obj,_STAGE_DEFAULT,return )

::Hash StageReference_obj::_stageMap;

::neash::display::Stage StageReference_obj::getStage( Dynamic __o_id){
::String id = __o_id.Default(HX_STRING(L"stageDefault",12));
{
		__SAFE_POINT
		if (!::org::casalib::util::StageReference_obj::_getMap()->exists(id))
			hx::Throw ((((HX_STRING(L"Cannot get Stage (\"",19) + id)) + HX_STRING(L"\") before it has been set.",26)));
		return ::org::casalib::util::StageReference_obj::_getMap()->get(id).Cast< ::neash::display::Stage >();
	}
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(StageReference_obj,getStage,return )

Void StageReference_obj::setStage( ::neash::display::Stage stage,Dynamic __o_id){
::String id = __o_id.Default(HX_STRING(L"stageDefault",12));
{
		__SAFE_POINT
		::org::casalib::util::StageReference_obj::_getMap()->set(id,stage);
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(StageReference_obj,setStage,(void))

bool StageReference_obj::removeStage( Dynamic __o_id){
::String id = __o_id.Default(HX_STRING(L"stageDefault",12));
{
		__SAFE_POINT
		if (!::org::casalib::util::StageReference_obj::_getMap()->exists(id))
			return false;
		::org::casalib::util::StageReference_obj::_getMap()->remove(id);
		return true;
	}
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(StageReference_obj,removeStage,return )

Array< ::String > StageReference_obj::getIds( ){
	__SAFE_POINT
	Array< ::String > ary = Array_obj< ::String >::__new();
	Dynamic key = ::org::casalib::util::StageReference_obj::_getMap()->keys();
	while(key->__Field(HX_STRING(L"hasNext",7))()){
		__SAFE_POINT
		ary->push(key->__Field(HX_STRING(L"next",4))());
	}
	return ary;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(StageReference_obj,getIds,return )

::String StageReference_obj::getStageId( ::neash::display::Stage stage){
	__SAFE_POINT
	{
		int _g = 0;
		Array< ::String > _g1 = ::org::casalib::util::StageReference_obj::getIds();
		while((_g < _g1->length)){
			__SAFE_POINT
			::String i = _g1->__get(_g);
			++_g;
			if ((::org::casalib::util::StageReference_obj::getStage(i) == stage))
				return i;
		}
	}
	return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(StageReference_obj,getStageId,return )

::Hash StageReference_obj::_getMap( ){
	if ((::org::casalib::util::StageReference_obj::_stageMap == null()))
		::org::casalib::util::StageReference_obj::_stageMap = ::Hash_obj::__new();
	return ::org::casalib::util::StageReference_obj::_stageMap;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(StageReference_obj,_getMap,return )


StageReference_obj::StageReference_obj()
{
}

void StageReference_obj::__Mark()
{
}

Dynamic StageReference_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 6:
		if (!memcmp(inName.__s,L"getIds",sizeof(wchar_t)*6) ) { return getIds_dyn(); }
		break;
	case 7:
		if (!memcmp(inName.__s,L"_getMap",sizeof(wchar_t)*7) ) { return _getMap_dyn(); }
		break;
	case 8:
		if (!memcmp(inName.__s,L"getStage",sizeof(wchar_t)*8) ) { return getStage_dyn(); }
		if (!memcmp(inName.__s,L"setStage",sizeof(wchar_t)*8) ) { return setStage_dyn(); }
		break;
	case 9:
		if (!memcmp(inName.__s,L"_stageMap",sizeof(wchar_t)*9) ) { return _stageMap; }
		break;
	case 10:
		if (!memcmp(inName.__s,L"getStageId",sizeof(wchar_t)*10) ) { return getStageId_dyn(); }
		break;
	case 11:
		if (!memcmp(inName.__s,L"removeStage",sizeof(wchar_t)*11) ) { return removeStage_dyn(); }
		break;
	case 13:
		if (!memcmp(inName.__s,L"STAGE_DEFAULT",sizeof(wchar_t)*13) ) { return _STAGE_DEFAULT(); }
		break;
	case 14:
		if (!memcmp(inName.__s,L"_STAGE_DEFAULT",sizeof(wchar_t)*14) ) { return _STAGE_DEFAULT_dyn(); }
	}
	return super::__Field(inName);
}

Dynamic StageReference_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	switch(inName.length) {
	case 9:
		if (!memcmp(inName.__s,L"_stageMap",sizeof(wchar_t)*9) ) { _stageMap=inValue.Cast< ::Hash >(); return inValue; }
		break;
	case 13:
		if (!memcmp(inName.__s,L"STAGE_DEFAULT",sizeof(wchar_t)*13) ) { STAGE_DEFAULT=inValue.Cast< ::String >(); return inValue; }
	}
	return super::__SetField(inName,inValue);
}

void StageReference_obj::__GetFields(Array< ::String> &outFields)
{
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_STRING(L"STAGE_DEFAULT",13),
	HX_STRING(L"_STAGE_DEFAULT",14),
	HX_STRING(L"_stageMap",9),
	HX_STRING(L"getStage",8),
	HX_STRING(L"setStage",8),
	HX_STRING(L"removeStage",11),
	HX_STRING(L"getIds",6),
	HX_STRING(L"getStageId",10),
	HX_STRING(L"_getMap",7),
	String(null()) };

static ::String sMemberFields[] = {
	String(null()) };

static void sMarkStatics() {
	hx::MarkMember(StageReference_obj::STAGE_DEFAULT);
	hx::MarkMember(StageReference_obj::_stageMap);
};

Class StageReference_obj::__mClass;

void StageReference_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_STRING(L"org.casalib.util.StageReference",31), hx::TCanCast< StageReference_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void StageReference_obj::__boot()
{
	hx::Static(STAGE_DEFAULT);
	hx::Static(_stageMap);
}

} // end namespace org
} // end namespace casalib
} // end namespace util
