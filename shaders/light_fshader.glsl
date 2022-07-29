#version 410 core

// Outputs colors in RGBA
out vec4 FragColor;

uniform vec4 obj_colour;

void main() { FragColor = obj_colour; }