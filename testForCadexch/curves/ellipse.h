#pragma once
#include "curve.h"

namespace curves {

    class Ellipse : public Curve {
    public:
        Ellipse(double radiusX, double radiusY);

        Point3D getPoint(double t) const override;
        Vector3D getDerivative(double t) const override;

    private:
        double radiusX_;
        double radiusY_;
    };

}