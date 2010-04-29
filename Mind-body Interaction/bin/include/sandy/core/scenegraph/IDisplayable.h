#ifndef INCLUDED_sandy_core_scenegraph_IDisplayable
#define INCLUDED_sandy_core_scenegraph_IDisplayable

#include <hxcpp.h>

HX_DECLARE_CLASS2(neash,display,DisplayObject)
HX_DECLARE_CLASS2(neash,display,DisplayObjectContainer)
HX_DECLARE_CLASS2(neash,display,InteractiveObject)
HX_DECLARE_CLASS2(neash,display,Sprite)
HX_DECLARE_CLASS2(neash,events,EventDispatcher)
HX_DECLARE_CLASS2(neash,events,IEventDispatcher)
HX_DECLARE_CLASS2(nme,display,IBitmapDrawable)
HX_DECLARE_CLASS3(sandy,core,scenegraph,IDisplayable)
HX_DECLARE_CLASS2(sandy,materials,Material)
namespace sandy{
namespace core{
namespace scenegraph{


class IDisplayable_obj : public hx::Interface{
	public:
		typedef hx::Interface super;
		typedef IDisplayable_obj OBJ_;
		virtual Void clear( )=0;
		Dynamic clear_dyn();
		
		virtual ::neash::display::Sprite __getContainer( )=0;
		Dynamic __getContainer_dyn();
		
		virtual double __getDepth( )=0;
		Dynamic __getDepth_dyn();
		virtual double __setDepth( double p_nDepth)=0;
		Dynamic __setDepth_dyn();
		
		virtual bool __getChanged( )=0;
		Dynamic __getChanged_dyn();
		virtual bool __setChanged( bool v)=0;
		Dynamic __setChanged_dyn();
		
		virtual ::sandy::materials::Material __getMaterial( )=0;
		Dynamic __getMaterial_dyn();
		virtual ::sandy::materials::Material __setMaterial( ::sandy::materials::Material v)=0;
		Dynamic __setMaterial_dyn();
		virtual Void display( ::neash::display::Sprite p_oContainer=null())=0;
		Dynamic display_dyn();
};

#define DELEGATE_sandy_core_scenegraph_IDisplayable \
virtual Void clear( ) { return mDelegate->clear();}  \
virtual Dynamic clear_dyn() { return mDelegate->clear_dyn();}  \
virtual ::neash::display::Sprite __getContainer( ) { return mDelegate->__getContainer();}  \
virtual Dynamic __getContainer_dyn() { return mDelegate->__getContainer_dyn();}  \
virtual double __getDepth( ) { return mDelegate->__getDepth();}  \
virtual Dynamic __getDepth_dyn() { return mDelegate->__getDepth_dyn();}  \
virtual double __setDepth( double p_nDepth) { return mDelegate->__setDepth(p_nDepth);}  \
virtual Dynamic __setDepth_dyn() { return mDelegate->__setDepth_dyn();}  \
virtual bool __getChanged( ) { return mDelegate->__getChanged();}  \
virtual Dynamic __getChanged_dyn() { return mDelegate->__getChanged_dyn();}  \
virtual bool __setChanged( bool v) { return mDelegate->__setChanged(v);}  \
virtual Dynamic __setChanged_dyn() { return mDelegate->__setChanged_dyn();}  \
virtual ::sandy::materials::Material __getMaterial( ) { return mDelegate->__getMaterial();}  \
virtual Dynamic __getMaterial_dyn() { return mDelegate->__getMaterial_dyn();}  \
virtual ::sandy::materials::Material __setMaterial( ::sandy::materials::Material v) { return mDelegate->__setMaterial(v);}  \
virtual Dynamic __setMaterial_dyn() { return mDelegate->__setMaterial_dyn();}  \
virtual Void display( ::neash::display::Sprite p_oContainer=null()) { return mDelegate->display(p_oContainer);}  \
virtual Dynamic display_dyn() { return mDelegate->display_dyn();}  \


template<typename IMPL>
class IDisplayable_delegate_ : public IDisplayable_obj
{
	protected:
		IMPL *mDelegate;
	public:
		IDisplayable_delegate_(IMPL *inDelegate) : mDelegate(inDelegate) {}
		hx::Object *__GetRealObject() { return mDelegate; }
		DELEGATE_sandy_core_scenegraph_IDisplayable
};

} // end namespace sandy
} // end namespace core
} // end namespace scenegraph

#endif /* INCLUDED_sandy_core_scenegraph_IDisplayable */ 
