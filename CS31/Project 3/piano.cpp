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
				cerr << "Translation:" << endl << instructions << endl;
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