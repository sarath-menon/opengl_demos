#include "VBO.hpp"
#include <iostream>

// Constructor that generates a Vertex Buffer Object and links it to vertices
VBO::VBO() { glGenBuffers(1, &ID); }

void VBO::set_vertices(const gl::M3DC &M) const {
  this->Bind();

  // We expect a matrix with each vertex position on a row, we then want to
  // pass this data to OpenGL reading across rows (row-major)

  // copy vertices to the active vertex buffer
  glBufferData(GL_ARRAY_BUFFER, sizeof(float) * M.size(), M.data(),
               GL_STATIC_DRAW);

  data_set_flag_ = true;
}

void VBO::set_texture(const gl::M2DC &M) const {
  this->Bind();

  // We expect a matrix with each texture coordinate pair in a row, we then want
  // to pass this data to OpenGL reading across rows (row-major)

  // copy vertices to the active vertex buffer
  glBufferData(GL_ARRAY_BUFFER, sizeof(float) * M.size(), M.data(),
               GL_STATIC_DRAW);

  texture_set_flag_ = true;
}

VBO::~VBO() { VBO::Delete(); }

// Binds the VBO
void VBO::Bind() const { glBindBuffer(GL_ARRAY_BUFFER, ID); }

// Unbinds the VBO
void VBO::Unbind() const { glBindBuffer(GL_ARRAY_BUFFER, ID); }

// Deletes the VBO
void VBO::Delete() const { glDeleteBuffers(1, &ID); }
