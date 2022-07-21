#pragma once
//
#include <glad/glad.h>
//
#include "gl_common.hpp"
#include <array>
#include <glm/glm.hpp>
#include <string>

class Triangle {

private:
  Eigen::Matrix<float, 3, 3, Eigen::RowMajor> vertices_;

public:
  Triangle(const V3 start);

  auto &get_vertices() { return vertices_; }
};

// vertices << -0.5f, -0.5f * float(sqrt(3)) / 3, 0.0f, // Lower left corner
//       0.5f, -0.5f * float(sqrt(3)) / 3, 0.0f,          // Lower right corner
//       0.0f, 0.5f * float(sqrt(3)) * 2 / 3, 0.0f;       // Upper corner
