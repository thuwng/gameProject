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
    int p, turn = 0, money = 200;
    bool is_real_player = false, bankrupt = false;
} Nobita, Shizuka, Suneo, Chaien;

//Thứ tự ảnh xí ngầu
const char* Dice[] = {"images/dice/xx1.png", "images/dice/xx2.png", "images/dice/xx3.png", "images/dice/xx4.png", "images/dice/xx5.png", "images/dice/xx6.png"};

//Thông tin người chơi
const int nobita_x = 100;
const int nobita_y = 50;
const int shizuka_x = 100;
const int shizuka_y = 500;
const int suneo_x = 500;
const int suneo_y = 50;
const int chaien_x = 500;
const int chaien_y = 500;

const char* cells[] = {"images/cells/cell36.png", "images/cells/cell1.png", "images/cells/cell2.png", "images/cells/cell3.png",
"images/cells/cell4.png", "images/cells/cell5.png", "images/cells/cell6.png", "images/cells/cell7.png", "images/cells/cell8.png",
"images/cells/cell9.png", "images/cells/cell10.png", "images/cells/cell11.png", "images/cells/cell12.png", "images/cells/cell13.png",
"images/cells/cell14.png", "images/cells/cell15.png", "images/cells/cell16.png", "images/cells/cell17.png", "images/cells/cell18.png",
"images/cells/cell19.png", "images/cells/cell20.png", "images/cells/cell21.png", "images/cells/cell22.png", "images/cells/cell23.png",
"images/cells/cell24.png", "images/cells/cell25.png", "images/cells/cell26.png", "images/cells/cell27.png", "images/cells/cell28.png",
"images/cells/cell29.png", "images/cells/cell30.png", "images/cells/cell31.png", "images/cells/cell32.png", "images/cells/cell33.png",
"images/cells/cell34.png", "images/cells/cell35.png"};

#endif // _DEFS__H
