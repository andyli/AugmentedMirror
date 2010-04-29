#include <hxcpp.h>

#ifndef INCLUDED_Hash
#include <Hash.h>
#endif
#ifndef INCLUDED_sandy_core_data_Edge3D
#include <sandy/core/data/Edge3D.h>
#endif
#ifndef INCLUDED_sandy_core_data_Point3D
#include <sandy/core/data/Point3D.h>
#endif
#ifndef INCLUDED_sandy_core_data_UVCoord
#include <sandy/core/data/UVCoord.h>
#endif
#ifndef INCLUDED_sandy_core_data_Vertex
#include <sandy/core/data/Vertex.h>
#endif
#ifndef INCLUDED_sandy_core_scenegraph_Geometry3D
#include <sandy/core/scenegraph/Geometry3D.h>
#endif
namespace sandy{
namespace core{
namespace scenegraph{

Void Geometry3D_obj::__construct(Array< Dynamic > p_points)
{
{
	this->EDGES_DICO = ::Hash_obj::__new();
	this->aVertex = Array_obj< ::sandy::core::data::Vertex >::__new();
	this->aFacesVertexID = Array_obj< Array< int > >::__new();
	this->aFacesUVCoordsID = Array_obj< Array< int > >::__new();
	this->aFacesNormals = Array_obj< ::sandy::core::data::Vertex >::__new();
	this->aVertexNormals = Array_obj< ::sandy::core::data::Vertex >::__new();
	this->aEdges = Array_obj< ::sandy::core::data::Edge3D >::__new();
	this->aFaceEdges = Array_obj< Array< int > >::__new();
	this->aUVCoords = Array_obj< ::sandy::core::data::UVCoord >::__new();
	this->m_nLastVertexId = 0;
	this->m_nLastNormalId = 0;
	this->m_nLastFaceId = 0;
	this->m_nLastFaceUVId = 0;
	this->m_nLastUVId = 0;
	this->m_nLastVertexNormalId = 0;
	this->m_aVertexFaces = Array_obj< Array< Dynamic > >::__new();
	this->init();
}
;
	return null();
}

Geometry3D_obj::~Geometry3D_obj() { }

Dynamic Geometry3D_obj::__CreateEmpty() { return  new Geometry3D_obj; }
hx::ObjectPtr< Geometry3D_obj > Geometry3D_obj::__new(Array< Dynamic > p_points)
{  hx::ObjectPtr< Geometry3D_obj > result = new Geometry3D_obj();
	result->__construct(p_points);
	return result;}

Dynamic Geometry3D_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Geometry3D_obj > result = new Geometry3D_obj();
	result->__construct(inArgs[0]);
	return result;}

Void Geometry3D_obj::init( ){
{
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Geometry3D_obj,init,(void))

Void Geometry3D_obj::addFace( ::sandy::core::data::Point3D v0,::sandy::core::data::Point3D v1,::sandy::core::data::Point3D v2,::sandy::core::data::UVCoord uv0,::sandy::core::data::UVCoord uv1,::sandy::core::data::UVCoord uv2){
{
		__SAFE_POINT
		int vid = this->getNextVertexID();
		this->setVertex(vid++,v0->x,v0->y,v0->z);
		this->setVertex(vid++,v1->x,v1->y,v1->z);
		this->setVertex(vid,v2->x,v2->y,v2->z);
		int ucid = this->getNextUVCoordID();
		this->setUVCoords(ucid++,uv0->u,uv0->v);
		this->setUVCoords(ucid++,uv1->u,uv1->v);
		this->setUVCoords(ucid,uv2->u,uv2->v);
		this->setFaceVertexIds(this->getNextFaceID(),Array_obj< int >::__new().Add((vid - 2)).Add((vid - 1)).Add(vid));
		this->setFaceUVCoordsIds(this->getNextFaceUVCoordID(),Array_obj< int >::__new().Add((ucid - 2)).Add((ucid - 1)).Add(ucid));
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC6(Geometry3D_obj,addFace,(void))

int Geometry3D_obj::setVertex( int p_nVertexID,double p_nX,double p_nY,double p_nZ){
	if ((this->aVertex->__get(p_nVertexID) != null())){
		return -1;
	}
	else{
		this->aVertex[p_nVertexID] = ::sandy::core::data::Vertex_obj::__new(p_nX,p_nY,p_nZ,null(),null(),null());
		return (++this->m_nLastVertexId - 1);
	}
}


HX_DEFINE_DYNAMIC_FUNC4(Geometry3D_obj,setVertex,return )

int Geometry3D_obj::getNextVertexID( ){
	return this->m_nLastVertexId;
}


HX_DEFINE_DYNAMIC_FUNC0(Geometry3D_obj,getNextVertexID,return )

int Geometry3D_obj::setFaceNormal( int p_nNormalID,double p_nX,double p_nY,double p_nZ){
	if ((this->aFacesNormals->__get(p_nNormalID) != null())){
		return -1;
	}
	else{
		this->aFacesNormals[p_nNormalID] = ::sandy::core::data::Vertex_obj::__new(p_nX,p_nY,p_nZ,null(),null(),null());
		return (++this->m_nLastNormalId - 1);
	}
}


HX_DEFINE_DYNAMIC_FUNC4(Geometry3D_obj,setFaceNormal,return )

int Geometry3D_obj::getNextFaceNormalID( ){
	return this->m_nLastNormalId;
}


HX_DEFINE_DYNAMIC_FUNC0(Geometry3D_obj,getNextFaceNormalID,return )

double Geometry3D_obj::setVertexNormal( int p_nNormalID,double p_nX,double p_nY,double p_nZ){
	if ((this->aVertexNormals->__get(p_nNormalID) != null())){
		return -1;
	}
	else{
		this->aVertexNormals[p_nNormalID] = ::sandy::core::data::Vertex_obj::__new(p_nX,p_nY,p_nZ,null(),null(),null());
		return (++this->m_nLastVertexNormalId - 1);
	}
}


HX_DEFINE_DYNAMIC_FUNC4(Geometry3D_obj,setVertexNormal,return )

int Geometry3D_obj::getNextVertexNormalID( ){
	return this->m_nLastVertexNormalId;
}


HX_DEFINE_DYNAMIC_FUNC0(Geometry3D_obj,getNextVertexNormalID,return )

int Geometry3D_obj::setFaceVertexIds( int p_nFaceID,Array< int > arguments){
	__SAFE_POINT
	if ((arguments == null()))
		arguments = Array_obj< int >::__new();
	if ((this->aFacesVertexID->__get(p_nFaceID) != null())){
		return -1;
	}
	else{
		Array< int > rest = arguments;
		this->aFacesVertexID[p_nFaceID] = rest;
		{
			int _g1 = 0;
			int _g = rest->length;
			while((_g1 < _g)){
				__SAFE_POINT
				int lId = _g1++;
				int lId1 = rest->__get(lId);
				int lId2 = rest->__get(hx::Mod(((lId + 1)),rest->length));
				int lEdgeID;
				::String lString;
				if ((this->isEdgeExist(lId1,lId2) == false)){
					lEdgeID = (this->aEdges->push(::sandy::core::data::Edge3D_obj::__new(lId1,lId2)) - 1);
					if ((lId1 < lId2)){
						lString = (((lId1 + HX_STRING(L"_",1))) + lId2);
					}
					else{
						lString = (((lId2 + HX_STRING(L"_",1))) + lId1);
					}
					this->EDGES_DICO->set(lString,lEdgeID);
				}
				else{
					if ((lId1 < lId2)){
						lString = (((lId1 + HX_STRING(L"_",1))) + lId2);
					}
					else{
						lString = (((lId2 + HX_STRING(L"_",1))) + lId1);
					}
					lEdgeID = this->EDGES_DICO->get(lString);
				}
				if ((null() == this->aFaceEdges->__get(p_nFaceID)))
					this->aFaceEdges[p_nFaceID] = Array_obj< int >::__new();
				this->aFaceEdges[p_nFaceID]->push(lEdgeID);
			}
		}
		return (++this->m_nLastFaceId - 1);
	}
}


HX_DEFINE_DYNAMIC_FUNC2(Geometry3D_obj,setFaceVertexIds,return )

bool Geometry3D_obj::isEdgeExist( int p_nVertexId1,int p_nVertexId2){
	__SAFE_POINT
	::String lString;
	if ((p_nVertexId1 < p_nVertexId2)){
		lString = (((p_nVertexId1 + HX_STRING(L"_",1))) + p_nVertexId2);
	}
	else{
		lString = (((p_nVertexId2 + HX_STRING(L"_",1))) + p_nVertexId1);
	}
	if ((this->EDGES_DICO->get(lString) == null())){
		return false;
	}
	else{
		return true;
	}
}


HX_DEFINE_DYNAMIC_FUNC2(Geometry3D_obj,isEdgeExist,return )

int Geometry3D_obj::getNextFaceID( ){
	return this->m_nLastFaceId;
}


HX_DEFINE_DYNAMIC_FUNC0(Geometry3D_obj,getNextFaceID,return )

int Geometry3D_obj::setFaceUVCoordsIds( int p_nFaceID,Array< int > arguments){
	if ((arguments == null()))
		arguments = Array_obj< int >::__new();
	if ((this->aFacesUVCoordsID->__get(p_nFaceID) != null())){
		return -1;
	}
	else{
		this->aFacesUVCoordsID[p_nFaceID] = arguments;
		return (++this->m_nLastFaceUVId - 1);
	}
}


HX_DEFINE_DYNAMIC_FUNC2(Geometry3D_obj,setFaceUVCoordsIds,return )

int Geometry3D_obj::getNextFaceUVCoordID( ){
	return this->m_nLastFaceUVId;
}


HX_DEFINE_DYNAMIC_FUNC0(Geometry3D_obj,getNextFaceUVCoordID,return )

int Geometry3D_obj::getVertexId( ::sandy::core::data::Vertex p_point){
	struct _Function_1_1{
		inline static int Block( ::sandy::core::scenegraph::Geometry3D_obj *__this,::sandy::core::data::Vertex &p_point)/* DEF (ret block)(not intern) */{
			Dynamic array = __this->aVertex;
			int idx = -1;
			{
				int _g1 = 0;
				int _g2 = array->__Field(HX_STRING(L"length",6)).Cast< int >();
				while((_g1 < _g2)){
					__SAFE_POINT
					int i = _g1++;
					if ((array[i] == p_point)){
						idx = i;
						break;
					}
				}
			}
			return idx;
		}
	};
	return _Function_1_1::Block(this,p_point);
}


HX_DEFINE_DYNAMIC_FUNC1(Geometry3D_obj,getVertexId,return )

int Geometry3D_obj::setUVCoords( int p_nID,double p_UValue,double p_nVValue){
	if ((this->aUVCoords->__get(p_nID) != null())){
		return -1;
	}
	else{
		this->aUVCoords[p_nID] = ::sandy::core::data::UVCoord_obj::__new(p_UValue,p_nVValue);
		return (++this->m_nLastUVId - 1);
	}
}


HX_DEFINE_DYNAMIC_FUNC3(Geometry3D_obj,setUVCoords,return )

int Geometry3D_obj::getNextUVCoordID( ){
	return this->m_nLastUVId;
}


HX_DEFINE_DYNAMIC_FUNC0(Geometry3D_obj,getNextUVCoordID,return )

Void Geometry3D_obj::generateFaceNormals( ){
{
		__SAFE_POINT
		if ((this->aFacesNormals->length > 0)){
			return null();
		}
		else{
			{
				int _g = 0;
				Array< Array< int > > _g1 = this->aFacesVertexID;
				while((_g < _g1->length)){
					__SAFE_POINT
					Array< int > a = _g1->__get(_g);
					++_g;
					if ((a->length < 3))
						continue;
					::sandy::core::data::Vertex lA;
					::sandy::core::data::Vertex lB;
					::sandy::core::data::Vertex lC;
					lA = this->aVertex->__get(a->__get(0));
					lB = this->aVertex->__get(a->__get(1));
					lC = this->aVertex->__get(a->__get(2));
					::sandy::core::data::Point3D lV = ::sandy::core::data::Point3D_obj::__new((lB->wx - lA->wx),(lB->wy - lA->wy),(lB->wz - lA->wz));
					::sandy::core::data::Point3D lW = ::sandy::core::data::Point3D_obj::__new((lB->wx - lC->wx),(lB->wy - lC->wy),(lB->wz - lC->wz));
					::sandy::core::data::Point3D lNormal = lV->cross(lW);
					lNormal->normalize();
					this->setFaceNormal(this->getNextFaceNormalID(),lNormal->x,lNormal->y,lNormal->z);
				}
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Geometry3D_obj,generateFaceNormals,(void))

Void Geometry3D_obj::generateVertexNormals( ){
{
		__SAFE_POINT
		if ((this->aVertexNormals->length > 0)){
			return null();
		}
		else{
			int lId = 0;
			{
				int _g1 = 0;
				int _g = this->aFacesVertexID->length;
				while((_g1 < _g)){
					__SAFE_POINT
					int lId1 = _g1++;
					Array< int > l_aList = this->aFacesVertexID->__get(lId1);
					::sandy::core::data::Vertex l_oNormal = this->aFacesNormals->__get(lId1);
					if ((l_oNormal == null()))
						continue;
					if ((null() == this->aVertexNormals->__get(l_aList->__get(0)))){
						this->m_nLastVertexNormalId++;
						this->aVertexNormals[l_aList->__get(0)] = ::sandy::core::data::Vertex_obj::__new(null(),null(),null(),null(),null(),null());
					}
					this->aVertexNormals[l_aList->__get(0)]->add(l_oNormal);
					if ((null() == this->aVertexNormals->__get(l_aList->__get(1)))){
						this->m_nLastVertexNormalId++;
						this->aVertexNormals[l_aList->__get(1)] = ::sandy::core::data::Vertex_obj::__new(null(),null(),null(),null(),null(),null());
					}
					this->aVertexNormals[l_aList->__get(1)]->add(l_oNormal);
					if ((null() == this->aVertexNormals->__get(l_aList->__get(2)))){
						this->m_nLastVertexNormalId++;
						this->aVertexNormals[l_aList->__get(2)] = ::sandy::core::data::Vertex_obj::__new(null(),null(),null(),null(),null(),null());
					}
					this->aVertexNormals[l_aList->__get(2)]->add(l_oNormal);
					if ((this->aVertex[l_aList->__get(0)]->aFaces->__get(0) == lId1))
						this->aVertex[l_aList->__get(0)]->aFaces->push(lId1);
					if ((this->aVertex[l_aList->__get(1)]->aFaces->__get(0) == lId1))
						this->aVertex[l_aList->__get(1)]->aFaces->push(lId1);
					if ((this->aVertex[l_aList->__get(2)]->aFaces->__get(0) == lId1))
						this->aVertex[l_aList->__get(2)]->aFaces->push(lId1);
					this->aVertex[l_aList->__get(0)]->nbFaces++;
					this->aVertex[l_aList->__get(1)]->nbFaces++;
					this->aVertex[l_aList->__get(2)]->nbFaces++;
				}
			}
			{
				int _g1 = 0;
				int _g = this->aVertexNormals->length;
				while((_g1 < _g)){
					__SAFE_POINT
					int lId1 = _g1++;
					::sandy::core::data::Vertex l_oVertex = this->aVertex->__get(lId1);
					if ((l_oVertex->nbFaces == 0))
						continue;
					if ((l_oVertex->nbFaces > 0))
						this->aVertexNormals[lId1]->scale((double(1) / double(l_oVertex->nbFaces)));
				}
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Geometry3D_obj,generateVertexNormals,(void))

::sandy::core::scenegraph::Geometry3D Geometry3D_obj::clone( ){
	__SAFE_POINT
	::sandy::core::scenegraph::Geometry3D l_result = ::sandy::core::scenegraph::Geometry3D_obj::__new(null());
	int i = 0;
	::sandy::core::data::Vertex l_oVertex;
	{
		int _g = 0;
		Array< ::sandy::core::data::Vertex > _g1 = this->aVertex;
		while((_g < _g1->length)){
			__SAFE_POINT
			::sandy::core::data::Vertex l_oVertex1 = _g1->__get(_g);
			++_g;
			l_result->aVertex[i] = l_oVertex1->clone();
			i++;
		}
	}
	i = 0;
	{
		int _g = 0;
		Array< Array< int > > _g1 = this->aFacesVertexID;
		while((_g < _g1->length)){
			__SAFE_POINT
			Array< int > a = _g1->__get(_g);
			++_g;
			l_result->aFacesVertexID[i] = a->copy();
			i++;
		}
	}
	i = 0;
	{
		int _g = 0;
		Array< ::sandy::core::data::Vertex > _g1 = this->aFacesNormals;
		while((_g < _g1->length)){
			__SAFE_POINT
			::sandy::core::data::Vertex l_oVertex1 = _g1->__get(_g);
			++_g;
			l_result->aFacesNormals[i] = l_oVertex1->clone();
			i++;
		}
	}
	i = 0;
	{
		int _g = 0;
		Array< ::sandy::core::data::Vertex > _g1 = this->aVertexNormals;
		while((_g < _g1->length)){
			__SAFE_POINT
			::sandy::core::data::Vertex l_oVertex1 = _g1->__get(_g);
			++_g;
			if ((l_oVertex1 != null())){
				l_result->aVertexNormals[i] = l_oVertex1->clone();
			}
			else{
				l_result->aVertexNormals[i] = null();
			}
			i++;
		}
	}
	i = 0;
	{
		int _g = 0;
		Array< Array< int > > _g1 = this->aFacesUVCoordsID;
		while((_g < _g1->length)){
			__SAFE_POINT
			Array< int > b = _g1->__get(_g);
			++_g;
			l_result->aFacesUVCoordsID[i] = b->copy();
			i++;
		}
	}
	i = 0;
	{
		int _g = 0;
		Array< ::sandy::core::data::UVCoord > _g1 = this->aUVCoords;
		while((_g < _g1->length)){
			__SAFE_POINT
			::sandy::core::data::UVCoord u = _g1->__get(_g);
			++_g;
			l_result->aUVCoords[i] = u->clone();
			i++;
		}
	}
	i = 0;
	{
		int _g = 0;
		Array< ::sandy::core::data::Edge3D > _g1 = this->aEdges;
		while((_g < _g1->length)){
			__SAFE_POINT
			::sandy::core::data::Edge3D l_oEdge = _g1->__get(_g);
			++_g;
			l_result->aEdges[i] = l_oEdge->clone();
			i++;
		}
	}
	i = 0;
	{
		int _g = 0;
		Array< Array< int > > _g1 = this->aFaceEdges;
		while((_g < _g1->length)){
			__SAFE_POINT
			Array< int > l_oEdges = _g1->__get(_g);
			++_g;
			l_result->aFaceEdges[i] = l_oEdges->copy();
			i++;
		}
	}
	return l_result;
}


HX_DEFINE_DYNAMIC_FUNC0(Geometry3D_obj,clone,return )

Void Geometry3D_obj::dispose( ){
{
		__SAFE_POINT
		Array< int > a;
		::sandy::core::data::Vertex l_oVertex;
		int l;
		::sandy::core::data::UVCoord u;
		l = this->aVertex->length;
		{
			int _g = 0;
			while((_g < l)){
				__SAFE_POINT
				int i = _g++;
				l_oVertex = this->aVertex->__get(i);
				l_oVertex->aFaces = null();
				l_oVertex = null();
			}
		}
		this->aVertex = null();
		l = this->aFacesVertexID->length;
		{
			int _g = 0;
			while((_g < l)){
				__SAFE_POINT
				int i = _g++;
				this->aFacesVertexID[i] = null();
			}
		}
		this->aFacesVertexID = null();
		l = this->aFacesNormals->length;
		{
			int _g = 0;
			while((_g < l)){
				__SAFE_POINT
				int i = _g++;
				l_oVertex = this->aFacesNormals->__get(i);
				l_oVertex->aFaces = null();
				l_oVertex = null();
			}
		}
		this->aFacesNormals = null();
		l = this->aVertexNormals->length;
		{
			int _g = 0;
			while((_g < l)){
				__SAFE_POINT
				int i = _g++;
				l_oVertex = this->aVertexNormals->__get(i);
				if ((l_oVertex != null())){
					l_oVertex->aFaces = null();
					l_oVertex = null();
				}
			}
		}
		this->aVertexNormals = null();
		l = this->aFacesUVCoordsID->length;
		{
			int _g = 0;
			while((_g < l)){
				__SAFE_POINT
				int i = _g++;
				this->aFacesUVCoordsID[i] = null();
			}
		}
		this->aFacesUVCoordsID = null();
		l = this->aUVCoords->length;
		{
			int _g = 0;
			while((_g < l)){
				__SAFE_POINT
				int i = _g++;
				this->aUVCoords[i] = null();
			}
		}
		this->aUVCoords = null();
		for(Dynamic __it = this->EDGES_DICO->keys();  __it->__Field(HX_STRING(L"hasNext",7))(); ){
::String l_sEdgeName = __it->__Field(HX_STRING(L"next",4))();
			{
				this->EDGES_DICO->remove(l_sEdgeName);
			}
;
			__SAFE_POINT
		}
		this->EDGES_DICO = null();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Geometry3D_obj,dispose,(void))

Void Geometry3D_obj::updateFaceNormals( ){
{
		__SAFE_POINT
		int idx = 0;
		{
			int _g = 0;
			Array< Array< int > > _g1 = this->aFacesVertexID;
			while((_g < _g1->length)){
				__SAFE_POINT
				Array< int > a = _g1->__get(_g);
				++_g;
				if ((a->length < 3))
					continue;
				::sandy::core::data::Vertex lA;
				::sandy::core::data::Vertex lB;
				::sandy::core::data::Vertex lC;
				lA = this->aVertex->__get(a->__get(0));
				lB = this->aVertex->__get(a->__get(1));
				lC = this->aVertex->__get(a->__get(2));
				::sandy::core::data::Point3D lV = ::sandy::core::data::Point3D_obj::__new((lB->wx - lA->wx),(lB->wy - lA->wy),(lB->wz - lA->wz));
				::sandy::core::data::Point3D lW = ::sandy::core::data::Point3D_obj::__new((lB->wx - lC->wx),(lB->wy - lC->wy),(lB->wz - lC->wz));
				::sandy::core::data::Point3D lNormal = lV->cross(lW);
				lNormal->normalize();
				this->setFaceNormal(idx,lNormal->x,lNormal->y,lNormal->z);
				idx++;
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Geometry3D_obj,updateFaceNormals,(void))

::String Geometry3D_obj::toString( ){
	return (((((((((((((((HX_STRING(L"[Geometry: ",11) + this->aFacesVertexID->length)) + HX_STRING(L" faces, ",8))) + this->aVertex->length)) + HX_STRING(L" points, ",9))) + this->aFacesNormals->length)) + HX_STRING(L" normals, ",10))) + this->aUVCoords->length)) + HX_STRING(L" uv coords]",11));
}


HX_DEFINE_DYNAMIC_FUNC0(Geometry3D_obj,toString,return )


Geometry3D_obj::Geometry3D_obj()
{
}

void Geometry3D_obj::__Mark()
{
	hx::MarkMember(EDGES_DICO);
	hx::MarkMember(aVertex);
	hx::MarkMember(aFacesVertexID);
	hx::MarkMember(aFacesUVCoordsID);
	hx::MarkMember(aFacesNormals);
	hx::MarkMember(aVertexNormals);
	hx::MarkMember(aEdges);
	hx::MarkMember(aFaceEdges);
	hx::MarkMember(aUVCoords);
	hx::MarkMember(m_nLastVertexId);
	hx::MarkMember(m_nLastNormalId);
	hx::MarkMember(m_nLastFaceId);
	hx::MarkMember(m_nLastFaceUVId);
	hx::MarkMember(m_nLastUVId);
	hx::MarkMember(m_nLastVertexNormalId);
	hx::MarkMember(m_aVertexFaces);
}

Dynamic Geometry3D_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 4:
		if (!memcmp(inName.__s,L"init",sizeof(wchar_t)*4) ) { return init_dyn(); }
		break;
	case 5:
		if (!memcmp(inName.__s,L"clone",sizeof(wchar_t)*5) ) { return clone_dyn(); }
		break;
	case 6:
		if (!memcmp(inName.__s,L"aEdges",sizeof(wchar_t)*6) ) { return aEdges; }
		break;
	case 7:
		if (!memcmp(inName.__s,L"aVertex",sizeof(wchar_t)*7) ) { return aVertex; }
		if (!memcmp(inName.__s,L"addFace",sizeof(wchar_t)*7) ) { return addFace_dyn(); }
		if (!memcmp(inName.__s,L"dispose",sizeof(wchar_t)*7) ) { return dispose_dyn(); }
		break;
	case 8:
		if (!memcmp(inName.__s,L"toString",sizeof(wchar_t)*8) ) { return toString_dyn(); }
		break;
	case 9:
		if (!memcmp(inName.__s,L"aUVCoords",sizeof(wchar_t)*9) ) { return aUVCoords; }
		if (!memcmp(inName.__s,L"setVertex",sizeof(wchar_t)*9) ) { return setVertex_dyn(); }
		break;
	case 10:
		if (!memcmp(inName.__s,L"EDGES_DICO",sizeof(wchar_t)*10) ) { return EDGES_DICO; }
		if (!memcmp(inName.__s,L"aFaceEdges",sizeof(wchar_t)*10) ) { return aFaceEdges; }
		break;
	case 11:
		if (!memcmp(inName.__s,L"m_nLastUVId",sizeof(wchar_t)*11) ) { return m_nLastUVId; }
		if (!memcmp(inName.__s,L"isEdgeExist",sizeof(wchar_t)*11) ) { return isEdgeExist_dyn(); }
		if (!memcmp(inName.__s,L"getVertexId",sizeof(wchar_t)*11) ) { return getVertexId_dyn(); }
		if (!memcmp(inName.__s,L"setUVCoords",sizeof(wchar_t)*11) ) { return setUVCoords_dyn(); }
		break;
	case 13:
		if (!memcmp(inName.__s,L"aFacesNormals",sizeof(wchar_t)*13) ) { return aFacesNormals; }
		if (!memcmp(inName.__s,L"m_nLastFaceId",sizeof(wchar_t)*13) ) { return m_nLastFaceId; }
		if (!memcmp(inName.__s,L"setFaceNormal",sizeof(wchar_t)*13) ) { return setFaceNormal_dyn(); }
		if (!memcmp(inName.__s,L"getNextFaceID",sizeof(wchar_t)*13) ) { return getNextFaceID_dyn(); }
		break;
	case 14:
		if (!memcmp(inName.__s,L"aFacesVertexID",sizeof(wchar_t)*14) ) { return aFacesVertexID; }
		if (!memcmp(inName.__s,L"aVertexNormals",sizeof(wchar_t)*14) ) { return aVertexNormals; }
		if (!memcmp(inName.__s,L"m_aVertexFaces",sizeof(wchar_t)*14) ) { return m_aVertexFaces; }
		break;
	case 15:
		if (!memcmp(inName.__s,L"m_nLastVertexId",sizeof(wchar_t)*15) ) { return m_nLastVertexId; }
		if (!memcmp(inName.__s,L"m_nLastNormalId",sizeof(wchar_t)*15) ) { return m_nLastNormalId; }
		if (!memcmp(inName.__s,L"m_nLastFaceUVId",sizeof(wchar_t)*15) ) { return m_nLastFaceUVId; }
		if (!memcmp(inName.__s,L"getNextVertexID",sizeof(wchar_t)*15) ) { return getNextVertexID_dyn(); }
		if (!memcmp(inName.__s,L"setVertexNormal",sizeof(wchar_t)*15) ) { return setVertexNormal_dyn(); }
		break;
	case 16:
		if (!memcmp(inName.__s,L"aFacesUVCoordsID",sizeof(wchar_t)*16) ) { return aFacesUVCoordsID; }
		if (!memcmp(inName.__s,L"setFaceVertexIds",sizeof(wchar_t)*16) ) { return setFaceVertexIds_dyn(); }
		if (!memcmp(inName.__s,L"getNextUVCoordID",sizeof(wchar_t)*16) ) { return getNextUVCoordID_dyn(); }
		break;
	case 17:
		if (!memcmp(inName.__s,L"updateFaceNormals",sizeof(wchar_t)*17) ) { return updateFaceNormals_dyn(); }
		break;
	case 18:
		if (!memcmp(inName.__s,L"setFaceUVCoordsIds",sizeof(wchar_t)*18) ) { return setFaceUVCoordsIds_dyn(); }
		break;
	case 19:
		if (!memcmp(inName.__s,L"getNextFaceNormalID",sizeof(wchar_t)*19) ) { return getNextFaceNormalID_dyn(); }
		if (!memcmp(inName.__s,L"generateFaceNormals",sizeof(wchar_t)*19) ) { return generateFaceNormals_dyn(); }
		break;
	case 20:
		if (!memcmp(inName.__s,L"getNextFaceUVCoordID",sizeof(wchar_t)*20) ) { return getNextFaceUVCoordID_dyn(); }
		break;
	case 21:
		if (!memcmp(inName.__s,L"m_nLastVertexNormalId",sizeof(wchar_t)*21) ) { return m_nLastVertexNormalId; }
		if (!memcmp(inName.__s,L"getNextVertexNormalID",sizeof(wchar_t)*21) ) { return getNextVertexNormalID_dyn(); }
		if (!memcmp(inName.__s,L"generateVertexNormals",sizeof(wchar_t)*21) ) { return generateVertexNormals_dyn(); }
	}
	return super::__Field(inName);
}

Dynamic Geometry3D_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	switch(inName.length) {
	case 6:
		if (!memcmp(inName.__s,L"aEdges",sizeof(wchar_t)*6) ) { aEdges=inValue.Cast< Array< ::sandy::core::data::Edge3D > >(); return inValue; }
		break;
	case 7:
		if (!memcmp(inName.__s,L"aVertex",sizeof(wchar_t)*7) ) { aVertex=inValue.Cast< Array< ::sandy::core::data::Vertex > >(); return inValue; }
		break;
	case 9:
		if (!memcmp(inName.__s,L"aUVCoords",sizeof(wchar_t)*9) ) { aUVCoords=inValue.Cast< Array< ::sandy::core::data::UVCoord > >(); return inValue; }
		break;
	case 10:
		if (!memcmp(inName.__s,L"EDGES_DICO",sizeof(wchar_t)*10) ) { EDGES_DICO=inValue.Cast< ::Hash >(); return inValue; }
		if (!memcmp(inName.__s,L"aFaceEdges",sizeof(wchar_t)*10) ) { aFaceEdges=inValue.Cast< Array< Array< int > > >(); return inValue; }
		break;
	case 11:
		if (!memcmp(inName.__s,L"m_nLastUVId",sizeof(wchar_t)*11) ) { m_nLastUVId=inValue.Cast< int >(); return inValue; }
		break;
	case 13:
		if (!memcmp(inName.__s,L"aFacesNormals",sizeof(wchar_t)*13) ) { aFacesNormals=inValue.Cast< Array< ::sandy::core::data::Vertex > >(); return inValue; }
		if (!memcmp(inName.__s,L"m_nLastFaceId",sizeof(wchar_t)*13) ) { m_nLastFaceId=inValue.Cast< int >(); return inValue; }
		break;
	case 14:
		if (!memcmp(inName.__s,L"aFacesVertexID",sizeof(wchar_t)*14) ) { aFacesVertexID=inValue.Cast< Array< Array< int > > >(); return inValue; }
		if (!memcmp(inName.__s,L"aVertexNormals",sizeof(wchar_t)*14) ) { aVertexNormals=inValue.Cast< Array< ::sandy::core::data::Vertex > >(); return inValue; }
		if (!memcmp(inName.__s,L"m_aVertexFaces",sizeof(wchar_t)*14) ) { m_aVertexFaces=inValue.Cast< Array< Array< Dynamic > > >(); return inValue; }
		break;
	case 15:
		if (!memcmp(inName.__s,L"m_nLastVertexId",sizeof(wchar_t)*15) ) { m_nLastVertexId=inValue.Cast< int >(); return inValue; }
		if (!memcmp(inName.__s,L"m_nLastNormalId",sizeof(wchar_t)*15) ) { m_nLastNormalId=inValue.Cast< int >(); return inValue; }
		if (!memcmp(inName.__s,L"m_nLastFaceUVId",sizeof(wchar_t)*15) ) { m_nLastFaceUVId=inValue.Cast< int >(); return inValue; }
		break;
	case 16:
		if (!memcmp(inName.__s,L"aFacesUVCoordsID",sizeof(wchar_t)*16) ) { aFacesUVCoordsID=inValue.Cast< Array< Array< int > > >(); return inValue; }
		break;
	case 21:
		if (!memcmp(inName.__s,L"m_nLastVertexNormalId",sizeof(wchar_t)*21) ) { m_nLastVertexNormalId=inValue.Cast< int >(); return inValue; }
	}
	return super::__SetField(inName,inValue);
}

void Geometry3D_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_STRING(L"EDGES_DICO",10));
	outFields->push(HX_STRING(L"aVertex",7));
	outFields->push(HX_STRING(L"aFacesVertexID",14));
	outFields->push(HX_STRING(L"aFacesUVCoordsID",16));
	outFields->push(HX_STRING(L"aFacesNormals",13));
	outFields->push(HX_STRING(L"aVertexNormals",14));
	outFields->push(HX_STRING(L"aEdges",6));
	outFields->push(HX_STRING(L"aFaceEdges",10));
	outFields->push(HX_STRING(L"aUVCoords",9));
	outFields->push(HX_STRING(L"m_nLastVertexId",15));
	outFields->push(HX_STRING(L"m_nLastNormalId",15));
	outFields->push(HX_STRING(L"m_nLastFaceId",13));
	outFields->push(HX_STRING(L"m_nLastFaceUVId",15));
	outFields->push(HX_STRING(L"m_nLastUVId",11));
	outFields->push(HX_STRING(L"m_nLastVertexNormalId",21));
	outFields->push(HX_STRING(L"m_aVertexFaces",14));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_STRING(L"EDGES_DICO",10),
	HX_STRING(L"aVertex",7),
	HX_STRING(L"aFacesVertexID",14),
	HX_STRING(L"aFacesUVCoordsID",16),
	HX_STRING(L"aFacesNormals",13),
	HX_STRING(L"aVertexNormals",14),
	HX_STRING(L"aEdges",6),
	HX_STRING(L"aFaceEdges",10),
	HX_STRING(L"aUVCoords",9),
	HX_STRING(L"m_nLastVertexId",15),
	HX_STRING(L"m_nLastNormalId",15),
	HX_STRING(L"m_nLastFaceId",13),
	HX_STRING(L"m_nLastFaceUVId",15),
	HX_STRING(L"m_nLastUVId",11),
	HX_STRING(L"m_nLastVertexNormalId",21),
	HX_STRING(L"m_aVertexFaces",14),
	HX_STRING(L"init",4),
	HX_STRING(L"addFace",7),
	HX_STRING(L"setVertex",9),
	HX_STRING(L"getNextVertexID",15),
	HX_STRING(L"setFaceNormal",13),
	HX_STRING(L"getNextFaceNormalID",19),
	HX_STRING(L"setVertexNormal",15),
	HX_STRING(L"getNextVertexNormalID",21),
	HX_STRING(L"setFaceVertexIds",16),
	HX_STRING(L"isEdgeExist",11),
	HX_STRING(L"getNextFaceID",13),
	HX_STRING(L"setFaceUVCoordsIds",18),
	HX_STRING(L"getNextFaceUVCoordID",20),
	HX_STRING(L"getVertexId",11),
	HX_STRING(L"setUVCoords",11),
	HX_STRING(L"getNextUVCoordID",16),
	HX_STRING(L"generateFaceNormals",19),
	HX_STRING(L"generateVertexNormals",21),
	HX_STRING(L"clone",5),
	HX_STRING(L"dispose",7),
	HX_STRING(L"updateFaceNormals",17),
	HX_STRING(L"toString",8),
	String(null()) };

static void sMarkStatics() {
};

Class Geometry3D_obj::__mClass;

void Geometry3D_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_STRING(L"sandy.core.scenegraph.Geometry3D",32), hx::TCanCast< Geometry3D_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void Geometry3D_obj::__boot()
{
}

} // end namespace sandy
} // end namespace core
} // end namespace scenegraph
