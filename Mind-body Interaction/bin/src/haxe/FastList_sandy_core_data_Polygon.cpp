#include <hxcpp.h>

#ifndef INCLUDED_haxe_FastCell_sandy_core_data_Polygon
#include <haxe/FastCell_sandy_core_data_Polygon.h>
#endif
#ifndef INCLUDED_haxe_FastList_sandy_core_data_Polygon
#include <haxe/FastList_sandy_core_data_Polygon.h>
#endif
#ifndef INCLUDED_sandy_core_data_Polygon
#include <sandy/core/data/Polygon.h>
#endif
#ifndef INCLUDED_sandy_core_scenegraph_IDisplayable
#include <sandy/core/scenegraph/IDisplayable.h>
#endif
namespace haxe{

Void FastList_sandy_core_data_Polygon_obj::__construct()
{
{
}
;
	return null();
}

FastList_sandy_core_data_Polygon_obj::~FastList_sandy_core_data_Polygon_obj() { }

Dynamic FastList_sandy_core_data_Polygon_obj::__CreateEmpty() { return  new FastList_sandy_core_data_Polygon_obj; }
hx::ObjectPtr< FastList_sandy_core_data_Polygon_obj > FastList_sandy_core_data_Polygon_obj::__new()
{  hx::ObjectPtr< FastList_sandy_core_data_Polygon_obj > result = new FastList_sandy_core_data_Polygon_obj();
	result->__construct();
	return result;}

Dynamic FastList_sandy_core_data_Polygon_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< FastList_sandy_core_data_Polygon_obj > result = new FastList_sandy_core_data_Polygon_obj();
	result->__construct();
	return result;}

