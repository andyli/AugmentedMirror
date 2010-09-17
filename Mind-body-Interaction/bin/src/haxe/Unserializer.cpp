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
#ifndef INCLUDED_StringTools
#include <StringTools.h>
#endif
#ifndef INCLUDED_Type
#include <Type.h>
#endif
#ifndef INCLUDED_cpp_CppDate__
#include <cpp/CppDate__.h>
#endif
#ifndef INCLUDED_haxe_Unserializer
#include <haxe/Unserializer.h>
#endif
#ifndef INCLUDED_haxe_io_Bytes
#include <haxe/io/Bytes.h>
#endif
namespace haxe{

Void Unserializer_obj::__construct(::String buf)
{
{
	this->buf = buf;
	this->length = buf.length;
	this->pos = 0;
	this->scache = Array_obj< ::String >::__new();
	this->cache = Array_obj< Dynamic >::__new();
	this->setResolver(::haxe::Unserializer_obj::DEFAULT_RESOLVER);
}
;
	return null();
}

Unserializer_obj::~Unserializer_obj() { }

Dynamic Unserializer_obj::__CreateEmpty() { return  new Unserializer_obj; }
hx::ObjectPtr< Unserializer_obj > Unserializer_obj::__new(::String buf)
{  hx::ObjectPtr< Unserializer_obj > result = new Unserializer_obj();
	result->__construct(buf);
	return result;}

Dynamic Unserializer_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Unserializer_obj > result = new Unserializer_obj();
	result->__construct(inArgs[0]);
	return result;}

