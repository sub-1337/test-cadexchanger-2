#include <iostream>
#include <vector>
#include <memory>
#include <random>
#include <algorithm>
#include <cmath>
#include <numbers>
#include <sstream>
#include <string>

#include "curves/circle.h"
#include "curves/ellipse.h"
#include "curves/helix.h"

using namespace curves;

constexpr double T = std::numbers::pi / 4.0;

int main()
{
    constexpr size_t NUM_CURVES = 10;

    std::ostringstream oss;
    std::vector<std::shared_ptr<Curve>> curvesContainer;

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> radiusDist(1.0, 5.0);
    std::uniform_real_distribution<> stepDist(0.5, 3.0);
    std::uniform_int_distribution<> typeDist(0, 2);

    // Гарантируем наличие всех типов
    curvesContainer.push_back(std::make_shared<Circle>(radiusDist(gen)));
    curvesContainer.push_back(std::make_shared<Ellipse>(radiusDist(gen), radiusDist(gen)));
    curvesContainer.push_back(std::make_shared<Helix>(radiusDist(gen), stepDist(gen)));

    for (size_t i = 3; i < NUM_CURVES; ++i)
    {
        int type = typeDist(gen);

        if (type == 0)
            curvesContainer.push_back(std::make_shared<Circle>(radiusDist(gen)));
        else if (type == 1)
            curvesContainer.push_back(std::make_shared<Ellipse>(radiusDist(gen), radiusDist(gen)));
        else
            curvesContainer.push_back(std::make_shared<Helix>(radiusDist(gen), stepDist(gen)));
    }

    // output points and deriatives

    oss << "Points and derivatives at t = PI/4\n\n";

    for (const auto& curve : curvesContainer)
    {
        auto p = curve->getPoint(T);
        auto d = curve->getDerivative(T);

        oss << "Point: ("
            << p[0] << ", " << p[1] << ", " << p[2] << ")  ";

        oss << "Derivative: ("
            << d[0] << ", " << d[1] << ", " << d[2] << ")\n";
    }


    // Only circle

    std::vector<std::shared_ptr<Circle>> circlesContainer;

    for (const auto& curve : curvesContainer)
    {
        if (auto circle = std::dynamic_pointer_cast<Circle>(curve))
        {
            circlesContainer.push_back(circle);
        }
    }

    std::sort(circlesContainer.begin(), circlesContainer.end(),
        [](const auto& a, const auto& b)
        {
            return a->getRadius() < b->getRadius();
        });

    double totalRadius = 0.0;
    for (const auto& circle : circlesContainer)
        totalRadius += circle->getRadius();

    oss << "\nSorted circles radii:\n";
    for (const auto& circle : circlesContainer)
        oss << circle->getRadius() << "\n";

    oss << "\nTotal sum of radii: " << totalRadius << "\n";


    // Output to console
    std::cout << oss.str();
	return 0;
}
