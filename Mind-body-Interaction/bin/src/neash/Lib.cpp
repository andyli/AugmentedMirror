#include <hxcpp.h>

#ifndef INCLUDED_cpp_Sys
#include <cpp/Sys.h>
#endif
#ifndef INCLUDED_neash_Lib
#include <neash/Lib.h>
#endif
#ifndef INCLUDED_neash_Timer
#include <neash/Timer.h>
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
#ifndef INCLUDED_neash_display_MovieClip
#include <neash/display/MovieClip.h>
#endif
#ifndef INCLUDED_neash_display_Sprite
#include <neash/display/Sprite.h>
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
#ifndef INCLUDED_neash_events_EventPhase
#include <neash/events/EventPhase.h>
#endif
#ifndef INCLUDED_neash_events_IEventDispatcher
#include <neash/events/IEventDispatcher.h>
#endif
#ifndef INCLUDED_neash_events_KeyboardEvent
#include <neash/events/KeyboardEvent.h>
#endif
#ifndef INCLUDED_neash_events_MouseEvent
#include <neash/events/MouseEvent.h>
#endif
#ifndef INCLUDED_neash_text_KeyCode
#include <neash/text/KeyCode.h>
#endif
#ifndef INCLUDED_nme_EventType
#include <nme/EventType.h>
#endif
#ifndef INCLUDED_nme_Manager
#include <nme/Manager.h>
#endif
#ifndef INCLUDED_nme_MouseEventType
#include <nme/MouseEventType.h>
#endif
#ifndef INCLUDED_nme_display_IBitmapDrawable
#include <nme/display/IBitmapDrawable.h>
#endif
#ifndef INCLUDED_nme_geom_Point
#include <nme/geom/Point.h>
#endif
#ifndef INCLUDED_nme_geom_Rectangle
#include <nme/geom/Rectangle.h>
#endif
namespace neash{

Void Lib_obj::__construct(::String inName,int inWidth,int inHeight,Dynamic inFullScreen,Dynamic inResizable,Dynamic cb)
{
{
	this->mKilled = false;
	this->mRequestedWidth = inWidth;
	this->mRequestedHeight = inHeight;
	this->mResizePending = false;
	this->mArgs = ::__get_args();
	bool vsync = false;
	while((this->mArgs->length > 0)){
		__SAFE_POINT
		if ((this->mArgs->__get(0) == HX_STRING(L"-opengl",7))){
			::neash::Lib_obj::mOpenGL = true;
			this->mArgs->shift();
		}
		else{
			if ((this->mArgs->__get(0) == HX_STRING(L"-fullscreen",11))){
				::neash::Lib_obj::mFullscreen = true;
				this->mArgs->shift();
			}
			else{
				if ((this->mArgs->__get(0) == HX_STRING(L"-vsync",6))){
					vsync = true;
					this->mArgs->shift();
				}
				else{
					if ((this->mArgs->__get(0) == HX_STRING(L"-debug",6))){
						::neash::Lib_obj::debug = true;
						this->mArgs->shift();
					}
					else{
						break;
					}
				}
			}
		}
	}
	bool full = (inFullScreen == null()) ? Dynamic( ::neash::Lib_obj::mFullscreen ) : Dynamic( inFullScreen );
	bool resizable = (inResizable == null()) ? Dynamic( true ) : Dynamic( inResizable );
	this->mManager = ::nme::Manager_obj::__new(inWidth,inHeight,inName,full,HX_STRING(L"",0),::neash::Lib_obj::mOpenGL,resizable,true,vsync);
	int w = ::nme::Manager_obj::getWindowWidth();
	int h = ::nme::Manager_obj::getWindowHeight();
	this->mResizePending = (bool(((w != this->mRequestedWidth))) || bool(((h != this->mRequestedHeight))));
	::neash::Lib_obj::mStage = ::neash::display::Stage_obj::__new(w,h,this->mManager);
	::neash::Lib_obj::mStage->frameRate = 100;
	::neash::Lib_obj::mMainClassRoot = ::neash::display::MovieClip_obj::__new();
	::neash::Lib_obj::mStage->addChild(::neash::Lib_obj::mMainClassRoot);
	::neash::Lib_obj::mCurrent = ::neash::Lib_obj::mMainClassRoot;
	::neash::Lib_obj::mCurrent->name = HX_STRING(L"Root MovieClip",14);
	::neash::Lib_obj::mRolling = null();
}
;
	return null();
}

Lib_obj::~Lib_obj() { }

Dynamic Lib_obj::__CreateEmpty() { return  new Lib_obj; }
hx::ObjectPtr< Lib_obj > Lib_obj::__new(::String inName,int inWidth,int inHeight,Dynamic inFullScreen,Dynamic inResizable,Dynamic cb)
{  hx::ObjectPtr< Lib_obj > result = new Lib_obj();
	result->__construct(inName,inWidth,inHeight,inFullScreen,inResizable,cb);
	return result;}

Dynamic Lib_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Lib_obj > result = new Lib_obj();
	result->__construct(inArgs[0],inArgs[1],inArgs[2],inArgs[3],inArgs[4],inArgs[5]);
	return result;}

