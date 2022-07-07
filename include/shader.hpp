#pragma once
#include "include_glad.h"
#include "vertex_shader.h"
#include <glm/ext/matrix_clip_space.hpp> // glm::perspective
#include <glm/ext/matrix_transform.hpp> // glm::translate, glm::rotate, glm::scale
#include <glm/ext/scalar_constants.hpp> // glm::pi
#include <glm/mat4x4.hpp>               // glm::mat4
#include <glm/vec3.hpp>                 // glm::vec3
#include <glm/vec4.hpp>                 // glm::vec4

class Shader {

private:
  // Create Shader Program Object and get its reference
  GLuint shaderProgram{};

public:
  Shader();

  auto &get_shader_program() { return shaderProgram; }
};