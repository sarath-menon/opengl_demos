#include "glfw_helper.hpp"
#include <iostream>

GLFWHelper::GLFWHelper() {

  // Initialize GLFW
  if (!glfwInit()) {
    exit(EXIT_FAILURE);
  }

  // Set opengl version
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);

  // use opengl core (modern) profile
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

// macos extras for glfw
#ifdef __APPLE__
  glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif

  // Parameters: width, height, windowname, full screen, resource sharing
  window = glfwCreateWindow(800, 800, "LearnOpenGL", NULL, NULL);

  // Error check for safety
  if (window == NULL) {
    std::cout << "Failed to create GLFW window" << std::endl;
    glfwTerminate();
    // return -1;
  }

  // Make window part of current context
  glfwMakeContextCurrent(window);

  // the number of screen updates to wait from the time glfwSwapBuffers was
  // called before swapping the buffers and returning.
  glfwSwapInterval(1);

  // Load glad with error checking
  if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
    std::cout << "Failed to initialize GLAD" << std::endl;
    // return -1;
  }

  // Set widnow area for rendering
  glViewport(0, 0, 800, 800);
  glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
}

// Callback definition
void GLFWHelper::framebuffer_size_callback(GLFWwindow *window, int width,
                                           int height) {
  glViewport(0, 0, width, height);
}

// close window when esc key pressed
void GLFWHelper::processInput(GLFWwindow *window) {
  if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
    glfwSetWindowShouldClose(window, true);
}

void GLFWHelper::display(GLuint shaderProgram, double current_time) {

  // Load the compiled shaders to the GPU
  glUseProgram(shaderProgram);

  // set clear (reset) colour
  glClearColor(0.2f, 0.3f, 0.3f, 1.0f);

  // set clear colour to front buffer
  glClear(GL_COLOR_BUFFER_BIT);

  // Start drawing-GLSL pipeline starts (primitive,start vertex, vertex count)
  glDrawArrays(GL_TRIANGLES, 0, 3);
}

void GLFWHelper::terminate_window(GLuint shaderProgram, VAO &vao) {

  // Delete all the objects we've created
  glDeleteVertexArrays(1, &vao.a);
  glDeleteBuffers(1, &vao.b);
  glDeleteProgram(shaderProgram);

  // Delete window before ending the program
  glfwDestroyWindow(window);
  // Terminate GLFW before ending the program
  glfwTerminate();
}