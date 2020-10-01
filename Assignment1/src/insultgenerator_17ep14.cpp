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
    cout << "Array 1:" << endl;
    for (int i =0; i < 49; i++ ) {
        cout << column1[i] << ", " ;
    }

    cout << "Array 2:" << endl;
    for (int i =0; i < 49; i++ ) {
        cout << column2[i] << ", " ;
    }

    cout << "Array 3:" << endl;
    for (int i =0; i < 49; i++ ) {
        cout << column3[i] << ", " ;
    }
}



// .initalize() reads form file
//.talk to me returns 1 insult
//.generate(int) generates int number of insults
//.generateAndSave(file.txt, int) saves the insults to a given file