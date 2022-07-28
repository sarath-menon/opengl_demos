#include "VAO.hpp"
#include <iostream>

// Constructor that generates a VAO ID
VAO::VAO() {
  VAO::create_one_vertex_array();

  // Activate the VA
  VAO::Bind();
}

VAO::~VAO() { this->Delete(); }

// Links a vbo to the VAO using a certain layout
void VAO::set_vertex_attrb_ptrs(VBO &vbo, const enum VertexData attrib) const {

  vbo.Bind();
  int layout{}, rowsize{};

  // associate active buffer with the (layout)th vertex attribute in the shader
  switch (attrib) {

  case VertexData::vertices:
    assert(vbo.data_set_flag() == true);
    layout = 0;
    rowsize = 3;
    break;

  case VertexData::colours:
    assert(vbo.colours_set_flag() == true);
    layout = 1;
    rowsize = 2;
    break;

  case VertexData::texture:
    assert(vbo.texture_set_flag() == true);
    layout = 2;
    rowsize = 2;
    break;
  }

  glVertexAttribPointer(layout, rowsize, GL_FLOAT, GL_FALSE, 0, (GLvoid *)0);
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