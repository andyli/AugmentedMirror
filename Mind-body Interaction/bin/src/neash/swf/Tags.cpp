#include <hxcpp.h>

#ifndef INCLUDED_neash_swf_Tags
#include <neash/swf/Tags.h>
#endif
namespace neash{
namespace swf{

Void Tags_obj::__construct()
{
	return null();
}

Tags_obj::~Tags_obj() { }

Dynamic Tags_obj::__CreateEmpty() { return  new Tags_obj; }
hx::ObjectPtr< Tags_obj > Tags_obj::__new()
{  hx::ObjectPtr< Tags_obj > result = new Tags_obj();
	result->__construct();
	return result;}

Dynamic Tags_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Tags_obj > result = new Tags_obj();
	result->__construct();
	return result;}

int Tags_obj::End;

int Tags_obj::ShowFrame;

int Tags_obj::DefineShape;

int Tags_obj::FreeCharacter;

int Tags_obj::PlaceObject;

int Tags_obj::RemoveObject;

int Tags_obj::DefineBits;

int Tags_obj::DefineButton;

int Tags_obj::JPEGTables;

int Tags_obj::SetBackgroundColor;

int Tags_obj::DefineFont;

int Tags_obj::DefineText;

int Tags_obj::DoAction;

int Tags_obj::DefineFontInfo;

int Tags_obj::DefineSound;

int Tags_obj::StartSound;

int Tags_obj::StopSound;

int Tags_obj::DefineButtonSound;

int Tags_obj::SoundStreamHead;

int Tags_obj::SoundStreamBlock;

int Tags_obj::DefineBitsLossless;

int Tags_obj::DefineBitsJPEG2;

int Tags_obj::DefineShape2;

int Tags_obj::DefineButtonCxform;

int Tags_obj::Protect;

int Tags_obj::PathsArePostScript;

int Tags_obj::PlaceObject2;

int Tags_obj::c27;

int Tags_obj::RemoveObject2;

int Tags_obj::SyncFrame;

int Tags_obj::c30;

int Tags_obj::FreeAll;

int Tags_obj::DefineShape3;

int Tags_obj::DefineText2;

int Tags_obj::DefineButton2;

int Tags_obj::DefineBitsJPEG3;

int Tags_obj::DefineBitsLossless2;

int Tags_obj::DefineEditText;

int Tags_obj::DefineVideo;

int Tags_obj::DefineSprite;

int Tags_obj::NameCharacter;

int Tags_obj::ProductInfo;

int Tags_obj::DefineTextFormat;

int Tags_obj::FrameLabel;

int Tags_obj::DefineBehavior;

int Tags_obj::SoundStreamHead2;

int Tags_obj::DefineMorphShape;

int Tags_obj::FrameTag;

int Tags_obj::DefineFont2;

int Tags_obj::GenCommand;

int Tags_obj::DefineCommandObj;

int Tags_obj::CharacterSet;

int Tags_obj::FontRef;

int Tags_obj::DefineFunction;

int Tags_obj::PlaceFunction;

int Tags_obj::GenTagObject;

int Tags_obj::ExportAssets;

int Tags_obj::ImportAssets;

int Tags_obj::EnableDebugger;

int Tags_obj::DoInitAction;

int Tags_obj::DefineVideoStream;

int Tags_obj::VideoFrame;

int Tags_obj::DefineFontInfo2;

int Tags_obj::DebugID;

int Tags_obj::EnableDebugger2;

int Tags_obj::ScriptLimits;

int Tags_obj::SetTabIndex;

int Tags_obj::DefineShape4_hmm;

int Tags_obj::c68;

int Tags_obj::FileAttributes;

int Tags_obj::PlaceObject3;

int Tags_obj::ImportAssets2;

int Tags_obj::DoABC;

int Tags_obj::DefineFontAlignZones;

int Tags_obj::CSMTextSettings;

int Tags_obj::DefineFont3;

int Tags_obj::SymbolClass;

int Tags_obj::MetaData;

int Tags_obj::DefineScalingGrid;

int Tags_obj::c79;

int Tags_obj::c80;

int Tags_obj::c81;

int Tags_obj::DoABC2;

int Tags_obj::DefineShape4;

int Tags_obj::DefineMorphShape2;

int Tags_obj::c85;

int Tags_obj::DefineSceneAndFrameLabelData;

int Tags_obj::DefineBinaryData;

int Tags_obj::DefineFontName;

int Tags_obj::StartSound2;

int Tags_obj::LAST;

Array< ::String > Tags_obj::tags;

::String Tags_obj::string( int i){
	return ::neash::swf::Tags_obj::tags->__get(i);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Tags_obj,string,return )


Tags_obj::Tags_obj()
{
}

void Tags_obj::__Mark()
{
}

Dynamic Tags_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 3:
		if (!memcmp(inName.__s,L"End",sizeof(wchar_t)*3) ) { return End; }
		if (!memcmp(inName.__s,L"c27",sizeof(wchar_t)*3) ) { return c27; }
		if (!memcmp(inName.__s,L"c30",sizeof(wchar_t)*3) ) { return c30; }
		if (!memcmp(inName.__s,L"c68",sizeof(wchar_t)*3) ) { return c68; }
		if (!memcmp(inName.__s,L"c79",sizeof(wchar_t)*3) ) { return c79; }
		if (!memcmp(inName.__s,L"c80",sizeof(wchar_t)*3) ) { return c80; }
		if (!memcmp(inName.__s,L"c81",sizeof(wchar_t)*3) ) { return c81; }
		if (!memcmp(inName.__s,L"c85",sizeof(wchar_t)*3) ) { return c85; }
		break;
	case 4:
		if (!memcmp(inName.__s,L"LAST",sizeof(wchar_t)*4) ) { return LAST; }
		if (!memcmp(inName.__s,L"tags",sizeof(wchar_t)*4) ) { return tags; }
		break;
	case 5:
		if (!memcmp(inName.__s,L"DoABC",sizeof(wchar_t)*5) ) { return DoABC; }
		break;
	case 6:
		if (!memcmp(inName.__s,L"DoABC2",sizeof(wchar_t)*6) ) { return DoABC2; }
		if (!memcmp(inName.__s,L"string",sizeof(wchar_t)*6) ) { return string_dyn(); }
		break;
	case 7:
		if (!memcmp(inName.__s,L"Protect",sizeof(wchar_t)*7) ) { return Protect; }
		if (!memcmp(inName.__s,L"FreeAll",sizeof(wchar_t)*7) ) { return FreeAll; }
		if (!memcmp(inName.__s,L"FontRef",sizeof(wchar_t)*7) ) { return FontRef; }
		if (!memcmp(inName.__s,L"DebugID",sizeof(wchar_t)*7) ) { return DebugID; }
		break;
	case 8:
		if (!memcmp(inName.__s,L"DoAction",sizeof(wchar_t)*8) ) { return DoAction; }
		if (!memcmp(inName.__s,L"FrameTag",sizeof(wchar_t)*8) ) { return FrameTag; }
		if (!memcmp(inName.__s,L"MetaData",sizeof(wchar_t)*8) ) { return MetaData; }
		break;
	case 9:
		if (!memcmp(inName.__s,L"ShowFrame",sizeof(wchar_t)*9) ) { return ShowFrame; }
		if (!memcmp(inName.__s,L"StopSound",sizeof(wchar_t)*9) ) { return StopSound; }
		if (!memcmp(inName.__s,L"SyncFrame",sizeof(wchar_t)*9) ) { return SyncFrame; }
		break;
	case 10:
		if (!memcmp(inName.__s,L"DefineBits",sizeof(wchar_t)*10) ) { return DefineBits; }
		if (!memcmp(inName.__s,L"JPEGTables",sizeof(wchar_t)*10) ) { return JPEGTables; }
		if (!memcmp(inName.__s,L"DefineFont",sizeof(wchar_t)*10) ) { return DefineFont; }
		if (!memcmp(inName.__s,L"DefineText",sizeof(wchar_t)*10) ) { return DefineText; }
		if (!memcmp(inName.__s,L"StartSound",sizeof(wchar_t)*10) ) { return StartSound; }
		if (!memcmp(inName.__s,L"FrameLabel",sizeof(wchar_t)*10) ) { return FrameLabel; }
		if (!memcmp(inName.__s,L"GenCommand",sizeof(wchar_t)*10) ) { return GenCommand; }
		if (!memcmp(inName.__s,L"VideoFrame",sizeof(wchar_t)*10) ) { return VideoFrame; }
		break;
	case 11:
		if (!memcmp(inName.__s,L"DefineShape",sizeof(wchar_t)*11) ) { return DefineShape; }
		if (!memcmp(inName.__s,L"PlaceObject",sizeof(wchar_t)*11) ) { return PlaceObject; }
		if (!memcmp(inName.__s,L"DefineSound",sizeof(wchar_t)*11) ) { return DefineSound; }
		if (!memcmp(inName.__s,L"DefineText2",sizeof(wchar_t)*11) ) { return DefineText2; }
		if (!memcmp(inName.__s,L"DefineVideo",sizeof(wchar_t)*11) ) { return DefineVideo; }
		if (!memcmp(inName.__s,L"ProductInfo",sizeof(wchar_t)*11) ) { return ProductInfo; }
		if (!memcmp(inName.__s,L"DefineFont2",sizeof(wchar_t)*11) ) { return DefineFont2; }
		if (!memcmp(inName.__s,L"SetTabIndex",sizeof(wchar_t)*11) ) { return SetTabIndex; }
		if (!memcmp(inName.__s,L"DefineFont3",sizeof(wchar_t)*11) ) { return DefineFont3; }
		if (!memcmp(inName.__s,L"SymbolClass",sizeof(wchar_t)*11) ) { return SymbolClass; }
		if (!memcmp(inName.__s,L"StartSound2",sizeof(wchar_t)*11) ) { return StartSound2; }
		break;
	case 12:
		if (!memcmp(inName.__s,L"RemoveObject",sizeof(wchar_t)*12) ) { return RemoveObject; }
		if (!memcmp(inName.__s,L"DefineButton",sizeof(wchar_t)*12) ) { return DefineButton; }
		if (!memcmp(inName.__s,L"DefineShape2",sizeof(wchar_t)*12) ) { return DefineShape2; }
		if (!memcmp(inName.__s,L"PlaceObject2",sizeof(wchar_t)*12) ) { return PlaceObject2; }
		if (!memcmp(inName.__s,L"DefineShape3",sizeof(wchar_t)*12) ) { return DefineShape3; }
		if (!memcmp(inName.__s,L"DefineSprite",sizeof(wchar_t)*12) ) { return DefineSprite; }
		if (!memcmp(inName.__s,L"CharacterSet",sizeof(wchar_t)*12) ) { return CharacterSet; }
		if (!memcmp(inName.__s,L"GenTagObject",sizeof(wchar_t)*12) ) { return GenTagObject; }
		if (!memcmp(inName.__s,L"ExportAssets",sizeof(wchar_t)*12) ) { return ExportAssets; }
		if (!memcmp(inName.__s,L"ImportAssets",sizeof(wchar_t)*12) ) { return ImportAssets; }
		if (!memcmp(inName.__s,L"DoInitAction",sizeof(wchar_t)*12) ) { return DoInitAction; }
		if (!memcmp(inName.__s,L"ScriptLimits",sizeof(wchar_t)*12) ) { return ScriptLimits; }
		if (!memcmp(inName.__s,L"PlaceObject3",sizeof(wchar_t)*12) ) { return PlaceObject3; }
		if (!memcmp(inName.__s,L"DefineShape4",sizeof(wchar_t)*12) ) { return DefineShape4; }
		break;
	case 13:
		if (!memcmp(inName.__s,L"FreeCharacter",sizeof(wchar_t)*13) ) { return FreeCharacter; }
		if (!memcmp(inName.__s,L"RemoveObject2",sizeof(wchar_t)*13) ) { return RemoveObject2; }
		if (!memcmp(inName.__s,L"DefineButton2",sizeof(wchar_t)*13) ) { return DefineButton2; }
		if (!memcmp(inName.__s,L"NameCharacter",sizeof(wchar_t)*13) ) { return NameCharacter; }
		if (!memcmp(inName.__s,L"PlaceFunction",sizeof(wchar_t)*13) ) { return PlaceFunction; }
		if (!memcmp(inName.__s,L"ImportAssets2",sizeof(wchar_t)*13) ) { return ImportAssets2; }
		break;
	case 14:
		if (!memcmp(inName.__s,L"DefineFontInfo",sizeof(wchar_t)*14) ) { return DefineFontInfo; }
		if (!memcmp(inName.__s,L"DefineEditText",sizeof(wchar_t)*14) ) { return DefineEditText; }
		if (!memcmp(inName.__s,L"DefineBehavior",sizeof(wchar_t)*14) ) { return DefineBehavior; }
		if (!memcmp(inName.__s,L"DefineFunction",sizeof(wchar_t)*14) ) { return DefineFunction; }
		if (!memcmp(inName.__s,L"EnableDebugger",sizeof(wchar_t)*14) ) { return EnableDebugger; }
		if (!memcmp(inName.__s,L"FileAttributes",sizeof(wchar_t)*14) ) { return FileAttributes; }
		if (!memcmp(inName.__s,L"DefineFontName",sizeof(wchar_t)*14) ) { return DefineFontName; }
		break;
	case 15:
		if (!memcmp(inName.__s,L"SoundStreamHead",sizeof(wchar_t)*15) ) { return SoundStreamHead; }
		if (!memcmp(inName.__s,L"DefineBitsJPEG2",sizeof(wchar_t)*15) ) { return DefineBitsJPEG2; }
		if (!memcmp(inName.__s,L"DefineBitsJPEG3",sizeof(wchar_t)*15) ) { return DefineBitsJPEG3; }
		if (!memcmp(inName.__s,L"DefineFontInfo2",sizeof(wchar_t)*15) ) { return DefineFontInfo2; }
		if (!memcmp(inName.__s,L"EnableDebugger2",sizeof(wchar_t)*15) ) { return EnableDebugger2; }
		if (!memcmp(inName.__s,L"CSMTextSettings",sizeof(wchar_t)*15) ) { return CSMTextSettings; }
		break;
	case 16:
		if (!memcmp(inName.__s,L"SoundStreamBlock",sizeof(wchar_t)*16) ) { return SoundStreamBlock; }
		if (!memcmp(inName.__s,L"DefineTextFormat",sizeof(wchar_t)*16) ) { return DefineTextFormat; }
		if (!memcmp(inName.__s,L"SoundStreamHead2",sizeof(wchar_t)*16) ) { return SoundStreamHead2; }
		if (!memcmp(inName.__s,L"DefineMorphShape",sizeof(wchar_t)*16) ) { return DefineMorphShape; }
		if (!memcmp(inName.__s,L"DefineCommandObj",sizeof(wchar_t)*16) ) { return DefineCommandObj; }
		if (!memcmp(inName.__s,L"DefineShape4_hmm",sizeof(wchar_t)*16) ) { return DefineShape4_hmm; }
		if (!memcmp(inName.__s,L"DefineBinaryData",sizeof(wchar_t)*16) ) { return DefineBinaryData; }
		break;
	case 17:
		if (!memcmp(inName.__s,L"DefineButtonSound",sizeof(wchar_t)*17) ) { return DefineButtonSound; }
		if (!memcmp(inName.__s,L"DefineVideoStream",sizeof(wchar_t)*17) ) { return DefineVideoStream; }
		if (!memcmp(inName.__s,L"DefineScalingGrid",sizeof(wchar_t)*17) ) { return DefineScalingGrid; }
		if (!memcmp(inName.__s,L"DefineMorphShape2",sizeof(wchar_t)*17) ) { return DefineMorphShape2; }
		break;
	case 18:
		if (!memcmp(inName.__s,L"SetBackgroundColor",sizeof(wchar_t)*18) ) { return SetBackgroundColor; }
		if (!memcmp(inName.__s,L"DefineBitsLossless",sizeof(wchar_t)*18) ) { return DefineBitsLossless; }
		if (!memcmp(inName.__s,L"DefineButtonCxform",sizeof(wchar_t)*18) ) { return DefineButtonCxform; }
		if (!memcmp(inName.__s,L"PathsArePostScript",sizeof(wchar_t)*18) ) { return PathsArePostScript; }
		break;
	case 19:
		if (!memcmp(inName.__s,L"DefineBitsLossless2",sizeof(wchar_t)*19) ) { return DefineBitsLossless2; }
		break;
	case 20:
		if (!memcmp(inName.__s,L"DefineFontAlignZones",sizeof(wchar_t)*20) ) { return DefineFontAlignZones; }
		break;
	case 28:
		if (!memcmp(inName.__s,L"DefineSceneAndFrameLabelData",sizeof(wchar_t)*28) ) { return DefineSceneAndFrameLabelData; }
	}
	return super::__Field(inName);
}

