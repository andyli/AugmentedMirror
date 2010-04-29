#ifndef INCLUDED_neash_swf_SWFStream
#define INCLUDED_neash_swf_SWFStream

#include <hxcpp.h>

HX_DECLARE_CLASS2(haxe,io,Bytes)
HX_DECLARE_CLASS2(neash,swf,SWFStream)
HX_DECLARE_CLASS2(neash,utils,IDataInput)
HX_DECLARE_CLASS2(nme,display,CapsStyle)
HX_DECLARE_CLASS2(nme,display,InterpolationMethod)
HX_DECLARE_CLASS2(nme,display,JointStyle)
HX_DECLARE_CLASS2(nme,display,LineScaleMode)
HX_DECLARE_CLASS2(nme,display,SpreadMethod)
HX_DECLARE_CLASS2(nme,geom,ColorTransform)
HX_DECLARE_CLASS2(nme,geom,Matrix)
HX_DECLARE_CLASS2(nme,geom,Rectangle)
namespace neash{
namespace swf{


class SWFStream_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef SWFStream_obj OBJ_;
		SWFStream_obj();
		Void __construct(::neash::utils::IDataInput inStream);

	public:
		static hx::ObjectPtr< SWFStream_obj > __new(::neash::utils::IDataInput inStream);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~SWFStream_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark();
		::String __ToString() const { return HX_STRING(L"SWFStream",9); }

		::neash::utils::IDataInput mStream; /* REM */ 
		int mVersion; /* REM */ 
		int mByteBuf; /* REM */ 
		int mBitPos; /* REM */ 
		int mTagSize; /* REM */ 
		int mTagRead; /* REM */ 
		int mPushTagSize; /* REM */ 
		int mPushTagRead; /* REM */ 
		virtual Void close( );
		Dynamic close_dyn();

		virtual int GetVersion( );
		Dynamic GetVersion_dyn();

		virtual Void AlignBits( );
		Dynamic AlignBits_dyn();

		virtual int Bits( int inBits,Dynamic inSigned);
		Dynamic Bits_dyn();

		virtual double Twips( int inBits);
		Dynamic Twips_dyn();

		virtual bool ReadBool( );
		Dynamic ReadBool_dyn();

		virtual ::nme::display::SpreadMethod ReadSpreadMethod( );
		Dynamic ReadSpreadMethod_dyn();

		virtual ::nme::display::InterpolationMethod ReadInterpolationMethod( );
		Dynamic ReadInterpolationMethod_dyn();

		virtual ::nme::display::CapsStyle ReadCapsStyle( );
		Dynamic ReadCapsStyle_dyn();

		virtual ::nme::display::JointStyle ReadJoinStyle( );
		Dynamic ReadJoinStyle_dyn();

		virtual ::nme::display::LineScaleMode ReadScaleMode( );
		Dynamic ReadScaleMode_dyn();

		virtual ::nme::geom::Rectangle ReadRect( );
		Dynamic ReadRect_dyn();

		virtual ::String ReadAlign( );
		Dynamic ReadAlign_dyn();

		virtual double FrameRate( );
		Dynamic FrameRate_dyn();

		virtual int Frames( );
		Dynamic Frames_dyn();

		virtual int ReadID( );
		Dynamic ReadID_dyn();

		virtual int ReadDepth( );
		Dynamic ReadDepth_dyn();

		virtual int ReadUI16( );
		Dynamic ReadUI16_dyn();

		virtual int ReadSI16( );
		Dynamic ReadSI16_dyn();

		virtual double ReadSTwips( );
		Dynamic ReadSTwips_dyn();

		virtual double ReadUTwips( );
		Dynamic ReadUTwips_dyn();

		virtual int ReadInt( );
		Dynamic ReadInt_dyn();

		virtual int ReadByte( );
		Dynamic ReadByte_dyn();

		virtual int ReadRGB( );
		Dynamic ReadRGB_dyn();

		virtual ::String ReadPascalString( );
		Dynamic ReadPascalString_dyn();

		virtual ::String ReadString( );
		Dynamic ReadString_dyn();

		virtual int ReadArraySize( bool inExtended);
		Dynamic ReadArraySize_dyn();

		virtual double Fixed( int inBits);
		Dynamic Fixed_dyn();

		virtual ::nme::geom::Matrix ReadMatrix( );
		Dynamic ReadMatrix_dyn();

		virtual ::nme::geom::ColorTransform ReadColorTransform( );
		Dynamic ReadColorTransform_dyn();

		virtual int BeginTag( );
		Dynamic BeginTag_dyn();

		virtual Void EndTag( );
		Dynamic EndTag_dyn();

		virtual ::haxe::io::Bytes ReadBytes( int inSize);
		Dynamic ReadBytes_dyn();

		virtual int BytesLeft( );
		Dynamic BytesLeft_dyn();

		virtual Void PushTag( );
		Dynamic PushTag_dyn();

		virtual Void PopTag( );
		Dynamic PopTag_dyn();

};

} // end namespace neash
} // end namespace swf

#endif /* INCLUDED_neash_swf_SWFStream */ 
