// Code for Project 1
	// Report poll results
	
	#include <iostream>
	using namespace std;       // see p. 36-37 in Savitch book
	
	int main()
	{
	    int numberSurveyed;
	    int forObomney;
	    int forSantpaul;
	
	    cout << "How many registered voters were surveyed? ";
	    cin >> numberSurveyed;
	    cout << "How many of them say they will vote for Obomney? ";
	    cin >> forObomney;
	    cout << "How many of them say they will vote for Santpaul? ";
	    cin >> forSantpaul;
	
	    double pctObomney = 100.0 * forObomney / numberSurveyed;
	    double pctSantpaul = 100.0 * forSantpaul / numberSurveyed;

	    cout.setf(ios::fixed);       // see pp. 31-32 in Savitch book
	    cout.precision(1);
	
	    cout << endl;
	    cout << pctObomney << "% say they will vote for Obomney." << endl;
	    cout << pctSantpaul << "% say they will vote for Santpaul." << endl;

	    if (forObomney > forSantpaul)
	        cout << "Obomney is predicted to win the election." << endl;
	    else
	        cout << "Santpaul is predicted to win the election." << endl;
	}
