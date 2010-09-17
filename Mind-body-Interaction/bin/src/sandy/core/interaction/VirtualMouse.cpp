#include <hxcpp.h>

#ifndef INCLUDED_Std
#include <Std.h>
#endif
#ifndef INCLUDED_neash_display_DisplayObject
#include <neash/display/DisplayObject.h>
#endif
#ifndef INCLUDED_neash_display_DisplayObjectContainer
#include <neash/display/DisplayObjectContainer.h>
#endif
#ifndef INCLUDED_neash_display_InteractiveObject
#include <neash/display/InteractiveObject.h>
#endif
#ifndef INCLUDED_neash_display_Sprite
#include <neash/display/Sprite.h>
#endif
#ifndef INCLUDED_neash_display_Stage
#include <neash/display/Stage.h>
#endif
#ifndef INCLUDED_neash_events_Event
#include <neash/events/Event.h>
#endif
#ifndef INCLUDED_neash_events_EventDispatcher
#include <neash/events/EventDispatcher.h>
#endif
#ifndef INCLUDED_neash_events_IEventDispatcher
#include <neash/events/IEventDispatcher.h>
#endif
#ifndef INCLUDED_neash_events_MouseEvent
#include <neash/events/MouseEvent.h>
#endif
#ifndef INCLUDED_neash_text_NeashText
#include <neash/text/NeashText.h>
#endif
#ifndef INCLUDED_nme_display_BitmapData
#include <nme/display/BitmapData.h>
#endif
#ifndef INCLUDED_nme_display_IBitmapDrawable
#include <nme/display/IBitmapDrawable.h>
#endif
#ifndef INCLUDED_nme_geom_Point
#include <nme/geom/Point.h>
#endif
#ifndef INCLUDED_nme_geom_Rectangle
#include <nme/geom/Rectangle.h>
#endif
#ifndef INCLUDED_sandy_core_data_Polygon
#include <sandy/core/data/Polygon.h>
#endif
#ifndef INCLUDED_sandy_core_data_UVCoord
#include <sandy/core/data/UVCoord.h>
#endif
#ifndef INCLUDED_sandy_core_interaction_PrivateConstructorAccess
#include <sandy/core/interaction/PrivateConstructorAccess.h>
#endif
#ifndef INCLUDED_sandy_core_interaction_TextLink
#include <sandy/core/interaction/TextLink.h>
#endif
#ifndef INCLUDED_sandy_core_interaction_VirtualMouse
#include <sandy/core/interaction/VirtualMouse.h>
#endif
#ifndef INCLUDED_sandy_core_scenegraph_IDisplayable
#include <sandy/core/scenegraph/IDisplayable.h>
#endif
#ifndef INCLUDED_sandy_materials_Appearance
#include <sandy/materials/Appearance.h>
#endif
#ifndef INCLUDED_sandy_materials_BitmapMaterial
#include <sandy/materials/BitmapMaterial.h>
#endif
#ifndef INCLUDED_sandy_materials_IAlphaMaterial
#include <sandy/materials/IAlphaMaterial.h>
#endif
#ifndef INCLUDED_sandy_materials_Material
#include <sandy/materials/Material.h>
#endif
#ifndef INCLUDED_sandy_materials_MovieMaterial
#include <sandy/materials/MovieMaterial.h>
#endif
#ifndef INCLUDED_sandy_util_ArrayUtil
#include <sandy/util/ArrayUtil.h>
#endif
namespace sandy{
namespace core{
namespace interaction{

Void VirtualMouse_obj::__construct(::sandy::core::interaction::PrivateConstructorAccess access)
{
{
	this->lastWithinStage = true;
	this->m_oPreviousTargets = Array_obj< ::neash::display::InteractiveObject >::__new();
	this->m_oCurrentTargets = Array_obj< ::neash::display::InteractiveObject >::__new();
	super::__construct(null());
	this->location = ::nme::geom::Point_obj::__new(0,0);
	this->lastLocation = this->location->clone();
}
;
	return null();
}

VirtualMouse_obj::~VirtualMouse_obj() { }

Dynamic VirtualMouse_obj::__CreateEmpty() { return  new VirtualMouse_obj; }
hx::ObjectPtr< VirtualMouse_obj > VirtualMouse_obj::__new(::sandy::core::interaction::PrivateConstructorAccess access)
{  hx::ObjectPtr< VirtualMouse_obj > result = new VirtualMouse_obj();
	result->__construct(access);
	return result;}

Dynamic VirtualMouse_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< VirtualMouse_obj > result = new VirtualMouse_obj();
	result->__construct(inArgs[0]);
	return result;}

Void VirtualMouse_obj::interactWithTexture( ::sandy::core::data::Polygon p_oPoly,::sandy::core::data::UVCoord p_uvTexture,::neash::events::MouseEvent p_event){
{
		__SAFE_POINT
		::neash::display::Sprite currentTarget = null();
		::nme::geom::Point targetLocal = null();
		::sandy::materials::MovieMaterial l_oMaterial = null();
		try{
			l_oMaterial = p_oPoly->visible ? ::sandy::materials::MovieMaterial( p_oPoly->__getAppearance()->__getFrontMaterial() ) : ::sandy::materials::MovieMaterial( p_oPoly->__getAppearance()->__getBackMaterial() );
		}
		catch(Dynamic __e){
			{
				Dynamic e = __e;{
					return null();
				}
			}
		}
		if ((l_oMaterial == null()))
			return null();
		this->m_ioTarget = l_oMaterial->__getMovie();
		this->location = ::nme::geom::Point_obj::__new((p_uvTexture->u * l_oMaterial->__getTexture()->getWidth()),(p_uvTexture->v * l_oMaterial->__getTexture()->getHeight()));
		if ((p_event->type == ::neash::events::MouseEvent_obj::MOUSE_OUT)){
			targetLocal = p_oPoly->__getContainer()->globalToLocal(this->location);
			if ((this->m_ioOldTarget != null())){
				this->_lastEvent = ::neash::events::MouseEvent_obj::__new(::neash::events::MouseEvent_obj::MOUSE_OUT,true,false,targetLocal->x,targetLocal->y,currentTarget,p_event->ctrlKey,p_event->altKey,p_event->shiftKey,p_event->buttonDown,p_event->delta);
				this->m_ioOldTarget->dispatchEvent(this->_lastEvent);
				this->dispatchEvent(this->_lastEvent);
				this->_lastEvent = ::neash::events::MouseEvent_obj::__new(::neash::events::MouseEvent_obj::ROLL_OUT,false,false,targetLocal->x,targetLocal->y,currentTarget,p_event->ctrlKey,p_event->altKey,p_event->shiftKey,p_event->buttonDown,p_event->delta);
				this->m_ioOldTarget->dispatchEvent(this->_lastEvent);
				this->dispatchEvent(this->_lastEvent);
				this->m_ioOldTarget = null();
			}
			return null();
		}
		Array< ::neash::display::DisplayObject > objectsUnderPoint = this->m_ioTarget->getObjectsUnderPoint(this->m_ioTarget->localToGlobal(this->location));
		::neash::display::DisplayObject currentParent = null();
		int i = objectsUnderPoint->length;
		while((--i > -1)){
			__SAFE_POINT
			currentParent = objectsUnderPoint->__get(i);
			while((currentParent != null())){
				__SAFE_POINT
				struct _Function_3_1{
					inline static ::neash::display::DisplayObjectContainer Block( ::neash::display::DisplayObject &currentParent)/* DEF (ret block)(not intern) */{
						::neash::display::DisplayObject tmp = currentParent;
						return ::Std_obj::is(tmp,hx::ClassOf< ::neash::display::DisplayObjectContainer >()) ? ::neash::display::DisplayObject( tmp ) : ::neash::display::DisplayObject( hx::Throw (HX_STRING(L"Class cast error",16)) );
					}
				};
				if ((bool((currentTarget != null())) && bool((bool(::Std_obj::is(currentParent,hx::ClassOf< ::neash::display::DisplayObjectContainer >())) && bool(!_Function_3_1::Block(currentParent)->mouseChildren))))){
					currentTarget = null();
					currentParent = currentParent->GetParent();
					continue;
				}
				struct _Function_3_2{
					inline static ::neash::display::DisplayObjectContainer Block( ::neash::display::DisplayObject &currentParent)/* DEF (ret block)(not intern) */{
						::neash::display::DisplayObject tmp = currentParent;
						return ::Std_obj::is(tmp,hx::ClassOf< ::neash::display::DisplayObjectContainer >()) ? ::neash::display::DisplayObject( tmp ) : ::neash::display::DisplayObject( hx::Throw (HX_STRING(L"Class cast error",16)) );
					}
				};
				if ((bool((currentTarget == null())) && bool((bool(::Std_obj::is(currentParent,hx::ClassOf< ::neash::display::DisplayObjectContainer >())) && bool(_Function_3_2::Block(currentParent)->mouseEnabled))))){
					struct _Function_4_1{
						inline static ::neash::display::Sprite Block( ::neash::display::DisplayObject &currentParent)/* DEF (ret block)(not intern) */{
							::neash::display::DisplayObject tmp = currentParent;
							return ::Std_obj::is(tmp,hx::ClassOf< ::neash::display::Sprite >()) ? ::neash::display::DisplayObject( tmp ) : ::neash::display::DisplayObject( hx::Throw (HX_STRING(L"Class cast error",16)) );
						}
					};
					currentTarget = _Function_4_1::Block(currentParent);
				}
				if ((currentTarget == null())){
					currentParent = currentParent->GetParent();
					continue;
				}
				this->m_oCurrentTargets->push(currentTarget);
				targetLocal = p_oPoly->__getContainer()->globalToLocal(this->location);
				::nme::geom::Point currentTargetLocal = currentTarget->globalToLocal(this->location);
				if ((bool((this->lastLocation->x != this->location->x)) || bool((this->lastLocation->y != this->location->y)))){
					bool withinStage = ((bool((this->location->x >= 0)) && bool((bool((this->location->y >= 0)) && bool((bool((this->location->x <= p_oPoly->__getContainer()->GetStage()->GetStageWidth())) && bool((this->location->y <= p_oPoly->__getContainer()->GetStage()->GetStageHeight()))))))));
					if ((bool(!withinStage) && bool(this->lastWithinStage))){
						this->_lastEvent = ::neash::events::MouseEvent_obj::__new(::neash::events::Event_obj::MOUSE_LEAVE,false,false,null(),null(),null(),null(),null(),null(),null(),null());
						p_oPoly->__getContainer()->GetStage()->dispatchEvent(this->_lastEvent);
						this->dispatchEvent(this->_lastEvent);
					}
					if (withinStage){
						this->_lastEvent = ::neash::events::MouseEvent_obj::__new(::neash::events::Event_obj::MOUSE_LEAVE,false,false,null(),null(),null(),null(),null(),null(),null(),null());
						currentTarget->dispatchEvent(this->_lastEvent);
						this->dispatchEvent(this->_lastEvent);
					}
					this->lastWithinStage = withinStage;
				}
				struct _Function_3_3{
					inline static int Block( ::sandy::core::interaction::VirtualMouse_obj *__this,::neash::display::Sprite &currentTarget)/* DEF (ret block)(not intern) */{
						Dynamic array = __this->m_oPreviousTargets;
						int idx = -1;
						{
							int _g1 = 0;
							int _g2 = array->__Field(HX_STRING(L"length",6)).Cast< int >();
							while((_g1 < _g2)){
								__SAFE_POINT
								int i1 = _g1++;
								if ((array[i1] == currentTarget)){
									idx = i1;
									break;
								}
							}
						}
						return idx;
					}
				};
				if ((_Function_3_3::Block(this,currentTarget) == -1)){
					this->_lastEvent = ::neash::events::MouseEvent_obj::__new(::neash::events::MouseEvent_obj::MOUSE_OVER,true,false,currentTargetLocal->x,currentTargetLocal->y,this->m_ioOldTarget,p_event->ctrlKey,p_event->altKey,p_event->shiftKey,p_event->buttonDown,p_event->delta);
					currentTarget->dispatchEvent(this->_lastEvent);
					this->dispatchEvent(this->_lastEvent);
					this->_lastEvent = ::neash::events::MouseEvent_obj::__new(::neash::events::MouseEvent_obj::ROLL_OVER,false,false,currentTargetLocal->x,currentTargetLocal->y,this->m_ioOldTarget,p_event->ctrlKey,p_event->altKey,p_event->shiftKey,p_event->buttonDown,p_event->delta);
					currentTarget->dispatchEvent(this->_lastEvent);
					this->dispatchEvent(this->_lastEvent);
				}
				if ((p_event->type == ::neash::events::MouseEvent_obj::MOUSE_DOWN)){
					this->_lastEvent = ::neash::events::MouseEvent_obj::__new(::neash::events::MouseEvent_obj::MOUSE_DOWN,true,false,currentTargetLocal->x,currentTargetLocal->y,currentTarget,p_event->ctrlKey,p_event->altKey,p_event->shiftKey,p_event->buttonDown,p_event->delta);
					currentTarget->dispatchEvent(this->_lastEvent);
					this->dispatchEvent(this->_lastEvent);
					this->lastDownTarget = currentTarget;
				}
				else{
					if ((p_event->type == ::neash::events::MouseEvent_obj::MOUSE_UP)){
						this->_lastEvent = ::neash::events::MouseEvent_obj::__new(::neash::events::MouseEvent_obj::MOUSE_UP,true,false,currentTargetLocal->x,currentTargetLocal->y,currentTarget,p_event->ctrlKey,p_event->altKey,p_event->shiftKey,p_event->buttonDown,p_event->delta);
						currentTarget->dispatchEvent(this->_lastEvent);
						this->dispatchEvent(this->_lastEvent);
					}
					else{
						if ((p_event->type == ::neash::events::MouseEvent_obj::CLICK)){
							this->_lastEvent = ::neash::events::MouseEvent_obj::__new(::neash::events::MouseEvent_obj::CLICK,true,false,currentTargetLocal->x,currentTargetLocal->y,currentTarget,p_event->ctrlKey,p_event->altKey,p_event->shiftKey,p_event->buttonDown,p_event->delta);
							currentTarget->dispatchEvent(this->_lastEvent);
							this->dispatchEvent(this->_lastEvent);
							this->lastDownTarget = null();
						}
						else{
							if ((bool((p_event->type == ::neash::events::MouseEvent_obj::DOUBLE_CLICK)) && bool(currentTarget->__getDoubleClickEnabled()))){
								this->_lastEvent = ::neash::events::MouseEvent_obj::__new(::neash::events::MouseEvent_obj::DOUBLE_CLICK,true,false,currentTargetLocal->x,currentTargetLocal->y,currentTarget,p_event->ctrlKey,p_event->altKey,p_event->shiftKey,p_event->buttonDown,p_event->delta);
								currentTarget->dispatchEvent(this->_lastEvent);
								this->dispatchEvent(this->_lastEvent);
							}
						}
					}
				}
				currentParent = currentParent->GetParent();
			}
		}
		int l = this->m_oPreviousTargets->length;
		{
			int _g = 0;
			while((_g < l)){
				__SAFE_POINT
				int i1 = _g++;
				struct _Function_3_1{
					inline static int Block( ::sandy::core::interaction::VirtualMouse_obj *__this,int &i1)/* DEF (ret block)(not intern) */{
						Dynamic _g1 = hx::ClassOf< ::sandy::util::ArrayUtil >();
						Dynamic array = __this->m_oCurrentTargets;
						int idx = -1;
						{
							int _g11 = 0;
							int _g2 = array->__Field(HX_STRING(L"length",6)).Cast< int >();
							while((_g11 < _g2)){
								__SAFE_POINT
								int i2 = _g11++;
								if ((array[i2] == __this->m_oPreviousTargets->__get(i1))){
									idx = i2;
									break;
								}
							}
						}
						return idx;
					}
				};
				if ((_Function_3_1::Block(this,i1) == -1)){
					targetLocal = p_oPoly->__getContainer()->globalToLocal(this->location);
					this->m_ioOldTarget = this->m_oPreviousTargets->__get(i1);
					this->_lastEvent = ::neash::events::MouseEvent_obj::__new(::neash::events::MouseEvent_obj::MOUSE_OUT,true,false,targetLocal->x,targetLocal->y,currentTarget,p_event->ctrlKey,p_event->altKey,p_event->shiftKey,p_event->buttonDown,p_event->delta);
					this->m_ioOldTarget->dispatchEvent(this->_lastEvent);
					this->dispatchEvent(this->_lastEvent);
					this->_lastEvent = ::neash::events::MouseEvent_obj::__new(::neash::events::MouseEvent_obj::ROLL_OUT,false,false,targetLocal->x,targetLocal->y,currentTarget,p_event->ctrlKey,p_event->altKey,p_event->shiftKey,p_event->buttonDown,p_event->delta);
					this->m_ioOldTarget->dispatchEvent(this->_lastEvent);
					this->dispatchEvent(this->_lastEvent);
				}
			}
		}
		this->lastLocation = this->location->clone();
		this->m_oPreviousTargets = this->m_oCurrentTargets->concat(Array_obj< ::neash::display::InteractiveObject >::__new());
		this->m_oCurrentTargets = Array_obj< ::neash::display::InteractiveObject >::__new();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC3(VirtualMouse_obj,interactWithTexture,(void))

Void VirtualMouse_obj::_checkLinks( ::neash::text::NeashText tf){
{
		__SAFE_POINT
		::nme::geom::Point currentTargetLocal = tf->globalToLocal(this->location);
		Array< ::sandy::core::interaction::TextLink > a = ::sandy::core::interaction::TextLink_obj::getTextLinks(tf,null());
		int l = a->length;
		{
			int _g = 0;
			while((_g < l)){
				__SAFE_POINT
				int i = _g++;
				struct _Function_3_1{
					inline static ::nme::geom::Rectangle Block( Array< ::sandy::core::interaction::TextLink > &a,int &i)/* DEF (ret block)(not intern) */{
						struct _Function_4_1{
							inline static ::sandy::core::interaction::TextLink Block( Array< ::sandy::core::interaction::TextLink > &a,int &i)/* DEF (ret block)(not intern) */{
								::sandy::core::interaction::TextLink tmp = a->__get(i);
								return ::Std_obj::is(tmp,hx::ClassOf< ::sandy::core::interaction::TextLink >()) ? ::sandy::core::interaction::TextLink( tmp ) : ::sandy::core::interaction::TextLink( hx::Throw (HX_STRING(L"Class cast error",16)) );
							}
						};
						::nme::geom::Rectangle tmp = (_Function_4_1::Block(a,i))->getBounds();
						return ::Std_obj::is(tmp,hx::ClassOf< ::nme::geom::Rectangle >()) ? ::nme::geom::Rectangle( tmp ) : ::nme::geom::Rectangle( hx::Throw (HX_STRING(L"Class cast error",16)) );
					}
				};
				if (_Function_3_1::Block(a,i)->containsPoint(currentTargetLocal))
					2;
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(VirtualMouse_obj,_checkLinks,(void))

::sandy::core::interaction::VirtualMouse VirtualMouse_obj::_oI;

::sandy::core::interaction::VirtualMouse VirtualMouse_obj::getInstance( ){
	if ((::sandy::core::interaction::VirtualMouse_obj::_oI == null()))
		::sandy::core::interaction::VirtualMouse_obj::_oI = ::sandy::core::interaction::VirtualMouse_obj::__new(::sandy::core::interaction::PrivateConstructorAccess_obj::__new());
	return ::sandy::core::interaction::VirtualMouse_obj::_oI;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(VirtualMouse_obj,getInstance,return )


VirtualMouse_obj::VirtualMouse_obj()
{
}

void VirtualMouse_obj::__Mark()
{
	hx::MarkMember(m_ioTarget);
	hx::MarkMember(m_ioOldTarget);
	hx::MarkMember(location);
	hx::MarkMember(lastLocation);
	hx::MarkMember(lastWithinStage);
	hx::MarkMember(_lastEvent);
	hx::MarkMember(lastDownTarget);
	hx::MarkMember(m_oPreviousTargets);
	hx::MarkMember(m_oCurrentTargets);
	super::__Mark();
}

Dynamic VirtualMouse_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 3:
		if (!memcmp(inName.__s,L"_oI",sizeof(wchar_t)*3) ) { return _oI; }
		break;
	case 8:
		if (!memcmp(inName.__s,L"location",sizeof(wchar_t)*8) ) { return location; }
		break;
	case 10:
		if (!memcmp(inName.__s,L"m_ioTarget",sizeof(wchar_t)*10) ) { return m_ioTarget; }
		if (!memcmp(inName.__s,L"_lastEvent",sizeof(wchar_t)*10) ) { return _lastEvent; }
		break;
	case 11:
		if (!memcmp(inName.__s,L"getInstance",sizeof(wchar_t)*11) ) { return getInstance_dyn(); }
		if (!memcmp(inName.__s,L"_checkLinks",sizeof(wchar_t)*11) ) { return _checkLinks_dyn(); }
		break;
	case 12:
		if (!memcmp(inName.__s,L"lastLocation",sizeof(wchar_t)*12) ) { return lastLocation; }
		break;
	case 13:
		if (!memcmp(inName.__s,L"m_ioOldTarget",sizeof(wchar_t)*13) ) { return m_ioOldTarget; }
		break;
	case 14:
		if (!memcmp(inName.__s,L"lastDownTarget",sizeof(wchar_t)*14) ) { return lastDownTarget; }
		break;
	case 15:
		if (!memcmp(inName.__s,L"lastWithinStage",sizeof(wchar_t)*15) ) { return lastWithinStage; }
		break;
	case 17:
		if (!memcmp(inName.__s,L"m_oCurrentTargets",sizeof(wchar_t)*17) ) { return m_oCurrentTargets; }
		break;
	case 18:
		if (!memcmp(inName.__s,L"m_oPreviousTargets",sizeof(wchar_t)*18) ) { return m_oPreviousTargets; }
		break;
	case 19:
		if (!memcmp(inName.__s,L"interactWithTexture",sizeof(wchar_t)*19) ) { return interactWithTexture_dyn(); }
	}
	return super::__Field(inName);
}

Dynamic VirtualMouse_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	switch(inName.length) {
	case 3:
		if (!memcmp(inName.__s,L"_oI",sizeof(wchar_t)*3) ) { _oI=inValue.Cast< ::sandy::core::interaction::VirtualMouse >(); return inValue; }
		break;
	case 8:
		if (!memcmp(inName.__s,L"location",sizeof(wchar_t)*8) ) { location=inValue.Cast< ::nme::geom::Point >(); return inValue; }
		break;
	case 10:
		if (!memcmp(inName.__s,L"m_ioTarget",sizeof(wchar_t)*10) ) { m_ioTarget=inValue.Cast< ::neash::display::Sprite >(); return inValue; }
		if (!memcmp(inName.__s,L"_lastEvent",sizeof(wchar_t)*10) ) { _lastEvent=inValue.Cast< ::neash::events::Event >(); return inValue; }
		break;
	case 12:
		if (!memcmp(inName.__s,L"lastLocation",sizeof(wchar_t)*12) ) { lastLocation=inValue.Cast< ::nme::geom::Point >(); return inValue; }
		break;
	case 13:
		if (!memcmp(inName.__s,L"m_ioOldTarget",sizeof(wchar_t)*13) ) { m_ioOldTarget=inValue.Cast< ::neash::display::Sprite >(); return inValue; }
		break;
	case 14:
		if (!memcmp(inName.__s,L"lastDownTarget",sizeof(wchar_t)*14) ) { lastDownTarget=inValue.Cast< ::neash::display::InteractiveObject >(); return inValue; }
		break;
	case 15:
		if (!memcmp(inName.__s,L"lastWithinStage",sizeof(wchar_t)*15) ) { lastWithinStage=inValue.Cast< bool >(); return inValue; }
		break;
	case 17:
		if (!memcmp(inName.__s,L"m_oCurrentTargets",sizeof(wchar_t)*17) ) { m_oCurrentTargets=inValue.Cast< Array< ::neash::display::InteractiveObject > >(); return inValue; }
		break;
	case 18:
		if (!memcmp(inName.__s,L"m_oPreviousTargets",sizeof(wchar_t)*18) ) { m_oPreviousTargets=inValue.Cast< Array< ::neash::display::InteractiveObject > >(); return inValue; }
	}
	return super::__SetField(inName,inValue);
}

void VirtualMouse_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_STRING(L"m_ioTarget",10));
	outFields->push(HX_STRING(L"m_ioOldTarget",13));
	outFields->push(HX_STRING(L"location",8));
	outFields->push(HX_STRING(L"lastLocation",12));
	outFields->push(HX_STRING(L"lastWithinStage",15));
	outFields->push(HX_STRING(L"_lastEvent",10));
	outFields->push(HX_STRING(L"lastDownTarget",14));
	outFields->push(HX_STRING(L"m_oPreviousTargets",18));
	outFields->push(HX_STRING(L"m_oCurrentTargets",17));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_STRING(L"_oI",3),
	HX_STRING(L"getInstance",11),
	String(null()) };

static ::String sMemberFields[] = {
	HX_STRING(L"m_ioTarget",10),
	HX_STRING(L"m_ioOldTarget",13),
	HX_STRING(L"location",8),
	HX_STRING(L"lastLocation",12),
	HX_STRING(L"lastWithinStage",15),
	HX_STRING(L"_lastEvent",10),
	HX_STRING(L"lastDownTarget",14),
	HX_STRING(L"m_oPreviousTargets",18),
	HX_STRING(L"m_oCurrentTargets",17),
	HX_STRING(L"interactWithTexture",19),
	HX_STRING(L"_checkLinks",11),
	String(null()) };

static void sMarkStatics() {
	hx::MarkMember(VirtualMouse_obj::_oI);
};

Class VirtualMouse_obj::__mClass;

void VirtualMouse_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_STRING(L"sandy.core.interaction.VirtualMouse",35), hx::TCanCast< VirtualMouse_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void VirtualMouse_obj::__boot()
{
	hx::Static(_oI);
}

} // end namespace sandy
} // end namespace core
} // end namespace interaction
