// ONP.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include <iostream>
#include <stack>
#include <string>
#include <fstream>
#include <cstdio>
#include <stdio.h>

using namespace std;

string word;
stack < char > s1;

short int selectPriority(char znak) {
	if (znak == '=') return 0;
	else if (znak == '<' || znak == '>') return 1;
	else if (znak == '+' || znak == '-') return 2;
	else if (znak == '*' || znak == '/' || znak == '%') return 3;
	else if (znak == '^') return 4;
	else if (znak == '~') return 5;
}

void isAlfanum(char znak){
	if (isalnum(znak))
		word += znak;
	else if (s1.empty() || selectPriority(znak) > selectPriority(s1.top())) {
		s1.push(znak);
	}
	else if (selectPriority(znak) <= selectPriority(s1.top())) {
		word += s1.top();
		s1.pop();
		s1.push(znak);
	}
}

void onpInf(char znak) {
	if (isalnum(znak))
		s1.push(znak);
	else if (!isalnum(znak)) {
		word += s1.top();
		s1.pop();
		word += znak;
		word += s1.top();
		s1.pop();
	}
}

bool loadFile(string fileName) {
	string isInfOnp;
	int fileLength;
	char *loadedChars = new char[256]();
	FILE* inFile;
	inFile = fopen(fileName, "r");
	string out = "out.txt";
	FILE* outFile;
	outFile = fopen(out, "a");
	inFile >> fileLength;
	for (int i = 0; i < fileLength; i++) {
		fgets(isInfOnp, 5, inFile);
		fgets(loadedChars, 256, inFile);
		if (isInfOnp == "INF: ") {
			for (int i = 0; i < 256 || loadedChars[i] == 0; i++)
				isAlfanum(loadedChars[i]);
			for (int i = 0; i < s1.size(); i++) {
				word += s1.top();
				s1.pop();
			}
			memset(loadedChars, 0, 256 * sizeof(char));
			outFile << word;
			word.clear();
		}
		else if (isInfOnp == "ONP: ") {
			for (int i = 0; i < 256 || loadedChars[i] == 0; i++)
				onpInf(loadedChars[i]);
			memset(loadedChars, 0, 256 * sizeof(char));
			outFile << word;
			word.clear();
		}
	}
}

int main()
{
	loadFile("in.txt");

	system("PAUSE");
    return 0;
}

