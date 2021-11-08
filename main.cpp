#include <iostream>
#include <functional>
#include <cmath>
#include <vector>
#include "solver.h"
#include<fstream>

const double pi = 3.1415;

int main()
{
    auto expo = [](double x, double t){ return exp(t);};
    std::vector<double> solution;
    // solver is defined as solver(function, intial_value, final_time, time_step)
    solution = solver(expo, 1.0, 2.0, 0.0002);
    std::cout << solution.back() << std::endl;
    return 0;
}