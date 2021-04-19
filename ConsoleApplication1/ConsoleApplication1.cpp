// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Geometry.h"
#include "InterfaceResiolver.h"

struct ResultProjection
{
    CPoint3D projection;
    float distance;
    float param;
};

int main()
{
    //std::cout << "Projection!\n";

   /* CPoint3D point1(0, 0, 0);
    CPoint3D point2(2, 0, 0);
    CPoint3D testPoint(2, 0, 0);

    CPoint3D projection = CGeometryKit::GetProjection(point1, point2, testPoint);
    float param = CGeometryKit::GetParameterProjection(point1, point2, projection);*/

    /*0 0 0
        1 0 0
        2 1 0
        3 1 1
        Точка:
    2 0.5 0.5*/


    /*
    0 0 0
    2 0 0
    2 2 0
    0 2 0
    0 0 0
        Точка:
    1 1 1
    */

    const int cCount = 5;
    CPoint3D points[cCount];
    ResultProjection results[cCount];

    points[0] = CPoint3D(0, 0, 0);
    points[1] = CPoint3D(2, 0, 0);
    points[2] = CPoint3D(2, 2, 0);
    points[3] = CPoint3D(0, 2, 0);
    points[4] = CPoint3D(0, 0, 0);

    CPoint3D testPoint = CPoint3D(1, 1, 1);

    float minDistance = FLT_MAX;

    for (int i = 0; i < cCount - 1; ++i)
    {
        results[i].projection = CGeometryKit::GetProjection(points[i], points[i + 1], testPoint);
        results[i].param = CGeometryKit::GetParameterProjection(points[i], points[i + 1], results[i].projection);
        results[i].distance = CGeometryKit::Euclidean(testPoint, results[i].projection);

        if (0 <= results[i].param && results[i].param <= 1)
        {
            if (results[i].distance < minDistance)
            {
                minDistance = results[i].distance;
            }
        }
    } 

    if (minDistance != FLT_MAX)
    {
        for (int i = 0; i < cCount - 1; ++i)
        {
            if (0 <= results[i].param && results[i].param <= 1 && abs(results[i].distance - minDistance) < CGeometryKit::GetTolerance())
            {
                std::cout << "segment " << i + 1 << "\t";
                std::cout << "parameter " << results[i].param << "\t";
                std::cout << "point " << results[i].projection.GetX() << " " << results[i].projection.GetY() << " " << results[i].projection.GetZ() << std::endl;
            }
        }
    }
    else
    {
        std::cout << "No projections." << std::endl;
    }
}
