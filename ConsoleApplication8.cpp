// ConsoleApplication6.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>
#include <iostream>

using namespace std;

int pigLatin(char userInput[50])
{
	char pigLatin[50] = "";
	char firstLetter[2] = "";
	char wordBody[100] = "";
	char ending[3] = "ay";
	int stringLength;
	int i = 0;
	int exit = 0;

	stringLength = strlen(userInput);
	if (stringLength <= 2 || !strcmp(userInput, "an") || !strcmp(userInput, "a") || !strcmp(userInput, "and") || !strcmp(userInput, "but")
		|| !strcmp(userInput, "for") || !strcmp(userInput, "so") || !strcmp(userInput, "nor") || !strcmp(userInput, "the") || !strcmp(userInput, "yet")
		|| !strcmp(userInput, "or"))
	{
		strcpy_s(pigLatin, userInput);
		cout << "Your text in pig latin is: " << pigLatin << endl;
	}
	//if letter starts with vowel
	else if (userInput[0] == 'a' || userInput[0] == 'e' || userInput[0] == 'i' || userInput[0] == 'o' || userInput[0] == 'u' || userInput[0] == 'y')
	{
		strcat_s(pigLatin, userInput);
		strcat_s(pigLatin, ending);
		cout << "Your text in pig latin is: " << pigLatin << endl;
	}
	else if (userInput[0] == '0' || userInput[0] == '1' || userInput[0] == '2' || userInput[0] == '3' || userInput[0] == '4' || userInput[0] == '5'
		|| userInput[0] == '6' || userInput[0] == '7' || userInput[0] == '8' || userInput[0] == '9')
	{
		exit = exit - 1;
		cout << "error" << endl;
	}
	else {
		firstLetter[0] = userInput[0];
		while (i <= stringLength)
		{
			wordBody[i] = userInput[i + 1];
			i++;
		}
		strcat_s(pigLatin, wordBody);
		strcat_s(pigLatin, firstLetter);
		strcat_s(pigLatin, ending);
		cout << "Your word in pig latin is: " << pigLatin << endl;
	}


	return exit;
}

int main()
{
	char newInput[50] = "";
	int end = 0;
	cout << "Enter a word that you want to translate into Pig Latin" << endl;
	gets_s(newInput);
	while (strcmp(newInput, "quit") || end <= 0) {
		end = pigLatin(newInput);
		cout << "Please enter text" << endl;
		gets_s(newInput);
	}



	return 0;
}
