#pragma once
#include "gl_common.hpp"
#include <glad/glad.h>

class VBO {
public:
  // Reference ID of the Vertex Buffer Object
  GLuint ID;

  // Constructor that generates a Vertex Buffer Object and links it to vertices
  VBO();

  ~VBO();

  // Binds the VBO
  void Bind();
  // Unbinds the VBO
  void Unbind();

  void set_vertices(const gl::M3DC &M);
  void set_texture(const gl::M2DC &M);

  // getter functions
  auto &data_set_flag() { return data_set_flag_; }
  auto &texture_set_flag() { return texture_set_flag_; }

private:
  // true if data has been set
  bool data_set_flag_{};
  bool texture_set_flag_{};

  // Deletes the VBO
  void Delete();
};