Dynamic Tags_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	switch(inName.length) {
	case 3:
		if (!memcmp(inName.__s,L"End",sizeof(wchar_t)*3) ) { End=inValue.Cast< int >(); return inValue; }
		if (!memcmp(inName.__s,L"c27",sizeof(wchar_t)*3) ) { c27=inValue.Cast< int >(); return inValue; }
		if (!memcmp(inName.__s,L"c30",sizeof(wchar_t)*3) ) { c30=inValue.Cast< int >(); return inValue; }
		if (!memcmp(inName.__s,L"c68",sizeof(wchar_t)*3) ) { c68=inValue.Cast< int >(); return inValue; }
		if (!memcmp(inName.__s,L"c79",sizeof(wchar_t)*3) ) { c79=inValue.Cast< int >(); return inValue; }
		if (!memcmp(inName.__s,L"c80",sizeof(wchar_t)*3) ) { c80=inValue.Cast< int >(); return inValue; }
		if (!memcmp(inName.__s,L"c81",sizeof(wchar_t)*3) ) { c81=inValue.Cast< int >(); return inValue; }
		if (!memcmp(inName.__s,L"c85",sizeof(wchar_t)*3) ) { c85=inValue.Cast< int >(); return inValue; }
		break;
	case 4:
		if (!memcmp(inName.__s,L"LAST",sizeof(wchar_t)*4) ) { LAST=inValue.Cast< int >(); return inValue; }
		if (!memcmp(inName.__s,L"tags",sizeof(wchar_t)*4) ) { tags=inValue.Cast< Array< ::String > >(); return inValue; }
		break;
	case 5:
		if (!memcmp(inName.__s,L"DoABC",sizeof(wchar_t)*5) ) { DoABC=inValue.Cast< int >(); return inValue; }
		break;
	case 6:
		if (!memcmp(inName.__s,L"DoABC2",sizeof(wchar_t)*6) ) { DoABC2=inValue.Cast< int >(); return inValue; }
		break;
	case 7:
		if (!memcmp(inName.__s,L"Protect",sizeof(wchar_t)*7) ) { Protect=inValue.Cast< int >(); return inValue; }
		if (!memcmp(inName.__s,L"FreeAll",sizeof(wchar_t)*7) ) { FreeAll=inValue.Cast< int >(); return inValue; }
		if (!memcmp(inName.__s,L"FontRef",sizeof(wchar_t)*7) ) { FontRef=inValue.Cast< int >(); return inValue; }
		if (!memcmp(inName.__s,L"DebugID",sizeof(wchar_t)*7) ) { DebugID=inValue.Cast< int >(); return inValue; }
		break;
	case 8:
		if (!memcmp(inName.__s,L"DoAction",sizeof(wchar_t)*8) ) { DoAction=inValue.Cast< int >(); return inValue; }
		if (!memcmp(inName.__s,L"FrameTag",sizeof(wchar_t)*8) ) { FrameTag=inValue.Cast< int >(); return inValue; }
		if (!memcmp(inName.__s,L"MetaData",sizeof(wchar_t)*8) ) { MetaData=inValue.Cast< int >(); return inValue; }
		break;
	case 9:
		if (!memcmp(inName.__s,L"ShowFrame",sizeof(wchar_t)*9) ) { ShowFrame=inValue.Cast< int >(); return inValue; }
		if (!memcmp(inName.__s,L"StopSound",sizeof(wchar_t)*9) ) { StopSound=inValue.Cast< int >(); return inValue; }
		if (!memcmp(inName.__s,L"SyncFrame",sizeof(wchar_t)*9) ) { SyncFrame=inValue.Cast< int >(); return inValue; }
		break;
	case 10:
		if (!memcmp(inName.__s,L"DefineBits",sizeof(wchar_t)*10) ) { DefineBits=inValue.Cast< int >(); return inValue; }
		if (!memcmp(inName.__s,L"JPEGTables",sizeof(wchar_t)*10) ) { JPEGTables=inValue.Cast< int >(); return inValue; }
		if (!memcmp(inName.__s,L"DefineFont",sizeof(wchar_t)*10) ) { DefineFont=inValue.Cast< int >(); return inValue; }
		if (!memcmp(inName.__s,L"DefineText",sizeof(wchar_t)*10) ) { DefineText=inValue.Cast< int >(); return inValue; }
		if (!memcmp(inName.__s,L"StartSound",sizeof(wchar_t)*10) ) { StartSound=inValue.Cast< int >(); return inValue; }
		if (!memcmp(inName.__s,L"FrameLabel",sizeof(wchar_t)*10) ) { FrameLabel=inValue.Cast< int >(); return inValue; }
		if (!memcmp(inName.__s,L"GenCommand",sizeof(wchar_t)*10) ) { GenCommand=inValue.Cast< int >(); return inValue; }
		if (!memcmp(inName.__s,L"VideoFrame",sizeof(wchar_t)*10) ) { VideoFrame=inValue.Cast< int >(); return inValue; }
		break;
	case 11:
		if (!memcmp(inName.__s,L"DefineShape",sizeof(wchar_t)*11) ) { DefineShape=inValue.Cast< int >(); return inValue; }
		if (!memcmp(inName.__s,L"PlaceObject",sizeof(wchar_t)*11) ) { PlaceObject=inValue.Cast< int >(); return inValue; }
		if (!memcmp(inName.__s,L"DefineSound",sizeof(wchar_t)*11) ) { DefineSound=inValue.Cast< int >(); return inValue; }
		if (!memcmp(inName.__s,L"DefineText2",sizeof(wchar_t)*11) ) { DefineText2=inValue.Cast< int >(); return inValue; }
		if (!memcmp(inName.__s,L"DefineVideo",sizeof(wchar_t)*11) ) { DefineVideo=inValue.Cast< int >(); return inValue; }
		if (!memcmp(inName.__s,L"ProductInfo",sizeof(wchar_t)*11) ) { ProductInfo=inValue.Cast< int >(); return inValue; }
		if (!memcmp(inName.__s,L"DefineFont2",sizeof(wchar_t)*11) ) { DefineFont2=inValue.Cast< int >(); return inValue; }
		if (!memcmp(inName.__s,L"SetTabIndex",sizeof(wchar_t)*11) ) { SetTabIndex=inValue.Cast< int >(); return inValue; }
		if (!memcmp(inName.__s,L"DefineFont3",sizeof(wchar_t)*11) ) { DefineFont3=inValue.Cast< int >(); return inValue; }
		if (!memcmp(inName.__s,L"SymbolClass",sizeof(wchar_t)*11) ) { SymbolClass=inValue.Cast< int >(); return inValue; }
		if (!memcmp(inName.__s,L"StartSound2",sizeof(wchar_t)*11) ) { StartSound2=inValue.Cast< int >(); return inValue; }
		break;
	case 12:
		if (!memcmp(inName.__s,L"RemoveObject",sizeof(wchar_t)*12) ) { RemoveObject=inValue.Cast< int >(); return inValue; }
		if (!memcmp(inName.__s,L"DefineButton",sizeof(wchar_t)*12) ) { DefineButton=inValue.Cast< int >(); return inValue; }
		if (!memcmp(inName.__s,L"DefineShape2",sizeof(wchar_t)*12) ) { DefineShape2=inValue.Cast< int >(); return inValue; }
		if (!memcmp(inName.__s,L"PlaceObject2",sizeof(wchar_t)*12) ) { PlaceObject2=inValue.Cast< int >(); return inValue; }
		if (!memcmp(inName.__s,L"DefineShape3",sizeof(wchar_t)*12) ) { DefineShape3=inValue.Cast< int >(); return inValue; }
		if (!memcmp(inName.__s,L"DefineSprite",sizeof(wchar_t)*12) ) { DefineSprite=inValue.Cast< int >(); return inValue; }
		if (!memcmp(inName.__s,L"CharacterSet",sizeof(wchar_t)*12) ) { CharacterSet=inValue.Cast< int >(); return inValue; }
		if (!memcmp(inName.__s,L"GenTagObject",sizeof(wchar_t)*12) ) { GenTagObject=inValue.Cast< int >(); return inValue; }
		if (!memcmp(inName.__s,L"ExportAssets",sizeof(wchar_t)*12) ) { ExportAssets=inValue.Cast< int >(); return inValue; }
		if (!memcmp(inName.__s,L"ImportAssets",sizeof(wchar_t)*12) ) { ImportAssets=inValue.Cast< int >(); return inValue; }
		if (!memcmp(inName.__s,L"DoInitAction",sizeof(wchar_t)*12) ) { DoInitAction=inValue.Cast< int >(); return inValue; }
		if (!memcmp(inName.__s,L"ScriptLimits",sizeof(wchar_t)*12) ) { ScriptLimits=inValue.Cast< int >(); return inValue; }
		if (!memcmp(inName.__s,L"PlaceObject3",sizeof(wchar_t)*12) ) { PlaceObject3=inValue.Cast< int >(); return inValue; }
		if (!memcmp(inName.__s,L"DefineShape4",sizeof(wchar_t)*12) ) { DefineShape4=inValue.Cast< int >(); return inValue; }
		break;
	case 13:
		if (!memcmp(inName.__s,L"FreeCharacter",sizeof(wchar_t)*13) ) { FreeCharacter=inValue.Cast< int >(); return inValue; }
		if (!memcmp(inName.__s,L"RemoveObject2",sizeof(wchar_t)*13) ) { RemoveObject2=inValue.Cast< int >(); return inValue; }
		if (!memcmp(inName.__s,L"DefineButton2",sizeof(wchar_t)*13) ) { DefineButton2=inValue.Cast< int >(); return inValue; }
		if (!memcmp(inName.__s,L"NameCharacter",sizeof(wchar_t)*13) ) { NameCharacter=inValue.Cast< int >(); return inValue; }
		if (!memcmp(inName.__s,L"PlaceFunction",sizeof(wchar_t)*13) ) { PlaceFunction=inValue.Cast< int >(); return inValue; }
		if (!memcmp(inName.__s,L"ImportAssets2",sizeof(wchar_t)*13) ) { ImportAssets2=inValue.Cast< int >(); return inValue; }
		break;
	case 14:
		if (!memcmp(inName.__s,L"DefineFontInfo",sizeof(wchar_t)*14) ) { DefineFontInfo=inValue.Cast< int >(); return inValue; }
		if (!memcmp(inName.__s,L"DefineEditText",sizeof(wchar_t)*14) ) { DefineEditText=inValue.Cast< int >(); return inValue; }
		if (!memcmp(inName.__s,L"DefineBehavior",sizeof(wchar_t)*14) ) { DefineBehavior=inValue.Cast< int >(); return inValue; }
		if (!memcmp(inName.__s,L"DefineFunction",sizeof(wchar_t)*14) ) { DefineFunction=inValue.Cast< int >(); return inValue; }
		if (!memcmp(inName.__s,L"EnableDebugger",sizeof(wchar_t)*14) ) { EnableDebugger=inValue.Cast< int >(); return inValue; }
		if (!memcmp(inName.__s,L"FileAttributes",sizeof(wchar_t)*14) ) { FileAttributes=inValue.Cast< int >(); return inValue; }
		if (!memcmp(inName.__s,L"DefineFontName",sizeof(wchar_t)*14) ) { DefineFontName=inValue.Cast< int >(); return inValue; }
		break;
	case 15:
		if (!memcmp(inName.__s,L"SoundStreamHead",sizeof(wchar_t)*15) ) { SoundStreamHead=inValue.Cast< int >(); return inValue; }
		if (!memcmp(inName.__s,L"DefineBitsJPEG2",sizeof(wchar_t)*15) ) { DefineBitsJPEG2=inValue.Cast< int >(); return inValue; }
		if (!memcmp(inName.__s,L"DefineBitsJPEG3",sizeof(wchar_t)*15) ) { DefineBitsJPEG3=inValue.Cast< int >(); return inValue; }
		if (!memcmp(inName.__s,L"DefineFontInfo2",sizeof(wchar_t)*15) ) { DefineFontInfo2=inValue.Cast< int >(); return inValue; }
		if (!memcmp(inName.__s,L"EnableDebugger2",sizeof(wchar_t)*15) ) { EnableDebugger2=inValue.Cast< int >(); return inValue; }
		if (!memcmp(inName.__s,L"CSMTextSettings",sizeof(wchar_t)*15) ) { CSMTextSettings=inValue.Cast< int >(); return inValue; }
		break;
	case 16:
		if (!memcmp(inName.__s,L"SoundStreamBlock",sizeof(wchar_t)*16) ) { SoundStreamBlock=inValue.Cast< int >(); return inValue; }
		if (!memcmp(inName.__s,L"DefineTextFormat",sizeof(wchar_t)*16) ) { DefineTextFormat=inValue.Cast< int >(); return inValue; }
		if (!memcmp(inName.__s,L"SoundStreamHead2",sizeof(wchar_t)*16) ) { SoundStreamHead2=inValue.Cast< int >(); return inValue; }
		if (!memcmp(inName.__s,L"DefineMorphShape",sizeof(wchar_t)*16) ) { DefineMorphShape=inValue.Cast< int >(); return inValue; }
		if (!memcmp(inName.__s,L"DefineCommandObj",sizeof(wchar_t)*16) ) { DefineCommandObj=inValue.Cast< int >(); return inValue; }
		if (!memcmp(inName.__s,L"DefineShape4_hmm",sizeof(wchar_t)*16) ) { DefineShape4_hmm=inValue.Cast< int >(); return inValue; }
		if (!memcmp(inName.__s,L"DefineBinaryData",sizeof(wchar_t)*16) ) { DefineBinaryData=inValue.Cast< int >(); return inValue; }
		break;
	case 17:
		if (!memcmp(inName.__s,L"DefineButtonSound",sizeof(wchar_t)*17) ) { DefineButtonSound=inValue.Cast< int >(); return inValue; }
		if (!memcmp(inName.__s,L"DefineVideoStream",sizeof(wchar_t)*17) ) { DefineVideoStream=inValue.Cast< int >(); return inValue; }
		if (!memcmp(inName.__s,L"DefineScalingGrid",sizeof(wchar_t)*17) ) { DefineScalingGrid=inValue.Cast< int >(); return inValue; }
		if (!memcmp(inName.__s,L"DefineMorphShape2",sizeof(wchar_t)*17) ) { DefineMorphShape2=inValue.Cast< int >(); return inValue; }
		break;
	case 18:
		if (!memcmp(inName.__s,L"SetBackgroundColor",sizeof(wchar_t)*18) ) { SetBackgroundColor=inValue.Cast< int >(); return inValue; }
		if (!memcmp(inName.__s,L"DefineBitsLossless",sizeof(wchar_t)*18) ) { DefineBitsLossless=inValue.Cast< int >(); return inValue; }
		if (!memcmp(inName.__s,L"DefineButtonCxform",sizeof(wchar_t)*18) ) { DefineButtonCxform=inValue.Cast< int >(); return inValue; }
		if (!memcmp(inName.__s,L"PathsArePostScript",sizeof(wchar_t)*18) ) { PathsArePostScript=inValue.Cast< int >(); return inValue; }
		break;
	case 19:
		if (!memcmp(inName.__s,L"DefineBitsLossless2",sizeof(wchar_t)*19) ) { DefineBitsLossless2=inValue.Cast< int >(); return inValue; }
		break;
	case 20:
		if (!memcmp(inName.__s,L"DefineFontAlignZones",sizeof(wchar_t)*20) ) { DefineFontAlignZones=inValue.Cast< int >(); return inValue; }
		break;
	case 28:
		if (!memcmp(inName.__s,L"DefineSceneAndFrameLabelData",sizeof(wchar_t)*28) ) { DefineSceneAndFrameLabelData=inValue.Cast< int >(); return inValue; }
	}
	return super::__SetField(inName,inValue);
}

