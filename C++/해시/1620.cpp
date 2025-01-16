#include <iostream>
#include <string>
#include <map>

using namespace std;

int N = 0, M = 0;
string arr[100001] = {"", };
map<string, int> mp;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    cin.ignore();

    for(int i = 1; i <= N; i++)
    {
        string str = "";
        cin >> str;
        arr[i] = str;
        mp[str] = i;
    }
    while(M--)
    {
        string str = "";
        cin >> str;
        if(1 <= atoi(str.c_str()) && atoi(str.c_str()) <= 100000)
        {
            cout << arr[atoi(str.c_str())] <<'\n';
        }
        else
            cout << mp[str] << '\n';
    }

    return 0;
}