//
//  FNooseGame.h
//  NooseGame
//
//  Created by Иван Милаев on 04/03/2019.
//  Copyright © 2019 IvanMilaev. All rights reserved.
//

#pragma once
#include <string>

// to make syntax Unreal friendly
using FString = std::string;
using int32 = int;

/*struct FNooseProgress
{
    FString Word_with_stars = "*";
    int32 Mistakes_counter = 0;
    FString Letters_history = "";
};
*/

enum class EGuessStatus
{
    Invalid_Status,
    OK,
    Not_letter,
    Repeat_letter,
    Not_Lowercase,
    Wrong_Length // возможные варианты - либо одна буква либо полностью слово (тогда должно совпадать с длиной загаданого)
};

class FNooseGame
{
public:
    FNooseGame(); // constructor
    
    int32 GetCurrentMistake() const;
    int32 GetHiddenWordLength() const;
    FString GetWordWithStars() const;
    void UpdateWordWithStars();
    bool IsGameWon() const;
    bool IsHang() const;
    
    EGuessStatus CheckGuessValidity(FString) const;
    
    void Hanging(int32);
    void Reset();
    
    void SubmitValidGuess(FString);
    
    
private:
    int32 MyCurrentMistake;
    FString MyHiddenWord;
    FString WordWithStars;
    bool bGameIsWon;
    bool bGameIsHang;
    bool IsLowercase(FString) const;
};
