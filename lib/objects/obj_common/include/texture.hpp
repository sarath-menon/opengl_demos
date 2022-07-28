#pragma once

#include <glad/glad.h>

#include "shader.hpp"

class Texture {
public:
  GLuint ID;
  GLenum type;
  Texture(const char *image, GLenum texType, GLenum slot, GLenum format,
          GLenum pixelType);

  ~Texture();

  // Assigns a texture unit to a texture
  void texUnit(const Shader &shader, const char *uniform, GLuint unit) const;
  // Binds a texture
  void Bind() const;
  // Unbinds a texture
  void Unbind() const;

private:
  // Deletes a texture
  void Delete() const;
};