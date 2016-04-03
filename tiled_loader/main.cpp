//
//  main.cpp
//  tiled_loader
//
//  Created by Marcel Ochsendorf on 29.03.16.
//  Copyright © 2016 Marcel Ochsendorf. All rights reserved.
// https://www.youtube.com/watch?v=9ka5bgHnHyg

#include <iostream>
#include "tmx_manager.hpp"
#include "tmx_map_loader.hpp"
#include "tmx_ini_parser.hpp"






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
    std::cout << "START\n";

    //LOAD CONFIG FILE HERE
  
 
          tmx_manager* tmx_manager_instance = &tmx_manager::getManagerInstance();
    
    

   
    
    tmx_map_loader* tiled_map = new tmx_map_loader();
 
    if(!tiled_map->tmx_load_map("tiled/desert-palace.tmx")){
    std::cout << "tmx_load_map fialed check file" << std::endl;
    }else{
    std::cout << "map file loaded" << std::endl;
    }
    
    //STARTING MAIN LOOP
    std::cout << "ENTER GAME LOOP" << std::endl;
    
    tmx_manager_instance->run_main_loop();

    
    delete tiled_map;
    
    tmx_manager::destroyTmxManager();
    return 0;
}
