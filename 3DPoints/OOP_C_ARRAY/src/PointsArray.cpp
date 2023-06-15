#include "PointsArray.h"
#include <iostream>

PointsArray::PointsArray(uint64_t nPoints)
{
    numberOfPoints = nPoints;
    generator.seed(SEED);
    points = new Point[numberOfPoints];
}

PointsArray::~PointsArray()
{
}

void PointsArray::initializeNull()
{
    for (uint64_t i = 0; i < numberOfPoints; i++)
    {
        Point & localPoint = points[i];
        localPoint.x = 0;
        localPoint.y = 0;
        localPoint.z = 0;
    }
}

void PointsArray::initializeUniformDistribution()
{
    using namespace distributions;
    for (uint64_t i = 0; i < numberOfPoints; i++)
    {
        Point & localPoint = points[i];
        localPoint.x = x_distr(0, 100)(generator);
        //localPoint.y = y_distr(-125, 25)(generator); // y is likelly to be inferior than x
        //localPoint.y = y_distr(75, 175)(generator); // y is likelly to be greater than x
        localPoint.y = y_distr(0, 100)(generator); // y follows the same distribution as x
        localPoint.z = z_distr(-100, 100)(generator);
    }
}

Vector3 PointsArray::getAverageOfPointsXLessY()
{
    Vector3 average{0, 0, 0};
    
    for(uint64_t i = 0 ; i < numberOfPoints; i++)
    {
        Point & local_point = points[i];
        if( local_point.x < local_point.y)
        {
            average.x += local_point.x;
            average.y += local_point.y;
            average.z += local_point.z;
        }
    }

    average.x /= numberOfPoints;
    average.y /= numberOfPoints;
    average.z /= numberOfPoints;


    printf("Average Of Points where X is less than Y: %f | %f | %f \n", average.x, average.y, average.z);
    return average;
}

Vector3 PointsArray::getAverageOfPoints()
{
    Vector3 average{0, 0, 0};

    for(uint64_t i = 0 ; i < numberOfPoints; i++)
    {
        Point & local_point = points[i];

        average.x += local_point.x;
        average.y += local_point.y;
        average.z += local_point.z;
    }

    average.x /= numberOfPoints;
    average.y /= numberOfPoints;
    average.z /= numberOfPoints;

    return average;
}
