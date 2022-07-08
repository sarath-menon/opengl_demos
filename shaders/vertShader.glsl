#version 410 core
// take input aPos of vec3 type at location 0
layout(location = 0) in vec3 aPos;
layout(location = 1) in vec3 aColour;

// output colours from vertex shader to fragment shader
out vec3 colour;

uniform float scale;

// opengl recognises as output, vertex position
void main() {
  gl_Position = vec4(aPos.x * scale, aPos.y * scale, aPos.z * scale, 1.0);
  colour = aColour;
}