#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

int main(int argc, char* argv[])
{
    ofstream out("out.txt", ios::out | ios::binary);





    for(int i =0;i<10000;i++)
    out << "\xe2\x80\x8d";

    out.close();

    
    return 0;
}