void Tags_obj::__GetFields(Array< ::String> &outFields)
{
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_STRING(L"End",3),
	HX_STRING(L"ShowFrame",9),
	HX_STRING(L"DefineShape",11),
	HX_STRING(L"FreeCharacter",13),
	HX_STRING(L"PlaceObject",11),
	HX_STRING(L"RemoveObject",12),
	HX_STRING(L"DefineBits",10),
	HX_STRING(L"DefineButton",12),
	HX_STRING(L"JPEGTables",10),
	HX_STRING(L"SetBackgroundColor",18),
	HX_STRING(L"DefineFont",10),
	HX_STRING(L"DefineText",10),
	HX_STRING(L"DoAction",8),
	HX_STRING(L"DefineFontInfo",14),
	HX_STRING(L"DefineSound",11),
	HX_STRING(L"StartSound",10),
	HX_STRING(L"StopSound",9),
	HX_STRING(L"DefineButtonSound",17),
	HX_STRING(L"SoundStreamHead",15),
	HX_STRING(L"SoundStreamBlock",16),
	HX_STRING(L"DefineBitsLossless",18),
	HX_STRING(L"DefineBitsJPEG2",15),
	HX_STRING(L"DefineShape2",12),
	HX_STRING(L"DefineButtonCxform",18),
	HX_STRING(L"Protect",7),
	HX_STRING(L"PathsArePostScript",18),
	HX_STRING(L"PlaceObject2",12),
	HX_STRING(L"c27",3),
	HX_STRING(L"RemoveObject2",13),
	HX_STRING(L"SyncFrame",9),
	HX_STRING(L"c30",3),
	HX_STRING(L"FreeAll",7),
	HX_STRING(L"DefineShape3",12),
	HX_STRING(L"DefineText2",11),
	HX_STRING(L"DefineButton2",13),
	HX_STRING(L"DefineBitsJPEG3",15),
	HX_STRING(L"DefineBitsLossless2",19),
	HX_STRING(L"DefineEditText",14),
	HX_STRING(L"DefineVideo",11),
	HX_STRING(L"DefineSprite",12),
	HX_STRING(L"NameCharacter",13),
	HX_STRING(L"ProductInfo",11),
	HX_STRING(L"DefineTextFormat",16),
	HX_STRING(L"FrameLabel",10),
	HX_STRING(L"DefineBehavior",14),
	HX_STRING(L"SoundStreamHead2",16),
	HX_STRING(L"DefineMorphShape",16),
	HX_STRING(L"FrameTag",8),
	HX_STRING(L"DefineFont2",11),
	HX_STRING(L"GenCommand",10),
	HX_STRING(L"DefineCommandObj",16),
	HX_STRING(L"CharacterSet",12),
	HX_STRING(L"FontRef",7),
	HX_STRING(L"DefineFunction",14),
	HX_STRING(L"PlaceFunction",13),
	HX_STRING(L"GenTagObject",12),
	HX_STRING(L"ExportAssets",12),
	HX_STRING(L"ImportAssets",12),
	HX_STRING(L"EnableDebugger",14),
	HX_STRING(L"DoInitAction",12),
	HX_STRING(L"DefineVideoStream",17),
	HX_STRING(L"VideoFrame",10),
	HX_STRING(L"DefineFontInfo2",15),
	HX_STRING(L"DebugID",7),
	HX_STRING(L"EnableDebugger2",15),
	HX_STRING(L"ScriptLimits",12),
	HX_STRING(L"SetTabIndex",11),
	HX_STRING(L"DefineShape4_hmm",16),
	HX_STRING(L"c68",3),
	HX_STRING(L"FileAttributes",14),
	HX_STRING(L"PlaceObject3",12),
	HX_STRING(L"ImportAssets2",13),
	HX_STRING(L"DoABC",5),
	HX_STRING(L"DefineFontAlignZones",20),
	HX_STRING(L"CSMTextSettings",15),
	HX_STRING(L"DefineFont3",11),
	HX_STRING(L"SymbolClass",11),
	HX_STRING(L"MetaData",8),
	HX_STRING(L"DefineScalingGrid",17),
	HX_STRING(L"c79",3),
	HX_STRING(L"c80",3),
	HX_STRING(L"c81",3),
	HX_STRING(L"DoABC2",6),
	HX_STRING(L"DefineShape4",12),
	HX_STRING(L"DefineMorphShape2",17),
	HX_STRING(L"c85",3),
	HX_STRING(L"DefineSceneAndFrameLabelData",28),
	HX_STRING(L"DefineBinaryData",16),
	HX_STRING(L"DefineFontName",14),
	HX_STRING(L"StartSound2",11),
	HX_STRING(L"LAST",4),
	HX_STRING(L"tags",4),
	HX_STRING(L"string",6),
	String(null()) };

