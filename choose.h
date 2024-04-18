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
    void loadNobita(Graphics graphics, bool ok) {
        if (!ok) {
            if (Nobita.is_real_player) {
                c1 = graphics.loadTexture("images/characters/Nobita_chose.png");
                graphics.renderTexture_new_size(c1, CHOOSE_CHARACTER_X, CHOOSE_CHARACTER_Y, CHOOSE_CHARACTER_W, CHOOSE_CHARACTER_H);
            }
            else {
                c1 = graphics.loadTexture("images/characters/Nobita.png");
                graphics.renderTexture_new_size(c1, CHOOSE_CHARACTER_X, CHOOSE_CHARACTER_Y, CHOOSE_CHARACTER_W, CHOOSE_CHARACTER_H);
            }
        }
        else {
            if (Nobita.is_real_player) {
                c1 = graphics.loadTexture("images/characters/Nobita_chose.png");
                graphics.renderTexture_new_size(c1, CHOOSE_CHARACTER_X - 5, CHOOSE_CHARACTER_Y - 5, CHOOSE_CHARACTER_W + 10, CHOOSE_CHARACTER_H + 10);
            }
            else {
                c1 = graphics.loadTexture("images/characters/Nobita.png");
                graphics.renderTexture_new_size(c1, CHOOSE_CHARACTER_X - 5, CHOOSE_CHARACTER_Y - 5, CHOOSE_CHARACTER_W + 10, CHOOSE_CHARACTER_H + 10);
            }
        }
    }

    SDL_Texture* c2;
    void loadShizuka(Graphics graphics, bool ok) {
        if (!ok) {
            if (Shizuka.is_real_player) {
                c2 = graphics.loadTexture("images/characters/Shizuka_chose.png");
                graphics.renderTexture_new_size(c2, CHOOSE_CHARACTER_X + CHOOSE_CHARACTER_D, CHOOSE_CHARACTER_Y, CHOOSE_CHARACTER_W, CHOOSE_CHARACTER_H);
            }
            else {
                c2 = graphics.loadTexture("images/characters/Shizuka.png");
                graphics.renderTexture_new_size(c2, CHOOSE_CHARACTER_X + CHOOSE_CHARACTER_D, CHOOSE_CHARACTER_Y, CHOOSE_CHARACTER_W, CHOOSE_CHARACTER_H);
            }
        }
        else {
            if (Shizuka.is_real_player) {
                c2 = graphics.loadTexture("images/characters/Shizuka_chose.png");
                graphics.renderTexture_new_size(c2, CHOOSE_CHARACTER_X + CHOOSE_CHARACTER_D - 5, CHOOSE_CHARACTER_Y - 5, CHOOSE_CHARACTER_W + 10, CHOOSE_CHARACTER_H + 10);
            }
            else {
                c2 = graphics.loadTexture("images/characters/Shizuka.png");
                graphics.renderTexture_new_size(c2, CHOOSE_CHARACTER_X + CHOOSE_CHARACTER_D - 5, CHOOSE_CHARACTER_Y - 5, CHOOSE_CHARACTER_W + 10, CHOOSE_CHARACTER_H + 10);
            }
        }
    }

    SDL_Texture* c3;
    void loadSuneo(Graphics graphics, bool ok) {
        if (!ok) {
            if (Suneo.is_real_player) {
                c3 = graphics.loadTexture("images/characters/Suneo_chose.png");
                graphics.renderTexture_new_size(c3, CHOOSE_CHARACTER_X + 2 * CHOOSE_CHARACTER_D, CHOOSE_CHARACTER_Y, CHOOSE_CHARACTER_W, CHOOSE_CHARACTER_H);
            }
            else {
                c3 = graphics.loadTexture("images/characters/Suneo.png");
                graphics.renderTexture_new_size(c3, CHOOSE_CHARACTER_X + 2 * CHOOSE_CHARACTER_D, CHOOSE_CHARACTER_Y, CHOOSE_CHARACTER_W, CHOOSE_CHARACTER_H);
            }
        }
        else {
            if (Suneo.is_real_player) {
                c3 = graphics.loadTexture("images/characters/Suneo_chose.png");
                graphics.renderTexture_new_size(c3, CHOOSE_CHARACTER_X + 2 * CHOOSE_CHARACTER_D - 5, CHOOSE_CHARACTER_Y - 5, CHOOSE_CHARACTER_W + 10, CHOOSE_CHARACTER_H + 10);
            }
            else {
                c3 = graphics.loadTexture("images/characters/Suneo.png");
                graphics.renderTexture_new_size(c3, CHOOSE_CHARACTER_X + 2 * CHOOSE_CHARACTER_D - 5, CHOOSE_CHARACTER_Y - 5, CHOOSE_CHARACTER_W + 10, CHOOSE_CHARACTER_H + 10);
            }
        }
    }

    SDL_Texture* c4;
    void loadChaien(Graphics graphics, bool ok) {
        if (!ok) {
            if (Chaien.is_real_player) {
                c4 = graphics.loadTexture("images/characters/Chaien_chose.png");
                graphics.renderTexture_new_size(c4, CHOOSE_CHARACTER_X + 3 * CHOOSE_CHARACTER_D, CHOOSE_CHARACTER_Y, CHOOSE_CHARACTER_W, CHOOSE_CHARACTER_H);
            }
            else {
                c4 = graphics.loadTexture("images/characters/Chaien.png");
                graphics.renderTexture_new_size(c4, CHOOSE_CHARACTER_X + 3 * CHOOSE_CHARACTER_D, CHOOSE_CHARACTER_Y, CHOOSE_CHARACTER_W, CHOOSE_CHARACTER_H);
            }
        }
        else {
            if (Chaien.is_real_player) {
                c4 = graphics.loadTexture("images/characters/Chaien_chose.png");
                graphics.renderTexture_new_size(c4, CHOOSE_CHARACTER_X + 3 * CHOOSE_CHARACTER_D - 5, CHOOSE_CHARACTER_Y - 5, CHOOSE_CHARACTER_W + 10, CHOOSE_CHARACTER_H + 10);
            }
            else {
                c4 = graphics.loadTexture("images/characters/Chaien.png");
                graphics.renderTexture_new_size(c4, CHOOSE_CHARACTER_X + 3 * CHOOSE_CHARACTER_D - 5, CHOOSE_CHARACTER_Y - 5, CHOOSE_CHARACTER_W + 10, CHOOSE_CHARACTER_H + 10);
            }
        }
    }

    void present(Graphics graphics) {
        //Hiện màn hình
        graphics.presentScene();
    }

    //Chọn nhân vật
    void choose_time(decide character, Graphics graphics, const char* name) {
        screen = graphics.loadTexture(name);
        SDL_Event choose_character;
        bool done = false;
        while (true) {
            int x, y;
            SDL_GetMouseState(&x, &y);
            SDL_Rect ch;
            ch.x = CHOOSE_CHARACTER_X;
            ch.y = CHOOSE_CHARACTER_Y;
            ch.w = CHOOSE_CHARACTER_W;
            ch.h = CHOOSE_CHARACTER_H;
            int d = CHOOSE_CHARACTER_D;

            if (x >= ch.x && x <= ch.x + ch.w && y >= ch.y && y <= ch.y + ch.h && !Nobita.is_real_player) {
                graphics.prepareScene(screen);
                character.loadNobita(graphics, 1);
                character.loadShizuka(graphics, 0);
                character.loadSuneo(graphics, 0);
                character.loadChaien(graphics, 0);
            }
            else if (x >= ch.x + d && x <= ch.x + ch.w + d && y >= ch.y && y <= ch.y + ch.h && !Shizuka.is_real_player) {
                graphics.prepareScene(screen);
                character.loadNobita(graphics, 0);
                character.loadShizuka(graphics, 1);
                character.loadSuneo(graphics, 0);
                character.loadChaien(graphics, 0);
            }
            else if (x >= ch.x + 2 * d && x <= ch.x + ch.w + 2 * d && y >= ch.y && y <= ch.y + ch.h && !Suneo.is_real_player) {
                graphics.prepareScene(screen);
                character.loadNobita(graphics, 0);
                character.loadShizuka(graphics, 0);
                character.loadSuneo(graphics, 1);
                character.loadChaien(graphics, 0);
            }
            else if (x >= ch.x + 3 * d && x <= ch.x + ch.w + 3 * d && y >= ch.y && y <= ch.y + ch.h && !Chaien.is_real_player) {
                graphics.prepareScene(screen);
                character.loadNobita(graphics, 0);
                character.loadShizuka(graphics, 0);
                character.loadSuneo(graphics, 0);
                character.loadChaien(graphics, 1);
            }
            else {
                graphics.prepareScene(screen);
                character.loadNobita(graphics, 0);
                character.loadShizuka(graphics, 0);
                character.loadSuneo(graphics, 0);
                character.loadChaien(graphics, 0);
            }
            graphics.presentScene();

            ch.x -= 5;
            ch.y -= 5;
            ch.w += 10;
            ch.h += 10;
            SDL_PollEvent(&choose_character);
            switch (choose_character.type) {
                case SDL_QUIT:
                    exit(0);
                    break;
                case SDL_MOUSEBUTTONDOWN:
                    if (x >= ch.x && x <= ch.x + ch.w && y >= ch.y && y <= ch.y + ch.h && !Nobita.is_real_player)
                        done = true, Nobita.is_real_player = true;
                    else if (x >= ch.x + d && x <= ch.x + ch.w + d && y >= ch.y && y <= ch.y + ch.h && !Shizuka.is_real_player)
                        done = true, Shizuka.is_real_player = true;
                    else if (x >= ch.x + 2 * d && x <= ch.x + ch.w + 2 * d && y >= ch.y && y <= ch.y + ch.h && !Suneo.is_real_player)
                        done = true, Suneo.is_real_player = true;
                    else if (x >= ch.x + 3 * d && x <= ch.x + ch.w + 3 * d && y >= ch.y && y <= ch.y + ch.h && !Chaien.is_real_player)
                        done = true, Chaien.is_real_player = true;
            }
            if (done) break;
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
