#include <iostream>
#include <string>
#include <map>

using namespace  std;

string str = "";
string ans = "";
map<char, int> mp;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> str;
    for(int i =0 ; i < str.size(); i++)
        mp[str[i]]++;
    
    ans = str;
    bool bSorry = false;
    char temp = ' ';
    int idx(0);
    for(auto iter : mp)
    {
        if(iter.second % 2 == 1)
        {
            if(bSorry == false)
            {
                ans[ans.size() / 2] = iter.first;
                bSorry = true;
            }
            else
            {
                cout << "I'm Sorry Hansoo" << '\n';
                return 0;
            }
        }
        for(int i = 0; i < iter.second / 2; i++)
        {
            ans[idx + i] = iter.first;
            ans[ans.size() - 1 - i - idx] = iter.first;
        }
        idx += iter.second / 2;
    }

    cout << ans << '\n';

    return 0;
}