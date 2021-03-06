#include "expliciteuler.h"
#include <cmath>

/**
* Explicit Euler Solve function
*
* Solves the ODE and modifies the solution vector
*
* @param f, defining the gradient of the problem, 
*/

void ExplicitEuler::solve(const std::function<double(double, double)>& f)
{
    double gradient = 0.0;
    _solution[0] = _y_0;
    size_t n = _solution.size();
    for(size_t i=1; i<n; i++)
    {
        if (std::isnan(gradient) || std::isinf(gradient)||std::isnan(_solution.back())||std::isnan(_solution.back()))
        {
            throw(std::runtime_error("Gradient or Solution is not a number, please check your function analytically"));
        }
        gradient = f(_solution[i-1], _dt*(i-1));
        _solution[i] = _solution[i-1] + _dt*gradient;
    }
}
