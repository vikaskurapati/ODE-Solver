#include "expliciteuler.h"
#include "impliciteuler.h"
#include<fstream>

const double pi = 3.1415;

int main()
{
    // the gradient is to be input as a lamba function which is a function of x, t. x is the variable being solved for and t is the independent variable
    // eg. dx/dt = e^t is show here. dx/dt = e^x would return exp(x)
    auto expo = [](double x, double t){ return exp(t);};
    double initial_value = 1.0;
    double final_time = 2.0;
    double time_step = 0.1;
    size_t choice = 1;
    std::vector<double> solution;
    std::cout << "Provide the initial value of the solution" << std::endl;
    std::cin >> initial_value;
    std::cout << "Provide the final time until which the solution should be run" << std::endl;
    std::cin >> final_time;
    std::cout << "Provide the timestep to be used" << std::endl;
    std::cin >> time_step;
    std::cout << "Choose the Solver" << std::endl << "1. ExplicitEuler" << std::endl << "2. ImplicitEuler" << std::endl;
    std::cin >> choice;
    if(choice == 1)
    {
        ExplicitEuler euler(initial_value, time_step, final_time);
        euler.solve(expo);
        euler.print_solution();
    }
    else
    {
        ImplicitEuler euler(initial_value, time_step, final_time);
        euler.solve(expo);
        euler.print_solution();
    }
    return 0;
}