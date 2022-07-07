#pragma once
#include "essential_functions.h"

class GLFWHelper {

private:
  GLFWwindow *window{};

public:
  GLFWHelper();

  auto get_window() { return window; }
};