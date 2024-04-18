#include <bits/stdc++.h>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include <SDL_ttf.h>
#include "graphics.h"
#include "defs.h"
#include "logic.h"
#include "choose.h"

using namespace std;

void waitUntilKeyPressed() {
    SDL_Event e;
    while (true) {
        if ( SDL_PollEvent(&e) != 0 &&
             (e.type == SDL_KEYDOWN || e.type == SDL_QUIT) )
            return;
        SDL_Delay(300);
    }
}

int main(int argc, char* argv[]) {
    //Mở màn
    Graphics graphics;
    graphics.initSDL(SCREEN_W, SCREEN_H);

    //Nạp ảnh mở màn
    SDL_Texture* start_screen = graphics.loadTexture("images/batdau.png");
    graphics.prepareScene(start_screen);

    //Nút play
    SDL_Texture* start_button = graphics.loadTexture("images/start.png");
    graphics.renderTexture_new_size(start_button, START_BUTTON_X, START_BUTTON_Y, START_BUTTON_W, START_BUTTON_H);

    //Hiện màn hình
    graphics.presentScene();

    //Ấn nút
    SDL_Event event;
    while (true) {
        int x, y;
        bool quit = 0;
        SDL_GetMouseState(&x, &y);
        SDL_Rect play;
        play.x = START_BUTTON_X;
        play.y = START_BUTTON_Y;
        play.w = START_BUTTON_W;
        play.h = START_BUTTON_H;

        if (x >= play.x && x <= play.x + play.w && y >= play.y && y <= play.y + play.h) {
            graphics.renderTexture_new_size(start_button, START_BUTTON_X - 10, START_BUTTON_Y - 10, START_BUTTON_W + 20, START_BUTTON_H + 20);
        }
        else {
            graphics.renderTexture_new_size(start_button, START_BUTTON_X, START_BUTTON_Y, START_BUTTON_W, START_BUTTON_H);
        }
        graphics.presentScene();

        SDL_PollEvent(&event);
        switch (event.type) {
            case SDL_QUIT:
                 exit(0);
                 break;
            case SDL_MOUSEBUTTONDOWN:
                if (x >= play.x - 10 && x <= play.x + play.w + 10 && y >= play.y - 10 && y <= play.y + play.h + 10) {
                    quit = 1;
                }
        }
        if (quit) break;
    }

    //Xóa
    SDL_DestroyTexture(start_screen);
    start_screen = NULL;
    SDL_DestroyTexture(start_button);
    start_button = NULL;

    //Nạp màn hình giới thiệu
    SDL_Texture* intro_screen = graphics.loadTexture("images/introduce.png");
    graphics.prepareScene(intro_screen);

    //Hiện màn hình
    graphics.presentScene();
    waitUntilKeyPressed();

    //Xóa
    SDL_DestroyTexture(intro_screen);
    intro_screen = NULL;

    //Nạp màn hình luật chơi
    SDL_Texture* rule_screen = graphics.loadTexture("images/rule.png");
    graphics.prepareScene(rule_screen);

    //Hiện màn hình
    graphics.presentScene();
    waitUntilKeyPressed();

    //Xóa
    SDL_DestroyTexture(rule_screen);
    rule_screen = NULL;

    //Nạp màn hình cách chơi
    SDL_Texture* way_screen = graphics.loadTexture("images/howtoplay.png");
    graphics.prepareScene(way_screen);

    //Hiện màn hình
    graphics.presentScene();
    waitUntilKeyPressed();

    //Xóa
    SDL_DestroyTexture(way_screen);
    way_screen = NULL;

    //Nạp màn hình chọn số lượng người chơi
    SDL_Texture* num_screen = graphics.loadTexture("images/number_of_players.png");
    graphics.prepareScene(num_screen);

    //Chọn 1 người
    SDL_Texture* oneplayer_button = graphics.loadTexture("images/1_player.png");
    graphics.renderTexture_new_size(oneplayer_button, NUM_BUTTON_X, NUM_BUTTON_Y, NUM_BUTTON_W, NUM_BUTTON_H);

    //Chọn 2 người
    SDL_Texture* twoplayers_button = graphics.loadTexture("images/2_players.png");
    graphics.renderTexture_new_size(twoplayers_button, NUM_BUTTON_X, NUM_BUTTON_Y + NUM_BUTTON_D, NUM_BUTTON_W, NUM_BUTTON_H);

    //Chọn 3 người
    SDL_Texture* threeplayers_button = graphics.loadTexture("images/3_players.png");
    graphics.renderTexture_new_size(threeplayers_button, NUM_BUTTON_X, NUM_BUTTON_Y + 2 * NUM_BUTTON_D, NUM_BUTTON_W, NUM_BUTTON_H);

    //Chọn 4 người
    SDL_Texture* fourplayers_button = graphics.loadTexture("images/4_players.png");
    graphics.renderTexture_new_size(fourplayers_button, NUM_BUTTON_X, NUM_BUTTON_Y + 3 * NUM_BUTTON_D, NUM_BUTTON_W, NUM_BUTTON_H);

    //Hiện màn hình
    graphics.presentScene();

    //Chọn số lượng
    SDL_Event choose_num;
    int num_of_players = 0;
    while (true) {
        int x, y;
        SDL_GetMouseState(&x, &y);
        SDL_Rect choose;
        choose.x = NUM_BUTTON_X;
        choose.y = NUM_BUTTON_Y;
        choose.w = NUM_BUTTON_W;
        choose.h = NUM_BUTTON_H;
        int d = NUM_BUTTON_D;

        if (x >= choose.x && x <= choose.x + choose.w && y >= choose.y && y <= choose.y + choose.h) {
            graphics.prepareScene(num_screen);
            graphics.renderTexture_new_size(oneplayer_button, choose.x - 10, choose.y - 10, choose.w + 20, choose.h + 20);
            graphics.renderTexture_new_size(twoplayers_button, choose.x, choose.y + d, choose.w, choose.h);
            graphics.renderTexture_new_size(threeplayers_button, choose.x, choose.y + 2 * d, choose.w, choose.h);
            graphics.renderTexture_new_size(fourplayers_button, choose.x, choose.y + 3 * d, choose.w, choose.h);
        }
        else if (x >= choose.x && x <= choose.x + choose.w && y >= choose.y + d && y <= choose.y + choose.h + d) {
            graphics.prepareScene(num_screen);
            graphics.renderTexture_new_size(oneplayer_button, choose.x, choose.y, choose.w, choose.h);
            graphics.renderTexture_new_size(twoplayers_button, choose.x - 10, choose.y + d - 10, choose.w + 20, choose.h + 20);
            graphics.renderTexture_new_size(threeplayers_button, choose.x, choose.y + 2 * d, choose.w, choose.h);
            graphics.renderTexture_new_size(fourplayers_button, choose.x, choose.y + 3 * d, choose.w, choose.h);
        }
        else if (x >= choose.x && x <= choose.x + choose.w && y >= choose.y + 2 * d && y <= choose.y + choose.h + 2 * d) {
            graphics.prepareScene(num_screen);
            graphics.renderTexture_new_size(oneplayer_button, choose.x, choose.y, choose.w, choose.h);
            graphics.renderTexture_new_size(twoplayers_button, choose.x, choose.y + d, choose.w, choose.h);
            graphics.renderTexture_new_size(threeplayers_button, choose.x - 10, choose.y + 2 * d - 10, choose.w + 20, choose.h + 20);
            graphics.renderTexture_new_size(fourplayers_button, choose.x, choose.y + 3 * d, choose.w, choose.h);
        }
        else if (x >= choose.x && x <= choose.x + choose.w && y >= choose.y + 3 * d && y <= choose.y + choose.h + 3 * d) {
            graphics.prepareScene(num_screen);
            graphics.renderTexture_new_size(oneplayer_button, choose.x, choose.y, choose.w, choose.h);
            graphics.renderTexture_new_size(twoplayers_button, choose.x, choose.y + d, choose.w, choose.h);
            graphics.renderTexture_new_size(threeplayers_button, choose.x, choose.y + 2 * d, choose.w, choose.h);
            graphics.renderTexture_new_size(fourplayers_button, choose.x - 10, choose.y + 3 * d - 10, choose.w + 20, choose.h + 20);
        }
        else {
            graphics.prepareScene(num_screen);
            graphics.renderTexture_new_size(oneplayer_button, choose.x, choose.y, choose.w, choose.h);
            graphics.renderTexture_new_size(twoplayers_button, choose.x, choose.y + d, choose.w, choose.h);
            graphics.renderTexture_new_size(threeplayers_button, choose.x, choose.y + 2 * d, choose.w, choose.h);
            graphics.renderTexture_new_size(fourplayers_button, choose.x, choose.y + 3 * d, choose.w, choose.h);
        }
        graphics.presentScene();

        SDL_PollEvent(&choose_num);
        switch (choose_num.type) {
            case SDL_QUIT:
                 exit(0);
                 break;
            case SDL_MOUSEBUTTONDOWN:
                if (x >= choose.x - 10 && x <= choose.x + choose.w + 10 && y >= choose.y - 10 && y <= choose.y + choose.h + 10)
                    num_of_players = 1;
                else if (x >= choose.x - 10 && x <= choose.x + choose.w + 10 && y >= choose.y + d - 10 && y <= choose.y + choose.h + d + 10)
                    num_of_players = 2;
                else if (x >= choose.x - 10 && x <= choose.x + choose.w + 10 && y >= choose.y + 2 * d - 10 && y <= choose.y + choose.h + 2 * d + 10)
                    num_of_players = 3;
                else if (x >= choose.x - 10 && x <= choose.x + choose.w + 10 && y >= choose.y + 3 * d - 10 && y <= choose.y + choose.h + 3 * d + 10)
                    num_of_players = 4;
        }
        if (num_of_players) break;
    }

    //Hiện màn hình
    graphics.presentScene();
    SDL_Delay(300);

    //Xóa
    SDL_DestroyTexture(num_screen);
    num_screen = NULL;
    SDL_DestroyTexture(oneplayer_button);
    oneplayer_button = NULL;
    SDL_DestroyTexture(twoplayers_button);
    twoplayers_button = NULL;
    SDL_DestroyTexture(threeplayers_button);
    threeplayers_button = NULL;
    SDL_DestroyTexture(fourplayers_button);
    fourplayers_button = NULL;

    //Chọn nhân vật
    int chose = 0;
    while (chose < num_of_players) {
        chose++;

        decide character;
        character.init(graphics, Choose[chose - 1]);

        character.loadNobita(graphics, 0);
        character.loadShizuka(graphics, 0);
        character.loadSuneo(graphics, 0);
        character.loadChaien(graphics, 0);

        character.present(graphics);
        character.choose_time(character, graphics, Choose[chose - 1]);

        character.destroy();
    }

    //Chào mừng đến với ván cờ tỷ phú mà THUWNG tạo ra
    decide welcome;
    welcome.init(graphics, "images/welcome.png");

    welcome.loadNobita(graphics, 0);
    welcome.loadShizuka(graphics, 0);
    welcome.loadSuneo(graphics, 0);
    welcome.loadChaien(graphics, 0);

    welcome.present(graphics);
    welcome.destroy();

    SDL_Delay(1000);

    //Nạp ảnh bàn cờ
    SDL_Texture* board = graphics.loadTexture("images/board.png");
    graphics.prepareScene(board);

    //Nạp nhân vật
    SDL_Texture* nobita = graphics.loadTexture("images/characters_removed_background/Nobita.png");
    graphics.renderTexture_new_size(nobita, Nobita.x, Nobita.y, Nobita.w, Nobita.h);
    SDL_Texture* shizuka = graphics.loadTexture("images/characters_removed_background/Shizuka.png");
    graphics.renderTexture_new_size(shizuka, Shizuka.x, Shizuka.y, Shizuka.w, Shizuka.h);
    SDL_Texture* suneo = graphics.loadTexture("images/characters_removed_background/Suneo.png");
    graphics.renderTexture_new_size(suneo, Suneo.x, Suneo.y, Suneo.w, Suneo.h);
    SDL_Texture* chaien = graphics.loadTexture("images/characters_removed_background/Chaien.png");
    graphics.renderTexture_new_size(chaien, Chaien.x, Chaien.y, Chaien.w, Chaien.h);

    //Hiện bàn cờ
    graphics.presentScene();
    SDL_Delay(1000);

    //Vòng lặp
    int stt = 0;

    while ((Nobita.turn < 30 || Shizuka.turn < 30 || Suneo.turn < 30 || Chaien.turn < 30) && !(Nobita.bankrupt && Shizuka.bankrupt && Suneo.bankrupt && Chaien.bankrupt)) {
        stt = (stt + 1) % 5;

        if (stt = 1) {
            Nobita.turn++;

            SDL_Texture* blank = graphics.loadTexture("images/blue1.png");
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

            SDL_Delay(2000);

            SDL_Texture* dice1 = graphics.loadTexture(Dice[a]);
            graphics.renderTexture_new_size(dice1, 650, 200, 200, 200);
            SDL_Texture* dice2 = graphics.loadTexture(Dice[b]);
            graphics.renderTexture_new_size(dice2, 880, 200, 200, 200);

            graphics.presentScene();
            SDL_Delay(2000);


            SDL_DestroyTexture(button);
            button = NULL;
            SDL_DestroyTexture(dice2);
            dice2 = NULL;
            SDL_DestroyTexture(dice1);
            dice1 = NULL;

            SDL_DestroyTexture(blank);
            blank = NULL;

            //Hiện lại bàn cờ
            graphics.prepareScene(board);
            graphics.renderTexture_new_size(nobita, Nobita.x, Nobita.y, Nobita.w, Nobita.h);
            graphics.renderTexture_new_size(shizuka, Shizuka.x, Shizuka.y, Shizuka.w, Shizuka.h);
            graphics.renderTexture_new_size(suneo, Suneo.x, Suneo.y, Suneo.w, Suneo.h);
            graphics.renderTexture_new_size(chaien, Chaien.x, Chaien.y, Chaien.w, Chaien.h);

            graphics.presentScene();
            waitUntilKeyPressed();

            //Nhân vật di chuyên
        }
        break;
    }

    //Xóa
    SDL_DestroyTexture(nobita);
    nobita = NULL;
    SDL_DestroyTexture(shizuka);
    shizuka = NULL;
    SDL_DestroyTexture(suneo);
    suneo = NULL;
    SDL_DestroyTexture(chaien);
    chaien = NULL;
    SDL_DestroyTexture(board);
    board = NULL;

    //Kết thúc ván cờ
    graphics.quit();

    return 0;
}
