#pragma once
#include <array>
#include <glad/glad.h>
#include <glm/glm.hpp>
#include <string>

class Triangle {

private:
  constexpr static int edges_ = 3;

public:
  Triangle(std::array<std::array<float, 2>, edges_> &vertices,
           std::array<std::array<float, 3>, edges_> &colours);

  auto &get_vertices() { return vertices_; }

  // Vertices coordinates
  GLfloat vertices_[6 * edges_]{};
};
