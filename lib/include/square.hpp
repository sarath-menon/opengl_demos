#pragma once
#include <array>
#include <glad/glad.h>
#include <glm/glm.hpp>
#include <string>

class Square {

private:
  constexpr static int edges_ = 4;

public:
  Square(std::array<std::array<float, 2>, edges_> &vertices,
         std::array<std::array<float, 3>, edges_> &colours);

  auto &get_vertices() { return vertices_; }

private:
  // Vertices coordinates
  GLfloat vertices_[6 * edges_]{};
};
