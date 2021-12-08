
#include <iostream>
using namespace std;


int main()
{
	int A = 8, B = 9;
	int *test[] = { &A,&B };
	*test[0] = 10;
	cout << A;
}
