//
//  tmx_render_system.hpp
//  tiled_loader
//
//  Created by Marcel Ochsendorf on 04.04.16.
//  Copyright © 2016 Marcel Ochsendorf. All rights reserved.
//

#ifndef tmx_render_system_hpp
#define tmx_render_system_hpp


#include <stdio.h>
#define GLFW_INCLUDE_GLU
#include "../glfw/include/GLFW/glfw3.h"
#include "tmx_vertex_buffer.hpp"
#include "tmx_shader_interface.hpp"
#include <vector>

class tmx_render_system{
public:
    tmx_render_system();
    ~tmx_render_system();
    GLFWwindow* _window;
    
    std::vector<tmx_shader_interface*> *shaders;
    
    static tmx_render_system&  get_tmx_render_system();
    static void destroy_tmx_render_system();
    
    
    void render(tmx_vertex_buffer* _vertex_buffer);

    
};
#endif /* tmx_render_system_hpp */
