#pragma once
#include "type_aliases.hpp"
#include <cmath>

namespace gl {

inline float deg2rad(const float angle) { return (gl::pi / 180.0f) * angle; };

inline float rad2deg(const float angle) { return (180.0f / gl::pi) * angle; };
} // namespace gl
