#pragma once
#include "shader.hpp"
#include <GLFW/glfw3.h>

class Viewer {

private:
  GLFWwindow *handle_{};

public:
  Viewer(const int width, const int height);

  auto getHandle() const { return handle_; }

  void display(Shader &shader, double current_time);

  static void framebuffer_size_callback(GLFWwindow *handle, int width,
                                        int height);
  void processInput();

  void terminate();
};