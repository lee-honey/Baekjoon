#include <iostream>
#include <string>

using namespace std;
string str;
string word;
int ans(0);

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    getline(cin, str);
    getline(cin, word);

    if(str.size() < word.size())
    {
        cout << "0" << '\n';
        return 0;
    }

    for(int i = 0; i < str.size() - word.size() + 1; i++)
    {
        string temp = str.substr(i, word.size());
        if(temp == word)
        {
            i += (word.size() - 1);
            ++ans;
        }
    }

    cout << ans << '\n';

    return 0;
}