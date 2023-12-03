#include <iostream>
#include <fstream>
using namespace std;

int main() {
    string inputFileName;
    cout << "Enter the input text file name: ";
    cin >> inputFileName;

    ifstream inputFile(inputFileName);

    if (!inputFile.is_open()) {
        cerr << "Error opening file: " << inputFileName << endl;
        return 1;
    }

    char ch;
    int floor = 0;
    // Read one character at a time
    while (inputFile.get(ch)) {
        // Process the character (replace with your own functionality)
        if (ch == '(') {
            floor ++;
        } else {
            floor --;
        }
    }

    cout<<floor;
    inputFile.close();

    return 0;
}
