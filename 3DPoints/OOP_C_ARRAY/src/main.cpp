#include "../../configuration.h"
#include <iostream>
#include "PointsArray.h"
#include <chrono>	 // timing libraries

int main()
{
    // generate random points
    PointsArray points(NUMBER_OF_POINTS);
    // points.initializeNull();
    points.initializeUniformDistribution();
    auto const start_time = std::chrono::steady_clock::now();

    points.getAverageOfPointsXLessY();

    auto const end_time = std::chrono::steady_clock::now();
    std::cout << "[OOP]Calculation time = "
              << std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time).count()
              << " microseconds"
              << std::endl;
}