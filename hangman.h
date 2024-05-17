#ifndef _HANGMAN__H
#define _HANGMAN__H

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include <SDL_ttf.h>
#include "graphics.h"
#include "defs.h"
#include "logic.h"

using namespace std;

const int MAX_BAD_GUESSES = 7;
const string WORD_LIST[] = {
	"angle", "ant", "apple", "arch", "arm", "army",
    "baby", "bag", "ball", "band", "basin", "basket", "bath", "bed", "bee", "bell", "berry",
    "bird", "blade", "board", "boat", "bone", "book", "boot", "bottle", "box", "boy",
    "brain", "brake", "branch", "brick", "bridge", "brush", "bucket", "bulb", "button",
    "cake", "camera", "card",  "cart", "carriage", "cat", "chain", "cheese", "chest",
    "chin", "church", "circle", "clock", "cloud", "coat", "collar", "comb", "cord",
    "cow", "cup", "curtain", "cushion",
    "dog", "door", "drain", "drawer", "dress", "drop", "ear", "egg", "engine", "eye",
    "face", "farm", "feather", "finger", "fish", "flag", "floor", "fly",
    "foot", "fork", "fowl", "frame",
    "garden", "girl", "glove", "goat", "gun",
    "hair", "hammer", "hand", "hat", "head", "heart", "hook", "horn", "horse",
    "hospital", "house",
    "island", "jewel",
    "kettle", "key", "knee", "knife", "knot",
    "leaf", "leg", "library", "line", "lip", "lock",
    "map", "match", "monkey", "moon", "mouth", "muscle",
    "nail", "neck", "needle", "nerve", "net", "nose", "nut",
    "office", "orange", "oven", "parcel", "pen", "pencil", "picture", "pig", "pin",
    "pipe", "plane", "plate", "plow", "pocket", "pot", "potato", "prison", "pump",
    "rail", "rat", "receipt", "ring", "rod", "roof", "root",
    "sail", "school", "scissors", "screw", "seed", "sheep", "shelf", "ship", "shirt",
    "shoe", "skin", "skirt", "snake", "sock", "spade", "sponge", "spoon", "spring",
    "square", "stamp", "star", "station", "stem", "stick", "stocking", "stomach",
    "store", "street", "sun",
    "table", "tail", "thread", "throat", "thumb", "ticket", "toe", "tongue", "tooth",
    "town", "train", "tray", "tree", "trousers",
    "umbrella",
    "wall", "watch", "wheel", "whip", "whistle", "window", "wire", "wing", "worm"};

const int WORD_COUNT = sizeof(WORD_LIST) / sizeof(string);

const char* alphabet[26] = {
    "q", "w", "e", "r", "t", "y", "u", "i", "o", "p",
    "a", "s", "d", "f", "g", "h", "j", "k", "l",
    "z", "x", "c", "v", "b", "n", "m"
};

char Alphabet[26] = {
    'q', 'w', 'e', 'r', 't', 'y', 'u', 'i', 'o', 'p',
    'a', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l',
    'z', 'x', 'c', 'v', 'b', 'n', 'm'
};

