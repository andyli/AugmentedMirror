#ifndef INCLUDED_org_casalib_events_IRemovableEventDispatcher
#define INCLUDED_org_casalib_events_IRemovableEventDispatcher

#include <hxcpp.h>

HX_DECLARE_CLASS3(org,casalib,events,IRemovableEventDispatcher)
namespace org{
namespace casalib{
namespace events{


class IRemovableEventDispatcher_obj : public hx::Interface{
	public:
		typedef hx::Interface super;
		typedef IRemovableEventDispatcher_obj OBJ_;
		virtual Void removeEventsForType( ::String type)=0;
		Dynamic removeEventsForType_dyn();
		virtual Void removeEventsForListener( Dynamic listener)=0;
		Dynamic removeEventsForListener_dyn();
		virtual Void removeEventListeners( )=0;
		Dynamic removeEventListeners_dyn();
		virtual int getTotalEventListeners( ::String type=null())=0;
		Dynamic getTotalEventListeners_dyn();
};

#define DELEGATE_org_casalib_events_IRemovableEventDispatcher \
virtual Void removeEventsForType( ::String type) { return mDelegate->removeEventsForType(type);}  \
virtual Dynamic removeEventsForType_dyn() { return mDelegate->removeEventsForType_dyn();}  \
virtual Void removeEventsForListener( Dynamic listener) { return mDelegate->removeEventsForListener(listener);}  \
virtual Dynamic removeEventsForListener_dyn() { return mDelegate->removeEventsForListener_dyn();}  \
virtual Void removeEventListeners( ) { return mDelegate->removeEventListeners();}  \
virtual Dynamic removeEventListeners_dyn() { return mDelegate->removeEventListeners_dyn();}  \
virtual int getTotalEventListeners( ::String type=null()) { return mDelegate->getTotalEventListeners(type);}  \
virtual Dynamic getTotalEventListeners_dyn() { return mDelegate->getTotalEventListeners_dyn();}  \


template<typename IMPL>
class IRemovableEventDispatcher_delegate_ : public IRemovableEventDispatcher_obj
{
	protected:
		IMPL *mDelegate;
	public:
		IRemovableEventDispatcher_delegate_(IMPL *inDelegate) : mDelegate(inDelegate) {}
		hx::Object *__GetRealObject() { return mDelegate; }
		DELEGATE_org_casalib_events_IRemovableEventDispatcher
};

} // end namespace org
} // end namespace casalib
} // end namespace events

#endif /* INCLUDED_org_casalib_events_IRemovableEventDispatcher */ 
