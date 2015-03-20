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
    isAtGoal = false;
  
}

bool MeanMonster::CanJump(STile t){
    return(t != nullptr && t->GetType() != TileType::wall);
}


STile MeanMonster::PreferedTile(STile l,STile f, STile r, STile d){
    //Is there an empty tile?
    
    if(l != nullptr && (l->GetType() == TileType::Empty || l->GetType() == TileType::Goal)){
        prefTiles.push_back(l);
        return l;
    }
    else if(f != nullptr && (f->GetType() == TileType::Empty || f->GetType() == TileType::Goal)){
        prefTiles.push_back(f);
        return f;
    }
    else if(r != nullptr && (r->GetType() == TileType::Empty || r->GetType() == TileType::Goal)){
        prefTiles.push_back(r);
        return r;
    }
    else if(d != nullptr && (d->GetType() == TileType::Empty || d->GetType() == TileType::Goal)){
        prefTiles.push_back(d);

        return d;
    }
    else{
        if(prefTiles.empty()){
            throw "Can't find anything";
        }else{
         //alright go back;
            STile last = prefTiles.back();
            prefTiles.pop_back();
            return last;
        }
        
    }
    return l;

}

void MeanMonster::Update(STile l, STile f, STile r,STile d){
    try{
        if(!isAtGoal){
            JumpTile(PreferedTile(l,f,r,d));
        }
    }catch(const char* e){
        std::cout<< e;
        isAtGoal = true;
    }
}


void MeanMonster::GetCurrentTile(unsigned short& x, unsigned short& y){
    currentTile->getPosition(x, y);
}

void MeanMonster::JumpTile(STile nTile){
    if(nTile->GetType() == TileType::Goal){
        std::cout << "Victory \n";
        isAtGoal = true;
    }
    else
        if(nTile != nullptr && nTile->GetType() != TileType::wall){
            currentTile->SetType(TileType::FootPrint);
        currentTile = nTile;
            currentTile->SetType(TileType::Monster);
    }
}

