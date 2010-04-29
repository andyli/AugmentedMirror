#include <hxcpp.h>

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
#ifndef INCLUDED_neash_events_EventDispatcher
#include <neash/events/EventDispatcher.h>
#endif
#ifndef INCLUDED_neash_events_IEventDispatcher
#include <neash/events/IEventDispatcher.h>
#endif
#ifndef INCLUDED_nme_display_IBitmapDrawable
#include <nme/display/IBitmapDrawable.h>
#endif
#ifndef INCLUDED_sandy_core_scenegraph_IDisplayable
#include <sandy/core/scenegraph/IDisplayable.h>
#endif
#ifndef INCLUDED_sandy_materials_Material
#include <sandy/materials/Material.h>
#endif
namespace sandy{
namespace core{
namespace scenegraph{

HX_DEFINE_DYNAMIC_FUNC0(IDisplayable_obj,clear,)

HX_DEFINE_DYNAMIC_FUNC0(IDisplayable_obj,__getContainer,return )

HX_DEFINE_DYNAMIC_FUNC0(IDisplayable_obj,__getDepth,return )

HX_DEFINE_DYNAMIC_FUNC1(IDisplayable_obj,__setDepth,return )

HX_DEFINE_DYNAMIC_FUNC0(IDisplayable_obj,__getChanged,return )

HX_DEFINE_DYNAMIC_FUNC1(IDisplayable_obj,__setChanged,return )

HX_DEFINE_DYNAMIC_FUNC0(IDisplayable_obj,__getMaterial,return )

HX_DEFINE_DYNAMIC_FUNC1(IDisplayable_obj,__setMaterial,return )

HX_DEFINE_DYNAMIC_FUNC1(IDisplayable_obj,display,)


} // end namespace sandy
} // end namespace core
} // end namespace scenegraph
