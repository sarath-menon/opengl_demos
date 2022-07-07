#pragma once
#include "essential_functions.h"

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