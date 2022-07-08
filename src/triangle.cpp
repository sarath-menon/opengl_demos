#include "triangle.hpp"

Triangle::Triangle(std::array<std::array<float, 2>, 3> &vertices) {

  // Set triangle coordinates
  vertices_[0] = vertices[0][0];
  vertices_[1] = vertices[0][1];

  vertices_[3] = vertices[1][0];
  vertices_[4] = vertices[1][1];

  vertices_[6] = vertices[2][0];
  vertices_[7] = vertices[2][1];
};
