// This program can't find its variable.
#include <iostream>
using namespace std;

int main()
{
    int value = 100;

    cout << value; // ERROR! value not defined yet!
    return 0;
}