#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
using namespace std;

unordered_set<string> us;
vector<int> v;
vector<int> result;
vector<int> visited;
int n, k;
string str;

void dfs()
{
    if (result.size() != k)
    {
        for (int i = 0; i < n; i++) {
            if (visited[i] == 0) {
                visited[i] = 1;
                result.push_back(v[i]);
                dfs();
                result.pop_back();
                visited[i] = 0;
            }
        }
    }
    else
    {
        for (int i = 0; i < result.size(); i++)
            str += to_string(result[i]);
        us.insert(str);
        str = "";
    }
}

int main()
{
    cin >> n >> k;
    v.assign(n, 0);
    visited.assign(n, 0);
    for(int i = 0; i < n ;i++)
        cin >> v[i];
    dfs();
    cout << us.size();
}