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

  Shader shader("shaders/2d_vertShader.glsl", "shaders/2d_fragShader.glsl");

  // create triangles
  Triangle t1(gl::V3(-0.4, -0.4, 0), 1.0);
  Triangle t2(gl::V3(0.4, 0.4, 0), 1.0);

  // vertex array object to prganize vertex buffers
  VAO VA;

  // vertex buffer to be sent to vertex shader
  VBO VB[] = {VBO(t1.vertices()), VBO(t2.vertices())};

  // Activate the VA
  VA.Bind();

  // Link VAO to VBO
  VA.LinkAttrib(VB[0], 0, t1.vertices(), GL_FLOAT);
  VA.LinkAttrib(VB[1], 1, t2.vertices(), GL_FLOAT);

  // Unbind all to prevent accidentally modifying them
  VA.Unbind();
  VB[0].Unbind();
  VB[1].Unbind();

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

    // Bind the VAO so OpenGL knows to use it
    VA.Bind();

    // send data in vertex buffer to the shader and start drawing
    // (primitive,start vertex, vertex count)
    glDrawArrays(GL_TRIANGLES, 0, 3);

    // Process events~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

    // Swap the back buffer with the front buffer
    glfwSwapBuffers(window);
    // handles window events, such as close button pressed
    glfwPollEvents();
  }

  glfw_helper.terminate_window(shader);
  return 0;
}
