#include "pyramid.hpp"
#include <iostream>

Pyramid::Pyramid(const gl::V3 coord, const float length) {

  global_pose_ = gl::A3::Identity();
  global_pose_.translation() = coord;

  length_ = length;

  // set vertices and texture coordinates
  vertices_ = gl::M3DR::Zero(3, 5);

  vertices_ << -1.0f, 0.0f, 1.0f, -1.0f, 0.0f, -1.0f, 1.0f, 0.0f, -1.0f, 1.0f,
      0.0f, 1.0f, 0.0f, 1.5f, 0.0f;

  // set texture coordinates
  texture_coord_ = gl::M2DR ::Zero(2, 5);

  texture_coord_ << 0.0f, 0.0f, 5.0f, 0.0f, 0.0f, 0.0f, 5.0f, 0.0f, 2.5f, 5.0f;

  //  set indices
  indices_ = Eigen::Matrix3Xi::Zero(3, 6);

  indices_ << 0, 1, 2, 0, 2, 3, 0, 1, 4, 1, 2, 4, 2, 3, 4, 3, 0, 4;
}
