#pragma once
#include "include_glad.h"
#include <array>
#include <glm/ext/matrix_clip_space.hpp> // glm::perspective
#include <glm/ext/matrix_transform.hpp> // glm::translate, glm::rotate, glm::scale
#include <glm/ext/scalar_constants.hpp> // glm::pi
#include <glm/mat4x4.hpp>               // glm::mat4
#include <glm/vec3.hpp>                 // glm::vec3
#include <glm/vec4.hpp>                 // glm::vec4

class Triangle {

public:
  Triangle(std::array<std::array<float, 2>, 3> &vertices);

  auto &get_vao() { return VAO; }

  auto &get_vbo() { return VBO; }

private:
  GLuint VAO, VBO;

  // Vertices coordinates
  GLfloat vertices_[9]{};
};
