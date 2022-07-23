#pragma once

#include "gl_common.hpp"
#include <cmath>

enum class axis { x, y, z };

class Rot {

private:
  // Rot matrices
  gl::M3 R_x = gl::M3::Identity();
  gl::M3 R_y = gl::M3::Identity();
  gl::M3 R_z = gl::M3::Identity();

public:
  Rot();

  void axis(axis ax, const float angle);
};
