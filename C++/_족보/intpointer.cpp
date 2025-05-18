#include <iostream>

using namespace std;

void Berger(int a);

int main(void)
{
    int* pA = new int;
    *pA = 20;
    Berger(*pA);
    return 0;
}