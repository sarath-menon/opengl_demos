#pragma once
#include "gl_common.hpp"
#include <GLFW/glfw3.h>

class Camera {

private:
  GLFWwindow *handle_{};

  gl::V3 coord_{};

public:
  Camera(const int width, const int height);

  // getter functions

  auto getHandle() const { return handle_; }
};