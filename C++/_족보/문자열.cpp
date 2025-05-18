#include <string.h>
#include <iostream>

using namespace std;

int main(void)
{
    static const char* str1 = "Zusin";
    static const char str2[] = "Zusin";
    int num1 = sizeof(str1);
    int num2 = sizeof(str2);
    int num3 = strlen(str1);
    int num4 = strlen(str2);

    cout << num1 << '\n';
    cout << num2 << '\n';
    cout << num3 << '\n';
    cout << num4 << '\n';

    return 0;
}