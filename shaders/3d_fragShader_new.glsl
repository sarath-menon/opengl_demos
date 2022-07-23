#version 410 core

// Outputs colors in RGBA
out vec4 FragColor;

in vec4 varying_colour;

void main() {
  // single colour
  FragColor = vec4(0.67f, 0.84f, 0.90f, 1.0f);
  // varying colour
  FragColor = varying_colour;
}