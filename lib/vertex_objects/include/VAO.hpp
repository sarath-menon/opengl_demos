#pragma once
#include "VBO.hpp"
#include "gl_common.hpp"

class VAO {
  //
  // To organize vertex buffer objects
  //
public:
  // ID reference for the Vertex Array Object
  GLuint ID;
  // Constructor that generates a VAO ID
  VAO();

  ~VAO();

  // Links a VBO to the VAO using a certain layout
  void set_vertex_attrb_ptrs(VBO &vbo, const GLuint layout,
                             const GLenum type) const;
  void link_texture(VBO &vbo, const GLuint layout, const GLenum type) const;

  // Unbinds the VAO
  void Unbind() const;

  // Binds the VAO
  void Bind() const;

private:
  void create_one_vertex_array();

  // Deletes the VAO
  void Delete();
};
