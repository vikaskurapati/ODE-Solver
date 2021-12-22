#include "expliciteuler.h"

ExplicitEuler::ExplicitEuler(double y_0, double dt, double t_end):Solver(y_0,dt,t_end)
{}

void ExplicitEuler::solve(const std::function<double(double, double)>& f)
{
    double gradient = 0.0;
    _solution[0] = _y_0;
    size_t n = _solution.size();
    for(int i=1; i<n; i++)
    {
        if (isnan(gradient) || isinf(gradient)||isnan(_solution.back())||isnan(_solution.back()))
        {
            throw(std::invalid_argument("Gradient or Solution is not a number, please check your function analytically"));
        }
        gradient = f(_solution[i-1], _dt*(i-1));
        _solution[i] = _solution[i-1] + _dt*gradient;
    }
}
