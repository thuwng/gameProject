#ifndef _LOGIC__H
#define _LOGIC__H

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include <SDL_ttf.h>
#include "graphics.h"
#include "defs.h"
#include "dat.h"
#include "benxe.h"
#include "congty.h"
#include "khivan.h"
#include "cohoi.h"

using namespace std;

//1
vector<int> dat = {2, 4, 8, 9, 11, 13, 15, 17, 18, 20, 22, 23, 25, 27, 29, 31, 34};
//2
vector<int> honhop = {1, 5, 35};
//3
vector<int> ben_xe = {6, 14, 24, 32};
//4
vector<int> cong_ty = {12, 26};
//5
vector<int> vaotu = {28};
//6
vector<int> nhatu = {10};
//7
vector<int> sanbay = {19};
//8
vector<int> khivan = {3, 16, 33};
//9
vector<int> cohoi = {7, 21, 30};

bool check(int pos, vector<int> a, int &loai) {
    int l = 0, r = (int) a.size() - 1;
    while (l <= r) {
        int m = (l + r) / 2;
        if (pos == a[m]) {
            loai = m;
            return true;
        }
        else if (pos < a[m]) r = m - 1;
        else l = m + 1;
    }
    return false;
}

int findpos(int pos, int &loai) {
    if (pos == 0) {
        loai = 17;
        return 1;
    }
    else if (check(pos, dat, loai)) return 1;
    else if (check(pos, honhop, loai)) return 2;
    else if (check(pos, benxe, loai)) return 3;
    else if (check(pos, congty, loai)) return 4;
    else if (check(pos, vaotu, loai)) return 5;
    else if (check(pos, nhatu, loai)) return 6;
    else if (check(pos, sanbay, loai)) return 7;
    else if (check(pos, khivan, loai)) return 8;
    else return 9;
}

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

    int x1, x2;
    void gieoxingau(int stt, bool &cont, int &mode, bool real) {
        SDL_Texture* blank = graphics.loadTexture(Turn[stt]);
        graphics.prepareScene(blank);
        graphics.presentScene();

        if (real) {
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
                            x1 = rand() % 6;
                            x2 = rand() % 6;
                            quit = true;
                        }
                }
                if (quit) break;
            }

            SDL_Delay(500);
            SDL_DestroyTexture(button);
            button = NULL;
        }
        else {
            x1 = rand() % 6;
            x2 = rand() % 6;
        }

        SDL_Texture* dice1 = graphics.loadTexture(Dice[x1]);
        graphics.renderTexture_new_size(dice1, 650, 200, 200, 200);
        SDL_Texture* dice2 = graphics.loadTexture(Dice[x2]);
        graphics.renderTexture_new_size(dice2, 880, 200, 200, 200);

        graphics.presentScene();
        if (real) SDL_Delay(1000);
        else SDL_Delay(2000);

        //Thay đổi vị trí
        int before = nvat[stt].p;
        nvat[stt].p = (nvat[stt].p + x1 + x2 + 2) % 36;
        if (x1 == x2) {
            cont = true;
            mode = 0;
        }

        //Xóa
        SDL_DestroyTexture(dice2);
        dice2 = NULL;
        SDL_DestroyTexture(dice1);
        dice1 = NULL;

        SDL_DestroyTexture(blank);
        blank = NULL;
    }

    void cohoiratu(int stt, bool &ratu) {
        SDL_Texture* blank = graphics.loadTexture(Turn[stt]);
        graphics.prepareScene(blank);
        graphics.presentScene();

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
                        x1 = rand() % 6;
                        x2 = rand() % 6;
                        quit = true;
                    }
            }
            if (quit) break;
        }

        SDL_Delay(500);

        SDL_Texture* dice1 = graphics.loadTexture(Dice[x1]);
        graphics.renderTexture_new_size(dice1, 650, 200, 200, 200);
        SDL_Texture* dice2 = graphics.loadTexture(Dice[x2]);
        graphics.renderTexture_new_size(dice2, 880, 200, 200, 200);

        graphics.presentScene();
        SDL_Delay(800);

        if (x1 == x2) ratu = true;

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
        SDL_Texture* in4_Nobita = graphics.renderText2(to_string(nvat[0].money), font, color);
        SDL_Texture* in4_Shizuka = graphics.renderText2(to_string(nvat[1].money), font, color);
        SDL_Texture* in4_Suneo = graphics.renderText2(to_string(nvat[2].money), font, color);
        SDL_Texture* in4_Chaien = graphics.renderText2(to_string(nvat[3].money), font, color);

        //Nạp nhân vật
        SDL_Texture* nobita = graphics.loadTexture("images/characters_removed_background/Nobita.png");
        SDL_Texture* shizuka = graphics.loadTexture("images/characters_removed_background/Shizuka.png");
        SDL_Texture* suneo = graphics.loadTexture("images/characters_removed_background/Suneo.png");
        SDL_Texture* chaien = graphics.loadTexture("images/characters_removed_background/Chaien.png");

        //Sở hữu
        SDL_Texture* Color[4];
        Color[0] = graphics.loadTexture("images/vang.png");
        Color[1] = graphics.loadTexture("images/hong.png");
        Color[2] = graphics.loadTexture("images/xanh.png");
        Color[3] = graphics.loadTexture("images/cam.png");

        //Chuẩn bị bàn cờ
        graphics.prepareScene(board);

        for (int stt = 0; stt < 4; stt++) {
            for (int i = 0; i < 18; i++)
                if (o_dat[i].chu == stt) {
                    int h = 1;
                    if (o_dat[i].ks) h = 4;
                    else if (o_dat[i].nha != 0) h += o_dat[i].nha;
                    if (i == 17) graphics.renderTexture_new_size(Color[stt], N_X[0], N_Y[0], 45, 5 * h);
                    else graphics.renderTexture_new_size(Color[stt], N_X[dat[i]], N_Y[dat[i]], 45, 5 * h);
                }
            for (int i = 0; i < 4; i++)
                if (bxe[i] == stt) {
                    graphics.renderTexture_new_size(Color[stt], N_X[ben_xe[i]], N_Y[ben_xe[i]], 45, 5);
                }
            for (int i = 0; i < 2; i++)
                if (cty[i] == stt) {
                    graphics.renderTexture_new_size(Color[stt], N_X[cong_ty[i]], N_Y[cong_ty[i]], 45, 5);
                }
        }

        if (!nvat[0].bankrupt) graphics.renderTexture_new_size(nobita, N_X[nvat[0].p], N_Y[nvat[0].p], N_W, N_H);
        if (!nvat[1].bankrupt) graphics.renderTexture_new_size(shizuka, S_X + N_X[nvat[1].p], S_Y + N_Y[nvat[1].p], S_W, S_H);
        if (!nvat[2].bankrupt) graphics.renderTexture_new_size(suneo, X_X + N_X[nvat[2].p], X_Y + N_Y[nvat[2].p], X_W, X_H);
        if (!nvat[3].bankrupt) graphics.renderTexture_new_size(chaien, C_X + N_X[nvat[3].p], C_Y + N_Y[nvat[3].p], C_W, C_H);

        if (!nvat[0].bankrupt) graphics.renderTexture(in4_Nobita, M_X, M_Y);
        if (!nvat[1].bankrupt) graphics.renderTexture(in4_Shizuka, M_X, M_Y + M_H);
        if (!nvat[2].bankrupt) graphics.renderTexture(in4_Suneo, M_X + M_W, M_Y);
        if (!nvat[3].bankrupt) graphics.renderTexture(in4_Chaien, M_X + M_W, M_Y + M_H);

        //Hiện lại bàn cờ
        graphics.presentScene();
        SDL_Delay(3000);

        //Xóa
        SDL_DestroyTexture(board);
        board = NULL;

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

        for (int i = 0; i < 4; i++) {
            SDL_DestroyTexture(Color[i]);
            Color[i] = NULL;
        }
    }

    void dingangobatdau(int stt, bool real) {
        SDL_Texture* visit = graphics.loadTexture(cell[1]);
        graphics.prepareScene(visit);
        nvat[stt].money += 200;

        if (real) {
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

            SDL_DestroyTexture(b);
            b = NULL;
        }
        else {
            graphics.presentScene();
            SDL_Delay(3000);
        }
        SDL_DestroyTexture(visit);
        visit = NULL;
    }

    void thuchien(int stt, bool &cont, int &mode, bool real) {
        int loai;
        if (findpos(nvat[stt].p, loai) == 1) {
            Loai1 a(graphics);
            a.hienthe(stt, loai, real);
        }
        else if (findpos(nvat[stt].p, loai) == 2) {
            SDL_Texture* visit = graphics.loadTexture(cell[nvat[stt].p]);
            graphics.prepareScene(visit);

            if (honhop[loai] == 1) nvat[stt].money += 200;
            else if (honhop[loai] == 5) nvat[stt].money -= min(200, nvat[stt].money * 10 / 100);
            else if (honhop[loai] == 35) nvat[stt].money -= 100;

            if (real) {
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

                SDL_DestroyTexture(b);
                b = NULL;
            }
            else {
                graphics.presentScene();
                SDL_Delay(1000);
            }
            SDL_DestroyTexture(visit);
            visit = NULL;
        }
        else if (findpos(nvat[stt].p, loai) == 3) {
            Loai3 a(graphics);
            a.hienthe(stt, loai, real);
        }
        else if (findpos(nvat[stt].p, loai) == 4) {
            Loai4 a(graphics);
            a.hienthe(stt, loai, x1 + x2 + 2, real);
        }
        else if (findpos(nvat[stt].p, loai) == 5) {
            SDL_Texture* visit = graphics.loadTexture(cell[nvat[stt].p]);
            graphics.prepareScene(visit);

            if (!nvat[stt].free_next_turn) {
                nvat[stt].free = false;
                nvat[stt].p = 10;
            }

            if (real) {
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

                SDL_DestroyTexture(b);
                b = NULL;
            }
            else {
                graphics.presentScene();
                SDL_Delay(1000);
            }

            SDL_DestroyTexture(visit);
            visit = NULL;
        }
        else if (findpos(nvat[stt].p, loai) == 6) {
            SDL_Texture* visit = graphics.loadTexture(cell[nvat[stt].p]);
            graphics.prepareScene(visit);

            if (real) {
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

                SDL_DestroyTexture(b);
                b = NULL;
            }
            else {
                graphics.presentScene();
                SDL_Delay(1000);
            }

            SDL_DestroyTexture(visit);
            visit = NULL;
        }
        else if (findpos(nvat[stt].p, loai) == 7) {
            SDL_Texture* visit = graphics.loadTexture(cell[nvat[stt].p]);
            graphics.prepareScene(visit);

            if (real) {
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

                SDL_DestroyTexture(b);
                b = NULL;
            }
            else {
                graphics.presentScene();
                SDL_Delay(1000);
            }

            SDL_Texture* road = graphics.loadTexture("images/road.jpg");
            Sprite dora;
            SDL_Texture* doraTexture = graphics.loadTexture(DORA_SPRITE);
            dora.init(doraTexture, DORA_FRAMES, DORA_CLIPS);

            bool quit1 = false;
            int dx = -20, dy = 420, nb = 0;
            while(!quit1) {
                if(nb == 28) quit1 = true;
                nb++;

                dora.tick();

                graphics.prepareScene(road);
                graphics.render(dx, dy, dora);
                graphics.presentScene();
                SDL_Delay(100);

                dx = (dx + 50) % (SCREEN_W - 50);
            }

            SDL_Texture* plane = graphics.loadTexture("images/airplane.png");
            quit1 = false;
            int Dx = -20, Dy = 150, c = 0;
            while(!quit1) {
                if(c == 29) quit1 = true;
                c++;

                dora.tick();

                graphics.prepareScene(road);
                graphics.render(dx, dy, dora);
                graphics.renderTexture_new_size(plane, Dx, Dy, 300, 200);

                graphics.presentScene();
                SDL_Delay(100);

                Dx = (Dx + 40) % SCREEN_W;
            }

            SDL_DestroyTexture(plane);
            plane = NULL;
            SDL_DestroyTexture(doraTexture);
            doraTexture = NULL;
            SDL_DestroyTexture(road);
            road = NULL;
            SDL_DestroyTexture(visit);
            visit = NULL;

            nvat[stt].p = 2;
            cont = true;
            mode = 1;
        }
        else if (findpos(nvat[stt].p, loai) == 8) {
            Loai8 a(graphics);
            a.hienthe(stt, real);
        }
        else if (findpos(nvat[stt].p, loai) == 9) {
            Loai9 a(graphics);
            a.hienthe(stt, cont, mode, real);
        }
    }

    void phasan(int stt) {
        for (int i = 0; i < 18; i++)
            if (o_dat[i].chu == stt) {
                o_dat[i].chu = -1;
                o_dat[i].nha = 0;
                o_dat[i].ks = false;
            }
        for (int i = 0; i < 4; i++)
            if (bxe[i] == stt) {
                bxe[i] = -1;
            }
        for (int i = 0; i < 2; i++)
            if (cty[i] == stt) {
                cty[i] = -1;
            }
    }
};

#endif // _LOGIC__H
