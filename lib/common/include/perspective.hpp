#pragma once
#include "type_aliases.hpp"
#include <cmath>

namespace gl {

static auto perspective(float fovy, float aspect, float zNear, float zFar) {

  // safety checks
  assert(aspect > 0);
  assert(zFar > zNear);

  const float tanHalfFovy = std::tan(fovy / 2.0f);

  gl::M4 result = gl::M4::Zero();

  result(0, 0) = 1.0f / (aspect * tanHalfFovy);
  result(1, 1) = 1.0f / (tanHalfFovy);
  result(2, 2) = -(zFar + zNear) / (zFar - zNear);
  result(3, 2) = -1.0f;
  result(2, 3) = -(2.0f * zFar * zNear) / (zFar - zNear);

  return result;
}

} // namespace gl