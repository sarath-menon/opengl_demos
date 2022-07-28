#include "simple_model.hpp"

// SimpleModel::SimpleModel(Shader &shader) {
//   model_loc = glGetUniformLocation(shader.getHandle(), "model");
// }

void SimpleModel::set_vertex_buffers() {

  // safety checks
  assert(vertices_.size() != 0);
  assert(indices_.size() != 0);

  vb[0].set_vertices(vertices_);

  eb.set_indices(indices_);
  // Link VBO to  VAO
  va.set_vertex_attrb_ptrs(vb[0], 0, GL_FLOAT);
  va.Unbind();
  eb.Unbind();
}

void SimpleModel::display() const {
  va.Bind();
  glDrawElements(GL_TRIANGLES, indices_.size(), GL_UNSIGNED_INT, 0);
}

void SimpleModel::set_global_pose(const gl::A3 &pose) { global_pose_ = pose; }

void SimpleModel::set_global_position(const gl::V3 pos) {
  global_pose_.translation() = pos;
}

void SimpleModel::set_global_orientation(const gl::Q quat) {
  global_pose_.linear() = quat.toRotationMatrix();
}

void SimpleModel::global_rotate_x(const float angle) {
  Rot::axis(global_pose_, axis::x, angle);
}

void SimpleModel::global_rotate_y(const float angle) {
  Rot::axis(global_pose_, axis::y, angle);
}

void SimpleModel::global_rotate_z(const float angle) {
  Rot::axis(global_pose_, axis::z, angle);
}

void SimpleModel::set_scale(const float scale) {
  scale_ = scale;
  vertices_ = vertices_ * scale;
}