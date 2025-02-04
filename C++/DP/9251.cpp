#include <iostream>
#include <string>

using namespace std;

int Max(int a, int b){ return (a > b) ? a : b; }
int DP[1001][1001];
string str, str2;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> str >> str2;

    for(int i = 1; i <= str.size(); i++)
    {
        for(int j = 1; j <= str2.size(); j++)
        {
            if(str[i - 1] == str2[j - 1])
                DP[i][j] = DP[i - 1][j - 1] + 1;
            else
                DP[i][j] = max(DP[i - 1][j], DP[i][j - 1]);
        }
    }

    cout << DP[str.size()][str2.size()] << '\n';

    return 0;
}
