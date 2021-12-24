#include "solver.h"

double error(const std::vector<double>& calc, const std::vector<double>& anal)
{
    long unsigned int n = calc.size();
    assert(anal.size() == n);
    double error = 0.0;
    for (long unsigned int i=0; i < n; i++)
    {
        if (abs(anal[i]) < 0.00001)
        {
            continue;
        }
        error += ((calc[i]-anal[i])/anal[i])*((calc[i]-anal[i])/anal[i]);
    }
    error = sqrt(error/n);
    return error;
}

Solver::Solver(double y_0, double dt, double t_end)
{
    _y_0=y_0;
    _dt=dt;
    _t_end=t_end;
    Solver::initialise_solution();
}

void Solver::initialise_solution()
{
    int n = static_cast<int> (_t_end/_dt) + 1;
    std::vector<double> temp(n, 0.0);
    _solution = temp;
}

Solver::Solver()
{
    std::cout<<"Enter initial value of solution"<<std::endl;
    std::cin>>_y_0;
    std::cout<<"Enter time step of the equation "<<std::endl;
    std::cin>>_dt;
    std::cout<<"Enter the final time of the equation to be used"<<std::endl;
    std::cin>>_t_end;
    Solver::initialise_solution();
}

void Solver::print_solution()
{
    int n = _solution.size();
    for (int i=0; i < n; i++)
    {
        std::cout << _solution[i] << " ";
    }
    std::cout << std::endl;
}

std::vector<double> Solver::get_solution()
{
    return _solution;
}