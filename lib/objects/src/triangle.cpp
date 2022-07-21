#include "triangle.hpp"
#include <iostream>

// Equilateral triangle
Triangle::Triangle(gl::V3 start, const float length) {

  // coord 1
  vertices_(0, 0) = start(0);
  vertices_(0, 1) = start(1);

  // coord 2
  vertices_(1, 0) = start(0) + length;
  vertices_(1, 1) = start(1);

  // coord 3
  vertices_(2, 0) = start(0) + (length / 2);
  vertices_(2, 1) = start(1) + (sqrt(3) / 2 * length);

  std::cout << "Coordinates :" << vertices_(0, 0) << ", " << vertices_(0, 1)
            << ", " << vertices_(1, 0) << ", " << vertices_(1, 1) << ", "
            << vertices_(2, 0) << ", " << vertices_(2, 1) << ", ";
};
