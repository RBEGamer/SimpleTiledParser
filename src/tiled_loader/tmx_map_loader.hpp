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
#include "tmx_helper_functions.hpp"
class tmx_map_loader {
   public:
    
    
    struct TMX_TILESET_DESC;
    struct TMX_LAYER_DESC;
    struct TMX_DATA_DESC;
    struct TMX_TILE_DESC;
    
    
    
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
    
    enum TMX_PROPERTY_TYPE{
    prp_bool, prop_int, prop_string, prop_float, prop_invalid, prop_bool
    };
    
    
    enum TMX_DATA_ENCODING{
        tmx_data_encoding_csv, tmx_data_enconding_base64, tmx_dataencoding_invalid
    };
    
    enum TMX_DATA_COMPRESSION{
        tmx_data_compression_gzip, tmx_data_compression_zlib, tmx_data_compression_none, tmx_data_compression_invalid
    };
    
    struct TMX_IMAGE_DESC{
        std::string tmx_image_format;
        std::string tmx_image_source;
        int tmx_trans_color;
        int tmx_width;
        int tmx_height;
    };
    
    struct TMX_FRAME_DESC{
        int tmx_framepos;
        int tmx_duration;
        int tmx_tileid;
        TMX_TILE_DESC* tmx_frametile;
        
    };
    
    struct TMX_ANIMATION_DESC{
        int tmx_anmimationid;
        int tmx_framecount;
        TMX_FRAME_DESC* tmx_frames;
        
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
        int tmx_tilesetamount;
        int tmx_layeramount;
    };
    
    struct TMX_PROPERTYS_DESC{
        std::string tmx_name;
        std::string tmx_value;
        TMX_PROPERTY_TYPE tmx_type;
    };
    
    
    
    struct TMX_TILE_DESC{
        TMX_TILESET_DESC* tmx_refered_tileset;
        int tmx_id; //this is the id in the tileset
        int tmx_gridid; //this is the global id used in the datagrid
        TMX_ANIMATION_DESC* tmx_animation_desc;
        TMX_PROPERTYS_DESC* tmx_properties_desc;
        int tmx_animation_count;
        int tmx_properties_count;
        //START PIXEL POINT IN THE IMAGE
        int tmx_start_pixel_offset_x;
        int tmx_start_pixel_offset_y;
        int* tmx_tile_width;
        int* tmx_tile_height;
        
        //TODO ADD REFERENZE TO TEXTUREATLAS TEXTURE
    };
    
    

    
    struct TMX_TILESET_DESC{
        int tmx_firstgid;
        std::string tmx_source;
        std::string tmx_name;
        int tmx_tilewidth;
        int tmx_tileheight;
        int tmx_spacing;
        int tmx_margin;
        int tmx_tilecount;
        int tmx_columns;
        int tmx_rows;
        TMX_IMAGE_DESC tmx_image_desc;
        TMX_TILE_DESC* tmx_tile_desc;
        TMX_MAP_DESC* tmx_map_description;
    
        int tmx_normal_tiles_count;
        TMX_TILE_DESC* tmx_normal_tiles;
        int tmx_property_tiles_count;
        TMX_TILE_DESC* tmx_property_tiles;
        int tmx_animated_tiles_count;
        TMX_TILE_DESC* tmx_animated_tiles;
    };

    struct TMX_DATA_FIELD{
        int tmx_tileid;
        int tmx_pos_x;
        int tmx_pos_y;
        TMX_TILE_DESC* tmx_tile;
        TMX_DATA_DESC* tmx_data_desc;
        //TODO ADD refered TEXTURE_ATLAS_ID*
    };
    
    struct TMX_DATA_DESC{
        TMX_DATA_ENCODING tmx_data_encoding;
        TMX_DATA_COMPRESSION tmx_data_compression;
        TMX_DATA_FIELD* tmx_data_field;
        TMX_LAYER_DESC* tmx_layer;
        int tmx_data_field_count;
    };
    
    
    struct TMX_LAYER_DESC{
        std::string tmx_name;
        int tmx_posx;
        int tmx_posy;
        int tmx_width;
        int tmx_height;
        float tmx_opacity;
        bool tmx_visible;
        int tmx_offsetx;
        int tmx_offsety;
        int tmx_property_count;
        TMX_PROPERTYS_DESC* tmx_properties;
        int tmx_data_count;
        TMX_DATA_DESC* tmx_data;
        TMX_MAP_DESC* tmx_map;
    };
    
    
    
    //TODO all 3 in one struct and a delte function
    
    //CURRENT MAP
    TMX_MAP_DESC* map_desc;
    TMX_TILESET_DESC* tilesets_desc;
    TMX_LAYER_DESC* layer_desc;
    
    std::string tilesets_folder_path;
    tmx_map_loader();
    ~tmx_map_loader();

    bool tmx_load_map(const char* _tmx_file_path);
    
private:
    void tmx_parse_tilesets(int _tmx_count_tilesets, std::string  _tmx_xml_buffer, TMX_TILESET_DESC* _tmx_tilesets_desc);
    void tmx_parse_image(int _tmx_curr_tileset, std::string _tmx_xml_buffer, TMX_TILESET_DESC* _tmx_tilesets_desc);
    void tmx_parse_tile(int _tmx_curr_tileset, std::string _tmx_xml_buffer, TMX_TILESET_DESC* _tmx_tileset_desc);
    void tmx_parse_animation(int _tmx_current_tile, std::string _tmx_xml_buffer, TMX_TILE_DESC* tmx_tile_desc);
    
    void tmx_parse_property(int _tmx_current_tile, std::string _tmx_xml_buffer, TMX_TILE_DESC* tmx_tile_desc);
    void tmx_parse_property(int _tmx_current_tile, std::string _tmx_xml_buffer, TMX_LAYER_DESC* tmx_tile_desc);
    
    void tmx_parse_data(int _tmx_current_layer, std::string _tmx_xml_buffer, TMX_LAYER_DESC* tmx_layer_desc);
    void tmx_parse_csv_none_encoding(int _tmx_curr_data, std::string _tmx_xml_buffer, TMX_DATA_DESC* _tmx_data_desc);
    void tmx_create_layer_descriptor(TMX_LAYER_DESC* _tmx_layer_desc);
    void tmx_parse_layers(int _tmx_count_layers, std::string _tmx_xml_buffer, TMX_LAYER_DESC* _tmx_layers_desc);
    
    
    void tmx_create_map_descriptor(TMX_MAP_DESC* _tmx_map_desc);
    void tmx_create_tileset_descriptor(TMX_TILESET_DESC* _tmx_tileset_desc);
    void tmx_create_image_desc(TMX_IMAGE_DESC* _tmx_image_desc);
    std::string tmx_parse_map_desc(char* _tmx_xml_buffer,  TMX_MAP_DESC* _map_desc);
};






#endif /* tmp_map_hpp */


