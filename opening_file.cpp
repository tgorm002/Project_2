#include <iostream>
#include <string>
#include <array>
#include <time.h>
#include <queue>
#include <vector>
#include <math.h>
#include <fstream>
#include <sstream>

using namespace std;

float arr[50500];
int placeInArr = 0;

void split2(string str){
    istringstream ss(str); 
    string word; 
    
    while (ss >> word) { 
        int numSize = word.size();
        //cout << "string: " << word << "\n"; 
        if(word.at(numSize - 3) == '-' && word.at(numSize-2) == '0' && word.at(numSize-1) == '1'){ //ends with e-01
            word.at(numSize - 4) = '0'; //e
            word.at(numSize - 3) = '0'; //-
            float temp = stof(word);
            temp = temp * .1;
            //cout << temp << endl;
            arr[placeInArr] = temp;
            // cout << "should add val to array" << endl;
            placeInArr++;
        }
        else if(word.at(numSize - 3) == '-' && word.at(numSize-2) == '0' && word.at(numSize-1) == '2') { //ends in e-02
            word.at(numSize - 4) = '0'; //e
            word.at(numSize - 3) = '0'; //-
            float temp = stof(word);
            temp = temp * .01;
            //cout << temp << endl;
            arr[placeInArr] = temp;
            // cout << "should add val to array" << endl;
            placeInArr++;
        }
        else if(word.at(numSize - 9) == '0' && word.at(numSize - 8) == '0' && word.at(numSize - 7) == '0' && word.at(numSize - 6) == '0' && word.at(numSize - 5) == '0' && word.at(numSize - 3) == '+' && word.at(numSize-2) == '0' && word.at(numSize-1) == '0') { //ends in e+00
            word.at(numSize - 4) = '0'; //e
            word.at(numSize - 3) = '0'; //-
            float temp = stof(word);
            //cout << temp  << " is at index " << placeInArr << endl;
            arr[placeInArr] = temp;
            // cout << "should add val to array" << endl;
            placeInArr++;
        }
        else if(word.at(numSize - 3) == '+' && word.at(numSize-2) == '0' && word.at(numSize-1) == '0') { //ends in e+00
            word.at(numSize - 4) = '0'; //e
            word.at(numSize - 3) = '0'; //-
            float temp = stof(word);
            //cout << temp << endl;
            arr[placeInArr] = temp;
            // cout << "should add val to array" << endl;
            placeInArr++;
        }
        else if(word.at(numSize - 3) == '-' && word.at(numSize-2) == '0' && word.at(numSize-1) == '3') { //ends in e-03
            word.at(numSize - 4) = '0'; //e
            word.at(numSize - 3) = '0'; //-
            float temp = stof(word);
            temp = temp * .001;
            //cout << temp << endl;
            arr[placeInArr] = temp;
            // cout << "should add val to array" << endl;
            placeInArr++;
        }
         else if(word.at(numSize - 3) == '-' && word.at(numSize-2) == '0' && word.at(numSize-1) == '4') { //ends in e-04
            word.at(numSize - 4) = '0'; //e
            word.at(numSize - 3) = '0'; //-
            float temp = stof(word);
            temp = temp * .0001;
            //cout << temp << endl;
            arr[placeInArr] = temp;
            // cout << "should add val to array" << endl;
            placeInArr++;
        }
        else if(word.at(numSize - 3) == '-' && word.at(numSize-2) == '0' && word.at(numSize-1) == '5') { //ends in e-04
            word.at(numSize - 4) = '0'; //e
            word.at(numSize - 3) = '0'; //-
            float temp = stof(word);
            temp = temp * .00001;
            //cout << temp << endl;
            arr[placeInArr] = temp;
            // cout << "should add val to array" << endl;
            placeInArr++;
        }
        else{
            cout << "SOMEHOW GOT HERE AND I SHOULDNT BE" << endl;
            cout << word << endl;
        }
    }
    return;
}

int main() {
    ifstream file("CS170_largetestdata__77.txt");
    string str; 
    int linenum = 0;
    while (getline(file, str)) {
        linenum++;
        // if(linenum == 69) {
            split2(str);
            //cout << str << endl;
        //}        
    }
    // for(int j = 0; j < 3300; j++) {
    //     //cout << "expecting output here" << endl;
    //     cout << arr[j] << endl;
    // }
}