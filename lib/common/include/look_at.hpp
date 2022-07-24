#pragma once
#include "type_aliases.hpp"
#include <cmath>

namespace gl {

static auto lookAt(const gl::V3 &position, const gl::V3 &lookat,
                   const gl::V3 &up) {
  // x, y and z axes.
  const gl::V3 view_z = (position - lookat).normalized();
  const gl::V3 view_x = up.cross(view_z).normalized();
  const gl::V3 view_y = view_z.cross(view_x).normalized();

  const gl::M3 R = (gl::M3() << view_x, view_y, view_z).finished();

  return (gl::M4() << R.transpose(), -R.transpose() * position,
          Eigen::RowVector3f::Zero(), 1.0f)
      .finished();
}

} // namespace gl