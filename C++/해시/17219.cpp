#include <iostream>
#include <string>
#include <map>

using namespace std;

int N = 0, M = 0;
map<string, string> mp;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    while(N--)
    {
        string str = "", passwd = "";
        cin >> str >> passwd;
        mp[str] = passwd;
    }
    while(M--)
    {
        string str = "";
        cin >> str;
        cout << mp[str] <<'\n';
    }
    return 0;
}