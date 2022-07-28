#pragma once
#include <glad/glad.h>
//
#include "utils.hpp"
#include <fstream>
#include <iostream>
#include <string>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp> // glm::value_ptr

class Shader {
public:
  Shader(std::string vs_path, std::string fs_path);

  ~Shader();

  const auto getType() const { return type_; }
  const auto getHandle() const { return handle_; }

  // Activates the Shader Program
  void Activate() const;

  void setVec3(const std::string &name, const glm::vec3 &value) const {
    glUniform3fv(glGetUniformLocation(handle_, name.c_str()), 1, &value[0]);
  }

private:
  GLenum type_;
  GLuint handle_;

  std::string vs_path_{};
  std::string fs_path_{};

  // void create_program_shader();

  // // read .glsl shader file and covert to string format
  // std::string readShaderSource(const char *filePath);

  // Deletes the Shader Program
  void Delete() const;

  // // Checks if the different Shaders have compiled properly
  // void compileErrors(unsigned int shader, const char *type);
};