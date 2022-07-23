#pragma once

#include <glad/glad.h>
//
#include "shader.hpp"
#include <GLFW/glfw3.h>

class Viewer {

private:
  GLFWwindow *handle_{};

  int width_{};
  int height_{};
  float aspect_ratio_{};

public:
  Viewer(const int width, const int height);
  ~Viewer();

  void clear_display(double current_time);

  void start_display();

  static void framebuffer_size_callback(GLFWwindow *handle, int width,
                                        int height);
  void processInput();

  void terminate();

  // getter functions

  auto getHandle() const { return handle_; }

  auto width() const { return width_; }

  auto height() const { return height_; }

  auto aspect_ratio() const { return aspect_ratio_; }
};