#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include "windows.h"


using namespace std;

const char FOOD = 'x';
const char BORDER = '#';


struct pacman {
    const char LOOK = '@';
    int foodEaten = 0;
    int x = 1;
    int y = 1;

};

BOOL gotoxy(const WORD x, const WORD y) {
    COORD xy;
    xy.X = x;
    xy.Y = y;
    return SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), xy);
}



int loadMap(vector<string>& map) {// initialize map

    string currLine;
    int foodCount = 0;
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
        for (int i = 0; i < currLine.length(); i++) {
            if (tolower(currLine.at(i)) == FOOD ) {
                foodCount++; //count food
            }
        }
        map.push_back(currLine); //add each line to map vector
    }
    mapFile.close();
 
    return foodCount; //return success or fail
}

bool movement(int incX, int incY, vector<string>& map, pacman& sprite) {
    bool success = false;//return val
    char nextChar = map.at(sprite.x + incX).at(sprite.y + incY);//char at the space we want to move to
    switch (tolower(nextChar)){
    case BORDER://if border do nothing
        break;
    case FOOD://if food increment
        sprite.foodEaten += 1;
    default: //valid move case instructions
        success = true;
        map.at(sprite.x).at(sprite.y) = ' ';//clear old location
        //update sprite location
        sprite.x += incX;
        sprite.y += incY;
        map.at(sprite.x).at(sprite.y) = sprite.LOOK; //update location in vector
    }
    
    return success;
}


void displayMap(const vector<string> & map) {
    gotoxy(0, 0);
    string currLine;
    for (string s : map) {
        cout << s << endl;
    }
}

bool gameOver(int foodCount, int foodEaten) {
    return foodCount == foodEaten;
}

int main()
{
    vector<string> map;
    int numberOfFood = 0;
    bool game_running = true;
    pacman sprite;

    numberOfFood = loadMap(map);

    
    system("cls");
    movement(0, 0, map, sprite); //for maps that do not have an initial starting position
        // I forsee an issue where the a map has a  starting position other than 1,1. should we loop to find sprite.look then set default to that?
    do{
        game_running = !gameOver(numberOfFood, sprite.foodEaten);
        gotoxy(0,0);

        displayMap(map);
        cout << "Total Food: " << numberOfFood << endl;
        
        system("pause>nul");

        if(GetAsyncKeyState(VK_DOWN) ){
            movement(1,0,map, sprite);
        }

        if(GetAsyncKeyState(VK_UP)  ){
            movement(-1,0,map, sprite);
        }

        if(GetAsyncKeyState(VK_RIGHT)  ){
            movement(0,1,map, sprite);
        }

        if(GetAsyncKeyState(VK_LEFT)   ){
            movement(0,-1,map, sprite);
        }

        if(GetAsyncKeyState(VK_ESCAPE)){
            game_running = false;
        }

        cout << "Food Eaten: " << sprite.foodEaten << endl;

    }while(game_running);

    system("cls");
    cout << "GAME OVER";
 
    return 0;
}
