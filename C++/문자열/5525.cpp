#include <iostream>
#include <string>
using namespace std;

int N = 0, M = 0;
int idx = 0;
int result = 0;
string S = "";

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M >> S;

    for(int i = 0; i < M; i++)
    {
        int k = 0;
        if(S[i] == 'O')
            continue;

        while(S[i + 1] == 'O' && S[i + 2] == 'I')
        {
            k++;
            if(k == N)
            {
                result++;
                k--;
            }
            i += 2;
        }
    }

    cout << result << '\n';

    return 0;
}