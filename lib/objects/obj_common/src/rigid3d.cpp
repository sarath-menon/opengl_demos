#include "rigid3d.hpp"

void Rigid3d::set_pose(const gl::A3 &pose) { pose_ = pose; }

void Rigid3d::set_position(const gl::V3 pos) { pose_.translation() = pos; }

void Rigid3d::set_orientation(const gl::Q quat) {
  pose_.linear() = quat.toRotationMatrix();
}

void Rigid3d::rotate_x(const float angle) { Rot::axis(pose_, axis::x, angle); }

void Rigid3d::rotate_y(const float angle) { Rot::axis(pose_, axis::y, angle); }

void Rigid3d::rotate_z(const float angle) { Rot::axis(pose_, axis::z, angle); }
