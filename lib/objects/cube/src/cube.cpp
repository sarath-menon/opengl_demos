#include "cube.hpp"
#include <iostream>

Cube::Cube(const gl::V3 coord, const float length) {

  pose_ = gl::A3::Identity();

  pose_.translation() = coord;
  length_ = length;

  // set vertices
  vertices_ = Eigen::Matrix3Xf::Zero(3, 36);

  vertices_ << -1.0f, 1.0f, -1.0f, -1.0f, -1.0f, -1.0f, 1.0f, -1.0f, -1.0f,
      1.0f, -1.0f, -1.0f, 1.0f, 1.0f, -1.0f, -1.0f, 1.0f, -1.0f, 1.0f, -1.0f,
      -1.0f, 1.0f, -1.0f, 1.0f, 1.0f, 1.0f, -1.0f, 1.0f, -1.0f, 1.0f, 1.0f,
      1.0f, 1.0f, 1.0f, 1.0f, -1.0f, 1.0f, -1.0f, 1.0f, -1.0f, -1.0f, 1.0f,
      1.0f, 1.0f, 1.0f, -1.0f, -1.0f, 1.0f, -1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f,
      -1.0f, -1.0f, 1.0f, -1.0f, -1.0f, -1.0f, -1.0f, 1.0f, 1.0f, -1.0f, -1.0f,
      -1.0f, -1.0f, 1.0f, -1.0f, -1.0f, 1.0f, 1.0f, -1.0f, -1.0f, 1.0f, 1.0f,
      -1.0f, 1.0f, 1.0f, -1.0f, -1.0f, 1.0f, -1.0f, -1.0f, -1.0f, -1.0f, -1.0f,
      -1.0f, -1.0f, 1.0f, -1.0f, 1.0f, -1.0f, 1.0f, 1.0f, -1.0f, 1.0f, 1.0f,
      1.0f, 1.0f, 1.0f, 1.0f, -1.0f, 1.0f, 1.0f, -1.0f, 1.0f, -1.0f;
}

void Cube::set_pose(gl::A3 &pose) { pose_ = pose; }

void Cube::set_trans(gl::V3 pos) { pose_.translation() = pos; }

void Cube::set_rot(gl::Q quat) { pose_.linear() = quat.toRotationMatrix(); }

void Cube::rot_x(float angle) {

  gl::A3 R = gl::A3::Identity();

  gl::M3 temp;
  temp << 1.0f, 0.0f, 0.0f, 0.0f, cos(angle), -sin(angle), 0.0f, sin(angle),
      cos(angle);

  R.linear() = temp;

  //   std::cout << R.rotation() << '\n';

  pose_ = R * pose_;
}
