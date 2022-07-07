#include "glfw_helper.hpp"

int main() {

  GLFWHelper app;
  auto window = app.get_window();

  // Shaders ------------------------------------------------------------

  // Create reference to access vertex shader
  GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
  // Attach Vertex Shader source to the Vertex Shader Object, 1-> one screen
  glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
  // Compile the Vertex Shader into machine code for GPU
  glCompileShader(vertexShader);

  // Create reference to access fragment shader
  GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
  // Attach Fragment Shader source to the Fragment Shader Object, 1-> one screen
  glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
  // Compile the Fragment Shader into machine code for GPU
  glCompileShader(fragmentShader);

  // Create Shader Program Object and get its reference
  GLuint shaderProgram = glCreateProgram();
  // Attach the Vertex and Fragment Shaders to the Shader Program
  glAttachShader(shaderProgram, vertexShader);
  glAttachShader(shaderProgram, fragmentShader);
  // Wrap-up/Link all the shaders together into the Shader Program
  glLinkProgram(shaderProgram);

  // Delete the now useless Vertex and Fragment Shader objects
  glDeleteShader(vertexShader);
  glDeleteShader(fragmentShader);

  // ------------------------------------------------------------------------------

  // Vertices coordinates
  GLfloat vertices[] = {
      -0.5f, -0.5f * float(sqrt(3)) / 3,    0.0f, // Lower left corner
      0.5f,  -0.5f * float(sqrt(3)) / 3,    0.0f, // Lower right corner
      0.0f,  0.5f * float(sqrt(3)) * 2 / 3, 0.0f  // Upper corner
  };

  // Pack data into buffers to send to GPU

  // Create reference containers for the Vartex Array Object and the Vertex
  // Buffer Object
  GLuint VAO, VBO;

  // Generate the VAO and VBO with only 1 object each
  glGenVertexArrays(1, &VAO);
  glGenBuffers(1, &VBO);

  // Make the VAO the current Vertex Array Object by binding it
  glBindVertexArray(VAO);

  // Bind the VBO specifying it's a GL_ARRAY_BUFFER
  glBindBuffer(GL_ARRAY_BUFFER, VBO);
  // Introduce the vertices into the VBO
  glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

  // Configure the Vertex Attribute so that OpenGL knows how to read the VBO
  glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void *)0);
  // Enable the Vertex Attribute so that OpenGL knows to use it
  glEnableVertexAttribArray(0);

  // Bind both the VBO and VAO to 0 so that we don't accidentally modify the VAO
  // and VBO we created
  glBindBuffer(GL_ARRAY_BUFFER, 0);
  glBindVertexArray(0);

  //  Render loop: show window till close button is pressed
  while (!glfwWindowShouldClose(window)) {

    // Inputs
    app.processInput(window);

    // rendering commands here~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

    // set colour
    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
    // set back buffer colour
    glClear(GL_COLOR_BUFFER_BIT);

    // Process events~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

    // Tell OpenGL which Shader Program we want to use
    glUseProgram(shaderProgram);
    // Bind the VAO so OpenGL knows to use it
    glBindVertexArray(VAO);
    // Draw the triangle using the GL_TRIANGLES primitive
    glDrawArrays(GL_TRIANGLES, 0, 3);
    // Swap the back buffer with the front buffer
    glfwSwapBuffers(window);

    // process events, such as close button pressed
    glfwPollEvents();
  }

  // Delete all the objects we've created
  glDeleteVertexArrays(1, &VAO);
  glDeleteBuffers(1, &VBO);
  glDeleteProgram(shaderProgram);
  // Delete window before ending the program
  glfwDestroyWindow(window);
  // Terminate GLFW before ending the program
  glfwTerminate();
  return 0;
}
