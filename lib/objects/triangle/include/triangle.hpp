#pragma once
//
#include <glad/glad.h>
//
#include "gl_common.hpp"
#include <array>
#include <cmath>
#include <glm/glm.hpp>
#include <memory>
#include <string>

class Triangle {

private:
  gl::M3DR vertices_;

public:
  // Equilateral triangle given starting coord and side length
  Triangle(const gl::V3 start, const float length);

  // all 3 coordinates given
  Triangle(const gl::V3 c1, const gl::V3 c2, const gl::V3 c3);

  const auto &vertices() { return vertices_; }
};
