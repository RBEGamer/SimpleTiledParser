//
//  tmx_vertex_buffer.hpp
//  tiled_loader
//
//  Created by Marcel Ochsendorf on 04.04.16.
//  Copyright © 2016 Marcel Ochsendorf. All rights reserved.
//

#ifndef tmx_vertex_buffer_hpp
#define tmx_vertex_buffer_hpp

#include <stdio.h>
#include "../glfw/include/GLFW/glfw3.h"

class tmx_vertex_buffer{

private:
    
    GLuint _vertex_buffer_id; //memoryid bufferid
    
    GLenum glmode;
    GLsizei glcount;
    GLsizei glstride;
    
public:
    
    
    GLuint tmx_get_vertex_buffer();
    
    tmx_vertex_buffer(const GLvoid* _data, GLsizeiptr _size, GLenum _mode, GLsizei _count, GLsizei _stride);
    ~tmx_vertex_buffer();
    
    void tmx_reder_vertex_buffer();
    void tmx_configure_vertex_attributes(GLint _vertex_pos);
    
    

};
#endif /* tmx_vertex_buffer_hpp */
