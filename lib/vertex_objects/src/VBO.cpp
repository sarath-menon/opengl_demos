#include "VBO.hpp"
#include <iostream>

// Constructor that generates a Vertex Buffer Object and links it to vertices
// for use with eigen
VBO::VBO(gl::M3 &V) {
  glGenBuffers(1, &ID);
  glBindBuffer(GL_ARRAY_BUFFER, ID);

  // We expect a matrix with each vertex position on a row, we then want to
  // pass this data to OpenGL reading across rows (row-major)

  glBufferData(GL_ARRAY_BUFFER, sizeof(float) * V.size(), V.data(),
               GL_STATIC_DRAW);
}

// Binds the VBO
void VBO::Bind() { glBindBuffer(GL_ARRAY_BUFFER, ID); }

// Unbinds the VBO
void VBO::Unbind() { glBindBuffer(GL_ARRAY_BUFFER, 0); }

// Deletes the VBO
void VBO::Delete() { glDeleteBuffers(1, &ID); }
