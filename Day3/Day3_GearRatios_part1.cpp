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

string findLine(string fileName, int lineNum) {
	ifstream infile(fileName);
	string line = "";
	int i = 0;
	while (getline(infile, line)) {
		if (i == lineNum) {
			return line;
		}
		i++;
	}
	return "";
}

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
				if (!trackingNum) {
					trackingNum = true;
					startX = x;
				}
				num += line[x];
			}
			if (!iswalnum(line[x])) {
				if (trackingNum) {
					trackingNum = false;
					number numb;
					numb.num = stoi(num);
					numb.startX = startX;
					numb.startY = y;
					numb.endX = x - 1;
					numb.endY = y;
					numberList.push_back(numb);
					num = "";
				}
			}
		}
		y++;
	}
	for (int i = 0; i < numberList.size(); i++) {
		cout << i << "\t" << numberList[i].num << "\t" << numberList[i].startX << "\t" << numberList[i].endX << "\t" << numberList[i].startY << endl;
	}
	for (int i = 0; i < numberList.size(); i++) {
		string line = findLine("input.txt", numberList[i].startY);
		if (numberList[i].startX > 0) {
			if (!iswalnum(line[numberList[i].startX - 1]) && line[numberList[i].startX - 1] != '.') {
				numberList[i].adjacentX.push_back(numberList[i].startX - 1);
				numberList[i].adjacentY.push_back(numberList[i].startY);
			}
			if (numberList[i].startY > 0) {
				string upperLine = findLine("input.txt", numberList[i].startY - 1);
				if (!iswalnum(upperLine[numberList[i].startX - 1]) && upperLine[numberList[i].startX - 1] != '.') {
					numberList[i].adjacentX.push_back(numberList[i].startX - 1);
					numberList[i].adjacentY.push_back(numberList[i].startY - 1);
				}
			}
			if (numberList[i].startY < 139) {
				string lowerLine = findLine("input.txt", numberList[i].startY + 1);
				if (!iswalnum(lowerLine[numberList[i].startX - 1]) && lowerLine[numberList[i].startX - 1] != '.') {
					numberList[i].adjacentX.push_back(numberList[i].startX - 1);
					numberList[i].adjacentY.push_back(numberList[i].startY + 1);
				}
			}
		}
		if (numberList[i].endX < line.size()) {
			if (!iswalnum(line[numberList[i].endX + 1]) && line[numberList[i].endX + 1] != '.'){
				numberList[i].adjacentX.push_back(numberList[i].endX + 1);
				numberList[i].adjacentY.push_back(numberList[i].startY);
			}
			if (numberList[i].startY > 0) {
				string upperLine = findLine("input.txt", numberList[i].startY - 1);
				if (!iswalnum(upperLine[numberList[i].endX + 1]) && upperLine[numberList[i].endX + 1] != '.') {
					numberList[i].adjacentX.push_back(numberList[i].endX + 1);
					numberList[i].adjacentY.push_back(numberList[i].startY - 1);
				}
			}
			if (numberList[i].startY < 139) {
				string lowerLine = findLine("input.txt", numberList[i].startY + 1);
				if (!iswalnum(lowerLine[numberList[i].endX + 1]) && lowerLine[numberList[i].endX + 1] != '.') {
					numberList[i].adjacentX.push_back(numberList[i].endX +1);
					numberList[i].adjacentY.push_back(numberList[i].startY + 1);
				}
			}
		}
		for (int j = 0; j < numberList[i].endX - numberList[i].startX + 1; j++) {
			if (numberList[i].startY > 0) {
				string upperLine = findLine("input.txt", numberList[i].startY - 1);
				if(!iswalnum(upperLine[numberList[i].startX + j]) && upperLine[numberList[i].startX + j] != '.') {
					numberList[i].adjacentX.push_back(numberList[i].startX + j);
					numberList[i].adjacentY.push_back(numberList[i].startY - 1);
				} 
			}
			if (numberList[i].startY < 139) {
				string lowerLine = findLine("input.txt", numberList[i].startY + 1);
				if(!iswalnum(lowerLine[numberList[i].startX + j]) && lowerLine[numberList[i].startX + j] != '.') {
					numberList[i].adjacentX.push_back(numberList[i].startX + j);
					numberList[i].adjacentY.push_back(numberList[i].startY + 1);
				} 
			}
		}
	}
	int sum = 0;
	for (int i = 0; i < numberList.size(); i++) {
		if (numberList[i].adjacentX.size() > 0) {
			sum += numberList[i].num;
			cout << i << "\t" << sum << "\t" << numberList[i].num << endl; 
		}
	}
	cout << sum;
	return 0;
}