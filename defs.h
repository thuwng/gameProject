#ifndef _DEFS__H
#define _DEFS__H

const char* WINDOW_TITLE = "Cờ tỷ phú cùng Doraemon và những người bạn";

//Màn hình
const int SCREEN_W = 1200;
const int SCREEN_H = 800;

//Nút play
const int START_BUTTON_W = 300;
const int START_BUTTON_H = 200;
const int START_BUTTON_X = 30;
const int START_BUTTON_Y = 350;

//Chọn số người chơi
const int NUM_BUTTON_W = 250;
const int NUM_BUTTON_H = 130;
const int NUM_BUTTON_X = 650;
const int NUM_BUTTON_Y = 230;
const int NUM_BUTTON_D = 140;

//Chọn nhân vật
const int CHOOSE_CHARACTER_W = 280;
const int CHOOSE_CHARACTER_H = 400;
const int CHOOSE_CHARACTER_X = 100;
const int CHOOSE_CHARACTER_Y = 20;
const int CHOOSE_CHARACTER_D = 250;

//Nhân vật Nobita
const int N_X[] = {880, 880, 813, 746, 679, 612, 545, 478, 411, 344, 277, 277, 277, 277, 277, 277, 277, 277, 277, 277, 344, 411, 478, 545, 612, 679, 746, 813, 880, 880, 880, 880, 880, 880, 880, 880};
const int N_Y[] = {643, 723, 723, 723, 723, 723, 723, 723, 723, 723, 723, 643, 563, 483, 403, 323, 243, 163,  83,   3,   3,   3,   3,   3,   3,   3,   3,   3,   3,  83, 163, 243, 323, 403, 483, 563};
const int N_W = 25;
const int N_H = 35;

//Nhân vật Shizuka
const int S_X = 0;
const int S_Y = 42;
const int S_W = 20;
const int S_H = 30;

//Nhân vật Suneo
const int X_X = 25;
const int X_Y = -5;
const int X_W = 35;
const int X_H = 45;

//Nhân vật Chaien
const int C_X = 25;
const int C_Y = 42;
const int C_W = 25;
const int C_H = 35;

//Thiết lập nhân vật
struct character{
    int x, y, w, h;
    character(int _x, int _y, int _w, int _h) {
        x = _x;
        y = _y;
        w = _w;
        h = _h;
    }
    int turn = 0, money = 200, stt = 1;
    bool is_real_player = false, bankrupt = false;
} Nobita(N_X[Nobita.stt], N_Y[Nobita.stt], N_W, N_H), Shizuka(S_X + N_X[Shizuka.stt], S_Y + N_Y[Shizuka.stt], S_W, S_H), Suneo(X_X + N_X[Suneo.stt], X_Y + N_Y[Suneo.stt], X_W, X_H), Chaien(C_X + N_X[Chaien.stt], C_Y + N_Y[Chaien.stt], C_W, C_H);

//Thứ tự ảnh xí ngầu
const char* Dice[] = {"images/dice/xx1.png", "images/dice/xx2.png", "images/dice/xx3.png", "images/dice/xx4.png", "images/dice/xx5.png", "images/dice/xx6.png"};

//Chọn nhân vật
const char* Choose[] = {"images/choose1.png", "images/choose2.png", "images/choose3.png", "images/choose4.png"};

#endif // _DEFS__H
