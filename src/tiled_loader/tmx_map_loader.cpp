//
//  tmp_map.cpp
//  tiled_loader
//
//  Created by Marcel Ochsendorf on 29.03.16.
//  Copyright © 2016 Marcel Ochsendorf. All rights reserved.
//

#include "tmx_map_loader.hpp"

tmx_map_loader::tmx_map_loader(){
    map_desc = new TMX_MAP_DESC();
    tmx_create_map_descriptor(map_desc);
    
    
}

tmx_map_loader::~tmx_map_loader(){
    //cleanup tileset desc
    delete[] tilesets_desc->tmx_tile_desc->tmx_animation_desc->tmx_frames;
    delete[] tilesets_desc->tmx_tile_desc->tmx_animation_desc;
    delete[] tilesets_desc->tmx_tile_desc->tmx_properties_desc;
    delete[] tilesets_desc;
    //cleanup layer desc
    delete [] layer_desc->tmx_data->tmx_data_field;
    delete [] layer_desc->tmx_data;
    delete [] layer_desc->tmx_properties;
    delete  layer_desc;
    //cleanup map
    delete map_desc;
}

void tmx_map_loader::tmx_create_map_descriptor(TMX_MAP_DESC* _tmx_map_desc){
    strcpy(_tmx_map_desc->tmx_version , "0.0");
    _tmx_map_desc->tmx_orientation = TMX_MAP_ORIENTATION::invalid_orientation;
    _tmx_map_desc->tmx_renderorder = TMX_MAP_RENDERORDER::invalid_renderorder;
    _tmx_map_desc->tmx_width = 0;
    _tmx_map_desc->tmx_height = 0;
    _tmx_map_desc->tmx_tilewidth = 0;
    _tmx_map_desc->tmx_tileheight = 0;
    _tmx_map_desc->tmx_hexsidelenght = 0;
    _tmx_map_desc->tmx_staggeraxis = TMX_MAP_STAGGERAXIS::invalid_staggeraxis;
    _tmx_map_desc->tmx_staggerindex = TMX_MAP_STAGGERINDEX::invalid_staggerindex;
    _tmx_map_desc->tmx_backgroundcolor = 0;
    _tmx_map_desc->tmx_nextobjectid = 0;
}

void tmx_map_loader::tmx_create_image_desc(TMX_IMAGE_DESC* _tmx_image_desc){
    _tmx_image_desc->tmx_height = 0;
    _tmx_image_desc->tmx_width = 0;
    _tmx_image_desc->tmx_image_format = "";
    _tmx_image_desc->tmx_image_source = "";
    _tmx_image_desc->tmx_trans_color = 0;
}

void tmx_map_loader::tmx_create_tileset_descriptor(TMX_TILESET_DESC* _tmx_tileset_desc){
    _tmx_tileset_desc->tmx_firstgid = -1;
    _tmx_tileset_desc->tmx_source = "";
    _tmx_tileset_desc->tmx_name = "";
    _tmx_tileset_desc->tmx_tilewidth = 0;
    _tmx_tileset_desc->tmx_tileheight = 0;
    _tmx_tileset_desc->tmx_spacing = 0;
    _tmx_tileset_desc->tmx_margin = 0;
    _tmx_tileset_desc->tmx_tilecount = 0;
    _tmx_tileset_desc->tmx_columns = 0;
    _tmx_tileset_desc->tmx_rows = 0;
    tmx_create_image_desc(&_tmx_tileset_desc->tmx_image_desc);
    _tmx_tileset_desc->tmx_tile_desc = 0;
}

void tmx_map_loader::tmx_create_layer_descriptor(TMX_LAYER_DESC* _tmx_layer_desc){
    _tmx_layer_desc->tmx_data = 0;
    _tmx_layer_desc->tmx_data_count = 0;
    _tmx_layer_desc->tmx_height = 0;
    _tmx_layer_desc->tmx_name = "";
    _tmx_layer_desc->tmx_offsetx = 0;
    _tmx_layer_desc->tmx_offsety = 0;
    _tmx_layer_desc->tmx_opacity = 1;
    _tmx_layer_desc->tmx_posx = 0;
    _tmx_layer_desc->tmx_posy = 0;
    _tmx_layer_desc->tmx_properties = 0;
    _tmx_layer_desc->tmx_property_count = 0;
    _tmx_layer_desc->tmx_visible = true;
    _tmx_layer_desc->tmx_width = 0;
}

void tmx_map_loader::tmx_parse_image(int _tmx_curr_tileset, std::string _tmx_xml_buffer, TMX_TILESET_DESC* _tmx_tilesets_desc){
    //read image tag
    //read attr
    //put in tileset
    
    char* tileset_attr_start = strstr(_tmx_xml_buffer.c_str(), "<image");
    tileset_attr_start += 6;
    char* tileset_attr_end = strstr(tileset_attr_start, ">");
    std::string tileset_attr_content = "";
    tileset_attr_content.append(tileset_attr_start, tileset_attr_end);
    
    //parse arguments
    char* attr_key_start = 0;
    char* attr_key_end = 0;
    std::string attr_value_string = "";
    //SEARCH ATTRIBITE
    attr_key_start = strstr(tileset_attr_content.c_str(), "source=\"");
    if(attr_key_start != nullptr){
        attr_key_start += strlen("source=\"");
        attr_key_end = strstr(attr_key_start,"\" ");
        if(attr_key_end == NULL){attr_key_end = strstr(attr_key_start,"\"");}
        if(attr_key_end != NULL){
            attr_value_string.append(attr_key_start, attr_key_end);
            //DO STUFF
            //strcpy(_map_desc->tmx_version, attr_value_string.c_str());
            (_tmx_tilesets_desc+_tmx_curr_tileset)->tmx_image_desc.tmx_image_source =attr_value_string;
        }
    }
    attr_key_start = 0;
    attr_key_end = 0;
    attr_value_string = "";
    
    //SEARCH ATTRIBITE
    attr_key_start = strstr(tileset_attr_content.c_str(), "width=\"");
    if(attr_key_start != nullptr){
        attr_key_start += strlen("width=\"");
        attr_key_end = strstr(attr_key_start,"\" ");
        if(attr_key_end == NULL){attr_key_end = strstr(attr_key_start,"\"");}
        if(attr_key_end != NULL){
            attr_value_string.append(attr_key_start, attr_key_end);
            //DO STUFF
            //strcpy(_map_desc->tmx_version, attr_value_string.c_str());
            (_tmx_tilesets_desc+_tmx_curr_tileset)->tmx_image_desc.tmx_width = atoi(attr_value_string.c_str());
        }
    }
    attr_key_start = 0;
    attr_key_end = 0;
    attr_value_string = "";
    
    
    //SEARCH ATTRIBITE
    attr_key_start = strstr(tileset_attr_content.c_str(), "height=\"");
    if(attr_key_start != nullptr){
        attr_key_start += strlen("height=\"");
        attr_key_end = strstr(attr_key_start,"\" ");
        if(attr_key_end == NULL){attr_key_end = strstr(attr_key_start,"\"");}
        if(attr_key_end != NULL){
            attr_value_string.append(attr_key_start, attr_key_end);
            //DO STUFF
            //strcpy(_map_desc->tmx_version, attr_value_string.c_str());
            (_tmx_tilesets_desc+_tmx_curr_tileset)->tmx_image_desc.tmx_height = atoi(attr_value_string.c_str());
        }
    }
    attr_key_start = 0;
    attr_key_end = 0;
    attr_value_string = "";
    
    //SEARCH ATTRIBITE
    attr_key_start = strstr(tileset_attr_content.c_str(), "format=\"");
    if(attr_key_start != nullptr){
        attr_key_start += strlen("format=\"");
        attr_key_end = strstr(attr_key_start,"\" ");
        if(attr_key_end == NULL){attr_key_end = strstr(attr_key_start,"\"");}
        if(attr_key_end != NULL){
            attr_value_string.append(attr_key_start, attr_key_end);
            //DO STUFF
            //strcpy(_map_desc->tmx_version, attr_value_string.c_str());
            (_tmx_tilesets_desc+_tmx_curr_tileset)->tmx_image_desc.tmx_image_format = attr_value_string;
        }
    }
    attr_key_start = 0;
    attr_key_end = 0;
    attr_value_string = "";
    
    //SEARCH ATTRIBITE
    attr_key_start = strstr(tileset_attr_content.c_str(), "trans=\"");
    if(attr_key_start != nullptr){
        attr_key_start += strlen("trans=\"");
        attr_key_end = strstr(attr_key_start,"\" ");
        if(attr_key_end == NULL){attr_key_end = strstr(attr_key_start,"\"");}
        if(attr_key_end != NULL){
            attr_value_string.append(attr_key_start, attr_key_end);
            //DO STUFF
            //strcpy(_map_desc->tmx_version, attr_value_string.c_str());
            (_tmx_tilesets_desc+_tmx_curr_tileset)->tmx_image_desc.tmx_trans_color = atoi(attr_value_string.c_str());
        }
    }
    attr_key_start = 0;
    attr_key_end = 0;
    attr_value_string = "";
}

