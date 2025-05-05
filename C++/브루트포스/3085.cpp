#include <iostream>
#include <string>
using namespace std;

int N(0);
char arr[51][51] = {0,};

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    for(int i = 0; i < N; i++)
    {
        string str;
        cin >> str;
        for(int j = 0; j < N; j++)
        {
            arr[i][j] = str[j];
        }
    }

    return 0;
}