//
//  tmx_vertex_buffer.cpp
//  tiled_loader
//
//  Created by Marcel Ochsendorf on 04.04.16.
//  Copyright © 2016 Marcel Ochsendorf. All rights reserved.
//

#include "tmx_vertex_buffer.hpp"


tmx_vertex_buffer::tmx_vertex_buffer(const GLvoid* _data, GLsizeiptr _size){
    glGenBuffers(1, &_vertex_buffer_id);
    glBindBuffer(GL_ARRAY_BUFFER, _vertex_buffer_id);
    glBufferData(GL_ARRAY_BUFFER, _size, _data, GL_STATIC_DRAW);
}

GLuint tmx_vertex_buffer::tmx_get_vertex_buffer(){
    return _vertex_buffer_id;
}

tmx_vertex_buffer::~tmx_vertex_buffer(){
    glDeleteBuffers(1, &_vertex_buffer_id);
    _vertex_buffer_id = 0;
}