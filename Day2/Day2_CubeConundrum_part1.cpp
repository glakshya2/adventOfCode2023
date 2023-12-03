#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

// Structure to store a single set
struct Set
{
	int redNum;
	int blueNum;
	int greenNum;
};

// Structure to store data for single game
struct Game
{
	vector<Set> sets;
};

string trimString(const string &str)
{
	size_t first = str.find_first_not_of(" \t\n\r");
	size_t last = str.find_last_not_of(" \t\n\r");

	if (first == std::string::npos || last == std::string::npos)
	{
		// The string is empty or contains only whitespaces
		return "";
	}

	return str.substr(first, last - first + 1);
}

Set processToken(string token)
{
	Set currentSet;
	currentSet.blueNum = 0;
	currentSet.greenNum = 0;
	currentSet.redNum = 0;
	string trackNum = "";
	string trackColor = "";
	for (int i = 0; i < token.size(); i++)
	{
		if (token[i] == ',')
		{
			if (trackColor == "red")
			{
				currentSet.redNum = stoi(trackNum);
			}
			if (trackColor == "green")
			{
				currentSet.greenNum = stoi(trackNum);
			}
			if (trackColor == "blue")
			{
				currentSet.blueNum = stoi(trackNum);
			}
			trackNum = "";
			trackColor = "";
			continue;
		}
		if (isdigit(token[i]))
		{
			trackNum += token[i];
		}
		else
		{
			if (token[i] == ' ')
			{
				continue;
			}
			else
			{
				trackColor += token[i];
			}
		}
	}
	if (trackColor == "red")
	{
		currentSet.redNum = stoi(trackNum);
	}
	if (trackColor == "green")
	{
		currentSet.greenNum = stoi(trackNum);
	}
	if (trackColor == "blue")
	{
		currentSet.blueNum = stoi(trackNum);
	}
	return currentSet;
}

// Read data from file
vector<Game> takeInput(string filename)
{

	vector<Game> games;
	ifstream infile(filename);
	string line;

	while (getline(infile, line))
	{
		// Current game
		Game currentGame;
		bool pastGame = false;
		int num = 0;
		string color = "";
		size_t pos = 0;
		string token = "";
		string delimiter = ":";
		while ((pos = line.find(delimiter)) != string::npos)
		{
			token = line.substr(0, pos);
			line.erase(0, pos + delimiter.length());
			cout << token << endl;
			line = trimString(line);
		}
		delimiter = ";";
		pos = 0;
		while ((pos = line.find(delimiter)) != string::npos)
		{
			token = line.substr(0, pos);
			currentGame.sets.push_back(processToken(token));
			line.erase(0, pos + delimiter.length());
		}
		currentGame.sets.push_back(processToken(line));
		games.push_back(currentGame);
	}

	return games;
}

int solve(vector<Game> games) {
	int sum = 0;
	for (int i = 0; i < games.size(); i++) {
		bool possible = true;
		for (int j = 0; j < games[i].sets.size(); j++) {
			if (games[i].sets[j].redNum > 12 || games[i].sets[j].greenNum > 13 || games[i].sets[j].blueNum > 14) {
				possible = false;
			}
		}
		if (possible) {
			sum += i + 1;
		}
	}
	return sum;
}

int main()
{
	vector<Game> games = takeInput("cubeConundrum.txt");
	cout << solve(games);
	return 0;
}