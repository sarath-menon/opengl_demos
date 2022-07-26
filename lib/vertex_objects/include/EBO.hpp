#pragma once

#include "gl_common.hpp"
#include <glad/glad.h>

class EBO {
public:
  // ID reference of Elements Buffer Object
  GLuint ID;
  // Constructor that generates a Elements Buffer Object and links it to indices
  EBO(const gl::M3IDR &indices, GLsizeiptr size);

  ~EBO();

  // Binds the EBO
  void Bind();
  // Unbinds the EBO
  void Unbind();
  // Deletes the EBO
  void Delete();
};