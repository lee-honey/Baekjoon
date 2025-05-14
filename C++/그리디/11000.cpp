#include <iostream>
#include <queue>
#include <algorithm>

using namespace  std;

int N(0);
vector<pair<int, int>> vec;
priority_queue<int, vector<int>, greater<int>> pq;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    while(N--)
    {
        int S(0), T(0);
        cin >> S >> T;
        vec.push_back({S, T});
    }
    sort(vec.begin(), vec.end());

    for(int i = 0; i < vec.size(); i++)
    {
        pq.push(vec[i].second); // 끝나는 시간을 넣음
        if(pq.top() <= vec[i].first)
            pq.pop(); // 가장 우선순위큐가 앞에있던, 가장 끝나는 시간이 작은 애보다 작은값이 들어오면 기존값을 꺼내줌
    }

    cout << pq.size() << '\n';

    return 0;
}