#include "shader.hpp"

auto Shader::create_program_shader() {

  std::string vertShaderStr = readShaderSource("shaders/vertShader.glsl");
  std::string fragShaderStr = readShaderSource("shaders/fragShader.glsl");

  // Create reference to access shaders
  GLuint vShader = glCreateShader(GL_VERTEX_SHADER);
  GLuint fShader = glCreateShader(GL_FRAGMENT_SHADER);

  const char *vertShaderSrc = vertShaderStr.c_str();
  const char *fragShaderSrc = fragShaderStr.c_str();

  glShaderSource(vShader, 1, &vertShaderSrc, NULL);
  glShaderSource(fShader, 1, &fragShaderSrc, NULL);

  // // Attach Vertex Shader source to the Vertex Shader Object, 1-> one screen
  // glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);

  // Compile the Vertex Shader into machine code for GPU
  glCompileShader(vShader);

  // // Attach Fragment Shader source to the Fragment Shader Object, 1-> one
  // screen glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);

  // Compile the Fragment Shader into machine code for GPU
  glCompileShader(fShader);

  // create list of compiles shaders
  GLuint shaderProgram = glCreateProgram();

  // Attach the Vertex and Fragment Shaders to the Shader Program
  glAttachShader(shaderProgram, vShader);
  glAttachShader(shaderProgram, fShader);

  // request GLSL to ensure that shader is compatible
  glLinkProgram(shaderProgram);

  // Delete the now useless Vertex and Fragment Shader objects
  glDeleteShader(vShader);
  glDeleteShader(fShader);

  return shaderProgram;
}

Shader::Shader(VO &vao) {

  shaderProgram_ = create_program_shader();

  // Bind the VO so OpenGL knows to use it
  glBindVertexArray(vao.a);
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