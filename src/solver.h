/**
* Solver File to solve an ODE
*
* Compute the solution of an ODE on the basis of the given gradient function using
* any chosen Solver Scheme.
* 
* This is a base class for the other solver classes
*/
#ifndef SOLVER_H
#define SOLVER_H
#include <vector>
#include <iostream>
#include <functional>
#include <cassert>

double error_squared(const std::vector<double>&, const std::vector<double>&);

enum SolverScheme{ EulerExplicit, EulerImplicit};

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
        void print_solution();
        std::vector<double> get_solution();
        virtual void solve(const std::function<double(double, double)>& f) = 0;
        virtual ~Solver() = default;
};

#endif //SOLVER_H
