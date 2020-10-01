#include <iostream>
#include <string>
#include <vector>
#include <time.h>
#include <fstream>

#include "insultgenerator_17ep14.h"
//#include "InsultsSource.txt"

using namespace std;


void InsultGenerator::initialize() {
    string filename = "InsultsSource.txt";
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



// .initalize() reads form file
//.talk to me returns 1 insult
//.generate(int) generates int number of insults
//.generateAndSave(file.txt, int) saves the insults to a given file