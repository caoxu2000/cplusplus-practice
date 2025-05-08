#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "windows.h"
#include <chrono>
#include <thread>
#include <random>


using namespace std;

const char BARRIER = 'x';
const char BORDER = '#';
const int ALIEN_COUNT = 5;
const int MOVE_TIMES = 4;


struct player {
    char look = '^';
    int  aliensShot=0;
    int x = 3;
    int y = 2;
    int color = 11;
    bool alive = true;

    virtual char getlook() {
        return look;
    }

    player() {
    }

    player(char newLook, int newX, int newY, int newColor = 5) {
        look = newLook;
        color = newColor;
        x = newX;
        y = newY;
    }

};


struct invader : public  player{
    char look = 'A';
    char getlook() {
        return look;
    }
    invader() {

    }
    invader(int newX, int newY) {
        x = newX;
        y = newY;
    }
};

struct bullet : public player {
    char look = '!';
    bool alive = false;
    char getlook() {
        return look;
    }
    bullet() {

    }
    bullet(int newX, int newY) {
        x = newX;
        y = newY;
    }

};

BOOL gotoxy(const WORD x, const WORD y) {
    COORD xy;
    xy.X = x;
    xy.Y = y;
    return SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), xy);
}

void Color(int color)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}



void loadMap(vector<string>& map) {// initialize map

    string currLine;
    string fileName;
    ifstream mapFile;

    do {//loop to get file that is openable
        cout << "Please enter a map name: " << endl;
        getline(cin, fileName);
        fileName += ".txt";
        mapFile.open(fileName);

        if (!mapFile) {
            cout << "Error opening file" << endl;
        }
    } while (!mapFile);


    while (getline(mapFile, currLine)) {
        map.push_back(currLine); //add each line to map vector
    }
    mapFile.close();
 
    return;
}


void moveBullet(vector<string>& map, bullet& shot, vector<invader>& aliens, player& player1){
    char nextChar = map.at(shot.x - 1).at(shot.y);

    if ((nextChar == BORDER || nextChar == BARRIER) && shot.alive == true) {// barrier and border case
        shot.alive = false;
        map.at(shot.x).at(shot.y) = ' ';//clear old location
        if (nextChar == BARRIER) {
            map.at(shot.x - 1).at(shot.y) = ' ';// clear barrier
        }
    }
    else {
        if (shot.alive) {
            map.at(shot.x).at(shot.y) = ' ';//clear old location
            //update sprite location
            shot.x -= 1;
            map.at(shot.x).at(shot.y) = shot.getlook(); //update location in vector
        }
    }

    for (int i = 0; i < aliens.size(); i++) {// alien case
        if (((shot.x - 1) == aliens.at(i).x && shot.y == aliens.at(i).y) && (aliens.at(i).alive == true) && (shot.alive = true)){
            aliens.at(i).look = ' '; //change alien look
            aliens.at(i).alive = false; //change alien to dead
            player1.aliensShot += 1; // increase alien shot count
            map.at(shot.x).at(shot.y) = ' ';//clear bullet location
            shot.alive = false;//change bullet to dead
            shot.x = 1; //reset bullet location (otherwise it is there but invisible and kills aliens)
            shot.y = 1;
        }
        
        }
}

void moveInvader(vector<string>& map, vector<invader>& aliens) {
    static int moveDirection = 1;
    static int moveCount = 0;

    if (map.at(aliens.front().x).at(aliens.front().y + moveDirection) == BORDER || map.at(aliens.back().x).at(aliens.back().y + moveDirection) == BORDER) { // if first or last Alien is about to hit border
        moveDirection *= -1;//swap direction
        moveCount++;// increment row interation count
        if (moveCount % MOVE_TIMES == 0) {
            for (int i = 0; i < aliens.size(); i++) {
                map.at(aliens.at(i).x).at(aliens.at(i).y) = ' '; // clear location we are at in map
                aliens.at(i).x += 1;
            }
        }
    }

    for (int i = 0; i < aliens.size(); i++) {
        map.at(aliens.at(i).x).at(aliens.at(i).y) = ' '; // clear location we are at in map
    }

    for (int i = 0; i < aliens.size(); i++) {
        aliens.at(i).y += moveDirection; // move sprite location
        map.at(aliens.at(i).x).at(aliens.at(i).y) =  aliens.at(i).getlook(); // update map with new location
    }
    return;
}



bool movement(int incX, int incY, vector<string>& map, player& player) {
    bool success = false;//return val
    char nextChar = map.at(player.x + incX).at(player.y + incY);//char at the space we want to move to
    
   
 
    switch (tolower(nextChar)){
    case BORDER://if border do nothing
        break;
    default: //valid move case instructions
        success = true;
        
        map.at(player.x).at(player.y) = ' ';//clear old location
        //update sprite location
        player.x += incX;
        player.y += incY;
        map.at(player.x).at(player.y) = player.getlook(); //update location in vector
        //map.at(player.x).at(player.y - 1) = ' ';
    }
    
    return success;
}


void displayMap(const vector<string> & map, player& player1, vector<invader>& aliens) {
    gotoxy(0, 0);
    string currLine;

    for (string s : map) {
        
        for (char t : s) {
            if (t == player1.getlook()){
                Color(player1.color);
                cout << t;
            }
            else if (t == 'A') {
                Color(4);
                cout << t;
            }
            else if (t == BARRIER) {
                Color(10);
                cout << t;
            }else {
                Color(7);
                cout << t;
            }
        }
        
       cout << endl;
    }
}


bool gameOver(player player, vector<invader> aliens) {
    bool gameOver2 = false; //alien hits player
    bool gameOver1 = ALIEN_COUNT == player.aliensShot; // if all aliens shot


    for (int i = 0; i < aliens.size(); i++) {
        if ((aliens.at(i).x == player.x) && (aliens.at(i).y == player.y)) {// if player and an alien is at same spot
            gameOver2 = true;
        }
    }

    return gameOver1 || gameOver2;
}

int main()
{
    int speed = 80;
    vector<string> map;
    vector<invader> aliens(ALIEN_COUNT);
    player player;
    bool game_running = true;
    bullet shot;

  
    loadMap(map);
    
    movement(map.size() - 5, map.at(0).length() / 2, map, player); //for maps that do not have an initial starting position
   
    for (int i = 0; i < aliens.size(); i++) {
        movement(0, i, map, aliens.at(i));
    }

    do{

        
        game_running = !gameOver(player, aliens);
        gotoxy(0,0);

        displayMap(map,player,aliens);

        cout << "Player shot : " << player.aliensShot << " aliens" << endl;
        
 
        this_thread::sleep_for(chrono::milliseconds(speed));


        if(GetAsyncKeyState(VK_SPACE) ){//shoot
            if (!shot.alive) {
                shot.x = player.x - 1;
                shot.y = player.y;
                shot.alive = true;
            }
        }

        if (GetAsyncKeyState(VK_DOWN)) {//decrease speed
            speed += 20;
        }

        if(GetAsyncKeyState(VK_UP)  ){//increase speed
            speed -= 20;
        }

        if(GetAsyncKeyState(VK_RIGHT)  ){
             movement(0,1,map, player);
        }

        if(GetAsyncKeyState(VK_LEFT)   ){
             movement(0,-1,map, player);
        }
      
        if (GetAsyncKeyState(VK_ESCAPE)) {
            game_running = false;

        }
       moveBullet(map, shot, aliens, player);
       moveInvader(map, aliens);
    }while(game_running);

    system("cls");
    cout << "GAME OVER";
 
    return 0;
}
