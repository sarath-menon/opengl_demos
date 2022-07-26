#pragma once
#include "gl_common.hpp"
#include <glad/glad.h>

class VBO {
public:
  // Reference ID of the Vertex Buffer Object
  GLuint ID;

  // Constructor that generates a Vertex Buffer Object and links it to vertices
  VBO();

  ~VBO();

  // Binds the VBO
  void Bind() const;
  // Unbinds the VBO
  void Unbind() const;

  void set_vertices(const gl::M3DR &M) const;
  void set_texture(const gl::M2DR &M) const;

  // getter functions
  const auto &data_set_flag() const { return data_set_flag_; }
  const auto &texture_set_flag() const { return texture_set_flag_; }

private:
  // true if data has been set
  mutable bool data_set_flag_{};
  mutable bool texture_set_flag_{};

  // Deletes the VBO
  void Delete() const;
};
