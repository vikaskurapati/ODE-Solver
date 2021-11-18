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

    REQUIRE( solution1.back()-2.0 < 0.001 );
    REQUIRE( solution2.back()-(exp(2)-1) < 0.001);

}