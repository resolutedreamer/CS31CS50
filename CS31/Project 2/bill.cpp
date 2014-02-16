#include <iostream>
#include <string>

	using namespace std;

	int main()
	{
	    //initializing all my variables here		
		
		int initialMeter = 0, finalMeter = 10, used=0;
		float bill = 0.0;
		int month = 1;
		string name;
		//user input segment

		cout << "Initial meter reading: ";
		cin >> initialMeter;
		
		cout << "Final meter reading: "; 
		cin >> finalMeter;
		cin.ignore(10000, '\n');

		cout << "Customer name: ";
		getline(cin, name);

		cout << "Month number (1=Jan, 2=Feb, etc.): ";
		cin >> month;
		
		cout << "---" << endl ;

		/*bill output below the triple lines segment starts here
		this first if takes care of the initial meter reading being negative*/
		if(initialMeter < 0)
		{
			cout << "The initial meter reading must be nonnegative." << endl;
			return 0;
		}
		//this second if takes care of the case where the final reading is less than the initial reading
		if(finalMeter < initialMeter)
		{
			cout << "The final reading must be at least as large as the initial reading." << endl;
			return 0;
		}
		//this third if takes care of the case where there was no customer name provided
		if(name=="")
		{
			cout << "You must enter a customer name." << endl;
			return 0;
		}
		//this fourth if takes care of the month number being incorrect.
		if(month<1||month>12)
		{
			cout << "The month number must be in the range 1 through 12." << endl;
			return 0;
		}
				
		//successful bill output segment
		else
		{
			used = finalMeter - initialMeter;
			float highRate = 0.0;
			//high usage
			if(month > 5 && month < 11)
			{
				if(used<47)
				{
					bill = used * 2.65;
				}	
				else
				{
					highRate = used - 46.0;
					float lowRate = (46 * 2.65);
					bill = lowRate + (highRate * 3.36);
				}

			}
			//low usage
			else
			{
				if(used<33)
				{
					bill = used * 2.65;
				}
				else
				{
					highRate = used - 32.0;
					float lowRate = (32 * 2.65);
					bill = lowRate + (highRate * 2.79);
				}
			}						
			
			cout.setf(ios::fixed);
			cout.precision(2);
			cout << "The bill for " << name << " is $" << bill << endl;
		}
		return 0;
	}