void tmx_map_loader::tmx_parse_animation(int _tmx_current_tile, std::string _tmx_xml_buffer, TMX_TILE_DESC* tmx_tile_desc){
    /*
     <animation>
     <frame tileid="64" duration="250"/>
     <frame tileid="80" duration="250"/>
     </animation>
     */
    
    //count animation
    const char* anim_counter_itr = strstr(_tmx_xml_buffer.c_str(), "<animation>");
    if(anim_counter_itr == NULL){return;}
    int anim_array_size = 0;
    while (true) {
        anim_counter_itr = strstr(anim_counter_itr, "<animation>");
        if (anim_counter_itr != 0) {
            anim_counter_itr += 11; //"<property "
            anim_array_size++;
        }else {
            break;
        }
    }
    //allocate anim desc
    (tmx_tile_desc + _tmx_current_tile)->tmx_animation_count = anim_array_size;
    (tmx_tile_desc + _tmx_current_tile)->tmx_animation_desc = new TMX_ANIMATION_DESC[anim_array_size]();
    
    //goto each <anim> and count frames
    
    for (int j = 0; j < anim_array_size; j++) {
        char* animfr_attr_start = strstr(_tmx_xml_buffer.c_str(), "<animation>");
        if(animfr_attr_start != NULL){
            animfr_attr_start += 11; //remove <properties>
            char* animfr_attr_end = strstr(animfr_attr_start, "</animation>");
            if(animfr_attr_end != NULL){
                std::string animfr_attr_content = "";
                animfr_attr_content.append(animfr_attr_start, animfr_attr_end);
                if(animfr_attr_content != ""){
                    //count frames
                    const char* frame_counter_itr = strstr(animfr_attr_content.c_str(), "<frame ");
                    int frame_array_size = 0;
                    while (true) {
                        frame_counter_itr = strstr(frame_counter_itr, "<frame ");
                        if (frame_counter_itr != 0) {
                            frame_counter_itr += 7; //"<property "
                            frame_array_size++;
                        }else {
                            break;
                        }
                    }
                    
                    
                    //allocate frame
                    ((tmx_tile_desc + _tmx_current_tile)->tmx_animation_desc+j)->tmx_framecount = frame_array_size;
                    ((tmx_tile_desc + _tmx_current_tile)->tmx_animation_desc+j)->tmx_anmimationid = j;
                    ((tmx_tile_desc + _tmx_current_tile)->tmx_animation_desc+j)->tmx_frames = new TMX_FRAME_DESC[frame_array_size]();
                    
                    //pars attr from frame
                    //<frame tileid="64" duration="250"/>
                    //animfr_attr_content
                    //
                    char* frame_attr_start = strstr(animfr_attr_content.c_str(), "<frame ");
                    for (int i = 0; i < frame_array_size; i++) {
                        frame_attr_start = strstr(frame_attr_start, "<frame ");
                        if(frame_attr_start != NULL){
                            frame_attr_start += 7; //remove the <tileset
                            char* frame_attr_end = strstr(frame_attr_start, ">");
                            std::string frame_attr_content = "";
                            frame_attr_content.append(frame_attr_start, frame_attr_end);
                            if(frame_attr_content == ""){continue;}
                            
                            (((tmx_tile_desc + _tmx_current_tile)->tmx_animation_desc+j)->tmx_frames+i)->tmx_framepos = i;
                            
                            char* frame_key_start = 0;
                            char* frame_key_end = 0;
                            std::string frame_value_string = "";
                            //SEARCH ATTRIBITE
                            frame_key_start = strstr(frame_attr_content.c_str(), "tileid=\"");
                            if(frame_key_start != nullptr){
                                frame_key_start += strlen("tileid=\"");
                                frame_key_end = strstr(frame_key_start,"\" ");
                                if(frame_key_end == NULL){frame_key_end = strstr(frame_key_start,"\"");}
                                if(frame_key_end != NULL){
                                    frame_value_string.append(frame_key_start, frame_key_end);
                                    //DO STUFF
                                    (((tmx_tile_desc + _tmx_current_tile)->tmx_animation_desc+j)->tmx_frames+i)->tmx_tileid = atoi(frame_value_string.c_str());
                                    
                                    //LINK TILE
                                    for (int l = 0; l <  (tmx_tile_desc + _tmx_current_tile)->tmx_refered_tileset->tmx_tilecount; l++) {
                                        if(((tmx_tile_desc + _tmx_current_tile)->tmx_refered_tileset->tmx_tile_desc+l)->tmx_gridid == (((tmx_tile_desc + _tmx_current_tile)->tmx_animation_desc+j)->tmx_frames+i)->tmx_tileid){
                                            (((tmx_tile_desc + _tmx_current_tile)->tmx_animation_desc+j)->tmx_frames+i)->tmx_frametile = ((tmx_tile_desc + _tmx_current_tile)->tmx_refered_tileset->tmx_tile_desc+l);
                                        }
                                    }
                                    
                                    
                                    
                                }
                            }
                            frame_key_start = 0;
                            frame_key_end = 0;
                            frame_value_string = "";
                            
                            
                            //SEARCH ATTRIBITE
                            frame_key_start = strstr(frame_attr_content.c_str(), "duration=\"");
                            if(frame_key_start != nullptr){
                                frame_key_start += strlen("duration=\"");
                                frame_key_end = strstr(frame_key_start,"\" ");
                                if(frame_key_end == NULL){frame_key_end = strstr(frame_key_start,"\"");}
                                if(frame_key_end != NULL){
                                    frame_value_string.append(frame_key_start, frame_key_end);
                                    //DO STUFF
                                    (((tmx_tile_desc + _tmx_current_tile)->tmx_animation_desc+j)->tmx_frames+i)->tmx_duration = atoi(frame_value_string.c_str());
                                }
                            }
                            frame_key_start = 0;
                            frame_key_end = 0;
                            frame_value_string = "";
                            
                            
                        }
                    }
                    
                    
                    
                }
            }
        }
        
        
        
    }//end for
    
    
    
    
}

void tmx_map_loader::tmx_parse_property(int _tmx_current_tile, std::string _tmx_xml_buffer, TMX_TILE_DESC* tmx_tile_desc){
    /*
     <properties>
     <property name="item_id" type="int" value="0"/>
     </properties>
     
     */
    char* prop_attr_start = strstr(_tmx_xml_buffer.c_str(), "<properties>");
    if(prop_attr_start != NULL){
        prop_attr_start += 12; //remove <properties>
        char* prop_attr_end = strstr(prop_attr_start, "</properties>");
        if(prop_attr_end != NULL){
            std::string tile_attr_content = "";
            tile_attr_content.append(prop_attr_start, prop_attr_end);
            if(tile_attr_content != ""){
                //count properties
                const char* prop_counter_itr = strstr(_tmx_xml_buffer.c_str(), "<property ");
                int prop_array_size = 0;
                while (true) {
                    prop_counter_itr = strstr(prop_counter_itr, "<property ");
                    if (prop_counter_itr != 0) {
                        prop_counter_itr += 10; //"<property "
                        prop_array_size++;
                    }else {
                        break;
                    }
                }
                //allocate prop array
                if(prop_array_size < 1){return;}
                (tmx_tile_desc + _tmx_current_tile)->tmx_properties_count = prop_array_size;
                (tmx_tile_desc + _tmx_current_tile)->tmx_properties_desc = new TMX_PROPERTYS_DESC[prop_array_size]();
                //parse attributes
                char* prop_attr_start = strstr(tile_attr_content.c_str(), "<property ");
                for (int i = 0; i < prop_array_size; i++) {
                    prop_attr_start = strstr(prop_attr_start, "<property ");
                    if(prop_attr_start != NULL){
                        prop_attr_start += 10; //remove the <tileset
                        char* prop_attr_end = strstr(prop_attr_start, ">");
                        std::string prop_attr_content = "";
                        prop_attr_content.append(prop_attr_start, prop_attr_end);
                        
                        
                        char* prop_key_start = 0;
                        char* prop_key_end = 0;
                        std::string prop_value_string = "";
                        //SEARCH ATTRIBITE
                        prop_key_start = strstr(prop_attr_content.c_str(), "name=\"");
                        if(prop_key_start != nullptr){
                            prop_key_start += strlen("name=\"");
                            prop_key_end = strstr(prop_key_start,"\" ");
                            if(prop_key_end == NULL){prop_key_end = strstr(prop_key_start,"\"");}
                            if(prop_key_end != NULL){
                                prop_value_string.append(prop_key_start, prop_key_end);
                                //DO STUFF
                                // ((_tmx_tileset_desc + _tmx_curr_tileset)->tmx_tile_desc + i)->tmx_id = atoi(attr_value_string.c_str());
                                ((tmx_tile_desc + _tmx_current_tile)->tmx_properties_desc + i)->tmx_name = prop_value_string;
                            }
                        }
                        prop_key_start = 0;
                        prop_key_end = 0;
                        prop_value_string = "";
                        
                        //SEARCH ATTRIBITE
                        prop_key_start = strstr(prop_attr_content.c_str(), "type=\"");
                        if(prop_key_start != nullptr){
                            prop_key_start += strlen("type=\"");
                            prop_key_end = strstr(prop_key_start,"\" ");
                            if(prop_key_end == NULL){prop_key_end = strstr(prop_key_start,"\"");}
                            if(prop_key_end != NULL){
                                prop_value_string.append(prop_key_start, prop_key_end);
                                //DO STUFF
                                // ((_tmx_tileset_desc + _tmx_curr_tileset)->tmx_tile_desc + i)->tmx_id = atoi(attr_value_string.c_str());
                                if(prop_value_string == "float"){
                                    ((tmx_tile_desc + _tmx_current_tile)->tmx_properties_desc + i)->tmx_type = TMX_PROPERTY_TYPE::prop_float;
                                }else if(prop_value_string == "bool"){
                                    ((tmx_tile_desc + _tmx_current_tile)->tmx_properties_desc + i)->tmx_type = TMX_PROPERTY_TYPE::prop_bool;
                                }else if(prop_value_string == "int"){
                                    ((tmx_tile_desc + _tmx_current_tile)->tmx_properties_desc + i)->tmx_type = TMX_PROPERTY_TYPE::prop_int;
                                }else if(prop_value_string == "string"){
                                    ((tmx_tile_desc + _tmx_current_tile)->tmx_properties_desc + i)->tmx_type = TMX_PROPERTY_TYPE::prop_string;
                                }else{
                                    ((tmx_tile_desc + _tmx_current_tile)->tmx_properties_desc + i)->tmx_type = TMX_PROPERTY_TYPE::prop_invalid;
                                }
                                
                            }
                        }
                        prop_key_start = 0;
                        prop_key_end = 0;
                        prop_value_string = "";
                        
                    }
                }
            }
        }
    }
}

