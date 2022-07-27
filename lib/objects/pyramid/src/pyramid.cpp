#include "pyramid.hpp"
#include <iostream>

Pyramid::Pyramid(const gl::V3 coord, const float length) {

  global_pose_ = gl::A3::Identity();
  global_pose_.translation() = coord;

  length_ = length;

  // set vertices and texture coordinates
  vertices_ = Eigen::Matrix3Xf::Zero(3, 16);

  vertices_ << -0.5f, 0.0f, 0.5f, -0.5f, 0.0f, -0.5f, 0.5f, 0.0f, -0.5f, 0.5f,
      0.0f, 0.5f, -0.5f, 0.0f, 0.5f, -0.5f, 0.0f, -0.5f, 0.0f, 0.8f, 0.0f,
      -0.5f, 0.0f, -0.5f, 0.5f, 0.0f, -0.5f, 0.0f, 0.8f, 0.0f, 0.5f, 0.0f,
      -0.5f, 0.5f, 0.0f, 0.5f, 0.0f, 0.8f, 0.0f, 0.5f, 0.0f, 0.5f, -0.5f, 0.0f,
      0.5f, 0.0f, 0.8f, 0.0f;

  // set texture coordinates
  texture_coord_ = Eigen::Matrix2Xf::Zero(2, 16);

  texture_coord_ << 0.0f, 0.0f, 0.0f, 5.0f, 5.0f, 5.0f, 5.0f, 0.0f, 0.0f, 0.0f,
      5.0f, 0.0f, 2.5f, 5.0f, 2.5f, 5.0f, 0.0f, 0.0f, 2.5f, 5.0f, 0.0f, 0.0f,
      5.0f, 0.0f, 2.5f, 5.0f, 5.0f, 0.0f, 0.0f, 0.0f, 2.5f, 5.0f;

  //  set indices
  indices_ = Eigen::Matrix3Xi::Zero(3, 6);

  indices_ << 0, 1, 2, // Bottom side
      0, 2, 3,         // Bottom side
      4, 6, 5,         // Left side
      7, 9, 8,         // Non-facing side
      10, 12, 11,      // Right side
      13, 15, 14;      // Facing side;
}
