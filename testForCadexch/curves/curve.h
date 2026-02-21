#pragma once
#include <array>

namespace curves {

    using Point3D = std::array<double, 3>;
    using Vector3D = std::array<double, 3>;

    class Curve {
    public:
        virtual ~Curve() = default;

        virtual Point3D getPoint(double t) const = 0;
        virtual Vector3D getDerivative(double t) const = 0;
    };

}