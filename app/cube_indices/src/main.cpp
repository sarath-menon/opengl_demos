#include "EBO.hpp"
#include "VAO.hpp"
#include "VBO.hpp"
#include "camera.hpp"
#include "cube.hpp"
#include "shader.hpp"
#include "stb_image.h"
#include "timer.hpp"
#include "triangle.hpp"
#include "viewer.hpp"
#include <iostream>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp> // glm::value_ptr

int main() {

  constexpr float width = 600;
  constexpr float height = 600;

  const glm::vec3 cam_pos(0.0f, 0.0f, 5.0f);
  const gl::V3 cube_pos(1.0, -2.0, -1.0);
  const glm::vec4 obj_colour(0.8f, 0.3f, 0.02f, 1.0f);

  Viewer viewer(width, height, "Cube with vertices drawn using indices");
  Shader obj_shader("shaders/3d_constcolour_vshader.glsl",
                    "shaders/3d_constcolour_fshader.glsl");

  Camera camera(width, height, cam_pos, obj_shader);
  Cube cube(cube_pos, obj_shader);

  cube.set_scale(0.5f);

  cube.set_global_position(gl::V3(1.0f, 1.0f, 1.0f));

  // Load the compiled shaders to the GPU
  obj_shader.Activate();

  // set object colour
  glUniform4f(glGetUniformLocation(obj_shader.getHandle(), "obj_colour"),
              obj_colour.x, obj_colour.y, obj_colour.z, obj_colour.w);

  //  Render loop: show window till close button is pressed
  while (!glfwWindowShouldClose(viewer.getHandle())) {
    // Inputs
    viewer.processInput();
    // clear display
    viewer.clear_display();

    // Camera ////////////////////////////////
    // camera
    // Handles camera inputs
    camera.Inputs(viewer.getHandle());

    // Draw cube ////////////////////////////////

    cube.global_rotate_y(M_PI / 100.0f);

    // send data in vertex buffer to the obj_shader and start drawing
    cube.display();

    //////////////////////////////////////////////////////////
    // Export the camMatrix to the Vertex Shader of the pyramid
    camera.update(obj_shader);
    viewer.start_display();
  }
}
