#include <iostream>
#include <fstream>
#include <cassert>
using namespace std;


void addSpace(ostream& outf, int& spacesNeeded,int& currentLineLength,int myWordLength, int lineLength, int& paragraphFlag);
void addWord(char myWord[], ostream& outf, int& currentLineLength, int& myWordLength, int& spacesNeeded);
int rearrange(int lineLength, istream& inf, ostream& outf);

int main()
{
	const int MAX_FILENAME_LENGTH = 100;
	for (;;)
	{
		cerr << "Enter input file name (or q to quit): ";
		char filename[MAX_FILENAME_LENGTH];
		cin.getline(filename, MAX_FILENAME_LENGTH);
		if (strcmp(filename, "q") == 0)
			break;
		ifstream infile(filename);
		if (!infile)
		{
			cerr << "Cannot open " << filename << "!" << endl;
			continue;
		}
		if (infile == "")
			continue;
		ofstream outfile("results.txt");
		if ( ! outfile )
		{
			cerr << "Error: cannot create results.txt!" << endl;
			continue;
		}
		cerr << "Enter maximum line length: ";
		int len;
		cin >> len;
		cin.ignore(10000, '\n');
		int returnCode = rearrange(len, infile, outfile);
		cerr << "Return code is " << returnCode << endl;
	}
}


int rearrange(int lineLength, istream& inf, ostream& outf)
{
	if (lineLength < 1 ) // lineLength > 400)
		return 2;
	char c = 0, myWord[401] = "";
	int currentLineLength = 0; // i increase this whenever i output a word, or output a space. i reset this whenever i do new paragraph or new line
	int myWordLength = 0; //i increase this as i add characters into the array where i'm storing my word. this will never exceed the lineLength, when it equals the line length then i output what i have so far onto that line, so it fits, then i put the value into "wholeWordLength"
	int spacesNeeded = -1; // i set this after i output a word, it's how many spaces i'm going to need after the word if the word is not the last word on the line
	int paragraphCounter = 0; // iincrease this when i see newlines, i reset it when i see a word
	int flag = 0; //this flag is for determining if i return 1 or return 0
	int paragraphFlag = 0; // i set this whenever i need a new paragraph
	int wholeWordLength = 0; // i only use this if my word is going to go over a line, if this number exceeds the lineLength then i will need to return 0;
	int iHaveText = 0; // i trigger this when i get an input character that is not "isspace" , so i know that i should have some kind of output in my output file 
	int iSpitOutWordsForBreakfast = 0; // this prevents me from starting a paragraph before the first word; it guarnteees the first entry in my output is a non-isspace character



	while(inf.get(c))
	{
		
		char temp[2] = {c, '\0'};
		if (iSpitOutWordsForBreakfast == 1)//makes sure that the i don't start with a paragraph
		{
			if (c == '\n')       //sets the new paragraph flag so that addSpace knows it needs to add a new paragraph before the word
			{
				paragraphCounter++;
				wholeWordLength = 0;
			}
			else if (!isspace(c)) 
			{
				if (paragraphCounter > 1)
				{
					paragraphFlag = 1;
					paragraphCounter = 0;
				}
				else
					paragraphCounter = 0;
			}
			else
				wholeWordLength = 0;
		}

		if (c == '-') //handles all the cases that can occur when i see a '-'
		{
			iHaveText = 1;
			strcat(myWord, temp);
			myWordLength++;
			addSpace(outf, spacesNeeded,currentLineLength,myWordLength,lineLength, paragraphFlag);
			addWord(myWord, outf, currentLineLength, myWordLength, spacesNeeded);
			iSpitOutWordsForBreakfast = 1;
			if (isspace(inf.peek()))
			{
				spacesNeeded = 1;
			}
		}
		else if (!isspace(c)) //if i picked up characters that go into a word, i'm going to add them to my c-string, where it will eventually be sent to the output.
		{
			iHaveText = 1;
			strcat(myWord, temp);
			if (wholeWordLength != 0)//check for words that might be too long for the line and handles them
			{
				wholeWordLength++;
				myWordLength++;
			}
			else
				myWordLength++;

			if (wholeWordLength > lineLength)
			{
				;
				wholeWordLength = 0;
				cerr << "return 1 has been set!" << endl;
				flag = 1;
			}
			else if (myWordLength == lineLength || myWordLength == 400) 
			{
				;
 				wholeWordLength = myWordLength;
				addSpace(outf, spacesNeeded,currentLineLength,myWordLength,lineLength, paragraphFlag);
				;
				addWord(myWord, outf, currentLineLength, myWordLength, spacesNeeded);
				;
				iSpitOutWordsForBreakfast = 1;
			}
		}
		else if (myWord[0] == '\0')
			continue;
		else //time to output
		{
			addSpace(outf, spacesNeeded,currentLineLength,myWordLength,lineLength, paragraphFlag); // the function addSpace adds new paragraph, spaces before words, and newlines, and sets the currentLineLength counter as needed
			addWord(myWord, outf, currentLineLength, myWordLength, spacesNeeded); //this function spits out the word, and resets the array holding the word, and tells how many spaces are needed after the word
			iSpitOutWordsForBreakfast = 1;
		}
	}
	if (myWord[0] != '\0')//deals with the last word i have in the array after i am done getting characters
	{
		addSpace(outf, spacesNeeded,currentLineLength,myWordLength,lineLength, paragraphFlag);
		addWord(myWord, outf, currentLineLength, myWordLength, spacesNeeded);
	}
	if (iHaveText == 1)//the endl at the very end of the file
		outf << endl;
	if (flag == 1)
		return 1;
	
	return 0;
}