struct Hangman{
    Graphics graphics;
    Hangman (Graphics _graphics) {
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

    string chooseWord() {
        int r = rand() % WORD_COUNT;
        return WORD_LIST[r];
    }

    bool contains(string word, char c) {
        for (int i = 0; i < (int) word.length(); i++)
            if (word[i] == c) return true;
        return false;
    }

	void play(bool &ketqua) {
	    SDL_Texture* HANGMAN = graphics.loadTexture("images/hangman/hangman.png");
	    graphics.prepareScene(HANGMAN);
	    SDL_Texture* start_button = graphics.loadTexture("images/hangman/nutplay.png");
        graphics.renderTexture_new_size(start_button, START_BUTTON_X + 420, START_BUTTON_Y + 150, START_BUTTON_W, START_BUTTON_H);
        graphics.presentScene();

        SDL_Event event;
        while (true) {
            int x, y;
            bool quit = 0;
            SDL_GetMouseState(&x, &y);
            SDL_Rect play;
            play.x = START_BUTTON_X + 420;
            play.y = START_BUTTON_Y + 150;
            play.w = START_BUTTON_W;
            play.h = START_BUTTON_H;

            if (x >= play.x && x <= play.x + play.w && y >= play.y && y <= play.y + play.h) {
                graphics.renderTexture_new_size(start_button, START_BUTTON_X + 420 - 10, START_BUTTON_Y + 150 - 10, START_BUTTON_W + 20, START_BUTTON_H + 20);
            }
            else {
                graphics.renderTexture_new_size(start_button, START_BUTTON_X + 420, START_BUTTON_Y + 150, START_BUTTON_W, START_BUTTON_H);
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

        string word = chooseWord(); cout << word << endl;
        string guessedWord = string(word.length(), '_');
        int badGuessCount = 0;
        int vt, vitri[word.length()];
        bool guessed[word.length()];
        for (int i = 0; i < word.length(); i++) guessed[i] = false;

        SDL_Texture* hm[8];
        hm[0] = graphics.loadTexture("images/hangman/hm0.png");
        hm[1] = graphics.loadTexture("images/hangman/hm1.png");
        hm[2] = graphics.loadTexture("images/hangman/hm2.png");
        hm[3] = graphics.loadTexture("images/hangman/hm3.png");
        hm[4] = graphics.loadTexture("images/hangman/hm4.png");
        hm[5] = graphics.loadTexture("images/hangman/hm5.png");
        hm[6] = graphics.loadTexture("images/hangman/hm6.png");
        hm[7] = graphics.loadTexture("images/hangman/hm7.png");
        SDL_Texture* oo = graphics.loadTexture("images/hangman/oo.png");

        TTF_Font* font = graphics.loadFont("fonts/TNR/times.ttf", 30);
        SDL_Color color = {0, 0, 0, 0};
        SDL_Texture* chucai[26];
        for (int i = 0; i < 26; i++) chucai[i] = graphics.renderText(alphabet[i], font, color);
        SDL_Texture* chu;

        do {
            graphics.prepareScene(hm[badGuessCount]);
            for (int i = 0; i < (int) word.length(); i++) {
                graphics.renderTexture_new_size(oo, 600 + i * 60, 250, 50, 50);
                if (guessed[i]) {
                    chu = graphics.renderText(alphabet[vitri[i]], font, color);
                    graphics.renderTexture(chu, 615 + i * 60, 260);
                }
            }

            for (int i = 0; i < 26; i++) {
                graphics.renderTexture_new_size(oo, H_X[i], H_Y[i], H_S, H_S);
                graphics.renderTexture(chucai[i], H_X[i] + 15, H_Y[i] + 10);
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
                        if (H_X[0] <= x1 && x1 <= H_X[0] + H_S && H_Y[0] <= y1 && y1 <= H_Y[0] + H_S) {
                            quit1 = true;
                            vt = 0;
                        }
                        else if (H_X[1] <= x1 && x1 <= H_X[1] + H_S && H_Y[1] <= y1 && y1 <= H_Y[1] + H_S) {
                            quit1 = true;
                            vt = 1;
                        }
                        else if (H_X[2] <= x1 && x1 <= H_X[2] + H_S && H_Y[2] <= y1 && y1 <= H_Y[2] + H_S) {
                            quit1 = true;
                            vt = 2;
                        }
                        else if (H_X[3] <= x1 && x1 <= H_X[3] + H_S && H_Y[3] <= y1 && y1 <= H_Y[3] + H_S) {
                            quit1 = true;
                            vt = 3;
                        }
                        else if (H_X[4] <= x1 && x1 <= H_X[4] + H_S && H_Y[4] <= y1 && y1 <= H_Y[4] + H_S) {
                            quit1 = true;
                            vt = 4;
                        }
                        else if (H_X[5] <= x1 && x1 <= H_X[5] + H_S && H_Y[5] <= y1 && y1 <= H_Y[5] + H_S) {
                            quit1 = true;
                            vt = 5;
                        }
                        else if (H_X[6] <= x1 && x1 <= H_X[6] + H_S && H_Y[6] <= y1 && y1 <= H_Y[6] + H_S) {
                            quit1 = true;
                            vt = 6;
                        }
                        else if (H_X[7] <= x1 && x1 <= H_X[7] + H_S && H_Y[7] <= y1 && y1 <= H_Y[7] + H_S) {
                            quit1 = true;
                            vt = 7;
                        }
                        else if (H_X[8] <= x1 && x1 <= H_X[8] + H_S && H_Y[8] <= y1 && y1 <= H_Y[8] + H_S) {
                            quit1 = true;
                            vt = 8;
                        }
                        else if (H_X[9] <= x1 && x1 <= H_X[9] + H_S && H_Y[9] <= y1 && y1 <= H_Y[9] + H_S) {
                            quit1 = true;
                            vt = 9;
                        }
                        else if (H_X[10] <= x1 && x1 <= H_X[10] + H_S && H_Y[10] <= y1 && y1 <= H_Y[10] + H_S) {
                            quit1 = true;
                            vt = 10;
                        }
                        else if (H_X[11] <= x1 && x1 <= H_X[11] + H_S && H_Y[11] <= y1 && y1 <= H_Y[11] + H_S) {
                            quit1 = true;
                            vt = 11;
                        }
                        else if (H_X[12] <= x1 && x1 <= H_X[12] + H_S && H_Y[12] <= y1 && y1 <= H_Y[12] + H_S) {
                            quit1 = true;
                            vt = 12;
                        }
                        else if (H_X[13] <= x1 && x1 <= H_X[13] + H_S && H_Y[13] <= y1 && y1 <= H_Y[13] + H_S) {
                            quit1 = true;
                            vt = 13;
                        }
                        else if (H_X[14] <= x1 && x1 <= H_X[14] + H_S && H_Y[14] <= y1 && y1 <= H_Y[14] + H_S) {
                            quit1 = true;
                            vt = 14;
                        }
                        else if (H_X[15] <= x1 && x1 <= H_X[15] + H_S && H_Y[15] <= y1 && y1 <= H_Y[15] + H_S) {
                            quit1 = true;
                            vt = 15;
                        }
                        else if (H_X[16] <= x1 && x1 <= H_X[16] + H_S && H_Y[16] <= y1 && y1 <= H_Y[16] + H_S) {
                            quit1 = true;
                            vt = 16;
                        }
                        else if (H_X[17] <= x1 && x1 <= H_X[17] + H_S && H_Y[17] <= y1 && y1 <= H_Y[17] + H_S) {
                            quit1 = true;
                            vt = 17;
                        }
                        else if (H_X[18] <= x1 && x1 <= H_X[18] + H_S && H_Y[18] <= y1 && y1 <= H_Y[18] + H_S) {
                            quit1 = true;
                            vt = 18;
                        }
                        else if (H_X[19] <= x1 && x1 <= H_X[19] + H_S && H_Y[19] <= y1 && y1 <= H_Y[19] + H_S) {
                            quit1 = true;
                            vt = 19;
                        }
                        else if (H_X[20] <= x1 && x1 <= H_X[20] + H_S && H_Y[20] <= y1 && y1 <= H_Y[20] + H_S) {
                            quit1 = true;
                            vt = 20;
                        }
                        else if (H_X[21] <= x1 && x1 <= H_X[21] + H_S && H_Y[21] <= y1 && y1 <= H_Y[21] + H_S) {
                            quit1 = true;
                            vt = 21;
                        }
                        else if (H_X[22] <= x1 && x1 <= H_X[22] + H_S && H_Y[22] <= y1 && y1 <= H_Y[22] + H_S) {
                            quit1 = true;
                            vt = 22;
                        }
                        else if (H_X[23] <= x1 && x1 <= H_X[23] + H_S && H_Y[23] <= y1 && y1 <= H_Y[23] + H_S) {
                            quit1 = true;
                            vt = 23;
                        }
                        else if (H_X[24] <= x1 && x1 <= H_X[24] + H_S && H_Y[24] <= y1 && y1 <= H_Y[24] + H_S) {
                            quit1 = true;
                            vt = 24;
                        }
                        else if (H_X[25] <= x1 && x1 <= H_X[25] + H_S && H_Y[25] <= y1 && y1 <= H_Y[25] + H_S) {
                            quit1 = true;
                            vt = 25;
                        }

                }
                if (quit1) break;
            }

            if (contains(word, Alphabet[vt])) {
                for (int i = word.length() - 1; i >= 0; i--) {
                    if (word[i] == Alphabet[vt]) {
                        guessedWord[i] = Alphabet[vt];
                        guessed[i] = true;
                        vitri[i] = vt;
                    }
                }
            }
            else badGuessCount++;
        } while (badGuessCount < MAX_BAD_GUESSES && word != guessedWord);

        if (badGuessCount < MAX_BAD_GUESSES) {
            ketqua = true;
            graphics.prepareScene(hm[badGuessCount]);
            for (int i = 0; i < (int) word.length(); i++) {
                graphics.renderTexture_new_size(oo, 600 + i * 60, 250, 50, 50);
                if (guessed[i]) {
                    chu = graphics.renderText(alphabet[vitri[i]], font, color);
                    graphics.renderTexture(chu, 615 + i * 60, 260);
                }
            }

            for (int i = 0; i < 26; i++) {
                graphics.renderTexture_new_size(oo, H_X[i], H_Y[i], H_S, H_S);
                graphics.renderTexture(chucai[i], H_X[i] + 15, H_Y[i] + 10);
            }

            graphics.presentScene();
            SDL_Delay(1000);
        }
        else {
            ketqua = false;
            graphics.prepareScene(hm[badGuessCount]);
            graphics.presentScene();
            SDL_Delay(1000);
        }

        SDL_DestroyTexture(HANGMAN);
        HANGMAN = NULL;
        SDL_DestroyTexture(start_button);
        start_button = NULL;
        for (int i = 0; i < 8; i++) {
            SDL_DestroyTexture(hm[i]);
            hm[i] = NULL;
        }
        SDL_DestroyTexture(oo);
        oo = NULL;
        //SDL_DestroyTexture(font);
        //font = NULL;
        SDL_DestroyTexture(chu);
        chu = NULL;
        for (int i = 0; i < 26; i++) {
            SDL_DestroyTexture(chucai[i]);
            chucai[i] = NULL;
        }
	}
};

#endif // _HANGMAN__H