void tmx_map_loader::tmx_parse_property(int _tmx_current_tile, std::string _tmx_xml_buffer, TMX_LAYER_DESC* tmx_layer_desc){
    /*
     <properties>
     <property name="item_id" type="int" value="0"/>
     </properties>
     
     
     */
    char* prop_attr_start = strstr(_tmx_xml_buffer.c_str(), "<properties>");
    if(prop_attr_start != NULL){
        prop_attr_start += 12; //remove <properties>
        char* prop_attr_end = strstr(prop_attr_start, "</properties>");
        if(prop_attr_end != NULL){
            std::string tile_attr_content = "";
            tile_attr_content.append(prop_attr_start, prop_attr_end);
            if(tile_attr_content != ""){
                //count properties
                const char* prop_counter_itr = strstr(_tmx_xml_buffer.c_str(), "<property ");
                int prop_array_size = 0;
                while (true) {
                    prop_counter_itr = strstr(prop_counter_itr, "<property ");
                    if (prop_counter_itr != 0) {
                        prop_counter_itr += 10; //"<property "
                        prop_array_size++;
                    }else {
                        break;
                    }
                }
                //allocate prop array
                if(prop_array_size < 1){return;}
                (tmx_layer_desc + _tmx_current_tile)->tmx_property_count = prop_array_size;
                (tmx_layer_desc + _tmx_current_tile)->tmx_properties = new TMX_PROPERTYS_DESC[prop_array_size]();
                //parse attributes
                char* prop_attr_start = strstr(tile_attr_content.c_str(), "<property ");
                for (int i = 0; i < prop_array_size; i++) {
                    prop_attr_start = strstr(prop_attr_start, "<property ");
                    if(prop_attr_start != NULL){
                        prop_attr_start += 10; //remove the <tileset
                        char* prop_attr_end = strstr(prop_attr_start, ">");
                        std::string prop_attr_content = "";
                        prop_attr_content.append(prop_attr_start, prop_attr_end);
                        
                        
                        char* prop_key_start = 0;
                        char* prop_key_end = 0;
                        std::string prop_value_string = "";
                        //SEARCH ATTRIBITE
                        prop_key_start = strstr(prop_attr_content.c_str(), "name=\"");
                        if(prop_key_start != nullptr){
                            prop_key_start += strlen("name=\"");
                            prop_key_end = strstr(prop_key_start,"\" ");
                            if(prop_key_end == NULL){prop_key_end = strstr(prop_key_start,"\"");}
                            if(prop_key_end != NULL){
                                prop_value_string.append(prop_key_start, prop_key_end);
                                //DO STUFF
                                // ((_tmx_tileset_desc + _tmx_curr_tileset)->tmx_tile_desc + i)->tmx_id = atoi(attr_value_string.c_str());
                                ((tmx_layer_desc + _tmx_current_tile)->tmx_properties + i)->tmx_name = prop_value_string;
                            }
                        }
                        prop_key_start = 0;
                        prop_key_end = 0;
                        prop_value_string = "";
                        
                        //SEARCH ATTRIBITE
                        prop_key_start = strstr(prop_attr_content.c_str(), "type=\"");
                        if(prop_key_start != nullptr){
                            prop_key_start += strlen("type=\"");
                            prop_key_end = strstr(prop_key_start,"\" ");
                            if(prop_key_end == NULL){prop_key_end = strstr(prop_key_start,"\"");}
                            if(prop_key_end != NULL){
                                prop_value_string.append(prop_key_start, prop_key_end);
                                //DO STUFF
                                // ((_tmx_tileset_desc + _tmx_curr_tileset)->tmx_tile_desc + i)->tmx_id = atoi(attr_value_string.c_str());
                                if(prop_value_string == "float"){
                                    ((tmx_layer_desc + _tmx_current_tile)->tmx_properties + i)->tmx_type = TMX_PROPERTY_TYPE::prop_float;
                                }else if(prop_value_string == "bool"){
                                    ((tmx_layer_desc + _tmx_current_tile)->tmx_properties + i)->tmx_type = TMX_PROPERTY_TYPE::prop_bool;
                                }else if(prop_value_string == "int"){
                                    ((tmx_layer_desc + _tmx_current_tile)->tmx_properties + i)->tmx_type = TMX_PROPERTY_TYPE::prop_int;
                                }else if(prop_value_string == "string"){
                                    ((tmx_layer_desc + _tmx_current_tile)->tmx_properties + i)->tmx_type = TMX_PROPERTY_TYPE::prop_string;
                                }else{
                                    ((tmx_layer_desc + _tmx_current_tile)->tmx_properties + i)->tmx_type = TMX_PROPERTY_TYPE::prop_invalid;
                                }
                                
                            }
                        }
                        prop_key_start = 0;
                        prop_key_end = 0;
                        prop_value_string = "";
                        
                    }
                }
            }
        }
    }
}

