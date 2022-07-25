#pragma once

#include "gl_common.hpp"
#include "rigid3d.hpp"
#include <cmath>

class Pyramid : public Rigid3d {

private:
  // length of each side
  float length_{};

public:
  // Equilateral triangle given starting coord and side length
  Pyramid(const gl::V3 coord, const float length);

  const auto &vertices() const { return vertices_; }

  const auto &texture_coord() const { return texture_coord_; }
};
