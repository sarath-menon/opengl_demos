#include "triangle.hpp"
#include <iostream>

Triangle::Triangle(gl::V3 c1, const float length) {

  vertices_ = Eigen::Matrix3f::Identity();

  // c 1
  vertices_(0, 0) = c1(0);
  vertices_(0, 1) = c1(1);

  // c 2
  vertices_(1, 0) = c1(0) + length;
  vertices_(1, 1) = c1(1);

  // c 3
  vertices_(2, 0) = c1(0) + (length / 2);
  vertices_(2, 1) = c1(1) + (sqrt(3) / 2 * length);
};

Triangle::Triangle(const gl::V3 c1, const gl::V3 c2, const gl::V3 c3) { // c 1
  vertices_(0, 0) = c1(0);
  vertices_(0, 1) = c1(1);

  // c 2
  vertices_(1, 0) = c2(0);
  vertices_(1, 1) = c2(1);

  // c 3
  vertices_(2, 0) = c3(0);
  vertices_(2, 1) = c3(1);
}