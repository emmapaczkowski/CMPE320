/*
*Author:Emma Paczkowski
*/

#include "jumble.h"
#include <iostream>

using namespace std;

JumblePuzzle::JumblePuzzle (string hiddenWordIn, string difficultyIn) {
    this->difficulty =  setDifficulty(difficultyIn);
    this->hiddenWord = setHidden(hiddenWordIn);
    this->puzzleSize = difficulty * hiddenWord.length();
    
   //Randomly assign a rowPos and columnPos;

  srand(time(0));
  this->rowPos = rand() % this->puzzleSize;
  this->colPos = rand() % this->puzzleSize;

  char validDirections[4];
  int numberOfValidDirections = JumblePuzzle ::getValidDirections(rowPos, colPos, puzzleSize, hiddenWord, validDirections);
  this->direction = validDirections[std::rand() % numberOfValidDirections];
  this->puzzle = JumblePuzzle::generatePuzzle(puzzleSize, direction, rowPos, colPos, hiddenWord);
}

JumblePuzzle::~JumblePuzzle() {
    for (int i = 0; i < puzzleSize; i++) {
        char* row = this->puzzle[i];
        delete[] row;
    }
    delete[] this->puzzle;
}

JumblePuzzle& JumblePuzzle::operator=(JumblePuzzle& comparePuzzle ) {
    if (this == &comparePuzzle) {
        return comparePuzzle;
    }

    for (int i = 0; i < puzzleSize; i++) {
        char* row = this->puzzle[i];
        delete[] row;
    }
    delete[] this->puzzle;

    this->direction = comparePuzzle.direction;
    this->puzzleSize = comparePuzzle.puzzleSize;
    this->rowPos = comparePuzzle.rowPos;
    this->colPos = comparePuzzle.colPos;
    this->hiddenWord = comparePuzzle.hiddenWord;
    this->difficulty = comparePuzzle.difficulty;

    this->puzzle = new char*[puzzleSize];
    for (int i = 0; i < puzzleSize; i++) {
        puzzle[i] = new char[puzzleSize];
        for (int j = 0; j < puzzleSize; j++) {
            puzzle[i][j] = comparePuzzle.puzzle[i][j];
        }
    }

    return *this;
}

JumblePuzzle::JumblePuzzle(JumblePuzzle& puzzleIn) {
    this->difficulty = puzzleIn.difficulty;
    this->hiddenWord = puzzleIn.hiddenWord;
    this->puzzleSize = puzzleIn.puzzleSize;
    this->direction = puzzleIn.direction;
    this->rowPos = puzzleIn.rowPos;
    this->colPos = puzzleIn.rowPos;

    this->puzzle = new char*[puzzleSize];
    for (int i = 0; i < puzzleSize; i++) {
        puzzle[i] = new char[puzzleSize];
        for (int j = 0; j < puzzleSize; j++) {
            puzzle[i][j] = puzzleIn.puzzle[i][j];
        }
    }
}

int JumblePuzzle::setDifficulty(string& difficulty) {
    if(difficulty == "hard") {
        return HARD;
    }
     if(difficulty == "medium") {
        return MEDIUM;
    }
     if(difficulty == "easy") {
        return EASY;
    }
    throw BadJumbleException("You must select your difficulty to be hard, medium or easy");

}
const string JumblePuzzle::setHidden(string hiddenStr) {

    if (hiddenStr.length() < 3) {
        throw BadJumbleException("Your word must be longer than characters");
    }
    if (hiddenStr.length() > 10) {
     throw BadJumbleException("Your word can not be longer than 10 charecters");
     }

    for (char& c :hiddenStr) {
        if (('a' <= c && c <= 'z') || ('A' <= c && c <= 'Z')) {
          continue;
        }
    throw BadJumbleException("Your word must only conatin a-z charecters");
  }

  return hiddenStr;
}

int JumblePuzzle::getValidDirections(int rowPos, int colPos,int puzzleSize, const string& hiddenWord,   char* outDirections) {
    int numValidDirections = 0;

     int lettersToAdd = (int) hiddenWord.length() - 1;
     if (rowPos - lettersToAdd >= 0) {
       outDirections[numValidDirections] = 'n';
      numValidDirections++;
     }
     if (rowPos + lettersToAdd < puzzleSize) {
      outDirections[numValidDirections] = 's';
      numValidDirections++;
     }
     if (colPos + lettersToAdd < puzzleSize) {
        outDirections[numValidDirections] = 'e';
        numValidDirections++;
    }
    if (colPos - lettersToAdd >= 0) {
        outDirections[numValidDirections] = 'w';
        numValidDirections++;
  }

  return numValidDirections;

}

char** JumblePuzzle::generatePuzzle(int puzzleSize, char direction, int rowPos, int colPos, const string& hiddenWord) {
    char** puzzle = new char*[puzzleSize];

    int rowcorer;
    int colcorner;
    int wordIndex;
    int diffIndex;
    if (direction == 's' || direction == 'e') {
        rowcorer = rowPos;
        colcorner = colPos;
        wordIndex = 0;
        diffIndex = 1;
    } 
    else if (direction == 'n') {  // North
        rowcorer = rowPos - (hiddenWord.length() - 1);
        colcorner = colPos;
        wordIndex = hiddenWord.length() - 1;
        diffIndex = -1;
    }
    else {  // West
        rowcorer = rowPos;
        colcorner = colPos - (hiddenWord.length() - 1);
        wordIndex = hiddenWord.length() - 1;
        diffIndex = -1;
    }

    bool placingHiddenWord = false;
    bool directionIsVertical = direction == 'n' || direction == 's';
    for (int row = 0; row < puzzleSize; row++) {
        puzzle[row] = new char[puzzleSize];
        for (int col = 0; col < puzzleSize; col++) {
            if (row == rowcorer && col == colcorner) {
                placingHiddenWord = true;
            }

            bool canPlaceVertical;
            if (col == colcorner && directionIsVertical) {
                canPlaceVertical = true;
            } else { canPlaceVertical = false; }

            
            bool canPlaceHorizontal;
            if (row == rowcorer && !directionIsVertical) {
                 canPlaceHorizontal = true;
            } else { canPlaceHorizontal = false; }

            if (placingHiddenWord && (canPlaceHorizontal || canPlaceVertical)) {
                puzzle[row][col] = hiddenWord[wordIndex];
                wordIndex += diffIndex;
                if (wordIndex < 0 || wordIndex == hiddenWord.length()) {
                    placingHiddenWord = false;
                }
            }
            else {
                char randomLetter = rand() % 26 + 'a';
                puzzle[row][col] = randomLetter;
            }
        }
    }
    return puzzle;
}