void tmx_map_loader::tmx_parse_tile(int _tmx_curr_tileset, std::string _tmx_xml_buffer, TMX_TILESET_DESC* _tmx_tileset_desc){
    //count special tiles
    
    const char* tile_counter_itr = strstr(_tmx_xml_buffer.c_str(), "<tile ");
    int tile_array_size = 0;
    while (true) {
        tile_counter_itr = strstr(tile_counter_itr, "<tile ");
        if (tile_counter_itr != 0) {
            tile_counter_itr += 9; //"<tileset "
            tile_array_size++;
        }else {
            break;
        }
    }
    
    //set tileset amount in tileset
    //(_tmx_tileset_desc + _tmx_curr_tileset)->tmx_tilecount =(_tmx_tileset_desc + _tmx_curr_tileset)->tmx_tilecount;
    //allocate tiles pointer
    //   std::cout << "this tileset has " << (_tmx_tileset_desc + _tmx_curr_tileset)->tmx_tilecount << "tiles with "<< tile_array_size << " tiles with anim/prop" << std::endl;
    (_tmx_tileset_desc + _tmx_curr_tileset)->tmx_tile_desc = new TMX_TILE_DESC[(_tmx_tileset_desc + _tmx_curr_tileset)->tmx_tilecount]();
    
    
    
    //generate all tiles
    for (int j = 0; j < (_tmx_tileset_desc + _tmx_curr_tileset)->tmx_tilecount; j++) {
        ((_tmx_tileset_desc + _tmx_curr_tileset)->tmx_tile_desc+j)->tmx_refered_tileset = (_tmx_tileset_desc + _tmx_curr_tileset);
        
        ((_tmx_tileset_desc + _tmx_curr_tileset)->tmx_tile_desc+j)->tmx_id = j;
        ((_tmx_tileset_desc + _tmx_curr_tileset)->tmx_tile_desc+j)->tmx_gridid = j + (_tmx_tileset_desc + _tmx_curr_tileset)->tmx_firstgid;
        
        
        ((_tmx_tileset_desc + _tmx_curr_tileset)->tmx_tile_desc+j)->tmx_tile_width = &(_tmx_tileset_desc + _tmx_curr_tileset)->tmx_tilewidth;
        ((_tmx_tileset_desc + _tmx_curr_tileset)->tmx_tile_desc+j)->tmx_tile_height = &(_tmx_tileset_desc + _tmx_curr_tileset)->tmx_tileheight;
        
        //CALC PIXELOFFSETS
        ((_tmx_tileset_desc + _tmx_curr_tileset)->tmx_tile_desc+j)->tmx_start_pixel_offset_x = (int)(j % (_tmx_tileset_desc + _tmx_curr_tileset)->tmx_columns) * (_tmx_tileset_desc + _tmx_curr_tileset)->tmx_tilewidth;
        
        ((_tmx_tileset_desc + _tmx_curr_tileset)->tmx_tile_desc+j)->tmx_start_pixel_offset_y = (int)( j / (_tmx_tileset_desc + _tmx_curr_tileset)->tmx_columns)* (_tmx_tileset_desc + _tmx_curr_tileset)->tmx_tileheight;
        
        
        //   std::cout  << "id " << j <<" tile startx : " << ((_tmx_tileset_desc + _tmx_curr_tileset)->tmx_tile_desc+j)->tmx_start_pixel_offset_x << " starty : " <<((_tmx_tileset_desc + _tmx_curr_tileset)->tmx_tile_desc+j)->tmx_start_pixel_offset_y << std::endl;
    }
    
    
    //go tgrough each tile special tiles
    int special_tile_id = -1;
    char* tile_attr_start = strstr(_tmx_xml_buffer.c_str(), "<tile");
    for (int i = 0; i < tile_array_size; i++) {
        
        
        tile_attr_start = strstr(tile_attr_start, "<tile");
        if(tile_attr_start != NULL){
            tile_attr_start += 5; //remove the <tileset
            char* tileset_attr_end = strstr(tile_attr_start, ">");
            std::string tile_attr_content = "";
            tile_attr_content.append(tile_attr_start, tileset_attr_end);
            char* tileset_end = strstr(++tileset_attr_end, " </tile>");
            std::string tile_content = ""; //the content of the tileset
            tile_content.append(tileset_attr_end,tileset_end);
            
            //get attr return content (id)
            char* attr_key_start = 0;
            char* attr_key_end = 0;
            std::string attr_value_string = "";
            //SEARCH ATTRIBITE
            attr_key_start = strstr(tile_content.c_str(), "id=\"");
            if(attr_key_start != nullptr){
                attr_key_start += strlen("id=\"");
                attr_key_end = strstr(attr_key_start,"\" ");
                if(attr_key_end == NULL){attr_key_end = strstr(attr_key_start,"\"");}
                if(attr_key_end != NULL){
                    attr_value_string.append(attr_key_start, attr_key_end);
                    //DO STUFF
                    special_tile_id = atoi(attr_value_string.c_str());
                }
            }
            
            attr_key_start = 0;
            attr_key_end = 0;
            attr_value_string = "";
            if(special_tile_id < 0){continue;}
            //parse animations
            tmx_parse_animation(special_tile_id, tile_content, (_tmx_tileset_desc + _tmx_curr_tileset)->tmx_tile_desc);
            //parse properties
            tmx_parse_property(special_tile_id,tile_content,(_tmx_tileset_desc + _tmx_curr_tileset)->tmx_tile_desc);
            
            
        }
        
        /*
         for (int j = 0; j < (_tmx_tileset_desc + _tmx_curr_tileset)->tmx_tilecount; j++) {
         std::cout << "PARSE TILE ID : " << ((_tmx_tileset_desc + _tmx_curr_tileset)->tmx_tile_desc + j)->tmx_id
         << " GRID ID : " << ((_tmx_tileset_desc + _tmx_curr_tileset)->tmx_tile_desc + j)->tmx_gridid
         << " FROM TILESET : " << (_tmx_tileset_desc + _tmx_curr_tileset)->tmx_name << std::endl;
         }
         */
        
        
    }
    
    
}

void tmx_map_loader::tmx_parse_csv_none_encoding(int _tmx_curr_data, std::string _tmx_xml_buffer, TMX_DATA_DESC* _tmx_data_desc){
    
    replaceAll(_tmx_xml_buffer, "\n" , ""); //replace the new line charakter
    _tmx_xml_buffer.append(","); //append a , to iterate through the last tile
    _tmx_xml_buffer.insert(0, ",");
    
    const char* comma_counter_itr = strstr(_tmx_xml_buffer.c_str(), ",");
    int comma_array_size = 0;
    while (true) {
        comma_counter_itr = strstr(comma_counter_itr, ",");
        if (comma_counter_itr != 0) {
            comma_counter_itr += 1; //"<tileset "
            comma_array_size++;
        }else {
            break;
        }
    }
    
    
    
    (_tmx_data_desc + _tmx_curr_data)->tmx_data_field_count = comma_array_size;
    (_tmx_data_desc + _tmx_curr_data)->tmx_data_field = new TMX_DATA_FIELD[comma_array_size]();
    
    //func parse csv charpointer rein und dann /n entfernen ,zählen rows cols berechenn array bauen nach komma trennen value atoien  in array struct rein fertig
    char* csv_attr_start = strstr(_tmx_xml_buffer.c_str(), ",");
    for (int i = 0;  i < comma_array_size-1; i++) {
        //sort init
        ((_tmx_data_desc + _tmx_curr_data)->tmx_data_field+i)->tmx_tile = NULL;
        ((_tmx_data_desc + _tmx_curr_data)->tmx_data_field+i)->tmx_pos_y =  (int)(i / (_tmx_data_desc + _tmx_curr_data)->tmx_layer->tmx_width);
        ((_tmx_data_desc + _tmx_curr_data)->tmx_data_field+i)->tmx_pos_x = (int)(i % (_tmx_data_desc + _tmx_curr_data)->tmx_layer->tmx_width);
        ((_tmx_data_desc + _tmx_curr_data)->tmx_data_field+i)->tmx_tileid = 0;
        ((_tmx_data_desc + _tmx_curr_data)->tmx_data_field+i)->tmx_data_desc = (_tmx_data_desc + _tmx_curr_data);
        
        // std::cout << "x : "  << ((_tmx_data_desc + _tmx_curr_data)->tmx_data_field+i)->tmx_pos_x << " y: " << ((_tmx_data_desc + _tmx_curr_data)->tmx_data_field+i)->tmx_pos_y << std::endl;
        
        //get tile id
        csv_attr_start = strstr(csv_attr_start, ",");
        if(csv_attr_start != NULL){
            csv_attr_start += 1; //remove the <tileset
            char* csv_attr_end = strstr(csv_attr_start, ",");
            std::string csv_attr_content = "";
            csv_attr_content.append(csv_attr_start, csv_attr_end);
            if(csv_attr_content != ""){
                ((_tmx_data_desc + _tmx_curr_data)->tmx_data_field+i)->tmx_tileid = atoi(csv_attr_content.c_str());
            }
        }
    }
    
    
    
    
    //wenn id 0 ist dann auf NULL refren
}

