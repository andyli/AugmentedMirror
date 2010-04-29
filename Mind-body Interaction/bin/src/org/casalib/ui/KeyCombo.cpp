#include <hxcpp.h>

#ifndef INCLUDED_Std
#include <Std.h>
#endif
#ifndef INCLUDED_org_casalib_errors_ArrayContentsError
#include <org/casalib/errors/ArrayContentsError.h>
#endif
#ifndef INCLUDED_org_casalib_ui_KeyCombo
#include <org/casalib/ui/KeyCombo.h>
#endif
namespace org{
namespace casalib{
namespace ui{

Void KeyCombo_obj::__construct(Array< int > keyCodes)
{
{
	if ((keyCodes->length < 2))
		hx::Throw (::org::casalib::errors::ArrayContentsError_obj::__new());
	int l = keyCodes->length;
	while((l-- > 0))if (!(::Std_obj::is(keyCodes->__get(l),hx::ClassOf< ::Int >())))
		hx::Throw (::org::casalib::errors::ArrayContentsError_obj::__new());
	this->_keyCodes = keyCodes->copy();
}
;
	return null();
}

KeyCombo_obj::~KeyCombo_obj() { }

Dynamic KeyCombo_obj::__CreateEmpty() { return  new KeyCombo_obj; }
hx::ObjectPtr< KeyCombo_obj > KeyCombo_obj::__new(Array< int > keyCodes)
{  hx::ObjectPtr< KeyCombo_obj > result = new KeyCombo_obj();
	result->__construct(keyCodes);
	return result;}

Dynamic KeyCombo_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< KeyCombo_obj > result = new KeyCombo_obj();
	result->__construct(inArgs[0]);
	return result;}

Array< int > KeyCombo_obj::getKeyCodes( ){
	__SAFE_POINT
	return this->_keyCodes->copy();
}


HX_DEFINE_DYNAMIC_FUNC0(KeyCombo_obj,getKeyCodes,return )

bool KeyCombo_obj::equals( ::org::casalib::ui::KeyCombo keyCombo){
	__SAFE_POINT
	if ((keyCombo == this))
		return true;
	struct _Function_1_1{
		inline static bool Block( ::org::casalib::ui::KeyCombo_obj *__this,::org::casalib::ui::KeyCombo &keyCombo)/* DEF (ret block)(not intern) */{
			Array< int > first = __this->getKeyCodes();
			Array< int > second = keyCombo->getKeyCodes();
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
	return _Function_1_1::Block(this,keyCombo);
}


HX_DEFINE_DYNAMIC_FUNC1(KeyCombo_obj,equals,return )


KeyCombo_obj::KeyCombo_obj()
{
}

void KeyCombo_obj::__Mark()
{
	hx::MarkMember(keyCodes);
	hx::MarkMember(_keyCodes);
}

Dynamic KeyCombo_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 6:
		if (!memcmp(inName.__s,L"equals",sizeof(wchar_t)*6) ) { return equals_dyn(); }
		break;
	case 8:
		if (!memcmp(inName.__s,L"keyCodes",sizeof(wchar_t)*8) ) { return getKeyCodes(); }
		break;
	case 9:
		if (!memcmp(inName.__s,L"_keyCodes",sizeof(wchar_t)*9) ) { return _keyCodes; }
		break;
	case 11:
		if (!memcmp(inName.__s,L"getKeyCodes",sizeof(wchar_t)*11) ) { return getKeyCodes_dyn(); }
	}
	return super::__Field(inName);
}

Dynamic KeyCombo_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	switch(inName.length) {
	case 8:
		if (!memcmp(inName.__s,L"keyCodes",sizeof(wchar_t)*8) ) { keyCodes=inValue.Cast< Array< int > >(); return inValue; }
		break;
	case 9:
		if (!memcmp(inName.__s,L"_keyCodes",sizeof(wchar_t)*9) ) { _keyCodes=inValue.Cast< Array< int > >(); return inValue; }
	}
	return super::__SetField(inName,inValue);
}

void KeyCombo_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_STRING(L"keyCodes",8));
	outFields->push(HX_STRING(L"_keyCodes",9));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_STRING(L"keyCodes",8),
	HX_STRING(L"_keyCodes",9),
	HX_STRING(L"getKeyCodes",11),
	HX_STRING(L"equals",6),
	String(null()) };

static void sMarkStatics() {
};

Class KeyCombo_obj::__mClass;

void KeyCombo_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_STRING(L"org.casalib.ui.KeyCombo",23), hx::TCanCast< KeyCombo_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void KeyCombo_obj::__boot()
{
}

} // end namespace org
} // end namespace casalib
} // end namespace ui
