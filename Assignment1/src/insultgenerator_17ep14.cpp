#include <iostream>
#include <string>
#include <vector>
#include <time.h>
#include <fstream>
#include <set>

#include "insultgenerator_17ep14.h"
//#include "InsultsSource.txt"

using namespace std;


void InsultGenerator::initialize() {
    string filename = "src\\InsultsSource.txt";
    ifstream fs(filename);
    int num = 0;
    
    //fs.open(filename);   // .c_str
    if (fs.fail()) {
        cerr << "Unable to open file: " << "InsultsSource.txt"<< endl;
    }

    string col1;
    string col2;
    string col3;

        while (fs >> col1 >> col2 >> col3) {
            column1[num] = col1;
            column2[num] = col2;
            column3[num] = col3;
            num++;
        }

    fs.close();
}

string InsultGenerator::talkToMe() {
    return ("Thou "+ column1[rand()%50] + " " + column2[rand()%50] + " " + column3[rand()%50] + "!" );
}

vector<string> InsultGenerator::generate(int num) {
    if (num == 0) {
        return {};
    }
    if (num > 1000) {
        cout << "requested number of insults is out of bounds" << endl;
        return {};
    }
    else {

        set<int> mySet;
        int count = num;
        while (count > 0 ) {
            int key = rand()%50*10000 + rand()%50*100 + rand()%50;
            if (mySet.find(key) == mySet.end()) {
               mySet.insert(key);
              count--;
            }
        }
        set<int>::iterator it = mySet.begin();
        while (it != mySet.end()) {
            cout<< (*it) << endl;
            it++;
        }
     return{};
    }
}

/*
void InsultGenerator::generateAndSave(string outFile, int num) {

}

*/




//.talk to me returns 1 insult
//.generate(int) generates int number of insults
//.generateAndSave(file.txt, int) saves the insults to a given file