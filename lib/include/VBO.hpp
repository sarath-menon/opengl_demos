#pragma once
#include <eigen3/Eigen/Dense>
#include <glad/glad.h>

class VBO {
public:
  // Reference ID of the Vertex Buffer Object
  GLuint ID;
  // Constructor that generates a Vertex Buffer Object and links it to vertices
  VBO(GLfloat *vertices, GLsizeiptr size);

  // for use with eigen
  VBO(Eigen::Matrix<float, Eigen::Dynamic, Eigen::Dynamic> &V);

  VBO(Eigen::Matrix<float, 3, 3> &V);

  // Binds the VBO
  void Bind();
  // Unbinds the VBO
  void Unbind();
  // Deletes the VBO
  void Delete();
};
