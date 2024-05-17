#ifndef _CONGTY__H
#define _CONGTY__H

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include <SDL_ttf.h>
#include "graphics.h"
#include "defs.h"

using namespace std;

vector<int> congty = {12, 26};

int cty[2] = {-1, -1};

struct Loai4{
    Graphics graphics;
    Loai4 (Graphics _graphics) {
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

    void hienthe(int stt, int loai, int diem, bool real) {
        if (cty[loai] == -1 && real) {
            SDL_Texture* visit = graphics.loadTexture(cell[congty[loai]]);
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
                cty[loai] = stt;
                nvat[stt].money -= 150;
                nvat[stt].cty++;
            }

            SDL_DestroyTexture(visit);
            visit = NULL;
            SDL_DestroyTexture(a);
            a = NULL;
            SDL_DestroyTexture(b);
            b = NULL;

            SDL_Delay(500);
        }
        else {
            if (nvat[cty[loai]].cty == 1) {
                nvat[stt].money -= 4 * diem;
                nvat[cty[loai]].money += 4 * diem;
            }
            else if (cty[loai] != -1){
                nvat[stt].money -= 10 * diem;
                nvat[cty[loai]].money += 10 * diem;
            }
        }
    }
};

#endif // _CONGTY__H
