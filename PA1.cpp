#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
// #include <pthread.h>
using namespace std;

/* 
-line one is the 2 positive integers for the image the length is 27 and the width is 7
-line 2 from position 0 to 10, if you need to print something print with U, from 15 to 25 it is H (based in the range of the x axis)
-line 3 and 4, decode the given problem with the index and the position of the U and H
-0 to 4 is the first 4 values of line 4, so 0 10 15 25, for the 4th line it is n - 1

-recieve the amount of rows and coloums and the input from the STDIN
-

*/
int main() {
    string input = R"(26 7
U 0 10,H 15 25 
0 4 8 12 25 29 33
0 10 15 25 0 10 15 25 0 10 15 25 0 10 15 16 17 18 19 20 21 22 23 24 25 0 10 15 25 1 9 15 25 2 3 4 5 6 7 8 15 25)";
    

    stringstream ss(input);
    string line1;
    getline(ss, line1);
    int width, height;

    stringstream line1_ss(line1);
    line1_ss >> width >> height;
    
    vector<vector<char>> array(height, vector<char>(width, ' '));           // create an empty map to place the letters and characters
    
    for (int i = 0; i < height; i++ ){
        for(int j = 0; j < width; j++){
           cout <<  array[i][j];
        }
        cout << endl;
    }

    // string line2;
    // getline(ss, line2);
    // replace(line2.begin(), line2.end(), ',', ' ');

    // char character_1, character_2;
    // int character_1_min, character_1_max, character_2_min, character_2_max;


    // string line3;
    // getline(ss, line3);

    // cout << line3;

    // string line4;
    // getline(ss, line4);
    // return 0;
}