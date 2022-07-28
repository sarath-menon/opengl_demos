#pragma once
#include "VBO.hpp"
#include "gl_common.hpp"

enum class VertexData {
  vertices,
  colours,
  texture,
};

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

  void set_vertex_attrb_ptrs(VBO &vbo, const enum VertexData attrib) const;

  // Unbinds the VAO
  void Unbind() const;

  // Binds the VAO
  void Bind() const;

private:
  void create_one_vertex_array();

  // Deletes the VAO
  void Delete();
};
