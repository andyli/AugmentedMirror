#ifndef INCLUDED_neash_display_DisplayObject
#define INCLUDED_neash_display_DisplayObject

#include <hxcpp.h>

#include <neash/events/EventDispatcher.h>
#include <nme/display/IBitmapDrawable.h>
HX_DECLARE_CLASS2(neash,display,BlendMode)
HX_DECLARE_CLASS2(neash,display,DisplayObject)
HX_DECLARE_CLASS2(neash,display,DisplayObjectContainer)
HX_DECLARE_CLASS2(neash,display,InteractiveObject)
HX_DECLARE_CLASS2(neash,display,Stage)
HX_DECLARE_CLASS2(neash,events,EventDispatcher)
HX_DECLARE_CLASS2(neash,events,IEventDispatcher)
HX_DECLARE_CLASS2(neash,geom,Transform)
HX_DECLARE_CLASS2(nme,display,BitmapData)
HX_DECLARE_CLASS2(nme,display,Graphics)
HX_DECLARE_CLASS2(nme,display,IBitmapDrawable)
HX_DECLARE_CLASS2(nme,filters,BitmapFilterSet)
HX_DECLARE_CLASS2(nme,geom,ColorTransform)
HX_DECLARE_CLASS2(nme,geom,Matrix)
HX_DECLARE_CLASS2(nme,geom,Point)
HX_DECLARE_CLASS2(nme,geom,Rectangle)
namespace neash{
namespace display{


class DisplayObject_obj : public ::neash::events::EventDispatcher_obj{
	public:
		typedef ::neash::events::EventDispatcher_obj super;
		typedef DisplayObject_obj OBJ_;
		DisplayObject_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< DisplayObject_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~DisplayObject_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark();
		inline operator ::nme::display::IBitmapDrawable_obj *()
			{ return new ::nme::display::IBitmapDrawable_delegate_< DisplayObject_obj >(this); }
		hx::Object *__ToInterface(const type_info &inType);
		::String __ToString() const { return HX_STRING(L"DisplayObject",13); }

		double x; /* REM */ 
		double y; /* REM */ 
		double scaleX; /* REM */ 
		double scaleY; /* REM */ 
		::nme::geom::Rectangle scale9Grid; /* REM */ 
		double alpha; /* REM */ 
		::String name; /* REM */ 
		double width; /* REM */ 
		double height; /* REM */ 
		bool visible; /* REM */ 
		bool cacheAsBitmap; /* REM */ 
		Dynamic opaqueBackground; /* REM */ 
		double mouseX; /* REM */ 
		double mouseY; /* REM */ 
		::neash::display::DisplayObjectContainer parent; /* REM */ 
		::neash::display::Stage stage; /* REM */ 
		double rotation; /* REM */ 
		::nme::geom::Rectangle scrollRect; /* REM */ 
		::neash::display::DisplayObject mask; /* REM */ 
		Array< Dynamic > filters; /* REM */ 
		::neash::display::BlendMode blendMode; /* REM */ 
		int __swf_depth; /* REM */ 
		::neash::geom::Transform transform; /* REM */ 
		double mX; /* REM */ 
		double mY; /* REM */ 
		bool mSizeDirty; /* REM */ 
		::nme::geom::Rectangle mBoundsRect; /* REM */ 
		::nme::geom::Rectangle mGraphicsBounds; /* REM */ 
		::nme::geom::Rectangle mScale9Grid; /* REM */ 
		bool mBoundsDirty; /* REM */ 
		double mScaleX; /* REM */ 
		double mScaleY; /* REM */ 
		bool mTransformed; /* REM */ 
		double mRotation; /* REM */ 
		::neash::display::DisplayObjectContainer mParent; /* REM */ 
		::nme::geom::Rectangle mScrollRect; /* REM */ 
		Dynamic mOpaqueBackground; /* REM */ 
		::neash::display::DisplayObject mMask; /* REM */ 
		::neash::display::DisplayObject mMaskingObj; /* REM */ 
		Dynamic mMaskHandle; /* REM */ 
		Array< Dynamic > mFilters; /* REM */ 
		::nme::filters::BitmapFilterSet mFilterSet; /* REM */ 
		bool mCacheAsBitmap; /* REM */ 
		::nme::display::BitmapData mCachedBitmap; /* REM */ 
		::nme::display::BitmapData mFilteredBitmap; /* REM */ 
		double mCachedBitmapTx; /* REM */ 
		double mCachedBitmapTy; /* REM */ 
		::nme::geom::Rectangle mCachedBoundsRect; /* REM */ 
		bool mCCLeft; /* REM */ 
		bool mCCRight; /* REM */ 
		bool mCCTop; /* REM */ 
		bool mCCBottom; /* REM */ 
		::nme::geom::Matrix mMatrix; /* REM */ 
		::nme::geom::Matrix mFullMatrix; /* REM */ 
		virtual ::nme::display::Graphics GetBitmapDrawable( );
		Dynamic GetBitmapDrawable_dyn();

