#pragma once

#include "gl_common.hpp"
#include "rotation.hpp"
#include <cmath>

/// Represents a Rigid body
class SimpleModel {

protected:
  // geometry parameters -----------

  // pose of the rigid body
  gl::A3 global_pose_{};

  // one (x,y,z) position coordinate per row
  gl::M3DR vertices_;
  // for vertext ordering, one per row
  gl::M3IDR indices_;

  float scale_{};

  // appearance parameters -----------

  // one (u,v) texture coordinate per row
  gl::M2DR texture_coord_;
  // one (x,y,z) normal vector per row
  gl::M3DR normals_;

public:
  // set global parameters -----------
  void set_global_pose(const gl::A3 &pose);
  void set_global_position(const gl::V3 pos);
  void set_global_orientation(const gl::Q quat);

  void global_rotate_x(const float angle);
  void global_rotate_y(const float angle);
  void global_rotate_z(const float angle);

  void set_scale(const float scale);

  // getter functions
  const auto &global_pose() const { return global_pose_; }

  const auto global_position() const { return global_pose_.translation(); }

  const auto orientationR() const { return global_pose_.rotation(); }

  const auto &vertices() const { return vertices_; }

  const auto &normals() const { return normals_; }

  const auto &indices() const { return indices_; }

  const auto &scale() const { return scale_; }

  const auto &texture_coord() const { return texture_coord_; }
};
