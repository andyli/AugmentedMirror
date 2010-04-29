#include <hxcpp.h>

#ifndef INCLUDED_Reflect
#include <Reflect.h>
#endif
#ifndef INCLUDED_Std
#include <Std.h>
#endif
#ifndef INCLUDED_sandy_ObjectMap
#include <sandy/ObjectMap.h>
#endif
#ifndef INCLUDED_sandy_bounds_BBox
#include <sandy/bounds/BBox.h>
#endif
#ifndef INCLUDED_sandy_bounds_BSphere
#include <sandy/bounds/BSphere.h>
#endif
#ifndef INCLUDED_sandy_core_data_Matrix4
#include <sandy/core/data/Matrix4.h>
#endif
#ifndef INCLUDED_sandy_core_data_Point3D
#include <sandy/core/data/Point3D.h>
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

Void TransformGroup_obj::__construct(Dynamic __o_p_sName)
{
::String p_sName = __o_p_sName.Default(HX_STRING(L"",0));
{
	super::__construct(p_sName);
	this->m_dChildBounds = ::sandy::ObjectMap_obj::__new(null());
}
;
	return null();
}

TransformGroup_obj::~TransformGroup_obj() { }

Dynamic TransformGroup_obj::__CreateEmpty() { return  new TransformGroup_obj; }
hx::ObjectPtr< TransformGroup_obj > TransformGroup_obj::__new(Dynamic __o_p_sName)
{  hx::ObjectPtr< TransformGroup_obj > result = new TransformGroup_obj();
	result->__construct(__o_p_sName);
	return result;}

Dynamic TransformGroup_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< TransformGroup_obj > result = new TransformGroup_obj();
	result->__construct(inArgs[0]);
	return result;}

