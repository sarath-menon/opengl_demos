#pragma once

#include "gl_common.hpp"
#include "rigid3d.hpp"
#include <cmath>

class Cube : public Rigid3d {

private:
  // gl::A3 pose_{};

  // length of each side
  float length_{};

  gl::M3DC vertices_;

public:
  // // getter function
  // void set_pose(gl::A3 &pose);

  // void set_trans(gl::V3 pos);

  // void set_rot(gl::Q quat);

  void rot_x(float angle);

  // Equilateral triangle given starting coord and side length
  Cube(const gl::V3 coord, const float length);

  // getter functions
  // auto &pose() { return pose_; }

  auto &vertices() { return vertices_; }
};
