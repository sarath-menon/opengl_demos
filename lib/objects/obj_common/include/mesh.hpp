#pragma once

#include <glad/glad.h> // holds all OpenGL type declarations
//
#include "mesh_structs.hpp"
#include "shader.hpp"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <string>
#include <vector>

class Mesh {
public:
  // mesh Data
  std::vector<Vertex> vertices;
  std::vector<unsigned int> indices;
  std::vector<Texture> textures;
  unsigned int VAO;

  // constructor
  Mesh(std::vector<Vertex> vertices, std::vector<unsigned int> indices,
       std::vector<Texture> textures);

  void Draw(Shader &shader);

private:
  // render data
  unsigned int VBO, EBO;

  void setupMesh();
};
