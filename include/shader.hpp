#pragma once
#include "include_glad.h"
#include <glm/ext/matrix_clip_space.hpp> // glm::perspective
#include <glm/ext/matrix_transform.hpp> // glm::translate, glm::rotate, glm::scale
#include <glm/ext/scalar_constants.hpp> // glm::pi
#include <glm/mat4x4.hpp>               // glm::mat4
#include <glm/vec3.hpp>                 // glm::vec3
#include <glm/vec4.hpp>                 // glm::vec4
#include <string>

class Shader {
public:
  Shader();

  auto &get_shader_program() { return shaderProgram_; }

  // Activates the Shader Program
  void Activate();

  // Deletes the Shader Program
  void Delete();

private:
  // Create Shader Program Object and get its reference
  GLuint shaderProgram_{};

  void create_program_shader();

  std::string readShaderSource(const char *filePath);
};