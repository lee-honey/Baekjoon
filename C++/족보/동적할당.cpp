#include <iostream>

using namespace std;

int main(void)
{
    int* ptr = new int;
    *ptr = 10;
    cout << ptr << endl;
    cout << *ptr << endl;
    delete ptr;
    cout << ptr << endl;
    return 0;
}