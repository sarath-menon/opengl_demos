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

  void set_data(gl::M3DC &M);

  // getter functions
  auto &data_set_flag() { return data_set_flag_; }

private:
  // true if data has been set
  bool data_set_flag_{};

  // Deletes the VBO
  void Delete();
};
