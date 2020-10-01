#include <iostream>
#include <string>
#include <vector>
#include <time.h>
#pragma once

using namespace std;

class InsultGenerator {

    public:
        void initialize();
        string talkToMe();
        vector<string> generate(int num);
        void generateAndSave(string, int num);

    private:
        string column1[50];
        string column2[50];
        string column3[50];
 
};