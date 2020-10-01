#include <iostream>
#include <string>
#include <vector>
#include <time.h>
#include <fstream>

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
    //int one = rand()%50;
    //int two = rand()%50;
    //int three = rand()%50;
    //cout <<"Thou "<< column1[rand()%50] <<" "<< column2[rand()%50] <<" "<< column3[rand()%50] <<"!"<< endl;
    //string insult = column1[one] + " " + column2[rand()%100-50] + " " + column3[rand()%100-50];
    //return insult;
    return ("Thou "+ column1[rand()%50] + " " + column2[rand()%50] + " " + column3[rand()%50] + "!" );
}
/*
vector<string> InsultGenerator::generate(int num) {

}

void InsultGenerator::generateAndSave(string outFile, int num) {

}

*/




//.talk to me returns 1 insult
//.generate(int) generates int number of insults
//.generateAndSave(file.txt, int) saves the insults to a given file