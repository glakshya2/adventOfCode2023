#include <iostream> 
#include <string>
using namespace std;

string replaceWordsWithNumbers(string input) {
  string numbers[] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"}; 
  string numString;
  string result;
  
  for(int i=0; i<input.length(); i++) {
    if(isdigit(input[i])) {
      numString += input[i];
    }
    else {
      if(numString.length() > 0) {
        int num = stoi(numString);
        result += to_string(num);
        numString = "";  
      }
      result += input[i]; 
    }
  }
  
  return result;
}

int main() {
  string input = "onedvfdhvd";
  string output = replaceWordsWithNumbers(input);

  cout << "Input string: " << input << endl;
  cout << "Output string: " << output;
  
  return 0;
}