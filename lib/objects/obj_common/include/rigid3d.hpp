#pragma once

#include "gl_common.hpp"
#include "rotation.hpp"
#include <cmath>

/// Represents a Rigid body
class Rigid3d {

protected:
  // pose of the rigid body
  gl::A3 local_pose_{};

public:
  // getter function
  void set_local_pose(const gl::A3 &pose);

  void set_local_position(const gl::V3 pos);

  void set_local_orientation(const gl::Q quat);

  void local_rotate_x(const float angle);
  void local_rotate_y(const float angle);
  void local_rotate_z(const float angle);

  // getter functions
  auto &local_pose() { return local_pose_; }

  auto local_position() { return local_pose_.translation(); }

  auto orientationR() { return local_pose_.rotation(); }
};

