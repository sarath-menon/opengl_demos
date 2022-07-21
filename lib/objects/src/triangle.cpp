#include "triangle.hpp"

// Equilateral triangle
Triangle::Triangle(gl::V3 start, const float length) {

  // coord 1
  vertices_(0, 0) = start(0);
  vertices_(0, 1) = start(1);

  // coord 2
  vertices_(0, 0) += length;
  vertices_(0, 1) = start(1);

  // coord 3
  vertices_(0, 0) += (length / 2);
  vertices_(0, 1) += (sqrt(3) / 2 * length);
};
