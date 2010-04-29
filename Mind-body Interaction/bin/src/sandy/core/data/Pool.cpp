#include <hxcpp.h>

#ifndef INCLUDED_sandy_core_data_Point3D
#include <sandy/core/data/Point3D.h>
#endif
#ifndef INCLUDED_sandy_core_data_Pool
#include <sandy/core/data/Pool.h>
#endif
#ifndef INCLUDED_sandy_core_data_UVCoord
#include <sandy/core/data/UVCoord.h>
#endif
#ifndef INCLUDED_sandy_core_data_Vertex
#include <sandy/core/data/Vertex.h>
#endif
namespace sandy{
namespace core{
namespace data{

Void Pool_obj::__construct()
{
{
	if ((::sandy::core::data::Pool_obj::INSTANCE != null())){
		hx::Throw (HX_STRING(L"There *MUST* be single Pool instance.",37));
	}
	this->m_nSize = 300;
	this->m_aVertices = Array_obj< ::sandy::core::data::Vertex >::__new();
	this->m_nIdVertice = 0;
	this->m_aUV = Array_obj< ::sandy::core::data::UVCoord >::__new();
	this->m_nIdUV = 0;
	this->m_aPoint3Ds = Array_obj< ::sandy::core::data::Point3D >::__new();
	this->m_nIdPoint3D = 0;
	{
		int _g1 = 0;
		int _g = this->m_nSize;
		while((_g1 < _g)){
			__SAFE_POINT
			int i = _g1++;
			this->m_aVertices[i] = ::sandy::core::data::Vertex_obj::__new(null(),null(),null(),null(),null(),null());
			this->m_aUV[i] = ::sandy::core::data::UVCoord_obj::__new(null(),null());
			this->m_aPoint3Ds[i] = ::sandy::core::data::Point3D_obj::__new(null(),null(),null());
		}
	}
}
;
	return null();
}

Pool_obj::~Pool_obj() { }

Dynamic Pool_obj::__CreateEmpty() { return  new Pool_obj; }
hx::ObjectPtr< Pool_obj > Pool_obj::__new()
{  hx::ObjectPtr< Pool_obj > result = new Pool_obj();
	result->__construct();
	return result;}

Dynamic Pool_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Pool_obj > result = new Pool_obj();
	result->__construct();
	return result;}

Void Pool_obj::init( ){
{
		this->m_nIdVertice = this->m_nIdUV = this->m_nIdPoint3D = 0;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Pool_obj,init,(void))

::sandy::core::data::Vertex Pool_obj::__getNextVertex( ){
	if ((this->m_nIdVertice >= this->m_aVertices->length))
		this->m_aVertices[this->m_aVertices->length] = ::sandy::core::data::Vertex_obj::__new(null(),null(),null(),null(),null(),null());
	::sandy::core::data::Vertex l_oV = this->m_aVertices->__get(this->m_nIdVertice++);
	l_oV->projected = false;
	l_oV->transformed = false;
	return l_oV;
}


HX_DEFINE_DYNAMIC_FUNC0(Pool_obj,__getNextVertex,return )

::sandy::core::data::UVCoord Pool_obj::__getNextUV( ){
	if ((this->m_nIdUV >= this->m_aUV->length))
		this->m_aUV[this->m_aUV->length] = ::sandy::core::data::UVCoord_obj::__new(null(),null());
	return this->m_aUV->__get(this->m_nIdUV++);
}


HX_DEFINE_DYNAMIC_FUNC0(Pool_obj,__getNextUV,return )

::sandy::core::data::Point3D Pool_obj::__getNextPoint3D( ){
	if ((this->m_nIdPoint3D >= this->m_aPoint3Ds->length))
		this->m_aPoint3Ds[this->m_aPoint3Ds->length] = ::sandy::core::data::Point3D_obj::__new(null(),null(),null());
	return this->m_aPoint3Ds->__get(this->m_nIdPoint3D++);
}


HX_DEFINE_DYNAMIC_FUNC0(Pool_obj,__getNextPoint3D,return )

::sandy::core::data::Pool Pool_obj::INSTANCE;

::sandy::core::data::Pool Pool_obj::getInstance( ){
	if ((::sandy::core::data::Pool_obj::INSTANCE == null()))
		::sandy::core::data::Pool_obj::INSTANCE = ::sandy::core::data::Pool_obj::__new();
	return ::sandy::core::data::Pool_obj::INSTANCE;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(Pool_obj,getInstance,return )


Pool_obj::Pool_obj()
{
}

void Pool_obj::__Mark()
{
	hx::MarkMember(nextVertex);
	hx::MarkMember(nextUV);
	hx::MarkMember(nextPoint3D);
	hx::MarkMember(m_nSize);
	hx::MarkMember(m_aVertices);
	hx::MarkMember(m_nIdVertice);
	hx::MarkMember(m_aUV);
	hx::MarkMember(m_nIdUV);
	hx::MarkMember(m_aPoint3Ds);
	hx::MarkMember(m_nIdPoint3D);
}

Dynamic Pool_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 4:
		if (!memcmp(inName.__s,L"init",sizeof(wchar_t)*4) ) { return init_dyn(); }
		break;
	case 5:
		if (!memcmp(inName.__s,L"m_aUV",sizeof(wchar_t)*5) ) { return m_aUV; }
		break;
	case 6:
		if (!memcmp(inName.__s,L"nextUV",sizeof(wchar_t)*6) ) { return __getNextUV(); }
		break;
	case 7:
		if (!memcmp(inName.__s,L"m_nSize",sizeof(wchar_t)*7) ) { return m_nSize; }
		if (!memcmp(inName.__s,L"m_nIdUV",sizeof(wchar_t)*7) ) { return m_nIdUV; }
		break;
	case 8:
		if (!memcmp(inName.__s,L"INSTANCE",sizeof(wchar_t)*8) ) { return INSTANCE; }
		break;
	case 10:
		if (!memcmp(inName.__s,L"nextVertex",sizeof(wchar_t)*10) ) { return __getNextVertex(); }
		break;
	case 11:
		if (!memcmp(inName.__s,L"getInstance",sizeof(wchar_t)*11) ) { return getInstance_dyn(); }
		if (!memcmp(inName.__s,L"nextPoint3D",sizeof(wchar_t)*11) ) { return __getNextPoint3D(); }
		if (!memcmp(inName.__s,L"m_aVertices",sizeof(wchar_t)*11) ) { return m_aVertices; }
		if (!memcmp(inName.__s,L"m_aPoint3Ds",sizeof(wchar_t)*11) ) { return m_aPoint3Ds; }
		if (!memcmp(inName.__s,L"__getNextUV",sizeof(wchar_t)*11) ) { return __getNextUV_dyn(); }
		break;
	case 12:
		if (!memcmp(inName.__s,L"m_nIdVertice",sizeof(wchar_t)*12) ) { return m_nIdVertice; }
		if (!memcmp(inName.__s,L"m_nIdPoint3D",sizeof(wchar_t)*12) ) { return m_nIdPoint3D; }
		break;
	case 15:
		if (!memcmp(inName.__s,L"__getNextVertex",sizeof(wchar_t)*15) ) { return __getNextVertex_dyn(); }
		break;
	case 16:
		if (!memcmp(inName.__s,L"__getNextPoint3D",sizeof(wchar_t)*16) ) { return __getNextPoint3D_dyn(); }
	}
	return super::__Field(inName);
}

Dynamic Pool_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	switch(inName.length) {
	case 5:
		if (!memcmp(inName.__s,L"m_aUV",sizeof(wchar_t)*5) ) { m_aUV=inValue.Cast< Array< ::sandy::core::data::UVCoord > >(); return inValue; }
		break;
	case 6:
		if (!memcmp(inName.__s,L"nextUV",sizeof(wchar_t)*6) ) { nextUV=inValue.Cast< ::sandy::core::data::UVCoord >(); return inValue; }
		break;
	case 7:
		if (!memcmp(inName.__s,L"m_nSize",sizeof(wchar_t)*7) ) { m_nSize=inValue.Cast< int >(); return inValue; }
		if (!memcmp(inName.__s,L"m_nIdUV",sizeof(wchar_t)*7) ) { m_nIdUV=inValue.Cast< int >(); return inValue; }
		break;
	case 8:
		if (!memcmp(inName.__s,L"INSTANCE",sizeof(wchar_t)*8) ) { INSTANCE=inValue.Cast< ::sandy::core::data::Pool >(); return inValue; }
		break;
	case 10:
		if (!memcmp(inName.__s,L"nextVertex",sizeof(wchar_t)*10) ) { nextVertex=inValue.Cast< ::sandy::core::data::Vertex >(); return inValue; }
		break;
	case 11:
		if (!memcmp(inName.__s,L"nextPoint3D",sizeof(wchar_t)*11) ) { nextPoint3D=inValue.Cast< ::sandy::core::data::Point3D >(); return inValue; }
		if (!memcmp(inName.__s,L"m_aVertices",sizeof(wchar_t)*11) ) { m_aVertices=inValue.Cast< Array< ::sandy::core::data::Vertex > >(); return inValue; }
		if (!memcmp(inName.__s,L"m_aPoint3Ds",sizeof(wchar_t)*11) ) { m_aPoint3Ds=inValue.Cast< Array< ::sandy::core::data::Point3D > >(); return inValue; }
		break;
	case 12:
		if (!memcmp(inName.__s,L"m_nIdVertice",sizeof(wchar_t)*12) ) { m_nIdVertice=inValue.Cast< int >(); return inValue; }
		if (!memcmp(inName.__s,L"m_nIdPoint3D",sizeof(wchar_t)*12) ) { m_nIdPoint3D=inValue.Cast< int >(); return inValue; }
	}
	return super::__SetField(inName,inValue);
}

void Pool_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_STRING(L"nextVertex",10));
	outFields->push(HX_STRING(L"nextUV",6));
	outFields->push(HX_STRING(L"nextPoint3D",11));
	outFields->push(HX_STRING(L"m_nSize",7));
	outFields->push(HX_STRING(L"m_aVertices",11));
	outFields->push(HX_STRING(L"m_nIdVertice",12));
	outFields->push(HX_STRING(L"m_aUV",5));
	outFields->push(HX_STRING(L"m_nIdUV",7));
	outFields->push(HX_STRING(L"m_aPoint3Ds",11));
	outFields->push(HX_STRING(L"m_nIdPoint3D",12));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_STRING(L"INSTANCE",8),
	HX_STRING(L"getInstance",11),
	String(null()) };

static ::String sMemberFields[] = {
	HX_STRING(L"nextVertex",10),
	HX_STRING(L"nextUV",6),
	HX_STRING(L"nextPoint3D",11),
	HX_STRING(L"m_nSize",7),
	HX_STRING(L"m_aVertices",11),
	HX_STRING(L"m_nIdVertice",12),
	HX_STRING(L"m_aUV",5),
	HX_STRING(L"m_nIdUV",7),
	HX_STRING(L"m_aPoint3Ds",11),
	HX_STRING(L"m_nIdPoint3D",12),
	HX_STRING(L"init",4),
	HX_STRING(L"__getNextVertex",15),
	HX_STRING(L"__getNextUV",11),
	HX_STRING(L"__getNextPoint3D",16),
	String(null()) };

static void sMarkStatics() {
	hx::MarkMember(Pool_obj::INSTANCE);
};

Class Pool_obj::__mClass;

void Pool_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_STRING(L"sandy.core.data.Pool",20), hx::TCanCast< Pool_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void Pool_obj::__boot()
{
	hx::Static(INSTANCE);
}

} // end namespace sandy
} // end namespace core
} // end namespace data
