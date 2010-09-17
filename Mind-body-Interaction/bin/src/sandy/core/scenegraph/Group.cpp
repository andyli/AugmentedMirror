#include <hxcpp.h>

#ifndef INCLUDED_Std
#include <Std.h>
#endif
#ifndef INCLUDED_sandy_core_data_Matrix4
#include <sandy/core/data/Matrix4.h>
#endif
#ifndef INCLUDED_sandy_core_scenegraph_ATransformable
#include <sandy/core/scenegraph/ATransformable.h>
#endif
#ifndef INCLUDED_sandy_core_scenegraph_Group
#include <sandy/core/scenegraph/Group.h>
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
#ifndef INCLUDED_sandy_core_scenegraph_TransformGroup
#include <sandy/core/scenegraph/TransformGroup.h>
#endif
#ifndef INCLUDED_sandy_view_Frustum
#include <sandy/view/Frustum.h>
#endif
namespace sandy{
namespace core{
namespace scenegraph{

Void Group_obj::__construct(Dynamic __o_p_sName)
{
::String p_sName = __o_p_sName.Default(HX_STRING(L"",0));
{
	super::__construct(p_sName);
}
;
	return null();
}

Group_obj::~Group_obj() { }

Dynamic Group_obj::__CreateEmpty() { return  new Group_obj; }
hx::ObjectPtr< Group_obj > Group_obj::__new(Dynamic __o_p_sName)
{  hx::ObjectPtr< Group_obj > result = new Group_obj();
	result->__construct(__o_p_sName);
	return result;}

Dynamic Group_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Group_obj > result = new Group_obj();
	result->__construct(inArgs[0]);
	return result;}

Void Group_obj::cull( ::sandy::view::Frustum p_oFrustum,::sandy::core::data::Matrix4 p_oViewMatrix,bool p_bChanged){
{
		__SAFE_POINT
		if ((this->__getVisible() == false)){
			this->culled = 2;
		}
		else{
			bool lChanged = (bool(p_bChanged) || bool(this->__getChanged()));
			{
				int _g = 0;
				Array< ::sandy::core::scenegraph::Node > _g1 = this->children;
				while((_g < _g1->length)){
					__SAFE_POINT
					::sandy::core::scenegraph::Node l_oNode = _g1->__get(_g);
					++_g;
					l_oNode->cull(p_oFrustum,p_oViewMatrix,lChanged);
				}
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC3(Group_obj,cull,(void))

::sandy::core::scenegraph::Group Group_obj::clone( ::String p_sName){
	__SAFE_POINT
	::sandy::core::scenegraph::Group l_oGroup = ::sandy::core::scenegraph::Group_obj::__new(p_sName);
	{
		int _g = 0;
		Array< ::sandy::core::scenegraph::Node > _g1 = this->children;
		while((_g < _g1->length)){
			__SAFE_POINT
			::sandy::core::scenegraph::Node l_oNode = _g1->__get(_g);
			++_g;
			if ((bool(::Std_obj::is(l_oNode,hx::ClassOf< ::sandy::core::scenegraph::Shape3D >())) || bool((bool(::Std_obj::is(l_oNode,hx::ClassOf< ::sandy::core::scenegraph::Group >())) || bool(::Std_obj::is(l_oNode,hx::ClassOf< ::sandy::core::scenegraph::TransformGroup >())))))){
				l_oGroup->addChild(l_oNode->__Field(HX_STRING(L"clone",5))((((p_sName + HX_STRING(L"_",1))) + l_oNode->name)));
			}
		}
	}
	return l_oGroup;
}


HX_DEFINE_DYNAMIC_FUNC1(Group_obj,clone,return )

::String Group_obj::toString( ){
	return (((HX_STRING(L"sandy.core.scenegraph.Group :[",30) + this->name)) + HX_STRING(L"]",1));
}


HX_DEFINE_DYNAMIC_FUNC0(Group_obj,toString,return )


Group_obj::Group_obj()
{
}

void Group_obj::__Mark()
{
	super::__Mark();
}

Dynamic Group_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 4:
		if (!memcmp(inName.__s,L"cull",sizeof(wchar_t)*4) ) { return cull_dyn(); }
		break;
	case 5:
		if (!memcmp(inName.__s,L"clone",sizeof(wchar_t)*5) ) { return clone_dyn(); }
		break;
	case 8:
		if (!memcmp(inName.__s,L"toString",sizeof(wchar_t)*8) ) { return toString_dyn(); }
	}
	return super::__Field(inName);
}

Dynamic Group_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	return super::__SetField(inName,inValue);
}

void Group_obj::__GetFields(Array< ::String> &outFields)
{
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_STRING(L"cull",4),
	HX_STRING(L"clone",5),
	HX_STRING(L"toString",8),
	String(null()) };

static void sMarkStatics() {
};

Class Group_obj::__mClass;

void Group_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_STRING(L"sandy.core.scenegraph.Group",27), hx::TCanCast< Group_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void Group_obj::__boot()
{
}

} // end namespace sandy
} // end namespace core
} // end namespace scenegraph
