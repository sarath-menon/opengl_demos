#include "VAO.hpp"
#include "VBO.hpp"
#include "camera.hpp"
#include "cube.hpp"
#include "pyramid.hpp"
#include "shader.hpp"
#include "stb_image.h"
#include "timer.hpp"
#include "viewer.hpp"
#include <iostream>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp> // glm::value_ptr

int main() {

  constexpr float width = 600;
  constexpr float height = 600;

  constexpr float camera_fov = 60.0_deg;
  constexpr float cam_pos[3] = {0.0f, 2.0f, 10.0f};
  constexpr float near_plane = 0.1f;
  constexpr float far_plane = 100.0f;

  constexpr float cube_pos[3] = {1.0, -2.0, -1.0};
  constexpr float pyramid_pos[3] = {0.0, 0.0, 0.0};

  Viewer viewer(width, height);
  Shader object_shader("shaders/3d_vertShader.glsl",
                       "shaders/3d_fragShader.glsl");
  Shader light_shader("shaders/light_vertShader.glsl",
                      "shaders/light_fragShader.glsl");

  Camera camera(width, height, glm::vec3(glm::make_vec3(cam_pos)));
  Cube cube(gl::V3(cube_pos[0], cube_pos[1], cube_pos[2]), 1.0);
  Pyramid pyramid(gl::V3(pyramid_pos[0], pyramid_pos[1], pyramid_pos[2]), 1.0);

  // to hold id's of uniform variables
  GLuint model_loc, light_model_loc;

  // vertex array object to prganize vertex buffers
  VAO va;

  // vertex buffer to be sent to vertex shader
  VBO vb[2];
  vb[0].set_vertices(cube.vertices());
  vb[1].set_vertices(pyramid.vertices());

  // Transformation matrices
  gl::A3 model_m = gl::A3::Identity();

  // get locations of uniforms in the shader program
  model_loc = glGetUniformLocation(object_shader.getHandle(), "model");
  light_model_loc = glGetUniformLocation(object_shader.getHandle(), "model");

  cube.set_global_position(gl::V3(1.0f, 3.0f, 1.0f));

  //  Render loop: show window till close button is pressed
  while (!glfwWindowShouldClose(viewer.getHandle())) {
    // viewer
    viewer.processInput();
    viewer.clear_display();

    // camera
    // Handles camera inputs
    camera.Inputs(viewer.getHandle());
    // Update the camera position according to mouse interaction
    camera.updateMatrix(camera_fov, 0.1f, 100.0f);

    // Draw pyramid ////////////////////////////////

    // Load the compiled shaders to the GPU
    object_shader.Activate();

    // build view,model matrices
    pyramid.global_rotate_x(M_PI / 100.0f);

    // create model matrix
    model_m = pyramid.global_pose();

    // copy matrix data to corresponding uniform variables
    glUniformMatrix4fv(model_loc, 1, GL_FALSE, model_m.data());

    // Link vaO to vbO
    va.link_vertices(vb[1], 0, GL_FLOAT);

    // draw
    glDrawArrays(GL_TRIANGLES, 0, 18);

    // Export the camMatrix to the Vertex Shader of the pyramid
    camera.Matrix(object_shader, "cam_view");

    //// Draw cube    ////////////////////////////////////////

    // Load the compiled shaders to the GPU
    light_shader.Activate();

    cube.global_rotate_y(M_PI / 100.0f);

    // create model matrix
    model_m = cube.global_pose();

    // copy matrix data to corresponding uniform variables
    glUniformMatrix4fv(model_loc, 1, GL_FALSE, model_m.data());

    // Link vaO to vbO
    va.link_vertices(vb[0], 0, GL_FLOAT);
    // draw
    glDrawArrays(GL_TRIANGLES, 0, 36);

    // Export the camMatrix to the Vertex Shader of the pyramid
    camera.Matrix(light_shader, "cam_view");

    //////////////////////////////////////////////////////////

    viewer.start_display();
  }
}
