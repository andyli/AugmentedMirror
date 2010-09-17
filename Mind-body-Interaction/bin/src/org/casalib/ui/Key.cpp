#include <hxcpp.h>

#ifndef INCLUDED_IntHash
#include <IntHash.h>
#endif
#ifndef INCLUDED_hxMath
#include <hxMath.h>
#endif
#ifndef INCLUDED_Std
#include <Std.h>
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
#ifndef INCLUDED_neash_events_Event
#include <neash/events/Event.h>
#endif
#ifndef INCLUDED_neash_events_EventDispatcher
#include <neash/events/EventDispatcher.h>
#endif
#ifndef INCLUDED_neash_events_IEventDispatcher
#include <neash/events/IEventDispatcher.h>
#endif
#ifndef INCLUDED_neash_events_KeyboardEvent
#include <neash/events/KeyboardEvent.h>
#endif
#ifndef INCLUDED_nme_display_IBitmapDrawable
#include <nme/display/IBitmapDrawable.h>
#endif
#ifndef INCLUDED_org_casalib_core_IDestroyable
#include <org/casalib/core/IDestroyable.h>
#endif
#ifndef INCLUDED_org_casalib_events_IRemovableEventDispatcher
#include <org/casalib/events/IRemovableEventDispatcher.h>
#endif
#ifndef INCLUDED_org_casalib_events_KeyComboEvent
#include <org/casalib/events/KeyComboEvent.h>
#endif
#ifndef INCLUDED_org_casalib_events_RemovableEventDispatcher
#include <org/casalib/events/RemovableEventDispatcher.h>
#endif
#ifndef INCLUDED_org_casalib_ui_Key
#include <org/casalib/ui/Key.h>
#endif
#ifndef INCLUDED_org_casalib_ui_KeyCombo
#include <org/casalib/ui/KeyCombo.h>
#endif
#ifndef INCLUDED_org_casalib_util_ArrayUtil
#include <org/casalib/util/ArrayUtil.h>
#endif
#ifndef INCLUDED_org_casalib_util_StageReference
#include <org/casalib/util/StageReference.h>
#endif
namespace org{
namespace casalib{
namespace ui{

Void Key_obj::__construct()
{
{
	super::__construct(null());
	::neash::display::Stage stage = ::org::casalib::util::StageReference_obj::getStage(null());
	stage->addEventListener(::neash::events::KeyboardEvent_obj::KEY_DOWN,this->_onKeyDown_dyn(),null(),null(),null());
	stage->addEventListener(::neash::events::KeyboardEvent_obj::KEY_UP,this->_onKeyUp_dyn(),null(),null(),null());
	stage->addEventListener(::neash::events::Event_obj::DEACTIVATE,this->_onDeactivate_dyn(),null(),null(),null());
	this->_keysDown = ::IntHash_obj::__new();
	this->_keysTyped = Array_obj< int >::__new();
	this->_combosDown = Array_obj< ::org::casalib::ui::KeyCombo >::__new();
	this->_combinations = Array_obj< ::org::casalib::ui::KeyCombo >::__new();
	this->_longestCombo = 0;
}
;
	return null();
}

Key_obj::~Key_obj() { }

Dynamic Key_obj::__CreateEmpty() { return  new Key_obj; }
hx::ObjectPtr< Key_obj > Key_obj::__new()
{  hx::ObjectPtr< Key_obj > result = new Key_obj();
	result->__construct();
	return result;}

Dynamic Key_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Key_obj > result = new Key_obj();
	result->__construct();
	return result;}

bool Key_obj::isDown( int keyCode){
	__SAFE_POINT
	return this->_keysDown->get(keyCode);
}


HX_DEFINE_DYNAMIC_FUNC1(Key_obj,isDown,return )

Void Key_obj::addKeyCombo( ::org::casalib::ui::KeyCombo keyCombo){
{
		__SAFE_POINT
		int l = this->_combinations->length;
		while((l-- > 0))if (this->_combinations[l]->equals(keyCombo))
			return null();
		this->_longestCombo = ::Std_obj::toInt(::Math_obj::max(this->_longestCombo,keyCombo->getKeyCodes()->length));
		this->_combinations->push(keyCombo);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Key_obj,addKeyCombo,(void))

Void Key_obj::removeKeyCombo( ::org::casalib::ui::KeyCombo keyCombo){
{
		__SAFE_POINT
		int i = -1;
		int l = this->_combinations->length;
		while((l-- > 0)){
			__SAFE_POINT
			if (this->_combinations[l]->equals(keyCombo)){
				i = l;
				break;
			}
		}
		if ((i == -1))
			return null();
		this->_combinations->splice(i,1);
		if ((keyCombo->getKeyCodes()->length == this->_longestCombo)){
			int size = 0;
			l = this->_combinations->length;
			while((l-- > 0))size = ::Std_obj::toInt(::Math_obj::max(size,this->_combinations[l]->getKeyCodes()->length));
			this->_longestCombo = size;
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Key_obj,removeKeyCombo,(void))

Void Key_obj::destroy( ){
{
		hx::Throw (HX_STRING(L"Cannot destroy a singleton.",27));
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Key_obj,destroy,(void))

Void Key_obj::_onKeyDown( ::neash::events::KeyboardEvent e){
{
		__SAFE_POINT
		bool alreadyDown = this->_keysDown->get(e->keyCode);
		this->_keysDown->set(e->keyCode,true);
		this->_keysTyped->push(e->keyCode);
		if ((this->_keysTyped->length > this->_longestCombo))
			this->_keysTyped->splice(0,1);
		int l = this->_combinations->length;
		while((l-- > 0)){
			__SAFE_POINT
			this->_checkedTypedKeys(this->_combinations->__get(l));
			if (!alreadyDown)
				this->_checkDownKeys(this->_combinations->__get(l));
		}
		this->dispatchEvent(e);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Key_obj,_onKeyDown,(void))

Void Key_obj::_onKeyUp( ::neash::events::KeyboardEvent e){
{
		__SAFE_POINT
		int l = this->_combosDown->length;
		while((l-- > 0)){
			__SAFE_POINT
			if ((::org::casalib::util::ArrayUtil_obj::indexOf(this->_combosDown[l]->getKeyCodes(),e->keyCode,null()) > -1)){
				::org::casalib::events::KeyComboEvent keyComboHold = ::org::casalib::events::KeyComboEvent_obj::__new(HX_STRING(L"release",7),null(),null());
				{
					::org::casalib::ui::KeyCombo keyCombo = this->_combosDown->__get(l);
					keyComboHold->_keyCombo = keyCombo;
					keyCombo;
				}
				this->_combosDown->splice(l,1);
				this->dispatchEvent(keyComboHold);
			}
		}
		this->_keysDown->remove(e->keyCode);
		this->dispatchEvent(e);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Key_obj,_onKeyUp,(void))

Void Key_obj::_onDeactivate( ::neash::events::Event e){
{
		__SAFE_POINT
		int l = this->_combosDown->length;
		while((l-- > 0)){
			__SAFE_POINT
			::org::casalib::events::KeyComboEvent keyComboHold = ::org::casalib::events::KeyComboEvent_obj::__new(HX_STRING(L"release",7),null(),null());
			{
				::org::casalib::ui::KeyCombo keyCombo = this->_combosDown->__get(l);
				keyComboHold->_keyCombo = keyCombo;
				keyCombo;
			}
			this->dispatchEvent(keyComboHold);
		}
		this->_combosDown = Array_obj< ::org::casalib::ui::KeyCombo >::__new();
		this->_keysDown = ::IntHash_obj::__new();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Key_obj,_onDeactivate,(void))

Void Key_obj::_checkedTypedKeys( ::org::casalib::ui::KeyCombo keyCombo){
{
		__SAFE_POINT
		struct _Function_1_1{
			inline static bool Block( ::org::casalib::ui::KeyCombo &keyCombo,::org::casalib::ui::Key_obj *__this)/* DEF (ret block)(not intern) */{
				Array< int > first = keyCombo->getKeyCodes();
				Array< int > second = __this->_keysTyped->slice(-keyCombo->getKeyCodes()->length,null());
				int i = first->length;
				bool result = true;
				if ((i != second->length)){
					result = false;
				}
				else{
					while((i-- > 0)){
						__SAFE_POINT
						if ((first->__get(i) != second->__get(i))){
							result = false;
							break;
						}
					}
				}
				return result;
			}
		};
		if (_Function_1_1::Block(keyCombo,this)){
			::org::casalib::events::KeyComboEvent keyComboSeq = ::org::casalib::events::KeyComboEvent_obj::__new(HX_STRING(L"sequence",8),null(),null());
			{
				keyComboSeq->_keyCombo = keyCombo;
				keyCombo;
			}
			this->dispatchEvent(keyComboSeq);
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Key_obj,_checkedTypedKeys,(void))

Void Key_obj::_checkDownKeys( ::org::casalib::ui::KeyCombo keyCombo){
{
		__SAFE_POINT
		struct _Function_1_1{
			inline static Array< int > Block( ::org::casalib::ui::KeyCombo &keyCombo)/* DEF (ret block)(not intern) */{
				Dynamic _g = hx::ClassOf< ::org::casalib::util::ArrayUtil >();
				Array< int > inArray = keyCombo->getKeyCodes();
				int i = 0;
				Array< int > cp = inArray->copy();
				Array< int > outArray = inArray->copy();
				{
					int _g1 = 0;
					while((_g1 < cp->length)){
						__SAFE_POINT
						int i1 = cp->__get(_g1);
						++_g1;
						{
							int _g2 = 1;
							int _g11 = ::org::casalib::util::ArrayUtil_obj::contains(outArray,i1);
							while((_g2 < _g11)){
								__SAFE_POINT
								int j = _g2++;
								outArray->remove(i1);
							}
						}
					}
				}
				return outArray;
			}
		};
		Array< int > uniqueCombo = _Function_1_1::Block(keyCombo);
		int i = uniqueCombo->length;
		while((i-- > 0))if (!this->_keysDown->get(uniqueCombo->__get(i)).Cast< bool >())
			return null();
		::org::casalib::events::KeyComboEvent keyComboDown = ::org::casalib::events::KeyComboEvent_obj::__new(HX_STRING(L"down",4),null(),null());
		{
			keyComboDown->_keyCombo = keyCombo;
			keyCombo;
		}
		this->_combosDown->push(keyCombo);
		this->dispatchEvent(keyComboDown);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Key_obj,_checkDownKeys,(void))

::org::casalib::ui::Key Key_obj::_instance;

::org::casalib::ui::Key Key_obj::getInstance( ){
	if ((::org::casalib::ui::Key_obj::_instance == null()))
		::org::casalib::ui::Key_obj::_instance = ::org::casalib::ui::Key_obj::__new();
	return ::org::casalib::ui::Key_obj::_instance;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(Key_obj,getInstance,return )


Key_obj::Key_obj()
{
}

void Key_obj::__Mark()
{
	hx::MarkMember(_keysDown);
	hx::MarkMember(_keysTyped);
	hx::MarkMember(_combosDown);
	hx::MarkMember(_combinations);
	hx::MarkMember(_longestCombo);
	super::__Mark();
}

Dynamic Key_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 6:
		if (!memcmp(inName.__s,L"isDown",sizeof(wchar_t)*6) ) { return isDown_dyn(); }
		break;
	case 7:
		if (!memcmp(inName.__s,L"destroy",sizeof(wchar_t)*7) ) { return destroy_dyn(); }
		break;
	case 8:
		if (!memcmp(inName.__s,L"_onKeyUp",sizeof(wchar_t)*8) ) { return _onKeyUp_dyn(); }
		break;
	case 9:
		if (!memcmp(inName.__s,L"_instance",sizeof(wchar_t)*9) ) { return _instance; }
		if (!memcmp(inName.__s,L"_keysDown",sizeof(wchar_t)*9) ) { return _keysDown; }
		break;
	case 10:
		if (!memcmp(inName.__s,L"_keysTyped",sizeof(wchar_t)*10) ) { return _keysTyped; }
		if (!memcmp(inName.__s,L"_onKeyDown",sizeof(wchar_t)*10) ) { return _onKeyDown_dyn(); }
		break;
	case 11:
		if (!memcmp(inName.__s,L"getInstance",sizeof(wchar_t)*11) ) { return getInstance_dyn(); }
		if (!memcmp(inName.__s,L"_combosDown",sizeof(wchar_t)*11) ) { return _combosDown; }
		if (!memcmp(inName.__s,L"addKeyCombo",sizeof(wchar_t)*11) ) { return addKeyCombo_dyn(); }
		break;
	case 13:
		if (!memcmp(inName.__s,L"_combinations",sizeof(wchar_t)*13) ) { return _combinations; }
		if (!memcmp(inName.__s,L"_longestCombo",sizeof(wchar_t)*13) ) { return _longestCombo; }
		if (!memcmp(inName.__s,L"_onDeactivate",sizeof(wchar_t)*13) ) { return _onDeactivate_dyn(); }
		break;
	case 14:
		if (!memcmp(inName.__s,L"removeKeyCombo",sizeof(wchar_t)*14) ) { return removeKeyCombo_dyn(); }
		if (!memcmp(inName.__s,L"_checkDownKeys",sizeof(wchar_t)*14) ) { return _checkDownKeys_dyn(); }
		break;
	case 17:
		if (!memcmp(inName.__s,L"_checkedTypedKeys",sizeof(wchar_t)*17) ) { return _checkedTypedKeys_dyn(); }
	}
	return super::__Field(inName);
}

Dynamic Key_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	switch(inName.length) {
	case 9:
		if (!memcmp(inName.__s,L"_instance",sizeof(wchar_t)*9) ) { _instance=inValue.Cast< ::org::casalib::ui::Key >(); return inValue; }
		if (!memcmp(inName.__s,L"_keysDown",sizeof(wchar_t)*9) ) { _keysDown=inValue.Cast< ::IntHash >(); return inValue; }
		break;
	case 10:
		if (!memcmp(inName.__s,L"_keysTyped",sizeof(wchar_t)*10) ) { _keysTyped=inValue.Cast< Array< int > >(); return inValue; }
		break;
	case 11:
		if (!memcmp(inName.__s,L"_combosDown",sizeof(wchar_t)*11) ) { _combosDown=inValue.Cast< Array< ::org::casalib::ui::KeyCombo > >(); return inValue; }
		break;
	case 13:
		if (!memcmp(inName.__s,L"_combinations",sizeof(wchar_t)*13) ) { _combinations=inValue.Cast< Array< ::org::casalib::ui::KeyCombo > >(); return inValue; }
		if (!memcmp(inName.__s,L"_longestCombo",sizeof(wchar_t)*13) ) { _longestCombo=inValue.Cast< int >(); return inValue; }
	}
	return super::__SetField(inName,inValue);
}

void Key_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_STRING(L"_keysDown",9));
	outFields->push(HX_STRING(L"_keysTyped",10));
	outFields->push(HX_STRING(L"_combosDown",11));
	outFields->push(HX_STRING(L"_combinations",13));
	outFields->push(HX_STRING(L"_longestCombo",13));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_STRING(L"_instance",9),
	HX_STRING(L"getInstance",11),
	String(null()) };

static ::String sMemberFields[] = {
	HX_STRING(L"_keysDown",9),
	HX_STRING(L"_keysTyped",10),
	HX_STRING(L"_combosDown",11),
	HX_STRING(L"_combinations",13),
	HX_STRING(L"_longestCombo",13),
	HX_STRING(L"isDown",6),
	HX_STRING(L"addKeyCombo",11),
	HX_STRING(L"removeKeyCombo",14),
	HX_STRING(L"destroy",7),
	HX_STRING(L"_onKeyDown",10),
	HX_STRING(L"_onKeyUp",8),
	HX_STRING(L"_onDeactivate",13),
	HX_STRING(L"_checkedTypedKeys",17),
	HX_STRING(L"_checkDownKeys",14),
	String(null()) };

static void sMarkStatics() {
	hx::MarkMember(Key_obj::_instance);
};

Class Key_obj::__mClass;

void Key_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_STRING(L"org.casalib.ui.Key",18), hx::TCanCast< Key_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void Key_obj::__boot()
{
	hx::Static(_instance) = null();
}

} // end namespace org
} // end namespace casalib
} // end namespace ui
