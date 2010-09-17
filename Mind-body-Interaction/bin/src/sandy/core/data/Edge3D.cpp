#include <hxcpp.h>

#ifndef INCLUDED_sandy_core_data_Edge3D
#include <sandy/core/data/Edge3D.h>
#endif
#ifndef INCLUDED_sandy_core_data_Vertex
#include <sandy/core/data/Vertex.h>
#endif
namespace sandy{
namespace core{
namespace data{

Void Edge3D_obj::__construct(int p_nVertexId1,int p_nVertexId2)
{
{
	this->vertexId1 = p_nVertexId1;
	this->vertexId2 = p_nVertexId2;
}
;
	return null();
}

Edge3D_obj::~Edge3D_obj() { }

Dynamic Edge3D_obj::__CreateEmpty() { return  new Edge3D_obj; }
hx::ObjectPtr< Edge3D_obj > Edge3D_obj::__new(int p_nVertexId1,int p_nVertexId2)
{  hx::ObjectPtr< Edge3D_obj > result = new Edge3D_obj();
	result->__construct(p_nVertexId1,p_nVertexId2);
	return result;}

Dynamic Edge3D_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Edge3D_obj > result = new Edge3D_obj();
	result->__construct(inArgs[0],inArgs[1]);
	return result;}

::sandy::core::data::Edge3D Edge3D_obj::clone( ){
	::sandy::core::data::Edge3D l_oEdge = ::sandy::core::data::Edge3D_obj::__new(this->vertexId1,this->vertexId2);
	return l_oEdge;
}


HX_DEFINE_DYNAMIC_FUNC0(Edge3D_obj,clone,return )


Edge3D_obj::Edge3D_obj()
{
}

void Edge3D_obj::__Mark()
{
	hx::MarkMember(vertexId1);
	hx::MarkMember(vertexId2);
	hx::MarkMember(vertex1);
	hx::MarkMember(vertex2);
}

Dynamic Edge3D_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 5:
		if (!memcmp(inName.__s,L"clone",sizeof(wchar_t)*5) ) { return clone_dyn(); }
		break;
	case 7:
		if (!memcmp(inName.__s,L"vertex1",sizeof(wchar_t)*7) ) { return vertex1; }
		if (!memcmp(inName.__s,L"vertex2",sizeof(wchar_t)*7) ) { return vertex2; }
		break;
	case 9:
		if (!memcmp(inName.__s,L"vertexId1",sizeof(wchar_t)*9) ) { return vertexId1; }
		if (!memcmp(inName.__s,L"vertexId2",sizeof(wchar_t)*9) ) { return vertexId2; }
	}
	return super::__Field(inName);
}

Dynamic Edge3D_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	switch(inName.length) {
	case 7:
		if (!memcmp(inName.__s,L"vertex1",sizeof(wchar_t)*7) ) { vertex1=inValue.Cast< ::sandy::core::data::Vertex >(); return inValue; }
		if (!memcmp(inName.__s,L"vertex2",sizeof(wchar_t)*7) ) { vertex2=inValue.Cast< ::sandy::core::data::Vertex >(); return inValue; }
		break;
	case 9:
		if (!memcmp(inName.__s,L"vertexId1",sizeof(wchar_t)*9) ) { vertexId1=inValue.Cast< int >(); return inValue; }
		if (!memcmp(inName.__s,L"vertexId2",sizeof(wchar_t)*9) ) { vertexId2=inValue.Cast< int >(); return inValue; }
	}
	return super::__SetField(inName,inValue);
}

void Edge3D_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_STRING(L"vertexId1",9));
	outFields->push(HX_STRING(L"vertexId2",9));
	outFields->push(HX_STRING(L"vertex1",7));
	outFields->push(HX_STRING(L"vertex2",7));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_STRING(L"vertexId1",9),
	HX_STRING(L"vertexId2",9),
	HX_STRING(L"vertex1",7),
	HX_STRING(L"vertex2",7),
	HX_STRING(L"clone",5),
	String(null()) };

static void sMarkStatics() {
};

Class Edge3D_obj::__mClass;

void Edge3D_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_STRING(L"sandy.core.data.Edge3D",22), hx::TCanCast< Edge3D_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void Edge3D_obj::__boot()
{
}

} // end namespace sandy
} // end namespace core
} // end namespace data
