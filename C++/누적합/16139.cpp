#include <iostream>
#include <string>

using namespace std;

string S = "";
int q(0);
int prefix[200001][26] = {0,};

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> S;
    for(int i = 1; i <= S.size(); i++)
    {
        for(char c = 'a'; c <= 'z'; c++)
        {
            prefix[i][c - 'a'] += prefix[i - 1][c - 'a'];
            if(c == S[i - 1])
                prefix[i][S[i - 1] - 'a']++;
        }
    }

    cin >> q;
    while(q--)
    {
        char    a;
        int     l, r;
        cin >> a >> l >> r;
        cout << prefix[r + 1][a - 'a'] - prefix[l][a - 'a'] << '\n';
    }

    return 0;
}