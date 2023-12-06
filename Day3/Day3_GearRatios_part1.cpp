#include <iostream>
#include <vector>
#include <fstream>
#include <string>
using namespace std;


struct number {
	int num;
	int startX;
	int startY;
	int endX;
	int endY;
	vector<int> adjacentX;
	vector<int> adjacentY;
};

int main(void) {
	vector<number> numberList;
	ifstream infile("input.txt");
	string line;
	int y = 0;
	while (getline(infile, line)) {
		bool trackingNum = false;
		string num = "";
		int startX = 0;
		for (int x = 0; x < line.size(); x++) {
			if (isdigit(line[x])) {
				
			}
		}
		y++;
	}
}