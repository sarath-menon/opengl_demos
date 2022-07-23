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
  void LinkAttrib(VBO &vbo, GLuint layout, gl::M3DC &M, GLenum type);
  // Binds the VAO
  void Bind();
  // Unbinds the VAO
  void Unbind();

private:
  // Deletes the VAO
  void Delete();
};
