#include "VAO.hpp"

// Constructor that generates a VAO ID
VAO::VAO() {
  // create vertex array
  glGenVertexArrays(1, &ID);
  // Activate the VA
  this->Bind();
}

VAO::~VAO() { this->Delete(); }

// Links a vbo to the VAO using a certain layout
void VAO::LinkAttrib(VBO &vbo, GLuint layout, gl::M3DC &M, GLenum type) {

  // safety checks
  assert(vbo.data_set_flag() == true);

  vbo.Bind();

  // associate active buffer with the (layout)th vertex attribute in the shader
  glVertexAttribPointer(layout, 3, type, GL_FALSE, 0, (GLvoid *)0);

  // enable the (layout)th vertex attribute
  glEnableVertexAttribArray(layout);

  // vbo.Unbind();
}

// Activate the VAO
void VAO::Bind() { glBindVertexArray(ID); }

// Unbinds the VAO
void VAO::Unbind() { glBindVertexArray(0); }

// Deletes the VAO
void VAO::Delete() { glDeleteVertexArrays(1, &ID); }