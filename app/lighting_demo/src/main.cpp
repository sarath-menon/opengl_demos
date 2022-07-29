#include "camera.hpp"
#include "cube.hpp"
#include "pyramid.hpp"
#include "shader.hpp"
#include "viewer.hpp"
#include <glm/glm.hpp>
#include <iostream>

int main() {

  constexpr float width = 600;
  constexpr float height = 600;

  const glm::vec3 cam_pos(0.0f, 0.0f, 5.0f);
  const gl::V3 cube_pos(1.0, -2.0, -1.0);
  const gl::V3 pyramid_pos(0.0, -2.0, 0.0);

  const glm::vec4 cube_colour(0.8f, 0.3f, 0.02f, 1.0f);
  const glm::vec4 pyramid_colour(0.0f, 1.0f, 0.0f, -1.0f);

  Viewer viewer(width, height, "Cube with vertices drawn using indices");

  Shader obj_shader("shaders/3d_constcolour_vshader.glsl",
                    "shaders/3d_constcolour_fshader.glsl");
  Shader light_shader("shaders/3d_constcolour_vshader.glsl",
                      "shaders/3d_constcolour_fshader.glsl");
  // Shader light_shader("shaders/light_vshader.glsl",
  //                     "shaders/light_fshader.glsl");

  Camera camera(width, height, cam_pos, obj_shader);

  Cube cube(cube_pos, light_shader);

  Pyramid pyramid(pyramid_pos, obj_shader);
  Pyramid pyramid2(pyramid_pos, obj_shader);

  cube.set_colour(cube_colour, light_shader);
  pyramid.set_colour(pyramid_colour, obj_shader);
  pyramid2.set_colour(cube_colour, obj_shader);

  cube.set_global_position(gl::V3(1.0f, 1.0f, -2.0f));
  pyramid2.set_global_position(gl::V3(-1.0f, -0.5f, -1.0f));

  //  Render loop: show window till close button is pressed
  while (!glfwWindowShouldClose(viewer.getHandle())) {
    // Inputs
    viewer.processInput();
    viewer.clear_display();
    camera.Inputs(viewer.getHandle());

    // Draw////////////////////////////////

    // send data in vertex buffer to the obj_shader and start drawing
    cube.display(light_shader);
    camera.update(light_shader);

    pyramid.global_rotate_y(M_PI / 100.0f);
    pyramid2.global_rotate_y(M_PI / 100.0f);

    pyramid.display(obj_shader);
    pyramid2.display(obj_shader);
    camera.update(obj_shader);

    //////////////////////////////////////////////////////////
    // Export the camMatrix to the Vertex Shader of the pyramid
    viewer.start_display();
  }
}
