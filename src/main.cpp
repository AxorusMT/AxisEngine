#include <iostream>
#include <string>

#include <SDL2/SDL.h>
#include <SDL2/SDL_syswm.h>

#include <bgfx/bgfx.h>
#include <bgfx/platform.h>

SDL_Window* window = nullptr;

int main(int argc, const char* argv[])
{
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        std::cout << "Error cannot init sdl2: " << SDL_GetError() << std::endl;
        return -1;
    }

    window = SDL_CreateWindow("axis", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1280, 720, SDL_WINDOW_SHOWN);
    if (window == nullptr) {
        std::cout << "Error cannot create window: " << SDL_GetError() << std::endl;
        return -1;
    }

    SDL_SysWMinfo wmi;

    SDL_VERSION(&wmi.version);
    if (!SDL_GetWindowWMInfo(window, &wmi)) {
        return -1;
    }

    // if doesnt work, change wl -> x11
    bgfx::PlatformData pd;
    pd.ndt = wmi.info.x11.display;
    pd.nwh = (void*)(uintptr_t)wmi.info.x11.display;

    bgfx::setPlatformData(pd);

    bgfx::renderFrame();
    bgfx::Init();

    bgfx::reset(1280, 720, BGFX_RESET_VSYNC);
    bgfx::setDebug(BGFX_DEBUG_TEXT);

    bgfx::setViewRect(0, 0, 0, uint16_t(1280), u_int16_t(720));
    bgfx::setViewClear(BGFX_CLEAR_COLOR | BGFX_CLEAR_DEPTH, 0x443355FF, 1.0f, 0);

    bgfx::touch(0);


    bool run = true;

    SDL_Event event;

    while (run) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                run = false;
            }

            if (event.type == SDL_KEYDOWN) {
                if (event.key.keysym.sym == SDLK_ESCAPE) {
                    run = false;
                }
                if (event.key.keysym.sym == SDLK_0) {
                    std::cout << "0 key pressed (this is just a test :D" << std::endl;
                }
            }

            bgfx::frame();
        }
    }

    SDL_DestroyWindow(window);
    bgfx::shutdown();
    SDL_Quit();
    return 0;
}
