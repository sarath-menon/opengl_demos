#include "camera.hpp"
#include "pyramid.hpp"
#include "shader.hpp"
#include "texture.hpp"
#include "viewer.hpp"
#include <filesystem>
#include <glm/glm.hpp>
#include <iostream>

int main() {

  static constexpr int width = 600;
  static constexpr int height = 600;

  const glm::vec3 cam_pos(0.0f, 0.0f, 5.0f);
  const gl::V3 pyramid_pos(1.0, -1.0, -1.0);

  Viewer viewer(width, height, "Pyramid with vertices drawn using indices");
  Shader obj_shader("shaders/3d_texture_vshader.glsl",
                    "shaders/3d_texture_fshader.glsl");

  Camera camera(width, height, cam_pos, obj_shader);
  Pyramid pyramid(pyramid_pos, obj_shader);

  pyramid.set_scale(0.5f);

  // pyramid.set_global_position(gl::V3(1.0f, 1.0f, 1.0f));

  //  Render loop: show window till close button is pressed
  while (!glfwWindowShouldClose(viewer.getHandle())) {
    // Inputs
    viewer.processInput();
    viewer.clear_display();
    camera.Inputs(viewer.getHandle());
    // Draw pyramid ////////////////////////////////

    pyramid.global_rotate_y(gl::pi / 100.0f);

    // send data in vertex buffer to the obj_shader and start drawing
    pyramid.display(obj_shader);

    //////////////////////////////////////////////////////////
    // Export the camMatrix to the Vertex Shader of the pyramid
    camera.update(obj_shader);
    viewer.start_display();
  }
}
