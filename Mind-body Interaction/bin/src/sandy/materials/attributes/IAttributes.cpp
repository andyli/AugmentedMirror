#include <hxcpp.h>

#ifndef INCLUDED_neash_events_EventDispatcher
#include <neash/events/EventDispatcher.h>
#endif
#ifndef INCLUDED_neash_events_IEventDispatcher
#include <neash/events/IEventDispatcher.h>
#endif
#ifndef INCLUDED_nme_display_Graphics
#include <nme/display/Graphics.h>
#endif
#ifndef INCLUDED_sandy_core_Scene3D
#include <sandy/core/Scene3D.h>
#endif
#ifndef INCLUDED_sandy_core_data_Polygon
#include <sandy/core/data/Polygon.h>
#endif
#ifndef INCLUDED_sandy_core_scenegraph_ATransformable
#include <sandy/core/scenegraph/ATransformable.h>
#endif
#ifndef INCLUDED_sandy_core_scenegraph_IDisplayable
#include <sandy/core/scenegraph/IDisplayable.h>
#endif
#ifndef INCLUDED_sandy_core_scenegraph_Node
#include <sandy/core/scenegraph/Node.h>
#endif
#ifndef INCLUDED_sandy_core_scenegraph_Sprite2D
#include <sandy/core/scenegraph/Sprite2D.h>
#endif
#ifndef INCLUDED_sandy_materials_Material
#include <sandy/materials/Material.h>
#endif
#ifndef INCLUDED_sandy_materials_attributes_IAttributes
#include <sandy/materials/attributes/IAttributes.h>
#endif
namespace sandy{
namespace materials{
namespace attributes{

HX_DEFINE_DYNAMIC_FUNC4(IAttributes_obj,draw,)

HX_DEFINE_DYNAMIC_FUNC3(IAttributes_obj,drawOnSprite,)

HX_DEFINE_DYNAMIC_FUNC1(IAttributes_obj,init,)

HX_DEFINE_DYNAMIC_FUNC1(IAttributes_obj,unlink,)

HX_DEFINE_DYNAMIC_FUNC1(IAttributes_obj,begin,)

HX_DEFINE_DYNAMIC_FUNC1(IAttributes_obj,finish,)

HX_DEFINE_DYNAMIC_FUNC0(IAttributes_obj,__getFlags,return )


} // end namespace sandy
} // end namespace materials
} // end namespace attributes
