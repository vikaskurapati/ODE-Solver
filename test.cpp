#include <iostream>
#include <functional>
#include <cmath>
#include <vector>
#include "solver.h"
#include<fstream>
#include <cassert>

void test_solver()
{
    auto test1 = [](double x, double t){ return 1;};
    auto test2 = [](double x, double t){ return exp(t);};
        
    auto solution1 = solver(test1, 0.0, 2.0, 0.002);
    auto solution2 = solver(test2, 0.0, 2.0, 0.002);

    bool error = false;

    if (solution1.back()-2.0 > 0.001)
    {
        std::cout << " Error in Test Case1" << std::endl;
        error = true;
    }
    if (solution2.back()-(exp(2)-1) > 0.001)
    {
        std::cout << "Error in Test Case2" << std::endl;
        error = true;
    }
    if (!error)
    {
        std::cout << "No Errors, Test Cases ran succesfully, Hurraaahhhhh!!!" << std::endl;
    }
}

int main(void)
{
    test_solver();
}