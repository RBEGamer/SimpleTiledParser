#version 400

// Input variables
uniform vec3 uColor;

// Output variables
out vec4 OutputColor;

void main(void)
{
  //OutputColor = vec4(1,0,1,1);
  OutputColor = vec4(uColor,1);
}
