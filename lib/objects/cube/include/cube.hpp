#pragma once
//
#include <glad/glad.h>
//
#include "gl_common.hpp"
#include <array>
#include <cmath>
#include <glm/glm.hpp>
#include <string>

class Cube {

private:
  gl::M3 coord_{};

public:
  // Equilateral triangle given starting coord and side length
  Cube(const gl::V3 coord, const float length);

  auto &vertices() { return coord_; }
};

// vertices << -0.5f, -0.5f * float(sqrt(3)) / 3, 0.0f, // Lower left corner
//       0.5f, -0.5f * float(sqrt(3)) / 3, 0.0f,          // Lower right corner
//       0.0f, 0.5f * float(sqrt(3)) * 2 / 3, 0.0f;       // Upper corner
