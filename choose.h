#ifndef _CHOOSE__H
#define _CHOOSE__H

#include <SDL.h>
#include <SDL_image.h>
#include "graphics.h"
#include "defs.h"

struct decide{
    //Nạp màn hình lựa chọn
    SDL_Texture* screen;
    void init(Graphics graphics, const char* image_path) {
        screen = graphics.loadTexture(image_path);
        graphics.prepareScene(screen);
    }

    //Thêm thẻ nhân vật
    SDL_Texture* c1;
    void loadNobita(Graphics graphics) {
        if (nvat[0].is_real_player) {
            c1 = graphics.loadTexture("images/characters/Nobita_chose.png");
            graphics.renderTexture_new_size(c1, CHOOSE_CHARACTER_X, CHOOSE_CHARACTER_Y, CHOOSE_CHARACTER_W, CHOOSE_CHARACTER_H);
        }
        else {
            c1 = graphics.loadTexture("images/characters/Nobita.png");
            graphics.renderTexture_new_size(c1, CHOOSE_CHARACTER_X, CHOOSE_CHARACTER_Y, CHOOSE_CHARACTER_W, CHOOSE_CHARACTER_H);
        }
    }

    SDL_Texture* c2;
    void loadShizuka(Graphics graphics) {
        if (nvat[1].is_real_player) {
            c2 = graphics.loadTexture("images/characters/Shizuka_chose.png");
            graphics.renderTexture_new_size(c2, CHOOSE_CHARACTER_X + CHOOSE_CHARACTER_D, CHOOSE_CHARACTER_Y, CHOOSE_CHARACTER_W, CHOOSE_CHARACTER_H);
        }
        else {
            c2 = graphics.loadTexture("images/characters/Shizuka.png");
            graphics.renderTexture_new_size(c2, CHOOSE_CHARACTER_X + CHOOSE_CHARACTER_D, CHOOSE_CHARACTER_Y, CHOOSE_CHARACTER_W, CHOOSE_CHARACTER_H);
        }
    }

    SDL_Texture* c3;
    void loadSuneo(Graphics graphics) {
        if (nvat[2].is_real_player) {
            c3 = graphics.loadTexture("images/characters/Suneo_chose.png");
            graphics.renderTexture_new_size(c3, CHOOSE_CHARACTER_X + 2 * CHOOSE_CHARACTER_D, CHOOSE_CHARACTER_Y, CHOOSE_CHARACTER_W, CHOOSE_CHARACTER_H);
        }
        else {
            c3 = graphics.loadTexture("images/characters/Suneo.png");
            graphics.renderTexture_new_size(c3, CHOOSE_CHARACTER_X + 2 * CHOOSE_CHARACTER_D, CHOOSE_CHARACTER_Y, CHOOSE_CHARACTER_W, CHOOSE_CHARACTER_H);
        }
    }

    SDL_Texture* c4;
    void loadChaien(Graphics graphics) {
        if (nvat[3].is_real_player) {
            c4 = graphics.loadTexture("images/characters/Chaien_chose.png");
            graphics.renderTexture_new_size(c4, CHOOSE_CHARACTER_X + 3 * CHOOSE_CHARACTER_D, CHOOSE_CHARACTER_Y, CHOOSE_CHARACTER_W, CHOOSE_CHARACTER_H);
        }
        else {
            c4 = graphics.loadTexture("images/characters/Chaien.png");
            graphics.renderTexture_new_size(c4, CHOOSE_CHARACTER_X + 3 * CHOOSE_CHARACTER_D, CHOOSE_CHARACTER_Y, CHOOSE_CHARACTER_W, CHOOSE_CHARACTER_H);
        }
    }

    void present(Graphics graphics) {
        //Hiện màn hình
        graphics.presentScene();
    }

    //Chọn nhân vật
    void choose_time(decide character, Graphics graphics, const char* name) {
        screen = graphics.loadTexture(name);
        character.loadNobita(graphics);
        character.loadShizuka(graphics);
        character.loadSuneo(graphics);
        character.loadChaien(graphics);
        SDL_Event dc;
        while (true) {
            int x, y;
            bool quit = false;
            SDL_GetMouseState(&x, &y);
            SDL_PollEvent(&dc);
            switch (dc.type) {
                case SDL_QUIT:
                    exit(0);
                    break;
                case SDL_MOUSEBUTTONDOWN:
                    if (CHOOSE_CHARACTER_X <= x && x <= CHOOSE_CHARACTER_X + CHOOSE_CHARACTER_W && CHOOSE_CHARACTER_Y <= y && y <= CHOOSE_CHARACTER_Y + CHOOSE_CHARACTER_H) {
                        nvat[0].is_real_player = true;
                        quit = true;
                    }
                    else if (CHOOSE_CHARACTER_X + CHOOSE_CHARACTER_D <= x && x <= CHOOSE_CHARACTER_X + CHOOSE_CHARACTER_W + CHOOSE_CHARACTER_D && CHOOSE_CHARACTER_Y <= y && y <= CHOOSE_CHARACTER_Y + CHOOSE_CHARACTER_H) {
                        nvat[1].is_real_player = true;
                        quit = true;
                    }
                    else if (CHOOSE_CHARACTER_X + 2 * CHOOSE_CHARACTER_D <= x && x <= CHOOSE_CHARACTER_X + CHOOSE_CHARACTER_W + 2 * CHOOSE_CHARACTER_D && CHOOSE_CHARACTER_Y <= y && y <= CHOOSE_CHARACTER_Y + CHOOSE_CHARACTER_H) {
                        nvat[2].is_real_player = true;
                        quit = true;
                    }
                    else if (CHOOSE_CHARACTER_X + 3 * CHOOSE_CHARACTER_D <= x && x <= CHOOSE_CHARACTER_X + CHOOSE_CHARACTER_W + 3 * CHOOSE_CHARACTER_D && CHOOSE_CHARACTER_Y <= y && y <= CHOOSE_CHARACTER_Y + CHOOSE_CHARACTER_H) {
                        nvat[3].is_real_player = true;
                        quit = true;
                    }
            }
            if (quit) break;
        }
    }

    //Xóa
    void destroy() {
        SDL_Delay(500);

        SDL_DestroyTexture(screen);
        screen = NULL;
        SDL_DestroyTexture(c1);
        c1 = NULL;
        SDL_DestroyTexture(c2);
        c2 = NULL;
        SDL_DestroyTexture(c3);
        c3 = NULL;
        SDL_DestroyTexture(c4);
        c4 = NULL;
    }
};

#endif // _CHOOSE__H
