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