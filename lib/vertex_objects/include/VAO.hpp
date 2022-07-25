#pragma once
#include "VBO.hpp"
#include "gl_common.hpp"

class VAO {
public:
  // ID reference for the Vertex Array Object
  GLuint ID;
  // Constructor that generates a VAO ID
  VAO();

  ~VAO();

  // Links a VBO to the VAO using a certain layout
  void link_vertices(VBO &vbo, const GLuint layout, const GLenum type) const;
  void link_texture(VBO &vbo, const GLuint layout, const GLenum type) const;

private:
  // Binds the VAO
  void Bind() const;
  // Unbinds the VAO
  void Unbind() const;

  // Deletes the VAO
  void Delete();
};
