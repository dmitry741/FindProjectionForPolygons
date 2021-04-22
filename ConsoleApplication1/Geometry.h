/* file: Geometry.h */

#pragma once
#include <cassert>

/// <summary>
/// Class that provides methods to interact with the point in 3 dimension space.
/// </summary>
class CPoint
{
protected:
	float _x, _y, _z;

public:
	/// <summary>
	/// Creates CPoint instance with provided coodinates.
	/// </summary>
	/// <param name="X">X coodinate.</param>
	/// <param name="Y">Y coodinate.</param>
	/// <param name="Z">Z coodinate.</param>
	/// <returns>CPoint instance.</returns>
	CPoint(float X, float Y, float Z): _x(X), _y(Y), _z(Z) {}

	/// <summary>
	/// Default constructor. Sets X, Y, Z to 0.
	/// </summary>
	/// <returns>CPoint instance.</returns>
	CPoint() : _x(0), _y(0), _z(0) {}

	/// <summary>
	/// Returns the X coordinate of the point.
	/// </summary>
	/// <returns>X coordinate of the point.</returns>
	float GetX() const { return _x; }

	/// <summary>
	/// Returns the Y coordinate of the point.
	/// </summary>
	/// <returns>Y coordinate of the point.</returns>
	float GetY() const { return _y; }

	/// <summary>
	/// Returns the Z coordinate of the point.
	/// </summary>
	/// <returns>Z coordinate of the point.</returns>
	float GetZ() const { return _z; }
};

/// <summary>
/// Class that provides methods to interact with the vector in 3 dimension space, including the base vector operations.
/// </summary>
class CVector : public CPoint
{
public: 
	/// <summary>
	/// Creates CVector instance with provided coodinates.
	/// </summary>
	/// <param name="X">X coodinate.</param>
	/// <param name="Y">Y coodinate.</param>
	/// <param name="Z">Z coodinate.</param>
	/// <returns>CVector instance.</returns>
	CVector(float X, float Y, float Z) : CPoint(X, Y, Z) {};

	/// <summary>
	/// Creates CVector instance by provided two points.
	/// </summary>
	/// <param name="point1">The first point (begin).</param>
	/// <param name="point2">The second point (end).</param>
	/// <returns>CVector instance.</returns>
	CVector(const CPoint& point1, const CPoint& point2);

	/// <summary>
	/// Creates CVector instance by provided CPoint object.
	/// </summary>
	/// <param name="point">CPoint object.</param>
	/// <returns>CVector instance.</returns>
	CVector(const CPoint& point);

	float GetLenght() const;
	static CVector Cross(const CVector& a, const CVector& b);	

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

/// <summary>
/// Class that provides methods to search projection of point on segments.
/// </summary>
class CGeometryKit
{
public:
	static float GetTolerance() { return 0.001f; };
	static float Euclidean(float X1, float Y1, float Z1, float X2, float Y2, float Z2);
	static float Euclidean(const CPoint& point1, const CPoint& point2);
	static CPoint GetProjection(const CPoint& point1, const CPoint& point2, const CPoint& testPoint);
	static float GetParameterProjection(const CPoint& point1, const CPoint& point2, const CPoint& testPoint);
};
