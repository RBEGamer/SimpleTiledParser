//
//  tmx_manager.cpp
//  tiled_loader
//
//  Created by Marcel Ochsendorf on 03.04.16.
//  Copyright © 2016 Marcel Ochsendorf. All rights reserved.
//

#include "tmx_manager.hpp"



tmx_manager::tmx_manager(bool _running,int _w,int _h,float _fov,float _fps,std::string _title){
    is_running = _running;
    _window = glfwGetCurrentContext();
    render_system = &tmx_render_system::get_tmx_render_system();
    
    window_widht = _w;
    window_widht = _h;
    window_fov = _fov;
    max_fps = _fps;
    window_title = _title;
    
   //GET FRAMESIZE
    glfwGetFramebufferSize(_window, &framesize_width, &framesize_height);
    glViewport(0, 0, framesize_width, framesize_height);
    
    //Z BUFFER
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);
    //PRECALC MATRICES
    render_system->create_matrices(_fov, _w, _h, 0.1f, 1000.0f);
    
}


tmx_manager::~tmx_manager(){
    
    tmx_render_system::destroy_tmx_render_system();
}


void tmx_manager::run_main_loop(){
    time_delta_time = 0.0f;
    frame_counter = 0;
    run_timer = 0;
    while (is_running) {
        //STORE FRAME START TIME
        time_frame_start = glfwGetTime();
        frame_counter++;
        is_running = !glfwWindowShouldClose(_window);
        //simple fps limiter
        if(current_time_fps >= max_fps){
            
            //DRAW HERE STUFF
            //MAKE PHYSICS
           
            //RENDER
            render_system->render(time_delta_time, run_timer);
            //RESET VARS
             current_time_fps = 0;
            frame_counter = 0;
            
        }
        frame_counter++;
        //GRAB EVENTS
        glfwPollEvents();
        //STORE END TIME
        time_frame_end = glfwGetTime();
        time_delta_time = time_frame_end - time_frame_start;
        run_timer += time_delta_time;
        //reset timer if limit
        if(run_timer >= std::numeric_limits<float>::max()){
            run_timer = 0;
            std::cout << "reset run timer" << std::endl;
        }
        current_time_fps += time_delta_time ;
    }
}

tmx_manager& tmx_manager::getManagerInstance(){
    static tmx_manager* curr_instance = NULL;
    if(curr_instance == NULL){
        //INIT GLFW
        GLFWwindow* glfw_window = NULL;
        if( !glfwInit() )
        {
            fprintf( stderr, "Failed to initialize GLFW\n" );
            getchar();
            exit(2);
        }
        //SET WINDOW HINTS
        //glfwWindowHint(GLFW_SAMPLES, 4);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 2);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);
        //glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); // To make MacOS happy; should not be needed
        //glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
        //SET DAFUALTS
        float s_max_fps = 1.0f/30.0f;
        int s_window_height =240;
        int s_window_widht = 320;
        float s_window_fov = 75.0f;
        std::string s_window_title = "CONFIG NOT FOUND";
        //LOAD CONGIG FILE
        tmx_ini_loader* tmx_ini_loader = new tmx_ini_loader::tmx_ini_loader();
        tmx_ini_loader->load_ini_file("config.ini");
        s_max_fps = 1.0f/atof(tmx_ini_loader->get_value("window", "fps").c_str());
        s_window_widht =atoi(tmx_ini_loader->get_value("window", "window_width").c_str());
        if(s_window_widht < 1){s_window_widht = 1;}
        s_window_height = atoi(tmx_ini_loader->get_value("window", "window_height").c_str());
        if(s_window_height < 1){s_window_height = 1;}
        s_window_fov = atof(tmx_ini_loader->get_value("window", "window_fov").c_str());
        if(s_window_widht < 1.0f){s_window_widht = 1.0f;}
        s_window_title =tmx_ini_loader->get_value("window", "window_title");
        if(s_window_title == ""){s_window_title = "CONFIG LOAD ERROR";}
        //GET MONITORS
        int monitor_count;
        int curr_monitor = 0;
        curr_monitor =atoi(tmx_ini_loader->get_value("window", "monitor").c_str());
        GLFWmonitor** monitors = glfwGetMonitors(&monitor_count);
        if(curr_monitor > monitor_count){curr_monitor = 0;}
        //CREATE WINDOW
        glfw_window = glfwCreateWindow(s_window_widht, s_window_height, s_window_title.c_str(), monitors[1], NULL);
        
        ///CHECK WINDOW STATE
        if(glfw_window == NULL){
            fprintf( stderr, "Failed to open GLFW window. If you have an Intel GPU, they are not 3.3 compatible. Try the 2.1 version of the tutorials.\n" );
            getchar();
            glfwTerminate();
            exit(3);
        }
        //set opengl context
        glfwMakeContextCurrent(glfw_window);
        glfwSetWindowPos(glfw_window, 10, 10);
        //CREATE MANAGER INSTANCE
        curr_instance =new tmx_manager(true, s_window_widht, s_window_height, s_window_fov, s_max_fps, s_window_title);
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