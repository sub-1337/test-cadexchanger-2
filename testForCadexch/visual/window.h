#pragma once
#include <string>
#include <vector>
#include <memory>
#include "../curves/curve.h"
#include "../curves/circle.h"
#include "../curves/ellipse.h"
#include "../curves/helix.h"

using namespace curves;

void openVisualWindow(const std::vector<std::shared_ptr<Curve>>& curvesContainer, std::string log);