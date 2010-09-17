#include <hxcpp.h>

#ifndef INCLUDED_neash_events_Event
#include <neash/events/Event.h>
#endif
#ifndef INCLUDED_neash_events_IEventDispatcher
#include <neash/events/IEventDispatcher.h>
#endif
namespace neash{
namespace events{

HX_DEFINE_DYNAMIC_FUNC5(IEventDispatcher_obj,addEventListener,return )

HX_DEFINE_DYNAMIC_FUNC1(IEventDispatcher_obj,dispatchEvent,return )

HX_DEFINE_DYNAMIC_FUNC1(IEventDispatcher_obj,hasEventListener,return )

HX_DEFINE_DYNAMIC_FUNC3(IEventDispatcher_obj,removeEventListener,)

HX_DEFINE_DYNAMIC_FUNC1(IEventDispatcher_obj,willTrigger,return )

HX_DEFINE_DYNAMIC_FUNC2(IEventDispatcher_obj,RemoveByID,)


} // end namespace neash
} // end namespace events
