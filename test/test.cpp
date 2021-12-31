#include <iostream>
#include <fstream>
#include <cstring>
#include <conio.h>

using namespace std;

int main()
{
    int a[] = { 1,2,3,4 };
    int *p = a;

    for (int i = 0; i < 6; i++) {
        p = p + 1;
    }
    
}
