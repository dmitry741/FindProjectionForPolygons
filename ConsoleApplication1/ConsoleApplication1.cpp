// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Geometry.h"
#include "CArray.h"
#include <vector>
#include <fstream>

struct ResultProjection
{
    CPoint3D projection;
    float distance = 0;
    float param = 0;
};

int main()
{
    std::vector<CPoint3D> points;
    std::ifstream file;

    file.open("testcase1.txt");

    if (!file.is_open())
    {
        std::cout << "File does not exist" << std::endl;
        return 1;
    }

    float x, y, z;

    while (!file.eof())
    {
        file >> x;
        file >> y;
        file >> z;

        CPoint3D point(x, y, z);
        points.push_back(point);
    }

    file.close();


    ResultProjection* results = new ResultProjection[points.size() - 1];
    CPoint3D testPoint = CPoint3D(2, 0.5, 0.5);

    float minDistance = std::numeric_limits<float>::max();

    for (int i = 0; i < points.size() - 1; ++i)
    {
        results[i].projection = CGeometryKit::GetProjection(points[i], points[static_cast<long long>(i) + 1], testPoint);
        results[i].param = CGeometryKit::GetParameterProjection(points[i], points[static_cast<long long>(i) + 1], results[i].projection);
        results[i].distance = CGeometryKit::Euclidean(testPoint, results[i].projection);

        if (0 <= results[i].param && results[i].param <= 1)
        {
            if (results[i].distance < minDistance)
            {
                minDistance = results[i].distance;
            }
        }
    } 

    if (minDistance != std::numeric_limits<float>::max())
    {
        for (int i = 0; i < points.size() - 1; ++i)
        {
            if (0 <= results[i].param && results[i].param <= 1 && abs(results[i].distance - minDistance) < CGeometryKit::GetTolerance())
            {
                std::cout << "segment " << i + 1 << " ";
                std::cout << "parameter " << results[i].param << " ";
                std::cout << "point " << results[i].projection.GetX() << " " << results[i].projection.GetY() << " " << results[i].projection.GetZ() << std::endl;
            }
        }
    }
    else
    {
        std::cout << "No projections." << std::endl;
    }

    delete[] results;
}
