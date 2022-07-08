#pragma once
#include <array>
#include <glad/glad.h>
#include <glm/glm.hpp>
#include <string>

class Square {

public:
  Triangle(std::array<std::array<float, 2>, 3> &vertices,
           std::array<std::array<float, 3>, 3> &colours);

  auto &get_vertices() { return vertices_; }

private:
  // Vertices coordinates
  GLfloat vertices_[18]{};
};
