#pragma once

/// Represents a Rigid body
class RigidBody {

private:
  // pose of the rigid body
  gl::A3 pose_{};

public:
  // getter function
  void set_pose(gl::A3 &pose);

  void set_trans(gl::V3 pos);

  void set_rot(gl::Q quat);

  // getter functions
  auto &pose() { return pose_; }

  auto &position() { return pose_.translation(); }

  auto &orientationR() { return pose_.rotation(); }
}