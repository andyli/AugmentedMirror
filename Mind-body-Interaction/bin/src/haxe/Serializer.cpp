#include <hxcpp.h>

#ifndef INCLUDED_Hash
#include <Hash.h>
#endif
#ifndef INCLUDED_IntHash
#include <IntHash.h>
#endif
#ifndef INCLUDED_List
#include <List.h>
#endif
#ifndef INCLUDED_hxMath
#include <hxMath.h>
#endif
#ifndef INCLUDED_Reflect
#include <Reflect.h>
#endif
#ifndef INCLUDED_Std
#include <Std.h>
#endif
#ifndef INCLUDED_StringBuf
#include <StringBuf.h>
#endif
#ifndef INCLUDED_StringTools
#include <StringTools.h>
#endif
#ifndef INCLUDED_Type
#include <Type.h>
#endif
#ifndef INCLUDED_ValueType
#include <ValueType.h>
#endif
#ifndef INCLUDED_cpp_CppDate__
#include <cpp/CppDate__.h>
#endif
#ifndef INCLUDED_haxe_Serializer
#include <haxe/Serializer.h>
#endif
#ifndef INCLUDED_haxe_io_Bytes
#include <haxe/io/Bytes.h>
#endif
namespace haxe{

Void Serializer_obj::__construct()
{
{
	this->buf = ::StringBuf_obj::__new();
	this->cache = Array_obj< Dynamic >::__new();
	this->useCache = ::haxe::Serializer_obj::USE_CACHE;
	this->useEnumIndex = ::haxe::Serializer_obj::USE_ENUM_INDEX;
	this->shash = ::Hash_obj::__new();
	this->scount = 0;
}
;
	return null();
}

Serializer_obj::~Serializer_obj() { }

Dynamic Serializer_obj::__CreateEmpty() { return  new Serializer_obj; }
hx::ObjectPtr< Serializer_obj > Serializer_obj::__new()
{  hx::ObjectPtr< Serializer_obj > result = new Serializer_obj();
	result->__construct();
	return result;}

Dynamic Serializer_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Serializer_obj > result = new Serializer_obj();
	result->__construct();
	return result;}

::String Serializer_obj::toString( ){
	__SAFE_POINT
	return this->buf->b->join(HX_STRING(L"",0));
}


HX_DEFINE_DYNAMIC_FUNC0(Serializer_obj,toString,return )

