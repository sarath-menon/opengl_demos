#include "essential_functions.h"
#include <iostream>

void framebuffer_size_callback(GLFWwindow *window, int width, int height);
void processInput(GLFWwindow *window);

int main() {
  // // glm test
  // glm::vec4 vec(1.0f, 0.0f, 0.0f, 1.0f);
  // glm::mat4 trans = glm::mat4(1.0f);
  // trans = glm::translate(trans, glm::vec3(1.0f, 1.0f, 0.0f));
  // vec = trans * vec;
  // std::cout << vec.x << '\t' << vec.y << '\t' << vec.z << std::endl;

  glfwInit();
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

#ifdef __APPLE__
  glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif

  // Window  Parameters: width, height,title
  GLFWwindow *window = glfwCreateWindow(800, 800, "LearnOpenGL", NULL, NULL);
  // Error check for safety
  if (window == NULL) {
    std::cout << "Failed to create GLFW window" << std::endl;
    glfwTerminate();
    return -1;
  }

  // Make window part of current context
  glfwMakeContextCurrent(window);

  // Load glad with error checking
  if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
    std::cout << "Failed to initialize GLAD" << std::endl;
    return -1;
  }

  // Set widnow area for rendering
  glViewport(0, 0, 800, 800);
  glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

  // Show window. Render loop
  while (!glfwWindowShouldClose(window)) {

    // Inputs
    processInput(window);

    // rendering commands here~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

    // set colour
    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
    // set back buffer colour
    glClear(GL_COLOR_BUFFER_BIT);

    // Process events~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

    // swap back buffer to see the front buffer
    glfwSwapBuffers(window);
    glfwPollEvents();
  }

  // Close window
  glfwTerminate();
  return 0;
}