static ::String sMemberFields[] = {
	String(null()) };

static void sMarkStatics() {
	hx::MarkMember(Tags_obj::End);
	hx::MarkMember(Tags_obj::ShowFrame);
	hx::MarkMember(Tags_obj::DefineShape);
	hx::MarkMember(Tags_obj::FreeCharacter);
	hx::MarkMember(Tags_obj::PlaceObject);
	hx::MarkMember(Tags_obj::RemoveObject);
	hx::MarkMember(Tags_obj::DefineBits);
	hx::MarkMember(Tags_obj::DefineButton);
	hx::MarkMember(Tags_obj::JPEGTables);
	hx::MarkMember(Tags_obj::SetBackgroundColor);
	hx::MarkMember(Tags_obj::DefineFont);
	hx::MarkMember(Tags_obj::DefineText);
	hx::MarkMember(Tags_obj::DoAction);
	hx::MarkMember(Tags_obj::DefineFontInfo);
	hx::MarkMember(Tags_obj::DefineSound);
	hx::MarkMember(Tags_obj::StartSound);
	hx::MarkMember(Tags_obj::StopSound);
	hx::MarkMember(Tags_obj::DefineButtonSound);
	hx::MarkMember(Tags_obj::SoundStreamHead);
	hx::MarkMember(Tags_obj::SoundStreamBlock);
	hx::MarkMember(Tags_obj::DefineBitsLossless);
	hx::MarkMember(Tags_obj::DefineBitsJPEG2);
	hx::MarkMember(Tags_obj::DefineShape2);
	hx::MarkMember(Tags_obj::DefineButtonCxform);
	hx::MarkMember(Tags_obj::Protect);
	hx::MarkMember(Tags_obj::PathsArePostScript);
	hx::MarkMember(Tags_obj::PlaceObject2);
	hx::MarkMember(Tags_obj::c27);
	hx::MarkMember(Tags_obj::RemoveObject2);
	hx::MarkMember(Tags_obj::SyncFrame);
	hx::MarkMember(Tags_obj::c30);
	hx::MarkMember(Tags_obj::FreeAll);
	hx::MarkMember(Tags_obj::DefineShape3);
	hx::MarkMember(Tags_obj::DefineText2);
	hx::MarkMember(Tags_obj::DefineButton2);
	hx::MarkMember(Tags_obj::DefineBitsJPEG3);
	hx::MarkMember(Tags_obj::DefineBitsLossless2);
	hx::MarkMember(Tags_obj::DefineEditText);
	hx::MarkMember(Tags_obj::DefineVideo);
	hx::MarkMember(Tags_obj::DefineSprite);
	hx::MarkMember(Tags_obj::NameCharacter);
	hx::MarkMember(Tags_obj::ProductInfo);
	hx::MarkMember(Tags_obj::DefineTextFormat);
	hx::MarkMember(Tags_obj::FrameLabel);
	hx::MarkMember(Tags_obj::DefineBehavior);
	hx::MarkMember(Tags_obj::SoundStreamHead2);
	hx::MarkMember(Tags_obj::DefineMorphShape);
	hx::MarkMember(Tags_obj::FrameTag);
	hx::MarkMember(Tags_obj::DefineFont2);
	hx::MarkMember(Tags_obj::GenCommand);
	hx::MarkMember(Tags_obj::DefineCommandObj);
	hx::MarkMember(Tags_obj::CharacterSet);
	hx::MarkMember(Tags_obj::FontRef);
	hx::MarkMember(Tags_obj::DefineFunction);
	hx::MarkMember(Tags_obj::PlaceFunction);
	hx::MarkMember(Tags_obj::GenTagObject);
	hx::MarkMember(Tags_obj::ExportAssets);
	hx::MarkMember(Tags_obj::ImportAssets);
	hx::MarkMember(Tags_obj::EnableDebugger);
	hx::MarkMember(Tags_obj::DoInitAction);
	hx::MarkMember(Tags_obj::DefineVideoStream);
	hx::MarkMember(Tags_obj::VideoFrame);
	hx::MarkMember(Tags_obj::DefineFontInfo2);
	hx::MarkMember(Tags_obj::DebugID);
	hx::MarkMember(Tags_obj::EnableDebugger2);
	hx::MarkMember(Tags_obj::ScriptLimits);
	hx::MarkMember(Tags_obj::SetTabIndex);
	hx::MarkMember(Tags_obj::DefineShape4_hmm);
	hx::MarkMember(Tags_obj::c68);
	hx::MarkMember(Tags_obj::FileAttributes);
	hx::MarkMember(Tags_obj::PlaceObject3);
	hx::MarkMember(Tags_obj::ImportAssets2);
	hx::MarkMember(Tags_obj::DoABC);
	hx::MarkMember(Tags_obj::DefineFontAlignZones);
	hx::MarkMember(Tags_obj::CSMTextSettings);
	hx::MarkMember(Tags_obj::DefineFont3);
	hx::MarkMember(Tags_obj::SymbolClass);
	hx::MarkMember(Tags_obj::MetaData);
	hx::MarkMember(Tags_obj::DefineScalingGrid);
	hx::MarkMember(Tags_obj::c79);
	hx::MarkMember(Tags_obj::c80);
	hx::MarkMember(Tags_obj::c81);
	hx::MarkMember(Tags_obj::DoABC2);
	hx::MarkMember(Tags_obj::DefineShape4);
	hx::MarkMember(Tags_obj::DefineMorphShape2);
	hx::MarkMember(Tags_obj::c85);
	hx::MarkMember(Tags_obj::DefineSceneAndFrameLabelData);
	hx::MarkMember(Tags_obj::DefineBinaryData);
	hx::MarkMember(Tags_obj::DefineFontName);
	hx::MarkMember(Tags_obj::StartSound2);
	hx::MarkMember(Tags_obj::LAST);
	hx::MarkMember(Tags_obj::tags);
};