void tmx_map_loader::tmx_parse_data(int _tmx_current_layer, std::string _tmx_xml_buffer, TMX_LAYER_DESC* tmx_layer_desc){
    //count data
    const char* data_counter_itr = strstr(_tmx_xml_buffer.c_str(), "<data ");
    int data_array_size = 0;
    while (true) {
        data_counter_itr = strstr(data_counter_itr, "<data ");
        if (data_counter_itr != 0) {
            data_counter_itr += 6; //"<data  "
            data_array_size++;
        }else {
            break;
        }
    }
    
    //alloc
    
    if(data_array_size < 1){return;}
    (tmx_layer_desc +_tmx_current_layer)->tmx_data_count =data_array_size;
    (tmx_layer_desc +_tmx_current_layer)->tmx_data = new TMX_DATA_DESC[data_array_size]();
    //for each data
    
    
    char* data_attr_start = strstr(_tmx_xml_buffer.c_str(), "<data ");
    
    for (int i = 0; i < data_array_size; i++) {
        
        ((tmx_layer_desc +_tmx_current_layer)->tmx_data+i)->tmx_layer = (tmx_layer_desc +_tmx_current_layer);
        
        
        
        data_attr_start = strstr(data_attr_start, "<data ");
        if(data_attr_start != NULL){
            data_attr_start += 6; //remove the <tileset
            char* data_attr_end = strstr(data_attr_start, ">");
            std::string data_attr_content = "";
            data_attr_content.append(data_attr_start, data_attr_end);
            char* data_end = strstr(++data_attr_end, "</data>");
            std::string data_content = ""; //the content of the tileset
            data_content.append(data_attr_end,data_end);
            if(data_attr_content == ""){continue;}
            
            //parse arguments
            char* attr_key_start = 0;
            char* attr_key_end = 0;
            std::string attr_value_string = "";
            //SEARCH ATTRIBITE
            attr_key_start = strstr(data_attr_content.c_str(), "encoding=\"");
            if(attr_key_start != nullptr){
                attr_key_start += strlen("encoding=\"");
                attr_key_end = strstr(attr_key_start,"\" ");
                if(attr_key_end == NULL){attr_key_end = strstr(attr_key_start,"\"");}
                if(attr_key_end != NULL){
                    attr_value_string.append(attr_key_start, attr_key_end);
                    //TODO STUFF
                    //strcpy(_map_desc->tmx_version, attr_value_string.c_str());
                    //(_tmx_layers_desc+i)->tmx_name = attr_value_string;
                    if(attr_value_string == "csv"){
                        ((tmx_layer_desc +_tmx_current_layer)->tmx_data+i)->tmx_data_encoding = TMX_DATA_ENCODING::tmx_data_encoding_csv;
                    }else if(attr_value_string == "base64"){
                        ((tmx_layer_desc +_tmx_current_layer)->tmx_data+i)->tmx_data_encoding = TMX_DATA_ENCODING::tmx_data_enconding_base64;
                    }else{
                        ((tmx_layer_desc +_tmx_current_layer)->tmx_data+i)->tmx_data_encoding = TMX_DATA_ENCODING::tmx_dataencoding_invalid;
                    }
                }
            }
            attr_key_start = 0;
            attr_key_end = 0;
            attr_value_string = "";
            
            
            //SET DEFUALT TO NONE
            ((tmx_layer_desc +_tmx_current_layer)->tmx_data+i)->tmx_data_compression = TMX_DATA_COMPRESSION::tmx_data_compression_none;
            //SEARCH ATTRIBITE
            attr_key_start = strstr(data_attr_content.c_str(), "compression=\"");
            if(attr_key_start != nullptr){
                attr_key_start += strlen("compression=\"");
                attr_key_end = strstr(attr_key_start,"\" ");
                if(attr_key_end == NULL){attr_key_end = strstr(attr_key_start,"\"");}
                if(attr_key_end != NULL){
                    attr_value_string.append(attr_key_start, attr_key_end);
                    //DO STUFF
                    //strcpy(_map_desc->tmx_version, attr_value_string.c_str());
                    //(_tmx_layers_desc+i)->tmx_name = attr_value_string;
                    if(attr_value_string == "gzip"){
                        ((tmx_layer_desc +_tmx_current_layer)->tmx_data+i)->tmx_data_compression = TMX_DATA_COMPRESSION::tmx_data_compression_gzip;
                    }else if(attr_value_string == "zlib"){
                        ((tmx_layer_desc +_tmx_current_layer)->tmx_data+i)->tmx_data_compression = TMX_DATA_COMPRESSION::tmx_data_compression_zlib;
                    }else{
                        ((tmx_layer_desc +_tmx_current_layer)->tmx_data+i)->tmx_data_compression = TMX_DATA_COMPRESSION::tmx_data_compression_invalid;
                    }
                }
            }
            attr_key_start = 0;
            attr_key_end = 0;
            attr_value_string = "";
            //get attr
            //get content
            //get csv !!!
            
            
            
            //CSV WITH NONE ENCODING
            if(((tmx_layer_desc +_tmx_current_layer)->tmx_data+i)->tmx_data_compression == TMX_DATA_COMPRESSION::tmx_data_compression_none && ((tmx_layer_desc +_tmx_current_layer)->tmx_data+i)->tmx_data_encoding == TMX_DATA_ENCODING::tmx_data_encoding_csv){
                tmx_parse_csv_none_encoding(i, data_content,(tmx_layer_desc +_tmx_current_layer)->tmx_data);
            }else{
                std::cout << "ONLY SUPPORTS CSV WITH NONE ENCODING" << std::endl;
            }
            
            
            
        }
    }//end for
    
}

void tmx_map_loader::tmx_parse_layers(int _tmx_count_layers, std::string _tmx_xml_buffer, TMX_LAYER_DESC* _tmx_layers_desc){
    
    // get attr WITH HEIGT !!!
    //get content
    //parse properties create new func
    //count data
    //alloca data
    //get data attr unsigned set to default
    //create datatiles
    //parse data with length and /n
    char* layer_attr_start = strstr(_tmx_xml_buffer.c_str(), "<layer ");
    
    for (int i = 0; i < _tmx_count_layers; i++) {
        layer_attr_start = strstr(layer_attr_start, "<layer ");
        if(layer_attr_start != NULL){
            layer_attr_start += 7; //remove the <tileset
            char* layer_attr_end = strstr(layer_attr_start, ">");
            std::string layer_attr_content = "";
            layer_attr_content.append(layer_attr_start, layer_attr_end);
            char* layer_end = strstr(++layer_attr_end, " </layer>");
            std::string layer_content = ""; //the content of the tileset
            layer_content.append(layer_attr_end,layer_end);
            if(layer_attr_content == ""){continue;}
            
            
            
            //PARSE ATTR
            
            //parse arguments
            char* attr_key_start = 0;
            char* attr_key_end = 0;
            std::string attr_value_string = "";
            //SEARCH ATTRIBITE
            attr_key_start = strstr(layer_attr_content.c_str(), "name=\"");
            if(attr_key_start != nullptr){
                attr_key_start += strlen("name=\"");
                attr_key_end = strstr(attr_key_start,"\" ");
                if(attr_key_end == NULL){attr_key_end = strstr(attr_key_start,"\"");}
                if(attr_key_end != NULL){
                    attr_value_string.append(attr_key_start, attr_key_end);
                    //DO STUFF
                    //strcpy(_map_desc->tmx_version, attr_value_string.c_str());
                    (_tmx_layers_desc+i)->tmx_name = attr_value_string;
                }
            }
            attr_key_start = 0;
            attr_key_end = 0;
            attr_value_string = "";
            
            //SEARCH ATTRIBITE
            attr_key_start = strstr(layer_attr_content.c_str(), "width=\"");
            if(attr_key_start != nullptr){
                attr_key_start += strlen("width=\"");
                attr_key_end = strstr(attr_key_start,"\" ");
                if(attr_key_end == NULL){attr_key_end = strstr(attr_key_start,"\"");}
                if(attr_key_end != NULL){
                    attr_value_string.append(attr_key_start, attr_key_end);
                    //DO STUFF
                    //strcpy(_map_desc->tmx_version, attr_value_string.c_str());
                    (_tmx_layers_desc+i)->tmx_width = atoi(attr_value_string.c_str());
                }
            }
            attr_key_start = 0;
            attr_key_end = 0;
            attr_value_string = "";
            
            //SEARCH ATTRIBITE
            attr_key_start = strstr(layer_attr_content.c_str(), "height=\"");
            if(attr_key_start != nullptr){
                attr_key_start += strlen("height=\"");
                attr_key_end = strstr(attr_key_start,"\" ");
                if(attr_key_end == NULL){attr_key_end = strstr(attr_key_start,"\"");}
                if(attr_key_end != NULL){
                    attr_value_string.append(attr_key_start, attr_key_end);
                    //DO STUFF
                    //strcpy(_map_desc->tmx_version, attr_value_string.c_str());
                    (_tmx_layers_desc+i)->tmx_height = atoi(attr_value_string.c_str());
                }
            }
            attr_key_start = 0;
            attr_key_end = 0;
            attr_value_string = "";
            
            
            //SEARCH ATTRIBITE
            attr_key_start = strstr(layer_attr_content.c_str(), "opacity=\"");
            if(attr_key_start != nullptr){
                attr_key_start += strlen("opacity=\"");
                attr_key_end = strstr(attr_key_start,"\" ");
                if(attr_key_end == NULL){attr_key_end = strstr(attr_key_start,"\"");}
                if(attr_key_end != NULL){
                    attr_value_string.append(attr_key_start, attr_key_end);
                    //DO STUFF
                    //strcpy(_map_desc->tmx_version, attr_value_string.c_str());
                    (_tmx_layers_desc+i)->tmx_opacity = atof(attr_value_string.c_str());
                }
            }
            attr_key_start = 0;
            attr_key_end = 0;
            attr_value_string = "";
            
            //SEARCH ATTRIBITE
            attr_key_start = strstr(layer_attr_content.c_str(), "offsetx=\"");
            if(attr_key_start != nullptr){
                attr_key_start += strlen("offsetx=\"");
                attr_key_end = strstr(attr_key_start,"\" ");
                if(attr_key_end == NULL){attr_key_end = strstr(attr_key_start,"\"");}
                if(attr_key_end != NULL){
                    attr_value_string.append(attr_key_start, attr_key_end);
                    //DO STUFF
                    //strcpy(_map_desc->tmx_version, attr_value_string.c_str());
                    (_tmx_layers_desc+i)->tmx_offsetx = atoi(attr_value_string.c_str());
                }
            }
            attr_key_start = 0;
            attr_key_end = 0;
            attr_value_string = "";
            
            
            //SEARCH ATTRIBITE
            attr_key_start = strstr(layer_attr_content.c_str(), "offsety=\"");
            if(attr_key_start != nullptr){
                attr_key_start += strlen("offsety=\"");
                attr_key_end = strstr(attr_key_start,"\" ");
                if(attr_key_end == NULL){attr_key_end = strstr(attr_key_start,"\"");}
                if(attr_key_end != NULL){
                    attr_value_string.append(attr_key_start, attr_key_end);
                    //DO STUFF
                    //strcpy(_map_desc->tmx_version, attr_value_string.c_str());
                    (_tmx_layers_desc+i)->tmx_offsety = atoi(attr_value_string.c_str());
                }
            }
            attr_key_start = 0;
            attr_key_end = 0;
            attr_value_string = "";
            
            //SEARCH ATTRIBITE
            attr_key_start = strstr(layer_attr_content.c_str(), "visible=\"");
            if(attr_key_start != nullptr){
                attr_key_start += strlen("visible=\"");
                attr_key_end = strstr(attr_key_start,"\" ");
                if(attr_key_end == NULL){attr_key_end = strstr(attr_key_start,"\"");}
                if(attr_key_end != NULL){
                    attr_value_string.append(attr_key_start, attr_key_end);
                    //DO STUFF
                    //strcpy(_map_desc->tmx_version, attr_value_string.c_str());
                    if(attr_value_string == "1"){
                        (_tmx_layers_desc+i)->tmx_visible = true;
                    }else if(attr_value_string == "0"){
                        (_tmx_layers_desc+i)->tmx_visible = false;
                    }else{
                        (_tmx_layers_desc+i)->tmx_visible = true;
                    }
                }
            }
            attr_key_start = 0;
            attr_key_end = 0;
            attr_value_string = "";
            
            
            if(layer_content == ""){continue;}
            tmx_parse_property(i, layer_content, _tmx_layers_desc);
            tmx_parse_data(i, layer_content, _tmx_layers_desc);
            
        }//end for
        
    }
    
}

