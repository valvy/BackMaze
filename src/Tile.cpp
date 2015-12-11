//
//  Tile.cpp
//  BackMaze
//
//  Created by Heiko van der Heijden on 22-02-15.
//  Copyright (c) 2015 Heiko van der Heijden. All rights reserved.
//

#include "Tile.hpp"
#include "Globals.hpp"

Tile::Tile(GLfloat x, GLfloat y, GLfloat z, unsigned short aX, unsigned short aY){
    type = TileType::Empty;
    posX = x;
    posY = y;
    posZ = z;
    arrayPosX = aX;
    arrayPosY = aY;
    
    colX = 1.0f;
    colY = 1.0f;
    colZ = 1.0f;
    
}


void Tile::DrawTile(){
    glBegin(GL_QUADS);
    {
        glVertex3f(-TILE_SIZE, TILE_SIZE, 0.0f);
        glVertex3f( TILE_SIZE, TILE_SIZE, 0.0f);
        glVertex3f( TILE_SIZE,-TILE_SIZE, 0.0f);
        glVertex3f(-TILE_SIZE,-TILE_SIZE, 0.0f);
    }
    glEnd();
}

void Tile::getPosition(unsigned short& X, unsigned short& Y){
    X = arrayPosX;
    Y = arrayPosY;
}

TileType Tile::GetType(){
    return type;
}

bool Tile::Hit(GLfloat X, GLfloat Y, bool kick){
    if(type == TileType::Empty || type == TileType::wall){
        if(X > (posX - (TILE_SIZE)) && X < (posX + (TILE_SIZE * 1.5f))){
            if(Y > (posY - TILE_SIZE) && Y < (posY + TILE_SIZE * 1.5f)){
                if(!kick){
                    this->SetType(TileType::wall);
                }else{
                    this->SetType(TileType::Empty);
                }
                return true;
            }
        }
    }
    return false;
}

void Tile::SetType(TileType nType){
    switch (nType){
        case TileType::Monster:
            colX = 0;
            colY = 1;
            colZ = 1;
            break;
        case TileType::Goal:
            colX = 1;
            colY =1;
            colZ = 0;
            break;
        case TileType::Empty:
            colX = 1.0f;
            colY = 1.0f;
            colZ = 1.0f;
            break;
        case TileType::FootPrint:
            colX = 1;
            colY = 0;
            colZ = 0;
            break;
        case TileType::wall:
            colX = 1.0f;
            colY = 0.85f;
            colZ = 0.35f;
            break;
        default:
            break;
    }
    
    type = nType;
}

void Tile::Update(){
    
    glColor3f(colX, colY, colZ);
    glPushMatrix();
    glRotatef(0, 0, 0, 0);
    glTranslated(posX, posY, posZ);
    this->DrawTile();
    glPopMatrix();
}

Tile::~Tile(){
    
}
