//
//  tmx_vertex_buffer.cpp
//  tiled_loader
//
//  Created by Marcel Ochsendorf on 04.04.16.
//  Copyright © 2016 Marcel Ochsendorf. All rights reserved.
//

#include "tmx_vertex_buffer.hpp"


tmx_vertex_buffer::tmx_vertex_buffer(const GLvoid* _data, GLsizeiptr _size, GLenum _mode, GLsizei _count, GLsizei _stride){
    
    glstride = _stride;
    glmode = _mode;
    glcount = _count;
    
    
    glGenBuffers(1, &_vertex_buffer_id);
    glBindBuffer(GL_ARRAY_BUFFER, _vertex_buffer_id); //use buffer now the to current buffer
    glBufferData(GL_ARRAY_BUFFER, _size, _data, GL_STATIC_DRAW); //store data in
}

GLuint tmx_vertex_buffer::tmx_get_vertex_buffer(){
    return _vertex_buffer_id;
}

tmx_vertex_buffer::~tmx_vertex_buffer(){
    glDeleteBuffers(1, &_vertex_buffer_id);
    _vertex_buffer_id = 0;
}


void tmx_vertex_buffer::tmx_reder_vertex_buffer(){
    glDrawArrays(glmode,  0, glcount);
}

void tmx_vertex_buffer::tmx_configure_vertex_attributes(GLint _vertex_pos){
    if(_vertex_pos != -1){
        glEnableVertexAttribArray(_vertex_pos);
        glVertexAttribPointer(_vertex_pos, 3, GL_FLOAT, GL_FALSE, glstride, NULL); //set vertex desc
    }
}
