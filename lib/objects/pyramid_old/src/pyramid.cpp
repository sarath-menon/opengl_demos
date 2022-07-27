#include "pyramid.hpp"
#include <iostream>

Pyramid::Pyramid(const gl::V3 coord, const float length) {

  global_pose_ = gl::A3::Identity();
  global_pose_.translation() = coord;

  length_ = length;

  // set vertices and texture coordinates
  vertices_ = Eigen::Matrix3Xf::Zero(3, 18);
  texture_coord_ = Eigen::Matrix2Xf::Zero(2, 18);

  vertices_ << -1.0f, -1.0f, 1.0f, 1.0f, -1.0f, 1.0f, 0.0f, 1.0f, 0.0f, 1.0f,
      -1.0f, 1.0f, 1.0f, -1.0f, -1.0f, 0.0f, 1.0f, 0.0f, 1.0f, -1.0f, -1.0f,
      -1.0f, -1.0f, -1.0f, 0.0f, 1.0f, 0.0f, -1.0f, -1.0f, -1.0f, -1.0f, -1.0f,
      1.0f, 0.0f, 1.0f, 0.0f, -1.0f, -1.0f, -1.0f, 1.0f, -1.0f, 1.0f, -1.0f,
      -1.0f, 1.0f, 1.0f, -1.0f, 1.0f, -1.0f, -1.0f, -1.0f, 1.0f, -1.0f, -1.0f;

  texture_coord_ << 0.0f, 0.0f, 1.0f, 0.0f, 0.5f, 1.0f, 0.0f, 0.0f, 1.0f, 0.0f,
      0.5f, 1.0f, 0.0f, 0.0f, 1.0f, 1.0f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f, 0.0f,
      0.5f, 1.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.5f, 1.0f, 1.0f, 1.0f, 0.0f, 0.0f,
      1.0f, 0.0f;
}
