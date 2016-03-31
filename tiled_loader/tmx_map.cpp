//
//  tmp_map.cpp
//  tiled_loader
//
//  Created by Marcel Ochsendorf on 29.03.16.
//  Copyright © 2016 Marcel Ochsendorf. All rights reserved.
//

#include "tmx_map.hpp"

tmx_map::tmx_map(){
   map_desc = new TMX_MAP_DESC();
    tmx_create_map_descriptor(map_desc);
    

}




tmx_map::~tmx_map(){
    //cleanup tileset desc
    delete[] tilesets_desc->tmx_tile_desc->tmx_animation_desc->tmx_frames;
    delete[] tilesets_desc->tmx_tile_desc->tmx_animation_desc;
    delete[] tilesets_desc->tmx_tile_desc->tmx_properties_desc;
    delete[] tilesets_desc;
  
    //cleanup map
    delete map_desc;
}



void tmx_map::tmx_create_map_descriptor(tmx_map::TMX_MAP_DESC* _tmx_map_desc){
    strcpy(_tmx_map_desc->tmx_version , "0.0");
    _tmx_map_desc->tmx_orientation = TMX_MAP_ORIENTATION::invalid_orientation;
    _tmx_map_desc->tmx_renderorder = TMX_MAP_RENDERORDER::invalid_renderorder;
    _tmx_map_desc->tmx_width = -1;
    _tmx_map_desc->tmx_height = -1;
    _tmx_map_desc->tmx_tilewidth = -1;
    _tmx_map_desc->tmx_tileheight = -1;
    _tmx_map_desc->tmx_hexsidelenght = -1;
    _tmx_map_desc->tmx_staggeraxis = TMX_MAP_STAGGERAXIS::invalid_staggeraxis;
    _tmx_map_desc->tmx_staggerindex = TMX_MAP_STAGGERINDEX::invalid_staggerindex;
    _tmx_map_desc->tmx_backgroundcolor = -1;
    _tmx_map_desc->tmx_nextobjectid = -1;
}
//\"
void tmx_map::tmx_create_image_desc(tmx_map::TMX_IMAGE_DESC* _tmx_image_desc){
    _tmx_image_desc->tmx_height = -1;
    _tmx_image_desc->tmx_width = -1;
    _tmx_image_desc->tmx_image_format = "";
    _tmx_image_desc->tmx_image_source = "";
    _tmx_image_desc->tmx_trans_color = 0;
}

void tmx_map::tmx_create_tileset_descriptor(tmx_map::TMX_TILESET_DESC* _tmx_tileset_desc){
    _tmx_tileset_desc->tmx_firstgid = -1;
    _tmx_tileset_desc->tmx_source = "";
    _tmx_tileset_desc->tmx_name = "";
    _tmx_tileset_desc->tmx_tilewidth = -1;
    _tmx_tileset_desc->tmx_tileheight = -1;
    _tmx_tileset_desc->tmx_spacing = -1;
    _tmx_tileset_desc->tmx_margin = -1;
    _tmx_tileset_desc->tmx_tilecount = -1;
    _tmx_tileset_desc->tmx_columns = -1;
    tmx_create_image_desc(&_tmx_tileset_desc->tmx_image_desc);
    _tmx_tileset_desc->tmx_tile_desc = 0;
}

void tmx_map::tmx_parse_image(int _tmx_curr_tileset, std::string _tmx_xml_buffer, TMX_TILESET_DESC* _tmx_tilesets_desc){
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

void tmx_map::tmx_parse_tile(int _tmx_curr_tileset, std::string _tmx_xml_buffer, TMX_TILESET_DESC* _tmx_tileset_desc){
//count tiles
    //go tgrough each tile
    //get attr return content
    //count properties
    //count animation
    
    
    
    /*
     BEIM ERSTELLEN DER TILES ALLE TILES MIT ID ERSTELLEN UND DA WO PROPERTIES VORHANDEN SIND DIESE SPEICHERN
     ZUSÄTZLICH NOCH DEN PIXELAUSCHNITT MIRSPEICHERN
     */
    
}

void tmx_map::tmx_parse_tilesets(int _tmx_count_tilesets, std::string _tmx_xml_buffer, TMX_TILESET_DESC* _tmx_tilesets_desc){

    
    
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
            
            
            //send tileset_content to other punction
            //parse_tileset_content....
            tmx_parse_image(i, tileset_content, _tmx_tilesets_desc);
            tmx_parse_tile(i, tileset_content, _tmx_tilesets_desc);
            
            
            
        }else{
            break;
        }
        
    }
    
    
}


std::string tmx_map::tmx_parse_map_desc(char* _tmx_xml_buffer, tmx_map::TMX_MAP_DESC* _map_desc){
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



bool tmx_map::tmx_load_map(const char* _tmx_file_path){
    
    
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

        
        
        
        
        
        
        
        
        char el = 0;
    }
    
    //free buffer
    free(complete_content_buffer);
    complete_content_buffer = 0;
    file_handler = 0;
    
    return false;
}






