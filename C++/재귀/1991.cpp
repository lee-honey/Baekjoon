#include <iostream>
#include <map>
#include <string>

using namespace std;

int N(0);
map<char, pair<char, char>> mp;
string str = "";

void Pre(char c)
{
    str += c;
    if(mp[c].first != '.')
        Pre(mp[c].first);
    if(mp[c].second != '.')
        Pre(mp[c].second);
}

void In(char c)
{
    if(mp[c].first != '.')
        In(mp[c].first);
    str += c;
    if(mp[c].second != '.')
        In(mp[c].second);
}

void Post(char c)
{
    if(mp[c].first != '.')
        Post(mp[c].first);
    if(mp[c].second != '.')
        Post(mp[c].second);
    str += c;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    for(int i = 0; i < N; i++)
    {
        char cKey, cLValue, cRValue;
        cin >> cKey >> cLValue >> cRValue;
        mp[cKey].first = cLValue;
        mp[cKey].second = cRValue;
    }

    Pre('A');
    cout << str <<'\n';
    str = "";
    
    In('A');
    cout << str <<'\n';
    str = "";

    Post('A');
    cout << str <<'\n';

    return 0;
}