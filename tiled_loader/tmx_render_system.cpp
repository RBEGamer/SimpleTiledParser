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
    shaders = new std::vector<tmx_shader_interface*>;
    
    //TODO LOAD ALL SHADERS
    tmx_shader_interface* color_shader = new tmx_shader_interface("basic_color_shader.vsh","basic_color_shader.fsh");
    
    shaders->push_back(color_shader);
   // delete  color_shader;
    
}
tmx_render_system::~tmx_render_system(){
    for (int i = 0; i < shaders->size(); i++) {
        delete shaders->at(i);
    }
    
    delete shaders;
}

tmx_render_system&  tmx_render_system::get_tmx_render_system(){
    static tmx_render_system * render_system = NULL;
    
    if(render_system == NULL){
        render_system = new tmx_render_system();
        glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
        glMatrixMode(GL_PROJECTION);//switch to projection matrix
        gluPerspective(75.0f, 1280.0f/720.0f, 1, 1000);
        glViewport(0.0f, 0.0f, 1280.0f, 720.0f);
        glMatrixMode(GL_MODELVIEW);
        
    }
    return *render_system;
}
void tmx_render_system::destroy_tmx_render_system(){
    tmx_render_system* curr_render_system = &get_tmx_render_system();
    delete curr_render_system;
}


void tmx_render_system::render(tmx_vertex_buffer* _vertex_buffer){
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    //GLint shader_id = shaders->at(0)->();
    glUseProgram(1); //SET SHADER
    glLoadIdentity();
    gluLookAt(0.0f, 0.0f, 5.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f);
    
    glUniform4f(0, 1.0f, 0.0f, 0.0f, 0.0f); //set  uniform at pos 0
    _vertex_buffer->tmx_configure_vertex_attributes(0);
    _vertex_buffer->tmx_reder_vertex_buffer();
    glUseProgram(0);
    glfwSwapBuffers(_window);
    glfwPollEvents();
}