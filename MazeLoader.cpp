//
//  MazeLoader.cpp
//  BackMaze
//
//  Created by Heiko van der Heijden on 04-03-15.
//  Copyright (c) 2015 Heiko van der Heijden. All rights reserved.
//

#include "MazeLoader.hpp"

std::vector<std::vector<STile>> MazeLoader::LoadFile(){
    
    std::vector<std::vector<STile>> tmp;
    
    std::ifstream str (fileName);
    
    if(str.good()){
        std::string line;
        
        while(!str.eof()){
            getline(str, line);
            for(unsigned short i = 0; i < line.length(); ++i){
                
            }
        }
    }
    else{
        std::cout<<"error : file does not exist \n ";
    }
    str.close();
    
    return tmp;
}

bool MazeLoader::SaveFile(std::vector<std::vector<STile>> dat){
    std::cout<<"saving  to "<< fileName << std::endl;
   // remove(fileName);
    std::fstream str;
    str.open(fileName);
    for (unsigned short i = 0; i < dat.size(); i++) {
        std::string line = "";
        for (unsigned short j = 0; j < dat[i].size(); j++) {
            if(dat[i][j]->GetType() == wall){
                line += 'w';
            }
            else{
                line += 'e';
            }
        }
        str << line << std::endl;
        std::cout<< line <<std::endl;
    }
    
    str.close();
    
    
    return false;
}