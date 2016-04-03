//
//  tmx_ini_parser.hpp
//  tiled_loader
//
//  Created by Marcel Ochsendorf on 03.04.16.
//  Copyright © 2016 Marcel Ochsendorf. All rights reserved.
//

#ifndef tmx_ini_parser_hpp
#define tmx_ini_parser_hpp

#include <stdio.h>
#include <cstring>
#include <iostream>
#include <stdlib.h>


class tmx_ini_loader{

public:
    
    tmx_ini_loader();
    ~tmx_ini_loader();
    void load_ini_file(const char* _filepath);
    std::string get_value(std::string _section, std::string _key);
    
    
    struct INI_FILE_KVPAIR{
        std::string key;
        std::string value;
    };
    
    struct INI_FILE_SECTION{
        std::string section_name;
        int key_value_count;
        INI_FILE_KVPAIR* kvpair;
    };
    
    struct INI_FILE_DESC{
        int section_count;
        INI_FILE_SECTION* sections;
    };
    
    INI_FILE_DESC* loaded_ini_file;
    




};



#endif /* tmx_ini_parser_hpp */
