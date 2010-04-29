#include <hxcpp.h>

#ifndef INCLUDED_haxe_Log
#include <haxe/Log.h>
#endif
#ifndef INCLUDED_sandy_core_data_Point3D
#include <sandy/core/data/Point3D.h>
#endif
#ifndef INCLUDED_sandy_core_scenegraph_ATransformable
#include <sandy/core/scenegraph/ATransformable.h>
#endif
#ifndef INCLUDED_sandy_core_scenegraph_Geometry3D
#include <sandy/core/scenegraph/Geometry3D.h>
#endif
#ifndef INCLUDED_sandy_core_scenegraph_IDisplayable
#include <sandy/core/scenegraph/IDisplayable.h>
#endif
#ifndef INCLUDED_sandy_core_scenegraph_Node
#include <sandy/core/scenegraph/Node.h>
#endif
#ifndef INCLUDED_sandy_core_scenegraph_Shape3D
#include <sandy/core/scenegraph/Shape3D.h>
#endif
#ifndef INCLUDED_sandy_materials_Appearance
#include <sandy/materials/Appearance.h>
#endif
#ifndef INCLUDED_sandy_primitive_Line3D
#include <sandy/primitive/Line3D.h>
#endif
#ifndef INCLUDED_sandy_primitive_Primitive3D
#include <sandy/primitive/Primitive3D.h>
#endif
namespace sandy{
namespace primitive{

Void Line3D_obj::__construct(::String p_sName,Array< ::sandy::core::data::Point3D > rest)
{
{
	super::__construct(p_sName,null(),null(),null());
	if ((rest->length < 2)){
		struct _Function_2_1{
			inline static Dynamic Block( ){
				hx::Anon __result = hx::Anon_obj::Create();
				__result->Add(HX_STRING(L"fileName",8) , HX_STRING(L"Line3D.hx",9));
				__result->Add(HX_STRING(L"lineNumber",10) , 47);
				__result->Add(HX_STRING(L"className",9) , HX_STRING(L"sandy.primitive.Line3D",22));
				__result->Add(HX_STRING(L"methodName",10) , HX_STRING(L"new",3));
				return __result;
			}
		};
		::haxe::Log_obj::trace(HX_STRING(L"Line3D::Too few arguments",25),_Function_2_1::Block());
	}
	else{
		this->rest_in = rest;
		this->__setGeometry(this->generate(rest));
		this->__setEnableBackFaceCulling(false);
	}
}
;
	return null();
}

Line3D_obj::~Line3D_obj() { }

Dynamic Line3D_obj::__CreateEmpty() { return  new Line3D_obj; }
hx::ObjectPtr< Line3D_obj > Line3D_obj::__new(::String p_sName,Array< ::sandy::core::data::Point3D > rest)
{  hx::ObjectPtr< Line3D_obj > result = new Line3D_obj();
	result->__construct(p_sName,rest);
	return result;}

Dynamic Line3D_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Line3D_obj > result = new Line3D_obj();
	result->__construct(inArgs[0],inArgs[1]);
	return result;}

hx::Object *Line3D_obj::__ToInterface(const type_info &inType) {
	if (inType==typeid( ::sandy::primitive::Primitive3D_obj)) return operator ::sandy::primitive::Primitive3D_obj *();
	return super::__ToInterface(inType);
}

::sandy::core::scenegraph::Shape3D Line3D_obj::clone( Dynamic __o_p_sName,Dynamic __o_p_bKeepTransform){
::String p_sName = __o_p_sName.Default(HX_STRING(L"",0));
bool p_bKeepTransform = __o_p_bKeepTransform.Default(false);
{
		__SAFE_POINT
		::sandy::primitive::Line3D o = ::sandy::primitive::Line3D_obj::__new(p_sName,this->rest_in);
		o->copy(this,p_bKeepTransform,false);
		return o;
	}
}


HX_DEFINE_DYNAMIC_FUNC2(Line3D_obj,clone,return )

::sandy::core::scenegraph::Geometry3D Line3D_obj::generate( Array< Dynamic > arguments){
	__SAFE_POINT
	if ((arguments == null()))
		arguments = Array_obj< Dynamic >::__new();
	::sandy::core::scenegraph::Geometry3D l_oGeometry = ::sandy::core::scenegraph::Geometry3D_obj::__new(null());
	Array< ::sandy::core::data::Point3D > l_aPoints = arguments;
	int i = 0;
	int l = l_aPoints->length;
	while((i < l)){
		__SAFE_POINT
		l_oGeometry->setVertex(i,l_aPoints[i]->x,l_aPoints[i]->y,l_aPoints[i]->z);
		i++;
	}
	i = 0;
	while((i < (l - 1))){
		__SAFE_POINT
		l_oGeometry->setFaceVertexIds(i,Array_obj< int >::__new().Add(i).Add((i + 1)));
		i++;
	}
	return l_oGeometry;
}


HX_DEFINE_DYNAMIC_FUNC1(Line3D_obj,generate,return )

::String Line3D_obj::toString( ){
	return HX_STRING(L"sandy.primitive.Line3D",22);
}


HX_DEFINE_DYNAMIC_FUNC0(Line3D_obj,toString,return )


Line3D_obj::Line3D_obj()
{
}

void Line3D_obj::__Mark()
{
	hx::MarkMember(rest_in);
	super::__Mark();
}

Dynamic Line3D_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 5:
		if (!memcmp(inName.__s,L"clone",sizeof(wchar_t)*5) ) { return clone_dyn(); }
		break;
	case 7:
		if (!memcmp(inName.__s,L"rest_in",sizeof(wchar_t)*7) ) { return rest_in; }
		break;
	case 8:
		if (!memcmp(inName.__s,L"generate",sizeof(wchar_t)*8) ) { return generate_dyn(); }
		if (!memcmp(inName.__s,L"toString",sizeof(wchar_t)*8) ) { return toString_dyn(); }
	}
	return super::__Field(inName);
}

Dynamic Line3D_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	switch(inName.length) {
	case 7:
		if (!memcmp(inName.__s,L"rest_in",sizeof(wchar_t)*7) ) { rest_in=inValue.Cast< Array< ::sandy::core::data::Point3D > >(); return inValue; }
	}
	return super::__SetField(inName,inValue);
}

void Line3D_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_STRING(L"rest_in",7));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_STRING(L"rest_in",7),
	HX_STRING(L"clone",5),
	HX_STRING(L"generate",8),
	HX_STRING(L"toString",8),
	String(null()) };

static void sMarkStatics() {
};

Class Line3D_obj::__mClass;

void Line3D_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_STRING(L"sandy.primitive.Line3D",22), hx::TCanCast< Line3D_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void Line3D_obj::__boot()
{
}

} // end namespace sandy
} // end namespace primitive