void tmx_map_loader::tmx_parse_tilesets(int _tmx_count_tilesets, std::string _tmx_xml_buffer, TMX_TILESET_DESC* _tmx_tilesets_desc){
    
    
    
    //get the <map attr="1" attr="2">
    char* tileset_attr_start = strstr(_tmx_xml_buffer.c_str(), "<tileset");
    
    for (int i = 0; i < _tmx_count_tilesets; i++) {
        tileset_attr_start = strstr(tileset_attr_start, "<tileset");
        if(tileset_attr_start != NULL){
            tileset_attr_start += 8; //remove the <tileset
            char* tileset_attr_end = strstr(tileset_attr_start, ">");
            std::string tileset_attr_content = "";
            tileset_attr_content.append(tileset_attr_start, tileset_attr_end);
            char* tileset_end = strstr(++tileset_attr_end, " </tileset>");
            std::string tileset_content = ""; //the content of the tileset
            tileset_content.append(tileset_attr_end,tileset_end);
            
            
            
            
            //parse arguments
            char* attr_key_start = 0;
            char* attr_key_end = 0;
            std::string attr_value_string = "";
            //SEARCH ATTRIBITE
            attr_key_start = strstr(tileset_attr_content.c_str(), "firstgid=\"");
            if(attr_key_start != nullptr){
                attr_key_start += strlen("firstgid=\"");
                attr_key_end = strstr(attr_key_start,"\" ");
                if(attr_key_end == NULL){attr_key_end = strstr(attr_key_start,"\"");}
                if(attr_key_end != NULL){
                    attr_value_string.append(attr_key_start, attr_key_end);
                    //DO STUFF
                    //strcpy(_map_desc->tmx_version, attr_value_string.c_str());
                    (_tmx_tilesets_desc+i)->tmx_firstgid = atoi(attr_value_string.c_str());
                }
            }
            attr_key_start = 0;
            attr_key_end = 0;
            attr_value_string = "";
            
            //SEARCH ATTRIBITE
            attr_key_start = strstr(tileset_attr_content.c_str(), "source=\"");
            if(attr_key_start != nullptr){
                attr_key_start += strlen("source=\"");
                attr_key_end = strstr(attr_key_start,"\" ");
                if(attr_key_end == NULL){attr_key_end = strstr(attr_key_start,"\"");}
                if(attr_key_end != NULL){
                    attr_value_string.append(attr_key_start, attr_key_end);
                    //DO STUFF
                    //strcpy(_map_desc->tmx_version, attr_value_string.c_str());
                    (_tmx_tilesets_desc+i)->tmx_source = attr_value_string;
                }
            }
            attr_key_start = 0;
            attr_key_end = 0;
            attr_value_string = "";
            
            
            //SEARCH ATTRIBITE
            attr_key_start = strstr(tileset_attr_content.c_str(), "name=\"");
            if(attr_key_start != nullptr){
                attr_key_start += strlen("name=\"");
                attr_key_end = strstr(attr_key_start,"\" ");
                if(attr_key_end == NULL){attr_key_end = strstr(attr_key_start,"\"");}
                if(attr_key_end != NULL){
                    attr_value_string.append(attr_key_start, attr_key_end);
                    //DO STUFF
                    //strcpy(_map_desc->tmx_version, attr_value_string.c_str());
                    (_tmx_tilesets_desc+i)->tmx_name = attr_value_string;
                }
            }
            attr_key_start = 0;
            attr_key_end = 0;
            attr_value_string = "";
            
            //SEARCH ATTRIBITE
            attr_key_start = strstr(tileset_attr_content.c_str(), "tilewidth=\"");
            if(attr_key_start != nullptr){
                attr_key_start += strlen("tilewidth=\"");
                attr_key_end = strstr(attr_key_start,"\" ");
                if(attr_key_end == NULL){attr_key_end = strstr(attr_key_start,"\"");}
                if(attr_key_end != NULL){
                    attr_value_string.append(attr_key_start, attr_key_end);
                    //DO STUFF
                    //strcpy(_map_desc->tmx_version, attr_value_string.c_str());
                    (_tmx_tilesets_desc+i)->tmx_tilewidth = atoi(attr_value_string.c_str());
                    
                }
            }
            attr_key_start = 0;
            attr_key_end = 0;
            attr_value_string = "";
            
            
            //SEARCH ATTRIBITE
            attr_key_start = strstr(tileset_attr_content.c_str(), "tileheight=\"");
            if(attr_key_start != nullptr){
                attr_key_start += strlen("tileheight=\"");
                attr_key_end = strstr(attr_key_start,"\" ");
                if(attr_key_end == NULL){attr_key_end = strstr(attr_key_start,"\"");}
                if(attr_key_end != NULL){
                    attr_value_string.append(attr_key_start, attr_key_end);
                    //DO STUFF
                    //strcpy(_map_desc->tmx_version, attr_value_string.c_str());
                    (_tmx_tilesets_desc+i)->tmx_tileheight = atoi(attr_value_string.c_str());
                    
                }
            }
            attr_key_start = 0;
            attr_key_end = 0;
            attr_value_string = "";
            
            
            //SEARCH ATTRIBITE
            attr_key_start = strstr(tileset_attr_content.c_str(), "spacing=\"");
            if(attr_key_start != nullptr){
                attr_key_start += strlen("spacing=\"");
                attr_key_end = strstr(attr_key_start,"\" ");
                if(attr_key_end == NULL){attr_key_end = strstr(attr_key_start,"\"");}
                if(attr_key_end != NULL){
                    attr_value_string.append(attr_key_start, attr_key_end);
                    //DO STUFF
                    //strcpy(_map_desc->tmx_version, attr_value_string.c_str());
                    (_tmx_tilesets_desc+i)->tmx_spacing = atoi(attr_value_string.c_str());
                    
                }
            }
            attr_key_start = 0;
            attr_key_end = 0;
            attr_value_string = "";
            
            
            //SEARCH ATTRIBITE
            attr_key_start = strstr(tileset_attr_content.c_str(), "margin=\"");
            if(attr_key_start != nullptr){
                attr_key_start += strlen("margin=\"");
                attr_key_end = strstr(attr_key_start,"\" ");
                if(attr_key_end == NULL){attr_key_end = strstr(attr_key_start,"\"");}
                if(attr_key_end != NULL){
                    attr_value_string.append(attr_key_start, attr_key_end);
                    //DO STUFF
                    //strcpy(_map_desc->tmx_version, attr_value_string.c_str());
                    (_tmx_tilesets_desc+i)->tmx_margin = atoi(attr_value_string.c_str());
                    
                }
            }
            attr_key_start = 0;
            attr_key_end = 0;
            attr_value_string = "";
            
            
            
            //SEARCH ATTRIBITE
            attr_key_start = strstr(tileset_attr_content.c_str(), "tilecount=\"");
            if(attr_key_start != nullptr){
                attr_key_start += strlen("tilecount=\"");
                attr_key_end = strstr(attr_key_start,"\" ");
                if(attr_key_end == NULL){attr_key_end = strstr(attr_key_start,"\"");}
                if(attr_key_end != NULL){
                    attr_value_string.append(attr_key_start, attr_key_end);
                    //DO STUFF
                    //strcpy(_map_desc->tmx_version, attr_value_string.c_str());
                    (_tmx_tilesets_desc+i)->tmx_tilecount = atoi(attr_value_string.c_str());
                    
                }
            }
            attr_key_start = 0;
            attr_key_end = 0;
            attr_value_string = "";
            
            
            //SEARCH ATTRIBITE
            attr_key_start = strstr(tileset_attr_content.c_str(), "columns=\"");
            if(attr_key_start != nullptr){
                attr_key_start += strlen("columns=\"");
                attr_key_end = strstr(attr_key_start,"\" ");
                if(attr_key_end == NULL){attr_key_end = strstr(attr_key_start,"\"");}
                if(attr_key_end != NULL){
                    attr_value_string.append(attr_key_start, attr_key_end);
                    //DO STUFF
                    //strcpy(_map_desc->tmx_version, attr_value_string.c_str());
                    (_tmx_tilesets_desc+i)->tmx_columns = atoi(attr_value_string.c_str());
                    
                }
            }
            attr_key_start = 0;
            attr_key_end = 0;
            attr_value_string = "";
            
            
            //CALC ROWS
            if((_tmx_tilesets_desc+i)->tmx_columns > 0){
                (_tmx_tilesets_desc+i)->tmx_rows =  (_tmx_tilesets_desc+i)->tmx_tilecount /  (_tmx_tilesets_desc+i)->tmx_columns;
            }else{
                (_tmx_tilesets_desc+i)->tmx_rows = 0;
                (_tmx_tilesets_desc+i)->tmx_tilecount = 0;
                (_tmx_tilesets_desc+i)->tmx_columns = 0;
            }
            
            //send tileset_content to other punction
            //parse_tileset_content....
            tmx_parse_image(i, tileset_content, _tmx_tilesets_desc);
            tmx_parse_tile(i, tileset_content, _tmx_tilesets_desc);
            
            //parse layer
            //parse imagelayer
            //objectgroup nur rechecke
            
        }else{
            break;
        }
        
    }
    
}