Void Unserializer_obj::setResolver( Dynamic r){
{
		struct _Function_1_1{
			inline static Dynamic Block( ){
				hx::Anon __result = hx::Anon_obj::Create();

				HX_BEGIN_LOCAL_FUNC0(_Function_2_1)
				::Class run(::String _){
{
						return null();
					}
					return null();
				}
				HX_END_LOCAL_FUNC1(return)

				__result->Add(HX_STRING(L"resolveClass",12) ,  Dynamic(new _Function_2_1()));

				HX_BEGIN_LOCAL_FUNC0(_Function_2_2)
				::Enum run(::String _){
{
						return null();
					}
					return null();
				}
				HX_END_LOCAL_FUNC1(return)

				__result->Add(HX_STRING(L"resolveEnum",11) ,  Dynamic(new _Function_2_2()));
				return __result;
			}
		};
		if ((r == null())){
			struct _Function_2_1{
				inline static Dynamic Block( ){
					hx::Anon __result = hx::Anon_obj::Create();

					HX_BEGIN_LOCAL_FUNC0(_Function_3_1)
					::Class run(::String _){
{
							return null();
						}
						return null();
					}
					HX_END_LOCAL_FUNC1(return)

					__result->Add(HX_STRING(L"resolveClass",12) ,  Dynamic(new _Function_3_1()));

					HX_BEGIN_LOCAL_FUNC0(_Function_3_2)
					::Enum run(::String _){
{
							return null();
						}
						return null();
					}
					HX_END_LOCAL_FUNC1(return)

					__result->Add(HX_STRING(L"resolveEnum",11) ,  Dynamic(new _Function_3_2()));
					return __result;
				}
			};
			this->resolver = _Function_2_1::Block();
		}
		else{
			this->resolver = r;
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Unserializer_obj,setResolver,(void))

int Unserializer_obj::get( int p){
	__SAFE_POINT
	return this->buf.charCodeAt(p);
}


HX_DEFINE_DYNAMIC_FUNC1(Unserializer_obj,get,return )

int Unserializer_obj::readDigits( ){
	__SAFE_POINT
	int k = 0;
	bool s = false;
	int fpos = this->pos;
	while(true){
		__SAFE_POINT
		int c = this->buf.charCodeAt(this->pos).Cast< int >();
		if ((c == null()))
			break;
		if ((c == 45)){
			if ((this->pos != fpos))
				break;
			s = true;
			this->pos++;
			continue;
		}
		hx::SubEq(c,48);
		if ((bool((c < 0)) || bool((c > 9))))
			break;
		k = ((k * 10) + c);
		this->pos++;
	}
	if (s)
		hx::MultEq(k,-1);
	return k;
}


HX_DEFINE_DYNAMIC_FUNC0(Unserializer_obj,readDigits,return )

Void Unserializer_obj::unserializeObject( Dynamic o){
{
		__SAFE_POINT
		while(true){
			__SAFE_POINT
			if ((this->pos >= this->length))
				hx::Throw (HX_STRING(L"Invalid object",14));
			if ((this->buf.charCodeAt(this->pos).Cast< int >() == 103))
				break;
			::String k = this->unserialize();
			if (!::Std_obj::is(k,hx::ClassOf< ::String >()))
				hx::Throw (HX_STRING(L"Invalid object key",18));
			Dynamic v = this->unserialize();
			if ((o != null())){
				o->__SetField(k,v);
			}
			else{
				{};
			}
		}
		this->pos++;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Unserializer_obj,unserializeObject,(void))

Dynamic Unserializer_obj::unserializeEnum( ::Enum edecl,::String tag){
	__SAFE_POINT
	Dynamic constr = ((edecl == null())) ? Dynamic( null() ) : Dynamic( edecl->__Field(tag) );
	if ((constr == null()))
		hx::Throw ((((((HX_STRING(L"Unknown enum tag ",17) + ::Type_obj::getEnumName(edecl))) + HX_STRING(L".",1))) + tag));
	if ((this->buf.charCodeAt(this->pos++).Cast< int >() != 58))
		hx::Throw (HX_STRING(L"Invalid enum format",19));
	int nargs = this->readDigits();
	if ((nargs == 0)){
		this->cache->push(constr);
		return constr;
	}
	Array< Dynamic > args = Array_obj< Dynamic >::__new();
	while((nargs > 0)){
		__SAFE_POINT
		args->push(this->unserialize());
		hx::SubEq(nargs,1);
	}
	Dynamic e = ::Reflect_obj::callMethod(edecl,constr,args);
	this->cache->push(e);
	return e;
}


HX_DEFINE_DYNAMIC_FUNC2(Unserializer_obj,unserializeEnum,return )

Dynamic Unserializer_obj::unserialize( ){
	__SAFE_POINT
	switch( (int)(this->buf.charCodeAt(this->pos++).Cast< int >())){
		case 110: {
			return null();
		}
		;break;
		case 116: {
			return true;
		}
		;break;
		case 102: {
			return false;
		}
		;break;
		case 122: {
			return 0;
		}
		;break;
		case 105: {
			return this->readDigits();
		}
		;break;
		case 100: {
			int p1 = this->pos;
			while(true){
				__SAFE_POINT
				int c = this->buf.charCodeAt(this->pos).Cast< int >();
				if ((bool(((bool((c >= 43)) && bool((c < 58))))) || bool((bool((c == 101)) || bool((c == 69)))))){
					this->pos++;
				}
				else{
					break;
				}
			}
			return ::Std_obj::parseFloat(this->buf.substr(p1,(this->pos - p1)));
		}
		;break;
		case 121: {
			int len = this->readDigits();
			if ((bool((this->buf.charAt(this->pos++) != HX_STRING(L":",1))) || bool(((this->length - this->pos) < len))))
				hx::Throw (HX_STRING(L"Invalid string length",21));
			::String s = this->buf.substr(this->pos,len);
			hx::AddEq(this->pos,len);
			s = ::StringTools_obj::urlDecode(s);
			this->scache->push(s);
			return s;
		}
		;break;
		case 107: {
			return ::Math_obj::NaN;
		}
		;break;
		case 109: {
			return ::Math_obj::NEGATIVE_INFINITY;
		}
		;break;
		case 112: {
			return ::Math_obj::POSITIVE_INFINITY;
		}
		;break;
		case 97: {
			::String buf = this->buf;
			Array< Dynamic > a = Array_obj< Dynamic >::__new();
			this->cache->push(a);
			while(true){
				__SAFE_POINT
				int c = this->buf.charCodeAt(this->pos).Cast< int >();
				if ((c == 104)){
					this->pos++;
					break;
				}
				if ((c == 117)){
					this->pos++;
					int n = this->readDigits();
					a[(((a->length + n)) - 1)] = null();
				}
				else{
					a->push(this->unserialize());
				}
			}
			return a;
		}
		;break;
		case 111: {
			struct _Function_2_1{
				inline static Dynamic Block( ){
					hx::Anon __result = hx::Anon_obj::Create();
					return __result;
				}
			};
			Dynamic o = _Function_2_1::Block();
			this->cache->push(o);
			this->unserializeObject(o);
			return o;
		}
		;break;
		case 114: {
			int n = this->readDigits();
			if ((bool((n < 0)) || bool((n >= this->cache->length))))
				hx::Throw (HX_STRING(L"Invalid reference",17));
			return this->cache->__get(n);
		}
		;break;
		case 82: {
			int n = this->readDigits();
			if ((bool((n < 0)) || bool((n >= this->scache->length))))
				hx::Throw (HX_STRING(L"Invalid string reference",24));
			return this->scache->__get(n);
		}
		;break;
		case 120: {
			hx::Throw (this->unserialize());
		}
		;break;
		case 99: {
			::String name = this->unserialize();
			::Class cl = this->resolver->__Field(HX_STRING(L"resolveClass",12))(name);
			if ((cl == null()))
				hx::Throw ((HX_STRING(L"Class not found ",16) + name));
			Dynamic o = ::Type_obj::createEmptyInstance(cl);
			this->cache->push(o);
			this->unserializeObject(o);
			return o;
		}
		;break;
		case 119: {
			::String name = this->unserialize();
			::Enum edecl = this->resolver->__Field(HX_STRING(L"resolveEnum",11))(name);
			if ((edecl == null()))
				hx::Throw ((HX_STRING(L"Enum not found ",15) + name));
			return this->unserializeEnum(edecl,this->unserialize());
		}
		;break;
		case 106: {
			::String name = this->unserialize();
			::Enum edecl = this->resolver->__Field(HX_STRING(L"resolveEnum",11))(name);
			if ((edecl == null()))
				hx::Throw ((HX_STRING(L"Enum not found ",15) + name));
			this->pos++;
			int index = this->readDigits();
			::String tag = ::Type_obj::getEnumConstructs(edecl)->__get(index);
			if ((tag == null()))
				hx::Throw ((((((HX_STRING(L"Unknown enum index ",19) + name)) + HX_STRING(L"@",1))) + index));
			return this->unserializeEnum(edecl,tag);
		}
		;break;
		case 108: {
			::List l = ::List_obj::__new();
			this->cache->push(l);
			::String buf = this->buf;
			while((this->buf.charCodeAt(this->pos).Cast< int >() != 104))l->add(this->unserialize());
			this->pos++;
			return l;
		}
		;break;
		case 98: {
			::Hash h = ::Hash_obj::__new();
			this->cache->push(h);
			::String buf = this->buf;
			while((this->buf.charCodeAt(this->pos).Cast< int >() != 104)){
				__SAFE_POINT
				::String s = this->unserialize();
				h->set(s,this->unserialize());
			}
			this->pos++;
			return h;
		}
		;break;
		case 113: {
			::IntHash h = ::IntHash_obj::__new();
			this->cache->push(h);
			::String buf = this->buf;
			int c = this->buf.charCodeAt(this->pos++).Cast< int >();
			while((c == 58)){
				__SAFE_POINT
				int i = this->readDigits();
				h->set(i,this->unserialize());
				c = this->buf.charCodeAt(this->pos++).Cast< int >();
			}
			if ((c != 104))
				hx::Throw (HX_STRING(L"Invalid IntHash format",22));
			return h;
		}
		;break;
		case 118: {
			::cpp::CppDate__ d = ::cpp::CppDate___obj::fromString(this->buf.substr(this->pos,19));
			this->cache->push(d);
			hx::AddEq(this->pos,19);
			return d;
		}
		;break;
		case 115: {
			int len = this->readDigits();
			::String buf = this->buf;
			if ((bool((buf.charAt(this->pos++) != HX_STRING(L":",1))) || bool(((this->length - this->pos) < len))))
				hx::Throw (HX_STRING(L"Invalid bytes length",20));
			Array< int > codes = ::haxe::Unserializer_obj::CODES;
			if ((codes == null())){
				codes = ::haxe::Unserializer_obj::initCodes();
				::haxe::Unserializer_obj::CODES = codes;
			}
			int i = this->pos;
			int rest = (int(len) & int(3));
			int size = ((((int(len) >> int(2))) * 3) + (((rest >= 2)) ? int( (rest - 1) ) : int( 0 )));
			int max = (i + ((len - rest)));
			::haxe::io::Bytes bytes = ::haxe::io::Bytes_obj::alloc(size);
			int bpos = 0;
			while((i < max)){
				__SAFE_POINT
				int c1 = codes->__get(buf.cca(i++));
				int c2 = codes->__get(buf.cca(i++));
				bytes->b[bpos++] = (int(((int(c1) << int(2)))) | int(((int(c2) >> int(4)))));
				int c3 = codes->__get(buf.cca(i++));
				bytes->b[bpos++] = (int(((int(c2) << int(4)))) | int(((int(c3) >> int(2)))));
				int c4 = codes->__get(buf.cca(i++));
				bytes->b[bpos++] = (int(((int(c3) << int(6)))) | int(c4));
			}
			if ((rest >= 2)){
				int c1 = codes->__get(buf.cca(i++));
				int c2 = codes->__get(buf.cca(i++));
				bytes->b[bpos++] = (int(((int(c1) << int(2)))) | int(((int(c2) >> int(4)))));
				if ((rest == 3)){
					int c3 = codes->__get(buf.cca(i++));
					bytes->b[bpos++] = (int(((int(c2) << int(4)))) | int(((int(c3) >> int(2)))));
				}
			}
			hx::AddEq(this->pos,len);
			this->cache->push(bytes);
			return bytes;
		}
		;break;
		default: {
		}
	}
	this->pos--;
	hx::Throw (((((((HX_STRING(L"Invalid char ",13) + this->buf.charAt(this->pos))) + HX_STRING(L" at position ",13))) + this->pos)));
}


HX_DEFINE_DYNAMIC_FUNC0(Unserializer_obj,unserialize,return )

Dynamic Unserializer_obj::DEFAULT_RESOLVER;

::String Unserializer_obj::BASE64;

Array< int > Unserializer_obj::CODES;

Array< int > Unserializer_obj::initCodes( ){
	__SAFE_POINT
	Array< int > codes = Array_obj< int >::__new();
	{
		int _g1 = 0;
		int _g = ::haxe::Unserializer_obj::BASE64.length;
		while((_g1 < _g)){
			__SAFE_POINT
			int i = _g1++;
			codes[::haxe::Unserializer_obj::BASE64.cca(i)] = i;
		}
	}
	return codes;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(Unserializer_obj,initCodes,return )

Dynamic Unserializer_obj::run( ::String v){
	__SAFE_POINT
	return ::haxe::Unserializer_obj::__new(v)->unserialize();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Unserializer_obj,run,return )


Unserializer_obj::Unserializer_obj()
{
}

void Unserializer_obj::__Mark()
{
	hx::MarkMember(buf);
	hx::MarkMember(pos);
	hx::MarkMember(length);
	hx::MarkMember(cache);
	hx::MarkMember(scache);
	hx::MarkMember(resolver);
}

Dynamic Unserializer_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 3:
		if (!memcmp(inName.__s,L"run",sizeof(wchar_t)*3) ) { return run_dyn(); }
		if (!memcmp(inName.__s,L"buf",sizeof(wchar_t)*3) ) { return buf; }
		if (!memcmp(inName.__s,L"pos",sizeof(wchar_t)*3) ) { return pos; }
		if (!memcmp(inName.__s,L"get",sizeof(wchar_t)*3) ) { return get_dyn(); }
		break;
	case 5:
		if (!memcmp(inName.__s,L"CODES",sizeof(wchar_t)*5) ) { return CODES; }
		if (!memcmp(inName.__s,L"cache",sizeof(wchar_t)*5) ) { return cache; }
		break;
	case 6:
		if (!memcmp(inName.__s,L"BASE64",sizeof(wchar_t)*6) ) { return BASE64; }
		if (!memcmp(inName.__s,L"length",sizeof(wchar_t)*6) ) { return length; }
		if (!memcmp(inName.__s,L"scache",sizeof(wchar_t)*6) ) { return scache; }
		break;
	case 8:
		if (!memcmp(inName.__s,L"resolver",sizeof(wchar_t)*8) ) { return resolver; }
		break;
	case 9:
		if (!memcmp(inName.__s,L"initCodes",sizeof(wchar_t)*9) ) { return initCodes_dyn(); }
		break;
	case 10:
		if (!memcmp(inName.__s,L"readDigits",sizeof(wchar_t)*10) ) { return readDigits_dyn(); }
		break;
	case 11:
		if (!memcmp(inName.__s,L"setResolver",sizeof(wchar_t)*11) ) { return setResolver_dyn(); }
		if (!memcmp(inName.__s,L"unserialize",sizeof(wchar_t)*11) ) { return unserialize_dyn(); }
		break;
	case 15:
		if (!memcmp(inName.__s,L"unserializeEnum",sizeof(wchar_t)*15) ) { return unserializeEnum_dyn(); }
		break;
	case 16:
		if (!memcmp(inName.__s,L"DEFAULT_RESOLVER",sizeof(wchar_t)*16) ) { return DEFAULT_RESOLVER; }
		break;
	case 17:
		if (!memcmp(inName.__s,L"unserializeObject",sizeof(wchar_t)*17) ) { return unserializeObject_dyn(); }
	}
	return super::__Field(inName);
}

Dynamic Unserializer_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	switch(inName.length) {
	case 3:
		if (!memcmp(inName.__s,L"buf",sizeof(wchar_t)*3) ) { buf=inValue.Cast< ::String >(); return inValue; }
		if (!memcmp(inName.__s,L"pos",sizeof(wchar_t)*3) ) { pos=inValue.Cast< int >(); return inValue; }
		break;
	case 5:
		if (!memcmp(inName.__s,L"CODES",sizeof(wchar_t)*5) ) { CODES=inValue.Cast< Array< int > >(); return inValue; }
		if (!memcmp(inName.__s,L"cache",sizeof(wchar_t)*5) ) { cache=inValue.Cast< Array< Dynamic > >(); return inValue; }
		break;
	case 6:
		if (!memcmp(inName.__s,L"BASE64",sizeof(wchar_t)*6) ) { BASE64=inValue.Cast< ::String >(); return inValue; }
		if (!memcmp(inName.__s,L"length",sizeof(wchar_t)*6) ) { length=inValue.Cast< int >(); return inValue; }
		if (!memcmp(inName.__s,L"scache",sizeof(wchar_t)*6) ) { scache=inValue.Cast< Array< ::String > >(); return inValue; }
		break;
	case 8:
		if (!memcmp(inName.__s,L"resolver",sizeof(wchar_t)*8) ) { resolver=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 16:
		if (!memcmp(inName.__s,L"DEFAULT_RESOLVER",sizeof(wchar_t)*16) ) { DEFAULT_RESOLVER=inValue.Cast< Dynamic >(); return inValue; }
	}
	return super::__SetField(inName,inValue);
}

void Unserializer_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_STRING(L"buf",3));
	outFields->push(HX_STRING(L"pos",3));
	outFields->push(HX_STRING(L"length",6));
	outFields->push(HX_STRING(L"cache",5));
	outFields->push(HX_STRING(L"scache",6));
	outFields->push(HX_STRING(L"resolver",8));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_STRING(L"DEFAULT_RESOLVER",16),
	HX_STRING(L"BASE64",6),
	HX_STRING(L"CODES",5),
	HX_STRING(L"initCodes",9),
	HX_STRING(L"run",3),
	String(null()) };

static ::String sMemberFields[] = {
	HX_STRING(L"buf",3),
	HX_STRING(L"pos",3),
	HX_STRING(L"length",6),
	HX_STRING(L"cache",5),
	HX_STRING(L"scache",6),
	HX_STRING(L"resolver",8),
	HX_STRING(L"setResolver",11),
	HX_STRING(L"get",3),
	HX_STRING(L"readDigits",10),
	HX_STRING(L"unserializeObject",17),
	HX_STRING(L"unserializeEnum",15),
	HX_STRING(L"unserialize",11),
	String(null()) };

static void sMarkStatics() {
	hx::MarkMember(Unserializer_obj::DEFAULT_RESOLVER);
	hx::MarkMember(Unserializer_obj::BASE64);
	hx::MarkMember(Unserializer_obj::CODES);
};

Class Unserializer_obj::__mClass;

void Unserializer_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_STRING(L"haxe.Unserializer",17), hx::TCanCast< Unserializer_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void Unserializer_obj::__boot()
{
	hx::Static(DEFAULT_RESOLVER) = hx::ClassOf< ::Type >();
	hx::Static(BASE64) = HX_STRING(L"ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789%:",64);
	hx::Static(CODES) = null();
}

} // end namespace haxe
