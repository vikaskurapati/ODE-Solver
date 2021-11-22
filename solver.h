/**
* Explicit Euler scheme to solve an ODE
*
* Compute the solution of an ODE on the basis of the given gradient function using
* Explicit Euler Scheme
*
* @param[in] f the function to use, int_value the initial value of the function, t the time until which the solver needs to solve, dt the timestep of the function
*/
#ifndef FUNCTIONS_H_INCLUDED
#define FUNCTIONS_H_INCLUDED

std::vector<double> solver(const std::function<double(double, double)>&, double, double, double);

void print_solution(const std::vector<double>&);
double error(const std::vector<double>&, const std::vector<double>&);

#endif