#ifndef INCLUDED_sandy_core_light_Light3D
#define INCLUDED_sandy_core_light_Light3D

#include <hxcpp.h>

#include <neash/events/EventDispatcher.h>
HX_DECLARE_CLASS2(neash,events,EventDispatcher)
HX_DECLARE_CLASS2(neash,events,IEventDispatcher)
HX_DECLARE_CLASS3(sandy,core,data,Point3D)
HX_DECLARE_CLASS3(sandy,core,light,Light3D)
namespace sandy{
namespace core{
namespace light{


class Light3D_obj : public ::neash::events::EventDispatcher_obj{
	public:
		typedef ::neash::events::EventDispatcher_obj super;
		typedef Light3D_obj OBJ_;
		Light3D_obj();
		Void __construct(::sandy::core::data::Point3D p_oD,double p_nPow);

	public:
		static hx::ObjectPtr< Light3D_obj > __new(::sandy::core::data::Point3D p_oD,double p_nPow);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~Light3D_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark();
		::String __ToString() const { return HX_STRING(L"Light3D",7); }

		bool changed; /* REM */ 
		virtual Void setPower( double p_nPow);
		Dynamic setPower_dyn();

		virtual double getPower( );
		Dynamic getPower_dyn();

		virtual double getNormalizedPower( );
		Dynamic getNormalizedPower_dyn();

		virtual ::sandy::core::data::Point3D getDirectionPoint3D( );
		Dynamic getDirectionPoint3D_dyn();

		virtual Void setDirection( double x,double y,double z);
		Dynamic setDirection_dyn();

		virtual Void setDirectionPoint3D( ::sandy::core::data::Point3D pDir);
		Dynamic setDirectionPoint3D_dyn();

		virtual double calculate( ::sandy::core::data::Point3D normal);
		Dynamic calculate_dyn();

		virtual Void destroy( );
		Dynamic destroy_dyn();

		int color; /* REM */ 
		virtual int __getColor( );
		Dynamic __getColor_dyn();

		virtual int __setColor( int p_nColor);
		Dynamic __setColor_dyn();

		::sandy::core::data::Point3D _dir; /* REM */ 
		double _power; /* REM */ 
		double _nPower; /* REM */ 
		int _color; /* REM */ 
		static double MAX_POWER; /* REM */ 
};

} // end namespace sandy
} // end namespace core
} // end namespace light

#endif /* INCLUDED_sandy_core_light_Light3D */ 
