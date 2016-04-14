#version 120



uniform mat4 MVP_MATRIX;
uniform float DELTA_TIME;
uniform vec3 CAMERA_POS;


attribute vec3 VERTICES;
attribute vec2 UV;
attribute vec3 NORMAL;



varying vec2 v_UV;
varying vec3 v_NORMAL;
varying float v_DELTA;


mat4 rotationMatrix(vec3 axis, float angle)
{
axis = normalize(axis);
float s = sin(angle);
float c = cos(angle);
float oc = 1.0 - c;

return mat4(oc * axis.x * axis.x + c,           oc * axis.x * axis.y - axis.z * s,  oc * axis.z * axis.x + axis.y * s,  0.0,
oc * axis.x * axis.y + axis.z * s,  oc * axis.y * axis.y + c,           oc * axis.y * axis.z - axis.x * s,  0.0,
oc * axis.z * axis.x - axis.y * s,  oc * axis.y * axis.z + axis.x * s,  oc * axis.z * axis.z + c,           0.0,
0.0,                                0.0,                                0.0,                                1.0);
}




void main(){
v_UV = UV;
v_NORMAL = NORMAL;
v_DELTA = DELTA_TIME;


	gl_Position = MVP_MATRIX * rotationMatrix(vec3(1,0.5f,0), DELTA_TIME)* vec4(VERTICES, 1.0);

}

