//
//  tmx_shader_loader.hpp
//  tiled_loader
//
//  Created by Marcel Ochsendorf on 04.04.16.
//  Copyright © 2016 Marcel Ochsendorf. All rights reserved.
//

#ifndef tmx_shader_loader_hpp
#define tmx_shader_loader_hpp

#include <stdio.h>

#include <iostream>
#include "glfw_include.h"


class tmx_shader_loader{
private:
    
    GLuint _program_handle;
    
    GLuint compile_shader(GLenum _target, const char* _source);
public:
    tmx_shader_loader(const char* _source_vs, const char* _source_fs);
    ~tmx_shader_loader();

    GLuint get_progam_handle();
};
#endif /* tmx_shader_loader_hpp */
