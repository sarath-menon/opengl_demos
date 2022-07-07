#pragma once
#include "include_glad.h"
#include <glm/ext/matrix_clip_space.hpp> // glm::perspective
#include <glm/ext/matrix_transform.hpp> // glm::translate, glm::rotate, glm::scale
#include <glm/ext/scalar_constants.hpp> // glm::pi
#include <glm/mat4x4.hpp>               // glm::mat4
#include <glm/vec3.hpp>                 // glm::vec3
#include <glm/vec4.hpp>                 // glm::vec4

class Shader {
public:
  Shader();

  auto &get_shader_program() { return shaderProgram_; }

private:
  // Create Shader Program Object and get its reference
  GLuint shaderProgram_{};

  auto create_program_shader();

  // Vertex Shader source code
  constexpr static char *vertexShaderSource =
      "#version 330 core\n"
      "layout (location = 0) in vec3 aPos;\n"
      "void main()\n"
      "{\n"
      "   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
      "}\0";

  // Fragment Shader source code
  constexpr static char *fragmentShaderSource =
      "#version 330 core\n"
      "out vec4 FragColor;\n"
      "void main()\n"
      "{\n"
      "   FragColor = vec4(0.8f, 0.3f, 0.02f, 1.0f);\n"
      "}\n\0";
};