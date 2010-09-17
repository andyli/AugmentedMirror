#include <hxcpp.h>

#ifndef INCLUDED_List
#include <List.h>
#endif
#ifndef INCLUDED_haxe_Timer
#include <haxe/Timer.h>
#endif
#ifndef INCLUDED_nme_EventType
#include <nme/EventType.h>
#endif
#ifndef INCLUDED_nme_KeyCode
#include <nme/KeyCode.h>
#endif
#ifndef INCLUDED_nme_Loader
#include <nme/Loader.h>
#endif
#ifndef INCLUDED_nme_Manager
#include <nme/Manager.h>
#endif
#ifndef INCLUDED_nme_MouseEventType
#include <nme/MouseEventType.h>
#endif
#ifndef INCLUDED_nme_Rect
#include <nme/Rect.h>
#endif
#ifndef INCLUDED_nme_Sound
#include <nme/Sound.h>
#endif
#ifndef INCLUDED_nme_Time
#include <nme/Time.h>
#endif
#ifndef INCLUDED_nme_Timer
#include <nme/Timer.h>
#endif
#ifndef INCLUDED_nme_display_CapsStyle
#include <nme/display/CapsStyle.h>
#endif
#ifndef INCLUDED_nme_display_Graphics
#include <nme/display/Graphics.h>
#endif
#ifndef INCLUDED_nme_display_JointStyle
#include <nme/display/JointStyle.h>
#endif
#ifndef INCLUDED_nme_display_LineScaleMode
#include <nme/display/LineScaleMode.h>
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
namespace nme{

Void Manager_obj::__construct(int width,int height,::String title,bool fullscreen,::String icon,Dynamic opengl,Dynamic resizable,Dynamic __o_hardware,Dynamic __o_vsync)
{
bool hardware = __o_hardware.Default(false);
bool vsync = __o_vsync.Default(false);
{
	int flags = 0;
	if (fullscreen)
		hx::AddEq(flags,::nme::Manager_obj::FULLSCREEN);
	if ((bool((opengl != null())) && bool(opengl))){
		hx::AddEq(flags,::nme::Manager_obj::OPENGL);
	}
	else{
		if ((bool((hardware != null())) && bool(hardware)))
			hx::AddEq(flags,::nme::Manager_obj::HARDWARE);
	}
	if ((bool((resizable != null())) && bool(resizable)))
		hx::AddEq(flags,::nme::Manager_obj::RESIZABLE);
	if (vsync)
		hx::AddEq(flags,::nme::Manager_obj::VSYNC);
	if ((bool((width < 100)) || bool((height < 20))))
		return null();
	::nme::Manager_obj::__scr = ::nme::Manager_obj::nme_screen_init(width,height,title,flags,icon);
	::nme::Manager_obj::graphics = ::nme::display::Graphics_obj::__new(::nme::Manager_obj::__scr);
	this->mainLoopRunning = false;
	this->mouseEventCallbacks = Array_obj< Dynamic >::__new();
	this->mouseClickCallbacks = Array_obj< Dynamic >::__new();
	this->keyEventCallbacks = Array_obj< Dynamic >::__new();
	this->updateCallbacks = Array_obj< Dynamic >::__new();
	this->renderCallbacks = Array_obj< Dynamic >::__new();
	this->tryQuitFunction = null();
	this->mPaused = false;
	this->mT0 = ::haxe::Timer_obj::stamp();
}
;
	return null();
}

Manager_obj::~Manager_obj() { }

Dynamic Manager_obj::__CreateEmpty() { return  new Manager_obj; }
hx::ObjectPtr< Manager_obj > Manager_obj::__new(int width,int height,::String title,bool fullscreen,::String icon,Dynamic opengl,Dynamic resizable,Dynamic __o_hardware,Dynamic __o_vsync)
{  hx::ObjectPtr< Manager_obj > result = new Manager_obj();
	result->__construct(width,height,title,fullscreen,icon,opengl,resizable,__o_hardware,__o_vsync);
	return result;}

Dynamic Manager_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Manager_obj > result = new Manager_obj();
	result->__construct(inArgs[0],inArgs[1],inArgs[2],inArgs[3],inArgs[4],inArgs[5],inArgs[6],inArgs[7],inArgs[8]);
	return result;}

