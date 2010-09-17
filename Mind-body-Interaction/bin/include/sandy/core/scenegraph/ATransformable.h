#ifndef INCLUDED_sandy_core_scenegraph_ATransformable
#define INCLUDED_sandy_core_scenegraph_ATransformable

#include <hxcpp.h>

#include <sandy/core/scenegraph/Node.h>
HX_DECLARE_CLASS1(sandy,CoordinateSystem)
HX_DECLARE_CLASS3(sandy,core,data,Matrix4)
HX_DECLARE_CLASS3(sandy,core,data,Point3D)
HX_DECLARE_CLASS3(sandy,core,scenegraph,ATransformable)
HX_DECLARE_CLASS3(sandy,core,scenegraph,Node)
namespace sandy{
namespace core{
namespace scenegraph{


class ATransformable_obj : public ::sandy::core::scenegraph::Node_obj{
	public:
		typedef ::sandy::core::scenegraph::Node_obj super;
		typedef ATransformable_obj OBJ_;
		ATransformable_obj();
		Void __construct(Dynamic __o_p_sName);

	public:
		static hx::ObjectPtr< ATransformable_obj > __new(Dynamic __o_p_sName);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~ATransformable_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark();
		::String __ToString() const { return HX_STRING(L"ATransformable",14); }

		bool disable; /* REM */ 
		::sandy::core::data::Matrix4 invModelMatrix; /* REM */ 
		::sandy::core::data::Matrix4 matrix; /* REM */ 
		::sandy::core::data::Point3D out; /* REM */ 
		double pan; /* REM */ 
		double roll; /* REM */ 
		double rotateX; /* REM */ 
		double rotateY; /* REM */ 
		double rotateZ; /* REM */ 
		double scaleX; /* REM */ 
		double scaleY; /* REM */ 
		double scaleZ; /* REM */ 
		::sandy::core::data::Point3D side; /* REM */ 
		double tilt; /* REM */ 
		::sandy::core::data::Point3D up; /* REM */ 
		double x; /* REM */ 
		double y; /* REM */ 
		double z; /* REM */ 
		virtual Void resetCoords( );
		Dynamic resetCoords_dyn();

		virtual Void initFrame( );
		Dynamic initFrame_dyn();

		virtual ::sandy::core::data::Matrix4 __getMatrix( );
		Dynamic __getMatrix_dyn();

		virtual ::sandy::core::data::Matrix4 __setMatrix( ::sandy::core::data::Matrix4 p_oMatrix);
		Dynamic __setMatrix_dyn();

		virtual double __setX( double p_nX);
		Dynamic __setX_dyn();

		virtual double __getX( );
		Dynamic __getX_dyn();

		virtual double __setY( double p_nY);
		Dynamic __setY_dyn();

		virtual double __getY( );
		Dynamic __getY_dyn();

		virtual double __setZ( double p_nZ);
		Dynamic __setZ_dyn();

		virtual double __getZ( );
		Dynamic __getZ_dyn();

		virtual ::sandy::core::data::Point3D getLookAt( );
		Dynamic getLookAt_dyn();

		virtual ::sandy::core::data::Point3D __getOut( );
		Dynamic __getOut_dyn();

		virtual ::sandy::core::data::Point3D __getSide( );
		Dynamic __getSide_dyn();

		virtual ::sandy::core::data::Point3D __getUp( );
		Dynamic __getUp_dyn();

		virtual double __setScaleX( double p_nScaleX);
		Dynamic __setScaleX_dyn();

		virtual double __getScaleX( );
		Dynamic __getScaleX_dyn();

		virtual double __setScaleY( double p_nScaleY);
		Dynamic __setScaleY_dyn();

		virtual double __getScaleY( );
		Dynamic __getScaleY_dyn();

		virtual double __setScaleZ( double p_nScaleZ);
		Dynamic __setScaleZ_dyn();

		virtual double __getScaleZ( );
		Dynamic __getScaleZ_dyn();

