#ifndef _LOGIC__H
#define _LOGIC__H

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include <SDL_ttf.h>
#include "graphics.h"
#include "defs.h"

using namespace std;

struct Monopoly {
    Graphics graphics;
    Monopoly (Graphics _graphics) {
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

    void gieoxingau(int stt) {
        SDL_Texture* blank = graphics.loadTexture(Turn[stt]);
        graphics.prepareScene(blank);
        graphics.presentScene();

        int a, b;
        SDL_Event get_dice;
        SDL_Texture* button = graphics.loadTexture("images/button.png");
        while (true) {
            int x, y;
            bool quit = false;
            SDL_GetMouseState(&x, &y);

            SDL_Rect dices;
            dices.x = 920;
            dices.y = 580;
            dices.w = 200;
            dices.h = 210;

            if (x >= dices.x && x <= dices.x + dices.w && y >= dices.y && y <= dices.y + dices.h) {
                graphics.prepareScene(blank);
                graphics.renderTexture_new_size(button, 920, 580, 200, 210);
            }
            else {
                graphics.prepareScene(blank);
                graphics.renderTexture_new_size(button, 930, 590, 180, 190);
            }
            graphics.presentScene();

            SDL_PollEvent(&get_dice);
            switch (get_dice.type) {
                case SDL_QUIT:
                    exit(0);
                    break;
                case SDL_MOUSEBUTTONDOWN:
                    if (x >= dices.x && x <= dices.x + dices.w && y >= dices.y && y <= dices.y + dices.h) {
                        a = rand() % 6;
                        b = rand() % 6;
                        quit = true;
                    }
            }
            if (quit) break;
        }

        SDL_Delay(200);

        SDL_Texture* dice1 = graphics.loadTexture(Dice[a]);
        graphics.renderTexture_new_size(dice1, 650, 200, 200, 200);
        SDL_Texture* dice2 = graphics.loadTexture(Dice[b]);
        graphics.renderTexture_new_size(dice2, 880, 200, 200, 200);

        graphics.presentScene();
        SDL_Delay(500);

        //Thay đổi vị trí
        if (stt == 0) Nobita.p += (a + b + 2) % 36;
        else if (stt == 1) Shizuka.p += (a + b + 2) % 36;
        else if (stt == 2) Suneo.p += (a + b + 2) % 36;
        else Chaien.p += (a + b + 2) % 36;

        //Xóa
        SDL_DestroyTexture(button);
        button = NULL;
        SDL_DestroyTexture(dice2);
        dice2 = NULL;
        SDL_DestroyTexture(dice1);
        dice1 = NULL;

        SDL_DestroyTexture(blank);
        blank = NULL;
    }

    void hienbanco() {
        SDL_Texture* board = graphics.loadTexture("images/board.png");

        //Nạp font
        TTF_Font* font = graphics.loadFont("fonts/TNR/times.ttf", 50);
        SDL_Color color = {0, 0, 0, 0};
        SDL_Texture* in4_Nobita = graphics.renderText2(to_string(Nobita.money), font, color);
        SDL_Texture* in4_Shizuka = graphics.renderText2(to_string(Shizuka.money), font, color);
        SDL_Texture* in4_Suneo = graphics.renderText2(to_string(Suneo.money), font, color);
        SDL_Texture* in4_Chaien = graphics.renderText2(to_string(Chaien.money), font, color);

        //Nạp nhân vật
        SDL_Texture* nobita = graphics.loadTexture("images/characters_removed_background/Nobita.png");
        SDL_Texture* shizuka = graphics.loadTexture("images/characters_removed_background/Shizuka.png");
        SDL_Texture* suneo = graphics.loadTexture("images/characters_removed_background/Suneo.png");
        SDL_Texture* chaien = graphics.loadTexture("images/characters_removed_background/Chaien.png");

        //Chuẩn bị bàn cờ
        graphics.prepareScene(board);

        graphics.renderTexture_new_size(nobita, N_X[Nobita.p], N_Y[Nobita.p], N_W, N_H);
        graphics.renderTexture_new_size(shizuka, S_X + N_X[Shizuka.p], S_Y + N_Y[Shizuka.p], S_W, S_H);
        graphics.renderTexture_new_size(suneo, X_X + N_X[Suneo.p], X_Y + N_Y[Suneo.p], X_W, X_H);
        graphics.renderTexture_new_size(chaien, C_X + N_X[Chaien.p], C_Y + N_Y[Chaien.p], C_W, C_H);

        graphics.renderTexture(in4_Nobita, M_X, M_Y);
        graphics.renderTexture(in4_Shizuka, M_X, M_Y + M_H);
        graphics.renderTexture(in4_Suneo, M_X + M_W, M_Y);
        graphics.renderTexture(in4_Chaien, M_X + M_W, M_Y + M_H);

        //Hiện lại bàn cờ
        graphics.presentScene();
        waitUntilKeyPressed();
    }
};

#endif // _LOGIC__H
