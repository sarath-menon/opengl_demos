#include "EBO.hpp"

EBO::EBO(const gl::M3IDR &indices) {
  glGenBuffers(1, &ID);
  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ID);
  glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(int) * indices.size(),
               indices.data(), GL_STATIC_DRAW);
}

EBO::~EBO() { EBO::Delete(); }

// Binds the EBO
void EBO::Bind() { glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ID); }

// Unbinds the EBO
void EBO::Unbind() { glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0); }

// Deletes the EBO
void EBO::Delete() { glDeleteBuffers(1, &ID); }