std::string tmx_map_loader::tmx_parse_map_desc(char* _tmx_xml_buffer, TMX_MAP_DESC* _map_desc){
    //get the <map attr="1" attr="2">
    char* map_attr_start = strstr(_tmx_xml_buffer, "<map");
    map_attr_start += 4; //remove the <map
    char* map_attr_end = strstr(map_attr_start, ">");
    std::string map_attr_content = "";
    map_attr_content.append(map_attr_start, map_attr_end);
    char* map_end = strstr(++map_attr_end, "</map>");
    std::string map_content = "";
    map_content.append(map_attr_end,map_end);
    
    char* attr_key_start = 0;
    char* attr_key_end = 0;
    std::string attr_value_string = "";
    //SEARCH ATTRIBITE
    attr_key_start = strstr(map_attr_content.c_str(), "version=\"");
    if(attr_key_start != nullptr){
        attr_key_start += strlen("version=\"");
        attr_key_end = strstr(attr_key_start,"\" ");
        if(attr_key_end == NULL){attr_key_end = strstr(attr_key_start,"\"");}
        if(attr_key_end != NULL){
            attr_value_string.append(attr_key_start, attr_key_end);
            //DO STUFF
            strcpy(_map_desc->tmx_version, attr_value_string.c_str());
        }
    }
    attr_key_start = 0;
    attr_key_end = 0;
    attr_value_string = "";
    
    
    attr_key_start = strstr(map_attr_content.c_str(), "orientation=\"");
    if(attr_key_start != nullptr){
        attr_key_start += strlen("orientation=\"");
        attr_key_end = strstr(attr_key_start,"\" ");
        if(attr_key_end == NULL){attr_key_end = strstr(attr_key_start,"\"");}
        if(attr_key_end != NULL){
            attr_value_string.append(attr_key_start, attr_key_end);
            //DO STUFF
            if(attr_value_string == "orthogonal"){_map_desc->tmx_orientation = TMX_MAP_ORIENTATION::orthogonal;}
            else if(attr_value_string == "isometric"){_map_desc->tmx_orientation = TMX_MAP_ORIENTATION::isometric;}
            else if(attr_value_string == "staggered"){_map_desc->tmx_orientation = TMX_MAP_ORIENTATION::staggerred;}
            else if(attr_value_string == "hexagonal"){_map_desc->tmx_orientation = TMX_MAP_ORIENTATION::hexagonal;}
            else{_map_desc->tmx_orientation = TMX_MAP_ORIENTATION::invalid_orientation;}
        }
    }
    attr_key_start = 0;
    attr_key_end = 0;
    attr_value_string = "";
    
    
    attr_key_start = strstr(map_attr_content.c_str(), "renderorder=\"");
    if(attr_key_start != nullptr){
        attr_key_start += strlen("renderorder=\"");
        attr_key_end = strstr(attr_key_start,"\" ");
        if(attr_key_end == NULL){attr_key_end = strstr(attr_key_start,"\"");}
        if(attr_key_end != NULL){
            attr_value_string.append(attr_key_start, attr_key_end);
            //DO STUFF
            if(attr_value_string == "left-up"){_map_desc->tmx_renderorder = TMX_MAP_RENDERORDER::left_up;}
            else if(attr_value_string == "left-down"){_map_desc->tmx_renderorder = TMX_MAP_RENDERORDER::left_down;}
            else if(attr_value_string == "right-up"){_map_desc->tmx_renderorder = TMX_MAP_RENDERORDER::right_up;}
            else if(attr_value_string == "right-down"){_map_desc->tmx_renderorder = TMX_MAP_RENDERORDER::right_down;}
            else{_map_desc->tmx_renderorder = TMX_MAP_RENDERORDER::invalid_renderorder;}
        }
    }
    attr_key_start = 0;
    attr_key_end = 0;
    attr_value_string = "";
    
    
    
    //SEARCH ATTRIBITE
    attr_key_start = strstr(map_attr_content.c_str(), "width=\"");
    if(attr_key_start != nullptr){
        attr_key_start += strlen("width=\"");
        attr_key_end = strstr(attr_key_start,"\" ");
        if(attr_key_end == NULL){attr_key_end = strstr(attr_key_start,"\"");}
        if(attr_key_end != NULL){
            attr_value_string.append(attr_key_start, attr_key_end);
            //DO STUFF
            _map_desc->tmx_width = atoi(attr_value_string.c_str());
        }
    }
    attr_key_start = 0;
    attr_key_end = 0;
    attr_value_string = "";
    
    //SEARCH ATTRIBITE
    attr_key_start = strstr(map_attr_content.c_str(), "height=\"");
    if(attr_key_start != nullptr){
        attr_key_start += strlen("height=\"");
        attr_key_end = strstr(attr_key_start,"\" ");
        if(attr_key_end == NULL){attr_key_end = strstr(attr_key_start,"\"");}
        if(attr_key_end != NULL){
            attr_value_string.append(attr_key_start, attr_key_end);
            //DO STUFF
            _map_desc->tmx_height = atoi(attr_value_string.c_str());
        }
    }
    attr_key_start = 0;
    attr_key_end = 0;
    attr_value_string = "";
    
    
    //SEARCH ATTRIBITE
    attr_key_start = strstr(map_attr_content.c_str(), "tilewidth=\"");
    if(attr_key_start != nullptr){
        attr_key_start += strlen("tilewidth=\"");
        attr_key_end = strstr(attr_key_start,"\" ");
        if(attr_key_end == NULL){attr_key_end = strstr(attr_key_start,"\"");}
        if(attr_key_end != NULL){
            attr_value_string.append(attr_key_start, attr_key_end);
            //DO STUFF
            _map_desc->tmx_tilewidth = atoi(attr_value_string.c_str());
        }
    }
    attr_key_start = 0;
    attr_key_end = 0;
    attr_value_string = "";
    //SEARCH ATTRIBITE
    attr_key_start = strstr(map_attr_content.c_str(), "tileheight=\"");
    if(attr_key_start != nullptr){
        attr_key_start += strlen("tileheight=\"");
        attr_key_end = strstr(attr_key_start,"\" ");
        if(attr_key_end == NULL){attr_key_end = strstr(attr_key_start,"\"");}
        if(attr_key_end != NULL){
            attr_value_string.append(attr_key_start, attr_key_end);
            //DO STUFF
            _map_desc->tmx_tileheight = atoi(attr_value_string.c_str());
        }
    }
    attr_key_start = 0;
    attr_key_end = 0;
    attr_value_string = "";
    if(_map_desc->tmx_orientation == TMX_MAP_ORIENTATION::hexagonal){
        //SEARCH ATTRIBITE
        attr_key_start = strstr(map_attr_content.c_str(), "hexsidelenght=\"");
        if(attr_key_start != nullptr){
            attr_key_start += strlen("hexsidelenght=\"");
            attr_key_end = strstr(attr_key_start,"\" ");
            if(attr_key_end == NULL){attr_key_end = strstr(attr_key_start,"\"");}
            if(attr_key_end != NULL){
                attr_value_string.append(attr_key_start, attr_key_end);
                //DO STUFF
                _map_desc->tmx_hexsidelenght = atoi(attr_value_string.c_str());
            }
        }
        attr_key_start = 0;
        attr_key_end = 0;
        attr_value_string = "";
    }
    
    
    if(_map_desc->tmx_orientation == TMX_MAP_ORIENTATION::hexagonal || _map_desc->tmx_orientation == TMX_MAP_ORIENTATION::staggerred){
        //SEARCH ATTRIBITE
        attr_key_start = strstr(map_attr_content.c_str(), "staggeraxis=\"");
        if(attr_key_start != nullptr){
            attr_key_start += strlen("staggeraxis=\"");
            attr_key_end = strstr(attr_key_start,"\" ");
            if(attr_key_end == NULL){attr_key_end = strstr(attr_key_start,"\"");}
            if(attr_key_end != NULL){
                attr_value_string.append(attr_key_start, attr_key_end);
                //DO STUFF
                if(attr_value_string == "x"){_map_desc->tmx_staggeraxis = TMX_MAP_STAGGERAXIS::staggeraxis_x;}
                else if(attr_value_string == "y"){_map_desc->tmx_staggeraxis = TMX_MAP_STAGGERAXIS::staggeraxis_y;}
                else{_map_desc->tmx_staggeraxis = TMX_MAP_STAGGERAXIS::invalid_staggeraxis;}
            }
        }
        attr_key_start = 0;
        attr_key_end = 0;
        attr_value_string = "";
        
        //SEARCH ATTRIBITE
        attr_key_start = strstr(map_attr_content.c_str(), "staggerindex=\"");
        if(attr_key_start != nullptr){
            attr_key_start += strlen("staggerindex=\"");
            attr_key_end = strstr(attr_key_start,"\" ");
            if(attr_key_end == NULL){attr_key_end = strstr(attr_key_start,"\"");}
            if(attr_key_end != NULL){
                attr_value_string.append(attr_key_start, attr_key_end);
                //DO STUFF
                if(attr_value_string == "even"){_map_desc->tmx_staggerindex = TMX_MAP_STAGGERINDEX::staggerindex_even;}
                else if(attr_value_string == "odd"){_map_desc->tmx_staggerindex = TMX_MAP_STAGGERINDEX::staggerindex_odd;}
                else {_map_desc->tmx_staggerindex = TMX_MAP_STAGGERINDEX::invalid_staggerindex;}
            }
        }
        attr_key_start = 0;
        attr_key_end = 0;
        attr_value_string = "";
    }
    
    
    //SEARCH ATTRIBITE
    attr_key_start = strstr(map_attr_content.c_str(), "nextobjectid=\"");
    if(attr_key_start != nullptr){
        attr_key_start += strlen("nextobjectid=\"");
        attr_key_end = strstr(attr_key_start,"\" ");
        if(attr_key_end == NULL){
            attr_key_end = strstr(attr_key_start,"\"");
        }
        if(attr_key_end != NULL){
            attr_value_string.append(attr_key_start, attr_key_end);
            //DO STUFF
            _map_desc->tmx_nextobjectid = atoi(attr_value_string.c_str());
        }
    }
    attr_key_start = 0;
    attr_key_end = 0;
    attr_value_string = "";
    
    
    //SEARCH ATTRIBITE
    attr_key_start = strstr(map_attr_content.c_str(), "backgroundcolor=\"#");
    if(attr_key_start != nullptr){
        attr_key_start += strlen("backgroundcolor=\"#");
        attr_key_end = strstr(attr_key_start,"\" ");
        if(attr_key_end == NULL){attr_key_end = strstr(attr_key_start,"\"");}
        if(attr_key_end != NULL){
            attr_value_string.append(attr_key_start, attr_key_end);
            //DO STUFF
            sscanf(attr_value_string.c_str(), "%x", &_map_desc->tmx_backgroundcolor);
        }
    }
    attr_key_start = 0;
    attr_key_end = 0;
    attr_value_string = "";
    
    
    return map_content;
}

