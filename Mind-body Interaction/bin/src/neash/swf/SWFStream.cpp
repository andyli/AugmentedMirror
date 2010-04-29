#include <hxcpp.h>

#ifndef INCLUDED_haxe_io_Bytes
#include <haxe/io/Bytes.h>
#endif
#ifndef INCLUDED_neash_swf_SWFStream
#include <neash/swf/SWFStream.h>
#endif
#ifndef INCLUDED_neash_swf_Tags
#include <neash/swf/Tags.h>
#endif
#ifndef INCLUDED_neash_text_TextFormatAlign
#include <neash/text/TextFormatAlign.h>
#endif
#ifndef INCLUDED_neash_utils_IDataInput
#include <neash/utils/IDataInput.h>
#endif
#ifndef INCLUDED_neash_utils_Uncompress
#include <neash/utils/Uncompress.h>
#endif
#ifndef INCLUDED_nme_display_CapsStyle
#include <nme/display/CapsStyle.h>
#endif
#ifndef INCLUDED_nme_display_InterpolationMethod
#include <nme/display/InterpolationMethod.h>
#endif
#ifndef INCLUDED_nme_display_JointStyle
#include <nme/display/JointStyle.h>
#endif
#ifndef INCLUDED_nme_display_LineScaleMode
#include <nme/display/LineScaleMode.h>
#endif
#ifndef INCLUDED_nme_display_SpreadMethod
#include <nme/display/SpreadMethod.h>
#endif
#ifndef INCLUDED_nme_geom_ColorTransform
#include <nme/geom/ColorTransform.h>
#endif
#ifndef INCLUDED_nme_geom_Matrix
#include <nme/geom/Matrix.h>
#endif
#ifndef INCLUDED_nme_geom_Rectangle
#include <nme/geom/Rectangle.h>
#endif
namespace neash{
namespace swf{

Void SWFStream_obj::__construct(::neash::utils::IDataInput inStream)
{
{
	this->mStream = inStream;
	::String sig0 = ::String::fromCharCode(this->mStream->readUnsignedByte());
	::String sig1 = ::String::fromCharCode(this->mStream->readUnsignedByte());
	::String sig2 = ::String::fromCharCode(this->mStream->readUnsignedByte());
	::String sig = (((sig0 + sig1)) + sig2);
	int ver = this->mStream->readUnsignedByte();
	if ((bool((sig != HX_STRING(L"FWS",3))) && bool((sig != HX_STRING(L"CWS",3)))))
		hx::Throw (HX_STRING(L"Invalid signature",17));
	if ((ver > 9))
		hx::Throw (HX_STRING(L"unknown swf version",19));
	this->mVersion = ver;
	int length = inStream->readInt();
	if ((sig == HX_STRING(L"CWS",3))){
		this->mStream = ::neash::utils::Uncompress_obj::ConvertStream(this->mStream,null());
	}
	this->mBitPos = 0;
	this->mByteBuf = 0;
	this->mTagRead = 0;
}
;
	return null();
}

SWFStream_obj::~SWFStream_obj() { }

Dynamic SWFStream_obj::__CreateEmpty() { return  new SWFStream_obj; }
hx::ObjectPtr< SWFStream_obj > SWFStream_obj::__new(::neash::utils::IDataInput inStream)
{  hx::ObjectPtr< SWFStream_obj > result = new SWFStream_obj();
	result->__construct(inStream);
	return result;}

Dynamic SWFStream_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< SWFStream_obj > result = new SWFStream_obj();
	result->__construct(inArgs[0]);
	return result;}

Void SWFStream_obj::close( ){
{
		this->mStream = null();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(SWFStream_obj,close,(void))

int SWFStream_obj::GetVersion( ){
	return this->mVersion;
}


HX_DEFINE_DYNAMIC_FUNC0(SWFStream_obj,GetVersion,return )

Void SWFStream_obj::AlignBits( ){
{
		this->mBitPos = 0;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(SWFStream_obj,AlignBits,(void))

int SWFStream_obj::Bits( int inBits,Dynamic inSigned){
	__SAFE_POINT
	int sign_bit = (inBits - 1);
	int result = 0;
	int left = inBits;
	while((left != 0)){
		__SAFE_POINT
		if ((this->mBitPos == 0)){
			this->mByteBuf = this->mStream->readUnsignedByte();
			this->mTagRead++;
			this->mBitPos = 8;
		}
		while((bool((this->mBitPos > 0)) && bool((left > 0)))){
			__SAFE_POINT
			result = (int(((int(result) << int(1)))) | int(((int(((int(this->mByteBuf) >> int(7)))) & int(1)))));
			this->mBitPos--;
			left--;
			hx::ShlEq(this->mByteBuf,1);
		}
	}
	if ((bool((inSigned != null())) && bool(inSigned))){
		int mask = ((int(1) << int(sign_bit)));
		if ((((int(result) & int(mask))) != 0))
			hx::SubEq(result,((int(1) << int(inBits))));
	}
	return result;
}


HX_DEFINE_DYNAMIC_FUNC2(SWFStream_obj,Bits,return )

double SWFStream_obj::Twips( int inBits){
	__SAFE_POINT
	int val = this->Bits(inBits,true);
	return (val * 0.05);
}


HX_DEFINE_DYNAMIC_FUNC1(SWFStream_obj,Twips,return )

bool SWFStream_obj::ReadBool( ){
	__SAFE_POINT
	return (this->Bits(1,null()) == 1);
}


HX_DEFINE_DYNAMIC_FUNC0(SWFStream_obj,ReadBool,return )

::nme::display::SpreadMethod SWFStream_obj::ReadSpreadMethod( ){
	__SAFE_POINT
	switch( (int)(this->Bits(2,null()))){
		case 0: {
			return ::nme::display::SpreadMethod_obj::PAD;
		}
		;break;
		case 1: {
			return ::nme::display::SpreadMethod_obj::REFLECT;
		}
		;break;
		case 2: {
			return ::nme::display::SpreadMethod_obj::REPEAT;
		}
		;break;
		case 3: {
			return ::nme::display::SpreadMethod_obj::PAD;
		}
		;break;
	}
	return ::nme::display::SpreadMethod_obj::REPEAT;
}


HX_DEFINE_DYNAMIC_FUNC0(SWFStream_obj,ReadSpreadMethod,return )

::nme::display::InterpolationMethod SWFStream_obj::ReadInterpolationMethod( ){
	__SAFE_POINT
	switch( (int)(this->Bits(2,null()))){
		case 0: {
			return ::nme::display::InterpolationMethod_obj::RGB;
		}
		;break;
		case 1: {
			return ::nme::display::InterpolationMethod_obj::LINEAR_RGB;
		}
		;break;
	}
	return ::nme::display::InterpolationMethod_obj::RGB;
}


HX_DEFINE_DYNAMIC_FUNC0(SWFStream_obj,ReadInterpolationMethod,return )

::nme::display::CapsStyle SWFStream_obj::ReadCapsStyle( ){
	__SAFE_POINT
	switch( (int)(this->Bits(2,null()))){
		case 0: {
			return ::nme::display::CapsStyle_obj::ROUND;
		}
		;break;
		case 1: {
			return ::nme::display::CapsStyle_obj::NONE;
		}
		;break;
		case 2: {
			return ::nme::display::CapsStyle_obj::SQUARE;
		}
		;break;
	}
	return ::nme::display::CapsStyle_obj::ROUND;
}


HX_DEFINE_DYNAMIC_FUNC0(SWFStream_obj,ReadCapsStyle,return )

::nme::display::JointStyle SWFStream_obj::ReadJoinStyle( ){
	__SAFE_POINT
	switch( (int)(this->Bits(2,null()))){
		case 0: {
			return ::nme::display::JointStyle_obj::ROUND;
		}
		;break;
		case 1: {
			return ::nme::display::JointStyle_obj::BEVEL;
		}
		;break;
		case 2: {
			return ::nme::display::JointStyle_obj::MITER;
		}
		;break;
	}
	return ::nme::display::JointStyle_obj::ROUND;
}


HX_DEFINE_DYNAMIC_FUNC0(SWFStream_obj,ReadJoinStyle,return )

::nme::display::LineScaleMode SWFStream_obj::ReadScaleMode( ){
	__SAFE_POINT
	switch( (int)(this->Bits(2,null()))){
		case 0: {
			return ::nme::display::LineScaleMode_obj::NORMAL;
		}
		;break;
		case 1: {
			return ::nme::display::LineScaleMode_obj::HORIZONTAL;
		}
		;break;
		case 2: {
			return ::nme::display::LineScaleMode_obj::VERTICAL;
		}
		;break;
		case 3: {
			return ::nme::display::LineScaleMode_obj::NONE;
		}
		;break;
	}
	return ::nme::display::LineScaleMode_obj::NORMAL;
}


HX_DEFINE_DYNAMIC_FUNC0(SWFStream_obj,ReadScaleMode,return )

::nme::geom::Rectangle SWFStream_obj::ReadRect( ){
	__SAFE_POINT
	this->AlignBits();
	int bits = this->Bits(5,null());
	double x0 = this->Twips(bits);
	double x1 = this->Twips(bits);
	double y0 = this->Twips(bits);
	double y1 = this->Twips(bits);
	return ::nme::geom::Rectangle_obj::__new(x0,y0,((x1 - x0)),((y1 - y0)));
}


HX_DEFINE_DYNAMIC_FUNC0(SWFStream_obj,ReadRect,return )

::String SWFStream_obj::ReadAlign( ){
	__SAFE_POINT
	int a = this->ReadByte();
	switch( (int)(a)){
		case 0: {
			return ::neash::text::TextFormatAlign_obj::LEFT;
		}
		;break;
		case 1: {
			return ::neash::text::TextFormatAlign_obj::RIGHT;
		}
		;break;
		case 2: {
			return ::neash::text::TextFormatAlign_obj::CENTER;
		}
		;break;
		case 3: {
			return ::neash::text::TextFormatAlign_obj::JUSTIFY;
		}
		;break;
	}
	return ::neash::text::TextFormatAlign_obj::LEFT;
}


HX_DEFINE_DYNAMIC_FUNC0(SWFStream_obj,ReadAlign,return )

double SWFStream_obj::FrameRate( ){
	__SAFE_POINT
	return (double(this->mStream->readUnsignedShort()) / double(256.0));
}


HX_DEFINE_DYNAMIC_FUNC0(SWFStream_obj,FrameRate,return )

int SWFStream_obj::Frames( ){
	__SAFE_POINT
	return this->mStream->readUnsignedShort();
}


HX_DEFINE_DYNAMIC_FUNC0(SWFStream_obj,Frames,return )

int SWFStream_obj::ReadID( ){
	__SAFE_POINT
	hx::AddEq(this->mTagRead,2);
	return this->mStream->readUnsignedShort();
}


HX_DEFINE_DYNAMIC_FUNC0(SWFStream_obj,ReadID,return )

int SWFStream_obj::ReadDepth( ){
	__SAFE_POINT
	hx::AddEq(this->mTagRead,2);
	return this->mStream->readUnsignedShort();
}


HX_DEFINE_DYNAMIC_FUNC0(SWFStream_obj,ReadDepth,return )

int SWFStream_obj::ReadUI16( ){
	__SAFE_POINT
	hx::AddEq(this->mTagRead,2);
	return this->mStream->readUnsignedShort();
}


HX_DEFINE_DYNAMIC_FUNC0(SWFStream_obj,ReadUI16,return )

int SWFStream_obj::ReadSI16( ){
	__SAFE_POINT
	hx::AddEq(this->mTagRead,2);
	return this->mStream->readShort();
}


HX_DEFINE_DYNAMIC_FUNC0(SWFStream_obj,ReadSI16,return )

double SWFStream_obj::ReadSTwips( ){
	__SAFE_POINT
	return (this->ReadSI16() * 0.05);
}


HX_DEFINE_DYNAMIC_FUNC0(SWFStream_obj,ReadSTwips,return )

double SWFStream_obj::ReadUTwips( ){
	__SAFE_POINT
	return (this->ReadUI16() * 0.05);
}


HX_DEFINE_DYNAMIC_FUNC0(SWFStream_obj,ReadUTwips,return )

int SWFStream_obj::ReadInt( ){
	__SAFE_POINT
	hx::AddEq(this->mTagRead,4);
	return this->mStream->readInt();
}


HX_DEFINE_DYNAMIC_FUNC0(SWFStream_obj,ReadInt,return )

int SWFStream_obj::ReadByte( ){
	__SAFE_POINT
	this->mTagRead++;
	return this->mStream->readUnsignedByte();
}


HX_DEFINE_DYNAMIC_FUNC0(SWFStream_obj,ReadByte,return )

int SWFStream_obj::ReadRGB( ){
	__SAFE_POINT
	hx::AddEq(this->mTagRead,3);
	int r = this->mStream->readUnsignedByte();
	int g = this->mStream->readUnsignedByte();
	int b = this->mStream->readUnsignedByte();
	return (int(((int(((int(r) << int(16)))) | int(((int(g) << int(8))))))) | int(b));
}


HX_DEFINE_DYNAMIC_FUNC0(SWFStream_obj,ReadRGB,return )

::String SWFStream_obj::ReadPascalString( ){
	__SAFE_POINT
	int len = this->ReadByte();
	::String result = HX_STRING(L"",0);
	{
		int _g = 0;
		while((_g < len)){
			__SAFE_POINT
			int i = _g++;
			int c = this->ReadByte();
			if ((c > 0))
				hx::AddEq(result,::String::fromCharCode(c));
		}
	}
	return result;
}


HX_DEFINE_DYNAMIC_FUNC0(SWFStream_obj,ReadPascalString,return )

::String SWFStream_obj::ReadString( ){
	__SAFE_POINT
	::String result = HX_STRING(L"",0);
	while(true){
		__SAFE_POINT
		int r = this->ReadByte();
		if ((r == 0))
			return result;
		hx::AddEq(result,::String::fromCharCode(r));
	}
	return result;
}


HX_DEFINE_DYNAMIC_FUNC0(SWFStream_obj,ReadString,return )

int SWFStream_obj::ReadArraySize( bool inExtended){
	__SAFE_POINT
	this->mTagRead++;
	int result = this->mStream->readUnsignedByte();
	if ((bool(inExtended) && bool((result == 255)))){
		hx::AddEq(this->mTagRead,2);
		result = this->mStream->readUnsignedShort();
	}
	return result;
}


HX_DEFINE_DYNAMIC_FUNC1(SWFStream_obj,ReadArraySize,return )

double SWFStream_obj::Fixed( int inBits){
	__SAFE_POINT
	return (double(this->Bits(inBits,true)) / double(65536.0));
}


HX_DEFINE_DYNAMIC_FUNC1(SWFStream_obj,Fixed,return )

::nme::geom::Matrix SWFStream_obj::ReadMatrix( ){
	__SAFE_POINT
	::nme::geom::Matrix result = ::nme::geom::Matrix_obj::__new(null(),null(),null(),null(),null(),null());
	this->AlignBits();
	bool has_scale = this->ReadBool();
	int scale_bits = has_scale ? int( this->Bits(5,null()) ) : int( 0 );
	result->a = has_scale ? double( this->Fixed(scale_bits) ) : double( 1.0 );
	result->d = has_scale ? double( this->Fixed(scale_bits) ) : double( 1.0 );
	bool has_rotate = this->ReadBool();
	int rotate_bits = has_rotate ? int( this->Bits(5,null()) ) : int( 0 );
	result->b = has_rotate ? double( this->Fixed(rotate_bits) ) : double( 0.0 );
	result->c = has_rotate ? double( this->Fixed(rotate_bits) ) : double( 0.0 );
	int trans_bits = this->Bits(5,null());
	result->tx = this->Twips(trans_bits);
	result->ty = this->Twips(trans_bits);
	return result;
}


HX_DEFINE_DYNAMIC_FUNC0(SWFStream_obj,ReadMatrix,return )

::nme::geom::ColorTransform SWFStream_obj::ReadColorTransform( ){
	__SAFE_POINT
	::nme::geom::ColorTransform result = ::nme::geom::ColorTransform_obj::__new(null(),null(),null(),null(),null(),null(),null(),null());
	bool has_add = this->ReadBool();
	bool has_mult = this->ReadBool();
	int bits = this->Bits(4,null());
	if (has_mult){
		result->redMultiplier = this->Bits(bits,true);
		result->greenMultiplier = this->Bits(bits,true);
		result->blueMultiplier = this->Bits(bits,true);
	}
	if (has_add){
		result->redOffset = this->Bits(bits,true);
		result->greenOffset = this->Bits(bits,true);
		result->blueOffset = this->Bits(bits,true);
	}
	return result;
}


HX_DEFINE_DYNAMIC_FUNC0(SWFStream_obj,ReadColorTransform,return )

int SWFStream_obj::BeginTag( ){
	__SAFE_POINT
	int data = this->mStream->readUnsignedShort();
	int tag = (int(data) >> int(6));
	int length = (int(data) & int(63));
	if ((tag >= ::neash::swf::Tags_obj::LAST))
		return 0;
	if ((length == 63))
		length = this->mStream->readUnsignedInt();
	this->mTagSize = length;
	this->mTagRead = 0;
	return tag;
}


HX_DEFINE_DYNAMIC_FUNC0(SWFStream_obj,BeginTag,return )

Void SWFStream_obj::EndTag( ){
{
		__SAFE_POINT
		int read = this->mTagRead;
		int size = this->mTagSize;
		if ((read > size))
			hx::Throw (HX_STRING(L"tag read overflow",17));
		while((read < size)){
			__SAFE_POINT
			this->mStream->readUnsignedByte();
			read++;
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(SWFStream_obj,EndTag,(void))

::haxe::io::Bytes SWFStream_obj::ReadBytes( int inSize){
	__SAFE_POINT
	::haxe::io::Bytes buffer = this->mStream->readBytes(inSize);
	hx::AddEq(this->mTagRead,inSize);
	return buffer;
}


HX_DEFINE_DYNAMIC_FUNC1(SWFStream_obj,ReadBytes,return )

int SWFStream_obj::BytesLeft( ){
	return (this->mTagSize - this->mTagRead);
}


HX_DEFINE_DYNAMIC_FUNC0(SWFStream_obj,BytesLeft,return )

Void SWFStream_obj::PushTag( ){
{
		this->mPushTagRead = this->mTagRead;
		this->mPushTagSize = this->mTagSize;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(SWFStream_obj,PushTag,(void))

Void SWFStream_obj::PopTag( ){
{
		this->mTagRead = this->mPushTagSize;
		this->mTagSize = this->mPushTagSize;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(SWFStream_obj,PopTag,(void))


SWFStream_obj::SWFStream_obj()
{
}

void SWFStream_obj::__Mark()
{
	hx::MarkMember(mStream);
	hx::MarkMember(mVersion);
	hx::MarkMember(mByteBuf);
	hx::MarkMember(mBitPos);
	hx::MarkMember(mTagSize);
	hx::MarkMember(mTagRead);
	hx::MarkMember(mPushTagSize);
	hx::MarkMember(mPushTagRead);
}

Dynamic SWFStream_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 4:
		if (!memcmp(inName.__s,L"Bits",sizeof(wchar_t)*4) ) { return Bits_dyn(); }
		break;
	case 5:
		if (!memcmp(inName.__s,L"close",sizeof(wchar_t)*5) ) { return close_dyn(); }
		if (!memcmp(inName.__s,L"Twips",sizeof(wchar_t)*5) ) { return Twips_dyn(); }
		if (!memcmp(inName.__s,L"Fixed",sizeof(wchar_t)*5) ) { return Fixed_dyn(); }
		break;
	case 6:
		if (!memcmp(inName.__s,L"Frames",sizeof(wchar_t)*6) ) { return Frames_dyn(); }
		if (!memcmp(inName.__s,L"ReadID",sizeof(wchar_t)*6) ) { return ReadID_dyn(); }
		if (!memcmp(inName.__s,L"EndTag",sizeof(wchar_t)*6) ) { return EndTag_dyn(); }
		if (!memcmp(inName.__s,L"PopTag",sizeof(wchar_t)*6) ) { return PopTag_dyn(); }
		break;
	case 7:
		if (!memcmp(inName.__s,L"mStream",sizeof(wchar_t)*7) ) { return mStream; }
		if (!memcmp(inName.__s,L"mBitPos",sizeof(wchar_t)*7) ) { return mBitPos; }
		if (!memcmp(inName.__s,L"ReadInt",sizeof(wchar_t)*7) ) { return ReadInt_dyn(); }
		if (!memcmp(inName.__s,L"ReadRGB",sizeof(wchar_t)*7) ) { return ReadRGB_dyn(); }
		if (!memcmp(inName.__s,L"PushTag",sizeof(wchar_t)*7) ) { return PushTag_dyn(); }
		break;
	case 8:
		if (!memcmp(inName.__s,L"mVersion",sizeof(wchar_t)*8) ) { return mVersion; }
		if (!memcmp(inName.__s,L"mByteBuf",sizeof(wchar_t)*8) ) { return mByteBuf; }
		if (!memcmp(inName.__s,L"mTagSize",sizeof(wchar_t)*8) ) { return mTagSize; }
		if (!memcmp(inName.__s,L"mTagRead",sizeof(wchar_t)*8) ) { return mTagRead; }
		if (!memcmp(inName.__s,L"ReadBool",sizeof(wchar_t)*8) ) { return ReadBool_dyn(); }
		if (!memcmp(inName.__s,L"ReadRect",sizeof(wchar_t)*8) ) { return ReadRect_dyn(); }
		if (!memcmp(inName.__s,L"ReadUI16",sizeof(wchar_t)*8) ) { return ReadUI16_dyn(); }
		if (!memcmp(inName.__s,L"ReadSI16",sizeof(wchar_t)*8) ) { return ReadSI16_dyn(); }
		if (!memcmp(inName.__s,L"ReadByte",sizeof(wchar_t)*8) ) { return ReadByte_dyn(); }
		if (!memcmp(inName.__s,L"BeginTag",sizeof(wchar_t)*8) ) { return BeginTag_dyn(); }
		break;
	case 9:
		if (!memcmp(inName.__s,L"AlignBits",sizeof(wchar_t)*9) ) { return AlignBits_dyn(); }
		if (!memcmp(inName.__s,L"ReadAlign",sizeof(wchar_t)*9) ) { return ReadAlign_dyn(); }
		if (!memcmp(inName.__s,L"FrameRate",sizeof(wchar_t)*9) ) { return FrameRate_dyn(); }
		if (!memcmp(inName.__s,L"ReadDepth",sizeof(wchar_t)*9) ) { return ReadDepth_dyn(); }
		if (!memcmp(inName.__s,L"ReadBytes",sizeof(wchar_t)*9) ) { return ReadBytes_dyn(); }
		if (!memcmp(inName.__s,L"BytesLeft",sizeof(wchar_t)*9) ) { return BytesLeft_dyn(); }
		break;
	case 10:
		if (!memcmp(inName.__s,L"GetVersion",sizeof(wchar_t)*10) ) { return GetVersion_dyn(); }
		if (!memcmp(inName.__s,L"ReadSTwips",sizeof(wchar_t)*10) ) { return ReadSTwips_dyn(); }
		if (!memcmp(inName.__s,L"ReadUTwips",sizeof(wchar_t)*10) ) { return ReadUTwips_dyn(); }
		if (!memcmp(inName.__s,L"ReadString",sizeof(wchar_t)*10) ) { return ReadString_dyn(); }
		if (!memcmp(inName.__s,L"ReadMatrix",sizeof(wchar_t)*10) ) { return ReadMatrix_dyn(); }
		break;
	case 12:
		if (!memcmp(inName.__s,L"mPushTagSize",sizeof(wchar_t)*12) ) { return mPushTagSize; }
		if (!memcmp(inName.__s,L"mPushTagRead",sizeof(wchar_t)*12) ) { return mPushTagRead; }
		break;
	case 13:
		if (!memcmp(inName.__s,L"ReadCapsStyle",sizeof(wchar_t)*13) ) { return ReadCapsStyle_dyn(); }
		if (!memcmp(inName.__s,L"ReadJoinStyle",sizeof(wchar_t)*13) ) { return ReadJoinStyle_dyn(); }
		if (!memcmp(inName.__s,L"ReadScaleMode",sizeof(wchar_t)*13) ) { return ReadScaleMode_dyn(); }
		if (!memcmp(inName.__s,L"ReadArraySize",sizeof(wchar_t)*13) ) { return ReadArraySize_dyn(); }
		break;
	case 16:
		if (!memcmp(inName.__s,L"ReadSpreadMethod",sizeof(wchar_t)*16) ) { return ReadSpreadMethod_dyn(); }
		if (!memcmp(inName.__s,L"ReadPascalString",sizeof(wchar_t)*16) ) { return ReadPascalString_dyn(); }
		break;
	case 18:
		if (!memcmp(inName.__s,L"ReadColorTransform",sizeof(wchar_t)*18) ) { return ReadColorTransform_dyn(); }
		break;
	case 23:
		if (!memcmp(inName.__s,L"ReadInterpolationMethod",sizeof(wchar_t)*23) ) { return ReadInterpolationMethod_dyn(); }
	}
	return super::__Field(inName);
}

Dynamic SWFStream_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	switch(inName.length) {
	case 7:
		if (!memcmp(inName.__s,L"mStream",sizeof(wchar_t)*7) ) { mStream=inValue.Cast< ::neash::utils::IDataInput >(); return inValue; }
		if (!memcmp(inName.__s,L"mBitPos",sizeof(wchar_t)*7) ) { mBitPos=inValue.Cast< int >(); return inValue; }
		break;
	case 8:
		if (!memcmp(inName.__s,L"mVersion",sizeof(wchar_t)*8) ) { mVersion=inValue.Cast< int >(); return inValue; }
		if (!memcmp(inName.__s,L"mByteBuf",sizeof(wchar_t)*8) ) { mByteBuf=inValue.Cast< int >(); return inValue; }
		if (!memcmp(inName.__s,L"mTagSize",sizeof(wchar_t)*8) ) { mTagSize=inValue.Cast< int >(); return inValue; }
		if (!memcmp(inName.__s,L"mTagRead",sizeof(wchar_t)*8) ) { mTagRead=inValue.Cast< int >(); return inValue; }
		break;
	case 12:
		if (!memcmp(inName.__s,L"mPushTagSize",sizeof(wchar_t)*12) ) { mPushTagSize=inValue.Cast< int >(); return inValue; }
		if (!memcmp(inName.__s,L"mPushTagRead",sizeof(wchar_t)*12) ) { mPushTagRead=inValue.Cast< int >(); return inValue; }
	}
	return super::__SetField(inName,inValue);
}

void SWFStream_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_STRING(L"mStream",7));
	outFields->push(HX_STRING(L"mVersion",8));
	outFields->push(HX_STRING(L"mByteBuf",8));
	outFields->push(HX_STRING(L"mBitPos",7));
	outFields->push(HX_STRING(L"mTagSize",8));
	outFields->push(HX_STRING(L"mTagRead",8));
	outFields->push(HX_STRING(L"mPushTagSize",12));
	outFields->push(HX_STRING(L"mPushTagRead",12));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_STRING(L"mStream",7),
	HX_STRING(L"mVersion",8),
	HX_STRING(L"mByteBuf",8),
	HX_STRING(L"mBitPos",7),
	HX_STRING(L"mTagSize",8),
	HX_STRING(L"mTagRead",8),
	HX_STRING(L"mPushTagSize",12),
	HX_STRING(L"mPushTagRead",12),
	HX_STRING(L"close",5),
	HX_STRING(L"GetVersion",10),
	HX_STRING(L"AlignBits",9),
	HX_STRING(L"Bits",4),
	HX_STRING(L"Twips",5),
	HX_STRING(L"ReadBool",8),
	HX_STRING(L"ReadSpreadMethod",16),
	HX_STRING(L"ReadInterpolationMethod",23),
	HX_STRING(L"ReadCapsStyle",13),
	HX_STRING(L"ReadJoinStyle",13),
	HX_STRING(L"ReadScaleMode",13),
	HX_STRING(L"ReadRect",8),
	HX_STRING(L"ReadAlign",9),
	HX_STRING(L"FrameRate",9),
	HX_STRING(L"Frames",6),
	HX_STRING(L"ReadID",6),
	HX_STRING(L"ReadDepth",9),
	HX_STRING(L"ReadUI16",8),
	HX_STRING(L"ReadSI16",8),
	HX_STRING(L"ReadSTwips",10),
	HX_STRING(L"ReadUTwips",10),
	HX_STRING(L"ReadInt",7),
	HX_STRING(L"ReadByte",8),
	HX_STRING(L"ReadRGB",7),
	HX_STRING(L"ReadPascalString",16),
	HX_STRING(L"ReadString",10),
	HX_STRING(L"ReadArraySize",13),
	HX_STRING(L"Fixed",5),
	HX_STRING(L"ReadMatrix",10),
	HX_STRING(L"ReadColorTransform",18),
	HX_STRING(L"BeginTag",8),
	HX_STRING(L"EndTag",6),
	HX_STRING(L"ReadBytes",9),
	HX_STRING(L"BytesLeft",9),
	HX_STRING(L"PushTag",7),
	HX_STRING(L"PopTag",6),
	String(null()) };

static void sMarkStatics() {
};

Class SWFStream_obj::__mClass;

void SWFStream_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_STRING(L"neash.swf.SWFStream",19), hx::TCanCast< SWFStream_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void SWFStream_obj::__boot()
{
}

} // end namespace neash
} // end namespace swf
