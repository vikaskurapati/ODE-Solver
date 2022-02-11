/**
* Explicit Euler Scheme to solve an ODE
*
* Compute the solution of an ODE on the basis of the given gradient function using
* any chosen Euler Scheme
*
* @param f the function to use, int_value the initial value of the function, 
* @param t the time until which the solver needs to solve, 
* @param dt the timestep of the function
*/

#ifndef EXPLICITEULER_H
#define EXPLICITEULER_H

#include "solver.h"

class ExplicitEuler : public Solver
{
    public:
        void solve(const std::function<double(double, double)>& f)  override;
        /**
        * Explicit Euler Constructor
        *
        * Constructs a solver instance based on the inputs and initializes the solution vector
        *
        * @param y_0, the initial value of the ODE problem, 
        * @param t_end the time until which the solver needs to solve, 
        * @param dt the timestep of the function
        */
        inline ExplicitEuler(double y_0, double dt, double t_end):Solver(y_0,dt,t_end){};
};

#endif