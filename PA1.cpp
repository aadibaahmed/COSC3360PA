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
-0 to 4 is the first 4 values of line 4, so 0 10 15 25, etc

-recieve the amount of rows and coloums and the input from the STDIN
*/
void decode_info(vector<vector<char>>& Map, vector<char>& Letters, vector<int>& Range, vector<int>& head_pos, vector<int>& data_pos){

    int width = Map[0].size();
    for(int row = 0; row < head_pos.size(); row++){
        int head_pos_start = head_pos[row];                                     // starts at 0
        int head_pos_end = head_pos[row+1];                                     // starts at 4
        for(int i  = 0; i < Letters.size(); i++){
            char letter = Letters[i];                                               // Letters are U and H, ranges are 0 - 10, 15- 25
            int beginning = Range[2 * i];                                           // gets the beginning and end vales from the Range vector, 2 * i for the beginning and 2* i +1 to get the end value which is right after.
            int end = Range[2 * i + 1];                                             // gets the end value
            for(int j = head_pos_start; j < head_pos_end; j++){
                int position = data_pos[j];                                   // gets the position of the character
                if(position >= beginning && position <= end){
                    int column = position;
                    Map[row][column] = letter;
                }

            }
        }
    }
}

int main() {
    string input = R"(26 7
U 0 10,H 15 25 
0 4 8 12 25 29 33
0 10 15 25 0 10 15 25 0 10 15 25 0 10 15 16 17 18 19 20 21 22 23 24 25 0 10 15 25 1 9 15 25 2 3 4 5 6 7 8 15 25)";
    

    stringstream ss(input);                                                // Get the height and the width from the first line
    string line1;
    getline(ss, line1);
    int width, height;

    stringstream line1_ss(line1);
    line1_ss >> width >> height;
    
    vector<vector<char>> array(height, vector<char>(width, ' '));          // create an empty map to place the letters and characters

    string line2;                                                          // Parse out the characters and its ranges from line 2
    getline(ss, line2);
    replace(line2.begin(), line2.end(), ',', ' ');                         // replace coma instances with space

    stringstream line2_ss(line2);
    vector<char> Letters;
    vector<int> Range;

    char letter;
    int min,max;
    
    while (line2_ss >> letter >> min >> max) {
        Letters.push_back(letter);
        Range.push_back(min);
        Range.push_back(max);
    }

    string line3;
    getline(ss, line3);

    vector<int> head_pos;
    stringstream line3_ss(line3);

    int num;
    while(line3_ss >> num){
        head_pos.push_back(num);
    }

    string line4;
    getline(ss, line4);
    
    vector<int> data_pos;
    stringstream line4_ss(line4);

    int pos;
    while(line4_ss >> pos){
        data_pos.push_back(pos);
    }

    decode_info(array, Letters, Range, head_pos, data_pos);
    
    for (const auto row : array) {
        for (char c : row) {
            cout << c;
        }    
        cout << endl;
    }
    
    return 0;
}