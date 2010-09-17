#ifndef INCLUDED_sandy_events_Shape3DEvent
#define INCLUDED_sandy_events_Shape3DEvent

#include <hxcpp.h>

#include <sandy/events/BubbleEvent.h>
HX_DECLARE_CLASS2(neash,events,Event)
HX_DECLARE_CLASS3(sandy,core,data,Point3D)
HX_DECLARE_CLASS3(sandy,core,data,Polygon)
HX_DECLARE_CLASS3(sandy,core,data,UVCoord)
HX_DECLARE_CLASS3(sandy,core,scenegraph,ATransformable)
HX_DECLARE_CLASS3(sandy,core,scenegraph,IDisplayable)
HX_DECLARE_CLASS3(sandy,core,scenegraph,Node)
HX_DECLARE_CLASS3(sandy,core,scenegraph,Shape3D)
HX_DECLARE_CLASS2(sandy,events,BubbleEvent)
HX_DECLARE_CLASS2(sandy,events,Shape3DEvent)
namespace sandy{
namespace events{


class Shape3DEvent_obj : public ::sandy::events::BubbleEvent_obj{
	public:
		typedef ::sandy::events::BubbleEvent_obj super;
		typedef Shape3DEvent_obj OBJ_;
		Shape3DEvent_obj();
		Void __construct(::String e,::sandy::core::scenegraph::Shape3D p_oShape,::sandy::core::data::Polygon p_oPolygon,::sandy::core::data::UVCoord p_oUV,::sandy::core::data::Point3D p_oPoint3d,::neash::events::Event p_oEvent);

	public:
		static hx::ObjectPtr< Shape3DEvent_obj > __new(::String e,::sandy::core::scenegraph::Shape3D p_oShape,::sandy::core::data::Polygon p_oPolygon,::sandy::core::data::UVCoord p_oUV,::sandy::core::data::Point3D p_oPoint3d,::neash::events::Event p_oEvent);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~Shape3DEvent_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark();
		::String __ToString() const { return HX_STRING(L"Shape3DEvent",12); }

		::sandy::core::scenegraph::Shape3D shape; /* REM */ 
		::sandy::core::data::Polygon polygon; /* REM */ 
		::sandy::core::data::UVCoord uv; /* REM */ 
		::sandy::core::data::Point3D point; /* REM */ 
		::neash::events::Event event; /* REM */ 
};

} // end namespace sandy
} // end namespace events

#endif /* INCLUDED_sandy_events_Shape3DEvent */ 
