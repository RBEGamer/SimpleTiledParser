//
//  tmx_shader_interface.cpp
//  tiled_loader
//
//  Created by Marcel Ochsendorf on 04.04.16.
//  Copyright © 2016 Marcel Ochsendorf. All rights reserved.
//

#include "tmx_shader_interface.hpp"



tmx_shader_interface::tmx_shader_interface(const char* _vs,const char* _fs){
    std::cout << "loading shader :" << _vs << " " << _fs << std::endl;
    vertext_shader_string = load_text_from_file(_vs);
    fragment_shader_string = load_text_from_file(_fs);
    if(_vs == NULL || _fs == NULL){
        std::cout << "_VS or _FS file seems to be empty" << std::endl;
    }
    shader = new tmx_shader_loader(vertext_shader_string, fragment_shader_string);

    aPositionVertex = glGetAttribLocation(shader->get_progam_handle(), "aPositionVertex");
    uColor = glGetUniformLocation(shader->get_progam_handle(),"uColor");
    
    if(aPositionVertex < 0){
        std::cout << "SHADER CANT FIND ATTRIBUTE" << std::endl;
    }
    if(uColor < 0){
        std::cout << "SHADER CANT FIND UNIFORM" << std::endl;
    }
    

}

tmx_shader_interface::~tmx_shader_interface(){
    delete  shader;
    free(vertext_shader_string);
    free(fragment_shader_string);
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

char* tmx_shader_interface::load_text_from_file(const char* _path){
    FILE* current_file_handle = fopen(_path, "rt");
    fseek(current_file_handle, 0, SEEK_END);
    int count = (int)ftell(current_file_handle);
    rewind(current_file_handle);
    char* data =(char*)malloc(sizeof(char)* (count+1));
    count = (int)fread(data, sizeof(char), count, current_file_handle);
    data[count] = '\0';
    fclose(current_file_handle);
    return data;
}