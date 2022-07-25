#pragma once
#include <Eigen/Dense>

namespace gl {

// vectors
using V3 = Eigen::Vector3f;
using V4 = Eigen::Vector4f;

// static matrix
using M3 = Eigen::Matrix3f;
using M3 = Eigen::Matrix3f;
using M4 = Eigen::Matrix4f;

// dynamic matrices
using M2DC = Eigen::Matrix<float, 2, Eigen::Dynamic, Eigen::RowMajor>;
using M3DC = Eigen::Matrix<float, 3, Eigen::Dynamic, Eigen::RowMajor>;

using A3 = Eigen::Affine3f;

// rotation transformations
using Q = Eigen::Quaternionf;

} // namespace gl
