#include <iostream>
#include <string>
#include <cassert>
using namespace std;

bool isTuneWellFormed(string tune);
bool isPlayable(string& tune, int& badBeat);
char translateNote(int octave, char noteLetter, char accidentalSign);
bool processNote(int& octave, int& k, string& tune, string& convertedTune);
string convertTune(string& tune);
int translateTune(string tune, string& instructions, int& badBeat);

int main()
{
	string tune;
	string instructions;
	int badBeat = 0;

	do
	{
		cerr << "Please Enter your Tune!: ";
		getline(cin, tune);

		//allows program to close
		if (tune == "exit" || tune == "EXIT")
		{
			return 0;
		}		
		//pass or fail, with information
		if (1==1)
		{
			if (translateTune(tune, instructions, badBeat) == 0)
			{
				cerr << "Size: " << tune.size() << endl;
				cerr << "Translation:" << endl << instructions << "ZZZ" << endl;
			}
			else if (translateTune(tune, instructions, badBeat) == 1)
			{
				cerr << "so sorry, the tune is not well formed" << endl << endl;
			}
			else if (translateTune(tune, instructions, badBeat) == 2)
			{
				cerr << "YOU MADE A MISTAKE, MY GOOD FELLOW. PLEASE CHECK BEAT NUMBER: " << badBeat << endl << endl;
			}
		}
	}
	while(1==1);
}

