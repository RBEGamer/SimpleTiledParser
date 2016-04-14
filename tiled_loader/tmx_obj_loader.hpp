//
//  tmx_obj_loader.hpp
//  tiled_loader
//
//  Created by Marcel Ochsendorf on 09.04.16.
//  Copyright © 2016 Marcel Ochsendorf. All rights reserved.
//

#ifndef tmx_obj_loader_hpp
#define tmx_obj_loader_hpp

#include <stdio.h>
#include "tmx_helper_functions.hpp"
#include <vector>
#include "glm_include.h"
class tmx_obj_loader{


public:
    tmx_obj_loader();
    ~tmx_obj_loader();
    
    
    bool loadOBJ(const char * path,std::vector<glm::vec3> & out_vertices,std::vector<glm::vec2> & out_uvs,std::vector<glm::vec3> & out_normals);



};

#endif /* tmx_obj_loader_hpp */

