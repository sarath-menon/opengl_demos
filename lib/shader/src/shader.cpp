#include "shader.hpp"

void Shader::create_program_shader() {

  // read shader source files
  std::string vertShaderStr = readShaderSource(vs_path_.c_str());
  std::string fragShaderStr = readShaderSource(fs_path_.c_str());

  const char *vertShaderSrc = vertShaderStr.c_str();
  const char *fragShaderSrc = fragShaderStr.c_str();

  // Create reference to access shaders
  GLuint vShader = glCreateShader(GL_VERTEX_SHADER);
  GLuint fShader = glCreateShader(GL_FRAGMENT_SHADER);

  glShaderSource(vShader, 1, &vertShaderSrc, NULL);
  glShaderSource(fShader, 1, &fragShaderSrc, NULL);

  // Compile the shaders into machine code
  glCompileShader(vShader);
  glCompileShader(fShader);

  // Checks if Shader compiled succesfully
  compileErrors(fShader, "FRAGMENT");

  // create list of compiles shaders
  shaderProgram_ = glCreateProgram();

  // Attach the Vertex and Fragment Shaders to the Shader Program
  glAttachShader(shaderProgram_, vShader);
  glAttachShader(shaderProgram_, fShader);

  // request GLSL to ensure that shader is compatible
  glLinkProgram(shaderProgram_);

  // Delete the now useless Vertex and Fragment Shader objects
  glDeleteShader(vShader);
  glDeleteShader(fShader);
}

Shader::Shader(std::string vs_path, std::string fs_path) {

  vs_path_ = vs_path;
  fs_path_ = fs_path;

  create_program_shader();

  // // Bind the VO so OpenGL knows to use it
  // glBindVertexArray(vao.a);
};

// to read shader text file
std::string Shader::readShaderSource(const char *filePath) {

  std::string content;
  std::ifstream fileStream(filePath, std::ios::in);
  std::string line = "";

  while (!fileStream.eof()) {
    getline(fileStream, line);
    content.append(line + "\n");
  }
  fileStream.close();
  return content;
}

// Activates the Shader Program
void Shader::Activate() { glUseProgram(shaderProgram_); }

// Deletes the Shader Program
void Shader::Delete() { glDeleteProgram(shaderProgram_); }

// Checks if the different Shaders have compiled properly
void Shader::compileErrors(unsigned int shader, const char *type) {
  // Stores status of compilation
  GLint hasCompiled;
  // Character array to store error message in
  char infoLog[1024];
  if (strcmp(type, "PROGRAM") != 0) {
    glGetShaderiv(shader, GL_COMPILE_STATUS, &hasCompiled);
    if (hasCompiled == GL_FALSE) {
      glGetShaderInfoLog(shader, 1024, NULL, infoLog);
      std::cout << "SHADER_COMPILATION_ERROR for:" << type << "\n"
                << infoLog << std::endl;
    }
  } else {
    glGetProgramiv(shader, GL_LINK_STATUS, &hasCompiled);
    if (hasCompiled == GL_FALSE) {
      glGetProgramInfoLog(shader, 1024, NULL, infoLog);
      std::cout << "SHADER_LINKING_ERROR for:" << type << "\n"
                << infoLog << std::endl;
    }
  }
}