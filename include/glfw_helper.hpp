#pragma once
#include "include_glad.h"
#include <GLFW/glfw3.h>

class GLFWHelper {

private:
  GLFWwindow *window{};

public:
  GLFWHelper();

  auto get_window() { return window; }

  static void framebuffer_size_callback(GLFWwindow *window, int width,
                                        int height);
  void processInput(GLFWwindow *window);
};