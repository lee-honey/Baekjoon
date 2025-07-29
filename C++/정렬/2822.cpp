#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<pair<int, int>> vec(8);
vector<int> ans;
int sum(0);

bool Cmp(const pair<int, int>& n1, const pair<int, int>& n2)
{
    return (n1.second < n2.second);
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    for(int i = 0; i < 8; i++)
    {
        vec[i].first = i + 1;
        cin >> vec[i].second;
    }

    sort(vec.begin(), vec.end(), Cmp);

    for(int i = 3; i < 8; i++)
    {
        ans.push_back(vec[i].first);
        sum += vec[i].second;
    }

    sort(ans.begin(), ans.end());

    cout << sum << '\n';
    for(int i = 0; i < 5; i++)
        cout << ans[i] << " ";
    

    return 0;
}