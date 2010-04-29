#ifndef INCLUDED_neash_swf_Tags
#define INCLUDED_neash_swf_Tags

#include <hxcpp.h>

HX_DECLARE_CLASS2(neash,swf,Tags)
namespace neash{
namespace swf{


class Tags_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef Tags_obj OBJ_;
		Tags_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< Tags_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~Tags_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark();
		::String __ToString() const { return HX_STRING(L"Tags",4); }

		static int End; /* REM */ 
		static int ShowFrame; /* REM */ 
		static int DefineShape; /* REM */ 
		static int FreeCharacter; /* REM */ 
		static int PlaceObject; /* REM */ 
		static int RemoveObject; /* REM */ 
		static int DefineBits; /* REM */ 
		static int DefineButton; /* REM */ 
		static int JPEGTables; /* REM */ 
		static int SetBackgroundColor; /* REM */ 
		static int DefineFont; /* REM */ 
		static int DefineText; /* REM */ 
		static int DoAction; /* REM */ 
		static int DefineFontInfo; /* REM */ 
		static int DefineSound; /* REM */ 
		static int StartSound; /* REM */ 
		static int StopSound; /* REM */ 
		static int DefineButtonSound; /* REM */ 
		static int SoundStreamHead; /* REM */ 
		static int SoundStreamBlock; /* REM */ 
		static int DefineBitsLossless; /* REM */ 
		static int DefineBitsJPEG2; /* REM */ 
		static int DefineShape2; /* REM */ 
		static int DefineButtonCxform; /* REM */ 
		static int Protect; /* REM */ 
		static int PathsArePostScript; /* REM */ 
		static int PlaceObject2; /* REM */ 
		static int c27; /* REM */ 
		static int RemoveObject2; /* REM */ 
		static int SyncFrame; /* REM */ 
		static int c30; /* REM */ 
		static int FreeAll; /* REM */ 
		static int DefineShape3; /* REM */ 
		static int DefineText2; /* REM */ 
		static int DefineButton2; /* REM */ 
		static int DefineBitsJPEG3; /* REM */ 
		static int DefineBitsLossless2; /* REM */ 
		static int DefineEditText; /* REM */ 
		static int DefineVideo; /* REM */ 
		static int DefineSprite; /* REM */ 
		static int NameCharacter; /* REM */ 
		static int ProductInfo; /* REM */ 
		static int DefineTextFormat; /* REM */ 
		static int FrameLabel; /* REM */ 
		static int DefineBehavior; /* REM */ 
		static int SoundStreamHead2; /* REM */ 
		static int DefineMorphShape; /* REM */ 
		static int FrameTag; /* REM */ 
		static int DefineFont2; /* REM */ 
		static int GenCommand; /* REM */ 
		static int DefineCommandObj; /* REM */ 
		static int CharacterSet; /* REM */ 
		static int FontRef; /* REM */ 
		static int DefineFunction; /* REM */ 
		static int PlaceFunction; /* REM */ 
		static int GenTagObject; /* REM */ 
		static int ExportAssets; /* REM */ 
		static int ImportAssets; /* REM */ 
		static int EnableDebugger; /* REM */ 
		static int DoInitAction; /* REM */ 
		static int DefineVideoStream; /* REM */ 
		static int VideoFrame; /* REM */ 
		static int DefineFontInfo2; /* REM */ 
		static int DebugID; /* REM */ 
		static int EnableDebugger2; /* REM */ 
		static int ScriptLimits; /* REM */ 
		static int SetTabIndex; /* REM */ 
		static int DefineShape4_hmm; /* REM */ 
		static int c68; /* REM */ 
		static int FileAttributes; /* REM */ 
		static int PlaceObject3; /* REM */ 
		static int ImportAssets2; /* REM */ 
		static int DoABC; /* REM */ 
		static int DefineFontAlignZones; /* REM */ 
		static int CSMTextSettings; /* REM */ 
		static int DefineFont3; /* REM */ 
		static int SymbolClass; /* REM */ 
		static int MetaData; /* REM */ 
		static int DefineScalingGrid; /* REM */ 
		static int c79; /* REM */ 
		static int c80; /* REM */ 
		static int c81; /* REM */ 
		static int DoABC2; /* REM */ 
		static int DefineShape4; /* REM */ 
		static int DefineMorphShape2; /* REM */ 
		static int c85; /* REM */ 
		static int DefineSceneAndFrameLabelData; /* REM */ 
		static int DefineBinaryData; /* REM */ 
		static int DefineFontName; /* REM */ 
		static int StartSound2; /* REM */ 
		static int LAST; /* REM */ 
		static Array< ::String > tags; /* REM */ 
		static ::String string( int i);
		static Dynamic string_dyn();

};

} // end namespace neash
} // end namespace swf

#endif /* INCLUDED_neash_swf_Tags */ 
