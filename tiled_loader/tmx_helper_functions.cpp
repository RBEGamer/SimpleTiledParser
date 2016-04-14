//
//  tmx_helper_functions.cpp
//  tiled_loader
//
//  Created by Marcel Ochsendorf on 03.04.16.
//  Copyright © 2016 Marcel Ochsendorf. All rights reserved.
//

#include "tmx_helper_functions.hpp"




void replaceAll(std::string& str, const std::string& from, const std::string& to) {
    if(from.empty())
        return;
    size_t start_pos = 0;
    while((start_pos = str.find(from, start_pos)) != std::string::npos) {
        str.replace(start_pos, from.length(), to);
        start_pos += to.length();
    }
}




bool replace(std::string& str, const std::string& from, const std::string& to) {
    size_t start_pos = str.find(from);
    if(start_pos == std::string::npos)
        return false;
    str.replace(start_pos, from.length(), to);
    return true;
}

long getFileSize(FILE *inFile){
    long fileSize = 0;
    fseek(inFile,0,SEEK_END);
    fileSize=ftell(inFile);
    fseek(inFile,0,SEEK_SET);
    return fileSize;
}


char *loadTextFromFile(const char *file, const char* _mode)
{
    FILE *currentFile = fopen(file, _mode);
    if(currentFile == NULL){return  NULL;}
    fseek(currentFile, 0, SEEK_END);
    int count = (int)ftell(currentFile);
    
    rewind(currentFile);
    char *data = (char *)malloc(sizeof(char)*(count +1));
    count = (int)fread(data, sizeof(char), count, currentFile);
    data[count] = '\0';
    
    fclose(currentFile);
    
    return data;
}
