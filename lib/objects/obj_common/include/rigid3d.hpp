#pragma once

#include "gl_common.hpp"
#include "rotation.hpp"
#include <cmath>

/// Represents a Rigid body
class Rigid3d {

protected:
  // global parameters -----------

  // pose of the rigid body
  gl::A3 global_pose_{};

  // one (x,y,z) position coordinate per row
  gl::M3DC vertices_;
  // one (u,v) texture coordinate per row
  gl::M2DC texture_coord_;
  // one (x,y,z) normal vector per row
  gl::M3DC normals_;

public:
  // set global parameters -----------
  void set_global_pose(const gl::A3 &pose);

  void set_global_position(const gl::V3 pos);

  void set_global_orientation(const gl::Q quat);

  void global_rotate_x(const float angle);
  void global_rotate_y(const float angle);
  void global_rotate_z(const float angle);

  // getter functions
  auto &global_pose() const { return global_pose_; }

  auto global_position() const { return global_pose_.translation(); }

  auto orientationR() const { return global_pose_.rotation(); }
};
