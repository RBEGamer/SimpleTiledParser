//
//  main.cpp
//  tiled_loader
//
//  Created by Marcel Ochsendorf on 29.03.16.
//  Copyright © 2016 Marcel Ochsendorf. All rights reserved.
//

#include <iostream>
#include "tmx_manager.hpp"
#include "tmx_map.hpp"

#include "../glfw/include/GLFW/glfw3.h"





//#include "/Users/marcelochsendorf/Desktop/SimpleTiledParser/include/GLFW/glfw3.h"



/*
#include <dirent.h>
enum FILE_TYPE{
    FT_UNKNOWN, FT_BMP, FT_TMX, FT_SHADER_VS, FT_SHADER_PS
};
enum SHORT_FILE_TYPE{
    SHORT_FT_IMAGE, SHORT_FT_MAP, SHORT_FT_SHADER, SHORT_FT_OTHER
};
struct FILE_INFO{
    std::string filename;
    std::string dir;
    std::string extention;
    FILE_TYPE filetype;
    SHORT_FILE_TYPE category;

};
int listdir(const char *path) {
    struct dirent *entry;
    DIR *dp;
    
    dp = opendir(path);
    if (dp == NULL) {
        perror("opendir: Path does not exist or could not be read.");
        return -1;
    }
    char* find_ptr = NULL;
    
    while ((entry = readdir(dp)))
        find_ptr = NULL;
    
   
    
   //     find_ptr = strstr(entry->d_name, ".");
    //strcpy
    if(find_ptr == NULL){
         std::cout << "DIR : " << std::endl;
    }else{
        std::cout << "FILE : " << std::endl;
    }
    
    
    closedir(dp);
    return 0;
    
    
    //liste mit files machen wo mind 1 punkt vorkommt
    //liste mit directories
    //alles in einer struct vector speicehrn
    
}
*/
int main(int argcp, const char ** argv) {
    std::cout << "Simple Tiled Loader\n";

    tmx_manager* tmx_manager_instance = &tmx_manager::getManagerInstance();
    
    
    //glfwInit();
    
    // insert code here...
          //glfwInit();
    //CREATE WINDOW
    //glfwWindowHint(GLFW_DEPTH_BITS, 24);
    //glfwWindowHint(GLFW_RED_BITS, 8);
    //glfwWindowHint(GLFW_GREEN_BITS, 8);
    //glfwWindowHint(GLFW_BLUE_BITS, 8);
    //glfwWindowHint(GLFW_ALPHA_BITS, 8);
    //GLFWwindow* glfWindow = glfwCreateWindow(800, 480, "SIMPLE TILE LOADER", NULL/* FULLSCREEN MONITOR*/, NULL);
    //set / create opengl context
    //glfwMakeContextCurrent(glfWindow);
   
    
    tmx_map* tiled_map = new tmx_map();
 
    if(!tiled_map->tmx_load_map("/tiled/desert-palace.tmx")){
        std::cout << "tmx_load_map fialed check file" << std::endl;
    }else{
    std::cout << "map file loaded" << std::endl;
    }
    
    


    
    delete tiled_map;
    
    
    //destroy window
    //glfwDestroyWindow(glfwGetCurrentContext());
    //shitdown stuff
    //glfwTerminate();
    
    
    glfwTerminate();
    tmx_manager::destroyTmxManager();
    return 0;
}
