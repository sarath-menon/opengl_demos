#pragma once

#include "gl_common.hpp"
#include "rotation.hpp"
#include <cmath>

/// Represents a Rigid body
class Rigid3d {

private:
protected:
  // pose of the rigid body
  gl::A3 pose_{};

public:
  // getter function
  void set_pose(const gl::A3 &pose);

  void set_position(const gl::V3 pos);

  void set_orientation(const gl::Q quat);

  // getter functions
  auto &pose() { return pose_; }

  auto position() { return pose_.translation(); }

  auto orientationR() { return pose_.rotation(); }
};