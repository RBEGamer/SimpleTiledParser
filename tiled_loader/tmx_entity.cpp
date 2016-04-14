//
//  ;
//  tiled_loader
//
//  Created by Marcel Ochsendorf on 12.04.16.
//  Copyright © 2016 Marcel Ochsendorf. All rights reserved.
//

#include "tmx_entity.hpp"


int gid;

tmx_entity::tmx_entity(std::string _name, std::string _tag, tmx_entity* _parent){
    name = _name;
    tag = _tag;
    is_active = true;
    gid = tmx_entity::get_gid();
    
    
    transform.position = glm::vec3(0.0f, 0.0f, 0.0f);
    transform.roation = glm::vec3(0.0f, 0.0f, 0.0f);
    transform.scale = glm::vec3(1.0f, 1.0f, 1.0f);
    //get parent matrices
    //TODO REMOVE
    transform_matrices.postion = glm::mat4x4(1.0f);
    transform_matrices.scale = glm::mat4x4(1.0f);
    transform_matrices.roation = glm::mat4x4(1.0f);
    //Create matrices
    transform_matrices.postion = glm::translate(transform_matrices.postion, transform.position);
    transform_matrices.scale= glm::scale(transform_matrices.scale, transform.scale);
    
    
    
    parent_entity  = _parent;
    
}



void tmx_entity::setRoation(glm::vec3 _axis, float _degree){
    transform.roation = _axis * _degree; //TODO FIX
    transform_matrices.roation = glm::rotate(transform_matrices.roation, _degree, _axis);
    apply_transform_to_model();
}

void tmx_entity::setPosition(glm::vec3 _transform){
    transform.position =_transform;
    transform_matrices.postion = glm::translate(transform_matrices.postion, transform.position);
    apply_transform_to_model();
}

void tmx_entity::setScale(glm::vec3 _scale){
    transform.scale = _scale;
    transform_matrices.scale= glm::scale(transform_matrices.scale, transform.scale);
    apply_transform_to_model();
}



void tmx_entity::apply_transform_to_model(){
    if(model == NULL){return;}
    model->translate_matrix = transform_matrices.postion;
    model->scale_matrix = transform_matrices.scale;
    model->roation_matrix = transform_matrices.roation;
    model->calc_local_matrix();
}


tmx_entity::~tmx_entity(){
    if(model != NULL){
        delete model;
    }
}


//void setShader(tmx_shader* _shader);

bool tmx_entity::isActive(){
    return is_active;
}

void tmx_entity::setActive(bool _state){
    is_active = _state;
    //TODO GOT THROUGH ALL OTHER childs
}

tmx_entity* tmx_entity::get_parent(){
    return parent_entity;
}


void tmx_entity::setModel(const char* _path){
    if(model == NULL){
        model = new tmx_model_buffer(0);
        model->load_obj(_path);
        //add to renderqueue
    }

}




//STATIC
int get_gid(){
    tmx_entity::gid_counter ++;
    return tmx_entity::gid_counter;
}

static tmx_entity* get_parent(){
    return NULL;
}

