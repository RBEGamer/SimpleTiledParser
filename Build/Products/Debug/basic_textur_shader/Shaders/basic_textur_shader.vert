#version 400

// Uniform Variables
uniform mat4 View;
uniform mat4 Proj;

// Input Variables
in vec3 InputPosition;
in vec2 InputTexcoord;


// Output Variables
out vec2 FragTexcoord;


void main(void)
{
  gl_Position = Proj * View * vec4(InputPosition, 1.0f);
  FragTexcoord = InputTexcoord;
}
