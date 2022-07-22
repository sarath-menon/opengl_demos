#include "VAO.hpp"
#include "VBO.hpp"
#include "shader.hpp"
#include "stb_image.h"
#include "triangle.hpp"
#include "viewer.hpp"
#include <Eigen/Dense>
#include <unsupported/Eigen/OpenGLSupport>

int main() {

  Viewer viewer(720, 480);

  Shader shader("shaders/3d_vertShader.glsl", "shaders/3d_fragShader.glsl");

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
  GLuint uniID = glGetUniformLocation(shader.getHandle(), "scale");

  //  Render loop: show window till close button is pressed
  while (!glfwWindowShouldClose(viewer.getHandle())) {
    // Inputs
    viewer.processInput();

    // Display
    viewer.display(shader, glfwGetTime());

    // Load the compiled shaders to the GPU
    shader.Activate();

    // Draw cube ////////////////////////////////

    gl::A3 model_m = gl::A3::Identity();
    gl::A3 view_m = gl::A3::Identity();
    gl::A3 proj_m = gl::A3::Identity();

    view_m = view_m.translate(gl::V3(0, -0.05, -0.2));
    proj_m =
        gl::perspective(gl::deg2rad(45.0f), viewer.aspect_ratio(), 0.1, 100.0);

    // Bind the VAO so OpenGL knows to use it
    VA.Bind();

    // send data in vertex buffer to the shader and start drawing
    // (primitive,start vertex, vertex count)
    glDrawArrays(GL_TRIANGLES, 0, 3);

    // Process events~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

    // Swap the back buffer with the front buffer
    glfwSwapBuffers(viewer.getHandle());
    // handles window events, such as close button pressed
    glfwPollEvents();
  }

  viewer.terminate();
  return 0;
}
