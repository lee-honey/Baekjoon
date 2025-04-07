#include <iostream>

using namespace std;

int main(void)
{
    ios::sync_with_stdio;
    cin.tie(NULL);
    cout.tie(NULL);

    int v1 = 1;
    int v2 = 2;

    const int* ptr = &v1;   // 상수 포인터 (상수에 대한 포인터)
    int* const ptr2 = &v2;  // 포인터 상수 (포인터가 상수)

    v1 = 10;    //  1
    v2 = 20;    //  2

    v2 = v1;    //  3
    v1 = v2;    //  4

    ptr = ptr2; //  5
    ptr2 = ptr; //  6

    *ptr = 6;   //  7
    *ptr2 = 8;  //  8

    (*ptr)++;   //  9
    (*ptr2)++;  //  10

    ptr++;      //  11
    ptr2++;     //  12

    return 0;
}