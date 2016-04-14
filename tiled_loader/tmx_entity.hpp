//
//  tmx_entity.hpp
//  tiled_loader
//
//  Created by Marcel Ochsendorf on 12.04.16.
//  Copyright © 2016 Marcel Ochsendorf. All rights reserved.
//

#ifndef tmx_entity_hpp
#define tmx_entity_hpp

#include <stdio.h>
#include <cstring>
#include <iostream>
#include <stdlib.h>
#include "glm_include.h"
#include "tmx_model_buffer.hpp"

class tmx_entity{
public:
    
    
    struct transforms_mat{
        glm::mat4x4 postion;
        glm::mat4x4 scale;
        glm::mat4x4 roation;
    };
    
    struct transforms_vec{
        glm::vec3 position;
        glm::vec3 scale;
        glm::vec3 roation;
    };
    
    transforms_mat transform_matrices;
    transforms_vec transform;
    
    
    std::string name;
    std::string tag;
    bool is_active;
    int gid;
    
    
    
    tmx_entity* parent_entity;
    tmx_model_buffer* model;
    
    tmx_entity(std::string _name = "GameObject", std::string _tag = "", tmx_entity* _parent = NULL);
    ~tmx_entity();
    tmx_entity* get_parent();
    
    //void setShader(tmx_shader* _shader);
    
    bool isActive();
    void setActive(bool _state);
    void setModel(const char* _path);
    
    
    void setRoation(glm::vec3 _axis, float _degree);
    void setPosition(glm::vec3 _transform);
    void setScale(glm::vec3 _scale);
    void apply_transform_to_model();
    static int gid_counter;
    static int get_gid();
    

};
#endif /* tmx_entity_hpp */


//erst null ausser wenn object wird geladen wir es auch zur renderliste hinzugefügtholds vertex buffer
//holds shader
//holds transform functions
//holds textures
//holds aabb
//name
//id
//holds parent at render gets the matrix of the parent to calc right positons
//holds visible state at change goto all other and set values
//tag