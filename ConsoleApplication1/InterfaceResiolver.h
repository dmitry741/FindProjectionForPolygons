#pragma once
#include "Geometry.h"

class CInterfaceResolver
{
public:

	static IPoint3D* ResolvePoint3D(float X, float Y, float Z)
	{
		return new CPoint3D(X, Y, Z);
	}
};