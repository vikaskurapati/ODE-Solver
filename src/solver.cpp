#include "solver.h"
#include <cmath>

/**
* Function to calculate the error between two vectors
*
* 
* @param calc The Caculated Vector whose error is to be calculated
* @param anal-The analytical solution which is used as a reference to calculate the error
*/

double error_squared(const std::vector<double>& calc, const std::vector<double>& anal)
{
    size_t n = calc.size();
    assert((anal.size() == n)&& "The size of the solution vector must be equal to the analytical solution vector");
    double error = 0.0;
    for (size_t i=0; i < n; i++)
    {
        if (abs(anal[i]) < 1e-5)
        {
            continue;
        }
        error += ((calc[i]-anal[i])/anal[i])*((calc[i]-anal[i])/anal[i]);
    }
    return error/n;
}

/**
* Solver Constructor
*
* @param y_0- initial value of the problem
* @param dt time-step of the problem
* @param t_end time until which the ode should solve the problem
*/

Solver::Solver(double y_0, double dt, double t_end)
{
    _y_0=y_0;
    _dt=dt;
    _t_end=t_end;
    Solver::initialise_solution();
}

/**
* Helper function to initialise the solution to vector
*/

void Solver::initialise_solution()
{
    int n = static_cast<int> (_t_end/_dt) + 1;
    //std::array<double, n> temp;
    std::vector<double> temp(n, 0.0);
    //temp.fill(0.0);
    _solution = temp;
}

/**
* Solver Default Constructor which is run if no parameters are given
* Asks the user to input the parameters as there are no parameters
*/
Solver::Solver()
{
    std::cout<<"Enter initial value of solution \n";
    std::cin>>_y_0;
    std::cout<<"Enter time step of the equation \n";
    std::cin>>_dt;
    std::cout<<"Enter the final time of the equation to be used \n";
    std::cin>>_t_end;
    Solver::initialise_solution();
}

/**
* Helper function to print the solution
*/

void Solver::print_solution()
{
    int n = _solution.size();
    for (size_t i=0; i < n; i++)
    {
        std::cout <<"( "<<_dt*i<< " , "<<_solution[i] <<" ) \n";
    }
    std::cout << "\n";
}
