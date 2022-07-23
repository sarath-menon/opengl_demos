#pragma once
#include "gl_common.hpp"
#include <GLFW/glfw3.h>

class Camera {

private:
  GLFWwindow *handle_{};

  gl::V3 coord_{};

public:
  Camera(const gl::V3 &coord);

  // set camera coordinates
  void set_coord(const gl::V3 &coord);

  // getter functions
  auto getHandle() const { return handle_; }

  auto coord() const { return coord_; }

  auto x() const { return coord_(0); }
  auto y() const { return coord_(1); }
  auto z() const { return coord_(2); }
};