#version 410 core
// take input aPos of vec3 type at location 0
layout(location = 0) in vec3 aPos;

// opengl recognises as output, vertex position
void main() { gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0); }