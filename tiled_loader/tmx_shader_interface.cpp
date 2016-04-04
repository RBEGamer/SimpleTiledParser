//
//  tmx_shader_interface.cpp
//  tiled_loader
//
//  Created by Marcel Ochsendorf on 04.04.16.
//  Copyright © 2016 Marcel Ochsendorf. All rights reserved.
//

#include "tmx_shader_interface.hpp"



tmx_shader_interface::tmx_shader_interface(char* _vs, char* _fs){
    shader = new tmx_shader_loader(_vs, _fs);
    aPositionVertex = glGetAttribLocation(shader->get_progam_handle(), "aPositionVertex");
    uColor = glGetUniformLocation(shader->get_progam_handle(),"uColor");
}

tmx_shader_interface::~tmx_shader_interface(){
    delete  shader;
}



GLuint tmx_shader_interface::get_program_handle(){
    return shader->get_progam_handle();
}

GLint tmx_shader_interface::get_a_position_vertex(){
    return aPositionVertex;
}

GLint tmx_shader_interface::get_u_color(){
    return uColor;
}