#define CATCH_CONFIG_MAIN
#include "../catch/catch.hpp"
#include "expliciteuler.h"
#include "impliciteuler.h"

TEST_CASE( "Explicit Euler is tested", "[ExplicitEuler]" ) {
    auto test1 = [](double x, double t){ return 1;};
    auto test2 = [](double x, double t){ return exp(t);};
        
    ExplicitEuler problem1(0.0, 0.002, 2.0);
    ExplicitEuler problem2(0.0, 0.002, 2.0);
    problem1.solve(test1);
    problem2.solve(test2);

    int n = 1001;

    std::vector<double> anal1(n, 0.0);
    std::vector<double> anal2(n, 0.0);

    for (int i=0; i < n; i++)
    {
        anal1[i] = 0.002*(i);
        anal2[i] = exp(i*0.002) - 1;
    }

    auto solution1 = problem1.get_solution();
    auto solution2 = problem2.get_solution();

    REQUIRE(solution1.size() == anal1.size());
    REQUIRE(solution2.size() == anal2.size());

    SECTION("Checking the last values for sanity")
    {
        REQUIRE( solution1.back()-2.0 < 0.001 );
        REQUIRE( solution2.back()-(exp(2)-1) < 0.001);
    }
    
    SECTION("Checking relative error norms")
    {
        REQUIRE(error(solution1, anal1) < 0.001);
        REQUIRE(error(solution2, anal2) < 0.001);
    }
}

TEST_CASE( "Implicit Euler is tested", "[ImplicitEuler]" ) {
    auto test1 = [](double x, double t){ return 1;};
    auto test2 = [](double x, double t){ return exp(t);};
        
    ImplicitEuler problem1(0.0, 0.002, 2.0);
    ImplicitEuler problem2(0.0, 0.002, 2.0);
    problem1.solve(test1);
    problem2.solve(test2);

    int n = 1001;

    std::vector<double> anal1(n, 0.0);
    std::vector<double> anal2(n, 0.0);

    for (int i=0; i < n; i++)
    {
        anal1[i] = 0.002*(i);
        anal2[i] = exp(i*0.002) - 1;
    }

    auto solution1 = problem1.get_solution();
    auto solution2 = problem2.get_solution();

    REQUIRE(solution1.size() == anal1.size());
    REQUIRE(solution2.size() == anal2.size());

    SECTION("Checking the last values for sanity")
    {
        REQUIRE( solution1.back()-2.0 < 0.001 );
        REQUIRE( solution2.back()-(exp(2)-1) < 0.001);
    }
    
    SECTION("Checking relative error norms")
    {
        REQUIRE(error(solution1, anal1) < 0.001);
        REQUIRE(error(solution2, anal2) < 0.001);
    }
}