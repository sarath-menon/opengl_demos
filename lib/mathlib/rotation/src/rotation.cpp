#include "rotation.hpp"
#include <iostream>

void Rot::axis(gl::A3 &pose, enum axis ax, const float angle) {

  // Rotating a rigid body at an arbitraty position by multiplting a
  // homogeneous transformation matrix requires moving it to the origin before
  // rotating and back to original position after rotating. Otherwise, the rigid
  // body rotates about the prigin

  gl::V3 current_pos = pose.translation();

  R = gl::M3::Identity();

  switch (ax) {

  case axis::x:
    R.row(1) << 0.0f, cos(angle), -sin(angle);
    R.row(2) << 0.0f, sin(angle), cos(angle);
    break;
  case axis::y:
    R.row(0) << cos(angle), 0.0f, -sin(angle);
    R.row(2) << sin(angle), 0.0f, cos(angle);
    break;
  case axis::z:
    R.row(0) << cos(angle), -sin(angle), 0.0f;
    R.row(1) << sin(angle), cos(angle), 0.0f;
    break;
  }

  // apply rotation
  pose = R * pose.rotation();

  // set original position
  pose.translation() = current_pos;

  // std::cout << "Current pos:" << pose.translation() << '\n';
}
