#pragma once
#include "shader.hpp"
#include <GLFW/glfw3.h>

class Viewer {

private:
  GLFWwindow *window{};

public:
  Viewer(const int width, const int height);

  auto get_window() { return window; }

  void display(Shader &shader, double current_time);

  static void framebuffer_size_callback(GLFWwindow *window, int width,
                                        int height);
  void processInput(GLFWwindow *window);

  void terminate_window();
};