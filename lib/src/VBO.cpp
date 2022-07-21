#include "VBO.hpp"
#include <iostream>

// Constructor that generates a Vertex Buffer Object and links it to vertices
VBO::VBO(GLfloat *vertices, GLsizeiptr size) {
  glGenBuffers(1, &ID);
  glBindBuffer(GL_ARRAY_BUFFER, ID);
  glBufferData(GL_ARRAY_BUFFER, size, vertices, GL_STATIC_DRAW);
}

// Binds the VBO
void VBO::Bind() { glBindBuffer(GL_ARRAY_BUFFER, ID); }

// Unbinds the VBO
void VBO::Unbind() { glBindBuffer(GL_ARRAY_BUFFER, 0); }

// Deletes the VBO
void VBO::Delete() { glDeleteBuffers(1, &ID); }

// for use with eigen
VBO::VBO(Eigen::Matrix<float, 3, 3> &V) {
  glGenBuffers(1, &ID);
  glBindBuffer(GL_ARRAY_BUFFER, ID);

  // We expect a matrix with each vertex position on a row, we then want to
  // pass this data to OpenGL reading across rows (row-major)

  // if eigen matrix is not rowmajor, transpose it
  if (V.Options & Eigen::RowMajor) {
    glBufferData(GL_ARRAY_BUFFER, sizeof(float) * V.size(), V.data(),
                 GL_STATIC_DRAW);
  }

  else {
    // Create temporary copy of transpose
    Eigen::Matrix<float, Eigen::Dynamic, Eigen::Dynamic> VT = V.transpose();
    glBufferData(GL_ARRAY_BUFFER, sizeof(float) * V.size(), VT.data(),
                 GL_STATIC_DRAW);
  }
}

// for use with eigen
VBO::VBO(Eigen::Matrix<float, Eigen::Dynamic, Eigen::Dynamic> &V) {
  glGenBuffers(1, &ID);
  glBindBuffer(GL_ARRAY_BUFFER, ID);
  glBufferData(GL_ARRAY_BUFFER, sizeof(float) * V.size(), V.data(),
               GL_STATIC_DRAW);
}
