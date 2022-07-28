#pragma once

#include <glad/glad.h>
//
#include "gl_common.hpp"
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtx/rotate_vector.hpp>
#include <glm/gtx/vector_angle.hpp>
#include <string>

#include "shader.hpp"

class Camera {
public:
  // Stores the main vectors of the camera
  glm::vec3 position_;
  glm::vec3 orientation_ = glm::vec3(0.0f, 0.0f, -1.0f);
  glm::vec3 Up = glm::vec3(0.0f, 1.0f, 0.0f);
  glm::mat4 cam_mat = glm::mat4(1.0f);

  // Prevents the camera from jumping around when first clicking left click
  bool firstClick = true;

  // Stores the width and height of the window
  int width{};
  int height{};

  // Adjust the speed of the camera and it's sensitivity when looking around
  float speed = 0.1f;
  float sensitivity = 100.0f;

  float near_plane_ = 0.1f;
  float far_plane_ = 100.0f;
  float fov_degrees_ = 60.0_deg;

  // Camera constructor to set up initial values
  Camera(const int width, const int height, const glm::vec3 position);

  // Exports the camera matrix to a shader
  void update(const Shader &shader, const std::string &uniform_name) const;

  // Handles camera inputs
  void Inputs(GLFWwindow *window);

private:
  // Updates the camera matrices
  void updateMatrix();
};