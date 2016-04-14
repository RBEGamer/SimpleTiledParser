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

#include "glfw_include.h"
//#include "tmx_manager.hpp"
#include <iostream>
#include <vector>
#include "tmx_model_buffer.hpp"

class tmx_render_system{
public:
    tmx_render_system();
    ~tmx_render_system();
    GLFWwindow* _window;
    
    
   // tmx_model_buffer* modelbuffer;
    
    
   // tmx_model_buffer* modelbuffer_1;

    
    std::vector<tmx_model_buffer *> *modelbuffers;
    
         
    static tmx_render_system&  get_tmx_render_system();
    static void destroy_tmx_render_system();
    
    
    void render(float _delta_time, float _run_timer);

    void create_matrices(float _fov,float _w, float _h, float _near, float _far);
};
#endif /* tmx_render_system_hpp */
