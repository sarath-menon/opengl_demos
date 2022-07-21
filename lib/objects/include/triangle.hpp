#pragma once
//
#include <glad/glad.h>
//

#include <array>
#include <eigen3/Eigen/Dense>
#include <eigen3/unsupported/Eigen/OpenGLSupport>
#include <glm/glm.hpp>
#include <string>

class Triangle {

private:
  constexpr static int edges_ = 3;

  Eigen::Vector3f x, y;
  Eigen::Matrix3f rot;

public:
  Triangle(std::array<std::array<float, 2>, edges_> &vertices,
           std::array<std::array<float, 3>, edges_> &colours);

  Triangle();

  auto &get_vertices() { return vertices_; }

  // Vertices coordinates
  GLfloat vertices_[6 * edges_]{};
};
