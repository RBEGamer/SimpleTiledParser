attribute  vec3 aPositionVertex;

void main(){
    
    glPosition = gl_ModelViewProjectionMatrix * aPositionVertex;
    
    
}