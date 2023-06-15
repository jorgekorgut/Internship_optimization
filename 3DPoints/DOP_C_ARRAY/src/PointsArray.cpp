#include "PointsArray.h"
#include <iostream>

PointsArray::PointsArray(uint64_t nPoints)
{
    numberOfPoints = nPoints;
    generator.seed(SEED);
    xy = new HotDimensions[numberOfPoints];
    z = new float[numberOfPoints];
}

PointsArray::~PointsArray()
{
}

void PointsArray::initializeNull()
{
    for (uint64_t i = 0; i < numberOfPoints; i++)
    {
        HotDimensions & local_xy = xy[i];
        local_xy.x = 0;
        local_xy.y = 0;
    }

    for (uint64_t i = 0; i < numberOfPoints; i++)
    {
        z[i] = 0;
    }
}

void PointsArray::initializeUniformDistribution()
{
    using namespace distributions;
    for (uint64_t i = 0; i < numberOfPoints; i++)
    {
        HotDimensions & local_xy = xy[i];
        local_xy.x = x_distr(0, 100)(generator);
        //local_xy.y = y_distr(-125, 25)(generator); // y is likelly to be inferior than x
        //local_xy.y = y_distr(75, 175)(generator); // y is likelly to be greater than x
        local_xy.y = y_distr(0, 100)(generator); // y follows the same distribution as x
        z[i] = z_distr(-100, 100)(generator);
    }
}

//To speed thinks up I can separate the points in different threads and then analyse the result of the individual ones
Vector3 PointsArray::getAverageOfPointsXLessY()
{
    Vector3 average{0, 0, 0};
    
    for(uint64_t i = 0 ; i < numberOfPoints; i++)
    {
        HotDimensions & local_xy = xy[i];
        if( local_xy.x < local_xy.y)
        {
            average.x += local_xy.x;
            average.y += local_xy.y;
            average.z += z[i];
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
        HotDimensions & local_xy = xy[i];

        average.x += local_xy.x;
        average.y += local_xy.y;
    }

    for(uint64_t i = 0 ; i < numberOfPoints; i++)
    {
        average.z += z[i];
    }

    average.x /= numberOfPoints;
    average.y /= numberOfPoints;
    average.z /= numberOfPoints;

    return average;
}
