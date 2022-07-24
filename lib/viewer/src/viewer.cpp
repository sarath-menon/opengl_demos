#include "viewer.hpp"
#include <iostream>

Viewer::Viewer(const int width, const int height) {

  // safety checks
  assert(width > 0 && height > 0);

  // set parameters
  width_ = width;
  height_ = height;

  aspect_ratio_ = static_cast<float>(width) / static_cast<float>(height);

  // Initialize GLFW
  if (!glfwInit()) {
    exit(EXIT_FAILURE);
  }

  // Set opengl version
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);

  // use opengl core (modern) profile
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

// macos extras for glfw
#ifdef __APPLE__
  glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif

  // Parameters: width, height, windowname, full screen, resource sharing
  handle_ = glfwCreateWindow(width, height, "LearnOpenGL", NULL, NULL);

  // Error check for safety
  if (handle_ == NULL) {
    std::cout << "Failed to create GLFW window" << std::endl;
    glfwTerminate();
    // return -1;
  }

  // Make window part of current context
  glfwMakeContextCurrent(handle_);

  // the number of screen updates to wait from the time glfwSwapBuffers was
  // called before swapping the buffers and returning.
  glfwSwapInterval(1);

  // Load glad with error checking
  if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
    std::cout << "Failed to initialize GLAD" << std::endl;
    // return -1;
  }

  // enable depth
  glEnable(GL_DEPTH_TEST);
  glDepthFunc(GL_LEQUAL);

  // // Set widnow area for rendering
  // glViewport(0, 0, width, height);
  // glfwSetFramebufferSizeCallback(handle_, framebuffer_size_callback);
}

Viewer::~Viewer() { terminate(); }

// Callback definition
void Viewer::framebuffer_size_callback(GLFWwindow *handle, const int width,
                                       const int height) {
  glViewport(0, 0, width, height);
}

// close window when esc key pressed
void Viewer::processInput() {
  if (glfwGetKey(handle_, GLFW_KEY_ESCAPE) == GLFW_PRESS)
    glfwSetWindowShouldClose(handle_, true);
}

void Viewer::clear_display(double current_time) {

  // set clear (reset) colour
  glClearColor(clear_colour_[0], clear_colour_[1], clear_colour_[2],
               clear_colour_[3]);

  // set clear colour to front buffer
  glClear(GL_COLOR_BUFFER_BIT);
  glClear(GL_DEPTH_BUFFER_BIT);
}

void Viewer::start_display() {
  // Swap the back buffer with the front buffer
  glfwSwapBuffers(handle_);
  // handles window events, such as close button pressed
  glfwPollEvents();
}

void Viewer::terminate() {

  // Delete window before ending the program
  glfwDestroyWindow(handle_);
  // Terminate GLFW before ending the program
  glfwTerminate();
}
