#version 410 core
// take input pos of vec3 type at location 0
layout(location = 0) in vec3 pos;

uniform mat4 model;
uniform mat4 view;
uniform mat4 proj;

// opengl recognises as output, vertex position
void main() { gl_Position = vec4(pos.x, pos.y, pos.z, 1.0); }