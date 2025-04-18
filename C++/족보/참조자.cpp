#include <iostream>

using namespace std;

int main(void)
{
    int i = 0;
    int& r= i;
    r = 2;
    int* p = &r;
    *p = 3;
    printf("%d, %d, %d", i, r, *p);
    return 0;
}