Void Serializer_obj::serializeString( ::String s){
{
		__SAFE_POINT
		Dynamic x = this->shash->get(s);
		if ((x != null())){
			{
				::StringBuf _g = this->buf;
				_g->b[_g->b->length] = HX_STRING(L"R",1);
			}
			{
				::StringBuf _g = this->buf;
				_g->b[_g->b->length] = x;
			}
			return null();
		}
		this->shash->set(s,this->scount++);
		{
			::StringBuf _g = this->buf;
			_g->b[_g->b->length] = HX_STRING(L"y",1);
		}
		s = ::StringTools_obj::urlEncode(s);
		{
			::StringBuf _g = this->buf;
			_g->b[_g->b->length] = s.length;
		}
		{
			::StringBuf _g = this->buf;
			_g->b[_g->b->length] = HX_STRING(L":",1);
		}
		{
			::StringBuf _g = this->buf;
			_g->b[_g->b->length] = s;
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Serializer_obj,serializeString,(void))

bool Serializer_obj::serializeRef( Dynamic v){
	__SAFE_POINT
	{
		int _g1 = 0;
		int _g = this->cache->length;
		while((_g1 < _g)){
			__SAFE_POINT
			int i = _g1++;
			if ((this->cache->__get(i) == v)){
				{
					::StringBuf _g2 = this->buf;
					_g2->b[_g2->b->length] = HX_STRING(L"r",1);
				}
				{
					::StringBuf _g2 = this->buf;
					_g2->b[_g2->b->length] = i;
				}
				return true;
			}
		}
	}
	this->cache->push(v);
	return false;
}


HX_DEFINE_DYNAMIC_FUNC1(Serializer_obj,serializeRef,return )

Void Serializer_obj::serializeFields( Dynamic v){
{
		__SAFE_POINT
		{
			int _g = 0;
			Array< ::String > _g1 = ::Reflect_obj::fields(v);
			while((_g < _g1->length)){
				__SAFE_POINT
				::String f = _g1->__get(_g);
				++_g;
				this->serializeString(f);
				this->serialize(((v == null())) ? Dynamic( null() ) : Dynamic( v->__Field(f) ));
			}
		}
		{
			::StringBuf _g = this->buf;
			_g->b[_g->b->length] = HX_STRING(L"g",1);
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Serializer_obj,serializeFields,(void))

Void Serializer_obj::serialize( Dynamic v){
{
		__SAFE_POINT
		::ValueType _switch_1 = (::Type_obj::_typeof(v));
		switch((_switch_1)->GetIndex()){
			case 0: {
				{
					::StringBuf _g = this->buf;
					_g->b[_g->b->length] = HX_STRING(L"n",1);
				}
			}
			;break;
			case 1: {
				if ((v == 0)){
					{
						::StringBuf _g = this->buf;
						_g->b[_g->b->length] = HX_STRING(L"z",1);
					}
					return null();
				}
				{
					::StringBuf _g = this->buf;
					_g->b[_g->b->length] = HX_STRING(L"i",1);
				}
				{
					::StringBuf _g = this->buf;
					_g->b[_g->b->length] = v;
				}
			}
			;break;
			case 2: {
				if (::Math_obj::isNaN(v)){
					::StringBuf _g = this->buf;
					_g->b[_g->b->length] = HX_STRING(L"k",1);
				}
				else{
					if (!::Math_obj::isFinite(v)){
						::StringBuf _g = this->buf;
						_g->b[_g->b->length] = (v < 0) ? ::String( HX_STRING(L"m",1) ) : ::String( HX_STRING(L"p",1) );
					}
					else{
						{
							::StringBuf _g = this->buf;
							_g->b[_g->b->length] = HX_STRING(L"d",1);
						}
						{
							::StringBuf _g = this->buf;
							_g->b[_g->b->length] = v;
						}
					}
				}
			}
			;break;
			case 3: {
				{
					::StringBuf _g = this->buf;
					_g->b[_g->b->length] = v ? ::String( HX_STRING(L"t",1) ) : ::String( HX_STRING(L"f",1) );
				}
			}
			;break;
			case 6: {
				::Class c = _switch_1->__Param(0);
{
					if ((c == hx::ClassOf< ::String >())){
						this->serializeString(v);
						return null();
					}
					if ((bool(this->useCache) && bool(this->serializeRef(v))))
						return null();
					::Class _switch_2 = (c);
					if (  ( _switch_2==hx::ClassOf< Array<int> >())){
						int ucount = 0;
						{
							::StringBuf _g = this->buf;
							_g->b[_g->b->length] = HX_STRING(L"a",1);
						}
						int l = v->__length();
						{
							int _g = 0;
							while((_g < l)){
								__SAFE_POINT
								int i = _g++;
								if ((v[i] == null())){
									ucount++;
								}
								else{
									if ((ucount > 0)){
										if ((ucount == 1)){
											::StringBuf _g1 = this->buf;
											_g1->b[_g1->b->length] = HX_STRING(L"n",1);
										}
										else{
											{
												::StringBuf _g1 = this->buf;
												_g1->b[_g1->b->length] = HX_STRING(L"u",1);
											}
											{
												::StringBuf _g1 = this->buf;
												_g1->b[_g1->b->length] = ucount;
											}
										}
										ucount = 0;
									}
									this->serialize(v[i]);
								}
							}
						}
						if ((ucount > 0)){
							if ((ucount == 1)){
								::StringBuf _g = this->buf;
								_g->b[_g->b->length] = HX_STRING(L"n",1);
							}
							else{
								{
									::StringBuf _g = this->buf;
									_g->b[_g->b->length] = HX_STRING(L"u",1);
								}
								{
									::StringBuf _g = this->buf;
									_g->b[_g->b->length] = ucount;
								}
							}
						}
						{
							::StringBuf _g = this->buf;
							_g->b[_g->b->length] = HX_STRING(L"h",1);
						}
					}
					else if (  ( _switch_2==hx::ClassOf< ::List >())){
						{
							::StringBuf _g = this->buf;
							_g->b[_g->b->length] = HX_STRING(L"l",1);
						}
						::List v1 = v;
						for(Dynamic __it = v1->iterator();  __it->__Field(HX_STRING(L"hasNext",7))(); ){
Dynamic i = __it->__Field(HX_STRING(L"next",4))();
							this->serialize(i);
							__SAFE_POINT
						}
						{
							::StringBuf _g = this->buf;
							_g->b[_g->b->length] = HX_STRING(L"h",1);
						}
					}
					else if (  ( _switch_2==hx::ClassOf< ::cpp::CppDate__ >())){
						::cpp::CppDate__ d = v;
						{
							::StringBuf _g = this->buf;
							_g->b[_g->b->length] = HX_STRING(L"v",1);
						}
						{
							::StringBuf _g = this->buf;
							_g->b[_g->b->length] = d->toString();
						}
					}
					else if (  ( _switch_2==hx::ClassOf< ::Hash >())){
						{
							::StringBuf _g = this->buf;
							_g->b[_g->b->length] = HX_STRING(L"b",1);
						}
						::Hash v1 = v;
						for(Dynamic __it = v1->keys();  __it->__Field(HX_STRING(L"hasNext",7))(); ){
::String k = __it->__Field(HX_STRING(L"next",4))();
							{
								this->serializeString(k);
								this->serialize(v1->get(k));
							}
;
							__SAFE_POINT
						}
						{
							::StringBuf _g = this->buf;
							_g->b[_g->b->length] = HX_STRING(L"h",1);
						}
					}
					else if (  ( _switch_2==hx::ClassOf< ::IntHash >())){
						{
							::StringBuf _g = this->buf;
							_g->b[_g->b->length] = HX_STRING(L"q",1);
						}
						::IntHash v1 = v;
						for(Dynamic __it = v1->keys();  __it->__Field(HX_STRING(L"hasNext",7))(); ){
int k = __it->__Field(HX_STRING(L"next",4))();
							{
								{
									::StringBuf _g = this->buf;
									_g->b[_g->b->length] = HX_STRING(L":",1);
								}
								{
									::StringBuf _g = this->buf;
									_g->b[_g->b->length] = k;
								}
								this->serialize(v1->get(k));
							}
;
							__SAFE_POINT
						}
						{
							::StringBuf _g = this->buf;
							_g->b[_g->b->length] = HX_STRING(L"h",1);
						}
					}
					else if (  ( _switch_2==hx::ClassOf< ::haxe::io::Bytes >())){
						::haxe::io::Bytes v1 = v;
						int i = 0;
						int max = (v1->length - 2);
						::String chars = HX_STRING(L"",0);
						::String b64 = ::haxe::Serializer_obj::BASE64;
						while((i < max)){
							__SAFE_POINT
							int b1 = v1->b->__get(i++);
							int b2 = v1->b->__get(i++);
							int b3 = v1->b->__get(i++);
							hx::AddEq(chars,(((((b64.charAt((int(b1) >> int(2))) + b64.charAt((int(((int(((int(b1) << int(4)))) | int(((int(b2) >> int(4))))))) & int(63))))) + b64.charAt((int(((int(((int(b2) << int(2)))) | int(((int(b3) >> int(6))))))) & int(63))))) + b64.charAt((int(b3) & int(63)))));
						}
						if ((i == max)){
							int b1 = v1->b->__get(i++);
							int b2 = v1->b->__get(i++);
							hx::AddEq(chars,(((b64.charAt((int(b1) >> int(2))) + b64.charAt((int(((int(((int(b1) << int(4)))) | int(((int(b2) >> int(4))))))) & int(63))))) + b64.charAt((int(((int(b2) << int(2)))) & int(63)))));
						}
						else{
							if ((i == (max + 1))){
								int b1 = v1->b->__get(i++);
								hx::AddEq(chars,(b64.charAt((int(b1) >> int(2))) + b64.charAt((int(((int(b1) << int(4)))) & int(63)))));
							}
						}
						{
							::StringBuf _g = this->buf;
							_g->b[_g->b->length] = HX_STRING(L"s",1);
						}
						{
							::StringBuf _g = this->buf;
							_g->b[_g->b->length] = chars.length;
						}
						{
							::StringBuf _g = this->buf;
							_g->b[_g->b->length] = HX_STRING(L":",1);
						}
						{
							::StringBuf _g = this->buf;
							_g->b[_g->b->length] = chars;
						}
					}
					else  {
						this->cache->pop();
						{
							::StringBuf _g = this->buf;
							_g->b[_g->b->length] = HX_STRING(L"c",1);
						}
						this->serializeString(::Type_obj::getClassName(c));
						this->cache->push(v);
						this->serializeFields(v);
					}
;
;
				}
			}
			;break;
			case 4: {
				if ((bool(this->useCache) && bool(this->serializeRef(v))))
					return null();
				{
					::StringBuf _g = this->buf;
					_g->b[_g->b->length] = HX_STRING(L"o",1);
				}
				this->serializeFields(v);
			}
			;break;
			case 7: {
				::Enum e = _switch_1->__Param(0);
{
					if ((bool(this->useCache) && bool(this->serializeRef(v))))
						return null();
					this->cache->pop();
					{
						::StringBuf _g = this->buf;
						_g->b[_g->b->length] = this->useEnumIndex ? ::String( HX_STRING(L"j",1) ) : ::String( HX_STRING(L"w",1) );
					}
					this->serializeString(::Type_obj::getEnumName(e));
					if (this->useEnumIndex){
						{
							::StringBuf _g = this->buf;
							_g->b[_g->b->length] = HX_STRING(L":",1);
						}
						{
							::StringBuf _g = this->buf;
							_g->b[_g->b->length] = v->__Index();
						}
					}
					else{
						this->serializeString(v->__Tag());
					}
					{
						::StringBuf _g = this->buf;
						_g->b[_g->b->length] = HX_STRING(L":",1);
					}
					Array< Dynamic > pl = v->__EnumParams();
					if ((pl == null())){
						::StringBuf _g = this->buf;
						_g->b[_g->b->length] = 0;
					}
					else{
						{
							::StringBuf _g = this->buf;
							_g->b[_g->b->length] = pl->length;
						}
						{
							int _g = 0;
							while((_g < pl->length)){
								__SAFE_POINT
								Dynamic p = pl->__get(_g);
								++_g;
								this->serialize(p);
							}
						}
					}
					this->cache->push(v);
				}
			}
			;break;
			case 5: {
				hx::Throw (HX_STRING(L"Cannot serialize function",25));
			}
			;break;
			default: {
				hx::Throw ((HX_STRING(L"Cannot serialize ",17) + ::Std_obj::string(v)));
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Serializer_obj,serialize,(void))

Void Serializer_obj::serializeException( Dynamic e){
{
		__SAFE_POINT
		{
			::StringBuf _g = this->buf;
			_g->b[_g->b->length] = HX_STRING(L"x",1);
		}
		this->serialize(e);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Serializer_obj,serializeException,(void))

bool Serializer_obj::USE_CACHE;

bool Serializer_obj::USE_ENUM_INDEX;

::String Serializer_obj::BASE64;

::String Serializer_obj::run( Dynamic v){
	__SAFE_POINT
	::haxe::Serializer s = ::haxe::Serializer_obj::__new();
	s->serialize(v);
	return s->toString();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Serializer_obj,run,return )


Serializer_obj::Serializer_obj()
{
}

void Serializer_obj::__Mark()
{
	hx::MarkMember(buf);
	hx::MarkMember(cache);
	hx::MarkMember(shash);
	hx::MarkMember(scount);
	hx::MarkMember(useCache);
	hx::MarkMember(useEnumIndex);
}

Dynamic Serializer_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 3:
		if (!memcmp(inName.__s,L"run",sizeof(wchar_t)*3) ) { return run_dyn(); }
		if (!memcmp(inName.__s,L"buf",sizeof(wchar_t)*3) ) { return buf; }
		break;
	case 5:
		if (!memcmp(inName.__s,L"cache",sizeof(wchar_t)*5) ) { return cache; }
		if (!memcmp(inName.__s,L"shash",sizeof(wchar_t)*5) ) { return shash; }
		break;
	case 6:
		if (!memcmp(inName.__s,L"BASE64",sizeof(wchar_t)*6) ) { return BASE64; }
		if (!memcmp(inName.__s,L"scount",sizeof(wchar_t)*6) ) { return scount; }
		break;
	case 8:
		if (!memcmp(inName.__s,L"useCache",sizeof(wchar_t)*8) ) { return useCache; }
		if (!memcmp(inName.__s,L"toString",sizeof(wchar_t)*8) ) { return toString_dyn(); }
		break;
	case 9:
		if (!memcmp(inName.__s,L"USE_CACHE",sizeof(wchar_t)*9) ) { return USE_CACHE; }
		if (!memcmp(inName.__s,L"serialize",sizeof(wchar_t)*9) ) { return serialize_dyn(); }
		break;
	case 12:
		if (!memcmp(inName.__s,L"useEnumIndex",sizeof(wchar_t)*12) ) { return useEnumIndex; }
		if (!memcmp(inName.__s,L"serializeRef",sizeof(wchar_t)*12) ) { return serializeRef_dyn(); }
		break;
	case 14:
		if (!memcmp(inName.__s,L"USE_ENUM_INDEX",sizeof(wchar_t)*14) ) { return USE_ENUM_INDEX; }
		break;
	case 15:
		if (!memcmp(inName.__s,L"serializeString",sizeof(wchar_t)*15) ) { return serializeString_dyn(); }
		if (!memcmp(inName.__s,L"serializeFields",sizeof(wchar_t)*15) ) { return serializeFields_dyn(); }
		break;
	case 18:
		if (!memcmp(inName.__s,L"serializeException",sizeof(wchar_t)*18) ) { return serializeException_dyn(); }
	}
	return super::__Field(inName);
}

Dynamic Serializer_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	switch(inName.length) {
	case 3:
		if (!memcmp(inName.__s,L"buf",sizeof(wchar_t)*3) ) { buf=inValue.Cast< ::StringBuf >(); return inValue; }
		break;
	case 5:
		if (!memcmp(inName.__s,L"cache",sizeof(wchar_t)*5) ) { cache=inValue.Cast< Array< Dynamic > >(); return inValue; }
		if (!memcmp(inName.__s,L"shash",sizeof(wchar_t)*5) ) { shash=inValue.Cast< ::Hash >(); return inValue; }
		break;
	case 6:
		if (!memcmp(inName.__s,L"BASE64",sizeof(wchar_t)*6) ) { BASE64=inValue.Cast< ::String >(); return inValue; }
		if (!memcmp(inName.__s,L"scount",sizeof(wchar_t)*6) ) { scount=inValue.Cast< int >(); return inValue; }
		break;
	case 8:
		if (!memcmp(inName.__s,L"useCache",sizeof(wchar_t)*8) ) { useCache=inValue.Cast< bool >(); return inValue; }
		break;
	case 9:
		if (!memcmp(inName.__s,L"USE_CACHE",sizeof(wchar_t)*9) ) { USE_CACHE=inValue.Cast< bool >(); return inValue; }
		break;
	case 12:
		if (!memcmp(inName.__s,L"useEnumIndex",sizeof(wchar_t)*12) ) { useEnumIndex=inValue.Cast< bool >(); return inValue; }
		break;
	case 14:
		if (!memcmp(inName.__s,L"USE_ENUM_INDEX",sizeof(wchar_t)*14) ) { USE_ENUM_INDEX=inValue.Cast< bool >(); return inValue; }
	}
	return super::__SetField(inName,inValue);
}

void Serializer_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_STRING(L"buf",3));
	outFields->push(HX_STRING(L"cache",5));
	outFields->push(HX_STRING(L"shash",5));
	outFields->push(HX_STRING(L"scount",6));
	outFields->push(HX_STRING(L"useCache",8));
	outFields->push(HX_STRING(L"useEnumIndex",12));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_STRING(L"USE_CACHE",9),
	HX_STRING(L"USE_ENUM_INDEX",14),
	HX_STRING(L"BASE64",6),
	HX_STRING(L"run",3),
	String(null()) };

static ::String sMemberFields[] = {
	HX_STRING(L"buf",3),
	HX_STRING(L"cache",5),
	HX_STRING(L"shash",5),
	HX_STRING(L"scount",6),
	HX_STRING(L"useCache",8),
	HX_STRING(L"useEnumIndex",12),
	HX_STRING(L"toString",8),
	HX_STRING(L"serializeString",15),
	HX_STRING(L"serializeRef",12),
	HX_STRING(L"serializeFields",15),
	HX_STRING(L"serialize",9),
	HX_STRING(L"serializeException",18),
	String(null()) };

static void sMarkStatics() {
	hx::MarkMember(Serializer_obj::USE_CACHE);
	hx::MarkMember(Serializer_obj::USE_ENUM_INDEX);
	hx::MarkMember(Serializer_obj::BASE64);
};

Class Serializer_obj::__mClass;

void Serializer_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_STRING(L"haxe.Serializer",15), hx::TCanCast< Serializer_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void Serializer_obj::__boot()
{
	hx::Static(USE_CACHE) = false;
	hx::Static(USE_ENUM_INDEX) = false;
	hx::Static(BASE64) = HX_STRING(L"ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789%:",64);
}

} // end namespace haxe
