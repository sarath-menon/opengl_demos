#pragma once

#include "gl_common.hpp"
#include <cmath>

namespace gl {
enum class axis { x, y, z };

class Rot {

private:
  // Rot matrices
  static gl::M3 R_x;
  static gl::M3 R_y;
  static gl::M3 R_z;

public:
  Rot();

  static void axis(axis ax, const float angle);
};
} // namespace gl
