//
//  main.cpp
//  NooseGame
//
//  Created by Иван Милаев on 19/02/2019.
//  Copyright © 2019 IvanMilaev. All rights reserved.
//

#include <iostream>

// to make syntax Unreal friendly
using FText = std::string;
using int32 = int;

void PrintIntro();
void PlayGame();
bool AskToPlayAgain();

int main(int argc, const char * argv[]) {
    
    bool bPlayAgain = false;
    
    do
    {
        PrintIntro();
        PlayGame();
        bPlayAgain = AskToPlayAgain();
    }
    while (bPlayAgain);
    
    return 0;
}


void PrintIntro()

{
    std::cout << "Welcome to Noose, a fun word game =).\n";
    std::cout << std::endl;
    std::cout << " ___________.._______ " << std::endl;
    std::cout << "| .__________))______| " << std::endl;
    std::cout << "| | / /      || " << std::endl;
    std::cout << "| |/ /       || " << std::endl;
    std::cout << "| | /        ||.-''. " << std::endl;
    std::cout << "| |/         |/  _  \\ " << std::endl;
    std::cout << "| |          ||  `/,| " << std::endl;
    std::cout << "| |          (\\`_.' " << std::endl;
    std::cout << "| |         .-`--'. " << std::endl;
    std::cout << "| |        /Y . . Y\\ " << std::endl;
    std::cout << "| |       // |   | \\\\ " << std::endl;
    std::cout << "| |      //  | . |  \\\\ " << std::endl;
    std::cout << "| |     ')   |   |   (` " << std::endl;
    std::cout << "| |          ||'|| " << std::endl;
    std::cout << "| |          || || " << std::endl;
    std::cout << "| |          || || " << std::endl;
    std::cout << "| |          || || " << std::endl;
    std::cout << "| |         / | | \\ " << std::endl;
    std::cout << "\"\"\"\"\"\"\"\"\"\"|_\\`-' \\`-' |\"\"\"| " << std::endl;
    std::cout << "|\"|\"\"\"\"\"\"\"\\ \\       '\"|\"| " << std::endl;
    std::cout << "| |        \\ \\        | | " << std::endl;
    std::cout << ": :         \\ \\       : : " << std::endl;
    std::cout << ". .          `'       . . " << std::endl;
    std::cout << std::endl;
    return;
}

bool AskToPlayAgain()
{
    std::cout << "Do you want to play again (y/n)? ";
    FText Response = "";
    std::getline(std::cin, Response);
    return (Response[0] == 'y') || (Response[0] == 'Y');
}

