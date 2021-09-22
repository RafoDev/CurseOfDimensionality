#include "experiment.h"

namespace Experiment
{
    int dimension{};
    int amountOfNumbers{};
    int chosen{};

    Point *points;
    float *distances;
    float *ratio;

    int collapsedRatio[11]{0};

    float maxDistance{};
    float minDistance{};

    Point chosenPoint;

    float euclidianDistance(Point a, Point b)
    {
        float result{0};
        for (int i = 0; i < dimension; i++)
            result += std::pow((a.arr[i] - b.arr[i]), 2);
        return sqrt(result);
    }

    void getDistances(Point points[], float distances[])
    {
        for (int i = 0; i < amountOfNumbers; i++)
            distances[i] = euclidianDistance(chosenPoint, points[i]);
    }

    void getMinMax(float distances[], float &min, float &max)
    {
        for (int i = 0; i < amountOfNumbers; i++)
        {
            min = min > distances[i] ? distances[i] : min;
            max = max < distances[i] ? distances[i] : max;
        }
    }

    void randomNumberGenerator(Point points[])
    {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> distrib(1, 1000);
        for (int i = 0; i < amountOfNumbers; i++)
        {
            if (i == chosen)
            {
                for (int j = 0; j < dimension; j++)
                    chosenPoint.arr[j] = distrib(gen);
                for (int j = 0; j < dimension; j++)
                    points[i].arr[j] = distrib(gen);
            }
            else
            {
                for (int j = 0; j < dimension; j++)
                    points[i].arr[j] = distrib(gen);
            }
        }
    }

    void printPoints(Point points[])
    {
        std::cout << "POINTS:" << '\n';
        for (int i = 0; i < amountOfNumbers; i++)
        {
            for (int j = 0; j < dimension; j++)
                std::cout << points[i].arr[j] << " ";
            std::cout << '\n';
        }
    }
    void printDistances(float distances[])
    {
        std::cout << "DISTANCES:" << '\n';
        for (int i = 0; i < amountOfNumbers; i++)
            std::cout << distances[i] << " ";
        std::cout << '\n';
    }
    void printRatio(float ratio[])
    {
        std::cout << "RATIO:" << '\n';
        for (int i = 0; i < amountOfNumbers; i++)
            std::cout << ratio[i] << " ";
        std::cout << '\n';
    }

    void getRatio(float maxDistance, float minDistance, float distances[], float ratio[])
    {
        float tmp = (maxDistance - minDistance);
        for (int i = 0; i < amountOfNumbers; i++)
            ratio[i] = roundf(((distances[i] - minDistance) / tmp) * 10) / 10;
    }

    void printCollapsedRatio(int collapsedRatio[])
    {
        std::cout<<"RESULT: "<<'\n';
        for (int i = 0; i < 11; i++)
        {
            std::cout << static_cast<float>(i) / 10 <<";"<< collapsedRatio[i] << '\n';
        }
    }
    void getCollapsedRatio(int collapsedRatio[], float ratio[])
    {
        for (int i = 0; i < amountOfNumbers; i++)
        {
            float tmp = 10 * ratio[i];
            ++collapsedRatio[static_cast<int>(tmp)];
        }
    }
    void setParameters(int _amountOfNumbers, int _dimension, int _chosen)
    {
        dimension = _dimension;
        amountOfNumbers = _amountOfNumbers - 1;
        chosen = _chosen;
    }
    void init()
    {
        points = new Point[amountOfNumbers];
        distances = new float[amountOfNumbers];
        ratio = new float[amountOfNumbers];

        randomNumberGenerator(points);

        getDistances(points, distances);

        maxDistance = distances[0];
        minDistance = distances[0];

        getMinMax(distances, minDistance, maxDistance);

        getRatio(maxDistance, minDistance, distances, ratio);

        getCollapsedRatio(collapsedRatio, ratio);
    }
    void getResult()
    {
        printCollapsedRatio(collapsedRatio);
        delete[] points;
        delete[] distances;
        delete[] ratio;
        for (int i{0}; i < 11; i++)
            collapsedRatio[i] = 0;
    }
}