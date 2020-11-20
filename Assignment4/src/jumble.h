/*
* Author: Emma Paczkowski
*/
#ifndef JUMBLE_h

#include <cstdlib>
#include <ctime>
#include <exception>
#include <string>

using namespace std;


class JumblePuzzle {

    public:

        JumblePuzzle(string toHide, string difficulty);


        //The big three
        JumblePuzzle(JumblePuzzle&);
        JumblePuzzle& operator=(JumblePuzzle&);
        ~JumblePuzzle();

        //accessors 
        char** getJumble() { 
            return puzzle; 
        }
        const string& getHiddenWord() { 
            return hiddenWord; 
        }
        int getSize() { 
            return puzzleSize;
        }
        int getRowPos() { 
            return rowPos;    
        }
        int getColPos() {
             return colPos;              
        }
        char getDirection() { 
            return direction;             
        }

    private:   
 
        int difficulty;
        string hiddenWord;
        char** puzzle;
        int puzzleSize;
        char direction;
        int rowPos;
        int colPos;

       // Constants for the difficulty of puzzle
        static const int EASY = 2;           //   static const Difficulty EASY = 2;
        static const int MEDIUM = 3;
        static const int HARD = 4;

       //Used to initalize difficulty when the constructor is called
        int initDifficulty(string&);       // static Difficulty initDifficulty(std::string&);

        //Use to initalice the hidden workd when the constructor is called
        const string initToHide(string&);    // static const std::string initHiddenWord(std::string);

        //Use to generate the puzzle
        char** generatePuzzle(int puzzleSize, char direction,  int rowPos, int colPos, const string& hiddenWord);   // removed static

};
#endif