#ifndef INCLUDED_sandy_core_data_Pool
#define INCLUDED_sandy_core_data_Pool

#include <hxcpp.h>

HX_DECLARE_CLASS3(sandy,core,data,Point3D)
HX_DECLARE_CLASS3(sandy,core,data,Pool)
HX_DECLARE_CLASS3(sandy,core,data,UVCoord)
HX_DECLARE_CLASS3(sandy,core,data,Vertex)
namespace sandy{
namespace core{
namespace data{


class Pool_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef Pool_obj OBJ_;
		Pool_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< Pool_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~Pool_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark();
		::String __ToString() const { return HX_STRING(L"Pool",4); }

		::sandy::core::data::Vertex nextVertex; /* REM */ 
		::sandy::core::data::UVCoord nextUV; /* REM */ 
		::sandy::core::data::Point3D nextPoint3D; /* REM */ 
		int m_nSize; /* REM */ 
		Array< ::sandy::core::data::Vertex > m_aVertices; /* REM */ 
		int m_nIdVertice; /* REM */ 
		Array< ::sandy::core::data::UVCoord > m_aUV; /* REM */ 
		int m_nIdUV; /* REM */ 
		Array< ::sandy::core::data::Point3D > m_aPoint3Ds; /* REM */ 
		int m_nIdPoint3D; /* REM */ 
		virtual Void init( );
		Dynamic init_dyn();

		virtual ::sandy::core::data::Vertex __getNextVertex( );
		Dynamic __getNextVertex_dyn();

		virtual ::sandy::core::data::UVCoord __getNextUV( );
		Dynamic __getNextUV_dyn();

		virtual ::sandy::core::data::Point3D __getNextPoint3D( );
		Dynamic __getNextPoint3D_dyn();

		static ::sandy::core::data::Pool INSTANCE; /* REM */ 
		static ::sandy::core::data::Pool getInstance( );
		static Dynamic getInstance_dyn();

};

} // end namespace sandy
} // end namespace core
} // end namespace data

#endif /* INCLUDED_sandy_core_data_Pool */ 