bool isTuneWellFormed(string tune) 
{
	//if there are no beats at all, the tune is well formed
	if (tune == "")
	{
		return 1;
	}
	
	//the first condition is that only certain characters are allowed to even exist in the string:
	//A B C D E F G # b 1 2 3 4 5 6 0 7 8 9 /
	//this first if statment says that, if the character is not A and ITS not B and its not C and so on and so forth etc, then it fails.
	//the for loop will check each character of the string
	for (int k = 0; k != tune.size(); k++)
	{
		if (tune[k] != 'A' && tune[k] != 'B' && tune[k] != 'C' && tune [k] != 'D' && tune [k] != 'E' && tune [k] != 'F' && tune [k] != 'G' && tune [k] != '#' && tune [k] != 'b' && tune [k] != '/' && tune [k] != '1' && tune [k] != '2' && tune [k] != '3' && tune [k] != '4' && tune [k] != '5' && tune [k] != '6' && tune [k] != '7' && tune [k] != '8' && tune [k] != '9' && tune [k] != '0' && tune [k] != '/')
		{
			return 0;
		}
	}

	//if the first element is not a letter or a / then it's not playable
	if (tune[0] != 'A' && tune[0] != 'B' && tune[0] != 'C' && tune [0] != 'D' && tune [0] != 'E' && tune [0] != 'F' && tune [0] != 'G' && tune [0] != '/')
	{
		return 0;
	}

	//we have 4 types of characters in the code - letters, numbers, slashes, and accent marks
	
	//SLASHES

	//BEFORE A SLASH
	//you can have a letter, such as A/
	//you can have a accent mark, such as Ab/
	//you can have a number, such as A3/
	//you can have a slash, such as //
	//no matter what you have before a slash, it's okay, so there's no particular fail condition associated with the chracter before a slash

	//AFTER A SLASH, 
	//you can have a letter, such as A/A
	//you can NOT have an accent mark, A/3 does not make sense
	//you can NOT have a number, because A/3 does not make sense
	//you can have another slash //
	//so it should fail if the next character after a slash is not a letter or a slash
	//this bit of code checks all the characters up until the second to last character
	for (int k = 0; k != (tune.size()-1); k++)
	{	
		if (tune [k] == '/')
		{			
			if (tune[(k+1)] != 'A' && tune[(k+1)] != 'B' && tune[(k+1)] != 'C' && tune [(k+1)] != 'D' && tune [(k+1)] != 'E' && tune [(k+1)] != 'F' && tune [(k+1)] != 'G' && tune[(k+1)] != '/' && tune[(k+1)] != '/n')
			{
				return 0;
			}
		}
	}
	

	//NUMBERS

	//BEFORE A NUMBER
	//you can have a letter before a number, such as A4
	//you can have a accent mark, such as Ab4
	//you can NOT have a number, such as 44
	//you can NOT have a slash, such as /4
	//this code looks to see if there is a number, if the character before a number is == to a number, or a slash, then there is failure

	for (int k = 1; k != tune.size(); k++)
	{
		if (tune[k] == '1' || tune[k] == '2' || tune[k] == '3' || tune [k] == '4' || tune [k] == '5' || tune [k] == '6'|| tune[k] == '7' || tune[k] == '8' || tune[k] == '9' || tune[k] == '0')
		{
			if (tune[(k-1)] == '/' || tune[(k-1)] == '1' || tune[(k-1)] == '2' || tune[(k-1)] == '3' || tune[(k-1)] == '4' || tune[(k-1)] == '6' || tune[(k-1)] == '7'|| tune[(k-1)] == '8'|| tune[(k-1)] == '9'|| tune[(k-1)] == '0')
			{
				return 0;
			}
		}
	}
	
	//AFTER A NUMBER
	//you can have a letter, as in A4C
	//you can NOT have an accent mark, as in A4b
	//you can NOT have a number, as in A44
	//you can have a slash, such as A4/
	//this code looks to see if there is a number, if the character after a number is == to a number, or a accent mark, then there is failure

	for (int k = 0; k != (tune.size()-1); k++)
	{	
		if (tune [k] == '1' || tune [k] == '2' || tune [k] == '3' || tune [k] == '4' || tune [k] == '5' || tune [k] == '6' ||tune [k] == '7' || tune [k] == '8' || tune [k] == '9' || tune [k] == '0')
		{
			if (tune[(k+1)] == 'b' || tune[(k+1)] == '#' || tune [(k+1)] == '1' || tune [(k+1)] == '2' || tune [(k+1)] == '3' || tune [(k+1)] == '4' || tune [(k+1)] == '5' || tune [(k+1)] == '6' || tune [(k+1)] == '7' || tune [(k+1)] == '8' || tune [(k+1)] == '9' || tune [(k+1)] == '0')
			{
				return 0;
			}			
		}
	}

	//ACCENT MARKS

	//BEFORE ACCENT MARKS
	//you can have a letter, such as Ab or A#
	//you can NOT have an accent mark, such as Abb or Ab#
	//you can NOT have a number, such as A4b or A4#
	//you can NOT have a slash, such as /b or /#
	//this code looks to see if there is an accent mark, if the character before it is NOT equal to a letter, then it fails
	
	for (int k = 1; k != tune.size(); k++)
	{
		if (tune[k] == 'b' || tune[k] == '#')
		{
			if (!(tune[(k-1)] == 'A' || tune[(k-1)] == 'B' || tune[(k-1)] == 'C' || tune[(k-1)] == 'D' || tune[(k-1)] == 'E' || tune[(k-1)] == 'F' || tune[(k-1)] == 'G'))
			{
				return 0;
			}
		}
	}

	//AFTER ACCENT MARKS
	//you can have a letter, such as AbC or A#C
	//you can NOT have an accent mark, such as Abb or Ab#
	//you can have a number, such as Ab3 or A#5
	//you can have a slash, such as Ab/ or a/
	//this code looks to see if there is an accent mark, if the character AFTER it is equal to another accent mark, then it fails

	for (int k = 1; k != tune.size(); k++)
	{
		if (tune[k] == 'b' || tune[k] == '#')
		{
			if (tune[(k+1)] == 'b' || tune[(k+1)] == '#')
			{
				return 0;
			}
		}
	}


	//LETTERS

	//BEFORE A LETTER
	//you can have a letter, such as AB
	//you can have a accent mark, such as AbA
	//you can have a number, such as A3A
	//you can have a slash, such as A/A
	//no matter what you have before a letter, it's okay, so there's no particular fail condition associated with the chracter before a letter

	//AFTER A LETTER
	//you can have a letter, such as AB
	//you can have a accent mark, such as Ab
	//you can have a number, such as A3
	//you can have a slash, such as A/
	//no matter what you have after a letter, it's okay, so there's no particular fail condition associated with the chracter before a letter

	//THIS LINE OF CODE SAYS THAT THE STRING IS NOT WELL FORMED UNLESS THE FINAL ENTRY IS A /
	int finalEntry = tune.size();
	if (tune[(finalEntry-1)] != '/')
	{
		return 0;
	}
	
	//IF THE STRING SURVIVES ALL THESE TESTS, IT PASSES!!!!!!!!!
	return 1;	
}
bool isPlayable(string& tune, int& badBeat)
{
	/*we have the variable tune, badBeat, we also need a variable beat and a variable k */
	int beat = 1; //we start with the first beat
	//if it's not well formed, it should also not be playable
	if (!isTuneWellFormed(tune))
	{
		return 0;
	}
	if(tune=="")
	{
		return 1;
	}
	//examine entry by entry
	for (int k = 0; k != tune.size(); k++)
	{
		//every time we see a slash, we know we are in a new beat
		if (tune[k]=='/')
		{
			beat++;
		}
		//these digits are no good
		if(tune[k] == '0' || tune[k] == '7' || tune[k] == '8' || tune[k] == '9')
		{
			badBeat = beat;
			return 0;
		}
		//Cb2 is not playable
		if(tune[k]=='2')
		{
			if(tune[(k-1)]== 'b' && tune[(k-2)]== 'C' )
			{
				badBeat = beat;
				return 0;
			}
		}
		//C6 and Cb6 == B5 are playable
		if(tune[k]=='6')
		{
			if(tune[(k-1)] == 'C')
			{
				continue;
			}
			if(tune[(k-1)]== 'b' && tune[(k-2)]== 'C' )
			{
				tune.erase(k, 1);
				tune[(k-1)] = '5';
				tune[(k-2)] = 'B';
				continue;
			}
		}
		//the lowest playable key is B#1 == C2, so before the 1 must always be "B#"
		if(tune[k]=='1')
		{
			if(tune[(k-1)] != '#')
			{
				badBeat = beat;
				return 0;
			}
			if(tune[(k-2)] != 'B' )
			{
				badBeat = beat;
				return 0;
			}
			tune.erase(k, 1);
			tune[(k-1)] = '2';
			tune[(k-2)] = 'C';
		}
		if(tune[k] == '6')
		{
			badBeat = beat;
			return 0;
		}
	}
	return 1;
}
char translateNote(int octave, char noteLetter, char accidentalSign)
{
      // This check is here solely to report a common CS 31 student error.
    if (octave > 9)
    {
        cerr << "********** translateNote was called with first argument = "
             << octave << endl;
    }

      // Convert Cb, C, C#/Db, D, D#/Eb, ..., B, B# to
      //         -1, 0,   1,   2,   3, ...,  11, 12

    int note;
    switch (noteLetter)
    {
      case 'C':  note =  0; break;
      case 'D':  note =  2; break;
      case 'E':  note =  4; break;
      case 'F':  note =  5; break;
      case 'G':  note =  7; break;
      case 'A':  note =  9; break;
      case 'B':  note = 11; break;
      default:   return ' ';
    }
    switch (accidentalSign)
    {
      case '#':  note++; break;
      case 'b':  note--; break;
      case ' ':  break;
      default:   return ' ';
    }

      // Convert ..., A#1, B1, C2, C#2, D2, ... to
      //         ..., -2,  -1, 0,   1,  2, ...

    int sequenceNumber = 12 * (octave - 2) + note;

    string keymap = "Z1X2CV3B4N5M,6.7/A8S9D0FG!H@JK#L$Q%WE^R&TY*U(I)OP";
    if (sequenceNumber < 0  ||  sequenceNumber >= keymap.size())
        return ' ';
    return keymap[sequenceNumber];
}
bool processNote(int& octave, int& k, string& tune, string& convertedTune)
{
	if(tune[k] == 'A')
		{
			if(tune[(k+1)]=='A' || tune[(k+1)]=='B'|| tune[(k+1)]=='C'|| tune[(k+1)]=='D'|| tune[(k+1)]=='E'|| tune[(k+1)]=='F'|| tune[(k+1)]=='G')//if after A is any letter, the note A refers to "A"
			{
				convertedTune += translateNote(octave, 'A', ' ');
			}
			if(tune[(k+1)]=='/')//if after A is a slash, then note A refers to "A"
			{
				convertedTune += translateNote(octave, 'A', ' ');
			}
			if(isdigit(tune[(k+1)]))//if after A as a number N, then note A refers to "A(N)" where N is the octave  A6
			{
				octave = tune[(k+1)] - '0';
				convertedTune += translateNote(octave, 'A', ' ');
			}
			if(tune[(k+1)]=='b')// if after A is a 'b', check what's next
			{
				if(tune[(k+2)]=='2' || tune[(k+2)]=='3'|| tune[(k+2)]=='4'||tune[(k+2)]=='5') //any number
				{
					octave = tune[(k+2)] - '0';
					convertedTune += translateNote(octave, 'A', 'b');
				}
				else//if there is no number after the 'b', then A refers to "Ab" in the 4th octave
				{
					convertedTune += translateNote(octave, 'A', 'b');
				}
			}
			if(tune[(k+1)]=='#')// if after A is '#', check what's after '#'
			{
				if(tune[(k+2)]=='2' || tune[(k+2)]=='3'|| tune[(k+2)]=='4'||tune[(k+2)]=='5'|| tune[(k+2)]=='6')//any number
				{
					octave = tune[(k+2)] - '0';
					convertedTune += translateNote(octave, 'A', '#');
				}
				else//if there is not a number after '#', then A refers to "A#" in the 4th octave
				{
					convertedTune += translateNote(octave, 'A', '#');
				}
			}	
		}
		if(tune[k] == 'B')
		{
			if(tune[(k+1)]=='A' || tune[(k+1)]=='B'|| tune[(k+1)]=='C'|| tune[(k+1)]=='D'|| tune[(k+1)]=='E'|| tune[(k+1)]=='F'|| tune[(k+1)]=='G')//if after A is any letter, the note A refers to "A"
			{
				convertedTune += translateNote(octave, 'B', ' ');
			}
			if(tune[(k+1)]=='/')//if after A is a slash, then note A refers to "A"
			{
				convertedTune += translateNote(octave, 'B', ' ');
			}
			if(isdigit(tune[(k+1)]))//if after A as a number N, then note A refers to "A(N)" where N is the octave  A6
			{
				octave = tune[(k+1)] - '0';
				convertedTune += translateNote(octave, 'B', ' ');
			}
			if(tune[(k+1)]=='b')// if after A is a 'b', check what's next
			{
				if(tune[(k+2)]=='2' || tune[(k+2)]=='3'|| tune[(k+2)]=='4'||tune[(k+2)]=='5') //any number
				{
					octave = tune[(k+2)] - '0';
					convertedTune += translateNote(octave, 'B', 'b');
				}
				else//if there is no number after the 'b', then A refers to "Ab" in the 4th octave
				{
					convertedTune += translateNote(octave, 'B', 'b');
				}
			}
			if(tune[(k+1)]=='#')// if after A is '#', check what's after '#'
			{
				if(tune[(k+2)]=='2' || tune[(k+2)]=='3'|| tune[(k+2)]=='4'||tune[(k+2)]=='5'|| tune[(k+2)]=='6')//any number
				{
					octave = tune[(k+2)] - '0';
					convertedTune += translateNote(octave, 'B', '#');
				}
				else//if there is not a number after '#', then A refers to "A#" in the 4th octave
				{
					convertedTune += translateNote(octave, 'B', '#');
				}
			}	
		}
		if(tune[k] == 'C')
		{
			if(tune[(k+1)]=='A' || tune[(k+1)]=='B'|| tune[(k+1)]=='C'|| tune[(k+1)]=='D'|| tune[(k+1)]=='E'|| tune[(k+1)]=='F'|| tune[(k+1)]=='G')//if after A is any letter, the note A refers to "A"
			{
				convertedTune += translateNote(octave, 'C', ' ');
			}
			if(tune[(k+1)]=='/')//if after A is a slash, then note A refers to "A"
			{
				convertedTune += translateNote(octave, 'C', ' ');
			}
			if(isdigit(tune[(k+1)]))//if after A as a number N, then note A refers to "A(N)" where N is the octave  A6
			{
				octave = tune[(k+1)] - '0';
				convertedTune += translateNote(octave, 'C', ' ');
			}
			if(tune[(k+1)]=='b')// if after A is a 'b', check what's next
			{
				if(tune[(k+2)]=='2' || tune[(k+2)]=='3'|| tune[(k+2)]=='4'||tune[(k+2)]=='5') //any number
				{
					octave = tune[(k+2)] - '0';
					convertedTune += translateNote(octave, 'C', 'b');
				}
				else//if there is no number after the 'b', then A refers to "Ab" in the 4th octave
				{
					convertedTune += translateNote(octave, 'C', 'b');
				}
			}
			if(tune[(k+1)]=='#')// if after A is '#', check what's after '#'
			{
				if(tune[(k+2)]=='2' || tune[(k+2)]=='3'|| tune[(k+2)]=='4'||tune[(k+2)]=='5'|| tune[(k+2)]=='6')//any number
				{
					octave = tune[(k+2)] - '0';
					convertedTune += translateNote(octave, 'C', '#');
				}
				else//if there is not a number after '#', then A refers to "A#" in the 4th octave
				{
					convertedTune += translateNote(octave, 'C', '#');
				}
			}	
		}
		if(tune[k] == 'D')
		{
			if(tune[(k+1)]=='A' || tune[(k+1)]=='B'|| tune[(k+1)]=='C'|| tune[(k+1)]=='D'|| tune[(k+1)]=='E'|| tune[(k+1)]=='F'|| tune[(k+1)]=='G')//if after A is any letter, the note A refers to "A"
			{
				convertedTune += translateNote(octave, 'D', ' ');
			}
			if(tune[(k+1)]=='/')//if after A is a slash, then note A refers to "A"
			{
				convertedTune += translateNote(octave, 'D', ' ');
			}
			if(isdigit(tune[(k+1)]))//if after A as a number N, then note A refers to "A(N)" where N is the octave  A6
			{
				octave = tune[(k+1)] - '0';
				convertedTune += translateNote(octave, 'D', ' ');
			}
			if(tune[(k+1)]=='b')// if after A is a 'b', check what's next
			{
				if(tune[(k+2)]=='2' || tune[(k+2)]=='3'|| tune[(k+2)]=='4'||tune[(k+2)]=='5') //any number
				{
					octave = tune[(k+2)] - '0';
					convertedTune += translateNote(octave, 'D', 'b');
				}
				else//if there is no number after the 'b', then A refers to "Ab" in the 4th octave
				{
					convertedTune += translateNote(octave, 'D', 'b');
				}
			}
			if(tune[(k+1)]=='#')// if after A is '#', check what's after '#'
			{
				if(tune[(k+2)]=='2' || tune[(k+2)]=='3'|| tune[(k+2)]=='4'||tune[(k+2)]=='5'|| tune[(k+2)]=='6')//any number
				{
					octave = tune[(k+2)] - '0';
					convertedTune += translateNote(octave, 'D', '#');
				}
				else//if there is not a number after '#', then A refers to "A#" in the 4th octave
				{
					convertedTune += translateNote(octave, 'D', '#');
				}
			}	
		}
		if(tune[k] == 'E')
		{
			if(tune[(k+1)]=='A' || tune[(k+1)]=='B'|| tune[(k+1)]=='C'|| tune[(k+1)]=='D'|| tune[(k+1)]=='E'|| tune[(k+1)]=='F'|| tune[(k+1)]=='G')//if after A is any letter, the note A refers to "A"
			{
				convertedTune += translateNote(octave, 'E', ' ');
			}
			if(tune[(k+1)]=='/')//if after A is a slash, then note A refers to "A"
			{
				convertedTune += translateNote(octave, 'E', ' ');
			}
			if(isdigit(tune[(k+1)]))//if after A as a number N, then note A refers to "A(N)" where N is the octave  A6
			{
				octave = tune[(k+1)] - '0';
				convertedTune += translateNote(octave, 'E', ' ');
			}
			if(tune[(k+1)]=='b')// if after A is a 'b', check what's next
			{
				if(tune[(k+2)]=='2' || tune[(k+2)]=='3'|| tune[(k+2)]=='4'||tune[(k+2)]=='5') //any number
				{
					octave = tune[(k+2)] - '0';
					convertedTune += translateNote(octave, 'E', 'b');
				}
				else//if there is no number after the 'b', then A refers to "Ab" in the 4th octave
				{
					convertedTune += translateNote(octave, 'E', 'b');
				}
			}
			if(tune[(k+1)]=='#')// if after A is '#', check what's after '#'
			{
				if(tune[(k+2)]=='2' || tune[(k+2)]=='3'|| tune[(k+2)]=='4'||tune[(k+2)]=='5'|| tune[(k+2)]=='6')//any number
				{
					octave = tune[(k+2)] - '0';
					convertedTune += translateNote(octave, 'E', '#');
				}
				else//if there is not a number after '#', then A refers to "A#" in the 4th octave
				{
					convertedTune += translateNote(octave, 'E', '#');
				}
			}	
		}
		if(tune[k] == 'F')
		{
			if(tune[(k+1)]=='A' || tune[(k+1)]=='B'|| tune[(k+1)]=='C'|| tune[(k+1)]=='D'|| tune[(k+1)]=='E'|| tune[(k+1)]=='F'|| tune[(k+1)]=='G')//if after A is any letter, the note A refers to "A"
			{
				convertedTune += translateNote(octave, 'F', ' ');
			}
			if(tune[(k+1)]=='/')//if after A is a slash, then note A refers to "A"
			{
				convertedTune += translateNote(octave, 'F', ' ');
			}
			if(isdigit(tune[(k+1)]))//if after A as a number N, then note A refers to "A(N)" where N is the octave  A6
			{
				octave = tune[(k+1)] - '0';
				convertedTune += translateNote(octave, 'F', ' ');
			}
			if(tune[(k+1)]=='b')// if after A is a 'b', check what's next
			{
				if(tune[(k+2)]=='2' || tune[(k+2)]=='3'|| tune[(k+2)]=='4'||tune[(k+2)]=='5') //any number
				{
					octave = tune[(k+2)] - '0';
					convertedTune += translateNote(octave, 'F', 'b');
				}
				else//if there is no number after the 'b', then A refers to "Ab" in the 4th octave
				{
					convertedTune += translateNote(octave, 'F', 'b');
				}
			}
			if(tune[(k+1)]=='#')// if after A is '#', check what's after '#'
			{
				if(tune[(k+2)]=='2' || tune[(k+2)]=='3'|| tune[(k+2)]=='4'||tune[(k+2)]=='5'|| tune[(k+2)]=='6')//any number
				{
					octave = tune[(k+2)] - '0';
					convertedTune += translateNote(octave, 'F', '#');
				}
				else//if there is not a number after '#', then A refers to "A#" in the 4th octave
				{
					convertedTune += translateNote(octave, 'F', '#');
				}
			}	
		}
		if(tune[k] == 'G')
		{
			if(tune[(k+1)]=='A' || tune[(k+1)]=='B'|| tune[(k+1)]=='C'|| tune[(k+1)]=='D'|| tune[(k+1)]=='E'|| tune[(k+1)]=='F'|| tune[(k+1)]=='G')//if after A is any letter, the note A refers to "A"
			{
				convertedTune += translateNote(octave, 'G', ' ');
			}
			if(tune[(k+1)]=='/')//if after A is a slash, then note A refers to "A"
			{
				convertedTune += translateNote(octave, 'G', ' ');
			}
			if(isdigit(tune[(k+1)]))//if after A as a number N, then note A refers to "A(N)" where N is the octave  A6
			{
				octave = tune[(k+1)] - '0';
				convertedTune += translateNote(octave, 'G', ' ');
			}
			if(tune[(k+1)]=='b')// if after A is a 'b', check what's next
			{
				if(tune[(k+2)]=='2' || tune[(k+2)]=='3'|| tune[(k+2)]=='4'||tune[(k+2)]=='5') //any number
				{
					octave = tune[(k+2)] - '0';
					convertedTune += translateNote(octave, 'G', 'b');
				}
				else//if there is no number after the 'b', then A refers to "Ab" in the 4th octave
				{
					convertedTune += translateNote(octave, 'G', 'b');
				}
			}
			if(tune[(k+1)]=='#')// if after A is '#', check what's after '#'
			{
				if(tune[(k+2)]=='2' || tune[(k+2)]=='3'|| tune[(k+2)]=='4'||tune[(k+2)]=='5'|| tune[(k+2)]=='6')//any number
				{
					octave = tune[(k+2)] - '0';
					convertedTune += translateNote(octave, 'G', '#');
				}
				else//if there is not a number after '#', then A refers to "A#" in the 4th octave
				{
					convertedTune += translateNote(octave, 'G', '#');
				}
			}	
		}
		return 0;
}
string convertTune(string& tune)
{
	cerr << "my original tune is: " << tune << endl;
	string convertedTune = "";
	int octave = 4;
	//first successful conversion - if the tune entered is totally blank, the output is the empty string!
	if(tune == "")
	{
		convertedTune = "";
		return "";
	}
	//second conversion - if the first entry is a /, that means the first beat is an empty beat
	if(tune[0]== '/')
	{
		convertedTune += " ";
		cerr << convertedTune << endl;
	}
	//if the first entry is a letter, we'll either convert the first entry or put a [ bracket mark first and then convert the letter
	
	if(tune[0] == 'A' ||tune[0] == 'B' ||tune[0] == 'C' ||tune[0] == 'D' ||tune[0] == 'E' ||tune[0] == 'F' ||tune[0] == 'G')
	{
		//check to see if there's multiple notes in the beat
		int count = 1;
		int zero = 0;
		for (int j = 1; j != tune.size(); j++)
		{
			if( tune[j]=='A' || tune[j]=='B' || tune[j]=='C' || tune[j]=='D' || tune[j]=='E' || tune[j]=='F' || tune[j]=='G')
			{
				count++;
			}
			if(tune[j]=='/' && count > 1)
			{
				convertedTune += "[";
				break;
			}
			else
				break;
		}
		//if there's only one note, translate the note, and add it to convertedTune and then go on
		processNote(octave, zero, tune, convertedTune);
	}
	
	//this should translate all the spaces and process all the notes
	for(int k=1; k!=(tune.size()-1);k++)
	{
		if (tune[k]=='/')
		{
			if (tune[(k-1)]=='/')
			{
				convertedTune += " ";
			}
		}
		processNote(octave, k, tune, convertedTune);
	}

	//we know the last entry is a /, we need to decide whether or not the final beat needs a ] bracket or not
	//was there more than one note in the final beat?
	int count = 1;
	int zero = 0;
	if (tune[(tune.size()-2)=='/'])
	{
		convertedTune += " ";
	}
	for (int j = (tune.size()-1)/*thelastpositionintune*/; j!= 0; j--)
	{
		if( tune[j]=='A' || tune[j]=='B' || tune[j]=='C' || tune[j]=='D' || tune[j]=='E' || tune[j]=='F' || tune[j]=='G')
		{
			count++;
		}
		if((tune[0]=='A' || tune[0]=='B' || tune[0]=='C' || tune[0]=='D' || tune[0]=='E' || tune[0]=='F' || tune[0]=='G') && count > 1)
		{
			convertedTune += "]";
			break;
		}
		if(tune[j]=='/' && count > 1)
		{
			convertedTune += "]";
			break;
		}
		break;
	}
	return convertedTune;
}
int translateTune(string tune, string& instructions, int& badBeat)
{
	//if the tune is not well formed, instructions is unchanged, badBeat is unchanged, translateTune returns 1
	if(!isTuneWellFormed(tune))
	{
		return 1;
	}
	else //we know it IS wellformed. is it playable?
	{
		// if the tune is well formed, but unplayable, instructions is unchanged, badBeat is the beat where the first problem occurs, translateTune returns 2
		if (!isPlayable(tune, badBeat))
		{	
			//we already set badBeat in isPlayable
			return 2;
		}
		//if the tune is wellformed and playable, instructions is the translated tune, badbeat is unchanged, translateTune returns 0
		else
		{
			instructions = convertTune(tune);
			return 0;
		}
	}
}


