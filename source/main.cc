#include "experiment.h"
#include <chrono>

int main()
{
    std::chrono::time_point<std::chrono::high_resolution_clock> start, end;
    int test[] = {2, 5, 10, 15, 20, 25};

    for (int i = 0; i < 6; i++)
    {
        start = std::chrono::high_resolution_clock::now();
        Experiment::setParameters(20000, test[i], 0);
        Experiment::init();
        Experiment::getResult();
        end = std::chrono::high_resolution_clock::now();
        int64_t duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();
        std::cout<<"Time elapsed: "<<duration<<" ns\n\n";
    }
}