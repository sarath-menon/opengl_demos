#include "glfw_helper.hpp"
#include <iostream>

GLFWHelper::GLFWHelper() {
  // Initialize GLFW
  glfwInit();
  // Set opengl version
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);

  // use opengl core (modern) profile
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

// macos extras for glfw
#ifdef __APPLE__
  glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif

  // Window  Parameters: width, height, windowname
  window = glfwCreateWindow(800, 800, "LearnOpenGL", NULL, NULL);

  // Error check for safety
  if (window == NULL) {
    std::cout << "Failed to create GLFW window" << std::endl;
    glfwTerminate();
    // return -1;
  }

  // Make window part of current context
  glfwMakeContextCurrent(window);

  // Load glad with error checking
  if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
    std::cout << "Failed to initialize GLAD" << std::endl;
    // return -1;
  }

  // Set widnow area for rendering
  glViewport(0, 0, 800, 800);
  glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
}