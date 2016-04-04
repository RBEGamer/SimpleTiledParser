//
//  tmx_shader_loader.cpp
//  tiled_loader
//
//  Created by Marcel Ochsendorf on 04.04.16.
//  Copyright © 2016 Marcel Ochsendorf. All rights reserved.
//


#include "tmx_shader_loader.hpp"



GLuint tmx_shader_loader::compile_shader(GLenum _target, const char* _source){
    GLuint shader_handle = glCreateShader(_target);
    glShaderSource(shader_handle, 1, &_source, NULL);
    glCompileShader(shader_handle);
    return shader_handle;
}

GLuint tmx_shader_loader::get_progam_handle(){
    return _program_handle;
}

tmx_shader_loader::tmx_shader_loader(const char* _source_vs, const char* _source_fs){
    _program_handle = glCreateProgram();
    GLuint vertex_shader = compile_shader(GL_VERTEX_SHADER, _source_vs);
    GLuint fragment_shader = compile_shader(GL_FRAGMENT_SHADER, _source_fs);
    glAttachShader(_program_handle, vertex_shader);
    glAttachShader(_program_handle, fragment_shader);
    glLinkProgram(_program_handle);
    
    glDeleteShader(vertex_shader);
    glDeleteShader(fragment_shader);
    
}


tmx_shader_loader::~tmx_shader_loader(){
    glDeleteProgram(_program_handle);
}