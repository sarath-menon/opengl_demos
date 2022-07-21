#pragma once
#include "VBO.hpp"
#include <eigen3/Eigen/Dense>

class VAO {
public:
  // ID reference for the Vertex Array Object
  GLuint ID;
  // Constructor that generates a VAO ID
  VAO();

  // Links a VBO to the VAO using a certain layout
  void LinkAttrib(VBO &VBO, GLuint layout,
                  Eigen::Matrix<float, 3, 3, Eigen::RowMajor> &M, GLenum type,
                  void *offset);
  // Binds the VAO
  void Bind();
  // Unbinds the VAO
  void Unbind();
  // Deletes the VAO
  void Delete();
};
