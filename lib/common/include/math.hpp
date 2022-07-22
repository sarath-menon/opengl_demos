#pragma once
#include <cmath>

namespace gl {

template <typename T> T deg2rad(T angle) { return (M_PI / 180.0) * angle; };

template <typename T> T rad2deg(T angle) { return (180.0 / M_PI) * angle; };
} // namespace gl
