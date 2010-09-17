#ifndef INCLUDED_sandy_core_scenegraph_Geometry3D
#define INCLUDED_sandy_core_scenegraph_Geometry3D

#include <hxcpp.h>

HX_DECLARE_CLASS0(Hash)
HX_DECLARE_CLASS3(sandy,core,data,Edge3D)
HX_DECLARE_CLASS3(sandy,core,data,Point3D)
HX_DECLARE_CLASS3(sandy,core,data,UVCoord)
HX_DECLARE_CLASS3(sandy,core,data,Vertex)
HX_DECLARE_CLASS3(sandy,core,scenegraph,Geometry3D)
namespace sandy{
namespace core{
namespace scenegraph{


class Geometry3D_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef Geometry3D_obj OBJ_;
		Geometry3D_obj();
		Void __construct(Array< Dynamic > p_points);

	public:
		static hx::ObjectPtr< Geometry3D_obj > __new(Array< Dynamic > p_points);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~Geometry3D_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark();
		::String __ToString() const { return HX_STRING(L"Geometry3D",10); }

		::Hash EDGES_DICO; /* REM */ 
		Array< ::sandy::core::data::Vertex > aVertex; /* REM */ 
		Array< Array< int > > aFacesVertexID; /* REM */ 
		Array< Array< int > > aFacesUVCoordsID; /* REM */ 
		Array< ::sandy::core::data::Vertex > aFacesNormals; /* REM */ 
		Array< ::sandy::core::data::Vertex > aVertexNormals; /* REM */ 
		Array< ::sandy::core::data::Edge3D > aEdges; /* REM */ 
		Array< Array< int > > aFaceEdges; /* REM */ 
		Array< ::sandy::core::data::UVCoord > aUVCoords; /* REM */ 
		int m_nLastVertexId; /* REM */ 
		int m_nLastNormalId; /* REM */ 
		int m_nLastFaceId; /* REM */ 
		int m_nLastFaceUVId; /* REM */ 
		int m_nLastUVId; /* REM */ 
		int m_nLastVertexNormalId; /* REM */ 
		Array< Array< Dynamic > > m_aVertexFaces; /* REM */ 
		virtual Void init( );
		Dynamic init_dyn();

		virtual Void addFace( ::sandy::core::data::Point3D v0,::sandy::core::data::Point3D v1,::sandy::core::data::Point3D v2,::sandy::core::data::UVCoord uv0,::sandy::core::data::UVCoord uv1,::sandy::core::data::UVCoord uv2);
		Dynamic addFace_dyn();

		virtual int setVertex( int p_nVertexID,double p_nX,double p_nY,double p_nZ);
		Dynamic setVertex_dyn();

		virtual int getNextVertexID( );
		Dynamic getNextVertexID_dyn();

		virtual int setFaceNormal( int p_nNormalID,double p_nX,double p_nY,double p_nZ);
		Dynamic setFaceNormal_dyn();

		virtual int getNextFaceNormalID( );
		Dynamic getNextFaceNormalID_dyn();

		virtual double setVertexNormal( int p_nNormalID,double p_nX,double p_nY,double p_nZ);
		Dynamic setVertexNormal_dyn();

		virtual int getNextVertexNormalID( );
		Dynamic getNextVertexNormalID_dyn();

		virtual int setFaceVertexIds( int p_nFaceID,Array< int > arguments);
		Dynamic setFaceVertexIds_dyn();

		virtual bool isEdgeExist( int p_nVertexId1,int p_nVertexId2);
		Dynamic isEdgeExist_dyn();

		virtual int getNextFaceID( );
		Dynamic getNextFaceID_dyn();

		virtual int setFaceUVCoordsIds( int p_nFaceID,Array< int > arguments);
		Dynamic setFaceUVCoordsIds_dyn();

		virtual int getNextFaceUVCoordID( );
		Dynamic getNextFaceUVCoordID_dyn();

		virtual int getVertexId( ::sandy::core::data::Vertex p_point);
		Dynamic getVertexId_dyn();

		virtual int setUVCoords( int p_nID,double p_UValue,double p_nVValue);
		Dynamic setUVCoords_dyn();

		virtual int getNextUVCoordID( );
		Dynamic getNextUVCoordID_dyn();

		virtual Void generateFaceNormals( );
		Dynamic generateFaceNormals_dyn();

		virtual Void generateVertexNormals( );
		Dynamic generateVertexNormals_dyn();

		virtual ::sandy::core::scenegraph::Geometry3D clone( );
		Dynamic clone_dyn();

		virtual Void dispose( );
		Dynamic dispose_dyn();

		virtual Void updateFaceNormals( );
		Dynamic updateFaceNormals_dyn();

		virtual ::String toString( );
		Dynamic toString_dyn();

};

} // end namespace sandy
} // end namespace core
} // end namespace scenegraph

#endif /* INCLUDED_sandy_core_scenegraph_Geometry3D */ 
