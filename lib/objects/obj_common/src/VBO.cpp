#include "VBO.hpp"
#include <iostream>

// Constructor that generates a Vertex Buffer Object and links it to vertices
VBO::VBO() { VBO::create_one_buffer(); }

void VBO::set_vertices(const gl::M3DR &M) const {

  VBO::Bind();

  // We expect a matrix with each vertex position on a row, we then want to
  // pass this data to OpenGL reading across rows (row-major)

  /* copy vertex data to the active vertex buffer
   API: (buffer type, data size, data, usage)
   usage -> tell the graphics card how to manage the data

   GL_STREAM_DRAW: the data is set only once and used by the GPU at most a few
   times.
   GL_STATIC_DRAW: the data is set only once and used many times.
   GL_DYNAMIC_DRAW: the data is changed a lot and used many times.*/

  glBufferData(GL_ARRAY_BUFFER, sizeof(float) * M.size(), M.data(),
               GL_STATIC_DRAW);

  data_set_flag_ = true;
}

void VBO::set_colours(const gl::M3DR &M) const {

  VBO::Bind();

  // We expect a matrix with one (R,G,B) colour for one vertex in a row, we then
  // want to pass this data to OpenGL reading across rows (row-major)

  glBufferData(GL_ARRAY_BUFFER, sizeof(float) * M.size(), M.data(),
               GL_STATIC_DRAW);

  colours_set_flag_ = true;
}

void VBO::set_texture(const gl::M2DR &M) const {
  this->Bind();

  // We expect a matrix with each texture coordinate pair in a row, we then want
  // to pass this data to OpenGL reading across rows (row-major)

  // copy vertices to the active vertex buffer
  glBufferData(GL_ARRAY_BUFFER, sizeof(float) * M.size(), M.data(),
               GL_STATIC_DRAW);

  texture_set_flag_ = true;
}

VBO::~VBO() { VBO::Delete(); }

// create a memory buffer on the GPU and get it's ID
void VBO::create_one_buffer() { glGenBuffers(1, &ID); }

// Bind the memory buffer to array type, since it is the type used by VBO's
void VBO::Bind() const { glBindBuffer(GL_ARRAY_BUFFER, ID); }

// Unbind the memory buffer
void VBO::Unbind() const { glBindBuffer(GL_ARRAY_BUFFER, ID); }

// Deletes the VBO
void VBO::Delete() const { glDeleteBuffers(1, &ID); }