		virtual ::String toString( );
		Dynamic toString_dyn();

		virtual Void DoAdded( ::neash::display::DisplayObject inObj);
		Dynamic DoAdded_dyn();

		virtual Void DoRemoved( ::neash::display::DisplayObject inObj);
		Dynamic DoRemoved_dyn();

		virtual Void DoMouseEnter( );
		Dynamic DoMouseEnter_dyn();

		virtual Void DoMouseLeave( );
		Dynamic DoMouseLeave_dyn();

		virtual Void SetParent( ::neash::display::DisplayObjectContainer inParent);
		Dynamic SetParent_dyn();

		virtual double GetX( );
		Dynamic GetX_dyn();

		virtual ::neash::display::DisplayObjectContainer GetParent( );
		Dynamic GetParent_dyn();

		virtual double GetY( );
		Dynamic GetY_dyn();

		virtual double SetX( double inX);
		Dynamic SetX_dyn();

		virtual double SetY( double inY);
		Dynamic SetY_dyn();

		virtual ::neash::display::Stage GetStage( );
		Dynamic GetStage_dyn();

		virtual ::neash::display::DisplayObjectContainer AsContainer( );
		Dynamic AsContainer_dyn();

		virtual double GetScaleX( );
		Dynamic GetScaleX_dyn();

		virtual double GetScaleY( );
		Dynamic GetScaleY_dyn();

		virtual double SetScaleX( double inS);
		Dynamic SetScaleX_dyn();

		virtual double SetScaleY( double inS);
		Dynamic SetScaleY_dyn();

		virtual ::nme::geom::Rectangle GetScale9Grid( );
		Dynamic GetScale9Grid_dyn();

		virtual ::nme::geom::Rectangle SetScale9Grid( ::nme::geom::Rectangle inRect);
		Dynamic SetScale9Grid_dyn();

		virtual double SetRotation( double inRotation);
		Dynamic SetRotation_dyn();

		virtual double GetRotation( );
		Dynamic GetRotation_dyn();

		virtual ::nme::geom::Rectangle GetScrollRect( );
		Dynamic GetScrollRect_dyn();

		virtual ::neash::display::InteractiveObject AsInteractiveObject( );
		Dynamic AsInteractiveObject_dyn();

		virtual ::nme::geom::Rectangle SetScrollRect( ::nme::geom::Rectangle inRect);
		Dynamic SetScrollRect_dyn();

		virtual bool hitTestPoint( double x,double y,Dynamic shapeFlag);
		Dynamic hitTestPoint_dyn();

		virtual double GetMouseX( );
		Dynamic GetMouseX_dyn();

		virtual double GetMouseY( );
		Dynamic GetMouseY_dyn();

		virtual ::neash::geom::Transform GetTransform( );
		Dynamic GetTransform_dyn();

		virtual ::neash::geom::Transform SetTransform( ::neash::geom::Transform trans);
		Dynamic SetTransform_dyn();

		virtual ::nme::geom::Rectangle getBounds( ::neash::display::DisplayObject targetCoordinateSpace);
		Dynamic getBounds_dyn();

		virtual ::nme::geom::Rectangle getRect( ::neash::display::DisplayObject targetCoordinateSpace);
		Dynamic getRect_dyn();

		virtual ::nme::geom::Point globalToLocal( ::nme::geom::Point inPos);
		Dynamic globalToLocal_dyn();

		virtual int GetNumChildren( );
		Dynamic GetNumChildren_dyn();

		virtual ::nme::geom::Matrix GetMatrix( );
		Dynamic GetMatrix_dyn();

		virtual ::nme::geom::Matrix SetMatrix( ::nme::geom::Matrix inMatrix);
		Dynamic SetMatrix_dyn();

