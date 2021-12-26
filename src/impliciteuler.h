/**
* Implicit Euler Scheme to solve an ODE
*
* Compute the solution of an ODE on the basis of the given gradient function using
* any chosen Euler Scheme
*
* @param[in] f the function to use, int_value the initial value of the function, t the time until which the solver needs to solve, dt the timestep of the function
*/

#ifndef IMPLICITEULER_H
#define IMPLICITEULER_H

#include "solver.h"

class ImplicitEuler : public Solver
{
    private:
        double Newton(const std::function<double(double, double)>&, double, double, double);
    
    public:
        void solve(const std::function<double(double, double)>&) override;

        ImplicitEuler(double y_0, double dt, double t_end);
};

#endif