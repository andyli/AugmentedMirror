#ifndef INCLUDED_neash_display_DisplayObjectContainer
#define INCLUDED_neash_display_DisplayObjectContainer

#include <hxcpp.h>

#include <neash/display/InteractiveObject.h>
HX_DECLARE_CLASS2(neash,display,DisplayObject)
HX_DECLARE_CLASS2(neash,display,DisplayObjectContainer)
HX_DECLARE_CLASS2(neash,display,InteractiveObject)
HX_DECLARE_CLASS2(neash,events,Event)
HX_DECLARE_CLASS2(neash,events,EventDispatcher)
HX_DECLARE_CLASS2(neash,events,IEventDispatcher)
HX_DECLARE_CLASS2(nme,display,BitmapData)
HX_DECLARE_CLASS2(nme,display,IBitmapDrawable)
HX_DECLARE_CLASS2(nme,geom,Matrix)
HX_DECLARE_CLASS2(nme,geom,Rectangle)
namespace neash{
namespace display{


class DisplayObjectContainer_obj : public ::neash::display::InteractiveObject_obj{
	public:
		typedef ::neash::display::InteractiveObject_obj super;
		typedef DisplayObjectContainer_obj OBJ_;
		DisplayObjectContainer_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< DisplayObjectContainer_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~DisplayObjectContainer_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark();
		::String __ToString() const { return HX_STRING(L"DisplayObjectContainer",22); }

		Array< ::neash::display::DisplayObject > mObjs; /* REM */ 
		Array< ::neash::display::DisplayObject > mLastSetupObjs; /* REM */ 
		int numChildren; /* REM */ 
		bool mouseChildren; /* REM */ 
		virtual Void AppendMask( Dynamic inMask);
		Dynamic AppendMask_dyn();

		virtual ::neash::display::DisplayObjectContainer AsContainer( );
		Dynamic AsContainer_dyn();

		virtual Void Broadcast( ::neash::events::Event inEvent);
		Dynamic Broadcast_dyn();

		virtual Void BuildBounds( );
		Dynamic BuildBounds_dyn();

		virtual Void DoAdded( ::neash::display::DisplayObject inObj);
		Dynamic DoAdded_dyn();

		virtual Void DoRemoved( ::neash::display::DisplayObject inObj);
		Dynamic DoRemoved_dyn();

		virtual ::nme::geom::Rectangle GetBackgroundRect( );
		Dynamic GetBackgroundRect_dyn();

		virtual Void GetFocusObjects( Array< ::neash::display::InteractiveObject > outObjs);
		Dynamic GetFocusObjects_dyn();

		virtual ::neash::display::InteractiveObject GetChildCachedObj( int inX,int inY,::neash::display::InteractiveObject inObj);
		Dynamic GetChildCachedObj_dyn();

		virtual Dynamic GetMaskHandle( );
		Dynamic GetMaskHandle_dyn();

		virtual int GetNumChildren( );
		Dynamic GetNumChildren_dyn();

		virtual ::neash::display::InteractiveObject GetObj( int inX,int inY,::neash::display::InteractiveObject inObj);
		Dynamic GetObj_dyn();

		virtual Dynamic __Render( Dynamic inMask,::nme::geom::Rectangle inScrollRect,int inTX,int inTY);
		Dynamic __Render_dyn();

		virtual Void RenderContentsToCache( ::nme::display::BitmapData inBitmap,double inTX,double inTY);
		Dynamic RenderContentsToCache_dyn();

		virtual int SetupRender( ::nme::geom::Matrix inParentMatrix);
		Dynamic SetupRender_dyn();

		virtual Void addChild( ::neash::display::DisplayObject inObject);
		Dynamic addChild_dyn();

		virtual Void addChildAt( ::neash::display::DisplayObject obj,int index);
		Dynamic addChildAt_dyn();

		virtual bool contains( ::neash::display::DisplayObject obj);
		Dynamic contains_dyn();

		virtual ::neash::display::DisplayObject getChildAt( int index);
		Dynamic getChildAt_dyn();

		virtual ::neash::display::DisplayObject getChildByName( ::String inName);
		Dynamic getChildByName_dyn();

		virtual int getChildIndex( ::neash::display::DisplayObject child);
		Dynamic getChildIndex_dyn();

		virtual Void removeChild( ::neash::display::DisplayObject child);
		Dynamic removeChild_dyn();

		virtual Void removeChildAt( int inI);
		Dynamic removeChildAt_dyn();

		virtual Void __removeChild( ::neash::display::DisplayObject child);
		Dynamic __removeChild_dyn();

		virtual Void setChildIndex( ::neash::display::DisplayObject child,int index);
		Dynamic setChildIndex_dyn();

		virtual Void swapChildren( ::neash::display::DisplayObject child1,::neash::display::DisplayObject child2);
		Dynamic swapChildren_dyn();

		virtual Void swapChildrenAt( int child1,int child2);
		Dynamic swapChildrenAt_dyn();

};

} // end namespace neash
} // end namespace display

#endif /* INCLUDED_neash_display_DisplayObjectContainer */ 
