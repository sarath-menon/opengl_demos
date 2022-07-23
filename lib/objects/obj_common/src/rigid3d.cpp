#include "rigid3d.hpp"

void Rigid3d::set_pose(const gl::A3 &pose) { pose_ = pose; }

void Rigid3d::set_position(const gl::V3 pos) { pose_.translation() = pos; }

void Rigid3d::set_rot(const gl::Q quat) {
  pose_.linear() = quat.toRotationMatrix();
}