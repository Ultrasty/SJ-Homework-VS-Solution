#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

int main()
{
    string s = "sss";
    int ullValue = 16;
    char buf[20] = { '0','0','0','0','0','0','0','0','0' };
    sprintf(buf, "%8X", ullValue);
    cout << buf << endl;

    int a;
    sscanf("21", "%x", &a);
    cout << a;

    return 0;
}
