#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include <iostream>
#include <functional>
#include <cmath>
#include <vector>
#include "solver.h"
#include<fstream>
#include <cassert>


TEST_CASE( "Solver is tested", "[solver]" ) {
    auto test1 = [](double x, double t){ return 1;};
    auto test2 = [](double x, double t){ return exp(t);};
        
    auto solution1 = solver(test1, 0.0, 2.0, 0.002);
    auto solution2 = solver(test2, 0.0, 2.0, 0.002);

    int n = 1001;

    std::vector<double> anal1(n, 0.0);
    std::vector<double> anal2(n, 0.0);

    for (int i=0; i < n; i++)
    {
        anal1[i] = 0.002*(i);
        anal2[i] = exp(i*0.002) - 1;
    }

    REQUIRE(solution1.size() == anal1.size());
    REQUIRE(solution2.size() == anal2.size());

    SECTION("Checking the last values for sanity")
    {
        REQUIRE( solution1.back()-2.0 < 0.001 );
        REQUIRE( solution2.back()-(exp(2)-1) < 0.001);
    }
    
    SECTION("Checking relative error norms")
    {
        REQUIRE(error(solution1, anal1) < 0.01);
        REQUIRE(error(solution2, anal2) < 0.01);
    }
}