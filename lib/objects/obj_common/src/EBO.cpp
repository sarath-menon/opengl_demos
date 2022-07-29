#include "EBO.hpp"

EBO::EBO() {
  glGenBuffers(1, &ID);
  EBO::Bind();
}

void EBO::set_indices(const gl::M3IDR &indices) const {
  glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(int) * indices.size(),
               indices.data(), GL_STATIC_DRAW);
}

EBO::~EBO() { EBO::Delete(); }

// Binds the EBO
void EBO::Bind() const { glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ID); }

// Unbinds the EBO
void EBO::Unbind() const { glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0); }

// Deletes the EBO
void EBO::Delete() const { glDeleteBuffers(1, &ID); }