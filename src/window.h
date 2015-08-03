#ifndef __Gua__window__
#define __Gua__window__


#include <cstdio>
#include <cstring>
#include <vector>

#include "canvas.h"
#include "color.h"
#include "vector.h"
#include "vertex.h"
#include "mesh.h"
#include "guamath.h"


using std::vector;

static const int kWindowWidth = 800;
static const int kWindowHeight = 600;

class Window {
    SDL_Surface *_screen;
    Canvas *_canvas;
    Mesh *_mesh;

    int _width;
    int _height;

    bool _running;
    
    bool pressedW = false;
    bool pressedS = false;
    bool pressedA = false;
    bool pressedD = false;
    bool pressedUp = false;
    bool pressedDown = false;
    bool pressedLeft = false;
    bool pressedRight = false;
    
public:
    Window(int argc, char *argv[], int width=kWindowWidth, int height=kWindowHeight, const char *title="Screen") {
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
        
        const char *modelPath = "illidan.gua3d";
        const char *texturePath = "illidan.guaimage";
        if(argc > 2) {
            modelPath = argv[1];
            texturePath = argv[2];
        }
        _mesh = new Mesh(modelPath, texturePath);
    };
    
    virtual ~Window() {
        delete _canvas;
        delete _mesh;
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
        static const float transform = 0.05;
        
        _mesh->rotation.x += pressedUp ? transform : 0;
        _mesh->rotation.x -= pressedDown ? transform : 0;
        _mesh->rotation.y += pressedLeft ? transform : 0;
        _mesh->rotation.y -= pressedRight ? transform : 0;
        
        _mesh->position.y += pressedW ? transform : 0;
        _mesh->position.y -= pressedS ? transform : 0;
        _mesh->position.x -= pressedA ? transform : 0;
        _mesh->position.x += pressedD ? transform : 0;
    };
    
    void draw() {
        _canvas->drawMesh(*_mesh);
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
        bool keyIsDown = (event->type == SDL_KEYDOWN);
        if (key == SDLK_ESCAPE) {
            quit();
        } else if (key == SDLK_UP) {
            pressedUp = keyIsDown;
        } else if (key == SDLK_DOWN) {
            pressedDown = keyIsDown;
        } else if (key == SDLK_LEFT) {
            pressedLeft = keyIsDown;
        } else if (key == SDLK_RIGHT) {
            pressedRight = keyIsDown;
        } else if(key == SDLK_w) {
            pressedW = keyIsDown;
        } else if(key == SDLK_s) {
            pressedS = keyIsDown;
        } else if (key == SDLK_a){
            pressedA = keyIsDown;
        } else if (key == SDLK_d) {
            pressedD = keyIsDown;
        }
    };
    
    void onMouseEvent(const SDL_Event *event) {
    };

    void HandleEvent(const SDL_Event *event) {
        unsigned char eventType = event->type;
        
        if (eventType == SDL_QUIT) {
            quit();
        } else if(eventType == SDL_KEYDOWN || eventType == SDL_KEYUP) {
            onKeyEvent(event);
        } else if (eventType == SDL_MOUSEBUTTONDOWN) {
            onMouseEvent(event);
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
