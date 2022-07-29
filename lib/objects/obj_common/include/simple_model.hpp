#pragma once

#include <glad/glad.h>
//
#include "EBO.hpp"
#include "VAO.hpp"
#include "VBO.hpp"
#include "gl_common.hpp"
#include "rotation.hpp"
#include "shader.hpp"
#include "texture.hpp"
#include <cmath>
#include <filesystem>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <memory>

/// Represents a Rigid body
class SimpleModel {

protected:
  // geometry parameters -----------

  // pose of the rigid body
  gl::A3 global_pose_{};

  float scale_{};

  // appearance parameters -----------

  // one (x,y,z) position coordinate per row
  gl::M3DR vertices_;

  // for vertext ordering, one per row
  gl::M3IDR indices_;

  // one (x,y,z) normal vector per row
  gl::M3DR normals_;

  // one (u,v) texture coordinate per row
  gl::M2DR texture_coord_;

  // (R,G,B, alpha) vector
  glm::vec4 obj_colour_;

  // vertex array object to prganize vertex buffers
  VAO va;
  // vertex buffer to be sent to vertex shader
  VBO vb[3];

  // Generates Element Buffer Object and links it to indices
  EBO eb;

  void set_vertex_buffers(const Shader &shader);

private:
  // to hold id's of uniform variables
  GLuint model_loc, colour_loc;

  const std::string texPath = "/resources/textures/";
  const std::string texture_file = "floor.png";
  std::string texture_dir =
      (std::filesystem::current_path().string() + texPath + texture_file);

  std::unique_ptr<Texture> texture;

  void activate_colour() const;

public:
  SimpleModel(const Shader &shader);

  void set_colour(const glm::vec4 colour, const Shader &shader);

  void display(const Shader &shader) const;

  // set global parameters -----------
  void set_global_pose(const gl::A3 &pose);
  void set_global_position(const gl::V3 pos);
  void set_global_orientation(const gl::Q quat);

  void global_rotate_x(const float angle);
  void global_rotate_y(const float angle);
  void global_rotate_z(const float angle);

  void set_scale(const float scale);

  // getter functions
  constexpr auto &global_pose() const { return global_pose_; }

  constexpr auto &vertices() const { return vertices_; }

  constexpr auto &normals() const { return normals_; }

  constexpr auto &indices() const { return indices_; }

  constexpr auto &scale() const { return scale_; }

  constexpr auto &texture_coord() const { return texture_coord_; }
};
