#pragma once

#include "gl_common.hpp"
#include <glad/glad.h>

class EBO {
  /*
  Specifies the order in which vertices should be drawn
  */
public:
  // ID reference of Elements Buffer Object
  GLuint ID;
  // Constructor that generates a Elements Buffer Object and links it to indices
  EBO();

  ~EBO();

  void set_indices(const gl::M3IDR &indices);

  // Binds the EBO
  void Bind();
  // Unbinds the EBO
  void Unbind();
  // Deletes the EBO
  void Delete();
};