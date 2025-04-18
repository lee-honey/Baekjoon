#include <iostream>

using namespace std;

struct tagInfo
{
    char a;
    int b;
    char c;
    char d;
};

int main(void)
{
    tagInfo tInfo = {'a', 10, 'c', 'd'};
    cout << sizeof(tInfo) << endl;

    return 0;
}