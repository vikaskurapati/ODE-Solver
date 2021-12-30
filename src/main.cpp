#include "solver.h"
#include<fstream>

const double pi = 3.1415;

int main()
{
    // the gradient is to be input as a lamba function which is a function of x, t. x is the variable being solved for and t is the independent variable
    // eg. dx/dt = e^t is show here. dx/dt = e^x would return exp(x)
    auto gradient_function = [](double x, double t){ return 1;};
    double initial_value = 1.0;
    double final_time = 2.0;
    double time_step = 0.1;
    std::vector<double> solution;
    std::cout << "Provide the initial value of the solution" << std::endl;
    std::cin >> initial_value;
    std::cout << "Provide the final time until which the solution should be run" << std::endl;
    std::cin >> final_time;
    std::cout << "Provide the timestep to be used" << std::endl;
    std::cin >> time_step;
    // solver is defined as solver(function, initial_value, final_time, time_step)
    std::cout << "Expected value at the last time step if you haven't changed the gradient function from the constant function would be: " << initial_value + final_time << std::endl;
    try
    {
       solution = solver(gradient_function, initial_value, final_time, time_step);
    }
    catch(const std::invalid_argument& e)
    {
        std::cerr << "Error:" << e.what() << '\n';
    }
    print_solution(solution);
    return 0;
}
