#include <hxcpp.h>

#ifndef INCLUDED_nme_geom_Point
#include <nme/geom/Point.h>
#endif
#ifndef INCLUDED_sandy_view_ViewPort
#include <sandy/view/ViewPort.h>
#endif
namespace sandy{
namespace view{

Void ViewPort_obj::__construct(int p_nW,int p_nH)
{
{
	this->offset = ::nme::geom::Point_obj::__new(null(),null());
	this->hasChanged = false;
	this->m_nW = 0;
	this->m_nW2 = 0;
	this->m_nH = 0;
	this->m_nH2 = 0;
	this->m_nRatio = 0.0;
	this->__setWidth(p_nW);
	this->__setHeight(p_nH);
}
;
	return null();
}

ViewPort_obj::~ViewPort_obj() { }

Dynamic ViewPort_obj::__CreateEmpty() { return  new ViewPort_obj; }
hx::ObjectPtr< ViewPort_obj > ViewPort_obj::__new(int p_nW,int p_nH)
{  hx::ObjectPtr< ViewPort_obj > result = new ViewPort_obj();
	result->__construct(p_nW,p_nH);
	return result;}

Dynamic ViewPort_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< ViewPort_obj > result = new ViewPort_obj();
	result->__construct(inArgs[0],inArgs[1]);
	return result;}

Void ViewPort_obj::update( ){
{
		this->m_nW2 = (double(this->m_nW) / double(2));
		this->m_nH2 = (double(this->m_nH) / double(2));
		this->m_nRatio = ((this->m_nH != 0)) ? double( (double(this->m_nW) / double(this->m_nH)) ) : double( 0 );
		this->hasChanged = true;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(ViewPort_obj,update,(void))

int ViewPort_obj::__getWidth( ){
	return this->m_nW;
}


HX_DEFINE_DYNAMIC_FUNC0(ViewPort_obj,__getWidth,return )

int ViewPort_obj::__getHeight( ){
	return this->m_nH;
}


HX_DEFINE_DYNAMIC_FUNC0(ViewPort_obj,__getHeight,return )

double ViewPort_obj::__getWidth2( ){
	return this->m_nW2;
}


HX_DEFINE_DYNAMIC_FUNC0(ViewPort_obj,__getWidth2,return )

double ViewPort_obj::__getHeight2( ){
	return this->m_nH2;
}


HX_DEFINE_DYNAMIC_FUNC0(ViewPort_obj,__getHeight2,return )

double ViewPort_obj::__getRatio( ){
	return this->m_nRatio;
}


HX_DEFINE_DYNAMIC_FUNC0(ViewPort_obj,__getRatio,return )

int ViewPort_obj::__setWidth( int p_nValue){
	__SAFE_POINT
	this->m_nW = p_nValue;
	this->update();
	return p_nValue;
}


HX_DEFINE_DYNAMIC_FUNC1(ViewPort_obj,__setWidth,return )

int ViewPort_obj::__setHeight( int p_nValue){
	__SAFE_POINT
	this->m_nH = p_nValue;
	this->update();
	return p_nValue;
}


HX_DEFINE_DYNAMIC_FUNC1(ViewPort_obj,__setHeight,return )


ViewPort_obj::ViewPort_obj()
{
}

void ViewPort_obj::__Mark()
{
	hx::MarkMember(offset);
	hx::MarkMember(hasChanged);
	hx::MarkMember(width);
	hx::MarkMember(height);
	hx::MarkMember(width2);
	hx::MarkMember(height2);
	hx::MarkMember(ratio);
	hx::MarkMember(m_nW);
	hx::MarkMember(m_nW2);
	hx::MarkMember(m_nH);
	hx::MarkMember(m_nH2);
	hx::MarkMember(m_nRatio);
}

Dynamic ViewPort_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 4:
		if (!memcmp(inName.__s,L"m_nW",sizeof(wchar_t)*4) ) { return m_nW; }
		if (!memcmp(inName.__s,L"m_nH",sizeof(wchar_t)*4) ) { return m_nH; }
		break;
	case 5:
		if (!memcmp(inName.__s,L"width",sizeof(wchar_t)*5) ) { return __getWidth(); }
		if (!memcmp(inName.__s,L"ratio",sizeof(wchar_t)*5) ) { return __getRatio(); }
		if (!memcmp(inName.__s,L"m_nW2",sizeof(wchar_t)*5) ) { return m_nW2; }
		if (!memcmp(inName.__s,L"m_nH2",sizeof(wchar_t)*5) ) { return m_nH2; }
		break;
	case 6:
		if (!memcmp(inName.__s,L"offset",sizeof(wchar_t)*6) ) { return offset; }
		if (!memcmp(inName.__s,L"update",sizeof(wchar_t)*6) ) { return update_dyn(); }
		if (!memcmp(inName.__s,L"height",sizeof(wchar_t)*6) ) { return __getHeight(); }
		if (!memcmp(inName.__s,L"width2",sizeof(wchar_t)*6) ) { return __getWidth2(); }
		break;
	case 7:
		if (!memcmp(inName.__s,L"height2",sizeof(wchar_t)*7) ) { return __getHeight2(); }
		break;
	case 8:
		if (!memcmp(inName.__s,L"m_nRatio",sizeof(wchar_t)*8) ) { return m_nRatio; }
		break;
	case 10:
		if (!memcmp(inName.__s,L"hasChanged",sizeof(wchar_t)*10) ) { return hasChanged; }
		if (!memcmp(inName.__s,L"__getWidth",sizeof(wchar_t)*10) ) { return __getWidth_dyn(); }
		if (!memcmp(inName.__s,L"__getRatio",sizeof(wchar_t)*10) ) { return __getRatio_dyn(); }
		if (!memcmp(inName.__s,L"__setWidth",sizeof(wchar_t)*10) ) { return __setWidth_dyn(); }
		break;
	case 11:
		if (!memcmp(inName.__s,L"__getHeight",sizeof(wchar_t)*11) ) { return __getHeight_dyn(); }
		if (!memcmp(inName.__s,L"__getWidth2",sizeof(wchar_t)*11) ) { return __getWidth2_dyn(); }
		if (!memcmp(inName.__s,L"__setHeight",sizeof(wchar_t)*11) ) { return __setHeight_dyn(); }
		break;
	case 12:
		if (!memcmp(inName.__s,L"__getHeight2",sizeof(wchar_t)*12) ) { return __getHeight2_dyn(); }
	}
	return super::__Field(inName);
}

Dynamic ViewPort_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	switch(inName.length) {
	case 4:
		if (!memcmp(inName.__s,L"m_nW",sizeof(wchar_t)*4) ) { m_nW=inValue.Cast< int >(); return inValue; }
		if (!memcmp(inName.__s,L"m_nH",sizeof(wchar_t)*4) ) { m_nH=inValue.Cast< int >(); return inValue; }
		break;
	case 5:
		if (!memcmp(inName.__s,L"width",sizeof(wchar_t)*5) ) { return __setWidth(inValue); }
		if (!memcmp(inName.__s,L"ratio",sizeof(wchar_t)*5) ) { ratio=inValue.Cast< double >(); return inValue; }
		if (!memcmp(inName.__s,L"m_nW2",sizeof(wchar_t)*5) ) { m_nW2=inValue.Cast< double >(); return inValue; }
		if (!memcmp(inName.__s,L"m_nH2",sizeof(wchar_t)*5) ) { m_nH2=inValue.Cast< double >(); return inValue; }
		break;
	case 6:
		if (!memcmp(inName.__s,L"offset",sizeof(wchar_t)*6) ) { offset=inValue.Cast< ::nme::geom::Point >(); return inValue; }
		if (!memcmp(inName.__s,L"height",sizeof(wchar_t)*6) ) { return __setHeight(inValue); }
		if (!memcmp(inName.__s,L"width2",sizeof(wchar_t)*6) ) { width2=inValue.Cast< double >(); return inValue; }
		break;
	case 7:
		if (!memcmp(inName.__s,L"height2",sizeof(wchar_t)*7) ) { height2=inValue.Cast< double >(); return inValue; }
		break;
	case 8:
		if (!memcmp(inName.__s,L"m_nRatio",sizeof(wchar_t)*8) ) { m_nRatio=inValue.Cast< double >(); return inValue; }
		break;
	case 10:
		if (!memcmp(inName.__s,L"hasChanged",sizeof(wchar_t)*10) ) { hasChanged=inValue.Cast< bool >(); return inValue; }
	}
	return super::__SetField(inName,inValue);
}

