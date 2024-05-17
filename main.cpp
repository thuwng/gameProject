#include <bits/stdc++.h>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include <SDL_ttf.h>
#include "graphics.h"
#include "defs.h"
#include "logic.h"
#include "choose.h"
#include "dat.h"
#include "benxe.h"
#include "congty.h"
#include "khivan.h"
#include "cohoi.h"
#include "hangman.h"

using namespace std;

void waitUntilKeyPressed() {
    SDL_Event e;
    while (true) {
        if (SDL_PollEvent(&e) != 0 && (e.type == SDL_KEYDOWN || e.type == SDL_QUIT))
            return;
        SDL_Delay(300);
    }
}

int main(int argc, char* argv[]) {
    //Mở màn
    Graphics graphics;
    graphics.initSDL(SCREEN_W, SCREEN_H);

    //Thêm nhạc
    Mix_Music *gMusic = graphics.loadMusic("doraemon.mp3");
    graphics.play(gMusic);

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

        decide Character;
        Character.init(graphics, "images/choose.png");

        Character.loadNobita(graphics);
        Character.loadShizuka(graphics);
        Character.loadSuneo(graphics);
        Character.loadChaien(graphics);

        Character.present(graphics);
        Character.choose_time(Character, graphics, "images/choose.png");

        Character.destroy();
    }

    //Chào mừng đến với ván cờ tỷ phú mà THUWNG tạo ra
    decide welcome;
    welcome.init(graphics, "images/welcome.png");

    welcome.loadNobita(graphics);
    welcome.loadShizuka(graphics);
    welcome.loadSuneo(graphics);
    welcome.loadChaien(graphics);

    welcome.present(graphics);
    welcome.destroy();

    SDL_Delay(3000);

    //Ô khởi đầu
    SDL_Texture* Cell = graphics.loadTexture("images/cells/cell1.png");
    graphics.prepareScene(Cell);

    SDL_Texture* b = graphics.loadTexture("images/tieptheo.png");
    graphics.renderTexture_new_size(b, O_X, O_Y, O_W, O_H);
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
                    quit = true;
                }
        }
        if (quit) break;
    }

    SDL_DestroyTexture(Cell);
    Cell = NULL;
    SDL_DestroyTexture(b);
    b = NULL;

    //Nạp ảnh bàn cờ
    SDL_Texture* board = graphics.loadTexture("images/board.png");
    graphics.prepareScene(board);

    //Nạp font
    TTF_Font* font = graphics.loadFont("fonts/TNR/times.ttf", 50);
    SDL_Color color = {0, 0, 0, 0};
    SDL_Texture* in4_Nobita = graphics.renderText2(to_string(nvat[0].money), font, color);
    SDL_Texture* in4_Shizuka = graphics.renderText2(to_string(nvat[1].money), font, color);
    SDL_Texture* in4_Suneo = graphics.renderText2(to_string(nvat[2].money), font, color);
    SDL_Texture* in4_Chaien = graphics.renderText2(to_string(nvat[3].money), font, color);

    //Nạp in4 các nhân vật
    graphics.renderTexture(in4_Nobita, M_X, M_Y);
    graphics.renderTexture(in4_Shizuka, M_X, M_Y + M_H);
    graphics.renderTexture(in4_Suneo, M_X + M_W, M_Y);
    graphics.renderTexture(in4_Chaien, M_X + M_W, M_Y + M_H);

    //Nạp nhân vật
    for (int i = 0; i < 4; i++) nvat[i].p = 1;
    SDL_Texture* nobita = graphics.loadTexture("images/characters_removed_background/Nobita.png");
    graphics.renderTexture_new_size(nobita, N_X[nvat[0].p], N_Y[nvat[0].p], N_W, N_H);
    SDL_Texture* shizuka = graphics.loadTexture("images/characters_removed_background/Shizuka.png");
    graphics.renderTexture_new_size(shizuka, S_X + N_X[nvat[1].p], S_Y + N_Y[nvat[1].p], S_W, S_H);
    SDL_Texture* suneo = graphics.loadTexture("images/characters_removed_background/Suneo.png");
    graphics.renderTexture_new_size(suneo, X_X + N_X[nvat[2].p], X_Y + N_Y[nvat[2].p], X_W, X_H);
    SDL_Texture* chaien = graphics.loadTexture("images/characters_removed_background/Chaien.png");
    graphics.renderTexture_new_size(chaien, C_X + N_X[nvat[3].p], C_Y + N_Y[nvat[3].p], C_W, C_H);

    //Hiện bàn cờ
    graphics.presentScene();
    SDL_Delay(2000);

    //Khởi tạo các loại ô
    Loai1 loai1(graphics);
    loai1.khoitao();

    //Vào game
    int stt = -1, sl = 0;
    for (int i = 0; i < 4; i++)
        if (nvat[i].is_real_player) sl++;
    int sl1 = 4 - sl, tt = 1;
    Monopoly thu(graphics);
    //Monopoly_AI thuw(graphics);

    while (nvat[0].turn < 30 || nvat[1].turn < 30 || nvat[2].turn < 30 || nvat[3].turn < 30) {
        stt = (stt + 1) % 4;
        bool real = nvat[stt].is_real_player;
        if (nvat[stt].bankrupt) continue;

        if (nvat[stt].free) {
            bool cont = false;
            int mode, tu = 0;
            nvat[stt].turn++;
            thu.gieoxingau(stt, cont, mode, real);
            thu.hienbanco();
            thu.thuchien(stt, cont, mode, real);
            thu.hienbanco();

            while (cont && tu < 2 && nvat[stt].money >= 0) {
                if (mode == 0) {
                    tu++;
                    thu.gieoxingau(stt, cont, mode, real);
                    thu.hienbanco();
                    thu.thuchien(stt, cont, mode, real);
                    thu.hienbanco();
                }
                else {
                    thu.thuchien(stt, cont, mode, real);
                    thu.hienbanco();
                    cont = false;
                }
            }

            if (tu == 2 && cont && nvat[stt].money >= 0) {
                if (!nvat[stt].free_next_turn) {
                    SDL_Texture* vao_tu = graphics.loadTexture("images/vaotu.png");
                    graphics.prepareScene(vao_tu);

                    graphics.presentScene();
                    SDL_Delay(1000);

                    nvat[stt].free = false;
                    nvat[stt].p = 10;
                    thu.hienbanco();

                    SDL_DestroyTexture(vao_tu);
                    vao_tu = NULL;
                }
                else {
                    SDL_Texture* mien_tu = graphics.loadTexture("images/mientu.png");
                    graphics.prepareScene(mien_tu);

                    graphics.presentScene();
                    SDL_Delay(1000);

                    nvat[stt].free_next_turn = false;
                    thu.hienbanco();

                    SDL_DestroyTexture(mien_tu);
                    mien_tu = NULL;
                }
            }
        }
        else {
            if (real) {
                bool ratu = false;
                thu.cohoiratu(stt, ratu);
                nvat[stt].free = ratu;
            }
            else {
                nvat[stt].free = true;
            }
        }

        if(nvat[stt].money < 0) {
            if (nvat[stt].is_real_player) sl--;
            else sl1--;
            nvat[stt].bankrupt = true;
            SDL_Texture* ps = graphics.loadTexture("images/phasan.png");
            graphics.prepareScene(ps);

            graphics.presentScene();
            SDL_Delay(1000);

            SDL_DestroyTexture(ps);
            ps = NULL;
        }
        if (sl == 1 && sl1 == 0) break;
        if (sl == 0) {
            tt = 0;
            break;
        }
    }

    if (tt == 0) {
        SDL_Texture* ps = graphics.loadTexture("images/lose.png");
        graphics.prepareScene(ps);

        graphics.presentScene();
        SDL_Delay(2000);

        SDL_DestroyTexture(ps);
        ps = NULL;
    }

    else {
        int tp = -1, st = 0;
        for (int i = 0; i < 4; i++)
            if (nvat[i].is_real_player && !nvat[i].bankrupt && nvat[i].money >= st) {
                tp = i;
                st = nvat[i].money;
            }

        SDL_Texture* ps = graphics.loadTexture("images/chienthang.png");
        graphics.prepareScene(ps);
        SDL_Texture* c1;
        if (tp == 0) c1 = graphics.loadTexture("images/characters/Nobita.png");
        else if (tp == 1) c1 = graphics.loadTexture("images/characters/Shizuka.png");
        else if (tp == 2) c1 = graphics.loadTexture("images/characters/Suneo.png");
        else if (tp == 3) c1 = graphics.loadTexture("images/characters/Chaien.png");
        graphics.renderTexture_new_size(c1, 800, 600, 150, 200);

        graphics.presentScene();
        SDL_Delay(2000);

        SDL_DestroyTexture(ps);
        ps = NULL;
    }

    //Xóa
    SDL_DestroyTexture(in4_Nobita);
    in4_Nobita = NULL;
    SDL_DestroyTexture(in4_Shizuka);
    in4_Shizuka = NULL;
    SDL_DestroyTexture(in4_Suneo);
    in4_Suneo = NULL;
    SDL_DestroyTexture(in4_Chaien);
    in4_Chaien = NULL;
    TTF_CloseFont(font);

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
    if (gMusic != nullptr) Mix_FreeMusic( gMusic );

    //Kết thúc ván cờ
    graphics.quit();

    return 0;
}
