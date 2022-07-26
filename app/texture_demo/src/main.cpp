#include "VAO.hpp"
#include "VBO.hpp"
#include "camera.hpp"
#include "pyramid.hpp"
#include "shader.hpp"
#include "texture.hpp"
#include "timer.hpp"
#include "triangle.hpp"
#include "viewer.hpp"
#include <filesystem>
#include <iostream>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp> // glm::value_ptr

int main() {

  constexpr float width = 600;
  constexpr float height = 600;

  constexpr float cam_pos[3] = {0.0f, 2.0f, 10.0f};
  const gl::V3 pyramid_pos(1.0, -2.0, -1.0);

  const std::string texPath = "/resources/textures/";
  const std::string texture_file = "floor.png";

  Viewer viewer(width, height, "Pyramid with texture");
  Shader shader("shaders/3d_texture_vshader.glsl",
                "shaders/3d_texture_fshader.glsl");
  Camera camera(width, height, glm::vec3(glm::make_vec3(cam_pos)));
  Pyramid pyramid(pyramid_pos, 1.0);

  // to hold id's of uniform variables
  GLuint model_loc;

  gl::Timer t;

  // vertex array object to prganize vertex buffers
  VAO va;
  // vertex buffer to be sent to vertex shader
  VBO vb[2];
  vb[0].set_vertices(pyramid.vertices());
  vb[1].set_texture(pyramid.texture_coord());

  // Transformation matrices
  gl::A3 model_m = gl::A3::Identity();
  // get locations of uniforms in the shader program
  model_loc = glGetUniformLocation(shader.getHandle(), "model");

  // start timer
  t.start();

  pyramid.set_global_position(gl::V3(1.0f, 1.0f, 1.0f));

  // load texture
  std::string parentDir = (std::filesystem::current_path()).string();
  Texture floor((parentDir + texPath + texture_file).c_str(), GL_TEXTURE_2D,
                GL_TEXTURE0, GL_RGBA, GL_UNSIGNED_BYTE);
  floor.texUnit(shader, "tex0", 0);

  //  Render loop: show window till close button is pressed
  while (!glfwWindowShouldClose(viewer.getHandle())) {
    // Inputs
    viewer.processInput();

    viewer.clear_display();
    //////////////////////////////

    // Load the compiled shaders to the GPU
    shader.Activate();

    // Draw pyramid ////////////////////////////////
    pyramid.global_rotate_y(M_PI / 100.0f);

    // create model matrix
    model_m = pyramid.global_pose();

    // copy matrix data to corresponding uniform variables
    glUniformMatrix4fv(model_loc, 1, GL_FALSE, model_m.data());

    // Handles camera inputs
    camera.Inputs(viewer.getHandle());
    // Updates and exports the camera matrix to the Vertex Shader
    camera.updateMatrix();

    // Export the camMatrix to the Vertex Shader of the pyramid
    camera.Matrix(shader, "cam_view");

    // // Updates and exports the camera matrix to the Vertex Shader
    // camera.Matrix(camera_fov, near_plane, far_plane, shader, "cam_view");

    // Link vaO to vbO
    va.set_vertex_attrb_ptrs(vb[0], 0, GL_FLOAT);
    va.link_texture(vb[1], 1, GL_FLOAT);

    // send data in vertex buffer to the shader and start drawing
    glDrawArrays(GL_TRIANGLES, 0, 36);

    viewer.start_display();
  }
}
