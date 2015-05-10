//
//  MacApp.h
//  BackMaze
//
//  Created by Heiko van der Heijden on 10-05-15.
//  Copyright (c) 2015 Heiko van der Heijden. All rights reserved.
//
#ifndef BackMaze_MacApp_h
#define BackMaze_MacApp_h
#ifdef __APPLE__
#include "TargetConditionals.h"
#if TARGET_OS_MAC

#import "Application.hpp"
#import <Cocoa/Cocoa.h>

@interface MacApp : NSWindow  <NSApplicationDelegate>{}
@property (nonatomic) NSOpenGLView* scene;
-(void) UpdateScene;


@end

#endif
#endif
#endif