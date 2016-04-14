#version 120


varying vec2 v_UV;
varying vec3 v_NORMAL;

varying float v_DELTA;

void main()
{


	gl_FragColor = vec4(v_NORMAL.x,v_NORMAL.y,0,1);

}