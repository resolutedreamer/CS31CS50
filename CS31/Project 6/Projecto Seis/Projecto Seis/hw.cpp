#include <iostream>
#include <cmath>
#include <cstring>
#include <string>
using namespace std;








#include <iostream>

    using namespace std;

    int* minimart(int* a, int* b)
    {
        if (*a < *b)
            return a;
        else
            return b;
    }

    void swap1(int* a, int *b)
    {
        int* temp = a;
        a = b;
        b = temp;
    }

    void swap2(int* a, int *b)
    {
        int temp = *a;
        *a = *b;
        *b = temp;
    }

    int main()
    {
        int array[6] = { 5, 3, 4, 17, 22, 19 };

        int* ptr = minimart(array, &array[2]);
        ptr[1] = 9;
        ptr += 2;
        *ptr = -1;
        *(array+1) = 79;

        cout << "diff=" << &array[5] - ptr << endl;

		for (int i = 0; i < 6; i++)
            cout << array[i] << endl;

		cout << endl<< endl<< endl<< endl<< endl<< endl;

        swap1(&array[0], &array[1]);
        swap2(array, &array[2]);

        for (int i = 0; i < 6; i++)
            cout << array[i] << endl;
    } 
/*


double computeAverage(const double* scores, int numScores)
{
    double tot = 0;
	for (int k = 0; k < numScores; k++)
	{
		tot += *(scores + k);
	}
    return tot/numScores;
}


int main()
{
	double d;
	double array[5] = {20, 30, 90, 80, 30};
	d = computeAverage(array, 5);
	cout << d << endl;
}
*/