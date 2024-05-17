#ifndef _DAT__H
#define _DAT__H

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include <SDL_ttf.h>
#include "graphics.h"
#include "defs.h"

using namespace std;

struct Dat{
    int chu = -1, nha = 0;
    bool ks = false;
    int giadat, gianha, giaks;
    int thuedat, thuenha1, thuenha2, thueks;
};
Dat o_dat[20];

struct Loai1{
    Graphics graphics;
    Loai1 (Graphics _graphics) {
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

    void khoitao() {
        //TÂN KỲ TÂN QUÝ
        o_dat[0].thuedat = 2; o_dat[0].thuenha1 = 10; o_dat[0].thuenha2 = 30; o_dat[0].thueks = 90;
        o_dat[0].giadat = 60; o_dat[0].gianha = 50; o_dat[0].giaks = 50;

        //LŨY BÁN BÍCH
        o_dat[1].thuedat = 4; o_dat[1].thuenha1 = 20; o_dat[1].thuenha2 = 60; o_dat[1].thueks = 180;
        o_dat[1].giadat = 60; o_dat[1].gianha = 50; o_dat[1].giaks = 50;

        //NGUYỄN KIỆM
        o_dat[2].thuedat = 6; o_dat[2].thuenha1 = 30; o_dat[2].thuenha2 = 90; o_dat[2].thueks = 270;
        o_dat[2].giadat = 100; o_dat[2].gianha = 50; o_dat[2].giaks = 50;

        //CỘNG HÒA
        o_dat[3].thuedat = 8; o_dat[3].thuenha1 = 40; o_dat[3].thuenha2 = 100; o_dat[3].thueks = 300;
        o_dat[3].giadat = 120; o_dat[3].gianha = 50; o_dat[3].giaks = 50;

        //HOÀNG VĂN THỤ
        o_dat[4].thuedat = 10; o_dat[4].thuenha1 = 50; o_dat[4].thuenha2 = 150; o_dat[4].thueks = 450;
        o_dat[4].giadat = 140; o_dat[4].gianha = 100; o_dat[4].giaks = 100;

        //LÊ ĐẠI HÀNH
        o_dat[5].thuedat = 12; o_dat[5].thuenha1 = 60; o_dat[5].thuenha2 = 180; o_dat[5].thueks = 500;
        o_dat[5].giadat = 160; o_dat[5].gianha = 100; o_dat[5].giaks = 100;

        //NGUYỄN TRI PHƯƠNG
        o_dat[6].thuedat = 14; o_dat[6].thuenha1 = 70; o_dat[6].thuenha2 = 200; o_dat[6].thueks = 550;
        o_dat[6].giadat = 180; o_dat[6].gianha = 100; o_dat[6].giaks = 100;

        //KHA VẠN CÂN
        o_dat[7].thuedat = 14; o_dat[7].thuenha1 = 70; o_dat[7].thuenha2 = 200; o_dat[7].thueks = 550;
        o_dat[7].giadat = 180; o_dat[7].gianha = 100; o_dat[7].giaks = 100;

        //PHẠM THẾ HIỂN
        o_dat[8].thuedat = 16; o_dat[8].thuenha1 = 80; o_dat[8].thuenha2 = 220; o_dat[8].thueks = 600;
        o_dat[8].giadat = 200; o_dat[8].gianha = 100; o_dat[8].giaks = 100;

        //HUỲNH TẤN PHÁT
        o_dat[9].thuedat = 18; o_dat[9].thuenha1 = 90; o_dat[9].thuenha2 = 250; o_dat[9].thueks = 700;
        o_dat[9].giadat = 220; o_dat[9].gianha = 150; o_dat[9].giaks = 150;

        //HÙNG VƯƠNG
        o_dat[10].thuedat = 18; o_dat[10].thuenha1 = 90; o_dat[10].thuenha2 = 250; o_dat[10].thueks = 700;
        o_dat[10].giadat = 220; o_dat[10].gianha = 150; o_dat[10].giaks = 150;

        //HẬU GIANG
        o_dat[11].thuedat = 20; o_dat[11].thuenha1 = 100; o_dat[11].thuenha2 = 300; o_dat[11].thueks = 750;
        o_dat[11].giadat = 240; o_dat[11].gianha = 150; o_dat[11].giaks = 150;

        //NGUYỄN TRÃI
        o_dat[12].thuedat = 22; o_dat[12].thuenha1 = 110; o_dat[12].thuenha2 = 330; o_dat[12].thueks = 800;
        o_dat[12].giadat = 260; o_dat[12].gianha = 150; o_dat[12].giaks = 150;

        //NGUYỄN TẤT THÀNH
        o_dat[13].thuedat = 24; o_dat[13].thuenha1 = 120; o_dat[13].thuenha2 = 360; o_dat[13].thueks = 850;
        o_dat[13].giadat = 280; o_dat[13].gianha = 150; o_dat[13].giaks = 150;

        //VÕ THỊ SÁU
        o_dat[14].thuedat = 26; o_dat[14].thuenha1 = 130; o_dat[14].thuenha2 = 390; o_dat[14].thueks = 900;
        o_dat[14].giadat = 300; o_dat[14].gianha = 200; o_dat[14].giaks = 200;

        //LƯƠNG ĐỊNH CỦA
        o_dat[15].thuedat = 28; o_dat[15].thuenha1 = 150; o_dat[15].thuenha2 = 450; o_dat[15].thueks = 1000;
        o_dat[15].giadat = 320; o_dat[15].gianha = 200; o_dat[15].giaks = 200;

        //LÊ LỢI
        o_dat[16].thuedat = 35; o_dat[16].thuenha1 = 175; o_dat[16].thuenha2 = 500; o_dat[16].thueks = 1100;
        o_dat[16].giadat = 350; o_dat[16].gianha = 200; o_dat[16].giaks = 200;

        //NGUYỄN HUỆ
        o_dat[17].thuedat = 50; o_dat[17].thuenha1 = 200; o_dat[17].thuenha2 = 600; o_dat[17].thueks = 1400;
        o_dat[17].giadat = 400; o_dat[17].gianha = 200; o_dat[17].giaks = 200;
    }

    void hienthe(int stt, int loai, bool real) {
        if (o_dat[loai].chu == -1 && real) {
            SDL_Texture* visit = graphics.loadTexture(cell[nvat[stt].p]);
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
                o_dat[loai].chu = stt;
                nvat[stt].money -= o_dat[loai].giadat;
            }

            SDL_DestroyTexture(visit);
            visit = NULL;
            SDL_DestroyTexture(a);
            a = NULL;
            SDL_DestroyTexture(b);
            b = NULL;

            SDL_Delay(500);
        }
        else if (o_dat[loai].chu == stt && o_dat[loai].nha < 2 && real) {
            SDL_Texture* visit = graphics.loadTexture(cell[nvat[stt].p]);
            graphics.prepareScene(visit);

            SDL_Texture* a = graphics.loadTexture("images/muanha.png");
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
                o_dat[loai].nha++;
                nvat[stt].money -= o_dat[loai].gianha;
            }

            SDL_DestroyTexture(visit);
            visit = NULL;
            SDL_DestroyTexture(a);
            a = NULL;
            SDL_DestroyTexture(b);
            b = NULL;

            SDL_Delay(500);
        }
        else if (o_dat[loai].chu == stt && o_dat[loai].nha == 2 && real) {
            SDL_Texture* visit = graphics.loadTexture(cell[nvat[stt].p]);
            graphics.prepareScene(visit);

            SDL_Texture* a = graphics.loadTexture("images/muaks.png");
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
                o_dat[loai].ks = true;
                nvat[stt].money -= o_dat[loai].giaks;
            }

            SDL_DestroyTexture(visit);
            visit = NULL;
            SDL_DestroyTexture(a);
            a = NULL;
            SDL_DestroyTexture(b);
            b = NULL;

            SDL_Delay(500);
        }
        else if (o_dat[loai].chu != stt && o_dat[loai].chu != -1) {
            int thue = 0;
            if (o_dat[loai].nha == 0) {
                nvat[stt].money -= o_dat[loai].thuedat;
                thue = o_dat[loai].thuedat;
            }
            else if (o_dat[loai].nha == 1) {
                nvat[stt].money -= o_dat[loai].thuenha1;
                thue = o_dat[loai].thuenha1;
            }
            else if (o_dat[loai].nha == 2 && !o_dat[loai].ks) {
                nvat[stt].money -= o_dat[loai].thuenha2;
                thue = o_dat[loai].thuenha2;
            }
            else {
                nvat[stt].money -= o_dat[loai].thueks;
                thue = o_dat[loai].thueks;
            }
            nvat[o_dat[loai].chu].money += thue;
        }
    }
};

#endif // _DAT__H
