#include <iostream>
#include <string>
#include <vector>
#include <time.h>
#include <stdexcept>
#pragma once

using namespace std;
// The InsultGenerateor class reads from the provided file and generates insults.  
// It uses three arrays to keep the input words from th file (one for each column).
// When generating random insults it uses an ordered set where the keys are the combined array indexes.
// For example if the indexes were 13,42,32 then the key would be 134232
// This was used as lookup time in a set is constant making it easy to see if an insult exists 
// Once enough insuts are generated, you itterate through the set to then generate the insults form the keys
class InsultGenerator {

    public:
        void initialize();
        string talkToMe();
        vector<string> generate(int num);
        void generateAndSave(string outFile, int num);

    private:
        string column1[50];
        string column2[50];
        string column3[50];
 
};

//The file execption class is used to throw exceptions when the file is unable to be read from or written to.
class FileException {
    public:
        FileException(const string& message);
        string& what();

    private:
        string message;
};

//This class is used when you request an invalid number of insults 
class NumInsultsOutOfBounds {
    public:
        NumInsultsOutOfBounds(const string& message);
        string& what();

    private:
        string message;
};
