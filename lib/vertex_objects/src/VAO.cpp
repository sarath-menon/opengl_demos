#include "VAO.hpp"

// Constructor that generates a VAO ID
VAO::VAO() {
  // create vertex array
  glGenVertexArrays(1, &ID);
  // Activate the VA
  this->Bind();
}

VAO::~VAO() { this->Delete(); }

// Links a VBO to the VAO using a certain layout
void VAO::LinkAttrib(VBO &VBO, GLuint layout, gl::M3DC &M, GLenum type) {
  VBO.Bind();

  // associate active buffer with the (layout)th vertex attribute in the shader
  glVertexAttribPointer(layout, 3, type, GL_FALSE, 0, (GLvoid *)0);

  // enable the (layout)th vertex attribute
  glEnableVertexAttribArray(layout);

  VBO.Unbind();
}

// Activate the VAO
void VAO::Bind() { glBindVertexArray(ID); }

// Unbinds the VAO
void VAO::Unbind() { glBindVertexArray(0); }

// Deletes the VAO
void VAO::Delete() { glDeleteVertexArrays(1, &ID); }