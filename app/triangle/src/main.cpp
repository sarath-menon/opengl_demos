#include "EBO.hpp"
#include "VAO.hpp"
#include "VBO.hpp"
#include "glfw_helper.hpp"
#include "shader.hpp"
#include "stb_image.h"
#include "triangle.hpp"
#include <Eigen/Dense>
#include <unsupported/Eigen/OpenGLSupport>

constexpr unsigned int width = 800;
constexpr unsigned int height = 800;

int main() {

  GLFWHelper glfw_helper;

  auto window = glfw_helper.get_window();

  Shader shader;

  std::array<std::array<float, 2>, 3> vertices = {
      {{-0.5f, -0.5f * float(sqrt(3)) / 3},
       {0.5f, -0.5f * float(sqrt(3)) / 3},
       {0.0f, 0.5f * float(sqrt(3)) * 2 / 3}}};

  // RGB vertex colours
  std::array<std::array<float, 3>, 3> colours = {
      {{0.8f, 0.3f, 0.02f}, {1.0f, 0.6f, 0.32f}, {0.9f, 0.45f, 0.17f}}};

  Triangle triangle(vertices, colours);

  // Generates Vertex Array Object and binds it
  VAO VAO1;
  VAO1.Bind();

  // Generates Vertex Buffer Object and links it to vertices
  VBO VBO1(triangle.get_vertices(), sizeof(triangle.get_vertices()));

  // Links VBO to VAO
  VAO1.LinkAttrib(VBO1, 0, 3, GL_FLOAT, 6 * sizeof(float), (void *)0);
  VAO1.LinkAttrib(VBO1, 1, 3, GL_FLOAT, 6 * sizeof(float),
                  (void *)(3 * sizeof(float)));

  // Unbind all to prevent accidentally modifying them
  VAO1.Unbind();
  VBO1.Unbind();

  // Gets ID of uniform called "scale"
  GLuint uniID = glGetUniformLocation(shader.get_program(), "scale");

  // Variables that help the rotation of the pyramid
  float rotation = 0.0f;
  double prevTime = glfwGetTime();

  //  Render loop: show window till close button is pressed
  while (!glfwWindowShouldClose(window)) {
    // Inputs
    glfw_helper.processInput(window);

    // Display
    glfw_helper.display(shader, glfwGetTime());

    // Load the compiled shaders to the GPU
    shader.Activate();

    // Set triangle scale (Assigns a value to the uniform); NOTE: Must always be
    // done after activating the Shader Program
    glUniform1f(uniID, 1.5f);

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