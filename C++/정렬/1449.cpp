#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N(0), L(0);
int ans(0);
vector<int> vec;
vector<bool> bIsVisited;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> L;
    vec.resize(N);

    for(int i = 0; i < N; i++)
        cin >> vec[i];

    sort(vec.begin(), vec.end());

    bIsVisited.resize(vec[N - 1] + 1);

    for(int i = 0; i < N; i++)
    {
        if(bIsVisited[vec[i]] == false)
        {
            for(int j = vec[i]; j < vec[i] + L; j++)
            {
                if(j > vec[N - 1])  break;
                bIsVisited[j] = true;
            }
            ++ans;
        }
    }

    cout << ans << '\n';

    return 0;
}