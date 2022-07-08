#include "glfw_helper.hpp"
#include "shader.hpp"
#include "triangle.hpp"

int main() {

  // create vertex buffer, array (Attributes - position(4D), color, texture etc)
  struct VAO vao;

  GLFWHelper glfw_helper;

  auto window = glfw_helper.get_window();

  std::array<std::array<float, 2>, 3> vertices = {
      {{-0.5f, -0.5f * float(sqrt(3)) / 3},
       {0.5f, -0.5f * float(sqrt(3)) / 3},
       {0.0f, 0.5f * float(sqrt(3)) * 2 / 3}}};

  Triangle triangle(vertices, vao);

  Shader shader(vao);
  auto shaderProgram = shader.get_shader_program();

  //  Render loop: show window till close button is pressed
  while (!glfwWindowShouldClose(window)) {

    // Inputs
    glfw_helper.processInput(window);

    // Display
    glfw_helper.display(shader.get_shader_program(), glfwGetTime());

    // Process events~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

    // Swap the back buffer with the front buffer
    glfwSwapBuffers(window);
    // handles window events, such as close button pressed
    glfwPollEvents();
  }

  glfw_helper.terminate_window(shaderProgram, vao);
  return 0;
}
