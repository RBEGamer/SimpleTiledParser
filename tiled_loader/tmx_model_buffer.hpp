//
//  tmx_model_buffer.hpp
//  tiled_loader
//
//  Created by Marcel Ochsendorf on 09.04.16.
//  Copyright © 2016 Marcel Ochsendorf. All rights reserved.
//

#ifndef tmx_model_buffer_hpp
#define tmx_model_buffer_hpp

#include <stdio.h>
#include  <vector>
#include "glfw_include.h"
#include "tmx_obj_loader.hpp"

class tmx_model_buffer{

    
public:
    glm::mat4 local_model_matrix;
    glm::mat4 translate_matrix;
    glm::mat4 scale_matrix;
    glm::mat4 roation_matrix;
    
    glm::vec3 current_position;
    glm::vec3 current_roation;
    glm::vec3 current_scale;
    
    GLint shader_program_id;
    
    
    GLint vertexbuffer_attr_pointer;
    GLuint vertexbuffer;
    GLint vertex_size;
    GLint vertex_count;
    std::vector<glm::vec3> vertex_buffer_data;

    GLint uvbuffer_attr_pointer;
    GLuint uvBuffer;
    GLint uv_size;
    GLint uv_count;
    std::vector<glm::vec2> uv_buffer_data;
    
    GLint normalbuffer_attr_pointer;
    GLuint normalBuffer;
    GLint normal_size;
    GLint normal_count;
    std::vector<glm::vec3> normal_buffer_data;

    
    tmx_model_buffer(GLint _shader_id);
    ~tmx_model_buffer();
    
    void rotate_around(float _angle, glm::vec3 _dir);
    void set_position(glm::vec3 _new_pos);
    void set_scale(glm::vec3 _new_scale);
    void calc_local_matrix();
    glm::mat4 get_local_matrix();

    
    glm::vec3 get_roation();
    glm::vec3 get_scale();
    glm::vec3 get_position();
    
    void set_shader_id(GLint _shaderid);
    
    bool render_object;
    void render_vertex_buffer();
    
    void fill_buffers(std::vector<glm::vec3> _vertices, std::vector<glm::vec2> _uvs, std::vector<glm::vec3>);
    void gen_buffers();
    
    
    void load_obj(const char* _path);
};


#endif /* tmx_model_buffer_hpp */


//count shader stride final buffer register buffer reload buffer 