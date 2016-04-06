attribute vec3 aPositionVertex;

void main(){
    gl_Position = gl_ProjectionMatrix * gl_ModelViewMatrix * vec4(aPositionVertex,1.0f);
    //gl_ModelViewProjection
}