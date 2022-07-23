#pragma once

#include "gl_common.hpp"
#include "rigid3d.hpp"
#include <cmath>

class Cube : public Rigid3d {

private:
  // gl::A3 pose_{};

  // length of each side
  float length_{};

  gl::M3DC vertices_;

public:
  // Equilateral triangle given starting coord and side length
  Cube(const gl::V3 coord, const float length);

  auto &vertices() { return vertices_; }
};
