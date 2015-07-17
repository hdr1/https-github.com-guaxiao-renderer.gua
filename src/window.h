#ifndef __Gua__window__
#define __Gua__window__


#include <cstdio>
#include <cstring>

#include "canvas.h"
#include "color.h"
#include "vector.h"


static const int kWindowWidth = 640;
static const int kWindowHeight = 480;


class Window {
    SDL_Surface *_screen;
    Canvas *_canvas;

    int _width;
    int _height;

    bool _running;
    
public:
    
    Window(int width=kWindowWidth, int height=kWindowHeight, const char *title="Screen") {
        // init
        if(SDL_Init(SDL_INIT_VIDEO) != 0) {
            fprintf(stderr, "SDL_Init failed\n");
        }
        
        SDL_Surface *screen = SDL_SetVideoMode(width, height, 32, SDL_SWSURFACE);
        if(screen == NULL) {
            SDL_Quit();
            fprintf(stderr, "SDL_SetVideoMode failed\n");
        }
        _screen = screen;
        
        SDL_WM_SetCaption(title, NULL);
        
        _width = width;
        _height = height;
        
        _canvas = new Canvas((uint32_t *)screen->pixels, width, height);
        
        _running = true;
    };
    
    ~Window() {
        delete _canvas;
    };
    
    void run() {
        while(_running) {
            SDL_LockSurface(_screen);

            updateInput();
            
            // 1, update
            update();
            
            // 2, clear
            clear();
            
            // 3, draw
            draw();
            
            // 4, present
            show();
        }
    };
    
    void update() {

    };
    
    void draw() {
        Vector v = Vector();
        for (int i = 0; i < 255; ++i) {
            v.x = i;
            v.y = i;
            _canvas->drawPoint(v, Color(i/255.0f, 0, 0, 1));
        }
    };
    
    void show() {
        SDL_UnlockSurface(_screen);
        SDL_UpdateRect(_screen, 0, 0, 0, 0);
    };

    void clear() {
        _canvas->clear();
    };
    
    void onKeyEvent(const SDL_Event *event) {
        SDLKey key = (*event).key.keysym.sym;
        if (key == SDLK_ESCAPE) {
            quit();
        }
    };
    
    void HandleEvent(const SDL_Event *event) {
        unsigned char eventType = event->type;
        
        if (eventType == SDL_QUIT) {
            quit();
        } else if(eventType == SDL_KEYDOWN) {
            onKeyEvent(event);
        }
    };
    
    void updateInput() {
        SDL_Event event;
        while(SDL_PollEvent(&event)) {
            HandleEvent(&event);
        }
    };
    
    void quit() {
        _running = false;
    };
};

#endif
