#include <iostream>
#include <random>
#include <math.h>

namespace Experiment
{
    
    extern int dimension;
    extern int amountOfNumbers;
    extern int chosen;

    struct Point
    {
        int *arr = new int[dimension];
    };

    extern Point *points;
    extern float *distances;
    extern float *ratio;

    extern int collapsedRatio[11];

    extern float maxDistance; 
    extern float minDistance;

    extern Point chosenPoint;


    float euclidianDistance(Point a, Point b);

    void getDistances(Point points[], float distances[]);

    void getMinMax(float distances[], float &min, float &max);

    void randomNumberGenerator(Point points[]);


    void getRatio(float maxDistance, float minDistance, float distances[], float ratio[]);

    void printCollapsedRatio(int collapsedRatio[]);

    void getCollapsedRatio(int collapsedRatio[], float ratio[]);


     void printPoints(Point points[]);

    void printDistances(float distances[]);

    void printRatio(float ratio[]);


    void setParameters(int _amountOfNumbers, int _dimension, int _chosen);

    void init();

    void getResult();
}