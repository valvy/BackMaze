//
//  Tile.hpp
//  BackMaze
//
//  Created by Heiko van der Heijden on 22-02-15.
//  Copyright (c) 2015 Heiko van der Heijden. All rights reserved.
//

#ifndef BackMaze_Tile_hpp
#define BackMaze_Tile_hpp
#include <memory>
#include "Globals.hpp"
#ifdef __APPLE__
#include <OpenGL/gl.h>
#else
#ifdef _WIN32
#include <gl/gl.h>
#include <gl/glu.h>
#include <windows.h>
#endif
#ifdef __linux__
#include <GL/gl.h>
#include <GL/glu.h>
#endif
#endif

enum class TileType{
    Goal,
    Monster,
    Empty,
    wall,
    FootPrint,
};

class Tile{
public:
    Tile(GLfloat x,GLfloat y,GLfloat z,unsigned short aPosX,unsigned short aPosY);
    ~Tile();
    void Update();
    void getPosition(unsigned short& x, unsigned short& y);
    bool Hit(GLfloat x, GLfloat y, bool kick);
    void SetType(TileType nType);
    TileType GetType();
private:
    unsigned short arrayPosX, arrayPosY;
    TileType type;
    void DrawTile();
    GLfloat posX, posY,posZ;
    GLfloat colX,colY,colZ;
    
};

typedef std::shared_ptr<Tile> STile;

#endif