Void FastList_sandy_core_data_Polygon_obj::add( ::sandy::core::data::Polygon item){
{
		this->head = ::haxe::FastCell_sandy_core_data_Polygon_obj::__new(item,this->head);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(FastList_sandy_core_data_Polygon_obj,add,(void))

::sandy::core::data::Polygon FastList_sandy_core_data_Polygon_obj::first( ){
	return (this->head == null()) ? ::sandy::core::data::Polygon( null() ) : ::sandy::core::data::Polygon( this->head->elt );
}


HX_DEFINE_DYNAMIC_FUNC0(FastList_sandy_core_data_Polygon_obj,first,return )

::sandy::core::data::Polygon FastList_sandy_core_data_Polygon_obj::pop( ){
	::haxe::FastCell_sandy_core_data_Polygon k = this->head;
	if ((k == null())){
		return null();
	}
	else{
		this->head = k->next;
		return k->elt;
	}
}


HX_DEFINE_DYNAMIC_FUNC0(FastList_sandy_core_data_Polygon_obj,pop,return )

bool FastList_sandy_core_data_Polygon_obj::isEmpty( ){
	return ((this->head == null()));
}


HX_DEFINE_DYNAMIC_FUNC0(FastList_sandy_core_data_Polygon_obj,isEmpty,return )

bool FastList_sandy_core_data_Polygon_obj::remove( ::sandy::core::data::Polygon v){
	Dynamic prev = null();
	::haxe::FastCell_sandy_core_data_Polygon l = this->head;
	while((l != null())){
		__SAFE_POINT
		if ((l->elt == v)){
			if ((prev == null())){
				this->head = l->next;
			}
			else{
				prev->__FieldRef(HX_STRING(L"next",4)) = l->next;
			}
			break;
		}
		prev = l;
		l = l->next;
	}
	return ((l != null()));
}


HX_DEFINE_DYNAMIC_FUNC1(FastList_sandy_core_data_Polygon_obj,remove,return )

Dynamic FastList_sandy_core_data_Polygon_obj::iterator( ){
	Array< ::haxe::FastCell_sandy_core_data_Polygon > l = Array_obj< ::haxe::FastCell_sandy_core_data_Polygon >::__new().Add(this->head);
	struct _Function_1_1{
		inline static Dynamic Block( Array< ::haxe::FastCell_sandy_core_data_Polygon > &l){
			hx::Anon __result = hx::Anon_obj::Create();

			HX_BEGIN_LOCAL_FUNC1(_Function_2_1,Array< ::haxe::FastCell_sandy_core_data_Polygon >,l)
			bool run(){
{
					return (l->__get(0) != null());
				}
				return null();
			}
			HX_END_LOCAL_FUNC0(return)

			__result->Add(HX_STRING(L"hasNext",7) ,  Dynamic(new _Function_2_1(l)));

			HX_BEGIN_LOCAL_FUNC1(_Function_2_2,Array< ::haxe::FastCell_sandy_core_data_Polygon >,l)
			::sandy::core::data::Polygon run(){
{
					::haxe::FastCell_sandy_core_data_Polygon k = l->__get(0);
					l[0] = k->next;
					return k->elt;
				}
				return null();
			}
			HX_END_LOCAL_FUNC0(return)

			__result->Add(HX_STRING(L"next",4) ,  Dynamic(new _Function_2_2(l)));
			return __result;
		}
	};
	return _Function_1_1::Block(l);
}


HX_DEFINE_DYNAMIC_FUNC0(FastList_sandy_core_data_Polygon_obj,iterator,return )

::String FastList_sandy_core_data_Polygon_obj::toString( ){
	__SAFE_POINT
	Array< ::sandy::core::data::Polygon > a = Array_obj< ::sandy::core::data::Polygon >::__new();
	::haxe::FastCell_sandy_core_data_Polygon l = this->head;
	while((l != null())){
		__SAFE_POINT
		a->push(l->elt);
		l = l->next;
	}
	return (((HX_STRING(L"{",1) + a->join(HX_STRING(L",",1)))) + HX_STRING(L"}",1));
}


HX_DEFINE_DYNAMIC_FUNC0(FastList_sandy_core_data_Polygon_obj,toString,return )


FastList_sandy_core_data_Polygon_obj::FastList_sandy_core_data_Polygon_obj()
{
}

void FastList_sandy_core_data_Polygon_obj::__Mark()
{
	hx::MarkMember(head);
}

Dynamic FastList_sandy_core_data_Polygon_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 3:
		if (!memcmp(inName.__s,L"add",sizeof(wchar_t)*3) ) { return add_dyn(); }
		if (!memcmp(inName.__s,L"pop",sizeof(wchar_t)*3) ) { return pop_dyn(); }
		break;
	case 4:
		if (!memcmp(inName.__s,L"head",sizeof(wchar_t)*4) ) { return head; }
		break;
	case 5:
		if (!memcmp(inName.__s,L"first",sizeof(wchar_t)*5) ) { return first_dyn(); }
		break;
	case 6:
		if (!memcmp(inName.__s,L"remove",sizeof(wchar_t)*6) ) { return remove_dyn(); }
		break;
	case 7:
		if (!memcmp(inName.__s,L"isEmpty",sizeof(wchar_t)*7) ) { return isEmpty_dyn(); }
		break;
	case 8:
		if (!memcmp(inName.__s,L"iterator",sizeof(wchar_t)*8) ) { return iterator_dyn(); }
		if (!memcmp(inName.__s,L"toString",sizeof(wchar_t)*8) ) { return toString_dyn(); }
	}
	return super::__Field(inName);
}

Dynamic FastList_sandy_core_data_Polygon_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	switch(inName.length) {
	case 4:
		if (!memcmp(inName.__s,L"head",sizeof(wchar_t)*4) ) { head=inValue.Cast< ::haxe::FastCell_sandy_core_data_Polygon >(); return inValue; }
	}
	return super::__SetField(inName,inValue);
}

void FastList_sandy_core_data_Polygon_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_STRING(L"head",4));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_STRING(L"head",4),
	HX_STRING(L"add",3),
	HX_STRING(L"first",5),
	HX_STRING(L"pop",3),
	HX_STRING(L"isEmpty",7),
	HX_STRING(L"remove",6),
	HX_STRING(L"iterator",8),
	HX_STRING(L"toString",8),
	String(null()) };

static void sMarkStatics() {
};

Class FastList_sandy_core_data_Polygon_obj::__mClass;

void FastList_sandy_core_data_Polygon_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_STRING(L"haxe.FastList_sandy_core_data_Polygon",37), hx::TCanCast< FastList_sandy_core_data_Polygon_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void FastList_sandy_core_data_Polygon_obj::__boot()
{
}

} // end namespace haxe
