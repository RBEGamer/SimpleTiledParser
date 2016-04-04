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

    
    GLuint _vertex_buffer_id; //memoryid bufferid
    
    
    
public:
    
    
    GLuint tmx_get_vertex_buffer();
    
    tmx_vertex_buffer(const GLvoid* _data, GLsizeiptr _size);
    ~tmx_vertex_buffer();

};
#endif /* tmx_vertex_buffer_hpp */
