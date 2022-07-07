#include "glfw_helper.hpp"
#include "shader.hpp"
#include "triangle.hpp"

int main() {

  GLFWHelper glfw_helper;
  Shader shader;

  std::array<float, 9> vertices = {
      -0.5f, -0.5f * float(sqrt(3)) / 3,
      0.0f, // Lower left corner
      0.5f,  -0.5f * float(sqrt(3)) / 3,
      0.0f, // Lower right corner
      0.0f,  0.5f * float(sqrt(3)) * 2 / 3,
      0.0f // Upper corner
  };

  Triangle triangle(vertices);

  auto window = glfw_helper.get_window();
  auto shaderProgram = shader.get_shader_program();

  auto VAO = triangle.get_vao();
  auto VBO = triangle.get_vbo();

  // ------------------------------------------------------------------------------

  //  Render loop: show window till close button is pressed
  while (!glfwWindowShouldClose(window)) {

    // Inputs
    glfw_helper.processInput(window);

    // rendering commands here~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

    // set colour
    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
    // set back buffer colour
    glClear(GL_COLOR_BUFFER_BIT);

    // Process events~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

    // Tell OpenGL which Shader Program we want to use
    glUseProgram(shaderProgram);
    // Bind the VAO so OpenGL knows to use it
    glBindVertexArray(VAO);
    // Draw the triangle using the GL_TRIANGLES primitive
    glDrawArrays(GL_TRIANGLES, 0, 3);
    // Swap the back buffer with the front buffer
    glfwSwapBuffers(window);

    // process events, such as close button pressed
    glfwPollEvents();
  }

  // Delete all the objects we've created
  glDeleteVertexArrays(1, &VAO);
  glDeleteBuffers(1, &VBO);
  glDeleteProgram(shaderProgram);
  // Delete window before ending the program
  glfwDestroyWindow(window);
  // Terminate GLFW before ending the program
  glfwTerminate();
  return 0;
}
