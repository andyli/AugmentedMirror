#include <hxcpp.h>

#ifndef INCLUDED_org_casalib_events_IRemovableEventDispatcher
#include <org/casalib/events/IRemovableEventDispatcher.h>
#endif
namespace org{
namespace casalib{
namespace events{

HX_DEFINE_DYNAMIC_FUNC1(IRemovableEventDispatcher_obj,removeEventsForType,)

HX_DEFINE_DYNAMIC_FUNC1(IRemovableEventDispatcher_obj,removeEventsForListener,)

HX_DEFINE_DYNAMIC_FUNC0(IRemovableEventDispatcher_obj,removeEventListeners,)

HX_DEFINE_DYNAMIC_FUNC1(IRemovableEventDispatcher_obj,getTotalEventListeners,return )


} // end namespace org
} // end namespace casalib
} // end namespace events
