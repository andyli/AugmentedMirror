#include <hxcpp.h>

#ifndef INCLUDED_hxMath
#include <hxMath.h>
#endif
#ifndef INCLUDED_org_casalib_math_Percent
#include <org/casalib/math/Percent.h>
#endif
#ifndef INCLUDED_org_casalib_math_geom_Point3d
#include <org/casalib/math/geom/Point3d.h>
#endif
namespace org{
namespace casalib{
namespace math{
namespace geom{

Void Point3d_obj::__construct(Dynamic __o_x,Dynamic __o_y,Dynamic __o_z)
{
double x = __o_x.Default(0);
double y = __o_y.Default(0);
double z = __o_z.Default(0);
{
	{
		this->_x = x;
		x;
	}
	{
		this->_y = y;
		y;
	}
	{
		this->_z = z;
		z;
	}
}
;
	return null();
}

Point3d_obj::~Point3d_obj() { }

Dynamic Point3d_obj::__CreateEmpty() { return  new Point3d_obj; }
hx::ObjectPtr< Point3d_obj > Point3d_obj::__new(Dynamic __o_x,Dynamic __o_y,Dynamic __o_z)
{  hx::ObjectPtr< Point3d_obj > result = new Point3d_obj();
	result->__construct(__o_x,__o_y,__o_z);
	return result;}

Dynamic Point3d_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Point3d_obj > result = new Point3d_obj();
	result->__construct(inArgs[0],inArgs[1],inArgs[2]);
	return result;}

double Point3d_obj::getX( ){
	return this->_x;
}


HX_DEFINE_DYNAMIC_FUNC0(Point3d_obj,getX,return )

double Point3d_obj::setX( double position){
	this->_x = position;
	return position;
}


HX_DEFINE_DYNAMIC_FUNC1(Point3d_obj,setX,return )

double Point3d_obj::getY( ){
	return this->_y;
}


HX_DEFINE_DYNAMIC_FUNC0(Point3d_obj,getY,return )

double Point3d_obj::setY( double position){
	this->_y = position;
	return position;
}


HX_DEFINE_DYNAMIC_FUNC1(Point3d_obj,setY,return )

double Point3d_obj::getZ( ){
	return this->_z;
}


HX_DEFINE_DYNAMIC_FUNC0(Point3d_obj,getZ,return )

double Point3d_obj::setZ( double position){
	this->_z = position;
	return position;
}


HX_DEFINE_DYNAMIC_FUNC1(Point3d_obj,setZ,return )

::org::casalib::math::geom::Point3d Point3d_obj::add( ::org::casalib::math::geom::Point3d point){
	return ::org::casalib::math::geom::Point3d_obj::__new((this->_x + point->_x),(this->_y + point->_y),(this->_z + point->_z));
}


HX_DEFINE_DYNAMIC_FUNC1(Point3d_obj,add,return )

::org::casalib::math::geom::Point3d Point3d_obj::subtract( ::org::casalib::math::geom::Point3d point){
	return ::org::casalib::math::geom::Point3d_obj::__new((this->_x - point->_x),(this->_y - point->_y),(this->_z - point->_z));
}


HX_DEFINE_DYNAMIC_FUNC1(Point3d_obj,subtract,return )

Void Point3d_obj::offset( double xOffset,double yOffset,double zOffset){
{
		{
			::org::casalib::math::geom::Point3d _g = this;
			{
				double position = (_g->_x + xOffset);
				_g->_x = position;
				position;
			}
		}
		{
			::org::casalib::math::geom::Point3d _g = this;
			{
				double position = (_g->_y + yOffset);
				_g->_y = position;
				position;
			}
		}
		{
			::org::casalib::math::geom::Point3d _g = this;
			{
				double position = (_g->_z + zOffset);
				_g->_z = position;
				position;
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC3(Point3d_obj,offset,(void))

bool Point3d_obj::equals( ::org::casalib::math::geom::Point3d point){
	return (bool((this->_x == point->_x)) && bool((bool((this->_y == point->_y)) && bool((this->_z == point->_z)))));
}


HX_DEFINE_DYNAMIC_FUNC1(Point3d_obj,equals,return )

::org::casalib::math::geom::Point3d Point3d_obj::clone( ){
	return ::org::casalib::math::geom::Point3d_obj::__new(this->_x,this->_y,this->_z);
}


HX_DEFINE_DYNAMIC_FUNC0(Point3d_obj,clone,return )

double Point3d_obj::distance( ::org::casalib::math::geom::Point3d firstPoint,::org::casalib::math::geom::Point3d secondPoint){
	__SAFE_POINT
	double x = (secondPoint->_x - firstPoint->_x);
	double y = (secondPoint->_y - firstPoint->_y);
	double z = (secondPoint->_z - firstPoint->_z);
	return ::Math_obj::sqrt(((((x * x) + (y * y))) + (z * z)));
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(Point3d_obj,distance,return )

::org::casalib::math::geom::Point3d Point3d_obj::interpolate( ::org::casalib::math::geom::Point3d firstPoint,::org::casalib::math::geom::Point3d secondPoint,::org::casalib::math::Percent amount){
	struct _Function_1_1{
		inline static double Block( ::org::casalib::math::geom::Point3d &secondPoint,::org::casalib::math::geom::Point3d &firstPoint,::org::casalib::math::Percent &amount)/* DEF (ret block)(not intern) */{
			double begin = firstPoint->_x;
			return (begin + (((secondPoint->_x - begin)) * amount->_percent));
		}
	};
	double x = _Function_1_1::Block(secondPoint,firstPoint,amount);
	struct _Function_1_2{
		inline static double Block( ::org::casalib::math::geom::Point3d &secondPoint,::org::casalib::math::geom::Point3d &firstPoint,::org::casalib::math::Percent &amount)/* DEF (ret block)(not intern) */{
			double begin = firstPoint->_y;
			return (begin + (((secondPoint->_y - begin)) * amount->_percent));
		}
	};
	double y = _Function_1_2::Block(secondPoint,firstPoint,amount);
	struct _Function_1_3{
		inline static double Block( ::org::casalib::math::geom::Point3d &secondPoint,::org::casalib::math::geom::Point3d &firstPoint,::org::casalib::math::Percent &amount)/* DEF (ret block)(not intern) */{
			double begin = firstPoint->_z;
			return (begin + (((secondPoint->_z - begin)) * amount->_percent));
		}
	};
	double z = _Function_1_3::Block(secondPoint,firstPoint,amount);
	return ::org::casalib::math::geom::Point3d_obj::__new(x,y,z);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC3(Point3d_obj,interpolate,return )


Point3d_obj::Point3d_obj()
{
}

void Point3d_obj::__Mark()
{
	hx::MarkMember(x);
	hx::MarkMember(y);
	hx::MarkMember(z);
	hx::MarkMember(_x);
	hx::MarkMember(_y);
	hx::MarkMember(_z);
}

Dynamic Point3d_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 1:
		if (!memcmp(inName.__s,L"x",sizeof(wchar_t)*1) ) { return getX(); }
		if (!memcmp(inName.__s,L"y",sizeof(wchar_t)*1) ) { return getY(); }
		if (!memcmp(inName.__s,L"z",sizeof(wchar_t)*1) ) { return getZ(); }
		break;
	case 2:
		if (!memcmp(inName.__s,L"_x",sizeof(wchar_t)*2) ) { return _x; }
		if (!memcmp(inName.__s,L"_y",sizeof(wchar_t)*2) ) { return _y; }
		if (!memcmp(inName.__s,L"_z",sizeof(wchar_t)*2) ) { return _z; }
		break;
	case 3:
		if (!memcmp(inName.__s,L"add",sizeof(wchar_t)*3) ) { return add_dyn(); }
		break;
	case 4:
		if (!memcmp(inName.__s,L"getX",sizeof(wchar_t)*4) ) { return getX_dyn(); }
		if (!memcmp(inName.__s,L"setX",sizeof(wchar_t)*4) ) { return setX_dyn(); }
		if (!memcmp(inName.__s,L"getY",sizeof(wchar_t)*4) ) { return getY_dyn(); }
		if (!memcmp(inName.__s,L"setY",sizeof(wchar_t)*4) ) { return setY_dyn(); }
		if (!memcmp(inName.__s,L"getZ",sizeof(wchar_t)*4) ) { return getZ_dyn(); }
		if (!memcmp(inName.__s,L"setZ",sizeof(wchar_t)*4) ) { return setZ_dyn(); }
		break;
	case 5:
		if (!memcmp(inName.__s,L"clone",sizeof(wchar_t)*5) ) { return clone_dyn(); }
		break;
	case 6:
		if (!memcmp(inName.__s,L"offset",sizeof(wchar_t)*6) ) { return offset_dyn(); }
		if (!memcmp(inName.__s,L"equals",sizeof(wchar_t)*6) ) { return equals_dyn(); }
		break;
	case 8:
		if (!memcmp(inName.__s,L"distance",sizeof(wchar_t)*8) ) { return distance_dyn(); }
		if (!memcmp(inName.__s,L"subtract",sizeof(wchar_t)*8) ) { return subtract_dyn(); }
		break;
	case 11:
		if (!memcmp(inName.__s,L"interpolate",sizeof(wchar_t)*11) ) { return interpolate_dyn(); }
	}
	return super::__Field(inName);
}

Dynamic Point3d_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	switch(inName.length) {
	case 1:
		if (!memcmp(inName.__s,L"x",sizeof(wchar_t)*1) ) { return setX(inValue); }
		if (!memcmp(inName.__s,L"y",sizeof(wchar_t)*1) ) { return setY(inValue); }
		if (!memcmp(inName.__s,L"z",sizeof(wchar_t)*1) ) { return setZ(inValue); }
		break;
	case 2:
		if (!memcmp(inName.__s,L"_x",sizeof(wchar_t)*2) ) { _x=inValue.Cast< double >(); return inValue; }
		if (!memcmp(inName.__s,L"_y",sizeof(wchar_t)*2) ) { _y=inValue.Cast< double >(); return inValue; }
		if (!memcmp(inName.__s,L"_z",sizeof(wchar_t)*2) ) { _z=inValue.Cast< double >(); return inValue; }
	}
	return super::__SetField(inName,inValue);
}

void Point3d_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_STRING(L"x",1));
	outFields->push(HX_STRING(L"y",1));
	outFields->push(HX_STRING(L"z",1));
	outFields->push(HX_STRING(L"_x",2));
	outFields->push(HX_STRING(L"_y",2));
	outFields->push(HX_STRING(L"_z",2));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_STRING(L"distance",8),
	HX_STRING(L"interpolate",11),
	String(null()) };

static ::String sMemberFields[] = {
	HX_STRING(L"x",1),
	HX_STRING(L"y",1),
	HX_STRING(L"z",1),
	HX_STRING(L"_x",2),
	HX_STRING(L"_y",2),
	HX_STRING(L"_z",2),
	HX_STRING(L"getX",4),
	HX_STRING(L"setX",4),
	HX_STRING(L"getY",4),
	HX_STRING(L"setY",4),
	HX_STRING(L"getZ",4),
	HX_STRING(L"setZ",4),
	HX_STRING(L"add",3),
	HX_STRING(L"subtract",8),
	HX_STRING(L"offset",6),
	HX_STRING(L"equals",6),
	HX_STRING(L"clone",5),
	String(null()) };

static void sMarkStatics() {
};

Class Point3d_obj::__mClass;

void Point3d_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_STRING(L"org.casalib.math.geom.Point3d",29), hx::TCanCast< Point3d_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void Point3d_obj::__boot()
{
}

} // end namespace org
} // end namespace casalib
} // end namespace math
} // end namespace geom