		virtual Void moveSideways( double p_nD);
		Dynamic moveSideways_dyn();

		virtual Void moveUpwards( double p_nD);
		Dynamic moveUpwards_dyn();

		virtual Void moveForward( double p_nD);
		Dynamic moveForward_dyn();

		virtual Void moveHorizontally( double p_nD);
		Dynamic moveHorizontally_dyn();

		virtual Void moveVertically( double p_nD);
		Dynamic moveVertically_dyn();

		virtual Void moveLateraly( double p_nD);
		Dynamic moveLateraly_dyn();

		virtual Void translate( double p_nX,double p_nY,double p_nZ);
		Dynamic translate_dyn();

		virtual Void rotateAxis( double p_nX,double p_nY,double p_nZ,double p_nAngle);
		Dynamic rotateAxis_dyn();

		virtual Void lookAt( double p_nX,double p_nY,double p_nZ);
		Dynamic lookAt_dyn();

		virtual Void lookAtPoint( ::sandy::core::data::Point3D p_oTarget);
		Dynamic lookAtPoint_dyn();

		virtual double __setRotateX( double p_nAngle);
		Dynamic __setRotateX_dyn();

		virtual double __getRotateX( );
		Dynamic __getRotateX_dyn();

		virtual double __setRotateY( double p_nAngle);
		Dynamic __setRotateY_dyn();

		virtual double __getRotateY( );
		Dynamic __getRotateY_dyn();

		virtual double __setRotateZ( double p_nAngle);
		Dynamic __setRotateZ_dyn();

		virtual double __getRotateZ( );
		Dynamic __getRotateZ_dyn();

		virtual double __setRoll( double p_nAngle);
		Dynamic __setRoll_dyn();

		virtual double __getRoll( );
		Dynamic __getRoll_dyn();

		virtual double __setTilt( double p_nAngle);
		Dynamic __setTilt_dyn();

		virtual double __getTilt( );
		Dynamic __getTilt_dyn();

		virtual double __setPan( double p_nAngle);
		Dynamic __setPan_dyn();

		virtual double __getPan( );
		Dynamic __getPan_dyn();

		virtual Void setPosition( double p_nX,double p_nY,double p_nZ);
		Dynamic setPosition_dyn();

		virtual Void setPositionPoint( ::sandy::core::data::Point3D p_oPoint);
		Dynamic setPositionPoint_dyn();

		virtual Void update( ::sandy::core::data::Matrix4 p_oModelMatrix,bool p_bChanged);
		Dynamic update_dyn();

		virtual Void updateTransform( );
		Dynamic updateTransform_dyn();

		virtual ::sandy::core::data::Point3D getPosition( ::sandy::CoordinateSystem p_eMode);
		Dynamic getPosition_dyn();

		virtual ::String toString( );
		Dynamic toString_dyn();

		virtual Void copy( ::sandy::core::scenegraph::Node src,Dynamic includeTransforms,Dynamic includeGeometry);
		Dynamic copy_dyn();

		::sandy::core::data::Matrix4 m_oMatrix; /* REM */ 
		::sandy::core::data::Point3D _vSide; /* REM */ 
		::sandy::core::data::Point3D _vOut; /* REM */ 
		::sandy::core::data::Point3D _vUp; /* REM */ 
		double _nTilt; /* REM */ 
		double _nYaw; /* REM */ 
		double _nRoll; /* REM */ 
		::sandy::core::data::Point3D _vRotation; /* REM */ 
		::sandy::core::data::Point3D _vLookatDown; /* REM */ 
		::sandy::core::data::Point3D _vLookAt; /* REM */ 
		::sandy::core::data::Point3D _p; /* REM */ 
		::sandy::core::data::Point3D _oScale; /* REM */ 
		::sandy::core::data::Matrix4 m_tmpMt; /* REM */ 
};

} // end namespace sandy
} // end namespace core
} // end namespace scenegraph

#endif /* INCLUDED_sandy_core_scenegraph_ATransformable */ 
