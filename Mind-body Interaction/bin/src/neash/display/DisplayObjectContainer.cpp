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
#ifndef INCLUDED_neash_events_Event
#include <neash/events/Event.h>
#endif
#ifndef INCLUDED_neash_events_EventDispatcher
#include <neash/events/EventDispatcher.h>
#endif
#ifndef INCLUDED_neash_events_IEventDispatcher
#include <neash/events/IEventDispatcher.h>
#endif
#ifndef INCLUDED_nme_display_BitmapData
#include <nme/display/BitmapData.h>
#endif
#ifndef INCLUDED_nme_display_IBitmapDrawable
#include <nme/display/IBitmapDrawable.h>
#endif
#ifndef INCLUDED_nme_geom_Matrix
#include <nme/geom/Matrix.h>
#endif
#ifndef INCLUDED_nme_geom_Rectangle
#include <nme/geom/Rectangle.h>
#endif
namespace neash{
namespace display{

Void DisplayObjectContainer_obj::__construct()
{
{
	this->mObjs = Array_obj< ::neash::display::DisplayObject >::__new();
	this->mLastSetupObjs = Array_obj< ::neash::display::DisplayObject >::__new();
	this->mouseChildren = true;
	super::__construct();
	this->name = (HX_STRING(L"DisplayObjectContainer ",23) + ::neash::display::DisplayObject_obj::mNameID++);
}
;
	return null();
}

DisplayObjectContainer_obj::~DisplayObjectContainer_obj() { }

Dynamic DisplayObjectContainer_obj::__CreateEmpty() { return  new DisplayObjectContainer_obj; }
hx::ObjectPtr< DisplayObjectContainer_obj > DisplayObjectContainer_obj::__new()
{  hx::ObjectPtr< DisplayObjectContainer_obj > result = new DisplayObjectContainer_obj();
	result->__construct();
	return result;}

Dynamic DisplayObjectContainer_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< DisplayObjectContainer_obj > result = new DisplayObjectContainer_obj();
	result->__construct();
	return result;}

Void DisplayObjectContainer_obj::AppendMask( Dynamic inMask){
{
		__SAFE_POINT
		this->super::AppendMask(inMask);
		{
			int _g = 0;
			Array< ::neash::display::DisplayObject > _g1 = this->mObjs;
			while((_g < _g1->length)){
				__SAFE_POINT
				::neash::display::DisplayObject obj = _g1->__get(_g);
				++_g;
				obj->AppendMask(inMask);
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(DisplayObjectContainer_obj,AppendMask,(void))

::neash::display::DisplayObjectContainer DisplayObjectContainer_obj::AsContainer( ){
	return this;
}


HX_DEFINE_DYNAMIC_FUNC0(DisplayObjectContainer_obj,AsContainer,return )

Void DisplayObjectContainer_obj::Broadcast( ::neash::events::Event inEvent){
{
		__SAFE_POINT
		this->dispatchEvent(inEvent);
		{
			int _g = 0;
			Array< ::neash::display::DisplayObject > _g1 = this->mObjs;
			while((_g < _g1->length)){
				__SAFE_POINT
				::neash::display::DisplayObject obj = _g1->__get(_g);
				++_g;
				::neash::display::DisplayObjectContainer container = obj->AsContainer();
				if ((container != null())){
					container->Broadcast(inEvent);
				}
				else{
					obj->dispatchEvent(inEvent);
				}
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(DisplayObjectContainer_obj,Broadcast,(void))

Void DisplayObjectContainer_obj::BuildBounds( ){
{
		__SAFE_POINT
		{
			this->super::BuildBounds();
			{
				int _g = 0;
				Array< ::neash::display::DisplayObject > _g1 = this->mObjs;
				while((_g < _g1->length)){
					__SAFE_POINT
					::neash::display::DisplayObject obj = _g1->__get(_g);
					++_g;
					if (obj->visible){
						::nme::geom::Rectangle r = obj->GetScreenBounds();
						if ((bool((r->width != 0)) || bool((r->height != 0)))){
							if ((bool((this->mBoundsRect->width == 0)) && bool((this->mBoundsRect->height == 0)))){
								this->mBoundsRect = r->clone();
							}
							else{
								this->mBoundsRect->extendBounds(r);
							}
						}
					}
				}
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(DisplayObjectContainer_obj,BuildBounds,(void))

Void DisplayObjectContainer_obj::DoAdded( ::neash::display::DisplayObject inObj){
{
		__SAFE_POINT
		this->super::DoAdded(inObj);
		{
			int _g = 0;
			Array< ::neash::display::DisplayObject > _g1 = this->mObjs;
			while((_g < _g1->length)){
				__SAFE_POINT
				::neash::display::DisplayObject child = _g1->__get(_g);
				++_g;
				child->DoAdded(inObj);
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(DisplayObjectContainer_obj,DoAdded,(void))

Void DisplayObjectContainer_obj::DoRemoved( ::neash::display::DisplayObject inObj){
{
		__SAFE_POINT
		this->super::DoAdded(inObj);
		{
			int _g = 0;
			Array< ::neash::display::DisplayObject > _g1 = this->mObjs;
			while((_g < _g1->length)){
				__SAFE_POINT
				::neash::display::DisplayObject child = _g1->__get(_g);
				++_g;
				child->DoRemoved(inObj);
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(DisplayObjectContainer_obj,DoRemoved,(void))

::nme::geom::Rectangle DisplayObjectContainer_obj::GetBackgroundRect( ){
	__SAFE_POINT
	::nme::geom::Rectangle r = this->super::GetBackgroundRect();
	if ((r != null()))
		r = r->clone();
	{
		int _g = 0;
		Array< ::neash::display::DisplayObject > _g1 = this->mObjs;
		while((_g < _g1->length)){
			__SAFE_POINT
			::neash::display::DisplayObject obj = _g1->__get(_g);
			++_g;
			if (obj->visible){
				::nme::geom::Rectangle o = obj->GetBackgroundRect();
				if ((o != null())){
					::nme::geom::Rectangle trans = o->transform(obj->mMatrix);
					if ((bool((r == null())) || bool((bool((r->width == 0)) || bool((r->height == 0)))))){
						r = trans;
					}
					else{
						if ((bool((trans->width != 0)) && bool((trans->height != 0))))
							r->extendBounds(trans);
					}
				}
			}
		}
	}
	return r;
}


HX_DEFINE_DYNAMIC_FUNC0(DisplayObjectContainer_obj,GetBackgroundRect,return )

Void DisplayObjectContainer_obj::GetFocusObjects( Array< ::neash::display::InteractiveObject > outObjs){
{
		__SAFE_POINT
		{
			int _g = 0;
			Array< ::neash::display::DisplayObject > _g1 = this->mObjs;
			while((_g < _g1->length)){
				__SAFE_POINT
				::neash::display::DisplayObject obj = _g1->__get(_g);
				++_g;
				obj->GetFocusObjects(outObjs);
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(DisplayObjectContainer_obj,GetFocusObjects,(void))

::neash::display::InteractiveObject DisplayObjectContainer_obj::GetChildCachedObj( int inX,int inY,::neash::display::InteractiveObject inObj){
	__SAFE_POINT
	int l = (this->mObjs->length - 1);
	{
		int _g1 = 0;
		int _g = this->mObjs->length;
		while((_g1 < _g)){
			__SAFE_POINT
			int i = _g1++;
			::neash::display::InteractiveObject result = this->mObjs[(l - i)]->GetObj(inX,inY,this);
			if ((result != null()))
				return result;
		}
	}
	return inObj;
}


HX_DEFINE_DYNAMIC_FUNC3(DisplayObjectContainer_obj,GetChildCachedObj,return )

Dynamic DisplayObjectContainer_obj::GetMaskHandle( ){
	__SAFE_POINT
	if ((this->mMaskHandle == null())){
		Dynamic handle = this->super::GetMaskHandle();
		if ((handle != null())){
			{
				int _g = 0;
				Array< ::neash::display::DisplayObject > _g1 = this->mObjs;
				while((_g < _g1->length)){
					__SAFE_POINT
					::neash::display::DisplayObject obj = _g1->__get(_g);
					++_g;
					obj->AppendMask(handle);
				}
			}
		}
	}
	return this->mMaskHandle;
}


HX_DEFINE_DYNAMIC_FUNC0(DisplayObjectContainer_obj,GetMaskHandle,return )

int DisplayObjectContainer_obj::GetNumChildren( ){
	return this->mObjs->length;
}


HX_DEFINE_DYNAMIC_FUNC0(DisplayObjectContainer_obj,GetNumChildren,return )

::neash::display::InteractiveObject DisplayObjectContainer_obj::GetObj( int inX,int inY,::neash::display::InteractiveObject inObj){
	__SAFE_POINT
	if ((bool(!this->visible) || bool((this->mMaskingObj != null()))))
		return null();
	int l = (this->mObjs->length - 1);
	{
		int _g1 = 0;
		int _g = this->mObjs->length;
		while((_g1 < _g)){
			__SAFE_POINT
			int i = _g1++;
			::neash::display::InteractiveObject result = this->mObjs[(l - i)]->GetObj(inX,inY,this);
			if ((result != null()))
				return result;
		}
	}
	return this->super::GetObj(inX,inY,this);
}


HX_DEFINE_DYNAMIC_FUNC3(DisplayObjectContainer_obj,GetObj,return )

Dynamic DisplayObjectContainer_obj::__Render( Dynamic inMask,::nme::geom::Rectangle inScrollRect,int inTX,int inTY){
	__SAFE_POINT
	if ((bool(!this->visible) || bool((this->mMaskingObj != null()))))
		return null();
	if ((bool(this->GetCacheAsBitmap()) && bool((this->mCachedBitmap != null())))){
		this->RenderCache(inMask);
	}
	else{
		inMask = this->super::__Render(inMask,inScrollRect,inTX,inTY);
		{
			int _g = 0;
			Array< ::neash::display::DisplayObject > _g1 = this->mObjs;
			while((_g < _g1->length)){
				__SAFE_POINT
				::neash::display::DisplayObject obj = _g1->__get(_g);
				++_g;
				if ((bool(obj->visible) && bool((obj->mMaskingObj == null())))){
					::nme::geom::Rectangle scroll = obj->mScrollRect;
					if ((scroll != null())){
						::nme::geom::Matrix m = obj->mFullMatrix;
						double x0 = m->tx;
						double y0 = m->ty;
						double x1 = ((m->a * scroll->width) + m->tx);
						double y1 = ((m->d * scroll->height) + m->ty);
						::nme::geom::Rectangle display_rect = ::nme::geom::Rectangle_obj::__new(x0,y0,(x1 - x0),(y1 - y0));
						if ((inScrollRect != null()))
							display_rect = display_rect->intersection(inScrollRect);
						if (!display_rect->isEmpty()){
							int tx = (inTX + ::Std_obj::toInt((scroll->x * m->a)));
							int ty = (inTY + ::Std_obj::toInt((scroll->y * m->d)));
							obj->__Render(inMask,display_rect,tx,ty);
						}
					}
					else{
						obj->__Render(inMask,inScrollRect,inTX,inTY);
					}
				}
			}
		}
	}
	return inMask;
}


HX_DEFINE_DYNAMIC_FUNC4(DisplayObjectContainer_obj,__Render,return )

Void DisplayObjectContainer_obj::RenderContentsToCache( ::nme::display::BitmapData inBitmap,double inTX,double inTY){
{
		__SAFE_POINT
		this->super::RenderContentsToCache(inBitmap,inTX,inTY);
		{
			int _g = 0;
			Array< ::neash::display::DisplayObject > _g1 = this->mObjs;
			while((_g < _g1->length)){
				__SAFE_POINT
				::neash::display::DisplayObject obj = _g1->__get(_g);
				++_g;
				obj->RenderContentsToCache(inBitmap,inTX,inTY);
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC3(DisplayObjectContainer_obj,RenderContentsToCache,(void))

int DisplayObjectContainer_obj::SetupRender( ::nme::geom::Matrix inParentMatrix){
	__SAFE_POINT
	int super_result = this->super::SetupRender(inParentMatrix);
	int child_result = 0;
	{
		int _g = 0;
		Array< ::neash::display::DisplayObject > _g1 = this->mObjs;
		while((_g < _g1->length)){
			__SAFE_POINT
			::neash::display::DisplayObject obj = _g1->__get(_g);
			++_g;
			if (obj->visible)
				hx::OrEq(child_result,obj->SetupRender(this->mFullMatrix));
		}
	}
	if ((this->mLastSetupObjs->length != this->mObjs->length)){
		hx::OrEq(child_result,::neash::display::DisplayObject_obj::NON_TRANSLATE_CHANGE);
	}
	else{
		if ((child_result == 0)){
			int _g1 = 0;
			int _g = this->mObjs->length;
			while((_g1 < _g)){
				__SAFE_POINT
				int i = _g1++;
				if ((this->mObjs->__get(i) != this->mLastSetupObjs->__get(i))){
					hx::OrEq(child_result,::neash::display::DisplayObject_obj::NON_TRANSLATE_CHANGE);
					break;
				}
			}
		}
	}
	this->mLastSetupObjs = this->mObjs->copy();
	int result = 0;
	if ((child_result != 0))
		result = (int(::neash::display::DisplayObject_obj::TRANSLATE_CHANGE) | int(::neash::display::DisplayObject_obj::NON_TRANSLATE_CHANGE));
	if ((((int(result) & int(::neash::display::DisplayObject_obj::NON_TRANSLATE_CHANGE))) != 0)){
		this->mCachedBitmap = null();
		this->mBoundsDirty = true;
	}
	if ((((int(result) | int(super_result))) != 0))
		this->mBoundsDirty = true;
	if ((bool(this->GetCacheAsBitmap()) && bool((this->mCachedBitmap == null()))))
		this->CreateBitmapCache();
	if ((result != 0))
		this->mMaskHandle = null();
	return (int(result) | int(super_result));
}


HX_DEFINE_DYNAMIC_FUNC1(DisplayObjectContainer_obj,SetupRender,return )

Void DisplayObjectContainer_obj::addChild( ::neash::display::DisplayObject inObject){
{
		__SAFE_POINT
		if ((inObject == this)){
			hx::Throw (HX_STRING(L"Adding to self",14));
		}
		if ((inObject->mParent == this)){
			this->setChildIndex(inObject,(this->mObjs->length - 1));
			return null();
		}
		this->mObjs->push(inObject);
		inObject->SetParent(this);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(DisplayObjectContainer_obj,addChild,(void))

Void DisplayObjectContainer_obj::addChildAt( ::neash::display::DisplayObject obj,int index){
{
		__SAFE_POINT
		if ((bool((index > this->mObjs->length)) || bool((index < 0)))){
			hx::Throw ((HX_STRING(L"Invalid index position ",23) + index));
		}
		if ((obj->mParent == this)){
			this->setChildIndex(obj,index);
			return null();
		}
		if ((index == this->mObjs->length)){
			this->mObjs->push(obj);
		}
		else{
			this->mObjs->insert(index,obj);
		}
		obj->SetParent(this);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(DisplayObjectContainer_obj,addChildAt,(void))

bool DisplayObjectContainer_obj::contains( ::neash::display::DisplayObject obj){
	if ((obj == this))
		return true;
	{
		int _g = 0;
		Array< ::neash::display::DisplayObject > _g1 = this->mObjs;
		while((_g < _g1->length)){
			__SAFE_POINT
			::neash::display::DisplayObject i = _g1->__get(_g);
			++_g;
			if ((obj == i))
				return true;
		}
	}
	return false;
}


HX_DEFINE_DYNAMIC_FUNC1(DisplayObjectContainer_obj,contains,return )

::neash::display::DisplayObject DisplayObjectContainer_obj::getChildAt( int index){
	return this->mObjs->__get(index);
}


HX_DEFINE_DYNAMIC_FUNC1(DisplayObjectContainer_obj,getChildAt,return )

::neash::display::DisplayObject DisplayObjectContainer_obj::getChildByName( ::String inName){
	{
		int _g1 = 0;
		int _g = this->mObjs->length;
		while((_g1 < _g)){
			__SAFE_POINT
			int i = _g1++;
			if ((this->mObjs[i]->name == inName))
				return this->mObjs->__get(i);
		}
	}
	return null();
}


HX_DEFINE_DYNAMIC_FUNC1(DisplayObjectContainer_obj,getChildByName,return )

int DisplayObjectContainer_obj::getChildIndex( ::neash::display::DisplayObject child){
	{
		int _g1 = 0;
		int _g = this->mObjs->length;
		while((_g1 < _g)){
			__SAFE_POINT
			int i = _g1++;
			if ((this->mObjs->__get(i) == child))
				return i;
		}
	}
	return -1;
}


HX_DEFINE_DYNAMIC_FUNC1(DisplayObjectContainer_obj,getChildIndex,return )

Void DisplayObjectContainer_obj::removeChild( ::neash::display::DisplayObject child){
{
		__SAFE_POINT
		{
			int _g1 = 0;
			int _g = this->mObjs->length;
			while((_g1 < _g)){
				__SAFE_POINT
				int i = _g1++;
				if ((this->mObjs->__get(i) == child)){
					child->SetParent(null());
					return null();
				}
			}
		}
		hx::Throw (HX_STRING(L"removeChild : none found?",25));
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(DisplayObjectContainer_obj,removeChild,(void))

Void DisplayObjectContainer_obj::removeChildAt( int inI){
{
		__SAFE_POINT
		this->mObjs[inI]->SetParent(null());
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(DisplayObjectContainer_obj,removeChildAt,(void))

Void DisplayObjectContainer_obj::__removeChild( ::neash::display::DisplayObject child){
{
		__SAFE_POINT
		int i = this->getChildIndex(child);
		if ((i >= 0)){
			this->mObjs->splice(i,1);
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(DisplayObjectContainer_obj,__removeChild,(void))

Void DisplayObjectContainer_obj::setChildIndex( ::neash::display::DisplayObject child,int index){
{
		__SAFE_POINT
		if ((index > this->mObjs->length)){
			hx::Throw ((HX_STRING(L"Invalid index position ",23) + index));
		}
		::neash::display::DisplayObject s = null();
		int orig = this->getChildIndex(child);
		if ((orig < 0)){
			::String msg = (((HX_STRING(L"setChildIndex : object ",23) + child->name)) + HX_STRING(L" not found.",11));
			if ((child->GetParent() == this)){
				int realindex = -1;
				{
					int _g1 = 0;
					int _g = this->mObjs->length;
					while((_g1 < _g)){
						__SAFE_POINT
						int i = _g1++;
						if ((this->mObjs->__get(i) == child)){
							realindex = i;
							break;
						}
					}
				}
				if ((realindex != -1)){
					hx::AddEq(msg,(HX_STRING(L"Internal error: Real child index was ",37) + ::Std_obj::string(realindex)));
				}
				else{
					hx::AddEq(msg,HX_STRING(L"Internal error: Child was not in mObjs array!",45));
				}
			}
			hx::Throw (msg);
		}
		if ((index < orig)){
			int i = orig;
			while((i > index)){
				__SAFE_POINT
				this->mObjs[i] = this->mObjs->__get((i - 1));
				i--;
			}
			this->mObjs[index] = child;
		}
		else{
			if ((orig < index)){
				int i = orig;
				while((i < index)){
					__SAFE_POINT
					this->mObjs[i] = this->mObjs->__get((i + 1));
					i++;
				}
				this->mObjs[index] = child;
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(DisplayObjectContainer_obj,setChildIndex,(void))

Void DisplayObjectContainer_obj::swapChildren( ::neash::display::DisplayObject child1,::neash::display::DisplayObject child2){
{
		int c1 = -1;
		int c2 = -1;
		::neash::display::DisplayObject swap;
		{
			int _g1 = 0;
			int _g = this->mObjs->length;
			while((_g1 < _g)){
				__SAFE_POINT
				int i = _g1++;
				if ((this->mObjs->__get(i) == child1)){
					c1 = i;
				}
				else{
					if ((this->mObjs->__get(i) == child2))
						c2 = i;
				}
			}
		}
		if ((bool((c1 != -1)) && bool((c2 != -1)))){
			swap = this->mObjs->__get(c1);
			this->mObjs[c1] = this->mObjs->__get(c2);
			this->mObjs[c2] = swap;
			swap = null();
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(DisplayObjectContainer_obj,swapChildren,(void))

Void DisplayObjectContainer_obj::swapChildrenAt( int child1,int child2){
{
		::neash::display::DisplayObject swap = this->mObjs->__get(child1);
		this->mObjs[child1] = this->mObjs->__get(child2);
		this->mObjs[child2] = swap;
		swap = null();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(DisplayObjectContainer_obj,swapChildrenAt,(void))


DisplayObjectContainer_obj::DisplayObjectContainer_obj()
{
}

void DisplayObjectContainer_obj::__Mark()
{
	hx::MarkMember(mObjs);
	hx::MarkMember(mLastSetupObjs);
	hx::MarkMember(numChildren);
	hx::MarkMember(mouseChildren);
	super::__Mark();
}

Dynamic DisplayObjectContainer_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 5:
		if (!memcmp(inName.__s,L"mObjs",sizeof(wchar_t)*5) ) { return mObjs; }
		break;
	case 6:
		if (!memcmp(inName.__s,L"GetObj",sizeof(wchar_t)*6) ) { return GetObj_dyn(); }
		break;
	case 7:
		if (!memcmp(inName.__s,L"DoAdded",sizeof(wchar_t)*7) ) { return DoAdded_dyn(); }
		break;
	case 8:
		if (!memcmp(inName.__s,L"__Render",sizeof(wchar_t)*8) ) { return __Render_dyn(); }
		if (!memcmp(inName.__s,L"addChild",sizeof(wchar_t)*8) ) { return addChild_dyn(); }
		if (!memcmp(inName.__s,L"contains",sizeof(wchar_t)*8) ) { return contains_dyn(); }
		break;
	case 9:
		if (!memcmp(inName.__s,L"Broadcast",sizeof(wchar_t)*9) ) { return Broadcast_dyn(); }
		if (!memcmp(inName.__s,L"DoRemoved",sizeof(wchar_t)*9) ) { return DoRemoved_dyn(); }
		break;
	case 10:
		if (!memcmp(inName.__s,L"AppendMask",sizeof(wchar_t)*10) ) { return AppendMask_dyn(); }
		if (!memcmp(inName.__s,L"addChildAt",sizeof(wchar_t)*10) ) { return addChildAt_dyn(); }
		if (!memcmp(inName.__s,L"getChildAt",sizeof(wchar_t)*10) ) { return getChildAt_dyn(); }
		break;
	case 11:
		if (!memcmp(inName.__s,L"numChildren",sizeof(wchar_t)*11) ) { return GetNumChildren(); }
		if (!memcmp(inName.__s,L"AsContainer",sizeof(wchar_t)*11) ) { return AsContainer_dyn(); }
		if (!memcmp(inName.__s,L"BuildBounds",sizeof(wchar_t)*11) ) { return BuildBounds_dyn(); }
		if (!memcmp(inName.__s,L"SetupRender",sizeof(wchar_t)*11) ) { return SetupRender_dyn(); }
		if (!memcmp(inName.__s,L"removeChild",sizeof(wchar_t)*11) ) { return removeChild_dyn(); }
		break;
	case 12:
		if (!memcmp(inName.__s,L"swapChildren",sizeof(wchar_t)*12) ) { return swapChildren_dyn(); }
		break;
	case 13:
		if (!memcmp(inName.__s,L"mouseChildren",sizeof(wchar_t)*13) ) { return mouseChildren; }
		if (!memcmp(inName.__s,L"GetMaskHandle",sizeof(wchar_t)*13) ) { return GetMaskHandle_dyn(); }
		if (!memcmp(inName.__s,L"getChildIndex",sizeof(wchar_t)*13) ) { return getChildIndex_dyn(); }
		if (!memcmp(inName.__s,L"removeChildAt",sizeof(wchar_t)*13) ) { return removeChildAt_dyn(); }
		if (!memcmp(inName.__s,L"__removeChild",sizeof(wchar_t)*13) ) { return __removeChild_dyn(); }
		if (!memcmp(inName.__s,L"setChildIndex",sizeof(wchar_t)*13) ) { return setChildIndex_dyn(); }
		break;
	case 14:
		if (!memcmp(inName.__s,L"mLastSetupObjs",sizeof(wchar_t)*14) ) { return mLastSetupObjs; }
		if (!memcmp(inName.__s,L"GetNumChildren",sizeof(wchar_t)*14) ) { return GetNumChildren_dyn(); }
		if (!memcmp(inName.__s,L"getChildByName",sizeof(wchar_t)*14) ) { return getChildByName_dyn(); }
		if (!memcmp(inName.__s,L"swapChildrenAt",sizeof(wchar_t)*14) ) { return swapChildrenAt_dyn(); }
		break;
	case 15:
		if (!memcmp(inName.__s,L"GetFocusObjects",sizeof(wchar_t)*15) ) { return GetFocusObjects_dyn(); }
		break;
	case 17:
		if (!memcmp(inName.__s,L"GetBackgroundRect",sizeof(wchar_t)*17) ) { return GetBackgroundRect_dyn(); }
		if (!memcmp(inName.__s,L"GetChildCachedObj",sizeof(wchar_t)*17) ) { return GetChildCachedObj_dyn(); }
		break;
	case 21:
		if (!memcmp(inName.__s,L"RenderContentsToCache",sizeof(wchar_t)*21) ) { return RenderContentsToCache_dyn(); }
	}
	return super::__Field(inName);
}

Dynamic DisplayObjectContainer_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	switch(inName.length) {
	case 5:
		if (!memcmp(inName.__s,L"mObjs",sizeof(wchar_t)*5) ) { mObjs=inValue.Cast< Array< ::neash::display::DisplayObject > >(); return inValue; }
		break;
	case 11:
		if (!memcmp(inName.__s,L"numChildren",sizeof(wchar_t)*11) ) { numChildren=inValue.Cast< int >(); return inValue; }
		break;
	case 13:
		if (!memcmp(inName.__s,L"mouseChildren",sizeof(wchar_t)*13) ) { mouseChildren=inValue.Cast< bool >(); return inValue; }
		break;
	case 14:
		if (!memcmp(inName.__s,L"mLastSetupObjs",sizeof(wchar_t)*14) ) { mLastSetupObjs=inValue.Cast< Array< ::neash::display::DisplayObject > >(); return inValue; }
	}
	return super::__SetField(inName,inValue);
}

void DisplayObjectContainer_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_STRING(L"mObjs",5));
	outFields->push(HX_STRING(L"mLastSetupObjs",14));
	outFields->push(HX_STRING(L"numChildren",11));
	outFields->push(HX_STRING(L"mouseChildren",13));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_STRING(L"mObjs",5),
	HX_STRING(L"mLastSetupObjs",14),
	HX_STRING(L"numChildren",11),
	HX_STRING(L"mouseChildren",13),
	HX_STRING(L"AppendMask",10),
	HX_STRING(L"AsContainer",11),
	HX_STRING(L"Broadcast",9),
	HX_STRING(L"BuildBounds",11),
	HX_STRING(L"DoAdded",7),
	HX_STRING(L"DoRemoved",9),
	HX_STRING(L"GetBackgroundRect",17),
	HX_STRING(L"GetFocusObjects",15),
	HX_STRING(L"GetChildCachedObj",17),
	HX_STRING(L"GetMaskHandle",13),
	HX_STRING(L"GetNumChildren",14),
	HX_STRING(L"GetObj",6),
	HX_STRING(L"__Render",8),
	HX_STRING(L"RenderContentsToCache",21),
	HX_STRING(L"SetupRender",11),
	HX_STRING(L"addChild",8),
	HX_STRING(L"addChildAt",10),
	HX_STRING(L"contains",8),
	HX_STRING(L"getChildAt",10),
	HX_STRING(L"getChildByName",14),
	HX_STRING(L"getChildIndex",13),
	HX_STRING(L"removeChild",11),
	HX_STRING(L"removeChildAt",13),
	HX_STRING(L"__removeChild",13),
	HX_STRING(L"setChildIndex",13),
	HX_STRING(L"swapChildren",12),
	HX_STRING(L"swapChildrenAt",14),
	String(null()) };

static void sMarkStatics() {
};

Class DisplayObjectContainer_obj::__mClass;

void DisplayObjectContainer_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_STRING(L"neash.display.DisplayObjectContainer",36), hx::TCanCast< DisplayObjectContainer_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void DisplayObjectContainer_obj::__boot()
{
}

} // end namespace neash
} // end namespace display
