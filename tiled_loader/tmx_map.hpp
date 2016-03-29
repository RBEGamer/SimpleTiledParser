//
//  tmp_map.hpp
//  tiled_loader
//
//  Created by Marcel Ochsendorf on 29.03.16.
//  Copyright © 2016 Marcel Ochsendorf. All rights reserved.
//

#ifndef tmx_map_hpp
#define tmx_map_hpp

#include <stdio.h>
#include <iostream>

#include <cstring>

#include <stdlib.h>
#ifdef HAVE_MALLOC_H
#include <malloc.h>
#endif

class tmx_map {
   public:
    
    enum TMX_MAP_ORIENTATION{
        orthogonal, isometric, staggerred, hexagonal, invalid_orientation
    };
    
    enum TMX_MAP_RENDERORDER{
        right_up, right_down, left_up, left_down, invalid_renderorder
    };
    
    enum TMX_MAP_STAGGERAXIS{
        staggeraxis_x, staggeraxis_y, invalid_staggeraxis
    };
    
    enum TMX_MAP_STAGGERINDEX{
        staggerindex_even, staggerindex_odd, invalid_staggerindex
    };
    struct TMX_MAP_DESC {
        char tmx_version[3];
        TMX_MAP_ORIENTATION tmx_orientation;
        TMX_MAP_RENDERORDER tmx_renderorder;
        int tmx_width; //map size in tiles x
        int tmx_height; //map size in tiles y
        int tmx_tilewidth; //size of a tile x
        int tmx_tileheight; // size of a tile y
        int tmx_hexsidelenght; // for ortho maps, witch lenght height on staggered axis
        TMX_MAP_STAGGERINDEX tmx_staggerindex;
        TMX_MAP_STAGGERAXIS tmx_staggeraxis;
        int tmx_backgroundcolor;
        int tmx_nextobjectid;
    };

    //CURRENT MAP
    TMX_MAP_DESC map_desc;
    
    
    tmx_map();
    ~tmx_map();
    void tmx_create_map_descriptor(TMX_MAP_DESC* _tmx_map_desc);
    bool tmx_load_map(const char* _tmx_file_path);
    
    std::string tmx_parse_map_desc(char* _tmx_xml_buffer,  TMX_MAP_DESC* _map_desc);
    
};






#endif /* tmp_map_hpp */


