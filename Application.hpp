//
//  Application.hpp
//  BackMaze
//
//  Created by Heiko van der Heijden on 22-02-15.
//  Copyright (c) 2015 Heiko van der Heijden. All rights reserved.
//

#ifndef BackMaze_Application_hpp
#define BackMaze_Application_hpp

#include <iostream>
#include <memory>
#include <vector>
#include "Globals.hpp"

#ifdef __APPLE__
#include <OpenGL/gl.h>
#else
#include <gl/gl.h>
#include <gl/glu.h>
#endif

class Application{
public:
    Application();
    ~Application();
    virtual void Update();
    virtual void OnMouseDown(float x, float y);
    virtual void OnKeyDown(unsigned short keycode);
protected:
    void ExitApp();
    void StartApp();
};

typedef std::unique_ptr<Application> App;

#endif
