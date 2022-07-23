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

  Shader shader("shaders/2d_vertShader.glsl", "shaders/2d_fragShader.glsl");

  // create triangles
  Triangle t1(gl::V3(-0.4, -0.4, 0), 1.0);

  // vertex array object to prganize vertex buffers
  VAO VA;

  // vertex buffer to be sent to vertex shader
  VBO vb[2];
  vb[0].set_data(t1.vertices());

  // Gets ID of uniform called "scale"
  GLuint uniID = glGetUniformLocation(shader.getHandle(), "scale");

  //  Render loop: show window till close button is pressed
  while (!glfwWindowShouldClose(viewer.getHandle())) {
    // Inputs
    viewer.processInput();

    // Load the compiled shaders to the GPU
    shader.Activate();

    // Link VAO to VBO
    VA.LinkAttrib(vb[0], 0, t1.vertices(), GL_FLOAT);

    viewer.clear_display(glfwGetTime());

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
