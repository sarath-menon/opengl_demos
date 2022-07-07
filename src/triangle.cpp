#include "triangle.hpp"

Triangle::Triangle(std::array<float, 9> &vertices) {

  // Set triangle coordinates
  vertices_[0] = vertices[0];
  vertices_[1] = vertices[1];
  vertices_[2] = vertices[2];
  vertices_[3] = vertices[3];
  vertices_[4] = vertices[4];
  vertices_[5] = vertices[5];
  vertices_[6] = vertices[6];
  vertices_[7] = vertices[7];
  vertices_[8] = vertices[8];
  vertices_[9] = vertices[9];

  // Pack data into buffers to send to GPU

  // Create reference containers for the Vartex Array Object and the Vertex
  // Buffer Object

  // Generate the VAO and VBO with only 1 object each
  glGenVertexArrays(1, &VAO);
  glGenBuffers(1, &VBO);

  // Make the VAO the current Vertex Array Object by binding it
  glBindVertexArray(VAO);

  // Bind the VBO specifying it's a GL_ARRAY_BUFFER
  glBindBuffer(GL_ARRAY_BUFFER, VBO);
  // Introduce the vertices_ into the VBO
  glBufferData(GL_ARRAY_BUFFER, sizeof(vertices_), vertices_, GL_STATIC_DRAW);

  // Configure the Vertex Attribute so that OpenGL knows how to read the VBO
  glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void *)0);
  // Enable the Vertex Attribute so that OpenGL knows to use it
  glEnableVertexAttribArray(0);

  // Bind both the VBO and VAO to 0 so that we don't accidentally modify the VAO
  // and VBO we created
  glBindBuffer(GL_ARRAY_BUFFER, 0);
  glBindVertexArray(0);
};
