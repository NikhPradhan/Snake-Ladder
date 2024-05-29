// SnakeAndLadder.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "CSnakeLadderGame.h"

int main()
{
    /*IJumper* snake1 = new CSnake(20, 6);
    IJumper* Ladder1 = new CLadder(5, 10);
    CPlayer player1(1, "Nikhil");
    CPlayer player2(2, "Sujana");
    std::cout << snake1->getStartingPostion() << std::endl;
    std::cout << player1.getName() << std::endl;
    std::cout << Ladder1->getStartingPostion() << std::endl;*/
    CSnakeLadderGame game;
    game.StartGame();
    

}
