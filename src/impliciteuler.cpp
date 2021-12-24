#include "impliciteuler.h"

ImplicitEuler::ImplicitEuler(double y_0, double dt, double t_end):Solver(y_0,dt,t_end)
{}

void ImplicitEuler::solve(const std::function<double(double, double)>& f)
{
    double gradient = 0.0;
    _solution[0] = _y_0;
    size_t n = _solution.size();
    for(int i=1; i<n; i++)
    {
        gradient = Newton(f, _solution[i-1], _dt, (i-1)*_dt);
        if (isnan(gradient) || isinf(gradient)||isnan(_solution.back())||isnan(_solution.back()))
        {
            throw(std::invalid_argument("Gradient or Solution is not a number, please check your function analytically"));
        }
        _solution[i] = gradient;
    }
}

double ImplicitEuler::Newton(const std::function<double(double, double)>& f, double yn, double dt, double t)
{
    int iter = 0;
    double tol = 1;
    double ynext = 0.0;
    double ycurr = yn;
    auto G = [](double x, double t, double yn, double dt, const std::function<double(double, double)>& f){ return x - yn - dt*f(x,t);};
    auto dG = [](double x, double t, double dt, const std::function<double(double, double)>& f){ return 1 - (1/0.01)*dt*(f(x + 0.01,t)- f(x,t));};
    while (tol > 1e-3 && iter < 100)
    {
        if(dG(ycurr, t, dt, f) == 0)
        {
            throw(std::invalid_argument("Newton Solver doesn't work, check your implicit solution"));
        }
        ynext = ycurr - G(ycurr, t, yn, dt, f)/dG(ycurr, t, dt, f);
        tol = abs(ynext - ycurr);
        ycurr = ynext;
        iter += 1;
    }
    return ycurr;
}