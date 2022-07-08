#include "shader.hpp"

void Shader::create_program_shader() {

  // read shader source files
  std::string vertShaderStr = readShaderSource("shaders/vertShader.glsl");
  std::string fragShaderStr = readShaderSource("shaders/fragShader.glsl");

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

Shader::Shader() {

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