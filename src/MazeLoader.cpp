//
//  MazeLoader.cpp
//  BackMaze
//
//  Created by Heiko van der Heijden on 04-03-15.
//  Copyright (c) 2015 Heiko van der Heijden. All rights reserved.
//

#include "MazeLoader.hpp"
#include <fstream>
#include <iostream>

#include "Application.hpp"



std::vector<std::string> MazeLoader::LoadFile(){
    std::vector <std::string> buffer;
    std::ifstream str (Application::AppPath() + '/' + fileName);
    if(str.good()){
        std::string line;
        
        while(!str.eof()){
            getline(str, line);
            buffer.push_back(line);
        }
    }
    else{
        std::cout<<"error : file could not find maze.dat \nclosing application\n";
        str.close();
        exit(EXIT_FAILURE);
    }
    str.close();
    
    return buffer;
}


bool MazeLoader::SaveFile(std::vector<std::vector<STile>> dat){
    std::fstream str;
    str.open(Application::AppPath() + '/' + fileName);
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