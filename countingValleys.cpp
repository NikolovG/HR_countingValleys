// Counting Valleys Coding Challange (C++)
// Credits : HackerRank
// Author  : pkacprzak 
//
// Solved on: Sep 25, 2021
// Solved by: Georgi Nikolov
//
// OBJECTIVE: A mountain is a sequence of consecutive steps above sea level,
// starting with a step up from sea level and ending with a step down to sea 
// level. A valley is a sequence of consecutive steps below sea level, 
// starting with a step down from sea level and ending with a step up to sea
// level. Given the sequence of up and down steps during a hike, find and 
// print the number of valleys walked through.

#include<iostream>

using namespace std;



int countingValleys(int steps, string path) {
    int index = 0, seaLevel = 0, valley = 0;
    bool belowSea = false;  // We are currently at 0 or at sea level

    while(steps >= 0) {  // While loop to go through steps 

        // Counting valleys if & only if the previous numbers were negative
        // and we are back at sea level
        if ((seaLevel == 0) && (belowSea == true)) {
            valley++;  
        }
        
        if (path[index] == 'U') {  
            seaLevel++;  // Keep track of sea level
            cout << "SeaLevel : " << seaLevel << " : U " << endl;
        }
        if (path[index] == 'D') {
            seaLevel--;  // Keep track of sea level
            cout << "SeaLevel : " << seaLevel << " : D " << endl;
        }
        
        if(seaLevel < 0){  // Need to know if we made it below sea level
            belowSea = true;
        }
        if(seaLevel > 0){
            belowSea = false;
        }

        steps--;
        index++;
    }
    
    return valley;  // Returing # of valleys
}



int main() {
    int steps = 12;
    string path = "DDUUDDUDUUUD";

    // NOTE: Uncomment for custom testing
    // cout<<"Steps : ";
    // cin>>steps;

    // cout<<"Path : ";
    // cin>>path;

    int valley = countingValleys(steps, path);
    cout<<"\nValleys: "<<valley<<endl;

    return 0;
}