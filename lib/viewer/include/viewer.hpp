#pragma once

#include <glad/glad.h>
//
#include "gl_common.hpp"
#include <GLFW/glfw3.h>

class Viewer {

private:
  GLFWwindow *handle_{};

  // default parameters
  int width_ = 600;
  int height_ = 600;

  float clear_colour_[4] = {0.2f, 0.3f, 0.3f, 1.0f};

  // derived parameters
  float aspect_ratio_{};

public:
  Viewer(const int width, const int height);
  ~Viewer();

  void clear_display(double current_time) const;

  void start_display() const;

  // static void framebuffer_size_callback(GLFWwindow *handle, int width,
  //                                       int height);
  void processInput() const;

  void terminate() const;

  // getter functions

  const auto getHandle() const { return handle_; }

  const auto width() const { return width_; }

  const auto height() const { return height_; }

  const auto aspect_ratio() const { return aspect_ratio_; }
};