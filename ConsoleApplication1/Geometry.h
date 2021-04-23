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
	/// Creates CPoint instance with provided coordinates.
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
	/// <returns>Float value that is X coordinate of the point.</returns>
	float GetX() const { return _x; }

	/// <summary>
	/// Returns the Y coordinate of the point.
	/// </summary>
	/// <returns>Float value that is Y coordinate of the point.</returns>
	float GetY() const { return _y; }

	/// <summary>
	/// Returns the Z coordinate of the point.
	/// </summary>
	/// <returns>Float value that is Z coordinate of the point.</returns>
	float GetZ() const { return _z; }
};

/// <summary>
/// Class that provides methods to interact with the vector in 3 dimension space, including the base vector operations.
/// </summary>
class CVector : public CPoint
{
public: 
	/// <summary>
	/// Creates CVector instance with provided coordinates.
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

	/// <summary>
	/// Returns the lenght of the vector.
	/// </summary>
	/// <returns>Float value that is the lenght of vector.</returns>
	float GetLenght() const;

	/// <summary>
	/// Calculates the vector product of two vectors.
	/// </summary>
	/// <param name="a">The first vector.</param>
	/// <param name="b">The second vector.</param>
	/// <returns>CVector instance that is product of two vectors.</returns>
	static CVector Cross(const CVector& a, const CVector& b);	

	/// <summary>
	/// Returns the sum of two vectors.
	/// </summary>
	/// <param name="a">The first vector.</param>
	/// <param name="b">The second vector.</param>
	/// <returns>The vector that is the sum of two vectors.</returns>
	friend CVector operator + (const CVector& a, const CVector& b)
	{
		return CVector(a.GetX() + b.GetX(), a.GetY() + b.GetY(), a.GetZ() + b.GetZ());
	}

	/// <summary>
	/// Returns the difference of two vectors.
	/// </summary>
	/// <param name="a">The first vector.</param>
	/// <param name="b">The second vector.</param>
	/// <returns>The vector that is the difference of two vectors.</returns>
	friend CVector operator - (const CVector& a, const CVector& b)
	{
		return CVector(a.GetX() - b.GetX(), a.GetY() - b.GetY(), a.GetZ() - b.GetZ());
	}
	
	/// <summary>
	/// Returns the vector multiplied by the number.
	/// </summary>
	/// <param name="k">The number.</param>
	/// <param name="v">The vector.</param>
	/// <returns>The vector multiplied by the number.</returns>
	friend CVector operator * (float k, const CVector& v)
	{
		return CVector(k * v.GetX(), k * v.GetY(), k * v.GetZ());
	}
};

/// <summary>
/// Class that provides methods to search projection of point on segment.
/// </summary>
class CGeometryKit
{
public:

	/// <summary>
	/// Returns the level of tolerance.
	/// </summary>
	/// <returns>Float value that is the level of tolerance.</returns>
	static float GetTolerance() { return 0.001f; };

	/// <summary>
	/// Returns euclidian distance between two points defined by their coordinates.
	/// </summary>
	/// <param name="X1">X ccoordinate of the first point.</param>
	/// <param name="Y1">Y ccoordinate of the first point.</param>
	/// <param name="Z1">Z ccoordinate of the first point.</param>
	/// <param name="X2">X ccoordinate of the second point.</param>
	/// <param name="Y2">Y ccoordinate of the second point.</param>
	/// <param name="Z2">Z ccoordinate of the second point.</param>
	/// <returns>Float value that is the euclidian distance between two points.</returns>
	static float Euclidean(float X1, float Y1, float Z1, float X2, float Y2, float Z2);

	/// <summary>
	/// Returns euclidian distance between two points.
	/// </summary>
	/// <param name="point1">The first point.</param>
	/// <param name="point2">The second point.</param>
	/// <returns>Float value that is the euclidian distance between two points.</returns>
	static float Euclidean(const CPoint& point1, const CPoint& point2);

	/// <summary>
	/// Returns the point that is the projection of test point on the segment defined by two points.
	/// </summary>
	/// <param name="point1">The frist point of segment.</param>
	/// <param name="point2">The second point of segment.</param>
	/// <param name="testPoint">The test point.</param>
	/// <returns>CPoint instance that is projection of test point on the segment.</returns>
	static CPoint GetProjection(const CPoint& point1, const CPoint& point2, const CPoint& testPoint);

	/// <summary>
	/// Returns the parameter of projection of test point on the segment defined by two points.
	/// </summary>
	/// <param name="point1">The frist point of segment.</param>
	/// <param name="point2">The second point of segment.</param>
	/// <param name="testPoint">The test point.</param>
	/// <returns>Float value that is the parameter of projection of test point on the segment.</returns>
	static float GetParameterProjection(const CPoint& point1, const CPoint& point2, const CPoint& testPoint);
};
