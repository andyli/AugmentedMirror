#include <hxcpp.h>

#ifndef INCLUDED_hxMath
#include <hxMath.h>
#endif
#ifndef INCLUDED_Std
#include <Std.h>
#endif
#ifndef INCLUDED_neash_Lib
#include <neash/Lib.h>
#endif
#ifndef INCLUDED_neash_display_BlendMode
#include <neash/display/BlendMode.h>
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
#ifndef INCLUDED_neash_geom_Transform
#include <neash/geom/Transform.h>
#endif
#ifndef INCLUDED_nme_Manager
#include <nme/Manager.h>
#endif
#ifndef INCLUDED_nme_display_BitmapData
#include <nme/display/BitmapData.h>
#endif
#ifndef INCLUDED_nme_display_Graphics
#include <nme/display/Graphics.h>
#endif
#ifndef INCLUDED_nme_display_IBitmapDrawable
#include <nme/display/IBitmapDrawable.h>
#endif
#ifndef INCLUDED_nme_filters_BitmapFilterSet
#include <nme/filters/BitmapFilterSet.h>
#endif
#ifndef INCLUDED_nme_geom_ColorTransform
#include <nme/geom/ColorTransform.h>
#endif
#ifndef INCLUDED_nme_geom_Matrix
#include <nme/geom/Matrix.h>
#endif
#ifndef INCLUDED_nme_geom_Point
#include <nme/geom/Point.h>
#endif
#ifndef INCLUDED_nme_geom_Rectangle
#include <nme/geom/Rectangle.h>
#endif
namespace neash{
namespace display{

Void DisplayObject_obj::__construct()
{
{
	this->mParent = null();
	super::__construct(null());
	this->mX = this->mY = 0;
	this->mScaleX = this->mScaleY = 1.0;
	this->alpha = 1.0;
	this->mTransformed = false;
	this->mRotation = 0.0;
	this->__swf_depth = 0;
	this->mMatrix = ::nme::geom::Matrix_obj::__new(null(),null(),null(),null(),null(),null());
	this->mFullMatrix = ::nme::geom::Matrix_obj::__new(null(),null(),null(),null(),null(),null());
	this->mMask = null();
	this->mMaskingObj = null();
	this->mCacheAsBitmap = false;
	this->mCachedBitmap = null();
	this->mFilteredBitmap = null();
	this->mCachedBitmapTx = 0;
	this->mCachedBitmapTy = 0;
	this->mBoundsDirty = true;
	this->mBoundsRect = ::nme::geom::Rectangle_obj::__new(null(),null(),null(),null());
	this->mGraphicsBounds = null();
	this->mMaskHandle = null();
	this->mCCLeft = this->mCCRight = this->mCCTop = this->mCCBottom = false;
	this->name = (HX_STRING(L"DisplayObject ",14) + ::neash::display::DisplayObject_obj::mNameID++);
	this->visible = true;
}
;
	return null();
}

DisplayObject_obj::~DisplayObject_obj() { }

Dynamic DisplayObject_obj::__CreateEmpty() { return  new DisplayObject_obj; }
hx::ObjectPtr< DisplayObject_obj > DisplayObject_obj::__new()
{  hx::ObjectPtr< DisplayObject_obj > result = new DisplayObject_obj();
	result->__construct();
	return result;}

Dynamic DisplayObject_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< DisplayObject_obj > result = new DisplayObject_obj();
	result->__construct();
	return result;}

hx::Object *DisplayObject_obj::__ToInterface(const type_info &inType) {
	if (inType==typeid( ::nme::display::IBitmapDrawable_obj)) return operator ::nme::display::IBitmapDrawable_obj *();
	return super::__ToInterface(inType);
}

::nme::display::Graphics DisplayObject_obj::GetBitmapDrawable( ){
	__SAFE_POINT
	return this->GetGraphics();
}


HX_DEFINE_DYNAMIC_FUNC0(DisplayObject_obj,GetBitmapDrawable,return )

::String DisplayObject_obj::toString( ){
	return this->name;
}


HX_DEFINE_DYNAMIC_FUNC0(DisplayObject_obj,toString,return )

Void DisplayObject_obj::DoAdded( ::neash::display::DisplayObject inObj){
{
		__SAFE_POINT
		if ((inObj == this)){
			::neash::events::Event evt = ::neash::events::Event_obj::__new(::neash::events::Event_obj::ADDED,true,false);
			evt->target = inObj;
			this->dispatchEvent(evt);
		}
		::neash::events::Event evt = ::neash::events::Event_obj::__new(::neash::events::Event_obj::ADDED_TO_STAGE,false,false);
		evt->target = inObj;
		this->dispatchEvent(evt);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(DisplayObject_obj,DoAdded,(void))

Void DisplayObject_obj::DoRemoved( ::neash::display::DisplayObject inObj){
{
		__SAFE_POINT
		if ((inObj == this)){
			::neash::events::Event evt = ::neash::events::Event_obj::__new(::neash::events::Event_obj::REMOVED,true,false);
			evt->target = inObj;
			this->dispatchEvent(evt);
		}
		::neash::events::Event evt = ::neash::events::Event_obj::__new(::neash::events::Event_obj::REMOVED_FROM_STAGE,false,false);
		evt->target = inObj;
		this->dispatchEvent(evt);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(DisplayObject_obj,DoRemoved,(void))

Void DisplayObject_obj::DoMouseEnter( ){
{
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(DisplayObject_obj,DoMouseEnter,(void))

Void DisplayObject_obj::DoMouseLeave( ){
{
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(DisplayObject_obj,DoMouseLeave,(void))

Void DisplayObject_obj::SetParent( ::neash::display::DisplayObjectContainer inParent){
{
		__SAFE_POINT
		if ((inParent == this->mParent))
			return null();
		if ((this->mParent != null()))
			this->mParent->__removeChild(this);
		if ((bool((this->mParent == null())) && bool((inParent != null())))){
			this->mParent = inParent;
			this->DoAdded(this);
		}
		else{
			if ((bool((this->mParent != null())) && bool((inParent == null())))){
				this->mParent = inParent;
				this->DoRemoved(this);
			}
			else{
				this->mParent = inParent;
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(DisplayObject_obj,SetParent,(void))

double DisplayObject_obj::GetX( ){
	return this->mX;
}


HX_DEFINE_DYNAMIC_FUNC0(DisplayObject_obj,GetX,return )

::neash::display::DisplayObjectContainer DisplayObject_obj::GetParent( ){
	return this->mParent;
}


HX_DEFINE_DYNAMIC_FUNC0(DisplayObject_obj,GetParent,return )

double DisplayObject_obj::GetY( ){
	return this->mY;
}


HX_DEFINE_DYNAMIC_FUNC0(DisplayObject_obj,GetY,return )

double DisplayObject_obj::SetX( double inX){
	__SAFE_POINT
	this->mX = inX;
	this->UpdateMatrix();
	return this->mX;
}


HX_DEFINE_DYNAMIC_FUNC1(DisplayObject_obj,SetX,return )

double DisplayObject_obj::SetY( double inY){
	__SAFE_POINT
	this->mY = inY;
	this->UpdateMatrix();
	return this->mY;
}


HX_DEFINE_DYNAMIC_FUNC1(DisplayObject_obj,SetY,return )

::neash::display::Stage DisplayObject_obj::GetStage( ){
	__SAFE_POINT
	return ::neash::Lib_obj::GetStage();
}


HX_DEFINE_DYNAMIC_FUNC0(DisplayObject_obj,GetStage,return )

::neash::display::DisplayObjectContainer DisplayObject_obj::AsContainer( ){
	return null();
}


HX_DEFINE_DYNAMIC_FUNC0(DisplayObject_obj,AsContainer,return )

double DisplayObject_obj::GetScaleX( ){
	return this->mScaleX;
}


HX_DEFINE_DYNAMIC_FUNC0(DisplayObject_obj,GetScaleX,return )

double DisplayObject_obj::GetScaleY( ){
	return this->mScaleY;
}


HX_DEFINE_DYNAMIC_FUNC0(DisplayObject_obj,GetScaleY,return )

double DisplayObject_obj::SetScaleX( double inS){
	__SAFE_POINT
	this->mScaleX = inS;
	this->UpdateMatrix();
	return inS;
}


HX_DEFINE_DYNAMIC_FUNC1(DisplayObject_obj,SetScaleX,return )

double DisplayObject_obj::SetScaleY( double inS){
	__SAFE_POINT
	this->mScaleY = inS;
	this->UpdateMatrix();
	return inS;
}


HX_DEFINE_DYNAMIC_FUNC1(DisplayObject_obj,SetScaleY,return )

::nme::geom::Rectangle DisplayObject_obj::GetScale9Grid( ){
	__SAFE_POINT
	if ((this->mScale9Grid == null()))
		return null();
	return this->mScale9Grid->clone();
}


HX_DEFINE_DYNAMIC_FUNC0(DisplayObject_obj,GetScale9Grid,return )

::nme::geom::Rectangle DisplayObject_obj::SetScale9Grid( ::nme::geom::Rectangle inRect){
	__SAFE_POINT
	if ((inRect == null())){
		this->mScale9Grid = null();
		return null();
	}
	this->mScale9Grid = inRect->clone();
	return this->mScale9Grid->clone();
}


HX_DEFINE_DYNAMIC_FUNC1(DisplayObject_obj,SetScale9Grid,return )

double DisplayObject_obj::SetRotation( double inRotation){
	__SAFE_POINT
	this->mRotation = (double(((inRotation * ::Math_obj::PI))) / double(180.0));
	this->UpdateMatrix();
	return inRotation;
}


HX_DEFINE_DYNAMIC_FUNC1(DisplayObject_obj,SetRotation,return )

double DisplayObject_obj::GetRotation( ){
	return (this->mRotation * ((double(180.0) / double(::Math_obj::PI))));
}


HX_DEFINE_DYNAMIC_FUNC0(DisplayObject_obj,GetRotation,return )

::nme::geom::Rectangle DisplayObject_obj::GetScrollRect( ){
	__SAFE_POINT
	if ((this->mScrollRect == null()))
		return null();
	return this->mScrollRect->clone();
}


HX_DEFINE_DYNAMIC_FUNC0(DisplayObject_obj,GetScrollRect,return )

::neash::display::InteractiveObject DisplayObject_obj::AsInteractiveObject( ){
	return null();
}


HX_DEFINE_DYNAMIC_FUNC0(DisplayObject_obj,AsInteractiveObject,return )

::nme::geom::Rectangle DisplayObject_obj::SetScrollRect( ::nme::geom::Rectangle inRect){
	__SAFE_POINT
	this->mScrollRect = inRect;
	return this->GetScrollRect();
}


HX_DEFINE_DYNAMIC_FUNC1(DisplayObject_obj,SetScrollRect,return )

bool DisplayObject_obj::hitTestPoint( double x,double y,Dynamic shapeFlag){
	bool bounding_box = (shapeFlag == null()) ? bool( true ) : bool( !shapeFlag );
	return true;
}


HX_DEFINE_DYNAMIC_FUNC3(DisplayObject_obj,hitTestPoint,return )

double DisplayObject_obj::GetMouseX( ){
	__SAFE_POINT
	return this->globalToLocal(::neash::Lib_obj::mLastMouse)->x;
}


HX_DEFINE_DYNAMIC_FUNC0(DisplayObject_obj,GetMouseX,return )

double DisplayObject_obj::GetMouseY( ){
	__SAFE_POINT
	return this->globalToLocal(::neash::Lib_obj::mLastMouse)->y;
}


HX_DEFINE_DYNAMIC_FUNC0(DisplayObject_obj,GetMouseY,return )

::neash::geom::Transform DisplayObject_obj::GetTransform( ){
	return ::neash::geom::Transform_obj::__new(this);
}


HX_DEFINE_DYNAMIC_FUNC0(DisplayObject_obj,GetTransform,return )

::neash::geom::Transform DisplayObject_obj::SetTransform( ::neash::geom::Transform trans){
	__SAFE_POINT
	this->mTransformed = true;
	this->mMatrix = trans->GetMatrix()->clone();
	return trans;
}


HX_DEFINE_DYNAMIC_FUNC1(DisplayObject_obj,SetTransform,return )

::nme::geom::Rectangle DisplayObject_obj::getBounds( ::neash::display::DisplayObject targetCoordinateSpace){
	return null();
}


HX_DEFINE_DYNAMIC_FUNC1(DisplayObject_obj,getBounds,return )

::nme::geom::Rectangle DisplayObject_obj::getRect( ::neash::display::DisplayObject targetCoordinateSpace){
	return null();
}


HX_DEFINE_DYNAMIC_FUNC1(DisplayObject_obj,getRect,return )

::nme::geom::Point DisplayObject_obj::globalToLocal( ::nme::geom::Point inPos){
	__SAFE_POINT
	return this->mFullMatrix->clone()->invert()->transformPoint(inPos);
}


HX_DEFINE_DYNAMIC_FUNC1(DisplayObject_obj,globalToLocal,return )

int DisplayObject_obj::GetNumChildren( ){
	return 0;
}


HX_DEFINE_DYNAMIC_FUNC0(DisplayObject_obj,GetNumChildren,return )

::nme::geom::Matrix DisplayObject_obj::GetMatrix( ){
	__SAFE_POINT
	return this->mMatrix->clone();
}


HX_DEFINE_DYNAMIC_FUNC0(DisplayObject_obj,GetMatrix,return )

::nme::geom::Matrix DisplayObject_obj::SetMatrix( ::nme::geom::Matrix inMatrix){
	__SAFE_POINT
	this->mMatrix = inMatrix->clone();
	this->mTransformed = (bool((this->mMatrix->a != 1)) || bool((bool((this->mMatrix->b != 0)) || bool((bool((this->mMatrix->tx != 0)) || bool((bool((this->mMatrix->c != 0)) || bool((bool((this->mMatrix->d != 1)) || bool((this->mMatrix->ty != 0)))))))))));
	return inMatrix;
}


HX_DEFINE_DYNAMIC_FUNC1(DisplayObject_obj,SetMatrix,return )

Void DisplayObject_obj::UpdateMatrix( ){
{
		__SAFE_POINT
		this->mMatrix = ::nme::geom::Matrix_obj::__new(this->mScaleX,0.0,0.0,this->mScaleY,null(),null());
		if ((this->mRotation != 0.0))
			this->mMatrix->rotate(this->mRotation);
		this->mMatrix->tx = this->mX;
		this->mMatrix->ty = this->mY;
		this->mTransformed = (bool((this->mMatrix->a != 1)) || bool((bool((this->mMatrix->c != 0)) || bool((bool((this->mMatrix->tx != 0)) || bool((bool((this->mMatrix->b != 0)) || bool((bool((this->mMatrix->d != 1)) || bool((this->mMatrix->ty != 0)))))))))));
		this->ClearCache();
		this->mBoundsDirty = true;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(DisplayObject_obj,UpdateMatrix,(void))

::nme::display::Graphics DisplayObject_obj::GetGraphics( ){
	return null();
}


HX_DEFINE_DYNAMIC_FUNC0(DisplayObject_obj,GetGraphics,return )

int DisplayObject_obj::SetupRender( ::nme::geom::Matrix inParentMatrix){
	__SAFE_POINT
	int result = 0;
	::nme::geom::Matrix m;
	if ((this->mScale9Grid != null())){
		m = inParentMatrix->clone();
		hx::AddEq(m->tx,(this->GetX() * inParentMatrix->a));
		hx::AddEq(m->ty,(this->GetY() * inParentMatrix->d));
	}
	else{
		if (this->mTransformed){
			m = this->mMatrix->mult(inParentMatrix);
		}
		else{
			m = inParentMatrix;
		}
	}
	if ((bool((m->a != this->mFullMatrix->a)) || bool((bool((m->b != this->mFullMatrix->b)) || bool((bool((m->c != this->mFullMatrix->c)) || bool((m->d != this->mFullMatrix->d))))))))
		hx::OrEq(result,::neash::display::DisplayObject_obj::NON_TRANSLATE_CHANGE);
	if ((bool((m->tx != this->mFullMatrix->tx)) || bool((m->ty != this->mFullMatrix->ty))))
		hx::OrEq(result,::neash::display::DisplayObject_obj::TRANSLATE_CHANGE);
	::nme::display::Graphics gfx = this->GetGraphics();
	if ((gfx != null())){
		if (gfx->CheckChanged()){
			hx::OrEq(result,(int(::neash::display::DisplayObject_obj::NON_TRANSLATE_CHANGE) | int(::neash::display::DisplayObject_obj::GRAPHICS_CHANGE)));
			this->mGraphicsBounds = null();
		}
	}
	if ((((int(result) & int(::neash::display::DisplayObject_obj::NON_TRANSLATE_CHANGE))) != 0)){
		this->mBoundsDirty = true;
	}
	else{
		if ((result != 0)){
			hx::AddEq(this->mBoundsRect->x,(m->tx - this->mFullMatrix->tx));
			hx::AddEq(this->mBoundsRect->y,(m->ty - this->mFullMatrix->ty));
			double dx = (this->mFullMatrix->tx + this->mCachedBitmapTx);
			double dy = (this->mFullMatrix->ty + this->mCachedBitmapTy);
			if ((bool(((bool(this->mCCLeft) && bool(((dx < 0)))))) || bool((bool(((bool(this->mCCRight) && bool(((dx > 0)))))) || bool((bool(((bool(this->mCCBottom) && bool(((dy < 0)))))) || bool(((bool(this->mCCTop) && bool(((dy > 0)))))))))))){
				this->mCachedBitmap = null();
			}
		}
	}
	this->mFullMatrix = m;
	if ((bool(this->GetCacheAsBitmap()) && bool((this->GetNumChildren() == 0)))){
		if ((bool((this->mCachedBitmap == null())) || bool((((int(result) & int(::neash::display::DisplayObject_obj::NON_TRANSLATE_CHANGE))) != 0)))){
			this->CreateBitmapCache();
		}
	}
	if ((result != 0))
		this->mMaskHandle = null();
	return result;
}


HX_DEFINE_DYNAMIC_FUNC1(DisplayObject_obj,SetupRender,return )

double DisplayObject_obj::GetHeight( ){
	__SAFE_POINT
	this->BuildBounds();
	return this->mBoundsRect->height;
}


HX_DEFINE_DYNAMIC_FUNC0(DisplayObject_obj,GetHeight,return )

double DisplayObject_obj::SetHeight( double inHeight){
	__SAFE_POINT
	this->BuildBounds();
	double h = this->mBoundsRect->height;
	if ((inHeight != h)){
		if ((h <= 0))
			return 0;
		hx::MultEq(this->mScaleY,(double(inHeight) / double(h)));
		this->UpdateMatrix();
	}
	return inHeight;
}


HX_DEFINE_DYNAMIC_FUNC1(DisplayObject_obj,SetHeight,return )

double DisplayObject_obj::GetWidth( ){
	__SAFE_POINT
	this->BuildBounds();
	return this->mBoundsRect->width;
}


HX_DEFINE_DYNAMIC_FUNC0(DisplayObject_obj,GetWidth,return )

double DisplayObject_obj::SetWidth( double inWidth){
	__SAFE_POINT
	this->BuildBounds();
	double w = this->mBoundsRect->width;
	if ((w != inWidth)){
		if ((w <= 0))
			return 0;
		hx::MultEq(this->mScaleX,(double(inWidth) / double(w)));
		this->UpdateMatrix();
	}
	return inWidth;
}


HX_DEFINE_DYNAMIC_FUNC1(DisplayObject_obj,SetWidth,return )

Dynamic DisplayObject_obj::GetOpaqueBackground( ){
	return this->mOpaqueBackground;
}


HX_DEFINE_DYNAMIC_FUNC0(DisplayObject_obj,GetOpaqueBackground,return )

Dynamic DisplayObject_obj::SetOpaqueBackground( Dynamic inBG){
	this->mOpaqueBackground = inBG;
	return this->mOpaqueBackground;
}


HX_DEFINE_DYNAMIC_FUNC1(DisplayObject_obj,SetOpaqueBackground,return )

::nme::geom::Rectangle DisplayObject_obj::GetBackgroundRect( ){
	__SAFE_POINT
	if ((this->mGraphicsBounds == null())){
		::nme::display::Graphics gfx = this->GetGraphics();
		if ((gfx != null()))
			this->mGraphicsBounds = gfx->GetExtent(::nme::geom::Matrix_obj::__new(null(),null(),null(),null(),null(),null()));
	}
	return this->mGraphicsBounds;
}


HX_DEFINE_DYNAMIC_FUNC0(DisplayObject_obj,GetBackgroundRect,return )

Void DisplayObject_obj::__RenderGfx( ::nme::display::BitmapData inTarget,::nme::geom::Rectangle inScrollRect,Dynamic inMask,double inTX,double inTY){
{
		__SAFE_POINT
		::nme::display::Graphics gfx = this->GetGraphics();
		if ((gfx != null())){
			int blend = (this->blendMode == null()) ? int( ::nme::display::Graphics_obj::BLEND_NORMAL ) : int( this->blendMode->__Index() );
			::nme::display::Graphics_obj::setBlendMode(blend);
			Dynamic handle = (inTarget == null()) ? Dynamic( null() ) : Dynamic( inTarget->handle() );
			if ((this->mScale9Grid != null())){
				::nme::geom::Rectangle data = this->GetBackgroundRect();
				gfx->SetScale9Grid(this->mScale9Grid,this->GetScaleX(),this->GetScaleY(),data);
			}
			if ((bool((inScrollRect != null())) || bool((inTarget != null())))){
				::nme::geom::Matrix m = this->mFullMatrix->clone();
				hx::SubEq(m->tx,inTX);
				hx::SubEq(m->ty,inTY);
				gfx->render(m,handle,inMask,inScrollRect);
			}
			else{
				gfx->render(this->mFullMatrix,handle,inMask,null());
			}
			gfx->SetScale9Grid(null(),0,0,null());
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC5(DisplayObject_obj,__RenderGfx,(void))

Dynamic DisplayObject_obj::__Render( Dynamic inParentMask,::nme::geom::Rectangle inScrollRect,int inTX,int inTY){
	__SAFE_POINT
	Dynamic mask_handle = (inParentMask != null()) ? Dynamic( inParentMask ) : Dynamic( ((this->mMask != null()) ? Dynamic( this->mMask->GetMaskHandle() ) : Dynamic( null() )) );
	bool bmp = this->GetCacheAsBitmap();
	if ((bool(bmp) && bool((this->mCachedBitmap != null())))){
		int blend = (this->blendMode == null()) ? int( ::nme::display::Graphics_obj::BLEND_NORMAL ) : int( this->blendMode->__Index() );
		::nme::display::Graphics_obj::setBlendMode(blend);
		this->RenderCache(mask_handle);
	}
	else{
		if (bmp){
		}
		else{
			if ((this->mOpaqueBackground != null())){
				::nme::geom::Rectangle bg = this->GetBackgroundRect();
				if ((bg != null())){
					::nme::display::Graphics gfx = ::nme::Manager_obj::graphics;
					::nme::display::Graphics_obj::immediateMatrix = this->mFullMatrix;
					::nme::display::Graphics_obj::immediateMask = mask_handle;
					gfx->beginFill(this->mOpaqueBackground,null());
					gfx->drawRect(bg->x,bg->y,bg->width,bg->height);
					gfx->endFill();
					gfx->flush();
					::nme::display::Graphics_obj::immediateMatrix = null();
					::nme::display::Graphics_obj::immediateMask = null();
				}
			}
			this->__RenderGfx(null(),inScrollRect,inParentMask,inTX,inTY);
		}
	}
	return mask_handle;
}


HX_DEFINE_DYNAMIC_FUNC4(DisplayObject_obj,__Render,return )

Void DisplayObject_obj::drawToSurface( Dynamic inSurface,::nme::geom::Matrix matrix,::nme::geom::ColorTransform colorTransform,::String blendMode,::nme::geom::Rectangle clipRect,bool smoothing){
{
		__SAFE_POINT
		if ((matrix == null()))
			matrix = ::nme::geom::Matrix_obj::__new(null(),null(),null(),null(),null(),null());
		this->SetupRender(matrix);
		this->RenderContentsToCache(inSurface,0,0);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC6(DisplayObject_obj,drawToSurface,(void))

::neash::display::InteractiveObject DisplayObject_obj::GetObj( int inX,int inY,::neash::display::InteractiveObject inObj){
	__SAFE_POINT
	if ((bool(!this->visible) || bool((this->mMaskingObj != null()))))
		return null();
	if ((bool(this->GetCacheAsBitmap()) && bool((this->mCachedBitmap != null()))))
		return this->CacheGetObj(inX,inY,inObj);
	::nme::display::Graphics gfx = this->GetGraphics();
	if ((bool((gfx != null())) && bool(gfx->hitTest(inX,inY)))){
		::neash::display::InteractiveObject i = this->AsInteractiveObject();
		return (i == null()) ? ::neash::display::InteractiveObject( inObj ) : ::neash::display::InteractiveObject( i );
	}
	return null();
}


HX_DEFINE_DYNAMIC_FUNC3(DisplayObject_obj,GetObj,return )

::neash::display::DisplayObject DisplayObject_obj::GetMask( ){
	return this->mMask;
}


HX_DEFINE_DYNAMIC_FUNC0(DisplayObject_obj,GetMask,return )

::neash::display::DisplayObject DisplayObject_obj::SetMask( ::neash::display::DisplayObject inMask){
	if ((this->mMask != null()))
		this->mMask->mMaskingObj = null();
	this->mMask = inMask;
	if ((this->mMask != null()))
		this->mMask->mMaskingObj = this;
	return this->mMask;
}


HX_DEFINE_DYNAMIC_FUNC1(DisplayObject_obj,SetMask,return )

Void DisplayObject_obj::AppendMask( Dynamic inMask){
{
		__SAFE_POINT
		::nme::display::Graphics gfx = this->GetGraphics();
		if ((gfx != null()))
			gfx->AddToMask(inMask,this->mFullMatrix,null());
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(DisplayObject_obj,AppendMask,(void))

Dynamic DisplayObject_obj::GetMaskHandle( ){
	__SAFE_POINT
	if ((this->mMaskingObj == null()))
		hx::Throw (HX_STRING(L"mask object mismatch",20));
	if ((this->mMaskHandle == null())){
		::nme::display::Graphics gfx = this->GetGraphics();
		if ((gfx != null())){
			this->mMaskHandle = gfx->CreateMask(this->mFullMatrix);
		}
	}
	return this->mMaskHandle;
}


HX_DEFINE_DYNAMIC_FUNC0(DisplayObject_obj,GetMaskHandle,return )

Array< Dynamic > DisplayObject_obj::SetFilters( Array< Dynamic > inFilters){
	__SAFE_POINT
	Array< Dynamic > f = Array_obj< Dynamic >::__new();
	if ((inFilters != null())){
		int _g = 0;
		while((_g < inFilters->length)){
			__SAFE_POINT
			Dynamic filter = inFilters->__get(_g);
			++_g;
			f->push(filter->__Field(HX_STRING(L"clone",5))());
		}
	}
	this->mFilters = f;
	this->mCachedBitmap = null();
	this->mFilteredBitmap = null();
	if ((this->mFilters->length < 1)){
		this->mFilterSet = null();
	}
	else{
		this->mFilterSet = ::nme::filters::BitmapFilterSet_obj::__new(this->mFilters);
	}
	return this->GetFilters();
}


HX_DEFINE_DYNAMIC_FUNC1(DisplayObject_obj,SetFilters,return )

Array< Dynamic > DisplayObject_obj::GetFilters( ){
	__SAFE_POINT
	Array< Dynamic > f = Array_obj< Dynamic >::__new();
	if ((this->mFilters != null())){
		{
			int _g = 0;
			Array< Dynamic > _g1 = this->mFilters;
			while((_g < _g1->length)){
				__SAFE_POINT
				Dynamic filter = _g1->__get(_g);
				++_g;
				f->push(filter->__Field(HX_STRING(L"clone",5))());
			}
		}
	}
	return f;
}


HX_DEFINE_DYNAMIC_FUNC0(DisplayObject_obj,GetFilters,return )

bool DisplayObject_obj::GetCacheAsBitmap( ){
	__SAFE_POINT
	return (bool(this->mCacheAsBitmap) || bool((bool(((this->mFilters != null()))) || bool(((bool(!::neash::Lib_obj::IsOpenGL()) && bool(((bool((this->blendMode != null())) && bool((this->blendMode != ::neash::display::BlendMode_obj::NORMAL)))))))))));
}


HX_DEFINE_DYNAMIC_FUNC0(DisplayObject_obj,GetCacheAsBitmap,return )

bool DisplayObject_obj::SetCacheAsBitmap( bool inVal){
	__SAFE_POINT
	this->mCacheAsBitmap = inVal;
	bool c = this->GetCacheAsBitmap();
	if (!c)
		this->ClearCache();
	return c;
}


HX_DEFINE_DYNAMIC_FUNC1(DisplayObject_obj,SetCacheAsBitmap,return )

Void DisplayObject_obj::ClearCache( ){
{
		this->mCachedBitmap = null();
		this->mFilteredBitmap = null();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(DisplayObject_obj,ClearCache,(void))

Void DisplayObject_obj::BuildBounds( ){
{
		__SAFE_POINT
		if ((bool(this->mBoundsDirty) || bool((this->mBoundsRect == null())))){
			this->mBoundsDirty = false;
			::nme::display::Graphics gfx = this->GetGraphics();
			if ((gfx == null())){
				this->mBoundsRect = ::nme::geom::Rectangle_obj::__new(this->mFullMatrix->tx,this->mFullMatrix->ty,0,0);
			}
			else{
				this->mBoundsRect = gfx->GetExtent(this->mFullMatrix);
				if ((this->mScale9Grid != null())){
					hx::MultEq(this->mBoundsRect->width,this->GetScaleX());
					hx::MultEq(this->mBoundsRect->height,this->GetScaleY());
				}
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(DisplayObject_obj,BuildBounds,(void))

::nme::geom::Rectangle DisplayObject_obj::GetScreenBounds( ){
	__SAFE_POINT
	this->BuildBounds();
	return this->mBoundsRect->clone();
}


HX_DEFINE_DYNAMIC_FUNC0(DisplayObject_obj,GetScreenBounds,return )

Void DisplayObject_obj::RenderContentsToCache( ::nme::display::BitmapData inBitmap,double inTX,double inTY){
{
		__SAFE_POINT
		this->__RenderGfx(inBitmap,null(),null(),inTX,inTY);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC3(DisplayObject_obj,RenderContentsToCache,(void))

Void DisplayObject_obj::CreateBitmapCache( ){
{
		__SAFE_POINT
		this->BuildBounds();
		this->mCachedBitmap = null();
		this->mFilteredBitmap = null();
		if ((bool((this->mBoundsRect->width > 0)) && bool((this->mBoundsRect->height > 0)))){
			this->mCachedBoundsRect = this->mBoundsRect->clone();
			::nme::geom::Rectangle cached_rect = this->mBoundsRect->intersection(::nme::geom::Rectangle_obj::__new(0,0,this->GetStage()->GetStageWidth(),this->GetStage()->GetStageHeight()));
			this->mCCLeft = (this->mBoundsRect->get_left() != cached_rect->get_left());
			this->mCCRight = (this->mBoundsRect->get_right() != cached_rect->get_right());
			this->mCCTop = (this->mBoundsRect->get_top() != cached_rect->get_top());
			this->mCCBottom = (this->mBoundsRect->get_bottom() != cached_rect->get_bottom());
			int w = ::Std_obj::toInt((cached_rect->width + 1));
			int h = ::Std_obj::toInt((cached_rect->height + 1));
			if ((bool((cached_rect->width > 0)) && bool((bool((cached_rect->height > 0)) && bool((bool((w > 0)) && bool((h > 0)))))))){
				this->mCachedBitmapTx = ::Math_obj::floor(cached_rect->x);
				this->mCachedBitmapTy = ::Math_obj::floor(cached_rect->y);
				this->mCachedBitmap = ::nme::display::BitmapData_obj::__new(w,h,true,0);
				this->RenderContentsToCache(this->mCachedBitmap,this->mCachedBitmapTx,this->mCachedBitmapTy);
				hx::SubEq(this->mCachedBitmapTx,this->mFullMatrix->tx);
				hx::SubEq(this->mCachedBitmapTy,this->mFullMatrix->ty);
				this->mFilteredBitmap = null();
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(DisplayObject_obj,CreateBitmapCache,(void))

::neash::display::InteractiveObject DisplayObject_obj::GetChildCachedObj( int inX,int inY,::neash::display::InteractiveObject inObj){
	return inObj;
}


HX_DEFINE_DYNAMIC_FUNC3(DisplayObject_obj,GetChildCachedObj,return )

::neash::display::InteractiveObject DisplayObject_obj::CacheGetObj( int inX,int inY,::neash::display::InteractiveObject inObj){
	__SAFE_POINT
	int tx = ::Std_obj::toInt((((this->mFullMatrix->tx + this->mCachedBitmapTx)) + 0.5));
	int ty = ::Std_obj::toInt((((this->mFullMatrix->ty + this->mCachedBitmapTy)) + 0.5));
	if ((bool((inX >= tx)) && bool((bool((inY >= ty)) && bool((bool((inX < (tx + this->mCachedBitmap->getWidth()))) && bool((inY < (ty + this->mCachedBitmap->getHeight()))))))))){
		::neash::display::InteractiveObject i = this->AsInteractiveObject();
		return this->GetChildCachedObj((inX - tx),(inY - ty),(i == null()) ? ::neash::display::InteractiveObject( inObj ) : ::neash::display::InteractiveObject( i ));
	}
	return null();
}


HX_DEFINE_DYNAMIC_FUNC3(DisplayObject_obj,CacheGetObj,return )

Void DisplayObject_obj::GetFocusObjects( Array< ::neash::display::InteractiveObject > outObjs){
{
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(DisplayObject_obj,GetFocusObjects,(void))

int DisplayObject_obj::__BlendIndex( ){
	__SAFE_POINT
	return (this->blendMode == null()) ? int( ::nme::display::Graphics_obj::BLEND_NORMAL ) : int( this->blendMode->__Index() );
}


HX_DEFINE_DYNAMIC_FUNC0(DisplayObject_obj,__BlendIndex,return )

Void DisplayObject_obj::RenderCache( Dynamic inMaskHandle){
{
		__SAFE_POINT
		int tx = ::Std_obj::toInt((((this->mFullMatrix->tx + this->mCachedBitmapTx)) + 0.5));
		int ty = ::Std_obj::toInt((((this->mFullMatrix->ty + this->mCachedBitmapTy)) + 0.5));
		::nme::display::Graphics gfx = ::nme::Manager_obj::graphics;
		if ((this->mFilterSet != null())){
			if ((this->mFilteredBitmap == null()))
				this->mFilteredBitmap = this->mFilterSet->FilterImage(this->mCachedBitmap);
			gfx->moveTo((tx + this->mFilterSet->GetOffsetX()),(ty + this->mFilterSet->GetOffsetY()));
			gfx->blit(this->mFilteredBitmap);
		}
		else{
			gfx->moveTo(tx,ty);
			gfx->blit(this->mCachedBitmap);
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(DisplayObject_obj,RenderCache,(void))

int DisplayObject_obj::mNameID;

int DisplayObject_obj::TRANSLATE_CHANGE;

int DisplayObject_obj::NON_TRANSLATE_CHANGE;

int DisplayObject_obj::GRAPHICS_CHANGE;


DisplayObject_obj::DisplayObject_obj()
{
}

void DisplayObject_obj::__Mark()
{
	hx::MarkMember(x);
	hx::MarkMember(y);
	hx::MarkMember(scaleX);
	hx::MarkMember(scaleY);
	hx::MarkMember(scale9Grid);
	hx::MarkMember(alpha);
	hx::MarkMember(name);
	hx::MarkMember(width);
	hx::MarkMember(height);
	hx::MarkMember(visible);
	hx::MarkMember(cacheAsBitmap);
	hx::MarkMember(opaqueBackground);
	hx::MarkMember(mouseX);
	hx::MarkMember(mouseY);
	hx::MarkMember(parent);
	hx::MarkMember(stage);
	hx::MarkMember(rotation);
	hx::MarkMember(scrollRect);
	hx::MarkMember(mask);
	hx::MarkMember(filters);
	hx::MarkMember(blendMode);
	hx::MarkMember(__swf_depth);
	hx::MarkMember(transform);
	hx::MarkMember(mX);
	hx::MarkMember(mY);
	hx::MarkMember(mSizeDirty);
	hx::MarkMember(mBoundsRect);
	hx::MarkMember(mGraphicsBounds);
	hx::MarkMember(mScale9Grid);
	hx::MarkMember(mBoundsDirty);
	hx::MarkMember(mScaleX);
	hx::MarkMember(mScaleY);
	hx::MarkMember(mTransformed);
	hx::MarkMember(mRotation);
	hx::MarkMember(mParent);
	hx::MarkMember(mScrollRect);
	hx::MarkMember(mOpaqueBackground);
	hx::MarkMember(mMask);
	hx::MarkMember(mMaskingObj);
	hx::MarkMember(mMaskHandle);
	hx::MarkMember(mFilters);
	hx::MarkMember(mFilterSet);
	hx::MarkMember(mCacheAsBitmap);
	hx::MarkMember(mCachedBitmap);
	hx::MarkMember(mFilteredBitmap);
	hx::MarkMember(mCachedBitmapTx);
	hx::MarkMember(mCachedBitmapTy);
	hx::MarkMember(mCachedBoundsRect);
	hx::MarkMember(mCCLeft);
	hx::MarkMember(mCCRight);
	hx::MarkMember(mCCTop);
	hx::MarkMember(mCCBottom);
	hx::MarkMember(mMatrix);
	hx::MarkMember(mFullMatrix);
	super::__Mark();
}

Dynamic DisplayObject_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 1:
		if (!memcmp(inName.__s,L"x",sizeof(wchar_t)*1) ) { return GetX(); }
		if (!memcmp(inName.__s,L"y",sizeof(wchar_t)*1) ) { return GetY(); }
		break;
	case 2:
		if (!memcmp(inName.__s,L"mX",sizeof(wchar_t)*2) ) { return mX; }
		if (!memcmp(inName.__s,L"mY",sizeof(wchar_t)*2) ) { return mY; }
		break;
	case 4:
		if (!memcmp(inName.__s,L"name",sizeof(wchar_t)*4) ) { return name; }
		if (!memcmp(inName.__s,L"mask",sizeof(wchar_t)*4) ) { return GetMask(); }
		if (!memcmp(inName.__s,L"GetX",sizeof(wchar_t)*4) ) { return GetX_dyn(); }
		if (!memcmp(inName.__s,L"GetY",sizeof(wchar_t)*4) ) { return GetY_dyn(); }
		if (!memcmp(inName.__s,L"SetX",sizeof(wchar_t)*4) ) { return SetX_dyn(); }
		if (!memcmp(inName.__s,L"SetY",sizeof(wchar_t)*4) ) { return SetY_dyn(); }
		break;
	case 5:
		if (!memcmp(inName.__s,L"alpha",sizeof(wchar_t)*5) ) { return alpha; }
		if (!memcmp(inName.__s,L"width",sizeof(wchar_t)*5) ) { return GetWidth(); }
		if (!memcmp(inName.__s,L"stage",sizeof(wchar_t)*5) ) { return GetStage(); }
		if (!memcmp(inName.__s,L"mMask",sizeof(wchar_t)*5) ) { return mMask; }
		break;
	case 6:
		if (!memcmp(inName.__s,L"scaleX",sizeof(wchar_t)*6) ) { return GetScaleX(); }
		if (!memcmp(inName.__s,L"scaleY",sizeof(wchar_t)*6) ) { return GetScaleY(); }
		if (!memcmp(inName.__s,L"height",sizeof(wchar_t)*6) ) { return GetHeight(); }
		if (!memcmp(inName.__s,L"mouseX",sizeof(wchar_t)*6) ) { return GetMouseX(); }
		if (!memcmp(inName.__s,L"mouseY",sizeof(wchar_t)*6) ) { return GetMouseY(); }
		if (!memcmp(inName.__s,L"parent",sizeof(wchar_t)*6) ) { return GetParent(); }
		if (!memcmp(inName.__s,L"mCCTop",sizeof(wchar_t)*6) ) { return mCCTop; }
		if (!memcmp(inName.__s,L"GetObj",sizeof(wchar_t)*6) ) { return GetObj_dyn(); }
		break;
	case 7:
		if (!memcmp(inName.__s,L"mNameID",sizeof(wchar_t)*7) ) { return mNameID; }
		if (!memcmp(inName.__s,L"visible",sizeof(wchar_t)*7) ) { return visible; }
		if (!memcmp(inName.__s,L"filters",sizeof(wchar_t)*7) ) { return GetFilters(); }
		if (!memcmp(inName.__s,L"mScaleX",sizeof(wchar_t)*7) ) { return mScaleX; }
		if (!memcmp(inName.__s,L"mScaleY",sizeof(wchar_t)*7) ) { return mScaleY; }
		if (!memcmp(inName.__s,L"mParent",sizeof(wchar_t)*7) ) { return mParent; }
		if (!memcmp(inName.__s,L"mCCLeft",sizeof(wchar_t)*7) ) { return mCCLeft; }
		if (!memcmp(inName.__s,L"mMatrix",sizeof(wchar_t)*7) ) { return mMatrix; }
		if (!memcmp(inName.__s,L"DoAdded",sizeof(wchar_t)*7) ) { return DoAdded_dyn(); }
		if (!memcmp(inName.__s,L"getRect",sizeof(wchar_t)*7) ) { return getRect_dyn(); }
		if (!memcmp(inName.__s,L"GetMask",sizeof(wchar_t)*7) ) { return GetMask_dyn(); }
		if (!memcmp(inName.__s,L"SetMask",sizeof(wchar_t)*7) ) { return SetMask_dyn(); }
		break;
	case 8:
		if (!memcmp(inName.__s,L"rotation",sizeof(wchar_t)*8) ) { return GetRotation(); }
		if (!memcmp(inName.__s,L"mFilters",sizeof(wchar_t)*8) ) { return mFilters; }
		if (!memcmp(inName.__s,L"mCCRight",sizeof(wchar_t)*8) ) { return mCCRight; }
		if (!memcmp(inName.__s,L"toString",sizeof(wchar_t)*8) ) { return toString_dyn(); }
		if (!memcmp(inName.__s,L"GetStage",sizeof(wchar_t)*8) ) { return GetStage_dyn(); }
		if (!memcmp(inName.__s,L"GetWidth",sizeof(wchar_t)*8) ) { return GetWidth_dyn(); }
		if (!memcmp(inName.__s,L"SetWidth",sizeof(wchar_t)*8) ) { return SetWidth_dyn(); }
		if (!memcmp(inName.__s,L"__Render",sizeof(wchar_t)*8) ) { return __Render_dyn(); }
		break;
	case 9:
		if (!memcmp(inName.__s,L"blendMode",sizeof(wchar_t)*9) ) { return blendMode; }
		if (!memcmp(inName.__s,L"transform",sizeof(wchar_t)*9) ) { return GetTransform(); }
		if (!memcmp(inName.__s,L"mRotation",sizeof(wchar_t)*9) ) { return mRotation; }
		if (!memcmp(inName.__s,L"mCCBottom",sizeof(wchar_t)*9) ) { return mCCBottom; }
		if (!memcmp(inName.__s,L"DoRemoved",sizeof(wchar_t)*9) ) { return DoRemoved_dyn(); }
		if (!memcmp(inName.__s,L"SetParent",sizeof(wchar_t)*9) ) { return SetParent_dyn(); }
		if (!memcmp(inName.__s,L"GetParent",sizeof(wchar_t)*9) ) { return GetParent_dyn(); }
		if (!memcmp(inName.__s,L"GetScaleX",sizeof(wchar_t)*9) ) { return GetScaleX_dyn(); }
		if (!memcmp(inName.__s,L"GetScaleY",sizeof(wchar_t)*9) ) { return GetScaleY_dyn(); }
		if (!memcmp(inName.__s,L"SetScaleX",sizeof(wchar_t)*9) ) { return SetScaleX_dyn(); }
		if (!memcmp(inName.__s,L"SetScaleY",sizeof(wchar_t)*9) ) { return SetScaleY_dyn(); }
		if (!memcmp(inName.__s,L"GetMouseX",sizeof(wchar_t)*9) ) { return GetMouseX_dyn(); }
		if (!memcmp(inName.__s,L"GetMouseY",sizeof(wchar_t)*9) ) { return GetMouseY_dyn(); }
		if (!memcmp(inName.__s,L"getBounds",sizeof(wchar_t)*9) ) { return getBounds_dyn(); }
		if (!memcmp(inName.__s,L"GetMatrix",sizeof(wchar_t)*9) ) { return GetMatrix_dyn(); }
		if (!memcmp(inName.__s,L"SetMatrix",sizeof(wchar_t)*9) ) { return SetMatrix_dyn(); }
		if (!memcmp(inName.__s,L"GetHeight",sizeof(wchar_t)*9) ) { return GetHeight_dyn(); }
		if (!memcmp(inName.__s,L"SetHeight",sizeof(wchar_t)*9) ) { return SetHeight_dyn(); }
		break;
	case 10:
		if (!memcmp(inName.__s,L"scale9Grid",sizeof(wchar_t)*10) ) { return GetScale9Grid(); }
		if (!memcmp(inName.__s,L"scrollRect",sizeof(wchar_t)*10) ) { return GetScrollRect(); }
		if (!memcmp(inName.__s,L"mSizeDirty",sizeof(wchar_t)*10) ) { return mSizeDirty; }
		if (!memcmp(inName.__s,L"mFilterSet",sizeof(wchar_t)*10) ) { return mFilterSet; }
		if (!memcmp(inName.__s,L"AppendMask",sizeof(wchar_t)*10) ) { return AppendMask_dyn(); }
		if (!memcmp(inName.__s,L"SetFilters",sizeof(wchar_t)*10) ) { return SetFilters_dyn(); }
		if (!memcmp(inName.__s,L"GetFilters",sizeof(wchar_t)*10) ) { return GetFilters_dyn(); }
		if (!memcmp(inName.__s,L"ClearCache",sizeof(wchar_t)*10) ) { return ClearCache_dyn(); }
		break;
	case 11:
		if (!memcmp(inName.__s,L"__swf_depth",sizeof(wchar_t)*11) ) { return __swf_depth; }
		if (!memcmp(inName.__s,L"mBoundsRect",sizeof(wchar_t)*11) ) { return mBoundsRect; }
		if (!memcmp(inName.__s,L"mScale9Grid",sizeof(wchar_t)*11) ) { return mScale9Grid; }
		if (!memcmp(inName.__s,L"mScrollRect",sizeof(wchar_t)*11) ) { return mScrollRect; }
		if (!memcmp(inName.__s,L"mMaskingObj",sizeof(wchar_t)*11) ) { return mMaskingObj; }
		if (!memcmp(inName.__s,L"mMaskHandle",sizeof(wchar_t)*11) ) { return mMaskHandle; }
		if (!memcmp(inName.__s,L"mFullMatrix",sizeof(wchar_t)*11) ) { return mFullMatrix; }
		if (!memcmp(inName.__s,L"AsContainer",sizeof(wchar_t)*11) ) { return AsContainer_dyn(); }
		if (!memcmp(inName.__s,L"SetRotation",sizeof(wchar_t)*11) ) { return SetRotation_dyn(); }
		if (!memcmp(inName.__s,L"GetRotation",sizeof(wchar_t)*11) ) { return GetRotation_dyn(); }
		if (!memcmp(inName.__s,L"GetGraphics",sizeof(wchar_t)*11) ) { return GetGraphics_dyn(); }
		if (!memcmp(inName.__s,L"SetupRender",sizeof(wchar_t)*11) ) { return SetupRender_dyn(); }
		if (!memcmp(inName.__s,L"__RenderGfx",sizeof(wchar_t)*11) ) { return __RenderGfx_dyn(); }
		if (!memcmp(inName.__s,L"BuildBounds",sizeof(wchar_t)*11) ) { return BuildBounds_dyn(); }
		if (!memcmp(inName.__s,L"CacheGetObj",sizeof(wchar_t)*11) ) { return CacheGetObj_dyn(); }
		if (!memcmp(inName.__s,L"RenderCache",sizeof(wchar_t)*11) ) { return RenderCache_dyn(); }
		break;
	case 12:
		if (!memcmp(inName.__s,L"mBoundsDirty",sizeof(wchar_t)*12) ) { return mBoundsDirty; }
		if (!memcmp(inName.__s,L"mTransformed",sizeof(wchar_t)*12) ) { return mTransformed; }
		if (!memcmp(inName.__s,L"DoMouseEnter",sizeof(wchar_t)*12) ) { return DoMouseEnter_dyn(); }
		if (!memcmp(inName.__s,L"DoMouseLeave",sizeof(wchar_t)*12) ) { return DoMouseLeave_dyn(); }
		if (!memcmp(inName.__s,L"hitTestPoint",sizeof(wchar_t)*12) ) { return hitTestPoint_dyn(); }
		if (!memcmp(inName.__s,L"GetTransform",sizeof(wchar_t)*12) ) { return GetTransform_dyn(); }
		if (!memcmp(inName.__s,L"SetTransform",sizeof(wchar_t)*12) ) { return SetTransform_dyn(); }
		if (!memcmp(inName.__s,L"UpdateMatrix",sizeof(wchar_t)*12) ) { return UpdateMatrix_dyn(); }
		if (!memcmp(inName.__s,L"__BlendIndex",sizeof(wchar_t)*12) ) { return __BlendIndex_dyn(); }
		break;
	case 13:
		if (!memcmp(inName.__s,L"cacheAsBitmap",sizeof(wchar_t)*13) ) { return GetCacheAsBitmap(); }
		if (!memcmp(inName.__s,L"mCachedBitmap",sizeof(wchar_t)*13) ) { return mCachedBitmap; }
		if (!memcmp(inName.__s,L"GetScale9Grid",sizeof(wchar_t)*13) ) { return GetScale9Grid_dyn(); }
		if (!memcmp(inName.__s,L"SetScale9Grid",sizeof(wchar_t)*13) ) { return SetScale9Grid_dyn(); }
		if (!memcmp(inName.__s,L"GetScrollRect",sizeof(wchar_t)*13) ) { return GetScrollRect_dyn(); }
		if (!memcmp(inName.__s,L"SetScrollRect",sizeof(wchar_t)*13) ) { return SetScrollRect_dyn(); }
		if (!memcmp(inName.__s,L"globalToLocal",sizeof(wchar_t)*13) ) { return globalToLocal_dyn(); }
		if (!memcmp(inName.__s,L"drawToSurface",sizeof(wchar_t)*13) ) { return drawToSurface_dyn(); }
		if (!memcmp(inName.__s,L"GetMaskHandle",sizeof(wchar_t)*13) ) { return GetMaskHandle_dyn(); }
		break;
	case 14:
		if (!memcmp(inName.__s,L"mCacheAsBitmap",sizeof(wchar_t)*14) ) { return mCacheAsBitmap; }
		if (!memcmp(inName.__s,L"GetNumChildren",sizeof(wchar_t)*14) ) { return GetNumChildren_dyn(); }
		break;
	case 15:
		if (!memcmp(inName.__s,L"GRAPHICS_CHANGE",sizeof(wchar_t)*15) ) { return GRAPHICS_CHANGE; }
		if (!memcmp(inName.__s,L"mGraphicsBounds",sizeof(wchar_t)*15) ) { return mGraphicsBounds; }
		if (!memcmp(inName.__s,L"mFilteredBitmap",sizeof(wchar_t)*15) ) { return mFilteredBitmap; }
		if (!memcmp(inName.__s,L"mCachedBitmapTx",sizeof(wchar_t)*15) ) { return mCachedBitmapTx; }
		if (!memcmp(inName.__s,L"mCachedBitmapTy",sizeof(wchar_t)*15) ) { return mCachedBitmapTy; }
		if (!memcmp(inName.__s,L"GetScreenBounds",sizeof(wchar_t)*15) ) { return GetScreenBounds_dyn(); }
		if (!memcmp(inName.__s,L"GetFocusObjects",sizeof(wchar_t)*15) ) { return GetFocusObjects_dyn(); }
		break;
	case 16:
		if (!memcmp(inName.__s,L"TRANSLATE_CHANGE",sizeof(wchar_t)*16) ) { return TRANSLATE_CHANGE; }
		if (!memcmp(inName.__s,L"opaqueBackground",sizeof(wchar_t)*16) ) { return GetOpaqueBackground(); }
		if (!memcmp(inName.__s,L"GetCacheAsBitmap",sizeof(wchar_t)*16) ) { return GetCacheAsBitmap_dyn(); }
		if (!memcmp(inName.__s,L"SetCacheAsBitmap",sizeof(wchar_t)*16) ) { return SetCacheAsBitmap_dyn(); }
		break;
	case 17:
		if (!memcmp(inName.__s,L"mOpaqueBackground",sizeof(wchar_t)*17) ) { return mOpaqueBackground; }
		if (!memcmp(inName.__s,L"mCachedBoundsRect",sizeof(wchar_t)*17) ) { return mCachedBoundsRect; }
		if (!memcmp(inName.__s,L"GetBitmapDrawable",sizeof(wchar_t)*17) ) { return GetBitmapDrawable_dyn(); }
		if (!memcmp(inName.__s,L"GetBackgroundRect",sizeof(wchar_t)*17) ) { return GetBackgroundRect_dyn(); }
		if (!memcmp(inName.__s,L"CreateBitmapCache",sizeof(wchar_t)*17) ) { return CreateBitmapCache_dyn(); }
		if (!memcmp(inName.__s,L"GetChildCachedObj",sizeof(wchar_t)*17) ) { return GetChildCachedObj_dyn(); }
		break;
	case 19:
		if (!memcmp(inName.__s,L"AsInteractiveObject",sizeof(wchar_t)*19) ) { return AsInteractiveObject_dyn(); }
		if (!memcmp(inName.__s,L"GetOpaqueBackground",sizeof(wchar_t)*19) ) { return GetOpaqueBackground_dyn(); }
		if (!memcmp(inName.__s,L"SetOpaqueBackground",sizeof(wchar_t)*19) ) { return SetOpaqueBackground_dyn(); }
		break;
	case 20:
		if (!memcmp(inName.__s,L"NON_TRANSLATE_CHANGE",sizeof(wchar_t)*20) ) { return NON_TRANSLATE_CHANGE; }
		break;
	case 21:
		if (!memcmp(inName.__s,L"RenderContentsToCache",sizeof(wchar_t)*21) ) { return RenderContentsToCache_dyn(); }
	}
	return super::__Field(inName);
}

Dynamic DisplayObject_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	switch(inName.length) {
	case 1:
		if (!memcmp(inName.__s,L"x",sizeof(wchar_t)*1) ) { return SetX(inValue); }
		if (!memcmp(inName.__s,L"y",sizeof(wchar_t)*1) ) { return SetY(inValue); }
		break;
	case 2:
		if (!memcmp(inName.__s,L"mX",sizeof(wchar_t)*2) ) { mX=inValue.Cast< double >(); return inValue; }
		if (!memcmp(inName.__s,L"mY",sizeof(wchar_t)*2) ) { mY=inValue.Cast< double >(); return inValue; }
		break;
	case 4:
		if (!memcmp(inName.__s,L"name",sizeof(wchar_t)*4) ) { name=inValue.Cast< ::String >(); return inValue; }
		if (!memcmp(inName.__s,L"mask",sizeof(wchar_t)*4) ) { return SetMask(inValue); }
		break;
	case 5:
		if (!memcmp(inName.__s,L"alpha",sizeof(wchar_t)*5) ) { alpha=inValue.Cast< double >(); return inValue; }
		if (!memcmp(inName.__s,L"width",sizeof(wchar_t)*5) ) { return SetWidth(inValue); }
		if (!memcmp(inName.__s,L"stage",sizeof(wchar_t)*5) ) { stage=inValue.Cast< ::neash::display::Stage >(); return inValue; }
		if (!memcmp(inName.__s,L"mMask",sizeof(wchar_t)*5) ) { mMask=inValue.Cast< ::neash::display::DisplayObject >(); return inValue; }
		break;
	case 6:
		if (!memcmp(inName.__s,L"scaleX",sizeof(wchar_t)*6) ) { return SetScaleX(inValue); }
		if (!memcmp(inName.__s,L"scaleY",sizeof(wchar_t)*6) ) { return SetScaleY(inValue); }
		if (!memcmp(inName.__s,L"height",sizeof(wchar_t)*6) ) { return SetHeight(inValue); }
		if (!memcmp(inName.__s,L"mouseX",sizeof(wchar_t)*6) ) { mouseX=inValue.Cast< double >(); return inValue; }
		if (!memcmp(inName.__s,L"mouseY",sizeof(wchar_t)*6) ) { mouseY=inValue.Cast< double >(); return inValue; }
		if (!memcmp(inName.__s,L"parent",sizeof(wchar_t)*6) ) { parent=inValue.Cast< ::neash::display::DisplayObjectContainer >(); return inValue; }
		if (!memcmp(inName.__s,L"mCCTop",sizeof(wchar_t)*6) ) { mCCTop=inValue.Cast< bool >(); return inValue; }
		break;
	case 7:
		if (!memcmp(inName.__s,L"mNameID",sizeof(wchar_t)*7) ) { mNameID=inValue.Cast< int >(); return inValue; }
		if (!memcmp(inName.__s,L"visible",sizeof(wchar_t)*7) ) { visible=inValue.Cast< bool >(); return inValue; }
		if (!memcmp(inName.__s,L"filters",sizeof(wchar_t)*7) ) { return SetFilters(inValue); }
		if (!memcmp(inName.__s,L"mScaleX",sizeof(wchar_t)*7) ) { mScaleX=inValue.Cast< double >(); return inValue; }
		if (!memcmp(inName.__s,L"mScaleY",sizeof(wchar_t)*7) ) { mScaleY=inValue.Cast< double >(); return inValue; }
		if (!memcmp(inName.__s,L"mParent",sizeof(wchar_t)*7) ) { mParent=inValue.Cast< ::neash::display::DisplayObjectContainer >(); return inValue; }
		if (!memcmp(inName.__s,L"mCCLeft",sizeof(wchar_t)*7) ) { mCCLeft=inValue.Cast< bool >(); return inValue; }
		if (!memcmp(inName.__s,L"mMatrix",sizeof(wchar_t)*7) ) { mMatrix=inValue.Cast< ::nme::geom::Matrix >(); return inValue; }
		break;
	case 8:
		if (!memcmp(inName.__s,L"rotation",sizeof(wchar_t)*8) ) { return SetRotation(inValue); }
		if (!memcmp(inName.__s,L"mFilters",sizeof(wchar_t)*8) ) { mFilters=inValue.Cast< Array< Dynamic > >(); return inValue; }
		if (!memcmp(inName.__s,L"mCCRight",sizeof(wchar_t)*8) ) { mCCRight=inValue.Cast< bool >(); return inValue; }
		break;
	case 9:
		if (!memcmp(inName.__s,L"blendMode",sizeof(wchar_t)*9) ) { blendMode=inValue.Cast< ::neash::display::BlendMode >(); return inValue; }
		if (!memcmp(inName.__s,L"transform",sizeof(wchar_t)*9) ) { return SetTransform(inValue); }
		if (!memcmp(inName.__s,L"mRotation",sizeof(wchar_t)*9) ) { mRotation=inValue.Cast< double >(); return inValue; }
		if (!memcmp(inName.__s,L"mCCBottom",sizeof(wchar_t)*9) ) { mCCBottom=inValue.Cast< bool >(); return inValue; }
		break;
	case 10:
		if (!memcmp(inName.__s,L"scale9Grid",sizeof(wchar_t)*10) ) { return SetScale9Grid(inValue); }
		if (!memcmp(inName.__s,L"scrollRect",sizeof(wchar_t)*10) ) { return SetScrollRect(inValue); }
		if (!memcmp(inName.__s,L"mSizeDirty",sizeof(wchar_t)*10) ) { mSizeDirty=inValue.Cast< bool >(); return inValue; }
		if (!memcmp(inName.__s,L"mFilterSet",sizeof(wchar_t)*10) ) { mFilterSet=inValue.Cast< ::nme::filters::BitmapFilterSet >(); return inValue; }
		break;
	case 11:
		if (!memcmp(inName.__s,L"__swf_depth",sizeof(wchar_t)*11) ) { __swf_depth=inValue.Cast< int >(); return inValue; }
		if (!memcmp(inName.__s,L"mBoundsRect",sizeof(wchar_t)*11) ) { mBoundsRect=inValue.Cast< ::nme::geom::Rectangle >(); return inValue; }
		if (!memcmp(inName.__s,L"mScale9Grid",sizeof(wchar_t)*11) ) { mScale9Grid=inValue.Cast< ::nme::geom::Rectangle >(); return inValue; }
		if (!memcmp(inName.__s,L"mScrollRect",sizeof(wchar_t)*11) ) { mScrollRect=inValue.Cast< ::nme::geom::Rectangle >(); return inValue; }
		if (!memcmp(inName.__s,L"mMaskingObj",sizeof(wchar_t)*11) ) { mMaskingObj=inValue.Cast< ::neash::display::DisplayObject >(); return inValue; }
		if (!memcmp(inName.__s,L"mMaskHandle",sizeof(wchar_t)*11) ) { mMaskHandle=inValue.Cast< Dynamic >(); return inValue; }
		if (!memcmp(inName.__s,L"mFullMatrix",sizeof(wchar_t)*11) ) { mFullMatrix=inValue.Cast< ::nme::geom::Matrix >(); return inValue; }
		break;
	case 12:
		if (!memcmp(inName.__s,L"mBoundsDirty",sizeof(wchar_t)*12) ) { mBoundsDirty=inValue.Cast< bool >(); return inValue; }
		if (!memcmp(inName.__s,L"mTransformed",sizeof(wchar_t)*12) ) { mTransformed=inValue.Cast< bool >(); return inValue; }
		break;
	case 13:
		if (!memcmp(inName.__s,L"cacheAsBitmap",sizeof(wchar_t)*13) ) { return SetCacheAsBitmap(inValue); }
		if (!memcmp(inName.__s,L"mCachedBitmap",sizeof(wchar_t)*13) ) { mCachedBitmap=inValue.Cast< ::nme::display::BitmapData >(); return inValue; }
		break;
	case 14:
		if (!memcmp(inName.__s,L"mCacheAsBitmap",sizeof(wchar_t)*14) ) { mCacheAsBitmap=inValue.Cast< bool >(); return inValue; }
		break;
	case 15:
		if (!memcmp(inName.__s,L"GRAPHICS_CHANGE",sizeof(wchar_t)*15) ) { GRAPHICS_CHANGE=inValue.Cast< int >(); return inValue; }
		if (!memcmp(inName.__s,L"mGraphicsBounds",sizeof(wchar_t)*15) ) { mGraphicsBounds=inValue.Cast< ::nme::geom::Rectangle >(); return inValue; }
		if (!memcmp(inName.__s,L"mFilteredBitmap",sizeof(wchar_t)*15) ) { mFilteredBitmap=inValue.Cast< ::nme::display::BitmapData >(); return inValue; }
		if (!memcmp(inName.__s,L"mCachedBitmapTx",sizeof(wchar_t)*15) ) { mCachedBitmapTx=inValue.Cast< double >(); return inValue; }
		if (!memcmp(inName.__s,L"mCachedBitmapTy",sizeof(wchar_t)*15) ) { mCachedBitmapTy=inValue.Cast< double >(); return inValue; }
		break;
	case 16:
		if (!memcmp(inName.__s,L"TRANSLATE_CHANGE",sizeof(wchar_t)*16) ) { TRANSLATE_CHANGE=inValue.Cast< int >(); return inValue; }
		if (!memcmp(inName.__s,L"opaqueBackground",sizeof(wchar_t)*16) ) { return SetOpaqueBackground(inValue); }
		break;
	case 17:
		if (!memcmp(inName.__s,L"mOpaqueBackground",sizeof(wchar_t)*17) ) { mOpaqueBackground=inValue.Cast< Dynamic >(); return inValue; }
		if (!memcmp(inName.__s,L"mCachedBoundsRect",sizeof(wchar_t)*17) ) { mCachedBoundsRect=inValue.Cast< ::nme::geom::Rectangle >(); return inValue; }
		break;
	case 20:
		if (!memcmp(inName.__s,L"NON_TRANSLATE_CHANGE",sizeof(wchar_t)*20) ) { NON_TRANSLATE_CHANGE=inValue.Cast< int >(); return inValue; }
	}
	return super::__SetField(inName,inValue);
}

void DisplayObject_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_STRING(L"x",1));
	outFields->push(HX_STRING(L"y",1));
	outFields->push(HX_STRING(L"scaleX",6));
	outFields->push(HX_STRING(L"scaleY",6));
	outFields->push(HX_STRING(L"scale9Grid",10));
	outFields->push(HX_STRING(L"alpha",5));
	outFields->push(HX_STRING(L"name",4));
	outFields->push(HX_STRING(L"width",5));
	outFields->push(HX_STRING(L"height",6));
	outFields->push(HX_STRING(L"visible",7));
	outFields->push(HX_STRING(L"cacheAsBitmap",13));
	outFields->push(HX_STRING(L"opaqueBackground",16));
	outFields->push(HX_STRING(L"mouseX",6));
	outFields->push(HX_STRING(L"mouseY",6));
	outFields->push(HX_STRING(L"parent",6));
	outFields->push(HX_STRING(L"stage",5));
	outFields->push(HX_STRING(L"rotation",8));
	outFields->push(HX_STRING(L"scrollRect",10));
	outFields->push(HX_STRING(L"mask",4));
	outFields->push(HX_STRING(L"filters",7));
	outFields->push(HX_STRING(L"blendMode",9));
	outFields->push(HX_STRING(L"__swf_depth",11));
	outFields->push(HX_STRING(L"transform",9));
	outFields->push(HX_STRING(L"mX",2));
	outFields->push(HX_STRING(L"mY",2));
	outFields->push(HX_STRING(L"mSizeDirty",10));
	outFields->push(HX_STRING(L"mBoundsRect",11));
	outFields->push(HX_STRING(L"mGraphicsBounds",15));
	outFields->push(HX_STRING(L"mScale9Grid",11));
	outFields->push(HX_STRING(L"mBoundsDirty",12));
	outFields->push(HX_STRING(L"mScaleX",7));
	outFields->push(HX_STRING(L"mScaleY",7));
	outFields->push(HX_STRING(L"mTransformed",12));
	outFields->push(HX_STRING(L"mRotation",9));
	outFields->push(HX_STRING(L"mParent",7));
	outFields->push(HX_STRING(L"mScrollRect",11));
	outFields->push(HX_STRING(L"mOpaqueBackground",17));
	outFields->push(HX_STRING(L"mMask",5));
	outFields->push(HX_STRING(L"mMaskingObj",11));
	outFields->push(HX_STRING(L"mMaskHandle",11));
	outFields->push(HX_STRING(L"mFilters",8));
	outFields->push(HX_STRING(L"mFilterSet",10));
	outFields->push(HX_STRING(L"mCacheAsBitmap",14));
	outFields->push(HX_STRING(L"mCachedBitmap",13));
	outFields->push(HX_STRING(L"mFilteredBitmap",15));
	outFields->push(HX_STRING(L"mCachedBitmapTx",15));
	outFields->push(HX_STRING(L"mCachedBitmapTy",15));
	outFields->push(HX_STRING(L"mCachedBoundsRect",17));
	outFields->push(HX_STRING(L"mCCLeft",7));
	outFields->push(HX_STRING(L"mCCRight",8));
	outFields->push(HX_STRING(L"mCCTop",6));
	outFields->push(HX_STRING(L"mCCBottom",9));
	outFields->push(HX_STRING(L"mMatrix",7));
	outFields->push(HX_STRING(L"mFullMatrix",11));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_STRING(L"mNameID",7),
	HX_STRING(L"TRANSLATE_CHANGE",16),
	HX_STRING(L"NON_TRANSLATE_CHANGE",20),
	HX_STRING(L"GRAPHICS_CHANGE",15),
	String(null()) };

static ::String sMemberFields[] = {
	HX_STRING(L"x",1),
	HX_STRING(L"y",1),
	HX_STRING(L"scaleX",6),
	HX_STRING(L"scaleY",6),
	HX_STRING(L"scale9Grid",10),
	HX_STRING(L"alpha",5),
	HX_STRING(L"name",4),
	HX_STRING(L"width",5),
	HX_STRING(L"height",6),
	HX_STRING(L"visible",7),
	HX_STRING(L"cacheAsBitmap",13),
	HX_STRING(L"opaqueBackground",16),
	HX_STRING(L"mouseX",6),
	HX_STRING(L"mouseY",6),
	HX_STRING(L"parent",6),
	HX_STRING(L"stage",5),
	HX_STRING(L"rotation",8),
	HX_STRING(L"scrollRect",10),
	HX_STRING(L"mask",4),
	HX_STRING(L"filters",7),
	HX_STRING(L"blendMode",9),
	HX_STRING(L"__swf_depth",11),
	HX_STRING(L"transform",9),
	HX_STRING(L"mX",2),
	HX_STRING(L"mY",2),
	HX_STRING(L"mSizeDirty",10),
	HX_STRING(L"mBoundsRect",11),
	HX_STRING(L"mGraphicsBounds",15),
	HX_STRING(L"mScale9Grid",11),
	HX_STRING(L"mBoundsDirty",12),
	HX_STRING(L"mScaleX",7),
	HX_STRING(L"mScaleY",7),
	HX_STRING(L"mTransformed",12),
	HX_STRING(L"mRotation",9),
	HX_STRING(L"mParent",7),
	HX_STRING(L"mScrollRect",11),
	HX_STRING(L"mOpaqueBackground",17),
	HX_STRING(L"mMask",5),
	HX_STRING(L"mMaskingObj",11),
	HX_STRING(L"mMaskHandle",11),
	HX_STRING(L"mFilters",8),
	HX_STRING(L"mFilterSet",10),
	HX_STRING(L"mCacheAsBitmap",14),
	HX_STRING(L"mCachedBitmap",13),
	HX_STRING(L"mFilteredBitmap",15),
	HX_STRING(L"mCachedBitmapTx",15),
	HX_STRING(L"mCachedBitmapTy",15),
	HX_STRING(L"mCachedBoundsRect",17),
	HX_STRING(L"mCCLeft",7),
	HX_STRING(L"mCCRight",8),
	HX_STRING(L"mCCTop",6),
	HX_STRING(L"mCCBottom",9),
	HX_STRING(L"mMatrix",7),
	HX_STRING(L"mFullMatrix",11),
	HX_STRING(L"GetBitmapDrawable",17),
	HX_STRING(L"toString",8),
	HX_STRING(L"DoAdded",7),
	HX_STRING(L"DoRemoved",9),
	HX_STRING(L"DoMouseEnter",12),
	HX_STRING(L"DoMouseLeave",12),
	HX_STRING(L"SetParent",9),
	HX_STRING(L"GetX",4),
	HX_STRING(L"GetParent",9),
	HX_STRING(L"GetY",4),
	HX_STRING(L"SetX",4),
	HX_STRING(L"SetY",4),
	HX_STRING(L"GetStage",8),
	HX_STRING(L"AsContainer",11),
	HX_STRING(L"GetScaleX",9),
	HX_STRING(L"GetScaleY",9),
	HX_STRING(L"SetScaleX",9),
	HX_STRING(L"SetScaleY",9),
	HX_STRING(L"GetScale9Grid",13),
	HX_STRING(L"SetScale9Grid",13),
	HX_STRING(L"SetRotation",11),
	HX_STRING(L"GetRotation",11),
	HX_STRING(L"GetScrollRect",13),
	HX_STRING(L"AsInteractiveObject",19),
	HX_STRING(L"SetScrollRect",13),
	HX_STRING(L"hitTestPoint",12),
	HX_STRING(L"GetMouseX",9),
	HX_STRING(L"GetMouseY",9),
	HX_STRING(L"GetTransform",12),
	HX_STRING(L"SetTransform",12),
	HX_STRING(L"getBounds",9),
	HX_STRING(L"getRect",7),
	HX_STRING(L"globalToLocal",13),
	HX_STRING(L"GetNumChildren",14),
	HX_STRING(L"GetMatrix",9),
	HX_STRING(L"SetMatrix",9),
	HX_STRING(L"UpdateMatrix",12),
	HX_STRING(L"GetGraphics",11),
	HX_STRING(L"SetupRender",11),
	HX_STRING(L"GetHeight",9),
	HX_STRING(L"SetHeight",9),
	HX_STRING(L"GetWidth",8),
	HX_STRING(L"SetWidth",8),
	HX_STRING(L"GetOpaqueBackground",19),
	HX_STRING(L"SetOpaqueBackground",19),
	HX_STRING(L"GetBackgroundRect",17),
	HX_STRING(L"__RenderGfx",11),
	HX_STRING(L"__Render",8),
	HX_STRING(L"drawToSurface",13),
	HX_STRING(L"GetObj",6),
	HX_STRING(L"GetMask",7),
	HX_STRING(L"SetMask",7),
	HX_STRING(L"AppendMask",10),
	HX_STRING(L"GetMaskHandle",13),
	HX_STRING(L"SetFilters",10),
	HX_STRING(L"GetFilters",10),
	HX_STRING(L"GetCacheAsBitmap",16),
	HX_STRING(L"SetCacheAsBitmap",16),
	HX_STRING(L"ClearCache",10),
	HX_STRING(L"BuildBounds",11),
	HX_STRING(L"GetScreenBounds",15),
	HX_STRING(L"RenderContentsToCache",21),
	HX_STRING(L"CreateBitmapCache",17),
	HX_STRING(L"GetChildCachedObj",17),
	HX_STRING(L"CacheGetObj",11),
	HX_STRING(L"GetFocusObjects",15),
	HX_STRING(L"__BlendIndex",12),
	HX_STRING(L"RenderCache",11),
	String(null()) };

static void sMarkStatics() {
	hx::MarkMember(DisplayObject_obj::mNameID);
	hx::MarkMember(DisplayObject_obj::TRANSLATE_CHANGE);
	hx::MarkMember(DisplayObject_obj::NON_TRANSLATE_CHANGE);
	hx::MarkMember(DisplayObject_obj::GRAPHICS_CHANGE);
};

Class DisplayObject_obj::__mClass;

void DisplayObject_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_STRING(L"neash.display.DisplayObject",27), hx::TCanCast< DisplayObject_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void DisplayObject_obj::__boot()
{
	hx::Static(mNameID) = 0;
	hx::Static(TRANSLATE_CHANGE) = 1;
	hx::Static(NON_TRANSLATE_CHANGE) = 2;
	hx::Static(GRAPHICS_CHANGE) = 4;
}

} // end namespace neash
} // end namespace display
