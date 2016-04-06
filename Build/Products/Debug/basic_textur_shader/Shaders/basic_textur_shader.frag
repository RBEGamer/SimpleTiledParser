#version 400


uniform sampler2D tex;


// Input variables
in vec2 FragTexcoord;


// Output variables
out vec4 OutputColor;

void main(void)
{
  OutputColor  = texture2D(tex,FragTexcoord);
}
