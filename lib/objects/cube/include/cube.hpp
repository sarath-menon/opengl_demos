#pragma once
//
#include <glad/glad.h>
//
#include "gl_common.hpp"
#include <array>
#include <cmath>
#include <glm/glm.hpp>
#include <string>

class Triangle {

private:
  gl::M3 vertices_{};

public:
  // Equilateral triangle given starting coord and side length
  Triangle(const gl::V3 start, const float length);

  // all 3 coordinates given
  Triangle(const gl::V3 c1, const gl::V3 c2, const gl::V3 c3);

  auto &vertices() { return vertices_; }
};

// vertices << -0.5f, -0.5f * float(sqrt(3)) / 3, 0.0f, // Lower left corner
//       0.5f, -0.5f * float(sqrt(3)) / 3, 0.0f,          // Lower right corner
//       0.0f, 0.5f * float(sqrt(3)) * 2 / 3, 0.0f;       // Upper corner