void addSpace(ostream& outf, int& spacesNeeded,int& currentLineLength,int myWordLength, int lineLength, int& paragraphFlag)
{
	if (paragraphFlag == 1)//new paragraph
	{
		outf << endl << endl;
		paragraphFlag = 0;
		currentLineLength = 0;
		return;
	}
	if (spacesNeeded == 0)//no spaces before my word; i use this for leaving no spaces before called in 'so-called'
	{
		if ( currentLineLength + myWordLength > lineLength)
		{
			outf << endl;
			currentLineLength = 0;
		}
	}
	else if (spacesNeeded == 1) // normal case of space after a normal word
	{
		cerr << "Also, my line currently has " << currentLineLength << " characters on it, including spaces" << endl;
		
		if (myWordLength == 0)
			return;
		else if (currentLineLength + myWordLength + 1 <= lineLength)
		{
			outf << ' ';
			currentLineLength++;
		}
		else
		{
			outf << endl;
			currentLineLength = 0;
		}

	}
	else if (spacesNeeded == 2) // if there was a . ? ! before the current word i need 2 spaces
	{			
		if (currentLineLength + myWordLength + 2 <= lineLength)
		{
			outf << "  ";
			currentLineLength += 2;
		}
		else
		{
			outf << endl;
			currentLineLength = 0;
		}
	}
	spacesNeeded = 0;
}

void addWord(char myWord[], ostream& outf,int& currentLineLength,int& myWordLength,int& spacesNeeded)
{
	cerr << myWord;
	cerr << endl;
	outf << myWord; 
	//cerr << "myWord[0] is " << myWord[0] << endl;
	if (myWord[strlen(myWord)-1] == '-' || myWord[0] == '\0')
		spacesNeeded = 0;
	else if (myWord [strlen(myWord)-1] == '.' || myWord [strlen(myWord)-1] == '?' || myWord [strlen(myWord)-1] == '!')
		spacesNeeded = 2;
	else
		spacesNeeded = 1;
	cerr << "I am outputting the word \"" << myWord << "\" and I need " << spacesNeeded << " spaces after the word." << endl;
	
	myWord[0] = '\0';
	currentLineLength += myWordLength;
	myWordLength = 0;
}