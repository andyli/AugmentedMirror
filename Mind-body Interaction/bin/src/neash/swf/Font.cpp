#include <hxcpp.h>

#ifndef INCLUDED_haxe_Log
#include <haxe/Log.h>
#endif
#ifndef INCLUDED_neash_swf_Font
#include <neash/swf/Font.h>
#endif
#ifndef INCLUDED_neash_swf_SWFStream
#include <neash/swf/SWFStream.h>
#endif
#ifndef INCLUDED_neash_text_FontManager
#include <neash/text/FontManager.h>
#endif
#ifndef INCLUDED_nme_geom_Matrix
#include <nme/geom/Matrix.h>
#endif
namespace neash{
namespace swf{

Void Font_obj::__construct(::neash::swf::SWFStream inStream,int inVersion)
{
{
	this->mGlyphs = Array_obj< Dynamic >::__new();
	inStream->AlignBits();
	bool has_layout = (bool(((inVersion > 1))) && bool(inStream->ReadBool()));
	bool has_jis = (bool(((inVersion > 1))) && bool(inStream->ReadBool()));
	bool small_text = (bool(((inVersion > 1))) && bool(inStream->ReadBool()));
	bool is_ansi = (bool(((inVersion > 1))) && bool(inStream->ReadBool()));
	bool wide_offsets = (bool(((inVersion > 1))) && bool(inStream->ReadBool()));
	bool wide_codes = (bool(((inVersion > 1))) && bool(inStream->ReadBool()));
	bool italic = (bool(((inVersion > 1))) && bool(inStream->ReadBool()));
	bool bold = (bool(((inVersion > 1))) && bool(inStream->ReadBool()));
	int lang_code = ((inVersion > 1)) ? int( inStream->ReadByte() ) : int( 0 );
	this->mName = ((inVersion > 1)) ? ::String( inStream->ReadPascalString() ) : ::String( HX_STRING(L"font",4) );
	int n;
	int s0;
	Array< int > offsets = Array_obj< int >::__new();
	int code_offset = 0;
	double v3scale = (inVersion > 2) ? double( 1.0 ) : double( 0.05 );
	if ((inVersion > 1)){
		n = inStream->ReadUI16();
		s0 = inStream->BytesLeft();
		{
			int _g = 0;
			while((_g < n)){
				__SAFE_POINT
				int i = _g++;
				offsets->push(wide_offsets ? int( inStream->ReadInt() ) : int( inStream->ReadUI16() ));
			}
		}
		code_offset = wide_offsets ? int( inStream->ReadInt() ) : int( inStream->ReadUI16() );
		code_offset = (s0 - code_offset);
	}
	else{
		s0 = inStream->BytesLeft();
		int o0 = inStream->ReadUI16();
		n = (int(o0) >> int(1));
		offsets->push(o0);
		{
			int _g = 1;
			while((_g < n)){
				__SAFE_POINT
				int i = _g++;
				offsets->push(inStream->ReadUI16());
			}
		}
	}
	Dynamic access_last = this->mGlyphs->__get((n - 1));
	inStream->AlignBits();
	{
		int _g = 0;
		while((_g < n)){
			__SAFE_POINT
			int i = _g++;
			if ((inStream->BytesLeft() != ((s0 - offsets->__get(i)))))
				hx::Throw (((((((((HX_STRING(L"bad offset in font stream (",27) + inStream->BytesLeft())) + HX_STRING(L"!=",2))) + ((s0 - offsets->__get(i))))) + HX_STRING(L")",1))));
			bool moved = false;
			double pen_x = 0.0;
			double pen_y = 0.0;
			Array< Dynamic > commands = Array_obj< Dynamic >::__new();
			inStream->AlignBits();
			int fill_bits = inStream->Bits(4,null());
			int line_bits = inStream->Bits(4,null());
			while(true){
				__SAFE_POINT
				bool edge = inStream->ReadBool();
				if (!edge){
					bool new_styles = inStream->ReadBool();
					bool new_line_style = inStream->ReadBool();
					bool new_fill_style1 = inStream->ReadBool();
					bool new_fill_style0 = inStream->ReadBool();
					bool move_to = inStream->ReadBool();
					if ((bool(new_styles) || bool((bool(new_styles) || bool(new_fill_style1)))))
						hx::Throw (((((((((((HX_STRING(L"fill style can't be changed here ",33) + new_styles)) + HX_STRING(L",",1))) + new_styles)) + HX_STRING(L",",1))) + new_fill_style0)));
					if (!move_to)
						break;
					if ((bool(!new_fill_style0) && bool((commands->length == 0))))
						hx::Throw (HX_STRING(L"fill style should be defined",28));
					int bits = inStream->Bits(5,null());
					pen_x = (inStream->Twips(bits) * v3scale);
					pen_y = (inStream->Twips(bits) * v3scale);
					Array< double > px = Array_obj< double >::__new().Add(pen_x);
					Array< double > py = Array_obj< double >::__new().Add(pen_y);

					HX_BEGIN_LOCAL_FUNC2(_Function_5_1,Array< double >,px,Array< double >,py)
					Void run(Dynamic g,::nme::geom::Matrix m){
{
							__SAFE_POINT
							g->__Field(HX_STRING(L"moveTo",6))(((((px->__get(0) * m->a) + (py->__get(0) * m->c))) + m->tx),((((px->__get(0) * m->b) + (py->__get(0) * m->d))) + m->ty));
						}
						return null();
					}
					HX_END_LOCAL_FUNC2((void))

					commands->push( Dynamic(new _Function_5_1(px,py)));
					if (new_fill_style0){
						int fill_style = inStream->Bits(1,null());
					}
				}
				else{
					if (inStream->ReadBool()){
						int delta_bits = (inStream->Bits(4,null()) + 2);
						if (inStream->ReadBool()){
							hx::AddEq(pen_x,(inStream->Twips(delta_bits) * v3scale));
							hx::AddEq(pen_y,(inStream->Twips(delta_bits) * v3scale));
						}
						else{
							if (inStream->ReadBool()){
								hx::AddEq(pen_y,(inStream->Twips(delta_bits) * v3scale));
							}
							else{
								hx::AddEq(pen_x,(inStream->Twips(delta_bits) * v3scale));
							}
						}
						Array< double > px = Array_obj< double >::__new().Add(pen_x);
						Array< double > py = Array_obj< double >::__new().Add(pen_y);

						HX_BEGIN_LOCAL_FUNC2(_Function_6_1,Array< double >,px,Array< double >,py)
						Void run(Dynamic g,::nme::geom::Matrix m){
{
								__SAFE_POINT
								g->__Field(HX_STRING(L"lineTo",6))(((((px->__get(0) * m->a) + (py->__get(0) * m->c))) + m->tx),((((px->__get(0) * m->b) + (py->__get(0) * m->d))) + m->ty));
							}
							return null();
						}
						HX_END_LOCAL_FUNC2((void))

						commands->push( Dynamic(new _Function_6_1(px,py)));
					}
					else{
						int delta_bits = (inStream->Bits(4,null()) + 2);
						Array< double > cx = Array_obj< double >::__new().Add((pen_x + (inStream->Twips(delta_bits) * v3scale)));
						Array< double > cy = Array_obj< double >::__new().Add((pen_y + (inStream->Twips(delta_bits) * v3scale)));
						Array< double > px = Array_obj< double >::__new().Add((cx->__get(0) + (inStream->Twips(delta_bits) * v3scale)));
						Array< double > py = Array_obj< double >::__new().Add((cy->__get(0) + (inStream->Twips(delta_bits) * v3scale)));
						pen_x = px->__get(0);
						pen_y = py->__get(0);

						HX_BEGIN_LOCAL_FUNC4(_Function_6_1,Array< double >,py,Array< double >,cy,Array< double >,px,Array< double >,cx)
						Void run(Dynamic g,::nme::geom::Matrix m){
{
								__SAFE_POINT
								g->__Field(HX_STRING(L"curveTo",7))(((((cx->__get(0) * m->a) + (cy->__get(0) * m->c))) + m->tx),((((cx->__get(0) * m->b) + (cy->__get(0) * m->d))) + m->ty),((((px->__get(0) * m->a) + (py->__get(0) * m->c))) + m->tx),((((px->__get(0) * m->b) + (py->__get(0) * m->d))) + m->ty));
							}
							return null();
						}
						HX_END_LOCAL_FUNC2((void))

						commands->push( Dynamic(new _Function_6_1(py,cy,px,cx)));
					}
				}
			}

			HX_BEGIN_LOCAL_FUNC0(_Function_3_1)
			Void run(Dynamic g,::nme::geom::Matrix m){
{
					__SAFE_POINT
					g->__Field(HX_STRING(L"endFill",7))();
				}
				return null();
			}
			HX_END_LOCAL_FUNC2((void))

			commands->push( Dynamic(new _Function_3_1()));
			struct _Function_3_2{
				inline static Dynamic Block( Array< Dynamic > &commands){
					hx::Anon __result = hx::Anon_obj::Create();
					__result->Add(HX_STRING(L"mCommands",9) , commands);
					__result->Add(HX_STRING(L"mAdvance",8) , 1024.0);
					return __result;
				}
			};
			this->mGlyphs[i] = _Function_3_2::Block(commands);
		}
	}
	if ((code_offset != 0)){
		inStream->AlignBits();
		if ((inStream->BytesLeft() != code_offset))
			hx::Throw (HX_STRING(L"Code offset miscaculation",25));
		this->mCodeToGlyph = Array_obj< Dynamic >::__new();
		{
			int _g = 0;
			while((_g < n)){
				__SAFE_POINT
				int i = _g++;
				int code = wide_codes ? int( inStream->ReadUI16() ) : int( inStream->ReadByte() );
				this->mCodeToGlyph[code] = this->mGlyphs->__get(i);
			}
		}
	}
	else{
		this->mCodeToGlyph = this->mGlyphs;
	}
	if (has_layout){
		this->mAscent = inStream->ReadSTwips();
		this->mDescent = inStream->ReadSTwips();
		this->mLeading = inStream->ReadSTwips();
		this->mAdvance = Array_obj< double >::__new();
		{
			int _g = 0;
			while((_g < n)){
				__SAFE_POINT
				int i = _g++;
				this->mGlyphs[i]->__FieldRef(HX_STRING(L"mAdvance",8)) = inStream->ReadSTwips();
			}
		}
	}
	else{
		this->mAscent = 800;
		this->mDescent = 224;
		this->mLeading = 0;
	}
	::neash::text::FontManager_obj::RegisterFont(this);
}
;
	return null();
}

Font_obj::~Font_obj() { }

Dynamic Font_obj::__CreateEmpty() { return  new Font_obj; }
hx::ObjectPtr< Font_obj > Font_obj::__new(::neash::swf::SWFStream inStream,int inVersion)
{  hx::ObjectPtr< Font_obj > result = new Font_obj();
	result->__construct(inStream,inVersion);
	return result;}

Dynamic Font_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Font_obj > result = new Font_obj();
	result->__construct(inArgs[0],inArgs[1]);
	return result;}

Void Font_obj::RestoreLineStyle( Dynamic g){
{
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Font_obj,RestoreLineStyle,(void))

bool Font_obj::Ok( ){
	return true;
}


HX_DEFINE_DYNAMIC_FUNC0(Font_obj,Ok,return )

::String Font_obj::GetName( ){
	return this->mName;
}


HX_DEFINE_DYNAMIC_FUNC0(Font_obj,GetName,return )

double Font_obj::RenderChar( Dynamic inGraphics,int inChar,::nme::geom::Matrix m){
	__SAFE_POINT
	if ((this->mCodeToGlyph->length > inChar)){
		Dynamic glyph = this->mCodeToGlyph->__get(inChar);
		if ((glyph != null())){
			{
				int _g = 0;
				Array< Dynamic > _g1 = glyph->__Field(HX_STRING(L"mCommands",9)).Cast< Array< Dynamic > >();
				while((_g < _g1->length)){
					__SAFE_POINT
					Dynamic c = _g1->__get(_g);
					++_g;
					c(inGraphics,m);
				}
			}
			return glyph->__Field(HX_STRING(L"mAdvance",8)).Cast< double >();
		}
	}
	return 0;
}


HX_DEFINE_DYNAMIC_FUNC3(Font_obj,RenderChar,return )

Void Font_obj::RenderGlyph( Dynamic inGraphics,int inGlyph,::nme::geom::Matrix m){
{
		__SAFE_POINT
		if ((this->mGlyphs->length > inGlyph)){
			Array< Dynamic > commands = this->mGlyphs[inGlyph]->__Field(HX_STRING(L"mCommands",9)).Cast< Array< Dynamic > >();
			{
				int _g = 0;
				while((_g < commands->length)){
					__SAFE_POINT
					Dynamic c = commands->__get(_g);
					++_g;
					c(inGraphics,m);
				}
			}
		}
		else{
			struct _Function_2_1{
				inline static Dynamic Block( ){
					hx::Anon __result = hx::Anon_obj::Create();
					__result->Add(HX_STRING(L"fileName",8) , HX_STRING(L"Font.hx",7));
					__result->Add(HX_STRING(L"lineNumber",10) , 265);
					__result->Add(HX_STRING(L"className",9) , HX_STRING(L"neash.swf.Font",14));
					__result->Add(HX_STRING(L"methodName",10) , HX_STRING(L"RenderGlyph",11));
					return __result;
				}
			};
			::haxe::Log_obj::trace((HX_STRING(L"Unsupported glyph: ",19) + ::String::fromCharCode(inGlyph)),_Function_2_1::Block());
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC3(Font_obj,RenderGlyph,(void))

double Font_obj::GetAdvance( int inChar,Dynamic inNext){
	if ((this->mCodeToGlyph->length > inChar)){
		Dynamic glyph = this->mCodeToGlyph->__get(inChar);
		if ((glyph != null()))
			return glyph->__Field(HX_STRING(L"mAdvance",8)).Cast< double >();
	}
	return 1024.0;
}


HX_DEFINE_DYNAMIC_FUNC2(Font_obj,GetAdvance,return )

double Font_obj::GetAscent( ){
	return this->mAscent;
}


HX_DEFINE_DYNAMIC_FUNC0(Font_obj,GetAscent,return )

double Font_obj::GetDescent( ){
	return this->mDescent;
}


HX_DEFINE_DYNAMIC_FUNC0(Font_obj,GetDescent,return )

double Font_obj::GetLeading( ){
	return this->mLeading;
}


HX_DEFINE_DYNAMIC_FUNC0(Font_obj,GetLeading,return )


Font_obj::Font_obj()
{
}

void Font_obj::__Mark()
{
	hx::MarkMember(mGlyphs);
	hx::MarkMember(mCodeToGlyph);
	hx::MarkMember(mName);
	hx::MarkMember(mAscent);
	hx::MarkMember(mDescent);
	hx::MarkMember(mLeading);
	hx::MarkMember(mAdvance);
}

Dynamic Font_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 2:
		if (!memcmp(inName.__s,L"Ok",sizeof(wchar_t)*2) ) { return Ok_dyn(); }
		break;
	case 5:
		if (!memcmp(inName.__s,L"mName",sizeof(wchar_t)*5) ) { return mName; }
		break;
	case 7:
		if (!memcmp(inName.__s,L"mGlyphs",sizeof(wchar_t)*7) ) { return mGlyphs; }
		if (!memcmp(inName.__s,L"mAscent",sizeof(wchar_t)*7) ) { return mAscent; }
		if (!memcmp(inName.__s,L"GetName",sizeof(wchar_t)*7) ) { return GetName_dyn(); }
		break;
	case 8:
		if (!memcmp(inName.__s,L"mDescent",sizeof(wchar_t)*8) ) { return mDescent; }
		if (!memcmp(inName.__s,L"mLeading",sizeof(wchar_t)*8) ) { return mLeading; }
		if (!memcmp(inName.__s,L"mAdvance",sizeof(wchar_t)*8) ) { return mAdvance; }
		break;
	case 9:
		if (!memcmp(inName.__s,L"GetAscent",sizeof(wchar_t)*9) ) { return GetAscent_dyn(); }
		break;
	case 10:
		if (!memcmp(inName.__s,L"RenderChar",sizeof(wchar_t)*10) ) { return RenderChar_dyn(); }
		if (!memcmp(inName.__s,L"GetAdvance",sizeof(wchar_t)*10) ) { return GetAdvance_dyn(); }
		if (!memcmp(inName.__s,L"GetDescent",sizeof(wchar_t)*10) ) { return GetDescent_dyn(); }
		if (!memcmp(inName.__s,L"GetLeading",sizeof(wchar_t)*10) ) { return GetLeading_dyn(); }
		break;
	case 11:
		if (!memcmp(inName.__s,L"RenderGlyph",sizeof(wchar_t)*11) ) { return RenderGlyph_dyn(); }
		break;
	case 12:
		if (!memcmp(inName.__s,L"mCodeToGlyph",sizeof(wchar_t)*12) ) { return mCodeToGlyph; }
		break;
	case 16:
		if (!memcmp(inName.__s,L"RestoreLineStyle",sizeof(wchar_t)*16) ) { return RestoreLineStyle_dyn(); }
	}
	return super::__Field(inName);
}

Dynamic Font_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	switch(inName.length) {
	case 5:
		if (!memcmp(inName.__s,L"mName",sizeof(wchar_t)*5) ) { mName=inValue.Cast< ::String >(); return inValue; }
		break;
	case 7:
		if (!memcmp(inName.__s,L"mGlyphs",sizeof(wchar_t)*7) ) { mGlyphs=inValue.Cast< Array< Dynamic > >(); return inValue; }
		if (!memcmp(inName.__s,L"mAscent",sizeof(wchar_t)*7) ) { mAscent=inValue.Cast< double >(); return inValue; }
		break;
	case 8:
		if (!memcmp(inName.__s,L"mDescent",sizeof(wchar_t)*8) ) { mDescent=inValue.Cast< double >(); return inValue; }
		if (!memcmp(inName.__s,L"mLeading",sizeof(wchar_t)*8) ) { mLeading=inValue.Cast< double >(); return inValue; }
		if (!memcmp(inName.__s,L"mAdvance",sizeof(wchar_t)*8) ) { mAdvance=inValue.Cast< Array< double > >(); return inValue; }
		break;
	case 12:
		if (!memcmp(inName.__s,L"mCodeToGlyph",sizeof(wchar_t)*12) ) { mCodeToGlyph=inValue.Cast< Array< Dynamic > >(); return inValue; }
	}
	return super::__SetField(inName,inValue);
}

void Font_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_STRING(L"mGlyphs",7));
	outFields->push(HX_STRING(L"mCodeToGlyph",12));
	outFields->push(HX_STRING(L"mName",5));
	outFields->push(HX_STRING(L"mAscent",7));
	outFields->push(HX_STRING(L"mDescent",8));
	outFields->push(HX_STRING(L"mLeading",8));
	outFields->push(HX_STRING(L"mAdvance",8));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_STRING(L"mGlyphs",7),
	HX_STRING(L"mCodeToGlyph",12),
	HX_STRING(L"mName",5),
	HX_STRING(L"mAscent",7),
	HX_STRING(L"mDescent",8),
	HX_STRING(L"mLeading",8),
	HX_STRING(L"mAdvance",8),
	HX_STRING(L"RestoreLineStyle",16),
	HX_STRING(L"Ok",2),
	HX_STRING(L"GetName",7),
	HX_STRING(L"RenderChar",10),
	HX_STRING(L"RenderGlyph",11),
	HX_STRING(L"GetAdvance",10),
	HX_STRING(L"GetAscent",9),
	HX_STRING(L"GetDescent",10),
	HX_STRING(L"GetLeading",10),
	String(null()) };

static void sMarkStatics() {
};

Class Font_obj::__mClass;

void Font_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_STRING(L"neash.swf.Font",14), hx::TCanCast< Font_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void Font_obj::__boot()
{
}

} // end namespace neash
} // end namespace swf