Void Lib_obj::OnResize( int inW,int inH){
{
		__SAFE_POINT
		this->mManager->OnResize(inW,inH);
		::neash::Lib_obj::mStage->OnResize(inW,inH);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(Lib_obj,OnResize,(void))

Void Lib_obj::ProcessKeys( int code,bool pressed,int inChar,bool ctrl,bool alt,bool shift){
{
		__SAFE_POINT
		if ((bool((code == ::neash::text::KeyCode_obj::ESCAPE)) && bool(::neash::Lib_obj::mQuitOnEscape))){
			this->mKilled = true;
			return null();
		}
		int _switch_1 = code;
		if (  ( _switch_1==::neash::text::KeyCode_obj::TAB)){
			::neash::Lib_obj::mStage->TabChange(shift ? int( -1 ) : int( 1 ),code);
		}
		else  {
			::neash::events::KeyboardEvent event = ::neash::events::KeyboardEvent_obj::__new(pressed ? ::String( ::neash::events::KeyboardEvent_obj::KEY_DOWN ) : ::String( ::neash::events::KeyboardEvent_obj::KEY_UP ),true,false,inChar,::neash::text::KeyCode_obj::ConvertCode(code),::neash::text::KeyCode_obj::ConvertLocation(code),ctrl,alt,shift);
			::neash::Lib_obj::mStage->HandleKey(event);
		}
;
;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC6(Lib_obj,ProcessKeys,(void))

::neash::events::MouseEvent Lib_obj::CreateMouseEvent( ::neash::display::InteractiveObject inObj,::neash::display::InteractiveObject inRelatedObj,Dynamic inMouse,::String inType){
	__SAFE_POINT
	bool bubble = (bool((inType != ::neash::events::MouseEvent_obj::ROLL_OUT)) && bool((inType != ::neash::events::MouseEvent_obj::ROLL_OVER)));
	::nme::geom::Point pos = ::nme::geom::Point_obj::__new(inMouse->__Field(HX_STRING(L"x",1)).Cast< int >(),inMouse->__Field(HX_STRING(L"y",1)).Cast< int >());
	if ((inObj != null()))
		pos = inObj->globalToLocal(pos);
	::neash::events::MouseEvent result = ::neash::events::MouseEvent_obj::__new(inType,bubble,false,pos->x,pos->y,inRelatedObj,inMouse->__Field(HX_STRING(L"ctrl",4)).Cast< bool >(),inMouse->__Field(HX_STRING(L"alt",3)).Cast< bool >(),inMouse->__Field(HX_STRING(L"shift",5)).Cast< bool >(),inMouse->__Field(HX_STRING(L"leftIsDown",10)).Cast< bool >(),2);
	result->stageX = (double(inMouse->__Field(HX_STRING(L"x",1)).Cast< int >()) / double(::neash::Lib_obj::mStage->GetScaleX()));
	result->stageY = (double(inMouse->__Field(HX_STRING(L"y",1)).Cast< int >()) / double(::neash::Lib_obj::mStage->GetScaleY()));
	result->target = inObj;
	return result;
}


HX_DEFINE_DYNAMIC_FUNC4(Lib_obj,CreateMouseEvent,return )

::neash::display::InteractiveObject Lib_obj::GetInteractiveObjectAtPos( int inX,int inY){
	__SAFE_POINT
	return ::neash::Lib_obj::mStage->GetInteractiveObjectAtPos(inX,inY);
}


HX_DEFINE_DYNAMIC_FUNC2(Lib_obj,GetInteractiveObjectAtPos,return )

Void Lib_obj::DragObject( double inX,double inY){
{
		__SAFE_POINT
		::nme::geom::Point pos = ::nme::geom::Point_obj::__new(inX,inY);
		::neash::display::DisplayObjectContainer p = ::neash::Lib_obj::mDragObject->GetParent();
		if ((p != null()))
			pos = p->globalToLocal(pos);
		if ((::neash::Lib_obj::mDragRect != null())){
			if ((pos->x < ::neash::Lib_obj::mDragRect->x)){
				pos->x = ::neash::Lib_obj::mDragRect->x;
			}
			else{
				if ((pos->x > ::neash::Lib_obj::mDragRect->get_right()))
					pos->x = ::neash::Lib_obj::mDragRect->get_right();
			}
			if ((pos->y < ::neash::Lib_obj::mDragRect->y)){
				pos->y = ::neash::Lib_obj::mDragRect->y;
			}
			else{
				if ((pos->y > ::neash::Lib_obj::mDragRect->get_bottom()))
					pos->y = ::neash::Lib_obj::mDragRect->get_bottom();
			}
		}
		::neash::Lib_obj::mDragObject->SetX((pos->x + ::neash::Lib_obj::mDragOffsetX));
		::neash::Lib_obj::mDragObject->SetY((pos->y + ::neash::Lib_obj::mDragOffsetY));
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(Lib_obj,DragObject,(void))

Void Lib_obj::DoMouse( ::nme::EventType inEvent){
{
		__SAFE_POINT
		Dynamic mouse = ::nme::Manager_obj::mouseEvent(::nme::MouseEventType_obj::met_Move);
		::neash::Lib_obj::mLastMouse->x = mouse->__Field(HX_STRING(L"x",1)).Cast< int >();
		::neash::Lib_obj::mLastMouse->y = mouse->__Field(HX_STRING(L"y",1)).Cast< int >();
		if ((::neash::Lib_obj::mDragObject != null()))
			this->DragObject((double(mouse->__Field(HX_STRING(L"x",1)).Cast< int >()) / double(::neash::Lib_obj::mStage->GetScaleX())),(double(mouse->__Field(HX_STRING(L"y",1)).Cast< int >()) / double(::neash::Lib_obj::mStage->GetScaleY())));
		::neash::display::InteractiveObject obj = this->GetInteractiveObjectAtPos(mouse->__Field(HX_STRING(L"x",1)).Cast< int >(),mouse->__Field(HX_STRING(L"y",1)).Cast< int >());
		::String type = ((inEvent == ::nme::EventType_obj::et_mousemove)) ? ::String( ::neash::events::MouseEvent_obj::MOUSE_MOVE ) : ::String( ((inEvent == ::nme::EventType_obj::et_mousebutton_up)) ? ::String( ::neash::events::MouseEvent_obj::MOUSE_UP ) : ::String( ((inEvent == ::nme::EventType_obj::et_mousebutton_down)) ? ::String( ::neash::events::MouseEvent_obj::MOUSE_DOWN ) : ::String( HX_STRING(L"unknown",7) ) ) );
		Array< ::neash::display::InteractiveObject > new_list = (obj != null()) ? Array< ::neash::display::InteractiveObject >( ::neash::Lib_obj::GetAnscestors(obj) ) : Array< ::neash::display::InteractiveObject >( Array_obj< ::neash::display::InteractiveObject >::__new() );
		int nl = new_list->length;
		if ((obj != ::neash::Lib_obj::mRolling)){
			if ((::neash::Lib_obj::mRolling != null())){
				::neash::Lib_obj::mRolling->DoMouseLeave();
				::neash::events::MouseEvent evt = this->CreateMouseEvent(::neash::Lib_obj::mRolling,obj,mouse,::neash::events::MouseEvent_obj::MOUSE_OUT);
				::neash::Lib_obj::mRolling->dispatchEvent(evt);
			}
			Array< ::neash::display::InteractiveObject > old_list = ::neash::Lib_obj::GetAnscestors(::neash::Lib_obj::mRolling);
			int ol = old_list->length;
			int common = 0;
			int stop = (ol < nl) ? int( ol ) : int( nl );
			while((bool((common < stop)) && bool((old_list->__get(common) == new_list->__get(common)))))common++;
			if ((ol > common)){
				::neash::events::MouseEvent evt = this->CreateMouseEvent(::neash::Lib_obj::mRolling,obj,mouse,::neash::events::MouseEvent_obj::ROLL_OUT);
				{
					int _g = common;
					while((_g < ol)){
						__SAFE_POINT
						int o = _g++;
						evt->target = old_list->__get(o);
						old_list[o]->dispatchEvent(evt);
					}
				}
			}
			if ((nl > common)){
				::neash::events::MouseEvent evt = this->CreateMouseEvent(obj,::neash::Lib_obj::mRolling,mouse,::neash::events::MouseEvent_obj::ROLL_OVER);
				{
					int _g = common;
					while((_g < nl)){
						__SAFE_POINT
						int o = _g++;
						evt->target = new_list->__get(o);
						new_list[o]->dispatchEvent(evt);
					}
				}
			}
			::neash::Lib_obj::mRolling = obj;
			if ((::neash::Lib_obj::mRolling != null())){
				::neash::Lib_obj::mRolling->DoMouseEnter();
				::neash::events::MouseEvent evt = this->CreateMouseEvent(::neash::Lib_obj::mRolling,obj,mouse,::neash::events::MouseEvent_obj::MOUSE_OVER);
				::neash::Lib_obj::mRolling->dispatchEvent(evt);
			}
		}
		if ((inEvent == ::nme::EventType_obj::et_mousebutton_down)){
			::neash::Lib_obj::mDownObj = obj;
			if ((obj != null()))
				obj->OnMouseDown(mouse->__Field(HX_STRING(L"x",1)).Cast< int >(),mouse->__Field(HX_STRING(L"y",1)).Cast< int >());
		}
		else{
			if ((bool((inEvent == ::nme::EventType_obj::et_mousemove)) && bool((::neash::Lib_obj::mDownObj != null())))){
				::neash::Lib_obj::mDownObj->OnMouseDrag(mouse->__Field(HX_STRING(L"x",1)).Cast< int >(),mouse->__Field(HX_STRING(L"y",1)).Cast< int >());
			}
			else{
				if ((inEvent == ::nme::EventType_obj::et_mousebutton_up)){
					if ((::neash::Lib_obj::mDownObj != null())){
						::neash::Lib_obj::mDownObj->OnMouseUp(mouse->__Field(HX_STRING(L"x",1)).Cast< int >(),mouse->__Field(HX_STRING(L"y",1)).Cast< int >());
						if ((obj == ::neash::Lib_obj::mDownObj)){
							::neash::events::MouseEvent evt = this->CreateMouseEvent(obj,null(),mouse,::neash::events::MouseEvent_obj::CLICK);
							::neash::Lib_obj::FireEvents(evt,new_list);
						}
						else{
							obj = ::neash::Lib_obj::mDownObj;
							new_list = ::neash::Lib_obj::GetAnscestors(obj);
						}
					}
					::neash::Lib_obj::mDownObj = null();
				}
			}
		}
		if ((bool((bool((nl > 0)) && bool(((bool((inEvent == ::nme::EventType_obj::et_mousebutton_down)) || bool((inEvent == ::nme::EventType_obj::et_mousebutton_up))))))) || bool((inEvent == ::nme::EventType_obj::et_mousemove)))){
			::neash::events::MouseEvent evt = this->CreateMouseEvent(obj,null(),mouse,type);
			::neash::Lib_obj::FireEvents(evt,new_list);
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Lib_obj,DoMouse,(void))

Void Lib_obj::step( ){
{
		__SAFE_POINT
		::nme::EventType type;
		do{
			Dynamic evt = this->mManager->getNextEvent();
			type = this->mManager->getEventType();
			::nme::EventType _switch_2 = (type);
			switch((_switch_2)->GetIndex()){
				case 2: {
					int code = this->mManager->lastKey();
					this->ProcessKeys(code,true,this->mManager->lastChar(),this->mManager->lastKeyCtrl(),this->mManager->lastKeyAlt(),this->mManager->lastKeyShift());
				}
				;break;
				case 3: {
					int code = this->mManager->lastKey();
					this->ProcessKeys(code,false,this->mManager->lastChar(),this->mManager->lastKeyCtrl(),this->mManager->lastKeyAlt(),this->mManager->lastKeyShift());
				}
				;break;
				case 4: {
					this->DoMouse(::nme::EventType_obj::et_mousemove);
				}
				;break;
				case 5: {
					this->DoMouse(::nme::EventType_obj::et_mousebutton_down);
				}
				;break;
				case 6: {
					this->DoMouse(::nme::EventType_obj::et_mousebutton_up);
				}
				;break;
				case 11: {
					this->OnResize(evt->__Field(HX_STRING(L"width",5)).Cast< int >(),evt->__Field(HX_STRING(L"height",6)).Cast< int >());
				}
				;break;
				case 12: {
					this->mKilled = true;
				}
				;break;
				default: {
				}
			}
		}
while((bool((type != ::nme::EventType_obj::et_noevent)) && bool(!this->mKilled)));
		::neash::Timer_obj::CheckTimers();
		::neash::events::Event event = ::neash::events::Event_obj::__new(::neash::events::Event_obj::ENTER_FRAME,null(),null());
		::neash::Lib_obj::mStage->Broadcast(event);
		::neash::Lib_obj::mStage->RenderAll();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Lib_obj,step,(void))

Void Lib_obj::MyRun( ){
{
		__SAFE_POINT
		double last_render = 0.0;
		if (this->mResizePending){
			this->mResizePending = false;
			::neash::Lib_obj::mStage->OnResize(::nme::Manager_obj::getWindowWidth(),::nme::Manager_obj::getWindowHeight());
		}
		while(!this->mKilled){
			__SAFE_POINT
			this->step();
			if ((::neash::Lib_obj::mStage->frameRate > 0)){
				double next = (last_render + ((double(1000.0) / double(::neash::Lib_obj::mStage->frameRate))));
				int now = ::neash::Lib_obj::getTimer();
				if (((now + 10.0) < next)){
					::cpp::Sys_obj::sleep((((next - now)) * 0.001));
					now = ::neash::Lib_obj::getTimer();
					last_render = now;
				}
				else{
					last_render = now;
				}
			}
			if (::neash::Lib_obj::mShowFPS)
				this->mManager->RenderFPS();
			if (::neash::Lib_obj::mCollectEveryFrame){
				::__hxcpp_collect();
			}
			this->mManager->flip();
		}
		this->mManager->close();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Lib_obj,MyRun,(void))

::neash::Lib Lib_obj::mMe;

::neash::display::MovieClip Lib_obj::current;

Dynamic Lib_obj::parameters;

bool Lib_obj::debug;

bool Lib_obj::mShowCursor;

bool Lib_obj::mShowFPS;

::neash::display::DisplayObject Lib_obj::mDragObject;

::nme::geom::Rectangle Lib_obj::mDragRect;

double Lib_obj::mDragOffsetX;

double Lib_obj::mDragOffsetY;

bool Lib_obj::mOpenGL;

bool Lib_obj::mFullscreen;

bool Lib_obj::mCollectEveryFrame;

bool Lib_obj::mQuitOnEscape;

::neash::display::Stage Lib_obj::mStage;

::neash::display::MovieClip Lib_obj::mMainClassRoot;

::neash::display::MovieClip Lib_obj::mCurrent;

::neash::display::InteractiveObject Lib_obj::mRolling;

::neash::display::InteractiveObject Lib_obj::mDownObj;

::nme::geom::Point Lib_obj::mLastMouse;

bool Lib_obj::IsOpenGL( ){
	return ::neash::Lib_obj::mOpenGL;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(Lib_obj,IsOpenGL,return )

Void Lib_obj::ShowCursor( bool inShow){
{
		__SAFE_POINT
		::neash::Lib_obj::mShowCursor = inShow;
		::nme::Manager_obj::SetCursor(inShow ? int( 1 ) : int( 0 ));
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Lib_obj,ShowCursor,(void))

Void Lib_obj::SetTextCursor( bool inText){
{
		__SAFE_POINT
		if (inText){
			::nme::Manager_obj::SetCursor(2);
		}
		else{
			::nme::Manager_obj::SetCursor(::neash::Lib_obj::mShowCursor ? int( 1 ) : int( 0 ));
		}
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Lib_obj,SetTextCursor,(void))

Void Lib_obj::SetFrameRate( double inRate){
{
		::neash::Lib_obj::mStage->frameRate = inRate;
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Lib_obj,SetFrameRate,(void))

Dynamic Lib_obj::GetParameters( ){
	__SAFE_POINT
	struct _Function_1_1{
		inline static Dynamic Block( ){
			hx::Anon __result = hx::Anon_obj::Create();
			return __result;
		}
	};
	Dynamic result = _Function_1_1::Block();
	int param_id = 0;
	Array< ::String > args = ::cpp::Sys_obj::args();
	{
		int _g = 0;
		while((_g < args->length)){
			__SAFE_POINT
			::String arg = args->__get(_g);
			++_g;
			if ((arg.charAt(0) == HX_STRING(L"-",1))){
				int pos = arg.indexOf(HX_STRING(L"=",1),null());
				if ((pos > 0)){
					if ((result != null())){
						result->__SetField(arg.substr(1,(pos - 1)),arg.substr((pos + 1),null()));
					}
					else{
						{};
					}
				}
				else{
					if ((result != null())){
						result->__SetField(arg.substr(1,null()),true);
					}
					else{
						{};
					}
				}
			}
			else{
				::String name = (HX_STRING(L"param",5) + param_id);
				if ((result != null())){
					result->__SetField(name,arg);
				}
				else{
					{};
				}
			}
		}
	}
	return result;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(Lib_obj,GetParameters,return )

::neash::display::MovieClip Lib_obj::GetCurrent( ){
	return ::neash::Lib_obj::mMainClassRoot;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(Lib_obj,GetCurrent,return )

Void Lib_obj::ShowFPS( Dynamic inShow){
{
		::neash::Lib_obj::mShowFPS = (bool((inShow == null())) || bool(inShow));
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Lib_obj,ShowFPS,(void))

Void Lib_obj::SetBackgroundColour( int inColour){
{
		__SAFE_POINT
		::neash::Lib_obj::mStage->SetBackgroundColour(inColour);
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Lib_obj,SetBackgroundColour,(void))

Dynamic Lib_obj::as( Dynamic v,::Class c){
	return v;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(Lib_obj,as,return )

int Lib_obj::getTimer( ){
	__SAFE_POINT
	return (::__time_stamp() * 1000.0);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(Lib_obj,getTimer,return )

::neash::display::Stage Lib_obj::GetStage( ){
	return ::neash::Lib_obj::mStage;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(Lib_obj,GetStage,return )

Void Lib_obj::FireEvents( ::neash::events::Event inEvt,Array< ::neash::display::InteractiveObject > inList){
{
		__SAFE_POINT
		int l = inList->length;
		if ((l == 0))
			return null();
		inEvt->SetPhase(::neash::events::EventPhase_obj::CAPTURING_PHASE);
		{
			int _g1 = 0;
			int _g = (l - 1);
			while((_g1 < _g)){
				__SAFE_POINT
				int i = _g1++;
				::neash::display::InteractiveObject obj = inList->__get(i);
				inEvt->currentTarget = obj;
				obj->dispatchEvent(inEvt);
				if (inEvt->IsCancelled())
					return null();
			}
		}
		inEvt->SetPhase(::neash::events::EventPhase_obj::AT_TARGET);
		inEvt->currentTarget = inList->__get((l - 1));
		inList[(l - 1)]->dispatchEvent(inEvt);
		if (inEvt->IsCancelled())
			return null();
		if (inEvt->bubbles){
			inEvt->SetPhase(::neash::events::EventPhase_obj::BUBBLING_PHASE);
			int i = (l - 2);
			while((i >= 0)){
				__SAFE_POINT
				::neash::display::InteractiveObject obj = inList->__get(i);
				inEvt->currentTarget = obj;
				obj->dispatchEvent(inEvt);
				if (inEvt->IsCancelled())
					return null();
				--i;
			}
		}
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(Lib_obj,FireEvents,(void))

Void Lib_obj::SendEventToObject( ::neash::events::Event inEvent,::neash::display::InteractiveObject inObj){
{
		__SAFE_POINT
		Array< ::neash::display::InteractiveObject > objs = ::neash::Lib_obj::GetAnscestors(inObj);
		objs->reverse();
		::neash::Lib_obj::FireEvents(inEvent,objs);
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(Lib_obj,SendEventToObject,(void))

Array< ::neash::display::InteractiveObject > Lib_obj::GetAnscestors( ::neash::display::DisplayObject inObj){
	__SAFE_POINT
	Array< ::neash::display::InteractiveObject > result = Array_obj< ::neash::display::InteractiveObject >::__new();
	while((inObj != null())){
		__SAFE_POINT
		::neash::display::InteractiveObject interactive = inObj->AsInteractiveObject();
		if ((interactive != null()))
			result->push(interactive);
		inObj = inObj->GetParent();
	}
	result->reverse();
	return result;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Lib_obj,GetAnscestors,return )

Void Lib_obj::SetDragged( ::neash::display::DisplayObject inObj,Dynamic inCentre,::nme::geom::Rectangle inRect){
{
		__SAFE_POINT
		::neash::Lib_obj::mDragObject = inObj;
		::neash::Lib_obj::mDragRect = inRect;
		if ((::neash::Lib_obj::mDragObject != null())){
			if ((bool((inCentre != null())) && bool(inCentre))){
				::neash::Lib_obj::mDragOffsetX = (double(-inObj->GetWidth()) / double(2));
				::neash::Lib_obj::mDragOffsetY = (double(-inObj->GetHeight()) / double(2));
			}
			else{
				::nme::geom::Point mouse = ::nme::Manager_obj::GetMouse();
				hx::DivEq(mouse->x,::neash::Lib_obj::mStage->GetScaleX());
				hx::DivEq(mouse->y,::neash::Lib_obj::mStage->GetScaleY());
				::neash::display::DisplayObjectContainer p = ::neash::Lib_obj::mDragObject->GetParent();
				if ((p != null()))
					mouse = p->globalToLocal(mouse);
				::neash::Lib_obj::mDragOffsetX = (inObj->GetX() - mouse->x);
				::neash::Lib_obj::mDragOffsetY = (inObj->GetY() - mouse->y);
			}
		}
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC3(Lib_obj,SetDragged,(void))

Void Lib_obj::Run( ){
{
		__SAFE_POINT
		::neash::Lib_obj::mMe->MyRun();
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(Lib_obj,Run,(void))

Void Lib_obj::close( ){
{
		::neash::Lib_obj::mMe->mKilled = true;
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(Lib_obj,close,(void))

Void Lib_obj::Init( ::String inName,int inWidth,int inHeight,Dynamic inFullScreen,Dynamic inResizable,Dynamic cb){
{
		::neash::Lib_obj::mMe = ::neash::Lib_obj::__new(inName,inWidth,inHeight,inFullScreen,inResizable,cb);
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC6(Lib_obj,Init,(void))


Lib_obj::Lib_obj()
{
}

void Lib_obj::__Mark()
{
	hx::MarkMember(mKilled);
	hx::MarkMember(mRequestedWidth);
	hx::MarkMember(mRequestedHeight);
	hx::MarkMember(mResizePending);
	hx::MarkMember(mManager);
	hx::MarkMember(mArgs);
}

Dynamic Lib_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 2:
		if (!memcmp(inName.__s,L"as",sizeof(wchar_t)*2) ) { return as_dyn(); }
		break;
	case 3:
		if (!memcmp(inName.__s,L"mMe",sizeof(wchar_t)*3) ) { return mMe; }
		if (!memcmp(inName.__s,L"Run",sizeof(wchar_t)*3) ) { return Run_dyn(); }
		break;
	case 4:
		if (!memcmp(inName.__s,L"Init",sizeof(wchar_t)*4) ) { return Init_dyn(); }
		if (!memcmp(inName.__s,L"step",sizeof(wchar_t)*4) ) { return step_dyn(); }
		break;
	case 5:
		if (!memcmp(inName.__s,L"debug",sizeof(wchar_t)*5) ) { return debug; }
		if (!memcmp(inName.__s,L"close",sizeof(wchar_t)*5) ) { return close_dyn(); }
		if (!memcmp(inName.__s,L"mArgs",sizeof(wchar_t)*5) ) { return mArgs; }
		if (!memcmp(inName.__s,L"MyRun",sizeof(wchar_t)*5) ) { return MyRun_dyn(); }
		break;
	case 6:
		if (!memcmp(inName.__s,L"mStage",sizeof(wchar_t)*6) ) { return mStage; }
		break;
	case 7:
		if (!memcmp(inName.__s,L"current",sizeof(wchar_t)*7) ) { return GetCurrent(); }
		if (!memcmp(inName.__s,L"mOpenGL",sizeof(wchar_t)*7) ) { return mOpenGL; }
		if (!memcmp(inName.__s,L"ShowFPS",sizeof(wchar_t)*7) ) { return ShowFPS_dyn(); }
		if (!memcmp(inName.__s,L"mKilled",sizeof(wchar_t)*7) ) { return mKilled; }
		if (!memcmp(inName.__s,L"DoMouse",sizeof(wchar_t)*7) ) { return DoMouse_dyn(); }
		break;
	case 8:
		if (!memcmp(inName.__s,L"mShowFPS",sizeof(wchar_t)*8) ) { return mShowFPS; }
		if (!memcmp(inName.__s,L"mCurrent",sizeof(wchar_t)*8) ) { return mCurrent; }
		if (!memcmp(inName.__s,L"mRolling",sizeof(wchar_t)*8) ) { return mRolling; }
		if (!memcmp(inName.__s,L"mDownObj",sizeof(wchar_t)*8) ) { return mDownObj; }
		if (!memcmp(inName.__s,L"IsOpenGL",sizeof(wchar_t)*8) ) { return IsOpenGL_dyn(); }
		if (!memcmp(inName.__s,L"getTimer",sizeof(wchar_t)*8) ) { return getTimer_dyn(); }
		if (!memcmp(inName.__s,L"GetStage",sizeof(wchar_t)*8) ) { return GetStage_dyn(); }
		if (!memcmp(inName.__s,L"mManager",sizeof(wchar_t)*8) ) { return mManager; }
		if (!memcmp(inName.__s,L"OnResize",sizeof(wchar_t)*8) ) { return OnResize_dyn(); }
		break;
	case 9:
		if (!memcmp(inName.__s,L"mDragRect",sizeof(wchar_t)*9) ) { return mDragRect; }
		break;
	case 10:
		if (!memcmp(inName.__s,L"parameters",sizeof(wchar_t)*10) ) { return GetParameters(); }
		if (!memcmp(inName.__s,L"mLastMouse",sizeof(wchar_t)*10) ) { return mLastMouse; }
		if (!memcmp(inName.__s,L"ShowCursor",sizeof(wchar_t)*10) ) { return ShowCursor_dyn(); }
		if (!memcmp(inName.__s,L"GetCurrent",sizeof(wchar_t)*10) ) { return GetCurrent_dyn(); }
		if (!memcmp(inName.__s,L"FireEvents",sizeof(wchar_t)*10) ) { return FireEvents_dyn(); }
		if (!memcmp(inName.__s,L"SetDragged",sizeof(wchar_t)*10) ) { return SetDragged_dyn(); }
		if (!memcmp(inName.__s,L"DragObject",sizeof(wchar_t)*10) ) { return DragObject_dyn(); }
		break;
	case 11:
		if (!memcmp(inName.__s,L"mShowCursor",sizeof(wchar_t)*11) ) { return mShowCursor; }
		if (!memcmp(inName.__s,L"mDragObject",sizeof(wchar_t)*11) ) { return mDragObject; }
		if (!memcmp(inName.__s,L"mFullscreen",sizeof(wchar_t)*11) ) { return mFullscreen; }
		if (!memcmp(inName.__s,L"ProcessKeys",sizeof(wchar_t)*11) ) { return ProcessKeys_dyn(); }
		break;
	case 12:
		if (!memcmp(inName.__s,L"mDragOffsetX",sizeof(wchar_t)*12) ) { return mDragOffsetX; }
		if (!memcmp(inName.__s,L"mDragOffsetY",sizeof(wchar_t)*12) ) { return mDragOffsetY; }
		if (!memcmp(inName.__s,L"SetFrameRate",sizeof(wchar_t)*12) ) { return SetFrameRate_dyn(); }
		break;
	case 13:
		if (!memcmp(inName.__s,L"mQuitOnEscape",sizeof(wchar_t)*13) ) { return mQuitOnEscape; }
		if (!memcmp(inName.__s,L"SetTextCursor",sizeof(wchar_t)*13) ) { return SetTextCursor_dyn(); }
		if (!memcmp(inName.__s,L"GetParameters",sizeof(wchar_t)*13) ) { return GetParameters_dyn(); }
		if (!memcmp(inName.__s,L"GetAnscestors",sizeof(wchar_t)*13) ) { return GetAnscestors_dyn(); }
		break;
	case 14:
		if (!memcmp(inName.__s,L"mMainClassRoot",sizeof(wchar_t)*14) ) { return mMainClassRoot; }
		if (!memcmp(inName.__s,L"mResizePending",sizeof(wchar_t)*14) ) { return mResizePending; }
		break;
	case 15:
		if (!memcmp(inName.__s,L"mRequestedWidth",sizeof(wchar_t)*15) ) { return mRequestedWidth; }
		break;
	case 16:
		if (!memcmp(inName.__s,L"mRequestedHeight",sizeof(wchar_t)*16) ) { return mRequestedHeight; }
		if (!memcmp(inName.__s,L"CreateMouseEvent",sizeof(wchar_t)*16) ) { return CreateMouseEvent_dyn(); }
		break;
	case 17:
		if (!memcmp(inName.__s,L"SendEventToObject",sizeof(wchar_t)*17) ) { return SendEventToObject_dyn(); }
		break;
	case 18:
		if (!memcmp(inName.__s,L"mCollectEveryFrame",sizeof(wchar_t)*18) ) { return mCollectEveryFrame; }
		break;
	case 19:
		if (!memcmp(inName.__s,L"SetBackgroundColour",sizeof(wchar_t)*19) ) { return SetBackgroundColour_dyn(); }
		break;
	case 25:
		if (!memcmp(inName.__s,L"GetInteractiveObjectAtPos",sizeof(wchar_t)*25) ) { return GetInteractiveObjectAtPos_dyn(); }
	}
	return super::__Field(inName);
}

Dynamic Lib_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	switch(inName.length) {
	case 3:
		if (!memcmp(inName.__s,L"mMe",sizeof(wchar_t)*3) ) { mMe=inValue.Cast< ::neash::Lib >(); return inValue; }
		break;
	case 5:
		if (!memcmp(inName.__s,L"debug",sizeof(wchar_t)*5) ) { debug=inValue.Cast< bool >(); return inValue; }
		if (!memcmp(inName.__s,L"mArgs",sizeof(wchar_t)*5) ) { mArgs=inValue.Cast< Array< ::String > >(); return inValue; }
		break;
	case 6:
		if (!memcmp(inName.__s,L"mStage",sizeof(wchar_t)*6) ) { mStage=inValue.Cast< ::neash::display::Stage >(); return inValue; }
		break;
	case 7:
		if (!memcmp(inName.__s,L"current",sizeof(wchar_t)*7) ) { current=inValue.Cast< ::neash::display::MovieClip >(); return inValue; }
		if (!memcmp(inName.__s,L"mOpenGL",sizeof(wchar_t)*7) ) { mOpenGL=inValue.Cast< bool >(); return inValue; }
		if (!memcmp(inName.__s,L"mKilled",sizeof(wchar_t)*7) ) { mKilled=inValue.Cast< bool >(); return inValue; }
		break;
	case 8:
		if (!memcmp(inName.__s,L"mShowFPS",sizeof(wchar_t)*8) ) { mShowFPS=inValue.Cast< bool >(); return inValue; }
		if (!memcmp(inName.__s,L"mCurrent",sizeof(wchar_t)*8) ) { mCurrent=inValue.Cast< ::neash::display::MovieClip >(); return inValue; }
		if (!memcmp(inName.__s,L"mRolling",sizeof(wchar_t)*8) ) { mRolling=inValue.Cast< ::neash::display::InteractiveObject >(); return inValue; }
		if (!memcmp(inName.__s,L"mDownObj",sizeof(wchar_t)*8) ) { mDownObj=inValue.Cast< ::neash::display::InteractiveObject >(); return inValue; }
		if (!memcmp(inName.__s,L"mManager",sizeof(wchar_t)*8) ) { mManager=inValue.Cast< ::nme::Manager >(); return inValue; }
		break;
	case 9:
		if (!memcmp(inName.__s,L"mDragRect",sizeof(wchar_t)*9) ) { mDragRect=inValue.Cast< ::nme::geom::Rectangle >(); return inValue; }
		break;
	case 10:
		if (!memcmp(inName.__s,L"parameters",sizeof(wchar_t)*10) ) { parameters=inValue.Cast< Dynamic >(); return inValue; }
		if (!memcmp(inName.__s,L"mLastMouse",sizeof(wchar_t)*10) ) { mLastMouse=inValue.Cast< ::nme::geom::Point >(); return inValue; }
		break;
	case 11:
		if (!memcmp(inName.__s,L"mShowCursor",sizeof(wchar_t)*11) ) { mShowCursor=inValue.Cast< bool >(); return inValue; }
		if (!memcmp(inName.__s,L"mDragObject",sizeof(wchar_t)*11) ) { mDragObject=inValue.Cast< ::neash::display::DisplayObject >(); return inValue; }
		if (!memcmp(inName.__s,L"mFullscreen",sizeof(wchar_t)*11) ) { mFullscreen=inValue.Cast< bool >(); return inValue; }
		break;
	case 12:
		if (!memcmp(inName.__s,L"mDragOffsetX",sizeof(wchar_t)*12) ) { mDragOffsetX=inValue.Cast< double >(); return inValue; }
		if (!memcmp(inName.__s,L"mDragOffsetY",sizeof(wchar_t)*12) ) { mDragOffsetY=inValue.Cast< double >(); return inValue; }
		break;
	case 13:
		if (!memcmp(inName.__s,L"mQuitOnEscape",sizeof(wchar_t)*13) ) { mQuitOnEscape=inValue.Cast< bool >(); return inValue; }
		break;
	case 14:
		if (!memcmp(inName.__s,L"mMainClassRoot",sizeof(wchar_t)*14) ) { mMainClassRoot=inValue.Cast< ::neash::display::MovieClip >(); return inValue; }
		if (!memcmp(inName.__s,L"mResizePending",sizeof(wchar_t)*14) ) { mResizePending=inValue.Cast< bool >(); return inValue; }
		break;
	case 15:
		if (!memcmp(inName.__s,L"mRequestedWidth",sizeof(wchar_t)*15) ) { mRequestedWidth=inValue.Cast< int >(); return inValue; }
		break;
	case 16:
		if (!memcmp(inName.__s,L"mRequestedHeight",sizeof(wchar_t)*16) ) { mRequestedHeight=inValue.Cast< int >(); return inValue; }
		break;
	case 18:
		if (!memcmp(inName.__s,L"mCollectEveryFrame",sizeof(wchar_t)*18) ) { mCollectEveryFrame=inValue.Cast< bool >(); return inValue; }
	}
	return super::__SetField(inName,inValue);
}

void Lib_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_STRING(L"mKilled",7));
	outFields->push(HX_STRING(L"mRequestedWidth",15));
	outFields->push(HX_STRING(L"mRequestedHeight",16));
	outFields->push(HX_STRING(L"mResizePending",14));
	outFields->push(HX_STRING(L"mManager",8));
	outFields->push(HX_STRING(L"mArgs",5));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_STRING(L"mMe",3),
	HX_STRING(L"current",7),
	HX_STRING(L"parameters",10),
	HX_STRING(L"debug",5),
	HX_STRING(L"mShowCursor",11),
	HX_STRING(L"mShowFPS",8),
	HX_STRING(L"mDragObject",11),
	HX_STRING(L"mDragRect",9),
	HX_STRING(L"mDragOffsetX",12),
	HX_STRING(L"mDragOffsetY",12),
	HX_STRING(L"mOpenGL",7),
	HX_STRING(L"mFullscreen",11),
	HX_STRING(L"mCollectEveryFrame",18),
	HX_STRING(L"mQuitOnEscape",13),
	HX_STRING(L"mStage",6),
	HX_STRING(L"mMainClassRoot",14),
	HX_STRING(L"mCurrent",8),
	HX_STRING(L"mRolling",8),
	HX_STRING(L"mDownObj",8),
	HX_STRING(L"mLastMouse",10),
	HX_STRING(L"IsOpenGL",8),
	HX_STRING(L"ShowCursor",10),
	HX_STRING(L"SetTextCursor",13),
	HX_STRING(L"SetFrameRate",12),
	HX_STRING(L"GetParameters",13),
	HX_STRING(L"GetCurrent",10),
	HX_STRING(L"ShowFPS",7),
	HX_STRING(L"SetBackgroundColour",19),
	HX_STRING(L"as",2),
	HX_STRING(L"getTimer",8),
	HX_STRING(L"GetStage",8),
	HX_STRING(L"FireEvents",10),
	HX_STRING(L"SendEventToObject",17),
	HX_STRING(L"GetAnscestors",13),
	HX_STRING(L"SetDragged",10),
	HX_STRING(L"Run",3),
	HX_STRING(L"close",5),
	HX_STRING(L"Init",4),
	String(null()) };

static ::String sMemberFields[] = {
	HX_STRING(L"mKilled",7),
	HX_STRING(L"mRequestedWidth",15),
	HX_STRING(L"mRequestedHeight",16),
	HX_STRING(L"mResizePending",14),
	HX_STRING(L"mManager",8),
	HX_STRING(L"mArgs",5),
	HX_STRING(L"OnResize",8),
	HX_STRING(L"ProcessKeys",11),
	HX_STRING(L"CreateMouseEvent",16),
	HX_STRING(L"GetInteractiveObjectAtPos",25),
	HX_STRING(L"DragObject",10),
	HX_STRING(L"DoMouse",7),
	HX_STRING(L"step",4),
	HX_STRING(L"MyRun",5),
	String(null()) };

static void sMarkStatics() {
	hx::MarkMember(Lib_obj::mMe);
	hx::MarkMember(Lib_obj::current);
	hx::MarkMember(Lib_obj::parameters);
	hx::MarkMember(Lib_obj::debug);
	hx::MarkMember(Lib_obj::mShowCursor);
	hx::MarkMember(Lib_obj::mShowFPS);
	hx::MarkMember(Lib_obj::mDragObject);
	hx::MarkMember(Lib_obj::mDragRect);
	hx::MarkMember(Lib_obj::mDragOffsetX);
	hx::MarkMember(Lib_obj::mDragOffsetY);
	hx::MarkMember(Lib_obj::mOpenGL);
	hx::MarkMember(Lib_obj::mFullscreen);
	hx::MarkMember(Lib_obj::mCollectEveryFrame);
	hx::MarkMember(Lib_obj::mQuitOnEscape);
	hx::MarkMember(Lib_obj::mStage);
	hx::MarkMember(Lib_obj::mMainClassRoot);
	hx::MarkMember(Lib_obj::mCurrent);
	hx::MarkMember(Lib_obj::mRolling);
	hx::MarkMember(Lib_obj::mDownObj);
	hx::MarkMember(Lib_obj::mLastMouse);
};

Class Lib_obj::__mClass;

void Lib_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_STRING(L"neash.Lib",9), hx::TCanCast< Lib_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void Lib_obj::__boot()
{
	hx::Static(mMe);
	hx::Static(current);
	hx::Static(parameters);
	hx::Static(debug) = false;
	hx::Static(mShowCursor) = true;
	hx::Static(mShowFPS) = false;
	hx::Static(mDragObject) = null();
	hx::Static(mDragRect) = null();
	hx::Static(mDragOffsetX) = 0;
	hx::Static(mDragOffsetY) = 0;
	hx::Static(mOpenGL) = false;
	hx::Static(mFullscreen) = false;
	hx::Static(mCollectEveryFrame) = false;
	hx::Static(mQuitOnEscape) = true;
	hx::Static(mStage);
	hx::Static(mMainClassRoot);
	hx::Static(mCurrent);
	hx::Static(mRolling);
	hx::Static(mDownObj);
	hx::Static(mLastMouse) = ::nme::geom::Point_obj::__new(null(),null());
}

} // end namespace neash
