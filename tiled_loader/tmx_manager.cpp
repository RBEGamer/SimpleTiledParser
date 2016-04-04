//
//  tmx_manager.cpp
//  tiled_loader
//
//  Created by Marcel Ochsendorf on 03.04.16.
//  Copyright © 2016 Marcel Ochsendorf. All rights reserved.
//

#include "tmx_manager.hpp"

tmx_manager::tmx_manager(bool _running){
    is_running = _running;
    _window = glfwGetCurrentContext();
    _render_system = &tmx_render_system::get_tmx_render_system();
}


tmx_manager::~tmx_manager(){

    tmx_render_system::destroy_tmx_render_system();
}


void tmx_manager::run_main_loop(){
    while (is_running) {
        //update subsystems
        is_running = !glfwWindowShouldClose(_window);

        
       
        _render_system->render();
    
    }
}

tmx_manager& tmx_manager::getManagerInstance(){
    static tmx_manager* curr_instance = NULL;
    if(curr_instance == NULL){
    //DO OPENGL INIT HERE
        glfwInit();
        GLFWwindow* glfw_window = NULL;
        //TODO ADD INI PARSER
        glfwWindowHint(GLFW_RED_BITS, 8);
        glfwWindowHint(GLFW_GREEN_BITS, 8);
        glfwWindowHint(GLFW_BLUE_BITS, 8);
        glfwWindowHint(GLFW_ALPHA_BITS, 8);
        
        // glfwWindowHint(GLFW_DEPTH_BITS, 24);
        
        
        
        tmx_ini_loader* tmx_ini_loader = new tmx_ini_loader::tmx_ini_loader();
        tmx_ini_loader->load_ini_file("config.ini");


        

        glfw_window = glfwCreateWindow(atoi(tmx_ini_loader->get_value("window", "window_width").c_str()), atoi(tmx_ini_loader->get_value("window", "window_height").c_str()), tmx_ini_loader->get_value("window", "window_title").c_str(), NULL, NULL);
        
        if(glfw_window == NULL){
        glfw_window = glfwCreateWindow(320,240, "CONIFIG NOT FOUND", NULL, NULL);
        }
        
        if(glfw_window == NULL){exit(3);}
        //set opengl context
        glfwMakeContextCurrent(glfw_window);
        
        curr_instance =new tmx_manager(true);
        delete tmx_ini_loader;
        if(curr_instance != NULL){
        std::cout << "TMX MANAGER INSTANCE CREATED" << std::endl;
        }else{
            std::cout << "FAILED TO CREATE TMX MANAGER INSTANCE" << std::endl;
            exit(1);

        }
    }
    return *curr_instance;
}


void tmx_manager::destroyTmxManager(){
    tmx_manager* curr_instance = &getManagerInstance();
    

    delete curr_instance;
    std::cout << "TMX MANAGER INSTANCE DELTED" << std::endl;
    
    GLFWwindow* current_window = glfwGetCurrentContext();
    glfwDestroyWindow(current_window);
    glfwTerminate();
    //SHUTDOWN
}