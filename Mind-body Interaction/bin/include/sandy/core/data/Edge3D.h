#ifndef INCLUDED_sandy_core_data_Edge3D
#define INCLUDED_sandy_core_data_Edge3D

#include <hxcpp.h>

HX_DECLARE_CLASS3(sandy,core,data,Edge3D)
HX_DECLARE_CLASS3(sandy,core,data,Vertex)
namespace sandy{
namespace core{
namespace data{


class Edge3D_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef Edge3D_obj OBJ_;
		Edge3D_obj();
		Void __construct(int p_nVertexId1,int p_nVertexId2);

	public:
		static hx::ObjectPtr< Edge3D_obj > __new(int p_nVertexId1,int p_nVertexId2);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~Edge3D_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark();
		::String __ToString() const { return HX_STRING(L"Edge3D",6); }

		int vertexId1; /* REM */ 
		int vertexId2; /* REM */ 
		::sandy::core::data::Vertex vertex1; /* REM */ 
		::sandy::core::data::Vertex vertex2; /* REM */ 
		virtual ::sandy::core::data::Edge3D clone( );
		Dynamic clone_dyn();

};

} // end namespace sandy
} // end namespace core
} // end namespace data

#endif /* INCLUDED_sandy_core_data_Edge3D */ 
