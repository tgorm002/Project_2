#include <iostream>
#include <string>
#include <array>
#include <time.h>
#include <queue>
#include <vector>
#include <math.h>
#include <fstream>
#include <sstream>

//man why is this assignment so hard for me :(

using namespace std;

float currBestAccuracy = 0;
float finalBestAccuracy = 0;

float numOfLinesInFile = 0;
const int numCOlumnElements = 10; //exclusiding the first column

float tempArr[numCOlumnElements];
float tempArr2[numCOlumnElements];

float arr[3300];
int placeInArr = 0;

void fillTempArr(int numColumns, int index) {
    int tempLoc = 0;
    for(int x = index; x < numColumns; x++) {
        tempArr[tempLoc] = arr[11*x + x + 1];
        cout << tempArr[tempLoc] << endl;
        tempLoc++;
    }
}
void fillTempArr2(int numColumns, int index) {
    for(int x = index; x < numColumns; x++) {
        tempArr2[x] = arr[11*x + x + 1];
    }
}
float findDistance(float arr1[numCOlumnElements], float arr2[numCOlumnElements]){
    float someNum = 0;
    for(int i = 0; i< numCOlumnElements; i++) {
        someNum = someNum + pow((arr1[i] - arr2[i]), 2);
    }
    //cout << someNum << endl;
    return someNum;
}

int checkReccuring(int check[1][4], int alreadySeen[24][4]) {
    for(int i = 0; i < 24; i++) {
        for(int j = 0; j < 4; j++) {
            if(check[i][j] == alreadySeen[i][j]) {
                cout << "found reccurring" << endl;
                return 1;
            }
        }
    }
    return 0;
}

void createArray(string str){
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
        else{
            cout << "SOMEHOW GOT HERE AND I SHOULDNT BE" << endl;
            cout << word << endl;
        }
    }
    return;
}
//float tempArr[numCOlumnElements];
float getAccuracy(int tester) {
    float numberClassifiedCorrectly = 0;
    int nearest_neighbor_label = 0;
    
    for(int i = 0; i < numOfLinesInFile; i++) { //was 0
        for(int x = tester; x < numCOlumnElements; x++) {
            tempArr[x] = arr[11*i + tester + 1];
            //cout << "filling temp arr1 " << tempArr[x] << endl;
        }        
        //fillTempArr(10, i);
        float label_object_to_classify = arr[11*i]; //0 -> 11 -> 22 -> ... -> 3289
        float closest_distance = 100000000; //gotta reset here
        float location = 100000000;
        for(int j = 0; j < numOfLinesInFile; j++) {
            //cout << "looping in inner for loop" << endl;
            if(j != i) {
                for(int x = tester; x < numCOlumnElements; x++) {
                    tempArr2[x] = arr[11*j + tester + 1];
                    //cout << "filling temp arr2 " << tempArr[x] << endl;
                }        
                //fillTempArr2(10,j);
                float currDistance = findDistance(tempArr, tempArr2);
                currDistance = sqrt(currDistance);
                //cout << currDistance << endl;
                if(currDistance < closest_distance) {
                    //cout << "inside the 2nd if statemnt within the inner for loop" << endl;
                    closest_distance = currDistance;
                    location = j;
                    nearest_neighbor_label = arr[11*j]; //just treid arr[11*i] and we got 300 for correctly classified which i know is wrong
                }
            }
        }
        //cout << "Nearest neighbor " << endl;
        //cout << label_object_to_classify << endl;
        if(label_object_to_classify == nearest_neighbor_label){ //might want to edit this if check cuz it rarely goes perfecyl equal?
            numberClassifiedCorrectly++;
            // cout << label_object_to_classify << endl;
            // cout << nearest_neighbor_label << endl;
            // cout << "made it in here" << endl;
        }

    }
    float finalAccuracy = numberClassifiedCorrectly / numOfLinesInFile;
    // cout << "number classified correctly: " << numberClassifiedCorrectly << endl;
    // cout << "num Lines in file: " <<  numOfLinesInFile << endl;
    finalBestAccuracy = finalAccuracy;
    return finalAccuracy;
}

int searchData() {
    //int current_set_of_features [numCOlumnElements+1]; //can have max 10 elements 
    for(int i = 0; i < numOfLinesInFile; i++) {
        //cout << "On the " << i << "th level of the tree" << endl;
        currBestAccuracy = 0;
        int feature_to_add; //only adding 1 feature at a time
        for(int j = 0; j < numCOlumnElements; j++) { //was num of lines in file
            //current_set_of_features[i]
            // if(checkReccuring(currNode, reccuringStates) == 1) { //he uses an intersect function here but im not 100% sure what that does
            //     //do nothing I think 
            // }
            // else {
                //cout << "--- Considering adding the " << j << "th feature" << endl;
                float iHateTHis = getAccuracy(j);
                if(iHateTHis > currBestAccuracy) { //struggling to go into this if check
                    //cout << "testing" << endl;
                    currBestAccuracy = iHateTHis;
                    feature_to_add = j;
                }
            //}
        }
        //current_set_of_features[i] = feature_to_add;
        //cout << "On the " << i << "th level we added feature " << feature_to_add << " to the current set" << endl;
    }
    cout << "why am i throwig an abort error here?" << endl; //solved and it was cuz array out of range
    return 0;
}

int main() {
    //open the txt file here prob using fstream
    //the size of the array i need is based on how many levels are in the tree
    string s;
    float sTotal = 0;
    int choice;
    ifstream in;
    cout << "Welcome to my Feature Selection Alforithm :) " << endl;
    // cout << "Enter the number 1 if you want to use the small data set and 2 if you want to use the large data set" << endl;
    // cin >> choice;
    // if(choice == 1) {
    //     in.open("CS170_SMALLtestdata__66.txt");
    //     while(!in.eof()) {
    //         getline(in, s);
    //         sTotal ++;	
    //     }
    //     ifstream file("CS170_SMALLtestdata__66.txt");
    //     string str; 
    //     int linenum = 0;
    //     while (getline(file, str)) {
    //         linenum++;
    //         createArray(str);      
    //     }
    // }
    // else{
    //     in.open("CS170_largetestdata__77.txt");
    //     while(!in.eof()) {
    //         getline(in, s);
    //         sTotal ++;	
    //     }
    //     ifstream file("CS170_largetestdata__77.txt");
    //     string str; 
    //     int linenum = 0;
    //     while (getline(file, str)) {
    //         linenum++;
    //         createArray(str);      
    //     }
    // }
    in.open("CS170_SMALLtestdata__66.txt");
    while(!in.eof()) {
        getline(in, s);
        sTotal ++;	
    }
    ifstream file("CS170_SMALLtestdata__66.txt");
    string str; 
    int linenum = 0;
    while (getline(file, str)) {
        linenum++;
        createArray(str);      
    }
    numOfLinesInFile = sTotal;
    cout << "total num of lines in file: " << numOfLinesInFile << endl;
    
    searchData();
    cout <<"do i get here?" << endl;
    cout << "best found accuracy is: "<< finalBestAccuracy << endl;
    return 0;
}
//for gettung num of lines in a txt file: http://www.cplusplus.com/forum/beginner/151963/
//for 2d arrays: https://www.geeksforgeeks.org/multidimensional-arrays-c-cpp/
//how to read a txt file usung fstream: https://www.cplusplus.com/forum/beginner/8388/
// https://www.geeksforgeeks.org/split-a-sentence-into-words-in-cpp/ for how to split string up
