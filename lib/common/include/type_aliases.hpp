#pragma once
#include <eigen3/Eigen/Dense>

namespace gl {

// vectors
using V3 = Eigen::Vector3f;
using V4 = Eigen::Vector4f;

// static matrix
using M3 = Eigen::Matrix<float, 3, 3, Eigen::RowMajor>;
using M4 = Eigen::Matrix<float, 4, 4, Eigen::RowMajor>;

// dynamic matrices
using M3DC = Eigen::Matrix<float, 3, Eigen::Dynamic, Eigen::RowMajor>;

using A3 = Eigen::Affine3f;

// rotation transformations
using Q = Eigen::Quaternionf;

} // namespace gl
