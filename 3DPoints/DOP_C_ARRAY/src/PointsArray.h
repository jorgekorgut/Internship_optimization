#pragma once

#include <random>
#include <vector>

namespace distributions 
{
    using x_distr = std::normal_distribution< float >;
    using y_distr = std::normal_distribution< float >;
    using z_distr = std::normal_distribution< float >;
}

struct HotDimensions{
    float x;
    float y;
};

struct Vector3{
    double x;
    double y;
    double z;
};

class PointsArray 
{
public:
    PointsArray(uint64_t numberOfPoints);
    ~PointsArray();
    Vector3 getAverageOfPointsXLessY();
    Vector3 getAverageOfPoints();
    void initializeUniformDistribution();
    void initializeNull();

private:
    HotDimensions * xy;
    float * z;
    uint64_t numberOfPoints;
    std::default_random_engine generator;
    int SEED = 42;
};
