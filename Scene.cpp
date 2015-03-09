//
//  Scene.cpp
//  BackMaze
//
//  Created by Heiko van der Heijden on 24-02-15.
//  Copyright (c) 2015 Heiko van der Heijden. All rights reserved.
//

#include "Scene.hpp"

Scene::Scene(){
    cells = MazeLoader::LoadFile();
    invert = false;
    startMonster = false;
    unsigned short xRow = 0;
    //creates all the tiles
    for (GLfloat i = -0.84f; i < 0.9; i += 0.13f) {
        unsigned short yRow = 0;
        std::vector<STile> tmp;
        for(GLfloat j = -0.84f; j < 0.9; j += 0.13f){
            tmp.push_back(STile( new Tile(i,j,0,xRow,yRow)));
            yRow++;
        }
        xRow++;
        cells.push_back(tmp);
    }
    
    //place the goal and the monster randomly in the field
    //srand((unsigned int)time(nullptr));
    int randX = rand() % (cells.size() - 1);
    int randY = rand() % (cells[0].size() - 1);
    cells[randX][randY]->SetType(TileType::Monster);
    monster = SMonster(new MeanMonster(cells[randX][randY]));
    randX = rand() % (cells.size() - 1);
    randY = rand() % (cells[0].size() - 1);
    cells[randX][randY]->SetType(TileType::Goal);
    
}

void Scene::OnMouseDown(float x, float y){
    float tmpX = ((x / 2) * 0.007f)-1;
    float tmpY = ((y / 2) * 0.007f)-1;
    for (unsigned short i = 0; i < cells.size(); i++) {
        for (unsigned short j = 0; j < cells[i].size(); j++) {
            cells[i][j]->Hit(tmpX, tmpY, invert);
        }
    }
}

void Scene::OnPressedKey(unsigned short keycode){
    std::cout<< keycode <<std::endl;
    switch (keycode) {
        case SPACE_BAR:
            invert = (!invert)? true : false;
        case ENTER_KEY:
            startMonster = (!startMonster)? true : false;
        case S_KEY:
            MazeLoader::SaveFile(this->cells);
        default:
            break;
            
    }
}

void Scene::Update(){
    for (unsigned short i = 0; i < cells.size(); i++) {
        for (unsigned short j = 0; j < cells[i].size(); j++) {
            cells[i][j]->Update();
        }
    }
    
    if(startMonster){
        //update the monster
        if(monster != nullptr){
            unsigned short x = 0, y = 0;
            monster->GetCurrentTile(x, y);
            STile l = (x > 0)? cells[x - 1][y] : nullptr;
            STile f = (y < cells.size() -1)? cells[x][y + 1] : nullptr;
            STile r = (x < cells[x].size() - 1)? cells[x + 1][y] : nullptr;
            STile d = (y > 0)? cells[x][y -1] : nullptr;
            monster->Update(l, f, r,d);
        }
    }
}

Scene::~Scene(){
    
}
