#include <cmath>
#include <stdexcept>
#include "ellipse.h"

namespace curves {
    Ellipse::Ellipse(double radiusX, double radiusY)
        : radiusX_(radiusX), radiusY_(radiusY) {
        if (radiusX <= 0.0 || radiusY <= 0.0)
            throw std::invalid_argument("Ellipse radii must be positive");
    }

    Point3D Ellipse::getPoint(double t) const {
        return { radiusX_ * std::cos(t),
                 radiusY_ * std::sin(t),
                 0.0 };
    }

    Vector3D Ellipse::getDerivative(double t) const {
        return { -radiusX_ * std::sin(t),
                  radiusY_ * std::cos(t),
                  0.0 };
    }
}