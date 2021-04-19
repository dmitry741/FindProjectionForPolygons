#pragma once
#include <cassert>

class IPoint3D
{
public:

	virtual float GetX() const = 0;
	virtual float GetY() const = 0;
	virtual float GetZ() const = 0;
};

class CPoint3D : public IPoint3D
{
protected:

	float _x, _y, _z;

public:
	CPoint3D(float X, float Y, float Z): _x(X), _y(Y), _z(Z) {}
	CPoint3D() : _x(0), _y(0), _z(0) {}

	float GetX() const { return _x; }
	float GetY() const { return _y; }
	float GetZ() const { return _z; }
};

class CVector : public CPoint3D
{
public: 
	CVector(float X, float Y, float Z) : CPoint3D(X, Y, Z) {};
	CVector(const CPoint3D& point1, const CPoint3D& point2);

	static float Dot(const CVector& a, const CVector& b);
	static CVector Cross(const CVector& a, const CVector& b);

	float GetLenght() const;
	void Negate();

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

class CGeometryKit
{
public:

	static float GetTolerance() { return 0.001f; };
	static float Euclidean(float X1, float Y1, float Z1, float X2, float Y2, float Z2);
	static float Euclidean(const CPoint3D& point1, const CPoint3D& point2);
	static CPoint3D GetProjection(const CPoint3D& point1, const CPoint3D& point2, const CPoint3D& testPoint);
	static float GetParameterProjection(const CPoint3D& point1, const CPoint3D& point2, const CPoint3D& testPoint);
};
