#include <iostream>
	using namespace std;

	int main()
	{
	    int len;

	    cout << "Enter a number: ";
	    cin >> len;

	    for (int i = 0; i < len; i++)
	    {
		int j=1;
		while ((len != 0) && (!(len < 0 )) && (i+j < len));
		{
		    cout << " ";
			j++;
		}
				
		cout << "#" << endl;
	    }
	}
