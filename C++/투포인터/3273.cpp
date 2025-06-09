#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int n(0), x(0);
vector<int> vec(100001);
int ans(0);
int st(0), ed(0);

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for(int i = 0; i < n; i++)
    {
        int temp(0);
        cin >>temp;
        vec.push_back(temp);
    }
    cin >> x;

    sort(vec.begin(), vec.end());


    return 0;
}