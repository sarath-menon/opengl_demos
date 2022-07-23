#include "VBO.hpp"
#include <iostream>

// Constructor that generates a Vertex Buffer Object and links it to vertices
VBO::VBO(gl::M3DC &M) {
  glGenBuffers(1, &ID);
  this->Bind();

  // We expect a matrix with each vertex position on a row, we then want to
  // pass this data to OpenGL reading across rows (row-major)

  // copy vertices to the active vertex buffer
  glBufferData(GL_ARRAY_BUFFER, sizeof(float) * M.size(), M.data(),
               GL_STATIC_DRAW);
}

VBO::~VBO() { this->Delete(); }

// Binds the VBO
void VBO::Bind() { glBindBuffer(GL_ARRAY_BUFFER, ID); }

// Unbinds the VBO
void VBO::Unbind() { glBindBuffer(GL_ARRAY_BUFFER, ID); }

// Deletes the VBO
void VBO::Delete() { glDeleteBuffers(1, &ID); }