void ViewPort_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_STRING(L"offset",6));
	outFields->push(HX_STRING(L"hasChanged",10));
	outFields->push(HX_STRING(L"width",5));
	outFields->push(HX_STRING(L"height",6));
	outFields->push(HX_STRING(L"width2",6));
	outFields->push(HX_STRING(L"height2",7));
	outFields->push(HX_STRING(L"ratio",5));
	outFields->push(HX_STRING(L"m_nW",4));
	outFields->push(HX_STRING(L"m_nW2",5));
	outFields->push(HX_STRING(L"m_nH",4));
	outFields->push(HX_STRING(L"m_nH2",5));
	outFields->push(HX_STRING(L"m_nRatio",8));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_STRING(L"offset",6),
	HX_STRING(L"hasChanged",10),
	HX_STRING(L"update",6),
	HX_STRING(L"width",5),
	HX_STRING(L"__getWidth",10),
	HX_STRING(L"height",6),
	HX_STRING(L"__getHeight",11),
	HX_STRING(L"width2",6),
	HX_STRING(L"__getWidth2",11),
	HX_STRING(L"height2",7),
	HX_STRING(L"__getHeight2",12),
	HX_STRING(L"ratio",5),
	HX_STRING(L"__getRatio",10),
	HX_STRING(L"__setWidth",10),
	HX_STRING(L"__setHeight",11),
	HX_STRING(L"m_nW",4),
	HX_STRING(L"m_nW2",5),
	HX_STRING(L"m_nH",4),
	HX_STRING(L"m_nH2",5),
	HX_STRING(L"m_nRatio",8),
	String(null()) };

static void sMarkStatics() {
};

Class ViewPort_obj::__mClass;

void ViewPort_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_STRING(L"sandy.view.ViewPort",19), hx::TCanCast< ViewPort_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void ViewPort_obj::__boot()
{
}

} // end namespace sandy
} // end namespace view
