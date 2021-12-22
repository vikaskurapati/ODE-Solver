/**
* Explicit Euler Scheme to solve an ODE
*
* Compute the solution of an ODE on the basis of the given gradient function using
* any chosen Euler Scheme
*
* @param[in] f the function to use, int_value the initial value of the function, t the time until which the solver needs to solve, dt the timestep of the function
*/

#ifndef EXPLICITEULER_H
#define EXPLICITEULER_H

#include "solver.h"

class ExplicitEuler : public Solver
{
    public:
        void solve(const std::function<double(double, double)>&) override;

        ExplicitEuler(double y_0, double dt, double t_end);
};

#endif