bool tmx_map_loader::tmx_load_map(const char* _tmx_file_path){
    
    
    //READ COMPLETE FILE TO BUFFER
    char * complete_content_buffer = 0;
    long length;
    FILE * file_handler = fopen (_tmx_file_path, "r");
    
    if (file_handler)
    {
        fseek (file_handler, 0, SEEK_END); //end to get filelenght
        length = ftell (file_handler);
        fseek (file_handler, 0, SEEK_SET);
        complete_content_buffer = (char*)malloc (length);
        if (complete_content_buffer)
        {
            fread (complete_content_buffer, 1, length, file_handler);
        }
        fclose (file_handler);
    }
    
    if (complete_content_buffer)
    {
        
        
        
        //TODO: remove the /n
        
        
        //PARSE THE <map>
        std::string map_content = "";
        map_content =  tmx_parse_map_desc(complete_content_buffer, map_desc);
        //TODO: check map validation
        
        
        
        
        //now parse the tilesets
        //first count the tilesets to allocate the array
        const char* tileset_counter_itr = strstr(map_content.c_str(), "<tileset ");
        int tileset_array_size = 0;
        while (true) {
            tileset_counter_itr = strstr(tileset_counter_itr, "<tileset ");
            if (tileset_counter_itr != 0) {
                tileset_counter_itr += 9; //"<tileset "
                tileset_array_size++;
            }else {
                break;
            }
        }
        //init all new allocations -> set invalid values set pointer to 0
        tilesets_desc = new TMX_TILESET_DESC[tileset_array_size]();
        for (int i = 0; i < tileset_array_size; i++) {
            tmx_create_tileset_descriptor((tilesets_desc+i));
        }
        //now parse the tileset attributes and process the content further
        tmx_parse_tilesets(tileset_array_size, map_content, tilesets_desc);
        map_desc->tmx_tilesetamount =tileset_array_size;
        
        for (int i = 0; i < tileset_array_size; i++) {
            (tilesets_desc + i)->tmx_map_description = map_desc;
        }
        //now parse all layers
        const char* layer_counter_itr = strstr(map_content.c_str(), "<layer ");
        int layer_array_size = 0;
        while (true) {
            layer_counter_itr = strstr(layer_counter_itr, "<layer ");
            if (layer_counter_itr != 0) {
                layer_counter_itr += 7; //"<tileset "
                layer_array_size++;
            }else {
                break;
            }
        }
        //init all new allocations -> set invalid values set pointer to 0
        layer_desc = new TMX_LAYER_DESC[layer_array_size]();
        map_desc->tmx_layeramount = layer_array_size;
        for (int i = 0; i < layer_array_size; i++) {
            tmx_create_layer_descriptor((layer_desc+i));
            //since tiledQt
            (layer_desc+i)->tmx_height = map_desc->tmx_height;
            (layer_desc+i)->tmx_width = map_desc->tmx_width;
            (layer_desc+i)->tmx_posy = 0;
            (layer_desc+i)->tmx_posy = 0;
            (layer_desc+i)->tmx_map = map_desc;
        }
        tmx_parse_layers(layer_array_size,map_content,layer_desc);
        
        //LAST STEP OF LOAD LINK TILESETS
        
        
        //LINK TILES
        //find tileset
        //find tile in tileset
        TMX_TILE_DESC* last_tile = NULL;
        for (int i = 0; i < map_desc->tmx_layeramount; i++) {
            for (int j = 0; j < (layer_desc+i)->tmx_data_count; j++) {
                for (int k = 0; k < ((layer_desc+i)->tmx_data+j)->tmx_data_field_count; k++) {
                    //IF THE THE LAST ID WAS THE SAME DONT SEARCH
                    if((((layer_desc+i)->tmx_data+j)->tmx_data_field+k)->tmx_tileid == 0){
                        last_tile = NULL;
                        (((layer_desc+i)->tmx_data+j)->tmx_data_field+k)->tmx_tile = NULL;
                        continue;
                    }
                    if(last_tile != NULL && (((layer_desc+i)->tmx_data+j)->tmx_data_field+k)->tmx_tileid == last_tile->tmx_gridid){
                        (((layer_desc+i)->tmx_data+j)->tmx_data_field+k)->tmx_tile =last_tile;
                    }else{
                        //SEARCH IN TILESETS
                        
                        for (int l = 0; l < map_desc->tmx_tilesetamount; l++) {
                            for (int m = 0; m < (tilesets_desc+l)->tmx_tilecount; m++) {
                                if(((tilesets_desc+l)->tmx_tile_desc+l)->tmx_gridid == (((layer_desc+i)->tmx_data+j)->tmx_data_field+k)->tmx_tileid){
                                    last_tile =((tilesets_desc+l)->tmx_tile_desc+l);
                                    (((layer_desc+i)->tmx_data+j)->tmx_data_field+k)->tmx_tile = last_tile;
                                    break;
                                }
                            }
                        }
                    }
                }
            }
        }
        
        
        
        
        
        
        //TODO: check if assetfolder set
        //TODO: check if all image files exists
        //TODO: build textureatlas class
        //TODO: refer tiles to textureclass atlas
        
        
        
        char el = 0;
        //free buffer
        free(complete_content_buffer);
        complete_content_buffer = 0;
        file_handler = 0;
        
        return true;
    }else{
        //free buffer
        free(complete_content_buffer);
        complete_content_buffer = 0;
        file_handler = 0;
        
        return false;
    }
    

}





