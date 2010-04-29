#include <hxcpp.h>

#ifndef INCLUDED_Reflect
#include <Reflect.h>
#endif
#ifndef INCLUDED_StringBuf
#include <StringBuf.h>
#endif
#ifndef INCLUDED_cpp_CppXml__
#include <cpp/CppXml__.h>
#endif
#ifndef INCLUDED_cpp_Lib
#include <cpp/Lib.h>
#endif
namespace cpp{

Void CppXml___obj::__construct()
{
{
}
;
	return null();
}

CppXml___obj::~CppXml___obj() { }

Dynamic CppXml___obj::__CreateEmpty() { return  new CppXml___obj; }
hx::ObjectPtr< CppXml___obj > CppXml___obj::__new()
{  hx::ObjectPtr< CppXml___obj > result = new CppXml___obj();
	result->__construct();
	return result;}

Dynamic CppXml___obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< CppXml___obj > result = new CppXml___obj();
	result->__construct();
	return result;}

void CppXml___obj::__init__(){
	::cpp::CppXml___obj::Element = HX_STRING(L"element",7);
	::cpp::CppXml___obj::PCData = HX_STRING(L"pcdata",6);
	::cpp::CppXml___obj::CData = HX_STRING(L"cdata",5);
	::cpp::CppXml___obj::Comment = HX_STRING(L"comment",7);
	::cpp::CppXml___obj::DocType = HX_STRING(L"doctype",7);
	::cpp::CppXml___obj::Prolog = HX_STRING(L"prolog",6);
	::cpp::CppXml___obj::Document = HX_STRING(L"document",8);
}


::String CppXml___obj::getNodeName( ){
	if ((this->nodeType != ::cpp::CppXml___obj::Element))
		hx::Throw (HX_STRING(L"bad nodeType",12));
	return this->_nodeName;
}


HX_DEFINE_DYNAMIC_FUNC0(CppXml___obj,getNodeName,return )

::String CppXml___obj::setNodeName( ::String n){
	if ((this->nodeType != ::cpp::CppXml___obj::Element))
		hx::Throw (HX_STRING(L"bad nodeType",12));
	return this->_nodeName = n;
}


HX_DEFINE_DYNAMIC_FUNC1(CppXml___obj,setNodeName,return )

::String CppXml___obj::getNodeValue( ){
	if ((bool((this->nodeType == ::cpp::CppXml___obj::Element)) || bool((this->nodeType == ::cpp::CppXml___obj::Document))))
		hx::Throw (HX_STRING(L"bad nodeType",12));
	return this->_nodeValue;
}


HX_DEFINE_DYNAMIC_FUNC0(CppXml___obj,getNodeValue,return )

::String CppXml___obj::setNodeValue( ::String v){
	if ((bool((this->nodeType == ::cpp::CppXml___obj::Element)) || bool((this->nodeType == ::cpp::CppXml___obj::Document))))
		hx::Throw (HX_STRING(L"bad nodeType",12));
	return this->_nodeValue = v;
}


HX_DEFINE_DYNAMIC_FUNC1(CppXml___obj,setNodeValue,return )

::cpp::CppXml__ CppXml___obj::getParent( ){
	return this->_parent;
}


HX_DEFINE_DYNAMIC_FUNC0(CppXml___obj,getParent,return )

::String CppXml___obj::get( ::String att){
	__SAFE_POINT
	if ((this->nodeType != ::cpp::CppXml___obj::Element))
		hx::Throw (HX_STRING(L"bad nodeType",12));
	struct _Function_1_1{
		inline static Dynamic Block( ::cpp::CppXml___obj *__this,::String &att)/* DEF (ret block)(not intern) */{
			Dynamic o = __this->_attributes;
			return ((o == null())) ? Dynamic( null() ) : Dynamic( o->__Field(att) );
		}
	};
	return _Function_1_1::Block(this,att);
}


HX_DEFINE_DYNAMIC_FUNC1(CppXml___obj,get,return )

