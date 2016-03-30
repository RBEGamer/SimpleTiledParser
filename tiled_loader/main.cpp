//
//  main.cpp
//  tiled_loader
//
//  Created by Marcel Ochsendorf on 29.03.16.
//  Copyright © 2016 Marcel Ochsendorf. All rights reserved.
//

#include <iostream>
#include "tmx_map.hpp"




int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    
    
    
    tmx_map* tiled_map = new tmx_map();
    tiled_map->tilesets_folder_path = "Assets/";
    if(!tiled_map->tmx_load_map("desert-palace.tmx")){
        std::cout << "tmx_load_map fialed check file" << std::endl;
    }
    delete tiled_map;
    return 0;
}
