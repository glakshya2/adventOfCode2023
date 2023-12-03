#include <iostream>
#include <fstream>
#include <vector>
#include <istream>
#include <string>
#include <unordered_map>
#include <sstream>
using namespace std;

struct
{
    string str;
    int num;
} keyPair[10];

int match(string &str, int n)
{
    for (int i = 0; i <= 9; i++)
    {
        if (str.length() - n < keyPair[i].str.length())
        {
            continue;
        }
        for (int j = 0; j < keyPair[i].str.length(); j++)
        {
            if (str[n + j] != keyPair[i].str[j])
            {
                break;
            }
            if (j == keyPair[i].str.length() - 1)
            {
                return keyPair[i].num;
            }
        }
    }
    return -1;
}

vector<int> findNum(string &str)
{
    vector<int> nums;
    for (int i = 0; i < str.length(); i++)
    {
        if (isdigit(str[i]))
        {
            nums.push_back(int(str[i]) - 48);
        }
        else
        {
            int check = match(str, i);
            if (check != -1)
            {
                nums.push_back(check);
            }
        }
    }
    return nums;
}

int processString(string &str)
{
    vector<int> nums = findNum(str);
    if (nums.size() == 0)
    {
        return 0;
    }
    int start = nums[0] * 10;
    int end = nums[nums.size() - 1];
    int sum = start + end;
    return sum;
}

int main()
{
    keyPair[0].num = 0;
    keyPair[0].str = "zero";
    keyPair[1].num = 1;
    keyPair[1].str = "one";
    keyPair[2].num = 2;
    keyPair[2].str = "two";
    keyPair[3].num = 3;
    keyPair[3].str = "three";
    keyPair[4].num = 4;
    keyPair[4].str = "four";
    keyPair[5].num = 5;
    keyPair[5].str = "five";
    keyPair[6].num = 6;
    keyPair[6].str = "six";
    keyPair[7].num = 7;
    keyPair[7].str = "seven";
    keyPair[8].num = 8;
    keyPair[8].str = "eight";
    keyPair[9].num = 9;
    keyPair[9].str = "nine";
    string inputFileName = "trebuchet.txt";
    ifstream inputFile(inputFileName);
    if (!inputFile.is_open())
    {
        cerr << "Error opening file: " << inputFileName << endl;
        return 1;
    }
    vector<string> strings;

    string line;
    while (getline(inputFile, line))
    {
        strings.push_back(line);
    }

    inputFile.close();
    int sum = 0;
    // Process each string (replace with your own functionality)
    for (string &str : strings)
    {
        sum += processString(str);
    }

    // Display the processed strings
    cout << sum;

    return 0;
}