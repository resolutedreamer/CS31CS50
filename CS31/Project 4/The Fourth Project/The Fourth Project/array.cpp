#include <iostream>
#include <string>
#include <cmath>
#include <cassert>
using namespace std;


int tally(const string a[], int n, string target);
int findFirst(const string a[], int n, string target);
bool findFirstSequence(const string a[], int n, string target, int& begin, int& end);
int findFirstDisorder(const string a[], int n);
int positionOfMin(const string a[], int n);
int moveToEnd(string a[], int n, int pos);
int moveToBeginning(string a[], int n, int pos);
int disagree(const string a1[], int n1, const string a2[], int n2);
int removeDups(string a[], int n);
bool subsequence(const string a1[], int n1, const string a2[], int n2);
int mingle(const string a1[], int n1, const string a2[], int n2, string result[], int max); 
int divide(string a[], int n, string divider); 

int main()
{	/*
		    string h[7] = { "peter", "lois", "meg", "chris", "", "stewie", "meg" };
	    assert(tally(h, 7, "meg") == 2);
	    assert(tally(h, 7, "") == 1);
	    assert(tally(h, 7, "quagmire") == 0);
	    assert(tally(h, 0, "meg") == 0);
	    assert(findFirst(h, 7, "meg") == 2);
	    assert(findFirst(h, 2, "meg") == -1);
	    int bg;
	    int en;
	    assert(findFirstSequence(h, 7, "chris", bg, en) && bg == 3 && en == 3);

	    string g[4] = { "peter", "lois", "chris", "stewie" };
	    assert(positionOfMin(g, 4) == 2);
	    assert(disagree(h, 4, g, 4) == 2);
	    assert(subsequence(h, 7, g, 4));
	    assert(moveToEnd(g, 4, 1) == 1 && g[1] == "chris" && g[3] == "lois");
	
	    string f[4] = { "chris", "stewie", "meg", "lois" };
	    assert(moveToBeginning(f, 4, 2) == 2 && f[0] == "meg" && f[2] == "stewie");
	
	    string e[5] = { "chris", "chris", "chris", "meg", "meg" };
	    assert(removeDups(e, 5) == 2 && e[1] == "meg");
	*/
	    string x[4] = { "brian", "lois", "lois", "quagmire" };
	    string y[4] = { "chris", "lois", "meg", "stewie" };
	    string z[10];
	    //assert(mingle(x, 4, y, 4, z, 10) == 8 && z[5] == "meg");
		
		mingle(x, 4, y, 4, z, 10);
		for(int i = 0; i < 8; i++ ) {
			cout << x[i] << " " ;
		}
	    //assert(divide(h, 7, "meg") == 3);
	
	    cout << "All tests succeeded!" << endl;

}