Void TransformGroup_obj::addChild( ::sandy::core::scenegraph::Node p_oChild){
{
		__SAFE_POINT
		this->super::addChild(p_oChild);
		this->updateChildBoundsCache(p_oChild);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(TransformGroup_obj,addChild,(void))

Void TransformGroup_obj::cull( ::sandy::view::Frustum p_oFrustum,::sandy::core::data::Matrix4 p_oViewMatrix,bool p_bChanged){
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


HX_DEFINE_DYNAMIC_FUNC3(TransformGroup_obj,cull,(void))

::sandy::core::scenegraph::TransformGroup TransformGroup_obj::clone( ::String p_sName){
	__SAFE_POINT
	::sandy::core::scenegraph::TransformGroup l_oGroup = ::sandy::core::scenegraph::TransformGroup_obj::__new(p_sName);
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


HX_DEFINE_DYNAMIC_FUNC1(TransformGroup_obj,clone,return )

Void TransformGroup_obj::destroy( ){
{
		__SAFE_POINT
		this->super::destroy();
		for(Dynamic __it = this->m_dChildBounds->iterator();  __it->__Field(HX_STRING(L"hasNext",7))(); ){
::sandy::core::scenegraph::Node k = __it->__Field(HX_STRING(L"next",4))();
			{
				::sandy::ObjectMap _g = this->m_dChildBounds;
				int idx = _g->getTagIndex(k);
				if ((idx >= 0)){
					_g->m_keys[idx] = null();
					_g->m_values[idx] = null();
				}
				::Reflect_obj::deleteField(k,HX_STRING(L"__{ObjectMapTag}",16));
			}
;
			__SAFE_POINT
		}
		this->m_dChildBounds = null();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(TransformGroup_obj,destroy,(void))

Void TransformGroup_obj::onChildBoundsChanged( ::sandy::core::scenegraph::Node child){
{
		__SAFE_POINT
		if (this->m_bUpdatingBounds)
			return null();
		this->updateChildBoundsCache(child);
		this->boundingBox->reset();
		struct _Function_1_1{
			inline static ::sandy::bounds::BBox Block( ::sandy::core::scenegraph::TransformGroup_obj *__this,::sandy::core::scenegraph::Node &key)/* DEF (ret block)(not intern) */{
				::sandy::ObjectMap _g = __this->m_dChildBounds;
				int idx = _g->getTagIndex(key);
				return ((idx < 0)) ? Dynamic( null() ) : Dynamic( _g->m_values->__get(idx) );
			}
		};
		for(Dynamic __it = this->m_dChildBounds->iterator();  __it->__Field(HX_STRING(L"hasNext",7))(); ){
::sandy::core::scenegraph::Node key = __it->__Field(HX_STRING(L"next",4))();
			this->boundingBox->merge(_Function_1_1::Block(this,key));
			__SAFE_POINT
		}
		this->boundingSphere->resetFromBox(this->boundingBox);
		if ((this->__getParent() != null()))
			this->__getParent()->onChildBoundsChanged(this);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(TransformGroup_obj,onChildBoundsChanged,(void))

::sandy::core::scenegraph::Node TransformGroup_obj::removeChild( ::sandy::core::scenegraph::Node p_oNode){
	__SAFE_POINT
	::sandy::core::scenegraph::Node rv = this->super::removeChild(p_oNode);
	{
		::sandy::ObjectMap _g = this->m_dChildBounds;
		int idx = _g->getTagIndex(p_oNode);
		if ((idx >= 0)){
			_g->m_keys[idx] = null();
			_g->m_values[idx] = null();
		}
		::Reflect_obj::deleteField(p_oNode,HX_STRING(L"__{ObjectMapTag}",16));
	}
	return rv;
}


HX_DEFINE_DYNAMIC_FUNC1(TransformGroup_obj,removeChild,return )

::sandy::core::scenegraph::Node TransformGroup_obj::removeChildByName( ::String p_sName){
	__SAFE_POINT
	::sandy::core::scenegraph::Node rv = this->super::removeChildByName(p_sName);
	if ((rv != null())){
		::sandy::ObjectMap _g = this->m_dChildBounds;
		int idx = _g->getTagIndex(rv);
		if ((idx >= 0)){
			_g->m_keys[idx] = null();
			_g->m_values[idx] = null();
		}
		::Reflect_obj::deleteField(rv,HX_STRING(L"__{ObjectMapTag}",16));
	}
	return rv;
}


HX_DEFINE_DYNAMIC_FUNC1(TransformGroup_obj,removeChildByName,return )

::String TransformGroup_obj::toString( ){
	return (((HX_STRING(L"sandy.core.scenegraph.TransformGroup :[",39) + this->name)) + HX_STRING(L"]",1));
}


HX_DEFINE_DYNAMIC_FUNC0(TransformGroup_obj,toString,return )

Void TransformGroup_obj::updateBoundingVolumes( ){
{
		__SAFE_POINT
		this->m_bUpdatingBounds = true;
		this->boundingBox->reset();
		{
			int _g = 0;
			Array< ::sandy::core::scenegraph::Node > _g1 = this->children;
			while((_g < _g1->length)){
				__SAFE_POINT
				::sandy::core::scenegraph::Node child = _g1->__get(_g);
				++_g;
				child->updateBoundingVolumes();
				this->boundingBox->merge(this->updateChildBoundsCache(child));
			}
		}
		this->boundingSphere->resetFromBox(this->boundingBox);
		this->m_bUpdatingBounds = false;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(TransformGroup_obj,updateBoundingVolumes,(void))

::sandy::bounds::BBox TransformGroup_obj::updateChildBoundsCache( ::sandy::core::scenegraph::Node child){
	__SAFE_POINT
	struct _Function_1_1{
		inline static ::sandy::bounds::BBox Block( ::sandy::core::scenegraph::TransformGroup_obj *__this,::sandy::core::scenegraph::Node &child)/* DEF (ret block)(not intern) */{
			::sandy::ObjectMap _g = __this->m_dChildBounds;
			int idx = _g->getTagIndex(child);
			return ((idx < 0)) ? Dynamic( null() ) : Dynamic( _g->m_values->__get(idx) );
		}
	};
	::sandy::bounds::BBox box = _Function_1_1::Block(this,child);
	if ((box == null())){
		box = ::sandy::bounds::BBox_obj::__new(null(),null());
		{
			::sandy::ObjectMap _g = this->m_dChildBounds;
			int idx = _g->getTagIndex(child);
			if ((idx < 0)){
				_g->m_values[idx] = box;
			}
			else{
				_g->m_keys->push(child);
				if ((child != null())){
					child->__SetField(HX_STRING(L"__{ObjectMapTag}",16),(_g->m_values->push(box) - 1));
				}
				else{
					{};
				}
			}
		}
	}
	box->copy(child->boundingBox);
	return box;
}


HX_DEFINE_DYNAMIC_FUNC1(TransformGroup_obj,updateChildBoundsCache,return )


TransformGroup_obj::TransformGroup_obj()
{
}

void TransformGroup_obj::__Mark()
{
	hx::MarkMember(trackBounds);
	hx::MarkMember(m_dChildBounds);
	hx::MarkMember(m_bUpdatingBounds);
	super::__Mark();
}

Dynamic TransformGroup_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 4:
		if (!memcmp(inName.__s,L"cull",sizeof(wchar_t)*4) ) { return cull_dyn(); }
		break;
	case 5:
		if (!memcmp(inName.__s,L"clone",sizeof(wchar_t)*5) ) { return clone_dyn(); }
		break;
	case 7:
		if (!memcmp(inName.__s,L"destroy",sizeof(wchar_t)*7) ) { return destroy_dyn(); }
		break;
	case 8:
		if (!memcmp(inName.__s,L"addChild",sizeof(wchar_t)*8) ) { return addChild_dyn(); }
		if (!memcmp(inName.__s,L"toString",sizeof(wchar_t)*8) ) { return toString_dyn(); }
		break;
	case 11:
		if (!memcmp(inName.__s,L"trackBounds",sizeof(wchar_t)*11) ) { return trackBounds; }
		if (!memcmp(inName.__s,L"removeChild",sizeof(wchar_t)*11) ) { return removeChild_dyn(); }
		break;
	case 14:
		if (!memcmp(inName.__s,L"m_dChildBounds",sizeof(wchar_t)*14) ) { return m_dChildBounds; }
		break;
	case 17:
		if (!memcmp(inName.__s,L"m_bUpdatingBounds",sizeof(wchar_t)*17) ) { return m_bUpdatingBounds; }
		if (!memcmp(inName.__s,L"removeChildByName",sizeof(wchar_t)*17) ) { return removeChildByName_dyn(); }
		break;
	case 20:
		if (!memcmp(inName.__s,L"onChildBoundsChanged",sizeof(wchar_t)*20) ) { return onChildBoundsChanged_dyn(); }
		break;
	case 21:
		if (!memcmp(inName.__s,L"updateBoundingVolumes",sizeof(wchar_t)*21) ) { return updateBoundingVolumes_dyn(); }
		break;
	case 22:
		if (!memcmp(inName.__s,L"updateChildBoundsCache",sizeof(wchar_t)*22) ) { return updateChildBoundsCache_dyn(); }
	}
	return super::__Field(inName);
}

Dynamic TransformGroup_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	switch(inName.length) {
	case 11:
		if (!memcmp(inName.__s,L"trackBounds",sizeof(wchar_t)*11) ) { trackBounds=inValue.Cast< bool >(); return inValue; }
		break;
	case 14:
		if (!memcmp(inName.__s,L"m_dChildBounds",sizeof(wchar_t)*14) ) { m_dChildBounds=inValue.Cast< ::sandy::ObjectMap >(); return inValue; }
		break;
	case 17:
		if (!memcmp(inName.__s,L"m_bUpdatingBounds",sizeof(wchar_t)*17) ) { m_bUpdatingBounds=inValue.Cast< bool >(); return inValue; }
	}
	return super::__SetField(inName,inValue);
}

void TransformGroup_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_STRING(L"trackBounds",11));
	outFields->push(HX_STRING(L"m_dChildBounds",14));
	outFields->push(HX_STRING(L"m_bUpdatingBounds",17));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_STRING(L"trackBounds",11),
	HX_STRING(L"m_dChildBounds",14),
	HX_STRING(L"m_bUpdatingBounds",17),
	HX_STRING(L"addChild",8),
	HX_STRING(L"cull",4),
	HX_STRING(L"clone",5),
	HX_STRING(L"destroy",7),
	HX_STRING(L"onChildBoundsChanged",20),
	HX_STRING(L"removeChild",11),
	HX_STRING(L"removeChildByName",17),
	HX_STRING(L"toString",8),
	HX_STRING(L"updateBoundingVolumes",21),
	HX_STRING(L"updateChildBoundsCache",22),
	String(null()) };

static void sMarkStatics() {
};

Class TransformGroup_obj::__mClass;

void TransformGroup_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_STRING(L"sandy.core.scenegraph.TransformGroup",36), hx::TCanCast< TransformGroup_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void TransformGroup_obj::__boot()
{
}

} // end namespace sandy
} // end namespace core
} // end namespace scenegraph
