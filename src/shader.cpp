#include "shader.hpp"

auto Shader::create_program_shader() {

  // Create reference to access vertex  shader
  GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
  // Attach Vertex Shader source to the Vertex Shader Object, 1-> one screen
  glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
  // Compile the Vertex Shader into machine code for GPU
  glCompileShader(vertexShader);

  // Create reference to access fragment shader
  GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
  // Attach Fragment Shader source to the Fragment Shader Object, 1-> one screen
  glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
  // Compile the Fragment Shader into machine code for GPU
  glCompileShader(fragmentShader);

  // Create Shader Program Object and get its reference
  GLuint shaderProgram = glCreateProgram();

  // Attach the Vertex and Fragment Shaders to the Shader Program
  glAttachShader(shaderProgram, vertexShader);
  glAttachShader(shaderProgram, fragmentShader);
  // Wrap-up/Link all the shaders together into the Shader Program
  glLinkProgram(shaderProgram);

  // Delete the now useless Vertex and Fragment Shader objects
  glDeleteShader(vertexShader);
  glDeleteShader(fragmentShader);

  return shaderProgram;
}

Shader::Shader(GLuint *VAO, GLuint *VBO) {

  VAO_ = VAO;
  VBO_ = VBO;

  shaderProgram_ = create_program_shader();

  // Tell OpenGL which Shader Program we want to use
  glUseProgram(shaderProgram_);
  // Bind the VAO so OpenGL knows to use it
  glBindVertexArray(*VAO_);
};
