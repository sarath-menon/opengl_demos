#include "VAO.hpp"
#include "VBO.hpp"
#include "camera.hpp"
#include "cube.hpp"
#include "shader.hpp"
#include "stb_image.h"
#include "triangle.hpp"
#include "viewer.hpp"

int main() {

  Viewer viewer(720, 480);
  Camera camera(gl::V3(0.0, 0.0, 8.0));

  Shader shader("shaders/3d_vertShader.glsl", "shaders/3d_fragShader.glsl");

  Cube cube(gl::V3(0.0, -2.0, 0.0), 1.0);

  // vertex array object to prganize vertex buffers
  VAO VA;

  // vertex buffer to be sent to vertex shader
  VBO VB[] = {VBO(cube.vertices())};

  // Activate the VA
  VA.Bind();

  // Link VAO to VBO
  VA.LinkAttrib(VB[0], 0, cube.vertices(), GL_FLOAT);

  // Unbind all to prevent accidentally modifying them
  VA.Unbind();
  VB[0].Unbind();

  // to hold id'd of uniform variables
  GLuint model_loc, view_loc, proj_loc;

  // setup matrices
  gl::A3 model_m = gl::A3::Identity();
  gl::A3 view_m = gl::A3::Identity();
  gl::A3 proj_m = gl::A3::Identity();
  gl::A3 mv_m = gl::A3::Identity();

  //  Render loop: show window till close button is pressed
  while (!glfwWindowShouldClose(viewer.getHandle())) {
    // Inputs
    viewer.processInput();

    // Display
    viewer.display(shader, glfwGetTime());

    // Load the compiled shaders to the GPU
    shader.Activate();

    // Draw cube ////////////////////////////////

    // get the uniform variables for the matrices
    model_loc = glGetUniformLocation(shader.getHandle(), "model");
    view_loc = glGetUniformLocation(shader.getHandle(), "view");
    proj_loc = glGetUniformLocation(shader.getHandle(), "proj");

    // build perspective matrix
    proj_m =
        gl::perspective(gl::deg2rad(60.0f), viewer.aspect_ratio(), 0.1, 100.0);

    // build view,model matrices
    view_m = view_m.translate(-camera.coord());
    model_m = view_m.translate(cube.coord());

    // move the whole world w.r.t the fixed camera
    mv_m = view_m * model_m;

    glUniformMatrix4fv(model_loc, 1, GL_FALSE, model_m.data());
    glUniformMatrix4fv(proj_loc, 1, GL_FALSE, proj_m.data());

    // Bind the VAO so OpenGL knows to use it
    VA.Bind();

    // send data in vertex buffer to the shader and start drawing
    // adjust OpenGL settings and draw model
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LEQUAL);
    glDrawArrays(GL_TRIANGLES, 0, 36);

    // Process events~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

    // Swap the back buffer with the front buffer
    glfwSwapBuffers(viewer.getHandle());
    // handles window events, such as close button pressed
    glfwPollEvents();
  }

  viewer.terminate();
  return 0;
}
