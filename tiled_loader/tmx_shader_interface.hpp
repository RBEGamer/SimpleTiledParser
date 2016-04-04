//
//  tmx_shader_interface.hpp
//  tiled_loader
//
//  Created by Marcel Ochsendorf on 04.04.16.
//  Copyright © 2016 Marcel Ochsendorf. All rights reserved.
//

#ifndef tmx_shader_interface_hpp
#define tmx_shader_interface_hpp

#include <stdio.h>
//#include "../glfw/include/GLFW/glfw3.h"
#include "tmx_shader_loader.hpp"

class tmx_shader_interface{

public:
    
    tmx_shader_interface(char* _vs, char* _fs);
    ~tmx_shader_interface();
    
    
    
    GLuint get_program_handle();
    GLint get_a_position_vertex();
    GLint get_u_color();
    
private:
    tmx_shader_loader* shader;
    
    GLuint aPositionVertex;
    GLint uColor;


};


#endif /* tmx_shader_interface_hpp */
