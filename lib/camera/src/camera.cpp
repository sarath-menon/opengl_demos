#include "camera.hpp"

Camera::Camera(const gl::V3 &coord) { this->set_coord(coord); }

void Camera::set_coord(const gl::V3 &coord) {
  coord_(0) = coord(0);
  coord_(1) = coord(1);
  coord_(2) = coord(2);
}