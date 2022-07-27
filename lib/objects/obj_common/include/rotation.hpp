#pragma once

#include "gl_common.hpp"
#include <cmath>

enum class axis { x, y, z };

class Rot {

private:
  // Rot matrices
  inline static gl::M3 R;

public:
  static void axis(gl::A3 &pose, axis ax, const float angle);
};