/*
void testone(int n)
{
	string ins = "---";
	int bb = 666;
	switch (n)
	{
			         default: {
	    cout << "Bad argument" << endl;
			} break; case  1: {
	    assert(isTuneWellFormed(""));
			} break; case  2: {
	    assert(!isTuneWellFormed("C"));
			} break; case  3: {
	    assert(!isTuneWellFormed("#"));
			} break; case  4: {
	    assert(!isTuneWellFormed("3"));
			} break; case  5: {
	    assert(isTuneWellFormed("/"));
			} break; case  6: {
	    assert(isTuneWellFormed("A/"));
			} break; case  7: {
	    assert(isTuneWellFormed("B/"));
	    assert(isTuneWellFormed("C/"));
	    assert(isTuneWellFormed("D/"));
	    assert(isTuneWellFormed("E/"));
	    assert(isTuneWellFormed("F/"));
			} break; case  8: {
	    assert(isTuneWellFormed("G/"));
			} break; case  9: {
	    assert(!isTuneWellFormed("H/"));
			} break; case 10: {
	    assert(!isTuneWellFormed("e/"));
			} break; case 11: {
	    assert(!isTuneWellFormed("#/"));
			} break; case 12: {
	    assert(!isTuneWellFormed("5/"));
			} break; case 13: {
	    assert(!isTuneWellFormed("#5/"));
			} break; case 14: {
	    assert(!isTuneWellFormed("C#"));
			} break; case 15: {
	    assert(!isTuneWellFormed("C5"));
			} break; case 16: {
	    assert(!isTuneWellFormed("C#5"));
			} break; case 17: {
	    assert(!isTuneWellFormed("C5#/"));
			} break; case 18: {
	    assert(isTuneWellFormed("C#/"));
			} break; case 19: {
	    assert(isTuneWellFormed("Db/"));
			} break; case 20: {
	    assert(isTuneWellFormed("C3/"));
			} break; case 21: {
	    assert(isTuneWellFormed("C#3/"));
			} break; case 22: {
	    assert(!isTuneWellFormed("C34/"));
			} break; case 23: {
	    assert(!isTuneWellFormed("C#34/"));
			} break; case 24: {
	    assert(!isTuneWellFormed("C#b/"));
			} break; case 25: {
	    assert(isTuneWellFormed("C0/"));
	    assert(isTuneWellFormed("D1/"));
			} break; case 26: {
	    assert(isTuneWellFormed("B9/"));
	    assert(isTuneWellFormed("B#9/"));
	    assert(isTuneWellFormed("Cb0/"));
			} break; case 27: {
	    assert(isTuneWellFormed("//"));
			} break; case 28: {
	    assert(isTuneWellFormed("C//"));
			} break; case 29: {
	    assert(isTuneWellFormed("/C/"));
			} break; case 30: {
	    assert(isTuneWellFormed("C/C/"));
			} break; case 31: {
	    assert(isTuneWellFormed("C#/C/"));
			} break; case 32: {
	    assert(isTuneWellFormed("C/C3/"));
			} break; case 33: {
	    assert(isTuneWellFormed("C#4/Eb5/"));
			} break; case 34: {
	    assert(!isTuneWellFormed("C/E"));
			} break; case 35: {
	    assert(!isTuneWellFormed("C#5/E5b/"));
			} break; case 36: {
	    assert(!isTuneWellFormed("C#5/#/"));
			} break; case 37: {
	    assert(isTuneWellFormed("////"));
			} break; case 38: {
	    assert(isTuneWellFormed("//C/D/E/F///F/E//D/C/"));
			} break; case 39: {
	    assert(!isTuneWellFormed("C/C/D/E/F/F/E/D/C/3/E/F/"));
			} break; case 40: {
	    assert(isTuneWellFormed("CD/"));
			} break; case 41: {
	    assert(isTuneWellFormed("C#D/"));
			} break; case 42: {
	    assert(isTuneWellFormed("C#3D/"));
			} break; case 43: {
	    assert(isTuneWellFormed("C3D/"));
			} break; case 44: {
	    assert(isTuneWellFormed("CD#/"));
			} break; case 45: {
	    assert(isTuneWellFormed("CD#3/"));
			} break; case 46: {
	    assert(isTuneWellFormed("CD3/"));
			} break; case 47: {
	    assert(isTuneWellFormed("C#D3/"));
			} break; case 48: {
	    assert(isTuneWellFormed("C#4D#5/"));
			} break; case 49: {
	    assert(!isTuneWellFormed("CD5#/"));
			} break; case 50: {
	    assert(!isTuneWellFormed("C#D#H/"));
			} break; case 51: {
	    assert(!isTuneWellFormed("C#4#/"));
			} break; case 52: {
	    assert(!isTuneWellFormed("C#43D#5/"));
			} break; case 53: {
	    assert(isTuneWellFormed("A3C#E//E//F#3A3D4/A3C#E/"));
			} break; case 54: {
	    assert(isTuneWellFormed("C0C0DC0DD/E#FbB#Cb/B#9/"));
			} break; case 55: {
	    assert(isTuneWellFormed("G3B3DD5//G/A/A3B/C5/B3D5//G//G//CE5//C5/D5/E5/F#5/B3G5//G//G/"));
			} break; case 56: {
	    assert(isTuneWellFormed("DADDA/"));
			} break; case 57: {
	    assert(translateTune("", ins, bb) == 0);
			} break; case 58: {
	    translateTune("", ins, bb);
	    assert(ins == "");
			} break; case 59: {
	    translateTune("", ins, bb);
	    assert(bb == 666);
			} break; case 60: {
	    assert(translateTune("/", ins, bb) == 0);
			} break; case 61: {
	    assert(translateTune("/", ins, bb) == 0);
	    assert(ins == " ");
			} break; case 62: {
	    translateTune("/", ins, bb);
	    assert(bb == 666);
			} break; case 63: {
	    assert(translateTune("G/", ins, bb) == 0);
			} break; case 64: {
	    translateTune("G/", ins, bb);
	    assert(ins == "L");
			} break; case 65: {
	    translateTune("G/", ins, bb);
	    assert(bb == 666);
			} break; case 66: {
	    assert(translateTune("G#/", ins, bb) == 0  &&  ins == "$");
			} break; case 67: {
	    assert(translateTune("Gb/", ins, bb) == 0  &&  ins == "#");
			} break; case 68: {
	    assert(translateTune("G3/", ins, bb) == 0  &&  ins == "S");
			} break; case 69: {
	    assert(translateTune("G#3/", ins, bb) == 0  &&  ins == "9");
			} break; case 70: {
	    assert(translateTune("B#1/", ins, bb) == 0  &&  ins == "Z");
			} break; case 71: {
	    assert(translateTune("C2/", ins, bb) == 0  &&  ins == "Z");
			} break; case 72: {
	    assert(translateTune("B5/", ins, bb) == 0  &&  ins == "O");
			} break; case 73: {
	    assert(translateTune("Cb6/", ins, bb) == 0  &&  ins == "O");
			} break; case 74: {
	    assert(translateTune("B#5/", ins, bb) == 0  &&  ins == "P");
			} break; case 75: {
	    assert(translateTune("C6/", ins, bb) == 0  &&  ins == "P");
			} break; case 76: {
	    assert(translateTune("//", ins, bb) == 0  &&  ins == "  ");
			} break; case 77: {
	    assert(translateTune("G//", ins, bb) == 0  &&  ins == "L ");
			} break; case 78: {
	    assert(translateTune("/G/", ins, bb) == 0  &&  ins == " L");
			} break; case 79: {
	    assert(translateTune("G/A/", ins, bb) == 0  &&  ins == "LQ");
			} break; case 80: {
	    assert(translateTune("G#/G/", ins, bb) == 0  &&  ins == "$L");
			} break; case 81: {
	    assert(translateTune("G/G3/", ins, bb) == 0  &&  ins == "LS");
			} break; case 82: {
	    assert(translateTune("C#4/Db5/", ins, bb) == 0  &&  ins == "!^");
			} break; case 83: {
	    assert(translateTune("////", ins, bb) == 0  &&  ins == "    ");
			} break; case 84: {
	    assert(translateTune("G///A/B/C//D//", ins, bb) == 0  &&  ins == "L  QWG H ");
			} break; case 85: {
	    assert(translateTune("C2/C#2/D2/D#2/Fb2/E#2/F#2/G2/G#2/A2/A#2/B2/", ins, bb) == 0  &&  ins == "Z1X2CV3B4N5M");
			} break; case 86: {
	    assert(translateTune("B#2/Db3/D3/Eb3/E3/F3/Gb3/G3/Ab3/A3/Bb3/Cb4/", ins, bb) == 0  &&  ins == ",6.7/A8S9D0F");
			} break; case 87: {
	    assert(translateTune("C4/C#/D/D#4/E/F4/Gb4/G4/Ab/A/Bb/B4/", ins, bb) == 0  &&  ins == "G!H@JK#L$Q%W");
			} break; case 88: {
	    assert(translateTune("C5/C#5/D5/D#5/E5/F5/F#5/G5/G#5/A5/A#5/B5/", ins, bb) == 0  &&  ins == "E^R&TY*U(I)O");
			} break; case 89: {
	    assert(translateTune("CE/", ins, bb) == 0  &&  ins == "[GJ]");
			} break; case 90: {
	    assert(translateTune("CEb/", ins, bb) == 0  &&  ins == "[G@]");
			} break; case 91: {
	    assert(translateTune("C#E/", ins, bb) == 0  &&  ins == "[!J]");
			} break; case 92: {
	    assert(translateTune("C3F#5/", ins, bb) == 0  &&  ins == "[,*]");
			} break; case 93: {
	    assert(translateTune("CDEFGAB/", ins, bb) == 0  &&  ins == "[GHJKLQW]");
			} break; case 94: {
	    assert(translateTune("C#D3EbF#5Gb2AB/", ins, bb) == 0  &&  ins == "[!.@*3QW]");
			} break; case 95: {
	    assert(translateTune("CD/E/FG/", ins, bb) == 0  &&  ins == "[GH]J[KL]");
			} break; case 96: {
	    assert(translateTune("D3/F#3/A3/D4//D3F#3A3D4/", ins, bb) == 0  &&  ins == ".8DH [.8DH]");
			} break; case 97: {
	    assert(translateTune("G3B3DD5//G/A/A3B/C5/B3D5//G//G//CE5//C5/D5/E5/F#5/B3G5//G//G/", ins, bb) == 0  &&  ins == "[SFHR] LQ[DW]E[FR] L L [GT] ERT*[FU] L L");
			} break; case 98: {
	    assert(translateTune("DADDA/", ins, bb) == 0  &&  ins == "[HQHHQ]");
			} break; case 99: {
	    assert(translateTune("C", ins, bb) == 1);
			} break; case 100: {
	    translateTune("C", ins, bb);
	    assert(ins == "---");
			} break; case 101: {
	    translateTune("C", ins, bb);
	    assert(bb == 666);
			} break; case 102: {
	    assert(translateTune("C0/", ins, bb) == 2);
			} break; case 103: {
	    translateTune("C0/", ins, bb);
	    assert(ins == "---");
			} break; case 104: {
	    translateTune("C0/", ins, bb);
	    assert(bb == 1);
			} break; case 105: {
	    assert(translateTune("C/D/C0/", ins, bb) == 2  &&  bb == 3);
			} break; case 106: {
	    assert(translateTune("C/D/E/C0/F/G/", ins, bb) == 2  &&  bb == 4);
			} break; case 107: {
	    assert(translateTune("C/D/C0/E/F/C0/", ins, bb) == 2  &&  bb == 3);
			} break; case 108: {
	    assert(translateTune("C/D/D0/E/F/C0/G/", ins, bb) == 2  &&  bb == 3);
			} break; case 109: {
	    assert(translateTune("C/D/EFC0/", ins, bb) == 2  &&  bb == 3);
			} break; case 110: {
	    assert(translateTune("C/D/EFC0G/", ins, bb) == 2  &&  bb == 3);
			} break; case 111: {
	    assert(translateTune("B1/", ins, bb) == 2);
			} break; case 112: {
	    assert(translateTune("C#6/", ins, bb) == 2);
			} break; case 113: {
	    assert(translateTune("C7/", ins, bb) == 2);
			} break; case 114: {
	    assert(translateTune("C8/", ins, bb) == 2);
			} break; case 115: {
	    assert(translateTune("C9/", ins, bb) == 2);
			}
	}
}

int main()
{
	cout << "Enter test number: ";
	int n;
	cin >> n;
	testone(n);
	cout << "Passed!" << endl;
}
*/