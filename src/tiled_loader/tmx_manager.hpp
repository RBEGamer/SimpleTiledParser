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
#include "glfw_include.h"



#include "tmx_ini_parser.hpp"
#include "tmx_render_system.hpp"
#include <limits>
class tmx_manager{
public:
    tmx_manager(bool _running = true,int _w = 320,int _h = 240,float _fov = 65.0f,float _fps = (1.0f/60.0f),std::string _title = "NO CONFIG");
    ~tmx_manager();

    
    
    
    
    static  tmx_manager& getManagerInstance();
    static void destroyTmxManager();
    void run_main_loop();
    
    float time_frame_start;
    float time_frame_end;
     float time_delta_time;
    float run_timer;
    
     float max_fps;
    float current_time_fps;
    int frame_counter;
    
    
     int window_height;
     int window_widht;
     int window_fov;
    
    int framesize_width;
    int framesize_height;
     std::string window_title;
    bool is_running;
    GLFWwindow* _window;
  
    
    tmx_render_system* render_system;
   
    
 
};


#endif /* tmx_manager_hpp */
