#include "triangle.hpp"

Triangle::Triangle(std::array<std::array<float, 2>, 3> &vertices,
                   std::array<std::array<float, 3>, 3> &colours) {

  // Set triangle coordinates
  vertices_[0] = vertices[0][0];
  vertices_[1] = vertices[0][1];

  vertices_[6] = vertices[1][0];
  vertices_[7] = vertices[1][1];

  vertices_[12] = vertices[2][0];
  vertices_[13] = vertices[2][1];

  // set vertex colours
  vertices_[3] = colours[0][0];
  vertices_[4] = colours[0][1];
  vertices_[5] = colours[0][2];

  vertices_[9] = colours[1][0];
  vertices_[10] = colours[1][1];
  vertices_[11] = colours[1][2];

  vertices_[15] = colours[2][0];
  vertices_[16] = colours[2][1];
  vertices_[17] = colours[2][2];
};
