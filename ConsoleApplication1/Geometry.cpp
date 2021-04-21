/* file: Geometry.cpp */

//  Implementation of CPoint3D, Vector, GeometryKit classes.

#include "Geometry.h"
#include <math.h>

// CVector

CVector::CVector(const CPoint& point1, const CPoint& point2) : 
	CPoint(point2.GetX() - point1.GetX(), point2.GetY() - point1.GetY(), point2.GetZ() - point1.GetZ()) {}

CVector::CVector(const CPoint& point) : 
	CPoint(point.GetX(), point.GetY(), point.GetZ()) {}

CVector CVector::Cross(const CVector& a, const CVector& b)
{
	auto X = a.GetY() * b.GetZ() - a.GetZ() * b.GetY();
	auto Y = a.GetZ() * b.GetX() - a.GetX() * b.GetZ();
	auto Z = a.GetX() * b.GetY() - a.GetY() * b.GetX();

	return CVector(X, Y, Z);
}

float CVector::GetLenght() const
{
	return CGeometryKit::Euclidean(_x, 0, _y, 0, _z, 0);
}

// CGeometryKit

float CGeometryKit::Euclidean(float X1, float Y1, float Z1, float X2, float Y2, float Z2)
{
	double X = static_cast<double>(X2) - static_cast<double>(X1);
	double Y = static_cast<double>(Y2) - static_cast<double>(Y1);
	double Z = static_cast<double>(Z2) - static_cast<double>(Z1);

	return static_cast<float>(sqrt(X * X + Y * Y + Z * Z));
}

float CGeometryKit::Euclidean(const CPoint& point1, const CPoint& point2)
{
	return Euclidean(point1.GetX(), point1.GetY(), point1.GetZ(), point2.GetX(), point2.GetY(), point2.GetZ());
}

CPoint CGeometryKit::GetProjection(const CPoint& point1, const CPoint& point2, const CPoint& testPoint)
{
	CVector v1(testPoint, point1);
	CVector v2(testPoint, point2);
	CVector direct = v2 - v1;

	assert(direct.GetLenght() > 0 && "Direct vector is equal to zero.");

	CVector normal = CVector::Cross(v1, v2);
	auto height = normal.GetLenght() / direct.GetLenght();

	if (height < GetTolerance())
		return testPoint;

	CVector vectorAlongHeight = CVector::Cross(direct, normal);
	CVector testVector(testPoint);

	return testVector + height / vectorAlongHeight.GetLenght() * vectorAlongHeight;
}

float CGeometryKit::GetParameterProjection(const CPoint& point1, const CPoint& point2, const CPoint& testPoint)
{
	CVector v(point1, point2);
	auto lenght = v.GetLenght();

	assert(lenght > 0 && "The lenght of vector must be more than zero.");

	float param;

	if (fabs(v.GetX()) > GetTolerance())
		param = (testPoint.GetX() - point1.GetX()) / v.GetX();
	else if (fabs(v.GetY()) > GetTolerance())
		param = (testPoint.GetY() - point1.GetY()) / v.GetY();
	else
		param = (testPoint.GetZ() - point1.GetZ()) / v.GetZ();

	return param;
}
