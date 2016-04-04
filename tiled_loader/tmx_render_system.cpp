//
//  tmx_render_system.cpp
//  tiled_loader
//
//  Created by Marcel Ochsendorf on 04.04.16.
//  Copyright © 2016 Marcel Ochsendorf. All rights reserved.
//

#include "tmx_render_system.hpp"

tmx_render_system::tmx_render_system(){
    _window = glfwGetCurrentContext();
}
tmx_render_system::~tmx_render_system(){
}

tmx_render_system&  tmx_render_system::get_tmx_render_system(){
    static tmx_render_system * render_system = NULL;
    
    if(render_system == NULL){
        render_system = new tmx_render_system();
        glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    }
    return *render_system;
}
void tmx_render_system::destroy_tmx_render_system(){
    tmx_render_system* curr_render_system = &get_tmx_render_system();
    delete curr_render_system;
}


void tmx_render_system::render(){
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    
    
    
    glfwSwapBuffers(_window);
    glfwPollEvents();
}