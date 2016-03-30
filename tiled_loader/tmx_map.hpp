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

    
    
    //image desc
    
    
    //tile desc (multivel prob, aimation)
    
    
    //property desc
    
    //animation desc
    
    //frame desc
    
    struct TMX_IMAGE_DESC{
    
    };
    
    
    struct TMX_FRAME_DESC{
        int tmx_framepos;
        int tmx_duration;
        int tmx_tileid;
    };
    
    struct TMX_ANIMATION_DESC{
        int tmx_anmimationid;
        int tmx_framecount;
        TMX_FRAME_DESC* tmx_frames;
    };
    
    
    enum TMX_PROPERTY_TYPE{
    prp_bool, prop_int, prop_string, prop_float, prop_invalid
    };
    
    struct TMX_PROPERTYS_DESC{
        std::string tmx_name;
        std::string tmx_value;
        TMX_PROPERTY_TYPE tmx_type;
    };
    
    
    struct TMX_TILE_DESC{
        int tmx_id;
        TMX_ANIMATION_DESC* tmx_animation_desc;
        TMX_PROPERTYS_DESC* tmx_properties_desc;
        int tmx_animation_count;
        int tmx_properties_count;
    };
    
    
    //tilesets zählen
    //passend allocatieren
    //alle init
    //tileset desc parsen
    //image parsen
    //tiles parsen
    //properties zählen int tile speichern
    //allociren
    //parsen
    //animations zählen in tile speichern
    //instancen
    //frames zählen speichern
    //frames erstllen
    //parsen
    
    struct TMX_TILESET_DESC{
        int tmx_firstgid;
        std::string tmx_source;
        std::string tmx_name;
        int tmx_tilewidth;
        int tmx_tileheight;
        int tmx_spacing;
        int tmx_margin;
        int tmx_tilecount;
        int tmx_colums;
        TMX_IMAGE_DESC tmx_image_desc;
        TMX_TILE_DESC* tmx_tile_desc;
    
    };
    
    
    
    
    
    //CURRENT MAP
    TMX_MAP_DESC* map_desc;
    TMX_TILESET_DESC* tilesets_desc;
    
    
    std::string tilesets_folder_path;
    tmx_map();
    ~tmx_map();
    void tmx_create_map_descriptor(TMX_MAP_DESC* _tmx_map_desc);
    bool tmx_load_map(const char* _tmx_file_path);
    
    std::string tmx_parse_map_desc(char* _tmx_xml_buffer,  TMX_MAP_DESC* _map_desc);
    
};






#endif /* tmp_map_hpp */


