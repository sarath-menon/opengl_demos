#pragma once
#include "gl_common.hpp"
#include <glad/glad.h>

class VBO {
public:
  // Reference ID of the Vertex Buffer Object
  GLuint ID;

  // Constructor that generates a Vertex Buffer Object and links it to vertices
  VBO(gl::M3DC &V);

  ~VBO();

  // Binds the VBO
  void Bind();
  // Unbinds the VBO
  void Unbind();

private:
  // Deletes the VBO
  void Delete();
};