Void Manager_obj::OnResize( int inW,int inH){
{
		__SAFE_POINT
		::nme::Manager_obj::__scr = ::nme::Manager_obj::nme_resize_surface(inW,inH);
		::nme::Manager_obj::graphics->SetSurface(::nme::Manager_obj::__scr);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(Manager_obj,OnResize,(void))

Void Manager_obj::mainLoop( ){
{
		__SAFE_POINT
		this->mainLoopRunning = true;
		bool left = false;
		double last_update = 0.0;
		while(this->mainLoopRunning){
			__SAFE_POINT
			::nme::EventType type;
			do{
				type = this->nextEvent();
				::nme::EventType _switch_1 = type;
				switch((_switch_1)->GetIndex()){
					case 12: {
						this->tryQuit();
					}
					;break;
					case 2: {
						if ((this->lastKey() == ::nme::Manager_obj::closeKey)){
							this->tryQuit();
						}
						else{
							this->fireKeyEvent(true);
						}
					}
					;break;
					case 3: {
						this->fireKeyEvent(false);
					}
					;break;
					case 5: {
						struct _Function_4_1{
							inline static Dynamic Block( )/* DEF (ret block)(not intern) */{
								Dynamic o = ::nme::Manager_obj::__evt;
								return ((o == null())) ? Dynamic( null() ) : Dynamic( o->__Field(HX_STRING(L"button",6)) );
							}
						};
						switch( (int)(_Function_4_1::Block())){
							case 1: {
								this->fireMouseEvent(::nme::MouseEventType_obj::met_LeftDown);
							}
							;break;
							case 2: {
								this->fireMouseEvent(::nme::MouseEventType_obj::met_MiddleDown);
							}
							;break;
							case 3: {
								this->fireMouseEvent(::nme::MouseEventType_obj::met_RightDown);
							}
							;break;
							case 4: {
								this->fireMouseEvent(::nme::MouseEventType_obj::met_MouseWheelUp);
							}
							;break;
							case 5: {
								this->fireMouseEvent(::nme::MouseEventType_obj::met_MouseWheelDown);
							}
							;break;
						}
					}
					;break;
					case 6: {
						struct _Function_4_1{
							inline static Dynamic Block( )/* DEF (ret block)(not intern) */{
								Dynamic o = ::nme::Manager_obj::__evt;
								return ((o == null())) ? Dynamic( null() ) : Dynamic( o->__Field(HX_STRING(L"button",6)) );
							}
						};
						switch( (int)(_Function_4_1::Block())){
							case 1: {
								this->fireMouseEvent(::nme::MouseEventType_obj::met_LeftUp);
							}
							;break;
							case 2: {
								this->fireMouseEvent(::nme::MouseEventType_obj::met_MiddleUp);
							}
							;break;
							case 3: {
								this->fireMouseEvent(::nme::MouseEventType_obj::met_RightUp);
							}
							;break;
						}
					}
					;break;
					case 4: {
						this->fireMouseEvent(::nme::MouseEventType_obj::met_Move);
					}
					;break;
					case 15: {
						struct _Function_4_1{
							inline static Dynamic Block( )/* DEF (ret block)(not intern) */{
								Dynamic o = ::nme::Manager_obj::__evt;
								return ((o == null())) ? Dynamic( null() ) : Dynamic( o->__Field(HX_STRING(L"channel",7)) );
							}
						};
						if ((::nme::Sound_obj::onChannelFinished_dyn() != null()))
							::nme::Sound_obj::onChannelFinished(_Function_4_1::Block());
					}
					;break;
					case 11: {
						{};
					}
					;break;
					default: {
					}
				}
			}
while((bool((type != ::nme::EventType_obj::et_noevent)) && bool(this->mainLoopRunning)));
			double t = ::haxe::Timer_obj::stamp();
			double dt = (t - last_update);
			if ((last_update == 0))
				dt = 0;
			last_update = t;
			if (!this->mPaused){
				{
					int _g = 0;
					Array< Dynamic > _g1 = this->updateCallbacks;
					while((_g < _g1->length)){
						__SAFE_POINT
						Dynamic f = _g1->__get(_g);
						++_g;
						f(dt);
					}
				}
			}
			{
				int _g = 0;
				Array< Dynamic > _g1 = this->renderCallbacks;
				while((_g < _g1->length)){
					__SAFE_POINT
					Dynamic f = _g1->__get(_g);
					++_g;
					f();
				}
			}
			::nme::Timer_obj::check();
			this->flip();
		}
		::nme::Manager_obj::nme_screen_close();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Manager_obj,mainLoop,(void))

Void Manager_obj::ResetFPS( ){
{
		__SAFE_POINT
		this->mT0 = ::haxe::Timer_obj::stamp();
		::nme::Manager_obj::mFrameCountStack = Array_obj< double >::__new();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Manager_obj,ResetFPS,(void))

Void Manager_obj::RenderFPS( ){
{
		__SAFE_POINT
		double t = (::haxe::Timer_obj::stamp() - this->mT0);
		int n = ::nme::Manager_obj::mFrameCountStack->length;
		::nme::Manager_obj::mFrameCountStack[n] = t;
		while((::nme::Manager_obj::mFrameCountStack->__get(0) < ((t - 1))))::nme::Manager_obj::mFrameCountStack->shift();
		::nme::Manager_obj::graphics->lineStyle(1,0,null(),null(),null(),null(),null(),null());
		::String text = (HX_STRING(L"FPS:",4) + ::nme::Manager_obj::mFrameCountStack->length);
		::nme::Manager_obj::graphics->moveTo(10,30);
		::nme::Manager_obj::graphics->text(text,12,null(),16777215,null(),null());
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Manager_obj,RenderFPS,(void))

Void Manager_obj::tryQuit( ){
{
		__SAFE_POINT
		if ((bool((this->tryQuitFunction_dyn() == null())) || bool(this->tryQuitFunction())))
			this->mainLoopRunning = false;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Manager_obj,tryQuit,(void))

Void Manager_obj::fireMouseEvent( ::nme::MouseEventType inType){
{
		__SAFE_POINT
		Dynamic event = ::nme::Manager_obj::mouseEvent(inType);
		{
			int _g = 0;
			Array< Dynamic > _g1 = this->mouseEventCallbacks;
			while((_g < _g1->length)){
				__SAFE_POINT
				Dynamic e = _g1->__get(_g);
				++_g;
				e(event);
			}
		}
		if ((inType == ::nme::MouseEventType_obj::met_LeftDown)){
			int _g = 0;
			Array< Dynamic > _g1 = this->mouseClickCallbacks;
			while((_g < _g1->length)){
				__SAFE_POINT
				Dynamic e = _g1->__get(_g);
				++_g;
				e(event);
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Manager_obj,fireMouseEvent,(void))

Void Manager_obj::fireKeyEvent( bool inIsDown){
{
		__SAFE_POINT
		struct _Function_1_1{
			inline static Dynamic Block( bool &inIsDown,::nme::Manager_obj *__this){
				hx::Anon __result = hx::Anon_obj::Create();
				__result->Add(HX_STRING(L"isDown",6) , inIsDown);
				__result->Add(HX_STRING(L"code",4) , __this->lastKey());
				__result->Add(HX_STRING(L"shift",5) , __this->lastKeyShift());
				__result->Add(HX_STRING(L"ctrl",4) , __this->lastKeyCtrl());
				__result->Add(HX_STRING(L"alt",3) , __this->lastKeyAlt());
				return __result;
			}
		};
		Dynamic event = _Function_1_1::Block(inIsDown,this);
		if ((bool(inIsDown) && bool((event->__Field(HX_STRING(L"code",4)).Cast< int >() == ::nme::Manager_obj::pauseUpdates)))){
			this->mPaused = !this->mPaused;
		}
		else{
			if ((bool(inIsDown) && bool((event->__Field(HX_STRING(L"code",4)).Cast< int >() == ::nme::Manager_obj::toggleQuality))))
				::nme::Manager_obj::nme_set_draw_quality((int(((::nme::Manager_obj::get_draw_quality() + 1))) & int(1)));
		}
		{
			int _g = 0;
			Array< Dynamic > _g1 = this->keyEventCallbacks;
			while((_g < _g1->length)){
				__SAFE_POINT
				Dynamic e = _g1->__get(_g);
				++_g;
				e(event);
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Manager_obj,fireKeyEvent,(void))

Void Manager_obj::addMouseCallback( Dynamic inCallback){
{
		__SAFE_POINT
		this->mouseEventCallbacks->push(inCallback);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Manager_obj,addMouseCallback,(void))

Void Manager_obj::addClickCallback( Dynamic inCallback){
{
		__SAFE_POINT
		this->mouseClickCallbacks->push(inCallback);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Manager_obj,addClickCallback,(void))

Void Manager_obj::addKeyCallback( Dynamic inCallback){
{
		__SAFE_POINT
		this->keyEventCallbacks->push(inCallback);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Manager_obj,addKeyCallback,(void))

Void Manager_obj::addRenderCallback( Dynamic inCallback){
{
		__SAFE_POINT
		this->renderCallbacks->push(inCallback);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Manager_obj,addRenderCallback,(void))

Void Manager_obj::addUpdateCallback( Dynamic inCallback){
{
		__SAFE_POINT
		this->updateCallbacks->push(inCallback);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Manager_obj,addUpdateCallback,(void))

Void Manager_obj::close( ){
{
		__SAFE_POINT
		if (this->mainLoopRunning){
			this->mainLoopRunning = false;
		}
		else{
			::nme::Manager_obj::nme_screen_close();
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Manager_obj,close,(void))

Void Manager_obj::delay( int period){
{
		__SAFE_POINT
		if ((period < 0))
			return null();
		::nme::Manager_obj::nme_delay(period);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Manager_obj,delay,(void))

Void Manager_obj::clear( int color){
{
		__SAFE_POINT
		::nme::Manager_obj::nme_surface_clear(::nme::Manager_obj::__scr,color);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Manager_obj,clear,(void))

Void Manager_obj::flip( ){
{
		__SAFE_POINT
		::nme::Manager_obj::graphics->flush();
		::nme::Manager_obj::nme_flipbuffer(::nme::Manager_obj::__scr);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Manager_obj,flip,(void))

Void Manager_obj::events( ){
{
		__SAFE_POINT
		::nme::Manager_obj::__evt = ::nme::Manager_obj::nme_event();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Manager_obj,events,(void))

::nme::EventType Manager_obj::nextEvent( ){
	__SAFE_POINT
	::nme::Manager_obj::__evt = ::nme::Manager_obj::nme_event();
	return this->getEventType();
}


HX_DEFINE_DYNAMIC_FUNC0(Manager_obj,nextEvent,return )

Dynamic Manager_obj::getNextEvent( ){
	__SAFE_POINT
	::nme::Manager_obj::__evt = ::nme::Manager_obj::nme_event();
	return ::nme::Manager_obj::__evt;
}


HX_DEFINE_DYNAMIC_FUNC0(Manager_obj,getNextEvent,return )

::nme::EventType Manager_obj::getEventType( ){
	__SAFE_POINT
	::nme::EventType returnType = ::nme::EventType_obj::et_noevent;
	struct _Function_1_1{
		inline static Dynamic Block( )/* DEF (ret block)(not intern) */{
			Dynamic o = ::nme::Manager_obj::__evt;
			return ((o == null())) ? Dynamic( null() ) : Dynamic( o->__Field(HX_STRING(L"type",4)) );
		}
	};
	switch( (int)_Function_1_1::Block()){
		case -1: {
			returnType = ::nme::EventType_obj::et_noevent;
		}
		;break;
		case 0: {
			returnType = ::nme::EventType_obj::et_active;
		}
		;break;
		case 1: {
			returnType = ::nme::EventType_obj::et_keydown;
		}
		;break;
		case 2: {
			returnType = ::nme::EventType_obj::et_keyup;
		}
		;break;
		case 3: {
			returnType = ::nme::EventType_obj::et_mousemove;
		}
		;break;
		case 4: {
			returnType = ::nme::EventType_obj::et_mousebutton_down;
		}
		;break;
		case 5: {
			returnType = ::nme::EventType_obj::et_mousebutton_up;
		}
		;break;
		case 6: {
			returnType = ::nme::EventType_obj::et_joystickmove;
		}
		;break;
		case 7: {
			returnType = ::nme::EventType_obj::et_joystickball;
		}
		;break;
		case 8: {
			returnType = ::nme::EventType_obj::et_joystickhat;
		}
		;break;
		case 9: {
			returnType = ::nme::EventType_obj::et_joystickbutton;
		}
		;break;
		case 10: {
			returnType = ::nme::EventType_obj::et_resize;
		}
		;break;
		case 11: {
			returnType = ::nme::EventType_obj::et_quit;
		}
		;break;
		case 12: {
			returnType = ::nme::EventType_obj::et_user;
		}
		;break;
		case 13: {
			returnType = ::nme::EventType_obj::et_syswm;
		}
		;break;
		case 14: {
			returnType = ::nme::EventType_obj::et_soundfinished;
		}
		;break;
	}
	return returnType;
}


HX_DEFINE_DYNAMIC_FUNC0(Manager_obj,getEventType,return )

bool Manager_obj::clickRect( int x,int y,::nme::Rect rect){
	if ((bool(((x < rect->x))) || bool((bool(((x > (rect->x + rect->w)))) || bool((bool(((y < rect->y))) || bool(((y > (rect->y + rect->h))))))))))
		return false;
	return true;
}


HX_DEFINE_DYNAMIC_FUNC3(Manager_obj,clickRect,return )

int Manager_obj::lastKey( ){
	__SAFE_POINT
	struct _Function_1_1{
		inline static Dynamic Block( )/* DEF (ret block)(not intern) */{
			Dynamic o = ::nme::Manager_obj::__evt;
			return ((o == null())) ? Dynamic( null() ) : Dynamic( o->__Field(HX_STRING(L"key",3)) );
		}
	};
	return _Function_1_1::Block();
}


HX_DEFINE_DYNAMIC_FUNC0(Manager_obj,lastKey,return )

int Manager_obj::lastChar( ){
	__SAFE_POINT
	struct _Function_1_1{
		inline static Dynamic Block( )/* DEF (ret block)(not intern) */{
			Dynamic o = ::nme::Manager_obj::__evt;
			return ((o == null())) ? Dynamic( null() ) : Dynamic( o->__Field(HX_STRING(L"char",4)) );
		}
	};
	return _Function_1_1::Block();
}


HX_DEFINE_DYNAMIC_FUNC0(Manager_obj,lastChar,return )

bool Manager_obj::lastKeyShift( ){
	__SAFE_POINT
	struct _Function_1_1{
		inline static Dynamic Block( )/* DEF (ret block)(not intern) */{
			Dynamic o = ::nme::Manager_obj::__evt;
			return ((o == null())) ? Dynamic( null() ) : Dynamic( o->__Field(HX_STRING(L"shift",5)) );
		}
	};
	return _Function_1_1::Block();
}


HX_DEFINE_DYNAMIC_FUNC0(Manager_obj,lastKeyShift,return )

bool Manager_obj::lastKeyCtrl( ){
	__SAFE_POINT
	struct _Function_1_1{
		inline static Dynamic Block( )/* DEF (ret block)(not intern) */{
			Dynamic o = ::nme::Manager_obj::__evt;
			return ((o == null())) ? Dynamic( null() ) : Dynamic( o->__Field(HX_STRING(L"ctrl",4)) );
		}
	};
	return _Function_1_1::Block();
}


HX_DEFINE_DYNAMIC_FUNC0(Manager_obj,lastKeyCtrl,return )

bool Manager_obj::lastKeyAlt( ){
	__SAFE_POINT
	struct _Function_1_1{
		inline static Dynamic Block( )/* DEF (ret block)(not intern) */{
			Dynamic o = ::nme::Manager_obj::__evt;
			return ((o == null())) ? Dynamic( null() ) : Dynamic( o->__Field(HX_STRING(L"alt",3)) );
		}
	};
	return _Function_1_1::Block();
}


HX_DEFINE_DYNAMIC_FUNC0(Manager_obj,lastKeyAlt,return )

int Manager_obj::mouseButton( ){
	__SAFE_POINT
	struct _Function_1_1{
		inline static Dynamic Block( )/* DEF (ret block)(not intern) */{
			Dynamic o = ::nme::Manager_obj::__evt;
			return ((o == null())) ? Dynamic( null() ) : Dynamic( o->__Field(HX_STRING(L"button",6)) );
		}
	};
	return _Function_1_1::Block();
}


HX_DEFINE_DYNAMIC_FUNC0(Manager_obj,mouseButton,return )

int Manager_obj::mouseX( ){
	__SAFE_POINT
	struct _Function_1_1{
		inline static Dynamic Block( )/* DEF (ret block)(not intern) */{
			Dynamic o = ::nme::Manager_obj::__evt;
			return ((o == null())) ? Dynamic( null() ) : Dynamic( o->__Field(HX_STRING(L"x",1)) );
		}
	};
	return _Function_1_1::Block();
}


HX_DEFINE_DYNAMIC_FUNC0(Manager_obj,mouseX,return )

int Manager_obj::mouseY( ){
	__SAFE_POINT
	struct _Function_1_1{
		inline static Dynamic Block( )/* DEF (ret block)(not intern) */{
			Dynamic o = ::nme::Manager_obj::__evt;
			return ((o == null())) ? Dynamic( null() ) : Dynamic( o->__Field(HX_STRING(L"y",1)) );
		}
	};
	return _Function_1_1::Block();
}


HX_DEFINE_DYNAMIC_FUNC0(Manager_obj,mouseY,return )

int Manager_obj::mouseMoveX( ){
	__SAFE_POINT
	struct _Function_1_1{
		inline static Dynamic Block( )/* DEF (ret block)(not intern) */{
			Dynamic o = ::nme::Manager_obj::__evt;
			return ((o == null())) ? Dynamic( null() ) : Dynamic( o->__Field(HX_STRING(L"xrel",4)) );
		}
	};
	return _Function_1_1::Block();
}


HX_DEFINE_DYNAMIC_FUNC0(Manager_obj,mouseMoveX,return )

int Manager_obj::mouseMoveY( ){
	__SAFE_POINT
	struct _Function_1_1{
		inline static Dynamic Block( )/* DEF (ret block)(not intern) */{
			Dynamic o = ::nme::Manager_obj::__evt;
			return ((o == null())) ? Dynamic( null() ) : Dynamic( o->__Field(HX_STRING(L"yrel",4)) );
		}
	};
	return _Function_1_1::Block();
}


HX_DEFINE_DYNAMIC_FUNC0(Manager_obj,mouseMoveY,return )

Dynamic Manager_obj::__scr;

Dynamic Manager_obj::__evt;

int Manager_obj::closeKey;

int Manager_obj::pauseUpdates;

int Manager_obj::toggleQuality;

int Manager_obj::FULLSCREEN;

int Manager_obj::OPENGL;

int Manager_obj::RESIZABLE;

int Manager_obj::HARDWARE;

int Manager_obj::VSYNC;

::nme::display::Graphics Manager_obj::graphics;

int Manager_obj::draw_quality;

Array< double > Manager_obj::mFrameCountStack;

int Manager_obj::getWindowWidth( ){
	__SAFE_POINT
	return ::nme::Manager_obj::nme_surface_width(::nme::Manager_obj::__scr);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(Manager_obj,getWindowWidth,return )

int Manager_obj::getWindowHeight( ){
	__SAFE_POINT
	return ::nme::Manager_obj::nme_surface_height(::nme::Manager_obj::__scr);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(Manager_obj,getWindowHeight,return )

Void Manager_obj::warn( ::String str){
{
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Manager_obj,warn,(void))

int Manager_obj::CURSOR_NONE;

int Manager_obj::CURSOR_NORMAL;

int Manager_obj::CURSOR_TEXT;

Void Manager_obj::SetCursor( int inCursor){
{
		__SAFE_POINT
		::nme::Manager_obj::nme_set_cursor(inCursor);
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Manager_obj,SetCursor,(void))

::nme::geom::Point Manager_obj::GetMouse( ){
	__SAFE_POINT
	Dynamic m = ::nme::Manager_obj::nme_get_mouse_position();
	return ::nme::geom::Point_obj::__new(m->__Field(HX_STRING(L"x",1)),m->__Field(HX_STRING(L"y",1)));
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(Manager_obj,GetMouse,return )

Dynamic Manager_obj::mouseEvent( ::nme::MouseEventType inType){
	__SAFE_POINT
	struct _Function_1_1{
		inline static Dynamic Block( ::nme::MouseEventType &inType){
			hx::Anon __result = hx::Anon_obj::Create();
			__result->Add(HX_STRING(L"type",4) , inType);
			__result->Add(HX_STRING(L"x",1) , ::nme::Manager_obj::SmouseX());
			__result->Add(HX_STRING(L"y",1) , ::nme::Manager_obj::SmouseY());
			__result->Add(HX_STRING(L"shift",5) , false);
			__result->Add(HX_STRING(L"ctrl",4) , false);
			__result->Add(HX_STRING(L"alt",3) , false);
			__result->Add(HX_STRING(L"leftIsDown",10) , (::nme::Manager_obj::mouseButtonState() != 0));
			__result->Add(HX_STRING(L"middleIsDown",12) , false);
			__result->Add(HX_STRING(L"rightIsDown",11) , false);
			return __result;
		}
	};
	return _Function_1_1::Block(inType);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Manager_obj,mouseEvent,return )

Dynamic Manager_obj::getScreen( ){
	return ::nme::Manager_obj::__scr;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(Manager_obj,getScreen,return )

int Manager_obj::windowWidth( ){
	return ::nme::Manager_obj::__scr->__Field(HX_STRING(L"width",5));
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(Manager_obj,windowWidth,return )

Void Manager_obj::SetBlitArea( ::nme::geom::Rectangle inRect,int inColour,int inAlpha,::nme::geom::Matrix inMatrix){
{
		__SAFE_POINT
		::nme::Manager_obj::nme_set_blit_area(::nme::Manager_obj::__scr,inRect,inColour,inAlpha,inMatrix);
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC4(Manager_obj,SetBlitArea,(void))

Void Manager_obj::UnSetBlitArea( ){
{
		__SAFE_POINT
		::nme::Manager_obj::nme_set_blit_area(::nme::Manager_obj::__scr,null(),0,0,null());
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(Manager_obj,UnSetBlitArea,(void))

int Manager_obj::mouseButtonState( ){
	__SAFE_POINT
	struct _Function_1_1{
		inline static Dynamic Block( )/* DEF (ret block)(not intern) */{
			Dynamic o = ::nme::Manager_obj::__evt;
			return ((o == null())) ? Dynamic( null() ) : Dynamic( o->__Field(HX_STRING(L"state",5)) );
		}
	};
	return _Function_1_1::Block();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(Manager_obj,mouseButtonState,return )

int Manager_obj::SmouseX( ){
	__SAFE_POINT
	struct _Function_1_1{
		inline static Dynamic Block( )/* DEF (ret block)(not intern) */{
			Dynamic o = ::nme::Manager_obj::__evt;
			return ((o == null())) ? Dynamic( null() ) : Dynamic( o->__Field(HX_STRING(L"x",1)) );
		}
	};
	return _Function_1_1::Block();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(Manager_obj,SmouseX,return )

int Manager_obj::SmouseY( ){
	__SAFE_POINT
	struct _Function_1_1{
		inline static Dynamic Block( )/* DEF (ret block)(not intern) */{
			Dynamic o = ::nme::Manager_obj::__evt;
			return ((o == null())) ? Dynamic( null() ) : Dynamic( o->__Field(HX_STRING(L"y",1)) );
		}
	};
	return _Function_1_1::Block();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(Manager_obj,SmouseY,return )

::nme::geom::Point Manager_obj::mousePoint( ){
	__SAFE_POINT
	return ::nme::geom::Point_obj::__new(::nme::Manager_obj::SmouseX(),::nme::Manager_obj::SmouseY());
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(Manager_obj,mousePoint,return )

int Manager_obj::set_draw_quality( int inQuality){
	__SAFE_POINT
	return ::nme::Manager_obj::nme_set_draw_quality(inQuality);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Manager_obj,set_draw_quality,return )

int Manager_obj::get_draw_quality( ){
	__SAFE_POINT
	return ::nme::Manager_obj::nme_get_draw_quality();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(Manager_obj,get_draw_quality,return )

::String Manager_obj::getClipboardString( ){
	return HX_STRING(L"",0);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(Manager_obj,getClipboardString,return )

Void Manager_obj::setClipboardString( ::String inString){
{
		__SAFE_POINT
		::nme::Manager_obj::nme_set_clipboard(inString);
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Manager_obj,setClipboardString,(void))

Dynamic Manager_obj::nme_surface_clear;

Dynamic Manager_obj::nme_screen_init;

Dynamic Manager_obj::nme_resize_surface;

Dynamic Manager_obj::nme_screen_close;

Dynamic Manager_obj::nme_flipbuffer;

Dynamic Manager_obj::nme_delay;

Dynamic Manager_obj::nme_event;

Dynamic Manager_obj::nme_set_draw_quality;

Dynamic Manager_obj::nme_get_draw_quality;

Dynamic Manager_obj::nme_set_cursor;

Dynamic Manager_obj::nme_get_mouse_position;

Dynamic Manager_obj::nme_set_clipboard;

Dynamic Manager_obj::nme_get_clipboard;

Dynamic Manager_obj::nme_set_blit_area;

Dynamic Manager_obj::nme_surface_width;

Dynamic Manager_obj::nme_surface_height;


Manager_obj::Manager_obj()
{
}

void Manager_obj::__Mark()
{
	hx::MarkMember(mainLoopRunning);
	hx::MarkMember(mouseEventCallbacks);
	hx::MarkMember(mouseClickCallbacks);
	hx::MarkMember(keyEventCallbacks);
	hx::MarkMember(updateCallbacks);
	hx::MarkMember(renderCallbacks);
	hx::MarkMember(mPaused);
	hx::MarkMember(tryQuitFunction);
	hx::MarkMember(timerStack);
	hx::MarkMember(mT0);
}

Dynamic Manager_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 3:
		if (!memcmp(inName.__s,L"mT0",sizeof(wchar_t)*3) ) { return mT0; }
		break;
	case 4:
		if (!memcmp(inName.__s,L"warn",sizeof(wchar_t)*4) ) { return warn_dyn(); }
		if (!memcmp(inName.__s,L"flip",sizeof(wchar_t)*4) ) { return flip_dyn(); }
		break;
	case 5:
		if (!memcmp(inName.__s,L"__scr",sizeof(wchar_t)*5) ) { return __scr; }
		if (!memcmp(inName.__s,L"__evt",sizeof(wchar_t)*5) ) { return __evt; }
		if (!memcmp(inName.__s,L"VSYNC",sizeof(wchar_t)*5) ) { return VSYNC; }
		if (!memcmp(inName.__s,L"close",sizeof(wchar_t)*5) ) { return close_dyn(); }
		if (!memcmp(inName.__s,L"delay",sizeof(wchar_t)*5) ) { return delay_dyn(); }
		if (!memcmp(inName.__s,L"clear",sizeof(wchar_t)*5) ) { return clear_dyn(); }
		break;
	case 6:
		if (!memcmp(inName.__s,L"OPENGL",sizeof(wchar_t)*6) ) { return OPENGL; }
		if (!memcmp(inName.__s,L"events",sizeof(wchar_t)*6) ) { return events_dyn(); }
		if (!memcmp(inName.__s,L"mouseX",sizeof(wchar_t)*6) ) { return mouseX_dyn(); }
		if (!memcmp(inName.__s,L"mouseY",sizeof(wchar_t)*6) ) { return mouseY_dyn(); }
		break;
	case 7:
		if (!memcmp(inName.__s,L"SmouseX",sizeof(wchar_t)*7) ) { return SmouseX_dyn(); }
		if (!memcmp(inName.__s,L"SmouseY",sizeof(wchar_t)*7) ) { return SmouseY_dyn(); }
		if (!memcmp(inName.__s,L"mPaused",sizeof(wchar_t)*7) ) { return mPaused; }
		if (!memcmp(inName.__s,L"tryQuit",sizeof(wchar_t)*7) ) { return tryQuit_dyn(); }
		if (!memcmp(inName.__s,L"lastKey",sizeof(wchar_t)*7) ) { return lastKey_dyn(); }
		break;
	case 8:
		if (!memcmp(inName.__s,L"closeKey",sizeof(wchar_t)*8) ) { return closeKey; }
		if (!memcmp(inName.__s,L"HARDWARE",sizeof(wchar_t)*8) ) { return HARDWARE; }
		if (!memcmp(inName.__s,L"graphics",sizeof(wchar_t)*8) ) { return graphics; }
		if (!memcmp(inName.__s,L"GetMouse",sizeof(wchar_t)*8) ) { return GetMouse_dyn(); }
		if (!memcmp(inName.__s,L"OnResize",sizeof(wchar_t)*8) ) { return OnResize_dyn(); }
		if (!memcmp(inName.__s,L"mainLoop",sizeof(wchar_t)*8) ) { return mainLoop_dyn(); }
		if (!memcmp(inName.__s,L"ResetFPS",sizeof(wchar_t)*8) ) { return ResetFPS_dyn(); }
		if (!memcmp(inName.__s,L"lastChar",sizeof(wchar_t)*8) ) { return lastChar_dyn(); }
		break;
	case 9:
		if (!memcmp(inName.__s,L"RESIZABLE",sizeof(wchar_t)*9) ) { return RESIZABLE; }
		if (!memcmp(inName.__s,L"SetCursor",sizeof(wchar_t)*9) ) { return SetCursor_dyn(); }
		if (!memcmp(inName.__s,L"getScreen",sizeof(wchar_t)*9) ) { return getScreen_dyn(); }
		if (!memcmp(inName.__s,L"nme_delay",sizeof(wchar_t)*9) ) { return nme_delay; }
		if (!memcmp(inName.__s,L"nme_event",sizeof(wchar_t)*9) ) { return nme_event; }
		if (!memcmp(inName.__s,L"RenderFPS",sizeof(wchar_t)*9) ) { return RenderFPS_dyn(); }
		if (!memcmp(inName.__s,L"nextEvent",sizeof(wchar_t)*9) ) { return nextEvent_dyn(); }
		if (!memcmp(inName.__s,L"clickRect",sizeof(wchar_t)*9) ) { return clickRect_dyn(); }
		break;
	case 10:
		if (!memcmp(inName.__s,L"FULLSCREEN",sizeof(wchar_t)*10) ) { return FULLSCREEN; }
		if (!memcmp(inName.__s,L"mouseEvent",sizeof(wchar_t)*10) ) { return mouseEvent_dyn(); }
		if (!memcmp(inName.__s,L"mousePoint",sizeof(wchar_t)*10) ) { return mousePoint_dyn(); }
		if (!memcmp(inName.__s,L"timerStack",sizeof(wchar_t)*10) ) { return timerStack; }
		if (!memcmp(inName.__s,L"lastKeyAlt",sizeof(wchar_t)*10) ) { return lastKeyAlt_dyn(); }
		if (!memcmp(inName.__s,L"mouseMoveX",sizeof(wchar_t)*10) ) { return mouseMoveX_dyn(); }
		if (!memcmp(inName.__s,L"mouseMoveY",sizeof(wchar_t)*10) ) { return mouseMoveY_dyn(); }
		break;
	case 11:
		if (!memcmp(inName.__s,L"CURSOR_NONE",sizeof(wchar_t)*11) ) { return CURSOR_NONE; }
		if (!memcmp(inName.__s,L"CURSOR_TEXT",sizeof(wchar_t)*11) ) { return CURSOR_TEXT; }
		if (!memcmp(inName.__s,L"windowWidth",sizeof(wchar_t)*11) ) { return windowWidth_dyn(); }
		if (!memcmp(inName.__s,L"SetBlitArea",sizeof(wchar_t)*11) ) { return SetBlitArea_dyn(); }
		if (!memcmp(inName.__s,L"lastKeyCtrl",sizeof(wchar_t)*11) ) { return lastKeyCtrl_dyn(); }
		if (!memcmp(inName.__s,L"mouseButton",sizeof(wchar_t)*11) ) { return mouseButton_dyn(); }
		break;
	case 12:
		if (!memcmp(inName.__s,L"pauseUpdates",sizeof(wchar_t)*12) ) { return pauseUpdates; }
		if (!memcmp(inName.__s,L"draw_quality",sizeof(wchar_t)*12) ) { return get_draw_quality(); }
		if (!memcmp(inName.__s,L"fireKeyEvent",sizeof(wchar_t)*12) ) { return fireKeyEvent_dyn(); }
		if (!memcmp(inName.__s,L"getNextEvent",sizeof(wchar_t)*12) ) { return getNextEvent_dyn(); }
		if (!memcmp(inName.__s,L"getEventType",sizeof(wchar_t)*12) ) { return getEventType_dyn(); }
		if (!memcmp(inName.__s,L"lastKeyShift",sizeof(wchar_t)*12) ) { return lastKeyShift_dyn(); }
		break;
	case 13:
		if (!memcmp(inName.__s,L"toggleQuality",sizeof(wchar_t)*13) ) { return toggleQuality; }
		if (!memcmp(inName.__s,L"CURSOR_NORMAL",sizeof(wchar_t)*13) ) { return CURSOR_NORMAL; }
		if (!memcmp(inName.__s,L"UnSetBlitArea",sizeof(wchar_t)*13) ) { return UnSetBlitArea_dyn(); }
		break;
	case 14:
		if (!memcmp(inName.__s,L"getWindowWidth",sizeof(wchar_t)*14) ) { return getWindowWidth_dyn(); }
		if (!memcmp(inName.__s,L"nme_flipbuffer",sizeof(wchar_t)*14) ) { return nme_flipbuffer; }
		if (!memcmp(inName.__s,L"nme_set_cursor",sizeof(wchar_t)*14) ) { return nme_set_cursor; }
		if (!memcmp(inName.__s,L"fireMouseEvent",sizeof(wchar_t)*14) ) { return fireMouseEvent_dyn(); }
		if (!memcmp(inName.__s,L"addKeyCallback",sizeof(wchar_t)*14) ) { return addKeyCallback_dyn(); }
		break;
	case 15:
		if (!memcmp(inName.__s,L"getWindowHeight",sizeof(wchar_t)*15) ) { return getWindowHeight_dyn(); }
		if (!memcmp(inName.__s,L"nme_screen_init",sizeof(wchar_t)*15) ) { return nme_screen_init; }
		if (!memcmp(inName.__s,L"mainLoopRunning",sizeof(wchar_t)*15) ) { return mainLoopRunning; }
		if (!memcmp(inName.__s,L"updateCallbacks",sizeof(wchar_t)*15) ) { return updateCallbacks; }
		if (!memcmp(inName.__s,L"renderCallbacks",sizeof(wchar_t)*15) ) { return renderCallbacks; }
		if (!memcmp(inName.__s,L"tryQuitFunction",sizeof(wchar_t)*15) ) { return tryQuitFunction; }
		break;
	case 16:
		if (!memcmp(inName.__s,L"mFrameCountStack",sizeof(wchar_t)*16) ) { return mFrameCountStack; }
		if (!memcmp(inName.__s,L"mouseButtonState",sizeof(wchar_t)*16) ) { return mouseButtonState_dyn(); }
		if (!memcmp(inName.__s,L"set_draw_quality",sizeof(wchar_t)*16) ) { return set_draw_quality_dyn(); }
		if (!memcmp(inName.__s,L"get_draw_quality",sizeof(wchar_t)*16) ) { return get_draw_quality_dyn(); }
		if (!memcmp(inName.__s,L"nme_screen_close",sizeof(wchar_t)*16) ) { return nme_screen_close; }
		if (!memcmp(inName.__s,L"addMouseCallback",sizeof(wchar_t)*16) ) { return addMouseCallback_dyn(); }
		if (!memcmp(inName.__s,L"addClickCallback",sizeof(wchar_t)*16) ) { return addClickCallback_dyn(); }
		break;
	case 17:
		if (!memcmp(inName.__s,L"nme_surface_clear",sizeof(wchar_t)*17) ) { return nme_surface_clear; }
		if (!memcmp(inName.__s,L"nme_set_clipboard",sizeof(wchar_t)*17) ) { return nme_set_clipboard; }
		if (!memcmp(inName.__s,L"nme_get_clipboard",sizeof(wchar_t)*17) ) { return nme_get_clipboard; }
		if (!memcmp(inName.__s,L"nme_set_blit_area",sizeof(wchar_t)*17) ) { return nme_set_blit_area; }
		if (!memcmp(inName.__s,L"nme_surface_width",sizeof(wchar_t)*17) ) { return nme_surface_width; }
		if (!memcmp(inName.__s,L"keyEventCallbacks",sizeof(wchar_t)*17) ) { return keyEventCallbacks; }
		if (!memcmp(inName.__s,L"addRenderCallback",sizeof(wchar_t)*17) ) { return addRenderCallback_dyn(); }
		if (!memcmp(inName.__s,L"addUpdateCallback",sizeof(wchar_t)*17) ) { return addUpdateCallback_dyn(); }
		break;
	case 18:
		if (!memcmp(inName.__s,L"getClipboardString",sizeof(wchar_t)*18) ) { return getClipboardString_dyn(); }
		if (!memcmp(inName.__s,L"setClipboardString",sizeof(wchar_t)*18) ) { return setClipboardString_dyn(); }
		if (!memcmp(inName.__s,L"nme_resize_surface",sizeof(wchar_t)*18) ) { return nme_resize_surface; }
		if (!memcmp(inName.__s,L"nme_surface_height",sizeof(wchar_t)*18) ) { return nme_surface_height; }
		break;
	case 19:
		if (!memcmp(inName.__s,L"mouseEventCallbacks",sizeof(wchar_t)*19) ) { return mouseEventCallbacks; }
		if (!memcmp(inName.__s,L"mouseClickCallbacks",sizeof(wchar_t)*19) ) { return mouseClickCallbacks; }
		break;
	case 20:
		if (!memcmp(inName.__s,L"nme_set_draw_quality",sizeof(wchar_t)*20) ) { return nme_set_draw_quality; }
		if (!memcmp(inName.__s,L"nme_get_draw_quality",sizeof(wchar_t)*20) ) { return nme_get_draw_quality; }
		break;
	case 22:
		if (!memcmp(inName.__s,L"nme_get_mouse_position",sizeof(wchar_t)*22) ) { return nme_get_mouse_position; }
	}
	return super::__Field(inName);
}

Dynamic Manager_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	switch(inName.length) {
	case 3:
		if (!memcmp(inName.__s,L"mT0",sizeof(wchar_t)*3) ) { mT0=inValue.Cast< double >(); return inValue; }
		break;
	case 5:
		if (!memcmp(inName.__s,L"__scr",sizeof(wchar_t)*5) ) { __scr=inValue.Cast< Dynamic >(); return inValue; }
		if (!memcmp(inName.__s,L"__evt",sizeof(wchar_t)*5) ) { __evt=inValue.Cast< Dynamic >(); return inValue; }
		if (!memcmp(inName.__s,L"VSYNC",sizeof(wchar_t)*5) ) { VSYNC=inValue.Cast< int >(); return inValue; }
		break;
	case 6:
		if (!memcmp(inName.__s,L"OPENGL",sizeof(wchar_t)*6) ) { OPENGL=inValue.Cast< int >(); return inValue; }
		break;
	case 7:
		if (!memcmp(inName.__s,L"mPaused",sizeof(wchar_t)*7) ) { mPaused=inValue.Cast< bool >(); return inValue; }
		break;
	case 8:
		if (!memcmp(inName.__s,L"closeKey",sizeof(wchar_t)*8) ) { closeKey=inValue.Cast< int >(); return inValue; }
		if (!memcmp(inName.__s,L"HARDWARE",sizeof(wchar_t)*8) ) { HARDWARE=inValue.Cast< int >(); return inValue; }
		if (!memcmp(inName.__s,L"graphics",sizeof(wchar_t)*8) ) { graphics=inValue.Cast< ::nme::display::Graphics >(); return inValue; }
		break;
	case 9:
		if (!memcmp(inName.__s,L"RESIZABLE",sizeof(wchar_t)*9) ) { RESIZABLE=inValue.Cast< int >(); return inValue; }
		if (!memcmp(inName.__s,L"nme_delay",sizeof(wchar_t)*9) ) { nme_delay=inValue.Cast< Dynamic >(); return inValue; }
		if (!memcmp(inName.__s,L"nme_event",sizeof(wchar_t)*9) ) { nme_event=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 10:
		if (!memcmp(inName.__s,L"FULLSCREEN",sizeof(wchar_t)*10) ) { FULLSCREEN=inValue.Cast< int >(); return inValue; }
		if (!memcmp(inName.__s,L"timerStack",sizeof(wchar_t)*10) ) { timerStack=inValue.Cast< ::List >(); return inValue; }
		break;
	case 11:
		if (!memcmp(inName.__s,L"CURSOR_NONE",sizeof(wchar_t)*11) ) { CURSOR_NONE=inValue.Cast< int >(); return inValue; }
		if (!memcmp(inName.__s,L"CURSOR_TEXT",sizeof(wchar_t)*11) ) { CURSOR_TEXT=inValue.Cast< int >(); return inValue; }
		break;
	case 12:
		if (!memcmp(inName.__s,L"pauseUpdates",sizeof(wchar_t)*12) ) { pauseUpdates=inValue.Cast< int >(); return inValue; }
		if (!memcmp(inName.__s,L"draw_quality",sizeof(wchar_t)*12) ) { return set_draw_quality(inValue); }
		break;
	case 13:
		if (!memcmp(inName.__s,L"toggleQuality",sizeof(wchar_t)*13) ) { toggleQuality=inValue.Cast< int >(); return inValue; }
		if (!memcmp(inName.__s,L"CURSOR_NORMAL",sizeof(wchar_t)*13) ) { CURSOR_NORMAL=inValue.Cast< int >(); return inValue; }
		break;
	case 14:
		if (!memcmp(inName.__s,L"nme_flipbuffer",sizeof(wchar_t)*14) ) { nme_flipbuffer=inValue.Cast< Dynamic >(); return inValue; }
		if (!memcmp(inName.__s,L"nme_set_cursor",sizeof(wchar_t)*14) ) { nme_set_cursor=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 15:
		if (!memcmp(inName.__s,L"nme_screen_init",sizeof(wchar_t)*15) ) { nme_screen_init=inValue.Cast< Dynamic >(); return inValue; }
		if (!memcmp(inName.__s,L"mainLoopRunning",sizeof(wchar_t)*15) ) { mainLoopRunning=inValue.Cast< bool >(); return inValue; }
		if (!memcmp(inName.__s,L"updateCallbacks",sizeof(wchar_t)*15) ) { updateCallbacks=inValue.Cast< Array< Dynamic > >(); return inValue; }
		if (!memcmp(inName.__s,L"renderCallbacks",sizeof(wchar_t)*15) ) { renderCallbacks=inValue.Cast< Array< Dynamic > >(); return inValue; }
		if (!memcmp(inName.__s,L"tryQuitFunction",sizeof(wchar_t)*15) ) { tryQuitFunction=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 16:
		if (!memcmp(inName.__s,L"mFrameCountStack",sizeof(wchar_t)*16) ) { mFrameCountStack=inValue.Cast< Array< double > >(); return inValue; }
		if (!memcmp(inName.__s,L"nme_screen_close",sizeof(wchar_t)*16) ) { nme_screen_close=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 17:
		if (!memcmp(inName.__s,L"nme_surface_clear",sizeof(wchar_t)*17) ) { nme_surface_clear=inValue.Cast< Dynamic >(); return inValue; }
		if (!memcmp(inName.__s,L"nme_set_clipboard",sizeof(wchar_t)*17) ) { nme_set_clipboard=inValue.Cast< Dynamic >(); return inValue; }
		if (!memcmp(inName.__s,L"nme_get_clipboard",sizeof(wchar_t)*17) ) { nme_get_clipboard=inValue.Cast< Dynamic >(); return inValue; }
		if (!memcmp(inName.__s,L"nme_set_blit_area",sizeof(wchar_t)*17) ) { nme_set_blit_area=inValue.Cast< Dynamic >(); return inValue; }
		if (!memcmp(inName.__s,L"nme_surface_width",sizeof(wchar_t)*17) ) { nme_surface_width=inValue.Cast< Dynamic >(); return inValue; }
		if (!memcmp(inName.__s,L"keyEventCallbacks",sizeof(wchar_t)*17) ) { keyEventCallbacks=inValue.Cast< Array< Dynamic > >(); return inValue; }
		break;
	case 18:
		if (!memcmp(inName.__s,L"nme_resize_surface",sizeof(wchar_t)*18) ) { nme_resize_surface=inValue.Cast< Dynamic >(); return inValue; }
		if (!memcmp(inName.__s,L"nme_surface_height",sizeof(wchar_t)*18) ) { nme_surface_height=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 19:
		if (!memcmp(inName.__s,L"mouseEventCallbacks",sizeof(wchar_t)*19) ) { mouseEventCallbacks=inValue.Cast< Array< Dynamic > >(); return inValue; }
		if (!memcmp(inName.__s,L"mouseClickCallbacks",sizeof(wchar_t)*19) ) { mouseClickCallbacks=inValue.Cast< Array< Dynamic > >(); return inValue; }
		break;
	case 20:
		if (!memcmp(inName.__s,L"nme_set_draw_quality",sizeof(wchar_t)*20) ) { nme_set_draw_quality=inValue.Cast< Dynamic >(); return inValue; }
		if (!memcmp(inName.__s,L"nme_get_draw_quality",sizeof(wchar_t)*20) ) { nme_get_draw_quality=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 22:
		if (!memcmp(inName.__s,L"nme_get_mouse_position",sizeof(wchar_t)*22) ) { nme_get_mouse_position=inValue.Cast< Dynamic >(); return inValue; }
	}
	return super::__SetField(inName,inValue);
}

void Manager_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_STRING(L"mainLoopRunning",15));
	outFields->push(HX_STRING(L"mouseEventCallbacks",19));
	outFields->push(HX_STRING(L"mouseClickCallbacks",19));
	outFields->push(HX_STRING(L"keyEventCallbacks",17));
	outFields->push(HX_STRING(L"updateCallbacks",15));
	outFields->push(HX_STRING(L"renderCallbacks",15));
	outFields->push(HX_STRING(L"mPaused",7));
	outFields->push(HX_STRING(L"timerStack",10));
	outFields->push(HX_STRING(L"mT0",3));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_STRING(L"__scr",5),
	HX_STRING(L"__evt",5),
	HX_STRING(L"closeKey",8),
	HX_STRING(L"pauseUpdates",12),
	HX_STRING(L"toggleQuality",13),
	HX_STRING(L"FULLSCREEN",10),
	HX_STRING(L"OPENGL",6),
	HX_STRING(L"RESIZABLE",9),
	HX_STRING(L"HARDWARE",8),
	HX_STRING(L"VSYNC",5),
	HX_STRING(L"graphics",8),
	HX_STRING(L"draw_quality",12),
	HX_STRING(L"mFrameCountStack",16),
	HX_STRING(L"getWindowWidth",14),
	HX_STRING(L"getWindowHeight",15),
	HX_STRING(L"warn",4),
	HX_STRING(L"CURSOR_NONE",11),
	HX_STRING(L"CURSOR_NORMAL",13),
	HX_STRING(L"CURSOR_TEXT",11),
	HX_STRING(L"SetCursor",9),
	HX_STRING(L"GetMouse",8),
	HX_STRING(L"mouseEvent",10),
	HX_STRING(L"getScreen",9),
	HX_STRING(L"windowWidth",11),
	HX_STRING(L"SetBlitArea",11),
	HX_STRING(L"UnSetBlitArea",13),
	HX_STRING(L"mouseButtonState",16),
	HX_STRING(L"SmouseX",7),
	HX_STRING(L"SmouseY",7),
	HX_STRING(L"mousePoint",10),
	HX_STRING(L"set_draw_quality",16),
	HX_STRING(L"get_draw_quality",16),
	HX_STRING(L"getClipboardString",18),
	HX_STRING(L"setClipboardString",18),
	HX_STRING(L"nme_surface_clear",17),
	HX_STRING(L"nme_screen_init",15),
	HX_STRING(L"nme_resize_surface",18),
	HX_STRING(L"nme_screen_close",16),
	HX_STRING(L"nme_flipbuffer",14),
	HX_STRING(L"nme_delay",9),
	HX_STRING(L"nme_event",9),
	HX_STRING(L"nme_set_draw_quality",20),
	HX_STRING(L"nme_get_draw_quality",20),
	HX_STRING(L"nme_set_cursor",14),
	HX_STRING(L"nme_get_mouse_position",22),
	HX_STRING(L"nme_set_clipboard",17),
	HX_STRING(L"nme_get_clipboard",17),
	HX_STRING(L"nme_set_blit_area",17),
	HX_STRING(L"nme_surface_width",17),
	HX_STRING(L"nme_surface_height",18),
	String(null()) };

static ::String sMemberFields[] = {
	HX_STRING(L"mainLoopRunning",15),
	HX_STRING(L"mouseEventCallbacks",19),
	HX_STRING(L"mouseClickCallbacks",19),
	HX_STRING(L"keyEventCallbacks",17),
	HX_STRING(L"updateCallbacks",15),
	HX_STRING(L"renderCallbacks",15),
	HX_STRING(L"mPaused",7),
	HX_STRING(L"tryQuitFunction",15),
	HX_STRING(L"timerStack",10),
	HX_STRING(L"mT0",3),
	HX_STRING(L"OnResize",8),
	HX_STRING(L"mainLoop",8),
	HX_STRING(L"ResetFPS",8),
	HX_STRING(L"RenderFPS",9),
	HX_STRING(L"tryQuit",7),
	HX_STRING(L"fireMouseEvent",14),
	HX_STRING(L"fireKeyEvent",12),
	HX_STRING(L"addMouseCallback",16),
	HX_STRING(L"addClickCallback",16),
	HX_STRING(L"addKeyCallback",14),
	HX_STRING(L"addRenderCallback",17),
	HX_STRING(L"addUpdateCallback",17),
	HX_STRING(L"close",5),
	HX_STRING(L"delay",5),
	HX_STRING(L"clear",5),
	HX_STRING(L"flip",4),
	HX_STRING(L"events",6),
	HX_STRING(L"nextEvent",9),
	HX_STRING(L"getNextEvent",12),
	HX_STRING(L"getEventType",12),
	HX_STRING(L"clickRect",9),
	HX_STRING(L"lastKey",7),
	HX_STRING(L"lastChar",8),
	HX_STRING(L"lastKeyShift",12),
	HX_STRING(L"lastKeyCtrl",11),
	HX_STRING(L"lastKeyAlt",10),
	HX_STRING(L"mouseButton",11),
	HX_STRING(L"mouseX",6),
	HX_STRING(L"mouseY",6),
	HX_STRING(L"mouseMoveX",10),
	HX_STRING(L"mouseMoveY",10),
	String(null()) };

static void sMarkStatics() {
	hx::MarkMember(Manager_obj::__scr);
	hx::MarkMember(Manager_obj::__evt);
	hx::MarkMember(Manager_obj::closeKey);
	hx::MarkMember(Manager_obj::pauseUpdates);
	hx::MarkMember(Manager_obj::toggleQuality);
	hx::MarkMember(Manager_obj::FULLSCREEN);
	hx::MarkMember(Manager_obj::OPENGL);
	hx::MarkMember(Manager_obj::RESIZABLE);
	hx::MarkMember(Manager_obj::HARDWARE);
	hx::MarkMember(Manager_obj::VSYNC);
	hx::MarkMember(Manager_obj::graphics);
	hx::MarkMember(Manager_obj::draw_quality);
	hx::MarkMember(Manager_obj::mFrameCountStack);
	hx::MarkMember(Manager_obj::CURSOR_NONE);
	hx::MarkMember(Manager_obj::CURSOR_NORMAL);
	hx::MarkMember(Manager_obj::CURSOR_TEXT);
	hx::MarkMember(Manager_obj::nme_surface_clear);
	hx::MarkMember(Manager_obj::nme_screen_init);
	hx::MarkMember(Manager_obj::nme_resize_surface);
	hx::MarkMember(Manager_obj::nme_screen_close);
	hx::MarkMember(Manager_obj::nme_flipbuffer);
	hx::MarkMember(Manager_obj::nme_delay);
	hx::MarkMember(Manager_obj::nme_event);
	hx::MarkMember(Manager_obj::nme_set_draw_quality);
	hx::MarkMember(Manager_obj::nme_get_draw_quality);
	hx::MarkMember(Manager_obj::nme_set_cursor);
	hx::MarkMember(Manager_obj::nme_get_mouse_position);
	hx::MarkMember(Manager_obj::nme_set_clipboard);
	hx::MarkMember(Manager_obj::nme_get_clipboard);
	hx::MarkMember(Manager_obj::nme_set_blit_area);
	hx::MarkMember(Manager_obj::nme_surface_width);
	hx::MarkMember(Manager_obj::nme_surface_height);
};

Class Manager_obj::__mClass;

void Manager_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_STRING(L"nme.Manager",11), hx::TCanCast< Manager_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void Manager_obj::__boot()
{
	hx::Static(__scr);
	hx::Static(__evt);
	hx::Static(closeKey) = 27;
	hx::Static(pauseUpdates) = ::nme::KeyCode_obj::F11;
	hx::Static(toggleQuality) = ::nme::KeyCode_obj::F12;
	hx::Static(FULLSCREEN) = 1;
	hx::Static(OPENGL) = 2;
	hx::Static(RESIZABLE) = 4;
	hx::Static(HARDWARE) = 8;
	hx::Static(VSYNC) = 16;
	hx::Static(graphics);
	hx::Static(draw_quality);
	hx::Static(mFrameCountStack) = Array_obj< double >::__new();
	hx::Static(CURSOR_NONE) = 0;
	hx::Static(CURSOR_NORMAL) = 1;
	hx::Static(CURSOR_TEXT) = 2;
	hx::Static(nme_surface_clear) = ::nme::Loader_obj::load(HX_STRING(L"nme_surface_clear",17),2);
	hx::Static(nme_screen_init) = ::nme::Loader_obj::load(HX_STRING(L"nme_screen_init",15),5);
	hx::Static(nme_resize_surface) = ::nme::Loader_obj::load(HX_STRING(L"nme_resize_surface",18),2);
	hx::Static(nme_screen_close) = ::nme::Loader_obj::load(HX_STRING(L"nme_screen_close",16),0);
	hx::Static(nme_flipbuffer) = ::nme::Loader_obj::load(HX_STRING(L"nme_flipbuffer",14),1);
	hx::Static(nme_delay) = ::nme::Loader_obj::load(HX_STRING(L"nme_delay",9),1);
	hx::Static(nme_event) = ::nme::Loader_obj::load(HX_STRING(L"nme_event",9),0);
	hx::Static(nme_set_draw_quality) = ::nme::Loader_obj::load(HX_STRING(L"nme_set_draw_quality",20),1);
	hx::Static(nme_get_draw_quality) = ::nme::Loader_obj::load(HX_STRING(L"nme_get_draw_quality",20),0);
	hx::Static(nme_set_cursor) = ::nme::Loader_obj::load(HX_STRING(L"nme_set_cursor",14),1);
	hx::Static(nme_get_mouse_position) = ::nme::Loader_obj::load(HX_STRING(L"nme_get_mouse_position",22),0);
	hx::Static(nme_set_clipboard) = ::nme::Loader_obj::load(HX_STRING(L"nme_set_clipboard",17),1);
	hx::Static(nme_get_clipboard) = ::nme::Loader_obj::load(HX_STRING(L"nme_get_clipboard",17),0);
	hx::Static(nme_set_blit_area) = ::nme::Loader_obj::load(HX_STRING(L"nme_set_blit_area",17),5);
	hx::Static(nme_surface_width) = ::nme::Loader_obj::load(HX_STRING(L"nme_surface_width",17),1);
	hx::Static(nme_surface_height) = ::nme::Loader_obj::load(HX_STRING(L"nme_surface_height",18),1);
}

} // end namespace nme
