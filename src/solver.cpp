#include "solver.h"

/**
* Function to calculate the error between two vectors
*
* 
* @param calc The Caculated Vector whose error is to be calculated
* @param anal-The analytical solution which is used as a reference to calculate the error
*/

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
    std::vector<double> temp(n, 0.0);
    _solution = temp;
}

/**
* Solver Default Constructor which is run if no parameters are given
* Asks the user to input the parameters as there are no parameters
*/
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

/**
* Helper function to print the solution
*/

void Solver::print_solution()
{
    int n = _solution.size();
    for (int i=0; i < n; i++)
    {
        std::cout <<"( "<<_dt*i<< " , "<<_solution[i] <<" )" << std::endl;
    }
    std::cout << std::endl;
}

/**
* Helper function which returns the solution
*/

std::vector<double> Solver::get_solution()
{
    return _solution;
}