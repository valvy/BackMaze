//
//  BackMaze.cpp
//  BackMaze
//
//  Created by Heiko van der Heijden on 22-02-15.
//  Copyright (c) 2015 Heiko van der Heijden. All rights reserved.
//

#include "BackMaze.hpp"


BackMaze::BackMaze() : Application(){
    scene = SScene(new Scene());
    
    StartApp();
}

void BackMaze::Update(){
    scene->Update();
}

void BackMaze::OnMouseDown(float x, float y){
    scene->OnMouseDown(x, y);
}

void BackMaze::OnKeyDown(unsigned short keycode){
    if(keycode == ESCAPE_KEY){
        this->scene.release();
        this->scene = SScene(new Scene());
    }
    else{
        scene->OnPressedKey(keycode);
    }
    
}




BackMaze::~BackMaze(){
    
}
