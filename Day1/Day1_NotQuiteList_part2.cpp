#include <iostream>
#include <fstream>
using namespace std;

int main() {
    string inputFileName = "NotQuiteLisp.txt";
    ifstream inputFile(inputFileName);

    if (!inputFile.is_open()) {
        cerr << "Error opening file: " << inputFileName << endl;
        return 1;
    }

    char ch;
    int floor = 0;
    signed int position = 1;
    // Read one character at a time
    while (inputFile.get(ch)) {
        // Process the character (replace with your own functionality)
        if (ch == '(') {
            floor ++;
        } else {
            floor --;
        }
        if (floor == -1) {
            cout<<position;
            break;
        } 
        position++;
    }

    cout<<floor;
    inputFile.close();

    return 0;
}