int tally(const string a[], int n, string target)
{
	//this one is done
	int count = 0;
	if(n < 0)
	{
		//cerr << -1 << endl;
		return -1;
	}
	for (int k = 0; k < n ;k++)
	{
		if (a[k] == target)
		{
			count++;
		}
	}
	//cerr << count << endl;
	return count;
}
int findFirst(const string a[], int n, string target)
{
	//this one is done
	int count = 0;
	if (n < 0)
	{
		//cerr << -1 << endl;
		return -1;
	}
	for (int k = 0; k < n ;k++)
	{
		if (a[k] == target)
		{
			//cerr << k << endl;
			return k;
		}
	}
	//cerr << -1 << endl;
	return -1;
}
bool findFirstSequence(const string a[], int n, string target, int& begin, int& end)
{
	//this one is done
	if (n < 0)
	{
		//cerr << "the beginning and the end" << endl;
		//cerr << begin << endl;
		//cerr << end << endl;
		//cerr << 0 << endl;
		return 0;
	}
	for (int k = 0; k < n ; k++)
	{
		if (a[k] == target)
		{
			begin = k;
			end = (k-1);
			for (int j = k; j < n ; j++)
			{		
				if( a[j] == target)
				{
					end++;
				}
			}
			//cerr << 1 << endl;
			//cerr << "the beginning and the end" << endl;
			//cerr << begin << endl;
			//cerr << end << endl;
			return 1;
			break;
		}
	}
	//cerr << "the beginning and the end" << endl;
	//cerr << begin << endl;
	//cerr << end << endl;
	//cerr << 0 << endl;
	return 0;
}
int findFirstDisorder(const string a[], int n)
{
	for (int k = 0; k < n-1; k++)
		if (a[k] > a[k+1])
			return k;
	return -1;
}
int positionOfMin(const string a[], int n)
{
	//done
	if (n < 0)
	{
		cerr << -1 << endl;
		return -1;
	}

	int smallest_spot = -1;
	string smallest = "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"; // ~ is the largest ascii character
	for(int k = 0 ; k < (n-1) ; k++)
	{	
		//cerr << "i'm in the for loop wheeee" << k << endl;
		if(a[k] <= a[k+1])
		{
			//cerr << "my entry is smaller than the next entry" << k << endl << a[k] <<endl << smallest;
			if (a[k] < smallest)	//only change the smallest location if your value 
									//is smaller than the last smallest value encountered
			{
				smallest_spot = k;
				smallest = a[k];
			}
		}
		else
		{
			//cerr << "my entry is bigger than the next entry" << k << endl;
			if (a[k+1] < smallest)	//only change the smallest location if your value 
									//is smaller than the last smallest value encountered
			{
				smallest_spot = k+1;
				smallest = a[k+1];
			}
		}
	}
	//cerr <<smallest_spot<<endl;
	return smallest_spot;






	/*
	//when it's time to give up, use this incomplete function
	int smallest = 0;
	string smallest_entry = "!";
	for(int k = 0 ; k < (n-1) ; k++)
	{	
		if(a[k] <= a[(k+1)])
		{
			smallest = k;
		}
		else
		{
			smallest = k+1;
		}
	}
	return smallest;
	*/


}
int moveToEnd(string a[], int n, int pos)
{
	//this one is done
	if (n < 0)
	{
		return -1;
	}

	string end = a[pos];
	for (int k=pos; k < (n-1); k++)
	{
		a[k] = a[k+1];
	}
	a[n-1]=end;
	return pos;
}
int moveToBeginning(string a[], int n, int pos)
{
	//this one is done.
	if (n < 0)
		return -1;
	string begin = a[pos];
	for (int k=pos; k > 1 ; k--)
	{
		a[k] = a[k-1];
	}
	a[0]=begin;
	//cerr << a[0] << endl;
	return pos;
}
int disagree(const string a1[], int n1, const string a2[], int n2)
{
	//done
	if (n1 < 0 || n2 < 0)
	{
		return -1;
	}
	else if (n1 < n2) //if the smaller is 1st array
	{
		for (int k=0; k < n1; k++)
		{
			if (a1[k] != a2[k])
				return k; //location of first unmatch
		}
		return n1; //if all match, n1 match
	}

	else if (n2 < n1)// if the smaller is 2nd array
	{
		for (int k=0; k < n2; k++)
		{
			if (a1[k] != a2[k])
				return k; // location of first unmatch
		}
		return n2; // if all match, n2 match
	}
	
	else //if (n1 == n2)
	{
		for (int k=0; k < n1; k++)
		{
			if (a1[k] != a2[k])
				return k;
		}
		return n1; // if all match, n1=n2 match
	}
}
int removeDups(string a[], int n)
{
	//this one almost kind of works
	if (n < 0)
		return -1;

	int duplicateNumber = 0;
	for (int i=0; i < (n-1); i++)
	{
		//cerr << "i am in the " << i <<"th iteration" << endl;
		if (a[i]==a[i+1] && a[i]!="__MARKEDFOORDELETION__") //if i see a duplicate
		{
			//cerr << "i see a duplicate" << endl;
			//cerr << "i am moving " << a[i] << " to the end" << endl;
			


			string end = a[i];
			for (int k=i; k < (n-1); k++)
			{
				a[k] = a[k+1];
			}
			a[n-1]=end;
			i--;
			a[n-1]= "__MARKEDFOORDELETION__";
			duplicateNumber++;
		}
	}

	for (int i=0; i < n; i++)
	{
		//cerr << a[i] << endl;
	}

	return n-duplicateNumber;
}
bool subsequence(const string a1[], int n1, const string a2[], int n2)
{
	//done
	//check all of the first array and see if you find the first entry of the second array anywhere, if you see the 1st entry of
	//the second array in the first, go look for the next entry of the second array and see if that exists somewhere further in the 
	//first array, and if you look for an entry of the second array you do not see further down the first array, return false
	int a1_index = -1;
	for (int a2_index = 0; a2_index < n2; a2_index++) // this makes sure i check all n2 entries of array 2
	{
		//cerr << endl << "i am looking in a1 for the " << a2_index << " entry of a2, which is " << a2[a2_index] << "."<< endl ;
		for (a1_index += 1; a1_index < n1; a1_index++) // i will look at all the entries of a1
		{
			//cerr << "I am looking at the " << a1_index << " entry of a1, which is " << a1[a1_index] << "." << endl;
			
			if (a1[a1_index] == a2[a2_index]) // if i see that an element of a1 DOES equal the element of a2 i am looking for
			{
				break; // i want to look for the next element of a2, so i stop looking for this element
			}
		}
		if (a1_index == n1)
			return 0;
	}
	return 1;
}
int mingle(const string a1[], int n1, const string a2[], int n2, string result[], int max)
{
	int total = n1+n2;
	if (n1 < 0 || n2 < 0)
		return -1;
	if (total > max)
		return -1;
	int k=0;
	/*string PASS[1000]; 
	for (; k < n1; k++)
	{
		PASS[k] = a1[k];
	}
	for (int j=0; j < n2 ;j++)
	{
		PASS[k+j] = a2[j];
	}

	for (int i=0; i < total; i++)
	{
		result [i] = PASS[positionOfMin(PASS, total)];
		PASS[positionOfMin(PASS, total)] = "~_DELETE__";
		cerr << result[i] << ensdl;
	}*/
	for (; k < n1; k++) { result[k] = a1[k]; }
	for (int j=0; j < n2 ;j++) { result[k+j] = a2[j]; }
	for (int i=0; i < total; si++ ) {
		divide(result, total, result[i]);
	}
	return total;
}
int divide(string a[], int n, string divider)
{
	if (n < 0)
		return -1;
	int count = 0;
	for (int k=0; k < n; k++)
	{
		//cerr << "I am on the iteration number " << k << endl;
		if ( a[k] < divider)
		{		
			string begin = a[k];
			for (int I=k; I > 0 ; I--)
			{
				a[I] = a[I-1];
			}
			a[0]=begin;
			count++;		
			//cerr << count << endl;
		}
	}

	for (int k=0; k < n; k++)
	{
		if (a[k] > divider)
		{
			string end = a[k];
			for (int I=k; I < n-1 ; I++)
			{
				a[I] = a[I+1];
			}
			a[n-1]=end;
		}
	}
	for (int i=0; i < n; i++)
	{
		cerr << a[i] << endl;
	}
	return count;
}