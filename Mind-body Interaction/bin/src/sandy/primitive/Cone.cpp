#include <hxcpp.h>

#ifndef INCLUDED_sandy_core_scenegraph_ATransformable
#include <sandy/core/scenegraph/ATransformable.h>
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
#ifndef INCLUDED_sandy_primitive_Cone
#include <sandy/primitive/Cone.h>
#endif
#ifndef INCLUDED_sandy_primitive_Cylinder
#include <sandy/primitive/Cylinder.h>
#endif
#ifndef INCLUDED_sandy_primitive_Primitive3D
#include <sandy/primitive/Primitive3D.h>
#endif
namespace sandy{
namespace primitive{

Void Cone_obj::__construct(::String p_sName,Dynamic __o_p_nRadius,Dynamic __o_p_nHeight,Dynamic __o_p_nSegmentsW,Dynamic __o_p_nSegmentsH)
{
double p_nRadius = __o_p_nRadius.Default(100.0);
double p_nHeight = __o_p_nHeight.Default(100.0);
int p_nSegmentsW = __o_p_nSegmentsW.Default(8);
int p_nSegmentsH = __o_p_nSegmentsH.Default(6);
{
	super::__construct(p_sName,p_nRadius,p_nHeight,p_nSegmentsW,p_nSegmentsH,0,null(),null(),null());
	this->setConvexFlag(true);
}
;
	return null();
}

Cone_obj::~Cone_obj() { }

Dynamic Cone_obj::__CreateEmpty() { return  new Cone_obj; }
hx::ObjectPtr< Cone_obj > Cone_obj::__new(::String p_sName,Dynamic __o_p_nRadius,Dynamic __o_p_nHeight,Dynamic __o_p_nSegmentsW,Dynamic __o_p_nSegmentsH)
{  hx::ObjectPtr< Cone_obj > result = new Cone_obj();
	result->__construct(p_sName,__o_p_nRadius,__o_p_nHeight,__o_p_nSegmentsW,__o_p_nSegmentsH);
	return result;}

Dynamic Cone_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Cone_obj > result = new Cone_obj();
	result->__construct(inArgs[0],inArgs[1],inArgs[2],inArgs[3],inArgs[4]);
	return result;}

hx::Object *Cone_obj::__ToInterface(const type_info &inType) {
	if (inType==typeid( ::sandy::primitive::Primitive3D_obj)) return operator ::sandy::primitive::Primitive3D_obj *();
	return super::__ToInterface(inType);
}

::sandy::core::scenegraph::Shape3D Cone_obj::clone( Dynamic __o_p_sName,Dynamic __o_p_bKeepTransform){
::String p_sName = __o_p_sName.Default(HX_STRING(L"",0));
bool p_bKeepTransform = __o_p_bKeepTransform.Default(false);
{
		__SAFE_POINT
		::sandy::primitive::Cone o = ::sandy::primitive::Cone_obj::__new(p_sName,this->radius,this->height,this->segmentsW,this->segmentsH);
		o->copy(this,p_bKeepTransform,false);
		return o;
	}
}


HX_DEFINE_DYNAMIC_FUNC2(Cone_obj,clone,return )

::String Cone_obj::toString( ){
	return HX_STRING(L"sandy.primitive.Cone",20);
}


HX_DEFINE_DYNAMIC_FUNC0(Cone_obj,toString,return )


Cone_obj::Cone_obj()
{
}

void Cone_obj::__Mark()
{
	super::__Mark();
}

Dynamic Cone_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 5:
		if (!memcmp(inName.__s,L"clone",sizeof(wchar_t)*5) ) { return clone_dyn(); }
		break;
	case 8:
		if (!memcmp(inName.__s,L"toString",sizeof(wchar_t)*8) ) { return toString_dyn(); }
	}
	return super::__Field(inName);
}

Dynamic Cone_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	return super::__SetField(inName,inValue);
}

void Cone_obj::__GetFields(Array< ::String> &outFields)
{
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_STRING(L"clone",5),
	HX_STRING(L"toString",8),
	String(null()) };

static void sMarkStatics() {
};

Class Cone_obj::__mClass;

void Cone_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_STRING(L"sandy.primitive.Cone",20), hx::TCanCast< Cone_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void Cone_obj::__boot()
{
}

} // end namespace sandy
} // end namespace primitive
