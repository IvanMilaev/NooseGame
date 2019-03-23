//
//  FNooseGame.cpp
//  NooseGame
//
//  Created by Иван Милаев on 04/03/2019.
//  Copyright © 2019 IvanMilaev. All rights reserved.
//

#include <iostream>
#include "FNooseGame.h"

// to make syntax Unreal friendly
using int32 = int;
using FString = std::string;

FNooseGame::FNooseGame() { Reset(); } // default constructor
int32 FNooseGame::GetCurrentMistake() const { return MyCurrentMistake; }
int32 FNooseGame::GetHiddenWordLength() const { return MyHiddenWord.length(); }
FString FNooseGame::GetWordWithStars() const { return WordWithStars; }
bool FNooseGame::IsGameWon() const { return bGameIsWon; }
bool FNooseGame::IsHang() const { return bGameIsHang; }

void FNooseGame::Reset()
{
    const FString HIDDEN_WORD = "imaginarium"; 
    MyHiddenWord = HIDDEN_WORD;
    const FString STARS_WORD(HIDDEN_WORD.length(), '*');
    WordWithStars = STARS_WORD;
    WordWithStars[0] = MyHiddenWord[0];
    WordWithStars[WordWithStars.length() - 1] = MyHiddenWord[HIDDEN_WORD.length() - 1];
    MyCurrentMistake = 0;
    bGameIsWon = false;
    bGameIsHang = false;
    return;
}

EGuessStatus FNooseGame::CheckGuessValidity(FString Guess) const
{
    if (!IsLowercase(Guess)) // if the guess isn't all lowercase
    {
        return EGuessStatus::Not_Lowercase;
    }
    else if (Guess.length() > 1 && Guess.length() != GetHiddenWordLength()) // if the guess length is wrong
    {
        return EGuessStatus::Wrong_Length;
    }
    else
    {
        return EGuessStatus::OK;
    }
}

// receives a VALID guess, incriments turn, and returns count
void FNooseGame::SubmitValidGuess(FString Guess)
{
    int32 WordLength = MyHiddenWord.length(); // assuming same length as guess
    
    if(Guess.length() == 1) {
        
        bool isRight = false;
        // loop through all letters in the hidden word
        for (int32 MHWChar = 0; MHWChar < WordLength; MHWChar++) {
            if(Guess[0] == MyHiddenWord[MHWChar]) {
                WordWithStars[MHWChar] = Guess[0];
                isRight = true;
            }
        }
        
        if(!isRight) {
            MyCurrentMistake++;
        }
        
        
    } else {
        
        if(Guess == MyHiddenWord) {
            
            bGameIsWon = true;
        }
        else
        {
            bGameIsHang = true;
        }
    }
    
    
    if(MyCurrentMistake == 8) {
        bGameIsHang = true;
    }
}

bool FNooseGame::IsLowercase(FString Word) const
{
    for (auto Letter : Word)
    {
        if (!islower(Letter)) // if not a lowercase letter
        {
            return false;
        }
    }
    return true;
}



void FNooseGame::Hanging( int32 mistake_number )
{
    switch ( mistake_number )
    {
        case 0:
            std::cout << "" << std::endl;
            break;
        case 1:
            std::cout << "" << std::endl;
            std::cout << " __________" << std::endl;
            std::cout << " |/      " << std::endl;
            std::cout << " |      " << std::endl;
            std::cout << " |     " << std::endl;
            std::cout << " |      " << std::endl;
            std::cout << " |      " << std::endl;
            std::cout << " |" << std::endl;
            std::cout << "_|___" << std::endl;
            std::cout << "" << std::endl;
            std::cout << "" << std::endl;
            break;
            
        case 2:
            std::cout << "" << std::endl;
            std::cout << " __________" << std::endl;
            std::cout << " |/      |" << std::endl;
            std::cout << " |      " << std::endl;
            std::cout << " |     " << std::endl;
            std::cout << " |      " << std::endl;
            std::cout << " |      " << std::endl;
            std::cout << " |" << std::endl;
            std::cout << "_|___" << std::endl;
            std::cout << "" << std::endl;
            std::cout << "" << std::endl;
            break;
            
        case 3:
            std::cout << "" << std::endl;
            std::cout << " __________" << std::endl;
            std::cout << " |/      |" << std::endl;
            std::cout << " |      (_)" << std::endl;
            std::cout << " |     " << std::endl;
            std::cout << " |      " << std::endl;
            std::cout << " |      " << std::endl;
            std::cout << " |" << std::endl;
            std::cout << "_|___" << std::endl;
            std::cout << "" << std::endl;
            std::cout << "" << std::endl;
            break;
            
        case 4:
            std::cout << "" << std::endl;
            std::cout << " __________" << std::endl;
            std::cout << " |/      |" << std::endl;
            std::cout << " |      (_)" << std::endl;
            std::cout << " |       |" << std::endl;
            std::cout << " |       |" << std::endl;
            std::cout << " |      " << std::endl;
            std::cout << " |" << std::endl;
            std::cout << "_|___" << std::endl;
            std::cout << "" << std::endl;
            std::cout << "" << std::endl;
            break;
        
        case 5:
            std::cout << "" << std::endl;
            std::cout << " __________" << std::endl;
            std::cout << " |/      |" << std::endl;
            std::cout << " |      (_)" << std::endl;
            std::cout << " |      \\|" << std::endl;
            std::cout << " |       |" << std::endl;
            std::cout << " |      " << std::endl;
            std::cout << " |" << std::endl;
            std::cout << "_|___" << std::endl;
            std::cout << "" << std::endl;
            std::cout << "" << std::endl;
            break;
        
        case 6:
            std::cout << "" << std::endl;
            std::cout << " __________" << std::endl;
            std::cout << " |/      |" << std::endl;
            std::cout << " |      (_)" << std::endl;
            std::cout << " |      \\|/" << std::endl;
            std::cout << " |       |" << std::endl;
            std::cout << " |      " << std::endl;
            std::cout << " |" << std::endl;
            std::cout << "_|___" << std::endl;
            std::cout << "" << std::endl;
            std::cout << "" << std::endl;
            break;
        
        case 7:
            std::cout << "" << std::endl;
            std::cout << " __________" << std::endl;
            std::cout << " |/      |" << std::endl;
            std::cout << " |      (_)" << std::endl;
            std::cout << " |      \\|/" << std::endl;
            std::cout << " |       |" << std::endl;
            std::cout << " |      / "<< std::endl;
            std::cout << " |" << std::endl;
            std::cout << "_|___" << std::endl;
            std::cout << "" << std::endl;
            std::cout << "" << std::endl;
            break;
        
        case 8:
            std::cout << "" << std::endl;
            std::cout << " __________" << std::endl;
            std::cout << " |/      |" << std::endl;
            std::cout << " |      (_)" << std::endl;
            std::cout << " |      \\|/" << std::endl;
            std::cout << " |       |" << std::endl;
            std::cout << " |      / \\"<< std::endl;
            std::cout << " |" << std::endl;
            std::cout << "_|___" << std::endl;
            std::cout << "" << std::endl;
            std::cout << "" << std::endl;
            break;
        default:
            std::cout << " Out of mistake range. Must be  from 1 to 8" << std::endl;
    }
    
    
}



