#include <hxcpp.h>

#ifndef INCLUDED_Std
#include <Std.h>
#endif
#ifndef INCLUDED_neash_events_EventDispatcher
#include <neash/events/EventDispatcher.h>
#endif
#ifndef INCLUDED_neash_events_IEventDispatcher
#include <neash/events/IEventDispatcher.h>
#endif
#ifndef INCLUDED_sandy_bounds_BBox
#include <sandy/bounds/BBox.h>
#endif
#ifndef INCLUDED_sandy_bounds_BSphere
#include <sandy/bounds/BSphere.h>
#endif
#ifndef INCLUDED_sandy_core_Scene3D
#include <sandy/core/Scene3D.h>
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
#ifndef INCLUDED_sandy_core_scenegraph_IDisplayable
#include <sandy/core/scenegraph/IDisplayable.h>
#endif
#ifndef INCLUDED_sandy_core_scenegraph_INodeOperation
#include <sandy/core/scenegraph/INodeOperation.h>
#endif
#ifndef INCLUDED_sandy_core_scenegraph_Node
#include <sandy/core/scenegraph/Node.h>
#endif
#ifndef INCLUDED_sandy_core_scenegraph_Shape3D
#include <sandy/core/scenegraph/Shape3D.h>
#endif
#ifndef INCLUDED_sandy_events_BubbleEventBroadcaster
#include <sandy/events/BubbleEventBroadcaster.h>
#endif
#ifndef INCLUDED_sandy_events_EventBroadcaster
#include <sandy/events/EventBroadcaster.h>
#endif
#ifndef INCLUDED_sandy_materials_Appearance
#include <sandy/materials/Appearance.h>
#endif
#ifndef INCLUDED_sandy_view_Frustum
#include <sandy/view/Frustum.h>
#endif
namespace sandy{
namespace core{
namespace scenegraph{

Void Node_obj::__construct(::String p_sName)
{
{
	this->culled = 2;
	this->children = Array_obj< ::sandy::core::scenegraph::Node >::__new();
	this->modelMatrix = ::sandy::core::data::Matrix4_obj::__new(null(),null(),null(),null(),null(),null(),null(),null(),null(),null(),null(),null(),null(),null(),null(),null());
	this->viewMatrix = ::sandy::core::data::Matrix4_obj::__new(null(),null(),null(),null(),null(),null(),null(),null(),null(),null(),null(),null(),null(),null(),null(),null());
	this->boundingBox = ::sandy::bounds::BBox_obj::__new(null(),null());
	this->boundingSphere = ::sandy::bounds::BSphere_obj::__new();
	this->id = ::sandy::core::scenegraph::Node_obj::_ID_++;
	this->m_bVisible = true;
	this->__setParent(null());
	this->name = ((p_sName != null())) ? ::String( p_sName ) : ::String( ::Std_obj::string(this->id) );
	this->__setChanged(true);
	this->m_oEB = ::sandy::events::BubbleEventBroadcaster_obj::__new(this);
	this->culled = 1;
	this->__setScene(null());
	this->boundingBox->reset();
	this->boundingSphere->reset();
}
;
	return null();
}

Node_obj::~Node_obj() { }

Dynamic Node_obj::__CreateEmpty() { return  new Node_obj; }
hx::ObjectPtr< Node_obj > Node_obj::__new(::String p_sName)
{  hx::ObjectPtr< Node_obj > result = new Node_obj();
	result->__construct(p_sName);
	return result;}

Dynamic Node_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Node_obj > result = new Node_obj();
	result->__construct(inArgs[0]);
	return result;}

bool Node_obj::__getVisible( ){
	return this->m_bVisible;
}


HX_DEFINE_DYNAMIC_FUNC0(Node_obj,__getVisible,return )

bool Node_obj::__setVisible( bool p_bVisibility){
	__SAFE_POINT
	if ((this->m_bVisible == p_bVisibility))
		return p_bVisibility;
	this->m_bVisible = p_bVisibility;
	this->__setChanged(true);
	{
		int _g = 0;
		Array< ::sandy::core::scenegraph::Node > _g1 = this->children;
		while((_g < _g1->length)){
			__SAFE_POINT
			::sandy::core::scenegraph::Node node = _g1->__get(_g);
			++_g;
			node->__setChanged(true);
		}
	}
	return p_bVisibility;
}


HX_DEFINE_DYNAMIC_FUNC1(Node_obj,__setVisible,return )

::sandy::events::BubbleEventBroadcaster Node_obj::__getBroadcaster( ){
	return this->m_oEB;
}


HX_DEFINE_DYNAMIC_FUNC0(Node_obj,__getBroadcaster,return )

::sandy::events::BubbleEventBroadcaster Node_obj::__setBroadcaster( ::sandy::events::BubbleEventBroadcaster v){
	return this->m_oEB = v;
}


HX_DEFINE_DYNAMIC_FUNC1(Node_obj,__setBroadcaster,return )

Void Node_obj::addEventListener( ::String p_sEvt,Dynamic p_oL){
{
		__SAFE_POINT
		this->m_oEB->addEventListener(p_sEvt,p_oL,null(),null(),null());
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(Node_obj,addEventListener,(void))

Void Node_obj::removeEventListener( ::String p_sEvt,Dynamic p_oL){
{
		__SAFE_POINT
		this->m_oEB->removeEventListener(p_sEvt,p_oL,null());
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(Node_obj,removeEventListener,(void))

bool Node_obj::isParent( ::sandy::core::scenegraph::Node p_oNode){
	return ((bool((this->_parent == p_oNode)) && bool((p_oNode != null()))));
}


HX_DEFINE_DYNAMIC_FUNC1(Node_obj,isParent,return )

bool Node_obj::__getUseSingleContainer( ){
	return false;
}


HX_DEFINE_DYNAMIC_FUNC0(Node_obj,__getUseSingleContainer,return )

bool Node_obj::__setUseSingleContainer( bool p_bUseSingleContainer){
	__SAFE_POINT
	{
		int _g = 0;
		Array< ::sandy::core::scenegraph::Node > _g1 = this->children;
		while((_g < _g1->length)){
			__SAFE_POINT
			::sandy::core::scenegraph::Node l_oNode = _g1->__get(_g);
			++_g;
			l_oNode->__setUseSingleContainer(p_bUseSingleContainer);
		}
	}
	this->__setChanged(true);
	return p_bUseSingleContainer;
}


HX_DEFINE_DYNAMIC_FUNC1(Node_obj,__setUseSingleContainer,return )

bool Node_obj::__setEnableClipping( bool p_bUseClipping){
	__SAFE_POINT
	{
		int _g = 0;
		Array< ::sandy::core::scenegraph::Node > _g1 = this->children;
		while((_g < _g1->length)){
			__SAFE_POINT
			::sandy::core::scenegraph::Node l_oNode = _g1->__get(_g);
			++_g;
			struct _Function_3_1{
				inline static ::sandy::core::scenegraph::Shape3D Block( ::sandy::core::scenegraph::Node &l_oNode)/* DEF (ret block)(not intern) */{
					::sandy::core::scenegraph::Node tmp = l_oNode;
					return ::Std_obj::is(tmp,hx::ClassOf< ::sandy::core::scenegraph::Shape3D >()) ? ::sandy::core::scenegraph::Node( tmp ) : ::sandy::core::scenegraph::Node( hx::Throw (HX_STRING(L"Class cast error",16)) );
				}
			};
			_Function_3_1::Block(l_oNode)->__setEnableClipping(p_bUseClipping);
		}
	}
	this->__setChanged(true);
	return p_bUseClipping;
}


HX_DEFINE_DYNAMIC_FUNC1(Node_obj,__setEnableClipping,return )

bool Node_obj::__getEnableBackFaceCulling( ){
	return false;
}


HX_DEFINE_DYNAMIC_FUNC0(Node_obj,__getEnableBackFaceCulling,return )

bool Node_obj::__setEnableBackFaceCulling( bool b){
	__SAFE_POINT
	{
		int _g = 0;
		Array< ::sandy::core::scenegraph::Node > _g1 = this->children;
		while((_g < _g1->length)){
			__SAFE_POINT
			::sandy::core::scenegraph::Node l_onode = _g1->__get(_g);
			++_g;
			l_onode->__setEnableBackFaceCulling(b);
		}
	}
	this->__setChanged(true);
	return b;
}


HX_DEFINE_DYNAMIC_FUNC1(Node_obj,__setEnableBackFaceCulling,return )

bool Node_obj::__getEnableInteractivity( ){
	return false;
}


HX_DEFINE_DYNAMIC_FUNC0(Node_obj,__getEnableInteractivity,return )

bool Node_obj::__setEnableInteractivity( bool p_bState){
	__SAFE_POINT
	{
		int _g = 0;
		Array< ::sandy::core::scenegraph::Node > _g1 = this->children;
		while((_g < _g1->length)){
			__SAFE_POINT
			::sandy::core::scenegraph::Node l_oNode = _g1->__get(_g);
			++_g;
			l_oNode->__setEnableInteractivity(p_bState);
		}
	}
	return p_bState;
}


HX_DEFINE_DYNAMIC_FUNC1(Node_obj,__setEnableInteractivity,return )

bool Node_obj::__getEnableEvents( ){
	return false;
}


HX_DEFINE_DYNAMIC_FUNC0(Node_obj,__getEnableEvents,return )

bool Node_obj::__setEnableEvents( bool b){
	__SAFE_POINT
	{
		int _g = 0;
		Array< ::sandy::core::scenegraph::Node > _g1 = this->children;
		while((_g < _g1->length)){
			__SAFE_POINT
			::sandy::core::scenegraph::Node l_oNode = _g1->__get(_g);
			++_g;
			l_oNode->__setEnableEvents(b);
		}
	}
	return b;
}


HX_DEFINE_DYNAMIC_FUNC1(Node_obj,__setEnableEvents,return )

::sandy::materials::Appearance Node_obj::__getAppearance( ){
	return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Node_obj,__getAppearance,return )

::sandy::materials::Appearance Node_obj::__setAppearance( ::sandy::materials::Appearance p_oApp){
	__SAFE_POINT
	{
		int _g = 0;
		Array< ::sandy::core::scenegraph::Node > _g1 = this->children;
		while((_g < _g1->length)){
			__SAFE_POINT
			::sandy::core::scenegraph::Node l_oNode = _g1->__get(_g);
			++_g;
			l_oNode->__setAppearance(p_oApp);
		}
	}
	this->__setChanged(true);
	return p_oApp;
}


HX_DEFINE_DYNAMIC_FUNC1(Node_obj,__setAppearance,return )

::sandy::core::scenegraph::Node Node_obj::__setParent( ::sandy::core::scenegraph::Node p_oNode){
	__SAFE_POINT
	if ((p_oNode != null())){
		this->_parent = p_oNode;
		this->__setChanged(true);
	}
	return p_oNode;
}


HX_DEFINE_DYNAMIC_FUNC1(Node_obj,__setParent,return )

::sandy::core::scenegraph::Node Node_obj::__getParent( ){
	return this->_parent;
}


HX_DEFINE_DYNAMIC_FUNC0(Node_obj,__getParent,return )

bool Node_obj::hasParent( ){
	return ((this->_parent != null()));
}


HX_DEFINE_DYNAMIC_FUNC0(Node_obj,hasParent,return )

Void Node_obj::addChild( ::sandy::core::scenegraph::Node p_oChild){
{
		__SAFE_POINT
		if ((p_oChild->__getParent() != null())){
			p_oChild->__getParent()->removeChild(p_oChild);
		}
		p_oChild->__setParent(this);
		this->__setChanged(true);
		this->children->push(p_oChild);
		if ((p_oChild->__getBroadcaster() != null()))
			this->m_oEB->addChild(p_oChild->__getBroadcaster());
		if ((this->__getScene() != null()))
			p_oChild->__setScene(this->__getScene());
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Node_obj,addChild,(void))

::sandy::core::scenegraph::Node Node_obj::getChildByName( ::String p_sName,Dynamic __o_p_bRecurs){
bool p_bRecurs = __o_p_bRecurs.Default(false);
{
		__SAFE_POINT
		{
			int _g = 0;
			Array< ::sandy::core::scenegraph::Node > _g1 = this->children;
			while((_g < _g1->length)){
				__SAFE_POINT
				::sandy::core::scenegraph::Node l_oNode = _g1->__get(_g);
				++_g;
				if ((l_oNode->name == p_sName)){
					return l_oNode;
				}
			}
		}
		if (p_bRecurs){
			::sandy::core::scenegraph::Node node = null();
			{
				int _g = 0;
				Array< ::sandy::core::scenegraph::Node > _g1 = this->children;
				while((_g < _g1->length)){
					__SAFE_POINT
					::sandy::core::scenegraph::Node l_oNode = _g1->__get(_g);
					++_g;
					node = l_oNode->getChildByName(p_sName,p_bRecurs);
					if ((node != null())){
						return node;
					}
				}
			}
		}
		return null();
	}
}


HX_DEFINE_DYNAMIC_FUNC2(Node_obj,getChildByName,return )

Void Node_obj::swapParent( ::sandy::core::scenegraph::Node p_oNewParent){
{
		__SAFE_POINT
		if ((this->__getParent()->removeChild(this) != null())){
			p_oNewParent->addChild(this);
			this->__setChanged(true);
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Node_obj,swapParent,(void))

::sandy::core::scenegraph::Node Node_obj::removeChild( ::sandy::core::scenegraph::Node p_oNode){
	__SAFE_POINT
	::sandy::core::scenegraph::Node found = null();
	{
		int _g1 = 0;
		int _g = this->children->length;
		while((_g1 < _g)){
			__SAFE_POINT
			int i = _g1++;
			if ((this->children->__get(i) == p_oNode)){
				found = this->children->__get(i);
				this->__getBroadcaster()->removeChild(this->children[i]->__getBroadcaster());
				this->children->splice(i,1);
				this->__setChanged(true);
				break;
			}
		}
	}
	return found;
}


HX_DEFINE_DYNAMIC_FUNC1(Node_obj,removeChild,return )

::sandy::core::scenegraph::Node Node_obj::removeChildByName( ::String p_sName){
	__SAFE_POINT
	::sandy::core::scenegraph::Node found = null();
	{
		int _g1 = 0;
		int _g = this->children->length;
		while((_g1 < _g)){
			__SAFE_POINT
			int i = _g1++;
			if ((this->children[i]->name == p_sName)){
				found = this->children->__get(i);
				this->__getBroadcaster()->removeChild(this->children[i]->__getBroadcaster());
				this->children->splice(i,1);
				this->__setChanged(true);
				break;
			}
		}
	}
	return found;
}


HX_DEFINE_DYNAMIC_FUNC1(Node_obj,removeChildByName,return )

Void Node_obj::destroy( ){
{
		__SAFE_POINT
		if ((this->hasParent() == true))
			this->__getParent()->removeChild(this);
		if ((this->children != null())){
			Array< ::sandy::core::scenegraph::Node > l_aTmp = this->children->copy();
			{
				int _g = 0;
				while((_g < l_aTmp->length)){
					__SAFE_POINT
					::sandy::core::scenegraph::Node lNode = l_aTmp->__get(_g);
					++_g;
					lNode->destroy();
				}
			}
			this->children->splice(0,this->children->length);
			this->children = null();
			l_aTmp = null();
		}
		this->m_oEB = null();
		this->__setScene(null());
		this->__setParent(null());
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Node_obj,destroy,(void))

Void Node_obj::remove( ){
{
		__SAFE_POINT
		if (this->hasParent())
			this->__getParent()->removeChild(this);
		Array< ::sandy::core::scenegraph::Node > l_aTmp = this->children;
		{
			int _g = 0;
			while((_g < l_aTmp->length)){
				__SAFE_POINT
				::sandy::core::scenegraph::Node lNode = l_aTmp->__get(_g);
				++_g;
				this->__getParent()->addChild(lNode);
			}
		}
		this->children->splice(0,this->children->length);
		this->m_oEB = null();
		this->__setChanged(true);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Node_obj,remove,(void))

Void Node_obj::update( ::sandy::core::data::Matrix4 p_oModelMatrix,bool p_bChanged){
{
		__SAFE_POINT
		this->culled = 1;
		if ((this->boundingBox != null()))
			this->boundingBox->uptodate = false;
		if ((this->boundingSphere != null()))
			this->boundingSphere->uptodate = false;
		this->__setChanged((bool(this->__getChanged()) || bool(p_bChanged)));
		{
			int _g = 0;
			Array< ::sandy::core::scenegraph::Node > _g1 = this->children;
			while((_g < _g1->length)){
				__SAFE_POINT
				::sandy::core::scenegraph::Node l_oNode = _g1->__get(_g);
				++_g;
				l_oNode->update(p_oModelMatrix,this->__getChanged());
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(Node_obj,update,(void))

Void Node_obj::cull( ::sandy::view::Frustum p_oFrustum,::sandy::core::data::Matrix4 p_oViewMatrix,bool p_bChanged){
{
		__SAFE_POINT
		if ((this->__getVisible() == false)){
			this->culled = 2;
		}
		else{
			if ((bool(p_bChanged) || bool(this->__getChanged()))){
				this->viewMatrix->copy(p_oViewMatrix);
				this->viewMatrix->multiply4x3(this->modelMatrix);
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC3(Node_obj,cull,(void))

bool Node_obj::__getChanged( ){
	return this->m_bChanged;
}


HX_DEFINE_DYNAMIC_FUNC0(Node_obj,__getChanged,return )

bool Node_obj::__setChanged( bool pVal){
	this->m_bChanged = pVal;
	return pVal;
}


HX_DEFINE_DYNAMIC_FUNC1(Node_obj,__setChanged,return )

Void Node_obj::updateBoundingVolumes( ){
{
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Node_obj,updateBoundingVolumes,(void))

Void Node_obj::onChildBoundsChanged( ::sandy::core::scenegraph::Node p_oNode){
{
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Node_obj,onChildBoundsChanged,(void))

::sandy::core::Scene3D Node_obj::__getScene( ){
	return this->m_oScene;
}


HX_DEFINE_DYNAMIC_FUNC0(Node_obj,__getScene,return )

::sandy::core::Scene3D Node_obj::__setScene( ::sandy::core::Scene3D p_oScene){
	__SAFE_POINT
	if ((p_oScene == null()))
		return null();
	if ((this->m_oScene != null()))
		this->m_oScene->removeEventListener(HX_STRING(L"scene_render_finish",19),this->_updateFlags_dyn(),null());
	this->m_oScene = p_oScene;
	this->m_oScene->addEventListener(HX_STRING(L"scene_render_finish",19),this->_updateFlags_dyn(),null(),null(),null());
	{
		int _g = 0;
		Array< ::sandy::core::scenegraph::Node > _g1 = this->children;
		while((_g < _g1->length)){
			__SAFE_POINT
			::sandy::core::scenegraph::Node node = _g1->__get(_g);
			++_g;
			node->__setScene(this->m_oScene);
		}
	}
	return p_oScene;
}


HX_DEFINE_DYNAMIC_FUNC1(Node_obj,__setScene,return )

Void Node_obj::_updateFlags( Dynamic _){
{
		__SAFE_POINT
		this->__setChanged(false);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Node_obj,_updateFlags,(void))

Void Node_obj::perform( ::sandy::core::scenegraph::INodeOperation p_iOperation){
{
		__SAFE_POINT
		p_iOperation->performOnEntry(this);
		{
			int _g = 0;
			Array< ::sandy::core::scenegraph::Node > _g1 = this->children;
			while((_g < _g1->length)){
				__SAFE_POINT
				::sandy::core::scenegraph::Node l_oChild = _g1->__get(_g);
				++_g;
				l_oChild->perform(p_iOperation);
			}
		}
		p_iOperation->performOnExit(this);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Node_obj,perform,(void))

::String Node_obj::toString( ){
	return HX_STRING(L"sandy.core.scenegraph.Node",26);
}


HX_DEFINE_DYNAMIC_FUNC0(Node_obj,toString,return )

Void Node_obj::copy( ::sandy::core::scenegraph::Node src,Dynamic __o_includeTransforms,Dynamic __o_includeGeometry){
bool includeTransforms = __o_includeTransforms.Default(false);
bool includeGeometry = __o_includeGeometry.Default(true);
{
		__SAFE_POINT
		this->__setChanged(true);
		if (includeGeometry){
			this->boundingBox = src->boundingBox->clone();
			this->boundingSphere = src->boundingSphere->clone();
		}
		this->__setUseSingleContainer(src->__getUseSingleContainer());
		this->__setEnableBackFaceCulling(src->__getEnableBackFaceCulling());
		this->__setEnableEvents(src->__getEnableEvents());
		this->__setEnableInteractivity(src->__getEnableInteractivity());
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC3(Node_obj,copy,(void))

int Node_obj::_ID_;


Node_obj::Node_obj()
{
}

void Node_obj::__Mark()
{
	hx::MarkMember(appearance);
	hx::MarkMember(changed);
	hx::MarkMember(culled);
	hx::MarkMember(name);
	hx::MarkMember(broadcaster);
	hx::MarkMember(children);
	hx::MarkMember(enableBackFaceCulling);
	hx::MarkMember(enableEvents);
	hx::MarkMember(enableInteractivity);
	hx::MarkMember(modelMatrix);
	hx::MarkMember(parent);
	hx::MarkMember(viewMatrix);
	hx::MarkMember(boundingBox);
	hx::MarkMember(boundingSphere);
	hx::MarkMember(id);
	hx::MarkMember(useSingleContainer);
	hx::MarkMember(visible);
	hx::MarkMember(scene);
	hx::MarkMember(m_bVisible);
	hx::MarkMember(m_bChanged);
	hx::MarkMember(m_oScene);
	hx::MarkMember(_parent);
	hx::MarkMember(m_oEB);
}

Dynamic Node_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 2:
		if (!memcmp(inName.__s,L"id",sizeof(wchar_t)*2) ) { return id; }
		break;
	case 4:
		if (!memcmp(inName.__s,L"_ID_",sizeof(wchar_t)*4) ) { return _ID_; }
		if (!memcmp(inName.__s,L"name",sizeof(wchar_t)*4) ) { return name; }
		if (!memcmp(inName.__s,L"cull",sizeof(wchar_t)*4) ) { return cull_dyn(); }
		if (!memcmp(inName.__s,L"copy",sizeof(wchar_t)*4) ) { return copy_dyn(); }
		break;
	case 5:
		if (!memcmp(inName.__s,L"scene",sizeof(wchar_t)*5) ) { return __getScene(); }
		if (!memcmp(inName.__s,L"m_oEB",sizeof(wchar_t)*5) ) { return m_oEB; }
		break;
	case 6:
		if (!memcmp(inName.__s,L"culled",sizeof(wchar_t)*6) ) { return culled; }
		if (!memcmp(inName.__s,L"parent",sizeof(wchar_t)*6) ) { return __getParent(); }
		if (!memcmp(inName.__s,L"remove",sizeof(wchar_t)*6) ) { return remove_dyn(); }
		if (!memcmp(inName.__s,L"update",sizeof(wchar_t)*6) ) { return update_dyn(); }
		break;
	case 7:
		if (!memcmp(inName.__s,L"changed",sizeof(wchar_t)*7) ) { return __getChanged(); }
		if (!memcmp(inName.__s,L"visible",sizeof(wchar_t)*7) ) { return __getVisible(); }
		if (!memcmp(inName.__s,L"destroy",sizeof(wchar_t)*7) ) { return destroy_dyn(); }
		if (!memcmp(inName.__s,L"perform",sizeof(wchar_t)*7) ) { return perform_dyn(); }
		if (!memcmp(inName.__s,L"_parent",sizeof(wchar_t)*7) ) { return _parent; }
		break;
	case 8:
		if (!memcmp(inName.__s,L"children",sizeof(wchar_t)*8) ) { return children; }
		if (!memcmp(inName.__s,L"isParent",sizeof(wchar_t)*8) ) { return isParent_dyn(); }
		if (!memcmp(inName.__s,L"addChild",sizeof(wchar_t)*8) ) { return addChild_dyn(); }
		if (!memcmp(inName.__s,L"m_oScene",sizeof(wchar_t)*8) ) { return m_oScene; }
		if (!memcmp(inName.__s,L"toString",sizeof(wchar_t)*8) ) { return toString_dyn(); }
		break;
	case 9:
		if (!memcmp(inName.__s,L"hasParent",sizeof(wchar_t)*9) ) { return hasParent_dyn(); }
		break;
	case 10:
		if (!memcmp(inName.__s,L"appearance",sizeof(wchar_t)*10) ) { return __getAppearance(); }
		if (!memcmp(inName.__s,L"viewMatrix",sizeof(wchar_t)*10) ) { return viewMatrix; }
		if (!memcmp(inName.__s,L"m_bVisible",sizeof(wchar_t)*10) ) { return m_bVisible; }
		if (!memcmp(inName.__s,L"swapParent",sizeof(wchar_t)*10) ) { return swapParent_dyn(); }
		if (!memcmp(inName.__s,L"m_bChanged",sizeof(wchar_t)*10) ) { return m_bChanged; }
		if (!memcmp(inName.__s,L"__getScene",sizeof(wchar_t)*10) ) { return __getScene_dyn(); }
		if (!memcmp(inName.__s,L"__setScene",sizeof(wchar_t)*10) ) { return __setScene_dyn(); }
		break;
	case 11:
		if (!memcmp(inName.__s,L"broadcaster",sizeof(wchar_t)*11) ) { return __getBroadcaster(); }
		if (!memcmp(inName.__s,L"modelMatrix",sizeof(wchar_t)*11) ) { return modelMatrix; }
		if (!memcmp(inName.__s,L"boundingBox",sizeof(wchar_t)*11) ) { return boundingBox; }
		if (!memcmp(inName.__s,L"__setParent",sizeof(wchar_t)*11) ) { return __setParent_dyn(); }
		if (!memcmp(inName.__s,L"__getParent",sizeof(wchar_t)*11) ) { return __getParent_dyn(); }
		if (!memcmp(inName.__s,L"removeChild",sizeof(wchar_t)*11) ) { return removeChild_dyn(); }
		break;
	case 12:
		if (!memcmp(inName.__s,L"enableEvents",sizeof(wchar_t)*12) ) { return __getEnableEvents(); }
		if (!memcmp(inName.__s,L"__getVisible",sizeof(wchar_t)*12) ) { return __getVisible_dyn(); }
		if (!memcmp(inName.__s,L"__setVisible",sizeof(wchar_t)*12) ) { return __setVisible_dyn(); }
		if (!memcmp(inName.__s,L"__getChanged",sizeof(wchar_t)*12) ) { return __getChanged_dyn(); }
		if (!memcmp(inName.__s,L"__setChanged",sizeof(wchar_t)*12) ) { return __setChanged_dyn(); }
		if (!memcmp(inName.__s,L"_updateFlags",sizeof(wchar_t)*12) ) { return _updateFlags_dyn(); }
		break;
	case 14:
		if (!memcmp(inName.__s,L"boundingSphere",sizeof(wchar_t)*14) ) { return boundingSphere; }
		if (!memcmp(inName.__s,L"getChildByName",sizeof(wchar_t)*14) ) { return getChildByName_dyn(); }
		break;
	case 15:
		if (!memcmp(inName.__s,L"__getAppearance",sizeof(wchar_t)*15) ) { return __getAppearance_dyn(); }
		if (!memcmp(inName.__s,L"__setAppearance",sizeof(wchar_t)*15) ) { return __setAppearance_dyn(); }
		break;
	case 16:
		if (!memcmp(inName.__s,L"__getBroadcaster",sizeof(wchar_t)*16) ) { return __getBroadcaster_dyn(); }
		if (!memcmp(inName.__s,L"__setBroadcaster",sizeof(wchar_t)*16) ) { return __setBroadcaster_dyn(); }
		if (!memcmp(inName.__s,L"addEventListener",sizeof(wchar_t)*16) ) { return addEventListener_dyn(); }
		break;
	case 17:
		if (!memcmp(inName.__s,L"__getEnableEvents",sizeof(wchar_t)*17) ) { return __getEnableEvents_dyn(); }
		if (!memcmp(inName.__s,L"__setEnableEvents",sizeof(wchar_t)*17) ) { return __setEnableEvents_dyn(); }
		if (!memcmp(inName.__s,L"removeChildByName",sizeof(wchar_t)*17) ) { return removeChildByName_dyn(); }
		break;
	case 18:
		if (!memcmp(inName.__s,L"useSingleContainer",sizeof(wchar_t)*18) ) { return __getUseSingleContainer(); }
		break;
	case 19:
		if (!memcmp(inName.__s,L"enableInteractivity",sizeof(wchar_t)*19) ) { return __getEnableInteractivity(); }
		if (!memcmp(inName.__s,L"removeEventListener",sizeof(wchar_t)*19) ) { return removeEventListener_dyn(); }
		if (!memcmp(inName.__s,L"__setEnableClipping",sizeof(wchar_t)*19) ) { return __setEnableClipping_dyn(); }
		break;
	case 20:
		if (!memcmp(inName.__s,L"onChildBoundsChanged",sizeof(wchar_t)*20) ) { return onChildBoundsChanged_dyn(); }
		break;
	case 21:
		if (!memcmp(inName.__s,L"enableBackFaceCulling",sizeof(wchar_t)*21) ) { return __getEnableBackFaceCulling(); }
		if (!memcmp(inName.__s,L"updateBoundingVolumes",sizeof(wchar_t)*21) ) { return updateBoundingVolumes_dyn(); }
		break;
	case 23:
		if (!memcmp(inName.__s,L"__getUseSingleContainer",sizeof(wchar_t)*23) ) { return __getUseSingleContainer_dyn(); }
		if (!memcmp(inName.__s,L"__setUseSingleContainer",sizeof(wchar_t)*23) ) { return __setUseSingleContainer_dyn(); }
		break;
	case 24:
		if (!memcmp(inName.__s,L"__getEnableInteractivity",sizeof(wchar_t)*24) ) { return __getEnableInteractivity_dyn(); }
		if (!memcmp(inName.__s,L"__setEnableInteractivity",sizeof(wchar_t)*24) ) { return __setEnableInteractivity_dyn(); }
		break;
	case 26:
		if (!memcmp(inName.__s,L"__getEnableBackFaceCulling",sizeof(wchar_t)*26) ) { return __getEnableBackFaceCulling_dyn(); }
		if (!memcmp(inName.__s,L"__setEnableBackFaceCulling",sizeof(wchar_t)*26) ) { return __setEnableBackFaceCulling_dyn(); }
	}
	return super::__Field(inName);
}

Dynamic Node_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	switch(inName.length) {
	case 2:
		if (!memcmp(inName.__s,L"id",sizeof(wchar_t)*2) ) { id=inValue.Cast< int >(); return inValue; }
		break;
	case 4:
		if (!memcmp(inName.__s,L"_ID_",sizeof(wchar_t)*4) ) { _ID_=inValue.Cast< int >(); return inValue; }
		if (!memcmp(inName.__s,L"name",sizeof(wchar_t)*4) ) { name=inValue.Cast< ::String >(); return inValue; }
		break;
	case 5:
		if (!memcmp(inName.__s,L"scene",sizeof(wchar_t)*5) ) { return __setScene(inValue); }
		if (!memcmp(inName.__s,L"m_oEB",sizeof(wchar_t)*5) ) { m_oEB=inValue.Cast< ::sandy::events::BubbleEventBroadcaster >(); return inValue; }
		break;
	case 6:
		if (!memcmp(inName.__s,L"culled",sizeof(wchar_t)*6) ) { culled=inValue.Cast< int >(); return inValue; }
		if (!memcmp(inName.__s,L"parent",sizeof(wchar_t)*6) ) { return __setParent(inValue); }
		break;
	case 7:
		if (!memcmp(inName.__s,L"changed",sizeof(wchar_t)*7) ) { return __setChanged(inValue); }
		if (!memcmp(inName.__s,L"visible",sizeof(wchar_t)*7) ) { return __setVisible(inValue); }
		if (!memcmp(inName.__s,L"_parent",sizeof(wchar_t)*7) ) { _parent=inValue.Cast< ::sandy::core::scenegraph::Node >(); return inValue; }
		break;
	case 8:
		if (!memcmp(inName.__s,L"children",sizeof(wchar_t)*8) ) { children=inValue.Cast< Array< ::sandy::core::scenegraph::Node > >(); return inValue; }
		if (!memcmp(inName.__s,L"m_oScene",sizeof(wchar_t)*8) ) { m_oScene=inValue.Cast< ::sandy::core::Scene3D >(); return inValue; }
		break;
	case 10:
		if (!memcmp(inName.__s,L"appearance",sizeof(wchar_t)*10) ) { return __setAppearance(inValue); }
		if (!memcmp(inName.__s,L"viewMatrix",sizeof(wchar_t)*10) ) { viewMatrix=inValue.Cast< ::sandy::core::data::Matrix4 >(); return inValue; }
		if (!memcmp(inName.__s,L"m_bVisible",sizeof(wchar_t)*10) ) { m_bVisible=inValue.Cast< bool >(); return inValue; }
		if (!memcmp(inName.__s,L"m_bChanged",sizeof(wchar_t)*10) ) { m_bChanged=inValue.Cast< bool >(); return inValue; }
		break;
	case 11:
		if (!memcmp(inName.__s,L"broadcaster",sizeof(wchar_t)*11) ) { return __setBroadcaster(inValue); }
		if (!memcmp(inName.__s,L"modelMatrix",sizeof(wchar_t)*11) ) { modelMatrix=inValue.Cast< ::sandy::core::data::Matrix4 >(); return inValue; }
		if (!memcmp(inName.__s,L"boundingBox",sizeof(wchar_t)*11) ) { boundingBox=inValue.Cast< ::sandy::bounds::BBox >(); return inValue; }
		break;
	case 12:
		if (!memcmp(inName.__s,L"enableEvents",sizeof(wchar_t)*12) ) { return __setEnableEvents(inValue); }
		break;
	case 14:
		if (!memcmp(inName.__s,L"boundingSphere",sizeof(wchar_t)*14) ) { boundingSphere=inValue.Cast< ::sandy::bounds::BSphere >(); return inValue; }
		break;
	case 18:
		if (!memcmp(inName.__s,L"useSingleContainer",sizeof(wchar_t)*18) ) { return __setUseSingleContainer(inValue); }
		break;
	case 19:
		if (!memcmp(inName.__s,L"enableInteractivity",sizeof(wchar_t)*19) ) { return __setEnableInteractivity(inValue); }
		break;
	case 21:
		if (!memcmp(inName.__s,L"enableBackFaceCulling",sizeof(wchar_t)*21) ) { return __setEnableBackFaceCulling(inValue); }
	}
	return super::__SetField(inName,inValue);
}

void Node_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_STRING(L"appearance",10));
	outFields->push(HX_STRING(L"changed",7));
	outFields->push(HX_STRING(L"culled",6));
	outFields->push(HX_STRING(L"name",4));
	outFields->push(HX_STRING(L"broadcaster",11));
	outFields->push(HX_STRING(L"children",8));
	outFields->push(HX_STRING(L"enableBackFaceCulling",21));
	outFields->push(HX_STRING(L"enableEvents",12));
	outFields->push(HX_STRING(L"enableInteractivity",19));
	outFields->push(HX_STRING(L"modelMatrix",11));
	outFields->push(HX_STRING(L"parent",6));
	outFields->push(HX_STRING(L"viewMatrix",10));
	outFields->push(HX_STRING(L"boundingBox",11));
	outFields->push(HX_STRING(L"boundingSphere",14));
	outFields->push(HX_STRING(L"id",2));
	outFields->push(HX_STRING(L"useSingleContainer",18));
	outFields->push(HX_STRING(L"visible",7));
	outFields->push(HX_STRING(L"scene",5));
	outFields->push(HX_STRING(L"m_bVisible",10));
	outFields->push(HX_STRING(L"m_bChanged",10));
	outFields->push(HX_STRING(L"m_oScene",8));
	outFields->push(HX_STRING(L"_parent",7));
	outFields->push(HX_STRING(L"m_oEB",5));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_STRING(L"_ID_",4),
	String(null()) };

static ::String sMemberFields[] = {
	HX_STRING(L"appearance",10),
	HX_STRING(L"changed",7),
	HX_STRING(L"culled",6),
	HX_STRING(L"name",4),
	HX_STRING(L"broadcaster",11),
	HX_STRING(L"children",8),
	HX_STRING(L"enableBackFaceCulling",21),
	HX_STRING(L"enableEvents",12),
	HX_STRING(L"enableInteractivity",19),
	HX_STRING(L"modelMatrix",11),
	HX_STRING(L"parent",6),
	HX_STRING(L"viewMatrix",10),
	HX_STRING(L"boundingBox",11),
	HX_STRING(L"boundingSphere",14),
	HX_STRING(L"id",2),
	HX_STRING(L"useSingleContainer",18),
	HX_STRING(L"visible",7),
	HX_STRING(L"scene",5),
	HX_STRING(L"m_bVisible",10),
	HX_STRING(L"__getVisible",12),
	HX_STRING(L"__setVisible",12),
	HX_STRING(L"__getBroadcaster",16),
	HX_STRING(L"__setBroadcaster",16),
	HX_STRING(L"addEventListener",16),
	HX_STRING(L"removeEventListener",19),
	HX_STRING(L"isParent",8),
	HX_STRING(L"__getUseSingleContainer",23),
	HX_STRING(L"__setUseSingleContainer",23),
	HX_STRING(L"__setEnableClipping",19),
	HX_STRING(L"__getEnableBackFaceCulling",26),
	HX_STRING(L"__setEnableBackFaceCulling",26),
	HX_STRING(L"__getEnableInteractivity",24),
	HX_STRING(L"__setEnableInteractivity",24),
	HX_STRING(L"__getEnableEvents",17),
	HX_STRING(L"__setEnableEvents",17),
	HX_STRING(L"__getAppearance",15),
	HX_STRING(L"__setAppearance",15),
	HX_STRING(L"__setParent",11),
	HX_STRING(L"__getParent",11),
	HX_STRING(L"hasParent",9),
	HX_STRING(L"addChild",8),
	HX_STRING(L"getChildByName",14),
	HX_STRING(L"swapParent",10),
	HX_STRING(L"removeChild",11),
	HX_STRING(L"removeChildByName",17),
	HX_STRING(L"destroy",7),
	HX_STRING(L"remove",6),
	HX_STRING(L"update",6),
	HX_STRING(L"cull",4),
	HX_STRING(L"__getChanged",12),
	HX_STRING(L"__setChanged",12),
	HX_STRING(L"m_bChanged",10),
	HX_STRING(L"updateBoundingVolumes",21),
	HX_STRING(L"onChildBoundsChanged",20),
	HX_STRING(L"m_oScene",8),
	HX_STRING(L"__getScene",10),
	HX_STRING(L"__setScene",10),
	HX_STRING(L"_updateFlags",12),
	HX_STRING(L"perform",7),
	HX_STRING(L"toString",8),
	HX_STRING(L"copy",4),
	HX_STRING(L"_parent",7),
	HX_STRING(L"m_oEB",5),
	String(null()) };

static void sMarkStatics() {
	hx::MarkMember(Node_obj::_ID_);
};

Class Node_obj::__mClass;

void Node_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_STRING(L"sandy.core.scenegraph.Node",26), hx::TCanCast< Node_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void Node_obj::__boot()
{
	hx::Static(_ID_) = 0;
}

} // end namespace sandy
} // end namespace core
} // end namespace scenegraph
