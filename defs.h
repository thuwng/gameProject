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
    int p, turn = 0, money = 200, bxe = 0, cty = 0;
    bool is_real_player = false, bankrupt = false;
    bool free = true, free_next_turn = false;
} nvat[4];

//Thứ tự ảnh xí ngầu
const char* Dice[] = {"images/dice/xx1.png", "images/dice/xx2.png", "images/dice/xx3.png", "images/dice/xx4.png", "images/dice/xx5.png", "images/dice/xx6.png"};
const char* Turn[] = {"images/blue1.png", "images/blue2.png", "images/blue3.png", "images/blue4.png"};

//Thứ tự thẻ theo ô
const char* cell[] = {"images/cells/cell36.png", "images/cells/cell1.png", "images/cells/cell2.png", "images/cells/cell3.png",
"images/cells/cell4.png", "images/cells/cell5.png", "images/cells/cell6.png", "images/cells/cell7.png", "images/cells/cell8.png",
"images/cells/cell9.png", "images/cells/cell10.png", "images/cells/cell11.png", "images/cells/cell12.png", "images/cells/cell13.png",
"images/cells/cell14.png", "images/cells/cell15.png", "images/cells/cell16.png", "images/cells/cell17.png", "images/cells/cell18.png",
"images/cells/cell19.png", "images/cells/cell20.png", "images/cells/cell21.png", "images/cells/cell22.png", "images/cells/cell23.png",
"images/cells/cell24.png", "images/cells/cell25.png", "images/cells/cell26.png", "images/cells/cell27.png", "images/cells/cell28.png",
"images/cells/cell29.png", "images/cells/cell30.png", "images/cells/cell31.png", "images/cells/cell32.png", "images/cells/cell33.png",
"images/cells/cell34.png", "images/cells/cell35.png"};

//Vị trí in số tiền
const int M_X = 50;
const int M_Y = 200;
const int M_W = 950;
const int M_H = 300;

//Các ô chữ
const int O_X = 750;
const int O_Y = 30;
const int O_W = 200;
const int O_H = 70;
const int O_D = 210;

//Doraemon chạy
const char*  DORA_SPRITE = "images/dora.png";
const int DORA_CLIPS[][4] = {
    {0, 0, 245, 322},
    {245, 0, 245, 322},
    {490, 0, 245, 322},
    {735, 0, 245, 322},

    {0, 322, 245, 322},
    {245, 322, 245, 322}
};
const int DORA_FRAMES = sizeof(DORA_CLIPS)/sizeof(int)/4;

//Ô khí vận và ô cơ hội
const int T_X = 430;
const int T_Y = 250;
const int T_W = 600;
const int T_H = 300;

//Bốc thăm
const int TH_X = 130;
const int TH_Y = 200;
const int TH_W = 220;
const int TH_DW = 280;
const int TH_H = 270;
const int TH_DH = 290;

//Lật thẻ
const int LT_X[16] = {250,430,610,790,250,430,610,790,250,430,610,790,250,430,610,790};
const int LT_Y[16] = { 10, 10, 10, 10,200,200,200,200,390,390,390,390,580,580,580,580};
const int LT_W = 140;
const int LT_H = 180;

//Hangman
const int H_X[26] = {
    300, 360, 420, 480, 540, 600, 660, 720, 780, 840,
    320, 380, 440, 500, 560, 620, 680, 740, 800,
    340, 400, 460, 520, 580, 640, 700
};
const int H_Y[26] = {
    550, 550, 550, 550, 550, 550, 550, 550, 550, 550,
    610, 610, 610, 610, 610, 610, 610, 610, 610,
    670, 670, 670, 670, 670, 670, 670
};
const int H_S = 50;

#endif // _DEFS__H
