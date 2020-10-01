#include <iostream>
#include <string>
#include <vector>
#include <time.h>

#include "insultgenerator_17ep14.h"

using namespace std;

class InsultGenerator {

    public:
        void initialize();
        string talkToMe();
        vector<string> generate(int num);
        void generateAndSave(string, int num);

    private:
        vector<int> column1;
        vector<int> column2;
        vector<int> column3;
 };

void initalize()
{
    

}

// .initalize() reads form file
//.talk to me returns 1 insult
//.generate(int) generates int number of insults
//.generateAndSave(file.txt, int) saves the insults to a given file