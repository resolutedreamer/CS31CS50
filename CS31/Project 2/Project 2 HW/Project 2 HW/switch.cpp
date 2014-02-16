#include <iostream>
	using namespace std;

	int main()
	{
		int month = 1;
		cout << "please enter a month: ";
		cin >> month;
		switch (month)
		{
		case 6:
			cout << "summer solstice";
			break;
		case 12:
			cout << "winter solstice";
			break;
		case 3:
		case 9:
			cout << "equinox";
			break;
		default:
			cout << "nothing special";
			break;
		}

	}