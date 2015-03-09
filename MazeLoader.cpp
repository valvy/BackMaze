//
//  MazeLoader.cpp
//  BackMaze
//
//  Created by Heiko van der Heijden on 04-03-15.
//  Copyright (c) 2015 Heiko van der Heijden. All rights reserved.
//

#include "MazeLoader.hpp"

std::vector<std::string> MazeLoader::LoadFile(){
    std::vector <std::string> buffer;
    std::ifstream str (MazeLoader::GetDirectoryPath() + '/' + fileName);
    
    if(str.good()){
        std::string line;
        
        while(!str.eof()){
            getline(str, line);
            buffer.push_back(line);
        }
    }
    else{
        std::cout<<"error : file does not exist \n ";
    }
    str.close();
    
    return buffer;
}

#define GetCurrentDir getcwd

std::string MazeLoader::GetDirectoryPath(){
    char cCurrentPath[FILENAME_MAX];
    
    if(!GetCurrentDir(cCurrentPath, sizeof(cCurrentPath)))
    {
        return "Error";
    }
    
    cCurrentPath[sizeof(cCurrentPath) - 1] = '\0';
    
    return cCurrentPath;
}

bool MazeLoader::SaveFile(std::vector<std::vector<STile>> dat){
    std::fstream str;
    str.open(MazeLoader::GetDirectoryPath() + '/' + fileName);
    for (unsigned short i = 0; i < dat.size(); i++) {
        std::string line = "";
        for (unsigned short j = 0; j < dat[i].size(); j++) {
            if(dat[i][j]->GetType() == TileType::wall){
                line += 'w';
            }
            else if(dat[i][j]->GetType() == TileType::Monster){
                line += 'M';
            }
            else if(dat[i][j]->GetType() == TileType::Goal){
                line += 'g';
            }
            else{
                line += 'e';
            }
        }
        str << line << std::endl;
    }
    
    str.close();
    
    
    return false;
}