//
//  tmx_model_buffer.cpp
//  tiled_loader
//
//  Created by Marcel Ochsendorf on 09.04.16.
//  Copyright © 2016 Marcel Ochsendorf. All rights reserved.
//

#include "tmx_model_buffer.hpp"


tmx_model_buffer::tmx_model_buffer(GLint _shader_id = 0){

    //load all identies
    local_model_matrix = glm::mat4(1.0f);
    translate_matrix = glm::mat4(1.0f);
    scale_matrix = glm::mat4(1.0f);
    roation_matrix = glm::mat4(1.0f);
    //precalc normal matrix
    calc_local_matrix();
    
    shader_program_id = _shader_id;
    
    vertexbuffer_attr_pointer = glGetAttribLocation(_shader_id, "VERTICES");
    uvbuffer_attr_pointer = glGetAttribLocation(_shader_id, "UV");
    normalbuffer_attr_pointer = glGetAttribLocation(_shader_id, "NORMAL");
    

    
    render_object = true;
    
}


tmx_model_buffer::~tmx_model_buffer(){
    glDeleteBuffers(1, &vertexbuffer);
    glDeleteBuffers(1, &uvBuffer);
    glDeleteBuffers(1, &normalBuffer);
}


void tmx_model_buffer::set_shader_id(GLint _shaderid){
shader_program_id = _shaderid;
}


void tmx_model_buffer::load_obj(const char* _path){
    //clear buffers
    vertex_buffer_data.clear();
    uv_buffer_data.clear();
    normal_buffer_data.clear();
    
    
    tmx_obj_loader* loader = new tmx_obj_loader();
    if(loader->loadOBJ(_path, vertex_buffer_data, uv_buffer_data, normal_buffer_data))
    {
        std::cout << " OBJ :" << _path << " VERTICES:" << vertex_buffer_data.size() << " UVS:" << uv_buffer_data.size() << " NORMALS:" << normal_buffer_data.size() << std::endl;
        gen_buffers();
    }else{
        std::cout << "cant load obj file :" << _path << std::endl;
    }
    delete loader;
}



void tmx_model_buffer::fill_buffers(std::vector<glm::vec3> _vertices, std::vector<glm::vec2> _uvs, std::vector<glm::vec3>){
    //clear buffers
    vertex_buffer_data.clear();
    uv_buffer_data.clear();
    normal_buffer_data.clear();
    //set new data
    vertex_buffer_data = _vertices;
    uv_buffer_data = _uvs;
    normal_buffer_data = _vertices;
    //refresh shader buffer
    gen_buffers();
}


void tmx_model_buffer::gen_buffers(){
    //VERTEX BUFFER
    vertex_size = 3;
    vertex_count = vertex_buffer_data.size();
    glGenBuffers(1, &vertexbuffer);
    glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
    glBufferData(GL_ARRAY_BUFFER,vertex_buffer_data.size() * sizeof(glm::vec3), &vertex_buffer_data[0], GL_STATIC_DRAW);
    //UV BUFFER
    uv_size = 2;
    uv_count = uv_buffer_data.size();
    glGenBuffers(1, &uvBuffer);
    glBindBuffer(GL_ARRAY_BUFFER, uvBuffer);
    glBufferData(GL_ARRAY_BUFFER, uv_buffer_data.size() * sizeof(glm::vec2), &uv_buffer_data[0], GL_STATIC_DRAW);
    //NORMAL BUFFER
    normal_size = 3;
    normal_count = normal_buffer_data.size();
    glGenBuffers(1, &normalBuffer);
    glBindBuffer(GL_ARRAY_BUFFER, normalBuffer);
    glBufferData(GL_ARRAY_BUFFER, normal_buffer_data.size() * sizeof(glm::vec3), &normal_buffer_data[0], GL_STATIC_DRAW);
}

void tmx_model_buffer::render_vertex_buffer(){
    if(!render_object){return;}
    if(vertex_count <=0 ){return;}
    glEnableVertexAttribArray(vertexbuffer_attr_pointer); //  ENABLE VERTICES
    glEnableVertexAttribArray(uvbuffer_attr_pointer); //ENABLE UV
    glEnableVertexAttribArray(normalbuffer_attr_pointer); //ENABLE NROMAL
    
    //SEND VERTEX DATA
    glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
    glVertexAttribPointer(
                          vertexbuffer_attr_pointer, // The attribute we want to configure
                          vertex_size,                  // size
                          GL_FLOAT,           // type
                          GL_FALSE,           // normalized?
                          0,                  // stride
                          (void*)0            // array buffer offset
                          );
    
    //SEND UV BUFFER
    glBindBuffer(GL_ARRAY_BUFFER, uvBuffer);
    glVertexAttribPointer(
                          uvbuffer_attr_pointer, // The attribute we want to configure
                          uv_size,                  // size
                          GL_FLOAT,           // type
                          GL_FALSE,           // normalized?
                          0,                  // stride
                          (void*)0            // array buffer offset
                          );
    
    //SEND UV BUFFER
    glBindBuffer(GL_ARRAY_BUFFER, normalBuffer);
    glVertexAttribPointer(
                          normalbuffer_attr_pointer, // The attribute we want to configure
                          normal_size,                  // size
                          GL_FLOAT,           // type
                          GL_FALSE,           // normalized?
                          0,                  // stride
                          (void*)0            // array buffer offset
                          );

    
    
    
    
    
    
    // Draw the triangle !
    glDrawArrays(GL_TRIANGLES, 0, vertex_buffer_data.size() ); // 3 indices starting at 0 -> 1 triangle
    glDisableVertexAttribArray(vertexbuffer_attr_pointer);
    glDisableVertexAttribArray(uvbuffer_attr_pointer);
    glDisableVertexAttribArray(normalbuffer_attr_pointer);
}

void tmx_model_buffer::rotate_around(float _angle, glm::vec3 _dir){
    current_roation = _dir * _angle;
    scale_matrix =glm::mat4(1.0f);
    roation_matrix = glm::rotate(scale_matrix, _angle, _dir);
    calc_local_matrix();
}

void tmx_model_buffer::set_position(glm::vec3 _new_pos){
    current_position = _new_pos;
    translate_matrix =glm::mat4(1.0f);
    translate_matrix =glm::translate(_new_pos);
    calc_local_matrix();
}

void tmx_model_buffer::set_scale(glm::vec3 _new_scale){
    current_scale = _new_scale;
    scale_matrix = glm::mat4(1.0f);
    scale_matrix = glm::scale(scale_matrix, _new_scale);
    calc_local_matrix();
}

void tmx_model_buffer::calc_local_matrix(){
    translate_matrix =glm::mat4(1.0f);
    translate_matrix = glm::translate(translate_matrix, current_position);
    local_model_matrix = translate_matrix* (scale_matrix * roation_matrix);
    
}


glm::mat4 tmx_model_buffer::get_local_matrix(){
    return local_model_matrix;
}



glm::vec3 tmx_model_buffer::get_roation(){
    return current_roation;
}

glm::vec3 tmx_model_buffer::get_scale(){
    return current_scale;
}

glm::vec3 tmx_model_buffer::get_position(){
    return  current_position;
}