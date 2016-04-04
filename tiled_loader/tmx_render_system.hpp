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
#include "../glfw/include/GLFW/glfw3.h"
class tmx_render_system{
public:
    tmx_render_system();
    ~tmx_render_system();
    GLFWwindow* _window;
    static tmx_render_system&  get_tmx_render_system();
    static void destroy_tmx_render_system();
    
    
    void render();

    
};
#endif /* tmx_render_system_hpp */
