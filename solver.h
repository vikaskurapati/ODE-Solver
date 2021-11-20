#include <iostream>
#ifndef FUNCTIONS_H_INCLUDED
#define FUNCTIONS_H_INCLUDED

std::vector<double> solver(const std::function<double(double, double)>&, double, double, double);

void print_solution(const std::vector<double>&);
double error(const std::vector<double>&, const std::vector<double>&);

#endif