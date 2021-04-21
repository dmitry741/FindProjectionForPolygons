/* file: Geometry.h */

#pragma once
#include <cassert>

/**
 * <a name="CPoint"></a>
 * \brief Class that provides methods to interact with the point in 3 dimension space.
 */
class CPoint
{
protected:

	float _x, _y, _z;

public:
	CPoint(float X, float Y, float Z): _x(X), _y(Y), _z(Z) {}
	CPoint() : _x(0), _y(0), _z(0) {}

	float GetX() const { return _x; }
	float GetY() const { return _y; }
	float GetZ() const { return _z; }
};

/**
 * <a name="CVector"></a>
 * \brief Class that provides methods to interact with the vector in 3 dimension space, including the base vector operations.
 */
class CVector : public CPoint
{
public: 
	CVector(float X, float Y, float Z) : CPoint(X, Y, Z) {};
	CVector(const CPoint& point1, const CPoint& point2);
	CVector(const CPoint& point);

	static CVector Cross(const CVector& a, const CVector& b);
	float GetLenght() const;

	friend CVector operator + (const CVector& a, const CVector& b)
	{
		return CVector(a.GetX() + b.GetX(), a.GetY() + b.GetY(), a.GetZ() + b.GetZ());
	}

	friend CVector operator - (const CVector& a, const CVector& b)
	{
		return CVector(a.GetX() - b.GetX(), a.GetY() - b.GetY(), a.GetZ() - b.GetZ());
	}
	
	friend CVector operator * (float k, const CVector& v)
	{
		return CVector(k * v.GetX(), k * v.GetY(), k * v.GetZ());
	}
};

/**
 * <a name="CGeometryKit"></a>
 * \brief Class that provides methods to search projection of point on segments.
 */
class CGeometryKit
{
public:

	static float GetTolerance() { return 0.001f; };
	static float Euclidean(float X1, float Y1, float Z1, float X2, float Y2, float Z2);
	static float Euclidean(const CPoint& point1, const CPoint& point2);
	static CPoint GetProjection(const CPoint& point1, const CPoint& point2, const CPoint& testPoint);
	static float GetParameterProjection(const CPoint& point1, const CPoint& point2, const CPoint& testPoint);
};
