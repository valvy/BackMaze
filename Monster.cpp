//
//  Monster.cpp
//  BackMaze
//
//  Created by Heiko van der Heijden on 24-02-15.
//  Copyright (c) 2015 Heiko van der Heijden. All rights reserved.
//

#include "Monster.hpp"
#include <iostream>

MeanMonster::MeanMonster(STile startingTile){
    currentTile = startingTile;
  
}

void MeanMonster::Update(STile l, STile f, STile r,STile d){


    if(f != nullptr && f->GetType() != TileType::FootPrint){
        JumpTile(f);
    }
    else if(r != nullptr && r->GetType() != TileType::FootPrint){
        JumpTile(r);
    }
    else if(d != nullptr && d->GetType() != TileType::FootPrint){
        JumpTile(d);
    }
    else if(l != nullptr && l->GetType() != TileType::FootPrint){
        JumpTile(l);
    }
    else
        std::cout<< "can't go further \n";
    
}


void MeanMonster::GetCurrentTile(unsigned short& x, unsigned short& y){
    currentTile->getPosition(x, y);
}

void MeanMonster::JumpTile(STile nTile){
    if(nTile->GetType() == TileType::Goal){
        std::cout << "Victory \n";
    }
    else
        if(nTile != nullptr && nTile->GetType() != TileType::wall){
            currentTile->SetType(TileType::FootPrint);
        currentTile = nTile;
            currentTile->SetType(TileType::Monster);
    }
}

