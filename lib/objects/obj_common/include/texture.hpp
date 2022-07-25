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
  void texUnit(Shader &shader, const char *uniform, GLuint unit);
  // Binds a texture
  void Bind();
  // Unbinds a texture
  void Unbind();

private:
  // Deletes a texture
  void Delete();
};