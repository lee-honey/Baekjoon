#include <iostream>
#include <vector>

using namespace std;

int n(0), k(0);
int arr[11] = {0,};
vector<int> ans;
bool found = false;
int cnt(0);

void BackTracking(int num, int depth)
{
    if(num > n || found) return;

    if(num == n)
    {
        if(++cnt == k)
        {
            for(int i = 0; i < depth; i++)
                ans.push_back(arr[i]);
            found = true;
        }
        return;
    }

    for(int i = 1; i <= 3; i++)
    {
        arr[depth] = i;
        BackTracking(num + i, depth + 1);
        arr[depth] = 0;
    }
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> k;

    BackTracking(0, 0);

    if(ans.empty())
        cout << -1 << '\n';
    else
    {
        for(int i = 0; i < ans.size(); i++)
        {
            cout << ans[i];
            if(i != ans.size() - 1)
                cout << "+";
        }
        cout << '\n';
    }

    return 0;
}