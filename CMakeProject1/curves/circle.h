#pragma once
#include "Curve.h"

namespace curves {

    class Circle : public Curve {
    public:
        explicit Circle(double radius);

        Point3D getPoint(double t) const override;
        Vector3D getDerivative(double t) const override;

        double getRadius() const;

    private:
        double radius_;
    };

}