#version 410 core
// take input pos of vec3 type at location 0
layout(location = 0) in vec3 pos;

uniform mat4 modelview;
uniform mat4 proj;

// opengl recognises as output, vertex position
void main() { gl_Position = proj * modelview * vec4(pos, 1.0); }
// void main() { gl_Position = vec4(pos, 1.0); }