Class Tags_obj::__mClass;

void Tags_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_STRING(L"neash.swf.Tags",14), hx::TCanCast< Tags_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void Tags_obj::__boot()
{
	hx::Static(End) = 0;
	hx::Static(ShowFrame) = 1;
	hx::Static(DefineShape) = 2;
	hx::Static(FreeCharacter) = 3;
	hx::Static(PlaceObject) = 4;
	hx::Static(RemoveObject) = 5;
	hx::Static(DefineBits) = 6;
	hx::Static(DefineButton) = 7;
	hx::Static(JPEGTables) = 8;
	hx::Static(SetBackgroundColor) = 9;
	hx::Static(DefineFont) = 10;
	hx::Static(DefineText) = 11;
	hx::Static(DoAction) = 12;
	hx::Static(DefineFontInfo) = 13;
	hx::Static(DefineSound) = 14;
	hx::Static(StartSound) = 15;
	hx::Static(StopSound) = 16;
	hx::Static(DefineButtonSound) = 17;
	hx::Static(SoundStreamHead) = 18;
	hx::Static(SoundStreamBlock) = 19;
	hx::Static(DefineBitsLossless) = 20;
	hx::Static(DefineBitsJPEG2) = 21;
	hx::Static(DefineShape2) = 22;
	hx::Static(DefineButtonCxform) = 23;
	hx::Static(Protect) = 24;
	hx::Static(PathsArePostScript) = 25;
	hx::Static(PlaceObject2) = 26;
	hx::Static(c27) = 27;
	hx::Static(RemoveObject2) = 28;
	hx::Static(SyncFrame) = 29;
	hx::Static(c30) = 30;
	hx::Static(FreeAll) = 31;
	hx::Static(DefineShape3) = 32;
	hx::Static(DefineText2) = 33;
	hx::Static(DefineButton2) = 34;
	hx::Static(DefineBitsJPEG3) = 35;
	hx::Static(DefineBitsLossless2) = 36;
	hx::Static(DefineEditText) = 37;
	hx::Static(DefineVideo) = 38;
	hx::Static(DefineSprite) = 39;
	hx::Static(NameCharacter) = 40;
	hx::Static(ProductInfo) = 41;
	hx::Static(DefineTextFormat) = 42;
	hx::Static(FrameLabel) = 43;
	hx::Static(DefineBehavior) = 44;
	hx::Static(SoundStreamHead2) = 45;
	hx::Static(DefineMorphShape) = 46;
	hx::Static(FrameTag) = 47;
	hx::Static(DefineFont2) = 48;
	hx::Static(GenCommand) = 49;
	hx::Static(DefineCommandObj) = 50;
	hx::Static(CharacterSet) = 51;
	hx::Static(FontRef) = 52;
	hx::Static(DefineFunction) = 53;
	hx::Static(PlaceFunction) = 54;
	hx::Static(GenTagObject) = 55;
	hx::Static(ExportAssets) = 56;
	hx::Static(ImportAssets) = 57;
	hx::Static(EnableDebugger) = 58;
	hx::Static(DoInitAction) = 59;
	hx::Static(DefineVideoStream) = 60;
	hx::Static(VideoFrame) = 61;
	hx::Static(DefineFontInfo2) = 62;
	hx::Static(DebugID) = 63;
	hx::Static(EnableDebugger2) = 64;
	hx::Static(ScriptLimits) = 65;
	hx::Static(SetTabIndex) = 66;
	hx::Static(DefineShape4_hmm) = 67;
	hx::Static(c68) = 68;
	hx::Static(FileAttributes) = 69;
	hx::Static(PlaceObject3) = 70;
	hx::Static(ImportAssets2) = 71;
	hx::Static(DoABC) = 72;
	hx::Static(DefineFontAlignZones) = 73;
	hx::Static(CSMTextSettings) = 74;
	hx::Static(DefineFont3) = 75;
	hx::Static(SymbolClass) = 76;
	hx::Static(MetaData) = 77;
	hx::Static(DefineScalingGrid) = 78;
	hx::Static(c79) = 79;
	hx::Static(c80) = 80;
	hx::Static(c81) = 81;
	hx::Static(DoABC2) = 82;
	hx::Static(DefineShape4) = 83;
	hx::Static(DefineMorphShape2) = 84;
	hx::Static(c85) = 85;
	hx::Static(DefineSceneAndFrameLabelData) = 86;
	hx::Static(DefineBinaryData) = 87;
	hx::Static(DefineFontName) = 88;
	hx::Static(StartSound2) = 89;
	hx::Static(LAST) = 90;
	hx::Static(tags) = Array_obj< ::String >::__new().Add(HX_STRING(L"End",3)).Add(HX_STRING(L"ShowFrame",9)).Add(HX_STRING(L"DefineShape",11)).Add(HX_STRING(L"FreeCharacter",13)).Add(HX_STRING(L"PlaceObject",11)).Add(HX_STRING(L"RemoveObject",12)).Add(HX_STRING(L"DefineBits",10)).Add(HX_STRING(L"DefineButton",12)).Add(HX_STRING(L"JPEGTables",10)).Add(HX_STRING(L"SetBackgroundColor",18)).Add(HX_STRING(L"DefineFont",10)).Add(HX_STRING(L"DefineText",10)).Add(HX_STRING(L"DoAction",8)).Add(HX_STRING(L"DefineFontInfo",14)).Add(HX_STRING(L"DefineSound",11)).Add(HX_STRING(L"StartSound",10)).Add(HX_STRING(L"StopSound",9)).Add(HX_STRING(L"DefineButtonSound",17)).Add(HX_STRING(L"SoundStreamHead",15)).Add(HX_STRING(L"SoundStreamBlock",16)).Add(HX_STRING(L"DefineBitsLossless",18)).Add(HX_STRING(L"DefineBitsJPEG2",15)).Add(HX_STRING(L"DefineShape2",12)).Add(HX_STRING(L"DefineButtonCxform",18)).Add(HX_STRING(L"Protect",7)).Add(HX_STRING(L"PathsArePostScript",18)).Add(HX_STRING(L"PlaceObject2",12)).Add(HX_STRING(L"27 (invalid)",12)).Add(HX_STRING(L"RemoveObject2",13)).Add(HX_STRING(L"SyncFrame",9)).Add(HX_STRING(L"30 (invalid)",12)).Add(HX_STRING(L"FreeAll",7)).Add(HX_STRING(L"DefineShape3",12)).Add(HX_STRING(L"DefineText2",11)).Add(HX_STRING(L"DefineButton2",13)).Add(HX_STRING(L"DefineBitsJPEG3",15)).Add(HX_STRING(L"DefineBitsLossless2",19)).Add(HX_STRING(L"DefineEditText",14)).Add(HX_STRING(L"DefineVideo",11)).Add(HX_STRING(L"DefineSprite",12)).Add(HX_STRING(L"NameCharacter",13)).Add(HX_STRING(L"ProductInfo",11)).Add(HX_STRING(L"DefineTextFormat",16)).Add(HX_STRING(L"FrameLabel",10)).Add(HX_STRING(L"DefineBehavior",14)).Add(HX_STRING(L"SoundStreamHead2",16)).Add(HX_STRING(L"DefineMorphShape",16)).Add(HX_STRING(L"FrameTag",8)).Add(HX_STRING(L"DefineFont2",11)).Add(HX_STRING(L"GenCommand",10)).Add(HX_STRING(L"DefineCommandObj",16)).Add(HX_STRING(L"CharacterSet",12)).Add(HX_STRING(L"FontRef",7)).Add(HX_STRING(L"DefineFunction",14)).Add(HX_STRING(L"PlaceFunction",13)).Add(HX_STRING(L"GenTagObject",12)).Add(HX_STRING(L"ExportAssets",12)).Add(HX_STRING(L"ImportAssets",12)).Add(HX_STRING(L"EnableDebugger",14)).Add(HX_STRING(L"DoInitAction",12)).Add(HX_STRING(L"DefineVideoStream",17)).Add(HX_STRING(L"VideoFrame",10)).Add(HX_STRING(L"DefineFontInfo2",15)).Add(HX_STRING(L"DebugID",7)).Add(HX_STRING(L"EnableDebugger2",15)).Add(HX_STRING(L"ScriptLimits",12)).Add(HX_STRING(L"SetTabIndex",11)).Add(HX_STRING(L"DefineShape4",12)).Add(HX_STRING(L"DefineMorphShape2",17)).Add(HX_STRING(L"FileAttributes",14)).Add(HX_STRING(L"PlaceObject3",12)).Add(HX_STRING(L"ImportAssets2",13)).Add(HX_STRING(L"DoABC",5)).Add(HX_STRING(L"DefineFontAlignZones",20)).Add(HX_STRING(L"CSMTextSettings",15)).Add(HX_STRING(L"DefineFont3",11)).Add(HX_STRING(L"SymbolClass",11)).Add(HX_STRING(L"Metadata",8)).Add(HX_STRING(L"DefineScalingGrid",17)).Add(HX_STRING(L"79 (invalid)",12)).Add(HX_STRING(L"80 (invalid)",12)).Add(HX_STRING(L"81 (invalid)",12)).Add(HX_STRING(L"DoABC2",6)).Add(HX_STRING(L"DefineShape4",12)).Add(HX_STRING(L"DefineMorphShape2",17)).Add(HX_STRING(L"c85",3)).Add(HX_STRING(L"DefineSceneAndFrameLabelData",28)).Add(HX_STRING(L"DefineBinaryData",16)).Add(HX_STRING(L"DefineFontName",14)).Add(HX_STRING(L"StartSound2",11)).Add(HX_STRING(L"LAST",4));
}

} // end namespace neash
} // end namespace swf