		virtual Void UpdateMatrix( );
		Dynamic UpdateMatrix_dyn();

		virtual ::nme::display::Graphics GetGraphics( );
		Dynamic GetGraphics_dyn();

		virtual int SetupRender( ::nme::geom::Matrix inParentMatrix);
		Dynamic SetupRender_dyn();

		virtual double GetHeight( );
		Dynamic GetHeight_dyn();

		virtual double SetHeight( double inHeight);
		Dynamic SetHeight_dyn();

		virtual double GetWidth( );
		Dynamic GetWidth_dyn();

		virtual double SetWidth( double inWidth);
		Dynamic SetWidth_dyn();

		virtual Dynamic GetOpaqueBackground( );
		Dynamic GetOpaqueBackground_dyn();

		virtual Dynamic SetOpaqueBackground( Dynamic inBG);
		Dynamic SetOpaqueBackground_dyn();

		virtual ::nme::geom::Rectangle GetBackgroundRect( );
		Dynamic GetBackgroundRect_dyn();

		virtual Void __RenderGfx( ::nme::display::BitmapData inTarget,::nme::geom::Rectangle inScrollRect,Dynamic inMask,double inTX,double inTY);
		Dynamic __RenderGfx_dyn();

		virtual Dynamic __Render( Dynamic inParentMask,::nme::geom::Rectangle inScrollRect,int inTX,int inTY);
		Dynamic __Render_dyn();

		virtual Void drawToSurface( Dynamic inSurface,::nme::geom::Matrix matrix,::nme::geom::ColorTransform colorTransform,::String blendMode,::nme::geom::Rectangle clipRect,bool smoothing);
		Dynamic drawToSurface_dyn();

		virtual ::neash::display::InteractiveObject GetObj( int inX,int inY,::neash::display::InteractiveObject inObj);
		Dynamic GetObj_dyn();

		virtual ::neash::display::DisplayObject GetMask( );
		Dynamic GetMask_dyn();

		virtual ::neash::display::DisplayObject SetMask( ::neash::display::DisplayObject inMask);
		Dynamic SetMask_dyn();

		virtual Void AppendMask( Dynamic inMask);
		Dynamic AppendMask_dyn();

		virtual Dynamic GetMaskHandle( );
		Dynamic GetMaskHandle_dyn();

		virtual Array< Dynamic > SetFilters( Array< Dynamic > inFilters);
		Dynamic SetFilters_dyn();

		virtual Array< Dynamic > GetFilters( );
		Dynamic GetFilters_dyn();

		virtual bool GetCacheAsBitmap( );
		Dynamic GetCacheAsBitmap_dyn();

		virtual bool SetCacheAsBitmap( bool inVal);
		Dynamic SetCacheAsBitmap_dyn();

		virtual Void ClearCache( );
		Dynamic ClearCache_dyn();

		virtual Void BuildBounds( );
		Dynamic BuildBounds_dyn();

		virtual ::nme::geom::Rectangle GetScreenBounds( );
		Dynamic GetScreenBounds_dyn();

		virtual Void RenderContentsToCache( ::nme::display::BitmapData inBitmap,double inTX,double inTY);
		Dynamic RenderContentsToCache_dyn();

		virtual Void CreateBitmapCache( );
		Dynamic CreateBitmapCache_dyn();

		virtual ::neash::display::InteractiveObject GetChildCachedObj( int inX,int inY,::neash::display::InteractiveObject inObj);
		Dynamic GetChildCachedObj_dyn();

		virtual ::neash::display::InteractiveObject CacheGetObj( int inX,int inY,::neash::display::InteractiveObject inObj);
		Dynamic CacheGetObj_dyn();

		virtual Void GetFocusObjects( Array< ::neash::display::InteractiveObject > outObjs);
		Dynamic GetFocusObjects_dyn();

		virtual int __BlendIndex( );
		Dynamic __BlendIndex_dyn();

		virtual Void RenderCache( Dynamic inMaskHandle);
		Dynamic RenderCache_dyn();

		static int mNameID; /* REM */ 
		static int TRANSLATE_CHANGE; /* REM */ 
		static int NON_TRANSLATE_CHANGE; /* REM */ 
		static int GRAPHICS_CHANGE; /* REM */ 
};

} // end namespace neash
} // end namespace display

#endif /* INCLUDED_neash_display_DisplayObject */ 
