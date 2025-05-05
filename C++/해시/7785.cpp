#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;

int N(0);
unordered_map<string, bool> mp;
vector<string> vec;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    for(int i = 0; i < N; i++)
    {
        string strName;
        string keyword;
        cin >> strName >> keyword;
        if(keyword == "enter")
            mp[strName] = true;
        else if(keyword == "leave")
            mp[strName] = false;
    }

    for(auto iter : mp)
    {
        if(iter.second == true)
            vec.push_back(iter.first);
    }

    sort(vec.begin(), vec.end(), greater<>());
    for(int i = 0; i < vec.size(); i++)
        cout << vec[i] << '\n';

    return 0;
}