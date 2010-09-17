#include <hxcpp.h>

#ifndef INCLUDED_hxMath
#include <hxMath.h>
#endif
#ifndef INCLUDED_sandy_bounds_BBox
#include <sandy/bounds/BBox.h>
#endif
#ifndef INCLUDED_sandy_core_data_Matrix4
#include <sandy/core/data/Matrix4.h>
#endif
#ifndef INCLUDED_sandy_core_data_Point3D
#include <sandy/core/data/Point3D.h>
#endif
#ifndef INCLUDED_sandy_core_data_Pool
#include <sandy/core/data/Pool.h>
#endif
#ifndef INCLUDED_sandy_core_data_Vertex
#include <sandy/core/data/Vertex.h>
#endif
namespace sandy{
namespace bounds{

Void BBox_obj::__construct(::sandy::core::data::Point3D p_min,::sandy::core::data::Point3D p_max)
{
{
	this->uptodate = false;
	this->minEdge = ((p_min != null())) ? ::sandy::core::data::Point3D( p_min ) : ::sandy::core::data::Point3D( ::sandy::core::data::Point3D_obj::__new(null(),null(),null()) );
	this->maxEdge = ((p_max != null())) ? ::sandy::core::data::Point3D( p_max ) : ::sandy::core::data::Point3D( ::sandy::core::data::Point3D_obj::__new(null(),null(),null()) );
}
;
	return null();
}

BBox_obj::~BBox_obj() { }

Dynamic BBox_obj::__CreateEmpty() { return  new BBox_obj; }
hx::ObjectPtr< BBox_obj > BBox_obj::__new(::sandy::core::data::Point3D p_min,::sandy::core::data::Point3D p_max)
{  hx::ObjectPtr< BBox_obj > result = new BBox_obj();
	result->__construct(p_min,p_max);
	return result;}

Dynamic BBox_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< BBox_obj > result = new BBox_obj();
	result->__construct(inArgs[0],inArgs[1]);
	return result;}

Void BBox_obj::addInternalPoint( ::sandy::core::data::Point3D p_oPoint){
{
		if ((p_oPoint->x > this->maxEdge->x)){
			this->maxEdge->x = p_oPoint->x;
		}
		if ((p_oPoint->y > this->maxEdge->y)){
			this->maxEdge->y = p_oPoint->y;
		}
		if ((p_oPoint->z > this->maxEdge->z)){
			this->maxEdge->z = p_oPoint->z;
		}
		if ((p_oPoint->x < this->minEdge->x)){
			this->minEdge->x = p_oPoint->x;
		}
		if ((p_oPoint->y < this->minEdge->y)){
			this->minEdge->y = p_oPoint->y;
		}
		if ((p_oPoint->z < this->minEdge->z)){
			this->minEdge->z = p_oPoint->z;
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(BBox_obj,addInternalPoint,(void))

Void BBox_obj::addInternalPointXYZ( double x,double y,double z){
{
		if ((x > this->maxEdge->x)){
			this->maxEdge->x = x;
		}
		if ((y > this->maxEdge->y)){
			this->maxEdge->y = y;
		}
		if ((z > this->maxEdge->z)){
			this->maxEdge->z = z;
		}
		if ((x < this->minEdge->x)){
			this->minEdge->x = x;
		}
		if ((y < this->minEdge->y)){
			this->minEdge->y = y;
		}
		if ((z < this->minEdge->z)){
			this->minEdge->z = z;
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC3(BBox_obj,addInternalPointXYZ,(void))

::sandy::bounds::BBox BBox_obj::clone( ){
	__SAFE_POINT
	::sandy::bounds::BBox l_oBBox = ::sandy::bounds::BBox_obj::__new(null(),null());
	l_oBBox->maxEdge = this->maxEdge->clone();
	l_oBBox->minEdge = this->minEdge->clone();
	return l_oBBox;
}


HX_DEFINE_DYNAMIC_FUNC0(BBox_obj,clone,return )

Void BBox_obj::copy( ::sandy::bounds::BBox p_oBBox){
{
		__SAFE_POINT
		this->uptodate = p_oBBox->uptodate;
		this->minEdge->copy(p_oBBox->minEdge);
		this->maxEdge->copy(p_oBBox->maxEdge);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(BBox_obj,copy,(void))

Void BBox_obj::merge( ::sandy::bounds::BBox box){
{
		__SAFE_POINT
		this->addInternalPointXYZ(box->maxEdge->x,box->maxEdge->y,box->maxEdge->z);
		this->addInternalPointXYZ(box->minEdge->x,box->minEdge->y,box->minEdge->z);
		this->uptodate = false;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(BBox_obj,merge,(void))

::sandy::core::data::Point3D BBox_obj::getCenter( ){
	return ::sandy::core::data::Point3D_obj::__new((double(((this->maxEdge->x + this->minEdge->x))) / double(2)),(double(((this->maxEdge->y + this->minEdge->y))) / double(2)),(double(((this->maxEdge->z + this->minEdge->z))) / double(2)));
}


HX_DEFINE_DYNAMIC_FUNC0(BBox_obj,getCenter,return )

Void BBox_obj::getEdges( Array< ::sandy::core::data::Point3D > edges){
{
		if ((edges == null()))
			return null();
		double centerX = (double(((this->maxEdge->x + this->minEdge->x))) / double(2));
		double centerY = (double(((this->maxEdge->y + this->minEdge->y))) / double(2));
		double centerZ = (double(((this->maxEdge->z + this->minEdge->z))) / double(2));
		double diagX = (centerX - this->maxEdge->x);
		double diagY = (centerY - this->maxEdge->y);
		double diagZ = (centerZ - this->maxEdge->z);
		::sandy::core::data::Point3D _g = edges->__get(0);
		_g->x = (centerX + diagX);
		_g->y = (centerY + diagY);
		_g->z = (centerZ + diagZ);
		_g = edges->__get(1);
		_g->x = (centerX + diagX);
		_g->y = (centerY - diagY);
		_g->z = (centerZ + diagZ);
		_g = edges->__get(2);
		_g->x = (centerX + diagX);
		_g->y = (centerY + diagY);
		_g->z = (centerZ - diagZ);
		_g = edges->__get(3);
		_g->x = (centerX + diagX);
		_g->y = (centerY - diagY);
		_g->z = (centerZ - diagZ);
		_g = edges->__get(4);
		_g->x = (centerX - diagX);
		_g->y = (centerY + diagY);
		_g->z = (centerZ + diagZ);
		_g = edges->__get(5);
		_g->x = (centerX - diagX);
		_g->y = (centerY - diagY);
		_g->z = (centerZ + diagZ);
		_g = edges->__get(6);
		_g->x = (centerX - diagX);
		_g->y = (centerY + diagY);
		_g->z = (centerZ - diagZ);
		_g = edges->__get(7);
		_g->x = (centerX - diagX);
		_g->y = (centerY - diagY);
		_g->z = (centerZ - diagZ);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(BBox_obj,getEdges,(void))

double BBox_obj::getDepth( ){
	__SAFE_POINT
	return ::Math_obj::abs((this->maxEdge->z - this->minEdge->z));
}


HX_DEFINE_DYNAMIC_FUNC0(BBox_obj,getDepth,return )

double BBox_obj::getHeight( ){
	__SAFE_POINT
	return ::Math_obj::abs((this->maxEdge->y - this->minEdge->y));
}


HX_DEFINE_DYNAMIC_FUNC0(BBox_obj,getHeight,return )

::sandy::core::data::Point3D BBox_obj::getSize( ){
	__SAFE_POINT
	return ::sandy::core::data::Point3D_obj::__new(::Math_obj::abs((this->maxEdge->x - this->minEdge->x)),::Math_obj::abs((this->maxEdge->y - this->minEdge->y)),::Math_obj::abs((this->maxEdge->z - this->minEdge->z)));
}


HX_DEFINE_DYNAMIC_FUNC0(BBox_obj,getSize,return )

double BBox_obj::getWidth( ){
	__SAFE_POINT
	return ::Math_obj::abs((this->maxEdge->x - this->minEdge->x));
}


HX_DEFINE_DYNAMIC_FUNC0(BBox_obj,getWidth,return )

bool BBox_obj::intersectsBox( ::sandy::bounds::BBox box){
	return ((bool((this->minEdge->x <= box->maxEdge->x)) && bool((bool((this->minEdge->y <= box->maxEdge->y)) && bool((bool((this->minEdge->z <= box->maxEdge->z)) && bool((bool((this->maxEdge->x >= box->minEdge->x)) && bool((bool((this->maxEdge->y >= box->minEdge->y)) && bool((this->maxEdge->z >= box->minEdge->z))))))))))));
}


HX_DEFINE_DYNAMIC_FUNC1(BBox_obj,intersectsBox,return )

bool BBox_obj::isPointInsideXYZ( double x,double y,double z){
	return ((bool((x >= this->minEdge->x)) && bool((bool((x <= this->maxEdge->x)) && bool((bool((y >= this->minEdge->y)) && bool((bool((y <= this->maxEdge->y)) && bool((bool((z >= this->minEdge->z)) && bool((z <= this->maxEdge->z))))))))))));
}


HX_DEFINE_DYNAMIC_FUNC3(BBox_obj,isPointInsideXYZ,return )

bool BBox_obj::isPointTotalInside( ::sandy::core::data::Point3D p_oPoint){
	return ((bool((p_oPoint->x > this->minEdge->x)) && bool((bool((p_oPoint->x < this->maxEdge->x)) && bool((bool((p_oPoint->y > this->minEdge->y)) && bool((bool((p_oPoint->y < this->maxEdge->y)) && bool((bool((p_oPoint->z > this->minEdge->z)) && bool((p_oPoint->z < this->maxEdge->z))))))))))));
}


HX_DEFINE_DYNAMIC_FUNC1(BBox_obj,isPointTotalInside,return )

::sandy::bounds::BBox BBox_obj::movedTo( ::sandy::core::data::Point3D pos){
	__SAFE_POINT
	::sandy::core::data::Point3D max = this->maxEdge->clone();
	::sandy::core::data::Point3D min = this->minEdge->clone();
	::sandy::core::data::Point3D cen = this->getCenter();
	cen->sub(pos);
	max->sub(cen);
	min->sub(cen);
	::sandy::bounds::BBox b = ::sandy::bounds::BBox_obj::__new(null(),null());
	b->maxEdge = max;
	b->minEdge = min;
	return b;
}


HX_DEFINE_DYNAMIC_FUNC1(BBox_obj,movedTo,return )

::sandy::bounds::BBox BBox_obj::movedToXYZ( double p_fX,double p_fY,double p_fZ){
	__SAFE_POINT
	return this->movedTo(::sandy::core::data::Point3D_obj::__new(p_fX,p_fY,p_fZ));
}


HX_DEFINE_DYNAMIC_FUNC3(BBox_obj,movedToXYZ,return )

Void BBox_obj::reset( ){
{
		__SAFE_POINT
		this->minEdge->reset(null(),null(),null());
		this->maxEdge->reset(null(),null(),null());
		this->uptodate = false;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(BBox_obj,reset,(void))

::sandy::bounds::BBox BBox_obj::transform( ::sandy::core::data::Matrix4 p_oMatrix){
	__SAFE_POINT
	::sandy::bounds::BBox l_oBox = ::sandy::bounds::BBox_obj::__new(null(),null());
	::sandy::core::data::Pool inst = ::sandy::core::data::Pool_obj::getInstance();
	Array< ::sandy::core::data::Point3D > l_aEdges = Array_obj< ::sandy::core::data::Point3D >::__new().Add(inst->__getNextPoint3D()).Add(inst->__getNextPoint3D()).Add(inst->__getNextPoint3D()).Add(inst->__getNextPoint3D()).Add(inst->__getNextPoint3D()).Add(inst->__getNextPoint3D()).Add(inst->__getNextPoint3D()).Add(inst->__getNextPoint3D());
	this->getEdges(l_aEdges);
	{
		int _g = 0;
		while((_g < l_aEdges->length)){
			__SAFE_POINT
			::sandy::core::data::Point3D l_oEdge = l_aEdges->__get(_g);
			++_g;
			p_oMatrix->transform(l_oEdge);
			l_oBox->addInternalPoint(l_oEdge);
		}
	}
	return l_oBox;
}


HX_DEFINE_DYNAMIC_FUNC1(BBox_obj,transform,return )

::String BBox_obj::toString( ){
	__SAFE_POINT
	return (((((HX_STRING(L"sandy.bounds.BBox ",18) + this->minEdge->toString())) + HX_STRING(L" ",1))) + this->maxEdge->toString());
}


HX_DEFINE_DYNAMIC_FUNC0(BBox_obj,toString,return )

::sandy::bounds::BBox BBox_obj::create( Array< ::sandy::core::data::Vertex > p_aVertices){
	__SAFE_POINT
	if ((p_aVertices->length == 0))
		return null();
	::sandy::bounds::BBox l_oBox = ::sandy::bounds::BBox_obj::__new(null(),null());
	::sandy::core::data::Vertex l_oVertex = p_aVertices->__get(0);
	l_oBox->minEdge->reset(l_oVertex->x,l_oVertex->y,l_oVertex->z);
	l_oBox->maxEdge->reset(l_oVertex->x,l_oVertex->y,l_oVertex->z);
	{
		int _g = 0;
		while((_g < p_aVertices->length)){
			__SAFE_POINT
			::sandy::core::data::Vertex l_oVertex1 = p_aVertices->__get(_g);
			++_g;
			l_oBox->addInternalPointXYZ(l_oVertex1->x,l_oVertex1->y,l_oVertex1->z);
		}
	}
	return l_oBox;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(BBox_obj,create,return )


BBox_obj::BBox_obj()
{
}

void BBox_obj::__Mark()
{
	hx::MarkMember(uptodate);
	hx::MarkMember(maxEdge);
	hx::MarkMember(minEdge);
}

Dynamic BBox_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 4:
		if (!memcmp(inName.__s,L"copy",sizeof(wchar_t)*4) ) { return copy_dyn(); }
		break;
	case 5:
		if (!memcmp(inName.__s,L"clone",sizeof(wchar_t)*5) ) { return clone_dyn(); }
		if (!memcmp(inName.__s,L"merge",sizeof(wchar_t)*5) ) { return merge_dyn(); }
		if (!memcmp(inName.__s,L"reset",sizeof(wchar_t)*5) ) { return reset_dyn(); }
		break;
	case 6:
		if (!memcmp(inName.__s,L"create",sizeof(wchar_t)*6) ) { return create_dyn(); }
		break;
	case 7:
		if (!memcmp(inName.__s,L"maxEdge",sizeof(wchar_t)*7) ) { return maxEdge; }
		if (!memcmp(inName.__s,L"minEdge",sizeof(wchar_t)*7) ) { return minEdge; }
		if (!memcmp(inName.__s,L"getSize",sizeof(wchar_t)*7) ) { return getSize_dyn(); }
		if (!memcmp(inName.__s,L"movedTo",sizeof(wchar_t)*7) ) { return movedTo_dyn(); }
		break;
	case 8:
		if (!memcmp(inName.__s,L"uptodate",sizeof(wchar_t)*8) ) { return uptodate; }
		if (!memcmp(inName.__s,L"getEdges",sizeof(wchar_t)*8) ) { return getEdges_dyn(); }
		if (!memcmp(inName.__s,L"getDepth",sizeof(wchar_t)*8) ) { return getDepth_dyn(); }
		if (!memcmp(inName.__s,L"getWidth",sizeof(wchar_t)*8) ) { return getWidth_dyn(); }
		if (!memcmp(inName.__s,L"toString",sizeof(wchar_t)*8) ) { return toString_dyn(); }
		break;
	case 9:
		if (!memcmp(inName.__s,L"getCenter",sizeof(wchar_t)*9) ) { return getCenter_dyn(); }
		if (!memcmp(inName.__s,L"getHeight",sizeof(wchar_t)*9) ) { return getHeight_dyn(); }
		if (!memcmp(inName.__s,L"transform",sizeof(wchar_t)*9) ) { return transform_dyn(); }
		break;
	case 10:
		if (!memcmp(inName.__s,L"movedToXYZ",sizeof(wchar_t)*10) ) { return movedToXYZ_dyn(); }
		break;
	case 13:
		if (!memcmp(inName.__s,L"intersectsBox",sizeof(wchar_t)*13) ) { return intersectsBox_dyn(); }
		break;
	case 16:
		if (!memcmp(inName.__s,L"addInternalPoint",sizeof(wchar_t)*16) ) { return addInternalPoint_dyn(); }
		if (!memcmp(inName.__s,L"isPointInsideXYZ",sizeof(wchar_t)*16) ) { return isPointInsideXYZ_dyn(); }
		break;
	case 18:
		if (!memcmp(inName.__s,L"isPointTotalInside",sizeof(wchar_t)*18) ) { return isPointTotalInside_dyn(); }
		break;
	case 19:
		if (!memcmp(inName.__s,L"addInternalPointXYZ",sizeof(wchar_t)*19) ) { return addInternalPointXYZ_dyn(); }
	}
	return super::__Field(inName);
}

Dynamic BBox_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	switch(inName.length) {
	case 7:
		if (!memcmp(inName.__s,L"maxEdge",sizeof(wchar_t)*7) ) { maxEdge=inValue.Cast< ::sandy::core::data::Point3D >(); return inValue; }
		if (!memcmp(inName.__s,L"minEdge",sizeof(wchar_t)*7) ) { minEdge=inValue.Cast< ::sandy::core::data::Point3D >(); return inValue; }
		break;
	case 8:
		if (!memcmp(inName.__s,L"uptodate",sizeof(wchar_t)*8) ) { uptodate=inValue.Cast< bool >(); return inValue; }
	}
	return super::__SetField(inName,inValue);
}

void BBox_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_STRING(L"uptodate",8));
	outFields->push(HX_STRING(L"maxEdge",7));
	outFields->push(HX_STRING(L"minEdge",7));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_STRING(L"create",6),
	String(null()) };

static ::String sMemberFields[] = {
	HX_STRING(L"uptodate",8),
	HX_STRING(L"maxEdge",7),
	HX_STRING(L"minEdge",7),
	HX_STRING(L"addInternalPoint",16),
	HX_STRING(L"addInternalPointXYZ",19),
	HX_STRING(L"clone",5),
	HX_STRING(L"copy",4),
	HX_STRING(L"merge",5),
	HX_STRING(L"getCenter",9),
	HX_STRING(L"getEdges",8),
	HX_STRING(L"getDepth",8),
	HX_STRING(L"getHeight",9),
	HX_STRING(L"getSize",7),
	HX_STRING(L"getWidth",8),
	HX_STRING(L"intersectsBox",13),
	HX_STRING(L"isPointInsideXYZ",16),
	HX_STRING(L"isPointTotalInside",18),
	HX_STRING(L"movedTo",7),
	HX_STRING(L"movedToXYZ",10),
	HX_STRING(L"reset",5),
	HX_STRING(L"transform",9),
	HX_STRING(L"toString",8),
	String(null()) };

static void sMarkStatics() {
};

Class BBox_obj::__mClass;

void BBox_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_STRING(L"sandy.bounds.BBox",17), hx::TCanCast< BBox_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void BBox_obj::__boot()
{
}

} // end namespace sandy
} // end namespace bounds
