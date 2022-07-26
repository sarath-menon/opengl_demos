#include "VAO.hpp"

// Constructor that generates a VAO ID
VAO::VAO() {
  VAO::create_one_vertex_array();

  // Activate the VA
  VAO::Bind();
}

VAO::~VAO() { this->Delete(); }

// Links a vbo to the VAO using a certain layout
void VAO::set_vertex_attrb_ptrs(VBO &vbo, const GLuint layout,
                                const GLenum type) const {

  // safety checks
  assert(vbo.data_set_flag() == true);

  vbo.Bind();

  // associate active buffer with the (layout)th vertex attribute in the shader
  glVertexAttribPointer(layout, 3, type, GL_FALSE, 0, (GLvoid *)0);

  // enable the (layout)th vertex attribute
  glEnableVertexAttribArray(layout);
}

// Links a vbo to the VAO using a certain layout
void VAO::link_texture(VBO &vbo, const GLuint layout, const GLenum type) const {

  // safety checks
  assert(vbo.texture_set_flag() == true);

  vbo.Bind();

  // associate active buffer with the (layout)th vertex attribute in the shader
  glVertexAttribPointer(layout, 2, type, GL_FALSE, 0, (GLvoid *)0);

  // enable the (layout)th vertex attribute
  glEnableVertexAttribArray(layout);
}

//
void VAO::create_one_vertex_array() { glGenVertexArrays(1, &ID); }

// Activate the VAO
void VAO::Bind() const { glBindVertexArray(ID); }

// Unbinds the VAO
void VAO::Unbind() const { glBindVertexArray(0); }

// Deletes the VAO
void VAO::Delete() { glDeleteVertexArrays(1, &ID); }