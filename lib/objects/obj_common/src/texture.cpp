#include "texture.hpp"

#define STB_IMAGE_IMPLEMENTATION
#include <stb_image.h>

Texture::Texture(const char *image_path, GLenum texType, GLenum slot,
                 GLenum format, GLenum pixelType) {
  // Assigns the type of the texture ot the texture object
  type = texType;

  // Stores the width, height, and the number of color channels of the image
  int widthImg, heightImg, numColCh;
  // Flips the image so it appears right side up
  stbi_set_flip_vertically_on_load(true);
  // Reads the image from a file and stores it in bytes
  unsigned char *data =
      stbi_load(image_path, &widthImg, &heightImg, &numColCh, 0);

  if (data) {
    GLenum format_ = 0;
    if (numColCh == 1)
      format_ = GL_RED;
    else if (numColCh == 3)
      format_ = GL_RGB;
    else if (numColCh == 4)
      format_ = GL_RGBA;

    // Generates an OpenGL texture object
    glGenTextures(1, &ID);

    // Assigns the texture to a Texture Unit (16 texture units per shader stage)
    glActiveTexture(slot);
    glBindTexture(texType, ID);

    // Configures the type of algorithm that is used to make the image smaller
    // or bigger
    glTexParameteri(texType, GL_TEXTURE_MIN_FILTER, GL_NEAREST_MIPMAP_LINEAR);
    glTexParameteri(texType, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

    //   glTexParameteri(texType, GL_TEXTURE_MIN_FILTER,
    //   GL_LINEAR_MIPMAP_LINEAR); glTexParameteri(texType,
    //   GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    // Configures the way the texture repeats (if it does at all)
    glTexParameteri(texType, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(texType, GL_TEXTURE_WRAP_T, GL_REPEAT);

    // Extra lines in case you choose to use GL_CLAMP_TO_BORDER
    // float flatColor[] = {1.0f, 1.0f, 1.0f, 1.0f};
    // glTexParameterfv(GL_TEXTURE_2D, GL_TEXTURE_BORDER_COLOR, flatColor);

    // Assigns the image to the OpenGL Texture object
    glTexImage2D(texType, 0, GL_RGBA, widthImg, heightImg, 0, format_,
                 pixelType, data);
    // Generates MipMaps
    glGenerateMipmap(texType);
  }

  else {
    std::cout << "Texture failed to load at path: " << image_path << std::endl;
    stbi_image_free(data);
  }
}

Texture::~Texture() { Texture::Delete(); }

void Texture::texUnit(const Shader &shader, const char *uniform,
                      GLuint unit) const {
  // Gets the location of the uniform
  GLuint texUni = glGetUniformLocation(shader.getHandle(), uniform);
  // Shader needs to be activated before changing the value of a uniform
  shader.Activate();
  // Sets the value of the uniform
  glUniform1i(texUni, unit);
}

void Texture::Bind() const { glBindTexture(type, ID); }

void Texture::Unbind() const { glBindTexture(type, 0); }

void Texture::Delete() const { glDeleteTextures(1, &ID); }