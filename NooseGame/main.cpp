//
//  main.cpp
//  NooseGame
//
//  Created by Иван Милаев on 19/02/2019.
//  Copyright © 2019 IvanMilaev. All rights reserved.
//
#pragma once
#include <iostream>
#include <string>
#include "FNooseGame.h"



// to make syntax Unreal friendly
using FText = std::string;
using int32 = int;

// function prototypes as outside a class
void PrintIntro();
void PlayGame();
FText GetValidGuess();
bool AskToPlayAgain();


FNooseGame NGame; // instantiate a new game, which we re-use across plays

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

void PlayGame()
{
    // Reset game  make a new word
    NGame.Reset();
    
    while (!NGame.IsGameWon() && !NGame.IsHang()) {
        FText Guess = GetValidGuess();

        // submit valid guess to the game, and receive counts
        NGame.SubmitValidGuess(Guess);

    }

    if (NGame.IsGameWon()) {
        std::cout << "\n\nYou win!!!.\n";
    }
    else
    {
        std::cout << "\n\nYou lose ...\n";
        NGame.Hanging(8);
    }
    //loop until all the letters are not guessed or man will not hang
        //show hidden word with stars instead of unsolved letters
        //input guess
        //validate guess
        //if guess is one letter:
            //if guess is not successed:
                //print next art of hanging man
        //else if guess is word (>1 letters):
            //if word is right - game won else - lost
    
    
    //display the results
    
}

// loop continually until the user gives a valid guess
FText GetValidGuess()
{
    FText Guess = "";
    EGuessStatus Status = EGuessStatus::Invalid_Status;
    do {
        // get a guess from the player
        int32 CurrentMistake = NGame.GetCurrentMistake();
        NGame.Hanging(CurrentMistake);
        std::cout << "Hidden word is: " << NGame.GetWordWithStars() << "\n";
        std::cout << "Mistake " << CurrentMistake << " of  8 \n";
        std::cout << ". Enter letter or full word: ";
        std::getline(std::cin, Guess);

         //check status and give feedback
        Status = NGame.CheckGuessValidity(Guess);
        switch (Status) {
            case EGuessStatus::Wrong_Length:
                std::cout << "Please enter a one letter or a " << NGame.GetHiddenWordLength() << " letter word.\n\n";
                break;
            case EGuessStatus::Not_Lowercase:
                std::cout << "Please enter all lowercase letters.\n\n";
                break;
            default:
                // assume the guess is valid
                break;
        }
    } while (Status != EGuessStatus::OK ||  Guess == "exit"); // keep looping until we get no errors
    return Guess;
}

bool AskToPlayAgain()
{
    std::cout << "Do you want to play again (y/n)? ";
    FText Response = "";
    std::getline(std::cin, Response);
    return (Response[0] == 'y') || (Response[0] == 'Y');
}

