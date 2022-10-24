#include <iostream>
#include <string>

#include <SDL2/SDL.h>
#include <glad/glad.h>

int main(int argc, const char* argv[]) {
    SDL_Window* window = nullptr;

    std::string window_title;

    #ifdef AXIS_DEBUG
    window_title = "AxisEngine [DEBUG]";
    #elif AXIS_RELEASE
    window_title = "AxisEngine [RELEASE]";
    #endif 

    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        std::cout << "SDL cant init: " << SDL_GetError() << std::endl;
        return -1;
    }

    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 3);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);

    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
    SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);

    window = SDL_CreateWindow(
        window_title.c_str(),
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        1280, 
        720,
        SDL_WINDOW_SHOWN | SDL_WINDOW_OPENGL
    );

    SDL_GLContext ctx;
    ctx = SDL_GL_CreateContext(window);

    gladLoadGLLoader(SDL_GL_GetProcAddress);

    // OpenGL stuff

    bool run = true;


    while (run) {
        glViewport(0, 0, 1280, 720);
        SDL_Event ev;

        while (SDL_PollEvent(&ev)) {
            if (ev.type == SDL_QUIT) {
                run = false;
            }
            if (ev.type == SDL_KEYDOWN) {
                if (ev.key.keysym.sym == SDLK_ESCAPE) {
                    run = false;
                }
            }
        }

        glClearColor(0.2f, 0.3f, 0.4f, 1.0f);
        glClear(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);

        SDL_GL_SwapWindow(window);
    }

    SDL_DestroyWindow(window);
    SDL_Delay(3000);
    SDL_Quit();
    return 0;
}