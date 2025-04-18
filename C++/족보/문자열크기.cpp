#include <iostream>
#include <cstring>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    char str[] = "a string length";
    cout << sizeof(str) << " " << strlen(str) << '\n';

    return 0;
}