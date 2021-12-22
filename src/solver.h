/**
* Solver File to solve an ODE
*
* Compute the solution of an ODE on the basis of the given gradient function using
* any chosen Euler Scheme
*
* @param[in] f the function to use, int_value the initial value of the function, t the time until which the solver needs to solve, dt the timestep of the function
*/
#ifndef SOLVER_H
#define SOLVER_H
#include <vector>
#include <iostream>
#include <functional>
#include <math.h>
#include <cassert>

std::vector<double> solver(const std::function<double(double, double)>&, double, double, double);

void print_solution(const std::vector<double>&);
double error(const std::vector<double>&, const std::vector<double>&);

class Solver
{
    private:
        void initialise_solution();
    protected:
        std::vector<double> _solution;
        double _y_0=0.0;
        double _dt=0.0;
        double _t_end=0;
    public:
        Solver();
        Solver(double y_0, double dt, double t_end);
        void get_solution();
        virtual void solve(const std::function<double(double, double)>&) = 0;
        virtual ~Solver() = default;
};

#endif //SOLVER_H
