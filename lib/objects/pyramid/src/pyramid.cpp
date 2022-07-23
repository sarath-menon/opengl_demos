#include "pyramid.hpp"
#include <iostream>

Pyramid::Pyramid(const gl::V3 coord, const float length) {

  pose_ = gl::A3::Identity();
  pose_.translation() = coord;

  length_ = length;

  // set vertices
  vertices_ = Eigen::Matrix3Xf::Zero(3, 54);

  vertices_ << -1.0f, -1.0f, 1.0f, 1.0f, -1.0f, 1.0f, 0.0f, 1.0f, 0.0f, 1.0f,
      -1.0f, 1.0f, 1.0f, -1.0f, -1.0f, 0.0f, 1.0f, 0.0f, 1.0f, -1.0f, -1.0f,
      -1.0f, -1.0f, -1.0f, 0.0f, 1.0f, 0.0f, -1.0f, -1.0f, -1.0f, -1.0f, -1.0f,
      1.0f, 0.0f, 1.0f, 0.0f, -1.0f, -1.0f, -1.0f, 1.0f, -1.0f, 1.0f, -1.0f,
      -1.0f, 1.0f, 1.0f, -1.0f, 1.0f, -1.0f, -1.0f, -1.0f, 1.0f, -1.0f, -1.0f;
}
