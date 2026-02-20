#include <catch2/catch_test_macros.hpp>
#include <cmath>
#include <numbers>

#include "circle.h"
#include "ellipse.h"
#include "helix.h"

using namespace curves;

constexpr double EPS = 1e-6;

TEST_CASE("Circle point and derivative correctness", "[circle]")
{
    Circle c(5.0);
    double t = std::numbers::pi / 4.0;

    auto p = c.getPoint(t);
    auto d = c.getDerivative(t);

    REQUIRE(std::abs(p[0] - 5.0 * std::cos(t)) < EPS);
    REQUIRE(std::abs(p[1] - 5.0 * std::sin(t)) < EPS);
    REQUIRE(p[2] == 0.0);

    REQUIRE(std::abs(d[0] + 5.0 * std::sin(t)) < EPS);
    REQUIRE(std::abs(d[1] - 5.0 * std::cos(t)) < EPS);
    REQUIRE(d[2] == 0.0);
}