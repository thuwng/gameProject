#ifndef _COHOI__H
#define _COHOI__H

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include <SDL_ttf.h>
#include "graphics.h"
#include "defs.h"
#include "logic.h"
#include "hangman.h"

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

    void hienthe(int stt, bool &cont, int &mode, bool real) {
        SDL_Texture* visit = graphics.loadTexture(cell[nvat[stt].p]);
        graphics.prepareScene(visit);
        SDL_Texture* o_ch;
        int r;

        if (real) {
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

            r = rand() % 10;
            o_ch = graphics.loadTexture(ch[r]);
            graphics.renderTexture_new_size(o_ch, T_X, T_Y, T_W, T_H);

            graphics.presentScene();
            SDL_Delay(2000);

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
                SDL_DestroyTexture(b);
                b = NULL;
                SDL_DestroyTexture(B);
                B = NULL;
            }
        }
        else {
            r = rand() % 10;
            o_ch = graphics.loadTexture(ch[r]);
            graphics.renderTexture_new_size(o_ch, T_X, T_Y, T_W, T_H);

            graphics.presentScene();
            SDL_Delay(2000);
        }

        if (r == 0) {
            for (int i = 0; i < 4; i++)
                if (i != stt && !nvat[i].bankrupt) {
                    nvat[stt].money -= 50;
                    nvat[i].money += 50;
                }
        }

        else if (r == 1) {
            if (!nvat[stt].free_next_turn) {
                SDL_Texture* vao_tu = graphics.loadTexture("images/vaotu.png");
                graphics.prepareScene(vao_tu);

                graphics.presentScene();
                SDL_Delay(2000);
                nvat[stt].free = false;
                nvat[stt].p = 10;

                SDL_DestroyTexture(vao_tu);
                vao_tu = NULL;
            }
            else {
                SDL_Texture* mien_tu = graphics.loadTexture("images/mientu.png");
                graphics.prepareScene(mien_tu);

                graphics.presentScene();
                SDL_Delay(2000);
                nvat[stt].free_next_turn = false;

                SDL_DestroyTexture(mien_tu);
                mien_tu = NULL;
            }
        }

        else if (r == 2) {
            nvat[stt].p -= 3;
            cont = true;
            mode = 1;
        }

        else if (r == 3) {
            if (real) {
                SDL_Texture* boctham = graphics.loadTexture("images/boctham.png");
                SDL_Texture* tham = graphics.loadTexture("images/tham.png");
                SDL_Texture* thamtrungthuong = graphics.loadTexture("images/thamtrungthuong.png");

                graphics.prepareScene(boctham);
                graphics.renderTexture_new_size(tham, TH_X, TH_Y, TH_W, TH_H);
                graphics.renderTexture_new_size(tham, TH_X + TH_DW, TH_Y, TH_W, TH_H);
                graphics.renderTexture_new_size(tham, TH_X, TH_Y + TH_DH, TH_W, TH_H);
                graphics.renderTexture_new_size(tham, TH_X + TH_DW, TH_Y + TH_DH, TH_W, TH_H);

                graphics.presentScene();

                SDL_Event d;
                int x, y, k = 0;
                bool quit = false;
                while (true) {
                    SDL_GetMouseState(&x, &y);
                    SDL_PollEvent(&d);
                    switch (d.type) {
                        case SDL_QUIT:
                            exit(0);
                            break;
                        case SDL_MOUSEBUTTONDOWN:
                            if (TH_X <= x && x <= TH_X + TH_W && TH_Y <= y && y <= TH_Y + TH_H) {
                                quit = true;
                                k = 1;
                            }
                            else if (TH_X + TH_DW <= x && x <= TH_X + TH_W + TH_DW && TH_Y <= y && y <= TH_Y + TH_H) {
                                quit = true;
                                k = 2;
                            }
                            else if (TH_X <= x && x <= TH_X + TH_W && TH_Y + TH_DH <= y && y <= TH_Y + TH_H + TH_DH) {
                                quit = true;
                                k = 3;
                            }
                            else if (TH_X + TH_DW <= x && x <= TH_X + TH_W + TH_DW && TH_Y + TH_DH <= y && y <= TH_Y + TH_H + TH_DH) {
                                quit = true;
                                k = 4;
                            }
                    }
                    if (quit) break;
                }
                TTF_Font* font = graphics.loadFont("fonts/TNR/times.ttf", 50);
                SDL_Color color = {0, 0, 0, 0};
                int tienthuong = (rand() % 5) * 100;
                nvat[stt].money += tienthuong;
                SDL_Texture* thuong = graphics.renderText2(to_string(tienthuong), font, color);
                graphics.prepareScene(boctham);

                if (k == 1) {
                    graphics.renderTexture_new_size(thamtrungthuong, TH_X, TH_Y, TH_W, TH_H);
                    graphics.renderTexture(thuong, TH_X + TH_W / 2 - 35, TH_Y + TH_H * 3 / 4 - 45);
                }
                else graphics.renderTexture_new_size(tham, TH_X, TH_Y, TH_W, TH_H);

                if (k == 2) {
                    graphics.renderTexture_new_size(thamtrungthuong, TH_X + TH_DW, TH_Y, TH_W, TH_H);
                    graphics.renderTexture(thuong, TH_X + TH_DW + TH_W / 2 - 35, TH_Y + TH_H * 3 / 4 - 45);
                }
                else graphics.renderTexture_new_size(tham, TH_X + TH_DW, TH_Y, TH_W, TH_H);

                if (k == 3) {
                    graphics.renderTexture_new_size(thamtrungthuong, TH_X, TH_Y + TH_DH, TH_W, TH_H);
                    graphics.renderTexture(thuong, TH_X + TH_W / 2 - 35, TH_Y + TH_DH + TH_H * 3 / 4 - 45);
                }
                else graphics.renderTexture_new_size(tham, TH_X, TH_Y + TH_DH, TH_W, TH_H);

                if (k == 4) {
                    graphics.renderTexture_new_size(thamtrungthuong, TH_X + TH_DW, TH_Y + TH_DH, TH_W, TH_H);
                    graphics.renderTexture(thuong, TH_X + TH_DW + TH_W / 2 - 35, TH_Y + TH_DH + TH_H * 3 / 4 - 45);
                }
                else graphics.renderTexture_new_size(tham, TH_X + TH_DW, TH_Y + TH_DH, TH_W, TH_H);

                SDL_Delay(500);
                graphics.presentScene();
                SDL_Delay(2000);

                SDL_DestroyTexture(boctham);
                boctham = NULL;
                SDL_DestroyTexture(tham);
                tham = NULL;
                SDL_DestroyTexture(thamtrungthuong);
                thamtrungthuong = NULL;
            }
            else {
                int tienthuong = (rand() % 5) * 100;
                nvat[stt].money += tienthuong;
            }
        }

        else if (r == 4) {
            nvat[stt].p = 0;
            cont = true;
            mode = 1;
        }

        else if (r == 5) {
            nvat[stt].p = 1;
            nvat[stt].money += 200;
        }

        else if (r == 6) {
            nvat[stt].money -= 100;
        }

        else if (r == 7 && real) {
            SDL_Texture* same_intro = graphics.loadTexture("images/same_intro.png");
            graphics.prepareScene(same_intro);

            graphics.presentScene();
            SDL_Delay(1000);

            SDL_Texture* b = graphics.loadTexture("images/tieptheo.png");
            graphics.renderTexture_new_size(b, O_X + 20, O_Y + 40, O_W, O_H);
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
                        if (O_X + 20 <= x && x <= O_X + 20 + O_W && O_Y + 40 <= y && y <= O_Y + 40 + O_H) {
                            quit = true;
                        }
                }
                if (quit) break;
            }
            SDL_Texture* same = graphics.loadTexture("images/same.png");

            SDL_Texture* the[9];
            the[0] = graphics.loadTexture("images/the.png");
            the[1] = graphics.loadTexture("images/the1.png");
            the[2] = graphics.loadTexture("images/the2.png");

            the[3] = graphics.loadTexture("images/the3.png");
            the[4] = graphics.loadTexture("images/the4.png");
            the[5] = graphics.loadTexture("images/the5.png");

            the[6] = graphics.loadTexture("images/the6.png");
            the[7] = graphics.loadTexture("images/the7.png");
            the[8] = graphics.loadTexture("images/the8.png");

            bool THE[16] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
            int lat[8] = {0, 0, 0, 0, 0, 0, 0, 0}, t_sl[8] = {0, 0, 0, 0, 0, 0, 0, 0};
            int t_stt[16] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

            for (int i = 0; i < 16; i++) {
                int r = 0;
                do {
                    r = rand() % 9;
                } while (r == 0 || t_sl[r - 1] == 2);

                t_stt[i] = r;
                t_sl[r - 1]++;
            }

            SDL_Texture* ketqua;
            bool won = false;
            for (int i = 1; i <= 8; i++) {
                graphics.prepareScene(same);
                for (int j = 0; j < 16; j++) {
                    if (!THE[j]) graphics.renderTexture_new_size(the[0], LT_X[j], LT_Y[j], LT_W, LT_H);
                    else graphics.renderTexture_new_size(the[t_stt[j]], LT_X[j], LT_Y[j], LT_W, LT_H);
                }
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
                            for (int j = 0; j < 16; j++)
                                if (LT_X[j] <= x1 && x1 <= LT_X[j] + LT_W && LT_Y[j] <= y1 && y1 <= LT_Y[j] + LT_H && !THE[j]) {
                                    THE[j] = true;
                                    lat[t_stt[j] - 1]++;
                                    quit1 = true;
                                    break;
                                }
                    }
                    if (quit1) break;
                }
                int dem = 0;
                for (int j = 0; j < 8; j++)
                    if (lat[j] == 2) dem++;

                if (dem >= 2) {
                    won = true;
                    break;
                }
                else SDL_Delay(500);
            }

            graphics.prepareScene(same);

            for (int j = 0; j < 16; j++) {
                if (!THE[j]) graphics.renderTexture_new_size(the[0], LT_X[j], LT_Y[j], LT_W, LT_H);
                else graphics.renderTexture_new_size(the[t_stt[j]], LT_X[j], LT_Y[j], LT_W, LT_H);
            }

            graphics.presentScene();
            SDL_Delay(1000);

            if (!won) {
                int dem = 0;
                for (int i = 0; i < 8; i++)
                    if (lat[i] == 2) dem++;
                if (dem >= 2) won = true;
            }

            if (won) {
                ketqua = graphics.loadTexture("images/win.png");
                nvat[stt].money += 400;
            }
            else ketqua = graphics.loadTexture("images/lose.png");

            graphics.prepareScene(ketqua);
            graphics.presentScene();
            SDL_Delay(2000);

            SDL_DestroyTexture(same_intro);
            same_intro = NULL;
            SDL_DestroyTexture(b);
            b = NULL;
            for (int i = 0; i <= 8; i++) {
                SDL_DestroyTexture(the[i]);
                the[i] = NULL;
            }
            SDL_DestroyTexture(ketqua);
            ketqua = NULL;
        }

        else if (r == 7 && !real) {
            nvat[stt].money += 400;
        }

        else if (r == 8) {
            nvat[stt].money /= 2;
        }

        else if (r == 9 && real) {
            Hangman game(graphics);
            bool ketqua;
            game.play(ketqua);
            SDL_Texture* kq;
            if (ketqua) {
                kq = graphics.loadTexture("images/win.png");
                nvat[stt].money += 400;
            }
            else kq = graphics.loadTexture("images/lose.png");

            graphics.prepareScene(kq);
            graphics.presentScene();
            SDL_Delay(2000);

            SDL_DestroyTexture(kq);
            kq = NULL;
        }

        else if (r == 9 && !real) {
            nvat[stt].money += 400;
        }

        SDL_DestroyTexture(visit);
        visit = NULL;
        SDL_DestroyTexture(o_ch);
        o_ch = NULL;
    }
};

#endif // _COHOI__H
