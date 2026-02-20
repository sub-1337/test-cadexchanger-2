#include <catch2/catch_test_macros.hpp>
#include <cmath>
#include <numbers>

#include "circle.h"
#include "ellipse.h"
#include "helix.h"

using namespace curves;

constexpr double EPS = 1e-6;

TEST_CASE("Circle point & derivative correctness", "[circle]")
{
    // Create circle
    Circle c(5.0);
    double t = std::numbers::pi / 4.0;

    auto p = c.getPoint(t);
    auto d = c.getDerivative(t);

    REQUIRE(std::abs(p[0] - 5.0 * std::cos(t)) < EPS);
    REQUIRE(std::abs(p[1] - 5.0 * std::sin(t)) < EPS);    
    REQUIRE(std::abs(d[0] + 5.0 * std::sin(t)) < EPS);
    REQUIRE(std::abs(d[1] - 5.0 * std::cos(t)) < EPS);
    REQUIRE(p[2] == 0.0);
    REQUIRE(d[2] == 0.0);
}

TEST_CASE("Ellipse point", "[ellipse]")
{
    // create ellipse
    Ellipse e(3.0, 4.0);
    double t = std::numbers::pi / 6.0;

    auto p = e.getPoint(t);
    REQUIRE(std::abs(p[0] - 3.0 * std::cos(t)) < EPS);
    REQUIRE(std::abs(p[1] - 4.0 * std::sin(t)) < EPS);
    REQUIRE(p[2] == 0.0);
}

TEST_CASE("Helix test", "[helix]")
{
    double radius = 2.0;
    double step = 6.0;
    // create heilx
    Helix h(radius, step);

    double t = 1.2;

    auto p1 = h.getPoint(t);
    auto p2 = h.getPoint(t + 2.0 * std::numbers::pi);

    REQUIRE(std::abs(p1[0] - p2[0]) < EPS);
    REQUIRE(std::abs(p1[1] - p2[1]) < EPS);
    REQUIRE(std::abs(p2[2] - (p1[2] + step)) < EPS);
}

TEST_CASE("Invalid parameters throw", "[validation]")
{
    REQUIRE_THROWS_AS(Circle(-1.0), std::invalid_argument);
    REQUIRE_THROWS_AS(Ellipse(1.0, -2.0), std::invalid_argument);
    REQUIRE_THROWS_AS(Helix(-1.0, 1.0), std::invalid_argument);
}