#include <iostream>
#include <functional>
#include <cmath>
#include <vector>
#include "solver.h"
#include<fstream>

const double pi = 3.1415;

int main()
{
    // the gradient is to be input as a lamba function as a function of x, t. x is the variable being solved for and t is the independent variable
    // eg. dx/dt = e^t is show here. dx/dt = e^x would return exp(x)
    auto expo = [](double x, double t){ return 1;};
    double intial_value = 1.0;
    double final_time = 2.0;
    double time_step = 0.1;
    std::vector<double> solution;
    // solver is defined as solver(function, intial_value, final_time, time_step)
    solution = solver(expo, intial_value, final_time, time_step);
    print_solution(solution);
    return 0;
}