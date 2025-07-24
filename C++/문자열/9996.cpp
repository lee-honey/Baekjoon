#include <iostream>
#include <string>
#include <vector>

using namespace std;

int             N(0);
string          pattern;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    cin >> pattern;

    int frontIdx(0);
    for(int i = 0; i < pattern.size(); i++)
    {
        if(pattern[i] == '*')
            frontIdx = i;
    }

    for(int i = 0; i < N; i++)
    {
        string str;
        cin >> str;

        int backIdx = pattern.size() - frontIdx - 1;

        if(str.size() < backIdx)
        {
            cout << "NE" << '\n';
            continue;
        }

        if(pattern.size() - 1 <= str.size() && str.substr(0, frontIdx) == pattern.substr(0, frontIdx)
        && str.substr(str.size() - backIdx, backIdx) == pattern.substr(frontIdx + 1, backIdx))
            cout << "DA" << '\n';
        else
            cout << "NE" << '\n';
    }

    return 0;
}