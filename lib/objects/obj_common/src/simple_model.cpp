#include "simple_model.hpp"

SimpleModel::SimpleModel(const Shader &shader) {

  model_loc = glGetUniformLocation(shader.getHandle(), "model");
  colour_loc = glGetUniformLocation(shader.getHandle(), "obj_colour");

  obj_colour_ = glm::vec4(0.8f, 0.3f, 0.02f, 1.0f);

  //  shader needs to be activated before setting values
  shader.Activate();

  // copy matrix data to corresponding uniform variables
  glUniform4f(colour_loc, obj_colour_.x, obj_colour_.y, obj_colour_.z,
              obj_colour_.w);

  texture = std::make_unique<Texture>(texture_dir.c_str(), GL_TEXTURE_2D,
                                      GL_TEXTURE0, GL_RGBA, GL_UNSIGNED_BYTE);

  shader.Deactivate();
}

void SimpleModel::set_colour(const glm::vec4 colour, const Shader &shader) {
  obj_colour_ = colour; //  shader needs to be activated before setting values
  shader.Activate();

  // copy matrix data to corresponding uniform variables
  glUniform4f(colour_loc, obj_colour_.x, obj_colour_.y, obj_colour_.z,
              obj_colour_.w);

  shader.Deactivate();
}

void SimpleModel::set_vertex_buffers(const Shader &shader) {

  // safety checks
  assert(vertices_.size() != 0);
  assert(indices_.size() != 0);

  vb[0].set_vertices(vertices_);
  vb[1].set_colours(colours_);
  vb[2].set_texture(texture_coord_);
  eb.set_indices(indices_);

  // load texture
  texture->texUnit(shader, "tex0", 0);

  // Link VBO to  VAO
  va.set_vertex_attrb_ptrs(vb[0], VertexData::vertices);
  va.set_vertex_attrb_ptrs(vb[1], VertexData::colours);
  va.set_vertex_attrb_ptrs(vb[2], VertexData::texture);

  // unbind after use
  va.Unbind();
  eb.Unbind();
}

void SimpleModel::display(const Shader &shader) const {

  // Transformation matrices
  gl::A3 model_m = gl::A3::Identity();

  // create model matrix
  model_m = global_pose_;

  // shader needs to be activated before setting values
  shader.Activate();

  // copy matrix data to corresponding uniform variables
  shader.setAff4(model_loc, model_m);

  va.Bind();

  glDrawElements(GL_TRIANGLES, indices_.size(), GL_UNSIGNED_INT, 0);

  va.Unbind();
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