Void CppXml___obj::set( ::String att,::String value){
{
		__SAFE_POINT
		if ((this->nodeType != ::cpp::CppXml___obj::Element))
			hx::Throw (HX_STRING(L"bad nodeType",12));
		struct _Function_1_1{
			inline static Dynamic Block( ){
				hx::Anon __result = hx::Anon_obj::Create();
				return __result;
			}
		};
		if ((this->_attributes == null()))
			this->_attributes = _Function_1_1::Block();
		{
			Dynamic o = this->_attributes;
			if ((o != null())){
				o->__SetField(att,value);
			}
			else{
				{};
			}
		}
		return null();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(CppXml___obj,set,(void))

Void CppXml___obj::remove( ::String att){
{
		__SAFE_POINT
		if ((this->nodeType != ::cpp::CppXml___obj::Element))
			hx::Throw (HX_STRING(L"bad nodeType",12));
		::Reflect_obj::deleteField(this->_attributes,att);
		return null();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(CppXml___obj,remove,(void))

bool CppXml___obj::exists( ::String att){
	__SAFE_POINT
	if ((this->nodeType != ::cpp::CppXml___obj::Element))
		hx::Throw (HX_STRING(L"bad nodeType",12));
	return ::Reflect_obj::hasField(this->_attributes,att);
}


HX_DEFINE_DYNAMIC_FUNC1(CppXml___obj,exists,return )

Dynamic CppXml___obj::attributes( ){
	__SAFE_POINT
	if ((this->nodeType != ::cpp::CppXml___obj::Element))
		hx::Throw (HX_STRING(L"bad nodeType",12));
	return ::Reflect_obj::fields(this->_attributes)->iterator();
}


HX_DEFINE_DYNAMIC_FUNC0(CppXml___obj,attributes,return )

Dynamic CppXml___obj::iterator( ){
	__SAFE_POINT
	if ((this->_children == null()))
		hx::Throw (HX_STRING(L"bad nodetype",12));
	return this->_children->iterator();
}


HX_DEFINE_DYNAMIC_FUNC0(CppXml___obj,iterator,return )

Dynamic CppXml___obj::elements( ){
	if ((this->_children == null()))
		hx::Throw (HX_STRING(L"bad nodetype",12));
	Array< Array< Dynamic > > children = Array_obj< Array< Dynamic > >::__new().Add(this->_children);
	struct _Function_1_1{
		inline static Dynamic Block( Array< Array< Dynamic > > &children){
			hx::Anon __result = hx::Anon_obj::Create();
			__result->Add(HX_STRING(L"cur",3) , 0);

			HX_BEGIN_LOCAL_FUNC1(_Function_2_1,Array< Array< Dynamic > >,children)
			bool run(){
{
					int k = __this->__Field(HX_STRING(L"cur",3)).Cast< int >();
					int l = children[0]->length;
					while((k < l)){
						__SAFE_POINT
						if ((children->__get(0)[k]->__Field(HX_STRING(L"nodeType",8)).Cast< ::String >() == ::cpp::CppXml___obj::Element))
							break;
						hx::AddEq(k,1);
					}
					__this->__FieldRef(HX_STRING(L"cur",3)) = k;
					return (k < l);
				}
				return null();
			}
			Dynamic __this;
			void __SetThis(Dynamic inThis) { __this = inThis; }
			HX_END_LOCAL_FUNC0(return)

			__result->Add(HX_STRING(L"hasNext",7) ,  Dynamic(new _Function_2_1(children)));

			HX_BEGIN_LOCAL_FUNC1(_Function_2_2,Array< Array< Dynamic > >,children)
			Dynamic run(){
{
					int k = __this->__Field(HX_STRING(L"cur",3)).Cast< int >();
					int l = children[0]->length;
					while((k < l)){
						__SAFE_POINT
						Dynamic n = children->__get(0)->__get(k);
						hx::AddEq(k,1);
						if ((n->__Field(HX_STRING(L"nodeType",8)).Cast< ::String >() == ::cpp::CppXml___obj::Element)){
							__this->__FieldRef(HX_STRING(L"cur",3)) = k;
							return n;
						}
					}
					return null();
				}
				return null();
			}
			Dynamic __this;
			void __SetThis(Dynamic inThis) { __this = inThis; }
			HX_END_LOCAL_FUNC0(return)

			__result->Add(HX_STRING(L"next",4) ,  Dynamic(new _Function_2_2(children)));
			return __result;
		}
	};
	return _Function_1_1::Block(children);
}


HX_DEFINE_DYNAMIC_FUNC0(CppXml___obj,elements,return )

Dynamic CppXml___obj::elementsNamed( ::String $t1){
	Array< ::String > name = Array_obj< ::String >::__new().Add($t1);
	if ((this->_children == null()))
		hx::Throw (HX_STRING(L"bad nodetype",12));
	Array< Array< Dynamic > > children = Array_obj< Array< Dynamic > >::__new().Add(this->_children);
	struct _Function_1_1{
		inline static Dynamic Block( Array< Array< Dynamic > > &children,Array< ::String > &name){
			hx::Anon __result = hx::Anon_obj::Create();
			__result->Add(HX_STRING(L"cur",3) , 0);

			HX_BEGIN_LOCAL_FUNC2(_Function_2_1,Array< Array< Dynamic > >,children,Array< ::String >,name)
			bool run(){
{
					int k = __this->__Field(HX_STRING(L"cur",3)).Cast< int >();
					int l = children[0]->length;
					while((k < l)){
						__SAFE_POINT
						Dynamic n = children->__get(0)->__get(k);
						if ((bool((n->__Field(HX_STRING(L"nodeType",8)).Cast< ::String >() == ::cpp::CppXml___obj::Element)) && bool((n->__Field(HX_STRING(L"_nodeName",9)).Cast< ::String >() == name->__get(0)))))
							break;
						k++;
					}
					__this->__FieldRef(HX_STRING(L"cur",3)) = k;
					return (k < l);
				}
				return null();
			}
			Dynamic __this;
			void __SetThis(Dynamic inThis) { __this = inThis; }
			HX_END_LOCAL_FUNC0(return)

			__result->Add(HX_STRING(L"hasNext",7) ,  Dynamic(new _Function_2_1(children,name)));

			HX_BEGIN_LOCAL_FUNC2(_Function_2_2,Array< Array< Dynamic > >,children,Array< ::String >,name)
			Dynamic run(){
{
					int k = __this->__Field(HX_STRING(L"cur",3)).Cast< int >();
					int l = children[0]->length;
					while((k < l)){
						__SAFE_POINT
						Dynamic n = children->__get(0)->__get(k);
						k++;
						if ((bool((n->__Field(HX_STRING(L"nodeType",8)).Cast< ::String >() == ::cpp::CppXml___obj::Element)) && bool((n->__Field(HX_STRING(L"_nodeName",9)).Cast< ::String >() == name->__get(0))))){
							__this->__FieldRef(HX_STRING(L"cur",3)) = k;
							return n;
						}
					}
					return null();
				}
				return null();
			}
			Dynamic __this;
			void __SetThis(Dynamic inThis) { __this = inThis; }
			HX_END_LOCAL_FUNC0(return)

			__result->Add(HX_STRING(L"next",4) ,  Dynamic(new _Function_2_2(children,name)));
			return __result;
		}
	};
	return _Function_1_1::Block(children,name);
}


HX_DEFINE_DYNAMIC_FUNC1(CppXml___obj,elementsNamed,return )

::cpp::CppXml__ CppXml___obj::firstChild( ){
	if ((this->_children == null()))
		hx::Throw (HX_STRING(L"bad nodetype",12));
	return this->_children->__get(0);
}


HX_DEFINE_DYNAMIC_FUNC0(CppXml___obj,firstChild,return )

::cpp::CppXml__ CppXml___obj::firstElement( ){
	if ((this->_children == null()))
		hx::Throw (HX_STRING(L"bad nodetype",12));
	{
		int _g1 = 0;
		int _g = this->_children->length;
		while((_g1 < _g)){
			__SAFE_POINT
			int cur = _g1++;
			::cpp::CppXml__ n = this->_children->__get(cur);
			if ((n->nodeType == ::cpp::CppXml___obj::Element))
				return n;
		}
	}
	return null();
}


HX_DEFINE_DYNAMIC_FUNC0(CppXml___obj,firstElement,return )

Void CppXml___obj::addChild( ::cpp::CppXml__ x_){
{
		__SAFE_POINT
		::cpp::CppXml__ x = x_;
		if ((this->_children == null()))
			hx::Throw (HX_STRING(L"bad nodetype",12));
		if ((x->_parent != null()))
			x->_parent->_children->remove(x);
		x->_parent = this;
		this->_children->push(x);
		return null();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(CppXml___obj,addChild,(void))

bool CppXml___obj::removeChild( ::cpp::CppXml__ x_){
	__SAFE_POINT
	::cpp::CppXml__ x = x_;
	if ((this->_children == null()))
		hx::Throw (HX_STRING(L"bad nodetype",12));
	bool b = this->_children->remove(x);
	if (b)
		x->_parent = null();
	return b;
}


HX_DEFINE_DYNAMIC_FUNC1(CppXml___obj,removeChild,return )

Void CppXml___obj::insertChild( ::cpp::CppXml__ x_,int pos){
{
		__SAFE_POINT
		::cpp::CppXml__ x = x_;
		if ((this->_children == null()))
			hx::Throw (HX_STRING(L"bad nodetype",12));
		if ((x->_parent != null()))
			x->_parent->_children->remove(x);
		x->_parent = this;
		this->_children->insert(pos,x);
		return null();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(CppXml___obj,insertChild,(void))

::String CppXml___obj::toString( ){
	__SAFE_POINT
	if ((this->nodeType == ::cpp::CppXml___obj::PCData))
		return this->_nodeValue;
	if ((this->nodeType == ::cpp::CppXml___obj::CData))
		return (((HX_STRING(L"<![CDATA[",9) + this->_nodeValue)) + HX_STRING(L"]]>",3));
	if ((bool((this->nodeType == ::cpp::CppXml___obj::Comment)) || bool((bool((this->nodeType == ::cpp::CppXml___obj::DocType)) || bool((this->nodeType == ::cpp::CppXml___obj::Prolog))))))
		return this->_nodeValue;
	::StringBuf s = ::StringBuf_obj::__new();
	if ((this->nodeType == ::cpp::CppXml___obj::Element)){
		s->b[s->b->length] = HX_STRING(L"<",1);
		s->b[s->b->length] = this->_nodeName;
		{
			int _g = 0;
			Array< ::String > _g1 = ::Reflect_obj::fields(this->_attributes);
			while((_g < _g1->length)){
				__SAFE_POINT
				::String k = _g1->__get(_g);
				++_g;
				s->b[s->b->length] = HX_STRING(L" ",1);
				s->b[s->b->length] = k;
				s->b[s->b->length] = HX_STRING(L"=\"",2);
				struct _Function_4_1{
					inline static Dynamic Block( ::cpp::CppXml___obj *__this,::String &k)/* DEF (ret block)(not intern) */{
						Dynamic o = __this->_attributes;
						return ((o == null())) ? Dynamic( null() ) : Dynamic( o->__Field(k) );
					}
				};
				s->b[s->b->length] = _Function_4_1::Block(this,k);
				s->b[s->b->length] = HX_STRING(L"\"",1);
			}
		}
		if ((this->_children->length == 0)){
			s->b[s->b->length] = HX_STRING(L"/>",2);
			return s->b->join(HX_STRING(L"",0));
		}
		s->b[s->b->length] = HX_STRING(L">",1);
	}
	for(Dynamic __it = this->iterator();  __it->__Field(HX_STRING(L"hasNext",7))(); ){
::cpp::CppXml__ x = __it->__Field(HX_STRING(L"next",4))();
		s->b[s->b->length] = x;
		__SAFE_POINT
	}
	if ((this->nodeType == ::cpp::CppXml___obj::Element)){
		s->b[s->b->length] = HX_STRING(L"</",2);
		s->b[s->b->length] = this->_nodeName;
		s->b[s->b->length] = HX_STRING(L">",1);
	}
	return s->b->join(HX_STRING(L"",0));
}


HX_DEFINE_DYNAMIC_FUNC0(CppXml___obj,toString,return )

::String CppXml___obj::Element;

::String CppXml___obj::PCData;

::String CppXml___obj::CData;

::String CppXml___obj::Comment;

::String CppXml___obj::DocType;

::String CppXml___obj::Prolog;

::String CppXml___obj::Document;

Dynamic CppXml___obj::_parse;

::cpp::CppXml__ CppXml___obj::parse( ::String xmlData){
	__SAFE_POINT
	::cpp::CppXml__ x = ::cpp::CppXml___obj::__new();
	x->_children = Array_obj< Dynamic >::__new();
	struct _Function_1_1{
		inline static Dynamic Block( ::cpp::CppXml__ &x){
			hx::Anon __result = hx::Anon_obj::Create();
			__result->Add(HX_STRING(L"cur",3) , x);

			HX_BEGIN_LOCAL_FUNC0(_Function_2_1)
			Void run(::String name,Dynamic att){
{
					__SAFE_POINT
					Dynamic x1 = ::cpp::CppXml___obj::__new();
					x1->__FieldRef(HX_STRING(L"_parent",7)) = __this->__Field(HX_STRING(L"cur",3));
					x1->__FieldRef(HX_STRING(L"nodeType",8)) = ::cpp::CppXml___obj::Element;
					x1->__FieldRef(HX_STRING(L"_nodeName",9)) = ::String(name);
					x1->__FieldRef(HX_STRING(L"_attributes",11)) = att;
					x1->__FieldRef(HX_STRING(L"_children",9)) = Array_obj< Dynamic >::__new();
					{
						int i = 0;
						__this->__Field(HX_STRING(L"cur",3))->__Field(HX_STRING(L"addChild",8))(x1);
						__this->__FieldRef(HX_STRING(L"cur",3)) = x1;
					}
				}
				return null();
			}
			Dynamic __this;
			void __SetThis(Dynamic inThis) { __this = inThis; }
			HX_END_LOCAL_FUNC2((void))

			__result->Add(HX_STRING(L"xml",3) ,  Dynamic(new _Function_2_1()));

			HX_BEGIN_LOCAL_FUNC0(_Function_2_2)
			Void run(::String text){
{
					__SAFE_POINT
					::cpp::CppXml__ x1 = ::cpp::CppXml___obj::__new();
					x1->_parent = __this->__Field(HX_STRING(L"cur",3)).Cast< ::cpp::CppXml__ >();
					x1->nodeType = ::cpp::CppXml___obj::CData;
					x1->_nodeValue = ::String(text);
					__this->__Field(HX_STRING(L"cur",3))->__Field(HX_STRING(L"addChild",8))(x1);
				}
				return null();
			}
			Dynamic __this;
			void __SetThis(Dynamic inThis) { __this = inThis; }
			HX_END_LOCAL_FUNC1((void))

			__result->Add(HX_STRING(L"cdata",5) ,  Dynamic(new _Function_2_2()));

			HX_BEGIN_LOCAL_FUNC0(_Function_2_3)
			Void run(::String text){
{
					__SAFE_POINT
					::cpp::CppXml__ x1 = ::cpp::CppXml___obj::__new();
					x1->_parent = __this->__Field(HX_STRING(L"cur",3)).Cast< ::cpp::CppXml__ >();
					x1->nodeType = ::cpp::CppXml___obj::PCData;
					x1->_nodeValue = ::String(text);
					__this->__Field(HX_STRING(L"cur",3))->__Field(HX_STRING(L"addChild",8))(x1);
				}
				return null();
			}
			Dynamic __this;
			void __SetThis(Dynamic inThis) { __this = inThis; }
			HX_END_LOCAL_FUNC1((void))

			__result->Add(HX_STRING(L"pcdata",6) ,  Dynamic(new _Function_2_3()));

			HX_BEGIN_LOCAL_FUNC0(_Function_2_4)
			Void run(::String text){
{
					__SAFE_POINT
					::cpp::CppXml__ x1 = ::cpp::CppXml___obj::__new();
					x1->_parent = __this->__Field(HX_STRING(L"cur",3)).Cast< ::cpp::CppXml__ >();
					if ((text.cca(0) == 63)){
						x1->nodeType = ::cpp::CppXml___obj::Prolog;
						text = (((HX_STRING(L"<",1) + ::String(text))) + HX_STRING(L">",1));
					}
					else{
						x1->nodeType = ::cpp::CppXml___obj::Comment;
						text = (((HX_STRING(L"<!--",4) + ::String(text))) + HX_STRING(L"-->",3));
					}
					x1->_nodeValue = text;
					__this->__Field(HX_STRING(L"cur",3))->__Field(HX_STRING(L"addChild",8))(x1);
				}
				return null();
			}
			Dynamic __this;
			void __SetThis(Dynamic inThis) { __this = inThis; }
			HX_END_LOCAL_FUNC1((void))

			__result->Add(HX_STRING(L"comment",7) ,  Dynamic(new _Function_2_4()));

			HX_BEGIN_LOCAL_FUNC0(_Function_2_5)
			Void run(::String text){
{
					__SAFE_POINT
					::cpp::CppXml__ x1 = ::cpp::CppXml___obj::__new();
					x1->_parent = __this->__Field(HX_STRING(L"cur",3)).Cast< ::cpp::CppXml__ >();
					x1->nodeType = ::cpp::CppXml___obj::DocType;
					x1->_nodeValue = (((HX_STRING(L"<!DOCTYPE",9) + ::String(text))) + HX_STRING(L">",1));
					__this->__Field(HX_STRING(L"cur",3))->__Field(HX_STRING(L"addChild",8))(x1);
				}
				return null();
			}
			Dynamic __this;
			void __SetThis(Dynamic inThis) { __this = inThis; }
			HX_END_LOCAL_FUNC1((void))

			__result->Add(HX_STRING(L"doctype",7) ,  Dynamic(new _Function_2_5()));

			HX_BEGIN_LOCAL_FUNC0(_Function_2_6)
			Void run(){
{
					__this->__FieldRef(HX_STRING(L"cur",3)) = __this->__Field(HX_STRING(L"cur",3))->__Field(HX_STRING(L"_parent",7));
				}
				return null();
			}
			Dynamic __this;
			void __SetThis(Dynamic inThis) { __this = inThis; }
			HX_END_LOCAL_FUNC0((void))

			__result->Add(HX_STRING(L"done",4) ,  Dynamic(new _Function_2_6()));
			return __result;
		}
	};
	Dynamic parser = _Function_1_1::Block(x);
	::cpp::CppXml___obj::_parse(xmlData,parser);
	x->nodeType = ::cpp::CppXml___obj::Document;
	return x;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(CppXml___obj,parse,return )

::cpp::CppXml__ CppXml___obj::createElement( ::String name){
	::cpp::CppXml__ r = ::cpp::CppXml___obj::__new();
	r->nodeType = ::cpp::CppXml___obj::Element;
	r->_nodeName = name;
	r->_attributes = null();
	r->_children = Array_obj< Dynamic >::__new();
	return r;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(CppXml___obj,createElement,return )

::cpp::CppXml__ CppXml___obj::createPCData( ::String data){
	::cpp::CppXml__ r = ::cpp::CppXml___obj::__new();
	r->nodeType = ::cpp::CppXml___obj::PCData;
	r->_nodeValue = data;
	return r;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(CppXml___obj,createPCData,return )

::cpp::CppXml__ CppXml___obj::createCData( ::String data){
	::cpp::CppXml__ r = ::cpp::CppXml___obj::__new();
	r->nodeType = ::cpp::CppXml___obj::CData;
	r->_nodeValue = data;
	return r;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(CppXml___obj,createCData,return )

::cpp::CppXml__ CppXml___obj::createComment( ::String data){
	::cpp::CppXml__ r = ::cpp::CppXml___obj::__new();
	r->nodeType = ::cpp::CppXml___obj::Comment;
	r->_nodeValue = data;
	return r;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(CppXml___obj,createComment,return )

::cpp::CppXml__ CppXml___obj::createDocType( ::String data){
	::cpp::CppXml__ r = ::cpp::CppXml___obj::__new();
	r->nodeType = ::cpp::CppXml___obj::DocType;
	r->_nodeValue = data;
	return r;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(CppXml___obj,createDocType,return )

::cpp::CppXml__ CppXml___obj::createProlog( ::String data){
	::cpp::CppXml__ r = ::cpp::CppXml___obj::__new();
	r->nodeType = ::cpp::CppXml___obj::Prolog;
	r->_nodeValue = data;
	return r;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(CppXml___obj,createProlog,return )

::cpp::CppXml__ CppXml___obj::createDocument( ){
	::cpp::CppXml__ r = ::cpp::CppXml___obj::__new();
	r->nodeType = ::cpp::CppXml___obj::Document;
	r->_children = Array_obj< Dynamic >::__new();
	return r;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(CppXml___obj,createDocument,return )


CppXml___obj::CppXml___obj()
{
}

void CppXml___obj::__Mark()
{
	hx::MarkMember(_nodeName);
	hx::MarkMember(_nodeValue);
	hx::MarkMember(_attributes);
	hx::MarkMember(_children);
	hx::MarkMember(_parent);
	hx::MarkMember(nodeType);
	hx::MarkMember(nodeName);
	hx::MarkMember(nodeValue);
}

Dynamic CppXml___obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 3:
		if (!memcmp(inName.__s,L"get",sizeof(wchar_t)*3) ) { return get_dyn(); }
		if (!memcmp(inName.__s,L"set",sizeof(wchar_t)*3) ) { return set_dyn(); }
		break;
	case 5:
		if (!memcmp(inName.__s,L"CData",sizeof(wchar_t)*5) ) { return CData; }
		if (!memcmp(inName.__s,L"parse",sizeof(wchar_t)*5) ) { return parse_dyn(); }
		break;
	case 6:
		if (!memcmp(inName.__s,L"PCData",sizeof(wchar_t)*6) ) { return PCData; }
		if (!memcmp(inName.__s,L"Prolog",sizeof(wchar_t)*6) ) { return Prolog; }
		if (!memcmp(inName.__s,L"_parse",sizeof(wchar_t)*6) ) { return _parse; }
		if (!memcmp(inName.__s,L"remove",sizeof(wchar_t)*6) ) { return remove_dyn(); }
		if (!memcmp(inName.__s,L"exists",sizeof(wchar_t)*6) ) { return exists_dyn(); }
		break;
	case 7:
		if (!memcmp(inName.__s,L"Element",sizeof(wchar_t)*7) ) { return Element; }
		if (!memcmp(inName.__s,L"Comment",sizeof(wchar_t)*7) ) { return Comment; }
		if (!memcmp(inName.__s,L"DocType",sizeof(wchar_t)*7) ) { return DocType; }
		if (!memcmp(inName.__s,L"_parent",sizeof(wchar_t)*7) ) { return _parent; }
		break;
	case 8:
		if (!memcmp(inName.__s,L"Document",sizeof(wchar_t)*8) ) { return Document; }
		if (!memcmp(inName.__s,L"nodeType",sizeof(wchar_t)*8) ) { return nodeType; }
		if (!memcmp(inName.__s,L"nodeName",sizeof(wchar_t)*8) ) { return getNodeName(); }
		if (!memcmp(inName.__s,L"iterator",sizeof(wchar_t)*8) ) { return iterator_dyn(); }
		if (!memcmp(inName.__s,L"elements",sizeof(wchar_t)*8) ) { return elements_dyn(); }
		if (!memcmp(inName.__s,L"addChild",sizeof(wchar_t)*8) ) { return addChild_dyn(); }
		if (!memcmp(inName.__s,L"toString",sizeof(wchar_t)*8) ) { return toString_dyn(); }
		break;
	case 9:
		if (!memcmp(inName.__s,L"_nodeName",sizeof(wchar_t)*9) ) { return _nodeName; }
		if (!memcmp(inName.__s,L"_children",sizeof(wchar_t)*9) ) { return _children; }
		if (!memcmp(inName.__s,L"nodeValue",sizeof(wchar_t)*9) ) { return getNodeValue(); }
		if (!memcmp(inName.__s,L"getParent",sizeof(wchar_t)*9) ) { return getParent_dyn(); }
		break;
	case 10:
		if (!memcmp(inName.__s,L"_nodeValue",sizeof(wchar_t)*10) ) { return _nodeValue; }
		if (!memcmp(inName.__s,L"attributes",sizeof(wchar_t)*10) ) { return attributes_dyn(); }
		if (!memcmp(inName.__s,L"firstChild",sizeof(wchar_t)*10) ) { return firstChild_dyn(); }
		break;
	case 11:
		if (!memcmp(inName.__s,L"createCData",sizeof(wchar_t)*11) ) { return createCData_dyn(); }
		if (!memcmp(inName.__s,L"_attributes",sizeof(wchar_t)*11) ) { return _attributes; }
		if (!memcmp(inName.__s,L"getNodeName",sizeof(wchar_t)*11) ) { return getNodeName_dyn(); }
		if (!memcmp(inName.__s,L"setNodeName",sizeof(wchar_t)*11) ) { return setNodeName_dyn(); }
		if (!memcmp(inName.__s,L"removeChild",sizeof(wchar_t)*11) ) { return removeChild_dyn(); }
		if (!memcmp(inName.__s,L"insertChild",sizeof(wchar_t)*11) ) { return insertChild_dyn(); }
		break;
	case 12:
		if (!memcmp(inName.__s,L"createPCData",sizeof(wchar_t)*12) ) { return createPCData_dyn(); }
		if (!memcmp(inName.__s,L"createProlog",sizeof(wchar_t)*12) ) { return createProlog_dyn(); }
		if (!memcmp(inName.__s,L"getNodeValue",sizeof(wchar_t)*12) ) { return getNodeValue_dyn(); }
		if (!memcmp(inName.__s,L"setNodeValue",sizeof(wchar_t)*12) ) { return setNodeValue_dyn(); }
		if (!memcmp(inName.__s,L"firstElement",sizeof(wchar_t)*12) ) { return firstElement_dyn(); }
		break;
	case 13:
		if (!memcmp(inName.__s,L"createElement",sizeof(wchar_t)*13) ) { return createElement_dyn(); }
		if (!memcmp(inName.__s,L"createComment",sizeof(wchar_t)*13) ) { return createComment_dyn(); }
		if (!memcmp(inName.__s,L"createDocType",sizeof(wchar_t)*13) ) { return createDocType_dyn(); }
		if (!memcmp(inName.__s,L"elementsNamed",sizeof(wchar_t)*13) ) { return elementsNamed_dyn(); }
		break;
	case 14:
		if (!memcmp(inName.__s,L"createDocument",sizeof(wchar_t)*14) ) { return createDocument_dyn(); }
	}
	return super::__Field(inName);
}

Dynamic CppXml___obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	switch(inName.length) {
	case 5:
		if (!memcmp(inName.__s,L"CData",sizeof(wchar_t)*5) ) { CData=inValue.Cast< ::String >(); return inValue; }
		break;
	case 6:
		if (!memcmp(inName.__s,L"PCData",sizeof(wchar_t)*6) ) { PCData=inValue.Cast< ::String >(); return inValue; }
		if (!memcmp(inName.__s,L"Prolog",sizeof(wchar_t)*6) ) { Prolog=inValue.Cast< ::String >(); return inValue; }
		if (!memcmp(inName.__s,L"_parse",sizeof(wchar_t)*6) ) { _parse=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 7:
		if (!memcmp(inName.__s,L"Element",sizeof(wchar_t)*7) ) { Element=inValue.Cast< ::String >(); return inValue; }
		if (!memcmp(inName.__s,L"Comment",sizeof(wchar_t)*7) ) { Comment=inValue.Cast< ::String >(); return inValue; }
		if (!memcmp(inName.__s,L"DocType",sizeof(wchar_t)*7) ) { DocType=inValue.Cast< ::String >(); return inValue; }
		if (!memcmp(inName.__s,L"_parent",sizeof(wchar_t)*7) ) { _parent=inValue.Cast< ::cpp::CppXml__ >(); return inValue; }
		break;
	case 8:
		if (!memcmp(inName.__s,L"Document",sizeof(wchar_t)*8) ) { Document=inValue.Cast< ::String >(); return inValue; }
		if (!memcmp(inName.__s,L"nodeType",sizeof(wchar_t)*8) ) { nodeType=inValue.Cast< ::String >(); return inValue; }
		if (!memcmp(inName.__s,L"nodeName",sizeof(wchar_t)*8) ) { return setNodeName(inValue); }
		break;
	case 9:
		if (!memcmp(inName.__s,L"_nodeName",sizeof(wchar_t)*9) ) { _nodeName=inValue.Cast< ::String >(); return inValue; }
		if (!memcmp(inName.__s,L"_children",sizeof(wchar_t)*9) ) { _children=inValue.Cast< Array< Dynamic > >(); return inValue; }
		if (!memcmp(inName.__s,L"nodeValue",sizeof(wchar_t)*9) ) { return setNodeValue(inValue); }
		break;
	case 10:
		if (!memcmp(inName.__s,L"_nodeValue",sizeof(wchar_t)*10) ) { _nodeValue=inValue.Cast< ::String >(); return inValue; }
		break;
	case 11:
		if (!memcmp(inName.__s,L"_attributes",sizeof(wchar_t)*11) ) { _attributes=inValue.Cast< Dynamic >(); return inValue; }
	}
	return super::__SetField(inName,inValue);
}

void CppXml___obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_STRING(L"_nodeName",9));
	outFields->push(HX_STRING(L"_nodeValue",10));
	outFields->push(HX_STRING(L"_attributes",11));
	outFields->push(HX_STRING(L"_children",9));
	outFields->push(HX_STRING(L"_parent",7));
	outFields->push(HX_STRING(L"nodeType",8));
	outFields->push(HX_STRING(L"nodeName",8));
	outFields->push(HX_STRING(L"nodeValue",9));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_STRING(L"Element",7),
	HX_STRING(L"PCData",6),
	HX_STRING(L"CData",5),
	HX_STRING(L"Comment",7),
	HX_STRING(L"DocType",7),
	HX_STRING(L"Prolog",6),
	HX_STRING(L"Document",8),
	HX_STRING(L"_parse",6),
	HX_STRING(L"parse",5),
	HX_STRING(L"createElement",13),
	HX_STRING(L"createPCData",12),
	HX_STRING(L"createCData",11),
	HX_STRING(L"createComment",13),
	HX_STRING(L"createDocType",13),
	HX_STRING(L"createProlog",12),
	HX_STRING(L"createDocument",14),
	String(null()) };

static ::String sMemberFields[] = {
	HX_STRING(L"_nodeName",9),
	HX_STRING(L"_nodeValue",10),
	HX_STRING(L"_attributes",11),
	HX_STRING(L"_children",9),
	HX_STRING(L"_parent",7),
	HX_STRING(L"nodeType",8),
	HX_STRING(L"nodeName",8),
	HX_STRING(L"nodeValue",9),
	HX_STRING(L"getNodeName",11),
	HX_STRING(L"setNodeName",11),
	HX_STRING(L"getNodeValue",12),
	HX_STRING(L"setNodeValue",12),
	HX_STRING(L"getParent",9),
	HX_STRING(L"get",3),
	HX_STRING(L"set",3),
	HX_STRING(L"remove",6),
	HX_STRING(L"exists",6),
	HX_STRING(L"attributes",10),
	HX_STRING(L"iterator",8),
	HX_STRING(L"elements",8),
	HX_STRING(L"elementsNamed",13),
	HX_STRING(L"firstChild",10),
	HX_STRING(L"firstElement",12),
	HX_STRING(L"addChild",8),
	HX_STRING(L"removeChild",11),
	HX_STRING(L"insertChild",11),
	HX_STRING(L"toString",8),
	String(null()) };

static void sMarkStatics() {
	hx::MarkMember(CppXml___obj::Element);
	hx::MarkMember(CppXml___obj::PCData);
	hx::MarkMember(CppXml___obj::CData);
	hx::MarkMember(CppXml___obj::Comment);
	hx::MarkMember(CppXml___obj::DocType);
	hx::MarkMember(CppXml___obj::Prolog);
	hx::MarkMember(CppXml___obj::Document);
	hx::MarkMember(CppXml___obj::_parse);
};

Class CppXml___obj::__mClass;

void CppXml___obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_STRING(L"Xml",3), hx::TCanCast< CppXml___obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void CppXml___obj::__boot()
{
	hx::Static(Element);
	hx::Static(PCData);
	hx::Static(CData);
	hx::Static(Comment);
	hx::Static(DocType);
	hx::Static(Prolog);
	hx::Static(Document);
	hx::Static(_parse) = ::cpp::Lib_obj::load(HX_STRING(L"std",3),HX_STRING(L"parse_xml",9),2);
}

} // end namespace cpp
