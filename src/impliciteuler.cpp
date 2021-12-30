#include "impliciteuler.h"

/**
* Implicit Euler Constructor
*
* Constructs a solver instance based on the inputs and initializes the solution vector
*
* @param y_0, the initial value of the ODE problem, 
* @param t_end the time until which the solver needs to solve, 
* @param dt the timestep of the function
*/
ImplicitEuler::ImplicitEuler(double y_0, double dt, double t_end):Solver(y_0,dt,t_end)
{}

/**
* Implicit Euler Solve function
*
* Solves the ODE and modifies the solution vector
*
* @param f, defining the gradient of the problem, 
*/
void ImplicitEuler::solve(const std::function<double(double, double)>& f)
{
    double ythis = 0.0;
    _solution[0] = _y_0;
    size_t n = _solution.size();
    for(int i=1; i<n; i++)
    {
        try
        {
            ythis = Newton(f, _solution[i-1], _dt, (i-1)*_dt);
        }
        catch(const std::runtime_error& error)
        {
            std::cerr << "Warning" << error.what() << "\n";
            throw(std::runtime_error("Newton is not solvable"));
        }
        if (isnan(ythis) || isinf(ythis)||isnan(_solution.back())||isnan(_solution.back()))
        {
            throw(std::runtime_error("Solution is not a number, please check your function analytically"));
        }
        _solution[i] = ythis;
    }
}

/**
* Helper Newton function to solve the implicit non-linear equation using Newton Raphson's Method
*
* Solves the non-linear equation and returns the solution
*
* @param f, defining the gradient of the problem, 
* @param yn value of the solution at nth time-step,
* @param dt time-step,
* @param t  time until which the solver already progressed
*/
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
            throw(std::runtime_error("Newton Solver doesn't work, check your implicit solution"));
        }
        ynext = ycurr - G(ycurr, t, yn, dt, f)/dG(ycurr, t, dt, f);
        tol = abs(ynext - ycurr);
        ycurr = ynext;
        iter += 1;
    }
    return ycurr;
}