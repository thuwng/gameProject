#ifndef _COHOI__H
#define _COHOI__H

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include <SDL_ttf.h>
#include "graphics.h"
#include "defs.h"
#include "logic.h"

using namespace std;

const char* ch[] = {"images/cohoi/ch1.png", "images/cohoi/ch2.png", "images/cohoi/ch3.png", "images/cohoi/ch4.png", "images/cohoi/ch5.png",
"images/cohoi/ch6.png", "images/cohoi/ch7.png", "images/cohoi/ch8.png", "images/cohoi/ch9.png", "images/cohoi/ch10.png"};

struct Loai9{
    Graphics graphics;
    Loai9 (Graphics _graphics) {
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

    void hienthe(int stt, bool &cont) {
        if (stt == 0) {
            SDL_Texture* visit = graphics.loadTexture(cell[Nobita.p]);
            graphics.prepareScene(visit);

            SDL_Texture* b = graphics.loadTexture("images/xemthe.png");
            graphics.renderTexture_new_size(b, 200, 600, O_W, O_H);
            graphics.presentScene();

            SDL_Event dc;
            int x, y;
            bool quit = false;
            while (true) {
                SDL_GetMouseState(&x, &y);
                SDL_PollEvent(&dc);
                switch (dc.type) {
                    case SDL_QUIT:
                        exit(0);
                        break;
                    case SDL_MOUSEBUTTONDOWN:
                        if (200 <= x && x <= 200 + O_W && 600 <= y && y <= 600 + O_H) {
                            quit = true;
                        }
                }
                if (quit) break;
            }

            int r = rand() % 10; r = 1;
            SDL_Texture* o_ch = graphics.loadTexture(ch[r]);
            graphics.renderTexture_new_size(o_ch, T_X, T_Y, T_W, T_H);

            graphics.presentScene();
            SDL_Delay(2000);

            if (r == 0) {
                Nobita.money -= 150;
                Shizuka.money += 50;
                Suneo.money += 50;
                Chaien.money += 50;
            }
            else if (r == 4) {
                Nobita.money += 200;
            }
            else if (r == 5) {
                Nobita.free_next_turn = true;
            }
            else if (r == 6) {
                Nobita.money += 400;
            }
            else if (r == 7) {
                Nobita.money += 200;
            }
            else if (r == 8) {
                Nobita.money += 50;
            }
            else if (r == 9) {
                Nobita.p = 1;
                Nobita.money += 200;
            }

            SDL_Texture* B = graphics.loadTexture("images/tieptheo.png");
            graphics.renderTexture_new_size(B, O_X, O_Y, O_W, O_H);

            graphics.presentScene();

            SDL_Event d;
            int x1, y1;
            bool quit1 = false;
            while (true) {
                SDL_GetMouseState(&x1, &y1);
                SDL_PollEvent(&d);
                switch (d.type) {
                    case SDL_QUIT:
                        exit(0);
                        break;
                    case SDL_MOUSEBUTTONDOWN:
                        if (O_X <= x1 && x1 <= O_X + O_W && O_Y <= y1 && y1 <= O_Y + O_H) {
                            quit1 = true;
                        }
                }
                if (quit1) break;
            }

            if (r == 1) {
                if (!Nobita.free_next_turn) {
                    SDL_Texture* vao_tu = graphics.loadTexture("images/vaotu.png");
                    graphics.prepareScene(vao_tu);

                    graphics.presentScene();
                    Nobita.free = false;
                    Nobita.p = 10;

                    SDL_DestroyTexture(vao_tu);
                    vao_tu = NULL;
                }
                else {
                    SDL_Texture* mien_tu = graphics.loadTexture("images/mientu.png");
                    graphics.prepareScene(mien_tu);

                    graphics.presentScene();
                    Nobita.free_next_turn = false;

                    SDL_DestroyTexture(mien_tu);
                    mien_tu = NULL;
                }
            }
            else if (r == 2) {
                Nobita.p -= 3;
                cont = true;
            }
            else if (r == 3) {
                SDL_Texture* boctham = graphics.loadTexture("images/boctham.png");
                graphics.prepareScene(boctham);
                SDL_Texture* tham = graphics.loadTexture("images/tham.png");
                graphics.renderTexture_new_size(tham, TH_X, TH_Y, TH_W, TH_H);

                graphics.presentScene();

                SDL_DestroyTexture(boctham);
                boctham = NULL;
            }

            SDL_DestroyTexture(visit);
            visit = NULL;
            SDL_DestroyTexture(b);
            b = NULL;
            SDL_DestroyTexture(o_ch);
            o_ch = NULL;
            SDL_DestroyTexture(B);
            B = NULL;
        }
    }
};

#endif // _COHOI__H
