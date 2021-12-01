#include "solver.h"

std::vector<double> solver(const std::function<double(double, double)>& f, double int_value, double t, double dt)
{
    std::vector<double> solution;
    double gradient = 0.0;
    solution.push_back(int_value);
    double current_t = 0;
    while(current_t < t)
    {
        if (isnan(gradient) || isinf(gradient)||isnan(solution.back())||isnan(solution.back()))
        {
            throw(std::invalid_argument("Gradient or Solution is not a number, please check your function analytically"));
        }
        gradient = f(solution.back(),current_t);
        solution.push_back(solution.back() + dt*gradient);
        current_t += dt;
    }
    return solution;
}

void print_solution(const std::vector<double>& x)
{
    for (auto elem: x)
    {
        std::cout << elem << " ";
    }
    std::cout << std::endl;
}

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