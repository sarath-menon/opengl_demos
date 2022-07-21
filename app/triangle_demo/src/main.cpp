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

  Triangle t1(gl::V3(0, 0, 0), 1.0);

  // Generates Vertex Array Object
  VAO VAO1;

  // Generates Vertex Buffer Object and links it to vertices
  VBO VBO1(t1.vertices());

  // Links VAO and link to VBO
  VAO1.Bind();
  VAO1.LinkAttrib(VBO1, 0, t1.vertices(), GL_FLOAT);

  // Unbind all to prevent accidentally modifying them
  VAO1.Unbind();
  VBO1.Unbind();

  // Gets ID of uniform called "scale"
  GLuint uniID = glGetUniformLocation(shader.get_program(), "scale");

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
