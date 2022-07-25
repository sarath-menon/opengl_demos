#version 410 core

// vertices
layout(location = 0) in vec3 pos;
uniform mat4 model;
uniform mat4 cam_view;

// texture
layout(location = 1) in vec2 aTex;
// Outputs the texture coordinates to the fragment shader
out vec2 texCoord;

// opengl recognises as output, vertex position
void main() {
  gl_Position = cam_view * model * vec4(pos, 1.0);

  // for gragment shader
  texCoord = aTex;
}
