#version 400

// Uniform Variables
uniform mat4 View;
uniform mat4 Proj;

// Input Variables
in vec3 InputPosition;


// Output Variables
out vec2 FragTexcoord;
out vec3 FragNormal;
out vec4 FragColor;


void main(void)
{
  gl_Position = Proj * View * vec4(InputPosition, 1.0f);
  //gl_Position = gl_ViewProjectionMatrix

}
