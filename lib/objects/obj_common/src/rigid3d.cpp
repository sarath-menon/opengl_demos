#include "rigid3d.hpp"

void Rigid3d::set_local_pose(const gl::A3 &pose) { local_pose_ = pose; }

void Rigid3d::set_local_position(const gl::V3 pos) {
  local_pose_.translation() = pos;
}

void Rigid3d::set_local_orientation(const gl::Q quat) {
  local_pose_.linear() = quat.toRotationMatrix();
}

void Rigid3d::local_rotate_x(const float angle) {
  Rot::axis(local_pose_, axis::x, angle);
}

void Rigid3d::local_rotate_y(const float angle) {
  Rot::axis(local_pose_, axis::y, angle);
}

void Rigid3d::local_rotate_z(const float angle) {
  Rot::axis(local_pose_, axis::z, angle);
}
