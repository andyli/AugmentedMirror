#ifndef INCLUDED_sandy_core_scenegraph_Camera3D
#define INCLUDED_sandy_core_scenegraph_Camera3D

#include <hxcpp.h>

#include <sandy/core/scenegraph/ATransformable.h>
HX_DECLARE_CLASS3(sandy,core,data,Matrix4)
HX_DECLARE_CLASS3(sandy,core,data,Vertex)
HX_DECLARE_CLASS3(sandy,core,scenegraph,ATransformable)
HX_DECLARE_CLASS3(sandy,core,scenegraph,Camera3D)
HX_DECLARE_CLASS3(sandy,core,scenegraph,Node)
HX_DECLARE_CLASS2(sandy,view,Frustum)
HX_DECLARE_CLASS2(sandy,view,ViewPort)
namespace sandy{
namespace core{
namespace scenegraph{


class Camera3D_obj : public ::sandy::core::scenegraph::ATransformable_obj{
	public:
		typedef ::sandy::core::scenegraph::ATransformable_obj super;
		typedef Camera3D_obj OBJ_;
		Camera3D_obj();
		Void __construct(Dynamic __o_p_nWidth,Dynamic __o_p_nHeight,Dynamic __o_p_nFov,Dynamic __o_p_nNear,Dynamic __o_p_nFar);

	public:
		static hx::ObjectPtr< Camera3D_obj > __new(Dynamic __o_p_nWidth,Dynamic __o_p_nHeight,Dynamic __o_p_nFov,Dynamic __o_p_nNear,Dynamic __o_p_nFar);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~Camera3D_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark();
		::String __ToString() const { return HX_STRING(L"Camera3D",8); }

		::sandy::view::ViewPort viewport; /* REM */ 
		::sandy::view::Frustum frustrum; /* REM */ 
		double fov; /* REM */ 
		virtual double __setFov( double p_nFov);
		Dynamic __setFov_dyn();

		virtual double __getFov( );
		Dynamic __getFov_dyn();

		double focalLength; /* REM */ 
		virtual double __setFocalLength( double f);
		Dynamic __setFocalLength_dyn();

		virtual double __getFocalLength( );
		Dynamic __getFocalLength_dyn();

		double near; /* REM */ 
		virtual double __setNear( double pNear);
		Dynamic __setNear_dyn();

		virtual double __getNear( );
		Dynamic __getNear_dyn();

		double far; /* REM */ 
		virtual double __setFar( double pFar);
		Dynamic __setFar_dyn();

		virtual double __getFar( );
		Dynamic __getFar_dyn();

		virtual Void projectArray( Array< ::sandy::core::data::Vertex > p_oList);
		Dynamic projectArray_dyn();

		virtual Void projectVertex( ::sandy::core::data::Vertex p_oVertex);
		Dynamic projectVertex_dyn();

		virtual Void update( ::sandy::core::data::Matrix4 p_oModelMatrix,bool p_bChanged);
		Dynamic update_dyn();

		virtual Void cull( ::sandy::view::Frustum p_oFrustum,::sandy::core::data::Matrix4 p_oViewMatrix,bool p_bChanged);
		Dynamic cull_dyn();

		::sandy::core::data::Matrix4 projectionMatrix; /* REM */ 
		virtual ::sandy::core::data::Matrix4 __getProjectionMatrix( );
		Dynamic __getProjectionMatrix_dyn();

		::sandy::core::data::Matrix4 invProjectionMatrix; /* REM */ 
		virtual ::sandy::core::data::Matrix4 __getinvProjectionMatrix( );
		Dynamic __getinvProjectionMatrix_dyn();

		virtual Void setPerspectiveProjection( double p_nFovY,double p_nAspectRatio,double p_nZNear,double p_nZFar);
		Dynamic setPerspectiveProjection_dyn();

		virtual Void updatePerspective( );
		Dynamic updatePerspective_dyn();

		virtual Void destroy( );
		Dynamic destroy_dyn();

		virtual ::String toString( );
		Dynamic toString_dyn();

		bool _perspectiveChanged; /* REM */ 
		::sandy::core::data::Matrix4 _mp; /* REM */ 
		::sandy::core::data::Matrix4 _mpInv; /* REM */ 
		double _nFov; /* REM */ 
		double _nFar; /* REM */ 
		double _nNear; /* REM */ 
		double mp11; /* REM */ 
		double mp21; /* REM */ 
		double mp31; /* REM */ 
		double mp41; /* REM */ 
		double mp12; /* REM */ 
		double mp22; /* REM */ 
		double mp32; /* REM */ 
		double mp42; /* REM */ 
		double mp13; /* REM */ 
		double mp23; /* REM */ 
		double mp33; /* REM */ 
		double mp43; /* REM */ 
		double mp14; /* REM */ 
		double mp24; /* REM */ 
		double mp34; /* REM */ 
		double mp44; /* REM */ 
		double m_nOffx; /* REM */ 
		double m_nOffy; /* REM */ 
};

} // end namespace sandy
} // end namespace core
} // end namespace scenegraph

#endif /* INCLUDED_sandy_core_scenegraph_Camera3D */ 
