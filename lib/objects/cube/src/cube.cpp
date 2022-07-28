#include "cube.hpp"
#include <iostream>

Cube::Cube(const gl::V3 coord, const float length) {

  global_pose_ = gl::A3::Identity();
  global_pose_.translation() = coord;

  length_ = length;

  // set vertices
  vertices_ = Eigen::Matrix3Xf::Zero(3, 8);

  vertices_ << -1.0f, -1.0f, 1.0f, -1.0f, -1.0f, -1.0f, 1.0f, -1.0f, -1.0f,
      1.0f, -1.0f, 1.0f, -1.0f, 1.0f, 1.0f, -1.0f, 1.0f, -1.0f, 1.0f, 1.0f,
      -1.0f, 1.0f, 1.0f, 1.0f;

  //   // set indices

  indices_ = Eigen::Matrix3Xi::Zero(3, 12);

  indices_ << 0, 1, 2, 0, 2, 3, 0, 4, 7, 0, 7, 3, 3, 7, 6, 3, 6, 2, 2, 6, 5, 2,
      5, 1, 1, 5, 4, 1, 4, 0, 4, 5, 6, 4, 6, 7;

  set_vertex_buffers();
}
