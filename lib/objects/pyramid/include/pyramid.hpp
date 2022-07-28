#pragma once

#include "gl_common.hpp"
#include "shader.hpp"
#include "simple_model.hpp"
#include <cmath>

class Pyramid : public SimpleModel {

private:
  // length of each side
  float length_{};

public:
  // Equilateral triangle given starting coord and side length
  Pyramid(const gl::V3 coord, const Shader &shader);
};
