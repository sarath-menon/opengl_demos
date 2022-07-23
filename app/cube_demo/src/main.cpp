#include "VAO.hpp"
#include "VBO.hpp"
#include "camera.hpp"
#include "cube.hpp"
#include "shader.hpp"
#include "stb_image.h"
#include "triangle.hpp"
#include "viewer.hpp"
#include <iostream>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp> // glm::value_ptr

int main() {

  Viewer viewer(600, 600);
  Camera camera(gl::V3(0.0, 0.0, 8.0));

  // Transformation matrices
  gl::A3 model_m = gl::A3::Identity();
  gl::A3 view_m = gl::A3::Identity();
  gl::A3 modelview_m = gl::A3::Identity();
  glm::mat4 proj_m;

  Shader shader("shaders/3d_vertShader.glsl", "shaders/3d_fragShader.glsl");
  // to hold id's of uniform variables
  GLuint modelview_loc, proj_loc;

  Cube cube(gl::V3(0.0, -2.0, 0.0), 1.0);

  // vertex array object to prganize vertex buffers
  VAO va;

  // vertex buffer to be sent to vertex shader
  VBO vb[2];
  vb[0].set_data(cube.vertices());

  //  Render loop: show window till close button is pressed
  while (!glfwWindowShouldClose(viewer.getHandle())) {
    // Inputs
    viewer.processInput();

    // Display
    viewer.display(shader, glfwGetTime());

    // Load the compiled shaders to the GPU
    shader.Activate();

    // Draw cube ////////////////////////////////

    // get locations of uniforms in the shader program
    modelview_loc = glGetUniformLocation(shader.getHandle(), "modelview");
    proj_loc = glGetUniformLocation(shader.getHandle(), "proj");

    // build perspective matrix
    // gl::perspective(gl::deg2rad(45.0f)
    proj_m = glm::perspective(1.0472f, viewer.aspect_ratio(), 0.1f,
                              1000.0f); // 1.0472 radians == 60 degrees

    // build view,model matrices
    view_m.translation() = -camera.coord();
    model_m.translation() = cube.coord();
    modelview_m = view_m * model_m;

    // copy matrix data to corresponding uniform variables
    glUniformMatrix4fv(modelview_loc, 1, GL_FALSE, modelview_m.data());
    glUniformMatrix4fv(proj_loc, 1, GL_FALSE, glm::value_ptr(proj_m));

    // Link vaO to vbO
    va.LinkAttrib(vb[0], 0, cube.vertices(), GL_FLOAT);

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
