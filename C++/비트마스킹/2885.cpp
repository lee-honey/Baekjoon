#include <iostream>

using namespace std;

int K(0);
int choco(0), division(0);

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> K;

    int temp(1);
    while(temp < K)
        temp <<= 1;
    choco = temp;

    while(K > 0)
    {
        if(K >= temp)
            K -= temp;
        else
        {
            temp >>= 1;
            division++;
        }
    }

    cout << choco << " " << division << '\n';

    return 0;
}