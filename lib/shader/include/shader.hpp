#pragma once
#include <fstream>
#include <glad/glad.h>
#include <iostream>
#include <string>

class Shader {
public:
  Shader(std::string vs_path, std::string fs_path);

  ~Shader();

  auto getType() const { return type_; }
  auto getHandle() const { return handle_; }

  // Activates the Shader Program
  void Activate();

private:
  GLenum type_;
  GLuint handle_;

  std::string vs_path_{};
  std::string fs_path_{};

  void create_program_shader();

  // Deletes the Shader Program
  void Delete();

  // read .glsl shader file and covert to string format
  std::string readShaderSource(const char *filePath);

  // Checks if the different Shaders have compiled properly
  void compileErrors(unsigned int shader, const char *type);
};