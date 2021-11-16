#include <iostream>
#include <vector>
#include <functional>
#include <math.h>
#include "solver.h"

std::vector<double> solver(const std::function<double(double, double)>& f, double int_value, double t, double dt)
{
    std::vector<double> solution;
    double gradient = 0.0;
    solution.push_back(int_value);
    double current_t = 0;
    while(current_t < t)
    {
        if (isnan(gradient) || isinf(gradient)||isnan(solution.back())||isnan(solution.back()))
        {
            throw(std::invalid_argument("Gradient or Solution not a number, please check your function analytically"));
        }
        gradient = f(solution.back(),current_t);
        solution.push_back(solution.back() + dt*gradient);
        current_t += dt;
    }
    return solution;
}