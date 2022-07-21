#include "VAO.hpp"

// Constructor that generates a VAO ID
VAO::VAO() { glGenVertexArrays(1, &ID); }

// Links a VBO to the VAO using a certain layout
void VAO::LinkAttrib(VBO &VBO, GLuint layout, gl::M3 &M, GLenum type) {
  VBO.Bind();
  glVertexAttribPointer(layout, M.cols(), type, GL_FALSE, 3 * sizeof(float),
                        (GLvoid *)0);
  glEnableVertexAttribArray(layout);
  VBO.Unbind();
}

// Activate the VAO
void VAO::Bind() { glBindVertexArray(ID); }

// Unbinds the VAO
void VAO::Unbind() { glBindVertexArray(0); }

// Deletes the VAO
void VAO::Delete() { glDeleteVertexArrays(1, &ID); }