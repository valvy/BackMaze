

#ifdef __linux__
#include "Application.hpp"
#include <unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include<X11/X.h>
#include<X11/Xlib.h>
#include<GL/gl.h>
#include<GL/glx.h>
#include<GL/glu.h>

Display                 *dpy;
Window                  root;
GLint                   att[] = { GLX_RGBA, GLX_DEPTH_SIZE, 24, GLX_DOUBLEBUFFER, None };
XVisualInfo             *vi;
Colormap                cmap;
XSetWindowAttributes    swa;
Window                  win;
GLXContext              glc;
XWindowAttributes       gwa;
XEvent                  xev;


Application::Application(){
	 dpy = XOpenDisplay(NULL);
	  if(dpy == nullptr) {
        printf("\n\tcannot connect to X server\n\n");
        exit(0);
	  }
	  root = DefaultRootWindow(dpy);
	  
	  vi = glXChooseVisual(dpy, 0, att);

	if(vi == NULL) {
        printf("\n\tno appropriate visual found\n\n");
        exit(0);
	} 
	else {
        printf("\n\tvisual %p selected\n", (void *)vi->visualid); /* %p creates hexadecimal output like in glxinfo */
	}
	cmap = XCreateColormap(dpy, root, vi->visual, AllocNone);
	swa.colormap = cmap;
	swa.event_mask = ExposureMask | KeyPressMask;
	win = XCreateWindow(dpy, root, 0, 0,WINDOW_HEIGHT, WINDOW_WIDTH, 0, vi->depth, InputOutput, vi->visual, CWColormap | CWEventMask, &swa);
	XMapWindow(dpy, win);
	XStoreName(dpy, win, "BackMaze");
	glc = glXCreateContext(dpy, vi, NULL, GL_TRUE);
	glXMakeCurrent(dpy, win, glc);
	glEnable(GL_DEPTH_TEST); 
}

#define GetCurrentDir getcwd
std::string Application::AppPath(){
    char cCurrentPath[FILENAME_MAX];
    
    if(!GetCurrentDir(cCurrentPath, sizeof(cCurrentPath)))
    {
        return "Error";
    }
    
    cCurrentPath[sizeof(cCurrentPath) - 1] = '\0';
    
    return cCurrentPath;
    
}

void Application::Update(){

}

void Application::OnMouseDown(float x, float y){

}

void Application::OnKeyDown(unsigned short keycode){

}

void Application::ExitApp(){

}

void Application::StartApp(){
	 while(true) {
        XNextEvent(dpy, &xev);
       //if(xev.type == Expose) {
                XGetWindowAttributes(dpy, win, &gwa);
               // glViewport(0, 0, gwa.width, gwa.height);
				glClearColor(0, 0, 0, 0);
				glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
				this->Update();
				glFlush();
                glXSwapBuffers(dpy, win);
        //}
       
        if(xev.type == KeyPress) {
			char buf[128] = {0};
			KeySym keysym;
			int len = XLookupString(&xev.xkey, buf, sizeof buf, &keysym, NULL);
			//std::cout << (unsigned short)keysym<< std::endl;
			this->OnKeyDown((unsigned short)keysym);

        }
    } /* this closes while(1) { */
} /* this is the } which closes int main(int argc, char *argv[]) { */


Application::~Application(){
	glXMakeCurrent(dpy, None, NULL);
    glXDestroyContext(dpy, glc);
    XDestroyWindow(dpy, win);
    XCloseDisplay(dpy);
    exit(0);
}
#endif

