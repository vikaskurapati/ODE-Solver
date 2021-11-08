
#include <iostream>
#ifndef FUNCTIONS_H_INCLUDED
#define FUNCTIONS_H_INCLUDED

std::vector<double> solver(const std::function<double(double, double)>&, double, double, double);

#endif