#include <cmath>
#include <stdexcept>
#include <numbers>
#include "helix.h"

namespace curves {
    Helix::Helix(double radius, double step)
        : radius_(radius), step_(step) {
        if (radius <= 0.0 || step_ <= 0.0)
            throw std::invalid_argument("Helix radius and step must be positive");
    }

    Point3D Helix::getPoint(double t) const {
        return { radius_ * std::cos(t),
                 radius_ * std::sin(t),
                 step_ * t / (2.0 * std::numbers::pi) };
    }

    Vector3D Helix::getDerivative(double t) const {
        return { -radius_ * std::sin(t),
                  radius_ * std::cos(t),
                  step_ / (2.0 * std::numbers::pi) };
    }
}