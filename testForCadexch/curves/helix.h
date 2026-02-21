#pragma once
#include "curve.h"

namespace curves {

    class Helix : public Curve {
    public:
        Helix(double radius, double step);

        Point3D getPoint(double t) const override;
        Vector3D getDerivative(double t) const override;

    private:
        double radius_;
        double step_;
    };

}