#include "VAO.h"
#include "VBO.h"
#include "glfw_helper.hpp"
#include "shader.hpp"
#include "triangle.hpp"

int main() {

  GLFWHelper glfw_helper;

  auto window = glfw_helper.get_window();

  Shader shader;

  std::array<std::array<float, 2>, 3> vertices = {
      {{-0.5f, -0.5f * float(sqrt(3)) / 3},
       {0.5f, -0.5f * float(sqrt(3)) / 3},
       {0.0f, 0.5f * float(sqrt(3)) * 2 / 3}}};

  Triangle triangle(vertices);

  // Generates Vertex Array Object and binds it
  VAO VAO1;
  VAO1.Bind();

  // Generates Vertex Buffer Object and links it to vertices
  VBO VBO1(triangle.get_vertices(), sizeof(triangle.get_vertices()));
  // Links VBO to VAO
  VAO1.LinkVBO(VBO1, 0);
  // Unbind all to prevent accidentally modifying them
  VAO1.Unbind();
  VBO1.Unbind();

  //  Render loop: show window till close button is pressed
  while (!glfwWindowShouldClose(window)) {

    // Inputs
    glfw_helper.processInput(window);

    // Display
    glfw_helper.display(shader, glfwGetTime());

    // Load the compiled shaders to the GPU
    shader.Activate();

    // Bind the VAO so OpenGL knows to use it
    VAO1.Bind();

    // Start drawing-GLSL pipeline starts (primitive,start vertex, vertex count)
    glDrawArrays(GL_TRIANGLES, 0, 3);

    // Process events~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

    // Swap the back buffer with the front buffer
    glfwSwapBuffers(window);
    // handles window events, such as close button pressed
    glfwPollEvents();
  }

  // Delete all the objects we've created
  VAO1.Delete();
  VBO1.Delete();

  shader.Delete();

  glfw_helper.terminate_window(shader);
  return 0;
}
