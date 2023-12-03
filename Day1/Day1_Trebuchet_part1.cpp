#include <iostream>
#include <fstream>
#include <vector>
#include <istream>
#include <string>
#include <unordered_map>
#include <sstream>
using namespace std;

int processString(string& str) {
    char start, final = 0;
    for (char& c : str) {
        if (isdigit(c)) {
            if (start == 0) {
                start = int(c) - 48;
            }
            final = int(c) - 48;
        }
    }
    int sum = (start*10) + final;
    return sum;
}

int main() {
    string inputFileName = "trebuchet.txt";
    ifstream inputFile(inputFileName);
    if (!inputFile.is_open()) {
        cerr << "Error opening file: " << inputFileName << endl;
        return 1;
    }
    vector<string> strings;

    string line;
    while (getline(inputFile, line)) {
        strings.push_back(line);
    }

    inputFile.close();
    int sum = 0;
    // Process each string (replace with your own functionality)
    for (string& str : strings) {
        sum += processString(str);
    }

    // Display the processed strings
    cout << sum;

    return 0;
}