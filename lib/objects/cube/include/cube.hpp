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
  gl::V3 coord_;

  // length of each side
  float length_{};

  gl::M3DC vertices_;

public:
  // Equilateral triangle given starting coord and side length
  Cube(const gl::V3 coord, const float length);

  // getter functions
  auto &coord() { return coord_; }

  auto &vertices() { return vertices_; }
};
