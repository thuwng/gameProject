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

    void hienthe(int stt, int loai, int diem) {
        if (stt == 0) {
            if (cty[loai] == -1) {
                SDL_Texture* visit = graphics.loadTexture(cell[congty[loai]]);
                graphics.prepareScene(visit);

                SDL_Texture* a = graphics.loadTexture("images/muadat.png");
                graphics.renderTexture_new_size(a, O_X, O_Y, O_W, O_H);
                SDL_Texture* b = graphics.loadTexture("images/boqua.png");
                graphics.renderTexture_new_size(b, O_X, O_Y + O_D, O_W, O_H);
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
                            else if (O_X <= x && x <= O_X + O_W && O_Y + O_D <= y && y <= O_Y + O_D + O_H) {
                                quit = true;
                            }
                    }
                    if (quit) break;
                }

                if (buy) {
                    cty[loai] = stt;
                    Nobita.money -= 150;
                    Nobita.cty++;
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
                if (cty[loai] == 1) {
                    if (Shizuka.cty == 1) {
                        Nobita.money -= 4 * diem;
                        Shizuka.money += 4 * diem;
                    }
                    else {
                        Nobita.money -= 10 * diem;
                        Shizuka.money += 10 * diem;
                    }
                }
                else if (cty[loai] == 2) {
                    if (Suneo.cty == 1) {
                        Nobita.money -= 4 * diem;
                        Suneo.money += 4 * diem;
                    }
                    else {
                        Nobita.money -= 10 * diem;
                        Suneo.money += 10 * diem;
                    }
                }
                else if (cty[loai] == 3) {
                    if (Chaien.cty == 1) {
                        Nobita.money -= 4 * diem;
                        Chaien.money += 4 * diem;
                    }
                    else {
                        Nobita.money -= 10 * diem;
                        Chaien.money += 10 * diem;
                    }
                }
            }
        }
        else if (stt == 1) {
            if (cty[loai] == -1) {
                SDL_Texture* visit = graphics.loadTexture(cell[congty[loai]]);
                graphics.prepareScene(visit);

                SDL_Texture* a = graphics.loadTexture("images/muadat.png");
                graphics.renderTexture_new_size(a, O_X, O_Y, O_W, O_H);
                SDL_Texture* b = graphics.loadTexture("images/boqua.png");
                graphics.renderTexture_new_size(b, O_X, O_Y + O_D, O_W, O_H);
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
                            else if (O_X <= x && x <= O_X + O_W && O_Y + O_D <= y && y <= O_Y + O_D + O_H) {
                                quit = true;
                            }
                    }
                    if (quit) break;
                }

                if (buy) {
                    cty[loai] = stt;
                    Shizuka.money -= 150;
                    Shizuka.cty++;
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
                if (cty[loai] == 0) {
                    if (Nobita.cty == 1) {
                        Shizuka.money -= 4 * diem;
                        Nobita.money += 4 * diem;
                    }
                    else {
                        Shizuka.money -= 10 * diem;
                        Nobita.money += 10 * diem;
                    }
                }
                else if (cty[loai] == 2) {
                    if (Suneo.cty == 1) {
                        Shizuka.money -= 4 * diem;
                        Suneo.money += 4 * diem;
                    }
                    else {
                        Shizuka.money -= 10 * diem;
                        Suneo.money += 10 * diem;
                    }
                }
                else if (cty[loai] == 3) {
                    if (Chaien.cty == 1) {
                        Shizuka.money -= 4 * diem;
                        Chaien.money += 4 * diem;
                    }
                    else {
                        Shizuka.money -= 10 * diem;
                        Chaien.money += 10 * diem;
                    }
                }
            }
        }
        else if (stt == 2) {
            if (cty[loai] == -1) {
                SDL_Texture* visit = graphics.loadTexture(cell[congty[loai]]);
                graphics.prepareScene(visit);

                SDL_Texture* a = graphics.loadTexture("images/muadat.png");
                graphics.renderTexture_new_size(a, O_X, O_Y, O_W, O_H);
                SDL_Texture* b = graphics.loadTexture("images/boqua.png");
                graphics.renderTexture_new_size(b, O_X, O_Y + O_D, O_W, O_H);
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
                            else if (O_X <= x && x <= O_X + O_W && O_Y + O_D <= y && y <= O_Y + O_D + O_H) {
                                quit = true;
                            }
                    }
                    if (quit) break;
                }

                if (buy) {
                    cty[loai] = stt;
                    Suneo.money -= 150;
                    Suneo.cty++;
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
                if (cty[loai] == 0) {
                    if (Nobita.cty == 1) {
                        Suneo.money -= 4 * diem;
                        Nobita.money += 4 * diem;
                    }
                    else {
                        Suneo.money -= 10 * diem;
                        Nobita.money += 10 * diem;
                    }
                }
                else if (cty[loai] == 1) {
                    if (Shizuka.cty == 1) {
                        Suneo.money -= 4 * diem;
                        Shizuka.money += 4 * diem;
                    }
                    else {
                        Suneo.money -= 10 * diem;
                        Shizuka.money += 10 * diem;
                    }
                }
                else if (cty[loai] == 3) {
                    if (Chaien.cty == 1) {
                        Suneo.money -= 4 * diem;
                        Chaien.money += 4 * diem;
                    }
                    else {
                        Suneo.money -= 10 * diem;
                        Chaien.money += 10 * diem;
                    }
                }
            }
        }
        else if (stt == 3) {
            if (cty[loai] == -1) {
                SDL_Texture* visit = graphics.loadTexture(cell[congty[loai]]);
                graphics.prepareScene(visit);

                SDL_Texture* a = graphics.loadTexture("images/muadat.png");
                graphics.renderTexture_new_size(a, O_X, O_Y, O_W, O_H);
                SDL_Texture* b = graphics.loadTexture("images/boqua.png");
                graphics.renderTexture_new_size(b, O_X, O_Y + O_D, O_W, O_H);
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
                            else if (O_X <= x && x <= O_X + O_W && O_Y + O_D <= y && y <= O_Y + O_D + O_H) {
                                quit = true;
                            }
                    }
                    if (quit) break;
                }

                if (buy) {
                    cty[loai] = stt;
                    Chaien.money -= 150;
                    Chaien.cty++;
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
                if (cty[loai] == 0) {
                    if (Nobita.cty == 1) {
                        Chaien.money -= 4 * diem;
                        Nobita.money += 4 * diem;
                    }
                    else {
                        Chaien.money -= 10 * diem;
                        Nobita.money += 10 * diem;
                    }
                }
                else if (cty[loai] == 1) {
                    if (Shizuka.cty == 1) {
                        Chaien.money -= 4 * diem;
                        Shizuka.money += 4 * diem;
                    }
                    else {
                        Chaien.money -= 10 * diem;
                        Shizuka.money += 10 * diem;
                    }
                }
                else if (cty[loai] == 2) {
                    if (Suneo.cty == 1) {
                        Chaien.money -= 4 * diem;
                        Suneo.money += 4 * diem;
                    }
                    else {
                        Chaien.money -= 10 * diem;
                        Suneo.money += 10 * diem;
                    }
                }
            }
        }
    }
};

#endif // _CONGTY__H
