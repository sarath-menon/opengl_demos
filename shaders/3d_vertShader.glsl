#version 410 core
// take input pos of vec3 type at location 0
layout(location = 0) in vec3 pos;

uniform mat4 model;
uniform mat4 cam_view;

out vec4 varying_colour;

// opengl recognises as output, vertex position
void main() {
  gl_Position = cam_view * model * vec4(pos, 1.0);
  varying_colour = vec4(pos, 1.0) * 0.5 + vec4(0.5, 0.5, 0.5, 0.5);
}
