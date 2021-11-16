#include <iostream>
#include <vector>
#include <functional>
#include "solver.h"

std::vector<double> solver(const std::function<double(double, double)>& f, double int_value, double t, double dt)
{
    std::vector<double> solution;
    double gradient = 0.0;
    solution.push_back(int_value);
    double current_t = 0;
    while(current_t < t)
    {
        gradient = f(solution.back(),current_t);
        solution.push_back(solution.back() + dt*gradient);
        current_t += dt;
    }
    return solution;
}

