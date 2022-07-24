#pragma once
#include <cmath>

namespace gl {

float deg2rad(const float angle) { return (M_PI / 180.0) * angle; };

float rad2deg(const float angle) { return (180.0 / M_PI) * angle; };
} // namespace gl
