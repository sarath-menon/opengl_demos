#pragma once

#include "gl_common.hpp"
#include "shader.hpp"
#include "simple_model.hpp"
#include <cmath>

class Cube : public SimpleModel {

private:
  // length of each side
  float scale_{};

public:
  // Equilateral triangle given starting coord and side length
  Cube(const gl::V3 coord, const Shader &shader);
};
