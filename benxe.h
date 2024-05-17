#ifndef _BENXE__H
#define _BENXE__H

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include <SDL_ttf.h>
#include "graphics.h"
#include "defs.h"

using namespace std;

vector<int> benxe = {6, 14, 24, 32};

int bxe[4] = {-1, -1, -1, -1};

struct Loai3{
    Graphics graphics;
    Loai3 (Graphics _graphics) {
        graphics = _graphics;
    }

    void waitUntilKeyPressed() {
        SDL_Event e;
        while (true) {
            if (SDL_PollEvent(&e) != 0 && (e.type == SDL_KEYDOWN || e.type == SDL_QUIT))
                return;
            SDL_Delay(300);
        }
    }

    void hienthe(int stt, int loai, bool real) {
        if (bxe[loai] == -1 && real) {
            SDL_Texture* visit = graphics.loadTexture(cell[benxe[loai]]);
            graphics.prepareScene(visit);

            SDL_Texture* a = graphics.loadTexture("images/muadat.png");
            graphics.renderTexture_new_size(a, O_X, O_Y, O_W, O_H);
            SDL_Texture* b = graphics.loadTexture("images/tieptheo.png");
            graphics.renderTexture_new_size(b, O_X + O_D, O_Y, O_W, O_H);
            graphics.presentScene();

            SDL_Event dc;
            int x, y;
            bool quit = false, buy = false;
            while (true) {
                SDL_GetMouseState(&x, &y);
                SDL_PollEvent(&dc);
                switch (dc.type) {
                    case SDL_QUIT:
                        exit(0);
                        break;
                    case SDL_MOUSEBUTTONDOWN:
                        if (O_X <= x && x <= O_X + O_W && O_Y <= y && y <= O_Y + O_H) {
                            buy = true;
                            quit = true;
                        }
                        else if (O_X + O_D <= x && x <= O_X + O_D + O_W && O_Y <= y && y <= O_Y + O_H) {
                            quit = true;
                        }
                }
                if (quit) break;
            }

            if (buy) {
                bxe[loai] = stt;
                nvat[stt].money -= 200;
                nvat[stt].bxe++;
            }

            SDL_DestroyTexture(visit);
            visit = NULL;
            SDL_DestroyTexture(a);
            a = NULL;
            SDL_DestroyTexture(b);
            b = NULL;

            SDL_Delay(500);
        }
        else if (bxe[loai] != -1){
            int j = 1;
            for (int i = 1; i < nvat[bxe[loai]].bxe; i++) j *= 2;
            nvat[stt].money -= 25 * j;
            nvat[bxe[loai]].money += 25 * j;
        }
    }
};

#endif // _BENXE__H
