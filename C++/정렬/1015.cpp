#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N(0);
vector<pair<int, int>> vec;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    vec.resize(N);
    for(int i = 0; i < N; i++)
    {
        cin >> vec[i].first;
        vec[i].second = i;
    }
    
    sort(vec.begin(), vec.end());

    vector<int> p(N);

    for(int i = 0; i < N; i++)
        p[vec[i].second] = i;

    for(int i = 0; i < N; i++)
        cout << p[i] << " "; 

    return 0;
}