//
//  tmx_manager.hpp
//  tiled_loader
//
//  Created by Marcel Ochsendorf on 03.04.16.
//  Copyright © 2016 Marcel Ochsendorf. All rights reserved.
//

#ifndef tmx_manager_hpp
#define tmx_manager_hpp

#include <stdio.h>
#include <cstring>
#include <iostream>
#include <stdlib.h>
#include "../glfw/include/GLFW/glfw3.h"
#include "tmx_ini_parser.hpp"
#include "tmx_render_system.hpp"
#include "tmx_vertex_buffer.hpp"
class tmx_manager{
public:
    tmx_manager(bool _running = true);
    ~tmx_manager();

    
    
    
    
     static  tmx_manager& getManagerInstance();
    static void destroyTmxManager();
    void run_main_loop();
    

    
    bool is_running;
    GLFWwindow* _window;
    tmx_vertex_buffer* vertex_buffer;
    
    
    tmx_render_system* _render_system;
    
    
    struct window_settings{
        int screen_w;
        int screen_h;
        float aspect_ratio;
        
    
    };
};


#endif /* tmx_manager_hpp */
