//
//  tmx_resource_manager.hpp
//  tiled_loader
//
//  Created by Marcel Ochsendorf on 12.04.16.
//  Copyright © 2016 Marcel Ochsendorf. All rights reserved.
//

#ifndef tmx_resource_manager_hpp
#define tmx_resource_manager_hpp

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <cstring>

#include "tmx_ini_parser.hpp"
#include "tmx_map_loader.hpp"
class tmx_resource_manager{
public:
    
    
    
    
    struct fiel_dir_info{
        bool is_dir;
        std::string file_name;
        std::string file_extention;
        unsigned int file_size;
    };
    
   // tmx_shader* loaded_shaders; //textur im shader
   // tmx_modelbuffer* loaded_models;

    tmx_ini_loader* loaded_configs;
    tmx_map_loader* loaded_maps;
    
    //tmx_model_buffer* get_model(const char* _model_name);
    tmx_ini_loader* get_config(const char* _config_name);
    void get_shader(const char* _shader_name);
    void get_texture(const char* _texure_name);
    tmx_map_loader* get_tiled_map(const char* _map_name);
    
    
    static tmx_resource_manager* get_resource_manager();
    static void delete_resource_manager();
    
    void scan_directories(const char* _path);
    

};
#endif /* tmx_resource_manager_hpp */
