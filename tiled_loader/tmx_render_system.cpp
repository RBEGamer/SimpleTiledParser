//
//  tmx_render_system.cpp
//  tiled_loader
//
//  Created by Marcel Ochsendorf on 04.04.16.
//  Copyright © 2016 Marcel Ochsendorf. All rights reserved.
//

#include "tmx_render_system.hpp"
#include "shader.hpp"



GLuint programID;
GLuint vertexPosition_modelspaceID;
GLuint vertexbuffer;

glm::mat4 MVP_MATRIX;
glm::mat4 ProjectionMatrix;
glm::mat4 ViewMatrix;
glm::mat4 ModelMatrix;


glm::vec4 main_color = glm::vec4(1,0,0,1);



void tmx_render_system::create_matrices(float _fov,float _w, float _h, float _near, float _far){
    ProjectionMatrix = glm::perspective(_fov, (_w/_h), _near, _far);
    //world space look dir, head up
    ViewMatrix = glm::lookAt(glm::vec3(0,0,-10), glm::vec3(0,0,0), glm::vec3(0,1,0));
    ModelMatrix = glm::mat4(1.0f);//indentity
    //CALC THE MVP MATRIX
    MVP_MATRIX = ProjectionMatrix * ViewMatrix * ModelMatrix;
}

//TODO ADD GEN MATRIX FUNC
    tmx_render_system::tmx_render_system(){
    _window = glfwGetCurrentContext();

        

       
     programID = LoadShaders( "SimpleVertexShader.vsh", "SimpleFragmentShader.fsh" );
    
        
    
    
    // Get a handle for our buffers
     
    
        
        tmx_model_buffer* modelbuffer = new tmx_model_buffer(programID);
        modelbuffer->set_position(glm::vec3(0,0,0));
        modelbuffer->set_scale(glm::vec3(1.0f,1.0f,1.0f));
        modelbuffer->load_bmp("cube.obj");
        
        tmx_model_buffer* modelbuffer_1 = new tmx_model_buffer(programID);
        modelbuffer_1->set_position(glm::vec3(0,0,0));
        modelbuffer_1->set_scale(glm::vec3(1,1,1));
          modelbuffer_1->load_bmp("cube.obj");
        //modelbuffer_1->render_object = false;
        
        
        modelbuffers = new std::vector<tmx_model_buffer*>;
        modelbuffers->push_back(modelbuffer);
        modelbuffers->push_back(modelbuffer_1);
        
      }






tmx_render_system::~tmx_render_system(){
    for (int i = 0; i < modelbuffers->size(); i++) {
        delete modelbuffers->at(i);
    }
    delete modelbuffers;
}

tmx_render_system&  tmx_render_system::get_tmx_render_system(){
    static tmx_render_system * render_system = NULL;

    
    if(render_system == NULL){
        render_system = new tmx_render_system();
        //SETUP OPENGL
        glClearColor(0.5f, 0.5f, 0.5f, 1.0f);
 
        
    }
    return *render_system;
}
void tmx_render_system::destroy_tmx_render_system(){
    tmx_render_system* curr_render_system = &get_tmx_render_system();
    delete curr_render_system;
}




void tmx_render_system::render(float _delta_time, float _run_timer){
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    
    
   

    
    
    //wenn shader anders als beim voherigen (id speichern dann wechseln
    
    GLint last_shader_gid = -1;
    glm::mat4 last_MVP_MAT;
    
    glUseProgram(0);

    
    
    for (int i = 0; i < modelbuffers->size(); i++) {
       if((i+1) < modelbuffers->size() && modelbuffers->at(i+1) != NULL && modelbuffers->at(i+1)->shader_program_id != last_shader_gid){
    
            last_shader_gid =modelbuffers->at(i)->shader_program_id;
                        glUseProgram(last_shader_gid);
           
           glUniform1f(glGetUniformLocation(last_shader_gid, "DELTA_TIME"), _run_timer);

           
            //SEND UNIFORMS
                }
//       ProjectionMatrix = glm::rotate(ProjectionMatrix, _run_timer, glm::vec3(1.0f,0.5f,0.2f));

       
        //CALC INDIVIDUAL MVP MATRIX if this the same the we dont neet to upload
        MVP_MATRIX = ProjectionMatrix * ViewMatrix * modelbuffers->at(i)->get_local_matrix();
        if(last_MVP_MAT != MVP_MATRIX){
               GLuint mat_id = glGetUniformLocation(last_shader_gid, "MVP_MATRIX");
        glUniformMatrix4fv(mat_id, 1, GL_FALSE, &MVP_MATRIX[0][0]);
            last_MVP_MAT = MVP_MATRIX;
        }
        modelbuffers->at(i)->render_vertex_buffer();
             }
    
    glUseProgram(0);

       //SET MVP MATRIX
    
    
    //CALC THE MVP MATRIX
   
    
    

   
    
    
    


    
    


    
    
  
    //
    // glUseProgram(0);
    glfwSwapBuffers(_window);
}