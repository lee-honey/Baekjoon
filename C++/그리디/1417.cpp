#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N(0);
int num(0);
priority_queue<int, vector<int>> pq;
int ans(0);

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    cin >> num;

    if(N == 1)
    {
        cout << "0" << '\n'; // 후보 한명
        return 0;
    }

    for(int i = 0; i < N - 1; i++)
    {
        int temp(0);
        cin >> temp;
        pq.push(temp);
    }

    while(num <= pq.top())
    {
        int temp = pq.top();
        temp -= 1;
        pq.pop();
        pq.push(temp);
        num += 1;
        ans++;
    }

    cout << ans << '\n';

    return 0;
}