#include "expliciteuler.h"
#include "impliciteuler.h"

#include <fstream>
#include <memory>
#include <cmath>

const double pi = 3.1415;

int main()
{
    /**
    * the gradient is to be input as a lamba function which is a function of x, t. x is the variable being solved for and t is the independent variable
    * eg. dy/dt = e^t is show here. dy/dt = e^y would return exp(y)/
    * @param auto The gradient function as a function of y and t
    */

    auto gradient_function = [](double y, double t){ return exp(y);};
    std::string line;
    std::ifstream myfile("../src/main.cpp");
    std::ofstream out("solution.txt");
    auto *coutbuf = std::cout.rdbuf();
    std::cout.rdbuf(out.rdbuf());
    int line_counter = 1;
    if (myfile.is_open())
    {
        while(getline(myfile, line))
        {
            if(line_counter == 18)
            {
                std::cout << "The Gradient function used for this problem is \n";
                std::cout << line << std::endl;
            }
            line_counter += 1;
        }
        myfile.close();
    }

    std::cout.rdbuf(coutbuf);
    double initial_value = 1.0;
    double final_time = 2.0;
    double time_step = 0.1;
    size_t choice = 1;
    std::vector<double> solution;
    std::cout << "Provide the initial value of the solution \n";
    std::cin >> initial_value;
    std::cout << "Provide the final time until which the solution should be run \n";
    std::cin >> final_time;
    std::cout << "Provide the timestep to be used \n";
    std::cin >> time_step;
    std::cout << "Choose the Solver \n 1. ExplicitEuler \n 2. ImplicitEuler \n";
    std::cin >> choice;
    std::string solvermethod;

    std::unique_ptr<Solver> euler;

    if(choice == 1)
    {
        euler = std::make_unique<ExplicitEuler>(initial_value, time_step, final_time);
        //ExplicitEuler euler(initial_value, time_step, final_time);
        solvermethod = "Explicit Euler";
    }
    else
    {
        euler = std::make_unique<ImplicitEuler>(initial_value, time_step, final_time);
//        ImplicitEuler euler(initial_value, time_step, final_time);
        solvermethod = "Implicit Euler";
    }

    std::cout.rdbuf(out.rdbuf());
    try
    {
        euler->solve(gradient_function);
    }
    catch(const std::runtime_error& error)
    {
        std::cerr << "Error: " << error.what() << "\n";
        return 1;
    }
    std::cout << "The Solver used for this problem is: \n";
    std::cout << "    " << solvermethod << std::endl;
    std::cout << "The solution obtained y(t) is: \n";
    std::cout << "( t,  y(t) ) \n";
    euler->print_solution(); 
    std::cout.rdbuf(coutbuf);
    return 0;
}