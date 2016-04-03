//
//  tmx_manager.cpp
//  tiled_loader
//
//  Created by Marcel Ochsendorf on 03.04.16.
//  Copyright © 2016 Marcel Ochsendorf. All rights reserved.
//

#include "tmx_manager.hpp"

tmx_manager::tmx_manager(){

}


tmx_manager::~tmx_manager(){


}

tmx_manager& tmx_manager::getManagerInstance(){
    static tmx_manager* curr_instance = NULL;
    if(curr_instance == NULL){
    //DO OPENGL INIT HERE
        glfwInit();
        GLFWwindow* glfw_window = NULL;
        //TODO ADD INI PARSER
        glfw_window = glfwCreateWindow(glfw_window_settings.screen_w, glfw_window_settings.screen_h, glfw_window_settings.window_title.c_str(), NULL, NULL);
        //set opengl context
        glfwMakeContextCurrent(glfw_window);
        
        curr_instance =new tmx_manager();
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
    glfwTerminate();
    //SHUTDOWN
}