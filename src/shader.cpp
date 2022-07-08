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

  // create list of compiles shaders
  GLuint shaderProgram = glCreateProgram();

  // Attach the Vertex and Fragment Shaders to the Shader Program
  glAttachShader(shaderProgram, vertexShader);
  glAttachShader(shaderProgram, fragmentShader);

  // request GLSL to ensure that shader is compatible
  glLinkProgram(shaderProgram);

  // Delete the now useless Vertex and Fragment Shader objects
  glDeleteShader(vertexShader);
  glDeleteShader(fragmentShader);

  return shaderProgram;
}

Shader::Shader(VO &vao) {

  shaderProgram_ = create_program_shader();

  // Bind the VO so OpenGL knows to use it
  glBindVertexArray(vao.a);
};
