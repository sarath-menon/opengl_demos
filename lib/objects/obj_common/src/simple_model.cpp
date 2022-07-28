#include "simple_model.hpp"

SimpleModel::SimpleModel(const Shader &shader) {
  model_loc = glGetUniformLocation(shader.getHandle(), "model");

  colour_loc = glGetUniformLocation(shader.getHandle(), "obj_colour");

  obj_colour = glm::vec4(0.8f, 0.3f, 0.02f, 1.0f);

  // shader needs to be activated  to set the colour
  shader.Activate();

  // copy matrix data to corresponding uniform variables
  glUniform4f(colour_loc, obj_colour.x, obj_colour.y, obj_colour.z,
              obj_colour.w);
}

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

void SimpleModel::display(const Shader &shader) const {

  // Transformation matrices
  gl::A3 model_m = gl::A3::Identity();

  // create model matrix
  model_m = global_pose_;

  // copy matrix data to corresponding uniform variables
  shader.setAff4(model_loc, model_m);

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