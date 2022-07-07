#pragma once
#include "include_glad.h"
#include <glm/ext/matrix_clip_space.hpp> // glm::perspective
#include <glm/ext/matrix_transform.hpp> // glm::translate, glm::rotate, glm::scale
#include <glm/ext/scalar_constants.hpp> // glm::pi
#include <glm/mat4x4.hpp>               // glm::mat4
#include <glm/vec3.hpp>                 // glm::vec3
#include <glm/vec4.hpp>                 // glm::vec4

class Triangle {

public:
  Triangle();

  auto &get_vao() { return VAO; }

  auto &get_vbo() { return VBO; }

private:
  GLuint VAO, VBO;

  // Vertices coordinates
  GLfloat vertices[9] = {
      -0.5f, -0.5f * float(sqrt(3)) / 3,    0.0f, // Lower left corner
      0.5f,  -0.5f * float(sqrt(3)) / 3,    0.0f, // Lower right corner
      0.0f,  0.5f * float(sqrt(3)) * 2 / 3, 0.0f  // Upper corner
  };
};