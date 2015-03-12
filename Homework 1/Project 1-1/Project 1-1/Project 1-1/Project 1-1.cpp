// Homework 1.cpp : Problem 1 - Paragraph counter
//Author: Kevin Hwang   
//ID: 911144369
//Due: 9-11-2014


#include <iostream>
#include <string>
#include <iomanip>


using namespace std;


string getFreqLetter(string text)
{
	int max = 0;
	int count = 0;
	string maxLetter;

	//Rotation of all the letters
	for (char q = 'A'; q <= 'z'; q == 'Z' ? q = 'a' : ++q)
	{
		count = 0;

		//loop for the entire paragraph, next letter......next letter......
		for (int i = 0; i < text.length(); i++)
		{
			if (text[i] == q)
				count++;
		}

		//if count is bigger then max, then maxLetter = current letter
		if (count > max)
		{
			max = count;
			maxLetter = q;

			if (count == max)
				maxLetter = q;



		}
	}
	return maxLetter;
}

struct wordCnt
{
	string word;
	int count;
};

void wordCounter(string text)
{
	wordCnt wordFreq[100];
	//set everything to zero.
	for (int i = 0; i < 100; i++)
	{
		wordFreq[i].word = "";
		wordFreq[i].count = 0;
	}
	int maxWord = 0;
	int list = 0;
	string temp = "";
	bool check = true;

	//going through every char in the total paragraph
	for (int i = 0; i <= text.length(); i++)
	{
		//meet the word delimiter and put word into the struct array.
		if (text[i] == ' ' || text[i] == '.' || text[i] == ',' || text[i] == ';' || text[i] == '!' || text[i] == '?' || i == text.length())
		{
			//find if the word exist
			for (int w = 0; w <= list; w++)
			{
				//compare the word in temp to the list of word(If non exist add word add count, if word exist add count).
				if (temp.compare(wordFreq[w].word) == 0)
				{
					wordFreq[w].count++;
					temp.clear();
					check = true;
					break;
				}
				else
					check = false;
			}

			if (check == false)
			{
				wordFreq[list].word = temp;
				wordFreq[list].count++;
				list++;
				temp.clear();
			}
		}

		//If no delimitor exist, continue construct the current word
		else
			temp += text[i];
	}
	//Read through the list and display all unique word with it's count.
	for (int i = 0; i < list; i++)
	{
		cout << wordFreq[i].word << setw(15 - wordFreq[i].word.length()) << right << wordFreq[i].count << endl;
	}
	cout << "-----------------------------------" << endl;
		
}


int main()
{
	string sample;
	string answer;
	string input;
	bool repeat = true;

	while (repeat == true)
	{
		cout << "Type in your string" << endl;
		getline(cin,sample);	

		cout << "1. Display the most frequent letter" << endl;
		cout << "2. Display the list of unique word and it's count" << endl;
		getline(cin, input);

		//display the most frequent letter.
		if (input == "1")
		{
			
			cout << "your most frequent letter is " << getFreqLetter(sample) << endl;

			cout << "would you like to try again?(yes/no)";
			getline(cin, answer);

			if (answer == "yes" || "y" || "Y")
				repeat = true;
			else
				repeat = false;

		}
		
		//display the most frequent letter.
		if (input == "2")
		{ 
			cout << "Here is the unique words for this paragraph" <<endl << endl;
			wordCounter(sample);
			cout << "would you like to try again?(yes/no)";
			getline(cin, answer);

			if (answer == "yes" || answer == "y" || answer == "Y")
				repeat = true;
			else
				repeat = false;
		}
	}

	system("pause");

	return 0;
}


