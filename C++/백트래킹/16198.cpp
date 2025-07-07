#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N(0);
int ans(0), tempEnergy(0);
vector<int> W;

void BackTracking()
{
    if(W.size() == 2)
    {
        ans = max(ans, tempEnergy);
        return;
    }

    for(int i = 1; i < W.size() - 1; i++)
    {
        int temp = W[i];
        tempEnergy += W[i - 1] * W[i + 1];
        W.erase(W.begin() + i);
        BackTracking();
        W.insert(W.begin() + i, temp);
        tempEnergy -= W[i - 1] * W[i + 1];
    }
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    for(int i = 0; i < N; i++)
    {
        int temp(0);
        cin >> temp;
        W.push_back(temp);
    }

    BackTracking();

    cout << ans << '\n';

    return 0;
}